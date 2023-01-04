/*
 * config.h
 *
 *  Created on: 2021-11-29
 *      Author: ART
 */

#ifndef CONFIG_H_
#define CONFIG_H_

//定义是否增加485功能
#define RS485  UNUSED

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
#define PARANUM    1
//---------------------------------------------------------------

#define ISRELEASE  USED
#define WATCHDOGEN USED

//需要显示的界面
#define DISPLAYTASKNUM 5





#define POWER_DETECT   (PTA7 || PTA8 || PTA9 || PTA10 || PTE2)


#define OFF     0
#define ON      1
#define UNUSE   0
#define USED    1
#define UNUSED  0

#define HighEnable	             0   //高有效
#define LowEnable	             1   //低有效

#define PWMEable                 1

//仪表控地初始化
#define LevelSet_E02_IN          HighEnable
#define LevelSet_A07_IN          HighEnable
#define LevelSet_A08_IN          HighEnable
#define LevelSet_A09_IN          HighEnable
#define LevelSet_A10_IN          HighEnable
#define LevelSet_A19_IN          HighEnable


//前模块
#define LevelSet_F_A17_IN        HighEnable
//#define LevelSet_F_A22_IN      HighEnable
#define LevelSet_F_A39_IN        HighEnable

//后模块
#define LevelSet_R_A17_IN        HighEnable
//#define LevelSet_R_A22_IN      HighEnable
#define LevelSet_R_A39_IN        HighEnable

//顶模块
#define LevelSet_T_A17_IN        HighEnable
//#define LevelSet_T_A22_IN      HighEnable
#define LevelSet_T_A39_IN        HighEnable


//新增模块
#define LevelSet_A_A17_IN        HighEnable
//#define LevelSet_T_A20_IN      HighEnable
#define LevelSet_A_A39_IN        HighEnable


/***模拟传感器端口上拉电阻以及传感器类型选择******/

//电压电阻标识
#define VOLT  1
#define RES   2

// A2上拉电阻
#define A2_PULL     510/2
// A3上拉电阻
#define A3_PULL     510/2
// A4上拉电阻
#define A4_PULL     510/2
// A13上拉电阻
#define A13_PULL    510/2
// A14上拉电阻
#define A14_PULL    510/2

#define A2_TYE     RES
#define A3_TYE     VOLT
#define A4_TYE     VOLT
#define A13_TYE    VOLT
#define A14_TYE    VOLT
/**********************/


/*********仪表设置参数****************/
#define PULSE                    1000 //百米脉冲(C3输出)
#define SUBI  	                 2100   //速比
#define COEF                     102  //比例系数

#define AIR_ALARM                60
#define OIL_ALARM                105
#define SPEED_ALARM              69
#define VIDEO_GEAR               UNUSED        //1 AV1 2 3 4
#define VIDEO_MID_DOOR           UNUSED  
#define VIDEO_FRO_DOOR           UNUSED
#define VIDEO_ELSE               UNUSED
#define RANYOU_ALARM             8
#define AIR1_COEF                100
#define AIR2_COEF                100
#define FUEL_COEF	             100 //
#define RAIN_TIME                40

#define MODULE_MILE              1
#define METRE_MILE               0
#define MILE_COME_FROM           METRE_MILE  //程数据存储区域定义枚举



/**********气压传感器参数开始*************************/
#define BAR_12                  USED     //2 12BAR
#define BAR_10                  UNUSED   //2 10BAR
#define AIR_TYPE                VOLT      //2 气压罐信号来源定义枚举
#define Bar1Source              meter.MeterA13
#define Bar2Source              meter.MeterA14
#define BCM_SENSOR_VOLT 	   10 	//2 模块传感器单位10mv时定义10，100mv时定义1

/***********气压传感器参数结束***********************/

/********燃油传感器开始**********/

//燃油资源
#define USEDFUEL      UNUSED
#define FUELSOURCE    bcm_senor1_r//meter.MeterA2
// 燃油阻值0 - 180    0 - 100(百分比)
#define FUELFULL_180  0
// 燃油阻值110 - 6    0 - 100(百分比)   
#define FUELFULL_6    1
//燃油传感器类型选择
#define FUELTYPE      FUELFULL_180   

/********燃油传感器结束**********/


/*********蓄电池舱温定义**********************/
//打开宏
#define USEDVBATTEMP    USED
//温度资源
#define VBATTEMPSOUTCE  bcm_senor2_r

/******************************/

#define SUPPORT_WIPER 		USED// 雨刷功能打开关闭

/*雨刮档位设置*****************/
#define WIPER_INT_SW	(SYSTEM_POW&&F_SW_P21) //间歇
#define WIPER_LO_SW     (SYSTEM_POW&&F_SW_P36) //低速档
#define WIPER_HI_SW     (SYSTEM_POW&&F_SW_P22) //高速档
#define WIPER_MI_SW		(SYSTEM_POW&&F_SW_P35) //喷水开关
/*雨刮档位设置End*****************/


//设置界面开关，ON 打开 OFF 关闭
#define ChangeLiChengEnable   ON  //设置里程
#define ChangeSubiEnable      ON  //设置速比
#define ChangePulseEnable     ON  //设置百米脉冲
#define ChangeCoefEnable      ON  //设置显示速度的倍数

#define ChangeTimeEnable      ON   //设置时间
#define ChangeBLEnable        ON   //设置背光
#define ChangeBuzzEnable      ON   //设置蜂鸣器
//----------------易燃挥发物设置宏定义--------
#define ChangeH11BUZZEnable   OFF
#define ChangeH11DISEnable    OFF
#define ChangeLanguageEnable  OFF
//--------------------------------------------
#define ChangeRainEnable         ON 
#define ChangeRainTimeEnable     ON
#define ChangeFuelCoefEnable     ON




/*20180301 TONY Set something*/
#define ChangeAirCoefEnable     ON
#define ChangeSpeedAlarmEnable  ON
#define ChangeAirAlarmEnable    ON
#define ChangeOilAlarmEnable    ON
#define ChangeFuelCoefEnable	ON
#define ChangeRanyouEnable      ON
#define ChangeVideoAv1Enable    ON
#define ChangeVideoAv2Enable    ON
#define ChangeVideoAv3Enable    ON
#define ChangeVideoAv4Enable    ON   



/************************ SWITCH ***************************/


#define KEY_ON				PTE2				  //On档
#define KEY_ACC				PTA7                  //ACC档
#define KEY_ST				PTA10                  //start档
#define KEY_EMG				(PTA8)                 //危急报警开关
#define KEY_CHARGE          PTA9                 //充电唤醒开关
#define KEY_POWER			UNUSED//总电源开关
#define LEAST_VOLTAGE       160
#define DEFINE_TIP_LEAST_VOLT   (Vbat < LEAST_VOLTAGE)   


#define SYSTEM_POW        	(KEY_ON||KEY_ACC)     //系统电源开关
#define WAKE_UP_SW			(KEY_ON||KEY_ACC||KEY_ST||KEY_EMG||KEY_POWER) //可唤醒开关
//灯光
#define RIGHT_LED_SW        PTD8//右转向灯
#define LEFT_LED_SW         PTD7  	//左转向灯
#define BACKLIGHT_SW        PTD11//小灯开关
#define HBEAM_SW			PTD10   	//远光
#define LBEAM_SW			PTD9 	//近光
#define FFOG_SW				PTD15//TestBitTrue(CanData[ID(0x18FF9117)][BYTE1],4)//前雾灯
#define RFOG_SW				PTD13  	//TestBitTrue(CanData[ID(0x18FF9117)][BYTE1],3)//后雾灯  //reset switch
//刹车
#define BREAK_SW            (R_SW_P18)
#define ELEC_BREAK          TestBitTrue(CanData[ID(0x18FFEA97)][1],7)	
#define BREAK_ALL           (BREAK_SW||ELEC_BREAK)
#define PARK_SW				R_SW_P20//手刹

//档位
#define D1_SW   				TestBits(CanData[ID(0x18FFEA97)][7],0,3,1)//((VCU_INFO_1[7].byte & 0X07) == 0X1)
#define D2_SW   				TestBits(CanData[ID(0x18FFEA97)][7],0,3,2)//((VCU_INFO_1[7].byte & 0X07) == 0X2)
#define D3_SW   				TestBits(CanData[ID(0x18FFEA97)][7],0,3,3)//((VCU_INFO_1[7].byte & 0X07) == 0X3)
#define D4_SW   				TestBits(CanData[ID(0x18FFEA97)][7],0,3,4)//((VCU_INFO_1[7].byte & 0X07) == 0X4)
#define D5_SW   				TestBits(CanData[ID(0x18FFEA97)][7],0,3,5)//((VCU_INFO_1[7].byte & 0X07) == 0X5)
#define D6_SW   				TestBits(CanData[ID(0x18FFEA97)][7],0,3,6)//((VCU_INFO_1[7].byte & 0X07) == 0X6)


#define D_SW   				    TestBits(CanData[ID(0x18FFEA97)][0],0,3,3)
#define NULL_SW                 TestBits(CanData[ID(0x18FFEA97)][0],0,3,2)
#define REVERSE_GEAR_SW         TestBits(CanData[ID(0x18FFEA97)][0],0,3,1)

//门状态)
#define ENG_DOOR_SW			    F_SW_P39
#define FRONT_DOOR_SW           T_SW_P17
#define MID_DOOR_SW			    T_SW_P39

//#define FRONT_DOOR_OPEN_SW      F_SW_P33
//#define FRONT_DOOR_CLOSE_SW     F_SW_P19
//#define MID_DOOR_OPEN_SW        F_SW_P32
//#define MID_DOOR_CLOSE_SW       F_SW_P18

//#define FRONT_DOOR_OPEN_CLOSE_SW	F_SW_P17
#define FRONT_DOOR_OPEN_CLOSE_CAN	TestBitTrue(CanData[ID(0x18FF9117)][BYTE4],0)
#define MIDDLE_DOOR_OPEN_CLOSE_CAN	TestBitTrue(CanData[ID(0x18FF9117)][BYTE4],1)

#define ALL_DOOR_OPEN_DIS       PTB5

#define  ALL_DOOR			(LED_FRONT_DOOR_SW || LED_MIDDLE_DOOR_SW)

//常用开关
#define PASSAGE_GET_OUT_SW  (T_SW_P22)//下客门铃

#define WATER_BATT_SW           F_SW_P37
#define WATER_MOTOR_SW          T_SW_P19

#define DEFINE_TIP_WATER_LOW   (WATER_BATT_SW||WATER_MOTOR_SW) 

//其他
#define DEFROST_SW			    UNUSE//除霜1
#define DEFROST_SW_2			UNUSE//除霜2
#define WARM_AIR_BLOWER_SW	    UNUSE//暖风机1
#define WARM_AIR_BLOWER_SW_2	UNUSE//暖风机2
#define ASR_SW  				PTD16
#define ABS_SW					PTD14
#define SAFE_DOOR_SW			UNUSE //安全门
#define BUZZ_SW					UNUSE//喇叭开关

#define PLANT_LEFT_F            (!R_SW_P21)//左前蹄片
#define PLANT_RIGHT_F           (!R_SW_P36)//右前蹄片
#define PLANT_LEFT_R            (!R_SW_P22) //左后蹄片
#define PLANT_RIGHT_R           (!R_SW_P37) //右后蹄片

#define PLANT_ALL			(PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R)


#define EMERGENCY_OUTSIDE_GAI_SW 		R_SW_P32
#define EMERGENCY_OUTSIDE_XUANZHUAN_SW 	R_SW_P33
#define EMERGENCY_INSIDE_GAI_SW 		T_SW_P34
#define EMERGENCY_INSIDE_XUANZHUAN_SW 	T_SW_P20

#define EMERGENCY_ALL		(EMERGENCY_OUTSIDE_GAI_SW||EMERGENCY_OUTSIDE_XUANZHUAN_SW||EMERGENCY_INSIDE_GAI_SW||EMERGENCY_INSIDE_XUANZHUAN_SW)



#define AIR1_LOW				(veh_bar1<Air_Alarm)
#define AIR2_LOW				(veh_bar2<Air_Alarm)
#define BREAK_AIRLOW_SW		 	UNUSE     //刹车气压低

#define BOX_LINGT_SW         	UNUSE //厢灯
#define TV_SW				 	F_SW_P32
#define INSIDE_LED_SW_1       	UNUSE //室内灯1 or 顶灯1
#define INSIDE_LED_SW_2		  	UNUSE //室内灯2 or 顶灯2
#define FAN_SW				 	F_SW_P19
#define DRIVER_LIGHT_SW		  	F_SW_P20

#define AC_CHARGE_OVER_SW	 	UNUSE
#define ENG_TEMP_ALARM_SW	  	UNUSE  //发动机仓温报警
#define BAT_TEMP_ALARM_SW	  	UNUSE  //电池仓温报警
#define ENG_DOOR_LIGHT_SW	  	UNUSE //后仓灯开关
#define XINGLICANG_LIGHT_SW	  	UNUSE //行李仓灯开关

#define BENG_SW  			  	UNUSE  //暖风水泵开关
#define EMENG_LIGHT_SW		  	UNUSE//应急照明开关

#define SEATBELT_NO_SW         (R_SW_P41 && KEY_ON)  //安全带未系开关
#define DRIVER_AWAY_SW      	(!R_SW_P34) //司机离座开关
#define DRIVER_AWAY_ALARM   	UNUSE
#define HUANSUQI_GAPWEN			UNUSE

#define WAITUI_LEFT_CHUANG      T_SW_P36
#define WAITUI_RIRHT_CHUANG     T_SW_P35
#define SHEBEICANG_FOGALARM		PTA19


#define RIGUANGDENG_ZUO_CAN		(TestBits(CanData[ID(0x18FF9117)][BYTE1],6,2,1)||TestBits(CanData[ID(0x18FF9117)][BYTE1],6,2,2))	
#define RIGUANGDENG_YOU_CAN		TestBits(CanData[ID(0x18FF9117)][BYTE1],6,2,2)
#define RIGUANGDENG_ZUO_SW		F_SW_P18
#define RIGUANGDENG_YOU_SW		F_SW_P33

#define FAN_CAN					TestBitTrue(CanData[ID(0x18FF9117)][BYTE3],1)
#define DRIVER_CAN				TestBitTrue(CanData[ID(0x18FF9117)][BYTE1],0)
#define DAOCHENGPING_CAN		TestBitTrue(CanData[ID(0x18FF9117)][BYTE2],6)
#define CHENEIPING_CAN			TestBitTrue(CanData[ID(0x18FF9117)][BYTE2],0)

/*******************************************************/

//摄像头设置
#define TV1_REVERSE_SW       (UNUSED && ChangeVideoAv1Enable && (VIDEO_AV_GRAR))
#define TV2_REAR_DOOR_SW     (UNUSED)//(UNUSE && ChangeVideoAv4Enable && (VIDEO_AV_ELSE))
#define TV3_FRONT_DOOR_SW    (UNUSED && ChangeVideoAv3Enable && (VIDEO_AV_FRO))
#define TV4_MIDDLE_DOOR_SW   (UNUSED && ChangeVideoAv2Enable && (VIDEO_AV_MID))




//定义符号片取模块输出反馈状态
#include "Artpatch.h"


#define  LED_LEFT_SW_FEEDBACK      F_OUT_P8
//右转向
#define  LED_RIGHT_SW_FEEDBACK     F_OUT_P10
//远光灯
#define  LED_HBEAM_SW_FEEDBACK     B40_FRONT_FEEDBACK(A14) && B40_FRONT_FEEDBACK(A42)
//1 近光灯
#define  LED_LBEAM_SW_FEEDBACK     B40_FRONT_FEEDBACK(A3)&& B40_FRONT_FEEDBACK(A11)
//1 前雾灯
#define  LED_FFOG_SW_FEEDBACK      B40_FRONT_FEEDBACK(A4)&& B40_FRONT_FEEDBACK(A6)
//1后雾灯
#define  LED_RFOG_SW_FEEDBACK      B40_TOP_FEEDBACK(A42)
//1 小灯
#define  LED_BACKLIGHT_SW_FEEDBACK (B40_REAR_FEEDBACK(A14))     
//1 刹车灯
#define  LED_BREAK_SW_FEEDBACK     (B40_TOP_FEEDBACK(A3))

/************************ROLL ALARM***************************/
#define DEFINE_TIP_LEAST_VOLT  (Vbat < LEAST_VOLTAGE)                             
#define OIL_LOW                 UNUSE
#define DEFINE_TIP_OIL_LOW		(OIL_LOW)&&(eng_speed>0)     
#define DEFINE_TIP_AIR_LOW 		(AIR1_LOW || AIR2_LOW || BREAK_AIRLOW_SW)	       
#define DEFINE_TIP_SPEED		((veh_speed_display >= (Speed_Alarm*10)))                   //超速                                  
#define DEFINE_TIP_PLANT_ALARM  (PLANT_ALL)//摩擦片报警
#define DEFINE_TIP_ENGINE_WATERTEP_HIGH UNUSE
/***********************************************************/ 

//是否有模块
#define  Has_Fmode       ON
#define  Has_Rmode       ON
#define  Has_Tmode       ON
#define  Has_Amode       OFF

//新增PWM宏定义
#define PWM_R_P02			   PWMEable

//灯光
#define  LED_LEFT_SW          LED_LEFT_SW_FEEDBACK
#define  LED_RIGHT_SW         LED_RIGHT_SW_FEEDBACK
#define  LED_HBEAM_SW         LED_HBEAM_SW_FEEDBACK
#define  LED_LBEAM_SW         LED_LBEAM_SW_FEEDBACK
#define  LED_FFOG_SW          LED_FFOG_SW_FEEDBACK
#define  LED_RFOG_SW          LED_RFOG_SW_FEEDBACK//后雾灯                                   
//门状态指示
#define  LED_FRONT_DOOR_SW    FRONT_DOOR_SW
#define  LED_MIDDLE_DOOR_SW   MID_DOOR_SW
#define  LED_ENG_DOOR_SW      ENG_DOOR_SW //发动机舱开关

#define  LED_FILTER_SW        UNUSE
#define  LED_DRYER_SW         UNUSE                                            
#define  LED_PREHEAT_SW       UNUSE                                            
#define  LED_STOP_SW          UNUSE                                             
#define  LED_SERVICE_SW       UNUSE                                            
#define  LED_ENG_FAULT_SW     UNUSE                                            
#define  LED_ENG_TEMP_HOT_SW  (ENG_TEMP_ALARM_SW || BAT_TEMP_ALARM_SW)
#define  LED_FUEL_LOW_SW      UNUSE
#define  LED_GENERATOR1_SW    UNUSE //充电指示
//一般情况下无需配置的项目
#define  LED_ABS_SW           (ABS_SW||ABS_CAN)
#define  LED_BATTERY_LOW_SW   ((Vbat < 200)||(Vbat > 320))        
#define  LED_OIL_LOW_SW       OIL_LOW                                        
#define  LED_POWER_SW         SYSTEM_POW                                       
#define  LED_AIR_LOW_SW       DEFINE_TIP_AIR_LOW                                
#define  LED_PARK_SW          PARK_SW    


//计算车速方式
#define CALULATE_SPEED_ENABLE  UNUSED
//2 是否启动发送车速报文任务
#define SENDSPEED_ENABLE	  USED  


//安徽阿瑞特易燃挥发物
#define ART_YIRAN             UNUSED
//关门三声提示音
#define CLOSE_DOOR_WANT_VOICE UNUSED

/********************************金龙订单宏使用************************************/
/*
//常亮
#define ASR1 TestBits(CanData[ID(0x18F0010B)][2],2,2,1)//((_18f0010b[2].byte  & 0x0c) == 0x04)
#define ASR4 TestBits(CanData[ID(0x18F0010B)][5],6,2,1)//((_18f0010b[5].byte  & 0xc0) == 0x40)
//闪烁
#define ASR2 (TestBits(CanData[ID(0x18F0010B)][0],2,2,1) || TestBits(CanData[ID(0x18F0010B)][0],0,2,1))//((_18f0010b[0].byte  & 0x03) == 0x01)
*/
#define ABS_CAN				((TestBits(CanData[ID(0x18F0010B)][BYTE6],0,2,1)&&TestBits(CanData[ID(0x18F0010B)][BYTE6],4,2,1))|| (timeout[ID(0x18F0010B)] > 30))


#define EBS_RED				(TestBits(CanData[ID(0x18F0010B)][BYTE6],2,2,1) || (timeout[ID(0x18F0010B)] > 10))
#define EBS_YELLOW			(TestBits(CanData[ID(0x18F0010B)][BYTE6],4,2,1) || (timeout[ID(0x18F0010B)] > 10))
#define ASR_BLINK			(TestBits(CanData[ID(0x18F0010B)][BYTE1],0,2,1) || TestBits(CanData[ID(0x18F0010B)][BYTE1],2,2,1))
#define ASR_ON				(TestBits(CanData[ID(0x18F0010B)][BYTE3],2,2,1) || TestBits(CanData[ID(0x18F0010B)][BYTE6],6,2,1))
#define JINZHAN_TINGCHE		TestBits(CanData[ID(0x18FDC40B)][BYTE1],2,3,1)
#define PODAO_QIBU_ON		TestBits(CanData[ID(0x18FDC40B)][BYTE1],5,3,1)
#define PODAO_QIBU_BLINK	TestBits(CanData[ID(0x18FDC40B)][BYTE1],5,3,2)


#define READY               TestBits(CanData[ID(0x18FFEA97)][0],3,3,4)


#endif /* CONFIG_H_ */
