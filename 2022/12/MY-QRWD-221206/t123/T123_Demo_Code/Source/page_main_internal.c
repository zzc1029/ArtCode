
#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"
#include "spiosd.h"
#include "osd2api.h"

#include "page_main_internal.h"
#include "display.h"
#include "uart.h"
#include "mydrivers.h"
#include "Videodetect.h"


unsigned char page_main_internal_process (TW_EVENT* event)
{
	switch(event->type)
	{
		case TW_EVENT_TYPE_ENTER_SYSTEM:
			dbg(2, (">>>>> Enter Menu Page\n\r"));
			/*IC_WritByte(TWIC_P0,0x0f,0x40);
			IC_WritByte(TWIC_P0,0x18,0x30);
			IC_WritByte(TWIC_P0,0x19,0x0c);*/
			//CVDInit();
			//auto_detection_ctrl(1);
			IC_WritByte(TWIC_P0,0x0f,0x00);
			IC_WritByte(TWIC_P0,0x19,0x80);
			IC_WritByte(TWIC_P1,0x13,0x06);
			clear_mark_area();
			
			display_unmark();
			tw_td_draw(&main_main_internal);
			sosd_td_enable();
			sosd_enable(DONT_LOAD);
			clear_unmark_area();
			//if(LIGHT_EN)
			//{
			//	LIGHT_EN = 0;
				IC_WritByte(TWIC_P1,0x63,0xf0);
			//}
			system_alarm.last_index = 0xff;
			//last_alarm_number = 0xff;
			system_air.last_air1 = 0;
			system_air.last_air2 = 0;
			system_air.last_soc = 0xff;
			display_mark();
			diplay_main_data();
			display_air();
			display_soc();
			display_system_time();
			display_mileage();
			display_fault_message();

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
