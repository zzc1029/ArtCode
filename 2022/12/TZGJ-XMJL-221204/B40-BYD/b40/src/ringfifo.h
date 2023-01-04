/*
 * fifo.h
 *
 *  Created on: 2021-12-17
 *      Author: stankong
 */

#ifndef FIFO_H_
#define FIFO_H_

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#include "stdint.h"

typedef struct _fifo
{
	volatile uint32_t wr_index;
	volatile uint32_t rd_index;
	volatile uint32_t count;
	volatile uint32_t ovfcount;
	uint32_t max_len;
	uint8_t * buff;
} RingFifo;

#define Fifo_Err_On()

extern uint32_t fifo_peek_bytes(RingFifo*fifo,uint32_t offset,uint8_t * buffer, uint32_t len);
extern uint32_t fifo_read_offsRet_bytes(RingFifo*fifo,uint32_t offset,uint8_t * data,uint32_t len);
extern uint32_t fifo_get_bytes(RingFifo*fifo,uint8_t*data,uint32_t len);
extern void fifo_init(RingFifo* fifo,uint8_t *buff,uint32_t len);
extern uint32_t fifo_append_bytes(RingFifo*fifo,uint8_t*data,uint32_t len);
extern void fifo_reset(RingFifo*fifo);

#define fifo_append_byte(fifo,data) 	{if(fifo_get_free(fifo)!=0) (fifo->buff + (fifo->wr_index++ & (fifo->max_len - 1)))[0] = data; else{Err_On();fifo->ovfcount++;}}
#define fifo_get_byte(fifo)  			((fifo->buff + (fifo->rd_index++ & (fifo->max_len - 1)))[0])
#define fifo_peek_byte(fifo)  			((fifo->buff + (fifo->rd_index & (fifo->max_len - 1)))[0])
#define fifo_peek_offset_byte(fifo,y)  	((fifo->buff + ((fifo->rd_index + y) & (fifo->max_len - 1)))[0])
#define fifo_have_data(fifo) 			(fifo->wr_index != fifo->rd_index)
#define fifo_get_free(fifo)  			(fifo->max_len - fifo->wr_index + fifo->rd_index)
#define fifo_get_count(fifo) 			(fifo->wr_index - fifo->rd_index)

#define fifo_drop_bytes(fifo,len) 		{fifo->rd_index += (len);}


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */



#endif /* FIFO_H_ */
