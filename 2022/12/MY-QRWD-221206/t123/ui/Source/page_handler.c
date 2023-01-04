#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"
#include "page_start.h"
#include "page_logo.h"
#include "page_main_internal.h"
#include "page_main_menus.h"
#include "page_meter_moudle.h"
#include "page_front_moudle.h"
#include "page_rear_moudle.h"
#include "page_top_moudle.h"
#include "page_parameter.h"
#include "page_help_message.h"
#include "page_video.h"
#include "page_surface1.h"
#include "page_surface2.h"
#include "page_surface3.h"
#include "page_surface4.h"
#include "page_surface5.h"
#include "page_surface6.h"
#include "page_surface7.h"
#include "page_surface8.h"
#include "page_surface9.h"
#include "page_surface10.h"
#include "page_surface11.h"
#include "page_surface12.h"
#include "page_surface13.h"
#include "page_surface14.h"
#include "page_surface15.h"
#include "page_surface16.h"
#include "page_surface17.h"
#include "page_surface18.h"
#include "page_surface19.h"
#include "page_surface20.h"
#include "page_surface21.h"
#include "ignore_page.h"

unsigned char tw_page_handler(unsigned char id, TW_EVENT* event)
{
	unsigned char rc=0;
	switch(id)
	{
		case ID_PAGE_START:
			rc = page_start_process(event);
		break;
		case ID_PAGE_LOGO:
			rc = page_logo_process(event);
		break;
		case ID_PAGE_MAIN_INTERNAL:
			rc = page_main_internal_process(event);
		break;
		case ID_PAGE_MAIN_MENUS:
			rc = page_main_menus_process(event);
		break;
		case ID_PAGE_METER_MOUDLE:
			rc = page_meter_moudle_process(event);
		break;
		case ID_PAGE_FRONT_MOUDLE:
			rc = page_front_moudle_process(event);
		break;
		case ID_PAGE_REAR_MOUDLE:
			rc = page_rear_moudle_process(event);
		break;
		case ID_PAGE_TOP_MOUDLE:
			rc = page_top_moudle_process(event);
		break;
		case ID_PAGE_PARAMETER:
			rc = page_parameter_process(event);
		break;
		case ID_PAGE_HELP_MESSAGE:
			rc = page_help_message_process(event);
		break;
		case ID_PAGE_VIDEO:
			rc = page_video_process(event);
		break;
		case ID_PAGE_SURFACE1:
			rc = page_surface1_process(event);
		break;
		case ID_PAGE_SURFACE2:
			rc = page_surface2_process(event);
		break;
		case ID_PAGE_SURFACE3:
			rc = page_surface3_process(event);
		break;
		case ID_PAGE_SURFACE4:
			rc = page_surface4_process(event);
		break;
		case ID_PAGE_SURFACE5:
			rc = page_surface5_process(event);
		break;
		case ID_PAGE_SURFACE6:
			rc = page_surface6_process(event);
		break;
		case ID_PAGE_SURFACE7:
			rc = page_surface7_process(event);
		break;
		case ID_PAGE_SURFACE8:
			rc = page_surface8_process(event);
		break;
		case ID_PAGE_SURFACE9:
			rc = page_surface9_process(event);
		break;
		case ID_PAGE_SURFACE10:
			rc = page_surface10_process(event);
		break;
		case ID_PAGE_SURFACE11:
			rc = page_surface11_process(event);
		break;
		case ID_PAGE_SURFACE12:
			rc = page_surface12_process(event);
		break;
		case ID_PAGE_SURFACE13:
			rc = page_surface13_process(event);
		break;
		case ID_PAGE_SURFACE14:
			rc = page_surface14_process(event);
		break;
		case ID_PAGE_SURFACE15:
			rc = page_surface15_process(event);
		break;
		case ID_PAGE_SURFACE16:
			rc = page_surface16_process(event);
		break;
		case ID_PAGE_SURFACE17:
			rc = page_surface17_process(event);
		break;
		case ID_PAGE_SURFACE18:
			rc = page_surface18_process(event);
		break;
		case ID_PAGE_SURFACE19:
			rc = page_surface19_process(event);
		break;
		case ID_PAGE_SURFACE20:
			rc = page_surface20_process(event);
		break;
		case ID_PAGE_SURFACE21:
			rc = page_surface21_process(event);
		break;
		default:	/* put to nodify if no process this event */
			rc = TW_RETURN_NO_PAGE;
		break;
	}

	return rc;
}
