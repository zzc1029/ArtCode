/*
 * system.c
 *
 *  Created on: 2021-11-29
 *      Author: ART
 */

#include "system_init.h"


volatile u8 ReInitDisplayFlag = 0;


TYPE_QWORD Art;
TYPE_BYTE  JINLONG_DOOR;

//Bcan��¼
uint8_t BCanSendDisable;
volatile uint8_t BcanDelay,Pcan1Delay,Pcan2Delay,Pcan3Delay,DcanDelay,speed_life;
uint8_t tmp_buff[7];
rtc_t       rtc;
volatile uint32_t SysTickPer1ms;
volatile uint32_t A5Count,A15Count;
volatile uint16_t    eng_speed;      //engine speed
volatile uint16_t    veh_speed;      //vehicle speed
volatile uint16_t    veh_speed_display;
uint16_t veh_bar1;
uint16_t veh_bar2;
uint16_t Vbat;
volatile uint16_t    veh_soc;
uint16_t    speed_count;
uint8_t blinker = 0,blink_gz = 0;

volatile TAIYA taiya;


u8 transmit[8] = {0};

#if Has_Fmode
volatile uint8_t FrontCurrent[16];
#endif

#if Has_Rmode
volatile uint8_t RearCurrent[16];
#endif

#if Has_Tmode
volatile uint8_t TopCurrent[16];
#endif
u32 TMS_Code_Time;



uint32_t    Veh_odo,Pre_odo,Set_Veh_odo,Pre_trip;
uint32_t    Veh_trip;

uint8_t  Temp_Vbat;
uint8_t  fuel_percent;

volatile u32 ABS_DTC[4];
volatile TYPE_BYTE Fault[5];
volatile u8 PeiDianOutSta[43],PeiDianTemp[14];
volatile u16 PeiDianOutCur[45];
u8 data_0x18FFC13A[8];


TYPE_BYTE   metre_state2[6],metre_state3[6];

const u32 displayidtable[] =
{
	0x18F0010B,
	0x18F0089E,
	0x18FA0617,
	0x18FE4A97,
	0x18FE4B97,
	0x18FF0B97,
	0x18FF0C9C,
	0x18FF2997,
	0x18FF3AF4,
	0x18FF6597,
	0x18FF65AC,
	0x18FF8DAC,
	0x18FFA898,
	0x18FFC13A,
	0x18FFEA97,
	0x18FFEB97,
	0x18FFF797,
	0x18FFF897,
	0x18FFF997,
	0x18FFFB97,
	//0x18FFFC97,
	//0x18FFFD97,
	0x19FFB71E,
	0x19FFB81E,
	0x19FFB91E,
	0x19FFBA1E,
	0x19FFBB1E,
	0x19FFBD1E,
};

#define DISPLAY_CAN_COUNT  ((sizeof(displayidtable)/sizeof(displayidtable[0])))

u16 CheckInArray(u32 id, const u32 arry[], u16 arrylen)
{
    u32 mid;
    u32 low = 0;
    u32 high = arrylen - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arry[mid] == id)
        {
            return 1;
        }
        if(arry[mid] < id)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return 0;
}

void CanRecvHook(u16 index)
{
    extern u8 dis_mod;
	u8 i;
	u8 data[8];
    u32 id = Pcan1GetIDFromIndex(index);
    if(CheckInArray(id, displayidtable, DISPLAY_CAN_COUNT))
    {
    	if(id == 0x18FFC13A)
		{
			if(timeout[ID(0x18FFC13A)] > 100)
			{
				data[BYTE1] = 0x10;
				for(i=1;i<8;i++)
					data[i] = 0;
			}
			else
			{
				data[BYTE1] = CanData[ID(0x18FFC13A)][BYTE1] & 0x0F;
				data[BYTE2] = CanData[ID(0x18FFC13A)][BYTE2];
				data[BYTE3] = CanData[ID(0x18FFC13A)][BYTE3];
				data[BYTE4] = CanData[ID(0x18FFC13A)][BYTE4];
				data[BYTE5] = CanData[ID(0x18FFC13A)][BYTE5];
				data[BYTE6] = CanData[ID(0x18FFC13A)][BYTE7];
				data[BYTE7] = CanData[ID(0x18FFC13A)][BYTE6];
				data[BYTE8] = CanData[ID(0x18FFC13A)][BYTE8];
				
			}
			DCan_Expend_Tx_Bytes(id, (uint8_t *)data, 8);
		}
		else if(id == 0x18FF0C9C)
		{
			if(timeout[ID(0x18FF0C9C)] > 100)
				CanData[ID(0x18FF0C9C)][BYTE2] = 0x08;
			else
				CanData[ID(0x18FF0C9C)][BYTE2] = CanData[ID(0x18FF0C9C)][BYTE2] & 0xF7;
			DCan_Expend_Tx_Bytes(id, (uint8_t *)CanData[index], 8);
		}
		else if(id == 0x18FA0617)
		{
			DCan_Expend_Tx_Bytes(id, (uint8_t *)data_0x18FFC13A,8);
		}
		else
       		DCan_Expend_Tx_Bytes(id, (uint8_t *)CanData[index], 8);
		
    }
}

void init_data(void)
{
    u8 i;
    Pre_odo = Veh_odo;
	Pre_trip = Veh_trip;
    Set_backlight_level = backlight_level;
    BUZZ_LAST_STATE = BUZZ_NORMAL_WORK;
    //ClearCanDataInit();
}



//油量
void  GetFuel(void)
{
    uint8_t fuelsource;
	fuelsource = FUELSOURCE;
	#if(FUELTYPE == FUELFULL_180)
	if((fuelsource <= 6) || (fuelsource > 250))
		fuel_percent = 0;
	else if(fuelsource <= 77)
		fuel_percent = 0.7062*(fuelsource)-4.2373;
	else if(fuelsource <= 180)
		fuel_percent = 0.4845*(fuelsource)+12.7907;
	else 
		fuel_percent = 100;
	#elif(FUELTYPE == FUELFULL_6)
	if(fuelsource >= 106)
		fuel = 0;
	else if(fuelsource >= 70)
		fuel = 73.61 - 0.694*fuelsource;
	//else if(fuel_temp >= 70)
		//fuel = 60 - 0.5*fuel_temp;
	else if(fuelsource >= 35)
		fuel = 75 - 0.71*fuelsource;
	else 
		fuel = 108 - 1.66*fuelsource;

	#endif
 
    fuel_percent = fuel_percent *0.01* Fuel_Coef;
	if(fuel_percent > 100)
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

const u16 ntc_wg906_table[] =
{
	2419, //20
	2328,
	2240,
	2156,
	2076,
	2000,
	1925,
	1854,
	1786,
	1721,
	1659,
	1599,
	1542,
	1487,
	1434,
	1384,
	1335,
	1289,
	1244,
	1201,
	1160,
	1121,
	1083,
	1046,
	1011,
	977,
	945,
	914,
	884,
	855,
	827,
	801,
	775,
	751,
	727,
	705,
	683,
	662,
	641,
	622,
	603,
	585,
	567,
	550,
	534,
	518,
	503,
	488,
	474,
	460,
	447,
	434,
	421,
	409,
	398,
	386,
	376,
	365,
	355,
	345,
	336,
	327,
	318,
	309,
	301,
	293,
	285,
	277,
	270,
	263,
	256,
	250,
	243,
	237,
	231,
	225,
	219,
	214,
	209,
	203,
	198,
	194,
	189,
	184,
	180,
	176,
	171,
	167,
	163,
	159,
	156,
	152,
	149,
	145,
	142,
	139,
	135,
	132,
	129,
	126 //120
};

//��������
void  GetVbatTemp(void)
{
	u8 i,data[8] = {0};
	u16 temp_va = VBATTEMPSOUTCE;
	
	for(i = 0;i < 100;i++)//sizeof(Temp_Value)
	{
	   if(temp_va >= ntc_wg906_table[i])
	   {
		  Temp_Vbat = i+20;
		  break;
	   }
	}
	
	if(i == 0)
	   Temp_Vbat = 19; //浣庝簬20搴�
	   
	if(i == 100)
	   Temp_Vbat = 121;//瓒呰繃120搴�


	data[0] = Temp_Vbat;
	//PCan1_Expend_Tx_Bytes(0x18ffd217,data,8);

}






void Acquisition_Bar(void)
{
    uint16_t i,bar1,bar2,soc_temp;
    if(AIR_TYPE == VOLT)
    {
        bar1 = Bar1Source/10;
        bar2 = Bar2Source/10;

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
    veh_bar2 = veh_bar2*0.01*Air_Coef;

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


//
void Acquisition_Task (void)
{
    get_date();
    Acquisition_Bar();
	#if USEDVBATTEMP
	GetVbatTemp();
    #endif
    #if USEDFUEL
    GetFuel();
   	#endif
}


static void Wenzi_Alarm_Static()
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
    TIP_0X3F  =   ((METER_OPEN_E8 == 1) && (METER_OUT_E8 == 2))?1:0;


}

#define NORMAL_BEEP    24
#define FAST_BEEP      12 


u8 fengmignqi(u8 contion,u8 time)
{                               
    static u8 flag,looptime;     
	u8  re = FALSE;            
	if(contion != flag)          
	{                           
       if(contion && (!flag))    
       {                        
          if(blinker == 1)      
          {                     
            looptime = time;      
		    flag = contion;       
          }                     
	   }                        
	   else                    
	   	flag = contion;       
	}                          
	if(looptime > 0)            
	{                          
		looptime--;             
		re = TRUE;	           
	}                          
	return FALSE;                        
}

#define TAIYA_SYMBOL  (TIP_0XC2||TIP_0XC3||TIP_0XC4||TIP_0XC5||TIP_0XC6||TIP_0XC7||TIP_0XC8||TIP_0XC9\
	||TIP_0XCA||TIP_0XCB||TIP_0XCC||TIP_0XCD||TIP_0XCE||TIP_0XCF||TIP_0XD0||TIP_0XD1||TIP_0XD2||TIP_0XD3\
	||TIP_0XD4||TIP_0XD5||TIP_0XD6||TIP_0XD7||TIP_0XD8||TIP_0XD9||TIP_0XDA||TIP_0XDB||TIP_0XDC||TIP_0XDD\
	||TIP_0XDE||TIP_0XDF)

static void Rool_Alarm_Handle(void)
{
    static uint16_t time = 0,buzz_time,timexx;
    static uint8_t add_time,add_flag,flag_30s,flag_10s,pre_door_time,meihuosan,meihuosanflag,meihuowu,meihuowuflag;
    static uint16_t falgggg,passgetoff;
    static u16 timex,time1,time2;
	static u8 time_3ci = 0,last_3ci_flag = 0;
	static u16 timesoc1,time3,time4,timesoc2,miehuo_period = 0;
	static u8 loop,lopflag = 0,shangche_buzz = 0,xiache_buzz = 0,miehuo_buzz;
	u8 i;
	TYPE_WORD Buzz_3Times_Normal;
	TYPE_BYTE Buzz_3Times_Hurry;
	static u16 last_buzz_nomal;
	static u8 last_buzz_hurry,buzz_nomal_time = 0,buzz_hurry_time = 0;
#if ISRELEASE
    Wenzi_Alarm_Static();

	Get_ID_Off++;
    if(Get_ID_Off > 900)
    {
        Get_ID_Off = 900;
    }
    TIP_0X44  = DEFINE_TIP_LEAST_VOLT;
    TIP_0X45  = UNUSE;
    TIP_0X46  = DEFINE_TIP_SPEED;
    TIP_0X47  = SHEBEICANG_FOGALARM;
    TIP_0X48  = AIR1_LOW;
    TIP_0X49  = AIR2_LOW;
    TIP_0X4A  = UNUSE;
    TIP_0X4B  = UNUSE;
    TIP_0X4C  = UNUSE;
    TIP_0X4D  = UNUSE;
    TIP_0X4E  = LED_FILTER_SW;
    TIP_0X4F  = UNUSE;
    TIP_0X50  = PLANT_LEFT_F;
    TIP_0X51  = PLANT_RIGHT_F;
    TIP_0X52  = PLANT_LEFT_R;
    TIP_0X53  = PLANT_RIGHT_R;
    TIP_0X54  = UNUSE;
    TIP_0X55  = EMERGENCY_INSIDE_GAI_SW;
    TIP_0X56  = EMERGENCY_INSIDE_XUANZHUAN_SW;
    TIP_0X57  = UNUSE;
    TIP_0X58  = UNUSE;
    TIP_0X59  = UNUSE;
    TIP_0X5A  = UNUSE;
    TIP_0X5B  = TestBits(CanData[ID(0x18FFEA97)][3],3,3,1);
    TIP_0X5C  = TestBits(CanData[ID(0x18FFEA97)][3],3,3,2);
	/*{
		if(TIP_0X5C != last_3ci_flag)
		{
			if(TIP_0X5C)
			{
				//if(blinker == 1)
				{
					time_3ci = 24;
					last_3ci_flag = TIP_0X5C;
				}
			}
			else
				last_3ci_flag = TIP_0X5C;
			
		}
		if(time_3ci > 0)
			time_3ci--;
	}*/
#endif

    TIP_0X5D  = TestBits(CanData[ID(0x18FFEA97)][3],3,3,3);
    TIP_0X5E  = TestBits(CanData[ID(0x18FFEA97)][3],3,3,4);
    TIP_0X5F  = UNUSE;
    TIP_0X60  = UNUSE;
    TIP_0X61  = UNUSE;
    TIP_0X62  = UNUSE;

    TIP_0X63  = UNUSE;
    TIP_0X64  = UNUSE;
    TIP_0X65  = UNUSE;
    TIP_0X66  = UNUSE;
    TIP_0X67  = UNUSE;
    TIP_0X68  = UNUSE;
    TIP_0X69  = UNUSE;
    TIP_0X6A  = UNUSE;
    TIP_0X6B  = UNUSE;

    TIP_0X6C  = UNUSE;
    TIP_0X6D  = UNUSE;
    TIP_0X6E  = UNUSE;
    TIP_0X6F  = UNUSE;

    TIP_0X78  = UNUSE;
    TIP_0X79  = UNUSE;
    TIP_0X7A  = UNUSE;
    TIP_0X7B  = UNUSE;
    TIP_0X7C  = UNUSE;
    TIP_0X7D  = UNUSE;
    TIP_0X7E  = UNUSE;
    TIP_0X7F  = UNUSE;
    TIP_0X80  = UNUSE;
    TIP_0X81  =  UNUSE;
    TIP_0X82  = UNUSE;
    TIP_0X83  = UNUSE;
    TIP_0X84  = UNUSE;
    TIP_0X85  = (CanData[ID(0x18FFF797)][0] >= 145);
    TIP_0X86  = (CanData[ID(0x18FFF797)][1] >= 125);
    TIP_0X87  = UNUSE;
    TIP_0X88  = UNUSE;
    TIP_0X89  = UNUSE;
    TIP_0X8A  = UNUSE;
	
    if(bcm_senor2_f <= 271)
	  	TIP_0X8B  = 1;
	else if((bcm_senor2_f > 280))
	 	 TIP_0X8B = 0;
	
    TIP_0X8C  = UNUSE;
    TIP_0X8D  = UNUSE;
    TIP_0X8E  = UNUSE;
    TIP_0X8F  = UNUSE;
    TIP_0X90  = UNUSE;
    TIP_0X91  = UNUSE;
	TIP_0X92  = UNUSE;
	TIP_0X93  = UNUSE;
	TIP_0X94  = WAITUI_RIRHT_CHUANG;
	TIP_0X95  = WAITUI_LEFT_CHUANG;
	TIP_0X96  = UNUSE;
	TIP_0X97  = UNUSE;
	TIP_0X98  = UNUSE;
	TIP_0X99  = UNUSE;
	TIP_0X9A  = UNUSE;
	TIP_0X9B  = WATER_BATT_SW;
	{
		u16 daihao1,daihao2;
		daihao1 = GetU16BEData(CanData[ID(0x18FF6597)][2],CanData[ID(0x18FF6597)][1]);
		daihao1 = daihao1 >> 5;
		daihao2 = GetU16BEData(CanData[ID(0x18FF6597)][4],CanData[ID(0x18FF6597)][3]);
		TIP_0X9C  =(daihao1 ==15)&&(daihao2 == 7);

	}
	TIP_0X9D  = WATER_MOTOR_SW;
	TIP_0X9E  = LED_FRONT_DOOR_SW &&(veh_speed_display > 40);
	TIP_0X9F  = LED_MIDDLE_DOOR_SW &&(veh_speed_display > 40);
	
	TIP_0XA0  = UNUSE;
	TIP_0XA1  = UNUSE;

	//��ʱͣ������
	TIP_0XA2  = TestBits(CanData[ID(0x18FF8DAC)][BYTE2],0,4,6);
	TIP_0XA3  = TestBits(CanData[ID(0x18FF8DAC)][BYTE2],0,4,5);
	TIP_0XA4  = TestBits(CanData[ID(0x18FF8DAC)][BYTE3],0,2,1) && TestBits(CanData[ID(0x18FF8DAC)][BYTE1],4,4,1);
	TIP_0XA5  = TestBits(CanData[ID(0x18FF8DAC)][BYTE3],0,2,1) && TestBits(CanData[ID(0x18FF8DAC)][BYTE2],0,4,5);
	
	/*if(PASSAGE_FLAG != PASSAGE_GET_OUT_SW)
    {
      if(PASSAGE_GET_OUT_SW)
	  	falgggg = 0;
	  PASSAGE_FLAG = PASSAGE_GET_OUT_SW;
	}
	if(PASSAGE_GET_OUT_SW)
		TIP_0XA6 = 1;
	else if(LED_MIDDLE_DOOR_SW)
	{
	  falgggg = 0;
	  TIP_0XA6 = 0;
	}*/
	if(PASSAGE_GET_OUT_SW)
		TIP_0XA6 = 1;
	if(LED_MIDDLE_DOOR_SW)
	{
//	  falgggg = 0;
	  TIP_0XA6 = 0;
	}


	
    if(PASSAGE_GET_OUT_SW != PRE_PASSAGE)
    {
       PRE_PASSAGE = PASSAGE_GET_OUT_SW;
	   if(PASSAGE_GET_OUT_SW)
	     passgetoff = 24;	
    }

	
	if(passgetoff > 0)
		passgetoff--;
	
	TIP_0XA7  = TestBitTrue(CanData[ID(0x18FFEA97)][7],4);
	TIP_0XA8  = TestBitTrue(CanData[ID(0x18FFEA97)][7],5);
	TIP_0XA9  = TestBitTrue(CanData[ID(0x18FFEA97)][7],6);
	TIP_0XAA  = TestBitTrue(CanData[ID(0x18FFEA97)][7],7);

	TIP_0XAB  = TestBits(CanData[ID(0x18FFA898)][0],0,2,2);
	TIP_0XAC  = TestBits(CanData[ID(0x18FFA898)][0],6,2,2);//(CanData[ID(0x18FFA898)][1] == 0X01);

	
	TIP_0XAD  = TestBits(CanData[ID(0x18FFFE97)][0],0,3,1);
	TIP_0XAE  = TestBits(CanData[ID(0x18FFFE97)][0],0,3,2);
	
	TIP_0XAF  = TestBits(CanData[ID(0x18FFFE97)][0],0,3,3);
	TIP_0XB0  = TestBits(CanData[ID(0x18FFFE97)][0],0,3,4);
	TIP_0XB1  = TestBits(CanData[ID(0x18FFFE97)][0],0,3,5);
	TIP_0XB2  = TestBits(CanData[ID(0x18FFFE97)][0],3,3,1);
	TIP_0XB3  = TestBits(CanData[ID(0x18FFFE97)][0],3,3,2);
	TIP_0XB4  = TestBits(CanData[ID(0x18FFFE97)][0],6,2,1);
	TIP_0XB5  = TestBits(CanData[ID(0x18FFFE97)][0],6,2,2);
	TIP_0XB6  = TestBits(CanData[ID(0x18FFFE97)][1],6,2,1)||TestBits(CanData[ID(0x18FFFE97)][1],6,2,2);
	TIP_0XB7  = DOOR_FLAG;
	TIP_0XB8  = UNUSE;
	TIP_0XB9  = UNUSE;
	TIP_0XBA  = EMERGENCY_OUTSIDE_GAI_SW;
	TIP_0XBB  = EMERGENCY_OUTSIDE_XUANZHUAN_SW;
	TIP_0XBC = UNUSE;  
	TIP_0XBD = UNUSE;   
	TIP_0XBE = UNUSE;
	TIP_0XBF = TestBitTrue(CanData[ID(0x18FFFE97)][2],0);
	TIP_0XC0 = TestBitTrue(CanData[ID(0x18FFFE97)][2],1);
	TIP_0XC1 = (Fault[3].bit.b3 == 1);

  //  #define TAIYA_ALARM_ENABLE(n,)  TestBits(taiya.fault_status[n],0,2,1)
    
    TIP_0XC2 = TestBits(taiya.fault_status[0],2,2,1);
	TIP_0XC3 = TestBits(taiya.fault_status[1],2,2,1);
	TIP_0XC4 = TestBits(taiya.fault_status[2],2,2,1);
	TIP_0XC5 = TestBits(taiya.fault_status[3],2,2,1);
	TIP_0XC6 = TestBits(taiya.fault_status[4],2,2,1);
	TIP_0XC7 = TestBits(taiya.fault_status[5],2,2,1);

	TIP_0XC8 = TestBits(taiya.fault_status[0],0,2,3);
	TIP_0XC9 = TestBits(taiya.fault_status[1],0,2,3);
	TIP_0XCA = TestBits(taiya.fault_status[2],0,2,3);
	TIP_0XCB = TestBits(taiya.fault_status[3],0,2,3);
	TIP_0XCC = TestBits(taiya.fault_status[4],0,2,3);
	TIP_0XCD = TestBits(taiya.fault_status[5],0,2,3);

	TIP_0XCE = TestBits(taiya.fault_status[0],4,2,1);
	TIP_0XCF = TestBits(taiya.fault_status[1],4,2,1);
	TIP_0XD0 = TestBits(taiya.fault_status[2],4,2,1);
	TIP_0XD1 = TestBits(taiya.fault_status[3],4,2,1);
	TIP_0XD2 = TestBits(taiya.fault_status[4],4,2,1);
	TIP_0XD3 = TestBits(taiya.fault_status[5],4,2,1);

    TIP_0XD4 = TestBits(taiya.error[0],0,3,1);
	TIP_0XD5 = TestBits(taiya.error[1],0,3,1);
	TIP_0XD6 = TestBits(taiya.error[2],0,3,1);
	TIP_0XD7 = TestBits(taiya.error[3],0,3,1);
	TIP_0XD8 = TestBits(taiya.error[4],0,3,1);
	TIP_0XD9 = TestBits(taiya.error[5],0,3,1);

	TIP_0XDA = TestBits(taiya.error[0],0,3,3);
	TIP_0XDB = TestBits(taiya.error[1],0,3,3);
	TIP_0XDC = TestBits(taiya.error[2],0,3,3);
	TIP_0XDD = TestBits(taiya.error[3],0,3,3);
	TIP_0XDE = TestBits(taiya.error[4],0,3,3);
	TIP_0XDF = TestBits(taiya.error[5],0,3,3);

    TIP_0XE0 = (Meihuo[0].alarm_level > 0);
	TIP_0XE1 = (Meihuo[1].alarm_level > 0);
	TIP_0XE2 = (Meihuo[2].alarm_level > 0);
	TIP_0XE3 = (Meihuo[3].alarm_level > 0);
	TIP_0XE4 = (Meihuo[4].alarm_level > 0);
	TIP_0XE5 = (Meihuo[5].alarm_level > 0);
	TIP_0XE6 = (Meihuo[6].alarm_level > 0);
	TIP_0XE7 = (Meihuo[7].alarm_level > 0);
	TIP_0XE8 = (Meihuo[8].alarm_level > 0);
	TIP_0XE9 = (Meihuo[9].alarm_level > 0);
	TIP_0XEA = (Meihuo[10].alarm_level > 0);
	TIP_0XEB = (Meihuo[11].alarm_level > 0);
	TIP_0XEC = (Meihuo[12].alarm_level > 0);
	TIP_0XED = (Meihuo[13].alarm_level > 0);
	TIP_0XEE = (Meihuo[14].alarm_level > 0);

    TIP_0XEF = TestBits(CanData[ID(0x18FF8DAC)][2],2,2,1);


	
#if CLOSE_DOOR_WANT_VOICE //关门三声提示声
	if((PRE_FRONT_DOOR != FRONT_DOOR_SW) || (PRE_MIDDLE_DOOR != MID_DOOR_SW))
	{

	   if(((PRE_FRONT_DOOR) && (!FRONT_DOOR_SW)) || ((PRE_MIDDLE_DOOR) && (!MID_DOOR_SW)))
	   {
	      pre_door_time = 16;
	   }
	   PRE_FRONT_DOOR = FRONT_DOOR_SW;
	   PRE_MIDDLE_DOOR = MID_DOOR_SW;
	}

    if(pre_door_time > 0)
    {
        pre_door_time--;
    }
#endif

	
	if((veh_soc <= 12)&&(timesoc1 == 0))
	{
		time3 = 16;
		timesoc1 = 600;
	}
	if(!(veh_soc <= 12))
	{
		time3 = 0;
		timesoc1 = 0;
	}
	if(time3 > 0)
		time3 --;
	if(timesoc1 > 0)
		timesoc1 --;

	if((veh_soc > 12)&&(veh_soc <= 20)&&(timesoc2 == 0))
	{
	    if(timesoc2 == 0)
	    {
		  time4 = 18;
		  timesoc2 = 1;
		}
	}
	if(!((veh_soc > 12)&&(veh_soc <= 20)))
	{
		timesoc2 = 0;
		time2 = 0;
	}
	if(time4 > 0)
		time4 --;



	
	if(TestBits(CanData[ID(0x18FFEA97)][3],3,3,4))
	{
	 if(lopflag == 0)
	 {
	   if(blinker == 1)
	   {
	     lopflag = 1;
		 loop = 12;
	   }
	 }
	}
	else
	{
	  lopflag = 0;
	  loop = 0;
	}

	if(loop > 0)
	   loop--;


   
   
//--------------------------------------------------------------------------------

	Buzz_3Times_Normal.bit.b0 = TIP_0XA7;
	Buzz_3Times_Normal.bit.b1 = TIP_0X5C;
	Buzz_3Times_Normal.bit.b2 = TIP_0XA9;
	Buzz_3Times_Normal.bit.b3= (((veh_soc*0.4) <=20) && ((veh_soc*0.4) > 12));
	Buzz_3Times_Normal.bit.b4= TIP_0XAD ;
	Buzz_3Times_Normal.bit.b5= (TIP_0XB2);
	Buzz_3Times_Normal.bit.b6= (TIP_0XB4);
	Buzz_3Times_Normal.bit.b7= TestBits(CanData[ID(0x18FFFE97)][1],6,2,1);
	Buzz_3Times_Normal.bit.b8= TIP_0XAE;
	Buzz_3Times_Normal.bit.b9= TIP_0XAF;
	Buzz_3Times_Normal.bit.b10 = TIP_0X5D;
	if((last_buzz_nomal != Buzz_3Times_Normal.word) && (buzz_nomal_time == 0))
	{
		if(Buzz_3Times_Normal.word > 0)
			buzz_nomal_time = 22;
		last_buzz_nomal = Buzz_3Times_Normal.word;
	}

	Buzz_3Times_Hurry.bit.b0 = TIP_0X5E;
	Buzz_3Times_Hurry.bit.b1 = ((veh_soc*0.4) <=12);
	Buzz_3Times_Hurry.bit.b2 = TIP_0XB0;
	Buzz_3Times_Hurry.bit.b3 = TIP_0XB3;
	Buzz_3Times_Hurry.bit.b4 = TIP_0XB5;
	Buzz_3Times_Hurry.bit.b5 = TestBits(CanData[ID(0x18FFFE97)][1],6,2,2);
	Buzz_3Times_Hurry.bit.b6 = TIP_0XB1;
	if((last_buzz_hurry != Buzz_3Times_Hurry.byte) && (buzz_hurry_time == 0))
	{
		if(Buzz_3Times_Hurry.byte > 0)
			buzz_hurry_time = 11;
		last_buzz_hurry = Buzz_3Times_Hurry.byte;
	}
	if(buzz_nomal_time > 0)
		buzz_nomal_time--;
	if(buzz_hurry_time > 0)
		buzz_hurry_time--;
#if 0
   if(CANJI_SHANGCHE_SW != CANJI_SHANGCHE_FLAG)
   {
   		if(CANJI_SHANGCHE_SW)
   		{
			shangche_buzz = 50;
			CANJI_SYMBOL = 1;
   		}
		
		CANJI_SHANGCHE_FLAG = CANJI_SHANGCHE_SW;
   }

   if(MIDDLE_FLAG != LED_MIDDLE_DOOR_SW)
   {
      if(!LED_MIDDLE_DOOR_SW)
      {
         CANJI_SYMBOL = 0;
	  }
      MIDDLE_FLAG = LED_MIDDLE_DOOR_SW;
   }
   
   if(shangche_buzz > 0)
   	shangche_buzz--;

   
   if(CANJI_XIACHE_SW != CANJI_XIACHE_FLAG)
   {
   		if(CANJI_XIACHE_SW)
			xiache_buzz = 25;
		CANJI_XIACHE_FLAG = CANJI_XIACHE_SW;
   }
   if(xiache_buzz > 0)
   	xiache_buzz--;
#endif
    for(i=0;i<MAX_MIEHUO;i++)
	{
		if(Meihuo[i].alarm_level > 2)
		{
			MIEHUO_ALARMHIGH = 1;
			break;
		}		
	}
	if(i==MAX_MIEHUO)
		MIEHUO_ALARMHIGH = 0;
	
    if(!MIEHUO_ALARMHIGH)
    {
	   	for(i=0;i<MAX_MIEHUO;i++)
		{
			if(Meihuo[i].alarm_level == 2)
			{
				MIEHUO_ALARMLOW = 1;
				break;
			}
		}
	}
	if(i==MAX_MIEHUO)
	{
		MIEHUO_ALARMLOW = 0;
	}
	if(MIEHUO_ALARMHIGH)
	{
		if(miehuo_period == 0)
		{
			miehuo_buzz = 41;
			miehuo_period = 3000;
		}
		if(miehuo_buzz == 0)
			miehuo_period--;
	}
	else if(MIEHUO_ALARMLOW != LAST_MIEHUO_ALARMLOW)
	{
		if(MIEHUO_ALARMLOW)
			miehuo_buzz = 24;
		LAST_MIEHUO_ALARMLOW =MIEHUO_ALARMLOW;
	}
	if(!MIEHUO_ALARMHIGH)
		miehuo_period = 0;
	if(miehuo_buzz > 0)
		miehuo_buzz--;
	
   BUZZ_Normal  =  TIP_0X46||TIP_0X47||TIP_0X4A||TIP_0X4B||TIP_0X4C||TIP_0X4F||TIP_0X50||TIP_0X51||TIP_0X52||(time2 > 0)\
		||TIP_0X53||TIP_0X54||TIP_0X55||TIP_0X56||TIP_0X94||TIP_0X95||TIP_0X47||(time1 > 0)\
		||TIP_0X4E||TIP_0X5A||SAFE_DOOR_SW||(time4 > 0)||TIP_0X9E||TIP_0X9F||LED5_B2\
		||(passgetoff > 0)||TIP_0X47||TIP_0X8B||TIP_0X8A||TIP_0X98||\
		DEFINE_TIP_WATER_LOW||EMERGENCY_ALL||LIZUO_BUZZ_FLAG||(buzz_nomal_time > 0)\
		||ANQUANDA_BUZZ_FLAG||(time_3ci > 0)||TIP_0XB8||(shangche_buzz > 0)||(xiache_buzz > 0)||TIP_0XBF||TIP_0XC0||(miehuo_buzz > 0);

   BUZZ_Critical = TIP_0X45||TIP_0X49 || TIP_0X48 ||(buzz_hurry_time > 0)||TIP_0XEF;


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
    static uint8_t time = 0,clear_mile_time = 0,hit_time = 0,life;
    TYPE_BYTE metre_state[8] = {0},temp_u8;
    u8 data[8],i;

   

     
	if(hit_time > 5)
	{
		hit_time = 0;

	    data[0] = 0; 
	    data[1] = 0;
	    data[2] = veh_bar1*2.5;
	    data[3] = (int)(veh_bar1*2.5) >> 8;
	    data[4] = veh_bar2*2.5;
	    data[5] = (int)(veh_bar2*2.5) >> 8;
	    data[6] = 0;
	    data[7] = 0;
	    Can1_Tx_Bytes(0x18FA0217,data,8);
		//-------------------------------------
		data[0] = 0;
	    data[1] = 0;
	    data[2] = GetU16Low(odometer_const);
	    data[3] = GetU16High(odometer_const);
	    data[4] = 0xff;
	    data[5] = 9;
	    data[6] = 0xff;
	    data[7] = 0xff;
		Can1_Tx_Bytes(0x18FA0B17,data,8);
		//-----------------------------------------
		data[0] = 0XFF;
		temp_u8.byte = 0;
		temp_u8.bit.b0 = SEATBELT_NO_SW;
		temp_u8.bit.b2 = TIP_0X8B;
		temp_u8.bit.b4 = TIP_0X8A;
		temp_u8.bit.b6 = DRIVER_AWAY_SW;
		data[1] = temp_u8.byte;
	    data[2] = 0XFF;
	    data[3] = 0XFF;
	    data[4] = 0xff;
	    data[5] = 0XFF;
	    data[6] = 0xff;
	    data[7] = 0xff;
		Can1_Tx_Bytes(0x18FA2017,data,8);
		//-----------------------------------------
		data[0] = 0XFF;
		data[1] = 0xff;
	    data[2] = 0XFF;
	    data[3] = 0XFF;
	    data[4] = Veh_odo*8;
	    data[5] = ((Veh_odo*8)>>8);
	    data[6] = ((Veh_odo*8)>>16);
	    data[7] = ((Veh_odo*8)>>24);
		Can1_Tx_Bytes(0x18FEE017,data,8);
		//-----------------------------------------
		data[0] = (Vbat*2);
		data[1] = (Vbat*2)>>8;
	    data[2] = 0XFF;
	    data[3] = 0XFF;
	    data[4] = 0xff;
	    data[5] = 0XFF;
	    data[6] = 0xff;
	    data[7] = 0xff;
		Can1_Tx_Bytes(0x18FA1017,data,8);
	}
	else
		hit_time++;
	
	if(clear_mile_time > 2)
	{
		clear_mile_time = 0;
		temp_u8.byte = 0;
		temp_u8.bit.b0 = LED_FRONT_DOOR_SW  && (!DOOR_FLAG);
		temp_u8.bit.b2 = LED_MIDDLE_DOOR_SW && (!DOOR_FLAG);
		temp_u8.bit.b4 = 1;
		temp_u8.bit.b5 = 1;
		temp_u8.bit.b6 = DOOR_FLAG;
	    data[0] = temp_u8.byte;
		
		temp_u8.byte = 0;
		temp_u8.bit.b0 = DRIVER_AWAY_SW;
		temp_u8.bit.b2 = BREAK_SW;
		temp_u8.bit.b4 = LED_PARK_SW;
		temp_u8.bit.b6 = LED_ENG_DOOR_SW;	
	    data[1] = temp_u8.byte;
		
		//һЩ����ȫ������Ч����
	    data[2] = 0xFF;
		
		temp_u8.byte = 0;
		temp_u8.bit.b0 = TestBits(CanData[ID(0x18FFEA97)][1],3,3,1);
		temp_u8.bit.b2 = 1;
		temp_u8.bit.b3 = 1;
		temp_u8.bit.b4 = 1;
		temp_u8.bit.b5 = 1;
		temp_u8.bit.b6 = 1;
		temp_u8.bit.b7 = 1;	
	    data[3] = temp_u8.byte;
		
	    data[4] = 0xff;
	    data[5] = 0xff;
	    data[6] = 0xff;
	    data[7] = 0xff;
		for(i=0;i<8;i++)
			data_0x18FFC13A[i] = data[i];	
      	Can1_Tx_Bytes(0x18FA0617,data,8);
		DCan_Expend_Tx_Bytes(0x18FA0617,data,8);

		
		//---------------------------------
		metre_state2[0].bit.b0  = REVERSE_GEAR_SW;  
		metre_state2[0].bit.b1  = 0;

		metre_state2[0].bit.b2  = LED_FRONT_DOOR_SW && (!DOOR_FLAG);//
		metre_state2[0].bit.b3  = 0;

		metre_state2[0].bit.b4  = LED_MIDDLE_DOOR_SW && (!DOOR_FLAG);
		metre_state2[0].bit.b5  = 0;
		metre_state2[0].bit.b6  = 1;
		metre_state2[0].bit.b7  = 1;


		metre_state2[1].bit.b0  = BREAK_SW||ELEC_BREAK; 
		metre_state2[1].bit.b1  = 0;
		metre_state2[1].bit.b2  = LED_PARK_SW;//��������ſ���
		metre_state2[1].bit.b3  = 0;
		metre_state2[1].bit.b4  = 1;
		metre_state2[1].bit.b5  = 1;
		metre_state2[1].bit.b6  = BUZZ_SW; //����
		metre_state2[1].bit.b7  = 0;

		metre_state2[2].bit.b0  = 1;	  
		metre_state2[2].bit.b1  = 1;
		metre_state2[2].bit.b2  = LED_FFOG_SW;
		metre_state2[2].bit.b3  = 0;
		metre_state2[2].bit.b4  = LED_RFOG_SW;
		metre_state2[2].bit.b5  = 0;
		metre_state2[2].bit.b6  = LED_HBEAM_SW;
		metre_state2[2].bit.b7  = 0;

		metre_state2[3].bit.b0  = LED_LBEAM_SW; 
		metre_state2[3].bit.b1  = 0;
		metre_state2[3].bit.b2  = LED_RIGHT_SW;
		metre_state2[3].bit.b3  = 0;
		metre_state2[3].bit.b4  = LED_LEFT_SW;
		metre_state2[3].bit.b5  = 0;
		metre_state2[3].bit.b6  = KEY_ON;
		metre_state2[3].bit.b7  = 0;

		metre_state2[4].bit.b0  = BACKLIGHT_SW;
		metre_state2[4].bit.b1  = 0;
		metre_state2[4].bit.b2  = NULL_SW;
		metre_state2[4].bit.b3  = 0;
		metre_state2[4].bit.b4  = REVERSE_GEAR_SW;
		metre_state2[4].bit.b5  = 0;
		metre_state2[4].bit.b6  = LED_ENG_DOOR_SW;
		metre_state2[4].bit.b7  = 0;

		metre_state2[5].bit.b0  = 0;	  
		metre_state2[5].bit.b1  = 0;
		metre_state2[5].bit.b2  = 0;
		metre_state2[5].bit.b3  = 0;
		metre_state2[5].bit.b4  = KEY_ACC;
		metre_state2[5].bit.b5  = 0;
		metre_state2[5].bit.b6  = (veh_bar1 < 55);
		metre_state2[5].bit.b7  = 0;

		data[0] = 0x01;
		data[1] = metre_state2[0].byte;
		data[2] = metre_state2[1].byte;
		data[3] = metre_state2[2].byte;
		data[4] = metre_state2[3].byte;
		data[5] = metre_state2[4].byte;
		data[6] = metre_state2[5].byte;
		data[7] = 0XFF;
		Can1_Tx_Bytes(0x18FA0517,data,8);
		//---------------------------------
		metre_state3[0].bit.b0  = ((veh_bar2 < Air_Alarm)); 
		metre_state3[0].bit.b1  = 0;
		metre_state3[0].bit.b2  = 0;
		metre_state3[0].bit.b3  = 0;
		metre_state3[0].bit.b4  = DEFINE_TIP_WATER_LOW;
		metre_state3[0].bit.b5  = 0;
		metre_state3[0].bit.b6  = LED_FILTER_SW;
		metre_state3[0].bit.b7  = 0;


		metre_state3[1].bit.b0  = 1;	  
		metre_state3[1].bit.b1  = 1;
		metre_state3[1].bit.b2  = 1;
		metre_state3[1].bit.b3  = 1;
		metre_state3[1].bit.b4  = CTL_WIPER_HI;
		metre_state3[1].bit.b5  = 0;
		metre_state3[1].bit.b6  = CTL_WIPER_LO;
		metre_state3[1].bit.b7  = 0;

		metre_state3[2].bit.b0  = CTL_WIPER_INT;	  
		metre_state3[2].bit.b1  = 0;
		metre_state3[2].bit.b2  = R_SW_P34;
		metre_state3[2].bit.b3  = 0;
		metre_state3[2].bit.b4  = LED_MIDDLE_DOOR_SW && (!DOOR_FLAG);
		metre_state3[2].bit.b5  = 0;
		metre_state3[2].bit.b6  = 1;
		metre_state3[2].bit.b7  = 1;

		metre_state3[3].bit.b0  = PLANT_LEFT_F;  
		metre_state3[3].bit.b1  = 0;
		metre_state3[3].bit.b2  = 1;
		metre_state3[3].bit.b3  = 1;
		metre_state3[3].bit.b4  = PLANT_LEFT_R;
		metre_state3[3].bit.b5  = 0;
		metre_state3[3].bit.b6  = PLANT_RIGHT_F;
		metre_state3[3].bit.b7  = 0;

		metre_state3[4].bit.b0  = 1;	  
		metre_state3[4].bit.b1  = 1;
		metre_state3[4].bit.b2  = PLANT_RIGHT_R;
		metre_state3[4].bit.b3  = 0;
		metre_state3[4].bit.b4  = 1;
		metre_state3[4].bit.b5  = 1;
		metre_state3[4].bit.b6  = LED_ENG_TEMP_HOT_SW;
		metre_state3[4].bit.b7  = 0;

		metre_state3[5].bit.b0  = 1;	  
		metre_state3[5].bit.b1  = 1;
		metre_state3[5].bit.b2  = (bcm_senor2_t<184);
		metre_state3[5].bit.b3  = 0;
		metre_state3[5].bit.b4  = DEFINE_TIP_LEAST_VOLT;
		metre_state3[5].bit.b5  = 0;
		metre_state3[5].bit.b6  = LED_ABS_SW;
		metre_state3[5].bit.b7  = 0;

		data[0] = 0x02;
		data[1] = metre_state3[0].byte;
		data[2] = metre_state3[1].byte;
		data[3] = metre_state3[2].byte;
		data[4] = metre_state3[3].byte;
		data[5] = metre_state3[4].byte;
		data[6] = metre_state3[5].byte;
		data[7] = 0XFF;
		Can1_Tx_Bytes(0x18FA0517,data,8);

		data[0] = 0x03;
		data[1] = 0;
		data[2] = 0XFF;
		data[3] = 0XFF;
		data[4] = 0XFF;
		data[5] = 0XFF;
		data[6] = 0XFF;
		data[7] = 0XFF;
		Can1_Tx_Bytes(0x18FA0517,data,8);
	}
	else
		clear_mile_time++;

	data[0] = rtc.secs*4;
	data[1] = rtc.mins;
	data[2] = rtc.hours;
	data[3] = rtc.month;
	data[4] = rtc.day;
	data[5] = rtc.year + 15;
	data[6] = 0;
	data[7] = 0;
	life++;
	if(life > 9)
	{
       life = 0;
	   Can1_Tx_Bytes(0x18FEE617,data,8);
	   Can2_Tx_Bytes(0x18FEE617,data,8);
	}
/**************************************************************/

}

void j1939_tx_1000ms(void)
{
	u8 data[8];
	data[0] = 0;
	data[1] = 0;
	data[2] = veh_bar2*10/8;
	data[3] = veh_bar1*10/8;
	data[4] = 0;
	data[5] = 0;
	data[6] = 0;
	data[7] = 0;
	
	Can1_Tx_Bytes(0x18FEAE30,data,8);
	Can2_Tx_Bytes(0x18FEAE30,data,8);
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
		temp_u8.byte = 0;
		temp_u8.bit.b4 = BREAK_SW;
		byte[3] = temp_u8.byte;	  
		byte[4] = 0;
		byte[5] = 0;
		byte[6] = 0;
		byte[7] = 0;
		
		Can1_Tx_Bytes(0x18FEF117,byte,8);

        time = 0;
    }
    time ++;
}


//����0C0CFE6CEE����
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

	SendCCVS();
}


//Ƶ�ʼ��㳵��
void calulate_speed(void)
{
    static uint16_t cur_speed_freq,speed_freq;
    cur_speed_freq = meter.MeterA5;
    if(Pulse != 0)
    {
        veh_speed = 3600.0 / Pulse * speed_freq;
        if(veh_speed > 1400)
            veh_speed = 1400;

        veh_speed_display = (veh_speed*0.01)*Coef;
    }
    else
        veh_speed = 0;

}


void singleMile(void)
{
    static float single_mile;
#if (!CALULATE_SPEED_ENABLE)	
    if(KEY_ON)
    {
        speed_life++;
        single_mile = single_mile + (float)(veh_speed_display / 3.6f / Coef);
        if((single_mile >= 100) && (speed_life < 15))
        {
            single_mile = single_mile - 100;
            Veh_trip++;
            //if(Veh_trip > 9999)
            ///{
            //    Veh_trip = 0;
           // }
			if((Veh_trip%10)==0)
              Veh_odo++;
        }
        else
        {
            if(speed_life > 14)
            {
                veh_speed_display = 0;
                eng_speed = 0;
                speed_life = 15;
            }
        }

    }
	#endif
    C3_Sign_OUT(veh_speed,Pulse);
}



void Send_Msg_Bcm(void)
{
    uint8_t i,buffer[8];
    for(i = 0; i < 8; i++)
    {
        buffer[i] = ctrl_cmd[i].byte;
    }
	
	buffer[7] |= RAIN_STATE;
	i =  Rain_Delay_Time/20;
	buffer[7] |= (i << 4);

	
	BCan_Standard_Tx_Bytes(0X6A4,buffer,8);
}



#define HLBEAM_ENABLE  (F_SW_P33)

void BCMConfig(void)
{
    static u8 toubiflag = 0,work_time,toubiflag_close = 0,work_time_2 = 0;
	static u8 kongtiao5s = 0,powertime = 0,acc_1s = 0;
	static u16 alawy30s,paishuifa2 = 0;
	static u8 per_40 = 0,per_60 = 0,per_75 = 0,per_90 = 0,FrontOpenCount = 0,MiddleOpenCount = 0,FrontCloseCount = 0,MiddleCloseCount = 0;
	
#if  (Has_Fmode == ON)
    /*  Front BCM output ON & OFF   */
    F_OUT_P1   =  UNUSE;
    F_OUT_P9   =  UNUSE;
    F_OUT_P2   =  UNUSE;
    F_OUT_P10  =  ((SYSTEM_POW && RIGHT_LED_SW)|| KEY_EMG) && TURN_HZ;
    F_OUT_P3   =  SYSTEM_POW && ((LBEAM_SW && BACKLIGHT_SW) || (HBEAM_SW && PTD5));
    F_OUT_P11  =  F_OUT_P3;
    F_OUT_P4   =  SYSTEM_POW && (BACKLIGHT_SW && FFOG_SW);
    F_OUT_P12  =  (veh_speed_display < 50);
    if((KEY_ON||KEY_CHARGE) && (Vbat > 200))
		kongtiao5s = 50;
    F_OUT_P5    = (kongtiao5s > 0);
	if(kongtiao5s > 0)
	   kongtiao5s--;
	#if 0
    {
    	static u8 a6_count1;
    	if((veh_speed_display > 10) && (veh_speed_display < 100))//1500MS����
    	{
			F_OUT_P13 = (a6_count1 < 8);
			if((a6_count1++) >= 15)
				a6_count1 = 0;
    	}
		else if((veh_speed_display > 100) && (veh_speed_display < 150))//1000MS����
		{
			F_OUT_P13 = (a6_count1 < 5);
			if((a6_count1++) >= 10)
				a6_count1 = 0;
    	}
		else if((veh_speed_display > 150) && (veh_speed_display < 200))//700MS����
		{
			F_OUT_P13 = (a6_count1 < 4);
			if((a6_count1++) >= 7)
				a6_count1 = 0;
    	}
		else
			F_OUT_P13 = 0;
    }
	#endif
	F_OUT_P13 = 0;
    F_OUT_P6   = F_OUT_P4; 
    F_OUT_P14  = SYSTEM_POW && HBEAM_SW && (!LBEAM_SW); 
    F_OUT_P7   = (!SYSTEM_POW);
    F_OUT_P42  =  F_OUT_P14;
    F_OUT_P8   =  ((SYSTEM_POW && LEFT_LED_SW)|| KEY_EMG) && TURN_HZ;
    F_OUT_P17  =  UNUSE;
#if ISRELEASE
    if(fbcm_off_line < 10)
    {
        fbcm_off_line++;
    }
    TIP_FBCM_OFF          = ((fbcm_off_line > 9) ? 1 : 0);                          // 前部模块离线
#endif

#endif

#if  (Has_Rmode == ON)

    R_OUT_P1    =  SYSTEM_POW && (LED_FRONT_DOOR_SW || LED_MIDDLE_DOOR_SW);
    R_OUT_P9    =  KEY_ON && BREAK_SW ;

	#if 0
    FRONTDOOR_OPEN_FLAG = (FRONT_DOOR_OPEN_SW || ((FRONT_DOOR_OPEN_CLOSE_CAN ||FRONT_DOOR_OPEN_CLOSE_SW)  && (!FRONT_DOOR_SW))) && (veh_speed_display < 50) && (FrontCloseCount == 0);
    if(FRONTDOOR_OPEN_STATUS != FRONTDOOR_OPEN_FLAG)
    {
    	if(FRONTDOOR_OPEN_FLAG)
			FrontOpenCount = 10;
		FRONTDOOR_OPEN_STATUS = FRONTDOOR_OPEN_FLAG;
    }
    R_OUT_P2    = (FrontOpenCount > 0);
	if(FrontOpenCount > 0)
		FrontOpenCount--;
	#endif
	R_OUT_P2    = UNUSED;
	
    if(SYSTEM_POW)
	   acc_1s = 10;
	
    R_OUT_P10   =  (!SYSTEM_POW) && (acc_1s > 0);
	if(acc_1s > 0)
	   acc_1s--;
	
	
    if(SYSTEM_POW)
	   powertime = 80;
    R_OUT_P3    = (powertime > 0);
	if(powertime > 0)
	   powertime--;
	
    R_OUT_P11   =  SYSTEM_POW && BREAK_ALL;

	#if 0
    MIDDLEDOOR_OPEN_FLAG = (MID_DOOR_OPEN_SW || (MIDDLE_DOOR_OPEN_CLOSE_CAN && (!MID_DOOR_SW))) && (veh_speed_display < 50) && (MiddleCloseCount == 0);
    if(MIDDLEDOOR_OPEN_STATUS != MIDDLEDOOR_OPEN_FLAG)
    {
    	if(MIDDLEDOOR_OPEN_FLAG)
			MiddleOpenCount = 10;
		MIDDLEDOOR_OPEN_STATUS = MIDDLEDOOR_OPEN_FLAG;
    }
    R_OUT_P4    = (MiddleOpenCount > 0);
	if(MiddleOpenCount > 0)
		MiddleOpenCount--;
    #endif

	R_OUT_P4 = SYSTEM_POW && BACKLIGHT_SW && LED_FRONT_DOOR_SW;

	#if 0
    MIDDLEDOOR_CLOSE_FLAG = (MID_DOOR_CLOSE_SW || (MIDDLE_DOOR_OPEN_CLOSE_CAN && MID_DOOR_SW)) && (veh_speed_display < 50) && (MiddleOpenCount == 0);
    if(MIDDLEDOOR_CLOSE_STATUS != MIDDLEDOOR_CLOSE_FLAG)
    {
    	if(MIDDLEDOOR_CLOSE_FLAG)
			MiddleCloseCount = 10;
		MIDDLEDOOR_CLOSE_STATUS = MIDDLEDOOR_CLOSE_FLAG;
    }
    R_OUT_P12    = (MiddleCloseCount > 0);
	if(MiddleCloseCount > 0)
		MiddleCloseCount--;
    #endif

    R_OUT_P12    = SYSTEM_POW && BACKLIGHT_SW && LED_MIDDLE_DOOR_SW;
	
    //if((SYSTEM_POW && LEFT_LED_SW) || KEY_EMG)
	//	R_OUT_P5 = F_OUT_P8;
	///else if(BACKLIGHT_SW)
	//	R_OUT_P5 = 1;
	//else
		R_OUT_P5 = 0;
	
   // if((SYSTEM_POW && RIGHT_LED_SW) || KEY_EMG)
	//	R_OUT_P13 = F_OUT_P10;
	//else if(BACKLIGHT_SW)
	//	R_OUT_P13 = 1;
	//else
		R_OUT_P13 = 0;

	//if(TIP_REAR_A6_SHORT)
    R_OUT_P6    =  F_OUT_P10;
    R_OUT_P14   =  SYSTEM_POW && BACKLIGHT_SW;
    R_OUT_P7    =  F_OUT_P8;
    R_OUT_P42   =  SYSTEM_POW && BACKLIGHT_SW;
    R_OUT_P8    =  UNUSED;
    #if 0
    FRONTDOOR_CLOSE_FLAG = (FRONT_DOOR_CLOSE_SW || ((FRONT_DOOR_OPEN_CLOSE_CAN || FRONT_DOOR_OPEN_CLOSE_SW) && FRONT_DOOR_SW)) && (veh_speed_display < 50) && (FrontOpenCount == 0);
    if(FRONTDOOR_CLOSE_STATUS != FRONTDOOR_CLOSE_FLAG)
    {
    	if(FRONTDOOR_CLOSE_FLAG)
			FrontCloseCount = 10;
		FRONTDOOR_CLOSE_STATUS = FRONTDOOR_CLOSE_FLAG;
    }
    R_OUT_P8    = (FrontCloseCount > 0);
	if(FrontCloseCount > 0)
		FrontCloseCount--;
	#endif
    R_OUT_P17   =  UNUSE;



    if(rbcm_off_line < 10)
    {
        rbcm_off_line++;
    }

#if ISRELEASE
    TIP_RBCM_OFF          = ((rbcm_off_line > 9) ? 1 : 0);                          // 
#endif
#endif

#if  (Has_Tmode == ON)

    /*  Rear BCM output ON & OFF    */
    T_OUT_P1    =  SYSTEM_POW && RIGUANGDENG_ZUO_CAN;
    T_OUT_P9    =  R_OUT_P6;
    T_OUT_P2    =  RESET_SWITCH_DELAY((SYSTEM_POW && MID_DOOR_OPEN_SW && (veh_speed_display < 50)),10);
    T_OUT_P10   =  SYSTEM_POW && DRIVER_CAN;
#if 1
    {
    	static u8 a6_count1;
    	if((veh_speed_display > 10) && (veh_speed_display < 100))//1500MS����
    	{
			T_OUT_P3 = (a6_count1 < 5);
			//if((a6_count1++) >= 15)
			//	a6_count1 = 0;
			if((a6_count1++) >= 40)
				a6_count1 = 0;
    	}
		else if((veh_speed_display > 100) && (veh_speed_display < 200))//700MS����
		{
			T_OUT_P3 = (a6_count1 < 5);
			//if((a6_count1++) >= 7)
			//	a6_count1 = 0;
			if((a6_count1++) >= 30)
				a6_count1 = 0;
    	}
		else
			T_OUT_P3 = 0;
    }
#endif

	
  //  T_OUT_P3    =  KEY_ON && (BREAK_SW || ELEC_BREAK || TestBits(CanData[ID(0x18F0010B)][BYTE1],6,2,1));
    T_OUT_P11   =  SYSTEM_POW && DAOCHENGPING_CAN;
    T_OUT_P4    =  SYSTEM_POW && BACKLIGHT_SW && LED_MIDDLE_DOOR_SW;
    T_OUT_P12   =  SYSTEM_POW && BACKLIGHT_SW && LED_FRONT_DOOR_SW;
    if(SYSTEM_POW && PASSAGE_GET_OUT_SW && (!LED_MIDDLE_DOOR_SW))
		T_OUT_P5 =1;
	if(LED_MIDDLE_DOOR_SW)
		T_OUT_P5 =0;
    T_OUT_P13   =  RESET_SWITCH_DELAY((SYSTEM_POW && MID_DOOR_CLOSE_SW && (veh_speed_display < 50)),10);;
    T_OUT_P6    =  R_OUT_P7;
    T_OUT_P14   =  SYSTEM_POW && RIGUANGDENG_YOU_CAN;
    T_OUT_P7    =  SYSTEM_POW && BACKLIGHT_SW;
    T_OUT_P42   =  SYSTEM_POW && BACKLIGHT_SW && FFOG_SW && RFOG_SW;
    T_OUT_P8    =  SYSTEM_POW && REVERSE_GEAR_SW;
    T_OUT_P17   = UNUSE;

    if(tbcm_off_line < 10)
    {
        tbcm_off_line++;
    }
#if ISRELEASE
    TIP_TBCM_OFF          = ((tbcm_off_line > 9) ? 1 : 0);                          // 顶部模块离线
#endif
#endif


	 METER_OPEN_E3      = RESET_SWITCH_DELAY(FRONT_DOOR_OPEN_SW && (veh_speed_display < 50),10);
     METER_OPEN_E6      = KEY_ON && (AIR1_LOW || AIR2_LOW);
     METER_OPEN_E7      = RESET_SWITCH_DELAY((FRONT_DOOR_CLOSE_SW && (veh_speed_display < 50)),10);;
     METER_OPEN_E8      = SYSTEM_POW && REVERSE_GEAR_SW;
	 METER_OPEN_WAKE_UP = UNUSE;

	
    if(pcan_off_line < 10)
    {
        pcan_off_line++;
    }
    TIP_PCAN_OFF          = ((pcan_off_line > 9) ? 1 : 0);

    Send_Msg_Bcm();

}



u8 meihuo_levle()
{
   u8 i,meihuolevel[4] = {0};
   for(i = 0;i < MAX_MIEHUO;i++)
   {
       if(Meihuo[i].alarm_level == 1)
	   	 meihuolevel[0] = 1;
	   else if(Meihuo[i].alarm_level == 2)
	   	 meihuolevel[1] = 1; 
	   else if(Meihuo[i].alarm_level == 3)
	   	 meihuolevel[2] = 1;
	   else if(Meihuo[i].alarm_level == 4)
	   	 meihuolevel[3] = 1;
   }
   if(meihuolevel[3])
   {
      return 4;
   }
   else if(meihuolevel[2])
   {
      return 3;
   }
   else if(meihuolevel[1])
   {
      return 2;
   }
   else if(meihuolevel[0])
   {
      return 1;
   }
   else
   	 return 0;
}


void LED_Handle(void)
{

    
	static u16 charge_time = 0,go_one = 0,time05s = 0,light = 0;//,lizuo_time = 0
	static u8 temp1,temp2,temp3,meihuoflag = 0;
	static u8 hz,hz_2;
	static TYPE_BYTE add_u8;
	u8 i;
	if(hz++ >= 10)
 		hz = 0;
	if(hz_2++ >= 5)
 		hz_2 = 0;
	LED0_B7   = TestBitTrue(CanData[ID(0x18FFEA97)][5],0); 
	LED0_B6   = TestBitTrue(CanData[ID(0x18FFEA97)][4],7);	
	LED0_B5   = ELEC_BREAK;
	LED0_B4   = LED_BREAK_SW_FEEDBACK;				
	LED0_B3   = DEFINE_TIP_WATER_LOW;										
	LED0_B2   = (EMERGENCY_INSIDE_XUANZHUAN_SW || EMERGENCY_OUTSIDE_XUANZHUAN_SW); 
	LED0_B1   = LED_BACKLIGHT_SW_FEEDBACK;													 
	LED0_B0   = PLANT_ALL; 


	 if(ASR_SW||ASR_ON)
		 LED1_B7 = 1;
	 else if(ASR_BLINK)
		LED1_B7	= (hz > 4) ;	//��籣����
	 else
		 LED1_B7 = 0;

	{
		static u16 anquandai_count;
		if(SEATBELT_NO_SW)
		{
			if(veh_speed_display > 2)
				LED1_B6 = (hz > 4);
			else
				LED1_B6 = 1;

			if((veh_speed_display > 150))
			{
				anquandai_count++;
				if(anquandai_count >= 900)
				{
					ANQUANDA_BUZZ_FLAG = 0;
					anquandai_count = 900;
				}
				else
				{
					ANQUANDA_BUZZ_FLAG = 1;
				}
			}
			else
			{
				ANQUANDA_BUZZ_FLAG = 0;
				anquandai_count = 0;
			}
		}
		else
		{
			LED1_B6 = 0;
			ANQUANDA_BUZZ_FLAG = 0;
			anquandai_count = 0;
		}
	}

	LED1_B5   = TestBitTrue(CanData[ID(0x18FFEA97)][5],4);
	LED1_B4   = TestBitTrue(CanData[ID(0x18FFEA97)][5],5);
	LED1_B3   = TestBitTrue(CanData[ID(0x18FFEA97)][4],2); 	
	LED1_B2	  = TestBitTrue(CanData[ID(0x18FFEA97)][4],1);
	LED1_B1	  = TestBitTrue(CanData[ID(0x18FFEA97)][4],0);
	LED1_B0   = TestBitTrue(CanData[ID(0x18FFEA97)][1],6); 

	LED2_B7   = TestBitTrue(CanData[ID(0x18FFEA97)][6],5); 
	if(PASSAGE_GET_OUT_SW)
		LED2_B6	 =	1;	  
	else if(MID_DOOR_SW)
	 	LED2_B6	 =	0;
	
	{
     TYPE_BYTE temp_u8; 
	 temp_u8.byte = 0;
	 temp_u8.byte = CanData[ID(0x18FFEA97)][1]&0x7;//VCU_INFO_1[1].byte&0x7;
	 if((temp_u8.byte != 3) && (temp_u8.byte != 0))//���ڳ��!
	 {
		if(temp_u8.byte < 3)
			temp_u8.byte--;
		LED2_B3   = temp_u8.bit.b0;	   //D
		LED2_B4   = temp_u8.bit.b1;	//N/A
		LED2_B5   = temp_u8.bit.b2;
	 }
	 else if(temp_u8.byte == 3)
	 {
		if(hz > 4)
		{
		   LED2_B3   = 1;    //D
		   LED2_B4   = 1;    //N/A
		   LED2_B5   = 0;
		}
		else
		{
		   LED2_B3   = 0;    //D
		   LED2_B4   = 1;    //N/A
		   LED2_B5   = 0;
		}
	 }

 	}
    LED2_B2   = TestBitTrue(CanData[ID(0x18FFEA97)][0],5);
    LED2_B1   = TestBitTrue(CanData[ID(0x18FFEA97)][0],4);
    LED2_B0   = TestBitTrue(CanData[ID(0x18FFEA97)][0],3);

   	 add_u8.byte = 0;
	 led[3].byte = 0;
	 if(REVERSE_GEAR_SW)
		 add_u8.byte = 1;
	 else if(NULL_SW)
		 add_u8.byte = 2;
	 else if(D_SW)
		 add_u8.byte = 3;	 
	 else if(D1_SW)
		 add_u8.byte = 4;	 
	 else if(D2_SW)
		 add_u8.byte = 5;	 
	 else if(D3_SW)
		 add_u8.byte = 6;	 
	 else if(D4_SW)
		 add_u8.byte = 7;	 
	 else if(D5_SW)
		 add_u8.byte = 8;	 
	 else if(D6_SW)
		 add_u8.byte = 9;	 
	 else
		 add_u8.byte = 0; 
	led[3].byte |= (add_u8.byte << 4);
	LED3_B3 = TestBitTrue(CanData[ID(0x18FFEA97)][4],4);
	LED3_B2 = (TestBitTrue(CanData[ID(0x18FFEA97)][4],3) && TestBitFalse(CanData[ID(0x18FFEA97)][4],4));
	if(TestBits(CanData[ID(0x18FFEA97)][1],3,3,1))
	{
		LED3_B1   = 0;   
		LED3_B0	 = 1;
	}
	else if(TestBits(CanData[ID(0x18FFEA97)][1],3,3,4) || TestBits(CanData[ID(0x18FFEA97)][1],3,3,6))
	{
		LED3_B1   = 1;   
		LED3_B0	 = 0;
	}
	else if(TestBits(CanData[ID(0x18FFEA97)][1],3,3,3) || TestBits(CanData[ID(0x18FFEA97)][1],3,3,5))
	{
		LED3_B1   = 1;   
		LED3_B0	 = 1;
	}
	else
	{
		LED3_B1   = 0;   
		LED3_B0	 = 0;
	} 


    LED4_B7 = KEY_ON &&(EMERGENCY_OUTSIDE_GAI_SW || EMERGENCY_INSIDE_GAI_SW);
    LED4_B6 = KEY_ON && (bcm_senor2_f <= 271);
	{
	 static u16 lizuotime,seattime;
	 static u8 lizuo_light;
	 if(KEY_ST)
	 	KEYSTFLAG = ON;
	 else if(!KEY_ON)
	 	KEYSTFLAG = OFF;
	 
	 if((veh_speed_display < 50)  && (DRIVER_AWAY_SW)&& KEYSTFLAG)//
	 {
	 	seattime++;
		lizuotime++;
		if((seattime > 10) && (lizuotime < 900))
		{
		   seattime = 10;	
		   LED4_B5 = (hz > 4);
		   LIZUO_BUZZ_FLAG = 1;
		}
	  else if((seattime > 10) && (lizuotime >= 900))
		{
			LED4_B5 = 1;
			LIZUO_BUZZ_FLAG = 0;
			lizuotime = 901;
			seattime = 10;	
		}
	 }
	 else
	 {
	 	seattime = 0;
		lizuotime = 0;
		LED4_B5 = 0;
		LIZUO_BUZZ_FLAG = 0;
	 }
  }
    LED4_B4 = TestBitTrue(CanData[ID(0x18FFEA97)][3],5);
    LED4_B3 = TestBitTrue(CanData[ID(0x18FFEA97)][3],4);
    LED4_B2 = TestBitTrue(CanData[ID(0x18FFEA97)][3],3);
    LED4_B1 = TestBitTrue(CanData[ID(0x18FFEA97)][6],4);
    LED4_B0 = TestBitTrue(CanData[ID(0x18FFEA97)][6],3);

	//if(TestBits(CanData[ID(0x18FF4F0B)][0],0,4,1))
	//	LED5_B7 = 1;  
	//else if(TestBits(CanData[ID(0x18FF4F0B)][0],0,4,5))
	//	LED5_B7 = (hz > 4);	
	//else 
	//	LED5_B7 = 0;
	LED5_B7 = WATER_BATT_SW||WATER_MOTOR_SW;
    LED5_B6 = TestBitTrue(CanData[ID(0x18FFEA97)][6],7);
    LED5_B5 = TestBitTrue(CanData[ID(0x18FFEA97)][6],6);
    LED5_B4 = TestBitTrue(CanData[ID(0x18FFEA97)][4],6);
    LED5_B3 = TestBitTrue(CanData[ID(0x18FFEA97)][4],5);
   // LED5_B3 = TestBitTrue(CanData[ID(0x18FFF897)][7],2);
    LED5_B2 = TestBitTrue(CanData[ID(0x18FFEA97)][6],2);
    LED5_B1 = TestBitTrue(CanData[ID(0x18FFEA97)][5],1);
    LED5_B0 = Fault[3].bit.b2;

	LED6_B7 = TestBitTrue(CanData[ID(0x18FFEA97)][7],7); 
	LED6_B6 = TestBitTrue(CanData[ID(0x18FFEA97)][7],6);
    LED6_B5 = TestBitTrue(CanData[ID(0x18FFEA97)][7],5); 
    LED6_B4 = TestBitTrue(CanData[ID(0x18FFEA97)][7],4);
    LED6_B3 = ALL_DOOR && (veh_speed_display > 40);     
    LED6_B2 = TestBitTrue(CanData[ID(0x18FFEA97)][5],6);     
    LED6_B1 = TestBitTrue(CanData[ID(0x18FFEA97)][7],3);
    LED6_B0 = DEFINE_TIP_SPEED;
	

	LED7_B7 = TestBitTrue(CanData[ID(0x18FFFE97)][0],7); 
    LED7_B6 = TestBitTrue(CanData[ID(0x18FFFE97)][0],6);
    LED7_B5 = TestBitTrue(CanData[ID(0x18FFFE97)][0],5); 
    LED7_B4 = TestBitTrue(CanData[ID(0x18FFFE97)][0],4);                    
    LED7_B3 = TestBitTrue(CanData[ID(0x18FFFE97)][0],3);                   
    LED7_B2 = TestBitTrue(CanData[ID(0x18FFFE97)][0],2);               
    LED7_B1 = TestBitTrue(CanData[ID(0x18FFFE97)][0],1);                 
    LED7_B0 = TestBitTrue(CanData[ID(0x18FFFE97)][0],0);              
    
	LED8_B7 = TestBitTrue(CanData[ID(0x18FFFE97)][1],7);     
	LED8_B6 = TestBitTrue(CanData[ID(0x18FFFE97)][1],6);      
	LED8_B5 = TestBitTrue(CanData[ID(0x18FFFE97)][1],5);        
	LED8_B4 = TestBitTrue(CanData[ID(0x18FFFE97)][1],4);      
	LED8_B3 = TestBitTrue(CanData[ID(0x18FFFE97)][1],3);         
	LED8_B2 = TestBitTrue(CanData[ID(0x18FFFE97)][1],2);         
	LED8_B1 = TestBitTrue(CanData[ID(0x18FFFE97)][1],1);
	LED8_B0 = TestBitTrue(CanData[ID(0x18FFFE97)][1],0);

   // epb hong
	LED9_B7 = (timeout[ID(0x18FF8DAC)] > 50) || ((CanData[ID(0x18FF65AC)][BYTE4] != 0)&&(CanData[ID(0x18FF65AC)][BYTE5] != 0));
	//epb lv
	//LED9_B6 = 0;
	if(TIP_0XA2)
	  LED9_B6 = 1;
	else if(TIP_0XA3)
	{
      LED9_B6 = (hz > 4);
	}
	else
	  LED9_B6 = 0;
	
	//if(PODAO_QIBU_ON)
	//	LED9_B5 = 1;
	//else if(PODAO_QIBU_BLINK)
	//	LED9_B5 = (hz > 4);	
	//else
	//	LED9_B5 = 0;
	// yuliu
	LED9_B5 = 0;
	//abs yellow
	LED9_B4 = LED_ABS_SW;      
	//yuliu
	LED9_B3 = UNUSED;//JINZHAN_TINGCHE;  
	//yuliu
	LED9_B2 = UNUSED;
	//̥ѹ
	LED9_B1 = TAIYA_SYMBOL;      
	LED9_B0 = (RearCurrent[A2] > 20); 

	LED10_B3 = LED_ENG_DOOR_SW;
	//EPB ��ɫ
	//if(TIP_0XA2)
	//  LED10_B2 = 1;
	//else if(TIP_0XA3)
	//{
    //  LED10_B2 = (hz > 4);
	//}
	//else
	  LED10_B2 = 0;
	
	//EPB��ɫ
	LED10_B1 = UNUSED;
	//��
	LED10_B0 = (meihuo_levle() > 0);

    LEFT_WL       = (SYSTEM_POW || KEY_EMG) && LED_LEFT_SW;      
    LBEAM_WL      = KEY_ON && LED_LBEAM_SW;      
    HBEAM_WL      = KEY_ON && LED_HBEAM_SW;       
    FFOG_WL       = KEY_ON && LED_FFOG_SW;        
    RFOG_WL       = KEY_ON && LED_RFOG_SW;       
    PARK_WL       = SYSTEM_POW && LED_PARK_SW;        
    AIR_LOW_WL    = KEY_ON && LED_AIR_LOW_SW;     
    FDOOR_WL      = SYSTEM_POW && LED_FRONT_DOOR_SW;      
    MDOOR_WL      = SYSTEM_POW && LED_MIDDLE_DOOR_SW;       
    POWER_WL      = SYSTEM_POW;      
    RIGHT_SW      = (SYSTEM_POW || KEY_EMG) && LED_RIGHT_SW;   

    //���ڷ��Ƭ������������û�����ֱ�������
    SYMBOLBUZZ = 0;
}








void LCDLEDControl()
{
    u8 i;
    static uint16_t led_hight_delay = 103;
    static u8 first = 72;
	static u8 first2 = 72,first3 = 72;
    static u8 veh_status = 0;
	static u8 timeout = 0;
	static u8 last = 0xFF,sendscreen = 0;
    static u8 zzc_start = 0;
    if(first > 0)
    {
        first --;
    }

	if(first2 > 0)
    {
        first2 --;
    }

    if(led_hight_delay > 0)
    {
        led_hight_delay --;
    }

	if(timeout) timeout--;

    switch(veh_status)
    {
    
        case 0: //��û��
            if(KEY_ON || KEY_CHARGE)
            {
            	zzc_start++;
				if(zzc_start >= 70)
				{
                	veh_status = 1;
					zzc_start = 70;
				}
            }
			/*else if((!(PTA7||PTA8||PTA9||PTE2)))
			{
              veh_status = 1;

			}*/
            break;
		case 1:
			if(sendscreen)
			{
				sendscreen = 0;
				ChangeToSubPage(SET_MODE, MODE_ACC);
                BACKGROUND_OFF();
			}
			if(KEY_ON || KEY_CHARGE)
            {
                led_hight_delay = led_hight_delay < 32 ? 32 : led_hight_delay;
                first = first < 2 ? 2 : first;
                veh_status = 2;
				//PARK_PAGE_FLAG = 1;
				//PARK_PAGE_BUZZ_FLAG = 1;
            }
			else 
            {
                ChangeToSubPage(SET_MODE, MODE_ACC);
                veh_status = 0;
				BACKGROUND_OFF();
            }
			break;

        case 2: //on
            if(first == 1)
            {	
				ChangeToSubPage(SET_MODE, MODE_NORMAL);
				SetBackGround(backlight_level);
                ONFlag = 1;
                initflag = 1;
            }

            if(led_hight_delay > 0)
            {
                for(i = 0; i < 11; i++)
                {
                    led[i].byte = 0xff;
                }
				LED9_B2 = 0;
				LED9_B3 = 0;
				LED2_B6 = 0;
				ledlogic.word = 0xffff;
            }

            if(!(KEY_ON || KEY_CHARGE))
            {
				timeout = 52;
                veh_status = 1;
				last = 0xFF;

            }
           
            break;
    }

    led_out();
}


#if ART_YIRAN
void YIRANRAN (void)
{
    static u8 i = 0;

    for (i = 0; i < 4; i++)
    {
        if (warn_offline[i] < 60)
        {
            warn_offline[i]++;
        }
    }
    //������
    if (((warn_yiran[0] & 0xf0) > 0) || (warn_offline[0] > 50))
    {
        ANJIANYI_FAU = 1;
        ANJIANYI_WARN = 0;
    }
    else
    {
        ANJIANYI_FAU = 0;
    }
    //̽����1

    if (((warn_yiran[1] & 0xf0) > 0) || (warn_offline[1] > 50))
    {
        TANCE1_FAU = 1;
        TANCE1_WARN = 0;
    }
    else
    {
        TANCE1_FAU = 0;
    }
    //̽����2

    if (((warn_yiran[2] & 0xf0) > 0) || (warn_offline[2] > 50))
    {
        TANCE2_FAU = 1;
        TANCE2_WARN = 0;
    }
    else
    {
        TANCE2_FAU = 0;
    }
    //̽����3

    if (((warn_yiran[3] & 0xf0) > 0) || (warn_offline[3] > 50))
    {
        TANCE3_FAU = 1;
        TANCE3_WARN = 0;
    }
    else
    {
        TANCE3_FAU = 0;
    }
}
#endif

//20220914�����޸�
#define ALL_DOOR_OPEN  (LED_FRONT_DOOR_SW || LED_MIDDLE_DOOR_SW)
void PTB5_flag(void)//DOOR_FLAG
{
  
   if(PTB5)
   {
   	  DOOR_FLAG = 1;
   }
   else if(!(LED_MIDDLE_DOOR_SW || LED_FRONT_DOOR_SW))
   {
	   DOOR_FLAG = 0;
   }
   
   #if 0 
   if(PTB5 != PRE_PTB5)
   {
      PRE_PTB5 = PTB5;
	  if(PTB5)
	    DOOR_FLAG ^= 1;
   }

   if(ALL_DOOR_OPEN != PRE_ALL_DOOR)
   {
      if(PRE_ALL_DOOR && (!ALL_DOOR_OPEN))
	  	 DOOR_FLAG = 0;
	  
	  PRE_ALL_DOOR = ALL_DOOR_OPEN;
   }
#endif

   
}
void CautCode(void)
{
   //if((_18ffc13a[0].byte&0x03)==0x01)
   //	TMS_Code_Time++;
   static u8 othertypetime = 0;
   if(TestBits(CanData[ID(0x18FFC13A)][0],0,2,1))
   {
   	 TMS_Code_Time++;
	 othertypetime = 20;
   }
   else
   {
      if(othertypetime > 0)
	  	 othertypetime--;
	  else
	  {
	    TMSFLAG20S = 1;
	  	TMS_Code_Time = 0;
	  }
   }
}

void  HandTire(void)
{
   u8 i;
   taiya.life++;
   if(taiya.life > 250)
   {
      taiya.life = 250;
	  for(i = 0;i<6;i++)
	  {
        taiya.wendu[i] = 0;
		taiya.yali[i] = 0;
		taiya.fault_status[i] = 0;
		taiya.error[i] = 0;
	  }
   }
}


void SystemLogic(void)
{
   static uint8_t pwmcount = 30;
   static u8 time200ms = 0,time1000ms = 0,TmsWorkTime = 0;
   BCMConfig();
   HandTire();
   LED_Handle();
   led_out();

   LCDLEDControl();
   
   set_output();
   #if((Has_Fmode == ON)||(Has_Tmode == ON)||(Has_Rmode == ON))
	   if(pwmcount > 0)
	   {
		 pwmcount--;
		 Send_PWM_Bcm();
	   }
	   Send_Msg_Bcm();			//内CAN发送信息
   #if  SUPPORT_WIPER
		RainConfig();
   #endif
   #endif
	TmsWorkTime++;
	if(TmsWorkTime > 9)
	{
	CautCode();
	TmsWorkTime = 0;
	}
   Rool_Alarm_Handle();

   j1939_tx_100ms();              //��CAN������Ϣ
   PTB5_flag();
   if(time1000ms >= 10)
   {
   	 j1939_tx_1000ms();
	 time1000ms = 0;
   }
   time1000ms++;
   #if ART_YIRAN
   YIRANRAN();
   #endif
   SaveODO();
   WriteEE();
   //AddSaveMile();
   //SaveODO();
   //clear message data
   ClearCanDataManage();
}


//
void BuzzLogic(void)
{
	static u16 buzzdelay = 1000;
    if(KEY_ON && BUZZ_NORMAL_WORK && ISRELEASE && (buzzdelay == 0))
    {
        if((LEFT_LED_SW || RIGHT_LED_SW || KEY_EMG))
        {    
            BEEP_TURN();
			led_out();
        }
        else if(KEY_ON && BUZZ_Critical && ONFlag)
        {
           BEEP_FAST();
		}
		
		else if(KEY_ON && (BUZZ_Normal || SYMBOLBUZZ) && ONFlag)
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




