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

extern uint32_t    Veh_odo,Pre_odo,Set_Veh_odo,Pre_trip;
extern uint32_t    Veh_trip;

extern uint8_t  Temp_Vbat;
extern uint8_t  fuel_percent;

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

#define CONNECTION(text1,text2) text1##text2
#define CONNECT(text1,text2) CONNECTION(text1,text2)


#define RESET_SWITCH_DELAY(cond, count)  \
	({                              \
		static uint8_t CONNECT(timeout, __LINE__) = 0; \
		static uint8_t CONNECT(first, __LINE__) = 0;   \
		if (CONNECT(timeout, __LINE__))               \
			CONNECT(timeout, __LINE__)--;             \
		if (cond)                  \
		{                          \
			if (CONNECT(first, __LINE__) == 0)        \
			{                      \
				CONNECT(first, __LINE__) = 1;         \
				CONNECT(timeout, __LINE__) = count;   \
			}                      \
		}                          \
		else                       \
		{                          \
			CONNECT(first, __LINE__) = 0;             \
		}                          \
		CONNECT(timeout, __LINE__) > 0;               \
	})
	




//condition 输出 interval_ms
#define HIGH_LEVEL_OUT(condition, interval_ms)          \
    ({                                                    \
        static uint32_t flag,time = 0;                         \
        static bool     re   = FALSE;                     \
        if ((condition))                                  \
        {                                                 \
            if (flag == 0)                                \
            {                                             \
                flag = 1;                                 \
                time = interval_ms;                       \
            }\
        }                                                 \
        else                                              \
        {                                                 \
            flag = 0;                                     \
        }                                                 \
        if(time > 0)                                      \
        {                                                 \
           time--;                                         \
		   re = TRUE;                                     \
		}                       \
        re;                                               \
    })



#if Has_Fmode
extern volatile uint8_t FrontCurrent[16];
#endif

#if Has_Rmode
extern volatile uint8_t RearCurrent[16];
#endif

#if Has_Tmode
extern volatile uint8_t TopCurrent[16];
#endif






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


extern TYPE_QWORD Art;
extern TYPE_BYTE  JINLONG_DOOR;

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
#define KEY_ACC_FLAG             Art.bit.b16
#define DOOR_FLAG           	 Art.bit.b17
#define ANQUANDA_BUZZ_FLAG       Art.bit.b18
#define KEYSTFLAG           Art.bit.b19
#define LIZUO_BUZZ_FLAG           Art.bit.b20
#define PASSAGE_FLAG           Art.bit.b21
#define PRE_PTB5              Art.bit.b22
#define PRE_ALL_DOOR        Art.bit.b23
#define PRE_PASSAGE           Art.bit.b24
#define FENGMINGQI4           Art.bit.b25
#define FENGMINGQI5           Art.bit.b26
#define FENGMINGQI6           Art.bit.b27
#define FENGMINGQI7           Art.bit.b28
#define FENGMINGQI8           Art.bit.b29
#define FENGMINGQI9           Art.bit.b30
#define TMSFLAG20S           Art.bit.b31
#define CANJI_SHANGCHE_FLAG           Art.bit.b32
#define CANJI_XIACHE_FLAG           Art.bit.b33

#define MIEHUO_ALARMHIGH           Art.bit.b34
#define MIEHUO_ALARMLOW          Art.bit.b35
#define BUZZ_2S           Art.bit.b36
#define LAST_MIEHUO_ALARMLOW          Art.bit.b37
#define PARK_PAGE_FLAG           Art.bit.b38
#define MIMA_FLAG           Art.bit.b39
#define LAST_HOUWU           Art.bit.b40
#define HOUWUDENG_FUWEI           Art.bit.b41
#define NOON_FALG                Art.bit.b42
#define set_buzz                 Art.bit.b43
#define PRE_FRONT_DOOR           Art.bit.b44
#define PRE_MIDDLE_DOOR          Art.bit.b45
#define BUZZ_Normal              Art.bit.b46
#define BUZZ_Critical            Art.bit.b47
#define SYMBOLBUZZ               Art.bit.b48
#define AUTOBACKGROUNDLING       Art.bit.b49
#define DRIVER_AWAY_FLAG         Art.bit.b50
#define CLEANFLAG                Art.bit.b51
#define CANJI_SYMBOL             Art.bit.b52
#define MIDDLE_FLAG              Art.bit.b53

#define FRONTDOOR_OPEN_STATUS    JINLONG_DOOR.bit.b0
#define FRONTDOOR_CLOSE_STATUS   JINLONG_DOOR.bit.b1
#define FRONTDOOR_CLOSE_FLAG    JINLONG_DOOR.bit.b2
#define FRONTDOOR_OPEN_FLAG     JINLONG_DOOR.bit.b3
#define MIDDLEDOOR_OPEN_STATUS   JINLONG_DOOR.bit.b4
#define MIDDLEDOOR_CLOSE_STATUS  JINLONG_DOOR.bit.b5
#define MIDDLEDOOR_OPEN_FLAG   JINLONG_DOOR.bit.b6
#define MIDDLEDOOR_CLOSE_FLAG  JINLONG_DOOR.bit.b7

#define Can1_Tx_Bytes            PCan1_Expend_Tx_Bytes
#define Can2_Tx_Bytes            PCan2_Expend_Tx_Bytes


extern TYPE_BYTE rfog_control;
#define RROG_INIT  (rfog_control.byte == 0)
#define RROG_BIT0   rfog_control.bit.b0
#define RROG_BIT1   rfog_control.bit.b1
#define RROG_END    rfog_control.byte = 0

extern volatile TYPE_BYTE Fault[5];
extern volatile u32 ABS_DTC[4];
extern TYPE_BYTE tony,metre_state2[6],metre_state3[6];
extern volatile u8 PeiDianOutSta[43],PeiDianTemp[14];
extern volatile u16 PeiDianOutCur[45];
extern u32 TMS_Code_Time;
extern u8 data_0x18FFC13A[8];



void Sendspeed(void);
void calulate_speed(void);
void Acquisition_Task (void);
void SystemLogic(void);
u8 JudgeMAInBuff(volatile u8 *p,volatile u8 data);
void singleMile(void);
void BuzzLogic(void);




#endif /* SYSTEM_H_ */
