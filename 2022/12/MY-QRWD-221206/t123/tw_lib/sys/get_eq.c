/**
 *  @file   get_eq.c
 *  @brief  get event queue
 *  $Id: get_eq.c,v 1.4 2013/04/02 05:42:18 dos1236 Exp $
 *  $Author: dos1236 $
 *  $Revision: 1.4 $
 *
 *  Copyright (c) 2011 Terawins Inc. All rights reserved.
 * 
 *  @date   2011/08/12  ken 	New file.
 *
 */

#include "sys.h"
#include "tw_widget_sys.h"

/* Event Queue */
#define EQ_SIZE	8 //16
TW_EVENT event_queue[EQ_SIZE];
unsigned char event_queue_idx = 0;
unsigned char event_queue_cnt = 0;
/*
 * ժҪ :void put_event (TW_EVENT* event)
 *
 * ���� :����event��event buffer
 *
 * ���� :TW_EVENT * event=>TW_EVENT�ṹָ��
 *
 * �ش�ֵ :�ش�TW_EVENT�ṹָ��
 *
 * ע�� : ��
*/
void put_event (TW_EVENT* event)
{
	unsigned char idx;

	if (event_queue_cnt >= EQ_SIZE) {
		WARN (("event queue full; data lost!\n"));
		return;
	}

	idx = (event_queue_idx + event_queue_cnt) % EQ_SIZE;
	event_queue[idx] = *event;
	event_queue_cnt++;
	dbg(2, ("event:%bd, EQ<< cnt=%bd\n", event->type, (char)event_queue_cnt));
}
/*
 * ժҪ :TW_EVENT* get_event (void)
 *
 * ���� :ȡ��EVENT BUFFER�ڵ�TW_EVENT�ṹָ��
 *
 * ���� :��
 *
 * �ش�ֵ :�ش�TW_EVENT�ṹָ��
 *
 * ע�� : ��
*/
TW_EVENT* get_event (void)
{
	unsigned char id;

	if (event_queue_cnt == 0) {
		/* queue empty; no available data */
		event_queue[0].type = TW_EVENT_TYPE_NONE;
		return &event_queue[0];
	}

	id = event_queue_idx;
	event_queue_idx = (event_queue_idx + 1) % EQ_SIZE;
	event_queue_cnt--;
	dbg(2, ("event: %bd, EQ>> cnt=%bd\n", event_queue[id].type, (char)event_queue_cnt));

	return &event_queue[id];
}
/*
 * ժҪ :void clear_event(void)
 *
 * ���� :���EVENT BUFFER
 *
 * ���� :��
 *
 * �ش�ֵ :��
 *
 * ע�� : ��
*/
void clear_event(void)
{
	event_queue_cnt= 0;	
}
