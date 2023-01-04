/*
 * canfifo.h
 *
 *  Created on: 2021-8-5
 *      Author: ART
 */

#ifndef _CANFIFO_H
#define _CANFIFO_H

#define CANSENDBUFFNUM     (6)  //T123���ͻ���������λ����ע��:5 ���� 2��6�η� =  64��


#define CANSENDBUFFDEEP    ((1<<CANSENDBUFFNUM))
#define CANSENDBUFFMASK    ((1<<CANSENDBUFFNUM)-1)


#define can_fifo_have_data(fifo)    (fifo.wr_index != fifo.rd_index)
//#define can_fifo_get_free(fifo)     (fifo->max_len - fifo->wr_index + fifo->rd_index)
#define can_fifo_get_free(fifo)     (fifo.max_len - fifo.wr_index + fifo.rd_index)

#define can_fifo_get_count(fifo)    (fifo.wr_index - fifo.rd_index)


//can���� һ֡ʹ��
typedef struct
{
  //CAN����״̬
  unsigned char sended;
  //CAN ID
  unsigned int ID;
  //CAN����   ��׼������չ
  unsigned char type;
  unsigned char data[8];
  unsigned char len;
}SendCanFifo;

//can����ȫ�ֱ���
typedef struct
{
	int wr_index;
	int rd_index;
	int ovfcount; //��������ʧ
	int errcount; //���ͳ������Դ���
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



