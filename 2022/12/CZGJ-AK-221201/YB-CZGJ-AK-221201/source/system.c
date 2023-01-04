/*
 * system.c
 *
 *  Created on: 2021-8-5
 *      Author: ART
 */


#include "system_init.h"
#include "system.h"
#include "MeterConfig.h"

TYPE_QWORD  Art,Syslogic;
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
volatile uint8_t  An_Kai_Handle_Time,_0CFF0C4A[8],_0CFF0D4A[8],Aver_Dianhao,Break_Pent,jiasu,jiansu;
volatile uint8_t  Uart2Receive[8],ReceIndex;

//钃勭數姹犳俯搴�
uint8_t  Temp_Vbat,Temp_Ranyou;
uint8_t  fuel_percent;

TYPE_BYTE tony;







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
	Oil_Alarm_2012 = Oil_Alarm;
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
void j1939_tx_50ms(void)
{
    u8 data[8];
	TYPE_BYTE temp_u8;
	u32 temp,i;
    static u8 fang = 0;
   
	fang++;
	if(fang > 4)
	{
	    fang= 0;

	    data[0] = 0; 
	    data[1] = veh_bar1*2;
	    data[2] = veh_bar1*2;
	    data[3] = Vbat/2;
		
		temp = Veh_odo*200;
	    data[4] = temp;
	    data[5] = temp >> 8;
	    data[6] = temp >> 16;
	    data[7] = temp >> 24;

        Can2_Tx_Bytes(0x18ffd017,data,8);


		temp_u8.byte = 0;
		temp_u8.bit.b0 = REVERSE_GEAR_SW;
		temp_u8.bit.b1 = NULL_SW;
		temp_u8.bit.b2 = UNUSED;
		temp_u8.bit.b3 = UNUSED;
		temp_u8.bit.b4 = UNUSED;
		temp_u8.bit.b5 = LED_FRONT_DOOR_SW;
		temp_u8.bit.b6 = LED_MIDDLE_DOOR_SW;
		temp_u8.bit.b7 = UNUSED;
		data[0] = temp_u8.byte;
		
		temp_u8.byte = 0;
		temp_u8.bit.b0 = HBEAM_SW;
		temp_u8.bit.b1 = LBEAM_SW;
		temp_u8.bit.b2 = ZUO_FLAG;
		temp_u8.bit.b3 = YOU_FLAG;
		temp_u8.bit.b4 = FFOG_SW;
		temp_u8.bit.b5 = RFOG_SW;
		temp_u8.bit.b6 = BACKLIGHT_SW;
		temp_u8.bit.b7 = BREAK_ALL;
		data[1] = temp_u8.byte;

		temp_u8.byte = 0;
		temp_u8.bit.b0 = LED_PARK_SW;
		temp_u8.bit.b1 = PLANT_LEFT_F||PLANT_LEFT;
		temp_u8.bit.b2 = PLANT_RIGHT_F||PLANT_RIGHT;
		temp_u8.bit.b3 = PLANT_LEFT_R;
		temp_u8.bit.b4 = PLANT_RIGHT_R;
		temp_u8.bit.b5 = DEFINE_TIP_WATER_LOW;//璇ョ増鏈畾涔夋按浣嶄綆
		temp_u8.bit.b6 = UNUSED;
		temp_u8.bit.b7 = LED_BATTERY_LOW_SW;
		data[2] = temp_u8.byte;	

		temp_u8.byte = 0;
		temp_u8.bit.b0 = INSIDE_LED_SW_1;
		temp_u8.bit.b1 = LUPAI_LIGHT;
		temp_u8.bit.b2 = KEY_POWER;
		temp_u8.bit.b3 = BUZZ_SW;
		temp_u8.bit.b4 = LED_ENG_DOOR_SW;
		temp_u8.bit.b5 = UNUSED;
		temp_u8.bit.b6 = UNUSED;
		temp_u8.bit.b7 = UNUSED;
		data[3] = temp_u8.byte;	

		temp_u8.byte = 0;
		temp_u8.bit.b0 = UNUSED;
		temp_u8.bit.b1 = AIR1_LOW;
		temp_u8.bit.b2 = AIR2_LOW;
		temp_u8.bit.b3 = (LED_FRONT_DOOR_SW||LED_MIDDLE_DOOR_SW)&&(veh_speed_display > 50);
		temp_u8.bit.b4 = UNUSED;
		temp_u8.bit.b5 = (DEFINE_TIP_SPEED);
		temp_u8.bit.b6 = LED_FILTER_SW;
		temp_u8.bit.b7 = ABS_SW;
		data[4] = temp_u8.byte;	
		
		temp_u8.byte = 0;
		temp_u8.bit.b0 = EMERGENCY_INSIDE_SW;
		temp_u8.bit.b1 = EMERGENCY_OUTSIDE_SW;
		temp_u8.bit.b2 = KEY_ACC;
		temp_u8.bit.b3 = KEY_ON;
		temp_u8.bit.b4 = KMG_FLAG;
		temp_u8.bit.b5 = CTL_WIPER_HI||CTL_WIPER_LO||CTL_WIPER_INT;
		temp_u8.bit.b6 = DRIVER_SW;
		temp_u8.bit.b7 = INSIDE_LED_SW_2;
		data[5] = temp_u8.byte;	
		
		temp_u8.byte = 0;
		temp_u8.bit.b0 = PASSAGE_GET_OUT_SW;
		temp_u8.bit.b1 = D_SW;
		temp_u8.bit.b2 = SEATBELT_NO_SW;

		data[6] = temp_u8.byte;	
		data[7] = veh_speed_display/10;
		Can2_Tx_Bytes(0x18ffd117,data,8);

	}


}





/*************************************************************************
* Function Name    : j1939_tx
* Description         : this function is send CAN message to J1939
* Parameters         : None
* Return Value       :None
**************************************************************************/
void j1939_tx_100ms(void)
{
    u32 temp;
    static uint8_t time = 0,clear_mile_time = 0,hit_time = 0,i,life;
    TYPE_BYTE metre_state[8] = {0},temp_u8;
    u8 data[8];

    metre_state[1].bit.b0 = LED_ENG_DOOR_SW;
    metre_state[1].bit.b1 = 0;
    metre_state[1].bit.b2  = LED_FRONT_DOOR_SW;
    metre_state[1].bit.b3  = 0;
    metre_state[1].bit.b4  = LED_MIDDLE_DOOR_SW;
    metre_state[1].bit.b5  = 0;
    metre_state[1].bit.b6  = 0;
    metre_state[1].bit.b7  = 0;


    temp_u8.bit.b0 = SAFE_DOOR_SW;
    temp_u8.bit.b1 = UNUSED;

    temp_u8.bit.b2 = LED_PARK_SW;
    temp_u8.bit.b3 = BACKLIGHT_SW;
    temp_u8.bit.b4 = YOU_FLAG;
    temp_u8.bit.b5 = ZUO_FLAG;
    temp_u8.bit.b6 = KMG_FLAG;
    temp_u8.bit.b7 = DIAN_NUANFENG;


    data[0] = temp_u8.byte; //瀹夊叏闂ㄦ棤瀹夊叏闂ㄥ彂閫�0
    data[1] = metre_state[1].byte;
    data[2] = rtc.secs;
    data[3] = rtc.mins;
    data[4] = rtc.hours;
    data[5] = rtc.day;
    data[6] = rtc.month;
    data[7] = rtc.year;
  
	
    Can1_Tx_Bytes(0x18f607bd,data,8);
	Can2_Tx_Bytes(0x18f607bd,data,8);

	
    temp = Veh_odo;
    data[0] = temp&0xFF;
    data[1] = (temp>>8)&0xFF;
    data[2] = (temp>>16)&0xFF;
    data[3] = (temp>>24)&0xFF;
    data[4] = veh_speed_display*0.1;

	temp_u8.byte = 0;
	temp_u8.bit.b0 = clear_mile;
	temp_u8.bit.b3 = LIZUO_FLAG;
	temp_u8.bit.b4 = SEATBELT_NO_SW;
    data[5] = temp_u8.byte;
    if(clear_mile)
    {
        clear_mile_time++;
        if(clear_mile_time>=10)
        {
            clear_mile = 0;
            clear_mile_time = 0;
        }
    }
    else
        clear_mile_time = 0;
    temp = Veh_trip;
    data[6] = temp&0xFF;
    data[7] = (temp>>8)&0xFF;

    Can1_Tx_Bytes(0x18ff304b,data,8);
	Can2_Tx_Bytes(0x18ff304b,data,8);

/**************************************************************/

}
void j1939_tx_200ms(void)
{
	u8 data[8];

	data[0] = Vbat/2;
	data[1] = 0XFF;
	data[2] = 0XFF;
	data[3] = 0XFF;
	data[4] = 0XFF;
	data[5] = 0XFF;
	data[6] = veh_bar2*10/8;
	data[7] = veh_bar1*10/8;
	Can1_Tx_Bytes(0x18FF304D,data,8);
}
void j1939_tx_1000ms(void)
{
	u8 data[8];
#if ANKAI_ABS
	data[0] = 0;
	data[1] = 0;
	data[2] = veh_bar2*10/8;
	data[3] = veh_bar1*10/8;
	data[4] = 0;
	data[5] = 0;
	data[6] = 0;
	data[7] = 0;
	
	Can1_Tx_Bytes(0x18FEAE30,data,8);
#endif
}

void I10Huangshan(void)
{
	u8 data[8];
    TYPE_BYTE temp;
	u16 vol = Battery_System_Volt ;
    u16 cur = Battery_Charge_Curr ;
	u32 odo_temp = Veh_odo;
	u32 zhiliucedianya = motor_dc_volt*10;
	
    data[0] = odo_temp;
	data[1] = odo_temp >> 8;
	data[2] = odo_temp >> 16;
	data[3] = odo_temp >> 24;
    data[4] = Veh_trip;
	data[5] = Veh_trip >> 8;	
	data[6] = veh_speed/10;
	temp.byte = 0;
	temp.bit.b0 = 0;
	temp.bit.b1 = 0;
	temp.bit.b2 = 0;
	temp.bit.b3 = LED_FRONT_DOOR_SW;
	temp.bit.b4 = LED_MIDDLE_DOOR_SW;
	temp.bit.b5 = LED_ENG_DOOR_SW;
	if(READY)
	{
	  temp.bit.b6 = 0;
	  temp.bit.b7 = 1;
	}
	else if(START_MARK)
	{
		temp.bit.b6 = 1;
		temp.bit.b7 = 1;
	}
	else if(STOP_MARK)
	{
		temp.bit.b6 = 1;
		temp.bit.b7 = 0;
	}	
	else
	{
	  temp.bit.b6 = 0;
	  temp.bit.b7 = 0;
	}
	data[7] = temp.byte;
	Can2_Tx_Bytes(0x18FEF100,data,8);

	data[0] = Aver_Dianhao;//ÿ������
	data[1] = veh_soc/0.4;
	data[2] = GetU16Low(vol);
	data[3] = GetU16High(vol);
	data[4] = GetU16Low(cur);
	data[5] = GetU16High(cur);	
	data[6] = jiasu;
	data[7] = jiansu;
  	Can2_Tx_Bytes(0x18FEF200,data,8);

	data[0]  = GetU16Low(Battery_High_Volt);
    data[1]  = GetU16High(Battery_High_Volt);
    data[2]  = GetU16Low(Battery_Low_Volt);
    data[3]  = GetU16High(Battery_Low_Volt);
	data[4]  = Box_High_Temp;
    data[5]  = 0;
    data[6]  = Box_High_Temp - Temp_jicha;
    data[7]  = 0;	
	Can2_Tx_Bytes(0x18FEF300,data,8);


	data[0]  = motor_tem;
    data[1]  = WaterTem;
    data[2]  = GetU16Low(insulate_value);
    data[3]  = GetU16High(insulate_value);
	temp.byte  = 0xff;
	if(NULL_SW)
	{
	   temp.bit.b6 = 1;
	   temp.bit.b7 = 0;   
	}
	else if(D_SW)
	{
	   temp.bit.b6 = 0;
	   temp.bit.b7 = 1;   
	}	
	else if(REVERSE_GEAR_SW)
	{
	   temp.bit.b6 = 1;
	   temp.bit.b7 = 1;   
	}	
	else
	{
		temp.bit.b6 = 0;
		temp.bit.b7 = 0;  
	}
	data[4]  = temp.byte;
    data[5]  = 0x0;
    data[6]  = 0x0;
    data[7]  = 0x0;	
	Can2_Tx_Bytes(0x18FEF400,data,8);
   
	data[0] = GetU16Low(zhiliucedianya);
	data[1] = GetU16High(zhiliucedianya);
	data[2] = GetU16Low(motor_dc_curr);
	data[3] = GetU16High(motor_dc_curr);
	data[4] = 0x0;
	data[5] = 0x0;	
	data[6] = 0x0;
	data[7] = 0x0;
    Can2_Tx_Bytes(0x18FEF500,data,8);
    
	data[0] = 0x0;
	data[1] = 0x0;
	data[2] = 0x0;
	data[3] = veh_bar1*2;
	data[4] = veh_bar2*2;

	temp.byte = 0;
	temp.bit.b0 = LED_HBEAM_SW;	
	temp.bit.b1 = LED_LBEAM_SW;	
	temp.bit.b2 = ZUO_FLAG;	
	temp.bit.b3 = YOU_FLAG;	
	temp.bit.b4 = LED_FFOG_SW;	
	temp.bit.b5 = LED_RFOG_SW;	
	temp.bit.b6 = KMG_FLAG;	
	temp.bit.b7 = WATER_SW;	
	data[5] = temp.byte;
	
	temp.byte = 0;
	temp.bit.b0 = PLANT_LEFT_F||PLANT_LEFT_R||PLANT_LEFT;
	temp.bit.b1 = PLANT_RIGHT_F||PLANT_RIGHT_R||PLANT_RIGHT;
	temp.bit.b2 = OIL_LOW;
	temp.bit.b3 = BUZZ_SW;
	temp.bit.b4 = LED_ENG_DOOR_SW;
	temp.bit.b5 = AIR1_LOW;
	temp.bit.b6 = AIR2_LOW;
	temp.bit.b7 = ELEC_BREAK;
	data[6] = temp.byte;

	temp.byte = 0;
	temp.bit.b0 = DEFINE_TIP_SPEED;
	temp.bit.b1 = (veh_speed > 0) && (LED_FRONT_DOOR_SW || LED_MIDDLE_DOOR_SW||LED_ENG_DOOR_SW);
	temp.bit.b2 = LED_FILTER_SW;
	temp.bit.b3 = ABS_SW;
	temp.bit.b4 = EMERGENCY_INSIDE_SW;
	temp.bit.b5 = EMERGENCY_OUTSIDE_SW;
	temp.bit.b6 = PASSAGE_GET_OUT_SW;
	temp.bit.b7 = SEATBELT_NO_SW;
	data[7] = temp.byte;

	Can2_Tx_Bytes(0x18FEF600,data,8);

	temp.byte = 0xff;
	temp.bit.b0 = DRIVER_AWAY_SW;
	temp.bit.b1 = BREAK_ALL;
	temp.bit.b2 = PARK_SW;
	data[0] = temp.byte;
	data[1] = 0;
	data[2] = 0;
	data[3] = 0;
	data[4] = 0;
	data[5] = 0;	
	data[6] = 0;
	data[7] = 0;
    Can2_Tx_Bytes(0x18FEF700,data,8);

}

void GongJiaoHouTai(void)
{
   static u8 lop = 0;
   lop++;
   if(lop > 4)
   {
      lop = 0;
	  I10Huangshan();
   }
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
		 speed_life++;
		 single_mile = single_mile + (float)(veh_speed_display*Coef*0.01/72.0);
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
	    else
	    {
           if(speed_life > 30)
           {
             veh_speed_display = 0;
			 speed_life = 30;
		   }
		}
	 }
 #endif

}

u8 data_change(void)
{
    static u8 pre_data[8],time = 0;
    u8 i,j,result;
    for(i = 0; i<8; i++)
    {
        if(pre_data[i] != ID_18ff0257_data[i])
        {
            for(j = 0; j<8; j++)
                pre_data[j] = ID_18ff0257_data[j];
            time = 0;
            result = 0;
            break;
        }
    }
    if(i == 8)
    {
        time++;
        if(time >= 100)
        {
            time = 100;
            result = 1;
        }
        else
            result = 0;
    }
    return result;
}

u8 data_change_life(void)
{
    static u8 pre_life,time = 0;
    u8 result;

    if(pre_life != Life)
    {
        pre_life = Life;
        time = 0;
        result = 0;
    }
    else
    {
        time++;
        if(time >= 100)
        {
            time = 100;
            result = 1;
        }
        else
            result = 0;
    }
    return result;
}




static void Rool_Alarm_Handle(void)
{
    static uint16_t time = 0,buzz_time,timexx;
    static uint8_t add_time,add_flag,flag_30s,flag_10s,pre_door_time;

if(KEY_ON)
{
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


    TIP_0X3C  =   ((METER_OPEN_E3 == 1) && (METER_OUT_E3 == 2))?1:0;
    TIP_0X3D  =   ((METER_OPEN_E6 == 1) && (METER_OUT_E6 == 2))?1:0;	
    TIP_0X3E  =   ((METER_OPEN_E7== 1)  && (METER_OUT_E7== 2))?1:0;
    TIP_0X3F  =   ((METER_OPEN_E8 == 1) && (METER_OUT_E7 == 2))?1:0;
}

	
	
	TIP_0X44 = KEY_ON && DEFINE_TIP_LEAST_VOLT;
	TIP_0X45 = UNUSED;//DEFINE_TIP_AIR_LOW;
	TIP_0X46 = KEY_ON && (DEFINE_TIP_SPEED||CHAOSU);
	TIP_0X47 = UNUSED;//DEFINE_TIP_PLANT_ALARM;
	TIP_0X48 = UNUSED;
	TIP_0X49 = UNUSED;
	//PASSAGE_GET_OUT_SW
	TIP_0X4A = KEY_ON && SYMBOL_POSITION21;
	//EMERGENCY_OUTSIDE_SW
	TIP_0X4B = UNUSED;
	TIP_0X4C = KEY_ON && AIR_LOW;
	TIP_0X4D = KEY_ON && AIR1_LOW;
	TIP_0X4E = KEY_ON && AIR2_LOW;
	TIP_0X4F = UNUSED;//鏈烘补鍘嬪姏浣�
	TIP_0X50 = UNUSED;//姘存俯楂�
	TIP_0X51 = KEY_ON && LED_FILTER_SW;//绌烘护闃诲鎶ヨ
	TIP_0X52 = KEY_ON && (timeout[GetIndexFromID(0x18FF2C47)] > 50);
	TIP_0X53 = KEY_ON && (timeout[GetIndexFromID(0x0CFF0A4A)] > 50);
	TIP_0X54 = KEY_ON && (timeout[GetIndexFromID(0x18FF2848)] > 50);
	TIP_0X55 = KEY_ON && (data_change() || (timeout[GetIndexFromID(0x18FF0257)] > 100));
	TIP_0X56 = KEY_ON && (data_change_life() || (timeout[GetIndexFromID(0x18FF2B49)] > 100));//缁濈紭妫�祴鏃犱俊鎭�
	TIP_0X57 = UNUSED;//TestBitTrue(Control_information_data7,3);

	TIP_0X58  = KEY_ON && CAN_AIR_LOW;
	TIP_0X59  = KEY_ON && (((Control_information_data7&0x02)==0x02));   //鍏呯數淇濇姢鐩�
	TIP_0X5A  = UNUSED;//((Control_information_data7&0x01)==0x01);//涓�骇鏁呴殰 鐔旀柇鍣ㄦ柇寮�
	TIP_0X5B  = UNUSED;//((Control_information_data1&0x80)==0x80);//浜岀骇鏁呴殰锛岀數姹犳�鐢靛帇杩囬珮
	TIP_0X5C  = UNUSED;//((Control_information_data1&0x40)==0x40);//浜岀骇鏁呴殰锛岀數姹犳�鐢靛帇杩囦綆
	TIP_0X5D  = UNUSED;//((Control_information_data1&0x20)==0x20);//浜岀骇鏁呴殰锛岀數姹犲崟浣撶數鍘嬭繃楂�
	TIP_0X5E  = UNUSED;//((Control_information_data1&0x08)==0x08);//浜岀骇鏁呴殰锛岀數姹犲崟浣撴斁鐢电數娴佽繃澶�
	TIP_0X5F  = UNUSED;//((Control_information_data1&0x04)==0x04);//浜岀骇鏁呴殰锛岀數姹犲崟浣撳厖鐢电數娴佽繃澶�
	TIP_0X60  = UNUSED;//((Control_information_data1&0x02)==0x02);//鐢垫睜绠辨俯搴﹁繃楂�
	TIP_0X61  = UNUSED;//((Control_information_data1&0x01)==0x01);//鐢垫睜绠辨俯搴﹁繃浣�
	TIP_0X62  = KEY_ON && ((ID_0CFF0B4A_data2&0x01)==0x01);		 //浜岀骇鏁呴殰锛岀郴缁熷憡璀�


	TIP_0X63  = KEY_ON && fault42;								 //鐢靛埗鍔ㄥ凡琛板噺
	TIP_0X64  = KEY_ON && fault43;								 //鐢靛埗鍔ㄥ凡涓ラ噸涓嬮檷
	TIP_0X65  = KEY_ON && fault44;								 //鏃犵數鍒跺姩锛屾敞鎰忓埞杞�
	TIP_0X66  = KEY_ON && ((electric_shake&0x07) == 0x01);		 //鐢甸噺浣庯紝璇峰厖鐢�
	TIP_0X67  = KEY_ON && ((electric_shake&0x07) == 0x02);	   //鐢甸噺浣庯紝璇烽檷浣庡姛鐜�
	TIP_0X68  = KEY_ON && ((electric_shake&0x07) == 0x03);		 //鐢垫睜鑰楀敖锛屾棤鍔ㄥ姏
	TIP_0X69  = KEY_ON && ((electric_shake&0x07) == 0x04);		 //鐢垫睜鑰楀敖锛岃鍏呯數
   // TIP_0X6A	= fault9;								   //鐑熼浘鏁呴殰
   // TIP_0X6B	= (((battery_1_data6>>1)&0x03)==0x01);	//鐢垫睜鍐呴儴缁濈紭涓�骇鏁呴殰
   // TIP_0X6C	= (((battery_1_data6>>1)&0x03)==0x02);	//鐢垫睜鍐呴儴缁濈紭浜岀骇鏁呴殰
   // TIP_0X6D	= fault38;								   //SOC杩囦綆
   // TIP_0X6E	= fault39;									 //娓╁害杩囬珮鍋滆溅
  //  TIP_0X6F	= ((ID_18FF2848_data5&0x10)==0x10); 	   //鍔ㄥ姏鐢垫睜杩囨祦
  //  TIP_0X70	= fault37;								   //SOC浣�
  //  TIP_0X71	= ((ID_18FF2848_data5&0x04) == 0x04);	   //SOC杩囬珮
  //  TIP_0X72	= ((ID_18FF2848_data5&0x02) == 0x02);	   //妯″潡鐢靛帇杩囦綆
  //  TIP_0X73	= ((ID_18FF2848_data5&0x01) == 0x01);	   //妯″潡鐢靛帇楂�
  //  TIP_0X74	= fault12;								   //鍗曠鐢垫睜鐢靛帇涓嶅潎琛�
  //  TIP_0X75	= fault13;								   //鏁寸鐢垫睜鐢靛帇涓嶅潎琛�
  //  TIP_0X76	= fault14;								   //鐢垫睜楂樹綆娓╁害澶т簬15搴�
  //  TIP_0X77	= fault15;								   //鐢垫睜楂樹綆娓╁害澶т簬10搴�
 //   TIP_0X78	= fault16;								   //鏋佹煴娓╁害澶т簬65搴�
 //   TIP_0X79	= fault17;								   //鏋佹煴娓╁害澶т簬75
 //   TIP_0X7A	= fault18;								   //鐢垫睜浠庢澘鐢靛帇妫�祴鏁呴殰
 //   TIP_0X7B	= fault19;								   //鐢垫睜浠庢澘CAN妫�祴鏁呴殰
	TIP_0X7C  = (KEY_ON || KEY_CHARGE ||KEY_POWER) && fault20;								 //缁濈紭鐢甸樆浜岀骇鍛婅
	TIP_0X7D  = (KEY_ON || KEY_CHARGE ||KEY_POWER) && fault21;								 //缁濈紭鐢甸樆涓�骇鍛婅
	TIP_0X7E  = KEY_ON && fault22;								 //鐩存祦渚ф瑺鍘�
	TIP_0X7F  = KEY_ON && fault23;								 //杩囨祦
	TIP_0X80  = KEY_ON && fault24;								 //IGBT鏁呴殰
	TIP_0X81  = KEY_ON && fault25;								 //鐩存祦渚ц繃鍘�
	TIP_0X82  = KEY_ON && ((ID_18FF2D47_data6&0X40) == 0X40); 	//涓绘帴瑙﹀櫒瑙︾數鏁呴殰
	TIP_0X83  = KEY_ON && ((ID_18FF2D47_data6&0X08) == 0X08); 	//涓绘帴瑙﹀櫒瑙︾數杩囪浇
	TIP_0X84  = KEY_ON && ((ID_18FF2D47_data6&0X04) == 0X04); 	//涓绘帴瑙﹀櫒瑙︾數瓒呴�
	TIP_0X85  = KEY_ON && ((ID_18FF2D47_data6&0X01) == 0X01); 	//涓绘帴瑙﹀櫒瑙︾數杩囩儹
	TIP_0X86  = KEY_ON && ((fog_alarm[0]&0x07)==0x05);
	TIP_0X87  = KEY_ON && ((fog_alarm[0]&0x07)==0x06);
	TIP_0X88  = KEY_ON && ((ChargingRelay&0x03)==0x01);
	#if 0
	TIP_0X89  = (FaultAlarmAdd == 1);
	TIP_0X8A  = (FaultAlarmAdd == 2);
	TIP_0X8B  = (FaultAlarmAdd == 3);
	TIP_0X8C  = (FaultAlarmAdd == 4);
	TIP_0X8D  = (FaultAlarmAdd == 5)&&READY;
	TIP_0X8E  = (FaultAlarmAdd == 6)&&READY;
	TIP_0X8F  = (FaultAlarmAdd == 7)&&READY;
	TIP_0X90  = (FaultAlarmAdd == 8);
	TIP_0X91  = (FaultAlarmAdd == 9);
	TIP_0X92  = (FaultAlarmAdd == 10);
	#endif
	TIP_0X93  = KEY_ON && ((add_fog[0].byte&0x07)==0x05);
	TIP_0X94  = KEY_ON && ((add_fog[0].byte&0x07)==0x06);
	TIP_0X95  = KEY_ON && (add[1] == 3);
	TIP_0X96  = KEY_ON && TestBits(ID_18FF2848_data7,0,2,1)&&(!SYMBOL_POSITION11)&&(!SYMBOL_POSITION09);
	TIP_0X97  = KEY_ON && TestBits(ID_18FF2848_data7,0,2,2)&&(!SYMBOL_POSITION11)&&(!SYMBOL_POSITION09);
	TIP_0X98  = (KEY_ON || KEY_CHARGE ||KEY_POWER) && TestBits(ID_18FF2848_data7,0,2,3)&&(!SYMBOL_POSITION11)&&(!SYMBOL_POSITION09);
	TIP_0X99  = KEY_ON && TestBits(motor_state,6,2,1);
	TIP_0X9A  = KEY_ON && TestBits(motor_state,6,2,2);
	TIP_0X9B  = KEY_ON && TestBits(motor_state,6,2,3);
	
	TIP_0X9C  = (KEY_ON || KEY_CHARGE ||KEY_POWER)&& TestBits(add[0],6,2,3);
	TIP_0X9D  = KEY_ON && TestBits(add[0],6,2,2);
	TIP_0X9E  = KEY_ON && TestBits(add[0],6,2,1);
	
	TIP_0X9F  = KEY_ON && TestBits(add[2],3,2,3);
	TIP_0XA0  = KEY_ON && TestBits(add[2],3,2,2);
	TIP_0XA1  = KEY_ON && TestBits(add[2],3,2,1);
	TIP_0XA2  = KEY_ON && TestBits(add[4],3,2,3);
	TIP_0XA3  = KEY_ON && TestBits(add[4],3,2,2);
	TIP_0XA4  = KEY_ON && TestBits(add[4],3,2,1);
	
	TIP_0XA5  = KEY_ON && ((add[6]&0xc0) == 0xc0);	 // TestBits(add[6],3,2,3);
	TIP_0XA6  = KEY_ON && ((add[6]&0xc0) == 0x80);
	TIP_0XA7  = KEY_ON && ((add[6]&0xc0) == 0x40);
	TIP_0XA8  = UNUSED;
	TIP_0XA9  = UNUSED;
	TIP_0XAA  = UNUSED;

	TIP_0XAB  = KEY_ON && PLANT_LEFT_F;
	TIP_0XAC  = KEY_ON && PLANT_RIGHT_F;
	TIP_0XAD  = KEY_ON && WATER_SW;
	TIP_0XAE  = KEY_ON && EMERGENCY_OUTSIDE_SW;
	TIP_0XAF  = KEY_ON && EMERGENCY_INSIDE_SW;
	TIP_0XB0  = KEY_ON && PLANT_RIGHT_R;
	TIP_0XB1  = KEY_ON && PLANT_LEFT_R;
	TIP_0XB2  = KEY_ON && (((ID_0CFF0B4A_data2>>4)&0x03)==0x01);
	TIP_0XB3  = KEY_ON && (((ID_0CFF0B4A_data2>>4)&0x03)==0x02);
	TIP_0XB4  = KEY_ON && (((ID_0CFF0B4A_data2>>4)&0x03)==0x03);

	TIP_0XC3  = KEY_ON && SYMBOL_POSITION32;
	TIP_0XC4  = KEY_ON && ((Add_Comm.byte&0X03)==0X3);
	TIP_0XC5  = KEY_ON && ((Add_Comm.byte&0X03)==0X2);
	TIP_0XC6  = KEY_ON && ((Add_Comm.byte&0X03)==0X1);


	if(KEY_ON && Ankai_Add_190703.bit.b6)
	{
	   add_time = 51;
	   add_flag = 1;
	   TIP_0XC7 = 1;
	   TIP_0XC8 = 0;
	}
	else
	{
	   if(add_time > 0)
		   add_time--;
	   else
	   {
		   add_flag = 0;
		   TIP_0XC7 = 0;
		   TIP_0XC8 = 0;
	   }
	   
	   if(add_flag == 1)
	   {
		   TIP_0XC7 = 0;
		   TIP_0XC8 = 1;
	   }
	}
	TIP_0XC9  = KEY_ON && TestBits(ID_18FF2848_data7,0,2,1) && (SYMBOL_POSITION11) ;
	TIP_0XCA  = KEY_ON && TestBits(ID_18FF2848_data7,0,2,2) && (SYMBOL_POSITION11) ;
	TIP_0XCB  = KEY_ON && TestBits(ID_18FF2848_data7,0,2,3) && (SYMBOL_POSITION11) ;
	
	TIP_0XCC  = KEY_ON && TestBits(ID_18FF2848_data7,0,2,1) && (SYMBOL_POSITION09) ;
	TIP_0XCD  = KEY_ON && TestBits(ID_18FF2848_data7,0,2,2) && (SYMBOL_POSITION09) ;
	TIP_0XCE  = KEY_ON && TestBits(ID_18FF2848_data7,0,2,3) && (SYMBOL_POSITION09) ;
	
	//20200319ϵͳ�澯�������ʡ�
	TIP_0XCF  = KEY_ON && TestBits(_0CFF0B4A[3],0,2,1);
	//20210128 ϵͳ���������������ж�
	TIP_0XD0  = KEY_ON && TestBits(_0CFF0B4A[3],0,2,2);
	//20210128 ϵͳ�����������ж�
    TIP_0XD1  = KEY_ON && TestBits(_0CFF0B4A[3], 0, 2, 3);

	if (TIP_0XD1)
    {
        if (flag_10s)
        {
            buzz_time = 100;
            flag_10s = 0;
        }
    }
    else
        flag_10s = 1;
    if (buzz_time > 0)
        buzz_time--;
   /* if(TIP_0XD0)
    {
	 if(flag_30s)
	 {
		 timexx = 300;
		 flag_30s = 0;
	 }
    }
    if(timexx > 0)
	 timexx--;
    if(timexx == 0)
    {
		TIP_0XD0 = 0;
	   if(flag_10s)
	   { 
		   TIP_0XD1 = 1;
		   buzz_time = 100;
		   flag_10s = 0;
	   }
    }
	if(buzz_time > 0)
		buzz_time--;
	else
		TIP_0XD1 = 0;
   if((_0CFF0B4A[3]&0x03) != 0x03)
	{ 
	   TIP_0XD0 = 0;
	   TIP_0XD1 = 0;
	   buzz_time = 0;
	   timexx = 300;
	   flag_10s = 1;
	   flag_30s = 1;
   }*/

	TIP_0XD2  = KEY_ON && WATER_CAN_SW;
	TIP_0XD3  = KEY_ON && WAITUI_CHUANG;
	
	TIP_0XD4  = KEY_ON && ((_0CFF0B4A[1]&0x20) == 0x20);
	TIP_0XD5  = KEY_ON && ((_0CFF0B4A[1]&0x10) == 0x10);
	TIP_0XD6  = KEY_ON && ((abs_fault&0x30) > 0);
	TIP_0XD7  = KEY_ON && ((_18FF0152[1]&0x02) == 0x02);
	TIP_0XD8  = UNUSED;//EMERGENCY_FRONT_SW;
	TIP_0XD9  = UNUSED;//EMERGENCY_MID_SW;
	TIP_0XDA  = KEY_ON && (Temp_Vbat > 85);
	TIP_0XDB  = UNUSED;
	TIP_0XDC  = KEY_ON && ((motor_flag&0x40) == 0x40);
	TIP_0XDD  = KEY_ON && ((add[8] & 0x18) == 0x18);
	TIP_0XDE  = KEY_ON && ((add[8] & 0x18) == 0x10);
    TIP_0XDF  = KEY_ON && ((add[8] & 0x18) == 0x08);
	TIP_0XE0  =	KEY_ON && WATER_RANYOU_SW;
	TIP_0XE1  =	UNUSED;//KEY_ON && (Temp_Ranyou > 85);
	TIP_0XE2  = KEY_ON && (_18FF064A[3] == 209);
	TIP_0XE3  = KEY_ON && AIRLOW_FRONTDOOR_SW;
	TIP_0XE4  = KEY_ON && AIRLOW_MIDDOOR_SW;
	TIP_0XE5  = KEY_ON && EMERGENCY_DRIVER_SW;
	TIP_0XE6  = PTC10;

	TIP_0XE7  = PLANT_LEFT;
	TIP_0XE8  = PLANT_RIGHT;
	
#if CLOSE_DOOR_WANT_VOICE //鍏抽棬鏈変笁澹版彁绀洪煶锛屾敞鎰弍re_door_time瀹氫箟浠ュ強浣跨敤
		if((PRE_YOUQIAN_DOOR != LED_FRONT_DOOR_SW) || (PRE_YOUZHONG_DOOR != LED_MIDDLE_DOOR_SW))
		{
	
		   if(((PRE_YOUQIAN_DOOR) && (!LED_FRONT_DOOR_SW)) || ((PRE_YOUZHONG_DOOR) && (!LED_MIDDLE_DOOR_SW)))
		   {
			  pre_door_time = 16;
		   }
		   PRE_YOUQIAN_DOOR = LED_FRONT_DOOR_SW;
		   PRE_YOUZHONG_DOOR = LED_MIDDLE_DOOR_SW;
		}
	
		 if(pre_door_time > 0)
		    pre_door_time--;
#endif



    BUZZ_Normal   =  fault ||TIP_0X98||TIP_0X6A||TIP_0X7D||TIP_0X85||TIP_0X86||TIP_0X87 || TIP_0XB1||TIP_0XB0||DEFINE_TIP_WATER_LOW||\
                     TIP_0X93||TIP_0X94||TIP_0X48||TIP_0X49||TIP_0X4B||TIP_0X47||DEFINE_TIP_SPEED || TIP_0XAB||EMERGENCY_ALL||\
                     TIP_0XAC||TIP_0XAD||TIP_0XAE||TIP_0XAF||TIP_0X51||TIP_0X4D||TIP_0X4E||TIP_0X4F||TIP_0X50||SYMBOL_POSITION35||\
                     ((LED_FRONT_DOOR_SW||LED_MIDDLE_DOOR_SW||ENG_DOOR_SW||SEATBELT_NO_SW)&&(veh_speed_display > 50))||(Temp_Ranyou > 85)||\
                     TIP_0XD0||TIP_0X60||TIP_0X62||(buzz_time>0)||TIP_0XDA||TIP_0XDB||TIP_0XD3||LIZUO_FLAG||PASSAGE_GET_OUT_SW||SAFE_DOOR_SW||
                     TIP_0XE6||TIP_0XE7||TIP_0XE8;
	

	
    BUZZ_Critical =  DEFINE_TIP_AIR_LOW||(pre_door_time > 0)||AIRLOW_FRONTDOOR_SW||AIRLOW_MIDDOOR_SW; //姘斿帇鎶ヨ


}

//鑾峰彇鐕冩补
void  GetFuel(void)
{
    uint16_t fuelsource;
	fuelsource = FUELSOURCE;
	#if(FUELTYPE == FUELFULL_180)
	if((fuelsource <= 6) || (fuelsource > 360))
		fuel_percent = 0;
	else if(fuelsource <= 77)
		fuel_percent = 0.7062*(fuelsource)-4.2373;
	else if(fuelsource <= 180)
		fuel_percent = 0.4845*(fuelsource)+12.7907;
	else 
		fuel_percent = 100;
	#elif(FUELTYPE == FUELFULL_6)
	if(fuelsource < 3)
		fuel_percent = 100;
	else if(fuelsource <= 18)
		fuel_percent = 105 - ((5*fuelsource)/3);
	else if((fuelsource <= 33))
		fuel_percent = 107 - ((25*fuelsource)/14);
	else if((fuelsource <= 70))
		fuel_percent = 71 - ((25*fuelsource)/38);
	else if((fuelsource <= 110))
		fuel_percent = 69 - ((5*fuelsource)/8);
	else 
		fuel_percent = 0;

	#endif
 
    fuel_percent = fuel_percent *0.01* Fuel_Coef;
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



//鑾峰彇钃勭數姹犳俯搴�
void  GetVbatTemp(void)
{
	u16 i,temp_va;
	u8 data[8] = {0};
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
	   
	if(i == (sizeof(Frist_Temp_V)/2))
	   Temp_Vbat = 120;//瓒呰繃120搴�

	/*if(temp_va > 1500)
	{
	   Temp_Vbat = 0xff;//offline
	   return ;
	}*/
	if(temp_va < 58)
		Temp_Vbat = 130;
	data[0] = Temp_Vbat;
	Can1_Tx_Bytes(0x18ffd217,data,8);


}


void  GetRanyouTemp(void)
{
	u16 i,temp_va;
	temp_va = RANYOUTEMPSOUTCE;
	
	for(i = 0;i < 100;i++)//sizeof(Temp_Value)
	{
	   if(temp_va >= Frist_Temp_V[i])
	   {
		  Temp_Ranyou = i+20;
		  break;
	   }
	}
	
	if(i == 0)
	   Temp_Ranyou = 20; //浣庝簬20搴�
	   
	if(i == (sizeof(Frist_Temp_V)/2))
	   Temp_Ranyou = 120;//瓒呰繃120搴�

	/*if(temp_va > 1500)
	{
	   Temp_Vbat = 0xff;//offline
	   return ;
	}*/
	if(temp_va < 58)
		Temp_Ranyou = 130;

}




void Acquisition_Bar(void)
{
    uint16_t i,bar1,bar2,soc_temp;
    if(AIR_TYPE == VOLT)
    {
        bar1 = Bar1Source / 10;
        bar2 = Bar2Source / 10;

        if((bar1 < 50))
            veh_bar1 = 0;
        else if(bar1 >= 360)
            veh_bar1 = 120;
        else
            veh_bar1 = 0.4*(bar1 - 50);

        if((bar2 < 50))
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
	#if USEDRANYOUTEMP
	GetRanyouTemp();
	#endif
	#if USEDVBATTEMP
	GetVbatTemp();
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
        veh_speed = 3600.0 / Pulse * speed_freq ;
        if(veh_speed > 1400)
            veh_speed = 1400;

        veh_speed_display = (veh_speed*0.01)*Coef;
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
    byte[4] = 0;
    byte[5] = 0;
    byte[6] = 0;
    byte[7] = tmp_speed;
    Can1_Tx_Bytes(0x0CFE6CEE,byte,8);
	Can2_Tx_Bytes(0x0CFE6CEE,byte,8);

	#if ANKAI_ABS
	SendCCVS();
	#endif
}



void BCMConfig(void)
{

    static u8 toubiflag = 0,work_time,toubiflag_close = 0,work_time_2 = 0;
	static u8 toubicount;
#if  (Has_Fmode == ON)
    /*  Front BCM output ON & OFF   */
    F_OUT_P1    = UNUSED;
    F_OUT_P9    = UNUSED;
    F_OUT_P2    = UNUSED;
    F_OUT_P10   = SYSTEM_POW && PTD15; 

	#if 0
	if(RFOG_SW!= LAST_HOUWU) //PTD7
	{
		LAST_HOUWU = RFOG_SW;
		if(RFOG_SW)   
		   HOUWUDENG_FUWEI	^= 1;
	}
	if(RROG_INIT)
	{
	   F_OUT_P3 = KEY_ON && BACKLIGHT_SW && (HBEAM_SW||LBEAM_SW||FFOG_SW)&&HOUWUDENG_FUWEI;
	   if(F_OUT_P3)
		 RROG_BIT0 = 1;
	}
	else if(RROG_BIT0)
	{
	   F_OUT_P3 = KEY_ON && BACKLIGHT_SW && HOUWUDENG_FUWEI;
	   if((!KEY_ON)||(!BACKLIGHT_SW))
	   {
		   HOUWUDENG_FUWEI = 0;
		   LAST_HOUWU = 0;
		   RROG_END;
	   }	   	
	}
	
	#else
    F_OUT_P3    = SYSTEM_POW && LED_FRONT_DOOR_SW && BACKLIGHT_SW;
	#endif
    F_OUT_P11   = ((SYSTEM_POW && LEFT_LED_SW) || KEY_EMG) && RIGHT_HZ;      
    F_OUT_P4    = ((SYSTEM_POW && RIGHT_LED_SW)|| KEY_EMG) && RIGHT_HZ;   
#if 1
	//Ͷ�һ����ź�
	if(FRONT_DOOR_OPEN_SW)
	{
		if(toubiflag)
		{
			work_time = 5;	//
			toubiflag = 0;
			toubicount = 1;
		}
	}
	else
	{
		toubiflag = 1;
	}

	F_OUT_P12	= SYSTEM_POW && (work_time > 0);									  // 鎶曞竵鏈轰俊鍙�
	if(work_time > 0)
		work_time--;

	if((!work_time) && toubicount)
    {
        toubicount ++;
        if(toubicount >= 5) //低电平时间
        {
            toubicount = 0;
            work_time = 5;  //高电平时间
        }
    }

#else	
	F_OUT_P12   = KEY_ON;
#endif
    F_OUT_P5    = SYSTEM_POW && HBEAM_SW;                                                  
    F_OUT_P13   = KEY_ON && (FFOG_SW&& BACKLIGHT_SW);                               
    F_OUT_P6    = KEY_ON && LBEAM_SW; 
#if 0
	if(FRONT_DOOR_CLOSE_SW)
	{
		if(toubiflag_close)
		{
			work_time_2= 5;	//楂樼數骞虫椂闂�
			toubiflag_close = 0;
			//toubicount = 1;
		}
	}
	else
	{
		toubiflag_close = 1;
	}

	F_OUT_P14	= KEY_ON && (work_time_2 > 0);									  // 鎶曞竵鏈轰俊鍙�
	if(work_time_2 > 0)
		work_time_2--;
#else
    F_OUT_P14   = SYSTEM_POW; 
#endif
    F_OUT_P7    = KEY_ON ;                                                  
    F_OUT_P42   = KEY_ON && BACKLIGHT_SW;                                          
    F_OUT_P8    = KEY_ON;                                                  
    F_OUT_P17   = UNUSED;
    if(fbcm_off_line < 10)
        fbcm_off_line++;
    TIP_FBCM_OFF  = ((fbcm_off_line > 9)?1:0);                              // 鍓嶉儴妯″潡绂荤嚎

#endif

#if  (Has_Rmode == ON)

    R_OUT_P1    = KEY_ON && REVERSE_GEAR_SW;                        
    R_OUT_P9    = KEY_ON && (BREAK_SW || BREAK_CONTION);  
	#if 1
	if(RFOG_SW != LAST_HOUWU) //PTD7
	{
		LAST_HOUWU = RFOG_SW;
		if(RFOG_SW)	
		   HOUWUDENG_FUWEI	^= 1;
	}
	if(RROG_INIT)
	{
	   R_OUT_P2 = KEY_ON && BACKLIGHT_SW && (HBEAM_SW || LBEAM_SW || FFOG_SW) && HOUWUDENG_FUWEI;
	   if(R_OUT_P2)
		 RROG_BIT0 = 1;
	}
	else if(RROG_BIT0)
	{
	   R_OUT_P2 = KEY_ON && BACKLIGHT_SW && HOUWUDENG_FUWEI;
	   if((!KEY_ON)||(!BACKLIGHT_SW))
	   {
	       RROG_BIT0 = 0;
		   RROG_BIT1 = 1;
	   }		
	}
	else if(RROG_BIT1)
	{
	   R_OUT_P2   = 0;
	   if((!RFOG_SW)&&((!KEY_ON)||(!BACKLIGHT_SW)))
	   {
		   HOUWUDENG_FUWEI = 0;
		   RROG_END;
	   }
	}
#endif
   // R_OUT_P2    = KEY_ON && (FFOG_SW && BACKLIGHT_SW) && RFOG_SW;        

    R_OUT_P10   = KEY_ON;  
    R_OUT_P3    = SYSTEM_POW && MID_DOOR_OPEN_SW && (veh_speed_display < 30);                                            
    R_OUT_P11   = F_OUT_P11;                                              
    R_OUT_P4    = F_OUT_P4;                                          
    R_OUT_P12   = KEY_ON;                                             
    R_OUT_P5    = KEY_ON && BACKLIGHT_SW && LED_MIDDLE_DOOR_SW;       
    R_OUT_P13   = SYSTEM_POW && MID_DOOR_CLOSE_SW;                          
    R_OUT_P6    = KEY_ON;                                                         
    R_OUT_P14   = KEY_ON && BACKLIGHT_SW;                    
    R_OUT_P7    = KEY_ON && BACKLIGHT_SW && LED_FRONT_DOOR_SW;
    R_OUT_P42   = KEY_ON && BOX_LINGT_SW_2;                                             
    R_OUT_P8    = KEY_ON;                                                
    R_OUT_P17   = UNUSED;

    if(rbcm_off_line < 10)
        rbcm_off_line++;

    TIP_RBCM_OFF          = ((rbcm_off_line > 9)?1:0);                              // 鍚庨儴妯″潡绂荤嚎
#endif

#if  (Has_Tmode == ON)

    /*  Rear BCM output ON & OFF    */
    T_OUT_P1    = F_OUT_P11;     
    T_OUT_P9    = F_OUT_P4;      

	if(PASSAGE_GET_OUT_SW&&(!LED_FRONT_DOOR_SW))
		T_OUT_P2 = 1;
	if(LED_FRONT_DOOR_SW)
		T_OUT_P2 = 0;
	
    T_OUT_P10   = KEY_ON && INSIDE_LED_SW_2;                                              
    T_OUT_P3    = SYSTEM_POW && FRONT_DOOR_OPEN_SW && (veh_speed_display < 30);                                     
    T_OUT_P11   = KEY_ON && REVERSE_GEAR_SW;                                    
    T_OUT_P4    = KEY_ON && LUPAI_LIGHT;  
    T_OUT_P12   = SYSTEM_POW && LED_FRONT_DOOR_SW && BACKLIGHT_SW;                                           
    T_OUT_P5    = KEY_ON && FRONT_DOOR_CLOSE_SW;                                    
    T_OUT_P13   = KEY_ON && DRIVER_SW;                           
    T_OUT_P6    = KEY_ON && LUPAI_LIGHT;                                                         
    T_OUT_P14   = KEY_ON && LUPAI_LIGHT;                       
    T_OUT_P7    = KEY_ON && BACKLIGHT_SW;
	T_OUT_P42	= KEY_ON && BREAK_ALL;    
	#if 1
	if(RFOG_SW != LAST_HOUWU) //PTD7
	{
		LAST_HOUWU = RFOG_SW;
		if(RFOG_SW)	
		   HOUWUDENG_FUWEI	^= 1;
	}
	if(RROG_INIT)
	{
	   T_OUT_P8 = KEY_ON && BACKLIGHT_SW && (HBEAM_SW || LBEAM_SW || FFOG_SW) && HOUWUDENG_FUWEI;
	   if(T_OUT_P8)
		 RROG_BIT0 = 1;
	}
	else if(RROG_BIT0)
	{
	   T_OUT_P8 = KEY_ON && BACKLIGHT_SW && HOUWUDENG_FUWEI;
	   if((!KEY_ON)||(!BACKLIGHT_SW))
	   {
	       RROG_BIT0 = 0;
		   RROG_BIT1 = 1;
	   }		
	}
	else if(RROG_BIT1)
	{
	   T_OUT_P8   = 0;
	   if((!RFOG_SW)&&((!KEY_ON)||(!BACKLIGHT_SW)))
	   {
		   HOUWUDENG_FUWEI = 0;
		   RROG_END;
	   }
	}

	#else
    T_OUT_P8    = KEY_ON && TV_SW;   
	#endif
    T_OUT_P17 = 0;




    if(tbcm_off_line < 10)
        tbcm_off_line++;

    TIP_TBCM_OFF          = ((tbcm_off_line > 9)?1:0);                              // 椤堕儴妯″潡绂荤嚎
#endif






    //浠〃杈撳嚭

    METER_OPEN_E3      = F_OUT_P11;
    METER_OPEN_E6      = F_OUT_P4;
	//if(PASSAGE_GET_OUT_SW && (!LED_MIDDLE_DOOR_SW))
	//	METER_OPEN_E7 = 1;
	//if(LED_MIDDLE_DOOR_SW)
   // 	METER_OPEN_E7 = 0;
    METER_OPEN_E7 = KEY_ON && BREAK_ALL;
	METER_OPEN_E8      = KEY_ON && REVERSE_GEAR_SW;
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
	static u8 emg_time = 20,zuo_time = 20,you_time = 20;
    // 鍚庨浘鐏�
    RFOG_WL         = KEY_ON  && LED_RFOG_SW;
	// ABS鏁呴殰
    ABS_WL          = KEY_ON  && LED_ABS_SW;//(LED_ABS_SW || START_FLAG);
	// 鍙宠浆鍚�
	//RIGHT           = LED_RIGHT_SW;
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
	//LEFT            =  LED_LEFT_SW;
	// 鎵嬪埗鍔�
	PARK_WL         = (KEY_ON || KEY_POWER) && LED_PARK_SW;
	// 姘存俯楂�
    ENG_TEMP_HOT_WL = KEY_ON && LED_ENG_TEMP_HOT_SW;
	// 鍙戝姩鏈鸿埍
    ENG_DOOR_WL     = SYSTEM_POW && LED_ENG_DOOR_SW;                
	//  涓棬
    MDOOR_WL        = (KEY_ON || KEY_POWER) && LED_MIDDLE_DOOR_SW;     
	//  鐕冩补浣�
    FUEL_LOW_WL     = KEY_ON && LED_FUEL_LOW_SW;
	//  鍓嶉棬
    FDOOR_WL        = (KEY_ON || KEY_POWER) && LED_FRONT_DOOR_SW;   
	//
    GENERATOR1_WL   = KEY_ON && LED_GENERATOR_SW;


	//------------------ת��ƴ���(����ΪƵ���ź�)
	if(KEY_EMG)
	{
		emg_time = 0;
	}

    if(emg_time < 10)
    {
		KMG_FLAG = 1;
		emg_time++;
    }
	else
	{
		KMG_FLAG = 0;
		emg_time = 20;
	}

	if(RIGHT_LED_SW)
	{
		you_time = 0;
	}

    if(you_time < 10)
    {
		YOU_FLAG = 1;
		you_time++;
    }
	else
	{
		YOU_FLAG = 0;
		you_time = 20;
	}

	
	if(LEFT_LED_SW)
	{
		zuo_time = 0;
	}

    if(zuo_time < 10)
    {
		ZUO_FLAG = 1;
		zuo_time++;
    }
	else
	{
		ZUO_FLAG = 0;
		zuo_time = 20;
	}
	if(OPENSYSTEMCHECK)
    {
       RIGHT = KEY_ON;
	   LEFT = KEY_ON;
	}
	else
	{
	    RIGHT =  ((SYSTEM_POW  && YOU_FLAG)|| KMG_FLAG) && RIGHT_HZ;
	    LEFT =   ((SYSTEM_POW  && ZUO_FLAG)|| KMG_FLAG) && RIGHT_HZ;
	}

	//-------------------
	if((KEY_ON||KEY_CHARGE) && (OPENSYSTEMCHECK || SELF_TEST))
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
  static u8 charge_time = 0,go_one = 0,time05s = 0,lizuo_time = 0,light = 0;
  static u8 temp1,temp2,temp3;
  	
/*绗﹀彿鐗囧畾涔� BYTE0 BIT7 寮�  BIT0缁撴潫*/

 if(charge_time > 0)
	 charge_time--;
 
 if(Battery_Charge_Curr < 32000)
 {
	 if((32000 - Battery_Charge_Curr) > 100)
	 {
		 if(!go_one)
		 {
			 go_one = 1;
			 charge_time = 50;
		 }
	 }
	 else
	 {
		 charge_time = 50;
		 go_one = 0;
	 }
 }
 else
 {
	 charge_time = 50;
	 go_one = 0;
 }

 //Ħ��Ƭ
 SYMBOL_POSITION00    = PLANT_ALL;
 //Ӧ����
 SYMBOL_POSITION01    = EMERGENCY_ALL;   
 //ˮλ��
 SYMBOL_POSITION02    = DEFINE_TIP_WATER_LOW;
 //�ƶ�(��ɲ)
 SYMBOL_POSITION03    = (BREAK_SW || BREAK_CONTION);   
 //���ƶ�
 SYMBOL_POSITION04    = ELEC_BREAK;
 //С��
 SYMBOL_POSITION05    = BACKLIGHT_SW;
 //��ȫ��
 SYMBOL_POSITION06    = SEATBELT_NO_SW;
 //�����
 SYMBOL_POSITION07    = fault;   

 //С�ڹ�
 SYMBOL_POSITION08    = (TIP_0XB3||TIP_0X67||TIP_0X97||TIP_0X7C||TIP_0X9A||TIP_0XCF);      
 //soc��
 SYMBOL_POSITION09    = ((ID_18FF2A48_data5 == 104)||(ID_18FF2A48_data5 == 214));
 //��ع���
 SYMBOL_POSITION10    = ((ID_18FF2848_data7&0x03)>0);  
 //����¶ȸ�
 SYMBOL_POSITION11    = ((ID_18FF2A48_data5 == 103)||(ID_18FF2A48_data5 == 3));  
 //ASR
 if(ASR_SW_Y||ASR_SW||START_FLAG)
 	 SYMBOL_POSITION12    =  1;	//N/A
 else if(ASR_SW_BLINK)
   SYMBOL_POSITION12 = (light > 4);
 else
  SYMBOL_POSITION12 = 0;  
 //MSD
 SYMBOL_POSITION13    = ((_0CFFEB4A[0] & 0x40) == 0x40); 
 //���
 SYMBOL_POSITION14    = charge_mark_1 && (charge_time == 0);
 //�������
 SYMBOL_POSITION15    = charge_mark_1;  

 //����̵�����
 SYMBOL_POSITION16    = (timeout[ID(0x0CFF0A4A)] < 50) && ((Control_information_data0&0x80) == 0x80); 
 //����̵�����
 SYMBOL_POSITION17    = (timeout[ID(0x0CFF0A4A)] < 50)&&((Control_information_data0&0x80) == 0); 
 //��ؽӴ���״̬(��2λ)
 SYMBOL_POSITION18    = (timeout[ID(0X18FF2848)] < 50)?((ID_18FF2848_data7&0x20) == 0x20):1; 
 SYMBOL_POSITION19    = (timeout[ID(0X18FF2848)] < 50)?((ID_18FF2848_data7&0x10) == 0x10):1;
 //���Ǵ�
 SYMBOL_POSITION20    = charge_line;     

 if(PASSAGE_GET_OUT_SW)
 	SYMBOL_POSITION21 = 1;
 else if(LED_FRONT_DOOR_SW)
 	SYMBOL_POSITION21 = 0;

 //������������
 SYMBOL_POSITION22    = Low_Buzz.bit.b2; 
 //AUTOHOLD
 SYMBOL_POSITION23    = ((_18FF0152[2] & 0x01) == 0x01);

 //EPB����
 SYMBOL_POSITION24    = ((Add_Comm.byte&0X03)>0);   
 //ITSR
 if(ITSR_MARK)
	SYMBOL_POSITION25	 =	1;	  //N/A
 else if(ITSR_BLINKER)
 {
 	SYMBOL_POSITION25	 =	(time05s > 2);	  //N/A
 }
 else
 	SYMBOL_POSITION25	 =	0;	  //N/A

 //R
 SYMBOL_POSITION26    = REVERSE_GEAR_SW;   
 //N
 SYMBOL_POSITION27    = NULL_SW; 
 //D_SW
 SYMBOL_POSITION28    = D_SW;  
 //�����
 {
  	static u8 lizuotime = 0;
	if(DRIVER_AWAY_SW)
	{
	  lizuotime++;
	  if(lizuotime > 30)
	  {
	    lizuotime = 30;
		LIZUO_FLAG = 1;
		SYMBOL_POSITION29  =1;
	  }
	}
	else
	{
		 lizuotime = 0;
		 LIZUO_FLAG = 0;
		 SYMBOL_POSITION29 =0;
	}
}

 //ASR
 SYMBOL_POSITION30    = SAFE_DOOR_SW;//LED_MIDDLE_DOOR_SW;    
 //MSD鏂紑
 SYMBOL_POSITION31    =LED_FRONT_DOOR_SW;  

 //EP
 SYMBOL_POSITION32    = Add_Comm.bit.b4; 
 //H
 SYMBOL_POSITION33    = Add_Comm.bit.b6;   
 //MCU����
 SYMBOL_POSITION34    = TIP_0X99||TIP_0X9A||TIP_0X9B; 
 //������
 SYMBOL_POSITION35    = ((ID_18FF2D47_data6&0X01) == 0X01);   
 //����
 SYMBOL_POSITION36    = DEFINE_TIP_SPEED||CHAOSU; 
 //READY\STOP\START
 if(STOP_MARK)
 {
	 SYMBOL_POSITION37	  = 1;	   
	 SYMBOL_POSITION38	  = 0; 
 }
 else if(READY)
 {
	 SYMBOL_POSITION37	  = 0;	   
	 SYMBOL_POSITION38	  = 1; 
 }
 else if(START_MARK)
 {
	 SYMBOL_POSITION37	  = 1;	   
	 SYMBOL_POSITION38	  = 1; 
 }
 else	
 {
	 SYMBOL_POSITION37	  = 0;	   
	 SYMBOL_POSITION38	  = 0; 
 }

 SYMBOL_POSITION39    = (add[1] == 109);

 SYMBOL_POSITION40    = ((CanData[ID(0x0CFF0F4A)][1] & 0X03) == 0X03);
 
 SYMBOL_POSITION41    = UNUSED;//(fuel_percent < 15);  
 
 SYMBOL_POSITION42    = UNUSED;//(AIRLOW_FRONTDOOR_SW || AIRLOW_MIDDOOR_SW);
 SYMBOL_POSITION43    = TestBitTrue(CanData[ID(0x0CFF0B4A)][1],6);    
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


 if(light++ == 10)
	   light = 0;
 time05s ++;
 if(time05s > 5)
 	time05s = 0; 
 //符号片需要蜂鸣器
 SYMBOLBUZZ = 0;
}









void SystemLogic(void)
{

  static u8 flag= 0,pwmcount = 20,time3S = 60;
  static u8 time200ms = 0,time1000ms = 0;
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
 
  if(KEY_ON && (time3S > 0))
  {
  	START_FLAG = 1;
  	time3S -- ;
  }
  else
  	START_FLAG = 0;
  BCMConfig();
  set_output();
  LedHand();
 // eng_speed = 6000;
  
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
   GongJiaoHouTai();
  j1939_tx_100ms();
  time200ms++;
  if(time200ms >= 2)
  {
	  j1939_tx_200ms();
	  time200ms = 0;
  }
#if ANKAI_ABS  
  time1000ms++;
  if(time1000ms >= 10)
  {
  	j1939_tx_1000ms();
  	time1000ms = 0;
  }
#endif
  ClearCanDataManage();
}


//
void BuzzLogic(void)
{
    static u16 buzzdelay = 300;
    if(KEY_ON && BUZZ_NORMAL_WORK && (buzzdelay == 0))
    {
        if((ZUO_FLAG || YOU_FLAG || KMG_FLAG || SELF_TEST))
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
	#if ANKAI_ADD_SCREEC_FOR_PARK
    else if(NO_PARK && (!KEY_ON) && PARK_BUZZZ_FLAG)
    {
		BEEP_FAULT();
    }
	#endif
	else
	{
		BEEP_OFF();
	}  

	
    if(buzzdelay > 0)
	   buzzdelay--;	
}








































