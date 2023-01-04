/*
 * display.c
 *
 *  Created on: 2021-11-30
 *      Author: ART
 */

#include "system_init.h"
#include "keyfifo.h"

volatile u8 avtest = 0;
volatile u8 DCanSendDisablel = 1;


uint8_t dis_mod = DIS_MAIN_MENU;
u8 Send_To_DP_Data[12];
u8 errcodemix[7];
u8 p_status[56];
u8 p_cur[96];
u8 p_temp[16];


/*---------------------------------金旅协议变量---------------------------------*/

volatile MIEHUO Meihuo[MAX_MIEHUO];
volatile uint8_t meihuo_life;
volatile uint16_t Get_ID_Off;

/*-------------------------------------------------------------------------------*/




void SendPAGE_MAIN04(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = PAGE_MAIN;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 1;
	
	

    SendEnd();
}


void SendPAGE_MAIN05(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = PAGE_MAIN;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 2;
	
	
    SendEnd();
}

void SendPAGE_MAIN06(u8 initpw)
{

	SendStart();

	Send_To_DP_Data[0] = PAGE_MAIN;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 3;

	
   	SendEnd();
}


SendGroup_Init(Main_Data)
{
	SendPAGE_MAIN04,
	SendPAGE_MAIN05,
	SendPAGE_MAIN06
};





//---------------------------ECU----------------
u32 Menu_ECU(u8 key,u8 initpw)
{
	static u8 flag = 0, changescreenflag = 0, lop;
    u8 i;
    if(initpw)
    {  
		SendKeyToGPU(CMD_DIS_PAGE);
        changescreenflag = 1;
    }
	
    
    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }
    return DIS_VCU_MENU;
}

//----------------------BAT--------------
u32 Menu_BAT(u8 key, u8 initpw) //调用
{
    if(initpw)
    {
        SendKeyToGPU(CMD_DIS_PAGE);
    }

    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }
    return DIS_BAT_MENU;
}
//-----------------------BMS------------------------
u32 Menu_BMS(u8 key, u8 initpw)
{

    if(initpw)
    {
        SendKeyToGPU(CMD_DIS_PAGE);
    }


    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }

    return DIS_BMS_MENU;
}
//------------------TMS-----------
typedef struct
{
  u8 second;
  u8 mins;
  u8 hour;
}catime;

void SendPAGE_TMS01(u8 initpw)
{
    TYPE_BYTE temp;
	static catime time;
	SendStart();
	Send_To_DP_Data[0] = 0X02;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 1;

	if(TMSFLAG20S)
	{
      TMSFLAG20S = 0;
	  time.second = 0;
	  time.mins = 0;
	  time.hour = 0;
	}
	time.second = TMS_Code_Time;//单位秒
	if(time.second >= 60)
	{
       time.mins++;
	   time.second = 0;
	   TMS_Code_Time = 0;
	   if(time.mins >= 60)
	   {
          time.mins = 0;
		  time.hour++;
	   }
	}
	DP_DATA1   = time.hour;
	DP_DATA2   = time.mins;
	DP_DATA3   = time.second;
	//if(timeout[ID(0x18FFC13A)] > 100)
	//	DP_DATA4 = CanData[][];
	//else
		
				
    SendEnd();
}
/*SendGroup_Init(0x02)
{
	SendPAGE_TMS01,
};
SendGroup_CodeGen(0X02);*/

u32 Menu_TMS(u8 key, u8 initpw) //调用
{
    static u8 flag = 0, changescreenflag = 0;
    if(initpw)
    {
        changescreenflag = 1;
        SendKeyToGPU(CMD_DIS_PAGE);
    }
	SendPAGE_TMS01(1);
    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }
    return DIS_TMS_MENU;
}

//------------------AIR-----------
u32 Menu_AIR(u8 key, u8 initpw) //调用
{
    static u8 flag = 0, changescreenflag = 0;
    if(initpw)
    {
        changescreenflag = 1;
        SendKeyToGPU(CMD_DIS_PAGE);
    }

    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }
    return DIS_AIR_MENU;
}

//------------------FAULT--------------
void SendPAGE_ABS01(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x30;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 1;
	
	DP_DATA1   = ABS_DTC[0];
	DP_DATA2   = (ABS_DTC[0] >> 8);
	DP_DATA3   = ((ABS_DTC[0] >> 21) & 0x07);
	DP_DATA4   = 0;
	DP_DATA5   = ((ABS_DTC[0] >> 16) & 0x1F);


    SendEnd();
}

void SendPAGE_ABS02(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x30;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 2;
	
	DP_DATA1   = ABS_DTC[1];
	DP_DATA2   = (ABS_DTC[1] >> 8);
	DP_DATA3   = ((ABS_DTC[1] >> 21) & 0x07);
	DP_DATA4   = 0;
	DP_DATA5   = ((ABS_DTC[1] >> 16) & 0x1F);
    SendEnd();
}
void SendPAGE_ABS03(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x30;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 3;
	

	DP_DATA1   = ABS_DTC[2];
	DP_DATA2   = (ABS_DTC[2] >> 8);
	DP_DATA3   = ((ABS_DTC[2] >> 21) & 0x07);
	DP_DATA4   = 0;
	DP_DATA5   = ((ABS_DTC[2] >> 16) & 0x1F);

    SendEnd();
}
void SendPAGE_ABS04(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x30;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 4;
	

	DP_DATA1   = ABS_DTC[3];
	DP_DATA2   = (ABS_DTC[3] >> 8);
	DP_DATA3   = ((ABS_DTC[3] >> 21) & 0x07);
	DP_DATA4   = 0;
	DP_DATA5   = ((ABS_DTC[3] >> 16) & 0x1F);

    SendEnd();
}

/*
SendGroup_Init(PAGE_0X30)
{
	SendPAGE_ABS01,
	SendPAGE_ABS02,
	SendPAGE_ABS03,
	SendPAGE_ABS04
};
SendGroup_CodeGen(PAGE_0X30);
*/
u32 Menu_FAULT(u8 key, u8 initpw)
{
    if(initpw)
    {
        SendKeyToGPU(CMD_DIS_PAGE);
    }
	//SendGroup(PAGE_0X30,1);
	SendPAGE_ABS01(1);
	SendPAGE_ABS02(1);
	SendPAGE_ABS03(1);
	SendPAGE_ABS04(1);
    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }

    return DIS_FAULT_MENU;
}
//------------------EPB--------------

u32 Menu_EPB(u8 key, u8 initpw)
{

    if(initpw)
    {
        SendKeyToGPU(CMD_DIS_PAGE);
    }

    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }

    return DIS_EPB_MENU;
}


void SendPAGE_0x29(u8 initpw)
{
	u8 temp;
	SendStart();
    Send_To_DP_Data[0] = 0x29;
	Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 4;

	if((CanData[ID(0x18FFA898)][BYTE1] & 0xC0) == 0)
	{
		Send_To_DP_Data[3] = 0;
		temp = BCD_TO_BIN(CanData[ID(0x18FFA898)][BYTE3]);
		Send_To_DP_Data[4] = temp;
		temp = BCD_TO_BIN(CanData[ID(0x18FFA898)][BYTE4]);
		Send_To_DP_Data[5] = temp;
	}
	else if((CanData[ID(0x18FFA898)][BYTE1] & 0xC0) == 0x40)
	{
		temp = BCD_TO_BIN(CanData[ID(0x18FFA898)][BYTE3]);
		Send_To_DP_Data[3] = temp;
		temp = BCD_TO_BIN(CanData[ID(0x18FFA898)][BYTE4]);
		Send_To_DP_Data[4] = temp;
		Send_To_DP_Data[5] = 0;
	}
	else
	{
		Send_To_DP_Data[3] = 0;
		Send_To_DP_Data[4] = 0;
		Send_To_DP_Data[5] = 0;
	}
    SendEnd();
}


//------------------RUNHUA--------------
u32 Menu_RUNHUA(u8 key, u8 initpw)
{

    if(initpw)
    {
        SendKeyToGPU(CMD_DIS_PAGE);
    }
	SendPAGE_0x29(initpw);

    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }
    #if RUNHUA
    return DIS_RUNHUA_MENU;
	#endif
}

#if 0
//------------------PEIDIANHE--------------
void SendPAGE_PEIDIAN01(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 1;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i]);
    SendEnd();
}
void SendPAGE_PEIDIAN02(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 2;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 4]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 4]);
    SendEnd();
}
void SendPAGE_PEIDIAN03(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 3;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 8]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 8]);
    SendEnd();
}
void SendPAGE_PEIDIAN04(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 4;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 12]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 12]);
    SendEnd();
}
void SendPAGE_PEIDIAN05(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 5;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 16]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 16]);
    SendEnd();
}
void SendPAGE_PEIDIAN06(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 6;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 20]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 20]);
    SendEnd();
}
void SendPAGE_PEIDIAN07(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 7;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 24]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 24]);
    SendEnd();
}
void SendPAGE_PEIDIAN08(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 8;
	
	for(i=0;i<3;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 28]);
	for(i=0;i<3;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 28]);
    SendEnd();
}
void SendPAGE_PEIDIAN09(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 9;
	
	for(i=0;i<8;i++)
		Send_To_DP_Data[3 + i] = PeiDianTemp[i];
    SendEnd();
}
void SendPAGE_PEIDIAN10(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 10;
	
	for(i=0;i<6;i++)
		Send_To_DP_Data[3 + i] = PeiDianTemp[i + 8];
    SendEnd();
}

#endif


//------------------PEIDIANHE--------------
void SendPAGE_PEIDIAN01(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 1;
	
	for(i=0;i<8;i++)
		Send_To_DP_Data[3 + i] = PeiDianOutSta[i];
    SendEnd();
}
void SendPAGE_PEIDIAN02(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 2;
	
	for(i=0;i<8;i++)
		Send_To_DP_Data[3 + i] = PeiDianOutSta[i + 8];
    SendEnd();
}
void SendPAGE_PEIDIAN03(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 3;
	
	for(i=0;i<8;i++)
		Send_To_DP_Data[3 + i] = PeiDianOutSta[i + 16];
    SendEnd();
}
void SendPAGE_PEIDIAN04(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 4;
	
	for(i=0;i<8;i++)
		Send_To_DP_Data[3 + i] = PeiDianOutSta[i + 24];
    SendEnd();
}
void SendPAGE_PEIDIAN05(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 5;
	
	for(i=0;i<8;i++)
		Send_To_DP_Data[3 + i] = PeiDianOutSta[i + 32];
    SendEnd();
}
void SendPAGE_PEIDIAN06(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 6;
	
	for(i=0;i<8;i++)
		Send_To_DP_Data[3 + i] = PeiDianOutSta[i + 40];
    SendEnd();
}
void SendPAGE_PEIDIAN07(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 7;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i]);
    SendEnd();
}
void SendPAGE_PEIDIAN08(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 8;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 4]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 4]);
    SendEnd();
}
void SendPAGE_PEIDIAN09(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 9;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 8]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 8]);
    SendEnd();
}
void SendPAGE_PEIDIAN0A(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 10;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 12]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 12]);
    SendEnd();
}
void SendPAGE_PEIDIAN0B(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 11;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 16]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 16]);
    SendEnd();
}
void SendPAGE_PEIDIAN0C(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 12;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 20]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 20]);
    SendEnd();
}
void SendPAGE_PEIDIAN0D(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 13;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 24]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 24]);
    SendEnd();
}
void SendPAGE_PEIDIAN0E(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 14;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 28]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 28]);
    SendEnd();
}
void SendPAGE_PEIDIAN0F(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 15;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 32]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 32]);
    SendEnd();
}
void SendPAGE_PEIDIAN10(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 16;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 36]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 36]);
    SendEnd();
}
void SendPAGE_PEIDIAN11(u8 initpw)
{
		
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 17;
	
	for(i=0;i<4;i++)
		Send_To_DP_Data[3 + i*2] = GetU16Low(PeiDianOutCur[i + 40]);
	for(i=0;i<4;i++)
		Send_To_DP_Data[4 + i*2] = GetU16High(PeiDianOutCur[i + 40]);
	SendEnd();
}
void SendPAGE_PEIDIAN12(u8 initpw)
{
		
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 18;
	
	for(i=0;i<8;i++)
		Send_To_DP_Data[3 + i] = PeiDianTemp[i];
	SendEnd();
}
void SendPAGE_PEIDIAN13(u8 initpw)
{
		
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 19;
	
	for(i=0;i<2;i++)
		Send_To_DP_Data[3 + i] = PeiDianTemp[i + 8];
	SendEnd();
}
void SendPAGE_PEIDIAN14(u8 initpw)
{
		
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 20;
	
	for(i=0;i<6;i++)
		Send_To_DP_Data[3 + i] = CanData[ID(0x181F081F)][i];
	SendEnd();
}

void SendPAGE_PEIDIAN21(u8 initpw)
{
	SendStart();
	Send_To_DP_Data[0] = 0x26;
	Send_To_DP_Data[1] = 0x01;
	Send_To_DP_Data[2] = 21;
	
	for(i=0;i<8;i++)
		Send_To_DP_Data[3 + i] = CanData[ID(0x181F061F)][i];
	SendEnd();
}



u32 Menu_PEIDIANHE(u8 key, u8 initpw) //调用
{
    static u8 flag = 0, changescreenflag = 0, fan = 2;
    u8 i;
    static u8 timecount;

    if(initpw)
    {
    	changescreenflag = 1;
        SendKeyToGPU(CMD_DIS_PAGE);
    }

	
    switch (key)
    {
        case IN_KEY2_SP:
            flag++;
            flag = flag >= 5 ? 0 : flag;
            changescreenflag = 1;
            break;
        case IN_KEY3_SP:
            flag = flag == 0 ? 5 : flag;
            flag--;
            changescreenflag = 1;
            break;
    }
    if (changescreenflag)
    {
        changescreenflag = 0;
        ChangeToSubPage (DIS_PEIDIANHE_MENU, flag);
    }
    if(fan ==  0)
		{
		   SendPAGE_PEIDIAN01(1);
		   SendPAGE_PEIDIAN02(1);
		   SendPAGE_PEIDIAN03(1);
	   }
	   else if(fan ==  2)
	   {
		   SendPAGE_PEIDIAN04(1);
		   SendPAGE_PEIDIAN05(1);
		   SendPAGE_PEIDIAN06(1);
	   }
	   else if(fan ==  4)
	   {
		   SendPAGE_PEIDIAN07(1);
		   SendPAGE_PEIDIAN08(1);
		   SendPAGE_PEIDIAN09(1);
	   }
	   else if(fan ==  6)
	   {
		   SendPAGE_PEIDIAN0A(1);
		   SendPAGE_PEIDIAN0B(1);
		   SendPAGE_PEIDIAN0C(1);
	   }
	   else if(fan ==  8)
	   {
		   SendPAGE_PEIDIAN0D(1);
		   SendPAGE_PEIDIAN0E(1);
		   SendPAGE_PEIDIAN0F(1);
	   }
	   else if(fan ==  10)
	   {
		   SendPAGE_PEIDIAN10(1);
		   SendPAGE_PEIDIAN11(1);
		   SendPAGE_PEIDIAN12(1);
	   }
	   else if(fan ==  12)
	   {
		   SendPAGE_PEIDIAN13(1);
		   SendPAGE_PEIDIAN14(1);
		   SendPAGE_PEIDIAN21(1);
	   }
	   
		   if(fan++ >= 14)
			   fan = 0;

    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }
    return DIS_PEIDIANHE_MENU;
}
//------------------RANLIAODIANCHI--------------
/*u32 Menu_RANLIAODIANCHI(u8 key, u8 initpw)
{

    if(initpw)
    {
        SendKeyToGPU(CMD_DIS_PAGE);
    }

    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }

    return DIS_RANLIAODIANCHI_MENU;
}*/

//-------------------MIEHUO-----------------------

u8 Max_MeiHuo_Box(void)
{
    u8 i;
    for(i = 0; i < MAX_MIEHUO; i++)
    {
        if(Meihuo[i].box == 0)
        {
            break;
        }
    }

    return i ;
}
void PageMIEHUOMsg(u8 initpw, u8 max_box, u8 box) //max_box实际是life,box实际是箱数
{
    SendStart();
	Send_To_DP_Data[0] = 0x22;
    Send_To_DP_Data[1] = 1;
    Send_To_DP_Data[2] = 1;

    Send_To_DP_Data[3] = meihuo_life;
	Send_To_DP_Data[4] = Meihuo[0].box;
	Send_To_DP_Data[5] = Meihuo[0].type;
    Send_To_DP_Data[6] = Meihuo[0].alarm_level;
    Send_To_DP_Data[7] = Meihuo[0].fault_status;
    Send_To_DP_Data[8] = Meihuo[0].zifa;
    Send_To_DP_Data[9] = Meihuo[0].faultcode;
	if(timeout[ID(0x18FF56F6)] > 100)
		Send_To_DP_Data[10] = 0x20;
	else
    	Send_To_DP_Data[10] = Meihuo[0].changjia;
    SendEnd();
}


void PageMIEHUOMsg01(u8 initpw, u8 index)
{
    SendStart();
	Send_To_DP_Data[0] = 0x22;
    Send_To_DP_Data[1] = 1;
    Send_To_DP_Data[2] = index;

    Send_To_DP_Data[4] = Meihuo[(index - 1)].box;
	Send_To_DP_Data[5] = Meihuo[(index - 1)].type;
    Send_To_DP_Data[6] = Meihuo[(index - 1)].alarm_level;
    Send_To_DP_Data[7] = Meihuo[(index - 1)].fault_status;
    Send_To_DP_Data[8] = Meihuo[(index - 1)].zifa;
    Send_To_DP_Data[9] = Meihuo[(index - 1)].faultcode;
    Send_To_DP_Data[10] = Meihuo[(index - 1)].changjia;
 
    SendEnd();
}


u32 Menu_MEIHUO(u8 key, u8 initpw) //调用
{
    static u8 flag = 0, changescreenflag = 0, fan = 2;
    u8 i;
    static u8 timecount;
    u8 max_box = Max_MeiHuo_Box();

    if(initpw)
    {
        SendKeyToGPU(CMD_DIS_PAGE);
    }

    switch (key)
    {
        case IN_KEY2_SP:
        case IN_KEY3_SP:
            flag = !flag;
            changescreenflag = 1;
            break;
    }
    if (changescreenflag)
    {
        changescreenflag = 0;
        ChangeToSubPage (DIS_MIEHUO_MENU, flag);
    }


    PageMIEHUOMsg(1, meihuo_life, max_box);
    PageMIEHUOMsg01(1, fan);
    fan++;
    if(fan > (max_box))
    {
        fan = 2;
    }
	
    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }
    return DIS_MIEHUO_MENU;
}




//胎压处理
void Send0x2301(u8 initpw)
{

	SendStart();

	Send_To_DP_Data[0] = 0x23;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x01;

    Send_To_DP_Data[3]   = taiya.yali[0];//绝缘电阻低
    Send_To_DP_Data[4]   = GetU16Low(taiya.wendu[0]);//绝缘电阻高

    Send_To_DP_Data[5]   = GetU16High(taiya.wendu[0]);//绝缘电阻报警
	Send_To_DP_Data[6]	 = taiya.yali[1];//绝缘电阻报警

    Send_To_DP_Data[7]   = GetU16Low(taiya.wendu[1]);//绝缘电阻低
    Send_To_DP_Data[8]   = GetU16High(taiya.wendu[1]);//绝缘电阻高
    
    Send_To_DP_Data[9]   = taiya.yali[2];//绝缘电阻低


	
	SendEnd();
}


void Send0x2302(u8 initpw)
{

	SendStart();

	Send_To_DP_Data[0] = 0x23;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x02;

    Send_To_DP_Data[3]   = GetU16Low(taiya.wendu[2]);//绝缘电阻低
    Send_To_DP_Data[4]   = GetU16High(taiya.wendu[2]);//绝缘电阻高

    Send_To_DP_Data[5]   = taiya.yali[3];//绝缘电阻报警
	Send_To_DP_Data[6]	 = GetU16Low(taiya.wendu[3]);//绝缘电阻报警

    Send_To_DP_Data[7]   = GetU16High(taiya.wendu[3]);//绝缘电阻低

	
    Send_To_DP_Data[8]   = taiya.yali[4];//绝缘电阻高
    
	Send_To_DP_Data[9]	 = GetU16Low(taiya.wendu[4]);//绝缘电阻报警

    Send_To_DP_Data[10]   = GetU16High(taiya.wendu[4]);//绝缘电阻低

	
	SendEnd();
}

void Send0x2303(u8 initpw)
{

	SendStart();

	Send_To_DP_Data[0] = 0x23;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x03;

    Send_To_DP_Data[3]   = taiya.yali[5];//绝缘电阻高
    
	Send_To_DP_Data[4]	 = GetU16Low(taiya.wendu[5]);//绝缘电阻报警

    Send_To_DP_Data[5]   = GetU16High(taiya.wendu[5]);//绝缘电阻低


	
	SendEnd();
}


SendGroup_Init(PAGE_TAIYA)
{
	Send0x2301,
	Send0x2302,
	Send0x2303,
};
SendGroup_CodeGen(PAGE_TAIYA);


u32 MenuDIS_TAIYA_MENU(u8 key,u8 initpw)
{
    static u8 flag = 0, changescreenflag = 0, loop = 0, add = 1, NND = 0;
    u8 i;
    static u8 timecount, xxx;
    if (initpw)
    {
    //    changescreenflag = 1;
        SendKeyToGPU (CMD_DIS_PAGE);
    }

    //SendGroup(PAGE_TAIYA,initpw); 

    Send0x2301(1);
	Send0x2302(1);
	Send0x2303(1);

   if (key == IN_KEY1_SP)
   {
	   return DIS_CHOOSE_MENU;
   }
	 return DIS_TAIYA_MENU;
}












void InitDisplay()
{

	memset((void*)Meihuo,0xFF, sizeof(Meihuo));

    InitDisplayHelper();
    
    
	AddMenu(Menu_ECU, DIS_VCU_MENU);
    AddMenu(Menu_BAT, DIS_BAT_MENU);
	AddMenu(Menu_ECU, DIS_BMS_MENU);
	AddMenu(Menu_TMS, DIS_TMS_MENU);
    AddMenu(Menu_AIR, DIS_AIR_MENU);
    AddMenu(Menu_FAULT, DIS_FAULT_MENU);
    AddMenu(MenuDIS_TAIYA_MENU, DIS_TAIYA_MENU);//3 电空调
    AddMenu(Menu_EPB, DIS_EPB_MENU);//3 电空调
    #if RUNHUA
    AddMenu(Menu_RUNHUA, DIS_RUNHUA_MENU);//3 可行驶里程和功率
    #endif
    AddMenu(Menu_PEIDIANHE, DIS_PEIDIANHE_MENU);//3 可行驶里程和功率
    AddMenu(Menu_MEIHUO, DIS_MIEHUO_MENU);//3 可行驶里程和功率
	//AddMenu(Menu_RANLIAODIANCHI, DIS_RANLIAODIANCHI_MENU);//3 可行驶里程和功率
}



u16 GetWenziWarnCode(u16 alarm_count)
{

	if((alarm_count >= 0xE0) && (alarm_count <= 0xEE))
	{
		return (Meihuo[alarm_count - 0xE0].alarm_level & 0x07);
	}
    else
		return 0;
	
  //  switch(alarm_count)
  //  {
        

   //     default:
   //         return 0;
   //         break;

   // }
}





