/*
 * canreceive.c
 *
 *  Created on: 2021-8-6
 *      Author: ART
 */

#include "system_init.h"


const uint32_t PCan1IdTable[] =
{
	//---高压报文
	0x0C079AA7,
	0x0C08A79A,
	0x1800D0A8,	
	0x1801D0A8,
	0x1800D0A9,
	0x0C0AA79D,
	0x0c03a1a7,
	0x0c04a1a7,
	0x0c06a1a7,
	0x0c07a1a7,
	0x0c08a1a7,
	0x0c09a1a7,
	0x0c0aa1a7,
	0x0c0aa7f0,
	0x0C08A7F4,
	0x0c01a70a,
	0x1818d0f3,
	0x1819d0f3,
	0x181ad0f3,
	0x181bd0f3,
	0x181cd0f3,
	0x181dd0f3,
	0x181ed0f3,
	0x180028f3,
	0x180128f3,
	0x180228f3,
	0x180328f3,
	0x180428f3,
	0x180028f4,
	0x180128f4,
	0x180228f4,
	0x0c02a70a,
	0x0c03a70a,
	0x18FFC13A,
	0x18FFF7F6,
	0x18FFA898,
	0x18FE521E,
	#if 0
	//---ECAS报文
	0x0CFE5A2F,//符号片
	0x18FECA2F,//故障码单包
	0x1CECFF2F,//故障码多包
	0x1CEBFF2F,//故障码多包
	#endif
	//中控屏信息
	0x18FA0118,
	0x18FEF433,
	0x0C02F4A7,
	0x0C09A7F4
};

#define PCAN1_DATA_MAX  (sizeof(PCan1IdTable)/sizeof(PCan1IdTable[0]))
#define PCAN1_ID_SUM   ((sizeof(PCan1IdTable)/sizeof(PCan1IdTable[0])))

volatile uint8_t CanData[PCAN1_DATA_MAX][8];
uint8_t timeout[PCAN1_DATA_MAX];

void  MemClr (volatile u8  *pdest,
                 u16  size)
{
    while (size > 0u) {
        *pdest++ = (u8)0;
        size--;
    }
}

void  MemCopy (volatile u8  *pdest,
               volatile u8  *psrc,
                        u16  size)
{
    while (size > 0u) {
        *pdest++ = *psrc++;
        size--;
    }
}

//数据清零
void ClearData(volatile u8* data,u8 ns)
{
    int i;
    for(i=0; i<ns; i++)
    {
        *data++ = 0;
    }
}

uint16_t Pcan1GetIndexFromID(uint32_t id)
{
	uint16_t i;
	for(i=0;i<PCAN1_ID_SUM;i++)
	{
		if(PCan1IdTable[i] == id)
			return i;
	}
	return PCAN1_ID_SUM;
}

u16 Pcan1ID(u32 id)
{
	u16 i;
	for(i=0;i<PCAN1_ID_SUM;i++)
	{
		if(PCan1IdTable[i] == id)
			return i;
	}
	return PCAN1_ID_SUM;
}

u32 Pcan1GetIDFromIndex(u16 index)
{
	if(index<PCAN1_ID_SUM)
	{
		return PCan1IdTable[index];
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
    u16 index;
	u8 i;
	static u8 clear_alarm[2];
	index = GetIndexFromID(id);
	ClearData(CanData[index],8);

    switch(id)
    {
    	case 0x0C079AA7:
			FLAG_0X0C079AA7 = 0;
			ClearData(DCDC1,8);
			break;
		
		case 0x0c08a79a:
			DC_DC.voltage_out = 10000;
			DC_DC.current = 10000;
			DC_DC.voltage_input = 10000;
			DC_DC.temp = 40;
			DC_DC.faultcode = 0;
			break;
		case 0x1800D0A8:
			 for(index = 0;index < 8;index++)
				 add1[index].byte = 0;
			 break;
		case 0x1801D0A8:
			 for(index = 0;index < 8;index++)
				 add2[index].byte = 0;
			 break;  
		case 0x1800D0A9:
			 for(index = 0;index < 8;index++)
				 add3[index].byte = 0;
			 break;
		case 0x0C0AA79D:
			FLAG_0X0C0AA79D = 0;
 		 	for(index = 0;index < 8;index++)
 				fuzhu[index].byte = 0;
 	    	break;
		case 0x0c03a1a7:
			MOTOR.ivoltage = 10000;
			MOTOR.icurrent = 10000; 		
			MOTOR.itorque= 32000;  
			MOTOR.ispeed = 0;
			eng_speed = 0; 
			veh_speed = 0;
			veh_speed_display = 0;
			break;
		case 0x0c04a1a7:
			FLAG_0X0C04A1A7 = 0;
			for(index = 0;index < 8;index++)
				_0C04A1A7_DATA[i] = 0;
			GEAR_FLAG = 0;
			MOTOR.itemp = 40;
			CONTROL.itemp = 40;
			MOTOR.etemp = 0;
			CONTROL.etemp = 0;
			DriverOperateStatus = 0;
			OnOffStatus = 0;
			SystemCode = 0;
			break;
		case 0x0c06a1a7:
			FLAG_0X0C06A1A7 = 0;
			for(index = 0;index < 8;index++)
				_0C06A1A7_DATA[i] = 0;
			STEP.ispeed_up = 0;
			STEP.ibraking = 0;
			oil_prss = 0;
			EngineInputAirTemp = 40;
			OilAccumulation = 0;
			break;
		case 0x0c07a1a7:
			ClearData(DebugData,8);
			break;
		case 0x0c08a1a7:
			shunshigonglv = 30000;
			FuelConsumption_Instant = 0;
			FuelConsumption_100KM_Subtotal = 0;
			FuelConsumption_100KM_Acctotal= 0;
			break;

		case 0x0c09a1a7:
			ClearData(VCUSofeVersion,8);
			break;
		case 0x0c0aa1a7:
			shengyugonglv = 30000;
			SystemMode = 0;
			SystemStatus = 0;
			break;
		case 0x0c0aa7f0:
			ClearData(ECUSofeVersion,8);
			break;
		case 0x0C08A7F4:
			for(index = 0;index < 8;index++)
				AIR[index].byte = 0;
			break;	
		case 0x0c01a70a:
			DrivingRange = 0;
			baigongli[0]= 0;
			baigongli[1]= 0;
			break;
		case 0x1818d0f3:
			BMS.ivoltage = 10000;		 
			BMS.icadc = 10000;		  
			BMS.isoc = 0;
			veh_soc = 0;
			BMS.istatus[0] = 0;
			BMS.istatus[1] = 0;
			BMS.istatus[2] = 0;
			break;
		case 0x1819d0f3:
			BMS.imax_charge = 10000;
			BMS.imax_discharge = 10000;
			BMS.isystem_fault = 0;
			BMS.iaverage_voltage = 0;
			BMS.imono_max_temp = 0;
			break;
		case 0x181ad0f3:
			BMS.itotal_anode_riso = 0;
			BMS.itotal_cathode_riso = 0;
			BMS.imono_max_voltage = 10000;		
			BMS.imono_min_voltage = 10000;
			break;

		case 0x181bd0f3:
			BMS.VIN = 0;
			BMS.status_flag4 = 0;
			BMS.ChargeOutletTemp1 = 40;
			BMS.ChargeOutletTemp2 = 40;
			BMS.ChargeOutletTemp3 = 40;
			BMS.ChargeOutletTemp4 = 40;
			BMS.error_total = 0;
			BMS.status_flag5 = 0;
			break;
		case 0x181cd0f3:
			BMS.rated_capacity = 0;
			BMS.rated_voltage = 0;
			BMS.battery_series_num = 0;
			BMS.battery_parallel_num = 0;
			BMS.temp_sensor_num = 0;
			break;	
		case 0x181dd0f3:
			
			BMS.imono_max_temp_2 = 40;
			BMS.maxtemp_pos_x = 0;
			BMS.maxtemp_pos_y = 0;
			BMS.imono_min_temp = 40;
			BMS.mintemp_pos_x = 0;
			BMS.mintemp_pos_y = 0;
			BMS.battery_typeinfo = 0;
			BMS.battery_cooling_methods = 0;
			break;
		case 0x181ed0f3:
			BMS.maxvol_pos_x = 0;
			BMS.maxvol_pos_y = 0;
			BMS.minvol_pos_x = 0;
			BMS.minvol_pos_y = 0;
			break;
		case 0x180028f3:
			ClearData(BmsMonoData[0],8);
			break;
		case 0x180128f3:
			ClearData(BmsMonoData[1],8);
			break;
		case 0x180228f3:
			ClearData(BmsMonoData[2],8);
			break;
		case 0x180328f3:
			ClearData(BmsMonoData[3],8);	 
			break;
		case 0x180428f3:
			ClearData(BmsMonoData[4],8);
			break;
		case 0x180028f4:		   
			BMS_MONO.isampl_number[0] = 0;
			BMS_MONO.itemp[0] = 40;
			BMS_MONO.isampl_number[1] = 0;
			BMS_MONO.itemp[1] = 40;
			BMS_MONO.isampl_number[2] = 0;
			BMS_MONO.itemp[2] = 40;
			BMS_MONO.isampl_number[3] = 0;
			BMS_MONO.itemp[3] = 40;
			break;
		case 0x180128f4:		   
			BMS_MONO.isampl_number[4] = 0;
			BMS_MONO.itemp[4] = 40;
			BMS_MONO.isampl_number[5] = 0;
			BMS_MONO.itemp[5] = 40;
			BMS_MONO.isampl_number[6] = 0;
			BMS_MONO.itemp[6] = 40;
			BMS_MONO.isampl_number[7] = 0;
			BMS_MONO.itemp[7] = 40;
			break;
		case 0x180228f4:
			BMS_MONO.isampl_number[8] = 0;
			BMS_MONO.itemp[8] = 40;
			BMS_MONO.isampl_number[9] = 0;
			BMS_MONO.itemp[9] = 40;
			break;
		case 0x0c02a70a:
			AlarmFlag[0] = 0;
			AlarmFlag[1] = 0;
			AlarmFlag[2] = 0;
			AlarmFlag[3] = 0;					
			break;
		case 0x0c03a70a:
			E_MotorError[0] = 0;
			E_MotorError[1] = 0;
			E_MotorError[2] = 0;
			E_MotorError[3] = 0;				
			break;
		//------------------------
		 
	   default:
			break;

    }
	/*if((clear_alarm[0] == 1)&&(clear_alarm[1] == 1))
	{
		clear_alarm[0] = 0;
		clear_alarm[1] = 0;
		MemClr(ECASFault,40);
	}*/
}

#define CellBatIDNum 0

volatile u8  Tot_packets,Const_0X20,temp_1;
volatile u32 pgn;

u8 get_faualt_bytes(u8 data)
{
	switch(data)
	{
		case 1:
			return 1;
			break;
		case 2:
			return 3;
		break;
		case 3:
			return 4;
			break;
		case 4:
			return 6;
			break;
		case 5:
			return 8;
			break;
		case 6:
			return 10;
			break;
		default:
			return 10;
			break;
	}
}

void CopyData(volatile uint8_t *Des,volatile uint8_t *Souc,uint8_t n)
{
   uint8_t i;
   for(i = 0;i < n;i++)
   	Des[i] = Souc[i];
}

/*********************************************
data_h can包数据高字节
data_l can包数据低字节
sort  小端模式大端模式两个值
*********************************************/
u16 GetU16From2U8(u8 data_h,u8 data_l,u8 sort)
{
	u16 tmp;
	if(sort == LITTLE_ENDIAN)
	{
		tmp = ((((uint16_t)data_h)<<8)+data_l);
	}
	else
	{
		tmp = (((uint16_t)data_l<<8)+data_h);
	}
	return tmp;
}
extern void CanRecvHook(u16 index);

void ClearCanDataManage(void)
{
    u8 i;
    for(i = 0; i< (PCAN1_DATA_MAX); i++)
    {
       
	    if(timeout[i] > 50)
	    {
	        ClearCanData(Pcan1GetIDFromIndex(i));
	    }
		else if(timeout[i] == 0)
		{
			CanRecvHook(i);
			timeout[i]++;
		}
	    else
	    {
	        timeout[i]++;
	    }

    }

}




static volatile uint8_t data[8] = {0,0,0,0,0,0,0,0};

void ReceCan(uint32_t id,volatile uint8_t *data)
{
	volatile static uint32_t sp1,sp2;
   volatile static uint16_t sp3,SP4;
   u32 temp = 0,index = 0;
   u8 tempu8;
   //index = GetIndexFromID(id);
   switch(id)
   {
        case 0x18FFC13A:
			 CanData[ID(0x18FFC13A)][5] = data[6];
			 CanData[ID(0x18FFC13A)][6] = data[5];
			 break;
        case 0x0C02F4A7:
			C7C8_TO_C5C6 = 1;
			break;
			
		case 0x0C09A7F4:
			C5C6_TO_C7C8 = 1;
			break;

		
		case 0x18FEF433:
			if(data[0] == 0x10)
				data[0] = 2;
			else if(data[0] == 0x11)
				data[0] = 3;
			else if(data[0] == 0x12)
				data[0] = 4;
			else if(data[0] == 0x13)
				data[0] = 5;
			else if((data[0] == 0) || (data[0] == 1))
			{
         
			}
			else 
			{
               break;
			}
				    

			taiya.yali[data[0]] = GetU16LE(data,1);
			taiya.wendu[data[0]] = data[3];
			taiya.fault_status[data[0]] = data[4];

			taiya.error[data[0]] = data[7];
			
			//if(data[0] == 0)
			//	taiya.fangbaotai[data[0]] = ((data[6] >> 7) & 0x01);
			//else if(data[0] == 1)
			//	taiya.fangbaotai[data[0]] = ((data[6] >> 6) & 0x01);
			break;
   
		case 0x0C079AA7:
				FLAG_0X0C079AA7 = 1;
				CopyData(DCDC1,data,8);
			break;
		case 0x0c08a79a:
			DC_DC.voltage_out = data[0]+((unsigned int)(data[1])<<8);
			DC_DC.current = data[2]+((unsigned int)(data[3])<<8);
			DC_DC.voltage_input = data[4]+((unsigned int)(data[5])<<8);
			DC_DC.temp = data[6];
			DC_DC.faultcode = data[7];
			break;
		case 0x1800D0A8:
			CanData[ID(0x1800D0A8)][BYTE2] = data[2];
			CanData[ID(0x1800D0A8)][BYTE3] = data[1];
			CanData[ID(0x1800D0A8)][BYTE4] = data[4];
			CanData[ID(0x1800D0A8)][BYTE5] = data[3];
			for(index = 0;index < 8;index++)
				add1[index].byte = data[index];
			break;
		case 0x1801D0A8:
			CanData[ID(0x1801D0A8)][BYTE3] = data[3];
			CanData[ID(0x1801D0A8)][BYTE4] = data[2];
			for(index = 0;index < 8;index++)
				add2[index].byte = data[index];
			break;	
		case 0x1800D0A9:
			CanData[ID(0x1800D0A9)][BYTE2] = data[2];
			CanData[ID(0x1800D0A9)][BYTE3] = data[1];
			CanData[ID(0x1800D0A9)][BYTE4] = data[4];
			CanData[ID(0x1800D0A9)][BYTE5] = data[3];
			for(index = 0;index < 8;index++)
				add3[index].byte = data[index];
			break;
		case 0x0C0AA79D:
			FLAG_0X0C0AA79D = 1;
			for(index = 0;index < 8;index++)
				fuzhu[index].byte = data[index];
			break;	
		case 0x0c03a1a7:				   
			MOTOR.ivoltage = data[0]+((unsigned int)(data[1])<<8);
			if(MOTOR.ivoltage > 19990)
				MOTOR.ivoltage = 19990;
			if(MOTOR.ivoltage < 10000)
				MOTOR.ivoltage = 10000;
			MOTOR.icurrent = data[2]+((unsigned int)(data[3])<<8);
			if(MOTOR.icurrent > 19990)
				MOTOR.icurrent = 19990;
			if(MOTOR.icurrent == 0)
				MOTOR.icurrent = 1;
			
			MOTOR.itorque= data[4]+((unsigned int)(data[5])<<8);
			if(MOTOR.itorque>35000)
				MOTOR.itorque = 35000;
			if(MOTOR.itorque<29000)
				MOTOR.itorque = 29000;
		  
			MOTOR.ispeed = data[6]+((unsigned int)(data[7])<<8);
			MOTOR.ispeed >>= 1;
			eng_speed = MOTOR.ispeed; 
			
			if(eng_speed >= 6000) 
				eng_speed = 6000;		   
			
			SP4 = (odometer_const * 0.95);
			sp3 = eng_speed;
			sp1 = (float)((float)sp3 * 60);
			sp2 = ((sp1 * 10)/(unsigned long)SP4);
			if(sp2 >= 1400)
			 sp2 = 1400;
			veh_speed = sp2;
			veh_speed_display =  (veh_speed*0.01)*Oil_Alarm; 			
		
			speed_life = 0;	
			break;
		case 0x0c04a1a7:
			FLAG_0X0C04A1A7 = 1;
			CopyData(_0C04A1A7_DATA,data,8); //
			GEAR_FLAG = 1;
			MOTOR.itemp = data[0];
			CONTROL.itemp = data[1];
			MOTOR.etemp = data[2];
			CONTROL.etemp = data[3];
			DriverOperateStatus = data[4];
			OnOffStatus = data[5];
			SystemCode = data[6]+((unsigned int)(data[7])<<8);
			if(SystemCode>10000)
				SystemCode = 10000;
			break;

		case 0x0c06a1a7:
			FLAG_0X0C06A1A7 = 1;
			CopyData(_0C06A1A7_DATA,data,8); //
			STEP.ispeed_up = data[0];
			STEP.ibraking = data[1];
			oil_prss = data[2]*4;
			EngineInputAirTemp = data[3];
			OilAccumulation = data[4] + ((u32)(data[5])<<8) +((u32)(data[6])<<16) + ((u32)(data[7])<<24);
			OilAccumulation >>=1;
			break;
		case 0x0c07a1a7:
			CopyData(DebugData,data,8);
			break;
		case 0x0c08a1a7:
			shunshigonglv = data[0]+((unsigned int)(data[1])<<8);
			FuelConsumption_Instant = data[3];
			FuelConsumption_100KM_Subtotal = data[4]+((unsigned int)(data[5])<<8);
			FuelConsumption_100KM_Acctotal= data[6]+((unsigned int)(data[7])<<8);
			break;
		case 0x0c09a1a7:
			CopyData(VCUSofeVersion,data,8); //电机控制器软件版本号
			CopyData(_0C09A1A7_DATA,data,8); //
			break;
		case 0x0c0aa1a7:
			SystemMode = data[0];
			SystemStatus = data[1];
			xuedimoshi   = data[2];
			qianyinli = data[3];
			shengyugonglv = data[4]+((unsigned int)(data[5])<<8);
			Motor_Current = (data[6]+((unsigned int)(data[7])<<8))/10;
			break;
		case 0x0c0aa7f0:
			CopyData(ECUSofeVersion,data,8); //					
			CopyData(_0C0AA7F0_DATA,data,8); //
			break;
		case 0x0C08A7F4:
			CopyData(_0C08A7F4_DATA,data,8); 
			for(index = 0;index < 8;index++)
				AIR[index].byte = data[index];
			break;
		case 0x0c01a70a:
			CopyData(_0C01A70A_DATA,data,8);
			DrivingRange = data[5];
			baigongli[0]  = data[6];
			baigongli[1] = data[7];
			break;
		case 0x1818d0f3:
			can_err_time = 0;
			CopyData(_1818D0F3_DATA,data,8);
			BMS.ivoltage = data[0]+((unsigned int)(data[1])<<8);
			if(BMS.ivoltage < 10000 )
				BMS.ivoltage = 10000;
			BMS.icadc = data[2]+((unsigned int)(data[3])<<8);
			if(BMS.icadc > 42767)
				BMS.icadc = 42767;
			BMS.isoc = data[4];
			veh_soc = data[4]*0.4;
			BMS.istatus[0] = data[5];
			BMS.istatus[1] = data[6];
			BMS.istatus[2] = data[7];
			break;
		case 0x1819d0f3:
			CopyData(_1819D0F3_DATA,data,8);
			BMS.imax_charge = data[0]+((unsigned int)(data[1])<<8);
			BMS.imax_discharge = data[2]+((unsigned int)(data[3])<<8);
			BMS.isystem_fault = data[4];
			BMS.iaverage_voltage = data[5]+((unsigned int)(data[6])<<8);
			if(BMS.iaverage_voltage < 10000)
				BMS.iaverage_voltage = 10000;
			if(BMS.iaverage_voltage > 42767)
				BMS.iaverage_voltage = 42767;
			BMS.imono_max_temp = data[7];
			break;
		case 0x181ad0f3:
			CopyData(_181AD0F3_DATA,data,8);
			
			BMS.itotal_anode_riso = data[0]+((unsigned int)(data[1])<<8);
			BMS.itotal_cathode_riso = data[2]+((unsigned int)(data[3])<<8);
			BMS.imono_max_voltage = data[4]+((unsigned int)(data[5])<<8);
			if(BMS.imono_max_voltage < 10000)
				BMS.imono_max_voltage = 10000;
			if(BMS.imono_max_voltage > 42767)
				BMS.imono_max_voltage = 42767;
			BMS.imono_min_voltage = data[6]+((unsigned int)(data[7])<<8);
			if(BMS.imono_min_voltage < 10000)
				BMS.imono_min_voltage = 10000;
			if(BMS.imono_min_voltage > 42767)
				BMS.imono_min_voltage = 42767;
			break;
		case 0x181bd0f3:
			CopyData(_181BD0F3_DATA,data,8);
			BMS.VIN = data[0];
			BMS.status_flag4 = data[1];
			BMS.ChargeOutletTemp1 = data[2];
			BMS.ChargeOutletTemp2 = data[3];
			BMS.ChargeOutletTemp3 = data[4];
			BMS.ChargeOutletTemp4 = data[5];
			BMS.error_total = data[6];
			BMS.status_flag5 = data[7];
			break;
		case 0x181cd0f3:
			CopyData(_181CD0F3_DATA,data,8);
			BMS.rated_capacity = data[0]+((unsigned int)(data[1])<<8);
			BMS.rated_voltage = data[2]+((unsigned int)(data[3])<<8);
			BMS.battery_series_num = data[4]+((unsigned int)(data[5])<<8);
			BMS.battery_parallel_num = data[6];
			BMS.temp_sensor_num = data[7];
			break;	
		case 0x181dd0f3:
			CopyData(_181DD0F3_DATA,data,8);
			BMS.imono_max_temp_2 = data[0];
			BMS.maxtemp_pos_x = data[1];
			BMS.maxtemp_pos_y = data[2];
			BMS.imono_min_temp = data[3];
			BMS.mintemp_pos_x = data[4];
			BMS.mintemp_pos_y = data[5];
			BMS.battery_typeinfo = data[6];
			BMS.battery_cooling_methods = data[7];
			break;
		case 0x181ed0f3:
			CopyData(_181ED0F3_DATA,data,8);
			BMS.maxvol_pos_x = data[0];
			BMS.maxvol_pos_y = data[1];
			BMS.minvol_pos_x = data[2];
			BMS.minvol_pos_y = data[3];
			break;
		case 0x180028f3:
			CanData[ID(0x180028f3)][BYTE2] = data[BYTE7];
			CanData[ID(0x180028f3)][BYTE3] = data[BYTE2];
			CanData[ID(0x180028f3)][BYTE4] = data[BYTE3];
			CanData[ID(0x180028f3)][BYTE5] = data[BYTE4];
			CanData[ID(0x180028f3)][BYTE6] = data[BYTE8];
			CanData[ID(0x180028f3)][BYTE7] = data[BYTE5];
			CanData[ID(0x180028f3)][BYTE8] = data[BYTE6];
			//CopyData(BmsMonoData[0],data,8);
			//CopyData(_180028F3_DATA,data,8);
			break;
		case 0x180128f3:
			CanData[ID(0x180128f3)][BYTE2] = data[BYTE7];
			CanData[ID(0x180128f3)][BYTE3] = data[BYTE2];
			CanData[ID(0x180128f3)][BYTE4] = data[BYTE3];
			CanData[ID(0x180128f3)][BYTE5] = data[BYTE4];
			CanData[ID(0x180128f3)][BYTE6] = data[BYTE8];
			CanData[ID(0x180128f3)][BYTE7] = data[BYTE5];
			CanData[ID(0x180128f3)][BYTE8] = data[BYTE6];
			//CopyData(BmsMonoData[1],data,8);
			//CopyData(_180128F3_DATA,data,8);
			break;
		case 0x180228f3:
			CanData[ID(0x180228f3)][BYTE2] = data[BYTE7];
			CanData[ID(0x180228f3)][BYTE3] = data[BYTE2];
			CanData[ID(0x180228f3)][BYTE4] = data[BYTE3];
			CanData[ID(0x180228f3)][BYTE5] = data[BYTE4];
			CanData[ID(0x180228f3)][BYTE6] = data[BYTE8];
			CanData[ID(0x180228f3)][BYTE7] = data[BYTE5];
			CanData[ID(0x180228f3)][BYTE8] = data[BYTE6];
			//CopyData(BmsMonoData[2],data,8); //	
			//CopyData(_180228F3_DATA,data,8);
			break;
		case 0x180328f3:
			CanData[ID(0x180328f3)][BYTE2] = data[BYTE7];
			CanData[ID(0x180328f3)][BYTE3] = data[BYTE2];
			CanData[ID(0x180328f3)][BYTE4] = data[BYTE3];
			CanData[ID(0x180328f3)][BYTE5] = data[BYTE4];
			CanData[ID(0x180328f3)][BYTE6] = data[BYTE8];
			CanData[ID(0x180328f3)][BYTE7] = data[BYTE5];
			CanData[ID(0x180328f3)][BYTE8] = data[BYTE6];
			//CopyData(BmsMonoData[3],data,8); //
			//CopyData(_180328F3_DATA,data,8);
			break;
		case 0x180428f3:
			CanData[ID(0x180428f3)][BYTE2] = data[BYTE7];
			CanData[ID(0x180428f3)][BYTE3] = data[BYTE2];
			CanData[ID(0x180428f3)][BYTE4] = data[BYTE3];
			CanData[ID(0x180428f3)][BYTE5] = data[BYTE4];
			CanData[ID(0x180428f3)][BYTE6] = data[BYTE8];
			CanData[ID(0x180428f3)][BYTE7] = data[BYTE5];
			CanData[ID(0x180428f3)][BYTE8] = data[BYTE6];
			//CopyData(BmsMonoData[4],data,8); //
			//CopyData(_180428F3_DATA,data,8);
			break;
		case 0x180028f4:
			CopyData(_180028F4_DATA,data,8);
			BMS_MONO.isampl_number[0] = data[0];
			BMS_MONO.itemp[0] = data[1];
			BMS_MONO.isampl_number[1] = data[2];
			BMS_MONO.itemp[1] = data[3];
			BMS_MONO.isampl_number[2] = data[4];
			BMS_MONO.itemp[2] = data[5];
			BMS_MONO.isampl_number[3] = data[6];
			BMS_MONO.itemp[3] = data[7];
			break;
		case 0x180128f4:
			CopyData(_180128F4_DATA,data,8);
			BMS_MONO.isampl_number[4] = data[0];
			BMS_MONO.itemp[4] = data[1];
			BMS_MONO.isampl_number[5] = data[2];
			BMS_MONO.itemp[5] = data[3];
			BMS_MONO.isampl_number[6] = data[4];
			BMS_MONO.itemp[6] = data[5];
			BMS_MONO.isampl_number[7] = data[6];
			BMS_MONO.itemp[7] = data[7];
			break;
		case 0x180228f4:		
			CopyData(_180228F4_DATA,data,8);
			BMS_MONO.isampl_number[8] = data[0];
			BMS_MONO.itemp[8] = data[1];
			BMS_MONO.isampl_number[9] = data[2];
			BMS_MONO.itemp[9] = data[3];
			break;
		case 0x0c02a70a:
			CopyData(_0C02A70A_DATA,data,8);
			AlarmFlag[0] = data[0];
			AlarmFlag[1] = data[1];
			AlarmFlag[2] = data[2];
			AlarmFlag[3] = data[3]; 				
			break;
		case 0x0c03a70a:
			CopyData(_0C03A70A_DATA,data,8);
			E_MotorError[0] = data[0];
			E_MotorError[1] = data[1];
			E_MotorError[2] = data[2];
			E_MotorError[3] = data[3];				
			break;
		case 0x18FFF7F6:
			if((data[0] == 0) || (data[0] >= 11))
				break;
			else
			{
				MIEHUO.box[data[0] - 1] = data[0];
				MIEHUO.type[data[0] - 1] = data[1];
				MIEHUO.alarm_level[data[0] - 1] = data[2];
				MIEHUO.fault_status[data[0] - 1] = data[3];
				MIEHUO.zifa_status[data[0] - 1] = data[4];
				MIEHUO.fault_code[data[0] - 1] = data[5];
				MIEHUO.rolling_count[data[0] - 1] = data[7];
			}
			break;
		//----------------------
		#if 0 
    	case 0x18FECA2F://ECAS故障(单个)
			ECASFault[0] = data[2];
			ECASFault[1] = data[3];
			ECASFault[2] = data[4];
			ECASFault[3] = data[5];
			MemClr(&ECASFault[4],36);
			break;
		case 0x1CECFF2F:
			Const_0X20  = data[0];//1 定值0x20
			Tot_packets = get_faualt_bytes(data[BYTE4]); //有效故障字节数
			Tot_packets = Tot_packets*4;
			break;
		case 0x1CEBFF2F:
			temp_1 = data[BYTE1];//序号
			if((Const_0X20 == 0x20) && (Tot_packets >= 4))
			{
				switch(temp_1)
				{
					case 0x01:
						MemCopy(ECASFault,&data[BYTE4],5);
						break;
					case 0x02:
						MemCopy(&ECASFault[5],&data[BYTE2],7);
						break;
					case 0x03:
						MemCopy(&ECASFault[12],&data[BYTE2],7);
						break;
					case 0x04:
						MemCopy(&ECASFault[19],&data[BYTE2],7);
						break;
					case 0x05:
						MemCopy(&ECASFault[26],&data[BYTE2],7);
						break;
					case 0x06:
						MemCopy(&ECASFault[33],&data[BYTE2],7);
						break;
					default:
						break;
				}
			}
			MemClr(&ECASFault[Tot_packets],40 - Tot_packets);
			break;
		#endif
		default:
			break;
	}
}

//CAN0接收函数 C5,C6
void Can2_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue)
{
   u32 id = 0;
   volatile uint16_t index = 0;
   id = GetID(CAN_MessageStructrue);
   index = Pcan1GetIndexFromID(id);
   pcan_off_line = 0;
   if(index < PCAN1_ID_SUM)
   {
	   //timeout 清零   动作未加入
	   timeout[index] = 0;
	   GeCantData(CAN_MessageStructrue,CanData[index]);
	   GeCantData(CAN_MessageStructrue,data);
       ReceCan(id,data);
   }
}


//CAN1接收函数  C7 C8
void Can3_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue)
{
   u32 id = 0;
   uint16_t index = 0;
   id = GetID(CAN_MessageStructrue);
   index = Pcan1GetIndexFromID(id);
   if(index < PCAN1_ID_SUM)
   {
	   //timeout 清零   动作未加入
	   timeout[index] = 0;
	   GeCantData(CAN_MessageStructrue,CanData[index]);
	   GeCantData(CAN_MessageStructrue,data);
	   ReceCan(id,data);	   
   }
}


//C16 C17
void Can4_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue)
{
   u32 id = 0;
   uint16_t index = 0;
   id = GetID(CAN_MessageStructrue);
   index = Pcan1GetIndexFromID(id);
   if(index < PCAN1_ID_SUM)
   {
	   //timeout 清零   动作未加入
	   GeCantData(CAN_MessageStructrue,CanData[index]);
	   GeCantData(CAN_MessageStructrue,data);
	   ReceCan(id,data);
   }
}














































