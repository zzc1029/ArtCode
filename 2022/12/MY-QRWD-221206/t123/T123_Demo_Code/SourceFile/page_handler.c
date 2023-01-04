/**
 *  @file   page_handler.c
 *  @brief  terawins UI page handler
 *  $Id: page_handler.c,v 1.3 2012/12/04 03:11:46 kevin Exp $
 *  $Author: kevin $
 *  $Revision: 1.3 $
 *
 *  Copyright (c) 2011 Terawins Inc. All rights reserved.
 *
 *  @date   2011/09/15  ken     New file.
 *
 */

#if 1

#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"

unsigned char tw_page_handler(unsigned char id, TW_EVENT* event)
{
	unsigned char rc=0;
	event=event;
	switch(id)
	{
		default:	/* put to nodify if no process this event */
			rc = TW_RETURN_NO_PAGE;
		break;

	}
	return rc;
}


#else

#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"

#include "main_menu.h"


unsigned char tw_page_handler(unsigned char id, TW_EVENT* event)
{
	unsigned char rc=0;
	
	if (id==PAGE_1) {
		rc = main_menu_process(event);
	}
#if 0// for second page of sample
	else if (id==PAGE_2) {
		rc = main_menu_process1(event);	
	}
#endif
	else if(id>=TOTAL_PAGE_NUM) {
		ERROR  (("no page ID: %bu!\n", id));
		return TW_ERROR_NO_PAGE;
	}
	else {	// no page process
		
		rc = TW_RETURN_NO_PAGE;
	}
	
	return rc;
}
#endif
