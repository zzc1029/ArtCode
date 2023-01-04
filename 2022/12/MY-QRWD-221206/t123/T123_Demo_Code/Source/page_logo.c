
#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"
#include "spiosd.h"
#include "osd2api.h"

#include "page_logo.h"
#include "page_main_internal.h"
#include "display.h"
#include "mydrivers.h"
#include "disp_config.h"

unsigned char page_logo_process (TW_EVENT* event)
{
	unsigned char i;
	switch(event->type)
	{
		case TW_EVENT_TYPE_ENTER_SYSTEM:
			dbg(2, (">>>>> Enter Menu Page\n\r"));
			
			if(ENTER_LOGO && !ENTER_ACC)
			{
				IC_WritByte(TWIC_P1,0x63,0xf0);
				ENTER_LOGO = 0;
			}
			clear_unmark_area();
			if(ENTER_ACC)
			{
				IC_WritByte(TWIC_P1,0x63,0x00);
				ENTER_ACC = 0;
				display_uncolor_icon(page_main_internal_black,10,7);
				display_uncolor_icon(page_main_internal_black,13,7);
				display_icon(page_main_internal_soc_7,iBLACK,16,8);
				for(i=0;i<12;i++)
					display_uncolor_icon(page_main_internal_black,7 + 3*i,9);
				display_uncolor_icon(page_main_internal_black,9,11);
				display_uncolor_icon(page_main_internal_black,12,11);
				display_icon(page_main_internal_soc_7,iBLACK,15,11);
			}
			LIGHT_EN = 1;
			tw_td_draw(&main_logo);
			sosd_td_enable();
			sosd_enable(DONT_LOAD);
			clear_mark_area();
			clear_alarm_area();
			
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
