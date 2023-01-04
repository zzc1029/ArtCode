/**
 *  @file   tw_timer.h
 *  @brief  terawins 10ms timer driver
 *  $Id: tw_timer.c,v 1.4 2013/04/02 05:42:18 dos1236 Exp $
 *  $Author: dos1236 $
 *  $Revision: 1.4 $
 *
 *  Copyright (c) 2011 Terawins Inc. All rights reserved.
 * 
 *  @date   2011/08/12  ken 	New file.
 *
 */

#include "sys.h"
#include "tw_timer.h"
#include "tw_irq.h"

bit TW_TIMER_OUT_FLAG=0;
static unsigned long data TW_TIMER_OUT=0;
static unsigned long data TW_TIMER_CN=0;
unsigned char TP_TIME=0x00;
/*
 * ժҪ :tw_timer_start(void)
 *
 * ���� :tw_timer ����(�жϿ���)
 *
 * ���� :��
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
static void tw_timer_start(void)
{
	enable_tw_irq(IRQ_10MS_TIME);
}
/*
 * ժҪ :tw_timer_stop(void)
 *
 * ���� :tw_timer �ر�(�жϹر�)
 *
 * ���� :��
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
static void tw_timer_stop(void)
{
	disable_tw_irq(IRQ_10MS_TIME);
}
/*
 * ժҪ :void tw_timer_open(unsigned long count)
 *
 * ���� :����twtimer��ʼ�趨 �����趨�ж�ʱ�� ��10msΪ��λ �жϿ���
 *
 * ���� :unsigned long count(��10ms second�趨ʱ��)
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
void tw_timer_open(unsigned long count)
{
	TW_TIMER_OUT=count;
	TW_TIMER_CN=0;
	TW_TIMER_OUT_FLAG=0;
	tw_timer_start();	
}
/*
 * ժҪ :tw_timer_close(void)
 *
 * ���� :���tw timer��ʼ�趨 ���ҹر��ж�
 *
 * ���� :��
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
void tw_timer_close(void)
{
	TW_TIMER_OUT=0;
	TW_TIMER_CN=0;
	TW_TIMER_OUT_FLAG=0;
	tw_timer_stop();	
}
/*
 * ժҪ :tw_timer_isr(void)
 *
 * ���� :tw timer �жϴ������
 *
 * ���� :��
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
void tw_timer_isr(void)
{
	TW_TIMER_CN++;
	TP_TIME++;
	if(TW_TIMER_CN>=TW_TIMER_OUT)
	{
		TW_TIMER_CN=0;
		TW_TIMER_OUT_FLAG=1;
	}
	clear_tw_irq(IRQ_10MS_TIME);
}
