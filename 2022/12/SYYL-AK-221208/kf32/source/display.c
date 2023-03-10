/*
 * display.c
 *
 *  Created on: 2021-8-10
 *      Author: ART
 */

#include "system_init.h"
#include "displayhelper.h"


//协议使用定义
volatile uint8_t can_water_low,abswarn;
volatile uint8_t Control_information_data7;
volatile uint8_t ID_0CFF0B4A_data2,battery_1_data6,Control_information_data6;
volatile uint8_t ID_18FF2A48_data5,ID_18FF2848_data7,veh_scr,_1CEBFF2F;
volatile uint8_t _18FECA2F,_0CFE5A2F_data4,_0CFE5A2F_data1,ID_18FF2D47_data6,Control_information_data0;
volatile uint8_t batt_time,motor_tem,motor_flag,ID_18FF2D47_data5;
volatile uint8_t _18FF8001[8],_18FF2D47[8],add[10],_18FF0152[8],_18FF3047[8],_18FF3147[8],_18FF3247[8];
volatile uint8_t  elec_time,motor_state;

volatile uint8_t  ID_18FF2848_data5,_18FF2848[8];
volatile uint16_t Battery_System_Volt,Battery_Charge_Curr;
volatile uint8_t  Box_High_Temp,Temp_jicha,ID_18FF2948_data6,Battery_Total_Count,_18FF2948[8];

volatile uint8_t  _18FF2A48[8],Temp_Positive,ID_18FF2A48_data0,ID_18FF2A48_data1,ID_18FF2A48_data2,b_postion;
volatile uint8_t  ID_18FF2E48_data0,ID_18FF2E48_data1,ID_18FF2E48_data2,ID_18FF2E48_data3;

volatile uint8_t  ID_18ff0257_data[8],_0CFFEB4A[8],_10FFC29E[8],_18FF0257[8],_18ff2b48[8];

volatile uint8_t any_Remain_time,electric_shake;
volatile TYPE_BYTE Ankai_Add_190703;
volatile uint8_t  ID_18FF2C48_data5,battery_2_data6,battery_2_soc;
volatile uint16_t battery_2_system_volt,battery_2_system_curr; 

volatile uint16_t Remain_Energy,Battery_2_Remain_enery;
	
volatile uint16_t motor_torque,motor_dc_volt,motor_dc_curr;
volatile uint16_t Battery_chong_Curr_1,Battery_fang_Curr_1;
volatile uint16_t motor_pow[4];

volatile TYPE_BYTE Add_Comm,Low_Buzz;
volatile uint8_t  fog_alarm[4];
volatile uint8_t  ID_18FF2D48_data6,ID_18FF2D48_data5,ID_18FF2D48_data4;
volatile uint16_t Battery_2_single_high_volt,Battery_2_single_low_volt; 
volatile uint16_t insulate_value;
volatile uint8_t  insulate_flag,Life;
volatile uint8_t  Model_Temperure[16];

volatile uint8_t _18FF2B49[8],_0CFF324A[8];
volatile uint8_t Control_information_data7,Control_information_data6,Control_information_data5;
volatile uint8_t Control_information_data0,Control_information_data1;
volatile uint8_t _0CFF0B4A[8],ID_0CFF0B4A_data2,abs_fault,ChargingRelay,FaultAlarmAdd;

volatile uint8_t _18FF5B52[8];
volatile TYPE_BYTE add_fog[8];

volatile uint8_t  _18FFC13A[8],_18FF45F4[8],_10FFC09E[8],_10FFC19E[8],_0CFF114A[8];
volatile uint8_t  errcodemix[6];

volatile uint8_t _18FF064A[8],_18FF2C47[8],_18FF5A52[8],_0CFF0A4A[8],_18FF0258[8];

volatile uint8_t   battery_1_soc,_18FF0498_data7;
volatile uint16_t  Single_mile;

#if GUZHAGN_LOOP
//VCU故障码
volatile uint8_t VCU_MA[MAX_MA];
//VCU故障码
volatile uint8_t BMS_MA[MAX_MA];
//电机故障码
volatile uint8_t MOTOR_MA[MAX_MA];
//打气变频
volatile uint8_t DAQI_MA[MAX_MA];
//转向变频
volatile uint8_t TURN_MA[MAX_MA];
//小充电机
volatile uint8_t XIAOQONG_MA[MAX_MA];
//小充电机
volatile uint8_t DIYA_MA[MAX_MA];

volatile uint8_t VCU_Index,BMS_Index,MOTOR_Index,DAQI_Index,TURN_Index,XIAOQONG_Index,DIYA_Index;
#endif
//----------------------------------------传统车定义
volatile uint16_t WaterTem,engine_oil_press,scr;
volatile uint8_t youjishui,jinqiyure,paiqizhidong,DPF_light,DPF_ban_light,ERR_LIGHT[8],Tot_packets,Const_0X20,temp_1,HybridFault1[40],_18FD0700[8];
volatile uint32_t pgn;
volatile TYPE_BYTE  add1[8],add2[8],add3[8],add4[8],add5[8];
volatile uint8_t NCD,MIL_light;
volatile u8 zongyouhao[4];
volatile u16 shunshiyouhao;

//故障参数初始化
void guzhangma_init(void)
{
  u16 i;
  #if GUZHAGN_LOOP
  for(i = 0;i < MAX_MA;i++)
  {
	  VCU_MA[i] = 0;
	  BMS_MA[i] = 0;
	  MOTOR_MA[i] = 0;
	  DAQI_MA[i] = 0;
	  TURN_MA[i] = 0;
	  XIAOQONG_MA[0] = 0;
	  DIYA_MA[0] = 0;
  }
  VCU_Index = 0;
  BMS_Index = 0;
  MOTOR_Index = 0;
  DAQI_Index = 0;
  TURN_Index = 0;
  XIAOQONG_Index = 0;
  DIYA_Index = 0;
  #endif
}


//判断故障码是否在故障码数组中，不在加入，p:对应故障码数组  data:故障码 1:不在数组，需要加入 0:在数组
u8 JudgeMAInBuff(volatile u8 *p,volatile u8 data)
{
   u16 i,j = 0;
   if(data == 0)
   	return j;
   for(i = 0;i < MAX_MA;i++)
   {
      if((p[i] != 0))
      {
         if((p[i] == data)) 
         {
             j = 0;
			 break;
		 }
	  }
	  else 
	  {
         j = 1;
		 break;
	  }  	
   }
   return j;
}




void CAN_T123(void)
{
    uint8_t data[8];
	uint32_t id = 0x0c000000,id1;
	id1 = ((uint32_t)communicate_T123_data[0]<<16)+((uint32_t)communicate_T123_data[1]<<8)+communicate_T123_data[2];
	id = id|id1;

	data[0] = communicate_T123_data[3];
	data[1] = communicate_T123_data[4];
	data[2] = communicate_T123_data[5];
	data[3] = communicate_T123_data[6];
	data[4] = communicate_T123_data[7];
	data[5] = communicate_T123_data[8];
	data[6] = communicate_T123_data[9];
	data[7] = communicate_T123_data[10];
	
	if(T123_USED_BCAN)
       Can0_Tx_Bytes(id,data,8);
	
	if(T123_USED_TCAN)
       Can1_Tx_Bytes(id,data,8);	
	
	if(T123_USED_PCAN)
       Can2_Tx_Bytes(id,data,8);	
	
	if(T123_USED_DCAN)
       Can3_Tx_Bytes(id,data,8);
}


void SendPAGE_BAT01(u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x22;
    communicate_T123_data[2] = 0x01;


    communicate_T123_data[3]   = Battery_Total_Count;//电池总箱数
    communicate_T123_data[3] = communicate_T123_data[3]&0x3f;
	//是否禁止充电标志位
	if(((battery_1_data6&0x10)==0x10))
	  communicate_T123_data[3] = communicate_T123_data[3]|0x80;
	else
		communicate_T123_data[3] = communicate_T123_data[3]&0x7f;
	//充电座温度
    communicate_T123_data[4]   = _18FF2A48[4];

    communicate_T123_data[5]   = Box_High_Temp - Temp_jicha;//电池模块最低温度
    communicate_T123_data[6]   = Box_High_Temp;              //电池模块的最高温度

    communicate_T123_data[7]   = GetU16Low(Battery_fang_Curr/10);
    communicate_T123_data[8]   = GetU16High(Battery_fang_Curr/10);
    communicate_T123_data[9]   = GetU16Low(Battery_chong_Curr/10);
    communicate_T123_data[10]  = GetU16High(Battery_chong_Curr/10);

    SendEndPlus(10);
}

void SendPAGE_BAT02(u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x22;
    communicate_T123_data[2] = 0x02;


    communicate_T123_data[3]   = (b_postion >> 4)&0x0f;//最高温度箱号
    communicate_T123_data[4]   = b_postion&0x0F;//最低温度箱号
    communicate_T123_data[5]   = (ID_18FF2A48_data2 >> 4)&0x0f;//电池最高电压箱
    communicate_T123_data[6]   = ID_18FF2A48_data1;              //电池最高电压节

    communicate_T123_data[7]   = ID_18FF2A48_data2&0x0f;//电池最低电压箱
    communicate_T123_data[8]  = ID_18FF2A48_data0;      //电池最低电压节
	communicate_T123_data[9]  = _18ff2b48[1];
	communicate_T123_data[10] = _18ff2b48[2];
    SendEndPlus(10);
}

#if(DISPLAYTASKNUM > 2)

//电池组信息
u32 display_surface3(u8 key,u8 initpw)
{
    static u32 subinitflag = 1;
    static u32 batnum = 0;
    if(initpw)
    {
        ChangeToPage(PAGE_0x21);
    }


    SendPAGE_BAT01(initpw);
    SendPAGE_BAT02(initpw);

    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }
    return DIS_PAGE3_MENU;
}

#endif


void SendPAGE_ECU01(u8 initpw)
{
  /*  TYPE_BYTE temp;
    SendStart();
    temp.byte = 0;
    communicate_T123_data[1] = PAGE_0x20;
    communicate_T123_data[2] = 1;

    temp.bit.b7 = ((Control_information_data6&0x08)==0x08);
    temp.bit.b6 = ((Control_information_data6&0x04)==0x04);
    temp.bit.b5 = DEFINE_TIP_AIR_LOW;
    temp.bit.b4 = ((Control_information_data7&0x01)==0x01);
    temp.bit.b3 = ((Control_information_data7&0x02)==0x02);
    temp.bit.b2 = clear_mile;
    temp.bit.b1 = ((Control_information_data6&0x01)==0x01);
    temp.bit.b0 = TestBitTrue(Control_information_data7,3);

    communicate_T123_data[3]   = temp.byte;
    communicate_T123_data[4]   = Break_Pent;


    SendEndPlus(10);*/
}

#if(DISPLAYTASKNUM > 4)

//整车控制器信息
u32 display_surface5(u8 key,u8 initpw)
{
    if(initpw)
    {
        ChangeToPage(PAGE_0x20);
    }

    SendPAGE_ECU01(initpw);

    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }

    return DIS_PAGE5_MENU;
}

#endif

void SendFOG01(u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x23;
    communicate_T123_data[2] = 0x01;

    communicate_T123_data[3]   = fog_alarm[3];
    communicate_T123_data[4]   = fog_alarm[2];
    communicate_T123_data[5]   = fog_alarm[1];
    communicate_T123_data[6]   = (timeout[GetIndexFromID(0x18FF5A52)]<100);

    SendEndPlus(10);
}

void SendFOG02(u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x24;
    communicate_T123_data[2] = 0x01;

    communicate_T123_data[3]   = add_fog[0].byte;
    communicate_T123_data[4]   = add_fog[1].byte;
    communicate_T123_data[5]   = add_fog[2].byte;
    communicate_T123_data[6]   = add_fog[3].byte;
    communicate_T123_data[7]   = add_fog[4].byte;
    communicate_T123_data[8]   = add_fog[5].byte;
    communicate_T123_data[9]   = add_fog[6].byte;
    communicate_T123_data[10]  = (timeout[GetIndexFromID(0x18ff5b52)]<100);

    SendEndPlus(10);
}


#if(DISPLAYTASKNUM > 1)
void SendERR01(u8 initpw)
{

	SendStart();

	communicate_T123_data[1] = PAGE_0x21;
	communicate_T123_data[2] = 0x01;

    communicate_T123_data[3]   = HybridFault1[0];
	communicate_T123_data[4]   = HybridFault1[1];
	communicate_T123_data[5]   = HybridFault1[2];
	communicate_T123_data[6]   = HybridFault1[3];
	communicate_T123_data[7]   = HybridFault1[4];
	communicate_T123_data[8]   = HybridFault1[5];
	communicate_T123_data[9]   = HybridFault1[6];
	communicate_T123_data[10]  = HybridFault1[7];
	
	SendEndPlus(10);
}


void SendERR02(u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x21;
    communicate_T123_data[2] = 0x02;

    communicate_T123_data[3]   = HybridFault1[8];
	communicate_T123_data[4]   = HybridFault1[9];
	communicate_T123_data[5]   = HybridFault1[10];
	communicate_T123_data[6]   = HybridFault1[11];
	communicate_T123_data[7]   = HybridFault1[12];
	communicate_T123_data[8]   = HybridFault1[13];
	communicate_T123_data[9]   = HybridFault1[14];
	communicate_T123_data[10]  = HybridFault1[15];
    SendEndPlus(10);
}

void SendERR03(u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x21;
    communicate_T123_data[2] = 0x03;

    communicate_T123_data[3]   = HybridFault1[16];
	communicate_T123_data[4]   = HybridFault1[17];
	communicate_T123_data[5]   = HybridFault1[18];
	communicate_T123_data[6]   = HybridFault1[19];
	communicate_T123_data[7]   = HybridFault1[20];
	communicate_T123_data[8]   = HybridFault1[21];
	communicate_T123_data[9]   = HybridFault1[22];
	communicate_T123_data[10]  = HybridFault1[23];
    SendEndPlus(10);
}

//烟雾报警信息界面
static u32 display_surface2(u8 key,u8 initpw)  //烟雾报警信息
{

    u8 i;
    if(initpw)
    {
        ChangeToPage(PAGE_0x21);
		//guzhangma_init();
    }

    SendERR01(initpw);

    SendERR02(initpw);

	SendERR03(initpw);

    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }
    return DIS_PAGE2_MENU;
}
#endif


void SendPAGE_MOTOR01(u8 initpw)
{

    SendStart();

    communicate_T123_data[1] = PAGE_0x21;
    communicate_T123_data[2] = 1;

    communicate_T123_data[3]   = GetU16Low(insulate_value);//绝缘电阻低
    communicate_T123_data[4]   = GetU16High(insulate_value);//绝缘电阻高

    communicate_T123_data[5]   = insulate_flag;//绝缘电阻报警

    //communicate_T123_data[6]   = GetU16Low(motor_torque/10);//当前扭矩低
    //communicate_T123_data[7]   =  GetU16High(motor_torque/10);
    communicate_T123_data[8]   = GetU16Low(motor_dc_volt);
    communicate_T123_data[9]   = GetU16High(motor_dc_volt);

    SendEndPlus(15);
}


void SendPAGE_MOTOR02(u8 initpw)
{

    SendStart();

    communicate_T123_data[1] = PAGE_0x21;
    communicate_T123_data[2] = 2;

    communicate_T123_data[3]   = GetU16Low(motor_dc_curr/10);//电机相电流低
    communicate_T123_data[4]  = GetU16High(motor_dc_curr/10);//电机相电流高

    communicate_T123_data[5]   = motor_tem;        //电机温度
    communicate_T123_data[6]   = WaterTem;         //电机控制器温度

    communicate_T123_data[7]   = GetU16Low(eng_speed);
    communicate_T123_data[8]   = GetU16High(eng_speed);

    SendEndPlus(15);
}

void SendPAGE_MOTOR03(u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x21;
    communicate_T123_data[2] = 3;

    communicate_T123_data[3]   = GetU16Low(motor_pow[0]/10);
    communicate_T123_data[4]   = GetU16High(motor_pow[0]/10);
    communicate_T123_data[5]   = GetU16Low(motor_pow[1]/10);
    communicate_T123_data[6]   = GetU16High(motor_pow[1]/10);
    communicate_T123_data[7]   = GetU16Low(motor_pow[2]/10);
    communicate_T123_data[8]   = GetU16High(motor_pow[2]/10);
    communicate_T123_data[9]   = GetU16Low(motor_pow[3]/10);
    communicate_T123_data[10]  = GetU16High(motor_pow[3]/10);


    SendEndPlus(15);
}


#if(DISPLAYTASKNUM > 3)

u32 display_surface4(u8 key,u8 initpw)
{
    static u8 fan = 0;

    if(initpw)
    {
        ChangeToPage(PAGE_0x21);
    }

    if((fan&0x03) == 0)
        SendPAGE_MOTOR01(initpw);
    else if((fan&0x03) == 1)
        SendPAGE_MOTOR02(initpw);
    else if((fan&0x03) == 2)
        SendPAGE_MOTOR03(initpw);
    fan ++;


    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }

    return DIS_PAGE4_MENU;
}
#endif





#if(DISPLAYTASKNUM > 0)

void Page0x22_01(u8 initpw)
{
	SendStart();
	communicate_T123_data[1] = PAGE_0x22;
	communicate_T123_data[2] = 1;
	
	communicate_T123_data[3]   = shunshiyouhao;
	communicate_T123_data[4]   = shunshiyouhao>>8;
	communicate_T123_data[5]   = zongyouhao[0];
	communicate_T123_data[6]   = zongyouhao[1];
	communicate_T123_data[7]   = zongyouhao[2];
	communicate_T123_data[8]   = zongyouhao[3];

	SendEnd();
}

static u32 display_surface1(u8 key,u8 initpw)  //松正
{
    u8 i;
    if(initpw)
    {
        ChangeToPage(PAGE_0x22);
    }

    Page0x22_01(initpw);

    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }

    return DIS_PAGE1_MENU;
}

#endif

//新增页面5
#if(DISPLAYTASKNUM > 5)

static u32 display_surface6(u8 key,u8 initpw)  //松正
{
    u8 i;
    if(initpw)
    {
        ChangeToPage(PAGE_0x26);
    }

    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }

    return DIS_PAGE6_MENU;
}

#endif




void AddAnkaiMenu(void)
{

#if(DISPLAYTASKNUM > 0)
    //故障信息  num5
	AddMenu(display_surface1,			   DIS_PAGE1_MENU);
#endif

#if(DISPLAYTASKNUM > 1)
    //烟雾报警信息 num4
	AddMenu(display_surface2,			   DIS_PAGE2_MENU);
#endif

#if(DISPLAYTASKNUM > 2)  
    //电池组信息 num3
    AddMenu(display_surface3,			   DIS_PAGE3_MENU);
#endif

#if(DISPLAYTASKNUM > 3)
    //电机控制器信息 num4
	AddMenu(display_surface4,			   DIS_PAGE4_MENU);
#endif

#if(DISPLAYTASKNUM > 4)
    //整车控制器  num1
	AddMenu(display_surface5,			   DIS_PAGE5_MENU);
#endif



#if(DISPLAYTASKNUM > 5)
    //备用
	AddMenu(display_surface6,			   DIS_PAGE6_MENU);
#endif 

}


