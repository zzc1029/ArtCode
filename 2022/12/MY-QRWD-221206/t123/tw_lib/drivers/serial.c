/**
 *  @file   serial.c
 *  @brief  serial driver for hellen
 *  $Id: serial.c,v 1.10 2013/06/17 04:08:18 ken Exp $
 *  $Author: ken $
 *  $Revision: 1.10 $
 *
 *  Copyright (c) 2011 Terawins Inc. All rights reserved.
 *
 *  @date   2011/08/12  ken     New file.
 *
 */

#include <reg51.h>
#include "sys.h"
#include "reg_tw.h"
#include "tw_irq.h"
#include "iccontrol.h"
#include "serial.h"
#include "config.h"
#include "uart.h"


extern unsigned char xdata CONFIG_REGS[];

/* USE EXTERNAL UART */
static unsigned char xdata *UART_BASE = &CONFIG_REGS[0x400];
static unsigned char xdata *UART1_BASE = &CONFIG_REGS[0x500];

//#define UART_BUFF_SIZE    10
unsigned char uqueue[UART_BUFF_SIZE];
unsigned char ufront = UART_BUFF_SIZE - 1;
unsigned char urear = UART_BUFF_SIZE - 1;
unsigned char rev_buf[REC_BUFF_SIZE];
//bit UART1_OK_FLAG = 0;

#ifdef I2C_DEBUG_MODE
    unsigned char i2c_count = 0x00;
#endif

#define UART_RBR            (0x00)
#define UART_THR            (0x00)
#define UART_DLL            (0x00)
#define UART_DLH            (0x04)
#define UART_FCR            (0x08)
#define UART_LCR            (0x0c)
#define UART_MCR            (0x10)
#define UART_LSR            (0x14)
#define UART_SCR            (0x1c)
#define UART_IER            (0x04)
#define UART_SWR            (0x88)
#define MAX_FIFO            60
#define CONFIG_APB_CLK      27000000L

#ifdef  HW_UART_BAUD
    #define UART_CLKDIV         ((CONFIG_APB_CLK+(HW_UART_BAUD*8))/(HW_UART_BAUD*16))
#else
    #define UART_BAUD           38400L
    #define UART_CLKDIV         ((CONFIG_APB_CLK+(UART_BAUD*8))/(UART_BAUD*16))
#endif

#ifdef  HW_UART1_BAUD
    #define UART1_CLKDIV        ((CONFIG_APB_CLK+(HW_UART1_BAUD*8))/(HW_UART1_BAUD*16))
#else
    #define UART1_BAUD           38400L
    #define UART1_CLKDIV        ((CONFIG_APB_CLK+(UART1_BAUD*8))/(UART1_BAUD*16))
#endif
/* APB: 27Mhz, UART baud rate: 19200, UART_CLKDIV: 88 */


#ifdef FIFO
    static unsigned char fifo[MAX_FIFO];
    static unsigned char qf = 0;
    static unsigned char qt = 0;
#endif
/*
 * ժҪ :void serial_init_tw(void)
 *
 * ���� :uart 0 ��ʼ��
 *
 * ���� :��
 *
 * �ش�ֵ : ��
 *
 * ע�� : ��
*/
void serial_init_tw (void)
{
    UART_BASE[UART_SWR] = 0x07;//software reset
    UART_BASE[UART_LCR] = 0x83;
    UART_BASE[UART_DLH] = (UART_CLKDIV >> 8);
    UART_BASE[UART_DLL] = (UART_CLKDIV & 0xff);
    UART_BASE[UART_LCR] = 3;    // N-8-1
    UART_BASE[UART_FCR] = 0xC1;
    UART_BASE[UART_IER] = 1;
}
/*
 * ժҪ :void serial_interrupt(void)
 *
 * ���� :uart 0 �жϿ���
 *
 * ���� :��
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
void serial_interrupt (void)
{
    UART_BASE[UART_FCR] = 0xC7;
    UART_BASE[UART_IER] = 1;

    enable_tw_irq (IRQ_UART0_INT);
}
/*
 * ժҪ :void serial1_init_tw(void)
 *
 * ���� :uart 1 ��ʼ��
 *
 * ���� :��
 *
 * �ش�ֵ : ��
 *
 * ע�� : ��
*/
#if 1
void serial1_init_tw (void)
{
    UART1_BASE[UART_SWR] = 0x07;//software reset
    UART1_BASE[UART_LCR] = 0x83;
    UART1_BASE[UART_DLH] = (UART1_CLKDIV >> 8);
    UART1_BASE[UART_DLL] = (UART1_CLKDIV & 0xff);
    UART1_BASE[UART_LCR] = 3;   // N-8-1
    #ifdef ENABLE_UART1_AFC
    UART1_BASE[UART_MCR] = 0x20;
    #endif
    UART1_BASE[UART_FCR] = 0xC1;
    UART1_BASE[UART_IER] = 1;
}
/*
 * ժҪ :void serial1_interrupt(void)
 *
 * ���� :uart 1 �жϿ���
 *
 * ���� :��
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
void serial1_interrupt (void)
{
    UART1_BASE[UART_FCR] = 0xC7;
    UART1_BASE[UART_IER] = 1;

    enable_tw_irq (IRQ_UART1_INT);
}

#endif

#if 0
char putc_t (char a0)
{
    unsigned short k1;

    if (UART_BASE[UART_SCR] == 0)
    {
        k1 = 200;
    }
    else
    {
        k1 = 6000;
    }

    while (1)
    {
        k1--;
        if (k1 == 0)
        {
            goto EXIT;
        }

        if (UART_BASE[UART_LSR] & 0x40 == 0)
        {
            continue;
        }

        UART_BASE[UART_THR] = a0;
        return 0;
    }

EXIT:
    UART_BASE[UART_SCR] = 1;                    // mark timeout
    UART_BASE[UART_THR] = a0;
    return 0;
}

char puts_t (char *s0)
{
    char *idx = s0;
    while (* (idx))
    {
        putc_t (*idx);
        idx++;
    }

    return 0;
}
#endif
/*
 * ժҪ :static void fill_fifo(void)
 *
 * ���� :uart ʹ��fifo buffer
 *
 * ���� :��
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
#ifdef FIFO
static void fill_fifo (void)
{
    unsigned char xdata q;
    q = qf + 1;

    if (q > MAX_FIFO)
    {
        q = 0;
    }

    while (q != qt && UART_BASE[UART_LSR] & 0x01)
    {
        fifo[qf] = UART_BASE[UART_RBR];
        qf = q;

        q++;
        if (q >= MAX_FIFO)
        {
            q = 0;
        }
    }
}
#endif
/*
 * ժҪ :void putb2_t(const char c)
 *
 * ���� :uart 0 ���һ��byte
 *
 * ���� :��
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
void putb2_t (const char c)
{
    unsigned char i;
    //EA=0;
    for (i = 0; i < 255; i++)
    {
        if (UART_BASE[UART_LSR] & 0x40)
        {
            break;
        }
        #ifdef FIFO
        fill_fifo();
        #endif
    }

    UART_BASE[UART_THR] = c;
    //EA=1;
}
/*
 * ժҪ :void put1b_t(unsigned char c)
 *
 * ���� :uart 1 ���һ��byte
 *
 * ���� :��
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
void put1b_t (unsigned char c)
{
    unsigned char i;

    for (i = 0; i < 255; i++)
    {
        if (UART1_BASE[UART_LSR] & 0x40)
        {
            break;
        }
    }

    UART1_BASE[UART_THR] = c;

}
/*
 * ժҪ :void putb_t(const char c)
 *
 * ���� :uart���һ����Ԫ
 *
 * ���� :const char c=>Ҫ�������Ԫ
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
#ifndef I2C_DEBUG_MODE
void putb_t (const char c)
{
    if (c == '\n')
    {
        putb2_t ('\r');
    }

    putb2_t (c);
}
#endif
/*
 * ժҪ :void putb_t(const char c)
 *
 * ���� :i2c debugʹ��
 *
 * ���� :const char c=>Ҫ�������Ԫ
 *
 * �ش�ֵ :��
 *
 * ע�� : ������������
*/
#ifdef  I2C_DEBUG_MODE
void putb_t (const char c)
{
    if (i2c_count == 0x00)
    {
        IC_WritByte (TWIC_P1, 0xE0 + i2c_count, 0x80);
    }
    i2c_count++;
    if (i2c_count >= 16)
    {

    }
    else if (c == '\n')
    {
        IC_WritByte (TWIC_P1, (0xE0 + i2c_count), '\r');
        IC_WritByte (TWIC_P1, (0xE0 + i2c_count + 1), '\n');
        IC_WritByte (TWIC_P1, (0xE0 + i2c_count + 2), 0);
    }
    else
    {
        IC_WritByte (TWIC_P1, 0xE0 + i2c_count, c);
    }
}
#endif
/*
 * ժҪ :char getb2_t(void)
 *
 * ���� :��ѯȡ��uart����������
 *
 * ���� :��
 *
 * �ش�ֵ :-1 => ������ c=>uart��ȡ�õ���Ԫ
 *
 * ע�� : ��
*/
char getb2_t (void)
{
    #ifdef FIFO
    char xdata c;
    fill_fifo();
    if (qt == qf)
    {
        return -1;
    }

    c = fifo[qt];
    qt++;
    if (qt > MAX_FIFO)
    {
        qt = 0;
    }

    return c;
    #else
    if (UART_BASE[UART_LSR] & 0x01)
    {
        return UART_BASE[UART_RBR];
    }

    return -1;
    #endif
}
/*
 * ժҪ :char getb_t(void)
 *
 * ���� :��ѯȡ��uart����������
 *
 * ���� :��
 *
 * �ش�ֵ :�ش�uart�õ�������
 *
 * ע�� : ��
*/
char getb_t (void)
{
    char xdata c;
    while (1)
    {
        c = getb2_t();
        if (c >= 0)
        {
            break;
        }
    }
    return c;
}


/*
 * ժҪ :void getuart(void)
 *
 * ���� :uart0 ��uart�жϵ����ϴ��浽 buffer��
 *
 * ���� :��
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
void getuart (void)
{
    unsigned char a = 0x00;
    unsigned char count = 0x00;
    while (UART_BASE[0x14] & 0x01)
    {
        a = UART_BASE[0x00];

        count++;
        if (count == 0)
        {
            break;
        }
    }
    clear_tw_irq (IRQ_UART0_INT);
}

/*
 * ժҪ :void getuart1(void)
 *
 * ���� :uart1 ��uart�жϵ����ϴ��浽 buffer��
 *
 * ���� :��
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
void getuart1 (void)
{
	unsigned char a;
	unsigned char count = 0;
	unsigned char temp = 0;
    while (UART1_BASE[0x14] & 0x01)
    {
        a = UART1_BASE[0x00];
		
		temp = urear + 1;
		if (temp >= UART_BUFF_SIZE)
		{
			temp = 0;
		}

        if (temp != ufront)
        {            
            uqueue[temp] = a;
			urear = temp;
        }

        count++;
        if (count == 0)
        {
            break;
        }
    }
    clear_tw_irq (IRQ_UART1_INT);
}

/*
 * ժҪ :unsigned char uartevent(unsigned char *value)
 *
 * ���� :��uart buffer�ڵ�����ȡ��
 *
 * ���� :unsigned char *value =>���ϻ�������ָ��
 *
 * �ش�ֵ :0=>û���� 1=>������
 *
 * ע�� : ��
*/
unsigned char uartevent (unsigned char *value)
{
    unsigned char index;
    if (ufront == urear)
    {
        return 0;
    }
    else
    {
        index = ufront + 1;
        if (index >= UART_BUFF_SIZE)
        {
            index = 0;
        }

        *value = uqueue[index];
        ufront = index;

        return 1;
    }
}

/******************************************************************************
*
* serial_init - initialize a channel
*
* set the selected baud rate and use timer1.
*
* RETURNS: N/A
*/

/*
 * ժҪ :void serial_init (void)
 *
 * ���� :uart 0 and uart1 ��ʼ��
 *
 * ���� :��
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
void serial_init (void)
{
    /* USE EXTERNAL UART */
    // use UART0
    serial_init_tw();
    // use UART1
    serial1_init_tw();
    // select external UART
    IC_WritByte (TWIC_P1, 0xFD, 0x01);
    // enable all io pads
    IC_WritByte (TWIC_P0, PW_MGRCTRL_REG, (IC_ReadByte (TWIC_P0, PW_MGRCTRL_REG) | PWRDN_TOTALPAD));
    // select UART0 RS232RX/RS232TX pin function
    IC_WritByte (TWIC_P1, PIN_FUNCTION_REG, ((IC_ReadByte (TWIC_P1, PIN_FUNCTION_REG) & (~UART0_MASK)) | UART0_EN));
    // select UART1 RS232RX/RS232TX pin function
    IC_WritByte (TWIC_P1, PIN_FUNCTION_REG, (IC_ReadByte (TWIC_P1, PIN_FUNCTION_REG) | UART1_EN));
    #ifdef ENABLE_UART1_AFC
    // select UART1 flow control RTS/CTS pin function
    IC_WritByte (TWIC_P1, PIN_FUNCTION_REG, ((IC_ReadByte (TWIC_P1, PIN_FUNCTION_REG) & (~RLUD_CPUINT_MASK)) | RS232_AFC_EN));
    #endif
    IC_WritByte (TWIC_P0, 0xE0, 0x98); // enable all io pads
}
/*
 * ժҪ :void set_baudrate0(unsigned long baudrate)
 *
 * ���� :uart 0 �趨 baudrate
 *
 * ���� :unsigned long baudrate => �趨baudrate ��ֵ
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
void set_baudrate0 (unsigned long baudrate)
{
    unsigned short uart_clock = 0x00;
    uart_clock = ((CONFIG_APB_CLK + (baudrate * 8)) / (baudrate * 16));
    UART_BASE[UART_LCR] = 0x83;
    UART_BASE[UART_DLH] = (uart_clock >> 8);
    UART_BASE[UART_DLL] = (uart_clock & 0xff);
    UART_BASE[UART_LCR] = 3;    // N-8-1
    UART_BASE[UART_FCR] = 0xC1;
    UART_BASE[UART_IER] = 1;
}
/*
 * ժҪ :void set_baudrate1(unsigned long baudrate)
 *
 * ���� :uart 1 �趨 baudrate
 *
 * ���� :unsigned long baudrate => �趨baudrate ��ֵ
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
void set_baudrate1 (unsigned long baudrate)
{
    unsigned short uart_clock = 0x00;
    uart_clock = ((CONFIG_APB_CLK + (baudrate * 8)) / (baudrate * 16));
    UART1_BASE[UART_LCR] = 0x83;
    UART1_BASE[UART_DLH] = (uart_clock >> 8);
    UART1_BASE[UART_DLL] = (uart_clock & 0xff);
    UART1_BASE[UART_LCR] = 3;   // N-8-1
    UART1_BASE[UART_FCR] = 0xC1;
    UART1_BASE[UART_IER] = 1;
}
/************************************************************************
* ���ڷ���
************************************************************************/
void check_uart1_data (unsigned char uart1data)
{
    unsigned char uart1sum;
    unsigned char i;
    rev_buf[0] = rev_buf[1];
    rev_buf[1] = rev_buf[2];
    rev_buf[2] = rev_buf[3];
    rev_buf[3] = rev_buf[4];
    rev_buf[4] = rev_buf[5];
    rev_buf[5] = rev_buf[6];
    rev_buf[6] = rev_buf[7];
    rev_buf[7] = rev_buf[8];
    rev_buf[8] = rev_buf[9];
    rev_buf[9] = rev_buf[10];
    rev_buf[10] = rev_buf[11];
    rev_buf[11] = uart1data;
    if (rev_buf[0] == 0xaa)
    {
        uart1sum = 0;
        for (i = 1; i < 11; i++)
        {
            uart1sum = (uart1sum + rev_buf[i]) & 0xff;
        }
        if (uart1sum == 0xaa)
        {
            uart1sum = 0x55;
        }
        if (uart1sum == rev_buf[11])
        {
            uart1_rev_data();
            put_uart1_timer_event();
        }
    }
}

void put_uart1_timer_event (void)
{
    put1b_t (0xaa);
    put1b_t (0x4f);
    put1b_t (0x4b);
    put1b_t (0x9a);
}

void put_uart1_key_event (void)
{
    put1b_t (0xaa);
    put1b_t (0x6f);
    put1b_t (0x6b);
    put1b_t (0xda);
}

