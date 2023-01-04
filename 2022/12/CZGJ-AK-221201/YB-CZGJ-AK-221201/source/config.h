/*
 * config.h
 *
 *  Created on: 2021-7-27
 *      Author: ART
 */

#ifndef _CONFIG_H
#define _CONFIG_H





//定义符号片取模块输出反馈状态
#include "Artpatch.h"

//该订单仪表软件版本，以后软件每次更新就累加1，在仪表诊断信息里面显示
#define  SOFT_VERSION	1

/*
 修改程序中的总里程为指定小计里程与总里程
 步骤:
 1.ODONUM参数版本增加即可 
 2.设置SETTRIP与SETODO为参数即可
 注意事项:由于现有硬件版本T123不断电，如要把总里程设为零，修改ODONUM参数后，烧录程序
 总里程不为零，断电即可。
*/

#define ODONUM    0
#define SETTRIP   0
#define SETODO    0

/*
设置修改参数，注意固定参数的修改,方法如上
*/
#define PARANUM    0


//#define  BACKLIGHT_SW_FEEDBACK         B40_FRONT_FEEDBACK(A13)
#define  LED_HBEAM_SW_FEEDBACK         B40_FRONT_FEEDBACK(A5)
#define  LED_LBEAM_SW_FEEDBACK         B40_FRONT_FEEDBACK(A6) 
#define  LED_FFOG_SW_FEEDBACK          B40_FRONT_FEEDBACK(A13) 
#define  LED_RFOG_SW_FEEDBACK          B40_TOP_FEEDBACK(A8) 
#define  BREAK_SW_FEEDBACK             B40_TOP_FEEDBACK(A42) 
#define  LED_BACKGROUND_FEEDBACK       B40_FRONT_FEEDBACK(A42)

#define USED      1
#define UNUSED    0

#define ON   1
#define OFF  0

#define HighEnable	0   //高有效
#define LowEnable	1   //低有效

#define PWMEable    1
//电压电阻标识
#define VOLT  1
#define RES   2


#define C16C17CAN  UNUSED

/***模拟传感器端口上拉电阻以及传感器类型选择******/
// A2上拉电阻
#define A2_PULL     255
// A3上拉电阻
#define A3_PULL     1000
// A4上拉电阻
#define A4_PULL     1000
// A13上拉电阻
#define A13_PULL    510
// A14上拉电阻
#define A14_PULL    510


#define A2_TYE     RES
#define A3_TYE     RES
#define A4_TYE     RES
#define A13_TYE    VOLT
#define A14_TYE    VOLT
/**********************/


//故障界面故障码轮询显示，时间是3秒
#define GUZHAGN_LOOP USED
//最大故障码做到256个  按照最大的来
#define MAX_MA      100 


/*雨刮档位设置*****************/
#define WIPER_INT_SW	(PTB7) //间歇
#define WIPER_LO_SW     (PTB8) //低速档
#define WIPER_HI_SW     (PTB2) //高速档
#define WIPER_MI_SW		(PTB1) //喷水开关
//雨刷功能打开关闭
#define SUPPORT_WIPER 	USED	
/*雨刮档位设置End*****************/

//安凯新增在ON档档位关闭时，根据协议显示手刹图标5秒钟
#define ANKAI_ADD_SCREEC_FOR_PARK      USED
#define NO_PARK                        Ankai_Add_190703.bit.b5
//油门
#define YOUMEN_ENABLE  	               TestBitTrue(_0CFF0B4A[1],3)
//EP误操作
#define EP_ENABLE                      TestBitTrue(_18FF0152[1],0)

// 关门三声提示蜂鸣器
#define CLOSE_DOOR_WANT_VOICE          UNUSED

/*  按键开启 仪表自动测试符号片亮灭   指针转动一圈 */
#define SELF_TEST_BY_METRE             USED                       //仪表自测模式
#define _8s_100ms                      80                     //80百毫秒

//仪表参数加入校验
#define PARACHECKEN UNUSED

//时钟输出使能
#define SCLKOUTEN  UNUSED
//feed dog enable
#define WATCHDOGEN  USED

//显示任务
#define MAXDISMENU 25

/***调试与T123通讯使用CAN*******/
#define T123_USED_BCAN  USED
#define T123_USED_TCAN  USED
#define T123_USED_PCAN  USED
#define T123_USED_DCAN  USED

// 360环视
#define TV_360  UNUSED

//计算车速方式
#define CALULATE_SPEED_ENABLE  UNUSED
//2 是否启动发送车速报文任务
#define SENDSPEED_ENABLE	  USED  

//摄像头设置
#define TV1_REVERSE_SW       UNUSED//(REVERSE_GEAR_SW && ChangeVideoAv1Enable && (VIDEO_AV_GRAR))
#define TV2_REAR_DOOR_SW     UNUSED//(UNUSED && ChangeVideoAv4Enable && (VIDEO_AV_ELSE))
#define TV3_FRONT_DOOR_SW    UNUSED//(LED_FRONT_DOOR_SW && ChangeVideoAv3Enable && (VIDEO_AV_FRO))
#define TV4_MIDDLE_DOOR_SW   UNUSED//(LED_MIDDLE_DOOR_SW && ChangeVideoAv2Enable && (VIDEO_AV_MID))



//是否有模块
#define  Has_Fmode       ON
#define  Has_Rmode       OFF
#define  Has_Tmode       ON
#define  Has_Amode       OFF

//新增PWM宏定义




#define ANKAI_ABS		UNUSED

//3 模块所有输出均PWM
#define MODLE_ALL_PWM          UNUSED

/**********气压传感器参数开始*************************/

#define USEDAIR               UNUSED

#define BAR_12                 USED     //2 12BAR
#define BAR_10                 UNUSED   //2 10BAR
#define AIR_TYPE               VOLT      //2 气压罐信号来源定义枚举
#define Bar1Source             meter.MeterA13  //2 气压一来源
#define Bar2Source             meter.MeterA14 //2 气压二来源
#define BCM_SENSOR_VOLT 	   10 	//2 模块传感器单位10mv时定义10，100mv时定义1

/***********气压传感器参数结束***********************/

/********燃油传感器开始**********/

//燃油资源
#define USEDFUEL      UNUSED
#define FUELSOURCE    meter.MeterA2
// 燃油阻值0 - 180    0 - 100(百分比)
#define FUELFULL_180  0
// 燃油阻值110 - 6    0 - 100(百分比)   
#define FUELFULL_6    1
//燃油传感器类型选择
#define FUELTYPE      FUELFULL_180   

/********燃油传感器结束**********/

/*********燃油加热器舱温定义**********************/
//打开宏
#define USEDRANYOUTEMP    UNUSED
//温度资源
#define RANYOUTEMPSOUTCE  meter.MeterA3

/******************************/


/*********蓄电池舱温定义**********************/
//打开宏
#define USEDVBATTEMP    USED
//温度资源
#define VBATTEMPSOUTCE bcm_senor2_f //meter.MeterA4

/******************************/


//灯光
#define  LED_LEFT_SW            LEFT_LED_SW
#define  LED_RIGHT_SW           RIGHT_LED_SW
#define  LED_HBEAM_SW           LED_HBEAM_SW_FEEDBACK
#define  LED_LBEAM_SW           LED_LBEAM_SW_FEEDBACK
#define  LED_FFOG_SW            LED_FFOG_SW_FEEDBACK
#define  LED_RFOG_SW            LED_RFOG_SW_FEEDBACK
//门状态指示
#define  LED_FRONT_DOOR_SW      FRONT_DOOR_SW
#define  LED_MIDDLE_DOOR_SW     MID_DOOR_SW
#define  LED_ENG_DOOR_SW        ENG_DOOR_SW
//其他配置项
#define  LED_FILTER_SW          UNUSED
#define  LED_DRYER_SW           UNUSED                                            
#define  LED_PREHEAT_SW         UNUSED                                            
#define  LED_STOP_SW            UNUSED                                             
#define  LED_SERVICE_SW         UNUSED                                            
#define  LED_ENG_FAULT_SW       UNUSED                                            
#define  LED_ENG_TEMP_HOT_SW    UNUSED
#define  LED_FUEL_LOW_SW        UNUSED
#define  LED_GENERATOR1_SW      UNUSED//充电指示
#define  LED_GENERATOR2_SW      UNUSED//充电指示
#define  LED_GENERATOR_SW       UNUSED//充电指示
//一般情况下无需配置的项目
#define  LED_ABS_SW             ABS_SW
#define  LED_BATTERY_LOW_SW     ((Vbat < 200)||(Vbat > 320))       
#define  LED_OIL_LOW_SW         UNUSED                                        
#define  LED_POWER_SW           SYSTEM_POW                                       
#define  LED_AIR_LOW_SW         DEFINE_TIP_AIR_LOW                                
#define  LED_PARK_SW            PARK_SW
/*******************************************************/
#define  ALL_DOOR			(LED_FRONT_DOOR_SW || LED_MIDDLE_DOOR_SW)



/*********仪表设置参数****************/
#define PULSE                    1450  //百米脉冲(C3输出)
#define SUBI  	                 1800   //速比

#define COEF                     100  //比例系数

#define AIR_ALARM                55
#define OIL_ALARM                105
#define SPEED_ALARM              69
#define VIDEO_GEAR               UNUSED        //1 AV1 2 3 4
#define VIDEO_MID_DOOR           UNUSED  
#define VIDEO_FRO_DOOR           UNUSED
#define VIDEO_ELSE               UNUSED
#define RANYOU_ALARM             15
#define AIR1_COEF                100
#define AIR2_COEF                100
#define FUEL_COEF	             100 //
#define RAIN_TIME                40

//设置界面开关
#define ChangeLiChengEnable      ON  //设置里程
#define ChangeSubiEnable         ON  //设置速比
#define ChangePulseEnable        ON  //设置百米脉冲
#define ChangeCoefEnable         ON  //设置显示速度的倍数

#define ChangeTimeEnable         ON   //设置时间
#define ChangeBLEnable           ON   //设置背光
#define ChangeBuzzEnable         ON   //设置蜂鸣器

/*20180301 TONY Set something*/
#define ChangeAir1CoefEnable     ON
#define ChangeAir2CoefEnable     ON
#define ChangeSpeedAlarmEnable   ON
#define ChangeAirAlarmEnable     ON
#define ChangeOilAlarmEnable     ON
#define ChangeRanyouEnable       ON
#define ChangeVideoAv1Enable     ON
#define ChangeVideoAv2Enable     ON
#define ChangeVideoAv3Enable     ON
#define ChangeVideoAv4Enable     ON   

/********************************安凯订单宏使用************************************/
#define ChangeRainEnable         ON 
#define ChangeRainTimeEnable     ON
//瞬时电耗宏定义  
#define ChangeFuelCoefEnable     ON

/******************指针数据源配置******************************/
//     2    3         指针位置
// 0            1
// 4            5
#define Rotate_Speed_SOURCE      (&eng_speed)   //上图编号0      
#define Vehicle_Speed_SOURCE     (&veh_speed_display)      //上图编号1

#define Motor2_SOURCE            (&veh_bar1)// 2
#define Motor3_SOURCE            (&veh_bar2)// 3

#define Motor4_SOURCE            (&veh_soc) // 4
#define Motor5_SOURCE            (&Vbat)  //  5
/**********************************************************************/

#define LevelSet_C20_IN          HighEnable //同C52的E2
#define LevelSet_A07_IN          HighEnable
#define LevelSet_A08_IN          HighEnable
#define LevelSet_A09_IN          HighEnable
#define LevelSet_A10_IN          HighEnable
#define LevelSet_A17_IN          HighEnable
#define LevelSet_A18_IN          HighEnable
#define LevelSet_A19_IN          HighEnable


#define PWM_F_P05  PWMEable
#define PWM_F_P13  PWMEable
#define PWM_F_P06  PWMEable
#define PWM_F_P42  PWMEable

#define PWM_F_P04  PWMEable

#define PWM_F_P13  PWMEable
#define PWM_F_P06  PWMEable
#define PWM_F_P14  PWMEable
#define PWM_F_P07  PWMEable

#define PWM_T_P04  PWMEable
#define PWM_T_P06  PWMEable
#define PWM_T_P14  PWMEable

#define PWM_T_P13  PWMEable
#define PWM_T_P10  PWMEable
#define PWM_T_P07  PWMEable




//#define LevelSet_D01_IN          HighEnable
//#define LevelSet_D03_IN          HighEnable
//#define LevelSet_D04_IN          HighEnable
//#define LevelSet_D05_IN          HighEnable
//#define LevelSet_D06_IN          HighEnable
//#define LevelSet_D07_IN          HighEnable
//#define LevelSet_D08_IN          HighEnable
//#define LevelSet_D09_IN          HighEnable
//#define LevelSet_D11_IN          HighEnable
//#define LevelSet_D12_IN          HighEnable



//前模块
#define LevelSet_F_A17_IN  HighEnable
//#define LevelSet_F_A22_IN  HighEnable
#define LevelSet_F_A39_IN  HighEnable

//后模块
#define LevelSet_R_A17_IN  HighEnable
//#define LevelSet_R_A22_IN  HighEnable
#define LevelSet_R_A39_IN  HighEnable

//顶模块
#define LevelSet_T_A17_IN  HighEnable
//#define LevelSet_T_A22_IN  HighEnable
#define LevelSet_T_A39_IN  HighEnable


//新增模块
#define LevelSet_A_A17_IN  HighEnable
//#define LevelSet_T_A20_IN  HighEnable
#define LevelSet_A_A39_IN  HighEnable

/************************ SWITCH ***************************/
#define  KEY_ON				    PTE2				     //On档
#define  KEY_ACC			    PTA7                    //ACC档
#define  KEY_ST				    UNUSED 			         //start档
#define  KEY_EMG			    (PTA8)                  //危急报警开关
#define  KEY_CHARGE             PTA9                   //充电唤醒开关
#define  KEY_POWER			    PTA10//总电源开关
#define  SYSTEM_POW        	    (KEY_ON||KEY_ACC)     //系统电源开关
#define  WAKE_UP_SW			    (KEY_ON||KEY_ACC||KEY_ST||KEY_EMG||KEY_POWER) //可唤醒开关
//灯光
#define  RIGHT_LED_SW           PTD9  //右转向灯
#define  LEFT_LED_SW            PTD8  //左转向灯
#define  BACKLIGHT_SW           PTB6  //小灯开关
#define  HBEAM_SW			    PTB3  //远光
#define  LBEAM_SW			    PTB12 //近光
#define  FFOG_SW				PTB5  //前雾灯
#define  RFOG_SW				PTB11  //后雾灯

//刹车
#define BREAK_CONTION           TestBitTrue(Control_information_data6,3)
#define BREAK_SW                F_SW_P17
#define ELEC_BREAK              (F_SW_P39 || TestBitTrue(Control_information_data7,7))	                                //刹车开关
#define BREAK_ALL               (BREAK_SW||BREAK_CONTION||ESC_BREAK)
#define PARK_SW				    (F_SW_P32|| TestBitTrue(CanData[ID(0x0CFF0A4A)][6],7))  //手刹
//档位

#define D_SW   				    TestBitTrue(Control_information_data6,5)
#define NULL_SW                 TestBitTrue(Control_information_data6,4)
#define REVERSE_GEAR_SW         (TestBitTrue(Control_information_data6,6))

//门状态)
#define ENG_DOOR_SW			    UNUSED
#define FRONT_DOOR_SW           T_SW_P17
#define MID_DOOR_SW			    UNUSED
#define FRONT_DOOR_OPEN_SW      PTD6
#define FRONT_DOOR_CLOSE_SW     PTD1
#define MID_DOOR_OPEN_SW        UNUSED
#define MID_DOOR_CLOSE_SW       UNUSED
//前门防夹开关
#define FRONT_DOOR_FANGJIA_SW   UNUSED 
//中门防夹开关
#define MID_DOOR_FANGJIA_SW     UNUSED

//应急阀
#define EMERGENCY_FRONT_INSIDE_SW 		UNUSED
#define EMERGENCY_FRONT_OUTSIDE_SW 		UNUSED
#define EMERGENCY_MIDDLE_INSIDE_SW 		UNUSED
#define EMERGENCY_MIDDLE_OUTSIDE_SW 	UNUSED

#define EMERGENCY_DRIVER_SW				UNUSED


#define EMERGENCY_INSIDE_SW 	    	T_SW_P21//车内应急阀
#define EMERGENCY_OUTSIDE_SW 	    	T_SW_P22  //车外应急阀
#define EMERGENCY_ALL  					(EMERGENCY_INSIDE_SW||EMERGENCY_OUTSIDE_SW||EMERGENCY_DRIVER_SW)


//常用开关
#define PASSAGE_GET_OUT_SW      (F_SW_P33)//下客门铃
#define WATER_SW			    (T_SW_P32)//水位低
#define WATER_RANYOU_SW			(UNUSED)//水位2低
#define WATER_AIR_SW			(UNUSED)//空调水位低
#define WATER_CAN_SW			(((can_water_low&0x3f) == 29)||((can_water_low&0x3f) == 50))//报文水位低


#define AIRLOW_FRONTDOOR_SW 		 	UNUSED
#define AIRLOW_MIDDOOR_SW 		 		UNUSED


#define AIR1_LOW				((veh_bar1<Air_Alarm) && USEDAIR)
#define AIR2_LOW				((veh_bar2<Air_Alarm) && USEDAIR)
#define AIR_LOW					UNUSED
#define CAN_AIR_LOW				TestBitTrue(Control_information_data7,2)

//摩擦片
#define PLANT_LEFT_F            UNUSED//(!F_SW_P36)//左前蹄片
#define PLANT_RIGHT_F           UNUSED//(!PTB6)//右前蹄片
#define PLANT_LEFT_R            UNUSED//(!PTB7) //左后蹄片
#define PLANT_RIGHT_R           UNUSED//(!PTB8) //右后蹄片

#define PLANT_LEFT              (!F_SW_P36)
#define PLANT_RIGHT             (!F_SW_P37)

//摩擦片报警
#define PLANT_ALL               (PLANT_LEFT||PLANT_RIGHT||PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R) 


/************************ROLL ALARM***************************/
#define DEFINE_TIP_LEAST_VOLT   (Vbat < LEAST_VOLTAGE)                             
#define OIL_LOW                 UNUSED
#define DEFINE_TIP_OIL_LOW		(OIL_LOW) && (eng_speed>0)     
#define DEFINE_TIP_AIR_LOW 		(AIR1_LOW || AIR2_LOW ||AIR_LOW||CAN_AIR_LOW)		       
#define DEFINE_TIP_SPEED		((veh_speed_display >= (Speed_Alarm*10)))                   //超速                                  
#define DEFINE_TIP_WATER_LOW    (WATER_SW ||WATER_RANYOU_SW||WATER_AIR_SW||WATER_CAN_SW)//水位低                                        
#define DEFINE_TIP_PLANT_ALARM  (PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R)//摩擦片报警
#define DEFINE_TIP_ENGINE_WATERTEP_HIGH UNUSED
/***********************************************************/ 

//另类开关
#define CANJI_TABAN 		    UNUSED
#define CHAOSU 				    UNUSED

#define DRIVER_SW  			    PTD4//司机灯
#define BOX_LINGT_SW_1          UNUSED //厢灯1
#define BOX_LINGT_SW_2          UNUSED  //厢灯1
#define TV_SW				    UNUSED
#define LCD_SW				    UNUSED
#define FAN_SW				    UNUSED
#define ROAD_LIGHT 			    UNUSED  //过道灯
#define LUPAI_LIGHT 			PTD2  //路牌灯
#define AIR_COMPRESSOR_ERR_SW	UNUSED
#define INSIDE_LED_SW_1         UNUSED //室内灯1 or 顶灯1
#define INSIDE_LED_SW_2		    PTD11 //室内灯2 or 顶灯2

#define AC_CHARGE_OVER_SW	    UNUSED
#define ENG_TEMP_ALARM_SW	    UNUSED  //发动机仓温报警
#define BAT_TEMP_ALARM_SW	    UNUSED  //电池仓温报警
#define ENG_DOOR_LIGHT_SW	    UNUSED //后仓灯开关
#define XINGLICANG_LIGHT_SW	    UNUSED //行李仓灯开关

#define BENG_SW  			    UNUSED  //暖风水泵开关
#define EMENG_LIGHT_SW		    UNUSED  //应急照明开关

#define SEATBELT_NO_SW          (F_SW_P35 && KEY_ON)  //安全带未系开关
#define DRIVER_AWAY_SW          ((!PTB10) && KEY_ON && (!PARK_SW)) //司机离座开关
#define DRIVER_AWAY_ALARM       UNUSED
#define DIAN_NUANFENG			UNUSED
//其他
#define DEFROST_SW			    UNUSED//除霜1
#define DEFROST_SW_2			UNUSED//除霜2
#define WARM_AIR_BLOWER_SW	    UNUSED//暖风机1
#define WARM_AIR_BLOWER_SW_2	UNUSED//暖风机2
#define ASR_SW  			    PTD14
#define ABS_SW				    PTD16//(TestBits(_18F0010B[5],0,2,0x00)&&TestBits(_18F0010B[5],4,2,0x01))
#define SAFE_DOOR_SW		    UNUSED //安全门
#define BUZZ_SW				    PTD15//喇叭开关
#define WAITUI_CHUANG			UNUSED//外推窗

#define STOP_MARK               ((ID_0CFF0B4A_data2&0x0c) == 0x08)                                             //ready
#define START_MARK              ((ID_0CFF0B4A_data2&0x0c) == 0x0c)                                             //ready
#define READY                   ((ID_0CFF0B4A_data2&0x0c) == 0x04)                                             //ready
#define fault                   ((ID_0CFF0B4A_data2&0x02) == 0x02)                                             //整车故障
#define charge_mark_1           ((battery_1_data6&0x08) == 0x08)                                             //充电链接图标
#define charge_line             ((Control_information_data7&0x02) == 0x02)  

#define ITSR_MARK 				((_18FF0498_data7&0x30)==0x10)
#define ITSR_BLINKER 			((_18FF0498_data7&0xC0)==0x40)


//--------------------abs相关报文宏定义---------------//
#define ASR_SW_Y             ((_18F0010B[5]&0XC0) == 0X40)
#define ASR_SW_BLINK         ((_18F0010B[0]&0X03) == 0X01) ||((_18F0010B[0]&0X0C) == 0X04)

#define ADD_E_BREAK1       ((_18F0010B[0]&0XC0)==0X40)
#define ADD_E_BREAK2       ((_18FDC40B[1]&0X03)==0X01)
#define ESC_BREAK          (ADD_E_BREAK1||ADD_E_BREAK2)//刹车开关  点亮制动灯

//以前宏定义
#define fault1                    ((Control_information_data1&0x80) == 0x80)
#define fault2                    ((Control_information_data1&0x40) == 0x40)
#define fault3                    ((Control_information_data1&0x20) == 0x20)
#define fault4                    ((Control_information_data1&0x10) == 0x10)
#define fault5                    ((Control_information_data1&0x08) == 0x08)
#define fault6                    ((Control_information_data1&0x04) == 0x04)
#define fault7                    ((Control_information_data1&0x02) == 0x02)
#define fault8                    ((Control_information_data1&0x01) == 0x01)

//烟雾报警
#define fault9                    (((battery_1_data6&0x20) == 0x20))
#define fault10                   ((((battery_1_data6&0x06) == 0x02) && ((state_information&0x04) == 0x00))||\
	                                (((battery_2_data6&0x06) == 0x02) && ((state_information&0x04) == 0x04)))
#define fault11                   ((((battery_1_data6&0x06) == 0x04) && ((state_information&0x04) == 0x00))||\
	                                (((battery_2_data6&0x06) == 0x04) && ((state_information&0x04) == 0x04)))
#define fault12                   (((ID_18FF2948_data6&0xC0)== 0x40)&&((ID_18FF2948_data6&0xC0)!= 0xC0))
#define fault13                   (((ID_18FF2948_data6&0xC0)== 0x80)&&((ID_18FF2948_data6&0xC0)!= 0xC0))
#define fault14                   (((ID_18FF2948_data6&0x30)== 0x10)&&((ID_18FF2948_data6&0x30)!= 0x30))
#define fault15                   (((ID_18FF2948_data6&0x30)== 0x20)&&((ID_18FF2948_data6&0x30)!= 0x30))
#define fault16                  (((ID_18FF2948_data6&0x0c)== 0x04)&&((ID_18FF2948_data6&0x0c)!= 0x0c))
#define fault17                  (((ID_18FF2948_data6&0x0c)== 0x08)&&((ID_18FF2948_data6&0x0c)!= 0x0c))
#define fault18                   (((ID_18FF2948_data6&0x03)== 0x01)&&((ID_18FF2948_data6&0x03)!= 0x03))
#define fault19                   (((ID_18FF2948_data6&0x03)== 0x02)&&((ID_18FF2948_data6&0x03)!= 0x03))
#define fault20                  ((insulate_flag&0x30) == 0x10)
#define fault21                  ((insulate_flag&0x30) == 0x20)
#define fault22                  ((motor_flag&0x08) == 0x08)
#define fault23                  ((motor_flag&0x04) == 0x04)
#define fault24                  ((motor_flag&0x02) == 0x02)
#define fault25                  ((motor_flag&0x01) == 0x01)
#define fault26                   ((ID_18FF2D47_data6&0x40) == 0x40)
#define fault27                   ((ID_18FF2D47_data6&0x08) == 0x08)
#define fault28                   ((ID_18FF2D47_data6&0x04) == 0x04)
#define fault29                   ((ID_18FF2D47_data6&0x01) == 0x01)
#define fault30                    ((fog_alarm[0] &0x0F) == 0x04)
#define fault31                    ((fog_alarm[0] &0x0F) == 0x05)
#define fault32                    ((fog_alarm[0] &0x0F) == 0x06)
#define fault33                    ((fog_alarm[0] &0x0F) == 0x07)
#define fault34                    ((((ID_18FF2848_data5&0x40) == 0x40)&&((state_information&0x04) == 0x00))||\
	                                 (((ID_18FF2C48_data5&0x40) == 0x40)&&((state_information&0x04) == 0x04)))

#define fault35                    ((((ID_18FF2848_data5&0x20) == 0x20)&&((state_information&0x04) == 0x00))||\
	                                 (((ID_18FF2C48_data5&0x20) == 0x20)&&((state_information&0x04) == 0x04)))

#define fault36                    ((((ID_18FF2848_data5&0x10) == 0x10)&&((state_information&0x04) == 0x00))||\
	                                 (((ID_18FF2C48_data5&0x10) == 0x10)&&((state_information&0x04) == 0x04)))
	                                 
#define fault37                    ((ID_18FF2848_data5&0x08) == 0x08)
										 
#define fault38                    ((ID_18FF2848_data5&0x40) == 0x40)

#define fault39                    (((ID_18FF2848_data5&0x20) == 0x20))
										 
#define fault40                    ((((ID_18FF2848_data5&0x01) == 0x01)&&((state_information&0x04) == 0x00))||\
									(((ID_18FF2C48_data5&0x01) == 0x01)&&((state_information&0x04) == 0x04)))

#define fault41                     ((state_information&0x01) == 0x01)
#define fault42                     (((electric_shake&0xc0) == 0x40)&&((electric_shake&0xc0) != 0xc0))
#define fault43                     (((electric_shake&0xc0) == 0x80)&&((electric_shake&0xc0) != 0xc0))
#define fault44                     ((electric_shake&0xc0) == 0xc0)
#define fault45                     ((ID_0CFF0B4A_data2&0x01) == 0x01)
#define fault47 					((Control_information_data7&0x01) == 0x01)

#define fog_buzz (((battery_1_data6&0x20) == 0x20)||((battery_2_data6&0x20) == 0x20))
#define insulate_buzz    ((insulate_flag&0x30)==0x20)



#endif





















