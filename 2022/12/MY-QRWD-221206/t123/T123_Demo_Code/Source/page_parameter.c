
#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"
#include "spiosd.h"
#include "osd2api.h"

#include "page_parameter.h"
#include "display.h"
#include "mydrivers.h"
#include "uart.h"



unsigned char jishu = 0;


unsigned char page_parameter_process (TW_EVENT* event)
{
	unsigned char i,BCD[4];
	switch(event->type)
	{
		case TW_EVENT_TYPE_ENTER_SYSTEM:
			dbg(2, (">>>>> Enter Menu Page\n\r"));
			if(page_xuanze == PAGE_PASSWORD)
			{
				jishu++;
				if(jishu < 2)
					clear_unalarm_area();
				clear_time_area();
				clear_set_area();
			}
			else if(page_xuanze == PAGE_PARA)
			{
				clear_unalarm_area();
				clear_mima_area();
				clear_set_area();
			
			}
			else if(page_xuanze == PAGE_SET)
			{
				clear_area_block(8,9,32,9);
				clear_time_area();
				clear_mima_area();
			}
			tw_td_draw(&main_parameter);
			sosd_td_enable();
			sosd_enable(DONT_LOAD);
			if(LIGHT_EN)
			{
				LIGHT_EN = 0;
				IC_WritByte(TWIC_P1,0x63,0xf0);
			}
			CLEAR_PAGE = 1;
			switch(page_xuanze)
			{
				case PAGE_PASSWORD:
					system_page.last_page = 0xff;
					system_b_password.blink = 0xff;
					for(i=0;i<4;i++)
					system_b_password.para[i] = 0;
					display_icon_uncolor_blink(*number_map[0],12,7,1);
					display_icon_uncolor_blink(*number_map[0],13,7,0);
					display_icon_uncolor_blink(*number_map[0],14,7,0);
					display_icon_uncolor_blink(*number_map[0],15,7,0);
					break;
				case PAGE_PARA:
					system_b_set.para[0] = system_time.hour;
					system_b_set.para[1] = system_time.minute;
					system_b_set.para[2] = system_time.year;
					system_b_set.para[3] = system_time.month;
					system_b_set.para[4] = system_time.day;
					system_b_set.para[5] = system_bright;
					system_b_set.para[6] = buzzer;
					
					BCD[0] = (system_time.hour >> 4) & 0x0f;
					BCD[1] = system_time.hour & 0x0f;
					if(BCD[0] > 9)
						BCD[0] = 0;
					if(BCD[1] > 9)
						BCD[1] = 0;
					display_set_time();
					display_icon_uncolor_blink(*number_map[BCD[0]],19,2,1);
					display_icon_uncolor_blink(*number_map[BCD[1]],20,2,1);
					display_icon_uncolor_blink(*number_map[system_bright],19,6,0);
					display_icon_uncolor_blink(*buzzer_map[buzzer],19,8,0);
					system_b_set.para[7] = vedio_enable[4];
					system_b_set.para[8] = vedio_enable[5];
					system_b_set.para[9] = vedio_enable[6];
					system_b_set.para[10] = vedio_enable[7];
				//	for(i=4;i<8;i++)
				//		display_icon_uncolor_blink(*buzzer_map[vedio_enable[i]],39,i-2,0);
				
					break;
				case PAGE_SET:
					jishu = 0;
					display_icon_uncolor_blink(*number_map[system_meilage.odo[6]],19,9,1);
					system_b_odo_char.para[0] = system_meilage.odo[6];
					for(i=0;i<6;i++)
					{
						system_b_odo_char.para[i + 1] = system_meilage.odo[5 - i];
						display_uncolor_icon(*number_map[system_meilage.odo[i]],25 - i,9);
					}
					BCD[3] = speed_scale / 1000;
					BCD[2] = (speed_scale % 1000) / 100;
					BCD[1] = (speed_scale % 100) / 10;
					BCD[0] = speed_scale % 10;
					for(i=0;i<4;i++)
					{
						system_b_odo_char.para[7 + i] = BCD[3 - i];
						display_uncolor_icon(*number_map[BCD[i]],22 - i,10);
					}
					BCD[3] = baimi_pulse / 1000;
					BCD[2] = (baimi_pulse % 1000) / 100;
					BCD[1] = (baimi_pulse % 100) / 10;
					BCD[0] = baimi_pulse % 10;
					for(i=0;i<4;i++)
					{
						system_b_odo_char.para[11 + i] = BCD[3 - i];
						display_uncolor_icon(*number_map[BCD[i]],22 - i,11);
					}
					BCD[2] = scale_factor / 100;
					BCD[1] = (scale_factor % 100) / 10;
					BCD[0] = scale_factor % 10;
					for(i=0;i<3;i++)
					{
						system_b_odo_char.para[15 + i] = BCD[2 - i];
						display_uncolor_icon(*number_map[BCD[i]],21 - i,12);
					}

					//气压1系数
					BCD[2] = air1_factor/ 100;
					BCD[1] = (air1_factor % 100) / 10;
					BCD[0] = air1_factor % 10;
					for(i=0;i<3;i++)
					{
						system_b_odo_char.para[18 + i] = BCD[2 - i];
						display_uncolor_icon(*number_map[BCD[i]],21 - i,13);
					}
					//气压2系数
					BCD[2] = air2_factor/ 100;
					BCD[1] = (air2_factor % 100) / 10;
					BCD[0] = air2_factor % 10;
					for(i=0;i<3;i++)
					{
						system_b_odo_char.para[21 + i] = BCD[2 - i];
						display_uncolor_icon(*number_map[BCD[i]],21 - i,14);
					}
					//超速
					BCD[2] = speed_alarm/ 100;
					BCD[1] = (speed_alarm % 100) / 10;
					BCD[0] = speed_alarm % 10;
					for(i=0;i<3;i++)
					{
						system_b_odo_char.para[24 + i] = BCD[2 - i];
						display_uncolor_icon(*number_map[BCD[i]],21 - i,15);
					}
					//气压报警
					BCD[2] = air_alarm/ 100;
					BCD[1] = (air_alarm % 100) / 10;
					BCD[0] = air_alarm % 10;
					for(i=0;i<3;i++)
					{
						system_b_odo_char.para[27 + i] = BCD[2 - i];
						display_uncolor_icon(*number_map[BCD[i]],21 - i,16);
					}
					//油压报警
					BCD[2] = oil_alarm/ 100;
					BCD[1] = (oil_alarm % 100) / 10;
					BCD[0] = oil_alarm % 10;
					for(i=0;i<3;i++)
					{
						system_b_odo_char.para[30 + i] = BCD[2 - i];
						display_uncolor_icon(*number_map[BCD[i]],21 - i,17);
					}
					//油量报警
					BCD[2] = fuel_alarm/ 100;
					BCD[1] = (fuel_alarm % 100) / 10;
					BCD[0] = fuel_alarm % 10;
					for(i=0;i<3;i++)
					{
						system_b_odo_char.para[33 + i] = BCD[2 - i];
						display_uncolor_icon(*number_map[BCD[i]],42 - i,9);
					}
					
					//视屏开关
					system_b_odo_char.para[36] = vedio_enable[0];
					system_b_odo_char.para[37] = vedio_enable[1];
					system_b_odo_char.para[38] = vedio_enable[2];
					system_b_odo_char.para[39] = vedio_enable[3];
					for(i=0;i<4;i++)
						display_icon_uncolor_blink(*buzzer_map[vedio_enable[i]],40,10+i,0);
					//雨刮20ms延迟
					system_b_odo_char.para[40] = vedio_enable[4];
					display_icon_uncolor_blink(*buzzer_map[vedio_enable[i]],40,14,0);
					//雨刮延迟时间
					BCD[2] = yugua_time/ 100;
					BCD[1] = (yugua_time % 100) / 10;
					BCD[0] = yugua_time % 10;
					for(i=0;i<3;i++)
					{
						system_b_odo_char.para[41 + i] = BCD[2 - i];
						display_uncolor_icon(*number_map[BCD[i]],42 - i,15);
					}
					break;
				default:
					break;
			}
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
