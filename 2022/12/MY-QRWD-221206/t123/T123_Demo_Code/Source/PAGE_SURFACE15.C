
#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"
#include "spiosd.h"
#include "osd2api.h"

#include "disp_config.h"

#if (PAGE_ADD > 14)

#include "page_surface15.h"
#include "display.h"
#include "mydrivers.h"

#include "uart.h"
unsigned char page_surface15_process (TW_EVENT* event)
{
	unsigned char i,j;
	switch(event->type)
	{
		case TW_EVENT_TYPE_ENTER_SYSTEM:
			dbg(2, (">>>>> Enter Menu Page\n\r"));
			tw_td_draw(&main_surface15);
			sosd_td_enable();
			sosd_enable(DONT_LOAD);
			clear_alarm_area();
			//clear_mark_area();//·ûºÅÆ¬ÇøÓò
			//clear_unmark_area();//·ûºÅÆ¬ÇøÓò
			//clear_unalarm_area();
			clear_area_block(0,0,31,2);
			clear_area_block(37,0,13,2);
			clear_area_block(0,2,50,16);  
	     //   clear_area_block(31,0,6,2); //·ûºÅÆ¬ÇøÓò
  
			for(i=0;i<6;i++)
				for(j=0;j<8;j++)
					surface_data[i][j] = 0;
			//if(LIGHT_EN)
			//{
			//	LIGHT_EN = 0;
				IC_WritByte(TWIC_P1,0x63,0xf0);
			//}
			display_surface15();

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
