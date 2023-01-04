/*
 * system.h
 *
 *  Created on: 2021-8-5
 *      Author: ART
 */

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

//由于软件与MPC5604不一致，软件发送名称一致，便于使用
// C3 & C4
#define  Can0_Tx_Standard_Bytes           BCan_Standard_Tx_Bytes
#define  Can0_Tx_Bytes                    BCan_Expend_Tx_Bytes

// C5 & C6
#define  Can1_Tx_Standard_Bytes           Can_Standard_Tx_Bytes
#define  Can1_Tx_Bytes                    Can_Expend_Tx_Bytes

// C7 & C8
#define  Can2_Tx_Standard_Bytes           PCan_Standard_Tx_Bytes
#define  Can2_Tx_Bytes                    PCan_Expend_Tx_Bytes

// C16 & C17
#define  Can3_Tx_Standard_Bytes           DCan_Standard_Tx_Bytes
#define  Can3_Tx_Bytes                    DCan_Expend_Tx_Bytes





#define POWER_DETECT (PTA8||PTA9||PTA10||PTE2||PTA7)

#define EnableIRQ()           INT_All_Enable (TRUE)
#define DisableIRQ()          INT_All_Enable (FALSE) 

#define CONTROL_T123_POWER()  GPIO_Set_Output_Data_Bits(GPIOG_SFR,GPIO_PIN_MASK_6, SET)	

//最低启动电池电压
#define LEAST_VOLTAGE       160  

#define GetU32LEData(l,ml,mh,h) ((((uint32_t)h)<<24)+(((uint32_t)mh)<<16)+(((uint32_t)ml)<<8)+l)

#define GetU16BE(x,y)  ((((uint16_t)x[y])<<8)+x[y+1])
#define GetU16LE(x,y)  ((((uint16_t)x[y+1])<<8)+x[y])

#define GetU16BEData(xl,xh)  ((((uint16_t)xl)<<8)+xh)
#define GetU16LEData(xl,xh)  ((((uint16_t)xh)<<8)+xl)

#define GetU16Low(x)	(((x)>>0)&0xFF)
#define GetU16High(x) 	(((x)>>8)&0xFF)

#define TestBitTrue(byte,bit)    (((byte) & (1<<(bit))) > 0)
#define TestBitFalse(byte,bit)    (((byte) & (1<<(bit))) == 0)


#define GetBits(byte,offset,bits)    (((byte)>>(offset)) & ((1<<(bits))-1))

//byte 被比较的数据所在的变量，offset 被比较的数据的起始位，bits被比较的数据位长度，comp 比较的值
#define TestBits(byte,offset,bits,comp)    (((byte) & (((1<<(bits))-1) << (offset))) == ((comp)<<(offset)))

#define BCD_TO_BIN(val) (((val)&0x0F) + ((val)>>4)*10)
#define BIN_TO_BCD(val) ((((val)/10)<<4) + (val)%10)      


typedef struct
{
   uint16_t MeterA2;
   uint16_t MeterA3;
   uint16_t MeterA4;
   uint16_t MeterA13;
   uint16_t MeterA14;
   uint16_t MeterA15;
   uint16_t MeterA5;
}Meter;

typedef struct  
{
    uint8_t secs;
    uint8_t mins;
    uint8_t hours;
    uint8_t day;
    uint8_t month;
    uint8_t year;
    uint8_t week;
}rtc_t;

extern rtc_t rtc;

typedef struct
{
#if 0
	unsigned long long b0:1;
	unsigned long long b1:1;
	unsigned long long b2:1;
	unsigned long long b3:1;
	unsigned long long b4:1;
	unsigned long long b5:1;
	unsigned long long b6:1;
	unsigned long long b7:1;
	unsigned long long b8:1;
	unsigned long long b9:1;
	unsigned long long b10:1;
	unsigned long long b11:1;
	unsigned long long b12:1;
	unsigned long long b13:1;
	unsigned long long b14:1;
	unsigned long long b15:1;
	unsigned long long b16:1;
	unsigned long long b17:1;
	unsigned long long b18:1;
	unsigned long long b19:1;
	unsigned long long b20:1;
	unsigned long long b21:1;
	unsigned long long b22:1;
	unsigned long long b23:1;
	unsigned long long b24:1;
	unsigned long long b25:1;
	unsigned long long b26:1;
	unsigned long long b27:1;
	unsigned long long b28:1;
	unsigned long long b29:1;
	unsigned long long b30:1;
	unsigned long long b31:1;
	unsigned long long b32:1;
	unsigned long long b33:1;
	unsigned long long b34:1;
	unsigned long long b35:1;
	unsigned long long b36:1;
	unsigned long long b37:1;
	unsigned long long b38:1;
	unsigned long long b39:1;
	unsigned long long b40:1;
	unsigned long long b41:1;
	unsigned long long b42:1;
	unsigned long long b43:1;
	unsigned long long b44:1;
	unsigned long long b45:1;
	unsigned long long b46:1;
	unsigned long long b47:1;
	unsigned long long b48:1;
	unsigned long long b49:1;
	unsigned long long b50:1;
	unsigned long long b51:1;
	unsigned long long b52:1;
	unsigned long long b53:1;
	unsigned long long b54:1;
	unsigned long long b55:1;
	unsigned long long b56:1;
	unsigned long long b57:1;
	unsigned long long b58:1;
	unsigned long long b59:1;
	unsigned long long b60:1;
	unsigned long long b61:1;
	unsigned long long b62:1;
	unsigned long long b63:1;
#endif

    #if 1
	unsigned long long b63:1;
	unsigned long long b62:1;
	unsigned long long b61:1;
	unsigned long long b60:1;
	unsigned long long b59:1;
	unsigned long long b58:1;
	unsigned long long b57:1;
	unsigned long long b56:1;
	unsigned long long b55:1;
	unsigned long long b54:1;
	unsigned long long b53:1;
	unsigned long long b52:1;
	unsigned long long b51:1;
	unsigned long long b50:1;
	unsigned long long b49:1;
	unsigned long long b48:1;
	unsigned long long b47:1;
	unsigned long long b46:1;
	unsigned long long b45:1;
	unsigned long long b44:1;
	unsigned long long b43:1;
	unsigned long long b42:1;
	unsigned long long b41:1;
	unsigned long long b40:1;
	unsigned long long b39:1;
	unsigned long long b38:1;
	unsigned long long b37:1;
	unsigned long long b36:1;
	unsigned long long b35:1;
	unsigned long long b34:1;
	unsigned long long b33:1;
	unsigned long long b32:1;
	unsigned long long b31:1;
	unsigned long long b30:1;
	unsigned long long b29:1;
	unsigned long long b28:1;
	unsigned long long b27:1;
	unsigned long long b26:1;
	unsigned long long b25:1;
	unsigned long long b24:1;
	unsigned long long b23:1;
	unsigned long long b22:1;
	unsigned long long b21:1;
	unsigned long long b20:1;
	unsigned long long b19:1;
	unsigned long long b18:1;
	unsigned long long b17:1;
	unsigned long long b16:1;
	unsigned long long b15:1;
	unsigned long long b14:1;
	unsigned long long b13:1;
	unsigned long long b12:1;
	unsigned long long b11:1;
	unsigned long long b10:1;
	unsigned long long b9:1;
	unsigned long long b8:1;
	unsigned long long b7:1;
	unsigned long long b6:1;
	unsigned long long b5:1;
	unsigned long long b4:1;
	unsigned long long b3:1;
	unsigned long long b2:1;
	unsigned long long b1:1;
	unsigned long long b0:1;
	#endif
} QWORD_FIELD;





typedef struct
{
	unsigned long long b0:1;
	unsigned long long b1:1;
	unsigned long long b2:1;
	unsigned long long b3:1;
	unsigned long long b4:1;
	unsigned long long b5:1;
	unsigned long long b6:1;
	unsigned long long b7:1;
	unsigned long long b8:1;
	unsigned long long b9:1;
	unsigned long long b10:1;
	unsigned long long b11:1;
	unsigned long long b12:1;
	unsigned long long b13:1;
	unsigned long long b14:1;
	unsigned long long b15:1;
	unsigned long long b16:1;
	unsigned long long b17:1;
	unsigned long long b18:1;
	unsigned long long b19:1;
	unsigned long long b20:1;
	unsigned long long b21:1;
	unsigned long long b22:1;
	unsigned long long b23:1;
	unsigned long long b24:1;
	unsigned long long b25:1;
	unsigned long long b26:1;
	unsigned long long b27:1;
	unsigned long long b28:1;
	unsigned long long b29:1;
	unsigned long long b30:1;
	unsigned long long b31:1;
	unsigned long long b32:1;
	unsigned long long b33:1;
	unsigned long long b34:1;
	unsigned long long b35:1;
	unsigned long long b36:1;
	unsigned long long b37:1;
	unsigned long long b38:1;
	unsigned long long b39:1;
	unsigned long long b40:1;
	unsigned long long b41:1;
	unsigned long long b42:1;
	unsigned long long b43:1;
	unsigned long long b44:1;
	unsigned long long b45:1;
	unsigned long long b46:1;
	unsigned long long b47:1;
	unsigned long long b48:1;
	unsigned long long b49:1;
	unsigned long long b50:1;
	unsigned long long b51:1;
	unsigned long long b52:1;
	unsigned long long b53:1;
	unsigned long long b54:1;
	unsigned long long b55:1;
	unsigned long long b56:1;
	unsigned long long b57:1;
	unsigned long long b58:1;
	unsigned long long b59:1;
	unsigned long long b60:1;
	unsigned long long b61:1;
	unsigned long long b62:1;
	unsigned long long b63:1;

} QQWORD_FIELD;


typedef struct
{
	unsigned char b0:1;
	unsigned char b1:1;
	unsigned char b2:1;
	unsigned char b3:1;
	unsigned char b4:1;
	unsigned char b5:1;
	unsigned char b6:1;
	unsigned char b7:1;
} BYTE_FIELD;

typedef union
{
	unsigned char byte;
	BYTE_FIELD	bit;
} TYPE_BYTE;


typedef union
{
	unsigned long long qword;
	unsigned char byte[8];
	TYPE_BYTE	tb[8];
	QWORD_FIELD	bit;
} TYPE_QWORD;


typedef union
{
	unsigned long long qword;
	unsigned char byte[8];
	QQWORD_FIELD	bit;
} TYPE_QQWORD;




typedef	union {
	uint8_t byte;
	BYTE_FIELD	bit;
	struct
	{
		uint8_t bits0 : 2;
		uint8_t bits1 : 2;
		uint8_t bits2 : 2;
		uint8_t bits3 : 2;
	}bits;
}TYPE_2BIT_BYTE;


typedef struct
{
	unsigned short b0:1;
	unsigned short b1:1;
	unsigned short b2:1;
	unsigned short b3:1;
	unsigned short b4:1;
	unsigned short b5:1;
	unsigned short b6:1;
	unsigned short b7:1;
	unsigned short b8:1;
	unsigned short b9:1;
	unsigned short b10:1;
	unsigned short b11:1;
	unsigned short b12:1;
	unsigned short b13:1;
	unsigned short b14:1;
	unsigned short b15:1;
} WORD_FIELD;

typedef union
{
	unsigned short word;
	unsigned char byte[2];
	WORD_FIELD bit;
} TYPE_WORD;

typedef struct 
{
	unsigned int b31:1;
	unsigned int b30:1;
	unsigned int b29:1;
	unsigned int b28:1;
	unsigned int b27:1;
	unsigned int b26:1;
	unsigned int b25:1;
	unsigned int b24:1;
	unsigned int b23:1;
	unsigned int b22:1;
	unsigned int b21:1;
	unsigned int b20:1;
	unsigned int b19:1;
	unsigned int b18:1;
	unsigned int b17:1;
	unsigned int b16:1;
	unsigned int b15:1;
	unsigned int b14:1;
	unsigned int b13:1;
	unsigned int b12:1;
	unsigned int b11:1;
	unsigned int b10:1;
	unsigned int b9:1;
	unsigned int b8:1;
	unsigned int b7:1;
	unsigned int b6:1;
	unsigned int b5:1;
	unsigned int b4:1;
	unsigned int b3:1;
	unsigned int b2:1;
	unsigned int b1:1;
	unsigned int b0:1;
} DWORD_FIELD;

typedef struct 
{
	unsigned short b0:2;
	unsigned short b1:2;
	unsigned short b2:2;
	unsigned short b3:2;
	unsigned short b4:2;
	unsigned short b5:2;
	unsigned short b6:2;
	unsigned short b7:2;
	unsigned short b8:2;
	unsigned short b9:2;
	unsigned short b10:2;
	unsigned short b11:2;
	unsigned short b12:2;
	unsigned short b13:2;
	unsigned short b14:2;
	unsigned short b15:2;
} DWORD_FIELD_2bit;


typedef union 
{
	unsigned int dword;
	unsigned char byte[4];
	DWORD_FIELD	bit;
	DWORD_FIELD_2bit BIT;
} TYPE_DWORD;

extern volatile    uint32_t    A15Count,A5Count;

extern uint8_t     communicate_T123_data[12];

extern volatile uint32_t SysTickPer1ms;
extern uint32_t time,Set_Veh_odo;
extern TYPE_QWORD Art,Syslogic;
extern uint16_t adc_100ma_fd[];
extern volatile uint8_t  Uart2Receive[8],ReceIndex;
extern uint8_t tmp_buff[];

#define _18FF8001_FLAG           Syslogic.bit.b0
#define _18FF2D47_FLAG           Syslogic.bit.b1
#define _18FF064A_FLAG           Syslogic.bit.b2
#define _18FF0152_FLAG           Syslogic.bit.b3
#define _18FF3047_FLAG           Syslogic.bit.b4
#define _18FF3147_FLAG           Syslogic.bit.b5
#define _18FF3247_FLAG           Syslogic.bit.b6
#define _18FF2C47_FLAG           Syslogic.bit.b7
#define _18FF2848_FLAG           Syslogic.bit.b8
#define _18FF2948_FLAG           Syslogic.bit.b9
#define _18FF2A48_FLAG           Syslogic.bit.b10
#define _18FF0257_FLAG           Syslogic.bit.b11
#define _0CFFEB4A_FLAG           Syslogic.bit.b12
#define _18FF5A52_FLAG           Syslogic.bit.b13
#define _18FF2B49_FLAG           Syslogic.bit.b14
#define _0CFF324A_FLAG           Syslogic.bit.b15
#define _0CFF0A4A_FLAG           Syslogic.bit.b16
#define _0CFF0B4A_FLAG           Syslogic.bit.b17
#define _18FF0258_FLAG           Syslogic.bit.b18
#define _18FF5B52_FLAG           Syslogic.bit.b19
#define _0CFF114A_FLAG           Syslogic.bit.b20
#define _10FFC19E_FLAG           Syslogic.bit.b21
#define _10FFC09E_FLAG           Syslogic.bit.b22
#define _18FF45F4_FLAG           Syslogic.bit.b23
#define _18FFC13A_FLAG           Syslogic.bit.b24
#define _10FFC29E_FLAG           Syslogic.bit.b25



#define CAN1_SEND_SUCCEED        Art.bit.b0
#define t123Ans                  Art.bit.b1

//仪表参数信息
#define BUZZ_NORMAL_WORK         Art.bit.b2
#define VIDEO_AV_GRAR            Art.bit.b3
#define VIDEO_AV_MID             Art.bit.b4
#define VIDEO_AV_FRO             Art.bit.b5
#define VIDEO_AV_ELSE            Art.bit.b6
#define RAIN_STATE               Art.bit.b7
#define T123OnFlag               Art.bit.b8
#define ENABLEDIANHAO            Art.bit.b9
#define SELF_TEST                Art.bit.b10
#define HALF_SELF_TEST_TIME      Art.bit.b11
// 上电自检符号片
#define OPENSYSTEMCHECK          Art.bit.b12

#define BCANSEND1MSDELAY         Art.bit.b13
#define TCANSEND1MSDELAY         Art.bit.b14
#define PCANSEND1MSDELAY         Art.bit.b15
#define DCANSEND1MSDELAY         Art.bit.b16
#define SET_VIDEO_AV1            Art.bit.b17
#define SET_VIDEO_AV2            Art.bit.b18
#define SET_VIDEO_AV3            Art.bit.b19
#define SET_VIDEO_AV4            Art.bit.b20
#define SET_RAIN                 Art.bit.b21
#define MIMA_FLAG                Art.bit.b22
#define MPC5602_CALL_T123        Art.bit.b23
#define FRONT_MAKE_SURE_SEND_INFORMATION     Art.bit.b24
#define REAR_MAKE_SURE_SEND_INFORMATION      Art.bit.b25   
#define TOP_MAKE_SURE_SEND_INFORMATION       Art.bit.b26
#define METRE_MAKE_SURE_SEND_INFORMATION     Art.bit.b27 
#define ONFlag                               Art.bit.b28
#define INITDIS                              Art.bit.b29
#define BCanSendDisable                      Art.bit.b30
#define BUZZ_Normal                          Art.bit.b31
#define BUZZ_Critical                        Art.bit.b32

#define SYMBOLBUZZ                           Art.bit.b33

#define PAGE_ON_FLAG       		             Art.bit.b34
#define PARK_BUZZZ_FLAG        	             Art.bit.b35
#define PRE_YOU                              Art.bit.b36

//右前门复位开
#define R_FRONT_DOOR_SW                      Art.bit.b37
//右中门复位开
#define R_MID_DOOR_SW			             Art.bit.b38
//右中门复位开
#define R_DOOR_SW        		             Art.bit.b39
#define clear_mile                           Art.bit.b40

#define  PRE_ZUOQIAN_DOOR                    Art.bit.b41
#define  PRE_ZUOZHONG_DOOR                   Art.bit.b42
#define  PRE_YOUQIAN_DOOR                    Art.bit.b43
#define  PRE_YOUZHONG_DOOR                   Art.bit.b44

#define  UP                                  Art.bit.b45
#define  DOWN                                Art.bit.b46
#define  NNORMAL                             Art.bit.b47
#define  KNEE                                Art.bit.b48
#define  ABS_FLAG                            Art.bit.b49
#define  HANDANOSCREENFORNOPOWER             Art.bit.b50
#define  AUTOBACKGROUNDLING                  Art.bit.b51

#define  CAN1_INTERRUPT_FLAG                 Art.bit.b52
#define  CAN1_BUSOFF_FLAG                    Art.bit.b53

#define  HOUWUDENG_FUWEI                     Art.bit.b54
#define  LAST_HOUWU                     	 Art.bit.b55
#define  LIZUO_FLAG                     	 Art.bit.b56

#define	 START_FLAG							 Art.bit.b58
#define  KMG_FLAG 			   				 Art.bit.b59
#define  ZUO_FLAG 			   				 Art.bit.b60
#define  YOU_FLAG 			  				 Art.bit.b61

// 蜂鸣器打开关闭
#define BUZZ(state)	  GPIO_Set_Output_Data_Bits(GPIOF_SFR,GPIO_PIN_MASK_2, state)	

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

#define RIGHT_HZ       (blinker > 17)

extern volatile uint8_t     BcanDelay,DcanDelay,PcanDelay,TcanDelay;

extern TYPE_BYTE  DisplaySymbol[8];
extern uint8_t dis_mod;



//仪表参数全局变量
extern uint8_t     Air_Alarm,Speed_Alarm,Oil_Alarm,Ranyou_Alarm,Air_Coef,Air2_Coef,Coef,Oil_Alarm_2012;
extern uint8_t     Rain_Delay_Time,Fuel_Coef;
extern uint8_t     backlight_level,Bus_Type,Coef_2012;
extern uint16_t    odometer_const,odometer_const_2012,Pulse,Pulse_const_2012;
extern uint16_t    speed_count;

//仪表设置全局变量
extern uint8_t     Set_Air_Alarm,Set_Speed_Alarm,Set_Oil_Alarm,Set_Ranyou_Alarm,Set_Air_Coef,Set_Air2_Coef,Set_Coef;
extern uint8_t     Set_Rain_Delay_Time,Set_Fuel_Coef;
extern uint8_t     Set_backlight_level,Set_Bus_Type;
extern uint16_t    Set_odometer_const,Set_odometer_const_2012,Set_Pulse;
extern uint8_t     Set_buzz;
extern volatile    uint8_t     speed_life;
extern uint8_t     Temp_Vbat,Temp_Ranyou;
extern uint8_t     fuel_percent;
extern uint8_t     blinker;
//仪表传感器
extern Meter meter;
//蓄电池电压
extern volatile    uint16_t Vbat;

extern volatile    uint16_t    eng_speed;      //engine speed
extern volatile    uint16_t    veh_speed;      //vehicle speed
extern volatile    uint16_t    veh_speed_display;
extern volatile    uint16_t    veh_bar1;
extern volatile    uint16_t    veh_bar2;
extern volatile    uint16_t    veh_soc;
extern volatile    uint8_t     bootloader,bootcmd;

//总里程
extern uint32_t   Veh_odo,odo;
//小计里程
extern uint16_t   Veh_trip;
extern uint32_t   mileaddress,paraddress;
extern uint8_t    Send[8];


//协议定义变量
extern volatile uint16_t Battery_Charge_Curr, Battery_chong_Curr, Battery_fang_Curr;
extern volatile uint16_t Battery_High_Volt, Battery_Low_Volt, Charge_Remain_time, Drive_mile;
extern volatile uint8_t     An_Kai_Handle_Time,_0CFF0C4A[8],_0CFF0D4A[8],Aver_Dianhao,Break_Pent,jiasu,jiansu;

extern TYPE_BYTE tony;
#define RROG_INIT  (tony.byte == 0)
#define RROG_BIT0   tony.bit.b0
#define RROG_BIT1   tony.bit.b1
#define RROG_END    tony.byte = 0



//参数初始化以及
void initdata(void);
void CaultOdo(void);








void j1939_tx_50ms(void);

void Light(void);
void SystemLogic(void);
void BuzzLogic(void);
void Acquisition_Task(void);
void calulate_speed(void);
void Sendspeed(void);









#endif

