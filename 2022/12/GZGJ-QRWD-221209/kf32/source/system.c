/*
 * system.c
 *
 *  Created on: 2021-8-5
 *      Author: ART
 */


#include "system_init.h"
#include "system.h"
#include "MeterConfig.h"

TYPE_QWORD  Art,Syslogic,CAN1_2_CAN2;
uint8_t     niuniu;
uint8_t     communicate_T123_data[12] = {0xaa,};
volatile    uint32_t    SysTickPer1ms;
// A5,A15
volatile    uint32_t    A15Count,A5Count;

//鎬婚噷绋�
uint32_t    Veh_odo,Pre_odo,Set_Veh_odo,odo,time;
//灏忚閲岀▼
uint16_t    Veh_trip;
TYPE_BYTE   DisplaySymbol[8];
//钃勭數姹犵數鍘�
volatile    uint16_t    Vbat;
volatile    uint16_t    eng_speed;      //engine speed
volatile    uint16_t    veh_speed;      //vehicle speed
volatile    uint16_t    veh_speed_display;
volatile    uint16_t    veh_bar1;
volatile    uint16_t    veh_bar2;
volatile    uint16_t    veh_soc;
uint16_t    speed_count;


//铚傞福鍣�
uint8_t     blinker,blinkerfast;
volatile    uint8_t     BcanDelay,DcanDelay,PcanDelay,TcanDelay;
rtc_t       rtc;
uint8_t     Send[8];
//杞�璁＄畻life
volatile uint8_t     speed_life;
volatile uint8_t     bootloader,bootcmd;
//鍗忚瀹氫箟鍙橀噺  Remain_Energy
volatile uint16_t Battery_chong_Curr, Battery_fang_Curr;
volatile uint16_t Battery_High_Volt, Battery_Low_Volt, Charge_Remain_time, Drive_mile;
volatile uint8_t  An_Kai_Handle_Time,_0CFF0C4A[8],_0CFF0D4A[8],Aver_Dianhao,Break_Pent;
volatile uint8_t  Uart2Receive[8],ReceIndex;

//钃勭數姹犳俯搴�
uint8_t  Temp_Vbat,Temp_Engine;
volatile uint16_t  fuel_percent;
volatile uint8_t FrontCurrent[16],RearCurrent[16],TopCurrent[16];
TYPE_BYTE tony,metre_state[2];
volatile u8 luntai_count[5] = {0};








void initdata(void)
{
	Set_Rain_Delay_Time = Rain_Delay_Time;
	Set_odometer_const  = odometer_const;
	Set_Veh_odo         = Veh_odo;
	Set_Pulse           = Pulse;
	Set_Coef            = Coef;
	Set_Air2_Coef       = Air2_Coef;
	Set_Air_Coef        = Air_Coef;
	Set_Fuel_Coef       = Fuel_Coef;
	Set_Speed_Alarm     = Speed_Alarm;
	Set_Air_Alarm       = Air_Alarm;
	Set_Oil_Alarm       = Oil_Alarm;
	Set_Ranyou_Alarm    = Ranyou_Alarm;
	SET_VIDEO_AV1       = VIDEO_AV_GRAR;
	SET_VIDEO_AV2       = VIDEO_AV_MID;
	SET_VIDEO_AV3       = VIDEO_AV_FRO;
	SET_VIDEO_AV4       = VIDEO_AV_ELSE;
	SET_RAIN            = RAIN_STATE;

	odo = Veh_odo;
	odometer_const_2012 = odometer_const;
	Coef_2012           = Coef;
	Pulse_const_2012 = Pulse;
	//MPC5602_CALL_T123 = 1;
}

void CaultOdo(void)
{
    uint8_t data[8];

	Veh_odo++;
	if(Veh_odo != Pre_odo)
	{
		Pre_odo = Veh_odo;
		SaveVehodo();
	}
	data[0] = Veh_odo;
	data[1] = Veh_odo >> 8;
	data[2] = Veh_odo >> 16;
	data[3] = Veh_odo >> 24;
	data[4] = mileaddress;
	data[5] = mileaddress >> 8;
	data[6] = mileaddress >> 16;
	data[7] = mileaddress >> 24;
	
    Can1_Tx_Standard_Bytes(0x521,data,8);

}

void SendCopyData(uint8_t *Des,volatile uint8_t *Souc,uint8_t n)
{
   uint8_t i;
   for(i = 0;i < n;i++)
   	Des[i] = Souc[i];
}



/*************************************************************************
* Function Name    : j1939_tx
* Description         : this function is send CAN message to J1939
* Parameters         : None
* Return Value       :None
**************************************************************************/
void CAN2_SEND1()
{
	u8 i,data[8];
	if(_0C04A1A7_FLAG)
	{
		_0C04A1A7_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _0C04A1A7_DATA[i];
		Can2_Tx_Bytes(0x0C04A1A7,data,8);
	}
	
	if(_0C07A1A7_FLAG)
	{
		_0C07A1A7_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _0C07A1A7_DATA[i];
		Can2_Tx_Bytes(0x0C07A1A7,data,8);
	}

	if(_0C09A1A7_FLAG)
	{
		_0C09A1A7_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _0C09A1A7_DATA[i];
		Can2_Tx_Bytes(0x0C09A1A7,data,8);
	}

	if(_0C0CA7F2_FLAG)
	{
		_0C0CA7F2_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _0C0CA7F2_DATA[i];
		Can2_Tx_Bytes(0x0C0CA7F2,data,8);
	}

	if(_0C0AA7F0_FLAG)
	{
		_0C0AA7F0_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _0C0AA7F0_DATA[i];
		Can2_Tx_Bytes(0x0C0AA7F0,data,8);
	}

	if(_0C01F4A7_FLAG)
	{
		_0C01F4A7_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _0C01F4A7_DATA[i];
		Can2_Tx_Bytes(0x0C01F4A7,data,8);
	}

	if(_0C08A7F4_FLAG)
	{
		_0C08A7F4_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _0C08A7F4_DATA[i];
		Can2_Tx_Bytes(0x0C08A7F4,data,8);
	}

	if(_180AA7A3_FLAG)
	{
		_180AA7A3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180AA7A3_DATA[i];
		Can2_Tx_Bytes(0x180AA7A3,data,8);
	}

	if(_180BA7A3_FLAG)
	{
		_180BA7A3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180BA7A3_DATA[i];
		Can2_Tx_Bytes(0x180BA7A3,data,8);
	}

}
void CAN2_SEND2()
{
	u8 i,data[8];
	if(_180CA7A3_FLAG)
	{
		_180CA7A3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180CA7A3_DATA[i];
		Can2_Tx_Bytes(0x180CA7A3,data,8);
	}
	
	if(_0C01A70A_FLAG)
	{
		_0C01A70A_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _0C01A70A_DATA[i];
		Can2_Tx_Bytes(0x0C01A70A,data,8);
	}

	if(_0C02A70A_FLAG)
	{
		_0C02A70A_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _0C02A70A_DATA[i];
		Can2_Tx_Bytes(0x0C02A70A,data,8);
	}

	if(_0C03A70A_FLAG)
	{
		_0C03A70A_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _0C03A70A_DATA[i];
		Can2_Tx_Bytes(0x0C03A70A,data,8);
	}

	if(_0C04A70A_FLAG)
	{
		_0C04A70A_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _0C04A70A_DATA[i];
		Can2_Tx_Bytes(0x0C04A70A,data,8);
	}

	if(_1818D0F3_FLAG)
	{
		_1818D0F3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _1818D0F3_DATA[i];
		Can2_Tx_Bytes(0x1818D0F3,data,8);
	}

	if(_1819D0F3_FLAG)
	{
		_1819D0F3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _1819D0F3_DATA[i];
		Can2_Tx_Bytes(0x1819D0F3,data,8);
	}

	if(_181AD0F3_FLAG)
	{
		_181AD0F3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _181AD0F3_DATA[i];
		Can2_Tx_Bytes(0x181AD0F3,data,8);
	}

	if(_181BD0F3_FLAG)
	{
		_181BD0F3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _181BD0F3_DATA[i];
		Can2_Tx_Bytes(0x181BD0F3,data,8);
	}

}


void CAN2_SEND3()
{
	u8 i,data[8];
	if(_181CD0F3_FLAG)
	{
		_181CD0F3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _181CD0F3_DATA[i];
		Can2_Tx_Bytes(0x181CD0F3,data,8);
	}
	
	if(_181DD0F3_FLAG)
	{
		_181DD0F3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _181DD0F3_DATA[i];
		Can2_Tx_Bytes(0x181DD0F3,data,8);
	}

	if(_181ED0F3_FLAG)
	{
		_181ED0F3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _181ED0F3_DATA[i];
		Can2_Tx_Bytes(0x181ED0F3,data,8);
	}

	if(_180028F3_FLAG)
	{
		_180028F3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180028F3_DATA[i];
		Can2_Tx_Bytes(0x180028F3,data,8);
	}

	if(_180128F3_FLAG)
	{
		_180128F3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180128F3_DATA[i];
		Can2_Tx_Bytes(0x180128F3,data,8);
	}

	if(_180228F3_FLAG)
	{
		_180228F3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _1818D0F3_DATA[i];
		Can2_Tx_Bytes(0x180228F3,data,8);
	}


	if(_180328F3_FLAG)
	{
		_180328F3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180328F3_DATA[i];
		Can2_Tx_Bytes(0x180328F3,data,8);
	}

	if(_180428F3_FLAG)
	{
		_180428F3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180428F3_DATA[i];
		Can2_Tx_Bytes(0x180428F3,data,8);
	}
	if(_180528F3_FLAG)
	{
		_180528F3_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180528F3_DATA[i];
		Can2_Tx_Bytes(0x180528F3,data,8);
	}

}


void CAN2_SEND4()
{
	u8 i,data[8];
	if(_180028F4_FLAG)
	{
		_180028F4_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180028F4_DATA[i];
		Can2_Tx_Bytes(0x180028F4,data,8);
	}
	
	if(_180128F4_FLAG)
	{
		_180128F4_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180128F4_DATA[i];
		Can2_Tx_Bytes(0x180128F4,data,8);
	}

	if(_180228F4_FLAG)
	{
		_180228F4_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180228F4_DATA[i];
		Can2_Tx_Bytes(0x180228F4,data,8);
	}

	if(_180328F4_FLAG)
	{
		_180328F4_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180328F4_DATA[i];
		Can2_Tx_Bytes(0x180328F4,data,8);
	}

	if(_0CFFF3A7_FLAG)
	{
		_0CFFF3A7_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _0CFFF3A7_DATA[i];
		Can2_Tx_Bytes(0x0CFFF3A7,data,8);
	}

	if(_0CFEEC21_FLAG)
	{
		_0CFEEC21_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _0CFEEC21_DATA[i];
		Can2_Tx_Bytes(0x0CFEEC21,data,8);
	}

	if(_18EBA1A5_FLAG)
	{
		_18EBA1A5_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _18EBA1A5_DATA[i];
		Can2_Tx_Bytes(0x18EBA1A5,data,8);
	}

	if(_18EFA1A5_FLAG)
	{
		_18EFA1A5_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _18EFA1A5_DATA[i];
		Can2_Tx_Bytes(0x18EFA1A5,data,8);
	}
	if(_1819A100_FLAG)
	{
		_1819A100_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _1819A100_DATA[i];
		Can2_Tx_Bytes(0x1819A100,data,8);
	}

}


void CAN2_SEND5()
{
	u8 i,data[8];
	if(_180028F4_FLAG)
	{
		_180028F4_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180028F4_DATA[i];
		Can2_Tx_Bytes(0x180028F4,data,8);
	}
	
	if(_180128F4_FLAG)
	{
		_180128F4_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180128F4_DATA[i];
		Can2_Tx_Bytes(0x180128F4,data,8);
	}

	if(_180228F4_FLAG)
	{
		_180228F4_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180228F4_DATA[i];
		Can2_Tx_Bytes(0x180228F4,data,8);
	}

	if(_180328F4_FLAG)
	{
		_180328F4_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _180328F4_DATA[i];
		Can2_Tx_Bytes(0x180328F4,data,8);
	}

	if(_0CFFF3A7_FLAG)
	{
		_0CFFF3A7_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _0CFFF3A7_DATA[i];
		Can2_Tx_Bytes(0x0CFFF3A7,data,8);
	}

	if(_0CFEEC21_FLAG)
	{
		_0CFEEC21_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _0CFEEC21_DATA[i];
		Can2_Tx_Bytes(0x0CFEEC21,data,8);
	}


	if(_18EBA1A5_FLAG)
	{
		_18EBA1A5_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _18EBA1A5_DATA[i];
		Can2_Tx_Bytes(0x18EBA1A5,data,8);
	}

	if(_18EFA1A5_FLAG)
	{
		_18EFA1A5_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _18EFA1A5_DATA[i];
		Can2_Tx_Bytes(0x18EFA1A5,data,8);
	}
	if(_1819A100_FLAG)
	{
		_1819A100_FLAG = 0;
		for(i=0;i<8;i++)
			data[i] = _1819A100_DATA[i];
		Can2_Tx_Bytes(0x1819A100,data,8);
	}

}


void CAN2_SEND(void)
{
    static u8 loop = 1;
	if(loop == 1)
	{
		CAN2_SEND1();
	}
	else if(loop == 2)
	{
		CAN2_SEND2();
	}
	else if(loop == 3)
	{
		CAN2_SEND3();
	}
	else if(loop == 4)
	{
		CAN2_SEND4();
	}
	else if(loop == 5)
	{
		CAN2_SEND5();
		loop = 0;
	}
	loop ++;

}






/*************************************************************************
* Function Name    : j1939_tx
* Description         : this function is send CAN message to J1939
* Parameters         : None
* Return Value       :None
**************************************************************************/
void j1939_tx_100ms(void)
{
    u32 odotemp;
    u8 data[8],i;	
	u16 u16_data;
	static u8 time_1s = 0;

	for(i = 0;i <8;i++)
		data[i] = 0;
	
	metre_state[0].bit.b0 = DEFINE_TIP_AIR_LOW;
	metre_state[0].bit.b1 = LED_PARK_SW;
	metre_state[0].bit.b2  = LED_ENG_DOOR_SW;
	metre_state[0].bit.b3  = LED_FRONT_DOOR_SW;
	metre_state[0].bit.b4  = LED_MIDDLE_DOOR_SW;
	metre_state[0].bit.b5  = KEY_ON;
	metre_state[0].bit.b6  = KEY_ACC;
	metre_state[0].bit.b7  = KEY_EMG;

	metre_state[1].bit.b0	= LED_RFOG_SW;				   // �����
	metre_state[1].bit.b1	= LED_LBEAM_SW; 				//����
	metre_state[1].bit.b2	= LED_PREHEAT_SW;			 //Զ���
	metre_state[1].bit.b3	= UNUSED;
	metre_state[1].bit.b4	= RIGHT_LED_SW;
	metre_state[1].bit.b5	= LED_FFOG_SW;
	metre_state[1].bit.b6	= LED_HBEAM_SW; 				 //Զ���
	metre_state[1].bit.b7	= LEFT_LED_SW;

	data[0] = metre_state[0].byte;
	data[1] = metre_state[1].byte;	
	metre_state[1].byte = 0;
	metre_state[1].bit.b0 = AIR1_LOW||AIR2_LOW;
	metre_state[1].bit.b1 = WATER_SW;
	metre_state[1].bit.b2 = 0;
	metre_state[1].bit.b3 = 0;
	metre_state[1].bit.b4 = 0;
	metre_state[1].bit.b5 = 0;
	data[2] = metre_state[1].byte;
	data[3] = veh_speed_display/5;
	u16_data = veh_bar1 * 100;
	data[4] = GetU16Low(u16_data);
	data[5] = GetU16High(u16_data);
	u16_data = veh_bar2 * 100;
	data[6] = GetU16Low(u16_data);
	data[7] = GetU16High(u16_data);
	
	Can1_Tx_Bytes(0x0C19A7A1,data,8);
	Can2_Tx_Bytes(0x0C19A7A1,data,8);


	for(i = 0;i <8;i++)
		data[i] = 0;
	if(Extinguisher.timecalibration)
	{
		Extinguisher.timecalibration ++;
		if(Extinguisher.timecalibration >=5)
		{
			Extinguisher.timecalibration = 0;			
		}
			data[0] = rtc.year;
			data[1] = rtc.month;
			data[2] = rtc.day;
			data[3] = rtc.hours;
			data[4] = rtc.mins;
			data[5] = rtc.secs;
			data[6] = 0;
			data[7] = 0;	
			Can1_Tx_Bytes(0x18EFA5A1,data,8);
		    Can2_Tx_Bytes(0x18EFA5A1,data,8);
	}

	if(time_1s<10)
	{
		time_1s ++;
	}
	else
	{	
		for(i = 0;i <8;i++)
			data[i] = 0;
		time_1s = 0;

		odotemp = Veh_odo*10;
		data[0] = odotemp;
		data[1] = odotemp>>8;
		data[2] = odotemp>>16;
		data[3] = odotemp>>24;
		data[4] = Veh_trip;
		data[5] = Veh_trip >> 8;
		data[6] = 0;
		data[7] = 0;
		Can1_Tx_Bytes(0x0C1AA7A1,data,8);
		Can2_Tx_Bytes(0x0C1AA7A1,data,8);

		
		for(i = 0;i <8;i++)
			data[i] = 0;

		data[0] = 4*rtc.secs;
		data[1] = rtc.mins;
		data[2] = rtc.hours;
		data[3] = rtc.month;
		data[4] = 4*rtc.day;
		data[5] = rtc.year;
		data[6] = 0;
		data[7] = 0;	
		Can1_Tx_Bytes(0x18FEE617,data,8);
		Can2_Tx_Bytes(0x18FEE617,data,8);
	}
/**************************************************************/

}

enum
{
   normal = 0,
   update,   
   check = 6,
};

uint8_t version[8];

void Edition(void)
{
	version[0] = 0x06;
	version[1] = 0x05;
	version[2] = 0x30;
	version[3] = 0x00;
	version[4] = 0x02;//01:BOOT模式 02:APP模式
	version[5] = 0x21;
	version[6] = 0x12;
	version[7] = 0x01;
	Can0_Tx_Standard_Bytes(0x52e,version,8);
}

void UpdateSomeing(void)
{
  if(bootloader == check)
  {
    bootloader = normal;
	Edition();
  }
  if(bootcmd == 0xa0)
  {
    bootcmd = 0;
    ERASEPAGE(0x7b000);
	SYSCTL_System_Reset_Enable(TRUE);
  }
}

void Light(void)
{
    static float single_mile;
	C3_Sign_OUT(veh_speed,Pulse);
    //UpdateSomeing();
	//Veh_odo++;
#if (!CALULATE_SPEED_ENABLE)
	if(KEY_ON)
	{
		 //speed_life++;
		 single_mile = single_mile + (float)(veh_speed*Coef*0.01/72.0);
		 if((single_mile >= 100.0))
		 {
			 single_mile = single_mile - 100.0;
			 Veh_trip++;
			 if(Veh_trip > 9999)
				 Veh_trip = 0;
		     if((Veh_trip % 10) == 0)
		     {
				 Veh_odo++;
		     }
		 }

	 }
 #endif

}





static void Rool_Alarm_Handle(void)
{
    static uint16_t time = 0,buzz_time,timexx;
    static uint8_t add_time,add_flag,flag_30s,flag_10s,pre_door_time,xx = 0;
	//static u8 luntai_count[5] = {0};
    TIP_FRONT_A1_SHORT  = ((F_OPEN1_A1 == 1) && (F_OUT1_A1 == 2))?1:0;              //
    TIP_FRONT_A2_SHORT  = ((F_OPEN3_A2 == 1) && (F_OUT3_A2 == 2))?1:0;              //
    TIP_FRONT_A3_SHORT  = ((F_OPEN5_A3 == 1) && (F_OUT5_A3 == 2))?1:0;              //
    TIP_FRONT_A4_SHORT  = ((F_OPEN7_A4 == 1) && (F_OUT7_A4 == 2))?1:0;              //
    TIP_FRONT_A5_SHORT  = ((F_OPEN9_A5 == 1) && (F_OUT9_A5 == 2))?1:0;              //
    TIP_FRONT_A6_SHORT  = ((F_OPEN11_A6 == 1) && (F_OUT11_A6 == 2))?1:0;            //
    TIP_FRONT_A7_SHORT  = ((F_OPEN13_A7 == 1) && (F_OUT13_A7 == 2))?1:0;            //
    TIP_FRONT_A8_SHORT  = ((F_OPEN15_A8 == 1) && (F_OUT15_A8 == 2))?1:0;            //
    TIP_FRONT_A9_SHORT  = ((F_OPEN2_A9 == 1) && (F_OUT2_A9 == 2))?1:0;          //
    TIP_FRONT_A10_SHORT = ((F_OPEN4_A10 == 1) && (F_OUT4_A10 == 2))?1:0;            //
    TIP_FRONT_A11_SHORT = ((F_OPEN6_A11 == 1) && (F_OUT6_A11 == 2))?1:0;            //
    TIP_FRONT_A12_SHORT = ((F_OPEN8_A12 == 1) && (F_OUT8_A12 == 2))?1:0;            //
    TIP_FRONT_A13_SHORT = ((F_OPEN10_A13 == 1) && (F_OUT10_A13 == 2))?1:0;          //
    TIP_FRONT_A14_SHORT = ((F_OPEN12_A14 == 1) && (F_OUT12_A14 == 2))?1:0;          //
    TIP_FRONT_A42_SHORT = ((F_OPEN14_A42 == 1) && (F_OUT14_A42 == 2))?1:0;          //


    TIP_REAR_A1_SHORT  = ((R_OPEN1_A1 == 1) && (R_OUT1_A1 == 2))?1:0;               //
    TIP_REAR_A2_SHORT  = ((R_OPEN3_A2 == 1) && (R_OUT3_A2 == 2))?1:0;               //
    TIP_REAR_A3_SHORT  = ((R_OPEN5_A3 == 1) && (R_OUT5_A3 == 2))?1:0;               //
    TIP_REAR_A4_SHORT  = ((R_OPEN7_A4 == 1) && (R_OUT7_A4 == 2))?1:0;               //
    TIP_REAR_A5_SHORT  = ((R_OPEN9_A5 == 1) && (R_OUT9_A5 == 2))?1:0;               //
    TIP_REAR_A6_SHORT  = ((R_OPEN11_A6 == 1) && (R_OUT11_A6 == 2))?1:0;         //
    TIP_REAR_A7_SHORT  = ((R_OPEN13_A7 == 1) && (R_OUT13_A7 == 2))?1:0;         //
    TIP_REAR_A8_SHORT  = ((R_OPEN15_A8 == 1) && (R_OUT15_A8 == 2))?1:0;         //
    TIP_REAR_A9_SHORT   = ((R_OPEN2_A9 == 1) && (R_OUT2_A9 == 2))?1:0;          //
    TIP_REAR_A10_SHORT  = ((R_OPEN4_A10 == 1) && (R_OUT4_A10 == 2))?1:0;            //
    TIP_REAR_A11_SHORT  = ((R_OPEN6_A11 == 1) && (R_OUT6_A11 == 2))?1:0;            //
    TIP_REAR_A12_SHORT  = ((R_OPEN8_A12 == 1) && (R_OUT8_A12 == 2))?1:0;            //
    TIP_REAR_A13_SHORT  = ((R_OPEN10_A13 == 1) && (R_OUT10_A13 == 2))?1:0;          //
    TIP_REAR_A14_SHORT  = ((R_OPEN12_A14 == 1) && (R_OUT12_A14 == 2))?1:0;          //
    TIP_REAR_A42_SHORT  = ((R_OPEN14_A42 == 1) && (R_OUT14_A42 == 2))?1:0;          //



    TIP_TOP_A1_SHORT  = ((T_OPEN1_A1 == 1) && (T_OUT1_A1 == 2))?1:0;                //
    TIP_TOP_A2_SHORT  = ((T_OPEN3_A2 == 1) && (T_OUT3_A2 == 2))?1:0;                //
    TIP_TOP_A3_SHORT  = ((T_OPEN5_A3 == 1) && (T_OUT5_A3 == 2))?1:0;                //
    TIP_TOP_A4_SHORT  = ((T_OPEN7_A4 == 1) && (T_OUT7_A4 == 2))?1:0;                //
    TIP_TOP_A5_SHORT  = ((T_OPEN9_A5 == 1) && (T_OUT9_A5 == 2))?1:0;                //
    TIP_TOP_A6_SHORT  = ((T_OPEN11_A6 == 1) && (T_OUT11_A6 == 2))?1:0;              //
    TIP_TOP_A7_SHORT  = ((T_OPEN13_A7 == 1) && (T_OUT13_A7 == 2))?1:0;              //
    TIP_TOP_A8_SHORT  = ((T_OPEN15_A8 == 1) && (T_OUT15_A8 == 2))?1:0;             //
    TIP_TOP_A9_SHORT    = ((T_OPEN2_A9 == 1) && (T_OUT2_A9 == 2))?1:0;             //
    TIP_TOP_A10_SHORT   = ((T_OPEN4_A10 == 1) && (T_OUT4_A10 == 2))?1:0;            //
    TIP_TOP_A11_SHORT   = ((T_OPEN6_A11 == 1) && (T_OUT6_A11 == 2))?1:0;            //
    TIP_TOP_A12_SHORT   = ((T_OPEN8_A12 == 1) && (T_OUT8_A12 == 2))?1:0;            //
    TIP_TOP_A13_SHORT   = ((T_OPEN10_A13 == 1) && (T_OUT10_A13 == 2))?1:0;          //
    TIP_TOP_A14_SHORT   = ((T_OPEN12_A14 == 1) && (T_OUT12_A14 == 2))?1:0;          //
    TIP_TOP_A42_SHORT   = ((T_OPEN14_A42 == 1) && (T_OUT14_A42 == 2))?1:0;          //

    TIP_0X37 = ((METER_OPEN_WAKE_UP == 1) && (METER_OUT_WAKE_UP == 2))?1:0;
    TIP_0X38 = 0;

#if 1
    TIP_0X3C  =   ((METER_OPEN_E3 == 1) && (METER_OUT_E3 == 2))?1:0;
    TIP_0X3D  =   ((METER_OPEN_E6 == 1) && (METER_OUT_E6 == 2))?1:0;	
    TIP_0X3E  =   ((METER_OPEN_E7== 1)  && (METER_OUT_E7== 2))?1:0;
    TIP_0X3F  =   ((METER_OPEN_E8 == 1) && (METER_OUT_E8 == 2))?1:0;


	
	TIP_0X44 = DEFINE_TIP_LEAST_VOLT;
	TIP_0X45 = DEFINE_TIP_AIR_LOW;//DEFINE_TIP_AIR_LOW;
	TIP_0X46 = UNUSED;
	TIP_0X47 = UNUSED;//DEFINE_TIP_PLANT_ALARM;
	TIP_0X48 = DEFINE_TIP_SPEED;
	TIP_0X49 = UNUSED;
	TIP_0X4A = UNUSED;
	TIP_0X4B = UNUSED;
	TIP_0X4C = UNUSED;
	TIP_0X4D = UNUSED;
	TIP_0X4E = UNUSED;
	TIP_0X4F = ((BMS.istatus[0]&0x80)==0x80);
	TIP_0X50 = ((BMS.istatus[0]&0x40)==0x40);
	TIP_0X51 = ((BMS.istatus[0]&0x20)==0x20);
	TIP_0X52 = ((BMS.istatus[0]&0x10)==0x10);
	TIP_0X53 = ((BMS.istatus[0]&0x08)==0x08);
	TIP_0X54 = ((BMS.istatus[0]&0x04)==0x04);
	TIP_0X55 = ((BMS.istatus[0]&0x02)==0x02);
	TIP_0X56 = ((BMS.istatus[0]&0x01)==0x01);
	TIP_0X57 = ((BMS.istatus[1]&0x80)==0x80);
	TIP_0X58 = ((BMS.istatus[1]&0x40)==0x40);
	TIP_0X59 = ((BMS.istatus[1]&0x20)==0x20);
	TIP_0X5A= ((BMS.istatus[1]&0x10)==0x10);
	TIP_0X5B= ((BMS.istatus[1]&0x08)==0x08);
	TIP_0X5C= ((BMS.istatus[1]&0x04)==0x04);
	TIP_0X5D= ((BMS.istatus[1]&0x02)==0x02);
	TIP_0X5E= ((BMS.istatus[1]&0x01)==0x01);

	TIP_0X5F = 0;//(RUNHUA[1]&0x40==0x40);
	TIP_0X60 = 0;
	TIP_0X61 = 0;
	TIP_0X62 = 0;
	TIP_0X63 = 0;
	TIP_0X64 = 0;
	TIP_0X65 = 0;
	TIP_0X66 = UNUSED;//(BMS.isystem_fault==1);
	 TIP_0X67 = ((BMS.status_flag4&0x02)==0x02);
	 TIP_0X68 = ((BMS.status_flag4&0x01)==0x01);
	 TIP_0X69 = ((BMS.status_flag5&0x02)==0x02);
	 TIP_0X6A = ((BMS.status_flag5&0x01)==0x01);
	 TIP_0X6B = (Extinguisher.faultcode==0x02);
	 TIP_0X6C = (Extinguisher.faultcode==0x03);
	 TIP_0X6D = (((AlarmFlag[1]&0x80)==0x80)||((E_MotorError[0]&0x40)==0x40)||((E_MotorError[1]&0x01)==0x01));
	 TIP_0X6E = ((AlarmFlag[2]&0x02)==0x02);
	 TIP_0X6F = UNUSED;//((E_MotorError[0]&0x40)==0x40);
	 TIP_0X70 = UNUSED;//(((E_MotorError[1]&0x04)==0x04);
	 TIP_0X71 = UNUSED;//(((E_MotorError[1]&0x01)==0x01);
	 TIP_0X72 = UNUSED;
	 TIP_0X73 = UNUSED;
     TIP_0X74 = UNUSED;
	 TIP_0X76 = UNUSED;((BMS.istatus[2]&0X80)==0X80);
	 TIP_0X77 = UNUSED;((BMS.istatus[2]&0X10)==0X10);	 
	 TIP_0X78 = UNUSED;
	 TIP_0X79 = UNUSED;
	 TIP_0X7A = UNUSED ; //((BMS.istatus[2]&0x01)==0x01);
	 TIP_0X7B = EMERGENCY_FRONT_OUT_SW;
	 
	 TIP_0X7C = UNUSED;
	 TIP_0X7D = UNUSED;
	 TIP_0X7E = UNUSED;
	 TIP_0X7F = UNUSED;
	 TIP_0X80 = UNUSED;
	 TIP_0X81 = UNUSED;
	 TIP_0X82 = UNUSED;
	 TIP_0X83 = UNUSED;
	TIP_0X84 = UNUSED;//((SystemStatus&0x30)==0x20);
    TIP_0X85 = UNUSED;
    TIP_0X86 = UNUSED;
	TIP_0X87 = PLANT_LEFT_F;
	TIP_0X88 = PLANT_RIGHT_F;
	TIP_0X89 = EMERGENCY_FRONT_INT_SW;
   TIP_0X8A = EMERGENCY_MID_INT_SW;
   TIP_0X8B = EMERGENCY_MID_OUT_SW;
   TIP_0X8C = UNUSED;
   TIP_0X8D = PTA10;
   TIP_0X8E = ((BMS.status_flag4&0x80)==0x80);
   TIP_0X8F = ((BMS.status_flag4&0x40)==0x40);
   TIP_0X90 = ((BMS.status_flag4&0x20)==0x20);
   TIP_0X91 = ((BMS.status_flag4&0x10)==0x10);
   TIP_0X92 = ((BMS.status_flag5&0x20)==0x20);
   TIP_0X93 = ((BMS.status_flag5&0x10)==0x10);
   TIP_0X94 = ((BMS.status_flag5&0x08)==0x08);
   TIP_0X95 = ((BMS.status_flag5&0x04)==0x04);
   TIP_0X96 = UNUSED;
   TIP_0X97 = PLANT_RIGHT_R;
   TIP_0X98 = PLANT_LEFT_R;
   TIP_0X99 = UNUSED;//((add1[6].byte&0x03)==0x02);
   TIP_0X9A = UNUSED;//((add3[6].byte&0x0C)==0x04);
   TIP_0X9B = UNUSED;//((add3[6].byte&0x0C)==0x08);
   TIP_0X9C = UNUSED;//((add3[6].byte&0x0C)==0x0C);
   TIP_0X9D = WATER_SW;
#endif
   /*TIP_0XB9 = ((BAT_FIRE.status[0] & 0xf0) > 0);
   TIP_0XBA = ((BAT_FIRE.status[1] & 0xf0) > 0);
   TIP_0XBB = ((BAT_FIRE.status[2] & 0xf0) > 0);
   TIP_0XBC = ((BAT_FIRE.status[3] & 0xf0) > 0);
   TIP_0XBD = ((BAT_FIRE.status[4] & 0xf0) > 0);
   TIP_0XBE = ((BAT_FIRE.status[5] & 0xf0) > 0);
   TIP_0XBF = ((BAT_FIRE.status[6] & 0xf0) > 0);
   TIP_0XC0 = ((BAT_FIRE.status[7] & 0xf0) > 0);
   TIP_0XC1 = ((BAT_FIRE.status[8] & 0xf0) > 0);
   TIP_0XC2 = ((BAT_FIRE.status[9] & 0xf0) > 0);*/

#if CLOSE_DOOR_WANT_VOICE //鍏抽棬鏈変笁澹版彁绀洪煶锛屾敞鎰弍re_door_time瀹氫箟浠ュ強浣跨敤
		if(LED_FRONT_DOOR_SW || LED_MIDDLE_DOOR_SW)
		{
	
		   if((((!PRE_YOUQIAN_DOOR) && (LED_FRONT_DOOR_SW)) || ((!PRE_YOUZHONG_DOOR) && (LED_MIDDLE_DOOR_SW)))&&(veh_speed_display > 30))
		   {
			  pre_door_time = 20;
		   
		   	  PRE_YOUQIAN_DOOR = LED_FRONT_DOOR_SW;
		   	  PRE_YOUZHONG_DOOR = LED_MIDDLE_DOOR_SW;
		   }
		   if(veh_speed_display < 30)
		   	{
				PRE_YOUQIAN_DOOR = 0;
		   	  	PRE_YOUZHONG_DOOR = 0;
		   	}
		}
		else
		{
			PRE_YOUQIAN_DOOR = 0;
	   	  	PRE_YOUZHONG_DOOR = 0;
	   	}	
	
		 if(pre_door_time > 0)
		    pre_door_time--;
#endif



    BUZZ_Normal =SYMBOL_POSITION35||SYMBOL_POSITION07||SYMBOL_POSITION18||SYMBOL_POSITION19||SYMBOL_POSITION08||SYMBOL_POSITION09||SYMBOL_POSITION17\
	  ||TIP_0X48||TIP_0X49||TIP_0X4A||TIP_0X4B||TIP_0X4C||TIP_0X5D||TIP_0X68||TIP_0X79||TIP_0X7B||TIP_0X4F\
	 ||TIP_0X50||TIP_0X51||TIP_0X52||TIP_0X53||TIP_0X54||TIP_0X55||TIP_0X56||TIP_0X57||TIP_0X58||TIP_0X59||TIP_0X5A||TIP_0X5B||TIP_0X5C||TIP_0X5D\
	 ||TIP_0X5E||TIP_0X67||TIP_0X68||TIP_0X69||TIP_0X72||TIP_0X73||TIP_0X71||TIP_0X75||TIP_0X78||TIP_0X79||TIP_0X7A||TIP_0X6A\
	 ||TIP_0X7C||TIP_0X7D||TIP_0X7E||TIP_0X7F||TIP_0X80||TIP_0X81||TIP_0X82||TIP_0X83||TIP_0X84||TIP_0X85||TIP_0X86||\
	 TIP_0X87||TIP_0X88||TIP_0X89||TIP_0X8A||TIP_0X8B||TIP_0X8C||TIP_0X8E||TIP_0X8F||TIP_0X90||TIP_0X91||\
	 TIP_0X93||TIP_0X94||TIP_0X95||TIP_0X4E||TIP_0X97||TIP_0X98||TIP_0X96||TIP_0X99||TIP_0X9A||TIP_0X9B||TIP_0X9C||TIP_0X9D||\
	 ((SEATBELT_NO_SW|| SYMBOL_POSITION16) && (veh_speed_display > 30))||(pre_door_time > 0);
	
    BUZZ_Critical =  TIP_0X45||TIP_0X46||TIP_0X47;


}

//鑾峰彇鐕冩补
void  GetFuel(void)
{
	float fuel;
    uint16_t fuelsource;
	fuelsource = FUELSOURCE;
	#if(FUELTYPE == FUELFULL_180)
	if((fuelsource <= 6) || (fuelsource > 250))
		fuel = 0;
	else if(fuelsource <= 77)
		fuel = 0.7062*(fuelsource)-4.2373;
	else if(fuelsource <= 180)
		fuel = 0.4845*(fuelsource)+12.7907;
	else 
		fuel = 100;
	#elif(FUELTYPE == FUELFULL_6)
	if(fuelsource < 3)
		fuel = 100;
	else if(fuelsource <= 18)
		fuel = 105 - ((5*fuelsource)/3);
	else if((fuelsource <= 33))
		fuel = 107 - ((25*fuelsource)/14);
	else if((fuelsource <= 70))
		fuel = 71 - ((25*fuelsource)/38);
	else if((fuelsource <= 110))
		fuel = 69 - ((5*fuelsource)/8);
	else 
		fuel = 0;

	#endif
 
    fuel_percent = (fuel *0.01)* Fuel_Coef;
	if(fuel_percent>100)
	   fuel_percent = 100;
}

const u16 Frist_Temp_V[] = 
{
  1201,1158,1116,1075,1037,1000,964,930,897,865,835,806,778,751,725,700,676,653,631,609,589,//40
  569,550,532,514,497,478,463,448,433,418,406,393,381,369,357,346,335,325,315,305,296,287,//62
  278,269,261,253,246,238,231,224,218,211,205,199,193,188,182,177,172,167,162,158,153,149,//84
  145,141,137,133,129,126,123,119,116,113,110,107,104,101,99,96,94,91,89,87,84,82,80,78,76,//109
  74,72,70,69,67,65,64,62,60,59,58   //120
};



//���ز���
void  GetVbatTemp(void)
{
	u16 i,temp_va,data[8] = {0};
	temp_va = VBATTEMPSOUTCE;
	
	for(i = 0;i < 100;i++)//sizeof(Temp_Value)
	{
	   if(temp_va >= Frist_Temp_V[i])
	   {
		  Temp_Vbat = i+20;
		  break;
	   }
	}
	
	if(i == 0)
	   Temp_Vbat = 20; //浣庝簬20搴�
	   
	if(i == sizeof(Frist_Temp_V))
	   Temp_Vbat = 120;//瓒呰繃120搴�

	/*if(temp_va > 1500)
	{
	   Temp_Vbat = 0xff;//offline
	   return ;
	}*/

	//data[0] = Temp_Vbat;
	//Can1_Tx_Bytes(0x18ffd217,data,8);
	if(temp_va < 58)
		Temp_Vbat = 130;

}


//���������
void  GetEngineTemp(void)
{
	u16 i,temp_va;
	temp_va = ENGINETEMPSOUTCE;
	
	for(i = 0;i < 100;i++)//sizeof(Temp_Value)
	{
	   if(temp_va >= Frist_Temp_V[i])
	   {
		  Temp_Engine = i+20;
		  break;
	   }
	}
	
	if(i == 0)
	   Temp_Engine = 20; //浣庝簬20搴�
	   
	if(i == sizeof(Frist_Temp_V))
	   Temp_Engine = 120;//瓒呰繃120搴�

	/*if(temp_va > 1500)
	{
	   Temp_Engine = 0xff;//offline
	   return ;
	}*/
	if(temp_va < 58)
		Temp_Engine = 130;
}




void Acquisition_Bar(void)
{
    uint16_t i,bar1,bar2,soc_temp;
    if(AIR_TYPE == VOLT)
    {
        bar1 = Bar1Source;
        bar2 = Bar2Source;

        if((bar1 < 50)||(bar1 >= 380))
            veh_bar1 = 0;
        else if(bar1 >= 360)
            veh_bar1 = 120;
        else
            veh_bar1 = 0.4*(bar1 - 50);

        if((bar2 < 50)||(bar2 >= 380))
            veh_bar2 = 0;
        else if(bar2 >= 360)
            veh_bar2 = 120;
        else
            veh_bar2 = 0.4*(bar2 - 50);
    }
    else if(AIR_TYPE == RES)
    {
        bar1 = Bar1Source;
        bar2 = Bar2Source;
#if BAR_12
        if((bar1 < 10) || (bar1 > 250))
            veh_bar1 = 0;
        else
            veh_bar1 = 0.632*(bar1 - 10);

        if((bar2 < 10) || (bar2 > 250))
            veh_bar2 = 0;
        else
            veh_bar2 = 0.632*(bar2 - 10);

#endif

    }
    veh_bar1 = veh_bar1*0.01*Air_Coef;
    veh_bar2 = veh_bar2*0.01*Air2_Coef;

#if BAR_10
    if(veh_bar1 >= 100)
        veh_bar1 = 100;
    if(veh_bar2 >= 100)
        veh_bar2 = 100;
#endif
#if BAR_12
    if(veh_bar1 >= 120)
        veh_bar1 = 120;
    if(veh_bar2 >= 120)
        veh_bar2 = 120;
#endif

}


//閲囬泦鏁版嵁绋嬪簭锛�s閲囬泦涓�,鐩墠涓昏鏄噰闆嗘皵鍘嬪� 鍜�鐕冩枡鍊�
void Acquisition_Task ()
{
    get_date();
    Acquisition_Bar();
	#if USEDVBATTEMP
	GetVbatTemp();
    #endif
	#if USEDENGINETEMP
	GetEngineTemp();
    #endif
    #if USEDFUEL
    GetFuel();
   	#endif
}

uint8_t specical_buzz(uint8_t flag , uint16_t delay_time)
{
    static uint8_t time;
    if(flag)
    {
        time++;
        if(time >= delay_time)
        {
            time = delay_time;
            return 1;
        }
        else
            return 0;
    }
    else
    {
        time = 0;
        return 0;
    }
}

/*************************************************************************
* Function Name    : send_msg_bcm
* Description         : this function is send CAN message to BCM
* Parameters         : None
* Return Value       :None
**************************************************************************/
void Send_Msg_Bcm(void)
{
    uint8_t i,data[8];
    for(i = 0; i < 8; i++)
    {
       data[i] = ctrl_cmd[i].byte;
    }
	
	data[7] |= RAIN_STATE;
	i =  Rain_Delay_Time/20;
	data[7] |= (i << 4);

    
    Can0_Tx_Standard_Bytes(0x6a4,data,8);
    
}

//浠庨鐜囪绠楄溅閫�
void calulate_speed(void)
{
    static uint16_t cur_speed_freq,speed_freq;
    cur_speed_freq = meter.MeterA5;
    if(Pulse != 0)
    {
        veh_speed = 3600.0 / Pulse * cur_speed_freq ;
        if(veh_speed > 1400)
            veh_speed = 1400;

        veh_speed_display = (veh_speed*0.01)*Oil_Alarm;
    }
    else
        veh_speed = 0;

}

void SendCCVS(void)
{
    static u8 time = 0;
	u8 byte[8];
	TYPE_BYTE temp_u8;
    if(time>=2) //100*10ms
    {
		temp_u8.byte = 0;
		temp_u8.bit.b2 = LED_PARK_SW;
		byte[0] = temp_u8.byte;
		byte[1] = 0;	   
		byte[2] = veh_speed_display/10;
		byte[3] = 0;	  
		byte[4] = 0;
		byte[5] = 0;
		byte[6] = 0;
		byte[7] = 0;
		
		Can1_Tx_Bytes(0x18FEF117,byte,8);

        time = 0;
    }
    time ++;
}



void Sendspeed(void)
{
    u8 byte[8]= {0};
    u8 tmp_speed = veh_speed_display/ 10;
    byte[4] = 0;//GetU16Low(eng_speed);
    byte[5] = 0;//GetU16High(eng_speed);
    byte[6] = 0;
    byte[7] = tmp_speed;
    Can1_Tx_Bytes(0x0CFE6CEE,byte,8);
	//SendCCVS();
}



void BCMConfig(void)
{

    uint8_t i;
    static u8 toubiflag = 0,toubicount = 0,work_time;
    static uint8_t xx = 0;//600
    static uint8_t acc_time = 100;
    static u16 right_fuzhu_time = 0,timexx = 0,R_TimeCount = 0;
    static u16 left_fuzhu_time = 0;
	
#if  (Has_Fmode == ON)
    /*  Front BCM output ON & OFF   */
    F_OUT_P1    = UNUSED;
    F_OUT_P9    = UNUSED;
    F_OUT_P2    = UNUSED;
    F_OUT_P10   = ((SYSTEM_POW && RIGHT_LED_SW )|| KEY_EMG) && RIGHT_HZ;                                                 
    F_OUT_P3    = ((SYSTEM_POW && LEFT_LED_SW)|| KEY_EMG) && RIGHT_HZ;                     
    F_OUT_P11   = SYSTEM_POW && BACKLIGHT_SW;      
    F_OUT_P4    = SYSTEM_POW && HBEAM_SW;   
	F_OUT_P12   = SYSTEM_POW && LBEAM_SW && (!HBEAM_SW);
    F_OUT_P5    = SYSTEM_POW && FFOG_SW&& BACKLIGHT_SW;                                                  
    F_OUT_P13   = SYSTEM_POW && BUZZ_SW; 
    F_OUT_P6    = SYSTEM_POW && BACKLIGHT_SW && LED_FRONT_DOOR_SW;
    F_OUT_P14   = KEY_ON && CHUSHUANG_SW;   
    F_OUT_P7    = KEY_ON && CHUSHUANG_SW;
    F_OUT_P42   = KEY_ON && CHUSHUANG_SW_2;  
    F_OUT_P8    = KEY_ON && CHUSHUANG_SW_2;
    F_OUT_P17 = 0;
    if(fbcm_off_line < 10)
        fbcm_off_line++;
    TIP_FBCM_OFF          = ((fbcm_off_line > 9)?1:0); 

#endif

#if  (Has_Rmode == ON)

    R_OUT_P1	= F_OUT_P3; 
	R_OUT_P9	= F_OUT_P10;	
	R_OUT_P2	= (KEY_ON|| KEY_CHARGE);
	R_OUT_P10	= KEY_ON && (GUANTONG_SW || (BACKLIGHT_SW && LED_MIDDLE_DOOR_SW));
	R_OUT_P3	= KEY_ON && BREAK_SW;
	R_OUT_P11	= KEY_ON;					
	R_OUT_P4	= SYSTEM_POW &&(BREAK_SW || ELEC_BREAK);		
	R_OUT_P12	= SYSTEM_POW && BACKLIGHT_SW && FFOG_SW && RFOG_SW;					
	R_OUT_P5	= SYSTEM_POW && LED_MIDDLE_DOOR_SW && BACKLIGHT_SW; 					
	R_OUT_P13   = KEY_ON;
	R_OUT_P6	= KEY_ON && REVERSE_GEAR_SW; 
	R_OUT_P14   = KEY_ON && (DRIVER_SW || (LED_FRONT_DOOR_SW && BACKLIGHT_SW)); 				
	R_OUT_P7	= SYSTEM_POW && GUANGGAO_DENGXIAGN_SW;//KEY_ON && ((CanData[ID(0x0C0AA79D)][BYTE8] & 0x80) == 0x80);
	R_OUT_P42   = SYSTEM_POW && GUANGGAO_DENGXIAGN_SW_2;//KEY_ON && (GUANTONG_SW_2 || (BACKLIGHT_SW && LED_MIDDLE_DOOR_SW));

	if(KEY_ON && ((CanData[ID(0x0C0AA79D)][BYTE8] & 0x80) == 0x80))
		R_TimeCount = 600;
	R_OUT_P8    = (R_TimeCount > 0);
	if(R_TimeCount > 0)
		R_TimeCount--;
	
    R_OUT_P17 = 0;

    if(rbcm_off_line < 10)
        rbcm_off_line++;

    TIP_RBCM_OFF          = ((rbcm_off_line > 9)?1:0);                              // 鍚庨儴妯″潡绂荤嚎
#endif

#if  (Has_Tmode == ON)

    /*  Rear BCM output ON & OFF    */
    T_OUT_P1	= F_OUT_P3; 
	T_OUT_P9	= F_OUT_P10;	
	T_OUT_P2	= (KEY_ON|| KEY_CHARGE);
	T_OUT_P10	= KEY_ON && (GUANTONG_SW || (BACKLIGHT_SW && LED_MIDDLE_DOOR_SW));
	T_OUT_P3	= KEY_ON && BREAK_SW;
	T_OUT_P11	= KEY_ON;					
	T_OUT_P4	= SYSTEM_POW &&(BREAK_SW || ELEC_BREAK);		
	T_OUT_P12	= SYSTEM_POW && BACKLIGHT_SW && FFOG_SW && RFOG_SW;					
	T_OUT_P5	= SYSTEM_POW && LED_MIDDLE_DOOR_SW && BACKLIGHT_SW; 					
	T_OUT_P13   = KEY_ON;
	T_OUT_P6	= KEY_ON && REVERSE_GEAR_SW; 
	T_OUT_P14   = KEY_ON && (DRIVER_SW || (LED_FRONT_DOOR_SW && BACKLIGHT_SW)); 				
	T_OUT_P7	= SYSTEM_POW && GUANGGAO_DENGXIAGN_SW;
	T_OUT_P42   = SYSTEM_POW && GUANGGAO_DENGXIAGN_SW_2;
	T_OUT_P8	= SYSTEM_POW && GUANTONG_SW_2;                                         
    T_OUT_P17 = 0;




    if(tbcm_off_line < 10)
        tbcm_off_line++;

    TIP_TBCM_OFF          = ((tbcm_off_line > 9)?1:0);                              // 椤堕儴妯″潡绂荤嚎
#endif






    //浠〃杈撳嚭

    METER_OPEN_E3      = KEY_ON &&(!BACKLIGHT_SW);

    METER_OPEN_E6      = KEY_ON &&(veh_speed_display > 30);
    METER_OPEN_E7      = KEY_ON && ((F_OUT_P7 && F_OUT_P14) || (F_OUT_P42 && F_OUT_P8));
    METER_OPEN_E8      = SYSTEM_POW && LUPAI_LIGHT;
	METER_OPEN_WAKE_UP = UNUSED;


	
    led_out();
	
	//LED
   if(blinkerfast == 1)
      GPIO_Toggle_Output_Data_Config(GPIOF_SFR,GPIO_PIN_MASK_4);
	


    if(blinkerfast++ == 4)
	   blinkerfast = 1;
}


void LedHand(void)
{
    //纯电面膜实际机油压力低取消
    static u8 selftime = 0;
	
    // 鍚庨浘鐏�
    RFOG_WL         = KEY_ON && LED_RFOG_SW;
	// ABS鏁呴殰
    ABS_WL          = KEY_ON  &&  LED_ABS_SW;            
	// 鍙宠浆鍚�
	RIGHT           = LED_RIGHT_SW;
	// 鐢垫簮鎸囩ず鐏�
	POWER_WL        = LED_POWER_SW;                           
	// 鏈烘补鍘嬪姏
    OIL_LOW_WL      = KEY_ON && LED_OIL_LOW_SW;                   
	// 绌烘护闃诲
    FILTER_WL       = KEY_ON && LED_FILTER_SW;                     
	// 骞茬嚗鍓�
    DRYER_WL        = KEY_ON && LED_DRYER_SW;
	// 鐢垫睜鐢靛帇
    BATTERY_LOW_WL  = KEY_ON && LED_BATTERY_LOW_SW;           
	// 杩戝厜鐏�
    LBEAM_WL        = KEY_ON && LED_LBEAM_SW;
	// 姘斿帇浣�
    AIR_LOW_WL      = KEY_ON && LED_AIR_LOW_SW ;
	// 鍙戝姩鏈洪鍔犵儹
    PREHEAT_WL      = KEY_ON && LED_PREHEAT_SW;                   
	// 鍋滄鐏�
    STOP_WL         = KEY_ON && LED_STOP_SW;
	// 杩滃厜鐏�
    HBEAM_WL        = KEY_ON && LED_HBEAM_SW;
	// 鏈嶅姟鐏�
    SERVICE_WL      = KEY_ON && LED_SERVICE_SW;
	// 鍙戝姩鏈烘晠闅�
    ENG_FAULT_WL    = KEY_ON && LED_ENG_FAULT_SW;               
	// 鍓嶉浘鐏�
    FFOG_WL         = KEY_ON && LED_FFOG_SW;
	// 宸﹁浆鍚�
	LEFT            = LED_LEFT_SW;
	// 鎵嬪埗鍔�
	PARK_WL         = SYSTEM_POW && LED_PARK_SW;
	// 姘存俯楂�
    ENG_TEMP_HOT_WL = KEY_ON && LED_ENG_TEMP_HOT_SW;
	// 鍙戝姩鏈鸿埍
    ENG_DOOR_WL     = KEY_ON && LED_ENG_DOOR_SW;                
	//  涓棬
    MDOOR_WL        = SYSTEM_POW && LED_MIDDLE_DOOR_SW;     
	//  鐕冩补浣�
    FUEL_LOW_WL     = KEY_ON && LED_FUEL_LOW_SW;
	//  鍓嶉棬
    FDOOR_WL        = SYSTEM_POW && LED_FRONT_DOOR_SW;   
	//
    GENERATOR1_WL   = KEY_ON && LED_GENERATOR_SW;


	
	if((KEY_ON) && (OPENSYSTEMCHECK || SELF_TEST))
	{
	    led[0].byte = 0XFF;
	    led[1].byte = 0XFF;
	    led[2].byte = 0XFF;  
		
		if(SELF_TEST)
		{
		    selftime++;
		    if(selftime <= (_8s_100ms/2))
		    {
				led[0].byte = 0Xff;
				led[1].byte = 0Xff;
				led[2].byte = 0Xff;  
		    }
		    else if(selftime > _8s_100ms)
		    {
		        SELF_TEST = 0;
		        selftime = 0;
		        HALF_SELF_TEST_TIME = 0;
				led[0].byte = 0;
				led[1].byte = 0;
				led[2].byte = 0;
		    }
		    else
		    {
		        HALF_SELF_TEST_TIME = 1;
				led[0].byte = 0;
				led[1].byte = 0;
				led[2].byte = 0;
		    }
		}
	}
    led_out();
}

//1 
void ScreenSymbol(void)
{
	static u8 charge_time = 0,go_one = 0,emgtime = 0,flag = 0;
	static u8 rs485process = 0,yun_count,lilaoshi = 1;

	TYPE_BYTE gear;
	u8 gear_temp;

	SYMBOL_POSITION00    = KEY_ON && PLANT_ALL;
	SYMBOL_POSITION01    = KEY_ON && LED_BACKGROUND_FEEDBACK;  
	SYMBOL_POSITION02    = KEY_ON && BREAK_SW_FEEDBACK;
	SYMBOL_POSITION03    = KEY_ON && (veh_scr > 0);   
	SYMBOL_POSITION04    = KEY_ON && ((BMS.istatus[1]&0x20)==0x20);
	SYMBOL_POSITION05 = ((BMS.status_flag4&0x01)==0x01);
	SYMBOL_POSITION06	= ELEC_BREAK;
	SYMBOL_POSITION07	= SYSTEM_ERROR;  
	SYMBOL_POSITION08	= (BMS.isystem_fault == 1);
	SYMBOL_POSITION09	= ((AlarmFlag[1]&0x80)==0x80)||((AlarmFlag[2]&0x02)==0x02)||((E_MotorError[0]&0x40)==0x40)||((E_MotorError[1]&0x01)==0x01);
	SYMBOL_POSITION10	= ((BMS.istatus[2]&0x20)==0x20);
	SYMBOL_POSITION11	= ((BMS.istatus[2]&0x40)==0x40);
	SYMBOL_POSITION12    = ((BMS.istatus[2]&0x02)==0x00)&&(timeout[ID(0x1818D0F3)] < 50); 
	SYMBOL_POSITION13	= UNUSED;//(xuedimoshi == 0x01);
	SYMBOL_POSITION14	= YUXUE_MOSHI;//((DriverOperateStatus&0x10)==0x10);
	SYMBOL_POSITION15   =  ((BMS.status_flag4&0x08)==0x00)&&(timeout[ID(0x181bd0f3)] < 50);  

	if(DRIVER_AWAY_SW)
	{
		if(emgtime < 50)
			emgtime ++;
	}
	else
	{
		emgtime = 0;
	}
	if(emgtime >= 50)
		SYMBOL_POSITION16  = 1;
	else
		SYMBOL_POSITION16  = 0;

	SYMBOL_POSITION17  = EMERGENCY_SW;
	SYMBOL_POSITION18	 =((BMS.istatus[1]&0x04) == 0x04) ;//(InsulationMonitorErrorLevel == 1);		
	SYMBOL_POSITION19   = UNUSED;	
	SYMBOL_POSITION20 = DEFINE_TIP_SPEED;
	SYMBOL_POSITION21    = UNUSED; 
	SYMBOL_POSITION22    = UNUSED; 
	SYMBOL_POSITION23    = UNUSED;   
	if(GEAR_FLAG)//�е�λ���Ĵ��?λ
	{
		gear_temp = DriverOperateStatus&0x0f;
//		if((gear_temp>0)&&(gear_temp<=12))
//		{
//			gear.byte = gear_temp+3;
//		}
//		else
		{
			switch(DriverOperateStatus&0x0f)
			{
				case 0:
					gear.byte = 2;//N
					break;
				case 13: //R
					gear.byte = 1;
					break;
				case 14: //D
					gear.byte = 3;
					break;
				default:
					gear.byte = 0;
					break;
			}
		}
	}
	else //�޵�λ������0000
	{
		gear.byte = 0;
	}
	SYMBOL_POSITION24   = gear.bit.b3;
	SYMBOL_POSITION25   = gear.bit.b2;
	SYMBOL_POSITION26   = gear.bit.b1;
	SYMBOL_POSITION27   = gear.bit.b0;
	SYMBOL_POSITION28    = ((SystemStatus&0xC0)==0x40);  
	SYMBOL_POSITION29    = KEY_ON && LED_ENG_DOOR_SW;   
	SYMBOL_POSITION30    = KEY_ON && LED_MIDDLE_DOOR_SW;    
	SYMBOL_POSITION31    = KEY_ON && LED_FRONT_DOOR_SW;  
	SYMBOL_POSITION32    = DEFINE_TIP_WATER_LOW; 
	SYMBOL_POSITION33    = ((SystemStatus&0x30)==0x30);   
	SYMBOL_POSITION34    = SEATBELT_NO_SW; 
	SYMBOL_POSITION35    = UNUSED;   
	SYMBOL_POSITION36    = ((BMS.istatus[0]&0x08)==0x08); 
	SYMBOL_POSITION37	  = F_SW_P39;	   
	SYMBOL_POSITION38	  = ((SystemStatus&0x30)==0x20); 
	SYMBOL_POSITION39    = ASR_SW;  

	SYMBOL_POSITION40 = UNUSED;

	SYMBOL_POSITION41    = 0;
	SYMBOL_POSITION42    = 0;
	SYMBOL_POSITION43    = 0;    
	SYMBOL_POSITION44    = 0;     
	SYMBOL_POSITION45    = 0;      
	SYMBOL_POSITION46    = 0;      
	SYMBOL_POSITION47    = 0;   

	SYMBOL_POSITION48    = 0;      
	SYMBOL_POSITION49    = 0;      
	SYMBOL_POSITION50    = 0;     
	SYMBOL_POSITION51    = 0;      
	SYMBOL_POSITION52    = 0;      
	SYMBOL_POSITION53    = 0;      
	SYMBOL_POSITION54    = 0;      
	SYMBOL_POSITION55    = 0;   

	SYMBOL_POSITION56    = 0;      
	SYMBOL_POSITION57    = 0;      
	SYMBOL_POSITION58    = 0;      
	SYMBOL_POSITION59    = 0;      
	SYMBOL_POSITION60    = 0;      
	SYMBOL_POSITION61    = 0;      
	SYMBOL_POSITION62    = 0;      
	SYMBOL_POSITION63    = 0; 
 
 //符号片需要蜂鸣器
    SYMBOLBUZZ = 0;


}





void JudgeEngeed1SThan10(void)
{
   static u8 _1s = 0;
   if(eng_speed > 10)
   {
     _1s++;
	 if(_1s > 20)
	 {
        _1s = 20;
		ENABLEDIANHAO = USED;
	 }
   }
   else
   {
	   ENABLEDIANHAO = UNUSED;
	   _1s = 0;
   }
}





void SystemLogic(void)
{

  static u8 flag= 0,pwmcount = 20,can_send1000ms = 0;
  
  if((KEY_ON||KEY_CHARGE) && (BACKLIGHT_SW || OPENSYSTEMCHECK || SELF_TEST))
  {
	if(backlight_level >= 10)
	   backlight_level = 10;
     SetBackGround(backlight_level);
  }
  else	
  {
     BACKGROUND_OFF();
    //SetBackGround(0);
    //BACKGROUND(RESET)   
  }
 

  BCMConfig();
  set_output();
  
 // eng_speed = 6000;
  
  LedHand();
  ScreenSymbol();
  SaveODO();
  WriteEE();
  // 棰戠巼
  flag++;
  if(flag > 9)
  {
    flag = 0;
    GetCaptureHZ();
  }
  Rool_Alarm_Handle();
 #if((Has_Fmode == ON)||(Has_Tmode == ON)||(Has_Rmode == ON))
    if(pwmcount > 0)
    {
      pwmcount--;
      Send_PWM_Bcm();
    }
	#if  SUPPORT_WIPER
        RainConfig();
   #endif
	Send_Msg_Bcm(); 		 //鍐匔AN鍙戦�淇℃伅
   
#endif

  j1939_tx_100ms();
#if 0
  if((can_send1000ms++) >= 10)
  {
  	j1939_tx_1000ms();
  	can_send1000ms = 0;
  }
 #endif

  ClearCanDataManage();
  //JudgeEngeed1SThan10();
}


//
void BuzzLogic(void)
{
    static u16 buzzdelay = 300;
    if(KEY_ON && BUZZ_NORMAL_WORK && (buzzdelay == 0))
    {
        if((LEFT_LED_SW || RIGHT_LED_SW || KEY_EMG || SELF_TEST))
        {    
            BEEP_TURN();
			led_out();
        }
        else if(BUZZ_Critical)
        {
           BEEP_FAST();
		}
		else if(BUZZ_Normal || SYMBOLBUZZ)
		{
           BEEP_FAULT();
		}
		else
        {       
            BEEP_OFF();
        }
    }

	else
	{
		BEEP_OFF();
	}  

	
    if(buzzdelay > 0)
	   buzzdelay--;	
}








































