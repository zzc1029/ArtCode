/*
 * config.h
 *
 *  Created on: 2021-7-27
 *      Author: ART
 */

#ifndef _CONFIG_H
#define _CONFIG_H





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


//���Ͻ����������ѯ��ʾ��ʱ����3��
#define GUZHAGN_LOOP USED
//������������256��  ����������
#define MAX_MA      100 


/*��ε�λ����*****************/
#define WIPER_INT_SW	(PTB7) //��Ъ
#define WIPER_LO_SW     (PTB8) //���ٵ�
#define WIPER_HI_SW     (PTB2) //���ٵ�
#define WIPER_MI_SW		(PTB1) //��ˮ����
//��ˢ���ܴ򿪹ر�
#define SUPPORT_WIPER 	USED	
/*��ε�λ����End*****************/

//����������ON����λ�ر�ʱ������Э����ʾ��ɲͼ��5����
#define ANKAI_ADD_SCREEC_FOR_PARK      USED
#define NO_PARK                        Ankai_Add_190703.bit.b5
//����
#define YOUMEN_ENABLE  	               TestBitTrue(_0CFF0B4A[1],3)
//EP�����
#define EP_ENABLE                      TestBitTrue(_18FF0152[1],0)

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
#define SENDSPEED_ENABLE	  USED  

//����ͷ����
#define TV1_REVERSE_SW       UNUSED//(REVERSE_GEAR_SW && ChangeVideoAv1Enable && (VIDEO_AV_GRAR))
#define TV2_REAR_DOOR_SW     UNUSED//(UNUSED && ChangeVideoAv4Enable && (VIDEO_AV_ELSE))
#define TV3_FRONT_DOOR_SW    UNUSED//(LED_FRONT_DOOR_SW && ChangeVideoAv3Enable && (VIDEO_AV_FRO))
#define TV4_MIDDLE_DOOR_SW   UNUSED//(LED_MIDDLE_DOOR_SW && ChangeVideoAv2Enable && (VIDEO_AV_MID))



//�Ƿ���ģ��
#define  Has_Fmode       ON
#define  Has_Rmode       OFF
#define  Has_Tmode       ON
#define  Has_Amode       OFF

//����PWM�궨��




#define ANKAI_ABS		UNUSED

//3 ģ�����������PWM
#define MODLE_ALL_PWM          UNUSED

/**********��ѹ������������ʼ*************************/

#define USEDAIR               UNUSED

#define BAR_12                 USED     //2 12BAR
#define BAR_10                 UNUSED   //2 10BAR
#define AIR_TYPE               VOLT      //2 ��ѹ���ź���Դ����ö��
#define Bar1Source             meter.MeterA13  //2 ��ѹһ��Դ
#define Bar2Source             meter.MeterA14 //2 ��ѹ����Դ
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

/*********ȼ�ͼ��������¶���**********************/
//�򿪺�
#define USEDRANYOUTEMP    UNUSED
//�¶���Դ
#define RANYOUTEMPSOUTCE  meter.MeterA3

/******************************/


/*********���ز��¶���**********************/
//�򿪺�
#define USEDVBATTEMP    USED
//�¶���Դ
#define VBATTEMPSOUTCE bcm_senor2_f //meter.MeterA4

/******************************/


//�ƹ�
#define  LED_LEFT_SW            LEFT_LED_SW
#define  LED_RIGHT_SW           RIGHT_LED_SW
#define  LED_HBEAM_SW           LED_HBEAM_SW_FEEDBACK
#define  LED_LBEAM_SW           LED_LBEAM_SW_FEEDBACK
#define  LED_FFOG_SW            LED_FFOG_SW_FEEDBACK
#define  LED_RFOG_SW            LED_RFOG_SW_FEEDBACK
//��״ָ̬ʾ
#define  LED_FRONT_DOOR_SW      FRONT_DOOR_SW
#define  LED_MIDDLE_DOOR_SW     MID_DOOR_SW
#define  LED_ENG_DOOR_SW        ENG_DOOR_SW
//����������
#define  LED_FILTER_SW          UNUSED
#define  LED_DRYER_SW           UNUSED                                            
#define  LED_PREHEAT_SW         UNUSED                                            
#define  LED_STOP_SW            UNUSED                                             
#define  LED_SERVICE_SW         UNUSED                                            
#define  LED_ENG_FAULT_SW       UNUSED                                            
#define  LED_ENG_TEMP_HOT_SW    UNUSED
#define  LED_FUEL_LOW_SW        UNUSED
#define  LED_GENERATOR1_SW      UNUSED//���ָʾ
#define  LED_GENERATOR2_SW      UNUSED//���ָʾ
#define  LED_GENERATOR_SW       UNUSED//���ָʾ
//һ��������������õ���Ŀ
#define  LED_ABS_SW             ABS_SW
#define  LED_BATTERY_LOW_SW     ((Vbat < 200)||(Vbat > 320))       
#define  LED_OIL_LOW_SW         UNUSED                                        
#define  LED_POWER_SW           SYSTEM_POW                                       
#define  LED_AIR_LOW_SW         DEFINE_TIP_AIR_LOW                                
#define  LED_PARK_SW            PARK_SW
/*******************************************************/
#define  ALL_DOOR			(LED_FRONT_DOOR_SW || LED_MIDDLE_DOOR_SW)



/*********�Ǳ����ò���****************/
#define PULSE                    1450  //��������(C3���)
#define SUBI  	                 1800   //�ٱ�

#define COEF                     100  //����ϵ��

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

#define Motor4_SOURCE            (&veh_soc) // 4
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
#define  KEY_ACC			    PTA7                    //ACC��
#define  KEY_ST				    UNUSED 			         //start��
#define  KEY_EMG			    (PTA8)                  //Σ����������
#define  KEY_CHARGE             PTA9                   //��绽�ѿ���
#define  KEY_POWER			    PTA10//�ܵ�Դ����
#define  SYSTEM_POW        	    (KEY_ON||KEY_ACC)     //ϵͳ��Դ����
#define  WAKE_UP_SW			    (KEY_ON||KEY_ACC||KEY_ST||KEY_EMG||KEY_POWER) //�ɻ��ѿ���
//�ƹ�
#define  RIGHT_LED_SW           PTD9  //��ת���
#define  LEFT_LED_SW            PTD8  //��ת���
#define  BACKLIGHT_SW           PTB6  //С�ƿ���
#define  HBEAM_SW			    PTB3  //Զ��
#define  LBEAM_SW			    PTB12 //����
#define  FFOG_SW				PTB5  //ǰ���
#define  RFOG_SW				PTB11  //�����

//ɲ��
#define BREAK_CONTION           TestBitTrue(Control_information_data6,3)
#define BREAK_SW                F_SW_P17
#define ELEC_BREAK              (F_SW_P39 || TestBitTrue(Control_information_data7,7))	                                //ɲ������
#define BREAK_ALL               (BREAK_SW||BREAK_CONTION||ESC_BREAK)
#define PARK_SW				    (F_SW_P32|| TestBitTrue(CanData[ID(0x0CFF0A4A)][6],7))  //��ɲ
//��λ

#define D_SW   				    TestBitTrue(Control_information_data6,5)
#define NULL_SW                 TestBitTrue(Control_information_data6,4)
#define REVERSE_GEAR_SW         (TestBitTrue(Control_information_data6,6))

//��״̬)
#define ENG_DOOR_SW			    UNUSED
#define FRONT_DOOR_SW           T_SW_P17
#define MID_DOOR_SW			    UNUSED
#define FRONT_DOOR_OPEN_SW      PTD6
#define FRONT_DOOR_CLOSE_SW     PTD1
#define MID_DOOR_OPEN_SW        UNUSED
#define MID_DOOR_CLOSE_SW       UNUSED
//ǰ�ŷ��п���
#define FRONT_DOOR_FANGJIA_SW   UNUSED 
//���ŷ��п���
#define MID_DOOR_FANGJIA_SW     UNUSED

//Ӧ����
#define EMERGENCY_FRONT_INSIDE_SW 		UNUSED
#define EMERGENCY_FRONT_OUTSIDE_SW 		UNUSED
#define EMERGENCY_MIDDLE_INSIDE_SW 		UNUSED
#define EMERGENCY_MIDDLE_OUTSIDE_SW 	UNUSED

#define EMERGENCY_DRIVER_SW				UNUSED


#define EMERGENCY_INSIDE_SW 	    	T_SW_P21//����Ӧ����
#define EMERGENCY_OUTSIDE_SW 	    	T_SW_P22  //����Ӧ����
#define EMERGENCY_ALL  					(EMERGENCY_INSIDE_SW||EMERGENCY_OUTSIDE_SW||EMERGENCY_DRIVER_SW)


//���ÿ���
#define PASSAGE_GET_OUT_SW      (F_SW_P33)//�¿�����
#define WATER_SW			    (T_SW_P32)//ˮλ��
#define WATER_RANYOU_SW			(UNUSED)//ˮλ2��
#define WATER_AIR_SW			(UNUSED)//�յ�ˮλ��
#define WATER_CAN_SW			(((can_water_low&0x3f) == 29)||((can_water_low&0x3f) == 50))//����ˮλ��


#define AIRLOW_FRONTDOOR_SW 		 	UNUSED
#define AIRLOW_MIDDOOR_SW 		 		UNUSED


#define AIR1_LOW				((veh_bar1<Air_Alarm) && USEDAIR)
#define AIR2_LOW				((veh_bar2<Air_Alarm) && USEDAIR)
#define AIR_LOW					UNUSED
#define CAN_AIR_LOW				TestBitTrue(Control_information_data7,2)

//Ħ��Ƭ
#define PLANT_LEFT_F            UNUSED//(!F_SW_P36)//��ǰ��Ƭ
#define PLANT_RIGHT_F           UNUSED//(!PTB6)//��ǰ��Ƭ
#define PLANT_LEFT_R            UNUSED//(!PTB7) //�����Ƭ
#define PLANT_RIGHT_R           UNUSED//(!PTB8) //�Һ���Ƭ

#define PLANT_LEFT              (!F_SW_P36)
#define PLANT_RIGHT             (!F_SW_P37)

//Ħ��Ƭ����
#define PLANT_ALL               (PLANT_LEFT||PLANT_RIGHT||PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R) 


/************************ROLL ALARM***************************/
#define DEFINE_TIP_LEAST_VOLT   (Vbat < LEAST_VOLTAGE)                             
#define OIL_LOW                 UNUSED
#define DEFINE_TIP_OIL_LOW		(OIL_LOW) && (eng_speed>0)     
#define DEFINE_TIP_AIR_LOW 		(AIR1_LOW || AIR2_LOW ||AIR_LOW||CAN_AIR_LOW)		       
#define DEFINE_TIP_SPEED		((veh_speed_display >= (Speed_Alarm*10)))                   //����                                  
#define DEFINE_TIP_WATER_LOW    (WATER_SW ||WATER_RANYOU_SW||WATER_AIR_SW||WATER_CAN_SW)//ˮλ��                                        
#define DEFINE_TIP_PLANT_ALARM  (PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R)//Ħ��Ƭ����
#define DEFINE_TIP_ENGINE_WATERTEP_HIGH UNUSED
/***********************************************************/ 

//���࿪��
#define CANJI_TABAN 		    UNUSED
#define CHAOSU 				    UNUSED

#define DRIVER_SW  			    PTD4//˾����
#define BOX_LINGT_SW_1          UNUSED //���1
#define BOX_LINGT_SW_2          UNUSED  //���1
#define TV_SW				    UNUSED
#define LCD_SW				    UNUSED
#define FAN_SW				    UNUSED
#define ROAD_LIGHT 			    UNUSED  //������
#define LUPAI_LIGHT 			PTD2  //·�Ƶ�
#define AIR_COMPRESSOR_ERR_SW	UNUSED
#define INSIDE_LED_SW_1         UNUSED //���ڵ�1 or ����1
#define INSIDE_LED_SW_2		    PTD11 //���ڵ�2 or ����2

#define AC_CHARGE_OVER_SW	    UNUSED
#define ENG_TEMP_ALARM_SW	    UNUSED  //���������±���
#define BAT_TEMP_ALARM_SW	    UNUSED  //��ز��±���
#define ENG_DOOR_LIGHT_SW	    UNUSED //��ֵƿ���
#define XINGLICANG_LIGHT_SW	    UNUSED //����ֵƿ���

#define BENG_SW  			    UNUSED  //ů��ˮ�ÿ���
#define EMENG_LIGHT_SW		    UNUSED  //Ӧ����������

#define SEATBELT_NO_SW          (F_SW_P35 && KEY_ON)  //��ȫ��δϵ����
#define DRIVER_AWAY_SW          ((!PTB10) && KEY_ON && (!PARK_SW)) //˾����������
#define DRIVER_AWAY_ALARM       UNUSED
#define DIAN_NUANFENG			UNUSED
//����
#define DEFROST_SW			    UNUSED//��˪1
#define DEFROST_SW_2			UNUSED//��˪2
#define WARM_AIR_BLOWER_SW	    UNUSED//ů���1
#define WARM_AIR_BLOWER_SW_2	UNUSED//ů���2
#define ASR_SW  			    PTD14
#define ABS_SW				    PTD16//(TestBits(_18F0010B[5],0,2,0x00)&&TestBits(_18F0010B[5],4,2,0x01))
#define SAFE_DOOR_SW		    UNUSED //��ȫ��
#define BUZZ_SW				    PTD15//���ȿ���
#define WAITUI_CHUANG			UNUSED//���ƴ�

#define STOP_MARK               ((ID_0CFF0B4A_data2&0x0c) == 0x08)                                             //ready
#define START_MARK              ((ID_0CFF0B4A_data2&0x0c) == 0x0c)                                             //ready
#define READY                   ((ID_0CFF0B4A_data2&0x0c) == 0x04)                                             //ready
#define fault                   ((ID_0CFF0B4A_data2&0x02) == 0x02)                                             //��������
#define charge_mark_1           ((battery_1_data6&0x08) == 0x08)                                             //�������ͼ��
#define charge_line             ((Control_information_data7&0x02) == 0x02)  

#define ITSR_MARK 				((_18FF0498_data7&0x30)==0x10)
#define ITSR_BLINKER 			((_18FF0498_data7&0xC0)==0x40)


//--------------------abs��ر��ĺ궨��---------------//
#define ASR_SW_Y             ((_18F0010B[5]&0XC0) == 0X40)
#define ASR_SW_BLINK         ((_18F0010B[0]&0X03) == 0X01) ||((_18F0010B[0]&0X0C) == 0X04)

#define ADD_E_BREAK1       ((_18F0010B[0]&0XC0)==0X40)
#define ADD_E_BREAK2       ((_18FDC40B[1]&0X03)==0X01)
#define ESC_BREAK          (ADD_E_BREAK1||ADD_E_BREAK2)//ɲ������  �����ƶ���

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





















