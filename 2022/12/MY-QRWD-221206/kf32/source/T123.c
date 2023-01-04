/*
 * T123.c
 *
 *  Created on: 2021-8-6
 *      Author: ART
 */


#include "system_init.h"


#define SENDBUFFNUM     (8)  //T123发送缓冲区长度位数，注意:5 代表 2的6次方 =  64个


#define SENDBUFFDEEP    ((1<<SENDBUFFNUM))
#define SENDBUFFMASK    ((1<<SENDBUFFNUM)-1)

SendToT123X SendBuff;

SendToT123Stru Sendbuffx[SENDBUFFDEEP];

SendToT123Stru domsg;



static void  CheckSum()
{
    uint8_t i;
    communicate_T123_data[11] = 0;
    for(i = 1; i < 11; i++)
        communicate_T123_data[11] += communicate_T123_data[i];
    if(communicate_T123_data[11] == 0xaa)
        communicate_T123_data[11] = 0x55;

}

u8  SendToT123Loop = 0;
u8  SendToT123Delay = 0;

void AddData(SendToT123Stru * da)
{
    int i;

    communicate_T123_data[0] = 0xAA;

	CheckSum();

    for(i =0; i<12; i++)
    {
        da->data[i] = communicate_T123_data[i];
    }
    da->sended = Ready;
    da->loop = SendToT123Loop;
    SendToT123Loop = 0;
    da->delay = SendToT123Delay;
    SendToT123Delay = 0;
	if(MPC5602_CALL_T123)
		CAN_T123();
}


void GetData(SendToT123Stru *da)
{
    int i;
    for(i=0; i<12; i++)
        domsg.data[i] = da->data[i];
    domsg.loop = da->loop;
    domsg.sended = da->sended;
    domsg.delay = da->delay;
}

#define fifo_have_data(fifo)            (fifo->wr_index != fifo->rd_index)
#define fifo_get_free(fifo)             (fifo->max_len - fifo->wr_index + fifo->rd_index)
#define fifo_get_count(fifo)            (fifo->wr_index - fifo->rd_index)
#define Min(x,y) (((x)<(y))?(x):(y))


void fifo_set_free(SendToT123X*fifo)
{
    fifo->rd_index = fifo->wr_index;
}

uint32_t fifo_in(SendToT123X*fifo)
{
    register uint32_t l,temp;
    temp = fifo_get_free(fifo);
    if(1 > temp)
    {
        fifo->ovfcount++;
        return 0;
    }
    temp = (fifo->wr_index & (fifo->max_len - 1));
    AddData(fifo->buff + temp);
    fifo->wr_index += 1;

    return 1;
}



uint32_t fifo_out(SendToT123X *fifo)
{
    register uint32_t l,temp;
    temp = fifo_get_count(fifo);
    if(temp < 1)
    {
        return 0;
    }
    temp =(fifo->rd_index & (fifo->max_len - 1));
    GetData(fifo->buff + temp);
    fifo->rd_index += 1;
    return 1;
}


void fifo_init(SendToT123X* fifo,SendToT123Stru*buff,uint32_t len)
{
    fifo->wr_index = 0;
    fifo->rd_index = 0;
    fifo->ovfcount = 0;
    fifo->max_len = len;
    fifo->buff = buff;
}

void fifo_reset(SendToT123X*fifo)
{
    fifo->wr_index = 0;
    fifo->rd_index = 0;
    fifo->ovfcount = 0;
}


void InitSendToT123()
{
    fifo_init(&SendBuff,Sendbuffx,SENDBUFFDEEP);
    domsg.sended = Sended;
}
void SendToT123()
{
    static u8 arr = 0;
    int i;
    if((domsg.sended == Sended)||(domsg.sended == SendErr))
    {
        fifo_out(&SendBuff);
    }
    switch(domsg.sended)
    {
        case Ready:
            t123Ans = 0;
            TransmitDataTo123(domsg.data,12);
            domsg.sended ++;
            arr = domsg.loop;
            break;
        case Check1:
			//domsg.sended ++;
			//break;
        case Check2:
            if((arr == 0)||(t123Ans == 1))
            {
            	arr = domsg.loop;
                if(t123Ans == 1)
                {
                    //Break_Pent++;
                    if(domsg.delay>0)
                    {
                        domsg.sended = SendNop;
                    }
                    else
                    {
                        domsg.sended = Sended;
                    }
                }
                else
                {
                    domsg.sended++;
                    if(domsg.sended < SendErr)
                    {
                    	TransmitDataTo123(domsg.data,12);
                    }
                    else
                    {
                        SendBuff.errcount++ ;
                        if(domsg.delay>0)
                            domsg.sended = SendNop;
                    }
                }
            }
            else
                arr --;
            break;
        case SendNop:
            if(domsg.delay > 0)
            {
                domsg.delay--;
            }
            else
            {
                domsg.sended = Sended;
            }
            break;
    }
}




