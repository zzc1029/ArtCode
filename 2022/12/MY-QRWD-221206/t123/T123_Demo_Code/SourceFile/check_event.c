/**
 *  @file   check_event.c
 *  @brief  check event queue
 *  $Id: check_event.c,v 1.2 2012/12/04 03:11:46 kevin Exp $
 *  $Author: kevin $
 *  $Revision: 1.2 $
 *
 *  Copyright (c) 2011 Terawins Inc. All rights reserved.
 * 
 *  @date   2011/08/12  ken 	New file.
 *
 */

#include "config.h"
#include "sys.h"
#include "tw_widget_sys.h"
//#include "touch.h"
//#include "ir.h"
#include "serial.h"
#include "timer.h"
#include "tw_timer.h"
#include "check_event.h"
#include "videodetect.h"
#include "panel.h"
//#include "mcu_if.h"

void check_event(void)
{
		TW_EVENT s_event;
		unsigned char rc=0x00;
		unsigned char ir=0x00;
		unsigned char sar=0x00;
		unsigned char uart=0x00;
		static unsigned char signal_active=0;
		static unsigned char signal_std=0;
		unsigned char i;

/*
		touchd t_value={0,0,0};
		t_value=touch_read();
		
		if((t_value.x!=0)||(t_value.y!=0))
		{
			//DBG_PRINT("x=%d y=%d status=%d\r\n",(int)t_value.x,(int)t_value.y,(int)t_value.status);
			if(t_value.status==0)
			{
				s_event.type = TW_EVENT_TYPE_TOUCH_DOWN;
			}
			else if(t_value.status==1)
			{
				s_event.type = TW_EVENT_TYPE_TOUCH_MOTION;
			}
			else if(t_value.status==2)
			{
				s_event.type = TW_EVENT_TYPE_TOUCH_RELEASE ;
			}
			else
				return;
			s_event.touch_panel.x= t_value.x;
			s_event.touch_panel.y= t_value.y;
			s_event.touch_panel.cpu_count = repeat_value;
			repeat_value=0x00;
			put_event(&s_event);
		}
		else
		{
			t_value=check_repeat(td_rep_thres);
			if((t_value.x!=0)||(t_value.y!=0))
			{
				s_event.touch_panel.x= t_value.x;
				s_event.touch_panel.y= t_value.y;
				s_event.type=TW_EVENT_TYPE_TOUCH_REPEAT;
				put_event(&s_event);
			}
		}

		rc=IRscan(&ir);
		if(rc!=0)
		{
			s_event.type = TW_EVENT_TYPE_IR_DOWN;
			s_event.ircode.ch = ir;
			//DBG_PRINT("front=%d rear=%d\r\n",(int)front,(int)rear);
			put_event(&s_event);
		}
*/
		for(i=0;i<12;i++)
		{
			rc=uartevent(&uart);
			if(rc!=0)
			{
				check_uart1_data(uart);
				//s_event.type=TW_EVENT_TYPE_UART;
				//s_event.uart.ch=uart;
				//put_event(&s_event);
				//DBG_PRINT("uart=%d\r\n",(int)uart);		
			}
			else
				break;
		}

		if(TIMER0_OUT_FLAG)
		{
			TIMER0_OUT_FLAG=0;
			s_event.type = TW_EVENT_TYPE_TIMEOUT;
			s_event.timer.tid = 0;
			put_event(&s_event);
		}
		
		if(TIMER1_OUT_FLAG)
		{
			TIMER1_OUT_FLAG=0;
			s_event.type = TW_EVENT_TYPE_TIMEOUT;
			s_event.timer.tid = 1;
			put_event(&s_event);
		}

		if(TW_TIMER_OUT_FLAG)
		{
			TW_TIMER_OUT_FLAG=0;
			s_event.type = TW_EVENT_TYPE_TIMEOUT;
			s_event.timer.tid = 2;
			put_event(&s_event);
		}
		SingalDetect();
		if((sigstate.SigActive!=signal_active)||((sigstate.SigActive==Signal_Set)&&(sigstate.SigStd!=signal_std)))
		{
			s_event.type=TW_EVENT_TYPE_SINGNAL;
			signal_active=sigstate.SigActive;
			signal_std=sigstate.SigStd;
			s_event.signal.SigActive=sigstate.SigActive;
			s_event.signal.SigSrc=sigstate.SigSrc;
			s_event.signal.SigStd=sigstate.SigStd;
			put_event(&s_event);
			dbg(2, ("1.SIGNAL ACT=%bd	SRC=%bd	STD=%bd\r\n",s_event.signal.SigActive,s_event.signal.SigSrc,s_event.signal.SigStd));
		}
}
