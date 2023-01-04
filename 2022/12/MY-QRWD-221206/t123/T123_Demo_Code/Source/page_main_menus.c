
#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"
#include "spiosd.h"
#include "osd2api.h"

#include "page_main_menus.h"
#include "page_main_internal.h"
#include "display.h"
#include "mydrivers.h"
#include "uart.h"
#include "disp_config.h"

extern unsigned char jishu;

unsigned char page_main_menus_process (TW_EVENT* event)
{
	switch(event->type)
	{
		case TW_EVENT_TYPE_ENTER_SYSTEM:
			dbg(2, (">>>>> Enter Menu Page\n\r"));
			sosd_sp_disable();
			if(CLEAR_PAGE)
			{
				display_icon(page_main_internal_soc_7,iBLACK,19,2);
				display_icon(page_main_internal_soc_7,iBLACK,20,2);
				display_icon(page_main_internal_soc_7,iBLACK,22,2);
				display_icon(page_main_internal_soc_7,iBLACK,23,2);
			}
			if(!CLEAR_PAGE)
				clear_unmark_area();
			tw_td_draw(&main_main_menus);
			sosd_td_enable();
			sosd_enable(DONT_LOAD);
			if(LIGHT_EN)
			{
				LIGHT_EN = 0;
				IC_WritByte(TWIC_P1,0x63,0xf0);
			}
			if(CLEAR_PAGE)
			{
				clear_unmark_area();	
				CLEAR_PAGE = 0;
			}
			clear_mark_area();
			if(menu < CURSOR_NUM)
				display_uncolor_icon(page_main_internal_arrows,CURSOR_R_X,CURSOR_R_Y - menu);
			else
				display_uncolor_icon(page_main_internal_arrows,CURSOR_L_X,CURSOR_L_Y - menu);
			jishu = 0;

			/* todo: Write Your Code Here */

		break;

		case TW_EVENT_TYPE_QUIT_SYSTEM:
			dbg(2, (">>>>> QUIT Menu Page\n\r"));

			/* todo: Write Your Code Here */

		break;

		default:	/* put to nodify if no process this event */
			return TW_RETURN_NO_PROCESS;


	}
	return TW_RETURN_NONE;
}
