/*
 * canreceive.c
 *
 *  Created on: 2021-8-6
 *      Author: ART
 */

#include "system_init.h"

const uint32_t CanIdTable[] =
{
	/******* VCU  ***********************/
	0x18FECA2F,//0
	0x1CEBFF2F,//1
	0x0CFE5A2F,//2
    0x18FF8001,//3
    0x0CFF0C4A,//4
    0x0CFF0D4A,//5
    0x18FF2D47,//6
    0x18FF2E47,//7
    0X18FF064A,//8
    0X18FF0152,//9
    0X18FF3047,//10
    0X18FF3147,//11
    0X18FF3247,//12
    0x18FF2C47,//13
    0x18FF2848,//14
    0x18FF2948,//15
    0x18FF2A48,//16
    0x18FF2B48,//17
    0x18FF2E48,//18
    0x18FF2F48,//19
    0x18FF0257,//20
    0x0CFFEB4A,//21
    0x18FF2C48,//22
    0x18FF5A52,//23
    0x18FF2D48,//24
    0x18FF2B49,//25
    0x104C1A08,//26
    0x104C1A09,//27
    0x104C1A18,//28
    0x104C1A19,//29
    0x0CFF324A,//30
    0x0CFF0A4A,//31
    0x0CFF0B4A,//32
    0x18F0010B,//33
    0x0CFF104A,//34
    0x18ff0258,//35
    0x18ff5b52,//36
    //协议转发部分
	0x0CFF114A,//37
	0x10FFC19E,//38
	0x10FFC09E,//39
	0x18FF45F4,//40
	0x18FFC13A,//41
	0x18FF3447,
	//PCAN2 接收报文 C7,C8 CAN
	0x10FFC29E,
	//PCAN3 C16,C17接线,未用到
	//------------------------------安凯新增
	0x18FF0498,
	0x18FDC40B,
	0x0CFF0F4A,
};

#define CAN_DATA_MAX  (sizeof(CanIdTable)/sizeof(CanIdTable[0]))
#define CAN_ID_SUM   ((sizeof(CanIdTable)/sizeof(CanIdTable[0])))

volatile uint8_t CanData[CAN_DATA_MAX][8];
volatile uint8_t timeout[CAN_DATA_MAX];

//数据清零
void ClearData(u8* data,u8 ns)
{
    int i;
    for(i=0; i<ns; i++)
    {
        *data++ = 0;
    }
}

uint16_t GetIndexFromID(uint32_t id)
{
	uint16_t i;
	for(i=0;i<CAN_ID_SUM;i++)
	{
		if(CanIdTable[i] == id)
			return i;
	}
	return CAN_ID_SUM;
}

u16 ID(u32 id)
{
	u16 i;
	for(i=0;i<CAN_ID_SUM;i++)
	{
		if(CanIdTable[i] == id)
			return i;
	}
	return CAN_ID_SUM;
}

u32 GetIDFromIndex(u16 index)
{
	if(index<CAN_ID_SUM)
	{
		return CanIdTable[index];
	}
	else
	{
		return 0;
	}
}
//获取ID
u32 GetID(CAN_MessageTypeDef CAN_MessageStructrue)
{
   volatile u32 id = 0;
   if(CAN_MessageStructrue.m_FrameFormat == CAN_FRAME_FORMAT_EFF)//id
   	id = CAN_MessageStructrue.m_ExtendedID;
   else
   	id = CAN_MessageStructrue.m_StandardID;
   return id;
}

void GeCantData(CAN_MessageTypeDef CAN_MessageStructrue,volatile u8 *data)
{
  u8 i = 0;
  for(i = 0;i < CAN_MessageStructrue.m_DataLength;i++)
  {
	data[i] = CAN_MessageStructrue.m_Data[i];
  }
}




void ClearCanData(u32 id)
{
    u16 battery_id,many_single,i;

    switch(id)
    {
    	case 0x0CFF0C4A:
			_0CFF0C4A[4] = 0X30;
			_0CFF0C4A[5] = 0X75;
			break;
		case 0x0CFF0D4A:
			_0CFF0D4A[4] = 125;
			break;
		case 0x0CFF104A:
			break;
        case 0X18FF064A:
            add[0] = 0;
            add[1] = 0;
            errcodemix[2] = 0xFF;
            break;
		case 0X18FF0152:
			Add_Comm.byte = 0;
        break;
		case 0X18FFC13A:
			can_water_low = 0;
		break;	

        case 0X18FF3047:
            add[2] = 0;
            add[3] =0;
            errcodemix[3] = 0xFF;
            break;
        case 0X18FF3147:
            add[4] = 0;
            add[5] = 0;
            errcodemix[4] = 0xFF;
            break;

        case 0X18FF3247:
            add[6] = 0;
            add[7] = 0;
            errcodemix[5] = 0xFF;
            break;
		case 0x18FF3447:
            add[8] = 0;
            add[9] = 0;
            errcodemix[6] = 0xFF;
            break;
        case 0x10ffc09e:
			//for(i = 0;i < 8;i++)
			//	air_con[i].byte = 0;
			//air_con[3].byte = 60;
			//air_con[4].byte = 60;
			break;
			
            case 0x18FF8001:
                Low_Buzz.byte = 0;
                break;	
				
        case 0x18FEF4D8:

            break;
        case 0x18FF2D47:
            batt_time = 0;
            WaterTem = 40;
            motor_tem = 40;
            motor_flag = 0;
            ID_18FF2D47_data6 = 0;
            eng_speed = 0;
            veh_speed = 0;
        //    speed_life = 0;
            ID_18FF2D47_data5 = 0;
            errcodemix[1] = 0xFF;
			veh_speed_display = 0;
            break;

        case 0x18FF2E47:
            motor_pow[0] = 0;
            motor_pow[1] = 0;
            motor_pow[2] = 0;
            motor_pow[3] = 0;
            break;


        case 0x18FF2C47:
            elec_time = 0;
            motor_torque  = 32000;
            motor_dc_volt = 0;
            motor_dc_curr = 32000;
            motor_state = 0;
            break;


        case 0x18FF2848:
            Battery_System_Volt = 0;
            Battery_Charge_Curr = 32000;
            battery_1_data6 = 0;
            ID_18FF2848_data5 = 0;
            battery_1_soc = 0;
			veh_soc = 0;
            ID_18FF2848_data7 = 0;
            break;

        case 0x18FF2948:
            Box_High_Temp = 40;
            Temp_jicha = 0;
            Battery_High_Volt = 0;
            Battery_Low_Volt  = 0;
            ID_18FF2948_data6 = 0;
            break;

        case 0x18FF2A48:
            Temp_Positive = 0;
            Remain_Energy = 0;
            ID_18FF2A48_data2 = 0;
            ID_18FF2A48_data1 = 0;
            ID_18FF2A48_data0 = 0;
            ID_18FF2A48_data5 = 0;
            errcodemix[0] = 0xFF;
            break;

        case 0x18FF2B48:
            Battery_fang_Curr = 32000;
            Battery_chong_Curr  = 32000;
			for(i = 0; i<8; i++)
				_18ff2b48[i] = 0;
            break;

        case 0x18FF2E48:
            ID_18FF2E48_data0 = 0;
            ID_18FF2E48_data1 = 0;
            ID_18FF2E48_data2 = 0;
            ID_18FF2E48_data3 = 0;
            Battery_2_Remain_enery = 0;
            break;

        case 0x18FF2F48:
            Battery_chong_Curr_1 = 0;
            Battery_fang_Curr_1  = 0;
            break;

        case 0x18FF0257:
            for(i = 0; i<8; i++)
                ID_18ff0257_data[i] = 0;
            break;


        case 0x0CFFEB4A:
            any_Remain_time = 0;
            electric_shake = 0;
            veh_scr = 0;
            Charge_Remain_time = 0xFFFF;
            break;

        case 0x18FF2C48:
            ID_18FF2C48_data5 = 0;
            battery_2_data6 = 0;
            battery_2_soc = 0;
            battery_2_system_volt = 0;
            battery_2_system_curr = 0;
            break;

        case 0x18FF5A52:
            fog_alarm[3]= 0;
            fog_alarm[2]= 0;
            fog_alarm[1]= 0;
            fog_alarm[0]= 0;
            break;


        case 0x18FF2D48:
            ID_18FF2D48_data6 = 0;
            ID_18FF2D48_data5 = 0;
            ID_18FF2D48_data4 = 0;
            Battery_2_single_high_volt = 0;
            Battery_2_single_low_volt  = 0;
            break;

        case 0x18FF2B49:
            insulate_value = 0;
            insulate_flag  = 0;
            break;

        case 0x104C1A08:
            Model_Temperure[0] = 40;
            Model_Temperure[2] = 40;
            Model_Temperure[4] = 40;
            Model_Temperure[6] = 40;
            break;

        case 0x104C1A09:
            Model_Temperure[8]  =40;
            Model_Temperure[10] =40;
            Model_Temperure[12] =40;
            Model_Temperure[14] =40;
            break;

        case 0x104C1A18:
            Model_Temperure[1] = 40;
            Model_Temperure[3] = 40;
            Model_Temperure[5] = 40;
            Model_Temperure[7] = 40;
            break;

        case 0x104C1A19:
            Model_Temperure[9]  = 40;
            Model_Temperure[11] = 40;
            Model_Temperure[13] = 40;
            Model_Temperure[15] = 40;
            break;

        case 0x0CFF324A:
            Drive_mile  = 0;
            Single_mile = 0;
            break;

        case 0x0CFF0A4A:
            Control_information_data7 = 0;
            Control_information_data5 = 0;
            Control_information_data6 = 0;
            Control_information_data1 = 0;
            Control_information_data0 = 0;
            break;

        case 0x0CFF0B4A:
            ID_0CFF0B4A_data2 = 0;
            break;
        case 0x18F0010B:
			for(i=0;i<8;i++)
				_18F0010B[i] = 0;
			abs_fault = 0;
            break;
        case 0x18ff0258:
            FaultAlarmAdd = 0;
            break;
        case 0x18ff5b52:
            for(i = 0; i < 8; i++)
                add_fog[i].byte = 0;
            break;
		case 0x18FF0498:
            _18FF0498_data7 = 0;
            break;
		case 0x18FDC40B:
			for(i=0;i<8;i++)
				_18FDC40B[i] = 0;
            break;
  }
}

#define CellBatIDNum 0

void CopyData(volatile uint8_t *Des,volatile uint8_t *Souc,uint8_t n)
{
   uint8_t i;
   for(i = 0;i < n;i++)
   	Des[i] = Souc[i];
}


void ClearCanDataManage(void)
{
    u8 i;
    for(i = 0; i< (CAN_DATA_MAX); i++)
    {
        if((i == GetIndexFromID(0x18FF0257))||(i == GetIndexFromID(0x18FF2B49))||(i == GetIndexFromID(0x18FF5A52))||(i == GetIndexFromID(0x18ff5b52)))
        {
            if(timeout[i] > 100)
            {
                ClearCanData(GetIDFromIndex(i));
            }
            else
            {
                timeout[i]++;
            }
        }
        else
        {
            if(timeout[i] > 50)
            {
                ClearCanData(GetIDFromIndex(i));
            }
            else
            {
                timeout[i]++;
            }
        }
    }

}



void ReceCan(uint32_t id,volatile uint8_t *data)
{
   volatile static uint32_t sp1,sp2;
   volatile static uint16_t sp3,SP4;
   u32 temp = 0;

	switch(id)
	{
	    case 0x10FFC29E:
			CopyData(_10FFC29E,data,8);
			_10FFC29E_FLAG = 1;
		break;
		case 0X18FF3447:  
			add[8] = data[0];
			add[9] = data[7];
			if (JudgeMAInBuff(DIYA_MA, add[9]))
			{
				DIYA_MA[DIYA_Index++] = add[9];
			}
		
			errcodemix[6] = errcodemix[6] < add[9] ? errcodemix[6] : add[9];
		
			break;

		case 0x18FECA2F:
			_18FECA2F = data[0];

			break;
		case 0x1CEBFF2F:
			 _1CEBFF2F = data[1];
			break;	
		 case 0x0CFE5A2F:
			_0CFE5A2F_data1 = data[0];
			_0CFE5A2F_data4 = data[3];
			 break; 					
		 case 0x18FF8001:
			 CopyData(_18FF8001,data,8);
			 _18FF8001_FLAG = 1;  
			 Low_Buzz.byte = data[0];
			 break;
		 case 0x0CFF0C4A:
			  CopyData(_0CFF0C4A,data,8);
			 break;
		 case 0x0CFF0D4A:
			  CopyData(_0CFF0D4A,data,8);
			 break;
		 case 0x18FF2D47:
			 CopyData(_18FF2D47,data,8);
			 _18FF2D47_FLAG = 1;  
			 batt_time = 0;
			 WaterTem = data[0];
			 motor_tem = data[1];
			 motor_flag = data[7];
			 ID_18FF2D47_data6 = data[6];
			 
			 ID_18FF2D47_data5 = data[5];
			 #if 1
			 if(JudgeMAInBuff(MOTOR_MA,ID_18FF2D47_data5))
			 {
				MOTOR_MA[MOTOR_Index++] = ID_18FF2D47_data5;
			 }

			 errcodemix[1] = errcodemix[1] < ID_18FF2D47_data5 ? errcodemix[1] : ID_18FF2D47_data5;
			 #endif
			 eng_speed = (u16)(data[3] << 8) + data[2];

			 if(eng_speed >= 6000)
				 eng_speed = 6000;

			 SP4 = (odometer_const);
			 sp3 = eng_speed;
			 sp1 = (float)((float)sp3 * 60);
			 sp2 = ((sp1 * 10)/(unsigned long)SP4);
			 if(sp2 >= 1400)
				 sp2 = 1400;
			 veh_speed = sp2;
			 veh_speed_display =  (veh_speed*0.01)*Oil_Alarm;
			 speed_life = 0;
			 break;
		 case 0x18FF2E47:
			 motor_pow[0] = (u16)(data[5] << 8) + data[4];
			 motor_pow[1] = (u16)(data[3] << 8) + data[2];
			 motor_pow[2] = (u16)(data[1] << 8) + data[0];
			 motor_pow[3] = (u16)(data[7] << 8) + data[6];
			 break;
			 
		 case 0X18FF064A:
			 CopyData(_18FF064A,data,8);
			 _18FF064A_FLAG = 1;   
			 add[0] = data[7];
			 add[1] = data[3];
			 
			 #if 1
			 if(JudgeMAInBuff(VCU_MA,add[1]))
			 {
				VCU_MA[VCU_Index++] = add[1];
			 }
			 
			 errcodemix[2] = errcodemix[2] < add[1] ? errcodemix[2] : add[1];
			 #endif
			 
			 break;
		 case 0X18FF0152:
			 CopyData(_18FF0152,data,8);
			 _18FF0152_FLAG = 1;
			 Add_Comm.byte = data[0];
		 break;
	 case 0X18FF3047:
		 CopyData(_18FF3047,data,8);
		 _18FF3047_FLAG = 1;	
		 add[2] = data[0];
		 add[3] = data[6];

		 #if 1
		 if(JudgeMAInBuff(TURN_MA,add[3]))
		 {
			TURN_MA[TURN_Index++] = add[3];
		 }
		 errcodemix[3] = errcodemix[3] < add[3] ? errcodemix[3] : add[3];
		 #endif
		 break;
	 case 0X18FF3147:
		 CopyData(_18FF3147,data,8);
		 _18FF3147_FLAG = 1;   
		 add[4] = data[0];
		 add[5] = data[6];
		 #if 1
		 if(JudgeMAInBuff(DAQI_MA,add[5]))
		 {
			DAQI_MA[DAQI_Index++] = add[5];
		 }
		 errcodemix[4] = errcodemix[4] < add[5] ? errcodemix[4] : add[5];
		 #endif
		 break;
	 case 0X18FF3247:
		 CopyData(_18FF3247,data,8);
		 _18FF3247_FLAG = 1;	
		 add[6] = data[0];
		 add[7] = data[7]>>3;

		 #if 1
		 if(JudgeMAInBuff(XIAOQONG_MA,add[7]))
		 {
			XIAOQONG_MA[XIAOQONG_Index++] = add[7];
		 }
		 errcodemix[5] = errcodemix[5] < add[7] ? errcodemix[5] : add[7];
		 #endif
		 break; 		 
	 case 0x18FF2C47:
		 CopyData(_18FF2C47,data,8);
		 _18FF2C47_FLAG = 1;
		 elec_time = 0;
		 motor_torque  = (u16)(data[7] << 8) + data[6];
		 motor_dc_volt = (u16)(data[5] << 8) + data[4];
		 motor_dc_curr = (u16)(data[3] << 8) + data[2];
		 motor_state = data[0];
		 break;
	 case 0x18FF2848:
		 Battery_System_Volt = (u16)(data[1] << 8) + data[0];
		 Battery_Charge_Curr = (u16)(data[3] << 8) + data[2];
		 battery_1_data6 = data[6];
		 ID_18FF2848_data5 = data[5];
		 veh_soc = data[4]*0.4;
		 if(veh_soc>100)
			 veh_soc = 100;
		 ID_18FF2848_data7 = data[7];
		 CopyData(_18FF2848,data,8);
		 _18FF2848_FLAG = 1;				 
		 break;
	 case 0x18FF2948:
		 CopyData(_18FF2948,data,8);
		 Box_High_Temp = data[4];
		 Temp_jicha = data[5];
		 Battery_High_Volt = (u16)(data[3] << 8) + data[2];
		 Battery_Low_Volt  = (u16)(data[1] << 8) + data[0];
		 ID_18FF2948_data6 = data[6];
		 Battery_Total_Count = data[7];
		 _18FF2948_FLAG = 1;
		 break;
	 case 0x18FF2A48:
		 CopyData(_18FF2A48,data,8);
		 Temp_Positive = data[3];
		 Remain_Energy = (u16)(data[7] << 8) + data[6];
	 
		 ID_18FF2A48_data5 = data[5];

		 #if 1
		 if(JudgeMAInBuff(BMS_MA,data[5]))
		 {
			BMS_MA[BMS_Index++] = data[5];
		 }
		 errcodemix[0] = errcodemix[0] < ID_18FF2A48_data5 ? errcodemix[0] : ID_18FF2A48_data5;
		 #endif
		 ID_18FF2A48_data2 = data[2];
		 ID_18FF2A48_data1 = data[1];
		 ID_18FF2A48_data0 = data[0];
		 _18FF2A48_FLAG = 1;
		 break;
		 
	 case 0x18FF2B48:
	 	 CopyData(_18ff2b48,data,8);
		 Battery_fang_Curr = ((u16)data[7] << 8) + data[6];
		 Battery_chong_Curr  = ((u16)data[5] << 8) + data[4];	 
		 b_postion = data[0];
		 break;

	case 0x18FF2E48:
		ID_18FF2E48_data0 = data[0];
		ID_18FF2E48_data1 = data[1];
		ID_18FF2E48_data2 = data[2];
		ID_18FF2E48_data3 = data[3];
		Battery_2_Remain_enery = (u16)(data[7] << 8) + data[6];
		break;
		
	case 0x18FF2F48:
		Battery_chong_Curr_1 = (u16)(data[7] << 8) + data[6];
		Battery_fang_Curr_1  = (u16)(data[5] << 8) + data[4];
		break;
		
	case 0x18FF0257:
		CopyData(ID_18ff0257_data,data,8);
		 _18FF0257_FLAG = 1;
		break;
		
	case 0x0CFFEB4A:
		CopyData(_0CFFEB4A,data,8);
		Aver_Dianhao = data[7];
		any_Remain_time = 0;
		electric_shake = data[5];
		Charge_Remain_time = (u16)(data[4] << 8) + data[3];
		veh_scr = data[0];
		Ankai_Add_190703.byte = data[2];   
		_0CFFEB4A_FLAG = USED;
		break;
	case 0x18FF2C48:
		ID_18FF2C48_data5 = data[5];
		battery_2_data6 = data[6];
		battery_2_soc = data[4];
		battery_2_system_volt = (u16)(data[1] << 8) + data[0];
		battery_2_system_curr = (u16)(data[3] << 8) + data[2];
		break;
		
	case 0x18FF5A52:
		CopyData(_18FF5A52,data,8);
		fog_alarm[3]= data[3];
		fog_alarm[2]= data[2];
		fog_alarm[1]= data[1];
		fog_alarm[0]= data[0];
		_18FF5A52_FLAG = 1; 				
		break;
		
	case 0x18FF2D48:
		ID_18FF2D48_data6 = data[6];
		ID_18FF2D48_data5 = data[5];
		ID_18FF2D48_data4 = data[4];
		Battery_2_single_high_volt = (u16)(data[3] << 8) + data[2];
		Battery_2_single_low_volt  = (u16)(data[1] << 8) + data[0];
		break;

	case 0x18FF2B49:
		CopyData(_18FF2B49,data,8);
		insulate_value = (u16)(data[1] << 8) + data[2];
		insulate_flag  = data[0];
		Life = data[7];

		_18FF2B49_FLAG = 1;
		break;
	case 0x104C1A08: //最高温度低字节
		Model_Temperure[0] = data[0];
		Model_Temperure[2] = data[2];
		Model_Temperure[4] = data[4];
		Model_Temperure[6] = data[6];
		break;

	case 0x104C1A09:
		Model_Temperure[8]	= data[0];
		Model_Temperure[10] = data[2];
		Model_Temperure[12] = data[4];
		Model_Temperure[14] = data[6];
		break;

	case 0x104C1A18:
		Model_Temperure[1] = data[0];
		Model_Temperure[3] = data[2];
		Model_Temperure[5] = data[4];
		Model_Temperure[7] = data[6];
		break;

	case 0x104C1A19:
		Model_Temperure[9]	= data[0];
		Model_Temperure[11] = data[2];
		Model_Temperure[13] = data[4];
		Model_Temperure[15] = data[6];
		break;
		
	case 0x0CFF324A:
		Drive_mile	 = (u16)(data[7] << 8) + data[6];
		_0CFF324A_FLAG = 1; 				

		break;
	case 0x0CFF0A4A:
		CopyData(_0CFF0A4A,data,8);
		Control_information_data7 = data[7];
		Control_information_data6 = data[6];
		Control_information_data5 = data[5];
		Control_information_data1 = data[1];
		Control_information_data0 = data[0];
		_0CFF0A4A_FLAG = 1;
		break;
		
	case 0x0CFF0B4A:
		CopyData(_0CFF0B4A,data,8);
		ID_0CFF0B4A_data2 = data[2];
		_0CFF0B4A_FLAG = 1; 				
		break;
		
	case 0x18F0010B:
		CopyData(_18F0010B,data,8);
		abs_fault = data[0];
		break;
		
	case 0x0CFF104A:
		ChargingRelay = data[6];
		Break_Pent = data[4]*0.4;
		jiasu = data[5];
		jiansu = data[4];
		dian_nuanfeng = (data[0] & 0x20);
		break;
		
	case 0x18ff0258:
		CopyData(_18FF0258,data,8);
		_18FF0258_FLAG = 1;
		FaultAlarmAdd = data[0];
		break;
	case 0x18ff5b52:
		CopyData(_18FF5B52,data,8);
		_18FF5B52_FLAG = 1;
		for(temp = 0; temp < 8; temp++)
			add_fog[temp].byte= data[temp];
		break;
	case 0x0CFF114A:   
		CopyData(_0CFF114A,data,8);
		_0CFF114A_FLAG = 1;
		break;
	case 0x10FFC19E:	
		CopyData(_10FFC19E,data,8);
		_10FFC19E_FLAG = 1;
		break;
	case 0x10FFC09E:   
		CopyData(_10FFC09E,data,8);
		_10FFC09E_FLAG = 1;
		break;
	case 0x18FF45F4:  
		CopyData(_18FF45F4,data,8);
		_18FF45F4_FLAG = 1;
		break;
	case 0x18FFC13A:   
		CopyData(_18FFC13A,data,8);
		_18FFC13A_FLAG = 1;
		can_water_low = (_18FFC13A[7]&0x3f);
		break;
	case 0x18FF0498:
        _18FF0498_data7 = data[7];
        break;

	#if ANKAI_ABS
	case 0x18FDC40B:
        CopyData(_18FDC40B,data,8); //	最高温度所在位置
        break;

	#endif 
	
	default:
		 break;
	}
}


static volatile uint8_t Pcandata[8] = {0,0,0,0,0,0,0,0};
//CAN0接收函数 C5,C6
void Can0_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue)
{
   u32 id = 0;
   volatile uint16_t index = 0;
   id = GetID(CAN_MessageStructrue);
   index = GetIndexFromID(id);
   if(index < CAN_ID_SUM)
   {
	   //timeout 清零   动作未加入
	   timeout[index] = 0;
	   GeCantData(CAN_MessageStructrue,CanData[index]);
	   GeCantData(CAN_MessageStructrue,Pcandata);
       ReceCan(id,Pcandata);
   }
}


//C7,C8can接收函数
void Can1_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue)
{
   u32 id = 0;
   uint16_t index = 0;
   id = GetID(CAN_MessageStructrue);
   index = GetIndexFromID(id);
   if(index < CAN_ID_SUM)
   {
	   //timeout 清零	动作未加入
	   timeout[index] = 0;
	   GeCantData(CAN_MessageStructrue,CanData[index]);
	   GeCantData(CAN_MessageStructrue,Pcandata);
       ReceCan(id,Pcandata);	   
   }
}

//C16 C17can接收函数
void Can2_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue)
{
   u32 id = 0;
   volatile uint16_t index = 0;
   id = GetID(CAN_MessageStructrue);
   index = GetIndexFromID(id);
   if(index < CAN_ID_SUM)
   {
	   //timeout 清零	动作未加入
	   GeCantData(CAN_MessageStructrue,CanData[index]);
	   GeCantData(CAN_MessageStructrue,Pcandata);
	   ReceCan(id,Pcandata);
   }
}







































