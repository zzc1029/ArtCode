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

//����CAN���Է���:
//����repeat������single
#define  CAN_SEND_REPERT     UNUSED
//ʹ���жϴ���
#define  CAN_SEND_INTERRUPU  UNUSED


//�������Ƭȡģ���������״̬
#include "Artpatch.h"
//�ö����Ǳ�����汾���Ժ����ÿ�θ��¾��ۼ�1�����Ǳ������Ϣ������ʾ
#define  SOFT_VERSION	1
/*
 �޸ĳ����е������Ϊָ��С������������
 ����:
 1.ODONUM�����汾���Ӽ��� 
 2.����SETTRIP��SETODOΪ��������
 ע������:��������Ӳ���汾T123���ϵ磬��Ҫ���������Ϊ�㣬�޸�ODONUM��������¼����
 ����̲�Ϊ�㣬�ϵ缴�ɡ�
*/

#define ODONUM    0
#define SETTRIP   0
#define SETODO    0

/*
�����޸Ĳ�����ע��̶��������޸�,��������
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

#define HighEnable	0   //����Ч
#define LowEnable	1   //����Ч

#define PWMEable    1
//��ѹ�����ʶ
#define VOLT  1
#define RES   2


#define C16C17CAN  UNUSED

/***ģ�⴫�����˿����������Լ�����������ѡ��******/
// A2��������
#define A2_PULL     255
// A3��������
#define A3_PULL     1000
// A4��������
#define A4_PULL     1000
// A13��������
#define A13_PULL    510
// A14��������
#define A14_PULL    510


#define A2_TYE     RES
#define A3_TYE     RES
#define A4_TYE     RES
#define A13_TYE    VOLT
#define A14_TYE    VOLT
/**********************/


/*��ε�λ����*****************/
#define WIPER_INT_SW	PTD8 //��Ъ
#define WIPER_LO_SW     PTD7 //���ٵ�
#define WIPER_HI_SW     PTD6 //���ٵ�
#define WIPER_MI_SW		PTD9 //��ˮ����
//��ˢ���ܴ򿪹ر�
#define SUPPORT_WIPER 	USED	
/*��ε�λ����End*****************/

// ����������ʾ������
#define CLOSE_DOOR_WANT_VOICE          USED

/*  �������� �Ǳ��Զ����Է���Ƭ����   ָ��ת��һȦ */
#define SELF_TEST_BY_METRE             USED                       //�Ǳ��Բ�ģʽ
#define _8s_100ms                      80                     //80�ٺ���

//�Ǳ��������У��
#define PARACHECKEN UNUSED

//ʱ�����ʹ��
#define SCLKOUTEN  UNUSED
//feed dog enable
#define WATCHDOGEN  USED

//��ʾ����
#define MAXDISMENU 25

/***������T123ͨѶʹ��CAN*******/
#define T123_USED_BCAN  USED
#define T123_USED_TCAN  USED
#define T123_USED_PCAN  USED
#define T123_USED_DCAN  USED

// 360����
#define TV_360  UNUSED

//���㳵�ٷ�ʽ
#define CALULATE_SPEED_ENABLE  UNUSED
//2 �Ƿ��������ͳ��ٱ�������
#define SENDSPEED_ENABLE	  UNUSED  

//����ͷ����
#define TV1_REVERSE_SW       UNUSED//(REVERSE_GEAR_SW && ChangeVideoAv1Enable && (VIDEO_AV_GRAR))
#define TV2_REAR_DOOR_SW     UNUSED//(UNUSED && ChangeVideoAv4Enable && (VIDEO_AV_ELSE))
#define TV3_FRONT_DOOR_SW    UNUSED//(LED_FRONT_DOOR_SW && ChangeVideoAv3Enable && (VIDEO_AV_FRO))
#define TV4_MIDDLE_DOOR_SW   UNUSED//(LED_MIDDLE_DOOR_SW && ChangeVideoAv2Enable && (VIDEO_AV_MID))



//�Ƿ���ģ��
#define  Has_Fmode       ON
#define  Has_Rmode       ON
#define  Has_Tmode       OFF
#define  Has_Amode       OFF

//����PWM�궨��

//3 ģ�����������PWM
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



/**********��ѹ������������ʼ*************************/
#define BAR_12                 USED     //2 12BAR
#define BAR_10                 UNUSED   //2 10BAR
#define AIR_TYPE               VOLT      //2 ��ѹ���ź���Դ����ö��
#define Bar1Source             bcm_senor1_f  //2 ��ѹһ��Դ
#define Bar2Source             bcm_senor2_f  //2 ��ѹ����Դ
#define BCM_SENSOR_VOLT 	   10 	//2 ģ�鴫������λ10mvʱ����10��100mvʱ����1

/***********��ѹ��������������***********************/

/********ȼ�ʹ�������ʼ**********/

//ȼ����Դ
#define USEDFUEL      UNUSED
#define FUELSOURCE    meter.MeterA2
// ȼ����ֵ0 - 180    0 - 100(�ٷֱ�)
#define FUELFULL_180  0
// ȼ����ֵ110 - 6    0 - 100(�ٷֱ�)   
#define FUELFULL_6    1
//ȼ�ʹ���������ѡ��
#define FUELTYPE      FUELFULL_180   

/********ȼ�ʹ���������**********/



/*********���ز��¶���**********************/
//�򿪺�
#define USEDVBATTEMP    UNUSED
//�¶���Դ
#define VBATTEMPSOUTCE  meter.MeterA4

/******************************/

/*********���������¶ȶ���**********************/
//�򿪺�
#define USEDENGINETEMP  UNUSED
//�¶���Դ
#define ENGINETEMPSOUTCE  meter.MeterA3

/******************************/


//�ƹ�
#define  LED_LEFT_SW            F_OUT_P3 
#define  LED_RIGHT_SW           F_OUT_P10 
#define  LED_HBEAM_SW           LED_HBEAM_SW_FEEDBACK
#define  LED_LBEAM_SW           LED_LBEAM_SW_FEEDBACK
#define  LED_FFOG_SW            LED_FFOG_SW_FEEDBACK
#define  LED_RFOG_SW            LED_RFOG_SW_FEEDBACK//RFOG_SW                             
//��״ָ̬ʾ
#define  LED_FRONT_DOOR_SW      FRONT_DOOR_SW
#define  LED_MIDDLE_DOOR_SW     MID_DOOR_SW
#define  LED_ENG_DOOR_SW        ENG_DOOR_SW //�������տ���
//����������
#define  LED_FILTER_SW          UNUSED
#define  LED_DRYER_SW           (RearCurrent[A11] > 10)                                            
#define  LED_PREHEAT_SW         UNUSED                                              
#define  LED_STOP_SW            UNUSED                                             
#define  LED_SERVICE_SW         UNUSED                                            
#define  LED_ENG_FAULT_SW       UNUSED                                            
#define  LED_ENG_TEMP_HOT_SW    (ENG_TEMP_ALARM_SW || BAT_TEMP_ALARM_SW)
#define  LED_FUEL_LOW_SW        UNUSED
#define  LED_GENERATOR1_SW      UNUSED//���ָʾ
#define  LED_GENERATOR2_SW      UNUSED//���ָʾ
#define  LED_GENERATOR_SW       UNUSED//���ָʾ
//һ��������������õ���Ŀ
#define  LED_ABS_SW             ABS_SW
#define  LED_BATTERY_LOW_SW     ((Vbat < 200)||(Vbat > 320))       
#define  LED_OIL_LOW_SW         OIL_LOW                                        
#define  LED_POWER_SW           SYSTEM_POW                                       
#define  LED_AIR_LOW_SW         DEFINE_TIP_AIR_LOW                                
#define  LED_PARK_SW            PARK_SW
/*******************************************************/
#define  ALL_DOOR			(LED_FRONT_DOOR_SW || LED_MIDDLE_DOOR_SW)



/*********�Ǳ����ò���****************/
#define PULSE                    8000 //��������(C3���)
#define SUBI  	                 2700   //�ٱ�
#define CHESU_COEF               105  //����ϵ��
#define COEF                     100  //����ϵ��

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

//���ý��濪��
#define ChangeLiChengEnable      ON  //�������
#define ChangeSubiEnable         ON  //�����ٱ�
#define ChangePulseEnable        ON  //���ð�������
#define ChangeCoefEnable         ON  //������ʾ�ٶȵı���

#define ChangeTimeEnable         ON   //����ʱ��
#define ChangeBLEnable           ON   //���ñ���
#define ChangeBuzzEnable         ON   //���÷�����

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

/********************************����������ʹ��************************************/
#define ChangeRainEnable         ON 
#define ChangeRainTimeEnable     ON
//˲ʱ��ĺ궨��  
#define ChangeFuelCoefEnable     ON

/******************ָ������Դ����******************************/
//     2    3         ָ��λ��
// 0            1
// 4            5
#define Rotate_Speed_SOURCE      (&eng_speed)   //��ͼ���0      
#define Vehicle_Speed_SOURCE     (&veh_speed_display)      //��ͼ���1

#define Motor2_SOURCE            (&veh_bar1)// 2
#define Motor3_SOURCE            (&veh_bar2)// 3

#define Motor4_SOURCE            (&Bat_Soc) // 4
#define Motor5_SOURCE            (&Vbat)  //  5
/**********************************************************************/

#define LevelSet_C20_IN          HighEnable //ͬC52��E2
#define LevelSet_A07_IN          HighEnable
#define LevelSet_A08_IN          HighEnable
#define LevelSet_A09_IN          HighEnable
#define LevelSet_A10_IN          HighEnable
#define LevelSet_A17_IN          HighEnable
#define LevelSet_A18_IN          HighEnable
#define LevelSet_A19_IN          HighEnable


#define LevelSet_T_A37_IN  HighEnable



//ǰģ��
#define LevelSet_F_A17_IN  HighEnable
//#define LevelSet_F_A22_IN  HighEnable
#define LevelSet_F_A39_IN  HighEnable

//��ģ��
#define LevelSet_R_A17_IN  HighEnable
//#define LevelSet_R_A22_IN  HighEnable
#define LevelSet_R_A39_IN  HighEnable

//��ģ��
#define LevelSet_T_A17_IN  HighEnable
//#define LevelSet_T_A22_IN  HighEnable
#define LevelSet_T_A39_IN  HighEnable


//����ģ��
#define LevelSet_A_A17_IN  HighEnable
//#define LevelSet_T_A20_IN  HighEnable
#define LevelSet_A_A39_IN  HighEnable

/************************ SWITCH ***************************/
#define  KEY_ON				    PTE2				     //On��
#define  KEY_ACC			    PTA7                     //ACC��
#define  KEY_ST				    UNUSED 			         //start��
#define  KEY_EMG			    PTA8             		//Σ����������
#define  KEY_CHARGE             PTA10                   //��绽�ѿ���
#define  KEY_POWER			    PTA9					//�ܵ�Դ����
#define  SYSTEM_POW        	    (KEY_ON||KEY_ACC)     //ϵͳ��Դ����
#define  WAKE_UP_SW			    (KEY_ON||KEY_ACC||KEY_ST||KEY_EMG||KEY_POWER) //�ɻ��ѿ���
#define  LUPAI_LIGHT 			PTA17  //·�Ƶ�

//�ƹ�
#define  RIGHT_LED_SW           PTB11  //��ת���
#define  LEFT_LED_SW            PTB10  //��ת���
#define  BACKLIGHT_SW           PTB7  //С�ƿ���
#define  HBEAM_SW			    PTB8  //Զ��
#define  LBEAM_SW			    PTB9 //����
#define  FFOG_SW				PTB5  //ǰ���
#define  RFOG_SW				PTB6  //�����

//ɲ��
#define BREAK_CONTION           UNUSED
#define BREAK_SW                F_SW_P35
#define ELEC_BREAK              ((OnOffStatus&0x80) == 0x80)                                //ɲ������
#define BREAK_ALL               (BREAK_SW||ELEC_BREAK)
#define PARK_SW				    (F_SW_P21 || ((DriverOperateStatus&0x0f)==0x0f))  //��ɲ
//��λ

#define D_SW   				    (((DriverOperateStatus&0x0f)==14))
#define NULL_SW                 ((DriverOperateStatus&0x0f)==0)  
#define REVERSE_GEAR_SW         (((DriverOperateStatus&0x0f)==13)) 

//��״̬)
#define ENG_DOOR_SW			    (KEY_ON && (!R_SW_P17))
#define FRONT_DOOR_SW           F_SW_P17
#define MID_DOOR_SW			    R_SW_P39
#define FRONT_DOOR_OPEN_SW      UNUSED
#define FRONT_DOOR_CLOSE_SW     UNUSED
#define MID_DOOR_OPEN_SW        UNUSED
#define MID_DOOR_CLOSE_SW       UNUSED
//ǰ�ŷ��п���
#define FRONT_DOOR_FANGJIA_SW   UNUSED 
//���ŷ��п���
#define MID_DOOR_FANGJIA_SW     UNUSED

//Ӧ����
#define EMERGENCY_FRONT_OUT_SW 		R_SW_P35
#define EMERGENCY_FRONT_INT_SW 	    R_SW_P34
#define EMERGENCY_MID_OUT_SW 		R_SW_P20
#define EMERGENCY_MID_INT_SW 	    R_SW_P19

#define EMERGENCY_FRONT_SW 	UNUSED  //ǰ��Ӧ����
#define EMERGENCY_MID_SW 	UNUSED  //����Ӧ����

#define EMERGENCY_SW 		(EMERGENCY_FRONT_OUT_SW||EMERGENCY_FRONT_INT_SW||EMERGENCY_MID_OUT_SW||EMERGENCY_MID_INT_SW) //Ӧ���� 



//���ÿ���
#define PASSAGE_GET_OUT_SW      UNUSED//�¿�����
#define WATER_SW			    R_SW_P33//ˮλ��
#define WATER_AIR_SW			UNUSED//�յ�ˮλ��
#define WATER_CAN_SW			UNUSED//����ˮλ��

#define CHUSHUANG_SW			PTD11//��˪1
#define CHUSHUANG_SW_2			PTD13//��˪2
#define GUANTONG_SW	    		PTB1//��ͨ�Ƶ���
#define GUANTONG_SW_2			PTB2//��ͨ��˫��

#define AIRLOW_SW_1 		 	UNUSED	  //ǰ����ѹ�Ϳ���
#define AIRLOW_SW_2 		 	UNUSED	  //������ѹ�Ϳ���
#define AIRLOW_SW_3				UNUSED	  //��ѹ3����
#define AIR1_LOW				((veh_bar1<Air_Alarm)||AIRLOW_SW_1)
#define AIR2_LOW				((veh_bar2<Air_Alarm)||AIRLOW_SW_2)
#define PARK_AIR_LOW		 	UNUSED  //פ����ѹ��
#define DOOR_AIRLOW_SW        	UNUSED  //�ű���ѹ����
#define BREAK_AIRLOW_SW		 	UNUSED  //ɲ����ѹ��
#define CAN_AIR_LOW				UNUSED

//Ħ��Ƭ
#define PLANT_LEFT_F            (!F_SW_P19)//��ǰ��Ƭ
#define PLANT_RIGHT_F           (!F_SW_P33)//��ǰ��Ƭ
#define PLANT_LEFT_R            (!F_SW_P34) //�����Ƭ
#define PLANT_RIGHT_R           (!F_SW_P20) //�Һ���Ƭ
#define PLANT_LEFT  			(UNUSED)//ǰ��Ƭ
#define PLANT_RIGHT 			(UNUSED)//����Ƭ

//Ħ��Ƭ����
#define PLANT_ALL               (PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R) 


/************************ROLL ALARM***************************/
#define DEFINE_TIP_LEAST_VOLT   (Vbat < LEAST_VOLTAGE)                             
#define OIL_LOW                 UNUSED//((4*engine_oil_press) < 70)
#define DEFINE_TIP_OIL_LOW		(OIL_LOW) && (eng_speed>0)     
#define DEFINE_TIP_AIR_LOW 		(AIR1_LOW || AIR2_LOW || DOOR_AIRLOW_SW || BREAK_AIRLOW_SW||CAN_AIR_LOW)		       
#define DEFINE_TIP_SPEED		((veh_speed_display >= (Speed_Alarm*10)))                   //����                                  
#define DEFINE_TIP_WATER_LOW    WATER_SW ||WATER_AIR_SW||WATER_CAN_SW//ˮλ��                                        
#define DEFINE_TIP_PLANT_ALARM  (PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R)//Ħ��Ƭ����
#define DEFINE_TIP_ENGINE_WATERTEP_HIGH UNUSED
/***********************************************************/ 

//���࿪��
#define CANJI_TABAN 		    UNUSED
#define CHAOSU 				    UNUSED

#define DRIVER_SW  			    PTD5//˾����
#define BOX_LINGT_SW            UNUSED //���
#define TV_SW				    UNUSED
#define LCD_SW				    UNUSED
#define FAN_SW				    UNUSED
#define ROAD_LIGHT 			    UNUSED  //������

#define AIR_COMPRESSOR_ERR_SW	UNUSED
#define INSIDE_LED_SW_1         UNUSED //���ڵ�1 or ����1
#define INSIDE_LED_SW_2		    UNUSED //���ڵ�2 or ����2

#define AC_CHARGE_OVER_SW	    UNUSED
#define ENG_TEMP_ALARM_SW	    UNUSED  //���������±���
#define BAT_TEMP_ALARM_SW	    UNUSED  //��ز��±���
#define ENG_DOOR_LIGHT_SW	    UNUSED //��ֵƿ���
#define XINGLICANG_LIGHT_SW	    UNUSED //����ֵƿ���

#define BENG_SW  			    UNUSED  //ů��ˮ�ÿ���
#define EMENG_LIGHT_SW		    UNUSED  //Ӧ����������

#define SEATBELT_NO_SW          (KEY_ON && F_SW_P32)   //��ȫ��δϵ����
#define SEATBELT_NO_ALARM		 UNUSED 

#define DRIVER_AWAY_SW           (D_SW &&(!F_SW_P18)) //˾����������
#define DRIVER_AWAY_ALARM       UNUSED

#define GUANGGAO_DENGXIAGN_SW	PTD1
#define GUANGGAO_DENGXIAGN_SW_2	PTD2
#define YUXUE_MOSHI				PTB12


//����
#define WARM_AIR_BLOWER_SW	    UNUSED//ů���1
#define WARM_AIR_BLOWER_SW_2	UNUSED//ů���2
#define ASR_SW  			    UNUSED
#define ABS_SW				    PTD16
#define SAFE_DOOR_SW		    UNUSED//��ȫ��
#define BUZZ_SW				    PTD3//���ȿ���

#define ready                ((SystemStatus&0x40) == 0x40)                                           //ready
#define SYSTEM_ERROR   		 ((SystemStatus&0x30)==0x30) //ϵͳ���ϣ�С����̾��ͼ��



#endif





















