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

TW_DATA  FLAG[5] = {0};
struct tw_gicon *code alarm_pos[] =
{
    //&page_main_internal_soc_7,
	&page_main_internal_alarm_pos_0,
    &page_main_internal_alarm_pos_1,
    &page_main_internal_alarm_pos_2,
    &page_main_internal_alarm_pos_3,
    &page_main_internal_alarm_pos_4,
    &page_main_internal_alarm_pos_5,

};



struct tw_gicon *code fault_map[] =
{
    &page_main_internal_fault_alarm_0,
    &page_main_internal_fault_alarm_1,
    &page_main_internal_fault_alarm_2,
    &page_main_internal_fault_alarm_3,
    &page_main_internal_fault_alarm_4,
    &page_main_internal_fault_alarm_5,
    &page_main_internal_fault_alarm_6,
    &page_main_internal_fault_alarm_7,
    &page_main_internal_fault_alarm_8,
    &page_main_internal_fault_alarm_9,
    &page_main_internal_fault_alarm_10,
    &page_main_internal_fault_alarm_11,
    &page_main_internal_fault_alarm_12,
    &page_main_internal_fault_alarm_13,
    &page_main_internal_fault_alarm_14,
    &page_main_internal_fault_alarm_15,
    &page_main_internal_fault_alarm_16,
    &page_main_internal_fault_alarm_17,
    &page_main_internal_fault_alarm_18,
    &page_main_internal_fault_alarm_19,
    &page_main_internal_fault_alarm_20,
    &page_main_internal_fault_alarm_21,
    &page_main_internal_fault_alarm_22,
    &page_main_internal_fault_alarm_23,
    &page_main_internal_fault_alarm_24,
    &page_main_internal_fault_alarm_25,
    &page_main_internal_fault_alarm_26,
    &page_main_internal_fault_alarm_27,
    &page_main_internal_fault_alarm_28,
    &page_main_internal_fault_alarm_29,
    &page_main_internal_fault_alarm_30,
    &page_main_internal_fault_alarm_31,
    &page_main_internal_fault_alarm_32,
    &page_main_internal_fault_alarm_33,
    &page_main_internal_fault_alarm_34,
    &page_main_internal_fault_alarm_35,
    &page_main_internal_fault_alarm_36,
    &page_main_internal_fault_alarm_37,
    &page_main_internal_fault_alarm_38,
    &page_main_internal_fault_alarm_39,
    &page_main_internal_fault_alarm_40,
    &page_main_internal_fault_alarm_41,
    &page_main_internal_fault_alarm_42,
    &page_main_internal_fault_alarm_43,
    &page_main_internal_fault_alarm_44,
    &page_main_internal_fault_alarm_45,
    &page_main_internal_fault_alarm_46,
    &page_main_internal_fault_alarm_47,
    &page_main_internal_fault_alarm_48,
    &page_main_internal_fault_alarm_49,
    &page_main_internal_fault_alarm_50,
    &page_main_internal_fault_alarm_51,
    &page_main_internal_fault_alarm_52,
    &page_main_internal_fault_alarm_53,
    &page_main_internal_fault_alarm_54,
    &page_main_internal_fault_alarm_55,
    &page_main_internal_fault_alarm_56,
    &page_main_internal_fault_alarm_57,
    &page_main_internal_fault_alarm_58,
    &page_main_internal_fault_alarm_59,
    &page_main_internal_fault_alarm_60,
    &page_main_internal_fault_alarm_61,
    &page_main_internal_fault_alarm_62,
    &page_main_internal_fault_alarm_63,
    &page_main_internal_fault_alarm_64,
    &page_main_internal_fault_alarm_65,
    &page_main_internal_fault_alarm_66,
    &page_main_internal_fault_alarm_67,
    &page_main_internal_fault_alarm_68,
    &page_main_internal_fault_alarm_69,
    &page_main_internal_fault_alarm_70,
    &page_main_internal_fault_alarm_71,
    &page_main_internal_fault_alarm_72,
    &page_main_internal_fault_alarm_73,
    &page_main_internal_fault_alarm_74,
    &page_main_internal_fault_alarm_75,
    &page_main_internal_fault_alarm_76,
    &page_main_internal_fault_alarm_77,
    &page_main_internal_fault_alarm_78,
    &page_main_internal_fault_alarm_79,
    &page_main_internal_fault_alarm_80,
    &page_main_internal_fault_alarm_81,
    &page_main_internal_fault_alarm_82,
    &page_main_internal_fault_alarm_83,
    &page_main_internal_fault_alarm_84,
    &page_main_internal_fault_alarm_85,
    &page_main_internal_fault_alarm_86,
    &page_main_internal_fault_alarm_87,
    &page_main_internal_fault_alarm_88,
    &page_main_internal_fault_alarm_89,
    &page_main_internal_fault_alarm_90,
    &page_main_internal_fault_alarm_91,
    &page_main_internal_fault_alarm_92,
    &page_main_internal_fault_alarm_93,
    &page_main_internal_fault_alarm_94,
    &page_main_internal_fault_alarm_95,
    &page_main_internal_fault_alarm_96,
    &page_main_internal_fault_alarm_97,
    &page_main_internal_fault_alarm_98,
    &page_main_internal_fault_alarm_99,
    &page_main_internal_fault_alarm_100,
    &page_main_internal_fault_alarm_101,
    &page_main_internal_fault_alarm_102,
    &page_main_internal_fault_alarm_103,
    &page_main_internal_fault_alarm_104,
    &page_main_internal_fault_alarm_105,
    &page_main_internal_fault_alarm_106,
    &page_main_internal_fault_alarm_107,
    &page_main_internal_fault_alarm_108,
    &page_main_internal_fault_alarm_109,
    &page_main_internal_fault_alarm_110,
    &page_main_internal_fault_alarm_111,
    &page_main_internal_fault_alarm_112,
    &page_main_internal_fault_alarm_113,
    &page_main_internal_fault_alarm_114,
    &page_main_internal_fault_alarm_115,
    &page_main_internal_fault_alarm_116,
    &page_main_internal_fault_alarm_117,
    &page_main_internal_fault_alarm_118,
    &page_main_internal_fault_alarm_119,
    &page_main_internal_fault_alarm_120,
    &page_main_internal_fault_alarm_121,
    &page_main_internal_fault_alarm_122,
    &page_main_internal_fault_alarm_123,
    &page_main_internal_fault_alarm_124,
    &page_main_internal_fault_alarm_125,
    &page_main_internal_fault_alarm_126,
    &page_main_internal_fault_alarm_127,
    &page_main_internal_fault_alarm_128,
    &page_main_internal_fault_alarm_129,
    &page_main_internal_fault_alarm_130,
    &page_main_internal_fault_alarm_131,
    &page_main_internal_fault_alarm_132,
    &page_main_internal_fault_alarm_133,
    &page_main_internal_fault_alarm_134,
    &page_main_internal_fault_alarm_135,
    &page_main_internal_fault_alarm_136,
    &page_main_internal_fault_alarm_137,
    &page_main_internal_fault_alarm_138,
    &page_main_internal_fault_alarm_139,
    &page_main_internal_fault_alarm_140,
    &page_main_internal_fault_alarm_141,
    &page_main_internal_fault_alarm_142,
    &page_main_internal_fault_alarm_143,
    &page_main_internal_fault_alarm_144,
    &page_main_internal_fault_alarm_145,
    &page_main_internal_fault_alarm_146,
    &page_main_internal_fault_alarm_147,
    &page_main_internal_fault_alarm_148,
    &page_main_internal_fault_alarm_149,
    &page_main_internal_fault_alarm_150,
    &page_main_internal_fault_alarm_151,
    &page_main_internal_fault_alarm_152,
    &page_main_internal_fault_alarm_153,
    &page_main_internal_fault_alarm_154,
    &page_main_internal_fault_alarm_155,
    &page_main_internal_fault_alarm_156,
    &page_main_internal_fault_alarm_157,
    &page_main_internal_fault_alarm_158,
    &page_main_internal_fault_alarm_159,
    &page_main_internal_fault_alarm_160,
    &page_main_internal_fault_alarm_161,
    &page_main_internal_fault_alarm_162,
    &page_main_internal_fault_alarm_163,
    &page_main_internal_fault_alarm_164,
    &page_main_internal_fault_alarm_165,
    &page_main_internal_fault_alarm_166,
    &page_main_internal_fault_alarm_167,
    &page_main_internal_fault_alarm_168,
    &page_main_internal_fault_alarm_169,
    &page_main_internal_fault_alarm_170,
    &page_main_internal_fault_alarm_171,
    &page_main_internal_fault_alarm_172,
    &page_main_internal_fault_alarm_173,
    &page_main_internal_fault_alarm_174,
    &page_main_internal_fault_alarm_175,
    &page_main_internal_fault_alarm_176,
    &page_main_internal_fault_alarm_177,
	&page_main_internal_fault_alarm_178,
	&page_main_internal_fault_alarm_179,
	&page_main_internal_fault_alarm_180,
	&page_main_internal_fault_alarm_181,
	&page_main_internal_fault_alarm_182,
	&page_main_internal_fault_alarm_183,
	&page_main_internal_fault_alarm_184,
	&page_main_internal_fault_alarm_185,
	&page_main_internal_fault_alarm_186,
	&page_main_internal_fault_alarm_187,
	&page_main_internal_fault_alarm_188,
	&page_main_internal_fault_alarm_189,
	&page_main_internal_fault_alarm_190,
	&page_main_internal_fault_alarm_191,
	&page_main_internal_fault_alarm_192,
	&page_main_internal_fault_alarm_193,
	&page_main_internal_fault_alarm_194,
	&page_main_internal_fault_alarm_195,
	&page_main_internal_fault_alarm_196,
	&page_main_internal_fault_alarm_197,
	&page_main_internal_fault_alarm_198,
	&page_main_internal_fault_alarm_199,
};

struct tw_icon code *buzzer_map[2] =
{
    &page_main_internal_font_open,
    &page_main_internal_font_close,
};
#if AIR_DISP
struct tw_icon code *air_map[10] =
{
    &page_main_internal_air_0,
    &page_main_internal_air_1,
    &page_main_internal_air_2,
    &page_main_internal_air_3,
    &page_main_internal_air_4,
    &page_main_internal_air_5,
    &page_main_internal_air_6,
    &page_main_internal_air_7,
    &page_main_internal_air_8,
    &page_main_internal_air_9,
};
#endif
#if BIG_SOC
struct tw_gicon code *soc_map[101] =
{
    &page_main_internal_battery_0,
    &page_main_internal_battery_1,
    &page_main_internal_battery_2,
    &page_main_internal_battery_3,
    &page_main_internal_battery_4,
    &page_main_internal_battery_5,
    &page_main_internal_battery_6,
    &page_main_internal_battery_7,
    &page_main_internal_battery_8,
    &page_main_internal_battery_9,
    &page_main_internal_battery_10,
    &page_main_internal_battery_11,
    &page_main_internal_battery_12,
    &page_main_internal_battery_13,
    &page_main_internal_battery_14,
    &page_main_internal_battery_15,
    &page_main_internal_battery_16,
    &page_main_internal_battery_17,
    &page_main_internal_battery_18,
    &page_main_internal_battery_19,
    &page_main_internal_battery_20,
    &page_main_internal_battery_21,
    &page_main_internal_battery_22,
    &page_main_internal_battery_23,
    &page_main_internal_battery_24,
    &page_main_internal_battery_25,
    &page_main_internal_battery_26,
    &page_main_internal_battery_27,
    &page_main_internal_battery_28,
    &page_main_internal_battery_29,
    &page_main_internal_battery_30,
    &page_main_internal_battery_31,
    &page_main_internal_battery_32,
    &page_main_internal_battery_33,
    &page_main_internal_battery_34,
    &page_main_internal_battery_35,
    &page_main_internal_battery_36,
    &page_main_internal_battery_37,
    &page_main_internal_battery_38,
    &page_main_internal_battery_39,
    &page_main_internal_battery_40,
    &page_main_internal_battery_41,
    &page_main_internal_battery_42,
    &page_main_internal_battery_43,
    &page_main_internal_battery_44,
    &page_main_internal_battery_45,
    &page_main_internal_battery_46,
    &page_main_internal_battery_47,
    &page_main_internal_battery_48,
    &page_main_internal_battery_49,
    &page_main_internal_battery_50,
    &page_main_internal_battery_51,
    &page_main_internal_battery_52,
    &page_main_internal_battery_53,
    &page_main_internal_battery_54,
    &page_main_internal_battery_55,
    &page_main_internal_battery_56,
    &page_main_internal_battery_57,
    &page_main_internal_battery_58,
    &page_main_internal_battery_59,
    &page_main_internal_battery_60,
    &page_main_internal_battery_61,
    &page_main_internal_battery_62,
    &page_main_internal_battery_63,
    &page_main_internal_battery_64,
    &page_main_internal_battery_65,
    &page_main_internal_battery_66,
    &page_main_internal_battery_67,
    &page_main_internal_battery_68,
    &page_main_internal_battery_69,
    &page_main_internal_battery_70,
    &page_main_internal_battery_71,
    &page_main_internal_battery_72,
    &page_main_internal_battery_73,
    &page_main_internal_battery_74,
    &page_main_internal_battery_75,
    &page_main_internal_battery_76,
    &page_main_internal_battery_77,
    &page_main_internal_battery_78,
    &page_main_internal_battery_79,
    &page_main_internal_battery_80,
    &page_main_internal_battery_81,
    &page_main_internal_battery_82,
    &page_main_internal_battery_83,
    &page_main_internal_battery_84,
    &page_main_internal_battery_85,
    &page_main_internal_battery_86,
    &page_main_internal_battery_87,
    &page_main_internal_battery_88,
    &page_main_internal_battery_89,
    &page_main_internal_battery_90,
    &page_main_internal_battery_91,
    &page_main_internal_battery_92,
    &page_main_internal_battery_93,
    &page_main_internal_battery_94,
    &page_main_internal_battery_95,
    &page_main_internal_battery_96,
    &page_main_internal_battery_97,
    &page_main_internal_battery_98,
    &page_main_internal_battery_99,
    &page_main_internal_battery_100,
};
#endif

#if SMALL_SOC
struct tw_icon code *soc_map[8] =
{
    &page_main_internal_soc_0,
    &page_main_internal_soc_1,
    &page_main_internal_soc_2,
    &page_main_internal_soc_3,
    &page_main_internal_soc_4,
    &page_main_internal_soc_5,
    &page_main_internal_soc_6,
    &page_main_internal_soc_7,
};
#endif

void Deal_para (void)
{
    unsigned char i, c_blink, b_x, b_y, temp[2];
    switch (para_cmd)
    {
        case PAGE_PASSWORD:
            for (i = 0; i < 4; i++)
            {
                if (i == system_b_password.blink)
                {
                    c_blink = 1;
                }
                else
                {
                    c_blink = 0;
                }
                display_icon_uncolor_blink (*number_map[system_b_password.para[i]], 12 + i, 7, c_blink);
            }
            break;
        case PAGE_PARA:
            for (i = 0; i < 11; i++)
            {
                if (i == system_b_set.blink)
                {
                    c_blink = 1;
                }
                else
                {
                    c_blink = 0;
                }
                switch (i)
                {
                    case SET_HOUR:
                        b_x = 19;
                        b_y = 2;
                        break;
                    case SET_MINUTE:
                        b_x = 22;
                        b_y = 2;
                        break;
                    case SET_YEAR:
                        b_x = 21;
                        b_y = 4;
                        break;
                    case SET_MONTH:
                        b_x = 24;
                        b_y = 4;
                        break;
                    case SET_DAY:
                        b_x = 27;
                        b_y = 4;
                        break;
                    case SET_LIGHT:
                        b_x = 18;
                        b_y = 6;
                        break;
                    case SET_BUZZER:
                        b_x = 19;
                        b_y = 8;
                        break;
                    default:
                        break;
                }
                if (i < 6)
                {
                    temp[0] = (system_b_set.para[i] >> 4) & 0x0f;
                    temp[1] = system_b_set.para[i] & 0x0f;
                    if (i != 5)
                    {
                        display_icon_uncolor_blink (*number_map[temp[0]], b_x, b_y, c_blink);
                    }
                    display_icon_uncolor_blink (*number_map[temp[1]], b_x + 1, b_y, c_blink);
                }
                else
                    if (i == 6)
                    {
                        display_icon_uncolor_blink (*buzzer_map[system_b_set.para[i]], b_x, b_y, c_blink);
                    }
                #if 0
                    else
                        if (i == 7)
                        {
                            display_icon_uncolor_blink (*buzzer_map[system_b_set.para[i]], 39, 2, c_blink);
                        }
                        else
                            if (i == 8)
                            {
                                display_icon_uncolor_blink (*buzzer_map[system_b_set.para[i]], 39, 3, c_blink);
                            }
                            else
                                if (i == 9)
                                {
                                    display_icon_uncolor_blink (*buzzer_map[system_b_set.para[i]], 39, 4, c_blink);
                                }
                                else
                                    if (i == 10)
                                    {
                                        display_icon_uncolor_blink (*buzzer_map[system_b_set.para[i]], 39, 5, c_blink);
                                    }
                #endif
            }
            break;
        case PAGE_SET:
            for (i = 0; i < 44; i++)
            {
                if (i == system_b_odo_char.blink)
                {
                    c_blink = 1;
                }
                else
                {
                    c_blink = 0;
                }
                if (i < 7)
                {
                    display_icon_uncolor_blink (*number_map[system_b_odo_char.para[i]], 19 + i, 9, c_blink);
                }
	            else  if (i < 11)
                {
                    display_icon_uncolor_blink (*number_map[system_b_odo_char.para[i]], 12 + i, 10, c_blink);
                }
	            else if (i < 15)
                {
                    display_icon_uncolor_blink (*number_map[system_b_odo_char.para[i]], 8 + i, 11, c_blink);
                }
	            else if (i < 18)
	            {
	                display_icon_uncolor_blink (*number_map[system_b_odo_char.para[i]], 4 + i, 12, c_blink);
	            }
	             else if (i < 21)
	            {
	                display_icon_uncolor_blink (*number_map[system_b_odo_char.para[i]], i + 1, 13, c_blink);
	            }
	            else if (i < 24)
                {
                    display_icon_uncolor_blink (*number_map[system_b_odo_char.para[i]], i - 2, 14, c_blink);
                }
	            else if (i < 27)
                {
                    display_icon_uncolor_blink (*number_map[system_b_odo_char.para[i]], i - 5, 15, c_blink);
                }
	            else if (i < 30)
                {
                    display_icon_uncolor_blink (*number_map[system_b_odo_char.para[i]], i - 8, 16, c_blink);
                }
	            else if (i < 33)
                {
                    display_icon_uncolor_blink (*number_map[system_b_odo_char.para[i]], i - 11, 17, c_blink);
                }
	            else if (i < 36)
                {
                    display_icon_uncolor_blink (*number_map[system_b_odo_char.para[i]], i + 7, 9, c_blink);
                }
	            else if (i == 36)
	            {
	                display_icon_uncolor_blink (*buzzer_map[system_b_odo_char.para[i]], 40, 10, c_blink);
	            }
	            else if (i == 37)
	            {
	                display_icon_uncolor_blink (*buzzer_map[system_b_odo_char.para[i]], 40, 11, c_blink);
	            }
	            else if(i == 38)
					display_icon_uncolor_blink(*buzzer_map[system_b_odo_char.para[i]],40,12,c_blink);
				else if(i == 39)
					display_icon_uncolor_blink(*buzzer_map[system_b_odo_char.para[i]],40,13,c_blink);
				else if(i== 40)
					display_icon_uncolor_blink(*buzzer_map[system_b_odo_char.para[i]],40,14,c_blink);
				else if(i < 44)
					display_icon_uncolor_blink(*number_map[system_b_odo_char.para[i]],i - 1,15,c_blink);
            }
            break;
    }
}

void protocl_event (unsigned char cmd_type)
{
    #if MODULE_FRONT_B50 || MODULE_REAR_B50 || MODULE_TOP_B50
    unsigned char i;
    #endif
    switch (cmd_type)
    {
        case UART1_MAIN_PAGE:
            if (system_page.current_page == UART1_MAIN_PAGE)
            {
                display_air();
                switch (dandu_disp)
                {
                    case MAIN_MARK:
                        display_mark();
                        break;
                    case MAIN_MILE:
                        display_mileage();
                        break;
                    case MAIN_TIME:
                        if (DISP_AIR)
                        {
                            display_air();
                        }
                        if (DISP_SOC)
                        {
                            display_soc();
                        }
                        if (DISP_TIME)
                        {
                            display_system_time();
                        }
                        DISP_AIR = 0;
                        DISP_SOC = 0;
                        DISP_TIME = 0;
                        break;
                    case MAIN_DATA:
                        diplay_main_data();
                        break;
                    default:
                        break;
                }
                dandu_disp = 0;
            }
            break;
        case UART1_MENU_PAGE:
            if (system_page.current_page == UART1_MENU_PAGE)
            {
                clear_unalarm_area();
                if (menu < CURSOR_NUM)
                {
                    display_uncolor_icon (page_main_internal_arrows, CURSOR_R_X, CURSOR_R_Y - menu);
                }
                else
                {
                    display_uncolor_icon (page_main_internal_arrows, CURSOR_L_X, CURSOR_L_Y - menu);
                }
            }
            break;
        case UART1_PARA_PAGE:
            if (system_page.current_page == UART1_PARA_PAGE)
            {
                Deal_para();
            }
            break;
        case UART1_VIDEO_PAGE:
            //CVBS0:ACB0 -倒车
            //CVBS1:AY0 -中门
            //CVBS2:ACR0-前门
            //CVBS3:ACB2-备用
            if (system_page.current_page == UART1_VIDEO_PAGE)
            {
                tw_timer_open (100);
                display_icon (page_main_internal_av, GREEN, 46, 1);
                if (system_video == ICVBS0) //okacb2
                {
                    IC_WritByte (TWIC_P0, 0x0f, 0x40);
                    IC_WritByte (TWIC_P0, 0x18, 0x30);
                    IC_WritByte (TWIC_P0, 0x19, 0x0c);
                    display_icon (*number_map[1], GREEN, 48, 1);
                }
                else
                    if (system_video == ICVBS1) //okacr0
                    {
                        IC_WritByte (TWIC_P0, 0x0f, 0x00);
                        IC_WritByte (TWIC_P0, 0x19, 0x80);
                        IC_WritByte (TWIC_P1, 0x13, 0x02);
                        display_icon (*number_map[2], GREEN, 48, 1);
                    }
                    else
                        if (system_video == ICVBS2) //ok acb0
                        {
                            IC_WritByte (TWIC_P0, 0x0f, 0x00);
                            IC_WritByte (TWIC_P0, 0x19, 0x80);
                            IC_WritByte (TWIC_P1, 0x13, 0x06);
                            display_icon (*number_map[3], GREEN, 48, 1);
                        }
                        else
                            if (system_video == ICVBS3) //ok ay0
                            {
                                IC_WritByte (TWIC_P0, 0x0f, 0x00);
                                IC_WritByte (TWIC_P0, 0x19, 0x80);
                                IC_WritByte (TWIC_P1, 0x13, 0x00);
                                display_icon (*number_map[4], GREEN, 48, 1);
                            }
            }
            break;
        case UART1_METER_PAGE:
            if (system_page.current_page == UART1_METER_PAGE)
            {
                if (status_para_change == 1)
                {
                    display_meter_status();
                }
                #if METER_C50
                else
                    if (status_para_change == 2)
                    {
                        displayu16 (43, 11, meter_para_A2, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        displayu16 (43, 12, meter_para_A3, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        displayu16 (43, 13, meter_para_A4, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                    }
                    else
                        if (status_para_change == 3)
                        {
                            displayu16 (43, 14, meter_para_A5, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                            displayu16 (43, 15, meter_para_A13, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                            displayu16 (43, 16, meter_para_A14, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        }
                #elif METER_C61
                else
                    if (status_para_change == 2)
                    {
                        displayu16 (43, 6, meter_para_A2, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        displayu16 (43, 7, meter_para_A3, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        displayu16 (43, 8, meter_para_A4, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        displayu16 (43, 9, meter_para_A5, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                    }
                    else
                        if (status_para_change == 3)
                        {
                            displayu16 (43, 10, meter_para_A13, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        }
                #elif METER_C52
                else
                    if (status_para_change == 2)
                    {
                        displayu16 (43, 10, meter_para_A2, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        displayu16 (43, 11, meter_para_A3, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        displayu16 (43, 12, meter_para_A4, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
						displayu8  (27, 17, meter_para_K, 2, 0, GREEN, FULLSPACE, FONT_SMALL);
                        displayu8  (37, 17, meter_para_T, 2, 0, GREEN, FULLSPACE, FONT_SMALL);
                    }
                    else
                        if (status_para_change == 3)
                        {
                            displayu16 (43, 13, meter_para_A5, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                            displayu16 (43, 14, meter_para_A13, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                            displayu16 (43, 15, meter_para_A14, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                            displayu16 (43, 16, meter_para_A15, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        }
                #endif
            }
            break;
        case UART1_FRONT_PAGE:
            if (system_page.current_page == UART1_FRONT_PAGE)
            {
                if (status_para_change == 1)
                {
                    #if MODULE_FRONT_B40
                    display_moudle_output_status (1, front_status[0], front_status[1]);
                    display_moudle_input_status (front_status[2], front_status[3]);
                    #endif
                    #if MODULE_FRONT_B50
                    display_moudle_input_status (front_status[0], front_status[1]);
                    #endif
                }
                else
                    if (status_para_change == 2)
                    {
                        #if MODULE_FRONT_B40
                        displayu16 (43, 7, front_para_A25, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        displayu16 (43, 9, front_para_A40, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        displayu16 (43, 11, front_para_A26, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        #endif
                        #if MODULE_FRONT_B50
                        for (i = 0; i < 7; i++)
                        {
                            if ((i > 3) && (i < 6))
                            {
                                displayu16 (43, 6 + i, front_para[i], 3, 2, GREEN, FULLSPACE, FONT_SMALL);
                            }
                            else
                            {
                                displayu16 (43, 6 + i, front_para[i], 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                            }
                        }
                        #endif
                    }
            }
            break;
        case UART1_REAR_PAGE:
            if (system_page.current_page == UART1_REAR_PAGE)
            {
                if (status_para_change == 1)
                {
                    #if MODULE_REAR_B40
                    display_moudle_output_status (1, rear_status[0], rear_status[1]);
                    display_moudle_input_status (rear_status[2], rear_status[3]);
                    #endif
                    #if MODULE_REAR_B50
                    display_moudle_input_status (rear_status[0], rear_status[1]);
                    #endif
                }
                else
                    if (status_para_change == 2)
                    {
                        #if MODULE_REAR_B40
                        displayu16 (43, 7, rear_para_A25, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        displayu16 (43, 9, rear_para_A40, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        displayu16 (43, 11, rear_para_A26, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        #endif
                        #if MODULE_REAR_B50
                        for (i = 0; i < 7; i++)
                        {
                            if ((i > 4) && (i < 6))
                            {
                                displayu16 (43, 6 + i, rear_para[i], 3, 2, GREEN, FULLSPACE, FONT_SMALL);
                            }
                            else
                            {
                                displayu16 (43, 6 + i, rear_para[i], 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                            }
                        }
                        #endif
                    }
            }
            break;
        case UART1_TOP_PAGE:
            if (system_page.current_page == UART1_TOP_PAGE)
            {
                if (status_para_change == 1)
                {
                    #if MODULE_TOP_B40
                    display_moudle_output_status (1, top_status[0], top_status[1]);
                    display_moudle_input_status (top_status[2], top_status[3]);
                    #endif
                    #if MODULE_TOP_B50
                    display_moudle_input_status (top_status[0], top_status[1]);
                    #endif
                }
                else
                    if (status_para_change == 2)
                    {
                        #if MODULE_TOP_B40
                        displayu16 (43, 7, top_para_A25, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        displayu16 (43, 9, top_para_A40, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        displayu16 (43, 11, top_para_A26, 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                        #endif
                        #if MODULE_TOP_B50
                        for (i = 0; i < 7; i++)
                        {
                            if ((i > 3) && (i < 6))
                            {
                                displayu16 (43, 6 + i, top_para[i], 3, 2, GREEN, FULLSPACE, FONT_SMALL);
                            }
                            else
                            {
                                displayu16 (43, 6 + i, top_para[i], 5, 0, GREEN, FULLSPACE, FONT_SMALL);
                            }
                        }
                        #endif
                    }
            }
            break;
        case UART1_FRONT_OUT_PAGE:
            if (system_page.current_page == UART1_FRONT_OUT_PAGE)
            {
                #if MODULE_FRONT_B50
                display_moudle_output_status (1, front_out_status[0], front_out_status[1]);
                display_moudle_output_status (18, front_out_status[2], front_out_status[3]);
                display_moudle_output_status (34, front_out_status[4], front_out_status[5]);
                #endif
            }
            break;
        case UART1_REAR_OUT_PAGE:
            if (system_page.current_page == UART1_REAR_OUT_PAGE)
            {
                #if MODULE_REAR_B50
                display_moudle_output_status (1, rear_out_status[0], rear_out_status[1]);
                display_moudle_output_status (18, rear_out_status[2], rear_out_status[3]);
                display_moudle_output_status (34, rear_out_status[4], rear_out_status[5]);
                #endif
            }
            break;
        case UART1_TOP_OUT_PAGE:
            if (system_page.current_page == UART1_TOP_OUT_PAGE)
            {
                #if MODULE_TOP_B50
                display_moudle_output_status (1, top_out_status[0], top_out_status[1]);
                display_moudle_output_status (18, top_out_status[2], top_out_status[3]);
                display_moudle_output_status (34, top_out_status[4], top_out_status[5]);
                #endif
            }
            break;
        case UART1_SURFACE1_PAGE:
            #if (PAGE_ADD > 0)
            if (system_page.current_page == UART1_SURFACE1_PAGE)
            {
                display_surface1();
            }
            #endif
            break;
        case UART1_SURFACE2_PAGE:
            #if (PAGE_ADD > 1)
            if (system_page.current_page == UART1_SURFACE2_PAGE)
            {
                display_surface2();
            }
            #endif
            break;
        case UART1_SURFACE3_PAGE:
            #if (PAGE_ADD > 2)
            if (system_page.current_page == UART1_SURFACE3_PAGE)
            {
                display_surface3();
            }
            #endif
            break;
        case UART1_SURFACE4_PAGE:
            #if (PAGE_ADD > 3)
            if (system_page.current_page == UART1_SURFACE4_PAGE)
            {
                display_surface4();
            }
            #endif
            break;
        case UART1_SURFACE5_PAGE:
            #if (PAGE_ADD > 4)
            if (system_page.current_page == UART1_SURFACE5_PAGE)
            {
                display_surface5();
            }
            #endif
            break;
        case UART1_SURFACE6_PAGE:
            #if (PAGE_ADD > 5)
            if (system_page.current_page == UART1_SURFACE6_PAGE)
            {
                display_surface6();
            }
            #endif
            break;
        case UART1_SURFACE7_PAGE:
            #if (PAGE_ADD > 6)
            if (system_page.current_page == UART1_SURFACE7_PAGE)
            {
                display_surface7();
            }
            #endif
            break;
        case UART1_SURFACE8_PAGE:
            #if (PAGE_ADD > 7)
            if (system_page.current_page == UART1_SURFACE8_PAGE)
            {
                display_surface8();
            }
            #endif
            break;
        case UART1_SURFACE9_PAGE:
            #if (PAGE_ADD > 8)
            if (system_page.current_page == UART1_SURFACE9_PAGE)
            {
                display_surface9();
            }
            #endif
            break;
        case UART1_SURFACE10_PAGE:
            #if (PAGE_ADD > 9)
            if (system_page.current_page == UART1_SURFACE10_PAGE)
            {
                display_surface10();
            }
            #endif
            break;
        case UART1_SURFACE11_PAGE:
            #if (PAGE_ADD > 10)
            if (system_page.current_page == UART1_SURFACE11_PAGE)
            {
                display_surface11();
            }
            #endif
            break;
        case UART1_SURFACE12_PAGE:
            #if (PAGE_ADD > 11)
            if (system_page.current_page == UART1_SURFACE12_PAGE)
            {
                display_surface12();
            }
            #endif
            break;
        case UART1_SURFACE13_PAGE:
            #if (PAGE_ADD > 12)
            if (system_page.current_page == UART1_SURFACE13_PAGE)
            {
                display_surface13();
            }
            #endif
            break;
        case UART1_SURFACE14_PAGE:
            #if (PAGE_ADD > 13)
            if (system_page.current_page == UART1_SURFACE14_PAGE)
            {
                display_surface14();
            }
            #endif
            break;
        case UART1_SURFACE15_PAGE:
            #if (PAGE_ADD > 14)
            if (system_page.current_page == UART1_SURFACE15_PAGE)
            {
                display_surface15();
            }
            #endif
            break;
        case UART1_SURFACE16_PAGE:
            #if (PAGE_ADD > 15)
            if (system_page.current_page == UART1_SURFACE16_PAGE)
            {
                display_surface16();
            }
            #endif
            break;
        case UART1_SURFACE17_PAGE:
            #if (PAGE_ADD > 16)
            if (system_page.current_page == UART1_SURFACE17_PAGE)
            {
                display_surface17();
            }
            #endif
            break;
        case UART1_SURFACE18_PAGE:
            #if (PAGE_ADD > 17)
            if (system_page.current_page == UART1_SURFACE18_PAGE)
            {
                display_surface18();
            }
            #endif
            break;
        case UART1_SURFACE19_PAGE:
            #if (PAGE_ADD > 18)
            if (system_page.current_page == UART1_SURFACE19_PAGE)
            {
                display_surface19();
            }
            #endif
            break;
        case UART1_SURFACE20_PAGE:
            #if (PAGE_ADD > 19)
            if (system_page.current_page == UART1_SURFACE20_PAGE)
            {
                display_surface20();
            }
            #endif
            break;
        case UART1_SURFACE21_PAGE:
            #if (PAGE_ADD > 20)
            if (system_page.current_page == UART1_SURFACE21_PAGE)
            {
                display_surface21();
            }
            #endif
            break;
        case GD_ALARM:
            //if((check_page(system_page.current_page) > 1) && (check_page(system_page.current_page) != ID_PAGE_VIDEO) && (check_page(system_page.current_page) != ID_PAGE_LOGO) && (check_page(system_page.current_page) < 31))
            if ((system_page.current_page > 0) && (system_page.current_page != 3) && (system_page.current_page != 6) && (system_page.current_page < 0x36))
            {
                display_fault_message();
                if ((system_page.current_page == UART1_MAIN_PAGE) && (DISP_MILE))
                {
                    display_mileage();
                }
                DISP_MILE = 0;
            }
            break;
        case GD_PAGE_CHANGE:
            page_switch();
            break;
        default:
            break;
    }
}
//------------------------------------------------------------------------------------
void display_meter_status (void)
{
    unsigned char i;
    unsigned int temp;
    temp = meter_status[0];
    for (i = 0; i < 16; i++)
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
    temp = meter_status[1];
    #if METER_C50
    for (i = 0; i < 16; i++)
    {
        if (temp & 0x01)
        {
            display_uncolor_icon (page_main_internal_status_green, 18, 1 + i);
        }
        else
        {
            clear_icon (page_main_internal_status_green, 18, 1 + i);
        }
        temp >>= 1;
    }
    temp = meter_status[2];
    for (i = 0; i < 8; i++)
    {
        if (temp & 0x01)
        {
            display_uncolor_icon (page_main_internal_status_green, 34, 1 + i);
        }
        else
        {
            clear_icon (page_main_internal_status_green, 34, 1 + i);
        }
        temp >>= 1;
    }
    temp = meter_status[3];
    for (i = 0; i < 2; i++)
    {
        if ((temp & 0x03) == 0)
        {
            display_uncolor_icon (page_main_internal_status_green, 34, 9 + i);
        }
        else
            if ((temp & 0x03) == 2)
            {
                display_uncolor_icon (page_main_internal_status_red, 34, 9 + i);
            }
            else
            {
                clear_area_block (34, 9 + i, 2, 1);
            }
        temp >>= 2;
    }
    #elif   METER_C61
    for (i = 0; i < 11; i++)
    {
        if (temp & 0x01)
        {
            display_uncolor_icon (page_main_internal_status_green, 18, 1 + i);
        }
        else
        {
            clear_icon (page_main_internal_status_green, 18, 1 + i);
        }
        temp >>= 1;
    }
    temp = meter_status[3];
    for (i = 0; i < 2; i++)
    {
        if ((temp & 0x03) == 0)
        {
            display_uncolor_icon (page_main_internal_status_green, 18, 12 + i);
        }
        else
            if ((temp & 0x03) == 2)
            {
                display_uncolor_icon (page_main_internal_status_red, 18, 12 + i);
            }
            else
            {
                clear_area_block (18, 12 + i, 2, 1);
            }
        temp >>= 2;
    }
    #elif   METER_C52
    for (i = 0; i < 16; i++)
    {
        if (temp & 0x01)
        {
            display_uncolor_icon (page_main_internal_status_green, 18, 1 + i);
        }
        else
        {
            clear_icon (page_main_internal_status_green, 18, 1 + i);
        }
        temp >>= 1;
    }
    temp = meter_status[2];
    for (i = 0; i < 9; i++)
    {
        if (temp & 0x01)
        {
            display_uncolor_icon (page_main_internal_status_green, 34, 1 + i);
        }
        else
        {
            clear_icon (page_main_internal_status_green, 34, 1 + i);
        }
        temp >>= 1;
    }

    #endif
}
void display_moudle_output_status (unsigned char x, unsigned int Lstatus, unsigned int Hstatus)
{
    unsigned char i;
    unsigned long temp;
    temp = Hstatus;
    temp <<= 16;
    temp |= Lstatus;
    #if MODULE_FRONT_B40 || MODULE_REAR_B40 || MODULE_TOP_B40
    #if B40_INPUT_ORDER
    for (i = 0; i < 15; i++)
    {
        if ((temp & 0x03) == 0)
        {
            display_uncolor_icon (page_main_internal_status_green, x, 1 + i);
        }
        else
            if ((temp & 0x03) == 2)
            {
                display_uncolor_icon (page_main_internal_status_red, x, 1 + i);
            }
            else
            {
                clear_area_block (x, 1 + i, 2, 1);
            }
        temp >>= 2;
    }
    #else
    for (i = 0; i < 8; i++)
    {
        if ((temp & 0x03) == 0)
        {
            display_uncolor_icon (page_main_internal_status_green, x, 1 + 2 * i);
        }
        else
            if ((temp & 0x03) == 2)
            {
                display_uncolor_icon (page_main_internal_status_red, x, 1 + 2 * i);
            }
            else
            {
                clear_area_block (x, 1 + 2 * i, 2, 1);
            }
        temp >>= 2;
    }
    for (i = 0; i < 7; i++)
    {
        if ((temp & 0x03) == 0)
        {
            display_uncolor_icon (page_main_internal_status_green, x, 2 + 2 * i);
        }
        else
            if ((temp & 0x03) == 2)
            {
                display_uncolor_icon (page_main_internal_status_red, x, 2 + 2 * i);
            }
            else
            {
                clear_area_block (x, 2 + 2 * i, 2, 1);
            }
        temp >>= 2;
    }
    #endif
    #endif
    #if MODULE_FRONT_B50 || MODULE_REAR_B50 || MODULE_TOP_B50
    for (i = 0; i < 8; i++)
    {
        if ((temp & 0x0f) == 1)
        {
            display_uncolor_icon (page_main_internal_status_green, x, 1 + i * 2);
        }
        else
            if ((temp & 0x0f) == 3)
            {
                display_uncolor_icon (page_main_internal_status_red, x, 1 + i * 2);
            }
            else
                if ((temp & 0x0f) == 4)
                {
                    display_uncolor_icon (page_main_internal_status_yellow, x, 1 + i * 2);
                }
                else
                {
                    clear_area_block (x, 1 + i * 2, 2, 1);
                }
        temp >>= 4;
    }
    #endif
}
void display_moudle_input_status (unsigned int status, unsigned int vestigital)
{
    unsigned char i;
    unsigned int temp;
    temp = status;
    #if MODULE_FRONT_B40 || MODULE_REAR_B40 || MODULE_TOP_B40
    for (i = 0; i < 15; i++)
    {
        if (temp & 0x01)
        {
            display_uncolor_icon (page_main_internal_status_green, 18, 1 + i);
        }
        else
        {
            clear_icon (page_main_internal_status_green, 18, 1 + i);
        }
        temp >>= 1;
    }
    if (vestigital & 0x01)
    {
        display_uncolor_icon (page_main_internal_status_green, 1, 16);
    }
    else
    {
        clear_icon (page_main_internal_status_green, 1, 16);
    }
    if (vestigital & 0x02)
    {
        display_uncolor_icon (page_main_internal_status_green, 18, 16);
    }
    else
    {
        clear_icon (page_main_internal_status_green, 18, 16);
    }
    #endif
    #if MODULE_FRONT_B50 || MODULE_REAR_B50 || MODULE_TOP_B50
    for (i = 0; i < 16; i++)
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
    temp = vestigital;
    for (i = 0; i < 10; i++)
    {
        if (temp & 0x01)
        {
            display_uncolor_icon (page_main_internal_status_green, 18, 1 + i);
        }
        else
        {
            clear_icon (page_main_internal_status_green, 18, 1 + i);
        }
        temp >>= 1;
    }
    #endif
}

void display_unmark (void)
{
    unsigned char i;

    for (i = 0; i < 16; i++)
    {
        display_uncolor_icon (page_main_internal_black, 1 + i * 3, 0);
    }

    for (i = 0; i < 7; i++)
    {
        display_uncolor_icon (page_main_internal_black, 1 + i * 3, 2);
    }
    for (i = 0; i < 4; i++)
    {
        display_uncolor_icon (page_main_internal_black, 37 + i * 3, 2);
    }
	
	  //  display_uncolor_icon (page_main_internal_black,1, 4);
	
    #if HAVE_READY
    display_uncolor_icon (page_main_internal_black, 22, 2);
    display_uncolor_icon (page_main_internal_black, 25, 2);
    #endif
}
void display_mark (void)
{
    unsigned char i;
    unsigned long temp;
    temp = mark_door;

    for (i = 0; i < 16; i++)
    {
        if (temp & 0x80000000)
        {
            clear_icon (page_main_internal_black, 3 * i + 1, 0);
        }
        else
        {
            display_uncolor_icon (page_main_internal_black, 1 + i * 3, 0);
        }
        temp <<= 1;
    }
    if (mark_door & 0x00008000)
    {
        clear_icon (page_main_internal_black, 7, 2);
    }
    else
    {
        display_uncolor_icon (page_main_internal_black, 7, 2);
    }
    if (mark_door & 0x00004000)
    {
        clear_icon (page_main_internal_black, 10, 2);
    }
    else
    {
        display_uncolor_icon (page_main_internal_black, 10, 2);
    }

    if (mark2 & 0x80)
    {
        clear_icon (page_main_internal_black, 13, 2);
    }
    else
    {
        display_uncolor_icon (page_main_internal_black, 13, 2);
    }

    if (mark2 & 0x40)
    {
        clear_icon (page_main_internal_black, 16, 2);
    }
    else
    {
        display_uncolor_icon (page_main_internal_black, 16, 2);
    }
    //安全带未系
    if (mark2 & 0x20)
    {
        clear_icon (page_main_internal_black, 19, 2);
    }
    else
    {
        display_uncolor_icon (page_main_internal_black, 19, 2);
    }

	//胎压
  /*   if (mark2 & 0x10)
    {
        clear_icon (page_main_internal_black, 1, 4);
    }
    else
    {
        display_uncolor_icon (page_main_internal_black, 1, 4);
    }   */

    //纯电模式
   /* switch(mark3 & 0xc0)
	{
		case 0x40:
			display_uncolor_gicon(page_main_internal_mark_ev,40,2);
			break;
		case 0x80:
			display_uncolor_gicon(page_main_internal_mark_hv,40,2);
			break;
		case 0xc0:
			display_uncolor_gicon(page_main_internal_mark_ranyou,40,2);
			break;	
		default:
			clear_area_block(40,2,3,2);
			break;
	}*/
    if (mark2 & 0x10)
    {
        clear_icon (page_main_internal_black, 40, 2);
    }
    else
    {
        display_uncolor_icon (page_main_internal_black, 40, 2);
    }
    //SOC符号片
    if (mark2 & 0x08)
    {
        clear_icon (page_main_internal_black, 43, 2);
    }
    else
    {
        display_uncolor_icon (page_main_internal_black, 43, 2);
    }
    //除霜 安全门
    if (mark2 & 0x04)
    {
        clear_icon (page_main_internal_black, 4, 2);
    }
    else
    {
        display_uncolor_icon (page_main_internal_black, 4, 2);
    }
	//小乌龟 
    if (mark2 & 0x02)
    {
        clear_icon (page_main_internal_black, 1, 2);
    }
    else
    {
        display_uncolor_icon (page_main_internal_black, 1, 2);
    }
    //asr
    if (mark2 & 0x01)
    {
        clear_icon (page_main_internal_black, 46, 2);
    }
    else
    {
        display_uncolor_icon (page_main_internal_black, 46, 2);
    }


    switch (mark_door & 0x000000f0)
    {
        case 0x00000010:
            display_uncolor_gicon (page_main_internal_mark_r, 28, 2);
            break;
        case 0x00000020:
            display_uncolor_gicon (page_main_internal_mark_n, 28, 2);
            break;
        case 0x00000030:
            display_uncolor_gicon (page_main_internal_mark_d, 28, 2);
            break;
       /* case 0x00000040:
            display_uncolor_gicon (page_main_internal_mark_d1, 28, 2);
            break;
        case 0x00000050:
            display_uncolor_gicon (page_main_internal_mark_d2, 28, 2);
            break;
        case 0x00000060:
            display_uncolor_gicon (page_main_internal_mark_d3, 28, 2);
            break;
        case 0x00000070:
            display_uncolor_gicon (page_main_internal_mark_d4, 28, 2);
            break;
        case 0x00000080:
            display_uncolor_gicon (page_main_internal_mark_d5, 28, 2);
            break;
        case 0x00000090:
            display_uncolor_gicon (page_main_internal_mark_d6, 28, 2);
            break;
        case 0x000000a0:
            display_uncolor_gicon (page_main_internal_mark_d7, 28, 2);
            break;
        case 0x000000b0:
            display_uncolor_gicon (page_main_internal_mark_d8, 28, 2);
            break;
        case 0x000000c0:
            display_uncolor_gicon (page_main_internal_mark_d9, 28, 2);
            break;
        case 0x000000d0:
            display_uncolor_gicon (page_main_internal_mark_d10, 28, 2);
            break;
        case 0x000000e0:
            display_uncolor_gicon (page_main_internal_mark_d11, 28, 2);
            break;
        case 0x000000f0:
            display_uncolor_gicon (page_main_internal_mark_d12, 28, 2);
            break;*/
        default:
            clear_area_block (28, 2, 3, 2);
            break;
    }

    if ((mark_door & 0x00003000) == 0x00002000)
    {
        display_uncolor_gicon (page_main_internal_mark_hong, 31, 2);
    }
    else
        if ((mark_door & 0x00003000) == 0x00001000)
        {
            display_uncolor_gicon (page_main_internal_mark_bai, 31, 2);
        }
        else
        {
            clear_area_block (31, 2, 3, 2);
        }

  /*  if ((mark_door & 0x00000c00) == 0x00000800)
    {
        display_uncolor_gicon (page_main_internal_mark_g_tx, 34, 2);
    }
    else
        if ((mark_door & 0x00000c00) == 0x00000400)
        {
            display_uncolor_gicon (page_main_internal_mark_r_tx, 34, 2);
        }
        else
        {
            clear_area_block (34, 2, 3, 2);
        }*/

	//超速报警
	if((mark_door & 0x00000800) == 0x00000800)
		clear_icon (page_main_internal_black, 37, 2);
    else
		display_uncolor_icon (page_main_internal_black, 37, 2);
	
    if ((mark_door & 0x00000300) == 0x00000200)
    {
        display_uncolor_gicon (page_main_internal_mark_y_stop, 34, 2);
    }
    else
        if ((mark_door & 0x00000300) == 0x00000100)
        {
            display_uncolor_gicon (page_main_internal_mark_r_stop, 34, 2);
        }
        else
        {
            clear_area_block (34, 2, 3, 2);
        }

    #if HAVE_READY
    if (mark_door & 0x00000008)
    {
        clear_icon (page_main_internal_black, 22, 2);
        clear_icon (page_main_internal_black, 25, 2);
    }
    else
    {
        display_uncolor_icon (page_main_internal_black, 22, 2);
        display_uncolor_icon (page_main_internal_black, 25, 2);
    }
    #endif
    #if DOOR_CAR
    if (mark_door & 0x00000004)
    {
        display_uncolor_gicon (page_main_internal_door_open_0, 16, 13);
    }
    else
    {
        display_uncolor_gicon (page_main_internal_door_close_0, 16, 13);
    }
    if (mark_door & 0x00000002)
    {
        display_uncolor_gicon (page_main_internal_door_open_1, 31, 11);
    }
    else
    {
        display_uncolor_gicon (page_main_internal_door_close_1, 31, 11);
    }
    if (mark_door & 0x00000001)
    {
        display_uncolor_gicon (page_main_internal_door_open_2, 44, 11);
    }
    else
    {
        display_uncolor_gicon (page_main_internal_door_close_2, 44, 11);
    }
    #endif

}
void diplay_main_data (void)
{

    displays16 (9, 7, total_voltage, 5, 0, GREEN, FULLSPACE, FONT_SMALL); //电池总电压
    displays16 (9, 8, total_current, 5, 0, GREEN, FULLSPACE, FONT_SMALL); //电池总电流
    displays16 (10, 12, motor_temp[0], 3, 0, GREEN, FULLSPACE, FONT_SMALL); //驱动电机温度
    displays16 (10, 13, motor_temp[1], 3, 0, GREEN, FULLSPACE, FONT_SMALL); //驱动电机控制器温度
    displayu16 (26, 7, mono_max_voltage, 2, 2, GREEN, FULLSPACE, FONT_SMALL); //单体最高电压
    displayu16 (26, 8, mono_min_voltage, 2, 2, GREEN, FULLSPACE, FONT_SMALL); //单体最低电压
    displays16 (42, 7, mono_max_temp, 3, 0, GREEN, FULLSPACE, FONT_SMALL); //单体最高温度
    displayu16 (11, 10, system_code, 5, 0, GREEN, FULLSPACE, FONT_SMALL); //系统故障代码
    displays16 (42, 8, mono_min_temp, 3, 0, GREEN, FULLSPACE, FONT_SMALL); //单体最低温度
    displayu16 (25, 9, dianhao, 3, 2, GREEN, FULLSPACE, FONT_SMALL); //百公里电耗
    //displays16 (9, 13, peidianhe_cur, 5, 0, GREEN, FULLSPACE, FONT_SMALL); //配电盒电流
    //displays16 (11, 12, peidianhe_temp, 3, 0, GREEN, FULLSPACE, FONT_SMALL); //配电盒电流
    displayu16 (10, 9, xushi_trip, 4, 0, GREEN, FULLSPACE, FONT_SMALL); //续驶里程


	displays16 (8, 14, shunshi_gonglv, 5, 1, GREEN, FULLSPACE, FONT_SMALL); //瞬时功率
	displays16 (8, 15, shengyu_gonglv, 5, 1, GREEN, FULLSPACE, FONT_SMALL); //剩余功率
	//displayu16 (10, 11, tms_fault_code, 5, 0, GREEN, FULLSPACE, FONT_SMALL); //TMS故障码
}

void display_air (void)
{

    #if AIR_DISP
    unsigned char i;
    unsigned char count_all, count_only, color1, color2;

    if (system_air.air1 < air_alarm)
    {
        color2 = iRED;
        color1 = RED;
    }
    else
    {
        color2 = iGREEN;
        color1 = GREEN;
    }
    count_all = system_air.air1 / 10;
    count_only = system_air.air1 % 10;
    if (system_air.air1 < system_air.last_air1)
    {
        clear_area_block (1, 5, 2, 10);
    }
    for (i = 0; i < count_all; i++)
    {
        display_icon (page_main_internal_air_9, color2, 1, 14 - i);
    }
    if (count_only != 0)
    {
        display_icon (*air_map[count_only - 1], color2, 1, 14 - i);
    }
    system_air.last_air1 = system_air.air1;

    if (system_air.air2 < air_alarm)
    {
        color2 = iRED;
        color1 = RED;
    }
    else
    {
        color2 = iGREEN;
        color1 = GREEN;
    }
    count_all = system_air.air2 / 10;
    count_only = system_air.air2 % 10;
    if (system_air.air2 < system_air.last_air2)
    {
        clear_area_block (47, 5, 2, 10);
    }
    for (i = 0; i < count_all; i++)
    {
        display_icon (page_main_internal_air_9, color2, 47, 14 - i);
    }
    if (count_only != 0)
    {
        display_icon (*air_map[count_only - 1], color2, 47, 14 - i);
    }
    system_air.last_air2 = system_air.air2;
    #endif
}

void display_soc (void)
{
    #if BIG_SOC
    if (system_air.last_soc != system_air.soc)
    {
        display_uncolor_gicon (*soc_map[system_air.soc], 9, 4);
        system_air.last_soc = system_air.soc;
    }
    #endif
    #if SMALL_SOC
    unsigned char i;
    unsigned char count_all, count_only, color1, color2;
    if (system_air.soc < 20)
    {
        color2 = iRED;
        color1 = RED;
    }
    else
    {
        color2 = iGREEN;
        color1 = GREEN;
    }
    count_all = system_air.soc / 8;
    count_only = system_air.soc % 8;
    if (system_air.soc < system_air.last_soc)
    {
        clear_area_block (19, 16, 13, 1);
    }
    for (i = 0; i < count_all; i++)
    {
        display_icon (page_main_internal_soc_7, color2, 19 + i, 16);
    }
    if (count_only != 0)
    {
        display_icon (*soc_map[count_only - 1], color2, 19 + i, 16);
    }
    system_air.last_soc = system_air.soc;
    displayu8 (32, 16, system_air.soc, 3, 0, color1, FULLSPACE, FONT_SMALL);
    #endif
    #if DULI_SOC
    unsigned char color;
    if (system_air.soc < 20)
    {
        color = RED;
    }
    else
    {
        color = GREEN;
    }
    system_air.last_soc = system_air.soc;
    displayu8 (32, 16, system_air.soc, 3, 0, color1, FULLSPACE, FONT_SMALL);
    #endif
}
void display_system_time (void)
{
    unsigned char BCD[10], i;

    BCD[0] = (system_time.year >> 4) & 0x0f;
    BCD[1] = system_time.year & 0x0f;
    BCD[2] = (system_time.month >> 4) & 0x0f;
    BCD[3] = system_time.month & 0x0f;
    BCD[4] = (system_time.day >> 4) & 0x0f;
    BCD[5] = system_time.day & 0x0f;
    BCD[6] = (system_time.hour >> 4) & 0x0f;
    BCD[7] = system_time.hour & 0x0f;
    BCD[8] = (system_time.minute >> 4) & 0x0f;
    BCD[9] = system_time.minute & 0x0f;
    for (i = 0; i < 10; i++)
    {
        if (BCD[i] > 9)
        {
            BCD[i] = 0;
        }
    }

    display_uncolor_icon (*number_map[BCD[6]], 9, 16);
    display_uncolor_icon (*number_map[BCD[7]], 10, 16);


    display_uncolor_icon (*number_map[BCD[8]], 12, 16);
    display_uncolor_icon (*number_map[BCD[9]], 13, 16);

    display_uncolor_icon (*number_map[BCD[0]], 5, 17);
    display_uncolor_icon (*number_map[BCD[1]], 6, 17);

    display_uncolor_icon (*number_map[BCD[2]], 8, 17);
    display_uncolor_icon (*number_map[BCD[3]], 9, 17);

    display_uncolor_icon (*number_map[BCD[4]], 11, 17);
    display_uncolor_icon (*number_map[BCD[5]], 12, 17);
}
void display_set_time (void)
{
    unsigned char BCD[10], i;
    BCD[0] = (system_time.year >> 4) & 0x0f;
    BCD[1] = system_time.year & 0x0f;
    BCD[2] = (system_time.month >> 4) & 0x0f;
    BCD[3] = system_time.month & 0x0f;
    BCD[4] = (system_time.day >> 4) & 0x0f;
    BCD[5] = system_time.day & 0x0f;
    BCD[6] = (system_time.hour >> 4) & 0x0f;
    BCD[7] = system_time.hour & 0x0f;
    BCD[8] = (system_time.minute >> 4) & 0x0f;
    BCD[9] = system_time.minute & 0x0f;
    for (i = 0; i < 10; i++)
    {
        if (BCD[i] > 9)
        {
            BCD[i] = 0;
        }
    }
    display_uncolor_icon (*number_map[BCD[6]], 19, 2);
    display_uncolor_icon (*number_map[BCD[7]], 20, 2);
    display_uncolor_icon (*number_map[BCD[8]], 22, 2);
    display_uncolor_icon (*number_map[BCD[9]], 23, 2);
    display_uncolor_icon (*number_map[BCD[0]], 21, 4);
    display_uncolor_icon (*number_map[BCD[1]], 22, 4);
    display_uncolor_icon (*number_map[BCD[2]], 24, 4);
    display_uncolor_icon (*number_map[BCD[3]], 25, 4);
    display_uncolor_icon (*number_map[BCD[4]], 27, 4);
    display_uncolor_icon (*number_map[BCD[5]], 28, 4);
}

void display_mileage (void)
{
    unsigned char i, temp = 0;
    displayu16 (42, 16, system_meilage.trip, 4, 1, WHITE, FULLSPACE, FONT_SMALL);

    for (i = 0; i < 7; i++)
    {
        if (system_meilage.odo[i] > 0)
        {
            temp = i;
        }
    }
    for (i = 0; i <= temp; i++)
    {
        display_uncolor_icon (*number_map[system_meilage.odo[i]], 46 - i, 17);
    }
    for (; i < 7; i++)
    {
        clear_area_block (46 - i, 17, 1, 1);
    }
}
void display_fault_message (void)
{
    static unsigned char yici = 1;
    if (system_page.current_page != 0x2e)
    {
        if (system_alarm.index == 0xff)
        {
            #if ALARM_SDDD
            if (yici)
            {
                clear_alarm_area();
                display_uncolor_icon (page_main_internal_shidaidiandong, 7, 18);
                yici = 0;
            }
            #else
            clear_alarm_area();
            #endif
            system_alarm.last_index = 0xff;
        }
        else
        {
            if ((system_alarm.index != system_alarm.last_index) || (system_alarm.last_number != system_alarm.number))
            {
                yici = 1;
                clear_area_block (6, 18, 44, 2);
                if ((system_alarm.index < 0x63) || ((system_alarm.index > 0x63) && (system_alarm.index < 0x7c))\
                        || ((system_alarm.index > 0x82) && (system_alarm.index < 0xa0)))//|| (system_alarm.index > 0xA9))
                {
                    display_uncolor_icon (page_main_internal_fault_flag_red, 3, 18);
                    display_uncolor_gicon (*fault_map[system_alarm.index], 7, 18);
                    system_alarm.last_index = system_alarm.index;
                }
                #if ALARM_NUM
                else if ((system_alarm.index > 194) && (system_alarm.index < 200))
                {
                 /*   display_uncolor_icon (page_main_internal_fault_flag_red, 3, 18);
                    display_uncolor_gicon (*alarm_pos[system_alarm.number], 7, 18);
                    display_uncolor_gicon (*fault_map[system_alarm.index], (7 + alarm_pos[system_alarm.number]->width), 18);
                    system_alarm.last_index = system_alarm.index; */

					unsigned int num = system_alarm.number & 0x07;				
					display_uncolor_icon(page_main_internal_fault_flag_red,3,18);	
					if(num > 0)
					{
						display_uncolor_gicon(*alarm_pos[num - 1],7,18);
						display_uncolor_gicon(*fault_map[system_alarm.index],(7 + alarm_pos[num - 1]->width),18);	
					}
					else
						display_uncolor_gicon(*fault_map[system_alarm.index],7,18); 				 
                }  
				
				else if((system_alarm.index > 0xb8) && (system_alarm.index < 0xc3))
                {
                    display_uncolor_icon (page_main_internal_fault_flag_red, 3, 18);
					display_uncolor_gicon (*fault_map[system_alarm.index], 7, 18);
					if(system_alarm.number > 0)
                    	displayu8(7 + fault_map[system_alarm.index]->width,18,system_alarm.number,3,0,WHITE,FULLZERO,FONT_MEDIUM);
                    system_alarm.last_index = system_alarm.index;
                }
               /* else if (system_alarm.index == 0x63)
                {
                    display_uncolor_icon (page_main_internal_fault_flag_red, 3, 18);
                    displayu8 (7, 18, system_alarm.number, 2, 0, WHITE, FULLSPACE, FONT_MEDIUM);
                    display_uncolor_gicon (*fault_map[system_alarm.index], 9, 18);
                    system_alarm.last_index = system_alarm.index;
                }*/
                system_alarm.last_number = system_alarm.number;
                #endif
            }
        }
    }
}
//------------------------------------------------------------------------------------
void display_init (void)
{
    unsigned char i,j;
    system_page.last_page = ID_PAGE_START;
    system_page.current_page = 0x52;
    buzzer = 0;
    mark_door = 0;
    mark2 = 0;
	mark3 = 0;
    menu = 0;
    page_xuanze = 0;
    para_cmd = 0;
    speed_scale = 0;
    baimi_pulse = 0;
    scale_factor = 100;
    system_bright = 0;
    system_video = 0;//tv1-4
    system_air.air1 = 0;
    system_air.air2 = 0;
    system_air.soc = 0;
    system_meilage.trip = 0;
    system_time.day = 0;
    system_time.hour = 0;
    system_time.minute = 0;
    system_time.year = 0;
    system_time.month = 0;
    for (i = 0; i < 7; i++)
    {
        system_meilage.odo[i] = 0;
    }

    system_alarm.index = 0xff;
    system_alarm.number = 0;
    system_alarm.last_number = 0;
    system_alarm.last_index = 0xff;
    system_air.last_air1 = 0;
    system_air.last_air2 = 0;
    system_air.last_soc = 0;

    system_b_password.blink = 0xff;
    for (i = 0; i < 4; i++)
    {
        system_b_password.para[i] = 0;
    }
    system_b_odo_char.blink = 0xff;
    for (i = 0; i < 44; i++)
    {
        system_b_odo_char.para[i] = 0;
    }
    system_b_set.blink = 0xff;
    for (i = 0; i < 11; i++)
    {
        system_b_set.para[i] = 0;
    }

    uart_cmd = 0;
    dandu_disp = 0;

    meter_status[0] = 0;
    meter_status[1] = 0;
    meter_status[2] = 0;
    meter_status[3] = 0x55;
    meter_para_A2 = 0;
    meter_para_A3 = 0;
    meter_para_A4 = 0;
	meter_para_K = 0;
    meter_para_A5 = 0;
    meter_para_A13 = 0;
    meter_para_A14 = 0;
    meter_para_A15 = 0;
    #if MODULE_FRONT_B40
    front_status[0] = 0x5555;
    front_status[1] = 0x5555;
    front_status[2] = 0;
    front_status[3] = 0;
    front_para_A25 = 0;
    front_para_A40 = 0;
    front_para_A26 = 0;
    #endif
    #if MODULE_REAR_B40
    rear_status[0] = 0x5555;
    rear_status[1] = 0x5555;
    rear_status[2] = 0;
    rear_status[3] = 0;
    rear_para_A25 = 0;
    rear_para_A40 = 0;
    rear_para_A26 = 0;
    #endif
    #if MODULE_TOP_B40
    top_status[0] = 0x5555;
    top_status[1] = 0x5555;
    top_status[2] = 0;
    top_status[3] = 0;
    top_para_A25 = 0;
    top_para_A40 = 0;
    top_para_A26 = 0;
    #endif
    #if MODULE_FRONT_B50
    front_status[0] = 0;
    front_status[1] = 0;
    for (i = 0; i < 7; i++)
    {
        front_para[i] = 0;
    }
    for (i = 0; i < 6; i++)
    {
        front_out_status[i] = 0;
    }
    #endif
    #if MODULE_REAR_B50
    rear_status[0] = 0;
    rear_status[1] = 0;
    for (i = 0; i < 7; i++)
    {
        rear_para[i] = 0;
    }
    for (i = 0; i < 6; i++)
    {
        rear_out_status[i] = 0;
    }
    #endif
    #if MODULE_TOP_B50
    top_status[0] = 0;
    top_status[1] = 0;
    for (i = 0; i < 7; i++)
    {
        top_para[i] = 0;
    }
    for (i = 0; i < 6; i++)
    {
        top_out_status[i] = 0;
    }
    #endif
    air1_factor = 0;
    air2_factor = 0;
    speed_alarm = 0;
    air_alarm = 0;
    oil_alarm = 0;
    fuel_alarm = 0;
    for (i = 0; i < 5; i++)
    {
        vedio_enable[i] = 0;
    }
    wiper_sec = 3;
    meter_input = 0;
    meter_output = 0;

    //-----------------------------------------------------------------
    li_battery_level = 0;
    system_status = 0;
    xudianchi_voltage = 0;
    system_code = 0;
    xushi_trip = 0;
    motor_zhuansu = 0;
    total_voltage = 0;
    total_current = 0;

    dongli_input_voltage = 0;
    dongli_input_current = 0;
    siji_status = 0;
    onoff_status = 0;
    bus_life = 0;
    bus_mode = 0;
    for (i = 0; i < 6; i++)
    {
        bus_yuliu[i] = 0;
    }
    youmen_taban = 0;
    zhidong_taban = 0;
	dianchi_soc = 0;
    for (i = 0; i < 7; i++)
    {
        bus_version[i] = 0;
    }
    for (i = 0; i < 2; i++)
    {
        motor_temp[i] = 0;
    }
    motor_zhuanju = 0;
 

    dcdc_output_voltage = 0;
    dcdc_output_current = 0;
    dcdc_input_voltage = 0;
    dcdc_temp = 0;
    dcdc_fault = 0;
    dcac_fault = 0;
    dcac_w_current = 0;
    dcac_v_current = 0;
    dcac_u_current = 0;
    dcac_temp = 0;
    motor_zhju = 0;
    riso_zheng = 0;
    riso_fu = 0;
    riso_life = 0;
    riso_fault = 0;
    riso_loudian = 0;

    for (i = 0; i < 8; i++)
    {
        tiaoshi_canshu[i] = 0;
    }

    chongdian_current = 0;
    fangdian_current = 0;
    mono_max_voltage = 0;
    mono_min_voltage = 0;
    mono_pingjun_voltage = 0;
    mono_max_temp = 0;
    mono_min_temp = 0;
    battery_riso_zheng = 0;
    battery_riso_fu = 0;
    for (i = 0; i < 5; i++)
    {
        battery_status[i] = 0;
    }

    vin_status = 0;
    battery_fault_suliang = 0;
    mono_binglian_shuliang = 0;
    mono_tanzhen_shuliang = 0;
    for (i = 0; i < 4; i++)
    {
        chongdian_temp[i] = 0;
    }
    eding_rongliang = 0;
    eding_voltage = 0;
    mono_chuanlian_shuliang = 0;

    mono_min_temp = 0;
    mono_max_t_xiang = 0;
    mono_max_t_jie = 0;
    mono_min_t_xiang = 0;
    mono_min_t_jie = 0;
    mono_max_v_xiang = 0;
    mono_max_v_jie = 0;
    mono_min_v_xiang = 0;
    mono_min_v_jie = 0;
    battery_leixing = 0;
    battery_lengque = 0;
    for (i = 0; i < 4; i++)
    {
        battery_yuliu[i] = 0;
    }

    for (i = 0; i < 10; i++)
    {
        dianchi_bianhao[i] = 0;
        dianchi_mono_voltage[i] = 0;
        dianchi_mono_temp[i] = 0;
        dianchi_xianghao[i] = 0;
    }

    air_fuhe = 0;
    air_set_temp = 0;
    air_wai_temp = 0;
    air_nei_temp = 0;
    air_current = 0;
    air_status = 0;
    air_life = 0;

    miehuoqi_xiang = 0;
    miehuoqi_yujing = 0;
    miehuoqi_fault = 0;
    miehuoqi_qingqiu = 0;
    for (i = 0; i < 5; i++)
    {
        yanwu_status[i] = 0;
    }
    yanwu_life = 0;

    dianchi_fenxian = 0;

    yzt_status = 0;

    motor_con_cur = 0;
    qiben1 = 0;
    qiben2 = 0;
    qiben3 = 0;
    qiben4 = 0;
    qiben5 = 0;


    //peidianhe_cur = 0;
   // peidianhe_temp = 0;
   // peidianhe_vol = 0;

    for (i = 0; i < 2; i++)
    {
        youbeng_life[i] = 0;
        youbeng_status[i] = 0;
        youbeng_zhuansu[i] = 0;
        youbeng_cur[i] = 0;
        youbeng_temp[i] = 0;
    }
    for (i = 0; i < 2; i++)
    {
        youbeng[i] = 0;
    }
    guzhangdaima = 0;
    diduan_vol = 0;
    yingjianbanben = 0;
    ruanjianbanben = 0;
    gaoduan_vol = 0;
    dianji_temp = 0;

    for (i = 0; i < 6; i++)
		for (j = 0; j < 8; j++)
			surface_data[i][j] = 0;
	runhua1 = 0;
	//peidianhe_status = 0;
	yugua_time = 0;
	shunshi_gonglv = 0;
	shengyu_gonglv = 0;
	elec_control_code = 0;
	tms_fault_code = 0;
}
