/*
 * config.h
 *
 *  Created on: 2021-11-29
 *      Author: ART
 */

#ifndef CONFIG_H_
#define CONFIG_H_

//�����Ƿ�����485����
#define RS485  UNUSED

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
#define PARANUM    1
//---------------------------------------------------------------

#define ISRELEASE  USED
#define WATCHDOGEN USED

//��Ҫ��ʾ�Ľ���
#define DISPLAYTASKNUM 5





#define POWER_DETECT   (PTA7 || PTA8 || PTA9 || PTA10 || PTE2)


#define OFF     0
#define ON      1
#define UNUSE   0
#define USED    1
#define UNUSED  0

#define HighEnable	             0   //����Ч
#define LowEnable	             1   //����Ч

#define PWMEable                 1

//�Ǳ�صس�ʼ��
#define LevelSet_E02_IN          HighEnable
#define LevelSet_A07_IN          HighEnable
#define LevelSet_A08_IN          HighEnable
#define LevelSet_A09_IN          HighEnable
#define LevelSet_A10_IN          HighEnable
#define LevelSet_A19_IN          HighEnable


//ǰģ��
#define LevelSet_F_A17_IN        HighEnable
//#define LevelSet_F_A22_IN      HighEnable
#define LevelSet_F_A39_IN        HighEnable

//��ģ��
#define LevelSet_R_A17_IN        HighEnable
//#define LevelSet_R_A22_IN      HighEnable
#define LevelSet_R_A39_IN        HighEnable

//��ģ��
#define LevelSet_T_A17_IN        HighEnable
//#define LevelSet_T_A22_IN      HighEnable
#define LevelSet_T_A39_IN        HighEnable


//����ģ��
#define LevelSet_A_A17_IN        HighEnable
//#define LevelSet_T_A20_IN      HighEnable
#define LevelSet_A_A39_IN        HighEnable


/***ģ�⴫�����˿����������Լ�����������ѡ��******/

//��ѹ�����ʶ
#define VOLT  1
#define RES   2

// A2��������
#define A2_PULL     510/2
// A3��������
#define A3_PULL     510/2
// A4��������
#define A4_PULL     510/2
// A13��������
#define A13_PULL    510/2
// A14��������
#define A14_PULL    510/2

#define A2_TYE     RES
#define A3_TYE     VOLT
#define A4_TYE     VOLT
#define A13_TYE    VOLT
#define A14_TYE    VOLT
/**********************/


/*********�Ǳ����ò���****************/
#define PULSE                    1000 //��������(C3���)
#define SUBI  	                 2100   //�ٱ�
#define COEF                     102  //����ϵ��

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
#define MILE_COME_FROM           METRE_MILE  //�����ݴ洢������ö��



/**********��ѹ������������ʼ*************************/
#define BAR_12                  USED     //2 12BAR
#define BAR_10                  UNUSED   //2 10BAR
#define AIR_TYPE                VOLT      //2 ��ѹ���ź���Դ����ö��
#define Bar1Source              meter.MeterA13
#define Bar2Source              meter.MeterA14
#define BCM_SENSOR_VOLT 	   10 	//2 ģ�鴫������λ10mvʱ����10��100mvʱ����1

/***********��ѹ��������������***********************/

/********ȼ�ʹ�������ʼ**********/

//ȼ����Դ
#define USEDFUEL      UNUSED
#define FUELSOURCE    bcm_senor1_r//meter.MeterA2
// ȼ����ֵ0 - 180    0 - 100(�ٷֱ�)
#define FUELFULL_180  0
// ȼ����ֵ110 - 6    0 - 100(�ٷֱ�)   
#define FUELFULL_6    1
//ȼ�ʹ���������ѡ��
#define FUELTYPE      FUELFULL_180   

/********ȼ�ʹ���������**********/


/*********���ز��¶���**********************/
//�򿪺�
#define USEDVBATTEMP    USED
//�¶���Դ
#define VBATTEMPSOUTCE  bcm_senor2_r

/******************************/

#define SUPPORT_WIPER 		USED// ��ˢ���ܴ򿪹ر�

/*��ε�λ����*****************/
#define WIPER_INT_SW	(SYSTEM_POW&&F_SW_P21) //��Ъ
#define WIPER_LO_SW     (SYSTEM_POW&&F_SW_P36) //���ٵ�
#define WIPER_HI_SW     (SYSTEM_POW&&F_SW_P22) //���ٵ�
#define WIPER_MI_SW		(SYSTEM_POW&&F_SW_P35) //��ˮ����
/*��ε�λ����End*****************/


//���ý��濪�أ�ON �� OFF �ر�
#define ChangeLiChengEnable   ON  //�������
#define ChangeSubiEnable      ON  //�����ٱ�
#define ChangePulseEnable     ON  //���ð�������
#define ChangeCoefEnable      ON  //������ʾ�ٶȵı���

#define ChangeTimeEnable      ON   //����ʱ��
#define ChangeBLEnable        ON   //���ñ���
#define ChangeBuzzEnable      ON   //���÷�����
//----------------��ȼ�ӷ������ú궨��--------
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


#define KEY_ON				PTE2				  //On��
#define KEY_ACC				PTA7                  //ACC��
#define KEY_ST				PTA10                  //start��
#define KEY_EMG				(PTA8)                 //Σ����������
#define KEY_CHARGE          PTA9                 //��绽�ѿ���
#define KEY_POWER			UNUSED//�ܵ�Դ����
#define LEAST_VOLTAGE       160
#define DEFINE_TIP_LEAST_VOLT   (Vbat < LEAST_VOLTAGE)   


#define SYSTEM_POW        	(KEY_ON||KEY_ACC)     //ϵͳ��Դ����
#define WAKE_UP_SW			(KEY_ON||KEY_ACC||KEY_ST||KEY_EMG||KEY_POWER) //�ɻ��ѿ���
//�ƹ�
#define RIGHT_LED_SW        PTD8//��ת���
#define LEFT_LED_SW         PTD7  	//��ת���
#define BACKLIGHT_SW        PTD11//С�ƿ���
#define HBEAM_SW			PTD10   	//Զ��
#define LBEAM_SW			PTD9 	//����
#define FFOG_SW				PTD15//TestBitTrue(CanData[ID(0x18FF9117)][BYTE1],4)//ǰ���
#define RFOG_SW				PTD13  	//TestBitTrue(CanData[ID(0x18FF9117)][BYTE1],3)//�����  //reset switch
//ɲ��
#define BREAK_SW            (R_SW_P18)
#define ELEC_BREAK          TestBitTrue(CanData[ID(0x18FFEA97)][1],7)	
#define BREAK_ALL           (BREAK_SW||ELEC_BREAK)
#define PARK_SW				R_SW_P20//��ɲ

//��λ
#define D1_SW   				TestBits(CanData[ID(0x18FFEA97)][7],0,3,1)//((VCU_INFO_1[7].byte & 0X07) == 0X1)
#define D2_SW   				TestBits(CanData[ID(0x18FFEA97)][7],0,3,2)//((VCU_INFO_1[7].byte & 0X07) == 0X2)
#define D3_SW   				TestBits(CanData[ID(0x18FFEA97)][7],0,3,3)//((VCU_INFO_1[7].byte & 0X07) == 0X3)
#define D4_SW   				TestBits(CanData[ID(0x18FFEA97)][7],0,3,4)//((VCU_INFO_1[7].byte & 0X07) == 0X4)
#define D5_SW   				TestBits(CanData[ID(0x18FFEA97)][7],0,3,5)//((VCU_INFO_1[7].byte & 0X07) == 0X5)
#define D6_SW   				TestBits(CanData[ID(0x18FFEA97)][7],0,3,6)//((VCU_INFO_1[7].byte & 0X07) == 0X6)


#define D_SW   				    TestBits(CanData[ID(0x18FFEA97)][0],0,3,3)
#define NULL_SW                 TestBits(CanData[ID(0x18FFEA97)][0],0,3,2)
#define REVERSE_GEAR_SW         TestBits(CanData[ID(0x18FFEA97)][0],0,3,1)

//��״̬)
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

//���ÿ���
#define PASSAGE_GET_OUT_SW  (T_SW_P22)//�¿�����

#define WATER_BATT_SW           F_SW_P37
#define WATER_MOTOR_SW          T_SW_P19

#define DEFINE_TIP_WATER_LOW   (WATER_BATT_SW||WATER_MOTOR_SW) 

//����
#define DEFROST_SW			    UNUSE//��˪1
#define DEFROST_SW_2			UNUSE//��˪2
#define WARM_AIR_BLOWER_SW	    UNUSE//ů���1
#define WARM_AIR_BLOWER_SW_2	UNUSE//ů���2
#define ASR_SW  				PTD16
#define ABS_SW					PTD14
#define SAFE_DOOR_SW			UNUSE //��ȫ��
#define BUZZ_SW					UNUSE//���ȿ���

#define PLANT_LEFT_F            (!R_SW_P21)//��ǰ��Ƭ
#define PLANT_RIGHT_F           (!R_SW_P36)//��ǰ��Ƭ
#define PLANT_LEFT_R            (!R_SW_P22) //�����Ƭ
#define PLANT_RIGHT_R           (!R_SW_P37) //�Һ���Ƭ

#define PLANT_ALL			(PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R)


#define EMERGENCY_OUTSIDE_GAI_SW 		R_SW_P32
#define EMERGENCY_OUTSIDE_XUANZHUAN_SW 	R_SW_P33
#define EMERGENCY_INSIDE_GAI_SW 		T_SW_P34
#define EMERGENCY_INSIDE_XUANZHUAN_SW 	T_SW_P20

#define EMERGENCY_ALL		(EMERGENCY_OUTSIDE_GAI_SW||EMERGENCY_OUTSIDE_XUANZHUAN_SW||EMERGENCY_INSIDE_GAI_SW||EMERGENCY_INSIDE_XUANZHUAN_SW)



#define AIR1_LOW				(veh_bar1<Air_Alarm)
#define AIR2_LOW				(veh_bar2<Air_Alarm)
#define BREAK_AIRLOW_SW		 	UNUSE     //ɲ����ѹ��

#define BOX_LINGT_SW         	UNUSE //���
#define TV_SW				 	F_SW_P32
#define INSIDE_LED_SW_1       	UNUSE //���ڵ�1 or ����1
#define INSIDE_LED_SW_2		  	UNUSE //���ڵ�2 or ����2
#define FAN_SW				 	F_SW_P19
#define DRIVER_LIGHT_SW		  	F_SW_P20

#define AC_CHARGE_OVER_SW	 	UNUSE
#define ENG_TEMP_ALARM_SW	  	UNUSE  //���������±���
#define BAT_TEMP_ALARM_SW	  	UNUSE  //��ز��±���
#define ENG_DOOR_LIGHT_SW	  	UNUSE //��ֵƿ���
#define XINGLICANG_LIGHT_SW	  	UNUSE //����ֵƿ���

#define BENG_SW  			  	UNUSE  //ů��ˮ�ÿ���
#define EMENG_LIGHT_SW		  	UNUSE//Ӧ����������

#define SEATBELT_NO_SW         (R_SW_P41 && KEY_ON)  //��ȫ��δϵ����
#define DRIVER_AWAY_SW      	(!R_SW_P34) //˾����������
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

//����ͷ����
#define TV1_REVERSE_SW       (UNUSED && ChangeVideoAv1Enable && (VIDEO_AV_GRAR))
#define TV2_REAR_DOOR_SW     (UNUSED)//(UNUSE && ChangeVideoAv4Enable && (VIDEO_AV_ELSE))
#define TV3_FRONT_DOOR_SW    (UNUSED && ChangeVideoAv3Enable && (VIDEO_AV_FRO))
#define TV4_MIDDLE_DOOR_SW   (UNUSED && ChangeVideoAv2Enable && (VIDEO_AV_MID))




//�������Ƭȡģ���������״̬
#include "Artpatch.h"


#define  LED_LEFT_SW_FEEDBACK      F_OUT_P8
//��ת��
#define  LED_RIGHT_SW_FEEDBACK     F_OUT_P10
//Զ���
#define  LED_HBEAM_SW_FEEDBACK     B40_FRONT_FEEDBACK(A14) && B40_FRONT_FEEDBACK(A42)
//1 �����
#define  LED_LBEAM_SW_FEEDBACK     B40_FRONT_FEEDBACK(A3)&& B40_FRONT_FEEDBACK(A11)
//1 ǰ���
#define  LED_FFOG_SW_FEEDBACK      B40_FRONT_FEEDBACK(A4)&& B40_FRONT_FEEDBACK(A6)
//1�����
#define  LED_RFOG_SW_FEEDBACK      B40_TOP_FEEDBACK(A42)
//1 С��
#define  LED_BACKLIGHT_SW_FEEDBACK (B40_REAR_FEEDBACK(A14))     
//1 ɲ����
#define  LED_BREAK_SW_FEEDBACK     (B40_TOP_FEEDBACK(A3))

/************************ROLL ALARM***************************/
#define DEFINE_TIP_LEAST_VOLT  (Vbat < LEAST_VOLTAGE)                             
#define OIL_LOW                 UNUSE
#define DEFINE_TIP_OIL_LOW		(OIL_LOW)&&(eng_speed>0)     
#define DEFINE_TIP_AIR_LOW 		(AIR1_LOW || AIR2_LOW || BREAK_AIRLOW_SW)	       
#define DEFINE_TIP_SPEED		((veh_speed_display >= (Speed_Alarm*10)))                   //����                                  
#define DEFINE_TIP_PLANT_ALARM  (PLANT_ALL)//Ħ��Ƭ����
#define DEFINE_TIP_ENGINE_WATERTEP_HIGH UNUSE
/***********************************************************/ 

//�Ƿ���ģ��
#define  Has_Fmode       ON
#define  Has_Rmode       ON
#define  Has_Tmode       ON
#define  Has_Amode       OFF

//����PWM�궨��
#define PWM_R_P02			   PWMEable

//�ƹ�
#define  LED_LEFT_SW          LED_LEFT_SW_FEEDBACK
#define  LED_RIGHT_SW         LED_RIGHT_SW_FEEDBACK
#define  LED_HBEAM_SW         LED_HBEAM_SW_FEEDBACK
#define  LED_LBEAM_SW         LED_LBEAM_SW_FEEDBACK
#define  LED_FFOG_SW          LED_FFOG_SW_FEEDBACK
#define  LED_RFOG_SW          LED_RFOG_SW_FEEDBACK//�����                                   
//��״ָ̬ʾ
#define  LED_FRONT_DOOR_SW    FRONT_DOOR_SW
#define  LED_MIDDLE_DOOR_SW   MID_DOOR_SW
#define  LED_ENG_DOOR_SW      ENG_DOOR_SW //�������տ���

#define  LED_FILTER_SW        UNUSE
#define  LED_DRYER_SW         UNUSE                                            
#define  LED_PREHEAT_SW       UNUSE                                            
#define  LED_STOP_SW          UNUSE                                             
#define  LED_SERVICE_SW       UNUSE                                            
#define  LED_ENG_FAULT_SW     UNUSE                                            
#define  LED_ENG_TEMP_HOT_SW  (ENG_TEMP_ALARM_SW || BAT_TEMP_ALARM_SW)
#define  LED_FUEL_LOW_SW      UNUSE
#define  LED_GENERATOR1_SW    UNUSE //���ָʾ
//һ��������������õ���Ŀ
#define  LED_ABS_SW           (ABS_SW||ABS_CAN)
#define  LED_BATTERY_LOW_SW   ((Vbat < 200)||(Vbat > 320))        
#define  LED_OIL_LOW_SW       OIL_LOW                                        
#define  LED_POWER_SW         SYSTEM_POW                                       
#define  LED_AIR_LOW_SW       DEFINE_TIP_AIR_LOW                                
#define  LED_PARK_SW          PARK_SW    


//���㳵�ٷ�ʽ
#define CALULATE_SPEED_ENABLE  UNUSED
//2 �Ƿ��������ͳ��ٱ�������
#define SENDSPEED_ENABLE	  USED  


//���հ�������ȼ�ӷ���
#define ART_YIRAN             UNUSED
//����������ʾ��
#define CLOSE_DOOR_WANT_VOICE UNUSED

/********************************����������ʹ��************************************/
/*
//����
#define ASR1 TestBits(CanData[ID(0x18F0010B)][2],2,2,1)//((_18f0010b[2].byte  & 0x0c) == 0x04)
#define ASR4 TestBits(CanData[ID(0x18F0010B)][5],6,2,1)//((_18f0010b[5].byte  & 0xc0) == 0x40)
//��˸
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
