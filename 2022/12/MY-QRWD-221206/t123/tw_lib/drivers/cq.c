/**
 *  @file   cq.c
 *  @brief  command queue driver
 *  $Id: cq.c,v 1.7 2013/02/18 08:10:30 ken Exp $
 *  $Author: ken $
 *  $Revision: 1.7 $
 *
 *  Copyright (c) 2011 Terawins Inc. All rights reserved.
 * 
 *  @date   2011/10/31  hugo	New file.
 *          2012/05/21  hugo    improved v2
 *
 */

#include <string.h>
#include "sys.h"
#include "reg_tw.h"
#include "iccontrol.h"
#include "cq.h"

#ifdef CQ_ENABLE_INT
#include "tw_irq.h"
#endif

/* Platform */
//#define CONFIG_EAGLE    // config for Eagle
#define CONFIG_THETIS   // config for Thetis

//#define CQ_DEBUG

static unsigned char cq_status;                 /* interrupt status */
static unsigned char cq_wlen;                   /* length to write */
static unsigned char cq_size;                   /* current queue size */
static unsigned char cq_size_last;              /* last queue size */
static unsigned char cq_debug;                  /* debug options */

static unsigned char xdata CQ_INT_MASK;         /* interrupt_mask */
static unsigned char xdata CQ_TRIGGER_SRC;      /* trigger source */
static unsigned char xdata CQ_TRIGGER_TIMEOUT;  /* trigger timeout */
static unsigned char xdata CQ_TRIGGER_ADJ_L;    /* trigger delay low byte */
static unsigned char xdata CQ_TRIGGER_ADJ_H;    /* trigger delay hi byte */

#define CQ_MAX_SIZE (128 - 1)

#define MIN(X,Y)    ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y)    ((X) > (Y) ? (X) : (Y))

struct cmdhdr {
    unsigned char page;
    unsigned char addr;
    unsigned char incr;
    unsigned int size;
};

struct regval {
    unsigned char addr;
    unsigned char value;
};

/*
 * Elements of Command Queue
 *
 * 2-byte command (write 1 ~ 8 byte)
 *  Byte    Bit     Description
 *  0       [7]     2/3-byte command, 0:2-byte, 1:3-byte
 *          [6]     Incr., 0:repeat address, 1: incremental address
 *          [5:3]   Page
 *          [2:0]   Length (=L)
 *  1       [7:0]   Initial Address
 *  2+0             Data(0)
 *  ...             ...
 *  2+L             Data(L)
 *
 * 3-byte command (write 1 ~ 125(=128-3) byte)
 *  Byte    Bit     Description
 *  0       [7]     2/3-byte command, 0:2-byte, 1:3-byte
 *          [6]     Incr., 0:repeat address, 1: incremental address
 *          [5:3]   Page
 *          [2:0]   (TBD)
 *  1       [7:0]   Length (=L)
 *  2       [7:0]   Initial Address
 *  3+0             Data(0)
 *  ...             ...
 *  3+L             Data(L)
 */

/*
 * P3_C0            General Setting
 *  [7]     W       Software reset to all registers in this module
 *  [1]     R/W     Debug Mode. Set ???1??? to read SRAM data from data port.
 *  [0]     R/W     CQ_locked. Lock command queue (cannot be issued)
 */
#define CQ_SOFTWARE_RESET       (1 << 7)

#ifndef CQ_DEBUG
#define CQ_SETTING_SET(VAL)     do { IC_WritByte (TWIC_P3, 0xC0, VAL); } while (0)
#else
#define CQ_SETTING_SET(VAL)     do { IC_WritByte (TWIC_P3, 0xC0, VAL); if ((cq_debug & CQ_DEBUG_SET_REG)) DBG_PRINT ("P3_C0=0x%02bx\n", (VAL)); } while (0)
#endif

/*
 * P3_C1            Interrupt Mask
 *  [3]     R/W     Command queue overflow
 *  [2]     R/W     Wait trigger signal time-out
 *  [1]     R/W     Invalid command
 *  [0]     R/W     Command queue done
 */

#ifndef CQ_DEBUG
#define CQ_INT_MASK_SET(VAL)    do { IC_WritByte (TWIC_P3, 0xC1, VAL); CQ_INT_MASK = (VAL); } while (0)
#else
#define CQ_INT_MASK_SET(VAL)    do { IC_WritByte (TWIC_P3, 0xC1, VAL); CQ_INT_MASK = (VAL); if ((cq_debug & CQ_DEBUG_SET_REG)) DBG_PRINT ("P3_C1=0x%02bx\n", (VAL)); } while (0)
#endif

/*
 * P3_C2            Interrupt Status
 *  [3]     R/W1C   Command queue overflow
 *  [2]     R/W1C   Wait trigger signal time-out
 *  [1]     R/W1C   Invalid command
 *  [0]     R/W1C   Command queue done
 */
#define CQ_DONE                 (1 << 0)
#define CQ_INVALID_CMD          (1 << 1)
#define CQ_TIMEOUT              (1 << 2)
#define CQ_OVERFLOW             (1 << 3)

#ifndef CQ_DEBUG
#define CQ_INT_STAT_SET(VAL)    do { IC_WritByte (TWIC_P3, 0xC2, VAL); } while (0)
#else
#define CQ_INT_STAT_SET(VAL)    do { IC_WritByte (TWIC_P3, 0xC2, VAL); if ((cq_debug & CQ_DEBUG_SET_REG)) DBG_PRINT ("P3_C2=0x%02bx\n", (VAL)); } while (0)
#endif

/*
 * P3_C3            Trigger Source
 *  [7]     R/W     CQ_issue (de-asserted when done)
 *  [6]     R/W     CQ_action
 *                  if (CQ_locked == 0) CQ_action <= CQ_issue;
 *                  else (CQ_issue==0) CQ_action <= 0;
 *  [1:0]   R/W     trigger_source
 *                  0: software trigger
 *                  1: vsync rising
 *                  2: vde falling
 */
#define CQ_ISSUE                (1 << 7)
#define CQ_TRIGGER_SRC_MASK     0x03

#ifndef CQ_DEBUG
#define CQ_TRIGGER_SRC_SET(VAL) do { IC_WritByte (TWIC_P3, 0xC3, VAL); CQ_TRIGGER_SRC = ((VAL) & CQ_TRIGGER_SRC_MASK); } while (0)
#else
#define CQ_TRIGGER_SRC_SET(VAL) do { IC_WritByte (TWIC_P3, 0xC3, VAL); CQ_TRIGGER_SRC = ((VAL) & CQ_TRIGGER_SRC_MASK); if ((cq_debug & CQ_DEBUG_SET_REG)) DBG_PRINT ("P3_C3=0x%02bx\n", IC_ReadByte (TWIC_P3, 0xC3)); } while (0)
#endif

#ifndef CQ_DEBUG
#define CQ_TRIGGER_ISSUE() do { IC_WritByte (TWIC_P3, 0xC3, (CQ_ISSUE | IC_ReadByte (TWIC_P3, 0xC3))); } while (0)
#else
#define CQ_TRIGGER_ISSUE() do { IC_WritByte (TWIC_P3, 0xC3, (CQ_ISSUE | IC_ReadByte (TWIC_P3, 0xC3))); if ((cq_debug & CQ_DEBUG_SET_REG)) DBG_PRINT ("P3_C3=0x%02bx\n", IC_ReadByte (TWIC_P3, 0xC3)); } while (0)
#endif

/*
 * P3_C5            Data Port
 *  [7:0]   R/W     Data port to SRAM (read for debug mode only)
 */
#define CQ_2BYTE_CMD            (0 << 7)
#define CQ_3BYTE_CMD            (1 << 7)
#define CQ_INCR_SHIFT           6
#define CQ_PAGE_SHIFT           3
#define CQ_LEN_SHIFT            0

#ifndef CQ_DEBUG
#define CQ_DATAPORT_SET(VAL)    do { IC_WritByte (TWIC_P3, 0xC5, VAL); cq_size++; cq_wlen--; } while (0)
#else
#define CQ_DATAPORT_SET(VAL)    do { IC_WritByte (TWIC_P3, 0xC5, VAL); if ((cq_debug & CQ_DEBUG_SET_REG)) DBG_PRINT ("P3_C5=0x%02bx\n", (VAL)); if ((cq_debug & CQ_DEBUG_DATAPORT)) DBG_PRINT ("CQ[%bd]=0x%02bx\n", cq_size, (VAL)); cq_size++; cq_wlen--; } while (0)
#endif

/*
 * P3_C6            Wait Trigger Time Out
 *  [7:0]   R/W     Time out threshold in WAIT TRIGGER state.
 *                  If the timer tick (1ms) is counted to this threshold,
 *                  command queue will start programming sequence and then
 *                  issue a time-out interrupt.
 *                  Set 0 to disable this feature.
 */

#ifndef CQ_DEBUG
#define CQ_TRIGGER_TIMEOUT_SET(VAL) do { IC_WritByte (TWIC_P3, 0xC6, VAL); CQ_TRIGGER_TIMEOUT = (VAL); } while (0)
#else
#define CQ_TRIGGER_TIMEOUT_SET(VAL) do { IC_WritByte (TWIC_P3, 0xC6, VAL); CQ_TRIGGER_TIMEOUT = (VAL); if ((cq_debug & CQ_DEBUG_SET_REG)) DBG_PRINT ("P3_C6=0x%02bx\n", (VAL)); } while (0)
#endif

/*
 * P3_C7            Queue Pointer
 *  [7:0]   R/W     When debug mode, the SRAM address will be override by
 *                  this queue pointer, and the corresponding data can be
 *                  read from data port.
 */

#ifndef CQ_DEBUG
#define CQ_POINTER_SET(VAL)     do { IC_WritByte (TWIC_P3, 0xC7, VAL); } while (0)
#else
#define CQ_POINTER_SET(VAL)     do { IC_WritByte (TWIC_P3, 0xC7, VAL); if ((cq_debug & CQ_DEBUG_SET_REG)) DBG_PRINT ("P3_C7=0x%02bx\n", (VAL)); } while (0)
#endif

/*
 * P3_C8            CQ_line_count_L
 *  [7:0]   R       CQ_line_count[7:0]
 *                  The line number when command queue is done.
 *
 * P3_C9            CQ_line_count_H
 *  [3:0]   R       CQ_line_count [11:8]
 *                  The line number when command queue is done.
 */
#define CQ_LINECNT              ((((int)IC_ReadByte (TWIC_P3, 0xC9)) << 8) | ((int)IC_ReadByte (TWIC_P3, 0xC8)))

#ifndef CQ_DEBUG
#define CQ_LINECNT_L_SET(VAL)   do { IC_WritByte (TWIC_P3, 0xC8, VAL); } while (0)
#else
#define CQ_LINECNT_L_SET(VAL)   do { IC_WritByte (TWIC_P3, 0xC8, VAL); if ((cq_debug & CQ_DEBUG_SET_REG)) DBG_PRINT ("P3_C8=0x%02bx\n", (VAL)); } while (0)
#endif

#ifndef CQ_DEBUG
#define CQ_LINECNT_H_SET(VAL)   do { IC_WritByte (TWIC_P3, 0xC9, VAL); } while (0)
#else
#define CQ_LINECNT_H_SET(VAL)   do { IC_WritByte (TWIC_P3, 0xC9, VAL); if ((cq_debug & CQ_DEBUG_SET_REG)) DBG_PRINT ("P3_C9=0x%02bx\n", (VAL)); } while (0)
#endif

/*
 * P3_CA            Trigger Timing Adjustment_L
 *  [7:0]   R/W     CQ_delay_amount[7:0]
 *
 * P3_CB            Trigger Timing Adjustment_H
 *  [7]     R/W     CQ_delay_enable
 *  [6]     R/W     CQ_delay_unit (0: clock, 1: line)
 *  [1:0]   R/W     CQ_delay_amount[9:8]
 */
#define CQ_DELAY_IN_LINE            (1 << 6)
#define CQ_DELAY_ENABLE             (1 << 7)

#ifndef CQ_DEBUG
#define CQ_TRIGGER_ADJ_L_SET(VAL) do { IC_WritByte (TWIC_P3, 0xCA, VAL); CQ_TRIGGER_ADJ_L = (VAL); } while (0)
#else
#define CQ_TRIGGER_ADJ_L_SET(VAL) do { IC_WritByte (TWIC_P3, 0xCA, VAL); CQ_TRIGGER_ADJ_L = (VAL); if ((cq_debug & CQ_DEBUG_SET_REG)) DBG_PRINT ("P3_CA=0x%02bx\n", (VAL)); } while (0)
#endif

#ifndef CQ_DEBUG
#define CQ_TRIGGER_ADJ_H_SET(VAL) do { IC_WritByte (TWIC_P3, 0xCB, VAL); CQ_TRIGGER_ADJ_H = (VAL); } while (0)
#else
#define CQ_TRIGGER_ADJ_H_SET(VAL) do { IC_WritByte (TWIC_P3, 0xCB, VAL); CQ_TRIGGER_ADJ_H = (VAL); if ((cq_debug & CQ_DEBUG_SET_REG)) DBG_PRINT ("P3_CB=0x%02bx\n", (VAL)); } while (0)
#endif



/*
 * Synopsis     void cq_info (void); 
 * Description  show command debug information and CQ controller registers.
 * Parameters   none
 * Return       none
 */
void
cq_info (void)
{
#ifdef CQ_DEBUG
    char i;

    DBG_PRINT ("Command Queue variables:\n");
    DBG_PRINT ("  debug: %02bx\n", cq_debug);
    DBG_PRINT ("    CQ_DEBUG_SET_REG: %d\n", (int)((cq_debug & CQ_DEBUG_SET_REG) != 0));
    DBG_PRINT ("    CQ_DEBUG_DATAPORT: %d\n", (int)((cq_debug & CQ_DEBUG_DATAPORT) != 0));
    DBG_PRINT ("    CQ_DEBUG_ISSUE: %d\n", (int)((cq_debug & CQ_DEBUG_ISSUE) != 0));
    DBG_PRINT ("    CQ_DEBUG_LINECNT: %d\n", (int)((cq_debug & CQ_DEBUG_LINECNT) != 0));
    DBG_PRINT ("    CQ_DEBUG_CONFIG: %d\n", (int)((cq_debug & CQ_DEBUG_CONFIG) != 0));
    DBG_PRINT ("    CQ_DEBUG_WRITE: %d\n", (int)((cq_debug & CQ_DEBUG_WRITE) != 0));
    DBG_PRINT ("    CQ_DEBUG_REGTABLE: %d\n", (int)((cq_debug & CQ_DEBUG_REGTABLE) != 0));
    DBG_PRINT ("  interrupt status: %bd\n", cq_status);
    DBG_PRINT ("  write length: %bd\n", cq_wlen);
    DBG_PRINT ("  queue size: %bd\n", cq_size);
    DBG_PRINT ("  queue size (last): %bd\n", cq_size_last);
    DBG_PRINT ("  trigger source: %bd\n", IC_ReadByte (TWIC_P3, 0xC3) & 0x03);
    DBG_PRINT ("  trigger timeout: %bd\n", IC_ReadByte (TWIC_P3, 0xC6));
    DBG_PRINT ("  trigger delay: %d\n", (int)(IC_ReadByte (TWIC_P3, 0xCA)) | (((int)(IC_ReadByte (TWIC_P3, 0xCB) & 0x3)) << 8));
    DBG_PRINT ("\n");

    DBG_PRINT ("Command Queue Registers:\n");
    for (i = 0; i < 16; i++)
        DBG_PRINT ("  P3_C%bX = 0x%02bx\n", i, IC_ReadByte (TWIC_P3, 0xC0 + i));
    DBG_PRINT ("\n");
#endif
}

/*
 * Synopsis     void cq_dump (void);
 * Description  dump data in command queue (for debug only).
 * Parameters   none
 * Return       none
 */
void
cq_dump (void)
{
    unsigned char size = cq_size > 0 ? cq_size : cq_size_last;
    unsigned char cq_setting;
    unsigned char i, v;

    DBG_PRINT ("CQ_SIZE: %bd\n", size);

    cq_setting = IC_ReadByte (TWIC_P3, 0xC0);
    CQ_SETTING_SET (cq_setting | (1 << 1));
    for (i = 0; i < size; i++) {
        CQ_POINTER_SET (i);
        v = IC_ReadByte (TWIC_P3, 0xC5);
        DBG_PRINT ("%3bd: 0x%02bx\n", i, v);
    }
    CQ_SETTING_SET (cq_setting & ~(1 << 1));
}

/*
 * Synopsis     static void cq_issue (void);
 * Description  start command queue programming sequence.
 * Parameters   none
 * Return       none
 */
static void
cq_issue (void)
{
#ifdef CQ_DEBUG
    if ((cq_debug & CQ_DEBUG_ISSUE)) {
        DBG_PRINT ("cq_issue: trigger=0x%02bx, size=%bd\n",
                (CQ_ISSUE | IC_ReadByte (TWIC_P3, 0xC3)) , cq_size);
    }
#endif

#ifdef CQ_ENABLE_INT
	mute_tw_irq();
	/* enable cq irq */
	enable_tw_irq(IRQ_CQ_INT);
#endif

    CQ_TRIGGER_ISSUE ();
    twdDelay(1);    /* FIXME it's a workaround */
}

/*
 * Synopsis     static char cq_issue_done (void);
 * Description  check result of command issue.
 * Parameters   none
 * Return       0 for successfully, minus if any error occurred
 */
static char
cq_issue_done (void)
{
    unsigned char status;
    char rc = -CQ_ERR_UNKNOWN;

#ifdef CQ_ENABLE_INT
    status = cq_status;
    if (status == 0)
        /* issue not done */
        return 0;
    cq_status = 0;          /* clear interrupt status */
    
    /* RESTORE INT MASK CONFIG */
	restore_tw_irq();
#else
    status = IC_ReadByte (TWIC_P3, 0xC2);
    if (status == 0)
        /* issue not done */
        return 0;
    CQ_INT_STAT_SET (0xff); /* clear interrupt status */
#endif

    cq_size_last = cq_size;
    cq_size = 0;

#ifdef CQ_DEBUG
    if ((cq_debug & CQ_DEBUG_LINECNT)) {
        DBG_PRINT ("CQ_LINECNT: %d\n", CQ_LINECNT);
    }
#endif

    if ((status & CQ_OVERFLOW)) {
        /* FIXME workaround hardware bug */
        cq_reset ();
    }

    if (status == CQ_DONE) {
        /* successful */
        rc = 1;
    } else {
        /* shit happens */
        DBG_PRINT ("CQ_INT_STAT_REG: 0x%02bx\n", status);

        if ((status & CQ_OVERFLOW)) {
            ERROR (("queue overflow\n"));
            rc = -CQ_ERR_QUEUE_OVERFLOW;
        }
        if ((status & CQ_TIMEOUT)) {
            ERROR (("trigger timeout\n"));
            rc = -CQ_ERR_TRIGGER_TIMEOUT;
        }
        if ((status & CQ_INVALID_CMD)) {
            ERROR (("invalid command\n"));
            rc = -CQ_ERR_INVALID_CMD;
        }
    }

    return rc;
}

/*
 * Synopsis     char cq_available (void);
 * Description  report available queue length.
 * Parameters   none
 * Return       available queue length
 */
char
cq_available (void)
{
    return (CQ_MAX_SIZE - cq_size);
}

/*
 * Synopsis     char cq_config (unsigned char page,
 *                              unsigned char addr,
 *                              unsigned char incr,
 *                              unsigned char size);
 * Description  setup command header.
 * Parameters   page - page no.
 *              addr - address
 *              incr - address to write is repeat(0) or incremental(1)
 *              size - length of command
 * Return       0 for successful, minus if any error occurred
 * NOTE         CQ attributes, including trigger source, trigger delay time
 *              and trigger wait timeout, should be configured before calling
 *              cq_config().
 *              If the queue is going to be full, it will be automatically
 *              flushed by calling cq_flush() before setup command header.
 */
char
cq_config (unsigned char page, unsigned char addr, unsigned char incr, unsigned char size)
{
    unsigned char wlen = size + (size > 8 ? 3 : 2);
    unsigned char temp;
    char rc;

#ifdef CQ_DEBUG
    if ((cq_debug & CQ_DEBUG_CONFIG)) {
        DBG_PRINT ("cq_config(%bd,0x%02bx,%bd,%bd)\n", page, addr, incr, size);
    }
#endif

    /* sanity check */
    if (size == 0) {
        ERROR (("illegal zero length\n"));
        return -CQ_ERR_LENGTH;
    }

    if (size > (CQ_MAX_SIZE - 3)) {
        ERROR (("illegal data length\n"));
        return -CQ_ERR_LENGTH;
    }

    if (cq_wlen != 0) {
        ERROR (("last command unfinished\n"));
        return -CQ_ERR_UNFINISHED;
    }

    /* flush queue forcely if it's going to be full */
    if (cq_size + wlen > CQ_MAX_SIZE) {
        rc = cq_flush ();
        if (rc < 0)
            return rc;
    }

    cq_wlen = wlen;

    /* command header */
    if (size < 9) {
        temp = CQ_2BYTE_CMD;
        temp |= (incr != 0) << CQ_INCR_SHIFT;
        temp |= (page & 0x7) << CQ_PAGE_SHIFT;
        temp |= (size - 1) << CQ_LEN_SHIFT;
        CQ_DATAPORT_SET (temp);
        CQ_DATAPORT_SET (addr);
    } else {
        temp = CQ_3BYTE_CMD;
        temp |= (incr != 0) << CQ_INCR_SHIFT;
        temp |= (page & 0x7) << CQ_PAGE_SHIFT;
        CQ_DATAPORT_SET (temp);
        CQ_DATAPORT_SET (size - 1);
        CQ_DATAPORT_SET (addr);
    }

    return 0;
}

/*
 * Synopsis     char cq_data (unsigned char byte);
 * Description  write one byte of a command.
 * Parameters   byte - one byte
 * Return       0 for successful, minus if any error occurred
 */
char
cq_data (unsigned char byte)
{
    if (cq_wlen == 0) {
        ERROR (("too many data\n"));
        return -CQ_ERR_CMD_OVERFLOW;
    }

    CQ_DATAPORT_SET (byte);
    return 0;
}

/*
 * Synopsis     char cq_flush (void);
 * Description  flush commands in command queue forcely.
 * Parameters   none
 * Return       0 for successful, minus if any error occurred
 */
char
cq_flush (void)
{
    unsigned int i;
    char rc;

    if (cq_wlen != 0) {
        ERROR (("last issue unfinished\n"));        
		return -CQ_ERR_UNFINISHED;
    }

    if (cq_size == 0) {
        ERROR (("command queue empty\n"));        
		return -CQ_ERR_EMPTY;
    }

    cq_issue ();
    for (i = 0; i < 0xffff; i++) {
        if ((rc = cq_issue_done ()))
            break;
    }

    if (i == 0xffff) {
        cq_reset ();
        ERROR (("issue timeout\n"));
        return -CQ_ERR_ISSUE_TIMEOUT;
    }

    return rc;
}

/*
 * Synopsis     char cq_flush_now (void);
 * Description  setup software trigger and flush commands in command queue.
 * Parameters   none
 * Return       0 for successful, minus if any error occurred
 */
char
cq_flush_now (void)
{
    cq_trigger_source (CQ_TRIGGER_SW);
    return cq_flush ();
}

/*
 * Synopsis     char cq_flush_vsync (void);
 * Description  setup vsync triffer and flush commands in command queue.
 * Parameters   none
 * Return       0 for successful, minus if any error occurred
 */
char
cq_flush_vsync (void)
{
    cq_trigger_source (CQ_TRIGGER_VSYNC);
    return cq_flush ();
}

/*
 * Synopsis     char cq_flush_vde (void);
 * Description  setup vde trigger and flush commands in command queue.
 * Parameters   none
 * Return       0 for successful, minus if any error occurred
 */
char
cq_flush_vde (void)
{
    cq_trigger_source (CQ_TRIGGER_VDE);
    return cq_flush ();
}

/*
 * Synopsis     char char cq_write_buf (unsigned char page,
 *                                      unsigned char addr,
 *                                      unsigned char incr,
 *                                      unsigned char size,
 *                                      unsigned char *buf);
 * Description  add a set of commands in command queue.
 *              the address of commands to write could be repeat (for data-port
 *              registers) or incremental (for normal registers).
 * Parameters   page - page no.
 *              addr - address
 *              incr - address to write is repeat(0) or incremental(1)
 *              size - length of command
 *              buf - pointer to commands in ROM code
 * Return       0 for successful, minus if any error occurred
 * WARNING      programmers have to take care of the length of command queue
 *              in case of queue overflow.
 */
static char
cq_write_buf (unsigned char page, unsigned char addr, unsigned char incr, unsigned char size, unsigned char *buf)
{
    unsigned char i;
    char rc;

#ifdef CQ_DEBUG
    if ((cq_debug & CQ_DEBUG_WRITE)) {
        DBG_PRINT ("cq_write_buf(%bd,0x%02bx,%bd,%bd,0x%x)\n",
                page, addr, incr, size, (int)buf);
    }
#endif

#ifdef CONFIG_EAGLE
    if (size == 1) {
        /* FIXME workaround hardware bug */
        rc = cq_config (page, addr, 0, 2);
        if (rc < 0)
            return rc;

        for (i = 0; i < 2; i++) {
            CQ_DATAPORT_SET (buf[0]);
        }
    } else {
        rc = cq_config (page, addr, incr, size);
        if (rc < 0)
            return rc;

        for (i = 0; i < size; i++) {
            CQ_DATAPORT_SET (buf[i]);
        }
    }
#else
    rc = cq_config (page, addr, incr, size);
    if (rc < 0)
        return rc;

    for (i = 0; i < size; i++) {
        CQ_DATAPORT_SET (buf[i]);
    }
#endif

    return 0;
}

/*
 * Synopsis     char cq_write_cmd (unsigned char *cmd);
 * Description  add a set of commands in command queue.
 *              the address of commands to write could be repeat (for data-port
 *              registers) or incremental (for normal registers).
 *              due to the limitation of command queue length, the function will
 *              automatically divide commands to write if necessary.
 * Parameters   cmd - pointer to command structure (byte0~4 is command header)
 *                  byte0   page
 *                  byte1   addr
 *                  byte3   incr
 *                  byte3   size[15:8]
 *                  byte4   size[7:0]
 *                  byte5   data
 *                  ...     ...
 * Return       0 for successful, minus if any error occurred
 */
char
cq_write_cmd (unsigned char *cmd)
{
    struct cmdhdr *hdr;
    unsigned int idx, cnt;
    unsigned int len1;  /* lenght to be going to write */
    unsigned int len2;  /* max length to write */
    char rc;

    hdr = (struct cmdhdr *)cmd;
    cmd += sizeof (struct cmdhdr);

    /* flush queue if almost full */
    if (cq_size > (CQ_MAX_SIZE - 3)) {
        rc = cq_flush ();
        if (rc < 0)
            return rc;
    }

    idx = 0;
    while (idx < hdr->size) {
        len1 = hdr->size - idx;
        len2 = CQ_MAX_SIZE - cq_size - (len1 > 8 ? 3 : 2);
        cnt = MIN (len1, len2);

        rc = cq_write_buf (hdr->page, (hdr->incr ? (hdr->addr + idx) : hdr->addr), hdr->incr, cnt, cmd + idx);
        if (rc < 0)
            return rc;

        idx += cnt;

        if (hdr->size - idx > 0) {
            rc = cq_flush ();
            if (rc < 0)
                return rc;
        }
    }

    return 0;
}

/*
 * Synopsis     char cq_write_cmdset (unsigned char code *cmd[],
 *                                    unsigned char num); 
 * Description  write a group of command set.
 * Parameters   cmd - pointer to command sets in ROM code
 *              num - number of command sets
 * Return       0 for successful, minus if any error occurred
 */
char
cq_write_cmdset (unsigned char code *cmd[], unsigned char num)
{
    unsigned char i;
    char rc;

    for (i = 0; i < num; i++) {
        rc = cq_write_cmd (cmd[i]);
        if (rc < 0)
            return rc;
    }

    return 0;
}

/*
 * Synopsis     void cq_trigger_source (unsigned char source);
 * Description  setup trigger source of command queue write action.
 * Parameters   trigger_src - trigger source
 *                  0 for software trigger
 *                  1 for vsync rising
 *                  2 for vde falling
 * Return       none
 */
void
cq_trigger_source (unsigned char source)
{
    /* sanity check */
    if (source > 2) {
        ERROR (("illegal trigger source (%d)\n", source));
        while (1);
    }

    CQ_TRIGGER_SRC_SET (source);
}

/*
 * Synopsis     void cq_trigger_delay (char enable,
 *                                     int count,
 *                                     char dly_in_hsync);
 * Description  adjust the timing of command queue trigger.
 * Parameters   enable
 *                  0: disable this feature
 *                  1: enable this feature
 *              count
 *                  range: 0~1023
 *              dly_in_hsync
 *                  0: delay in clock cycle
 *                  1: delay in line (hsync rising)
 * Return       none
 */
void
cq_trigger_delay (char enable, int count, char dly_in_hsync)
{
    unsigned char hi, lo;

    if (enable) {
        lo = (unsigned char)(count & 0xff);
        hi = (unsigned char)((count >> 8) & 0x3) | CQ_DELAY_ENABLE;
        if (dly_in_hsync)
            hi |= CQ_DELAY_IN_LINE;
    } else {
        lo = hi = 0;
    }

    CQ_TRIGGER_ADJ_L_SET (lo);
    CQ_TRIGGER_ADJ_H_SET (hi);
}

/*
 * Synopsis     void cq_trigger_timeout (unsigned char count);
 * Description  setup wait timeout in case trigger source is missed.
 *              data in command queue will be issued anyway if wait timeout.
 * Parameters   count - timeout threshold in WAIT TRIGGER status
 *                  range: 1~127 ms, and 0 to disable this feature.
 * Return       none
 */
void
cq_trigger_timeout (unsigned char count)
{
    CQ_TRIGGER_TIMEOUT_SET (count);
}

/*
 * Synopsis     void cq_reset (void);
 * Description  reset command queue driver and controller.
 * Parameters   none
 * Return       none
 */
void
cq_reset (void)
{
    CQ_SETTING_SET (CQ_SOFTWARE_RESET);

    /* restore hardware setting */
    IC_WritByte (TWIC_P3, 0xC1, CQ_INT_MASK);
    IC_WritByte (TWIC_P3, 0xC3, CQ_TRIGGER_SRC);
    IC_WritByte (TWIC_P3, 0xC6, CQ_TRIGGER_TIMEOUT);
    IC_WritByte (TWIC_P3, 0xCA, CQ_TRIGGER_ADJ_L);
    IC_WritByte (TWIC_P3, 0xCB, CQ_TRIGGER_ADJ_H);

    /* reset software setting */
    cq_status = 0;
    cq_wlen = 0;
    cq_size = cq_size_last = 0;

#ifdef CQ_ENABLE_INT
    /* RESTORE INT MASK CONFIG */
	restore_tw_irq();
#endif

#ifdef CONFIG_EAGLE
    /* FIXME workaround hardware bug - reset write pointer */
    while (1) {
        IC_WritByte (TWIC_P3, 0xC5, 0x00);

#ifndef CQ_ENABLE_INT
        cq_status = IC_ReadByte (TWIC_P3, 0xC2);
#endif
        if ((cq_status & CQ_OVERFLOW)) {
            IC_WritByte (TWIC_P3, 0xC2, 0xff);
            cq_status = 0;
            break;
        }
    }
#endif
}

/*
 * Synopsis     void cq_init (void);
 * Description  initiate command queue driver
 * Parameters   none
 * Return       none
 */
void
cq_init (void)
{
	cq_debug = 0;
	/* debug options */
#ifdef CQ_DEBUG	     
    cq_debug |= CQ_DEBUG_SET_REG;
    cq_debug |= CQ_DEBUG_DATAPORT;
    cq_debug |= CQ_DEBUG_ISSUE;
    cq_debug |= CQ_DEBUG_LINECNT;
    cq_debug |= CQ_DEBUG_CONFIG;
    cq_debug |= CQ_DEBUG_WRITE;
    cq_debug |= CQ_DEBUG_REGTABLE;
#endif	

    /* init register backup values */
    CQ_INT_MASK = 0;
    CQ_TRIGGER_SRC = 0;
    CQ_TRIGGER_TIMEOUT = 0;
    CQ_TRIGGER_ADJ_L = 0;
    CQ_TRIGGER_ADJ_H = 0;

    /* software setting */
    cq_status = 0;
    cq_wlen = 0;
    cq_size = cq_size_last = 0;

    /* hardware setting */
    CQ_SETTING_SET (CQ_SOFTWARE_RESET); /* software reset */
    CQ_INT_MASK_SET (0x00);             /* enable CQ interrupt */

#ifdef CQ_ENABLE_INT
	/* enable cq irq */
	enable_tw_irq(IRQ_CQ_INT);
#endif

	/* init setting */
	cq_trigger_source (0);      /* software trigger */
	cq_trigger_delay (0, 0, 0); /* no trigger dealy */
	cq_trigger_timeout (0);     /* no trigger timeout */
	cq_info ();
}

/*
 * Synopsis     void cq_isr (void);
 * Description  CQ interrupt service routine. (called by INT handler only)
 * Parameters   none
 * Return       none
 */
void
cq_isr (void)
{
#ifdef CQ_ENABLE_INT
    cq_status |= IC_ReadByte_INT (TWIC_P3, 0xC2);   /* read interrupt status */
    IC_WritByte_INT (TWIC_P3, 0xC2, cq_status);     /* clear interrupt status */

	clear_tw_irq(IRQ_CQ_INT);		            /* clear cq interrupt status */
#endif
}

/*
 * Synopsis     char cq_busy (void);
 * Description  report CQ action status.
 * Parameters   none
 * Return       0: idle state; 1: busy state.
 */
char
cq_busy (void)
{
    return ((IC_ReadByte_INT (TWIC_P3, 0xC3) & (1 << 6)));
}

//----------------------------------------------------------------------------
// packed API
//----------------------------------------------------------------------------

/*
 * Synopsis     char cq_write_byte (unsigned short bPage,
 *                                  unsigned char bAdd,
 *                                  unsigned char bData);
 * Description  write one byte via command queue.
 * Parameters   bPage - page no. (TWIC_P0~TWIC_P7)
 *              bAdd - address
 *              bData - data to write
 * Return       0 for successful, minus if any error occurred
 */
char cq_write_byte(unsigned short bPage, unsigned char bAdd, unsigned char bData)
{
    char rc;

#ifndef ENABLE_EX_MCU
    /* sanity check */
    if ((bPage & ~0x0700))
        return -CQ_ERR_ARGUMENT;
#else
	bPage &= 0x000F;
	bPage <<= 7;
#endif

    /* config command */
#ifdef CONFIG_EAGLE
    rc = cq_config ((unsigned char)(bPage >> 8), bAdd, 0, 2);
    if (rc < 0)
        return rc;

    CQ_DATAPORT_SET (bData);
    CQ_DATAPORT_SET (bData);
#else
    rc = cq_config ((unsigned char)(bPage >> 8), bAdd, 0, 1);
    if (rc < 0)
        return rc;

    CQ_DATAPORT_SET (bData);
#endif

    return 0;
}

/*
 * Synopsis     char cq_write_byte_issue (unsigned short bPage,
 *                                        unsigned char bAdd,
 *                                        unsigned char bData,
 *                                        unsigned char trig);
 * Description  setup trigger source and write one byte.
 * Parameters   bPage - page no. (TWIC_P0~TWIC_P7)
 *              bAdd - address
 *              bData - data to write
 *              trig - trigger source
 * Return       0 for successful, minus if any error occurred
 */
char cq_write_byte_issue(unsigned short bPage, unsigned char bAdd, unsigned char bData,unsigned char trig)
{
    cq_trigger_source (trig);
    cq_write_byte (bPage, bAdd, bData);
    return cq_flush ();
}

/*
 * Synopsis     char cq_write_byte (unsigned short bPage,
 *                                  unsigned char bAdd,
 *                                  unsigned short bData,
 *                                  unsigned char incr);
 * Description  write one word via command queue
 * Parameters   bPage - page no. (TWIC_P0~TWIC_P7)
 *              bAdd - address
 *              incr - address to write is repeat(0) or incremental(1)
 * Return       0 for successful, minus if any error occurred
 */
char cq_write_word(unsigned short bPage, unsigned char bAdd, unsigned short bData, unsigned char incr)
{
    char rc;

#ifndef ENABLE_EX_MCU
    /* sanity check */
    if ((bPage & ~0x0700))
        return -CQ_ERR_ARGUMENT;
#else
	bPage &= 0x000F;
	bPage <<= 7;
#endif

    /* config command */
    rc = cq_config ((unsigned char)(bPage >> 8), bAdd, incr, 2);
    if (rc < 0)
        return rc;

    /* LO byte first */
    CQ_DATAPORT_SET ((unsigned char)(bData >> 0));
    CQ_DATAPORT_SET ((unsigned char)(bData >> 8));

    return 0;
}

/*
 * Synopsis     char cq_write_byte_issue (unsigned short bPage,
 *                                        unsigned char bAdd,
 *                                        unsigned short bData,
 *                                        unsigned char incr,
 *                                        unsigned char trig);
 * Description  setup trigger source and write one word.
 * Parameters   bPage - page no. (TWIC_P0~TWIC_P7)
 *              bAdd - address
 *              incr - address to write is repeat(0) or incremental(1)
 *              trig - trigger source
 * Return       0 for successful, minus if any error occurred
 */
char cq_write_word_issue(unsigned short bPage, unsigned char bAdd, unsigned short bData, unsigned char incr,unsigned char trig)
{
    cq_trigger_source (trig);
    cq_write_word (bPage, bAdd, bData, incr);
    return cq_flush ();
}

/*
 * Synopsis     char cq_WriteRegsTable (unsigned char code *RegsTable,
 *                                     unsigned char end_page);
 * Description  write a group of register & value pairs.
 * Parameters   RegsTable - pointer to regtable
 *              end_page - the last page in regtable
 * Return       0 for successful, minus if any error occurred
 */
char cq_WriteRegsTable(unsigned char code* RegsTable,unsigned char end_page)
{
    unsigned char page = 0;     /* page index */
    unsigned int regs = 0;      /* num of written registers in a page */
    unsigned int idx, num, i, j;
    unsigned int cnt;
    unsigned int len1;          /* lenght to be going to write */
    unsigned int len2;          /* max length to write */
    struct regval *rv;
    char rc;

    idx = 0;
    while (1) {
        rv = ((struct regval *)RegsTable) + idx;

        /* check end of page */
        if (rv->addr == 0xff) {
#ifdef CQ_DEBUG
            if ((cq_debug & CQ_DEBUG_REGTABLE)) {
                DBG_PRINT ("======== page[%bd] cnt=%d ========\n", page, regs);
            }
#endif
            page++;
            regs = 0;
            idx++;

            if (page == end_page)
                break;

            continue;
        }

        /* looking for contiguous data */
        for (i = 0;; i++) {
            if ((rv[i].addr + 1 != rv[i+1].addr) || (rv[i+1].addr == 0xff))
                break;
        }
        num = i + 1;
#ifdef CQ_DEBUG
            if ((cq_debug & CQ_DEBUG_REGTABLE)) {
                DBG_PRINT ("page=%bd, addr=0x%02bx, size=%d\n", page, rv->addr, num);
            }
#endif

        /* write regs */
        if (cq_size > (CQ_MAX_SIZE - 3)) {
            rc = cq_flush ();
            if (rc < 0)
                return rc;
        }

        i = 0;
        while (i < num) {
            len1 = num - i;
            len2 = CQ_MAX_SIZE - cq_size - (len1 > 8 ? 3 : 2);
            cnt = MIN (len1, len2);

#ifdef CQ_DEBUG
            if ((cq_debug & CQ_DEBUG_WRITE)) {
                DBG_PRINT ("cq_write_rv(%bd,0x%02bx,%bd,%bd,0x%x)\n",
                        page, rv[i].addr, 1, cnt, (int)&rv[i]);
            }
#endif

#ifdef CONFIG_EAGLE
            if (cnt == 1) {
                /* FIXME workaround hardware bug */
                rc = cq_config (page, rv[i].addr, 0, 2);
                if (rc < 0)
                    return rc;

                for (j = 0; j < 2; j++) {
                    CQ_DATAPORT_SET (rv[i].value);
                }
            } else {
                rc = cq_config (page, rv[i].addr, 1, cnt);
                if (rc < 0)
                    return rc;

                for (j = 0; j < cnt; j++) {
                    CQ_DATAPORT_SET (rv[i+j].value);
                }
            }
#else
            rc = cq_config (page, rv[i].addr, 1, cnt);
            if (rc < 0)
                return rc;

            for (j = 0; j < cnt; j++) {
                CQ_DATAPORT_SET (rv[i+j].value);
            }
#endif

            i += cnt;

            if (num - i > 0) {
                rc = cq_flush ();
                if (rc < 0)
                    return rc;
            }
        }

        regs += num;
        idx += num;
    }

    return 0;
}

/*
 * Synopsis     char cq_WriteRegsTable_issue (unsigned char code *RegsTable,
 *                                            unsigned char end_page,
 *                                            unsigned char trig);
 * Description  setup trigger source and write RegsTable.
 * Parameters   RegsTable - pointer to regtable
 *              end_page - the last page in regtable
 *              trig - trigger source
 * Return       0 for successful, minus if any error occurred
 */
char cq_WriteRegsTable_issue(unsigned char code* RegsTable,unsigned char end_page, unsigned char trig)
{
    cq_trigger_source (trig);
    return cq_WriteRegsTable (RegsTable, end_page);
}

//----------------------------------------------------------------------------
// debug only
//----------------------------------------------------------------------------

/*
 * Synopsis     void cq_try_overflow (void);
 * Description  make queue overflow and test error handling.
 * Parameters   none
 * Return       none
 */
void cq_try_overflow (void)
{
    unsigned char i;

    IC_WritByte (TWIC_P3, 0xC5, 0x80);  /* 3-byte cmd, incr=0, page=0 */
    IC_WritByte (TWIC_P3, 0xC5, 0x7f);  /* len=128 */
    IC_WritByte (TWIC_P3, 0xC5, 0x01);  /* addr=0x01 */
    for (i = 0; i < 128; i++) {         /* data: 128 bytes (overflow) */
        IC_WritByte (TWIC_P3, 0xC5, 0x00);
    }

    cq_size = 3 + 128;
    cq_flush ();
}

/*
 * Synopsis     void cq_try_trigger_timeout (void);
 * Description  
 * Parameters   none
 * Return       none
 */
void cq_try_trigger_timeout (void)
{
    unsigned char P0_CA, P3_C3, P3_C6;
    unsigned char i;

    P0_CA = IC_ReadByte (TWIC_P0, 0xCA);    /* backup P0_CA */
#ifdef CONFIG_EAGLE
    IC_WritByte (TWIC_P0, 0xCA, IC_ReadByte (TWIC_P0, 0xCA) | (1 << 5));    /* PDn_Bias=1 (turn off vsync) */
#endif
#ifdef CONFIG_THETIS
    IC_WritByte (TWIC_P0, 0xCA, IC_ReadByte (TWIC_P0, 0xCA) & ~(1 << 5));   /* DPLL_PowerDown_=0 (turn off vsync) */
#endif

    P3_C3 = IC_ReadByte (TWIC_P3, 0xC3);    /* backup P3_C3 */
    IC_WritByte (TWIC_P3, 0xC3, 1);         /* trigger source = vsync */

    P3_C6 = IC_ReadByte (TWIC_P3, 0xC6);    /* backup P3_C6 */
    IC_WritByte (TWIC_P3, 0xC6, 10);        /* trigger timeout = 10ms */

    IC_WritByte (TWIC_P3, 0xC5, 0x80);      /* 3-byte cmd, incr=0, page=0 */
    IC_WritByte (TWIC_P3, 0xC5, 0x0f);      /* len=16 */
    IC_WritByte (TWIC_P3, 0xC5, 0x01);      /* addr=0x01 */
    for (i = 0; i < 16; i++) {              /* data: 16 bytes */
        IC_WritByte (TWIC_P3, 0xC5, 0x00);
    }

    cq_size = 3 + 16;
    cq_flush ();

    IC_WritByte (TWIC_P0, 0xCA, P0_CA);     /* restore P0_CA */
    IC_WritByte (TWIC_P3, 0xC3, P3_C3);     /* restore P3_C3 */
    IC_WritByte (TWIC_P3, 0xC6, P3_C6);     /* restore P3_C6 */
}

/*
 * Synopsis     void cq_try_invalid_cmd (void);
 * Description  write invalid command and test error handling.
 * Parameters   none
 * Return       none
 */
void cq_try_invalid_cmd (void)
{
    unsigned char i;

    IC_WritByte (TWIC_P3, 0xC5, 0x80);      /* 3-byte cmd, incr=0, page=0 */
    IC_WritByte (TWIC_P3, 0xC5, 0x0f);      /* len=16 */
    IC_WritByte (TWIC_P3, 0xC5, 0x01);      /* addr=0x01 */
    for (i = 0; i < 8; i++) {               /* data: 8 bytes (underflow) */
        IC_WritByte (TWIC_P3, 0xC5, 0x00);
    }

    cq_size = 3 + 8;
    cq_flush ();
}

/*
 * Synopsis     void cq_try_issue_timeout (void);
 * Description  disable vsync and test error handling.
 * Parameters   none
 * Return       none
 */
void cq_try_issue_timeout (void)
{
    unsigned char P0_CA, P3_C3, P3_C6;
    unsigned char i;

    P0_CA = IC_ReadByte (TWIC_P0, 0xCA);    /* backup P0_CA */
#ifdef CONFIG_EAGLE
    IC_WritByte (TWIC_P0, 0xCA, IC_ReadByte (TWIC_P0, 0xCA) | (1 << 5));   /* PDn_Bias=1 (turn off vsync) */
#endif
#ifdef CONFIG_THETIS
    IC_WritByte (TWIC_P0, 0xCA, IC_ReadByte (TWIC_P0, 0xCA) & ~(1 << 5));  /* DPLL_PowerDown_=0 (turn off vsync) */
#endif

    P3_C3 = IC_ReadByte (TWIC_P3, 0xC3);    /* backup P3_C3 */
    IC_WritByte (TWIC_P3, 0xC3, 1);         /* trigger source = vsync */

    P3_C6 = IC_ReadByte (TWIC_P3, 0xC6);    /* backup P3_C6 */
    IC_WritByte (TWIC_P3, 0xC6, 0);         /* disable trigger timeout */

    IC_WritByte (TWIC_P3, 0xC5, 0x80);      /* 3-byte cmd, incr=0, page=0 */
    IC_WritByte (TWIC_P3, 0xC5, 0x0f);      /* len=16 */
    IC_WritByte (TWIC_P3, 0xC5, 0x01);      /* addr=0x01 */
    for (i = 0; i < 16; i++) {              /* data: 16 bytes */
        IC_WritByte (TWIC_P3, 0xC5, 0x00);
    }

    cq_size = 3 + 16;
    cq_flush ();

    IC_WritByte (TWIC_P0, 0xCA, P0_CA);     /* restore P0_CA */
    IC_WritByte (TWIC_P3, 0xC3, P3_C3);     /* restore P3_C3 */
    IC_WritByte (TWIC_P3, 0xC6, P3_C6);     /* restore P3_C6 */
}
