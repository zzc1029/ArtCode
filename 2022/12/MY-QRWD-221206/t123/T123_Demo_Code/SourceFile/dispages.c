#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"
#include "spiosd.h"
#include "osd2api.h"

#include "page_main_internal.h"
#include "videodetect.h"
#include "disp_config.h"
#include "display.h"
#include "uart.h"
#include "tw_timer.h"
#include "mydrivers.h"

struct tw_icon *code number_hex_map[16] =
{
    &page_main_internal_number_0,
    &page_main_internal_number_1,
    &page_main_internal_number_2,
    &page_main_internal_number_3,
    &page_main_internal_number_4,
    &page_main_internal_number_5,
    &page_main_internal_number_6,
    &page_main_internal_number_7,
    &page_main_internal_number_8,
    &page_main_internal_number_9,
    &page_main_internal_number_a,
    //  &page_main_internal_number_b,
	//  &page_main_internal_number_c,
    //  &page_main_internal_number_d,
    //  &page_main_internal_number_e,
    //  &page_main_internal_number_f,
};

void display_surface1 (void)
{
    unsigned int temp;
    unsigned char i,u8_data;
    displays16 (15, 2, dongli_input_voltage, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (15, 3, dongli_input_current, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    //display_char_8bit (12, 6, GREEN, siji_status);
    //司机操作状态
    //档位
    u8_data = siji_status & 0x0f;
	switch(u8_data)
	{
		case 0:
			display_gicon(page_main_internal_s1_n,GREEN,7,8);
			break;
		case 0x01:
			display_gicon(page_main_internal_s1_d1,GREEN,7,8);
			break;
		case 0x02:
			display_gicon(page_main_internal_s1_d2,GREEN,7,8);
			break;
		case 0x03:
			display_gicon(page_main_internal_s1_d3,GREEN,7,8);
			break;
		case 0x04:
			display_gicon(page_main_internal_s1_d4,GREEN,7,8);
			break;
		case 0x05:
			display_gicon(page_main_internal_s1_d5,GREEN,7,8);
			break;
		case 0x06:
			display_gicon(page_main_internal_s1_d6,GREEN,7,8);
			break;
		case 0x07:
			display_gicon(page_main_internal_s1_d7,GREEN,7,8);
			break;
		case 0x08:
			display_gicon(page_main_internal_s1_d8,GREEN,7,8);
			break;
		case 0x09:
			display_gicon(page_main_internal_s1_d9,GREEN,7,8);
			break;
		case 0x0a:
			display_gicon(page_main_internal_s1_d10,GREEN,7,8);
			break;
		case 0x0b:
			display_gicon(page_main_internal_s1_d11,GREEN,7,8);
			break;
		case 0x0c:
			display_gicon(page_main_internal_s1_d12,GREEN,7,8);
			break;
		case 0x0d:
			display_gicon(page_main_internal_s1_r,GREEN,7,8);
			break;
		case 0x0e:
			display_gicon(page_main_internal_s1_d,GREEN,7,8);
			break;
		case 0x0f:
			display_gicon(page_main_internal_s1_p,GREEN,7,8);
			break;
		default:
			break;
	}
	//爬坡模式
    u8_data = siji_status >> 4;
	if(u8_data & 0x01)
		display_icon(page_main_internal_youxiao,GREEN,37,7);
	else
		display_icon(page_main_internal_wuxiao,GREEN,37,7);
	//车辆工作模式
	u8_data = siji_status >> 5;
	if((u8_data & 0x03) == 0)
		display_gicon(page_main_internal_s1_chundian,GREEN,11,9);
	else if((u8_data & 0x03) == 1)
		display_gicon(page_main_internal_s1_hundong,GREEN,11,9);
	else if((u8_data & 0x03) == 2)
		display_gicon(page_main_internal_s1_chadian,GREEN,11,9);
	else
		clear_area_block(11,9,5,1);
	//高压维修开关
	u8_data = siji_status >> 7;
	if(u8_data & 0x01)
		display_icon(page_main_internal_youxiao,GREEN,11,10);
	else
		display_icon(page_main_internal_wuxiao,GREEN,11,10);
   // display_char_8bit (11, 7, GREEN, onoff_status);
   //开关量状态
	u8_data = onoff_status;
	for(i=0;i<8;i++)
	{
		if(u8_data & 0x01)
			display_icon(page_main_internal_youxiao,GREEN,41,8 + i);
		else
			display_icon(page_main_internal_wuxiao,GREEN,41,8 + i);
		u8_data >>= 1;
	}
	//u8_data = onoff_status >> 5;
	/*for(i=0;i<3;i++)
	{
		if(u8_data & 0x01)
			display_icon(page_main_internal_youxiao,GREEN,41,12 + i);
		else
			display_icon(page_main_internal_wuxiao,GREEN,41,12 + i);
		u8_data >>= 1;
	}*/
    //display_char_8bit (9, 8, GREEN, system_status);

    //系统状态-电机
	u8_data = system_status;
	switch(u8_data & 0x03)
	{
		case 0:
			display_uncolor_icon(page_main_internal_status_green,8,12);
			clear_area_block(13,12,12,1);
			break;
		case 1:
			display_uncolor_icon(page_main_internal_status_green,13,12);
			clear_area_block(8,12,2,1);
			clear_area_block(18,12,8,1);
			break;
		case 2:
			display_uncolor_icon(page_main_internal_status_green,18,12);
			clear_area_block(8,12,8,1);
			clear_area_block(23,12,2,1);
			break;
		case 3:
			display_uncolor_icon(page_main_internal_status_green,23,12);
			clear_area_block(8,12,12,1);
			break;
		default:
			break;
	}
	//系统状态-发电机
	u8_data = system_status >> 2;
	switch(u8_data & 0x03)
	{
		case 0:
			display_uncolor_icon(page_main_internal_status_green,8,13);
			clear_area_block(13,13,12,1);
			break;
		case 1:
			display_uncolor_icon(page_main_internal_status_green,13,13);
			clear_area_block(8,13,2,1);
			clear_area_block(18,13,8,1);
			break;
		case 2:
			display_uncolor_icon(page_main_internal_status_green,18,13);
			clear_area_block(8,13,8,1);
			clear_area_block(23,13,2,1);
			break;
		case 3:
			display_uncolor_icon(page_main_internal_status_green,23,13);
			clear_area_block(8,13,12,1);
			break;
		default:
			break;
	}
	//系统状态-整车系统
	u8_data = system_status >> 4;
	if((u8_data & 0x03) == 0)
    {
        clear_area_block (12, 14, 5, 1);
        display_icon (page_main_internal_zhengchang, GREEN, 9, 14);
    }
    else if ((u8_data & 0x03) == 1)
        display_gicon (page_main_internal_yijigz, RED, 9, 14);

    else if ((u8_data & 0x03) == 2)
    {
        display_gicon (page_main_internal_erjigz, RED,9, 14);
    }
    else if ((u8_data & 0x03) == 3)
    {
        display_gicon (page_main_internal_sanjigz, RED,9, 14);
    }
    //displayu8 (9, 9, bus_mode, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    //整车模式
	switch(bus_mode)
	{
		case 0x55:
			display_gicon(page_main_internal_s1_zijian,GREEN,9,11);
			break;
		case 0x65:
			display_gicon(page_main_internal_s1_kuaichong,GREEN,9,11);
			break;
		case 0x66:
			display_gicon(page_main_internal_s1_manchong,GREEN,9,11);
			break;
		default:
			clear_area_block(9,11,5,1);
			break;
	}
	displayu8 (37, 6, bus_life, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (11, 7, bus_version[0], 2, 0, GREEN, FULLZERO, FONT_SMALL);
    displayu8 (14, 7, bus_version[1], 2, 0, GREEN, FULLZERO, FONT_SMALL);
    displayu8 (17, 7, bus_version[2], 2, 0, GREEN, FULLZERO, FONT_SMALL);
	temp = ByteToWord(bus_version[3],bus_version[4]);
    displayu16 (20, 7, temp, 4, 0, GREEN, FULLZERO, FONT_SMALL);
    displayu8 (25, 7,bus_version[5], 2, 0, GREEN, FULLZERO, FONT_SMALL);
    displayu8 (28, 7, bus_version[6], 2, 0, GREEN, FULLZERO, FONT_SMALL);

    displayu8 (39, 2, youmen_taban, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (39, 3, zhidong_taban, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    for (i = 0; i < 2; i++)
    {
        display_char_8bit (10, 4 + i, GREEN, bus_yuliu[i]);
    }
	for (i = 0; i < 2; i++)
    {
        display_char_8bit (25, 4 + i, GREEN, bus_yuliu[2+i]);
    }
	for (i = 0; i < 2; i++)
    {
        display_char_8bit (40, 4 + i, GREEN, bus_yuliu[4+i]);
    }
}
void display_surface2 (void)
{
    unsigned int temp;
    displays16 (14, 3, motor_temp[0], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (14, 5, motor_temp[1], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (12, 7, motor_zhju, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    temp = surface_data[0][3];
    temp <<= 8;
    temp |= surface_data[0][2];
    displayu8 (5, 11, surface_data[0][0], 2, 0, GREEN, FULLZERO, FONT_SMALL);
    displayu8 (8, 11, surface_data[0][1], 2, 0, GREEN, FULLZERO, FONT_SMALL);
    displayu16 (11, 11, temp, 4, 0, GREEN, FULLZERO, FONT_SMALL);
    displayu8 (16, 11, surface_data[0][4], 2, 0, GREEN, FULLZERO, FONT_SMALL);
    displayu8 (19, 11, surface_data[0][5], 2, 0, GREEN, FULLZERO, FONT_SMALL);
    displayu8 (21, 11, surface_data[0][6], 2, 0, GREEN, FULLZERO, FONT_SMALL);

   // displays16 (38, 3, motor_temp[2], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
   // displays16 (38, 5, motor_temp[3], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    /*temp = surface_data[1][3];
    temp <<= 8;
    temp |= surface_data[1][2];
    displayu8 (28, 11, surface_data[1][0], 2, 0, GREEN, FULLZERO, FONT_SMALL);
    displayu8 (31, 11, surface_data[1][1], 2, 0, GREEN, FULLZERO, FONT_SMALL);
    displayu16 (34, 11, temp, 4, 0, GREEN, FULLZERO, FONT_SMALL);
    displayu8 (39, 11, surface_data[1][4], 2, 0, GREEN, FULLZERO, FONT_SMALL);
    displayu8 (42, 11, surface_data[1][5], 2, 0, GREEN, FULLZERO, FONT_SMALL);
    displayu8 (44, 11, surface_data[1][6], 2, 0, GREEN, FULLZERO, FONT_SMALL);*/
    //控制器输入电流
    displays16 (39, 3, motor_con_cur, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
   //电控故障代码
	displayu8 (41, 5, elec_control_code, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
}
void display_surface3 (void)
{
    displays16 (15, 2, dcdc_output_voltage, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (15, 4, dcdc_output_current, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (15, 6, dcdc_input_voltage, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (17, 8, dcdc_temp, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (17, 10, dcdc_fault, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    //displayu16 (15, 12, riso_zheng, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
   // displayu16 (15, 14, riso_fu, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
   // displayu8 (17, 16, riso_life, 3, 0, GREEN, FULLSPACE, FONT_SMALL);

   // displayu8 (43, 12, riso_fault, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    /*if (riso_loudian == 0xaa)
    {
        display_icon (page_main_internal_number_0, GREEN, 40, 14);
        display_icon (page_main_internal_x, GREEN, 41, 14);
        display_icon (page_main_internal_number_a, GREEN, 42, 14);
        display_icon (page_main_internal_number_a, GREEN, 43, 14);
    }
    else
        if (riso_loudian == 0x55)
        {
            display_icon (page_main_internal_number_0, GREEN, 40, 14);
            display_icon (page_main_internal_x, GREEN, 41, 14);
            display_icon (page_main_internal_number_5, GREEN, 42, 14);
            display_icon (page_main_internal_number_5, GREEN, 43, 14);
        }
        else
        {
            clear_area_block (40, 13, 4, 1);
        }*/
	//DC/DC启动指令
	if((surface_data[0][0] & 0xff) == 0xaa)
		display_icon(page_main_internal_guanbi,GREEN,35,2);
	else if((surface_data[0][0] & 0xff) == 0x55)
		display_icon(page_main_internal_qidong,GREEN,35,2);
	else
		clear_area_block(35,2,3,1);

	//DC/AC（助力转向）启动指令
	if((surface_data[0][1] & 0xff) == 0xaa)
		display_icon(page_main_internal_guanbi,GREEN,41,4);
	else if((surface_data[0][1] & 0xff) == 0x55)
		display_icon(page_main_internal_qidong,GREEN,41,4);
	else
		clear_area_block(41,4,3,1);

	//DC/AC（助力转向）工作模式
	if((surface_data[0][2]& 0xff) == 0xaa)
		display_gicon(page_main_internal_s3_daiji,GREEN,41,6);
	else if((surface_data[0][2]& 0xff) == 0x55)
		display_gicon(page_main_internal_s3_yunxing,GREEN,41,6);
	else
		clear_area_block(41,6,3,1);

	//DC/AC（空压机）启动指令
	if((surface_data[0][3] & 0xff) == 0xaa)
		display_icon(page_main_internal_guanbi,GREEN,40,8);
	else if((surface_data[0][3] & 0xff) == 0x55)
		display_icon(page_main_internal_qidong,GREEN,40,8);
	else
		clear_area_block(40,8,3,1);
}
void display_surface4 (void)
{
    unsigned char i;
    for (i = 0; i < 8; i++)
    {
        if (i < 4)
        {
            display_char_8bit (10, 3 + 2 * i, GREEN, tiaoshi_canshu[i]);
        }
        else
        {
            display_char_8bit (33, 3 + 2 * (i - 4), GREEN, tiaoshi_canshu[i]);
        }
    }
    display_char_8bit (10, 11, GREEN, yzt_status); //云智通状态
}
void display_surface5 (void)
{   
    //static unsigned char last_soc = 0;
    displays16 (14, 1, total_voltage, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (14, 3, chongdian_current, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (14, 5, fangdian_current, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu16 (14, 7, battery_riso_zheng, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu16 (14, 9, battery_riso_fu, 5, 0, GREEN, FULLSPACE, FONT_SMALL);

    displays16 (37, 1, total_current, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu16 (37, 3, mono_pingjun_voltage, 2, 2, GREEN, FULLSPACE, FONT_SMALL);
   // displays16 (37, 5, mono_max_temp, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu16 (37, 9, mono_max_voltage, 2, 2, GREEN, FULLSPACE, FONT_SMALL);
    displayu16 (37, 11, mono_min_voltage, 2, 2, GREEN, FULLSPACE, FONT_SMALL);
   // displays16 (37, 7, mono_min_temp, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
   
	displayu8 (14, 11, dianchi_soc, 3, 0, GREEN, FULLSPACE, FONT_SMALL);



}
void display_surface6 (void)
{
    unsigned char i;
    display_char_8bit (12, 3, GREEN, vin_status);
    for (i = 0; i < 4; i++)
    {
    	if( chongdian_temp[i] == 215)
			clear_area_block(15, 5 + 2 * i,5,1);
		else
        	displays16 (15, 5 + 2 * i, chongdian_temp[i], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    }
    displayu8 (15, 13, battery_fault_suliang, 3, 0, GREEN, FULLSPACE, FONT_SMALL);

    displayu16 (38, 3, eding_rongliang, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu16 (38, 5, eding_voltage, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu16 (38, 7, mono_chuanlian_shuliang, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (40, 9, mono_binglian_shuliang, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (40, 11, mono_tanzhen_shuliang, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
}
void display_hex (unsigned char x, unsigned char y, unsigned char temp)
{
    display_icon (page_main_internal_number_0, GREEN, x, y);
    display_icon (page_main_internal_x, GREEN, x + 1, y);
    display_icon (*number_hex_map[ ((temp >> 4) & 0x0f)], GREEN, x + 2, y);
    display_icon (*number_hex_map[ (temp & 0x0f)], GREEN, x + 3, y);
}

void display_surface7 (void)
{
    unsigned char i;
    displays16 (10, 3, mono_max_temp, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (15, 3, mono_max_t_xiang, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (20, 3, mono_max_t_jie, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (10, 5, mono_min_temp, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (15, 5, mono_min_t_xiang, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (20, 5, mono_min_t_jie, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    display_hex (8, 7, battery_leixing);
    display_hex (10, 9, battery_lengque);

    displayu16 (34, 3, mono_max_voltage, 1, 2, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (39, 3, mono_max_v_xiang, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (44, 3, mono_max_v_jie, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu16 (34, 5, mono_min_voltage, 1, 2, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (39, 5, mono_min_v_xiang, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (44, 5, mono_min_v_jie, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    for (i = 0; i < 4; i++)
    {
        display_hex (30, 7 + 2 * i, battery_yuliu[i]);
    }
}
void display_surface8s (void)
{
    unsigned char i, color;
    for (i = 0; i < 10; i++)
    {
        if ((dianchi_mono_voltage[i] > 414) || (dianchi_mono_voltage[i] < 251))
        {
            color = RED;
        }
        else
        {
            color = GREEN;
        }
        if (i < 5)
        {
            displayu16 (3, 5 + 2 * i, dianchi_bianhao[i], 3, 0, WHITE, FULLZERO, FONT_SMALL);
            displayu16 (7, 5 + 2 * i, dianchi_mono_voltage[i], 2, 2, color, FULLSPACE, FONT_SMALL);
            displayu8 (26, 5 + 2 * i, dianchi_xianghao[i], 3, 0, WHITE, FULLZERO, FONT_SMALL);
            displays16 (31, 5 + 2 * i, dianchi_mono_temp[i], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
        }
        else
        {
            displayu16 (14, 5 + 2 * (i - 5), dianchi_bianhao[i], 3, 0, WHITE, FULLZERO, FONT_SMALL);
            displayu16 (18, 5 + 2 * (i - 5), dianchi_mono_voltage[i], 2, 2, color, FULLSPACE, FONT_SMALL);
            displayu8 (37, 5 + 2 * (i - 5), dianchi_xianghao[i], 3, 0, WHITE, FULLZERO, FONT_SMALL);
            displays16 (42, 5 + 2 * (i - 5), dianchi_mono_temp[i], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
        }
    }
}

void display_surface8 (void)
{
    unsigned char i, color;
    switch (dianchi_fenxian)
    {
        case 1:
            for (i = 0; i < 2; i++)
            {
                if ((dianchi_mono_voltage[i] > 414) || (dianchi_mono_voltage[i] < 251))
                {
                    color = RED;
                }
                else
                {
                    color = GREEN;
                }
                displayu16 (3, 5 + 2 * i, dianchi_bianhao[i], 3, 0, WHITE, FULLZERO, FONT_SMALL);
                displayu16 (7, 5 + 2 * i, dianchi_mono_voltage[i], 2, 2, color, FULLSPACE, FONT_SMALL);
            }
            break;
        case 2:
            for (i = 0; i < 2; i++)
            {
                if ((dianchi_mono_voltage[i + 2] > 414) || (dianchi_mono_voltage[i + 2] < 251))
                {
                    color = RED;
                }
                else
                {
                    color = GREEN;
                }
                displayu16 (3, 5 + 2 * (i + 2), dianchi_bianhao[i + 2], 3, 0, WHITE, FULLZERO, FONT_SMALL);
                displayu16 (7, 5 + 2 * (i + 2), dianchi_mono_voltage[i + 2], 2, 2, color, FULLSPACE, FONT_SMALL);
            }
            break;
        case 3:
            if ((dianchi_mono_voltage[4] > 414) || (dianchi_mono_voltage[4] < 251))
            {
                color = RED;
            }
            else
            {
                color = GREEN;
            }
            displayu16 (3, 13, dianchi_bianhao[4], 3, 0, WHITE, FULLZERO, FONT_SMALL);
            displayu16 (7, 13, dianchi_mono_voltage[4], 2, 2, color, FULLSPACE, FONT_SMALL);
            if ((dianchi_mono_voltage[5] > 414) || (dianchi_mono_voltage[5] < 251))
            {
                color = RED;
            }
            else
            {
                color = GREEN;
            }
            displayu16 (14, 5, dianchi_bianhao[5], 3, 0, WHITE, FULLZERO, FONT_SMALL);
            displayu16 (18, 5, dianchi_mono_voltage[5], 2, 2, color, FULLSPACE, FONT_SMALL);
            break;
        case 4:
            for (i = 0; i < 2; i++)
            {
                if ((dianchi_mono_voltage[i + 6] > 414) || (dianchi_mono_voltage[i + 6] < 251))
                {
                    color = RED;
                }
                else
                {
                    color = GREEN;
                }
                displayu16 (14, 5 + 2 * (i + 1), dianchi_bianhao[i + 6], 3, 0, WHITE, FULLZERO, FONT_SMALL);
                displayu16 (18, 5 + 2 * (i + 1), dianchi_mono_voltage[i + 6], 2, 2, color, FULLSPACE, FONT_SMALL);
            }
            break;
        case 5:
            for (i = 0; i < 2; i++)
            {
                if ((dianchi_mono_voltage[i + 8] > 414) || (dianchi_mono_voltage[i + 8] < 251))
                {
                    color = RED;
                }
                else
                {
                    color = GREEN;
                }
                displayu16 (14, 5 + 2 * (i + 3), dianchi_bianhao[i + 8], 3, 0, WHITE, FULLZERO, FONT_SMALL);
                displayu16 (18, 5 + 2 * (i + 3), dianchi_mono_voltage[i + 8], 2, 2, color, FULLSPACE, FONT_SMALL);
            }
            break;
        case 6:
            for (i = 0; i < 4; i++)
            {
                displayu8 (26, 5 + 2 * i, dianchi_xianghao[i], 3, 0, WHITE, FULLZERO, FONT_SMALL);
                displays16 (31, 5 + 2 * i, dianchi_mono_temp[i], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
            }
            break;
        case 7:
            displayu8 (26, 13, dianchi_xianghao[4], 3, 0, WHITE, FULLZERO, FONT_SMALL);
            displays16 (31, 13, dianchi_mono_temp[4], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
            for (i = 0; i < 3; i++)
            {
                displayu8 (37, 5 + 2 * i, dianchi_xianghao[i + 5], 3, 0, WHITE, FULLZERO, FONT_SMALL);
                displays16 (42, 5 + 2 * i, dianchi_mono_temp[i + 5], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
            }
            break;
        case 8:
            for (i = 0; i < 2; i++)
            {
                displayu8 (37, 5 + 2 * (i + 3), dianchi_xianghao[i + 8], 3, 0, WHITE, FULLZERO, FONT_SMALL);
                displays16 (42, 5 + 2 * (i + 3), dianchi_mono_temp[i + 8], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
            }
            break;
        default:
            break;
    }
    dianchi_fenxian = 0;
}
void display_surface9 (void)
{
    displayu8 (17, 3, air_fuhe, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (17, 5, air_set_temp, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (17, 7, air_wai_temp, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (17, 9, air_nei_temp, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (38, 3, air_current, 4, 1, GREEN, FULLSPACE, FONT_SMALL);
   // display_char_8bit (35, 5, GREEN, air_status);
   if((air_status  & 0xc1) == 0)
   	{
		display_icon (page_main_internal_guanbi, GREEN, 40,5);
		clear_area_block(43,5,1,1);
   	}
	else if((air_status  & 0xc1) == 0x40)
	{
		display_icon (page_main_internal_guzhang, RED, 40,5);
		clear_area_block(43,5,1,1);
   	}
	else if((air_status  & 0xc1) == 0x01)
	{
		display_icon (page_main_internal_qidong, GREEN, 40,5);
		clear_area_block(43,5,1,1);
   	}
	else if((air_status  & 0xc1) == 0x80)
		display_icon (page_main_internal_s9_ready, GREEN, 40,5);
	else
		clear_area_block(40,5,4,1);
    displayu8 (40, 7, air_life, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
}
void display_surface10 (void)
{
   unsigned char i,u8_data;
	//bms_status_1
	u8_data = battery_status[0];
	for(i=0;i<8;i++)
	{		
		if(u8_data & 0x01)
			display_icon(page_main_internal_youxiao,GREEN,15,1 + i);
		else
			display_icon(page_main_internal_wuxiao,GREEN,15,1 + i);
		u8_data >>= 1;
	}
	//bms_status_2
	u8_data = battery_status[1];
	for(i=0;i<8;i++)
	{		
		if(u8_data & 0x01)
			display_icon(page_main_internal_youxiao,GREEN,15,9 + i);
		else
			display_icon(page_main_internal_wuxiao,GREEN,15,9 + i);
		u8_data >>= 1;
	}
	//bms_status_3
	u8_data = battery_status[2];
		if(u8_data & 0x01)
			display_icon(page_main_internal_youxiao,GREEN,29,1);
		else
			display_icon(page_main_internal_wuxiao,GREEN,29,1);
		
	u8_data = battery_status[2];	
		if(u8_data & 0x02)
			display_gicon(page_main_internal_bihe,GREEN,29,2);
		else
			display_gicon(page_main_internal_duankai,RED,29,2);
		
	u8_data = battery_status[2];	
	for(i=0;i<6;i++)
	{		
		if(u8_data & 0x04)
			display_icon(page_main_internal_youxiao,GREEN,29,3 + i);
		else
			display_icon(page_main_internal_wuxiao,GREEN,29,3 + i);
		u8_data >>= 1;
	}
	//bms_status_4
	u8_data = battery_status[3];
	for(i=0;i<8;i++)
	{		
		if(u8_data & 0x01)
			display_icon(page_main_internal_youxiao,GREEN,29,9 + i);
		else
			display_icon(page_main_internal_wuxiao,GREEN,29,9 + i);
		u8_data >>= 1;
	}
	//bms_status_5
	u8_data = battery_status[4];
	for(i=0;i<6;i++)
	{		
		if(u8_data & 0x01)
			display_icon(page_main_internal_youxiao,GREEN,43,1 + i);
		else
			display_icon(page_main_internal_wuxiao,GREEN,43,1 + i);
		u8_data >>= 1;
	}
}
void display_surface11 (void)
{
//    	switch(runhua1)
// 	{
// 		case 0:
// 			display_gicon(page_main_internal_s13_runhua,GREEN,27,4);
// 			break;
// 		case 2:
// 			display_gicon(page_main_internal_s13_chuanganqigz,RED,27,4);
// 			break;
// 		case 4:
// 			display_gicon(page_main_internal_s13_diyouwei,RED,27,4);
// 			break;
// 		case 0x40:
// 			display_gicon(page_main_internal_s13_xiuzhi,GREEN,27,4);
// 			break;
// 		default:
// 			clear_area_block(27,4,10,1);
// 			break;
// 	}
#if 0

   signed int s16_data;
   unsigned int u16_data;
   //胎压
   u16_data = ByteToWord(surface_data[0][0],surface_data[0][1]);
   displayu16 (6, 11, u16_data, 4, 1, GREEN, FULLSPACE, FONT_SMALL);

   u16_data = ByteToWord(surface_data[0][2],surface_data[0][3]);
   displayu16 (6, 4, u16_data, 4, 1, GREEN, FULLSPACE, FONT_SMALL);

   u16_data = ByteToWord(surface_data[0][4],surface_data[0][5]);
   displayu16 (35, 12, u16_data, 4, 1, GREEN, FULLSPACE, FONT_SMALL);

   u16_data = ByteToWord(surface_data[0][6],surface_data[0][7]);
   displayu16 (35, 10, u16_data, 4, 1, GREEN, FULLSPACE, FONT_SMALL);

   u16_data = ByteToWord(surface_data[1][0],surface_data[1][1]);
   displayu16 (35, 5, u16_data, 4, 1, GREEN, FULLSPACE, FONT_SMALL);

   u16_data = ByteToWord(surface_data[1][2],surface_data[1][3]);
   displayu16 (35, 3, u16_data, 4, 1, GREEN, FULLSPACE, FONT_SMALL);
   
   //胎温
   s16_data = surface_data[2][0];
   displays16 (7, 12, s16_data - 55, 4, 0, GREEN, FULLSPACE, FONT_SMALL);

   s16_data = surface_data[2][1];
   displays16 (7, 5, s16_data - 55, 4, 0, GREEN, FULLSPACE, FONT_SMALL);

   s16_data = surface_data[2][2];
   displays16 (36, 13, s16_data - 55, 4, 0, GREEN, FULLSPACE, FONT_SMALL);

   s16_data = surface_data[2][3];
   displays16 (36, 11, s16_data - 55, 4, 0, GREEN, FULLSPACE, FONT_SMALL);

   s16_data = surface_data[2][4];
   displays16 (36, 6, s16_data - 55, 4, 0, GREEN, FULLSPACE, FONT_SMALL);

   s16_data = surface_data[2][5];
   displays16 (36, 4, s16_data - 55, 4, 0, GREEN, FULLSPACE, FONT_SMALL);
   
#endif

}
void display_surface12 (void)
{

    displays16 (18, 2, qiben1, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (18, 4, qiben2, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (18, 6, qiben3, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (20, 8, qiben4, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (20, 10, qiben5, 3, 0, GREEN, FULLSPACE, FONT_SMALL);



}
void display_surface13 (void)
{
	unsigned char u8_data;
	unsigned int u16_data;
	int s16_data;
	//BMS请求设定模式
/*	u8_data = surface_data[0][0];
	switch(u8_data & 0x03)
	{
		case 0:
			clear_area_block(22,2,20,1);
			display_uncolor_icon(page_main_internal_status_green,15,2);
			break;
		case 1:
			clear_area_block(15,2,3,1);
			clear_area_block(28,2,10,1);
			display_uncolor_icon(page_main_internal_status_green,22,2);
			break;
		case 2:
			clear_area_block(15,2,10,1);
			clear_area_block(35,2,3,1);
			display_uncolor_icon(page_main_internal_status_green,28,2);
			break;
		case 3:
			clear_area_block(15,2,20,1);
			display_uncolor_icon(page_main_internal_status_green,35,2);
			break;
		default:
			break;
	}
	//高压请求
	u8_data = surface_data[0][0] >> 2;
	switch(u8_data & 0x03)
	{
		case 0:
			clear_area_block(22,3,20,1);
			display_uncolor_icon(page_main_internal_status_green,15,3);
			break;
		case 1:
			clear_area_block(15,3,3,1);
			clear_area_block(28,3,10,1);
			display_uncolor_icon(page_main_internal_status_green,22,3);
			break;
		case 2:
		case 3:
			clear_area_block(15,3,10,1);
			clear_area_block(35,3,3,1);
			display_uncolor_icon(page_main_internal_status_green,28,3);
			break;
		default:
			break;
	}
	// 充电状态
	u8_data = surface_data[0][0] >> 4;
	switch(u8_data & 0x03)
	{
		case 0:
			clear_area_block(22,4,20,1);
			display_uncolor_icon(page_main_internal_status_green,15,4);
			break;
		case 1:
			clear_area_block(15,4,3,1);
			clear_area_block(28,4,10,1);
			display_uncolor_icon(page_main_internal_status_green,22,4);
			break;
		case 2:
		case 3:
			clear_area_block(15,4,10,1);
			clear_area_block(35,4,3,1);
			display_uncolor_icon(page_main_internal_status_green,28,4);
			break;
		default:
			break;
	}
	//BMS高压继电器状态 
	u8_data = surface_data[0][0] >> 6;
	switch(u8_data & 0x03)
	{
		case 0:
			clear_area_block(22,5,20,1);
			display_uncolor_icon(page_main_internal_status_green,15,5);
			break;
		case 1:
			clear_area_block(15,5,3,1);
			clear_area_block(28,5,10,1);
			display_uncolor_icon(page_main_internal_status_green,22,5);
			break;
		case 2:
		case 3:
			clear_area_block(15,5,10,1);
			clear_area_block(35,5,3,1);
			display_uncolor_icon(page_main_internal_status_green,28,5);
			break;
		default:
			break;
	}
	// BMS当前电压
	u16_data = ByteToWord(surface_data[0][2],surface_data[0][1]);
	displayu16 (19, 6, u16_data, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
	// 设定温度
	s16_data = surface_data[0][4] - 40;
    displays16 (39, 6, s16_data, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
	// BMS生命帧
	displayu8(21, 7, surface_data[0][6], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
	// CRC效验值
	displayu8(39, 7, surface_data[0][7], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
*/

	//TMS工作状态
	u8_data = surface_data[0][0];
	switch(u8_data & 0x03)
	{
		case 0:
			clear_area_block(22,9,20,1);
			display_uncolor_icon(page_main_internal_status_green,15,9);
			break;
		case 1:
			clear_area_block(15,9,3,1);
			clear_area_block(28,9,10,1);
			display_uncolor_icon(page_main_internal_status_green,22,9);
			break;
		case 2:
			clear_area_block(15,9,10,1);
			clear_area_block(35,9,3,1);
			display_uncolor_icon(page_main_internal_status_green,28,9);
			break;
		case 3:
			clear_area_block(15,9,20,1);
			display_uncolor_icon(page_main_internal_status_green,35,9);
			break;
		default:
			break;
	}
	// TMS高压继电器状态
	u8_data = surface_data[0][0] >> 2;
	switch(u8_data & 0x03)
	{
		case 0:
			clear_area_block(22,10,20,1);
			display_uncolor_icon(page_main_internal_status_green,15,10);
			break;
		case 1:
			clear_area_block(15,10,3,1);
			clear_area_block(28,10,10,1);
			display_uncolor_icon(page_main_internal_status_green,22,10);
			break;
		case 2:
		case 3:
			clear_area_block(15,10,10,1);
			clear_area_block(35,10,3,1);
			display_uncolor_icon(page_main_internal_status_green,28,10);
			break;
		default:
			break;
	}
	//出水温度(机组到电池)
	s16_data = surface_data[0][1] - 40;
    displays16 (21, 11, s16_data, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
	//回水温度(电池到机组)
	s16_data = surface_data[0][2] - 40;
    displays16 (21, 12, s16_data, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
	//TMS需求功率
	u16_data = ByteToWord(surface_data[0][6],surface_data[0][5]);
	displayu16 (19, 13, u16_data, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
	//TMS故障码
	u8_data = surface_data[0][7] & 0x3f;
    displayu8 (21, 14, u8_data, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
	//TMS故障码等级
	u8_data = (surface_data[0][7] & 0xc0) >> 6;
	if(u8_data == 0)
		display_icon (page_main_internal_zhengchang, GREEN, 21, 15);
	else
    	displayu8 (21, 15, u8_data, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
}
void display_surface14 (void)
{
// 	int s16_data;
//   	unsigned int u16_data;
// 	unsigned char u8_data;
//  	//电器盒输入总电流
//   	s16_data = ByteToWord(surface_data[0][0],surface_data[0][1]) - 1600;
// 	displays16 (27, 7, s16_data, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
// 	//电器盒电压
// 	u16_data = ByteToWord(surface_data[0][2],surface_data[0][3]);
// 	displays16 (27, 9, u16_data, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
// 	//电器盒输入总电流
//   	s16_data = surface_data[0][4] - 40;
// 	displays16 (29, 11, s16_data, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
// 	//保护动作指示
// 	u8_data = surface_data[0][5];
// 	if((u8_data & 0x03) == 0x01)
// 		display_gicon(page_main_internal_s14_guoliu,GREEN,29,13);
// 	else if((u8_data & 0x03) == 0x02)
// 		display_gicon(page_main_internal_s14_guore,GREEN,29,13);
// 	else
// 		clear_area_block(29,13,7,1);
}
void display_surface15 (void)
{
    displays16 (17, 8, total_voltage, 5, 0, GREEN, FULLSPACE, FONT_SMALL); //电池总电压
    displays16 (17, 9, total_current, 5, 0, GREEN, FULLSPACE, FONT_SMALL); //电池总电流
    displayu16 (37, 8, mono_max_voltage, 2, 2, GREEN, FULLSPACE, FONT_SMALL); //单体最高电压
	displayu16 (37, 9, mono_min_voltage, 2, 2, GREEN, FULLSPACE, FONT_SMALL); //单体最低电压
	displays16 (38, 10, mono_max_temp, 3, 0, GREEN, FULLSPACE, FONT_SMALL); //单体最高温度
	displays16 (38, 11, mono_min_temp, 3, 0, GREEN, FULLSPACE, FONT_SMALL); //单体最低温度
	displayu16 (17, 10, riso_zheng, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu16 (17, 11, riso_fu, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
	display_soc();
 	if(surface_data[0][0]& 0x01)
 		{
 		clear_icon (page_main_internal_black,31, 0);
 		}
  	else        
		{
		display_uncolor_icon (page_main_internal_black,31,0);
  		}
	if(surface_data[0][0]& 0x02)
 		{
 		clear_icon (page_main_internal_black,34, 0);
		}
  	else        
		{
		display_uncolor_icon (page_main_internal_black,34,0);
  		}
	

	    //充电座温度
    if( chongdian_temp[0] == 215)
		clear_area_block(19, 12 , 5, 1);
	else
        displays16 (19, 12, chongdian_temp[0], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
		
	if( chongdian_temp[1] == 215)
		clear_area_block(38, 12 , 5, 1);
	else
        displays16 (38, 12, chongdian_temp[1], 3, 0, GREEN, FULLSPACE, FONT_SMALL);

	if( chongdian_temp[2] == 215)
		clear_area_block(19, 13 , 5, 1);
	else
        displays16 (19, 13, chongdian_temp[2], 3, 0, GREEN, FULLSPACE, FONT_SMALL);

	if( chongdian_temp[3] == 215)
		clear_area_block(38, 13 , 5, 1);
	else
        displays16 (38, 13, chongdian_temp[3], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
		
}
void display_surface16 (void)
{
    unsigned char temp, i;
    displayu8 (15, 3, youbeng_life[0], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu16 (14, 4, youbeng_zhuansu[0], 4, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu16 (16, 5, youbeng_cur[0], 2, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (15, 6, youbeng_temp[0], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    if ((youbeng_status[0] & 0x03) == 1)
    {
        display_gicon (page_main_internal_yuunxing, GREEN, 15, 7);
    }
    else
        if ((youbeng_status[0] & 0x03) == 2)
        {
            display_gicon (page_main_internal_s16_tingji, GREEN, 15, 7);
        }
        else
        {
            clear_area_block (15, 7, 3, 1);
        }
    displays16 (15, 8, dianji_temp, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (16, 9, diduan_vol, 2, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu16 (14, 10, gaoduan_vol, 4, 0, GREEN, FULLSPACE, FONT_SMALL);
    temp = youbeng[0];
    if (temp & 0x01)
    {
        display_gicon (page_main_internal_yitingji, GREEN, 14, 11);
    }
    else
    {
        display_gicon (page_main_internal_weitingji, GREEN, 14, 11);
    }
    temp >>= 1;
    if ((temp & 0x03) == 2)
    {
        display_gicon (page_main_internal_gaoya, GREEN, 16, 12);
    }
    else
        if ((temp & 0x03) == 0)
        {
            display_gicon (page_main_internal_diya, GREEN, 16, 12);
        }
    temp >>= 2;

    for (i = 0; i < 4; i++)
    {
        if (temp & 0x01)
        {
            display_icon (page_main_internal_guzhang, RED, 16, 13 + i);
        }
        else
        {
            display_icon (page_main_internal_zhengchang, GREEN, 16, 13 + i);
        }
        temp >>= 1;
    }
    if (temp & 0x01)
    {
        display_icon (page_main_internal_guzhang, RED, 30, 3);
    }
    else
    {
        display_icon (page_main_internal_zhengchang, GREEN, 30, 3);
    }
    temp = youbeng[1];
    for (i = 0; i < 8; i++)
    {
        if (temp & 0x01)
        {
            display_icon (page_main_internal_guzhang, RED, 30, 4 + i);
        }
        else
        {
            display_icon (page_main_internal_zhengchang, GREEN, 30, 4 + i);
        }
        temp >>= 1;
    }
    temp = youbeng[2];
    for (i = 0; i < 8; i++)
    {
        if (temp & 0x01)
        {
            display_icon (page_main_internal_guzhang, RED, 45, 3 + i);
        }
        else
        {
            display_icon (page_main_internal_zhengchang, GREEN, 45, 3 + i);
        }
        temp >>= 1;
    }
    displayu8 (38, 12, yingjianbanben, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu8 (38, 13, ruanjianbanben, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
}

void display_surface17 (void)
{
    //unsigned char temp;
    displayu8 (16, 4, youbeng_life[1], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu16 (15, 6, youbeng_zhuansu[1], 4, 0, GREEN, FULLSPACE, FONT_SMALL);
    displayu16 (17, 8, youbeng_cur[1], 2, 0, GREEN, FULLSPACE, FONT_SMALL);
    displays16 (16, 10, youbeng_temp[1], 3, 0, GREEN, FULLSPACE, FONT_SMALL);
    if ((youbeng_status[1] & 0x03) == 0)
    {
        display_gicon (page_main_internal_tingji, GREEN, 16, 12);
    }
    else
        if ((youbeng_status[1] & 0x03) == 1)
        {
            display_gicon (page_main_internal_yuunxing, GREEN, 16, 12);
        }
        else
            if ((youbeng_status[1] & 0x03) == 2)
            {
                display_gicon (page_main_internal_gz, GREEN, 16, 12);
            }
            else
            {
                clear_area_block (16, 12, 3, 1);
            }

    if ((youbeng_status[1] & 0x0c) == 0)
    {
        clear_area_block (18, 14, 5, 1);
        display_icon (page_main_internal_zhengchang, GREEN, 15, 14);
    }
    else
        if ((youbeng_status[1] & 0x0c) == 4)
        {
            display_gicon (page_main_internal_yijigz, RED, 15, 14);
        }
        else
            if ((youbeng_status[1] & 0x0c) == 8)
            {
                display_gicon (page_main_internal_erjigz, RED, 15, 14);
            }
            else
                if ((youbeng_status[1] & 0x0c) == 12)
                {
                    display_gicon (page_main_internal_sanjigz, RED, 15, 14);
                }
                else
                {
                    clear_area_block (15, 14, 8, 1);
                }
    displayu8 (37, 4, guzhangdaima, 3, 0, GREEN, FULLSPACE, FONT_SMALL);
}
void display_surface18 (void)
{
#if 0

	unsigned char i,j,mo,yu,he;
	static unsigned char xiang_zong = 0;

	//--------------------------------------------
	if(xiang_zong != surface_data[0][0])
	{
		clear_area_block(3,6,44,11);
		xiang_zong = surface_data[0][0];
	}
	mo = (surface_data[0][0])/2;
	yu = (surface_data[0][0])%2;
	he = (mo + yu);
	//life
	displayu8(43,4,surface_data[0][1],3,0,GREEN,FULLSPACE,FONT_SMALL);
	if(surface_data[0][0] > 0)
	{
		if(mo > 5)
			mo = 5;
		for(i=0;i<mo;i++)
		{
			for(j=0;j<2;j++)
			{
				//箱号
				displayu8(4,6 + i*2 + j,surface_data[i+1][j*4],1,0,GREEN,FULLSPACE,FONT_SMALL);
				//预警级别
				switch(surface_data[i+1][j*4 + 1] & 0xf0)
				{
					case 0x00:
						displayu8(11,6 + i*2 + j,0,1,0,GREEN,FULLSPACE,FONT_SMALL);
						break;
					case 0x10:
						displayu8(11,6 + i*2 + j,1,1,0,GREEN,FULLSPACE,FONT_SMALL);
						break;
					case 0x20:
						displayu8(11,6 + i*2 + j,2,1,0,GREEN,FULLSPACE,FONT_SMALL);
						break;
					case 0x30:
						displayu8(11,6 + i*2 + j,3,1,0,GREEN,FULLSPACE,FONT_SMALL);
						break;
					case 0x40:
						displayu8(11,6 + i*2 + j,4,1,0,GREEN,FULLSPACE,FONT_SMALL);
						break;
					default:
						break;
				}
                //故障状态
				switch(surface_data[i+1][j*4 + 1] & 0x0c)
				{						
					case 0x00:
						display_icon(page_main_internal_zhengchang,GREEN,15,6 + i*2 + j);
						clear_area_block(18,6 + i*2 + j,1,1);
						break;
				    case 0x04:
						displayu8(18,6 + i*2 + j,1,1,0,GREEN,FULLSPACE,FONT_SMALL);
						clear_area_block(15,6 + i*2 + j,3,1);
						break;
					case 0x08:
						displayu8(18,6+ i*2 + j,2,1,0,GREEN,FULLSPACE,FONT_SMALL);
						clear_area_block(15,6 + i*2 + j,3,1);
						break;						
					case 0x0c:
						displayu8(18,6+ i*2 + j,3,1,0,GREEN,FULLSPACE,FONT_SMALL);
						clear_area_block(15,6 + i*2 + j,3,1);
						break;
					default:
						break;
					}
				//子阀状态
				switch(surface_data[i+1][j*4 + 1] & 0x03)
				{						
					case 0x01:
						displayu8(32,6+ i*2 + j,1,1,0,GREEN,FULLSPACE,FONT_SMALL);
						break;
					case 0x02:
						displayu8(32,6+ i*2 + j,2,1,0,GREEN,FULLSPACE,FONT_SMALL);
						break;
					case 0x03:
						displayu8(32,6+ i*2 + j,3,1,0,GREEN,FULLSPACE,FONT_SMALL);
						break;
					default:
						break;
				}
				//灭火弹类型
				switch(surface_data[i+1][j*4 + 3])
				{
					case 0:
						displayu8(25,6 + i*2 + j,1,1,0,GREEN,FULLSPACE,FONT_SMALL);
						clear_area_block(22,6 + i*2 + j,3,1);
						break;
					case 2:
						displayu8(25,6 + i*2 + j,2,1,0,GREEN,FULLSPACE,FONT_SMALL);
						clear_area_block(22,6 + i*2 + j,3,1);
						break;
					case 3:
						displayu8(25,6+ i*2 + j,3,1,0,GREEN,FULLSPACE,FONT_SMALL);
						clear_area_block(22,6 + i*2 + j,3,1);
						break;						
					case 4:
						displayu8(25,6+ i*2 + j,4,1,0,GREEN,FULLSPACE,FONT_SMALL);
						clear_area_block(22,6 + i*2 + j,3,1);
						break;						
					case 5:
						displayu8(25,6+ i*2 + j,5,1,0,GREEN,FULLSPACE,FONT_SMALL);
						clear_area_block(22,6 + i*2 + j,3,1);
						break;
					case 6:
						displayu8(25,6+ i*2 + j,6,1,0,GREEN,FULLSPACE,FONT_SMALL);
						clear_area_block(22,6 + i*2 + j,3,1);
						break;
					case 7:
						displayu8(25,6+ i*2 + j,7,1,0,GREEN,FULLSPACE,FONT_SMALL);
						clear_area_block(22,6 + i*2 + j,3,1);
						break;
					case 255:
						displayu8(22,6+ i*2 + j,255,3,0,GREEN,FULLSPACE,FONT_SMALL);
						clear_area_block(25,6 + i*2 + j,1,1);
						break;
					default:
						break;
				}
				//故障码
				displayu8(42,6 + i*2 + j,surface_data[i+1][j*4 + 2],2,0,GREEN,FULLSPACE,FONT_SMALL);
				/*switch(surface_data[i+1][j*4 + 3])
				{
					case 0:
						displayu8(37,6 + i*2 + j,0,1,0,GREEN,FULLSPACE,FONT_SMALL);
						break;
					case 1:
						displayu8(37,6 + i*2 + j,1,1,0,GREEN,FULLSPACE,FONT_SMALL);
						break;
					case 2:
						displayu8(37,6 + i*2 + j,2,1,0,GREEN,FULLSPACE,FONT_SMALL);
						break;
					case 3:
						displayu8(37,6 + i*2 + j,3,1,0,GREEN,FULLSPACE,FONT_SMALL);
						break;
					case 4:
						displayu8(37,6 + i*2 + j,4,1,0,GREEN,FULLSPACE,FONT_SMALL);
						break;
					case 5:
						displayu8(37,6 + i*2 + j,5,1,0,GREEN,FULLSPACE,FONT_SMALL);
						break;
					default:
						break;
				}*/
			}
		}
		if((yu != 0) && (i == mo))
		{
			//箱号
			displayu8(4,6 + i*2,surface_data[i+1][0],1,0,GREEN,FULLSPACE,FONT_SMALL);
			//预警级别
			switch(surface_data[i+1][1] & 0xf0)
			{
				case 0x00:
					displayu8(11,6 + i*2,0,1,0,GREEN,FULLSPACE,FONT_SMALL);
					break;
				case 0x10:
					displayu8(11,6 + i*2,1,1,0,GREEN,FULLSPACE,FONT_SMALL);
					break;
				case 0x20:
					displayu8(11,6 + i*2,2,1,0,GREEN,FULLSPACE,FONT_SMALL);
					break;
				case 0x30:
					displayu8(11,6 + i*2,3,1,0,GREEN,FULLSPACE,FONT_SMALL);
					break;
				case 0x40:
					displayu8(11,6 + i*2,4,1,0,GREEN,FULLSPACE,FONT_SMALL);
					break;
				default:
					break;
			}
			//故障状态
			switch(surface_data[i+1][1] & 0x0c)
			{						
				case 0x00:
					display_icon(page_main_internal_zhengchang,GREEN,15,6 + i*2);
					clear_area_block(18,6 + i*2,1,1);
					break;
				case 0x04:
					displayu8(18,6 + i*2,1,1,0,GREEN,FULLSPACE,FONT_SMALL);
					clear_area_block(15,6 + i*2,3,1);
					break;
				case 0x08:
					displayu8(18,6+ i*2,2,1,0,GREEN,FULLSPACE,FONT_SMALL);
					clear_area_block(15,6 + i*2,3,1);
					break;						
				case 0x0c:
					displayu8(18,6+ i*2,3,1,0,GREEN,FULLSPACE,FONT_SMALL);
					clear_area_block(15,6 + i*2,3,1);
					break;
				default:
					break;
				}
			//子阀状态
			switch(surface_data[i+1][1] & 0x03)
			{						
				case 0x01:
					displayu8(32,6+ i*2,1,1,0,GREEN,FULLSPACE,FONT_SMALL);
					break;
				case 0x02:
					displayu8(32,6+ i*2,2,1,0,GREEN,FULLSPACE,FONT_SMALL);
					break;
				case 0x03:
					displayu8(32,6+ i*2,3,1,0,GREEN,FULLSPACE,FONT_SMALL);
					break;
				default:
					break;
			}
			//灭火弹类型
			switch(surface_data[i+1][3])
			{
				case 0:
					displayu8(25,6 + i*2,0,1,0,GREEN,FULLSPACE,FONT_SMALL);
					clear_area_block(22,6 + i*2,3,1);
					break;
				case 1:
					displayu8(25,6 + i*2,1,1,0,GREEN,FULLSPACE,FONT_SMALL);
					clear_area_block(22,6 + i*2,3,1);
					break;
				case 2:
					displayu8(25,6 + i*2,2,1,0,GREEN,FULLSPACE,FONT_SMALL);
					clear_area_block(22,6 + i*2,3,1);
					break;
				case 3:
					displayu8(25,6+ i*2,3,1,0,GREEN,FULLSPACE,FONT_SMALL);
					clear_area_block(22,6 + i*2,3,1);
					break;						
				case 4:
					displayu8(25,6+ i*2,4,1,0,GREEN,FULLSPACE,FONT_SMALL);
					clear_area_block(22,6 + i*2,3,1);
					break;						
				case 5:
					displayu8(25,6+ i*2,5,1,0,GREEN,FULLSPACE,FONT_SMALL);
					clear_area_block(22,6 + i*2,3,1);
					break;
				case 6:
					displayu8(25,6+ i*2,6,1,0,GREEN,FULLSPACE,FONT_SMALL);
					clear_area_block(22,6 + i*2,3,1);
					break;
				case 7:
					displayu8(25,6+ i*2,7,1,0,GREEN,FULLSPACE,FONT_SMALL);
					clear_area_block(22,6 + i*2,3,1);
					break;
				case 255:
					displayu8(22,6+ i*2,255,3,0,GREEN,FULLSPACE,FONT_SMALL);
					clear_area_block(25,6 + i*2,1,1);
					break;
				default:
					break;
			}
			//故障码
			displayu8(42,6 + i*2,surface_data[i+1][2],2,0,GREEN,FULLSPACE,FONT_SMALL);
			/*switch(surface_data[i+1][2])
			{
				case 0:
					displayu8(41,6 + i*2,0,1,0,GREEN,FULLSPACE,FONT_SMALL);
					break;
				case 1:
					displayu8(41,6+ i*2,1,1,0,GREEN,FULLSPACE,FONT_SMALL);
					break;
				case 2:
					displayu8(41,6 + i*2,2,1,0,GREEN,FULLSPACE,FONT_SMALL);
					break;
				case 3:
					displayu8(41,6+ i*2,3,1,0,GREEN,FULLSPACE,FONT_SMALL);
					break;
				case 4:
					displayu8(41,6 + i*2,4,1,0,GREEN,FULLSPACE,FONT_SMALL);
					break;
				case 5:
					displayu8(41,6 + i*2,5,1,0,GREEN,FULLSPACE,FONT_SMALL);
					break;
				default:
					break;
			}*/
		}
	}
	else
		clear_area_block(3,6,44,11);
	
#endif

}

void display_surface19 (void)
{
    unsigned char i;
    unsigned int temp;
    temp = meter_input;
    for (i = 0; i < 4; i++)
    {
        if (temp & 0x01)
        {
            display_uncolor_icon (page_main_internal_status_green, 1, 1 + i);
        }
        else
        {
            clear_icon (page_main_internal_status_green, 1, 1 + i);
        }
        temp >>= 1;
    }
    temp = meter_output;
    for (i = 0; i < 4; i++)
    {
        if ((temp & 0x03) == 0)
        {
            display_uncolor_icon (page_main_internal_status_green, 1, 6 + i);
        }
        else
            if ((temp & 0x03) == 2)
            {
                display_uncolor_icon (page_main_internal_status_red, 1, 6 + i);
            }
            else
            {
                clear_area_block (1, 6 + i, 2, 1);
            }
        temp >>= 2;
    }
}
void display_surface20 (void)
{
#if 0
	unsigned char u8_data,i;
	unsigned char u4_bit[2];
	u8_data = surface_data[0][0]<<2;
	//临时停车激活、临时停车工作、电子驻车状态
	for(i=0;i<3;i++)
	{
		if((u8_data & 0xC0) == 0x40)
			display_icon(page_main_internal_youxiao,GREEN,28,5 + i);
		else
			display_icon(page_main_internal_wuxiao,GREEN,28,5 + i);
		u8_data <<= 2;
	}
	//低压释放限制状态、童锁状态
	u8_data = surface_data[0][2]<<4;
	for(i=0;i<2;i++)
	{
		if((u8_data & 0xC0) == 0x40)
			display_icon(page_main_internal_youxiao,GREEN,28,8 + i);
		else
			display_icon(page_main_internal_wuxiao,GREEN,28,8 + i);
		u8_data <<= 2;
	}
	//故障码
	if(surface_data[0][1] == 0)
		clear_area_block(28,10,5,1);
	else
	{
		u4_bit[0] = surface_data[0][1] & 0x0f;
		u4_bit[1] = (surface_data[0][1] >> 4) & 0x0f;
		displayu8(28,10,u4_bit[1],1,0,RED,FULLSPACE,FONT_SMALL);
		display_icon(page_main_internal_number_10,RED,29,10);
		displayu8(30,10,u4_bit[0],1,0,RED,FULLSPACE,FONT_SMALL);
	}
	//故障部件及原因
	switch(surface_data[0][1])
	{
		case 0x11:
			display_gicon(page_main_internal_s20_g1_jinqi,RED,28,11);
			display_gicon(page_main_internal_s20_g2_dianyuan,RED,28,12);
			break;
		case 0x21:
			display_gicon(page_main_internal_s20_g1_jinqi,RED,28,11);
			display_gicon(page_main_internal_s20_g2_di,RED,28,12);
			break;
		case 0x31:
			display_gicon(page_main_internal_s20_g1_jinqi,RED,28,11);
			display_gicon(page_main_internal_s20_g2_duanlu,RED,28,12);
			break;
		case 0x14:
			display_gicon(page_main_internal_s20_g1_paiqi,RED,28,11);
			display_gicon(page_main_internal_s20_g2_dianyuan,RED,28,12);
			break;
		case 0x24:
			display_gicon(page_main_internal_s20_g1_paiqi,RED,28,11);
			display_gicon(page_main_internal_s20_g2_di,RED,28,12);
			break;
		case 0x34:
			display_gicon(page_main_internal_s20_g1_paiqi,RED,28,11);
			display_gicon(page_main_internal_s20_g2_duanlu,RED,28,12);
			break;
		case 0x53:
			display_gicon(page_main_internal_s20_g1_ebs,RED,28,11);
			display_gicon(page_main_internal_s20_g2_ebs,RED,28,12);
			break;
		case 0x16:
			display_gicon(page_main_internal_s20_g1_zhidong,RED,28,11);
			display_gicon(page_main_internal_s20_g2_dianyuan,RED,28,12);
			break;
		case 0x26:
			display_gicon(page_main_internal_s20_g1_zhidong,RED,28,11);
			display_gicon(page_main_internal_s20_g2_di,RED,28,12);
			break;
		case 0x36:
			display_gicon(page_main_internal_s20_g1_zhidong,RED,28,11);
			display_gicon(page_main_internal_s20_g2_duanlu,RED,28,12);
			break;
		case 0x41:
			display_gicon(page_main_internal_s20_g1_fadian,RED,28,11);
			display_gicon(page_main_internal_s20_g2_dianyagao,RED,28,12);
			break;
		case 0x42:
			display_gicon(page_main_internal_s20_g1_fadian,RED,28,11);
			display_gicon(page_main_internal_s20_g2_dianyadi,RED,28,12);
			break;
		case 0x43:
			display_gicon(page_main_internal_s20_g1_fadian,RED,28,11);
			display_gicon(page_main_internal_s20_g2_three,RED,28,12);
			break;
		case 0x44:
			display_gicon(page_main_internal_s20_g1_can,RED,28,11);
			display_gicon(page_main_internal_s20_g2_diushi,RED,28,12);
			break;
		case 0x54:
			display_gicon(page_main_internal_s20_g1_can,RED,28,11);
			display_gicon(page_main_internal_s20_g2_duanlu,RED,28,12);
			break;
		case 0x55:
			display_gicon(page_main_internal_s20_g1_chuanganqi,RED,28,11);
			display_gicon(page_main_internal_s20_g2_chuanganqi,RED,28,12);
			break;
		case 0x56:
			display_gicon(page_main_internal_s20_g1_kaiguan,RED,28,11);
			display_gicon(page_main_internal_s20_g2_kaiguan,RED,28,12);
			break;
		case 0x22:
			display_gicon(page_main_internal_s20_g1_mokuai,RED,28,11);
			display_gicon(page_main_internal_s20_g2_fati,RED,28,12);
			break;
		default:
			clear_area_block(28,11,12,2);
			break;
	}

#endif

}

void display_surface21 (void)
{




}



