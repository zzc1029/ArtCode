#ifndef _DISP_CONFIG_H
#define _DISP_CONFIG_H

#define meter_para_T     		1


#define USED     				1
#define UNUSED    				0

#define PAGE_ADD				19
//-------------------仪表类型选择----------------------------
#define	METER_C50				UNUSED
#define	METER_C61				UNUSED
#define METER_C52               USED
//-------------------模块类型选择----------------------------
#define	MODULE_FRONT_B40		USED
#define	MODULE_REAR_B40		    USED
#define	MODULE_TOP_B40		    UNUSED

#define	B40_INPUT_ORDER			UNUSED

#define	MODULE_FRONT_B50		UNUSED
#define	MODULE_REAR_B50			UNUSED
#define	MODULE_TOP_B50			UNUSED
//-------------------气压soc 车门文字选择-----------------------------------
#define	ALARM_NUM				USED
#define	AIR_DISP				UNUSED
#define	DOOR_CAR				USED
#define HAVE_READY				USED
#define	BIG_SOC					UNUSED
#define	SMALL_SOC				USED
#define	DULI_SOC				UNUSED
#define ALARM_SDDD              UNUSED
//--------------------菜单----------------------------------------------
#define	CURSOR_NUM				6  //右边的菜单数量
#define	CURSOR_LEFT_NUM			7  //左边的菜单数量
#define	CURSOR_R_X				29
#define	CURSOR_R_Y				9
#define	CURSOR_L_X				9
#define	CURSOR_L_Y				16//((CURSOR_R_Y + 1 * CURSOR_LEFT_NUM)) 	//18//(2*num+ry-2?)
//------------------------------------------------------------------
#define GREEN 					0x02
#define RED 					0x01
#define YELLOW					0x00
#define WHITE					0x03

#define iGREEN 					0x02
#define	iBLACK					0x01
#define	iRED 					0x03
#define iYELLOW					0x04
#define iBLUE					0x05
#define iCYAN					0x06
#define iPURPLE					0x07
#define iWHITE					0x08
//-----------------------------------------------------------------
#define	PAGE_TOTAL				(8 + PAGE_ADD + MODULE_FRONT_B40 + MODULE_REAR_B40 + MODULE_TOP_B40\
								+ MODULE_FRONT_B50*2 + MODULE_REAR_B50*2 + MODULE_TOP_B50*2)
#endif
