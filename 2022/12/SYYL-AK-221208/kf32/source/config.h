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


#define  BACKLIGHT_SW_FEEDBACK         B40_FRONT_FEEDBACK(A13)
#define  LED_HBEAM_SW_FEEDBACK         B40_FRONT_FEEDBACK(A5)
#define  LED_LBEAM_SW_FEEDBACK         B40_FRONT_FEEDBACK(A6)
#define  LED_FFOG_SW_FEEDBACK          B40_FRONT_FEEDBACK(A13) 
#define  LED_RFOG_SW_FEEDBACK          B40_REAR_FEEDBACK(A2) 
#define  BREAK_SW_FEEDBACK             B40_REAR_FEEDBACK(A9) 
#define  LED_BACKGROUND_FEEDBACK       B40_FRONT_FEEDBACK(A42)

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

/***ģ�⴫�����˿����������Լ�����������ѡ��******/
// A2��������
#define A2_PULL     510/2
// A3��������
#define A3_PULL     1000//510
// A4��������
#define A4_PULL     1000//510
// A13��������
#define A13_PULL    510
// A14��������
#define A14_PULL    510
// A15��������
#define A15_PULL    1000

#define A2_TYE     RES
#define A3_TYE     RES
#define A4_TYE     RES
#define A13_TYE    VOLT
#define A14_TYE    VOLT
/**********************/


//���Ͻ����������ѯ��ʾ��ʱ����3��
#define GUZHAGN_LOOP USED
//������������256��  ����������
#define MAX_MA      100 


/*��ε�λ����*****************/
#define WIPER_INT_SW	UNUSED//(KEY_ON&&PTB7) //��Ъ
#define WIPER_LO_SW     UNUSED//(KEY_ON&&PTB8) //���ٵ�
#define WIPER_HI_SW     UNUSED//(KEY_ON&&PTB2) //���ٵ�
#define WIPER_MI_SW		UNUSED//(KEY_ON&&PTB1) //��ˮ����
//��ˢ���ܴ򿪹ر�
#define SUPPORT_WIPER 	UNUSED	
/*��ε�λ����End*****************/

//����������ON����λ�ر�ʱ������Э����ʾ��ɲͼ��5����
#define ANKAI_ADD_SCREEC_FOR_PARK      UNUSED
#define NO_PARK                        Ankai_Add_190703.bit.b5
//����
#define YOUMEN_ENABLE  	               UNUSED//TestBitTrue(_0CFF0B4A[1],3)
//EP�����
#define EP_ENABLE                      UNUSED//TestBitTrue(_18FF0152[1],0)

// ����������ʾ������
#define CLOSE_DOOR_WANT_VOICE          UNUSED

/*  �������� �Ǳ��Զ����Է���Ƭ����   ָ��ת��һȦ */
#define SELF_TEST_BY_METRE             USED                       //�Ǳ��Բ�ģʽ
#define _8s_100ms                      80                     //80�ٺ���

//�Ǳ��������У��
#define PARACHECKEN UNUSED

//ʱ�����ʹ��
#define SCLKOUTEN  UNUSED
//feed dog enable
#define WATCHDOGEN  UNUSED

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
#define CALULATE_SPEED_ENABLE  USED
//2 �Ƿ��������ͳ��ٱ�������
#define SENDSPEED_ENABLE	  USED  

//����ͷ����
#define TV1_REVERSE_SW       UNUSED//(REVERSE_GEAR_SW && ChangeVideoAv1Enable && (VIDEO_AV_GRAR))
#define TV2_REAR_DOOR_SW     UNUSED//(UNUSED && ChangeVideoAv4Enable && (VIDEO_AV_ELSE))
#define TV3_FRONT_DOOR_SW    UNUSED//(LED_FRONT_DOOR_SW && ChangeVideoAv3Enable && (VIDEO_AV_FRO))
#define TV4_MIDDLE_DOOR_SW   UNUSED//(LED_MIDDLE_DOOR_SW && ChangeVideoAv2Enable && (VIDEO_AV_MID))



//�Ƿ���ģ��
#define  Has_Fmode       OFF
#define  Has_Rmode       OFF
#define  Has_Tmode       OFF
#define  Has_Amode       OFF

//����PWM�궨��




//3 ģ�����������PWM
#define MODLE_ALL_PWM          UNUSED

/**********��ѹ������������ʼ*************************/
#define BAR_12                 USED     //2 12BAR
#define BAR_10                 UNUSED   //2 10BAR
#define AIR_TYPE               VOLT      //2 ��ѹ���ź���Դ����ö��
#define Bar1Source             meter.MeterA13  //2 ��ѹһ��Դ
#define Bar2Source             meter.MeterA14  //2 ��ѹ����Դ
#define BCM_SENSOR_VOLT 	   10 	//2 ģ�鴫������λ10mvʱ����10��100mvʱ����1

/***********��ѹ��������������***********************/

/********ȼ�ʹ�������ʼ**********/

//ȼ����Դ
#define USEDFUEL      USED
#define FUELSOURCE    meter.MeterA2
// ȼ����ֵ0 - 180    0 - 100(�ٷֱ�)
#define FUELFULL_180  0
// ȼ����ֵ110 - 6    0 - 100(�ٷֱ�)   
#define FUELFULL_6    1
//ȼ�ʹ���������ѡ��
#define FUELTYPE      FUELFULL_6   

/********ȼ�ʹ���������**********/



/*********���ز��¶���**********************/
//�򿪺�
#define USEDVBATTEMP    USED
//�¶���Դ
#define VBATTEMPSOUTCE  meter.MeterA4

/******************************/

/*********���������¶ȶ���**********************/
//�򿪺�
#define USEDENGINETEMP  USED
//�¶���Դ
#define ENGINETEMPSOUTCE  meter.MeterA3

/******************************/

/*********���������¶ȶ���**********************/
//�򿪺�
#define USEDJIAREQITEMP  USED
//�¶���Դ
#define JIAREQITEMPSOUTCE  meter.MeterA15

/******************************/

//�ƹ�
#define  LED_LEFT_SW            LEFT_LED_SW
#define  LED_RIGHT_SW           RIGHT_LED_SW
#define  LED_HBEAM_SW           HBEAM_SW
#define  LED_LBEAM_SW           LBEAM_SW
#define  LED_FFOG_SW            FFOG_SW
#define  LED_RFOG_SW            METER_OPEN_E7 && METER_OPEN_E6                             
//��״ָ̬ʾ
#define  LED_FRONT_DOOR_SW      FRONT_DOOR_SW
#define  LED_MIDDLE_DOOR_SW     MID_DOOR_SW
#define  LED_ENG_DOOR_SW        ENG_DOOR_SW //�������տ���
//����������
#define  LED_FILTER_SW          PTC14
#define  LED_DRYER_SW           UNUSED                                            
#define  LED_PREHEAT_SW         ((jinqiyure&0x03) == 0x01)                                               
#define  LED_STOP_SW            UNUSED                                             
#define  LED_SERVICE_SW         UNUSED                                            
#define  LED_ENG_FAULT_SW       UNUSED                                            
#define  LED_ENG_TEMP_HOT_SW    ((WaterTem - 40)>103)
#define  LED_FUEL_LOW_SW        (fuel_percent < Ranyou_Alarm)
#define  LED_GENERATOR1_SW      PTB4//���ָʾ
#define  LED_GENERATOR2_SW      PTD16//���ָʾ
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
#define PULSE                    1750 //��������(C3���)
#define SUBI  	                 2000   //�ٱ�
#define CHESU_COEF               105  //����ϵ��
#define COEF                     100  //����ϵ��

#define AIR_ALARM                55
#define OIL_ALARM                105
#define SPEED_ALARM              79
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

#define Motor2_SOURCE            (&WaterTem)// 2
#define Motor3_SOURCE            (&engine_oil_press)// 3

#define Motor4_SOURCE            (&fuel_percent) // 4
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

#define LevelSet_D01_IN  HighEnable
#define LevelSet_D05_IN  HighEnable
#define LevelSet_D08_IN  HighEnable
#define LevelSet_D09_IN  HighEnable
#define LevelSet_D11_IN  HighEnable

#define LevelSet_B03_IN  HighEnable
#define LevelSet_B05_IN  HighEnable
#define LevelSet_B06_IN  HighEnable
#define LevelSet_B10_IN  HighEnable
#define LevelSet_B12_IN  HighEnable

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
#define  KEY_EMG			    (PTA8&&PTA9)             //Σ����������
#define  KEY_CHARGE             UNUSED                   //��绽�ѿ���
#define  KEY_POWER			    UNUSED					//�ܵ�Դ����
#define  SYSTEM_POW        	    (KEY_ON||KEY_ACC)     //ϵͳ��Դ����
#define  WAKE_UP_SW			    (KEY_ON||KEY_ACC||KEY_ST||KEY_EMG||KEY_POWER) //�ɻ��ѿ���
//�ƹ�
#define  RIGHT_LED_SW           PTA9  //��ת���
#define  LEFT_LED_SW            PTA8  //��ת���
#define  BACKLIGHT_SW           PTB6  //С�ƿ���
#define  HBEAM_SW			    PTB3  //Զ��
#define  LBEAM_SW			    PTB12 //����
#define  FFOG_SW				PTB5  //ǰ���
#define  RFOG_SW				PTB8  //�����

//ɲ��
#define BREAK_CONTION           UNUSED
#define BREAK_SW                PTB10
#define ELEC_BREAK              UNUSED                                //ɲ������
#define BREAK_ALL               (BREAK_SW||ELEC_BREAK)
#define PARK_SW				    (PTB7)  //��ɲ
//��λ

#define D_SW   				    UNUSED
#define NULL_SW                 UNUSED
#define REVERSE_GEAR_SW         PTD8

//��״̬)
#define ENG_DOOR_SW			    UNUSED
#define FRONT_DOOR_SW           PTD1
#define MID_DOOR_SW			    UNUSED
#define FRONT_DOOR_OPEN_SW      UNUSED
#define FRONT_DOOR_CLOSE_SW     UNUSED
#define MID_DOOR_OPEN_SW        UNUSED
#define MID_DOOR_CLOSE_SW       UNUSED
//ǰ�ŷ��п���
#define FRONT_DOOR_FANGJIA_SW   UNUSED 
//���ŷ��п���
#define MID_DOOR_FANGJIA_SW     UNUSED
//��ȫ��
#define SAFE_DOOR_SW		    PTC13 

//Ӧ����
#define EMERGENCY_INSIDE_SW 	UNUSED
#define EMERGENCY_OUTSIDE_SW 	UNUSED
#define EMERGENCY_SW 		    PTD2
#define EMERGENCY_OUTSIDE_GAI_SW 	UNUSED

#define EMERGENCY_FRONT_SW 	    UNUSED  //ǰ��Ӧ����
#define EMERGENCY_MID_SW 	    UNUSED  //����Ӧ����
#define EMERGENCY_ALL  EMERGENCY_INSIDE_SW||EMERGENCY_OUTSIDE_SW||EMERGENCY_SW||EMERGENCY_FRONT_SW||EMERGENCY_MID_SW


//���ÿ���
#define PASSAGE_GET_OUT_SW      UNUSED//�¿�����
#define WATER_SW			    PTB2//ˮλ��
#define WATER_AIR_SW			UNUSED//�յ�ˮλ��
#define WATER_CAN_SW			UNUSED//����ˮλ��


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
#define PLANT_LEFT_F            UNUSED//��ǰ��Ƭ
#define PLANT_RIGHT_F           UNUSED//��ǰ��Ƭ
#define PLANT_LEFT_R            UNUSED //�����Ƭ
#define PLANT_RIGHT_R           UNUSED //�Һ���Ƭ
#define PLANT_LEFT  			(!PTC10)//��ǰ��Ƭ
#define PLANT_RIGHT 			(!PTC12)//��ǰ��Ƭ

//Ħ��Ƭ����
#define PLANT_ALL               (PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R||PLANT_LEFT||PLANT_RIGHT) 


/************************ROLL ALARM***************************/
#define DEFINE_TIP_LEAST_VOLT   (Vbat < LEAST_VOLTAGE)                             
#define OIL_LOW                 ((4*engine_oil_press) < 70)
#define DEFINE_TIP_OIL_LOW		(OIL_LOW) && (eng_speed>0)     
#define DEFINE_TIP_AIR_LOW 		(AIR1_LOW || AIR2_LOW || DOOR_AIRLOW_SW || BREAK_AIRLOW_SW||CAN_AIR_LOW||AIRLOW_SW_3)		       
#define DEFINE_TIP_SPEED		((veh_speed_display >= (Speed_Alarm*10)))                   //����                                  
#define DEFINE_TIP_WATER_LOW    UNUSED//WATER_SW ||WATER_AIR_SW||WATER_CAN_SW//ˮλ��                                        
#define DEFINE_TIP_PLANT_ALARM  (PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R)//Ħ��Ƭ����
#define DEFINE_TIP_ENGINE_WATERTEP_HIGH UNUSED
/***********************************************************/ 

//���࿪��
#define CANJI_TABAN 		    UNUSED

#define SAFE_DOOR_ALARM_SW      UNUSED
#define DRIVER_SW  			    UNUSED//˾����
#define BOX_LINGT_SW            UNUSED //���
#define TV_SW				    UNUSED
#define LCD_SW				    UNUSED
#define FAN_SW				    UNUSED
#define ROAD_LIGHT 			    UNUSED  //������
#define LUPAI_LIGHT 			UNUSED  //·�Ƶ�
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

#define SEATBELT_NO_SW          (PTD3 && KEY_ON)  //��ȫ��δϵ����
#define DRIVER_AWAY_SW          UNUSED //˾����������
#define DRIVER_AWAY_ALARM       UNUSED

//����
#define DEFROST_SW			    UNUSED//��˪1
#define DEFROST_SW_2			UNUSED//��˪2
#define WARM_AIR_BLOWER_SW	    UNUSED//ů���1
#define WARM_AIR_BLOWER_SW_2	UNUSED//ů���2
#define ASR_SW  			    PTD12
#define ABS_SW				    PTD7//ABS_SW1
#define BUZZ_SW				    UNUSED//���ȿ���
//----У�����ⶨ��---//
#define HUANSUQI_GZ				PTD5
#define XIAOCHE_FLAG			PTD9
#define TINGCHE_XINHAO			PTD11


#define STOP_MARK               ((ID_0CFF0B4A_data2&0x0c) == 0x08)                                             //ready
#define START_MARK              ((ID_0CFF0B4A_data2&0x0c) == 0x0c)                                             //ready
#define READY                   ((ID_0CFF0B4A_data2&0x0c) == 0x04)                                             //ready
#define fault                   ((ID_0CFF0B4A_data2&0x02) == 0x02)                                             //��������
#define charge_mark_1           ((battery_1_data6&0x08) == 0x08)                                             //�������ͼ��
#define charge_line             ((Control_information_data7&0x02) == 0x02)  

#define ITSR_MARK 				((_18FF0498_data7&0x30)==0x10)
#define ITSR_BLINKER 			((_18FF0498_data7&0xC0)==0x40)


//-----------------------������������غ궨��--------------------------//
/*#define ENG_ERR_OFF  	 		((_18FD0700[0] & 0x30) == 0)
#define ENG_ERR_ON  	 		((_18FD0700[0] & 0x30) == 0x10)

#define DRIVER_ERR_OFF  	 	((_18FD0700[0] & 0x0C) == 0)
#define DRIVER_ERR_ON  	 		((_18FD0700[0] & 0x0C) == 0x04)

#define MIL_OFF  	 			((_18FD0700[0] & 0xC0) == 0)
#define MIL_ON  	 			((_18FD0700[0] & 0xC0) == 0x40)*/

#define DPF_OFF_R  	 			((DPF_light&0X07)==0X00)
#define DPF_ON_Y 		 		((DPF_light&0X07)==0X01)
#define DPF_BLINKER_Y  		    ((DPF_light&0X07)==0X04)
#define DPF_ON_R				((DPF_light&0X07)==0X02)

//#define DPF_BAN_OFF				((DPF_ban_light&0x03)==0X00)
#define DPF_BAN_ON				((DPF_ban_light&0x03)==0X01)
//----------------------------ABS-------------------------------------//
//ASR ����           
#define ASR_SW_Y             (((add1[5].byte&0XC0) == 0X40) && ((add1[2].byte&0X0C) == 0X04)) 
//ASR ��˸
#define ASR_SW_BLINK         ((TestBits(add1[0].byte,0,2,1) && TestBits(add1[5].byte,6,2,1))||(TestBits(add1[0].byte,2,2,1) && TestBits(add1[5].byte,6,2,1)))   
//ASR ���ܹر�
#define ASR_STOP             (((add1[2].byte&0X0C) == 0X04) &&  ((add1[5].byte&0XC0) == 0X40))

#define EBS_SW_R           	TestBits(add1[2].byte,2,2,1)// �ϵ��Լ�Ҳ������ 20200703
#define EBS_SW_Y           ((add1[5].byte&0X30) == 0X10)

//ESC���� ����
#define ESC_FAULT         ((TestBits(add3[0].byte,0,2,1) && TestBits(add3[0].byte,2,2,0)) && \
	                       (TestBits(add1[2].byte,2,2,0)))
//ESC ��������˸
#define ESC_NORMAL        ((TestBits(add3[0].byte,0,2,1) && TestBits(add3[0].byte,2,2,1)))
// ABS ���� 
#define ABS_SW1			     (((add1[5].byte&0x30) == 0x10) && ((add1[5].byte&0x03) == 0x00))

#define ADD_E_BREAK1       ((add1[0].byte&0XC0)==0X40)
#define ADD_E_BREAK2       ((add2[1].byte&0X03)==0X01)
#define ESC_BREAK          (ADD_E_BREAK1||ADD_E_BREAK2)//ɲ������  �����ƶ���

#define EBS_SW_R           TestBits(add1[2].byte,2,2,1)// �ϵ��Լ�Ҳ������ 20200703
#define EBS_SW_Y           ((add1[5].byte&0X30) == 0X10)

//--------------------------------------------------------------------//
#define TBOX_TIMEOUT		(KEY_ON && PAIFANG_LIXIAN)
#define TBOX_GUZHANG		(KEY_ON && PAIFANG_START && ((CanData[ID(0x18FF0257)][BYTE1] & 0x03) == 0x01))
#define TBOX_TONGXUN		(KEY_ON && PAIFANG_START && ((CanData[ID(0x18FF0257)][BYTE1] & 0x03) == 0x02))
#define TBOX_DINGWEI		(KEY_ON && PAIFANG_START && ((CanData[ID(0x18FF0257)][BYTE1] & 0x03) == 0x03))

//��ǰ�궨��
#define fault1                    ((Control_information_data1&0x80) == 0x80)
#define fault2                    ((Control_information_data1&0x40) == 0x40)
#define fault3                    ((Control_information_data1&0x20) == 0x20)
#define fault4                    ((Control_information_data1&0x10) == 0x10)
#define fault5                    ((Control_information_data1&0x08) == 0x08)
#define fault6                    ((Control_information_data1&0x04) == 0x04)
#define fault7                    ((Control_information_data1&0x02) == 0x02)
#define fault8                    ((Control_information_data1&0x01) == 0x01)

//������
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





















