/*
 * canreceive.c
 *
 *  Created on: 2021-8-6
 *      Author: ART
 */

#include "system_init.h"

const uint32_t CanIdTable[] =
{
	0x0c03a1a7,
	0x0c04a1a7,
	0x0c05a1a7,
	0x0c06a1a7,
	0x0c07a1a7,
	0x0c08a1a7,
	0x0c09a1a7,
	0x0c0aa1a7,
	0x0c0aa7f0,
	0x1819a1a4,
	0x0c08a79a,
	0x0c09a79b,
	0x0c01a70a,
	0x0c02a70a,
	0x0c03a70a,	
	//0x0c08a7f4,
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
	0x18eba1a5,
	0x1819a100,
	0x0c0ca7f2,
	0x18efa1a5,
	0X180AA7A3,
	0x18FEF4D8,  
	0x0C08A7F4,
	0x0C0AA79D,
	0x18FFA898,
	0x18FE521E,
	0x1800D0A8,
	0x1801D0A8,
	0x1800D0A9,
	0x1CFF511E,
	0x18FE0010,
	0x18FF45F4,
	0x18FFC13A,
	0x0C079AA7,
	0x18FFF7F6,
	0x18FEF433,
};

#define CAN_DATA_MAX  (sizeof(CanIdTable)/sizeof(CanIdTable[0]))
#define CAN_ID_SUM   ((sizeof(CanIdTable)/sizeof(CanIdTable[0])))

volatile uint8_t CanData[CAN_DATA_MAX][8];
volatile uint8_t timeout[CAN_DATA_MAX];

void  MemClr (volatile uint8_t  *pdest,
		volatile uint16_t  size)
{
    while (size > 0u) {
        *pdest++ = (u8)0;
        size--;
    }
}

void  MemCopy (volatile uint8_t  *pdest,
		volatile uint8_t  *psrc,
		volatile uint16_t  size)
{
    while (size > 0u) {
        *pdest++ = *psrc++;
        size--;
    }
}

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


//数据清零
void ClearData(volatile u8* data,u8 ns)
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
    static u8 clear_alarm[2];
	u8 index;
    switch(id)
    {
		/*case 0x1CFF511E:
			for(index = 0;index < 2;index++)
				NTC[index] = 40;
		break;*/
		case 0x18FE521E:
			for(index = 0;index < 8;index++)
				PEIDIAN[index]= 0;
			break;
		case 0x18FFA898:
			for(index = 0;index < 8;index++)
				RUNHUA[index] = 0;
			break;
		case 0x18FF45F4:
			for(index = 0;index < 8;index++)
				shuileng1[index] = 0;
			break;
		case 0x18FFC13A:
			for(index = 0;index < 8;index++)
				shuileng2[index] = 0;
			break;
        case 0x180AA7A3:
 		 	for(index = 0;index < 8;index++)
 				YUN_TONG[index].byte = 0;
 	   	 	break;
		
        case 0x0C0AA79D:
 		 	for(index = 0;index < 8;index++)
 				fuzhu[index].byte = 0;
 	    	break;
		
        case 0x0C08A7F4:
			for(index = 0;index < 8;index++)
				AIR[index].byte = 0;
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
			GEAR_FLAG = 0;
			MOTOR.itemp = 40;
			CONTROL.itemp = 40;
			MOTOR.etemp = 0;
			CONTROL.etemp = 0;
			DriverOperateStatus = 0;
			OnOffStatus = 0;
			SystemCode = 0;
			break;
		case 0x0c05a1a7:
			EngineSpeed = 0;
			EngineWaterTemp = 40;
			EngineLoad = 0;
			scr = 0;
			EngineTatgetAccelerator = 0;
			EngineActualAccelerator = 0;
			VCU_Life = 0;
			break;
		case 0x0c06a1a7:
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
		case 0x0c0ca7f2:
			ClearData(EECUSofeVersion,8);
			break;
		case 0x0c0aa7f0:
			ClearData(ECUSofeVersion,8);
			break;
		case 0x1819a1a4:
			InsulationMonitorRes_Positive = 0;
			InsulationMonitorRes_Negative= 0;
			InsulationMonitorErrorLevel = 0;
			InsulationMonitorLife = 0;
			InsulationMonitorAlarm = 0;
			break;

		case 0x0c08a79a:
			DC_DC.voltage_out = 10000;
			DC_DC.current = 10000;
			DC_DC.voltage_input = 10000;
			DC_DC.temp = 40;
			DC_DC.faultcode = 0;
			break;

		case 0x0c09a79b:
			DC_AC.current_w = 10000;
			DC_AC.current_v = 10000;
			DC_AC.current_u = 10000;
			DC_AC.temp = 40;
			DC_AC.faultcode = 0;
			break;

		case 0x0c01a70a:
			DrivingRange = 0;
			baigongli[0]= 0;
			baigongli[1]= 0;
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

			
	/******************/
	/*
		case 0x0c08a7f4:
			AC.iload = 0;
			AC.iset_temp = 0;
			AC.iexternal_temp = 0;
			AC.iinternal_temp = 0;
			AC.iDC_value = 0;			
			AC.istatus = 0;
			AC.ilife = 0;
			break;
			*/
		case 0x1818d0f3:
			YELLOW_BAT_FLAG = 0;
			BMS.ivoltage = 10000;		 
			BMS.icadc = 10000;		  
			BMS.isoc = 0;
			Bat_Soc = 0;
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
		case 0x0C079AA7:
			ClearData(DCDC1,8);
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

		case 0x18eba1a5:
			Extinguisher.num = 0;
			Extinguisher.alarmlevel = 0;
			Extinguisher.faultcode = 0;
			break;

		case 0x1819a100:
			fire_alarm_status[0] = 0;
			fire_alarm_status[1] = 0;
			fire_alarm_status[2] = 0;
			fire_alarm_status[3] = 0;
			fire_alarm_system_status= 0;
			fire_alarm_life = 0;
			veh_scr = 0;					
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
		/*case 0x18FFF7F6:
			for(index = 0;index < 3;index++)
			{
				BAT_FIRE.box[index] = 0;
				BAT_FIRE.type[index] = 0;
				BAT_FIRE.status[index] = 0;
				BAT_FIRE.fault_code[index] = 0;
				BAT_FIRE.rollcounter = 0;
			}
			break;*/
		default:
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

        if(timeout[i] > 100)
        {
            ClearCanData(GetIDFromIndex(i));
        }
        else
        {
            timeout[i]++;
        }

    }

}



void ReceCan(uint32_t id,volatile uint8_t *data)
{
   volatile static uint32_t sp1,sp2;
   volatile static uint16_t sp3,SP4;
   u32 temp = 0;
   u8 index;
	switch(id)
	{
		case 0x0C079AA7:
				CopyData(DCDC1,data,8);
			break;
		case 0x18FF45F4:
				CopyData(shuileng1,data,8);
			break;
		case 0x18FFC13A:
				CopyData(shuileng2,data,8);
			break;
		case 0x1CFF511E:
			
			break;	
		case 0x0C08A7F4:
			CopyData(_0C08A7F4_DATA,data,8); 
			_0C08A7F4_FLAG = 1;
			for(index = 0;index < 8;index++)
				AIR[index].byte = data[index];
			break;
		case 0x180AA7A3:				
			CopyData(_180AA7A3_DATA,data,8); //
			_180AA7A3_FLAG = 1;		
			for(index = 0;index < 8;index++)
				YUN_TONG[index].byte = data[index];
			break;
		case 0x180BA7A3:
			CopyData(_180BA7A3_DATA,data,8); //
			_180BA7A3_FLAG = 1;		
			break;
		case 0x180CA7A3:
			CopyData(_180CA7A3_DATA,data,8); //
			_180CA7A3_FLAG = 1;		
			break;
		case 0x0C0AA79D:
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
			CopyData(_0C04A1A7_DATA,data,8); //
			_0C04A1A7_FLAG = 1;
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
		case 0x0c05a1a7:
			EngineSpeed = data[0] + (((unsigned int)(data[1]))<<8);
			EngineWaterTemp = data[2];
			EngineLoad = data[3];
			scr = data[4];
			EngineTatgetAccelerator = data[5];
			EngineActualAccelerator = data[6];
			VCU_Life = data[7];
			break;
		case 0x0c06a1a7:
			STEP.ispeed_up = data[0];
			STEP.ibraking = data[1];
			oil_prss = data[2]*4;
			EngineInputAirTemp = data[3];
			OilAccumulation = data[4] + ((u32)(data[5])<<8) +((u32)(data[6])<<16) + ((u32)(data[7])<<24);
			OilAccumulation >>=1;
			break;
		case 0x0c07a1a7:
			CopyData(DebugData,data,8);
			CopyData(_0C07A1A7_DATA,data,8); //
			_0C07A1A7_FLAG = 1;
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
			_0C09A1A7_FLAG = 1;
			break;
		case 0x0c0aa1a7:
			SystemMode = data[0];
			SystemStatus = data[1];
			xuedimoshi   = data[2];
			qianyinli = data[3];
			shengyugonglv = data[4]+((unsigned int)(data[5])<<8);
			Motor_Current = (data[6]+((unsigned int)(data[7])<<8))/10;
			break;
		case 0x0c0ca7f2:
			CopyData(EECUSofeVersion,data,8); //
			CopyData(_0C0CA7F2_DATA,data,8); //
			_0C0CA7F2_FLAG = 1;
			break;
		case 0x0c0aa7f0:
			CopyData(ECUSofeVersion,data,8); //					
			CopyData(_0C0AA7F0_DATA,data,8); //
			_0C0AA7F0_FLAG = 1;
			break;
		case 0x0C01F4A7:
			CopyData(_0C01F4A7_DATA,data,8); //
			_0C01F4A7_FLAG = 1;
			break;
		case 0x1819a1a4:
			InsulationMonitorRes_Positive = data[1]+((unsigned int)(data[0])<<8);
			InsulationMonitorRes_Negative= data[3]+((unsigned int)(data[2])<<8);
			InsulationMonitorErrorLevel = data[4];
			InsulationMonitorLife = data[5];
			InsulationMonitorAlarm = data[6];
			break;
		case 0x0c08a79a:
			DC_DC.voltage_out = data[0]+((unsigned int)(data[1])<<8);
			DC_DC.current = data[2]+((unsigned int)(data[3])<<8);
			DC_DC.voltage_input = data[4]+((unsigned int)(data[5])<<8);
			DC_DC.temp = data[6];
			DC_DC.faultcode = data[7];
			break;
		case 0x0c09a79b:
			DC_AC.current_w = data[0]+((unsigned int)(data[1])<<8);
			DC_AC.current_v = data[2]+((unsigned int)(data[3])<<8);
			DC_AC.current_u = data[4]+((unsigned int)(data[5])<<8);
			DC_AC.temp = data[6];
			DC_AC.faultcode = data[7];
			break;
		case 0x0c01a70a:
			CopyData(_0C01A70A_DATA,data,8);
			_0C01A70A_FLAG = 1;
			DrivingRange = data[5];
			baigongli[0]  = data[6];
			baigongli[1] = data[7];
			break;
		case 0x0c02a70a:
			CopyData(_0C02A70A_DATA,data,8);
			_0C02A70A_FLAG = 1;
			AlarmFlag[0] = data[0];
			AlarmFlag[1] = data[1];
			AlarmFlag[2] = data[2];
			AlarmFlag[3] = data[3]; 				
			break;
		case 0x0c03a70a:
			CopyData(_0C03A70A_DATA,data,8);
			_0C03A70A_FLAG = 1;
			E_MotorError[0] = data[0];
			E_MotorError[1] = data[1];
			E_MotorError[2] = data[2];
			E_MotorError[3] = data[3];				
			break;
		case 0x0C04A70A:	
			CopyData(_0C04A70A_DATA,data,8);
			_0C04A70A_FLAG = 1;
			break;
		case 0x1818d0f3:
			YELLOW_BAT_FLAG = 1;
			can_err_time = 0;
			CopyData(_1818D0F3_DATA,data,8);
			_1818D0F3_FLAG = 1;
			BMS.ivoltage = data[0]+((unsigned int)(data[1])<<8);
			if(BMS.ivoltage < 10000 )
				BMS.ivoltage = 10000;
			BMS.icadc = data[2]+((unsigned int)(data[3])<<8);
			if(BMS.icadc > 42767)
				BMS.icadc = 42767;
			BMS.isoc = data[4];
			Bat_Soc = data[4]*0.4;
			BMS.istatus[0] = data[5];
			BMS.istatus[1] = data[6];
			BMS.istatus[2] = data[7];
			break;
		case 0x1819d0f3:
			CopyData(_1819D0F3_DATA,data,8);
			_1819D0F3_FLAG = 1;
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
			_181AD0F3_FLAG = 1;
			
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
			_181BD0F3_FLAG = 1;
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
			_181CD0F3_FLAG = 1;
			BMS.rated_capacity = data[0]+((unsigned int)(data[1])<<8);
			BMS.rated_voltage = data[2]+((unsigned int)(data[3])<<8);
			BMS.battery_series_num = data[4]+((unsigned int)(data[5])<<8);
			BMS.battery_parallel_num = data[6];
			BMS.temp_sensor_num = data[7];
			break;	
		case 0x181dd0f3:
			CopyData(_181DD0F3_DATA,data,8);
			_181DD0F3_FLAG = 1;
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
			_181ED0F3_FLAG = 1;
			BMS.maxvol_pos_x = data[0];
			BMS.maxvol_pos_y = data[1];
			BMS.minvol_pos_x = data[2];
			BMS.minvol_pos_y = data[3];
			break;
		case 0x180028f3:
			CopyData(BmsMonoData[0],data,8);
			CopyData(_180028F3_DATA,data,8);
			_180028F3_FLAG = 1;
			break;
		case 0x180128f3:
			CopyData(BmsMonoData[1],data,8);
			CopyData(_180128F3_DATA,data,8);
			_180128F3_FLAG = 1;
			break;
		case 0x180228f3:
			CopyData(BmsMonoData[2],data,8); //	
			CopyData(_180228F3_DATA,data,8);
			_180228F3_FLAG = 1;
			break;
		case 0x180328f3:
			CopyData(BmsMonoData[3],data,8); //
			CopyData(_180328F3_DATA,data,8);
			_180328F3_FLAG = 1;
			break;
		case 0x180428f3:
			CopyData(BmsMonoData[4],data,8); //
			CopyData(_180428F3_DATA,data,8);
			_180428F3_FLAG = 1;
			break;
		case 0x180028f4:
			CopyData(_180028F4_DATA,data,8);
			_180028F4_FLAG = 1;
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
			_180128F4_FLAG = 1;
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
			_180228F4_FLAG = 1;
			BMS_MONO.isampl_number[8] = data[0];
			BMS_MONO.itemp[8] = data[1];
			BMS_MONO.isampl_number[9] = data[2];
			BMS_MONO.itemp[9] = data[3];
			break;
		case 0x0CFFF3A7:
			CopyData(_0CFFF3A7_DATA,data,8);
			_0CFFF3A7_FLAG = 1;
			break;
		case 0x0CFEEC21:
			CopyData(_0CFEEC21_DATA,data,8);
			_0CFEEC21_FLAG = 1;
			break;
		case 0x18eba1a5:	
			CopyData(_18EBA1A5_DATA,data,8);
			_18EBA1A5_FLAG = 1;
			Extinguisher.num = data[0];
			Extinguisher.alarmlevel = data[1];
			Extinguisher.faultcode = data[2];
			break;
		case 0x18efa1a5:
			CopyData(_18EFA1A5_DATA,data,8);
			_18EFA1A5_FLAG = 1;
			Extinguisher.timecalibration = 1;
			break;
		case 0x1819a100:
			CopyData(_1819A100_DATA,data,8);
			_1819A100_FLAG = 1;
			veh_scr = data[1];
			fire_alarm_status[0] = data[0];
			fire_alarm_status[1] = data[1];
			fire_alarm_status[2] = data[2];
			fire_alarm_status[3] = data[3];
			fire_alarm_system_status= data[6];
			fire_alarm_life = data[7];					
			break;
		case 0x1800D0A8:
			for(index = 0;index < 8;index++)
				add1[index].byte = data[index];
			break;
        case 0x1801D0A8:
			for(index = 0;index < 8;index++)
				add2[index].byte = data[index];
			break;	
        case 0x1800D0A9:
			for(index = 0;index < 8;index++)
				add3[index].byte = data[index];
			break;
		case 0x18FFF7F6:
			if((data[0] == 0) || (data[0] > 10))
				break;
			BAT_FIRE.box[data[0] - 1] = data[0];
			BAT_FIRE.type[data[0] - 1] = data[1];
			BAT_FIRE.status[data[0] - 1] = (data[4] | (data[3] << 2) | (data[2] << 4));
			BAT_FIRE.fault_code[data[0] - 1] = data[5];
			BAT_FIRE.rollcounter = data[7];
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
			TIRE.press[data[0]] = data[1]+((unsigned int)(data[2])<<8);
			TIRE.temperature[data[0]] = data[3];
			TIRE.fault_1[data[0]] = data[4];
			TIRE.fault_2[data[0]] = data[7];
			break;
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







































