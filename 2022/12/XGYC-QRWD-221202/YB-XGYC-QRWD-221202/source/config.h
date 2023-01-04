/*
 * config.h
 *
 *  Created on: 2021-11-29
 *      Author: ART
 */

#ifndef CONFIG_H_
#define CONFIG_H_

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

#define ISRELEASE  USED
#define WATCHDOGEN USED

//��Ҫ��ʾ�Ľ���
#define DISPLAYTASKNUM 5
#define POWER_DETECT   (PTA7||PTA8||PTA9||PTA10||PTA12||PTE2||PTA20)


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
#define LevelSet_A20_IN			 HighEnable

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
#define A3_TYE     RES
#define A4_TYE     RES
#define A13_TYE    VOLT
#define A14_TYE    VOLT
/**********************/


/*********�Ǳ����ò���****************/
#define PULSE                    8000 //��������(C3���)
#define SUBI  	                 2500   //�ٱ�
#define COEF                     102  //����ϵ��

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
#define MILE_COME_FROM           METRE_MILE  //�����ݴ洢������ö��



/**********��ѹ������������ʼ*************************/
#define BAR_12                  USED     //2 12BAR
#define BAR_10                  UNUSED   //2 10BAR
#define AIR_TYPE                VOLT      //2 ��ѹ���ź���Դ����ö��
#define Bar1Source              bcm_senor1_f  //2 ��ѹһ��Դ
#define Bar2Source              bcm_senor2_f  //2 ��ѹ����Դ
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
#define VBATTEMPSOUTCE  bcm_senor2_t

/******************************/

#define SUPPORT_WIPER 		USED// ��ˢ���ܴ򿪹ر�

/*��ε�λ����*****************/
#define WIPER_INT_SW	(KEY_ON&&PTD8) //��Ъ
#define WIPER_LO_SW     (KEY_ON&&PTD7) //���ٵ�
#define WIPER_HI_SW     (KEY_ON&&PTD6) //���ٵ�
#define WIPER_MI_SW		(KEY_ON&&PTD9) //��ˮ����
/*��ε�λ����End*****************/


//���ý��濪�أ�ON �� OFF �ر�
#define ChangeLiChengEnable   ON  //�������
#define ChangeSubiEnable      ON  //�����ٱ�
#define ChangePulseEnable     ON  //���ð�������
#define ChangeCoefEnable      ON  //������ʾ�ٶȵı���

#define ChangeTimeEnable      ON   //����ʱ��
#define ChangeBLEnable        ON   //���ñ���
#define ChangeBuzzEnable      ON   //���÷�����

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


#define KEY_ON				PTE2				  //On��
#define KEY_ACC				PTA7                  //ACC��
#define KEY_ST				UNUSED                  //start��
#define KEY_EMG				(PTA8)                 //Σ����������
#define KEY_CHARGE          PTA10                 //��绽�ѿ���
#define KEY_POWER			PTA9//�ܵ�Դ����
#define LEAST_VOLTAGE       160
#define DEFINE_TIP_LEAST_VOLT   (Vbat < LEAST_VOLTAGE)   


#define SYSTEM_POW        	(KEY_ON||KEY_ACC)     //ϵͳ��Դ����
#define WAKE_UP_SW			(KEY_ON||KEY_ACC||KEY_ST||KEY_EMG||KEY_POWER) //�ɻ��ѿ���
//�ƹ�
#define RIGHT_LED_SW        PTB11   //��ת���
#define LEFT_LED_SW         PTB10    //��ת���
#define BACKLIGHT_SW        PTB7    //С�ƿ���
#define HBEAM_SW            PTB8    //Զ��
#define LBEAM_SW            PTB9    //����
#define FFOG_SW             TonyTestBitTrue(0x18FA0118,BYTE1,0)//PTB5//ǰ���
#define RFOG_SW             TonyTestBitTrue(0x18FA0118,BYTE1,1)//PTB6//�����


#define LOW_SPEED_SW         TonyTestBitTrue(0x18FA0118,BYTE1,2)
#define DRIVE_LIGHT_SW       TonyTestBitTrue(0x18FA0118,BYTE1,3)
#define XIANG_DENG1_SW       TonyTestBitTrue(0x18FA0118,BYTE1,4)
#define XIANG_DENG2_SW       TonyTestBitTrue(0x18FA0118,BYTE1,5)
#define LU_PAI_SW            TonyTestBitTrue(0x18FA0118,BYTE1,6)
#define GUANG_GAO_SW         TonyTestBitTrue(0x18FA0118,BYTE1,7)

#define HOU_SHIJING_SW       TonyTestBitTrue(0x18FA0118,BYTE2,0)//PTB5//ǰ���
#define ECAS_UP_SW           TonyTestBitTrue(0x18FA0118,BYTE2,1)//PTB6//�����
#define ECAS_DOWN_SW         TonyTestBitTrue(0x18FA0118,BYTE2,2)
#define ECAS_RESET_SW        TonyTestBitTrue(0x18FA0118,BYTE2,3)
#define ECAS_CEGUI_SW        TonyTestBitTrue(0x18FA0118,BYTE2,4)
#define DRIVE_FENGSHAN_SW    TonyTestBitTrue(0x18FA0118,BYTE2,5)
#define CHUSHUANG_LOW_SW     TonyTestBitTrue(0x18FA0118,BYTE2,6)
#define CHUSHUANG_HIGHT_SW   TonyTestBitTrue(0x18FA0118,BYTE2,7)




//ɲ��
#define BREAK_SW            (F_SW_P35)
#define ELEC_BREAK          ((OnOffStatus&0x80) == 0x80)   
#define BREAK_ALL           (BREAK_SW||ELEC_BREAK)

#define READY               ((SystemStatus&0x40) == 0x40) 
#define SYSTEM_ERROR   		 ((SystemStatus&0x30)==0x30) 
#define SYSTEM_ERROR_WUGUI   ((SystemStatus&0x30)==0x20) 


#define PARK_SW            	F_SW_P21//��ɲ
//��λ
#define D_SW   				    (((DriverOperateStatus&0x0f)==14))
#define NULL_SW                 ((DriverOperateStatus&0x0f)==0)  
#define REVERSE_GEAR_SW         (((DriverOperateStatus&0x0f)==13)) 
#define P_SW					((DriverOperateStatus&0x0f)==0x0f)

//��״̬)
#define ENG_DOOR_SW         (!R_SW_P17)
#define FRONT_DOOR_SW       T_SW_P17
#define MID_DOOR_SW         T_SW_P39

#define FRONT_DOOR_OPEN_SW  UNUSE
#define FRONT_DOOR_CLOSE_SW UNUSE
#define MID_DOOR_OPEN_SW    UNUSE
#define MID_DOOR_CLOSE_SW   UNUSE

#define FRONT_DOOR_FANGJIA_SW UNUSE //���п���
#define MID_DOOR_FANGJIA_SW   UNUSE

//���ÿ���
#define PASSAGE_GET_OUT_SW  (T_SW_P37)//�¿�����
#define WATER_SW      		 R_SW_P33//��ȴˮλ��  
  

//����
#define ASR_SW              UNUSE
#define ABS_SW              PTD16
#define SAFE_DOOR_SW        UNUSE //��ȫ��
#define BUZZ_SW             PTD3//���ȿ���

#define PLANT_LEFT_F  ((!F_SW_P19))//��ǰ��Ƭ
#define PLANT_RIGHT_F ((!F_SW_P33))//��ǰ��Ƭ
#define PLANT_LEFT_R  ((!F_SW_P34)) //�����Ƭ
#define PLANT_RIGHT_R ((!F_SW_P20)) //�Һ���Ƭ


#define PLANT_ALL     (PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R) //Ħ��Ƭ����

#define EMERGENCY_F_INSIDE_SW       (T_SW_P18)
#define EMERGENCY_F_OUTSIDE_SW      (T_SW_P19)
#define EMERGENCY_M_INSIDE_SW       (T_SW_P32)
#define EMERGENCY_M_OUTSIDE_SW      (T_SW_P33)
#define EMERGENCY_ALL     (EMERGENCY_F_INSIDE_SW||EMERGENCY_F_OUTSIDE_SW||EMERGENCY_M_INSIDE_SW||EMERGENCY_M_OUTSIDE_SW) //Ħ��Ƭ����


#define AIRLOW_SW_1 		 	UNUSED	  //ǰ����ѹ�Ϳ���
#define AIRLOW_SW_2 		 	UNUSED	  //������ѹ�Ϳ���

#define AIR1_LOW				((veh_bar1<Air_Alarm)||AIRLOW_SW_1)
#define AIR2_LOW				((veh_bar2<Air_Alarm)||AIRLOW_SW_2)
#define DEFINE_TIP_AIR_LOW 		(AIR1_LOW || AIR2_LOW)	

#define DRIVER_SW            PTD5//˾����
#define BOX_LINGT_1_SW       PTD1 //���
#define BOX_LINGT_2_SW       PTD2 //���
#define DEFROST_SW           PTD11//��˪����
#define DEFROST_SW_2         PTD13//��˪���� 
#define DIAN_JIARE_SW		 F_SW_P39
#define TV_SW                UNUSE
#define LCD_SW               PTC10  //������
#define FAN_SW               PTB12  //����
#define ROAD_LIGHT           UNUSE  //������
#define LUPAI_LIGHT          UNUSE//·�Ƶ�


#define SEATBELT_NO_SW         (KEY_ON && F_SW_P32)  //��ȫ��δϵ����
#define DRIVER_AWAY_SW          (D_SW && (!F_SW_P18)) //˾����������
#define DRIVER_AWAY_ALARM       (UNUSE)
#define OUTSIDE_VOICE_BAN_SW	!LOW_SPEED_SW
#define CANJI_TABAN		  		F_SW_P17


//����ͷ����
#define TV1_REVERSE_SW       (UNUSED && ChangeVideoAv1Enable && (VIDEO_AV_GRAR))
#define TV2_REAR_DOOR_SW     (UNUSED)//(UNUSE && ChangeVideoAv4Enable && (VIDEO_AV_ELSE))
#define TV3_FRONT_DOOR_SW    (UNUSED && ChangeVideoAv3Enable && (VIDEO_AV_FRO))
#define TV4_MIDDLE_DOOR_SW   (UNUSED && ChangeVideoAv2Enable && (VIDEO_AV_MID))




//�������Ƭȡģ���������״̬
#include "Artpatch.h"


#define  LED_LEFT_SW_FEEDBACK      F_OUT_P3//B40_FEEDBACK(f,A11) && B40_FEEDBACK(r,A11)
//��ת��
#define  LED_RIGHT_SW_FEEDBACK     F_OUT_P10//B40_FEEDBACK(f,A4)  && B40_FEEDBACK(r,A4)
//Զ���
#define  LED_HBEAM_SW_FEEDBACK     B40_FRONT_FEEDBACK(A4)
//1 �����
#define  LED_LBEAM_SW_FEEDBACK     B40_FRONT_FEEDBACK(A12)
//1 ǰ���
#define  LED_FFOG_SW_FEEDBACK      B40_FRONT_FEEDBACK(A5)
//1�����
#define  LED_RFOG_SW_FEEDBACK      B40_REAR_FEEDBACK(A12)
//1 С��
#define  LED_BACKLIGHT_SW_FEEDBACK (B40_FRONT_FEEDBACK(A11) && B40_TOP_FEEDBACK(A12)&& B40_REAR_FEEDBACK(A14)&& B40_REAR_FEEDBACK(A7))
//1 ɲ����
#define  LED_BREAK_SW_FEEDBACK     (B40_TOP_FEEDBACK(A6) && B40_REAR_FEEDBACK(A4))


//�Ƿ���ģ��
#define  Has_Fmode       ON
#define  Has_Rmode       ON
#define  Has_Tmode       ON
#define  Has_Amode       OFF

//����PWM�궨��
#define PWM_F_P04              PWMEable
#define PWM_F_P12              PWMEable
#define PWM_F_P05              PWMEable

#define PWM_T_P11              PWMEable
#define PWM_T_P04              PWMEable

#define PWM_R_P42              PWMEable

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
//����������
#define  LED_FILTER_SW        UNUSE
#define  LED_DRYER_SW         (RearCurrent[A11] > 10)  
#define  LED_PREHEAT_SW       UNUSE
#define  LED_ENG_FAULT_SW     UNUSE
#define  LED_ENG_TEMP_HOT_SW  UNUSE
#define  LED_FUEL_LOW_SW      UNUSE
#define  LED_GENERATOR1_SW    UNUSE //���ָʾ
//һ��������������õ���Ŀ
#define  LED_ABS_SW           ABS_SW
#define  LED_BATTERY_LOW_SW   ((Vbat < 200)||(Vbat > 320))
#define  LED_OIL_LOW_SW       OIL_LOW
#define  LED_POWER_SW         SYSTEM_POW
#define  LED_AIR_LOW_SW       DEFINE_TIP_AIR_LOW
#define  LED_PARK_SW          PARK_SW
//������ݴ洢������ö��

/************************ROLL ALARM***************************/

#define DEFINE_TIP_LEAST_VOLT  (Vbat < LEAST_VOLTAGE)
#define OIL_LOW                 UNUSE
#define DEFINE_TIP_OIL_LOW      (OIL_LOW)&&(eng_speed>0)
#define DEFINE_TIP_SPEED        ((veh_speed_display >= (Speed_Alarm*10)))                   //����                                  
#define DEFINE_TIP_WATER_LOW    WATER_SW                //ˮλ��                                        
#define DEFINE_TIP_PLANT_ALARM  (PLANT_LEFT_F||PLANT_RIGHT_F||PLANT_LEFT_R||PLANT_RIGHT_R)//Ħ��Ƭ����
#define DEFINE_TIP_ENGINE_WATERTEP_HIGH UNUSE

//���㳵�ٷ�ʽ
#define CALULATE_SPEED_ENABLE  UNUSED
//2 �Ƿ��������ͳ��ٱ�������
#define SENDSPEED_ENABLE	  USED  


//���հ�������ȼ�ӷ���
#define ART_YIRAN             UNUSED

//����������ʾ��
#define CLOSE_DOOR_WANT_VOICE USED
                                      


#endif /* CONFIG_H_ */
