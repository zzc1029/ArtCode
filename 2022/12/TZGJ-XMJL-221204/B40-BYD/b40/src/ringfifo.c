/*
 * fifo.c
 *
 *  Created on: 2021-12-17
 *      Author: stankong
 */



#include "stdint.h"
#include "string.h"
#include "ringfifo.h"


#define Min(len1,len2)  ((len1)<(len2)?(len1):(len2))

void fifo_init(RingFifo* fifo,uint8_t *buff,uint32_t len)
{
    fifo->wr_index = 0;
    fifo->rd_index = 0;
    fifo->ovfcount = 0;
    fifo->max_len = len;
    fifo->buff = buff;
}

void fifo_reset(RingFifo*fifo)
{
    fifo->wr_index = 0;
    fifo->rd_index = 0;
    fifo->ovfcount = 0;
}

uint32_t fifo_append_bytes(RingFifo*fifo,uint8_t* buffer, uint32_t len)
{
    register uint32_t l,temp,temp2;
    temp = fifo_get_free(fifo);
    if(len > temp)
    {
    	len = temp;
    	Fifo_Err_On();
    	fifo->ovfcount++;
    }
   	temp = (fifo->wr_index & (fifo->max_len - 1));
   	temp2 = fifo->max_len - temp;
    /* first put the data starting from fifo->in to buffer end */
    l = Min(len, temp2);
    memcpy(fifo->buff + temp, buffer, l);
    /* then put the rest (if any) at the beginning of the buffer */
    memcpy(fifo->buff, buffer + l, len - l);
    fifo->wr_index += len;

    return len;
}


uint32_t fifo_get_bytes(RingFifo*fifo,uint8_t*buffer,uint32_t len)
{
    register uint32_t l,temp,temp2;
    temp = fifo->wr_index - fifo->rd_index;
    len = Min(len, temp);
    temp =(fifo->rd_index & (fifo->max_len - 1));
    temp2 = fifo->max_len - temp;
    /* first get the data from fifo->out until the end of the buffer */
    l = Min(len, temp2);
    memcpy(buffer, fifo->buff + temp, l);
    /* then get the rest (if any) from the beginning of the buffer */
    memcpy(buffer + l, fifo->buff, len - l);
    fifo->rd_index += len;
    return len;
}



uint32_t fifo_peek_bytes(RingFifo*fifo,uint32_t offset,uint8_t * buffer, uint32_t len)
{
    register uint32_t l,start;
    start = fifo->rd_index + offset;
    if((start) >= fifo->wr_index)
        return 0;
    len = Min(len, fifo->wr_index - start);
    /* first get the data from fifo->out until the end of the buffer */
    l = Min(len, fifo->max_len - (start & (fifo->max_len - 1)));
    memcpy(buffer, fifo->buff + (start & (fifo->max_len - 1)), l);
    /* then get the rest (if any) from the beginning of the buffer */
    memcpy(buffer + l, fifo->buff, len - l);
    return len;
}




