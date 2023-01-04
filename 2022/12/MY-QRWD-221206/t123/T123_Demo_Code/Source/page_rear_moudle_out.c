
#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"
#include "spiosd.h"
#include "osd2api.h"
#include "disp_config.h"

#if MODULE_REAR_B50
#include "page_rear_moudle_out.h"
#include "display.h"
#include "uart.h"
#include "mydrivers.h"

unsigned char page_rear_moudle_out_process (TW_EVENT* event)
{
	unsigned char i;
	switch(event->type)
	{
		case TW_EVENT_TYPE_ENTER_SYSTEM:
			dbg(2, (">>>>> Enter Menu Page\n\r"));
			tw_td_draw(&main_rear_moudle_out);
			sosd_td_enable();
			sosd_enable(DONT_LOAD);
			clear_unalarm_area();
			if(LIGHT_EN)
			{
				LIGHT_EN = 0;
				IC_WritByte(TWIC_P1,0x63,0xf0);
			}
			display_moudle_output_status(1,rear_out_status[0],rear_out_status[1]);
			display_moudle_output_status(18,rear_out_status[2],rear_out_status[3]);
			display_moudle_output_status(34,rear_out_status[4],rear_out_status[5]);

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
#endif
