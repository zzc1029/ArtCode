
#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"
#include "spiosd.h"
#include "osd2api.h"

#include "page_start.h"
#include "page_main_internal.h"
#include "tw_timer.h"
#include "display.h"
#include "uart.h"

unsigned char page_start_process (TW_EVENT* event)
{
	switch(event->type)
	{
		case TW_EVENT_TYPE_ENTER_SYSTEM:
			dbg(2, (">>>>> Enter Menu Page\n\r"));
			tw_td_draw(&main_start);
			sosd_td_enable();
			sosd_enable(DONT_LOAD);
			tw_timer_open(50);
			/* todo: Write Your Code Here */

		break;
		case TW_EVENT_TYPE_TIMEOUT:
			tw_timer_close();
			put_quit_page_event(ID_PAGE_START);
			
			put_enter_page_event(ID_PAGE_LOGO);
			ENTER_ACC = 1;
			ENTER_LOGO = 1;
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
