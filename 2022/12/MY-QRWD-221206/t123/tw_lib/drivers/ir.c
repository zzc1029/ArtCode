/*
 *  @file   ir.c
 *  @brief  IR driver 
 *  $Id: ir.c,v 1.3 2013/04/02 05:42:18 dos1236 Exp $
 *  $Author: dos1236 $
 *  $Revision: 1.3 $
 *
 *  Copyright (c) 2012 Terawins Inc. All rights reserved.
 * 
 *  @date   2012/06/11  yc New file.
 *
 */

#include "sys.h"
#include "reg_tw.h"
#include "iccontrol.h"
#include "tw_irq.h"
#include "ir.h"

static unsigned char queue[IR_BUFF_SIZE];
static unsigned char front=IR_BUFF_SIZE-1; 
static unsigned char rear=IR_BUFF_SIZE-1;
static unsigned char irRepeat=0 ;
/*
 * ժҪ :void ir_clear(void)
 *
 * ���� :���IR QUEUE BUFFER
 *
 * ���� :��
 *
 * �ش�ֵ : ��
 *
 * ע�� : ��
*/
void ir_clear(void)
{
	front=IR_BUFF_SIZE-1;
	rear=IR_BUFF_SIZE-1;
}
/*
 * ժҪ :void CheckIR(void)
 *
 * ���� :IR�жϴ������
 *
 * ���� :��
 *
 * �ش�ֵ : ��
 *
 * ע�� : ��
*/
void CheckIR(void)
{
		unsigned short tempIRSYS;
		tempIRSYS = IC_ReadByte(TWIC_P1,0x43);
		tempIRSYS <<= 8;
		tempIRSYS |= IC_ReadByte(TWIC_P1,0x42);
		if(tempIRSYS == IR_SYS_CODE) //0xff00
		{	
			unsigned char tempIRStd,tempIRCode;
			tempIRCode = IC_ReadByte(TWIC_P1,0x44);
			tempIRStd = IC_ReadByte(TWIC_P1,0x45);
			if(IC_ReadByte(TWIC_P1, 0x47)&0x01) //repeat
			{
				if(irRepeat<4)
				{
					irRepeat++;//repeat 4 times as a interrupt
					clear_tw_irq(IRQ_IR_PACKET);
					return;
				}	
			}
			if(tempIRCode == ~tempIRStd)
			{
				rear=(rear+1)%IR_BUFF_SIZE;
				if(rear==front)
				{
					if(rear==0)
					{
						rear=10-1;//max value
					}
					else
					{
						rear=rear-1;
					}
				}
				else
				{
					queue[rear]=tempIRCode;
				} 
			}
			irRepeat=0;
		}	
	clear_tw_irq(IRQ_IR_PACKET);

}
/*
 * ժҪ :unsigned char IRscan(unsigned char *value)
 *
 * ���� :��IRȡֵ
 *
 * ���� :unsigned char *value =>�ὫIRֵ���� *value
 *
 * �ش�ֵ : 0=>������ 1=>������
 *
 * ע�� : ��
*/
unsigned char IRscan(unsigned char *value)
{
	unsigned char temp;
	if(front==rear)
	{
		return 0;
	}
	else
	{
		front=(front+1)%IR_BUFF_SIZE;
		temp=queue[front];
		*value=temp;
		return 1;
	}
}
/*
 * ժҪ :void ir_init(void) 
 *
 * ���� :IR��ʼ��
 *
 * ���� :��
 *
 * �ش�ֵ : ��
 *
 * ע�� : ��
*/
void ir_init(void)
{
	IC_WritByte(TWIC_P1, 0x47,0x85);
	enable_tw_irq(IRQ_IR_PACKET);	
}
