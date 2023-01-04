#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"
#include "page_start.h"
#include "page_main_internal.h"
#include "page_main_menus.h"
#include "page_meter_moudle.h"
#include "disp_config.h"
#if MODULE_FRONT_B40 || MODULE_FRONT_B50
#include "page_front_moudle.h"
#endif
#if MODULE_FRONT_B50
#include "page_front_moudle_out.h"
#endif
#if MODULE_REAR_B40 || MODULE_REAR_B50
#include "page_rear_moudle.h"
#endif
#if MODULE_REAR_B50
#include "page_rear_moudle_out.h"
#endif
#if MODULE_TOP_B40 || MODULE_TOP_B50
#include "page_top_moudle.h"
#endif
#if MODULE_TOP_B50
#include "page_top_moudle_out.h"
#endif
#if (PAGE_ADD > 0)
#include "page_surface1.h"
#endif
#if (PAGE_ADD > 1)
#include "page_surface2.h"
#endif
#if (PAGE_ADD > 2)
#include "page_surface3.h"
#endif
#if (PAGE_ADD > 3)
#include "page_surface4.h"
#endif
#if (PAGE_ADD > 4)
#include "page_surface5.h"
#endif
#if (PAGE_ADD > 5)
#include "page_surface6.h"
#endif
#if (PAGE_ADD > 6)
#include "page_surface7.h"
#endif
#if (PAGE_ADD > 7)
#include "page_surface8.h"
#endif
#if (PAGE_ADD > 8)
#include "page_surface9.h"
#endif
#if (PAGE_ADD > 9)
#include "page_surface10.h"
#endif
#if (PAGE_ADD > 10)
#include "page_surface11.h"
#endif
#if (PAGE_ADD > 11)
#include "page_surface12.h"
#endif
#if (PAGE_ADD > 12)
#include "page_surface13.h"
#endif
#if (PAGE_ADD > 13)
#include "page_surface14.h"
#endif
#if (PAGE_ADD > 14)
#include "page_surface15.h"
#endif
#if (PAGE_ADD > 15)
#include "page_surface16.h"
#endif
#if (PAGE_ADD > 16)
#include "page_surface17.h"
#endif
#if (PAGE_ADD > 17)
#include "page_surface18.h"
#endif
#if (PAGE_ADD > 18)
#include "page_surface19.h"
#endif
#if (PAGE_ADD > 19)
#include "page_surface20.h"
#endif
#if (PAGE_ADD > 20)
#include "page_surface21.h"
#endif






#include "page_help_message.h"
#include "page_logo.h"
#include "page_parameter.h"
#include "page_video.h"
#include "ignore_page.h"

unsigned char tw_page_handler(unsigned char id, TW_EVENT* event)
{
	unsigned char rc=0;
	switch(id)
	{
		case ID_PAGE_START:
			rc = page_start_process(event);
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
		#if MODULE_FRONT_B40 || MODULE_FRONT_B50
		case ID_PAGE_FRONT_MOUDLE:
			rc = page_front_moudle_process(event);
		break;
		#endif
		#if MODULE_FRONT_B50
		case ID_PAGE_FRONT_MOUDLE_OUT:
			rc = page_front_moudle_out_process(event);
		break;
		#endif
		#if MODULE_REAR_B40 || MODULE_REAR_B50
		case ID_PAGE_REAR_MOUDLE:
			rc = page_rear_moudle_process(event);
		break;
		#endif
		#if MODULE_REAR_B50
		case ID_PAGE_REAR_MOUDLE_OUT:
			rc = page_rear_moudle_out_process(event);
		break;
		#endif
		#if MODULE_TOP_B40 || MODULE_TOP_B50
		case ID_PAGE_TOP_MOUDLE:
			rc = page_top_moudle_process(event);
		break;
		#endif
		#if MODULE_TOP_B50
		case ID_PAGE_TOP_MOUDLE_OUT:
			rc = page_top_moudle_out_process(event);
		break;
		#endif
		#if (PAGE_ADD > 0)
		case ID_PAGE_SURFACE1:
			rc = page_surface1_process(event);
		break;
		#endif
		#if (PAGE_ADD > 1)
		case ID_PAGE_SURFACE2:
			rc = page_surface2_process(event);
		break;
		#endif
		#if (PAGE_ADD > 2)
		case ID_PAGE_SURFACE3:
			rc = page_surface3_process(event);
		break;
		#endif
		#if (PAGE_ADD > 3)
		case ID_PAGE_SURFACE4:
			rc = page_surface4_process(event);
		break;
		#endif
		#if (PAGE_ADD > 4)
		case ID_PAGE_SURFACE5:
			rc = page_surface5_process(event);
		break;
		#endif
		#if (PAGE_ADD > 5)
		case ID_PAGE_SURFACE6:
			rc = page_surface6_process(event);
		break;
		#endif
		#if (PAGE_ADD > 6)
		case ID_PAGE_SURFACE7:
			rc = page_surface7_process(event);
		break;
		#endif
		#if (PAGE_ADD > 7)
		case ID_PAGE_SURFACE8:
			rc = page_surface8_process(event);
		break;
		#endif
		#if (PAGE_ADD > 8)
		case ID_PAGE_SURFACE9:
			rc = page_surface9_process(event);
		break;
		#endif
		#if (PAGE_ADD > 9)
		case ID_PAGE_SURFACE10:
			rc = page_surface10_process(event);
		break;
		#endif
		#if (PAGE_ADD > 10)
		case ID_PAGE_SURFACE11:
			rc = page_surface11_process(event);
		break;
		#endif
		#if (PAGE_ADD > 11)
		case ID_PAGE_SURFACE12:
			rc = page_surface12_process(event);
		break;
		#endif
		#if (PAGE_ADD > 12)
		case ID_PAGE_SURFACE13:
			rc = page_surface13_process(event);
		break;
		#endif
		#if (PAGE_ADD > 13)
		case ID_PAGE_SURFACE14:
			rc = page_surface14_process(event);
		break;
		#endif
		#if (PAGE_ADD > 14)
		case ID_PAGE_SURFACE15:
			rc = page_surface15_process(event);
		break;
		#endif
		#if (PAGE_ADD > 15)
		case ID_PAGE_SURFACE16:
			rc = page_surface16_process(event);
		break;
		#endif
		#if (PAGE_ADD > 16)
		case ID_PAGE_SURFACE17:
			rc = page_surface17_process(event);
		break;
		#endif
		#if (PAGE_ADD > 17)
		case ID_PAGE_SURFACE18:
			rc = page_surface18_process(event);
		break;
		#endif
		#if (PAGE_ADD > 18)
		case ID_PAGE_SURFACE19:
			rc = page_surface19_process(event);
		break;
		#endif
		#if (PAGE_ADD > 19)
		case ID_PAGE_SURFACE20:
			rc = page_surface20_process(event);
		break;
		#endif
		#if (PAGE_ADD > 20)
		case ID_PAGE_SURFACE21:
			rc = page_surface21_process(event);
		break;
		#endif
		case ID_PAGE_HELP_MESSAGE:
			rc = page_help_message_process(event);
		break;
		case ID_PAGE_LOGO:
			rc = page_logo_process(event);
		break;
		case ID_PAGE_PARAMETER:
			rc = page_parameter_process(event);
		break;
		case ID_PAGE_VIDEO:
			rc = page_video_process(event);
		break;
		default:	/* put to nodify if no process this event */
			rc = TW_RETURN_NO_PAGE;
		break;
	}

	return rc;
}
