/**
 *  @file   c_root.c
 *  @brief  main program for demo code
 *  $Id: c_root.c,v 1.4 2012/12/17 05:30:48 dos1236 Exp $
 *  $Author: dos1236 $
 *  $Revision: 1.4 $
 *
 *  Copyright (c) 2012 Terawins Inc. All rights reserved.
 * 
 *  @date   2012/06/04  ken 	New file.
 *
 */

#include <reg51.h>
#include "sys.h"
#include "tw_widget_sys.h"
//#include "init.h"
#include "spiosd.h"
#include "panel.h"
#include "check_event.h"
#include "rc.h"
#include "osd2api.h"
#include "display.h"
#include "uart.h"
#include "serial.h"
#include "page_main_internal.h"
#include "Videodetect.h"

/* init.c */
extern void init(void);


void main(void)
{
	char data rc=0;
	unsigned int c;
	TW_EVENT *events;
	

	init();

	panel_init();
	
	spiosd_init(0x11E, 0x24, 0x99, 0x27);

	//do_calibration(0);		/* touch panel calibration */

	tw_widget_init();

	resource_init();

	osd_init();

	CVDInit();
	auto_detection_ctrl(1);
	
	/*IC_WritByte(TWIC_P0,0x0f,0x40);
	IC_WritByte(TWIC_P0,0x18,0x30);
	IC_WritByte(TWIC_P0,0x19,0x0c);*/
	
	IC_WritByte(TWIC_P0,0x0f,0x00);
	IC_WritByte(TWIC_P0,0x19,0x80);
	IC_WritByte(TWIC_P1,0x13,0x06);
	IC_WritByte(TWIC_P1,0x66,0xff);
	for(c = 0; c < 35000; c++){;}
	tw_menu_draw(&page_main_internal_osd2_1_menu);//OSD2³õÊ¼»¯
	osd_enable();
	osd_blink(5,50);
	display_init();
	serial_interrupt();
	serial1_interrupt();


	while(1) {
		check_event();
		//get_command();

		protocl_event(getdata());
		
		events = get_event();
		rc = tw_page_process(events);
		//put_nodify(events, rc);
	}
}
