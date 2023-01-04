/**
 *  @file   serial.h
 *  @brief  head file for SERIAL.c
 *  $Id: serial.h,v 1.3 2013/03/28 08:43:35 dos1236 Exp $
 *  $Author: dos1236 $
 *  $Revision: 1.3 $
 *
 *  Copyright (c) 2011 Terawins Inc. All rights reserved.
 * 
 *  @date   2011/08/12  ken 	New file.
 *
 */

#ifndef _SERIAL_H
#define _SERIAL_H
/***************************************************************
//ÐÂÔö¼Ó

***************************************************************/
#ifndef UART_BUFF_SIZE
	#define UART_BUFF_SIZE	48
#endif
#define REC_BUFF_SIZE	12
extern unsigned char rev_buf[REC_BUFF_SIZE];
extern bit UART1_OK_FLAG;
/***************************************************************
***************************************************************/
//#define I2C_DEBUG_MODE

extern void serial_init(void);
extern void putb_t(const char c);
extern void put1b_t(unsigned char c);
extern char getb_t(void);
extern void getuart(void);
extern void getuart1(void);
extern unsigned char uartevent(unsigned char *value);
extern void serial_interrupt(void);
extern void serial1_interrupt(void);
extern void set_baudrate0(unsigned long baudrate);
extern void set_baudrate1(unsigned long baudrate);

extern unsigned char i2c_count;

extern void check_uart1_data(unsigned char uart1data);

extern void put_uart1_timer_event(void);
extern void put_uart1_key_event(void);



#endif /* _SERIAL_H */
