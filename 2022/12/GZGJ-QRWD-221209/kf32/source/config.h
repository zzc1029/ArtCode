/*
 * config.h
 *
 *  Created on: 2021-7-27
 *      Author: ART
 */

#ifndef _CONFIG_H
#define _CONFIG_H


#define  ZHONGCAI            UNUSED

#define  BYTONY              UNUSED

//加入CAN测试方法:
//发送repeat，否则single
#define  CAN_SEND_REPERT     UNUSED
//使用中断处理
#define  CAN_SEND_INTERRUPU  UNUSED


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
//---------------------------------------------------------------


//#define  BACKLIGHT_SW_FEEDBACK         B40_FRONT_FEEDBACK(A13)
#define  LED_HBEAM_SW_FEEDBACK         B40_FRONT_FEEDBACK(A4)
#define  LED_LBEAM_SW_FEEDBACK         B40_FRONT_FEEDBACK(A12)
#define  LED_FFOG_SW_FEEDBACK          B40_FRONT_FEEDBACK(A5) 
#define  LED_RFOG_SW_FEEDBACK          B40_REAR_FEEDBACK(A12) 
#define  BREAK_SW_FEEDBACK             B40_REAR_FEEDBACK(A4) 
#define  LED_BACKGROUND_FEEDBACK       B40_FRONT_FEEDBACK(A11)

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


/*雨刮档位设置*****************/
#define WIPER_INT_SW	PTD8 //间歇
#define WIPER_LO_SW     PTD7 //低速档
#define WIPER_HI_SW     PTD6 //高速档
#define WIPER_MI_SW		PTD9 //喷水开关
//雨刷功能打开关闭
#define SUPPORT_WIPER 	USED	
/*雨刮档位设置End*****************/

// 关门三声提示蜂鸣器
#define CLOSE_DOOR_WANT_VOICE          USED

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
#define SENDSPEED_ENABLE	  UNUSED  

//摄像头设置
#define TV1_REVERSE_SW       UNUSED//(REVERSE_GEAR_SW && ChangeVideoAv1Enable && (VIDEO_AV_GRAR))
#define TV2_REAR_DOOR_SW     UNUSED//(UNUSED && ChangeVideoAv4Enable && (VIDEO_AV_ELSE))
#define TV3_FRONT_DOOR_SW    UNUSED//(LED_FRONT_DOOR_SW && ChangeVideoAv3Enable && (VIDEO_AV_FRO))
#define TV4_MIDDLE_DOOR_SW   UNUSED//(LED_MIDDLE_DOOR_SW && ChangeVideoAv2Enable && (VIDEO_AV_MID))



//是否有模块
#define  Has_Fmode       ON
#define  Has_Rmode       ON
#define  Has_Tmode       OFF
#define  Has_Amode       OFF

//新增PWM宏定义

//3 模块所有输出均PWM
#define MODLE_ALL_PWM          UNUSED

#define PWM_F_P04		PWMEable
#define PWM_F_P12		PWMEable
#define PWM_F_P05		PWMEable
#define PWM_F_P14		PWMEable
#define PWM_F_P07		PWMEable
#define PWM_F_P42		PWMEable
#define PWM_F_P08		PWMEable

#define PWM_R_P10		PWMEable
#define PWM_R_P14		PWMEable
#define PWM_R_P08		PWMEable



/**********气压传感器参数开始*************************/
#define BAR_12                 USED     //2 12BAR
#define BAR_10                 UNUSED   //2 10BAR
#define AIR_TYPE               VOLT      //2 气压罐信号来源定义枚举
#define Bar1Source             bcm_senor1_f  //2 气压一来源
#define Bar2Source             bcm_senor2_f  //2 气压二来源
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



/*********蓄电池舱温定义**********************/
//打开宏
#define USEDVBATTEMP    UNUSED
//温度资源
#define VBATTEMPSOUTCE  meter.MeterA4

/******************************/

/*********发动机舱温度定义**********************/
//打开宏
#define USEDENGINETEMP  UNUSED
//温度资源
#define ENGINETEMPSOUTCE  meter.MeterA3

/******************************/


//灯光
#define  LED_LEFT_SW            F_OUT_P3 
#define  LED_RIGHT_SW           F_OUT_P10 
#define  LED_HBEAM_SW           LED_HBEAM_SW_FEEDBACK
#define  LED_LBEAM_SW           LED_LBEAM_SW_FEEDBACK
#define  LED_FFOG_SW            LED_FFOG_SW_FEEDBACK
#define  LED_RFOG_SW            LED_RFOG_SW_FEEDBACK//RFOG_SW                             
//门状态指示
#define  LED_FRONT_DOOR_SW      FRONT_DOOR_SW
#define  LED_MIDDLE_DOOR_SW     MID_DOOR_SW
#define  LED_ENG_DOOR_SW        ENG_DOOR_SW //发动机舱开关
//其他配置项
#define  LED_FILTER_SW          UNUSED
#define  LED_DRYER_SW           (RearCurrent[A11] > 10)                                            
#define  LED_PREHEAT_SW         UNUSED                                              
#define  LED_STOP_SW            UNUSED                                             
#define  LED_SERVICE_SW         UNUSED                                            
#define  LED_ENG_FAULT_SW       UNUSED                                            
#define  LED_ENG_TEMP_HOT_SW    (ENG_TEMP_ALARM_SW || BAT_TEMP_ALARM_SW)
#define  LED_FUEL_LOW_SW        UNUSED
#define  LED_GENERATOR1_SW      UNUSED//充电指示
#define  LED_GENERATOR2_SW      UNUSED//充电指示
#define  LED_GENERATOR_SW       UNUSED//充电指示
//一般情况下无需配置的项目
#define  LED_ABS_SW             ABS_SW
#define  LED_BATTERY_LOW_SW     ((Vbat < 200)||(Vbat > 320))       
#define  LED_OIL_LOW_SW         OIL_LOW                                        
#define  LED_POWER_SW           SYSTEM_POW                                       
#define  LED_AIR_LOW_SW         DEFINE_TIP_AIR_LOW                                
#define  LED_PARK_SW            PARK_SW
/*******************************************************/
#define  ALL_DOOR			(LED_FRONT_DOOR_SW || LED_MIDDLE_DOOR_SW)



/*********仪表设置参数****************/
#define PULSE                    8000 //百米脉冲(C3输出)
#define SUBI  	                 2700   //速比
#define CHESU_COEF               105  //比例系数
#define COEF                     100  //比例系数

#define AIR_ALARM                60
#define OIL_ALARM                100
#define SPEED_ALARM              65
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

#define Motor4_SOURCE            (&Bat_Soc) // 4
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


#define LevelSet_T_A37_IN  HighEnable



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
#define  KEY_ACC			    PTA7                     //ACC档
#define  KEY_ST				    UNUSED 			         //start档
#define  KEY_EMG			    PTA8             		//危急报警开关
#define  KEY_CHARGE             PTA10                   //充电唤醒开关
#define  KEY_POWER			    PTA9					//总电源开关
#define  SYSTEM_POW        	    (KEY_ON||KEY_ACC)     //系统电源开关
#define  WAKE_UP_SW			    (KEY_ON||KEY_ACC||KEY_ST||KEY_EMG||KEY_POWER) //可唤醒开关
#define  LUPAI_LIGHT 			PTA17  //路牌灯

//灯光
#define  RIGHT_LED_SW           PTB11  //右转向灯
#define  LEFT_LED_SW            PTB10  //左转向灯
#define  BACKLIGHT_SW           PTB7  //小灯开关
#define  HBEAM_SW			    PTB8  //远光
#define  LBEAM_SW			    PTB9 //近光
#define  FFOG_SW				PTB5  //前雾灯
#define  RFOG_SW				PTB6  //后雾灯

//刹车
#define BREAK_CONTION           UNUSED
#define BREAK_SW                F_SW_P35
#define ELEC_BREAK              ((OnOffStatus&0x80) == 0x80)                                //刹车开关
#define BREAK_ALL               (BREAK_SW||ELEC_BREAK)
#define PARK_SW				    (F_SW_P21 || ((DriverOperateStatus&0x0f)==0x0f))  //手刹
//档位

#define D_SW   				    (((DriverOperateStatus&0x0f)==14))
#define NULL_SW                 ((DriverOperateStatus&0x0f)==0)  
#define REVERSE_GEAR_SW         (((DriverOperateStatus&0x0f)==13)) 

//门状态)
#define ENG_DOOR_SW			    (KEY_ON && (!R_SW_P17))
#define FRONT_DOOR_SW           F_SW_P17
#define MID_DOOR_SW			    R_SW_P39
#define FRONT_DOOR_OPEN_SW      UNUSED
#define FRONT_DOOR_CLOSE_SW     UNUSED
#define MID_DOOR_OPEN_SW        UNUSED
#define MID_DOOR_CLOSE_SW       UNUSED
//前门防夹开关
#define FRONT_DOOR_FANGJIA_SW   UNUSED 
//中门防夹开关
#define MID_DOOR_FANGJIA_SW     UNUSED

//应急阀
#define EMERGENCY_FRONT_OUT_SW 		R_SW_P35
#define EMERGENCY_FRONT_INT_SW 	    R_SW_P34
#define EMERGENCY_MID_OUT_SW 		R_SW_P20
#define EMERGENCY_MID_INT_SW 	    R_SW_P19

#define EMERGENCY_FRONT_SW 	UNUSED  //前门应急阀
#define EMERGENCY_MID_SW 	UNUSED  //中门应急阀

#define EMERGENCY_SW 		(EMERGENCY_FRONT_OUT_SW||EMERGENCY_FRONT_INT_SW||EMERGENCY_MID_OUT_SW||EMERGENCY_MID_INT_SW) //应急阀 



//常用开关
#define PASSAGE_GET_OUT_SW      UNUSED//下客门铃
#define WATER_SW			    R_SW_P33//水位低
#define WATER_AIR_SW			UNUSED//空调水位低
#define WATER_CAN_SW			UNUSED//报文水位低

#define CHUSHUANG_SW			PTD11//除霜1
#define CHUSHUANG_SW_2			PTD13//除霜2
#define GUANTONG_SW	    		PTB1//贯通灯单档
#define GUANTONG_SW_2			PTB2//贯通灯双档

#define AIRLOW_SW_1 		 	UNUSED	  //前门气压低开关
#define AIRLOW_SW_2 		 	UNUSED	  //后门气压低开关
#define AIRLOW_SW_3				UNUSED	  //气压3报警
#define AIR1_LOW				((veh_bar1<Air_Alarm)||AIRLOW_SW_1)
#define AIR2_LOW				((veh_bar2<Air_Alarm)||AIRLOW_SW_2)
#define PARK_AIR_LOW		 	UNUSED  //驻车气压低
#define DOOR_AIRLOW_SW        	UNUSED  //门泵气压报警
#define BREAK_AIRLOW_SW		 	UNUSED  //刹车气压低
#define CAN_AIR_LOW				UNUSED

//摩擦片
#define PLANT_LEFT_F            (!F_SW_P19)//左前蹄片
#define PLANT_RIGHT_F           (!F_SW_P33)//右前蹄片
#define PLANT_LEFT_R            (!F_SW_P34) //左后蹄片
#define PLANT_RIGHT_R           (!F_SW_P20) //右后蹄片
#define PLANT_LEFT  			(UNUSED)//前蹄片
#define PLANT_RIGHT 			(UNUSED)//后蹄片

//摩擦片报警
#define PLANT_ALL               (PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R) 


/************************ROLL ALARM***************************/
#define DEFINE_TIP_LEAST_VOLT   (Vbat < LEAST_VOLTAGE)                             
#define OIL_LOW                 UNUSED//((4*engine_oil_press) < 70)
#define DEFINE_TIP_OIL_LOW		(OIL_LOW) && (eng_speed>0)     
#define DEFINE_TIP_AIR_LOW 		(AIR1_LOW || AIR2_LOW || DOOR_AIRLOW_SW || BREAK_AIRLOW_SW||CAN_AIR_LOW)		       
#define DEFINE_TIP_SPEED		((veh_speed_display >= (Speed_Alarm*10)))                   //超速                                  
#define DEFINE_TIP_WATER_LOW    WATER_SW ||WATER_AIR_SW||WATER_CAN_SW//水位低                                        
#define DEFINE_TIP_PLANT_ALARM  (PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R)//摩擦片报警
#define DEFINE_TIP_ENGINE_WATERTEP_HIGH UNUSED
/***********************************************************/ 

//另类开关
#define CANJI_TABAN 		    UNUSED
#define CHAOSU 				    UNUSED

#define DRIVER_SW  			    PTD5//司机灯
#define BOX_LINGT_SW            UNUSED //厢灯
#define TV_SW				    UNUSED
#define LCD_SW				    UNUSED
#define FAN_SW				    UNUSED
#define ROAD_LIGHT 			    UNUSED  //过道灯

#define AIR_COMPRESSOR_ERR_SW	UNUSED
#define INSIDE_LED_SW_1         UNUSED //室内灯1 or 顶灯1
#define INSIDE_LED_SW_2		    UNUSED //室内灯2 or 顶灯2

#define AC_CHARGE_OVER_SW	    UNUSED
#define ENG_TEMP_ALARM_SW	    UNUSED  //发动机仓温报警
#define BAT_TEMP_ALARM_SW	    UNUSED  //电池仓温报警
#define ENG_DOOR_LIGHT_SW	    UNUSED //后仓灯开关
#define XINGLICANG_LIGHT_SW	    UNUSED //行李仓灯开关

#define BENG_SW  			    UNUSED  //暖风水泵开关
#define EMENG_LIGHT_SW		    UNUSED  //应急照明开关

#define SEATBELT_NO_SW          (KEY_ON && F_SW_P32)   //安全带未系开关
#define SEATBELT_NO_ALARM		 UNUSED 

#define DRIVER_AWAY_SW           (D_SW &&(!F_SW_P18)) //司机离座开关
#define DRIVER_AWAY_ALARM       UNUSED

#define GUANGGAO_DENGXIAGN_SW	PTD1
#define GUANGGAO_DENGXIAGN_SW_2	PTD2
#define YUXUE_MOSHI				PTB12


//其他
#define WARM_AIR_BLOWER_SW	    UNUSED//暖风机1
#define WARM_AIR_BLOWER_SW_2	UNUSED//暖风机2
#define ASR_SW  			    UNUSED
#define ABS_SW				    PTD16
#define SAFE_DOOR_SW		    UNUSED//安全门
#define BUZZ_SW				    PTD3//喇叭开关

#define ready                ((SystemStatus&0x40) == 0x40)                                           //ready
#define SYSTEM_ERROR   		 ((SystemStatus&0x30)==0x30) //系统故障，小车感叹号图标



#endif





















