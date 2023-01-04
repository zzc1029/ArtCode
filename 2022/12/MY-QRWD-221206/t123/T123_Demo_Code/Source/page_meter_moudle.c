
#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"
#include "spiosd.h"
#include "osd2api.h"

#include "page_meter_moudle.h"
#include "display.h"
#include "uart.h"
#include "mydrivers.h"
#include "disp_config.h"

unsigned char page_meter_moudle_process (TW_EVENT* event)
{
	switch(event->type)
	{
		case TW_EVENT_TYPE_ENTER_SYSTEM:
			dbg(2, (">>>>> Enter Menu Page\n\r"));
			tw_td_draw(&main_meter_moudle);
			sosd_td_enable();
			sosd_enable(DONT_LOAD);
			clear_unalarm_area();
			if(LIGHT_EN)
			{
				LIGHT_EN = 0;
				IC_WritByte(TWIC_P1,0x63,0xf0);
			}
			display_meter_status();
			#if METER_C50
			displayu16(43,11,meter_para_A2,5,0,GREEN,FULLSPACE,FONT_SMALL);
			displayu16(43,12,meter_para_A3,5,0,GREEN,FULLSPACE,FONT_SMALL);
			displayu16(43,13,meter_para_A4,5,0,GREEN,FULLSPACE,FONT_SMALL);
			displayu16(43,14,meter_para_A5,5,0,GREEN,FULLSPACE,FONT_SMALL);
			displayu16(43,15,meter_para_A13,5,0,GREEN,FULLSPACE,FONT_SMALL);
			displayu16(43,16,meter_para_A14,5,0,GREEN,FULLSPACE,FONT_SMALL);
			#endif
			#if METER_C61
			displayu16(43,6,meter_para_A2,5,0,GREEN,FULLSPACE,FONT_SMALL);
			displayu16(43,7,meter_para_A3,5,0,GREEN,FULLSPACE,FONT_SMALL);
			displayu16(43,8,meter_para_A4,5,0,GREEN,FULLSPACE,FONT_SMALL);
			displayu16(43,9,meter_para_A5,5,0,GREEN,FULLSPACE,FONT_SMALL);
			displayu16(43,10,meter_para_A13,5,0,GREEN,FULLSPACE,FONT_SMALL);
			#endif
			#if METER_C52
			displayu16 (43, 10, meter_para_A2, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
			displayu16 (43, 11, meter_para_A3, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
			displayu16 (43, 12, meter_para_A4, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
			displayu8  (27, 17, meter_para_K, 2, 0, GREEN, FULLSPACE, FONT_SMALL);//Âß¼­°æ±¾
			displayu8  (37, 17, meter_para_T, 2, 0, GREEN, FULLSPACE, FONT_SMALL);//ÏÔÊ¾°æ±¾
			displayu16 (43, 13, meter_para_A5, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
			displayu16 (43, 14, meter_para_A13, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
			displayu16 (43, 15, meter_para_A14, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
			displayu16 (43, 16, meter_para_A15, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
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
