/*
 * system.c
 *
 *  Created on: 2021-11-29
 *      Author: ART
 */

#include "system_init.h"


volatile u8 ReInitDisplayFlag = 0;


TYPE_QWORD Art,CanSend_Flag;
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
uint8_t blinker = 0;

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



uint32_t    Veh_odo,Pre_odo,Set_Veh_odo;
uint16_t    Veh_trip;

uint8_t  Temp_Vbat;
uint8_t  fuel_percent;
volatile uint8_t  pengzhang_shuixiang = 0xff;

u8 lizuo = 0;
u32 All_Spn[10];
u8  All_Fmi[10];
u8  All_Oc[10];


const u32 displayidtable[] =
{
    0x0C03A1A7,//
    0x0C04A1A7,//
    0x0C06A1A7,//
    0x0C079AA7,//
    0x0C07A1A7,//
    0x0C08A79A,//
    0x0C08A7F4,//
    0x0C09A1A7,//
    0x0C0AA1A7,//
    0x0C0AA79D,//
    0x0C0AA7F0,//
    0x180028F3,//
    0x180028F4,//
    0x1800D0A8,//
    0x1800D0A9,//
    0x180128F3,//
    0x180128F4,//
    0x1801D0A8,//
    0x180228F3,//
    0x180228F4,//
    0x180328F3,//
    0x180428F3,//
    0x1818D0F3,//
    0x1819D0F3,//
    0x181AD0F3,//
    0x181BD0F3,//
    0x181CD0F3,//
    0x181DD0F3,//
    0x181ED0F3,//
    0x18FE521E,
    0x18FFA898,
    0x18FFC13A,

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
    u32 id = Pcan1GetIDFromIndex(index);
    if(CheckInArray(id, displayidtable, DISPLAY_CAN_COUNT))
    {
        DCan_Expend_Tx_Bytes(id, (uint8_t *)CanData[index], 8);
    }
}

void init_data(void)
{
    u8 i;
    Pre_odo = Veh_odo;
    Set_backlight_level = backlight_level;
    BUZZ_LAST_STATE = BUZZ_NORMAL_WORK;


    //ClearCanDataInit();

}

u8 Get_Spn_Any (u32 low, u32 high)
{
    u8 i, result;
    for (i = 0; i < 10; i++)
    {
        if ((All_Spn[i] >= low) && (All_Spn[i] <= high))
        {
            result = 1;
            break;
        }
    }
    if (i == 10)
    {
        result = 0;
    }
    return result;
}






//油量
void  GetFuel(void)
{
    uint16_t fuelsource;
	fuelsource = FUELSOURCE;
	#if(FUELTYPE == FUELFULL_180)
	/*if((fuelsource <= 6) || (fuelsource > 250))
		fuel_percent = 0;
	else if(fuelsource <= 77)
		fuel_percent = 0.7062*(fuelsource)-4.2373;
	else if(fuelsource <= 180)
		fuel_percent = 0.4845*(fuelsource)+12.7907;
	else 
		fuel_percent = 100;*/
	if((fuelsource <= 10) || (fuelsource > 250))
		fuel_percent = 0;
	else if(fuelsource <= 26)
		fuel_percent = 1.5625 * fuelsource - 15.625;
	else if(fuelsource <= 59)
		fuel_percent = 0.7576 * fuelsource + 5.3016;
	else if(fuelsource <= 115)
		fuel_percent = 0.4464 * fuelsource + 23.664;
	else if(fuelsource <= 180)
		fuel_percent = 0.3846 * fuelsource + 30.772;
	else
		fuel_percent = 100;
	#elif(FUELTYPE == FUELFULL_6)
	if(fuelsource >= 106)
		fuel_percent = 0;
	else if(fuelsource >= 70)
		fuel_percent = 73.61 - 0.694*fuelsource;
	//else if(fuel_temp >= 70)
		//fuel = 60 - 0.5*fuel_temp;
	else if(fuelsource >= 35)
		fuel_percent = 75 - 0.71*fuelsource;
	else 
		fuel_percent = 108 - 1.66*fuelsource;

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



//��������
void  GetVbatTemp(void)
{
	u8 i,data[8] = {0};
	u16 temp_va = VBATTEMPSOUTCE;
	
	for(i = 0;i < 100;i++)//sizeof(Temp_Value)
	{
	   if(temp_va >= Frist_Temp_V[i])
	   {
		  Temp_Vbat = i+20;
		  break;
	   }
	}
	
	if(i == 0)
	   Temp_Vbat = 19; //浣庝簬20搴�
	   
	if(i == 100)
	   Temp_Vbat = 121;//瓒呰繃120搴�

//	if(temp_va > 1500)
//	{
//	   Temp_Vbat = 0xff;//offline
//	   return ;
//	}

	data[0] = Temp_Vbat;
	PCan1_Expend_Tx_Bytes(0x18ffd217,data,8);


}






void Acquisition_Bar(void)
{
    uint16_t i,bar1,bar2,soc_temp;
    if(AIR_TYPE == VOLT)
    {
        bar1 = Bar1Source;
        bar2 = Bar2Source;

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
    veh_bar2 = veh_bar2*0.01*Air_Coef;//Air2_Coef;

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
    TIP_0X3F  =   ((METER_OPEN_E8 == 1) && (METER_OUT_E7 == 2))?1:0;


}

#define _taiya (TIP_0XE2||TIP_0XE1||TIP_0XE0||\
		 TIP_0XD0||TIP_0XD1||TIP_0XD2||TIP_0XD3||TIP_0XD4||TIP_0XD5||TIP_0XD6||TIP_0XD7||TIP_0XD8\
		 ||TIP_0XD9||TIP_0XDA||TIP_0XDB||TIP_0XDC||TIP_0XDD||TIP_0XDE||TIP_0XDF\
		 ||TIP_0XC5||TIP_0XC6||TIP_0XC7||TIP_0XC8||TIP_0XC9||TIP_0XCA||TIP_0XCB||TIP_0XCC||TIP_0XCD\
		 ||TIP_0XCE||TIP_0XCF)


static void Rool_Alarm_Handle(void)
{
    static uint16_t time = 0, pre_door_time = 0;
    u8 index = 0, i;
    static u16 doorbuzzcount = 0;
#if ISRELEASE
    Wenzi_Alarm_Static();
#endif
#if 1
    TIP_0X44 = DEFINE_TIP_LEAST_VOLT;
    TIP_0X45 = DEFINE_TIP_AIR_LOW;
    TIP_0X46 = UNUSE;
    TIP_0X47 = UNUSE;
    TIP_0X48 = DEFINE_TIP_SPEED;
    TIP_0X49 = UNUSE;
    TIP_0X4A = UNUSE;
    TIP_0X4B = UNUSE;//EMERGENCY_OUTSIDE_SW;
    TIP_0X4C = UNUSE;
    TIP_0X4D = UNUSE;
    TIP_0X4E = UNUSE;
    
	TIP_0X4F = TestBitTrue(CanData[ID(0x1818D0F3)][5], 7);
    TIP_0X50 = TestBitTrue(CanData[ID(0x1818D0F3)][5], 6);
    TIP_0X51 = TestBitTrue(CanData[ID(0x1818D0F3)][5], 5);
    TIP_0X52 = TestBitTrue(CanData[ID(0x1818D0F3)][5], 4);
    TIP_0X53 = TestBitTrue(CanData[ID(0x1818D0F3)][5], 3);
    TIP_0X54 = TestBitTrue(CanData[ID(0x1818D0F3)][5], 2);
    TIP_0X55 = TestBitTrue(CanData[ID(0x1818D0F3)][5], 1);
    TIP_0X56 = TestBitTrue(CanData[ID(0x1818D0F3)][5], 0);
    TIP_0X57 = TestBitTrue(CanData[ID(0x1818D0F3)][6], 7);
    TIP_0X58 = TestBitTrue(CanData[ID(0x1818D0F3)][6], 6);
    TIP_0X59 = TestBitTrue(CanData[ID(0x1818D0F3)][6], 5);
    TIP_0X5A = TestBitTrue(CanData[ID(0x1818D0F3)][6], 4);
    TIP_0X5B = TestBitTrue(CanData[ID(0x1818D0F3)][6], 3);
    TIP_0X5C = TestBitTrue(CanData[ID(0x1818D0F3)][6], 2);
    TIP_0X5D = TestBitTrue(CanData[ID(0x1818D0F3)][6], 1);
    TIP_0X5E = TestBitTrue(CanData[ID(0x1818D0F3)][6], 0);
	//1 ���ƶ�����
	TIP_0X5F = ((CanData[ID(0x18FE521E)][BYTE8] & 0x02) == 0x02);
    TIP_0X60 = ((CanData[ID(0x18FE521E)][BYTE8] & 0x04) == 0x04);
    TIP_0X61 = UNUSE;
    TIP_0X62 = UNUSE;
    TIP_0X63 = LED_FRONT_DOOR_SW && (veh_speed_display > 30);
    TIP_0X64 = LED_MIDDLE_DOOR_SW && (veh_speed_display > 30);
    TIP_0X65 = UNUSE;
    TIP_0X66 = CanData[ID(0x1819D0F3)][4] == 1;

    TIP_0X67  = TestBitTrue(CanData[ID(0x181BD0F3)][1], 1);
    TIP_0X68  =  TestBitTrue(CanData[ID(0x181BD0F3)][1], 0);
    TIP_0X69  = TestBitTrue(CanData[ID(0x181BD0F3)][7], 1);
    TIP_0X6A  = TestBitTrue(CanData[ID(0x181BD0F3)][7], 0);

    TIP_0X6B  = UNUSE;
    TIP_0X6C  = UNUSE;

    TIP_0X6D  = TestBitTrue(CanData[ID(0x0C02A70A)][1], 7) || TestBitTrue(CanData[ID(0x0C03A70A)][0], 6) || TestBitTrue(CanData[ID(0x0C03A70A)][1], 0);
    TIP_0X6E  = TestBitTrue(CanData[ID(0x0C02A70A)][2], 1);
    TIP_0X6F  = UNUSE;
    TIP_0X70  = UNUSE;
    TIP_0X71  = UNUSE;
    TIP_0X72  = UNUSE;
    TIP_0X73  = UNUSE;
    TIP_0X74  = UNUSE;
    TIP_0X75  = UNUSE ;



    TIP_0X76 = UNUSE;

    TIP_0X77  = UNUSE;
    TIP_0X78  = UNUSE;
    TIP_0X79  = UNUSE;
    TIP_0X7A  = UNUSE;
    TIP_0X7B  = EMERGENCY_F_OUTSIDE_SW;
    TIP_0X7C  = UNUSE;

    TIP_0X7D  = UNUSE;
    TIP_0X7E  = UNUSE;
    TIP_0X7F  = UNUSE;
    TIP_0X80  = UNUSE;
    TIP_0X81  = UNUSE;
    TIP_0X82  = UNUSE;
    TIP_0X83  = UNUSE;
    TIP_0X84  = UNUSE;


    TIP_0X85 = UNUSE;  //5s
    TIP_0X86 = UNUSE;  //5s
    TIP_0X87 = PLANT_LEFT_F;  //5s
    TIP_0X88 = PLANT_RIGHT_F;  //5s
    TIP_0X89 = EMERGENCY_F_INSIDE_SW;
    TIP_0X8A = EMERGENCY_M_INSIDE_SW;  // 3ci
    TIP_0X8B = EMERGENCY_M_OUTSIDE_SW;  // 5s
    TIP_0X8C = UNUSE;  // ��
    TIP_0X8D = KEY_CHARGE;  // 3ci
    TIP_0X8E = TestBitTrue(CanData[ID(0x181BD0F3)][1], 7);
    TIP_0X8F = TestBitTrue(CanData[ID(0x181BD0F3)][1], 6);
    TIP_0X90 = TestBitTrue(CanData[ID(0x181BD0F3)][1], 5);
    /*********************************  ̥ѹ  *****************************************/
    TIP_0X91 = TestBitTrue(CanData[ID(0x181BD0F3)][1], 4);
    TIP_0X92 = UNUSE;//TestBitTrue(CanData[ID(0x181BD0F3)][7],5);
    TIP_0X93 = TestBitTrue(CanData[ID(0x181BD0F3)][7], 4);
    TIP_0X94 = TestBitTrue(CanData[ID(0x181BD0F3)][7], 3);
    TIP_0X95 = TestBitTrue(CanData[ID(0x181BD0F3)][7], 2);
    TIP_0X96 = UNUSE;
    TIP_0X97 = PLANT_RIGHT_R;
    TIP_0X98 = PLANT_LEFT_R;
    TIP_0X99 = UNUSE;
    TIP_0X9A = UNUSE;
    TIP_0X9B = UNUSE;
    TIP_0X9C = UNUSE;
    TIP_0X9D = WATER_SW;
    TIP_0X9E = UNUSE;
    TIP_0X9F = UNUSE;
    TIP_0XA0 = UNUSE;
    TIP_0XA1 = UNUSE;
    TIP_0XA2 = UNUSE;
    TIP_0XA3 = UNUSE;
    TIP_0XA4 = UNUSE;
    TIP_0XA5 = UNUSE;
    TIP_0XA6 = UNUSE;
    TIP_0XA7 = UNUSE;
    TIP_0XA8 = UNUSE;
    TIP_0XA9 = UNUSE;
	TIP_0XAA = UNUSE;
	TIP_0XAB = UNUSE;
	//�ƶ�ϵͳ���� 20211125����
    /*if(CanData[GetIndexFromID(0x0c079aa7)][4] == 0x55)
		zhidongtime++;
	else
		zhidongtime = 0;
	if(zhidongtime > 12000)
	   zhidongtime = 12000;*/
    TIP_0XAC = UNUSE;//(zhidongtime >= 12000);
	TIP_0XAD = ((CanData[ID(0x18FE521E)][BYTE8] & 0x08) == 0x08);
	TIP_0XAE = ((CanData[ID(0x18FFA898)][BYTE1] & 0x03) == 0x02);
	TIP_0XAF = ((CanData[ID(0x18FFA898)][BYTE1] & 0xC0) == 0x80);
	TIP_0XB0 = UNUSE;
	TIP_0XB1 = UNUSE;
	TIP_0XB2 = UNUSE;
	TIP_0XB3 = UNUSE;
	TIP_0XB4 = UNUSE;
	TIP_0XB5 = UNUSE;
	TIP_0XB6 = UNUSE;
	TIP_0XB7 = UNUSE;
	TIP_0XB8 = UNUSE;
	TIP_0XB9 = UNUSE;
	TIP_0XBA = UNUSE;
	TIP_0XBB = UNUSE;
#endif
	TIP_0XBC = ((MIEHUO.alarm_level[0] > 0) && (MIEHUO.alarm_level[0] < 5));
	TIP_0XBD = ((MIEHUO.alarm_level[1] > 0) && (MIEHUO.alarm_level[1] < 5));
	TIP_0XBE = ((MIEHUO.alarm_level[2] > 0) && (MIEHUO.alarm_level[2] < 5));
	TIP_0XBF = ((MIEHUO.alarm_level[3] > 0) && (MIEHUO.alarm_level[3] < 5));
	TIP_0XC0 = ((MIEHUO.alarm_level[4] > 0) && (MIEHUO.alarm_level[4] < 5));
	TIP_0XC1 = ((MIEHUO.alarm_level[5] > 0) && (MIEHUO.alarm_level[5] < 5));

	
	TIP_0XC2 = LED4_B7;
	
	TIP_0XC3 = CANJI_TABAN;
	
	TIP_0XC4 = LED5_B1;

    TIP_0XC5 = TestBits(taiya.fault_status[0],2,2,1);
	TIP_0XC6 = TestBits(taiya.fault_status[1],2,2,1);
	TIP_0XC7 = TestBits(taiya.fault_status[2],2,2,1);
	TIP_0XC8 = TestBits(taiya.fault_status[3],2,2,1);
	TIP_0XC9 = TestBits(taiya.fault_status[4],2,2,1);
	TIP_0XCA = TestBits(taiya.fault_status[5],2,2,1);

	TIP_0XCB = TestBits(taiya.fault_status[0],4,2,1);
	TIP_0XCC = TestBits(taiya.fault_status[1],4,2,1);
	TIP_0XCD = TestBits(taiya.fault_status[2],4,2,1);
	TIP_0XCE = TestBits(taiya.fault_status[3],4,2,1);
	TIP_0XCF = TestBits(taiya.fault_status[4],4,2,1);
	TIP_0XD0 = TestBits(taiya.fault_status[5],4,2,1);

	TIP_0XD1 = TestBits(taiya.fault_status[0],6,2,1);
	TIP_0XD2 = TestBits(taiya.fault_status[1],6,2,1);
	TIP_0XD3 = TestBits(taiya.fault_status[2],6,2,1);
	TIP_0XD4 = TestBits(taiya.fault_status[3],6,2,1);
	TIP_0XD5 = TestBits(taiya.fault_status[4],6,2,1);
	TIP_0XD6 = TestBits(taiya.fault_status[5],6,2,1);
	
	TIP_0XD7 = TestBits(taiya.error[0],5,3,1);
	TIP_0XD8 = TestBits(taiya.error[1],5,3,1);
	TIP_0XD9 = TestBits(taiya.error[2],5,3,1);
	TIP_0XDA = TestBits(taiya.error[3],5,3,1);
	TIP_0XDB = TestBits(taiya.error[4],5,3,1);
	TIP_0XDC = TestBits(taiya.error[5],5,3,1);

	TIP_0XDD = TestBits(taiya.error[0],5,3,2);
	TIP_0XDE = TestBits(taiya.error[1],5,3,2);
	TIP_0XDF = TestBits(taiya.error[2],5,3,2);
	TIP_0XE0 = TestBits(taiya.error[3],5,3,2);
	TIP_0XE1 = TestBits(taiya.error[4],5,3,2);
	TIP_0XE2 = TestBits(taiya.error[5],5,3,2);



	
#if CLOSE_DOOR_WANT_VOICE //关门三声提示声
	if(LED_FRONT_DOOR_SW || LED_MIDDLE_DOOR_SW)
	{

	   if((((!PRE_FRONT_DOOR) && (LED_FRONT_DOOR_SW)) || ((!PRE_MIDDLE_DOOR) && (LED_MIDDLE_DOOR_SW)))&&(veh_speed_display > 30))
	   {
		  pre_door_time = 20;
	   
	   	  PRE_FRONT_DOOR = LED_FRONT_DOOR_SW;
	   	  PRE_MIDDLE_DOOR = LED_MIDDLE_DOOR_SW;
	   }
	   if(veh_speed_display < 30)
	   	{
			PRE_FRONT_DOOR = 0;
	   	  	PRE_MIDDLE_DOOR = 0;
	   	}
	}
	else
	{
		PRE_FRONT_DOOR = 0;
   	  	PRE_MIDDLE_DOOR = 0;
   	}	

	 if(pre_door_time > 0)
	    pre_door_time--;
#endif

	
		BUZZ_Normal = ((LED2_B5 ||LED3_B3) && (veh_speed_display > 30)) || LED0_B7 || LED2_B4 || LED1_B2 || LED3_B5 || LED0_B0 ||PASSAGE_GET_OUT_SW \
				 	 || (CanData[ID(0x1818D0F3)][5] > 0) || (CanData[ID(0x1818D0F3)][6] > 0)||DEFINE_TIP_SPEED||CANJI_TABAN\
					 || LED1_B7 || ((CanData[ID(0x181BD0F3)][1] & 0xF3) > 0) || ((CanData[ID(0x181BD0F3)][7] & 0x1F) > 0) || LED1_B6 || (pre_door_time > 0)||
					 T_SW_P32||LED5_B2||_taiya||(!R_SW_P32);
	

#if ISRELEASE
    BUZZ_Critical =  TIP_0X45 ; //��ѹ����
#endif

}


/*************************************************************************
* Function Name    : j1939_tx
* Description         : this function is send CAN message to J1939
* Parameters         : None
* Return Value       :None
**************************************************************************/
void j1939_tx_100ms(void)
{
    u8 buffer[8],i;
	u32 odo;
	TYPE_BYTE temp_u8;
	static u8 time_count = 0;
	static u16 zuotime,youtime,time = 0;
	u16 datatemp;
	
	temp_u8.byte = 0;
	temp_u8.bit.b0 = DEFINE_TIP_AIR_LOW;
	temp_u8.bit.b1 = LED_PARK_SW;
	temp_u8.bit.b2 = LED_ENG_DOOR_SW;
    temp_u8.bit.b3 = LED_FRONT_DOOR_SW;
    temp_u8.bit.b4 = LED_MIDDLE_DOOR_SW;
    temp_u8.bit.b5 = KEY_ON;
    temp_u8.bit.b6 = KEY_ACC;
    temp_u8.bit.b7 = KEY_EMG;
	buffer[0] = temp_u8.byte;
	temp_u8.byte = 0;
	temp_u8.bit.b0 = LED_RFOG_SW;
	temp_u8.bit.b1 = LED_LBEAM_SW;
	temp_u8.bit.b2 = 0;
    temp_u8.bit.b3 = 0;
	if(RIGHT_LED_SW)
		youtime = 10;
	if(youtime > 0)
		youtime--;
    temp_u8.bit.b4 = (youtime > 0);
    temp_u8.bit.b5 = LED_FFOG_SW;
    temp_u8.bit.b6 = LED_HBEAM_SW;
	if(LEFT_LED_SW)
		zuotime = 10;
	if(zuotime > 0)
		zuotime--;
    temp_u8.bit.b7 = (zuotime > 0);
	buffer[1] = temp_u8.byte;
	temp_u8.byte = 0;
	temp_u8.bit.b0 = DEFINE_TIP_AIR_LOW;
	temp_u8.bit.b1 = WATER_SW;
	temp_u8.bit.b2 = 0;
    temp_u8.bit.b3 = 0;
    temp_u8.bit.b4 = (CanData[ID(0x18FFF7F6)][BYTE2] == 2) || (CanData[ID(0x18FFF7F6)][BYTE2] == 3) || (CanData[ID(0x18FFF7F6)][BYTE2] == 4);
    temp_u8.bit.b5 = 0;
    temp_u8.bit.b6 = 0;
    temp_u8.bit.b7 = 0;
	buffer[2] = temp_u8.byte;
	buffer[3] = veh_speed_display / 5;
	datatemp = veh_bar1 * 100;
	buffer[4] = GetByteLSB0(datatemp);
	buffer[5] = GetByteLSB1(datatemp);
	datatemp = veh_bar2 * 100;
    buffer[6] = GetByteLSB0(datatemp);
    buffer[7] = GetByteLSB1(datatemp);

	Can1_Tx_Bytes(0x0C19A7A1,buffer,8);
	Can2_Tx_Bytes(0x0C19A7A1,buffer,8);

	if(time < 10)
    {
        time ++;
    }
    else
    {
    	odo = Veh_odo * 10;
		buffer[0] = odo;
		buffer[1] = odo >> 8;
		buffer[2] = odo >> 16; 
		buffer[3] = odo >> 24; 
		buffer[4] = Veh_trip;
		buffer[5] = Veh_trip >> 8;
		buffer[6] = 0;
		buffer[7] = 0;

		Can1_Tx_Bytes(0x0C1AA7A1,buffer,8); 
		Can2_Tx_Bytes(0x0C1AA7A1,buffer,8); 


		buffer[0] = rtc.secs * 4;
		buffer[1] = rtc.mins;
		buffer[2] = rtc.hours; 
		buffer[3] = rtc.month; 
		buffer[4] = rtc.day * 4;
		buffer[5] = rtc.year + 15;
		buffer[6] = 0xff;
		buffer[7] = 0xfa;

		Can1_Tx_Bytes(0x18FEE617,buffer,8); 
		Can2_Tx_Bytes(0x18FEE617,buffer,8); 

        if(C7C8_TO_C5C6)
        {
           C7C8_TO_C5C6 = 0;
		   Can1_Tx_Bytes(0x0C02F4A7,(u8 *)CanData[ID(0x0C02F4A7)],8);    
		}
		if(C5C6_TO_C7C8)
		{
          C5C6_TO_C7C8 = 0;
		  Can2_Tx_Bytes(0x0C09A7F4,(u8 *)CanData[ID(0x0C09A7F4)],8);   
		}
//	case 0x0C02F4A7:
//		C7C8_TO_C5C6 = 1;
//		break;
		
//	case 0x0C09A7F4:
//		C5C6_TO_C7C8 = 1;
//		break;

		
    }

 
/**************************************************************/

}
void send_to_can2(void)
{
	u8 buffer[8],i;
	if(FLAG_0X0C0AA79D)
	{
		for(i = 0;i < 8;i++)
			buffer[i] = fuzhu[i].byte;
	}
	else
	{
		for(i = 0;i < 8;i++)
			buffer[i] = 0;
	}
	Can2_Tx_Bytes(0x0C0AA79D,buffer,8); 

	if(FLAG_0X0C04A1A7)
	{
		for(i = 0;i < 8;i++)
			buffer[i] = _0C04A1A7_DATA[i];
	}
	else
	{
		for(i = 0;i < 8;i++)
			buffer[i] = 0;
	}
	Can2_Tx_Bytes(0x0C04A1A7,buffer,8); 

	if(FLAG_0X0C06A1A7)
	{
		for(i = 0;i < 8;i++)
			buffer[i] = _0C06A1A7_DATA[i];
	}
	else
	{
		for(i = 0;i < 8;i++)
			buffer[i] = 0;
	}
	Can2_Tx_Bytes(0x0C06A1A7,buffer,8); 

	if(FLAG_0X0C079AA7)
	{
		for(i = 0;i < 8;i++)
			buffer[i] = DCDC1[i];
	}
	else
	{
		for(i = 0;i < 8;i++)
			buffer[i] = 0;
	}
	Can2_Tx_Bytes(0x0C079AA7,buffer,8); 
}
//����0C0CFE6CEE����
void Sendspeed(void)
{
    u8 byte[8]= {0};
    u8 tmp_speed = veh_speed_display/ 10;
    byte[4] = 0;//GetU16Low(eng_speed);
    byte[5] = 0;//GetU16High(eng_speed);
    byte[6] = 0;
    byte[7] = tmp_speed;
    Can1_Tx_Bytes(0x0CFE6CEE,byte,8);
}


//Ƶ�ʼ��㳵��
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



void singleMile(void)
{
    static float single_mile;
	C3_Sign_OUT(veh_speed,Pulse);
#if (!CALULATE_SPEED_ENABLE)	
    if(KEY_ON)
    {
        speed_life++;
        single_mile = single_mile + (float)(veh_speed / 3.6f / Coef);
        if((single_mile >= 100) && (speed_life < 15))
        {
            single_mile = single_mile - 100;
            Veh_trip++;
            if(Veh_trip > 9999)
            {
                Veh_trip = 0;
            }
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




void BCMConfig(void)
{
    static u8 fdoor_open_count = 0,fdoor_close_count = 0,mdoor_open_count = 0,mdoor_close_count = 0;
    static uint8_t xx = 0;
	static u16 timexx = 0;
	static u8 last_fdoor_can_flag = 2,last_mdoor_can_flag = 2;
	TYPE_BYTE moudle_out_flag;

#if  (Has_Fmode == ON)
    /*  Front BCM output ON & OFF   */
    F_OUT_P1 = UNUSE;
    F_OUT_P9 = UNUSE;
    F_OUT_P2 = UNUSE;
	
    F_OUT_P10 = ((SYSTEM_POW && RIGHT_LED_SW) || KEY_EMG) && TURN_HZ; 
	F_OUT_P3  = ((SYSTEM_POW && LEFT_LED_SW) || KEY_EMG) && TURN_HZ;
    F_OUT_P11 = SYSTEM_POW && BACKLIGHT_SW;
    F_OUT_P4  = SYSTEM_POW && HBEAM_SW;
	F_OUT_P12 = SYSTEM_POW && (!HBEAM_SW) && LBEAM_SW;
    F_OUT_P5  = SYSTEM_POW && BACKLIGHT_SW && FFOG_SW;  
    F_OUT_P13 = SYSTEM_POW && BUZZ_SW;
    F_OUT_P6  = SYSTEM_POW; 
    F_OUT_P14 = KEY_ON && CHUSHUANG_LOW_SW; 
    F_OUT_P7  = F_OUT_P14;
    F_OUT_P42 = KEY_ON && CHUSHUANG_HIGHT_SW; 
    F_OUT_P8  = F_OUT_P42; 
    F_OUT_P17 = 0;
#if ISRELEASE
    if(fbcm_off_line < 10)
    {
        fbcm_off_line++;
    }
    TIP_FBCM_OFF          = ((fbcm_off_line > 9) ? 1 : 0);                          // 前部模块离线
#endif

#endif

#if  (Has_Rmode == ON)

    R_OUT_P1    = F_OUT_P3;                          //a1 倒车
    R_OUT_P9    = F_OUT_P10;      // a9刹车灯

#if 0
    if((DCDC1[4] == 0xAA)&&(xx == 1)&&KEY_ON)
 	{
     	R_OUT_P2   = 1;
		timexx = 600;
		xx = 0;	
	}
	if((timexx> 0)&&(DCDC1[4] == 0xAA)&&KEY_ON)
	{	
		timexx--;
		R_OUT_P2	= 1;
	}
	else
	{
		timexx = 0;
		R_OUT_P2	= 0;
	}

	if((DCDC1[4] == 0x55) && KEY_ON)
 	{
     	R_OUT_P2   = 1;   
		xx = 1;
	}
#else
	R_OUT_P2 = SYSTEM_POW;
#endif
    R_OUT_P10   = UNUSED;
    R_OUT_P3    = KEY_ON && BREAK_SW;  
    R_OUT_P11   = KEY_ON;
    R_OUT_P4    = SYSTEM_POW && BREAK_ALL;  
    R_OUT_P12   = KEY_ON && BACKLIGHT_SW && FFOG_SW && RFOG_SW;    
    R_OUT_P5    = SYSTEM_POW && LED_MIDDLE_DOOR_SW && BACKLIGHT_SW;
	R_OUT_P13  =  KEY_ON;
	//----------------------------------------------------------
    R_OUT_P6    = KEY_ON && REVERSE_GEAR_SW;
    R_OUT_P14   = SYSTEM_POW && BACKLIGHT_SW;  
    R_OUT_P7    = SYSTEM_POW && BACKLIGHT_SW;  
    R_OUT_P42   = SYSTEM_POW && LCD_SW;       

    R_OUT_P8   = KEY_ON && ((CanData[ID(0x0C0AA79D)][BYTE8] & 0x80)==0x80);
    R_OUT_P17 	= OFF;

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
    T_OUT_P1    = F_OUT_P10; 
    T_OUT_P9    = F_OUT_P3; 
    T_OUT_P2    = SYSTEM_POW && LED_MIDDLE_DOOR_SW && BACKLIGHT_SW;
    T_OUT_P10   = SYSTEM_POW && LED_FRONT_DOOR_SW && BACKLIGHT_SW;
    T_OUT_P3    = SYSTEM_POW && HOU_SHIJING_SW;  
    T_OUT_P11   = SYSTEM_POW && XIANG_DENG1_SW;
	T_OUT_P4    = SYSTEM_POW && XIANG_DENG2_SW;  
    T_OUT_P12   = SYSTEM_POW && BACKLIGHT_SW;    
    T_OUT_P5    = SYSTEM_POW;
	T_OUT_P13   = KEY_ON && REVERSE_GEAR_SW;
    T_OUT_P6    = SYSTEM_POW && BREAK_ALL;
    T_OUT_P14   = SYSTEM_POW && LU_PAI_SW;  
	T_OUT_P7    = KEY_ON && DRIVE_FENGSHAN_SW;
    T_OUT_P42   = SYSTEM_POW;    
    T_OUT_P8    = KEY_ON && DRIVE_LIGHT_SW;   

    T_OUT_P17 = 0;


    if(tbcm_off_line < 10)
    {
        tbcm_off_line++;
    }
#if ISRELEASE
    TIP_TBCM_OFF          = ((tbcm_off_line > 9) ? 1 : 0);                          // 顶部模块离线
#endif
#endif


	 METER_OPEN_E3		= KEY_ON && (!BACKLIGHT_SW);
	 METER_OPEN_E6		= KEY_ON && (veh_speed_display > 30);
	 METER_OPEN_E7	    = KEY_ON && ((F_OUT_P14 && F_OUT_P7)||(F_OUT_P42 && F_OUT_P8));
	 METER_OPEN_E8		= SYSTEM_POW && (OUTSIDE_VOICE_BAN_SW);
	 METER_OPEN_WAKE_UP = UNUSE;

	
    if(pcan_off_line < 10)
    {
        pcan_off_line++;
    }
    TIP_PCAN_OFF          = ((pcan_off_line > 9) ? 1 : 0);

    Send_Msg_Bcm();

}


TYPE_BYTE Last_Syb ;
void SymbolConfig (void) //���Ƭ����
{
    u16 temp;
    static u8 timex = 0, timexx = 0, timexxx = 120, epb_time, asr_time, car1_time, car2_time, person1_time, person2_time;
    Last_Syb.byte = 0;
    temp = GetU16From2U8 (CanData[ID (0x18F201F3)][BYTE5], CanData[ID (0x18F201F3)][BYTE4], LITTLE_ENDIAN);
    if (temp > 36000)
    {
        if (timex <= 5)
        {
            Last_Syb.bit.b7 = 1;
            Last_Syb.bit.b6 = 0;
        }
        else
        {
            Last_Syb.bit.b7 = 0;
            Last_Syb.bit.b6 = 1;
        }

        Last_Syb.bit.b5 = 0;
        Last_Syb.bit.b4 = 0;
    }
    if ((timex++) > 10)
    {
        timex = 1;
    }

    if (temp < 36000)
    {
        if (timexx <= 6)
        {
            Last_Syb.bit.b5 = 1;
            Last_Syb.bit.b4 = 0;
        }
        else
        {
            Last_Syb.bit.b5 = 0;
            Last_Syb.bit.b4 = 1;
        }
        Last_Syb.bit.b7 = 0;
        Last_Syb.bit.b6 = 0;
    }
    if ((timexxx > 0) && (!SHAN_FLAG))
    {
        timexxx --;
        Last_Syb.byte  = 0;
    }
    if ((timexx++) > 10)
    {
        timexx = 1;
    }
    Last_Syb.bit.b3  = ((CanData[ID (0x18F208F3)][BYTE7] & 0x80) == 0x80);

    //ASR��˸���Ƭ����
    if (ASR_SW)
    {
        if (asr_time < 5)
        {
            ASR_BLINKER = 1;
        }
        else
        {
            ASR_BLINKER = 0;
        }

        if (asr_time < 10)
        {
            asr_time ++;
        }
        else
        {
            asr_time = 0;
        }
    }
    else
    {
        asr_time = 0;
        ASR_BLINKER = 0;
    }
	
}

#define delayByCondi(flag, delay_count) \
    ({                                      \
        static uint8_t time = 0;                \
        uint8_t re = 0;                     \
        if(flag)                            \
        {                                   \
            if(time >= delay_count)         \
            {                               \
                re = 1;                     \
            }                               \
            else                            \
            {                               \
                time++;                     \
            }                               \
        }                                   \
        else                                \
        {                                   \
            time = 0;                       \
        }                                   \
        re;                                 \
    })




#define symbol_hz   (BUZZ_Critical ? (blinker < 11) :(blinker < 21)) 

void LED_Handle(void)
{

    uint8_t i;
    static u8 charge_time = 0, go_one = 0,blink = 0;
	static u8 canjiflag = 1,canjitime = 0;
	SymbolConfig();

	lizuo = (delayByCondi (DRIVER_AWAY_SW, 20) && READY);
    
	LED0_B7 = KEY_ON && DEFINE_TIP_PLANT_ALARM;
	LED0_B6 = KEY_ON && LED_BACKLIGHT_SW_FEEDBACK;
	LED0_B5 = KEY_ON && LED_BREAK_SW_FEEDBACK;
	LED0_B4 = KEY_ON && CANJI_TABAN && symbol_hz;//(blink > 4);
	LED0_B3 = KEY_ON && TestBitTrue(CanData[ID(0x1818D0F3)][BYTE7], 5);
	LED0_B2 = KEY_ON && TestBitTrue(CanData[ID(0x181BD0F3)][BYTE2], 0);
	LED0_B1 = KEY_ON && ELEC_BREAK;
	LED0_B0 = KEY_ON && SYSTEM_ERROR;
    
	LED1_B7 = KEY_ON &&CanData[ID(0x1819D0F3)][BYTE5] == 1;	//��ظ�̾��
    LED1_B6 = KEY_ON &&TestBitTrue(CanData[ID(0x0C02A70A)][BYTE2], 7) || TestBitTrue(CanData[ID(0x0C02A70A)][BYTE3], 1) || TestBitTrue(CanData[ID(0x0C03A70A)][BYTE1], 6) || TestBitTrue(CanData[ID(0x0C03A70A)][BYTE2], 0); //������
    LED1_B5 = KEY_ON &&TestBitTrue(CanData[ID(0x1818D0F3)][BYTE8], 5);
    LED1_B4 = KEY_ON &&TestBitTrue(CanData[ID(0x1818D0F3)][BYTE8], 6);
    LED1_B3 = KEY_ON &&TestBitFalse(CanData[ID(0x1818D0F3)][BYTE8], 1);
    LED1_B2 = KEY_ON && SAFE_DOOR_SW;  //�����
    LED1_B1 = KEY_ON &&TestBitTrue(CanData[ID(0x0C04A1A7)][4], 4); //s
    LED1_B0 = KEY_ON &&TestBitFalse(CanData[ID(0x181BD0F3)][1], 3); //msd


	LED2_B7 = KEY_ON && SYSTEM_ERROR_WUGUI;
    LED2_B6 = KEY_ON && ASR_SW;  //��ع���
    LED2_B5 = KEY_ON && delayByCondi(DRIVER_AWAY_SW, 50);
    LED2_B4 = KEY_ON && EMERGENCY_ALL;
    LED2_B3 = KEY_ON && TestBitTrue(CanData[ID(0x1818D0F3)][BYTE7], 2);
    LED2_B2 = KEY_ON && ABS_SW;
    LED2_B1 = KEY_ON && DEFINE_TIP_SPEED;
    LED2_B0 = KEY_ON && UNUSE;

	LED3_B7 = KEY_ON && LED_ENG_DOOR_SW;
    LED3_B6 = KEY_ON && READY;
    LED3_B5 = KEY_ON && WATER_SW;
    LED3_B4 = KEY_ON && UNUSE;
	LED3_B3 = KEY_ON && SEATBELT_NO_SW;
    LED3_B2 = KEY_ON && SYSTEM_ERROR;
    LED3_B1 = KEY_ON && TestBitTrue(CanData[ID(0x1818D0F3)][5], 3);
    LED3_B0 = KEY_ON && UNUSE;


	//LED4_B7 = KEY_ON && UNUSE;
	if(PASSAGE_GET_OUT_SW /*&& (!LED_MIDDLE_DOOR_SW)*/)
		LED4_B7 = KEY_ON;
	else if(LED_MIDDLE_DOOR_SW)
		LED4_B7 = 0;
	LED4_B6 = KEY_ON && LED_DRYER_SW;
    LED4_B5 = KEY_ON && DIAN_JIARE_SW;
    LED4_B4 = KEY_ON && P_SW;
    LED4_B3 = KEY_ON && TestBitTrue(CanData[ID(0x0C04A1A7)][4],3);
    LED4_B2 = KEY_ON && TestBitTrue(CanData[ID(0x0C04A1A7)][4],2);
    LED4_B1 = KEY_ON && TestBitTrue(CanData[ID(0x0C04A1A7)][4],1);
    LED4_B0 = KEY_ON && TestBitTrue(CanData[ID(0x0C04A1A7)][4],0);

    LED5_B0 = SYSTEM_POW && HOU_SHIJING_SW;
	if(KEY_ON && T_SW_P34)
	{
      if(canjiflag)
      {
         canjiflag = 0;
		 canjitime = 100;
	  }
	}
	else
	{
		canjiflag = 1;
	}
	LED5_B1 = KEY_ON && (canjitime > 0);
	if(canjitime > 0)
	   canjitime--;


	
	LED5_B2 = KEY_ON && ((_taiya)/* || (taiya.life >= 205)*/);
	LED5_B3 = KEY_ON && (!R_SW_P32) && symbol_hz;//(blink > 4);
		

	
	blink++;
	if(blink > 9)
		blink = 0;
	
    LEFT_WL       = LED_LEFT_SW_FEEDBACK;      
    LBEAM_WL      = SYSTEM_POW && LED_LBEAM_SW;      
    HBEAM_WL      = SYSTEM_POW && LED_HBEAM_SW;       
    FFOG_WL       = SYSTEM_POW && LED_FFOG_SW;        
    RFOG_WL       = SYSTEM_POW && LED_RFOG_SW;       
    PARK_WL       = SYSTEM_POW && LED_PARK_SW;        
    AIR_LOW_WL    = KEY_ON && LED_AIR_LOW_SW;     
    FDOOR_WL      = (SYSTEM_POW || KEY_POWER)&& LED_FRONT_DOOR_SW;      
    MDOOR_WL      = (SYSTEM_POW || KEY_POWER) && LED_MIDDLE_DOOR_SW;       
    POWER_WL      = SYSTEM_POW;      
    RIGHT_SW      = LED_RIGHT_SW_FEEDBACK;   

    //���ڷ��Ƭ������������û�����ֱ�������
    SYMBOLBUZZ = 0;
}








void LCDLEDControl()
{
    u8 i;
    static uint16_t led_hight_delay = 103;
    static u8 first = 72;
	static u8 first2 = 72;
    static u8 veh_status = 0;
	static u8 timeout = 0;
	static u8 sendscreen = 0;
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
            	#if 1
            	//SetBackGround(backlight_level);
                zzc_start++;
				if(zzc_start >= 60)
				{
                	veh_status = 1;
					zzc_start = 60;
					SetBackGround(backlight_level);
				}
				#else 
				veh_status = 1;
				#endif
            }
			else
			{
				ChangeToSubPage(SET_MODE, MODE_ACC);
                BACKGROUND_OFF();
			}
            break;
		case 1:
			if(sendscreen)
			{
				sendscreen = 0;
				ChangeToSubPage(SET_MODE, MODE_ACC);
                BACKGROUND_OFF();
			}
			if(KEY_ON)
            {
                led_hight_delay = led_hight_delay < 32 ? 32 : led_hight_delay;
                first = first < 2 ? 2 : first;
                veh_status = 2;
            }
            else if(KEY_CHARGE)
            {
                first2 = first2 < 2 ? 2 : first2;
                veh_status = 4;
            }
			else
            {
                ChangeToSubPage(SET_MODE, MODE_ACC);
                veh_status = 0;
            }
			break;

        case 2: //on
            if(first == 1)
            {	
				ChangeToSubPage(SET_MODE, MODE_NORMAL);
				ChangeToSubPage(DIS_MAIN, MAIN);
				SetBackGround(backlight_level);
                ONFlag = 1;
                initflag = 1;
            }

            if(led_hight_delay > 0)
            {
                for(i = 0; i < 8; i++)
                {
                    led[i].byte = 0xff;
                }
				ledlogic.word = 0xffff;
				LED4_B7 = 0;
            }

            if(!KEY_ON)
            {
                //ChangeToSubPage(SET_MODE, MODE_OTHER); //
                ChangeToSubPage(SET_MODE, MODE_ACC);
                //store_miles();
                //SaveVehodo();
				timeout = 52;
                veh_status = 1;
				
				NOON_FALG = 0;
            }
            break;
		case 4: //���
			if(first2 == 1)
            {
				ChangeToSubPageCache(SET_MODE, MODE_OTHER);
				ChangeToSubPage(DIS_MAIN, CHARGE);
				SetBackGround(backlight_level);
            }
		
			if((KEY_ON) || (!(KEY_CHARGE)))
            {
                veh_status = 1;
			}
            break;
    }

    led_out();
}



void Taiya_time()
{
  u8 i;
  taiya.life++;
  if(taiya.life >= 205)
  {
     taiya.life = 205;
	 for(i = 0;i<6;i++)
	 {
       taiya.yali[i] = 0;
	   taiya.wendu[i] = 55;
	   taiya.fault_status[i] = 0;
	   taiya.error[i] = 0;
	 }
  }
}


void SystemLogic(void)
{
   static uint8_t pwmcount = 30;
   BCMConfig();
   Taiya_time();

   LED_Handle();
   led_out();

   LCDLEDControl();
   
   set_output();
   #if((Has_Fmode == ON)||(Has_Tmode == ON)||(Has_Rmode == ON))
#if  SUPPORT_WIPER
	RainConfig();
#endif

	Send_PWM_Bcm();

	Send_Msg_Bcm();			//内CAN发送信息
   #endif

   Rool_Alarm_Handle();

   j1939_tx_100ms();              //��CAN������Ϣ
   send_to_can2();
   SaveODO();
   WriteEE();
   //clear message data
   ClearCanDataManage();
}


//
void BuzzLogic(void)
{
	static u16 buzzdelay = 800;
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




