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
volatile uint8_t  An_Kai_Handle_Time,_0CFF0C4A[8],_0CFF0D4A[8],Aver_Dianhao,Break_Pent;
volatile uint8_t  Uart2Receive[8],ReceIndex;

//钃勭數姹犳俯搴�
uint8_t  Temp_Vbat,Temp_Engine,Temp_Jiareqi;
volatile uint16_t  fuel_percent;

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
	Oil_Alarm_2012		= Oil_Alarm;
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
void j1939_tx_60s(void)
{
	  u8 data[8];
	  

      data[0] = 0xE9;
      data[1] = 0xFE;
      data[2] = 0;
      data[3] = 0;
      data[4] = 0;
      data[5] = 0;
      data[6] = 0;
      data[7] = 0;
      Can1_Tx_Bytes(0x18EA0021,data,8);
}





/*************************************************************************
* Function Name    : j1939_tx
* Description         : this function is send CAN message to J1939
* Parameters         : None
* Return Value       :None
**************************************************************************/
void j1939_tx_100ms(void)
{
    u32 licheng;
    u8 data[8],what_i_f,i;


	for(i = 0;i <8;i++)
		data[i] = 0;
	
	data[1]= fuel_percent * 2.5;
	Can1_Tx_Bytes(0x18FEFC17,data,8);


	for(i = 0;i <8;i++)
		data[i] = 0;

	licheng = Veh_odo * 8;
	data[4] = licheng;
	data[5] = licheng >> 8;
	data[6] = licheng >> 16;
	data[7] = licheng >> 24;
	
	Can1_Tx_Bytes(0x18FEE000,data,8);



	/*if(LED_PARK_SW)
		what_i_f = 0X04;
	else
		what_i_f = 0x00;
	data[0] = what_i_f;
	data[1] = 0;
	data[2] = veh_speed_display/10;
	if(ADD_E_BREAK1)
		what_i_f = 0x10;
	else
		what_i_f = 0x00;
	data[3] = what_i_f;
	data[4] = 0xff;
	data[5] = 0xff;
	data[6] = 0xff;
	data[7] = 0xff;
	Can1_Tx_Bytes(0x18FEF117, data,8);
	Can2_Tx_Bytes(0x18FEF117, data,8);*/
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
#if (CALULATE_SPEED_ENABLE)
	if(KEY_ON)
	{
		 //speed_life++;
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
    static uint16_t time = 0,buzz_time,timexx,delay60s= 0,time1ci;
    static uint8_t add_time,add_flag,flag_30s,flag_10s,pre_door_time,oildelay2s,xx = 0;

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


	if(!((OIL_LOW && (eng_speed>400))))
	{	
	   oildelay2s= 20;
	}

	if((OIL_LOW) && (eng_speed>400)&&(oildelay2s == 0))
		DelayOILOW = 1;
	else
		DelayOILOW = 0;

	if(oildelay2s > 0)
		oildelay2s--;

	if(!WATER_SW)
	{	
	   delay60s= 600;
	}

	if(WATER_SW &&(delay60s == 0))
		WATER_LOW_FLAG = 1;
	else
		WATER_LOW_FLAG = 0;

	if(delay60s > 0)
		delay60s--;
	if(WATER_LOW_FLAG)
	{
		if(xx == 0)
		{
			xx = 1;
			time1ci = 5;
		}
	}
	else
	{
		xx = 0;
		time1ci = 0;
	}
		
	if(time1ci > 0)
		time1ci--;
	
	TIP_0X44 = DEFINE_TIP_LEAST_VOLT;
	TIP_0X45 = UNUSED;//DEFINE_TIP_AIR_LOW;
	TIP_0X46 = (DEFINE_TIP_SPEED);
	TIP_0X47 = UNUSED;//DEFINE_TIP_PLANT_ALARM;
	TIP_0X48 = WATER_LOW_FLAG;
	TIP_0X49 = UNUSED;
	TIP_0X4A = PASSAGE_GET_OUT_SW;
	TIP_0X4B = EMERGENCY_SW;
	TIP_0X4C = UNUSED;
	TIP_0X4D = AIR1_LOW;
	TIP_0X4E = AIR2_LOW;
	TIP_0X4F = DelayOILOW;//鏈烘补鍘嬪姏浣�
	TIP_0X50 = LED_ENG_TEMP_HOT_SW;//姘存俯楂�
	TIP_0X51 = LED_FILTER_SW;//绌烘护闃诲鎶ヨ
	TIP_0X52 = PLANT_LEFT;
	TIP_0X53 = PLANT_RIGHT;
	TIP_0X54 = (Temp_Vbat > 85);
	TIP_0X55 = (Temp_Engine > 90);//缁濈紭妫�祴鏃犱俊鎭�
	TIP_0X56 = TBOX_GUZHANG;
	TIP_0X57 = TBOX_TONGXUN;
	TIP_0X58 = TBOX_DINGWEI;
	TIP_0X59 = TBOX_TIMEOUT;
	TIP_0X5A = (Temp_Jiareqi> 90);
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



    BUZZ_Normal = TIP_0X45||TIP_0X46||TIP_0X47||TIP_0X49||TIP_0X4B||TIP_0X4C||TIP_0X52||TIP_0X53||\
					(time1ci > 0)||LED_ENG_TEMP_HOT_SW||DelayOILOW||((PASSAGE_GET_OUT_SW||SEATBELT_NO_SW) &&(veh_speed_display > 50))\
					||(Temp_Vbat > 85)||(Temp_Engine > 90)||SAFE_DOOR_SW||(Temp_Jiareqi> 90);

	
    BUZZ_Critical =  TIP_0X4C || TIP_0X4D || TIP_0X4E ||DEFINE_TIP_AIR_LOW||(pre_door_time > 0)||TINGCHE_XINHAO; //姘斿帇鎶ヨ


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

void  GetJiaReQiTemp(void)
{
	u16 i,temp_va;
	temp_va = JIAREQITEMPSOUTCE;
	
	for(i = 0;i < 100;i++)//sizeof(Temp_Value)
	{
	   if(temp_va >= Frist_Temp_V[i])
	   {
		  Temp_Jiareqi = i+20;
		  break;
	   }
	}
	
	if(i == 0)
	   Temp_Jiareqi = 20; //浣庝�0搴�
	   
	if(i == sizeof(Frist_Temp_V))
	   Temp_Jiareqi = 120;//瓒呰�20搴�

	if(temp_va < 58)
		Temp_Jiareqi = 130;
}



void Acquisition_Bar(void)
{
    uint16_t i,bar1,bar2,soc_temp;
    if(AIR_TYPE == VOLT)
    {
        bar1 = Bar1Source /10;
        bar2 = Bar2Source /10;

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
	#if USEDVBATTEMP
	GetVbatTemp();
    #endif
	#if USEDENGINETEMP
	GetEngineTemp();
    #endif
	#if USEDJIAREQITEMP
	GetJiaReQiTemp();
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

    static u8 toubiflag = 0,work_time;
	
#if  (Has_Fmode == ON)
    /*  Front BCM output ON & OFF   */
    F_OUT_P1    = UNUSED;
    F_OUT_P9    = UNUSED;
    F_OUT_P2    = UNUSED;
    F_OUT_P10   = KEY_ON && BUZZ_SW;                                                 
    F_OUT_P3    = KEY_ON && LED_FRONT_DOOR_SW && BACKLIGHT_SW;                     
    F_OUT_P11   = ((SYSTEM_POW && LEFT_LED_SW) || KEY_EMG) && RIGHT_HZ;      
    F_OUT_P4    = ((SYSTEM_POW && RIGHT_LED_SW)|| KEY_EMG) && RIGHT_HZ;   
#if 1
	//Ͷ�һ����ź�
	if(FRONT_DOOR_OPEN_SW)
	{
		if(toubiflag)
		{
			work_time = 5;	//楂樼數骞虫椂闂�
			toubiflag = 0;
			//toubicount = 1;
		}
	}
	else
	{
		toubiflag = 1;
	}

	F_OUT_P12	= KEY_ON && (work_time > 0);									  // 鎶曞竵鏈轰俊鍙�
	if(work_time > 0)
		work_time--;

#endif	
//	F_OUT_P12   = UNUSED;
    F_OUT_P5    = KEY_ON && HBEAM_SW;                                                  
    F_OUT_P13   = KEY_ON && (FFOG_SW&& BACKLIGHT_SW);                               
    F_OUT_P6    = KEY_ON && (LBEAM_SW);                                           
    F_OUT_P14   = KEY_ON;                                
    F_OUT_P7    = KEY_ON;                                                  
    F_OUT_P42   = KEY_ON && BACKLIGHT_SW;                                          
    F_OUT_P8    = KEY_ON;                                                  
    F_OUT_P17   = UNUSED;
    if(fbcm_off_line < 10)
        fbcm_off_line++;
    TIP_FBCM_OFF          = ((fbcm_off_line > 9)?1:0);                              // 鍓嶉儴妯″潡绂荤嚎

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

    R_OUT_P10   = KEY_ON && (veh_speed_display > 50);  
    R_OUT_P3    = KEY_ON && BACKLIGHT_SW;                                            
    R_OUT_P11   = F_OUT_P11;                                              
    R_OUT_P4    = F_OUT_P4;                                          
    R_OUT_P12   = KEY_ON;                                             
    R_OUT_P5    = KEY_ON && BACKLIGHT_SW && LED_MIDDLE_DOOR_SW;       
    R_OUT_P13   = KEY_ON;                          
    R_OUT_P6    = KEY_ON;                                                         
    R_OUT_P14   = KEY_ON && BACKLIGHT_SW;                    
    R_OUT_P7    = SYSTEM_POW &&(veh_speed_display < 50);
    R_OUT_P42   = KEY_ON && BACKLIGHT_SW &&(veh_speed_display < 50);                                             
    R_OUT_P8    = KEY_ON;                                                
    R_OUT_P17   = UNUSED;

    if(rbcm_off_line < 10)
        rbcm_off_line++;

    TIP_RBCM_OFF          = ((rbcm_off_line > 9)?1:0);                              // 鍚庨儴妯″潡绂荤嚎
#endif

#if  (Has_Tmode == ON)

    /*  Rear BCM output ON & OFF    */
    T_OUT_P1    = KEY_ON && LED_FRONT_DOOR_SW && BACKLIGHT_SW;     
    T_OUT_P9    = SYSTEM_POW;      

	T_OUT_P2    = KEY_ON && PASSAGE_GET_OUT_SW &&(!LED_MIDDLE_DOOR_SW);
    T_OUT_P10   = KEY_ON && BACKLIGHT_SW && LED_MIDDLE_DOOR_SW;                                              
    T_OUT_P3    = SYSTEM_POW && MID_DOOR_OPEN_SW&& (veh_speed_display < 30);                                     
    T_OUT_P11   = SYSTEM_POW && MID_DOOR_CLOSE_SW;                                    
    T_OUT_P4    = KEY_ON && LUPAI_LIGHT;  
    T_OUT_P12   = KEY_ON && INSIDE_LED_SW_1;                                           
    T_OUT_P5    = KEY_ON && INSIDE_LED_SW_2 ;                                    
    T_OUT_P13   = KEY_ON && DRIVER_SW;                           
    T_OUT_P6    = KEY_ON && LUPAI_LIGHT;                                                         
    T_OUT_P14   = KEY_ON && LUPAI_LIGHT;                       
    T_OUT_P7    = KEY_ON && BACKLIGHT_SW;
	T_OUT_P42	= SYSTEM_POW && FRONT_DOOR_OPEN_SW && (veh_speed_display < 30);    
    T_OUT_P8    = SYSTEM_POW && FRONT_DOOR_CLOSE_SW;                                            
    T_OUT_P17 = 0;




    if(tbcm_off_line < 10)
        tbcm_off_line++;

    TIP_TBCM_OFF          = ((tbcm_off_line > 9)?1:0);                              // 椤堕儴妯″潡绂荤嚎
#endif






    //浠〃杈撳嚭

    METER_OPEN_E3      = UNUSED;

	if(RFOG_SW!= LAST_HOUWU) //PTD7
	{
		 LAST_HOUWU = RFOG_SW;
		 if(RFOG_SW)   
			HOUWUDENG_FUWEI  ^= 1;
	}
	if(RROG_INIT)
	{
		METER_OPEN_E6 = KEY_ON && BACKLIGHT_SW && (HBEAM_SW||LBEAM_SW||FFOG_SW)&&HOUWUDENG_FUWEI;
		if(METER_OPEN_E6)
			RROG_BIT0 = 1;
	}
	else if(RROG_BIT0)
	{
		METER_OPEN_E6 = KEY_ON && BACKLIGHT_SW && HOUWUDENG_FUWEI;
		if((!KEY_ON)||(!BACKLIGHT_SW))
		{
			HOUWUDENG_FUWEI = 0;
			LAST_HOUWU = 0;
			RROG_END;
		}		 
	}

    METER_OPEN_E7      = METER_OPEN_E6;
	METER_OPEN_E8      = SYSTEM_POW && (veh_speed_display > 50);
	METER_OPEN_WAKE_UP = UNUSED;

}


void LedHand(void)
{
    //纯电面膜实际机油压力低取消
    static u8 selftime = 0;	
	static u8 emg_time = 20,zuo_time = 20,you_time = 20;
    // 鍚庨浘鐏�
    RFOG_WL         = KEY_ON  && LED_RFOG_SW;
	// ABS鏁呴殰
    ABS_WL          = KEY_ON  && LED_ABS_SW;            
	// 鍙宠浆鍚�
	//RIGHT           = ((SYSTEM_POW && LED_RIGHT_SW) || KEY_EMG)&& RIGHT_HZ;
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
	//LEFT            =  ((SYSTEM_POW && LED_LEFT_SW) || KEY_EMG)&& RIGHT_HZ;
	// 鎵嬪埗鍔�
	PARK_WL         = SYSTEM_POW && LED_PARK_SW;
	// 姘存俯楂�
    ENG_TEMP_HOT_WL = KEY_ON && LED_ENG_TEMP_HOT_SW;
	// 鍙戝姩鏈鸿埍
    ENG_DOOR_WL     = SYSTEM_POW && LED_ENG_DOOR_SW;                
	//  涓棬
    MDOOR_WL        = UNUSED;//SYSTEM_POW && LED_MIDDLE_DOOR_SW;     
	//  鐕冩补浣�
    FUEL_LOW_WL     = KEY_ON && LED_FUEL_LOW_SW;
	//  鍓嶉棬
    FDOOR_WL        = SYSTEM_POW && LED_FRONT_DOOR_SW;   
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
 static u8 zzc_flag = 0,blinker = 0,zzc_time = 0,blinker1 = 0;	

 //Ħ��Ƭ
 SYMBOL_POSITION00    = KEY_ON && PLANT_ALL;
 //Ӧ����
 SYMBOL_POSITION01    = KEY_ON && EMERGENCY_ALL;   
 //ˮλ��
 SYMBOL_POSITION02    = KEY_ON && WATER_LOW_FLAG;
 //ɲ��
 SYMBOL_POSITION03    = KEY_ON && BREAK_SW;   
 //С��
 SYMBOL_POSITION04    = KEY_ON && BACKLIGHT_SW;
 //ASR
 SYMBOL_POSITION05	  = ASR_SW;// 
 //��ȫ��δϵ
 SYMBOL_POSITION06    = SEATBELT_NO_SW;
 //���ָʾ1
 SYMBOL_POSITION07    = LED_GENERATOR1_SW;  
 //���ָʾ2
 SYMBOL_POSITION08    = LED_GENERATOR2_SW; 
 //����
 SYMBOL_POSITION09    = DEFINE_TIP_SPEED;
 //У��ָʾ
 SYMBOL_POSITION10    = XIAOCHE_FLAG; 
 //ͣ���ź�
 SYMBOL_POSITION11    = TINGCHE_XINHAO;  
 //��ȫ��
 SYMBOL_POSITION12	=  SAFE_DOOR_SW;// 
 //NCD(��)
 if(zzc_flag)
 	SYMBOL_POSITION13	=  1;// 
 else if((NCD&0X07) == 0X01)
  SYMBOL_POSITION13	= 1;	
 else if((NCD&0X07) == 0X04)
	SYMBOL_POSITION13	= (blinker > 4);	
 else if((NCD&0X07) == 0X00)
	SYMBOL_POSITION13 = 0;

 //NCD(��)
 if(zzc_flag)
 	SYMBOL_POSITION14	=  1;// 
 else if(((NCD >> 3)&0X07) == 0X03)
	SYMBOL_POSITION14	= 1;	
 else if(((NCD >> 3)&0X07) == 0X05)
	SYMBOL_POSITION14 = (blinker > 4);
 else if(((NCD >> 3)&0X07) == 0X00)
	SYMBOL_POSITION14 = 0;
 //wif
 if(zzc_flag)
	 SYMBOL_POSITION15	 =	1;// 
 else 
	 SYMBOL_POSITION15	=  ((youjishui&0X03) == 0x01);  

 //��������ϵ�
 if(zzc_flag)
 	SYMBOL_POSITION16    = 1; 
 else
 	SYMBOL_POSITION16	=  (((ERR_LIGHT[0]&0X03)==0X01) || TestBits(CanData[ID(0x18EBFF00)][BYTE2],0,2,1));  
 //MI��
 if(zzc_flag)
 	SYMBOL_POSITION17 = 1;
 else if(((MIL_light&0X03)==0X02))
 {
    SYMBOL_POSITION17 = (blinker > 4);
 }
 else
 	SYMBOL_POSITION17 = ((MIL_light&0X03)==0X01);

 //DPF����(��)
 SYMBOL_POSITION18    = DPF_ON_R || zzc_flag;

 //DPF����(��)
 if(zzc_flag || DPF_ON_Y)
 	SYMBOL_POSITION19    = 1; 
 else if(DPF_BLINKER_Y)
 	SYMBOL_POSITION19    = (blinker> 4); 
 else
 	SYMBOL_POSITION19 = 0;

 //DPF�����ֹ
 SYMBOL_POSITION20   = DPF_BAN_ON || zzc_flag;
 
 //����������
 SYMBOL_POSITION21   = HUANSUQI_GZ; 

  //TBOX  
 if(TBOX_TIMEOUT || TBOX_GUZHANG)
 	SYMBOL_POSITION22 = 1;
 else if(TBOX_TONGXUN)
 	SYMBOL_POSITION22 = (blinker1> 2);
 else if(TBOX_DINGWEI)
	 SYMBOL_POSITION22 = (blinker> 4);
 else
 	SYMBOL_POSITION22 = 0;  

 //EPB����
 SYMBOL_POSITION23   = UNUSED;   
 //ITSR
 SYMBOL_POSITION24	 =	UNUSED;	  

 //R
 SYMBOL_POSITION25    = UNUSED;   
 //N
 SYMBOL_POSITION26    = REVERSE_GEAR_SW; 
 //D_SW
 SYMBOL_POSITION27    = NULL_SW;  
 //�����
 SYMBOL_POSITION28    = D_SW;   
 //ASR
 SYMBOL_POSITION29    = LED_ENG_DOOR_SW;
 //MSD鏂紑
 SYMBOL_POSITION30    = LED_MIDDLE_DOOR_SW;  

 //EP
 SYMBOL_POSITION31    = LED_FRONT_DOOR_SW;
 //EP
 SYMBOL_POSITION32    = UNUSED; 
 //H
 SYMBOL_POSITION33    = UNUSED;   
 //MCU����
 SYMBOL_POSITION34    = UNUSED; 
 //������
 SYMBOL_POSITION35    = UNUSED;   
 //����
 SYMBOL_POSITION36    = UNUSED; 
 //READY\STOP\START
 SYMBOL_POSITION37	  = UNUSED;	   
 SYMBOL_POSITION38	  = UNUSED; 


 //С��������
 SYMBOL_POSITION39    = UNUSED;  

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

 	blinker++;
	if(blinker > 9) blinker= 0;
	blinker1++;
	if(blinker1 > 4) blinker1= 0;
	if(zzc_time <= 60)
	{
		zzc_time ++;
		zzc_flag = 1;
	}
	else
	{
		zzc_flag = 0;
	}
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

  static u8 flag= 0,pwmcount = 20;
  static u16 can_send1000ms = 0,paifang_count = 0;
  
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
  if(KEY_ON)
	{
		paifang_count++;
		if(paifang_count >= 1800)
		{
			PAIFANG_START = 1;
		}
	}
	else
	{
		paifang_count = 0;
		PAIFANG_START = 0;
		PAIFANG_LIXIAN = 0;
		timeout[ID(0x18FF0257)] = 0;
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
  if(flag > 4)
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
  if((can_send1000ms++) >= 600)
  {
  	j1939_tx_60s();
  	can_send1000ms = 0;
  }
  

  ClearCanDataManage();
  JudgeEngeed1SThan10();
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
    else if(NO_PARK && !KEY_ON)
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








































