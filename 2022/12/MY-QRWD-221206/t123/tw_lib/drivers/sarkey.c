/*
 *  @file   sarkey.c
 *  @brief  SAR Key driver 
 *  $Id: sarkey.c,v 1.4 2013/06/18 02:04:23 kevin Exp $
 *  $Author: kevin $
 *  $Revision: 1.4 $
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
#include "sarkey.h"

static unsigned char squeue[SARKEY_BUFF_SIZE];
static unsigned char sfront=SARKEY_BUFF_SIZE-1; 
static unsigned char srear=SARKEY_BUFF_SIZE-1;
static unsigned char SarRepeat;
static unsigned char sarcount;
/*
 * ժҪ :void CheckSAR(void)
 *
 * ���� :SARKEY �жϴ������
 *
 * ���� :��
 *
 * �ش�ֵ : ��
 *
 * ע�� : ��
*/
void CheckSAR(void)
{
	unsigned char value=0x00;
	value=IC_ReadByte(TWIC_P3, 0x24);
	#if 1
	if((value>=(SARKEY_TVAL1-5))&&(value<=(SARKEY_TVAL1+5)))
	{
		value=0x01;
	}
	else if((value>=(SARKEY_TVAL2-5))&&(value<=(SARKEY_TVAL2+5)))
	{
		value=0x02;
	}
	else if((value>=(SARKEY_TVAL3-5))&&(value<=(SARKEY_TVAL3+5)))
	{
		value=0x03;
	}
	else if((value>=(SARKEY_TVAL4-5))&&(value<=(SARKEY_TVAL4+5)))
	{
		value=0x04;
	}
	else if((value>=(SARKEY_TVAL5-5))&&(value<=(SARKEY_TVAL5+5)))
	{
		value=0x05;
	}
	else if((value>=(SARKEY_TVAL6-5))&&(value<=(SARKEY_TVAL6+5)))
	{
		value=0x06;
	}
	else
	{
		goto EXIT;
	}
	#endif
	#if 0
	if(value==SARKEY_TVAL1)
	{
		value=0x01;
	}
	else if(value==SARKEY_TVAL2)
	{
		value=0x02;
	}
	else if(value==SARKEY_TVAL3)
	{
		value=0x03;
	}
	else if(value==SARKEY_TVAL4)
	{
		value=0x04;
	}
	else if(value==SARKEY_TVAL5)
	{
		value=0x05;
	}
	else if(value==SARKEY_TVAL6)
	{
		value=0x06;
	}
	else
	{
		return;
	}
	#endif
	srear=(srear+1)%SARKEY_BUFF_SIZE;
	if(srear==sfront)
	{
		if(srear==0)
		{
			srear=10-1;//max value
		}
		else
		{
			srear=srear-1;
		}
	}
	else
	{
		squeue[srear]=value;
	}
	SarRepeat=1;//check repeat key by time interrupt  
	if(value==0xff)
		SarRepeat=0;
	twdDelay(500);
EXIT:
	clear_tw_irq(IRQ_SAR1_TOGGLE);	
}

/*
 * ժҪ :unsigned char SARscan(unsigned char *value)
 *
 * ���� :��SARKEYȡֵ
 *
 * ���� :unsigned char *value =>�ὫSARKEYֵ���� *value
 *
 * �ش�ֵ : 0=>������ 1=>������
 *
 * ע�� : ��
*/
unsigned char SARscan(unsigned char *value)
{
	unsigned char temp;
	if(sfront==srear)
	{
		return 0;
	}
	else
	{
			sfront=(sfront+1)%SARKEY_BUFF_SIZE;
			temp=squeue[sfront];
			*value=temp;
			return 1;
	}
}
/*
 * ժҪ :void sarkey_init()
 *
 * ���� :SARKEY ��ʼ��
 *
 * ���� :��
 *
 * �ش�ֵ : ��
 *
 * ע�� : ��
*/
void sarkey_init()
{
	IC_WritByte(TWIC_P3,0X23,IC_ReadByte(TWIC_P3,0x23)|0x02);//POWER UP
	IC_WritByte(TWIC_P3,0X23,IC_ReadByte(TWIC_P3,0x23)|0x01);//Enable debounce
	IC_WritByte(TWIC_P3,0X25,0X15);//THRESHOLD
	
	enable_tw_irq(IRQ_SAR1_TOGGLE);	
}
