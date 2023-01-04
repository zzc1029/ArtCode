/*
 * canfifo.h
 *
 *  Created on: 2021-8-5
 *      Author: ART
 */

#ifndef _CANFIFO_H
#define _CANFIFO_H

#define CANSENDBUFFNUM     (6)  //T123发送缓冲区长度位数，注意:5 代表 2的6次方 =  64个


#define CANSENDBUFFDEEP    ((1<<CANSENDBUFFNUM))
#define CANSENDBUFFMASK    ((1<<CANSENDBUFFNUM)-1)


#define can_fifo_have_data(fifo)    (fifo.wr_index != fifo.rd_index)
//#define can_fifo_get_free(fifo)     (fifo->max_len - fifo->wr_index + fifo->rd_index)
#define can_fifo_get_free(fifo)     (fifo.max_len - fifo.wr_index + fifo.rd_index)

#define can_fifo_get_count(fifo)    (fifo.wr_index - fifo.rd_index)


//can发送 一帧使用
typedef struct
{
  //CAN包的状态
  unsigned char sended;
  //CAN ID
  unsigned int ID;
  //CAN类型   标准还是扩展
  unsigned char type;
  unsigned char data[8];
  unsigned char len;
}SendCanFifo;

//can发送全局变量
typedef struct
{
	int wr_index;
	int rd_index;
	int ovfcount; //包满，丢失
	int errcount; //发送超过重试次数
	SendCanFifo * buff;
	int max_len;
} SendToCan;


enum
{
  CANSENDED = 0,
  CANDELAYING,
  CANSUCCEED
};







#endif



