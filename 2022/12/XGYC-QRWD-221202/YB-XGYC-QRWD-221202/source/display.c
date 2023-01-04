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


volatile u8 DCDC1[8],DriverOperateStatus,OnOffStatus;
volatile u8 _0C04A1A7_DATA[8],_0C06A1A7_DATA[8],_0C09A1A7_DATA[8],_181AD0F3_DATA[8],_181BD0F3_DATA[8];
volatile u8 _181CD0F3_DATA[8],_181DD0F3_DATA[8],_181ED0F3_DATA[8]; 
volatile u8 _0C0CA7F2_DATA[8],_0C0AA7F0_DATA[8],_0C08A7F4_DATA[8],_180AA7A3_DATA[8];
volatile u8 _180BA7A3_DATA[8],_180CA7A3_DATA[8],_0C01A70A_DATA[8],_0C02A70A_DATA[8],_0C03A70A_DATA[8];
volatile u8 _0C04A70A_DATA[8],_1818D0F3_DATA[8],_1819D0F3_DATA[8],_18EFA1A5_DATA[8]; 
volatile u8 _180028F3_DATA[8],_180128F3_DATA[8],_180228F3_DATA[8],_180328F3_DATA[8],_180428F3_DATA[8];
volatile u8 _180528F3_DATA[8],_180028F4_DATA[8],_180128F4_DATA[8];
volatile u8 _180228F4_DATA[8],_180328F4_DATA[8],_0CFFF3A7_DATA[8],_0CFEEC21_DATA[8];
volatile u8 EngineWaterTemp,EngineLoad,EngineTatgetAccelerator,EngineActualAccelerator,VCU_Life,EngineInputAirTemp,FuelConsumption_Instant;
volatile u16 EngineSpeed,scr,oil_prss,shunshigonglv,FuelConsumption_100KM_Subtotal,FuelConsumption_100KM_Acctotal,shengyugonglv,Motor_Current;
volatile u32 OilAccumulation;
volatile u8 VCUSofeVersion[8],ECUSofeVersion[8],EECUSofeVersion[8],SystemMode,SystemStatus,xuedimoshi,qianyinli;
volatile u16 can_err_time,SystemCode;
volatile u8 DrivingRange,baigongli[2],AlarmFlag[4],E_MotorError[4],BmsMonoData[5][8],DebugData[8];
volatile u8 ECASFault[40];


volatile TYPE_BYTE AIR[8],YUN_TONG[8],fuzhu[8],add1[8],add2[8],add3[8];
volatile bus_motor MOTOR;
volatile bus_control CONTROL;
volatile footboard STEP;
volatile dcdc DC_DC;
volatile footboard STEP;
volatile battery BMS;
volatile mono_battery BMS_MONO;
volatile miehuo MIEHUO;


uint8_t dis_mod = DIS_MAIN_MENU;
u8 Send_To_DP_Data[12];




unsigned long ByteToDword (volatile u8 *data, u8 i)
{
    unsigned long temp, tep;
    tep  = ((data[i + 1] << 8) & 0x0000ff00) + data[i];
    temp = ((data[i + 3] << 8) & 0x0000ff00) + data[i + 2];
    temp = (temp << 16) & 0xffff0000;
    return (temp | tep);
}

u32 Get_Spn (u32 data) //57843
{
    u16 temp = (unsigned int) (data & 0xffff);
    data  &= 0xe00000;
    data >>= 5;
    return data + temp;
}

u8 Get_Fmi (u32 data)
{
    return (data & 0x1f0000) >> 16;
}

u8 Get_Oc (u32 data)
{
    return (data & 0x7f000000) >> 24;
}


u32 ECAS_All_Spn[10];
u16 ECAS_All_Fmi[10];
u8  ECAS_All_Oc[10];

void ECAS_Spn_and_Fim1(void)
{
	 u32 temp;
	 u8 i,j = 0;
	 for(i=0;i<5;i++)
	 {
	 	temp = ByteToDword(ECASFault,(4*i));
	 	ECAS_All_Spn[i] = Get_Spn(temp);
	 	ECAS_All_Fmi[i] = Get_Fmi(temp);
		ECAS_All_Oc[i] = Get_Oc(temp);
	 }
}




void SendPAGE_MAIN04(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x01;
	Send_To_DP_Data[1] = PAGE_MAIN;
	Send_To_DP_Data[2] = 1;
	
	DP_DATA1 = CanData[ID(0x1818D0F3)][0];
    DP_DATA2 = CanData[ID(0x1818D0F3)][1];
    DP_DATA3 = CanData[ID(0x1818D0F3)][2];
    DP_DATA4 = CanData[ID(0x1818D0F3)][3];

    DP_DATA5 = CanData[ID(0x181AD0F3)][4];
    DP_DATA6 = CanData[ID(0x181AD0F3)][5];
    DP_DATA7 = CanData[ID(0x181AD0F3)][6];
    DP_DATA8 = CanData[ID(0x181AD0F3)][7];

    SendEnd();
}


void SendPAGE_MAIN05(u8 initpw)
{
        
	SendStart();
	Send_To_DP_Data[0] = 0x01;
	Send_To_DP_Data[1] = PAGE_MAIN;
	Send_To_DP_Data[2] = 2;
	
	DP_DATA1 = CanData[ID(0x181DD0F3)][0];
    DP_DATA2 = CanData[ID(0x181DD0F3)][3];
    DP_DATA3 = CanData[ID(0x0C04A1A7)][0];
    DP_DATA4 = CanData[ID(0x0C04A1A7)][1];

    DP_DATA5 = CanData[ID(0x0C08A1A7)][0];
    DP_DATA6 = CanData[ID(0x0C08A1A7)][1];
    DP_DATA7 = CanData[ID(0x0C0AA1A7)][4];
    DP_DATA8 = CanData[ID(0x0C0AA1A7)][5];
	
    SendEnd();
}

void SendPAGE_MAIN06(u8 initpw)
{
    u16 u16_data;
	SendStart();
	Send_To_DP_Data[0] = 0x01;
	Send_To_DP_Data[1] = PAGE_MAIN;
	Send_To_DP_Data[2] = 3;
	
	DP_DATA1   = CanData[ID(0x0C01A70A)][5];
    DP_DATA2   = CanData[ID(0x0C01A70A)][6];
    DP_DATA3   = CanData[ID(0x0C01A70A)][7];
    DP_DATA4   = CanData[ID(0x1818D0F3)][4];

    DP_DATA5 = 0;
    DP_DATA6 = 0;
    DP_DATA7 = 0;
    DP_DATA8 = 0;


   	SendEnd();
}


SendGroup_Init(Main_Data)
{
	SendPAGE_MAIN04,
	SendPAGE_MAIN05,
	SendPAGE_MAIN06
};



FUNC_MENU(DIS_VCU_MENU, {});
FUNC_MENU(DIS_MCU_MENU, {});
FUNC_MENU(DIS_BMS_MENU,
{
    static u8 page = 0;
    const u8 PAGE_NUM  = 3;

    switch(key)
    {
        case IN_KEY2_SP:
            page++;
            page = (page >= PAGE_NUM) ? 0 : page;
            ChangeToSubPage(DIS_BMS_MENU, page);
            break;
        case IN_KEY3_SP:
            page = (page == 0) ? PAGE_NUM : page;
            page--;
            ChangeToSubPage(DIS_BMS_MENU, page);
            break;
    }
});

FUNC_MENU(DIS_BATCELL_MENU, {});

FUNC_MENU(DIS_FUZU_MENU,
{
    static u8 page = 0;
    const u8 PAGE_NUM  = 4;

    switch(key)
    {
        case IN_KEY2_SP:
            page++;
            page = (page >= PAGE_NUM) ? 0 : page;
            ChangeToSubPage(DIS_FUZU_MENU, page);
            break;
        case IN_KEY3_SP:
            page = (page == 0) ? PAGE_NUM : page;
            page--;
            ChangeToSubPage(DIS_FUZU_MENU, page);
            break;
    }

});

FUNC_MENU(DIS_PARAM_MENU, {});
FUNC_MENU(DIS_TMS_MENU, {});
void SendPAGE_0x21_1(u8 initpw)
{
	SendStart();
    Send_To_DP_Data[0] = PAGE_0X21;
	Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 1;
	Send_To_DP_Data[3] = MIEHUO.rolling_count[0];
	Send_To_DP_Data[4] = MIEHUO.box[0];
	Send_To_DP_Data[5] = MIEHUO.type[0];
	Send_To_DP_Data[6] = MIEHUO.alarm_level[0];
	Send_To_DP_Data[7] = MIEHUO.fault_status[0];
	Send_To_DP_Data[8] = MIEHUO.zifa_status[0];
	Send_To_DP_Data[9] = MIEHUO.fault_code[0];
    SendEnd();
}

void SendPAGE_0x21_x(u8 initpw,u8 count)
{
	SendStart();
    Send_To_DP_Data[0] = PAGE_0X21;
	Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = count + 1;
	Send_To_DP_Data[3] = 0;
	Send_To_DP_Data[4] = MIEHUO.box[count];
	Send_To_DP_Data[5] = MIEHUO.type[count];
	Send_To_DP_Data[6] = MIEHUO.alarm_level[count];
	Send_To_DP_Data[7] = MIEHUO.fault_status[count];
	Send_To_DP_Data[8] = MIEHUO.zifa_status[count];
	Send_To_DP_Data[9] = MIEHUO.fault_code[count];
    SendEnd();
}


FUNC_MENU(DIS_MIEHUO_MENU,
{
	static u8 loop = 0;
	u8 xiang;
	for(xiang=0;xiang<10;xiang++)
	{
		if(MIEHUO.box[xiang] == 0)
			break;
	}
	if(xiang != 0)
	{
		if(loop == 0)
			SendPAGE_0x21_1(1);
		else if(loop < xiang)
			SendPAGE_0x21_x(1,loop);

		loop++;
		if(loop >= xiang)
			loop = 0;
	}
});

FUNC_MENU(DIS_AP_MENU, {});



void SendPAGE_0x22(u8 initpw)
{
	SendStart();
    Send_To_DP_Data[0] = PAGE_0X22;
	Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 1;
	if((CanData[ID(0x18FFA898)][BYTE1] & 0xC0) == 0x00)
	{
		Send_To_DP_Data[3] = CanData[ID(0x18FFA898)][BYTE3];
		Send_To_DP_Data[4] = CanData[ID(0x18FFA898)][BYTE4];
		Send_To_DP_Data[5] = 0;
		Send_To_DP_Data[6] = 0;
	}
	else if((CanData[ID(0x18FFA898)][BYTE1] & 0xC0) == 0x40)
	{
		Send_To_DP_Data[3] = 0;
		Send_To_DP_Data[4] = 0;
		Send_To_DP_Data[5] = CanData[ID(0x18FFA898)][BYTE3];
		Send_To_DP_Data[6] = CanData[ID(0x18FFA898)][BYTE4];
	}
	else
	{
		Send_To_DP_Data[3] = 0;
		Send_To_DP_Data[4] = 0;
		Send_To_DP_Data[5] = 0;
		Send_To_DP_Data[6] = 0;
	}
    SendEnd();
}


FUNC_MENU(DIS_RUNHUA_MENU, {

	SendPAGE_0x22(1);
});



void SendPAGE_0x2301(u8 initpw)
{
	SendStart();
    Send_To_DP_Data[0] = PAGE_0X23;
	Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 1;
	
	Send_To_DP_Data[3] = GetU16Low(taiya.yali[0]);
	Send_To_DP_Data[4] = GetU16High(taiya.yali[0]);
	Send_To_DP_Data[5] = taiya.wendu[0];
	
	Send_To_DP_Data[6] = GetU16Low(taiya.yali[1]);
	Send_To_DP_Data[7] = GetU16High(taiya.yali[1]);
	Send_To_DP_Data[8] = taiya.wendu[1];

	Send_To_DP_Data[9] = GetU16Low(taiya.yali[2]);
	Send_To_DP_Data[10] = GetU16High(taiya.yali[2]);

	
    SendEnd();
}

void SendPAGE_0x2302(u8 initpw)
{
	SendStart();
    Send_To_DP_Data[0] = PAGE_0X23;
	Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 2;

	Send_To_DP_Data[3] = taiya.wendu[2];	
	Send_To_DP_Data[4] = GetU16Low(taiya.yali[3]);
	Send_To_DP_Data[5] = GetU16High(taiya.yali[3]);
	
	Send_To_DP_Data[6] = taiya.wendu[3];
	
	Send_To_DP_Data[8] = GetU16Low(taiya.yali[4]);
	Send_To_DP_Data[9] = GetU16High(taiya.yali[4]);
	Send_To_DP_Data[10] = taiya.wendu[4];

	
    SendEnd();
}

void SendPAGE_0x2303(u8 initpw)
{
	SendStart();
    Send_To_DP_Data[0] = PAGE_0X23;
	Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 3;

	Send_To_DP_Data[3] = GetU16Low(taiya.yali[5]);
	Send_To_DP_Data[4] = GetU16High(taiya.yali[5]);
	Send_To_DP_Data[5] = taiya.wendu[5];	
	

	
    SendEnd();
}




FUNC_MENU(DIS_TAIYA_MENU, {

	SendPAGE_0x2301(1);
	SendPAGE_0x2302(1);
	SendPAGE_0x2303(1);
});

#if 0
void SendPAGE_0x30(u8 initpw,u8 index)
{
	SendStart();
    Send_To_DP_Data[0] = PAGE_0X30;
	Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 1;
	Send_To_DP_Data[3] = ECAS_All_Spn[index];
	Send_To_DP_Data[4] = ECAS_All_Spn[index] >> 8;
	Send_To_DP_Data[5] = ECAS_All_Spn[index] >> 16;
	Send_To_DP_Data[6] = ECAS_All_Spn[index] >> 24;
	Send_To_DP_Data[7] = ECAS_All_Fmi[index];
	Send_To_DP_Data[8] = ECAS_All_Oc[index];
    SendEnd();
}
void SendPAGE_0x30_ZERO(u8 initpw,u8 index)
{
	SendStart();

    Send_To_DP_Data[0] = PAGE_0X30;
	Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 1;
	Send_To_DP_Data[3] = 0;
	Send_To_DP_Data[4] = 0;
	Send_To_DP_Data[5] = 0;
	Send_To_DP_Data[6] = 0;
	Send_To_DP_Data[7] = 0;
	Send_To_DP_Data[8] = 0;
	SendEnd();
}

FUNC_MENU(DIS_ECAS_MENU, 
({
	static u8 count123 = 10,fan = 0;
	u8 zeronum,j;
	
	ECAS_Spn_and_Fim1();
	count123++;

	if(count123 > 50)
	{
		count123 = 0;
		if(ECAS_All_Spn[fan] > 0)
		{
		  SendPAGE_0x30(1,fan);
		  fan++;
		  if(fan > 4)
		  	fan = 0;
		}
		else
		{
		  	fan = 0;
	  		zeronum = 0;
			for(j = 0;j < 5;j++)
			{
			 if(ECAS_All_Spn[j] == 0)
			 	zeronum++;
			}
			if(zeronum == 5)
				SendPAGE_0x30_ZERO(1,fan);
		}
	}
}));
#endif
void InitDisplay()
{
    InitDisplayHelper();

	AddMenu(FUNC_ITEM(DIS_VCU_MENU));
    AddMenu(FUNC_ITEM(DIS_MCU_MENU));
    AddMenu(FUNC_ITEM(DIS_BMS_MENU));
    AddMenu(FUNC_ITEM(DIS_BATCELL_MENU));
    AddMenu(FUNC_ITEM(DIS_FUZU_MENU));
    AddMenu(FUNC_ITEM(DIS_PARAM_MENU));
	AddMenu(FUNC_ITEM(DIS_TMS_MENU));
	AddMenu(FUNC_ITEM(DIS_MIEHUO_MENU));
    //AddMenu(FUNC_ITEM(DIS_ZHONGKONGPING_MENU));
    AddMenu(FUNC_ITEM(DIS_AP_MENU));
	AddMenu(FUNC_ITEM(DIS_RUNHUA_MENU));
	AddMenu(FUNC_ITEM(DIS_TAIYA_MENU));
	//AddMenu(FUNC_ITEM(DIS_ECAS_MENU));
}




u16 GetWenziWarnCode(u16 alarm_count)
{
    u8 temp = 0;
    u8 index = 0, taiya_lin;

	/*if((alarm_count >= 0xBC) && (alarm_count <= 0xC1))
	{
		return (MIEHUO.alarm_level[alarm_count - 0xBC] & 0x07);
	}*/
	switch(alarm_count)
	{
		case 0xBD:
			return (MIEHUO.alarm_level[0] & 0x07);
			break;
		case 0xBE:
			return (MIEHUO.alarm_level[1] & 0x07);
			break;
		case 0xBF:
			return (MIEHUO.alarm_level[2] & 0x07);
			break;
		case 0xC0:
			return (MIEHUO.alarm_level[3] & 0x07);
			break;
		case 0xC1:
			return (MIEHUO.alarm_level[4] & 0x07);
			break;
		case 0xC2:
			return (MIEHUO.alarm_level[5] & 0x07);
			break;
		default:
			break;
	}
    return 0;
}





