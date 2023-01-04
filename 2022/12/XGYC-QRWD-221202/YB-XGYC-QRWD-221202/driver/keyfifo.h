/*
 * keyfifo.h
 *
 *  Created on: 2021-8-6
 *      Author: ART
 */


#ifndef _KEYFIFO_H_
#define _KEYFIFO_H_

typedef enum _MESSAGE
{
		MSG_NONE = 0x00

} MESSAGE;

#define	MAX_FIFO_DEPTH	8

typedef enum _MSG_FIFO_INDEX
{
	MSG_FIFO_KEY = 0,
	MSG_FIFO_DISP ,
	MSG_FIFO_SYS,
	MSG_FIFO_COUNT			//message fifo count

} MSG_FIFO_INDEX;


typedef struct _MESSAGE_FIFO
{
 	unsigned char IndexHead;
 	unsigned char Count;
 	unsigned char Buf[MAX_FIFO_DEPTH];

} MESSAGE_FIFO;


extern MESSAGE_FIFO MsgFifos[MSG_FIFO_COUNT];
extern void message_init(void);


extern void message_send(unsigned char MsgFifoIndex, unsigned char event);

extern unsigned char message_get(unsigned char MsgFifoIndex);




#endif

