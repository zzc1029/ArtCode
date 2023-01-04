
#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"
#include "spiosd.h"
#include "osd2api.h"
#include "videodetect.h"

#include "page_video.h"
#include "display.h"
#include "tw_timer.h"
#include "mydrivers.h"

unsigned char page_video_process (TW_EVENT* event)
{
	switch(event->type)
	{
		case TW_EVENT_TYPE_ENTER_SYSTEM:
			dbg(2, (">>>>> Enter Menu Page\n\r"));
			clear_unmark_area();
			IC_WritByte(TWIC_P1,0x63,0x00);
			clear_alarm_area();
			clear_mark_area();
			tw_td_draw(&main_video);
			sosd_td_enable();
			sosd_enable(DONT_LOAD);
			IC_WritByte(TWIC_P1,0x63,0xf0);
			
			IC_WritByte(TWIC_P0,0x0f,0x40);
			IC_WritByte(TWIC_P0,0x18,0x30);
			IC_WritByte(TWIC_P0,0x19,0x0c);

			IC_WritByte(TWIC_P0,0x0f,0x00);
			IC_WritByte(TWIC_P0,0x19,0x80);
			IC_WritByte(TWIC_P1,0x13,0x06);

			/* todo: Write Your Code Here */

		break;
		case TW_EVENT_TYPE_TIMEOUT:
			tw_timer_close();
			clear_mark_area();
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
