/*
 * system.h
 *
 *  Created on: 2021-11-29
 *      Author: ART
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

extern uint8_t BCanSendDisable;
extern volatile uint8_t BcanDelay,Pcan1Delay,Pcan2Delay,Pcan3Delay,DcanDelay,speed_life;
extern uint8_t tmp_buff[7];
extern rtc_t       rtc;
extern volatile uint32_t SysTickPer1ms;
extern volatile uint32_t A5Count,A15Count;
extern u8  initflag;

extern uint16_t    Vbat;
extern volatile uint16_t    eng_speed;      //engine speed
extern volatile uint16_t    veh_speed;      //vehicle speed
extern volatile uint16_t    veh_speed_display;
extern uint16_t    veh_bar1;
extern uint16_t    veh_bar2;
extern volatile uint16_t    veh_soc;
extern uint16_t    speed_count;

extern uint32_t    Veh_odo,Pre_odo,Set_Veh_odo;
extern uint16_t    Veh_trip;

extern uint8_t  Temp_Vbat;
extern uint8_t  fuel_percent;




#if Has_Fmode
extern volatile uint8_t FrontCurrent[16];
#endif

#if Has_Rmode
extern volatile uint8_t RearCurrent[16];
#endif

#if Has_Tmode
extern volatile uint8_t TopCurrent[16];
#endif



enum
{
    BYTE1 = 0,
    BYTE2,
    BYTE3,
    BYTE4,
    BYTE5,
    BYTE6,
    BYTE7,
    BYTE8
}; //2 对应CAN报文的字节 BYTE0起始或者BYTE1起始


typedef struct{
	unsigned char luntai[6];
	unsigned int  yali[6];
	unsigned int wendu[6];
	unsigned char fault_status[6];
	unsigned char error[6];
	unsigned char fangbaotai[2];
	unsigned int  life;
}TAIYA;
extern volatile TAIYA taiya;



#define EnableIRQ()           INT_All_Enable (TRUE)
#define DisableIRQ()          INT_All_Enable (FALSE) 

// 蜂鸣器打开关闭
#define BUZZ(state)	  GPIO_Set_Output_Data_Bits(GPIOA_SFR,GPIO_PIN_MASK_7, state)	

#define BEEP_OFF()\
{\
  BUZZ(Bit_RESET);\
  if(blinker++ >= 40)\
     blinker = 1;\
}


#define BEEP_TURN()\
{\
  BUZZ((blinker == 21));\
  if(blinker++ >= 40)\
     blinker = 1;\
}

#define BEEP_FAULT()\
{\
  BUZZ(blinker < 21);\
  if(blinker++ >= 40)\
     blinker = 1;\
}

#define BEEP_FAST()\
{\
  BUZZ(blinker < 11);\
  if(blinker++ >= 20)\
     blinker = 1;\
}

#define TURN_HZ       (blinker > 17)


extern TYPE_QWORD Art,CanSend_Flag;
#define FLAG_0X0C0AA79D         CanSend_Flag.bit.b0
#define FLAG_0X0C04A1A7         CanSend_Flag.bit.b1
#define FLAG_0X0C06A1A7         CanSend_Flag.bit.b2
#define FLAG_0X0C079AA7         CanSend_Flag.bit.b3


//仪表参数信息
#define BUZZ_NORMAL_WORK         Art.bit.b2
#define VIDEO_AV_GRAR            Art.bit.b3
#define VIDEO_AV_MID             Art.bit.b4
#define VIDEO_AV_FRO             Art.bit.b5
#define VIDEO_AV_ELSE            Art.bit.b6
#define RAIN_STATE               Art.bit.b7
#define SET_VIDEO_AV1            Art.bit.b8
#define SET_VIDEO_AV2            Art.bit.b9
#define SET_VIDEO_AV3            Art.bit.b10
#define SET_VIDEO_AV4            Art.bit.b11
#define ENABLEDIANHAO            Art.bit.b12
#define ONFlag                   Art.bit.b13
#define clear_mile               Art.bit.b14
#define BUZZ_LAST_STATE          Art.bit.b15
#define _18FF8001_FLAG           Art.bit.b16
#define _18FF0152_FLAG           Art.bit.b17
#define _18FF3047_FLAG           Art.bit.b18
#define _18FF3147_FLAG           Art.bit.b19
#define _18FF3247_FLAG           Art.bit.b20
#define _18FF2C47_FLAG           Art.bit.b21
#define _18FF2848_FLAG           Art.bit.b22
#define _18FF2948_FLAG           Art.bit.b23
#define _18FF2A48_FLAG           Art.bit.b24
#define _18FF0257_FLAG           Art.bit.b25
#define _0CFFEB4A_FLAG           Art.bit.b26
#define _18FF5A52_FLAG           Art.bit.b27
#define ECAS_RESET_FLAG           Art.bit.b28
#define ECAS_RESET_FUWEI           Art.bit.b29
#define ECAS_CEQING_FLAG           Art.bit.b30
#define ECAS_CEQING_FUWEI           Art.bit.b31
#define ECAS_DOWN_FLAG           Art.bit.b32
#define ECAS_DOWN_FUWEI           Art.bit.b33

#define ECAS_UP_FUWEI           Art.bit.b34
#define ECAS_UP_FLAG           Art.bit.b35
#define AUTO_LIGHT           	 Art.bit.b36
#define LIFE           			 Art.bit.b37
#define ASR_BLINKER           	 Art.bit.b38
#define SHAN_FLAG           	 Art.bit.b39
#define LED_SIJIDENG_1           Art.bit.b40
#define LED_SIJIDENG_2           Art.bit.b41
#define NOON_FALG                Art.bit.b42
#define set_buzz                 Art.bit.b43
#define PRE_FRONT_DOOR           Art.bit.b44
#define PRE_MIDDLE_DOOR          Art.bit.b45
#define BUZZ_Normal              Art.bit.b46
#define BUZZ_Critical            Art.bit.b47
#define SYMBOLBUZZ               Art.bit.b48
#define AUTOBACKGROUNDLING       Art.bit.b49
#define GEAR_FLAG                Art.bit.b50
#define LAST_FDOOR_OPEN_FLAG     Art.bit.b51
#define LAST_FDOOR_CLOSE_FLAG    Art.bit.b52
#define LAST_MDOOR_OPEN_FLAG     Art.bit.b53
#define LAST_MDOOR_CLOSE_FLAG    Art.bit.b54
#define LAST_FDOOR_CAN_FLAG      Art.bit.b55
#define LAST_MDOOR_CAN_FLAG      Art.bit.b56

#define C7C8_TO_C5C6             Art.bit.b57
#define C5C6_TO_C7C8             Art.bit.b58
#define _0x0C06A1A6              Art.bit.b59


#define Can1_Tx_Bytes            PCan1_Expend_Tx_Bytes
#define Can2_Tx_Bytes            PCan2_Expend_Tx_Bytes



extern u32 All_Spn[10];
extern u8 All_Fmi[10];
extern u8 All_Oc[10];

extern volatile uint8_t  pengzhang_shuixiang;



#define MAX_XIANG   16       //1 最大做到16箱
#define MAX_JIE     60

#define DIANJI_Low 520750//电机SPN低
#define DIANJI_Hi  520795//电机SPN高

#define DIANCHI_Low 520850//电池SPN低
#define DIANCHI_Hi  520883//电池SPN高

#define DIANCHI_ADD1_Low 520885//第二个电池SPN低
#define DIANCHI_ADD1_Hi  520890//第二个电池SPN高

#define DIANCHI_ADD2_Low 521500//第3个电池SPN低
#define DIANCHI_ADD2_Hi  521512//第3个电池SPN高

#define DIANCHI_ADD3_Low 521514//第4个电池SPN低
#define DIANCHI_ADD3_Hi  521600//第4个电池SPN高

#define Total_Car_Low 520450//整车SPN低
#define Total_Car_Hi  520505//整车SPN高

#define FUJI_Low 520506//辅机SPN低
#define FUJI_Hi  520640//辅机SPN高

#define FUJI_ADD_LOW   521200
#define FUJI_ADD_HIGH  521300

#define TCU_Low  520650
#define TCU_High 520670

#define TMS_SPN 	520884//TMS SPN
#define YANWU_HUOZAI  521513//烟雾and火灾

//其他故障需扣除互锁报文SPN 所以有多个
#define QITA_Low 521030//其他故障
#define QITA_Hi  521035//其他故障

#define QITA1_Low 521037//其他故障
#define QITA1_Hi  521083//其他故障

#define QITA2_Low 521092//其他故障
#define QITA2_Hi  521100//其他故障


void Sendspeed(void);
void calulate_speed(void);
void Acquisition_Task (void);
void SystemLogic(void);
u8 JudgeMAInBuff(volatile u8 *p,volatile u8 data);
void singleMile(void);
void BuzzLogic(void);






#endif /* SYSTEM_H_ */
