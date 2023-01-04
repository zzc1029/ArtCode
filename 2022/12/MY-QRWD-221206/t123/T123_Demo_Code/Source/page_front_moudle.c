
#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"
#include "spiosd.h"
#include "osd2api.h"
#include "disp_config.h"

#if MODULE_FRONT_B40 || MODULE_FRONT_B50

#include "page_front_moudle.h"
#include "display.h"
#include "uart.h"
#include "mydrivers.h"

unsigned char page_front_moudle_process (TW_EVENT* event)
{
	#if MODULE_FRONT_B50
	unsigned char i;
	#endif
	switch(event->type)
	{
		case TW_EVENT_TYPE_ENTER_SYSTEM:
			dbg(2, (">>>>> Enter Menu Page\n\r"));
			clear_unmark_area();
			tw_td_draw(&main_front_moudle);
			sosd_td_enable();
			sosd_enable(DONT_LOAD);
			clear_mark_area();
			if(LIGHT_EN)
			{
				LIGHT_EN = 0;
				IC_WritByte(TWIC_P1,0x63,0xf0);
			}
			#if MODULE_FRONT_B40
			display_moudle_output_status(1,front_status[0],front_status[1]);
			display_moudle_input_status(front_status[2],front_status[3]);
			displayu16(43,7,front_para_A25,5,0,GREEN,FULLSPACE,FONT_SMALL);
			displayu16(43,9,front_para_A40,5,0,GREEN,FULLSPACE,FONT_SMALL);
			displayu16(43,11,front_para_A26,5,0,GREEN,FULLSPACE,FONT_SMALL);
			#endif
			#if MODULE_FRONT_B50
			display_moudle_input_status(front_status[0],front_status[1]);
			for(i=0;i<7;i++)
			{
				if((i>3) && (i<6))
					displayu16(43,6 + i,front_para[i],3,2,GREEN,FULLSPACE,FONT_SMALL);
				else
					displayu16(43,6 + i,front_para[i],5,0,GREEN,FULLSPACE,FONT_SMALL);
			}
			#endif
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
