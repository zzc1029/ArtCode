/*
 * keyfif.c
 *
 *  Created on: 2021-8-6
 *      Author: ART
 */

#include "keyfifo.h"

MESSAGE_FIFO MsgFifos[MSG_FIFO_COUNT];

void message_init(void)
{
	unsigned char i, j;

	for(i = 0; i < MSG_FIFO_COUNT; i++)
	{
		MsgFifos[i].IndexHead = 0;
		MsgFifos[i].Count = 0;
		for(j = 0; j < MAX_FIFO_DEPTH; j++)
		{
			MsgFifos[i].Buf[j] = 0;
		}
	}
}

void message_send(unsigned char MsgFifoIndex, unsigned char event)
{
	MESSAGE_FIFO* pMsgFifo = &MsgFifos[MsgFifoIndex];

	if(pMsgFifo->Count >= MAX_FIFO_DEPTH)		//fifo full
	{
//		DBG(("fifo %bu is full!\n", MsgFifoIndex));
	}
	pMsgFifo->Buf[(pMsgFifo->IndexHead + (pMsgFifo->Count++)) % MAX_FIFO_DEPTH] = event;
}

unsigned char message_get(unsigned char MsgFifoIndex)
{
	unsigned char event = MSG_NONE;
	MESSAGE_FIFO* pMsgFifo = &MsgFifos[MsgFifoIndex];

	if(pMsgFifo->Count)			//fifo is not empty
	{
		event = pMsgFifo->Buf[pMsgFifo->IndexHead];
		pMsgFifo->IndexHead = (pMsgFifo->IndexHead + 1) % MAX_FIFO_DEPTH;
		pMsgFifo->Count--;
	}

	return event;
}
