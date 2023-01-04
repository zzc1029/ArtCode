/*
 * config.h
 *
 *  Created on: 2021-11-29
 *      Author: ART
 */

#ifndef CONFIG_H_
#define CONFIG_H_

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

#define ISRELEASE  USED
#define WATCHDOGEN USED

//需要显示的界面
#define DISPLAYTASKNUM 5
#define POWER_DETECT   (PTA7||PTA8||PTA9||PTA10||PTA12||PTE2||PTA20)


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
#define LevelSet_A20_IN			 HighEnable

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
#define A3_TYE     RES
#define A4_TYE     RES
#define A13_TYE    VOLT
#define A14_TYE    VOLT
/**********************/


/*********仪表设置参数****************/
#define PULSE                    8000 //百米脉冲(C3输出)
#define SUBI  	                 2500   //速比
#define COEF                     102  //比例系数

#define AIR_ALARM                55
#define OIL_ALARM                105
#define SPEED_ALARM              65
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
#define Bar1Source              bcm_senor1_f  //2 气压一来源
#define Bar2Source              bcm_senor2_f  //2 气压二来源
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
#define VBATTEMPSOUTCE  bcm_senor2_t

/******************************/

#define SUPPORT_WIPER 		USED// 雨刷功能打开关闭

/*雨刮档位设置*****************/
#define WIPER_INT_SW	(KEY_ON&&PTD8) //间歇
#define WIPER_LO_SW     (KEY_ON&&PTD7) //低速档
#define WIPER_HI_SW     (KEY_ON&&PTD6) //高速档
#define WIPER_MI_SW		(KEY_ON&&PTD9) //喷水开关
/*雨刮档位设置End*****************/


//设置界面开关，ON 打开 OFF 关闭
#define ChangeLiChengEnable   ON  //设置里程
#define ChangeSubiEnable      ON  //设置速比
#define ChangePulseEnable     ON  //设置百米脉冲
#define ChangeCoefEnable      ON  //设置显示速度的倍数

#define ChangeTimeEnable      ON   //设置时间
#define ChangeBLEnable        ON   //设置背光
#define ChangeBuzzEnable      ON   //设置蜂鸣器

#define ChangeRainEnable         ON 
#define ChangeRainTimeEnable     ON




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
#define KEY_ST				UNUSED                  //start档
#define KEY_EMG				(PTA8)                 //危急报警开关
#define KEY_CHARGE          PTA10                 //充电唤醒开关
#define KEY_POWER			PTA9//总电源开关
#define LEAST_VOLTAGE       160
#define DEFINE_TIP_LEAST_VOLT   (Vbat < LEAST_VOLTAGE)   


#define SYSTEM_POW        	(KEY_ON||KEY_ACC)     //系统电源开关
#define WAKE_UP_SW			(KEY_ON||KEY_ACC||KEY_ST||KEY_EMG||KEY_POWER) //可唤醒开关
//灯光
#define RIGHT_LED_SW        PTB11   //右转向灯
#define LEFT_LED_SW         PTB10    //左转向灯
#define BACKLIGHT_SW        PTB7    //小灯开关
#define HBEAM_SW            PTB8    //远光
#define LBEAM_SW            PTB9    //近光
#define FFOG_SW             TonyTestBitTrue(0x18FA0118,BYTE1,0)//PTB5//前雾灯
#define RFOG_SW             TonyTestBitTrue(0x18FA0118,BYTE1,1)//PTB6//后雾灯


#define LOW_SPEED_SW         TonyTestBitTrue(0x18FA0118,BYTE1,2)
#define DRIVE_LIGHT_SW       TonyTestBitTrue(0x18FA0118,BYTE1,3)
#define XIANG_DENG1_SW       TonyTestBitTrue(0x18FA0118,BYTE1,4)
#define XIANG_DENG2_SW       TonyTestBitTrue(0x18FA0118,BYTE1,5)
#define LU_PAI_SW            TonyTestBitTrue(0x18FA0118,BYTE1,6)
#define GUANG_GAO_SW         TonyTestBitTrue(0x18FA0118,BYTE1,7)

#define HOU_SHIJING_SW       TonyTestBitTrue(0x18FA0118,BYTE2,0)//PTB5//前雾灯
#define ECAS_UP_SW           TonyTestBitTrue(0x18FA0118,BYTE2,1)//PTB6//后雾灯
#define ECAS_DOWN_SW         TonyTestBitTrue(0x18FA0118,BYTE2,2)
#define ECAS_RESET_SW        TonyTestBitTrue(0x18FA0118,BYTE2,3)
#define ECAS_CEGUI_SW        TonyTestBitTrue(0x18FA0118,BYTE2,4)
#define DRIVE_FENGSHAN_SW    TonyTestBitTrue(0x18FA0118,BYTE2,5)
#define CHUSHUANG_LOW_SW     TonyTestBitTrue(0x18FA0118,BYTE2,6)
#define CHUSHUANG_HIGHT_SW   TonyTestBitTrue(0x18FA0118,BYTE2,7)




//刹车
#define BREAK_SW            (F_SW_P35)
#define ELEC_BREAK          ((OnOffStatus&0x80) == 0x80)   
#define BREAK_ALL           (BREAK_SW||ELEC_BREAK)

#define READY               ((SystemStatus&0x40) == 0x40) 
#define SYSTEM_ERROR   		 ((SystemStatus&0x30)==0x30) 
#define SYSTEM_ERROR_WUGUI   ((SystemStatus&0x30)==0x20) 


#define PARK_SW            	F_SW_P21//手刹
//档位
#define D_SW   				    (((DriverOperateStatus&0x0f)==14))
#define NULL_SW                 ((DriverOperateStatus&0x0f)==0)  
#define REVERSE_GEAR_SW         (((DriverOperateStatus&0x0f)==13)) 
#define P_SW					((DriverOperateStatus&0x0f)==0x0f)

//门状态)
#define ENG_DOOR_SW         (!R_SW_P17)
#define FRONT_DOOR_SW       T_SW_P17
#define MID_DOOR_SW         T_SW_P39

#define FRONT_DOOR_OPEN_SW  UNUSE
#define FRONT_DOOR_CLOSE_SW UNUSE
#define MID_DOOR_OPEN_SW    UNUSE
#define MID_DOOR_CLOSE_SW   UNUSE

#define FRONT_DOOR_FANGJIA_SW UNUSE //防夹开关
#define MID_DOOR_FANGJIA_SW   UNUSE

//常用开关
#define PASSAGE_GET_OUT_SW  (T_SW_P37)//下客门铃
#define WATER_SW      		 R_SW_P33//冷却水位低  
  

//其他
#define ASR_SW              UNUSE
#define ABS_SW              PTD16
#define SAFE_DOOR_SW        UNUSE //安全门
#define BUZZ_SW             PTD3//喇叭开关

#define PLANT_LEFT_F  ((!F_SW_P19))//左前蹄片
#define PLANT_RIGHT_F ((!F_SW_P33))//右前蹄片
#define PLANT_LEFT_R  ((!F_SW_P34)) //左后蹄片
#define PLANT_RIGHT_R ((!F_SW_P20)) //右后蹄片


#define PLANT_ALL     (PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R) //摩擦片报警

#define EMERGENCY_F_INSIDE_SW       (T_SW_P18)
#define EMERGENCY_F_OUTSIDE_SW      (T_SW_P19)
#define EMERGENCY_M_INSIDE_SW       (T_SW_P32)
#define EMERGENCY_M_OUTSIDE_SW      (T_SW_P33)
#define EMERGENCY_ALL     (EMERGENCY_F_INSIDE_SW||EMERGENCY_F_OUTSIDE_SW||EMERGENCY_M_INSIDE_SW||EMERGENCY_M_OUTSIDE_SW) //摩擦片报警


#define AIRLOW_SW_1 		 	UNUSED	  //前门气压低开关
#define AIRLOW_SW_2 		 	UNUSED	  //后门气压低开关

#define AIR1_LOW				((veh_bar1<Air_Alarm)||AIRLOW_SW_1)
#define AIR2_LOW				((veh_bar2<Air_Alarm)||AIRLOW_SW_2)
#define DEFINE_TIP_AIR_LOW 		(AIR1_LOW || AIR2_LOW)	

#define DRIVER_SW            PTD5//司机灯
#define BOX_LINGT_1_SW       PTD1 //厢灯
#define BOX_LINGT_2_SW       PTD2 //厢灯
#define DEFROST_SW           PTD11//除霜低速
#define DEFROST_SW_2         PTD13//除霜高速 
#define DIAN_JIARE_SW		 F_SW_P39
#define TV_SW                UNUSE
#define LCD_SW               PTC10  //广告灯箱
#define FAN_SW               PTB12  //风扇
#define ROAD_LIGHT           UNUSE  //过道灯
#define LUPAI_LIGHT          UNUSE//路牌灯


#define SEATBELT_NO_SW         (KEY_ON && F_SW_P32)  //安全带未系开关
#define DRIVER_AWAY_SW          (D_SW && (!F_SW_P18)) //司机离座开关
#define DRIVER_AWAY_ALARM       (UNUSE)
#define OUTSIDE_VOICE_BAN_SW	!LOW_SPEED_SW
#define CANJI_TABAN		  		F_SW_P17


//摄像头设置
#define TV1_REVERSE_SW       (UNUSED && ChangeVideoAv1Enable && (VIDEO_AV_GRAR))
#define TV2_REAR_DOOR_SW     (UNUSED)//(UNUSE && ChangeVideoAv4Enable && (VIDEO_AV_ELSE))
#define TV3_FRONT_DOOR_SW    (UNUSED && ChangeVideoAv3Enable && (VIDEO_AV_FRO))
#define TV4_MIDDLE_DOOR_SW   (UNUSED && ChangeVideoAv2Enable && (VIDEO_AV_MID))




//定义符号片取模块输出反馈状态
#include "Artpatch.h"


#define  LED_LEFT_SW_FEEDBACK      F_OUT_P3//B40_FEEDBACK(f,A11) && B40_FEEDBACK(r,A11)
//右转向
#define  LED_RIGHT_SW_FEEDBACK     F_OUT_P10//B40_FEEDBACK(f,A4)  && B40_FEEDBACK(r,A4)
//远光灯
#define  LED_HBEAM_SW_FEEDBACK     B40_FRONT_FEEDBACK(A4)
//1 近光灯
#define  LED_LBEAM_SW_FEEDBACK     B40_FRONT_FEEDBACK(A12)
//1 前雾灯
#define  LED_FFOG_SW_FEEDBACK      B40_FRONT_FEEDBACK(A5)
//1后雾灯
#define  LED_RFOG_SW_FEEDBACK      B40_REAR_FEEDBACK(A12)
//1 小灯
#define  LED_BACKLIGHT_SW_FEEDBACK (B40_FRONT_FEEDBACK(A11) && B40_TOP_FEEDBACK(A12)&& B40_REAR_FEEDBACK(A14)&& B40_REAR_FEEDBACK(A7))
//1 刹车灯
#define  LED_BREAK_SW_FEEDBACK     (B40_TOP_FEEDBACK(A6) && B40_REAR_FEEDBACK(A4))


//是否有模块
#define  Has_Fmode       ON
#define  Has_Rmode       ON
#define  Has_Tmode       ON
#define  Has_Amode       OFF

//新增PWM宏定义
#define PWM_F_P04              PWMEable
#define PWM_F_P12              PWMEable
#define PWM_F_P05              PWMEable

#define PWM_T_P11              PWMEable
#define PWM_T_P04              PWMEable

#define PWM_R_P42              PWMEable

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
//其他配置项
#define  LED_FILTER_SW        UNUSE
#define  LED_DRYER_SW         (RearCurrent[A11] > 10)  
#define  LED_PREHEAT_SW       UNUSE
#define  LED_ENG_FAULT_SW     UNUSE
#define  LED_ENG_TEMP_HOT_SW  UNUSE
#define  LED_FUEL_LOW_SW      UNUSE
#define  LED_GENERATOR1_SW    UNUSE //充电指示
//一般情况下无需配置的项目
#define  LED_ABS_SW           ABS_SW
#define  LED_BATTERY_LOW_SW   ((Vbat < 200)||(Vbat > 320))
#define  LED_OIL_LOW_SW       OIL_LOW
#define  LED_POWER_SW         SYSTEM_POW
#define  LED_AIR_LOW_SW       DEFINE_TIP_AIR_LOW
#define  LED_PARK_SW          PARK_SW
//里程数据存储区域定义枚举

/************************ROLL ALARM***************************/

#define DEFINE_TIP_LEAST_VOLT  (Vbat < LEAST_VOLTAGE)
#define OIL_LOW                 UNUSE
#define DEFINE_TIP_OIL_LOW      (OIL_LOW)&&(eng_speed>0)
#define DEFINE_TIP_SPEED        ((veh_speed_display >= (Speed_Alarm*10)))                   //超速                                  
#define DEFINE_TIP_WATER_LOW    WATER_SW                //水位低                                        
#define DEFINE_TIP_PLANT_ALARM  (PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R)//摩擦片报警
#define DEFINE_TIP_ENGINE_WATERTEP_HIGH UNUSE

//计算车速方式
#define CALULATE_SPEED_ENABLE  UNUSED
//2 是否启动发送车速报文任务
#define SENDSPEED_ENABLE	  USED  


//安徽阿瑞特易燃挥发物
#define ART_YIRAN             UNUSED

//关门三声提示音
#define CLOSE_DOOR_WANT_VOICE USED
                                      


#endif /* CONFIG_H_ */
