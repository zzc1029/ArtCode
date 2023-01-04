/*
 * display.c
 *
 *  Created on: 2021-8-10
 *      Author: ART
 */

#include "system_init.h"
#include "displayhelper.h"



volatile u8 DCDC1[8],RUNHUA[8],PEIDIAN[8],shuileng1[8],shuileng2[8],DriverOperateStatus,OnOffStatus;
//volatile u8 jizhong_alarm[10],jizhong_life[10],jizhong_grade[10],jizhong_code[10],jizhong_box[10]={0};
volatile u8 _0C04A1A7_DATA[8],_0C07A1A7_DATA[8],_0C09A1A7_DATA[8],_181AD0F3_DATA[8],_181BD0F3_DATA[8];
volatile u8 _181CD0F3_DATA[8],_181DD0F3_DATA[8],_181ED0F3_DATA[8]; 
volatile u8 _0C0CA7F2_DATA[8],_0C0AA7F0_DATA[8],_0C01F4A7_DATA[8],_0C08A7F4_DATA[8],_180AA7A3_DATA[8];
volatile u8 _180BA7A3_DATA[8],_180CA7A3_DATA[8],_0C01A70A_DATA[8],_0C02A70A_DATA[8],_0C03A70A_DATA[8];
volatile u8 _0C04A70A_DATA[8],_1818D0F3_DATA[8],_1819D0F3_DATA[8],_18EFA1A5_DATA[8],_1819A100_DATA[8]; 
volatile u8 _180028F3_DATA[8],_180128F3_DATA[8],_180228F3_DATA[8],_180328F3_DATA[8],_180428F3_DATA[8];
volatile u8 _180528F3_DATA[8],_180028F4_DATA[8],_180128F4_DATA[8];
volatile u8 _180228F4_DATA[8],_180328F4_DATA[8],_0CFFF3A7_DATA[8],_0CFEEC21_DATA[8],_18EBA1A5_DATA[8];
volatile u8 EngineWaterTemp,EngineLoad,EngineTatgetAccelerator,EngineActualAccelerator,VCU_Life,EngineInputAirTemp,FuelConsumption_Instant;
volatile u16 EngineSpeed,scr,oil_prss,shunshigonglv,FuelConsumption_100KM_Subtotal,FuelConsumption_100KM_Acctotal,shengyugonglv,Motor_Current;
volatile u32 OilAccumulation;
volatile u8 VCUSofeVersion[8],ECUSofeVersion[8],EECUSofeVersion[8],SystemMode,SystemStatus,xuedimoshi,qianyinli,InsulationMonitorErrorLevel,InsulationMonitorLife,InsulationMonitorAlarm;
volatile u16 InsulationMonitorRes_Positive,InsulationMonitorRes_Negative,can_err_time,Bat_Soc,SystemCode;
volatile u8 DrivingRange,baigongli[2],AlarmFlag[4],E_MotorError[4],BmsMonoData[5][8],veh_scr,fire_alarm_status[4],fire_alarm_system_status,fire_alarm_life,DebugData[8];


volatile TYPE_BYTE AIR[8],YUN_TONG[8],fuzhu[8],add1[8],add2[8],add3[8];
volatile bus_motor MOTOR;
volatile bus_control CONTROL;
volatile footboard STEP;
volatile dcdc DC_DC;
volatile dcac DC_AC;
volatile footboard STEP;
volatile extinguisher Extinguisher;
volatile battery BMS;
volatile mono_battery BMS_MONO;
volatile bat_fire BAT_FIRE;
volatile tire TIRE;





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

#if(DISPLAYTASKNUM > 8)

void Page0x2C_01(u8 initpw)
{
	
	SendStart();
	communicate_T123_data[1] = PAGE_0x2C;
	communicate_T123_data[2] = 1;

	for(i=0;i<8;i++)
		communicate_T123_data[3 + i]   = shuileng2[i];

	SendEnd();
}

static u32 display_surface1(u8 key,u8 initpw)  //松正
{
    u8 i;
	static u8 loop = 0;
    if(initpw)
    {
        ChangeToPage(PAGE_0x2C);
    }

	Page0x2C_01(initpw);


    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }

   return DIS_PAGE1_MENU;
}

#endif

#if(DISPLAYTASKNUM > 1)

void Send0x28_1(u8 initpw)
{

	SendStart();

	communicate_T123_data[1] = PAGE_0x28;
	communicate_T123_data[2] = 0x01;

   	for (i = 0; i < 8; i++)
    {
        communicate_T123_data[3 + i]   = AIR[i].byte;
    }
	
	SendEndPlus(10);
}


//烟雾报警信息界面
static u32 display_surface2(u8 key,u8 initpw)  //烟雾报警信息
{

    static u8 flag = 0,changescreenflag = 0;
    u8 i;
    if(initpw)
    {
        ChangeToPage(PAGE_0x28);
    }

    Send0x28_1(initpw);

    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }
    return DIS_PAGE2_MENU;
}
#endif



#if(DISPLAYTASKNUM > 2)

void Send0x27_1(u8 num, u8 initpw)
{
	SendStart();
	communicate_T123_data[1] = PAGE_0x27;
	communicate_T123_data[2] = num;
	
	for (i = 0; i < 8; i++)
    {
        communicate_T123_data[i + 3] = BmsMonoData[num - 1][i];
    }

	SendEnd();
}

void Send0x27_6 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x27;
    communicate_T123_data[2] = 0x06;

    communicate_T123_data[3]   = BMS_MONO.isampl_number[0];
    communicate_T123_data[4]   = BMS_MONO.itemp[0];
    communicate_T123_data[5]   = BMS_MONO.isampl_number[1];
    communicate_T123_data[6]   = BMS_MONO.itemp[1];
    communicate_T123_data[7]   = BMS_MONO.isampl_number[2];
    communicate_T123_data[8]   = BMS_MONO.itemp[2];
    communicate_T123_data[9]   = BMS_MONO.isampl_number[3];
    communicate_T123_data[10]   = BMS_MONO.itemp[3];

    SendEnd();
}
void Send0x27_7 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x27;
    communicate_T123_data[2] = 0x07;

    communicate_T123_data[3]   = BMS_MONO.isampl_number[4];
    communicate_T123_data[4]   = BMS_MONO.itemp[4];
    communicate_T123_data[5]   = BMS_MONO.isampl_number[5];
    communicate_T123_data[6]   = BMS_MONO.itemp[5];
    communicate_T123_data[7]   = BMS_MONO.isampl_number[6];
    communicate_T123_data[8]   = BMS_MONO.itemp[6];
    communicate_T123_data[9]   = BMS_MONO.isampl_number[7];
    communicate_T123_data[10]   = BMS_MONO.itemp[7];

    SendEnd();
}
void Send0x27_8 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x27;
    communicate_T123_data[2] = 0x08;

    communicate_T123_data[3]   = BMS_MONO.isampl_number[8];
    communicate_T123_data[4]   = BMS_MONO.itemp[8];
    communicate_T123_data[5]   = BMS_MONO.isampl_number[9];
    communicate_T123_data[6]   = BMS_MONO.itemp[9];

    SendEnd();
}

//电池组信息
u32 display_surface3(u8 key,u8 initpw)
{
    static u8 fan = 0;
    if(initpw)
    {
        ChangeToPage(PAGE_0x27);
    }

	switch (fan & 7)
    {
        case 0:
            Send0x27_1 (1, initpw);
            break;
        case 1:
            Send0x27_1 (2, initpw);
            break;
        case 2:
            Send0x27_1 (3, initpw);
            break;
        case 3:
            Send0x27_1 (4, initpw);
            break;
        case 4:
            Send0x27_1 (5, initpw);
            break;
        case 5:
            Send0x27_6 (initpw);
            break;
        case 6:
            Send0x27_7 (initpw);
            break;
        case 7:
            Send0x27_8 (initpw);
            break;
        default:
            break;
    }

    fan ++;
	if(fan >= 8)
		fan = 0;
    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }
    return DIS_PAGE3_MENU;
}

#endif

#if(DISPLAYTASKNUM > 3)
void Send0x24_1 (u8 initpw)
{
    u16 tempxx, cur1, cur2, cur3;
    SendStart();

    communicate_T123_data[1] = PAGE_0x24;
    communicate_T123_data[2] = 0x01;

    tempxx = BMS.ivoltage / 10;
    cur1 = BMS.imax_charge / 10;
    cur2 = BMS.imax_discharge / 10;
    cur3 = BMS.icadc / 10;

    communicate_T123_data[3]   = GetU16Low (tempxx);
    communicate_T123_data[4]   = GetU16High (tempxx);
    communicate_T123_data[5]   = GetU16Low (cur1);
    communicate_T123_data[6]   = GetU16High (cur1);
    communicate_T123_data[7]   = GetU16Low (cur2);
    communicate_T123_data[8]   = GetU16High (cur2);
    communicate_T123_data[9]   = GetU16Low (cur3);
    communicate_T123_data[10]  = GetU16High (cur3);

    SendEnd();
}

void Send0x24_2 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x24;
    communicate_T123_data[2] = 0x02;

    communicate_T123_data[3]   = GetU16Low (BMS.itotal_anode_riso);
    communicate_T123_data[4]   = GetU16High (BMS.itotal_anode_riso);
    communicate_T123_data[5]   = GetU16Low (BMS.itotal_cathode_riso);
    communicate_T123_data[6]   = GetU16High (BMS.itotal_cathode_riso);
    communicate_T123_data[7]   = GetU16Low (BMS.imono_max_voltage);
    communicate_T123_data[8]   = GetU16High (BMS.imono_max_voltage);
    communicate_T123_data[9]   = GetU16Low (BMS.imono_min_voltage);
    communicate_T123_data[10]   = GetU16High (BMS.imono_min_voltage);

    SendEnd();
}

void Send0x24_3 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x24;
    communicate_T123_data[2] = 0x03;

    communicate_T123_data[3]   = GetU16Low (BMS.iaverage_voltage);
    communicate_T123_data[4]   = GetU16High (BMS.iaverage_voltage);
	communicate_T123_data[5]   = CanData[ID(0x1818D0F3)][BYTE5];
    /*communicate_T123_data[5]   = BMS.imono_max_temp;
    communicate_T123_data[6]   = BMS.istatus[0];
    communicate_T123_data[7]   = BMS.istatus[1];
    communicate_T123_data[8]   = BMS.istatus[2];
    communicate_T123_data[9]   = BMS.status_flag4;
    communicate_T123_data[10]   = BMS.status_flag5;*/

    SendEnd();
}
void Send0x24_4 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x24;
    communicate_T123_data[2] = 0x04;

    communicate_T123_data[3]   = BMS.imono_min_temp;

    SendEnd();
}

void Send0x25_1 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x25;
    communicate_T123_data[2] = 0x01;

    communicate_T123_data[3]   = BMS.VIN;
    communicate_T123_data[4]   = BMS.ChargeOutletTemp1;
    communicate_T123_data[5]   = BMS.ChargeOutletTemp2;
    communicate_T123_data[6]   = BMS.ChargeOutletTemp3;
    communicate_T123_data[7]   = BMS.ChargeOutletTemp4;
    communicate_T123_data[8]   = BMS.error_total;

    SendEnd();
}

void Send0x25_2 (u8 initpw)
{
    u16 vol;
    SendStart();

    vol = BMS.rated_voltage / 10;

    communicate_T123_data[1] = PAGE_0x25;
    communicate_T123_data[2] = 0x02;

    communicate_T123_data[3]   = GetU16Low (BMS.rated_capacity);
    communicate_T123_data[4]   = GetU16High (BMS.rated_capacity);
    communicate_T123_data[5]   = GetU16Low (vol);
    communicate_T123_data[6]   = GetU16High (vol);
    communicate_T123_data[7]   = GetU16Low (BMS.battery_series_num);
    communicate_T123_data[8]   = GetU16High (BMS.battery_series_num);
    communicate_T123_data[9]   = BMS.battery_parallel_num;
    communicate_T123_data[10]   = BMS.temp_sensor_num;
    SendEnd();
}
void Send0x26_1 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x26;
    communicate_T123_data[2] = 0x01;

    communicate_T123_data[3]   = BMS.imono_max_temp_2;
    communicate_T123_data[4]   = BMS.maxtemp_pos_x;
    communicate_T123_data[5]   = BMS.maxtemp_pos_y;
    communicate_T123_data[6]   = BMS.imono_min_temp;
    communicate_T123_data[7]   = BMS.mintemp_pos_x;
    communicate_T123_data[8]   = BMS.mintemp_pos_y;
    communicate_T123_data[9]   = BMS.battery_typeinfo;
    communicate_T123_data[10]   = BMS.battery_cooling_methods;
    SendEnd();
}
void Send0x26_2 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x26;
    communicate_T123_data[2] = 0x02;

    communicate_T123_data[3]   = GetU16Low (BMS.imono_max_voltage);
    communicate_T123_data[4]   = GetU16High (BMS.imono_max_voltage);
    communicate_T123_data[5]   = GetU16Low (BMS.imono_min_voltage);
    communicate_T123_data[6]   = GetU16High (BMS.imono_min_voltage);

    SendEnd();
}

void Send0x26_3 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x26;
    communicate_T123_data[2] = 0x03;

    communicate_T123_data[3]   = BMS.maxvol_pos_x;
    communicate_T123_data[4]   = BMS.maxvol_pos_y;
    communicate_T123_data[5]   = BMS.minvol_pos_x;
    communicate_T123_data[6]   = BMS.minvol_pos_y;

    SendEnd();
}
void Send0xbatt401 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x29;
    communicate_T123_data[2] = 0x01;

    communicate_T123_data[3]   = BMS.istatus[0];
    communicate_T123_data[4]   = BMS.istatus[1];
    communicate_T123_data[5]   = BMS.istatus[2];
    communicate_T123_data[6]   = BMS.status_flag4;
    communicate_T123_data[7]   = BMS.status_flag5;

    SendEnd();
}

u32 display_surface4(u8 key,u8 initpw)
{
    static u8 flag = 0;
    static u8 fan = 0;
    u8 changescreenflag = 0;

    if(initpw)
    {
       changescreenflag = 1;
    }

	switch (key)
    {
        case IN_KEY2_SP:
            flag++;
            flag = flag >= 4 ? 0 : flag;
            changescreenflag = 1;
            break;
        case IN_KEY3_SP:
            flag = flag == 0 ? 4 : flag;
            flag--;
            changescreenflag = 1;
            break;
    }

	if (changescreenflag)
    {
        switch (flag)
        {
            case 0:
                ChangeToPage (PAGE_0x24);
                Send0x24_1 (changescreenflag);
                Send0x24_2 (changescreenflag);
                Send0x24_3 (changescreenflag);
                //Send0x24_4 (changescreenflag);
                break;
            case 1:
                ChangeToPage (PAGE_0x25);
                Send0x25_1 (changescreenflag);
                Send0x25_2 (changescreenflag);
                break;
            case 2:
                ChangeToPage (PAGE_0x26);
                Send0x26_1 (changescreenflag);
                Send0x26_2 (changescreenflag);
                Send0x26_3 (changescreenflag);
                break;
			case 3:
                ChangeToPage (PAGE_0x29);
				Send0xbatt401(changescreenflag);
				break;
        }
    }

	switch (flag)
    {
        case 0:
            if ((fan & 0x03) == 0)
            {
                Send0x24_1(0);
            }
            else if ((fan & 0x03) == 1)
            {
                Send0x24_2(0);
            }
            else if ((fan & 0x03) == 2)
            {
                Send0x24_3(0);
            }
			/*else if ((fan & 0x03) == 3)
            {
                Send0x24_4(0);
            }*/
            fan ++;
			if(fan >= 4)
				fan = 0;
            break;
        case 1:
            if ((fan & 0x03) == 0)
            {
                Send0x25_1(0);
            }
            else if ((fan & 0x03) == 1)
            {
                Send0x25_2(0);
            }
            fan ++;
			if(fan >= 2)
				fan = 0;
            break;
        case 2:
            if ((fan & 0x03) == 0)
            {
                Send0x26_1(0);
            }
            else if ((fan & 0x03) == 1)
            {
                Send0x26_2(0);
            }
            else if ((fan & 0x03) == 2)
            {
                Send0x26_3(0);
            }
            fan ++;
			if(fan >= 3)
				fan = 0;
            break;
		case 3:
			Send0xbatt401(0);
			break;
    }
    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }

    return DIS_PAGE4_MENU;
}
#endif



#if(DISPLAYTASKNUM > 4)

void Send0x23_1 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x23;
    communicate_T123_data[2] = 0x01;
    for (i = 0; i < 8; i++)
    {
        communicate_T123_data[3 + i]   = DebugData[i];
    }

    SendEnd();
}


void Send0x23_2 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x23;
    communicate_T123_data[2] = 0x02;
	
    communicate_T123_data[3]   = YUN_TONG[6].byte;

    SendEnd();

}

u32 display_surface5(u8 key,u8 initpw)
{
    if(initpw)
    {
        ChangeToPage(PAGE_0x23);
    }

	Send0x23_1(initpw);
	Send0x23_2(initpw);

	if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }

    return DIS_PAGE5_MENU;
}

#endif


//新增页面5
#if(DISPLAYTASKNUM > 5)

void Send0x22_1 (u8 initpw)
{
    u16 vol1, vol2, cur;
    SendStart();

    communicate_T123_data[1] = PAGE_0x22;
    communicate_T123_data[2] = 0x01;

    vol1 = DC_DC.voltage_out * 0.1;
    vol2 = DC_DC.voltage_input * 0.1;
    cur = DC_DC.current * 0.1;

    communicate_T123_data[3]   = GetU16Low (vol1);
    communicate_T123_data[4]   = GetU16High (vol1);
    communicate_T123_data[5]   = GetU16Low (cur);
    communicate_T123_data[6]   = GetU16High (cur);
    communicate_T123_data[7]   = GetU16Low (vol2);
    communicate_T123_data[8]   = GetU16High (vol2);

    communicate_T123_data[9]   = DC_DC.temp;
    communicate_T123_data[10]   = DC_DC.faultcode;

    SendEnd();
}

void Send0x22_2 (u8 initpw)
{
    SendStart();


    communicate_T123_data[1] = PAGE_0x22;
    communicate_T123_data[2] = 0x02;

    communicate_T123_data[3]   = DCDC1[0];
    communicate_T123_data[4]   = DCDC1[2];
    communicate_T123_data[5]   = DCDC1[3];
    communicate_T123_data[6]   = DCDC1[4];

    SendEnd();
}

void Send0x22_3 (u8 initpw)
{
    SendStart();
    communicate_T123_data[1] = PAGE_0x22;
    communicate_T123_data[2] = 0x03;

    communicate_T123_data[3]   = GetU16Low (InsulationMonitorRes_Positive);
    communicate_T123_data[4]   = GetU16High (InsulationMonitorRes_Positive);
    communicate_T123_data[5]   = GetU16Low (InsulationMonitorRes_Negative);
    communicate_T123_data[6]   = GetU16High (InsulationMonitorRes_Negative);
    communicate_T123_data[7]   = InsulationMonitorErrorLevel;
    communicate_T123_data[8]   = InsulationMonitorLife;
    communicate_T123_data[9]   = InsulationMonitorAlarm;
    SendEnd();
}
void Send0x2B_1 (u8 initpw)
{
    SendStart();
    communicate_T123_data[1] = PAGE_0x2B;
    communicate_T123_data[2] = 0x01;
    for (i = 0; i < 8; i++)
    {
        communicate_T123_data[3 + i] = fuzhu[i].byte;
    }

    SendEnd();
}

void Send0x2F_01 (u8 initpw)
{
    SendStart();
    communicate_T123_data[1] = PAGE_0x2F;
    communicate_T123_data[2] = 0x01;

    for (i = 0; i < 8; i++)
    {
        communicate_T123_data[3 + i] = add1[i].byte;
    }

    SendEnd();
}

void Send0x2F_02 (u8 initpw)
{
    SendStart();
    communicate_T123_data[1] = PAGE_0x2F;
    communicate_T123_data[2] = 0x02;

    for (i = 0; i < 8; i++)
    {
        communicate_T123_data[3 + i] = add2[i].byte;
    }

    SendEnd();
}

void Send0x30_01 (u8 initpw)
{
    SendStart();
    communicate_T123_data[1] = PAGE_0x30;
    communicate_T123_data[2] = 0x01;

    for (i = 0; i < 8; i++)
    {
        communicate_T123_data[3 + i] = add3[i].byte;
    }

    SendEnd();
}

static u32 display_surface6(u8 key,u8 initpw)  //松正
{
    static u8 flag = 0;
    static u8 fan = 0;
    u8 changescreenflag = 0;

    if (initpw)
    {
        changescreenflag = 1;
    }

    switch (key)
    {
        case IN_KEY2_SP:
            flag++;
            flag = flag >= 4 ? 0 : flag;
            changescreenflag = 1;
            break;
        case IN_KEY3_SP:
            flag = flag == 0 ? 4 : flag;
            flag--;
            changescreenflag = 1;
            break;
    }
    if (changescreenflag)
    {
        switch (flag)
        {
            case 0:
                ChangeToPage (PAGE_0x22);
                break;
            case 1:
                ChangeToPage (PAGE_0x2B);
                break;
            case 2:
                ChangeToPage (PAGE_0x2F);
                break;
            case 3:
                ChangeToPage (PAGE_0x30);
                break;
        }
    }

	switch (flag)
    {
        case 0:
            if ((fan & 0x03) == 0)
            {
                Send0x22_1 (0);
            }
            else if ((fan & 0x03) == 1)
            {
                Send0x22_2 (0);
            }
            else if ((fan & 0x03) == 2)
            {
                Send0x22_3 (0);
            }
            fan ++;
			if(fan >= 3)
				fan = 0;
            break;
        case 1:
            Send0x2B_1 (0);
            break;
        case 2:
            Send0x2F_02 (0);
            Send0x2F_01 (0);
            break;
        case 3:
            Send0x30_01 (0);
            break;
    }
	
    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }

    return DIS_PAGE6_MENU;
}

#endif

#if(DISPLAYTASKNUM > 6)

void Send0x21_1 (u8 initpw)
{
    u16 cur;
    SendStart();

    communicate_T123_data[1] = PAGE_0x21;
    communicate_T123_data[2] = 0x01;


    communicate_T123_data[3]   = MOTOR.itemp;
    communicate_T123_data[4]   = CONTROL.itemp;
    communicate_T123_data[5]   = MOTOR.etemp;
    communicate_T123_data[6]   = CONTROL.etemp;
    communicate_T123_data[7]   = GetU16Low (MOTOR.itorque);
    communicate_T123_data[8]   = GetU16High (MOTOR.itorque);
    
    cur =  MOTOR.icurrent * 0.1;
    communicate_T123_data[9]   = GetU16Low (cur);
    communicate_T123_data[10]   = GetU16High (cur);


    SendEnd();
}

void Send0x21_2 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x21;
    communicate_T123_data[2] = 0x02;

    //communicate_T123_data[3]   = 0;
    for (i = 0; i < 8; i++)
    {
        communicate_T123_data[i + 3]   = ECUSofeVersion[i];
    }
    SendEnd();
}

void Send0x21_3 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x21;
    communicate_T123_data[2] = 0x03;

    for (i = 0; i < 8; i++)
    {
        communicate_T123_data[i + 3]   = EECUSofeVersion[i];
    }
    SendEnd();
}


u32 display_surface7(u8 key,u8 initpw)
{
	static u8 fan = 0;
    if(initpw)
    {
        ChangeToPage(PAGE_0x21);
    }

	if ((fan & 0x03) == 0)
    {
        Send0x21_1 (initpw);
    }
    else if ((fan & 0x03) == 1)
    {
        Send0x21_2 (initpw);
    }
	else if ((fan & 0x03) == 2)
    {
        Send0x21_3 (initpw);
    }
    fan ++;
	if(fan >= 3)
		fan = 0;
	if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }

    return DIS_PAGE7_MENU;
}

#endif

#if(DISPLAYTASKNUM > 7)

void Send0x20_1 (u8 initpw)
{
    u16 vol, cur;

	SendStart();

    communicate_T123_data[1] = PAGE_0x20;
    communicate_T123_data[2] = 0x01;

    vol =  MOTOR.ivoltage * 0.1;
    cur =  MOTOR.icurrent * 0.1;
    communicate_T123_data[3]   = GetU16Low (vol);
    communicate_T123_data[4]   = GetU16High (vol);
    communicate_T123_data[5]   = GetU16Low (cur);
    communicate_T123_data[6]   = GetU16High (cur);
    communicate_T123_data[7]   = DriverOperateStatus;
    communicate_T123_data[8]   = OnOffStatus;
    communicate_T123_data[9]   = VCU_Life;
    //   communicate_T123_data[10]  = STEP.ispeed_up[1]*0.4;

    SendEnd();

}

void Send0x20_2 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x20;
    communicate_T123_data[2] = 0x02;

    communicate_T123_data[3]   = SystemMode;
    communicate_T123_data[4]   = SystemStatus;
    SendEnd();
}

void Send0x20_3 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x20;
    communicate_T123_data[2] = 0x03;

    communicate_T123_data[3]   = STEP.ispeed_up * 0.4;
    communicate_T123_data[4]   = STEP.ibraking * 0.4;
	//communicate_T123_data[5]   = xuedimoshi;
	//communicate_T123_data[6]   = qianyinli;
    SendEnd();
}

void Send0x20_4 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x20;
    communicate_T123_data[2] = 0x04;

    for (i = 0; i < 8; i++)
    {
        communicate_T123_data[i + 3]   = VCUSofeVersion[i];
    }
    SendEnd();
}

u32 display_surface8(u8 key,u8 initpw)
{
	static u8 fan = 0;
    if(initpw)
    {
        ChangeToPage(PAGE_0x20);
    }

	if ((fan & 0x03) == 0)
    {
        Send0x20_1 (initpw);
    }
    else if ((fan & 0x03) == 1)
    {
        Send0x20_2 (initpw);
    }
	else if ((fan & 0x03) == 2)
    {
        Send0x20_3 (initpw);
    }
	else if ((fan & 0x03) == 3)
    {
        Send0x20_4 (initpw);
    }
    fan ++;
	if(fan >= 4)
		fan = 0;
	if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }

    return DIS_PAGE8_MENU;
}

#endif
#if 0
#if(DISPLAYTASKNUM > 8)

void Send0x31_1 (u8 initpw)
{

	SendStart();

	for(i=0;i<10;i++)
	{
		if(BAT_FIRE.box[i] == 0)
			break;
	}
    communicate_T123_data[1] = PAGE_0x31;
    communicate_T123_data[2] = 0x01;

    communicate_T123_data[3]   = i;
    communicate_T123_data[4]   = BAT_FIRE.rollcounter;

    SendEnd();

}

void Send0x31_2 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x31;
    communicate_T123_data[2] = 0x02;

    communicate_T123_data[3]   = BAT_FIRE.box[0];
    communicate_T123_data[4]   = BAT_FIRE.status[0];
	communicate_T123_data[5]   = BAT_FIRE.fault_code[0];
	communicate_T123_data[6]   = BAT_FIRE.type[0];
	communicate_T123_data[7]   = BAT_FIRE.box[1];
    communicate_T123_data[8]   = BAT_FIRE.status[1];
	communicate_T123_data[9]   = BAT_FIRE.fault_code[1];
	communicate_T123_data[10]   = BAT_FIRE.type[1];
    SendEnd();
}

void Send0x31_3 (u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x31;
    communicate_T123_data[2] = 0x03;

    communicate_T123_data[3]   = BAT_FIRE.box[2];
    communicate_T123_data[4]   = BAT_FIRE.status[2];
	communicate_T123_data[5]   = BAT_FIRE.fault_code[2];
	communicate_T123_data[6]   = BAT_FIRE.type[2];
	communicate_T123_data[7]   = BAT_FIRE.box[3];
    communicate_T123_data[8]   = BAT_FIRE.status[3];
	communicate_T123_data[9]   = BAT_FIRE.fault_code[3];
	communicate_T123_data[10]   = BAT_FIRE.type[3];
    SendEnd();
}



u32 display_surface9(u8 key,u8 initpw)
{
	static u8 fan = 0;
    if(initpw)
    {
        ChangeToPage(PAGE_0x31);
    }

	if (fan == 0)
    {
        Send0x31_1 (1);
    }
    else if (fan  == 2)
    {
        Send0x31_2 (1);
    }
	else if (fan  == 4)
    {
        Send0x31_3 (1);
    }

    fan ++;
	if(fan >= 6)
		fan = 0;
	if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }

    return DIS_PAGE9_MENU;
}

#endif
#endif
void AddWanDaMenu(void)
{
#if 0
#if(DISPLAYTASKNUM > 8)
    //电池箱灭火
	AddMenu(display_surface9,			   DIS_PAGE9_MENU);
#endif
#endif

#if(DISPLAYTASKNUM > 8)
    //TMS
	AddMenu(display_surface1,			   DIS_PAGE1_MENU);
#endif

#if(DISPLAYTASKNUM > 1)
    //空调系统信息
	AddMenu(display_surface2,			   DIS_PAGE2_MENU);
#endif

#if(DISPLAYTASKNUM > 2)  
    //电池系统信息
    AddMenu(display_surface3,			   DIS_PAGE3_MENU);
#endif

#if(DISPLAYTASKNUM > 3)
    //电池管理信息
	AddMenu(display_surface4,			   DIS_PAGE4_MENU);
#endif

#if(DISPLAYTASKNUM > 4)
    //调试参数信息
	AddMenu(display_surface5,			   DIS_PAGE5_MENU);
#endif

#if(DISPLAYTASKNUM > 5)
    //辅助系统信息
	AddMenu(display_surface6,			   DIS_PAGE6_MENU);
#endif 
#if(DISPLAYTASKNUM > 6)
    //主驱系统信息
	AddMenu(display_surface7,			   DIS_PAGE7_MENU);
#endif 
#if(DISPLAYTASKNUM > 7)
    //控制系统信息
	AddMenu(display_surface8,			   DIS_PAGE8_MENU);
#endif 


}


