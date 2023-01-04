/*
 * canreceive.c
 *
 *  Created on: 2021-8-6
 *      Author: ART
 */

#include "system_init.h"



const uint32_t PCan1IdTable[] =
{
	
    0x18FFEA97, 
     //1 基本信息2
    0x18FFEB97, 
    //1 基本信息3 
    0x18FFF797,  //1 
    //1 基本信息4
    0x18FFF897,
    //1 基本信息5
    0x18FFF997,
    //1 基本信息6
    0x18FF6597,
    //1 基本信息7
    0x18FFFB97,
    //1 基本信息8
    0x18FE4A97,
    //1 基本信息9
    0x18FE4B97,
    //1 TMS1
    0x18FF3AF4,
    //1 TMS2
    0x18FFC13A,
    //1 空调信息1
    0x18FF0B97,
    //1 空调信息2
    0x18FF0C9C,
    //1 ABS信息1
    0x18F0010B,
    0x18FDC40B,
    //1 ABS多包故障
    0x18FECA0B,
    0x1CEBFF0B,
    //1 EPB
    0x18FF8DAC,
    0x18FF65AC,
    //1 灭火装置
    0x18FF56F6,
    //1 油门踏板信息1
    0x18FF2997,
    //1 制动踏板和油泵频率
    0x18F0089E,
	//1 碰撞预警
	0x18FFFE97,
	//1 集中润滑
	0x18FFA898,
	//1 燃料电池
	//0x18FFFC97,
	//0x18FFFD97,
	//1 配电盒
	/*0x19FFB71E,
	0x19FFB81E,
	0x19FFB91E,
	0x19FFBA1E,
	0x19FFBB1E,
	0x19FFBD1E,*/
	0x181F041F,
	0x181F051F,
	0x181F061F,
	0x181F071F,
	0x181F081F,
	//1报文开关
	0x18FF9117,
	0x18FA0617,
	//胎压
	0x18fef433,
};

#define PCAN1_DATA_MAX  (sizeof(PCan1IdTable)/sizeof(PCan1IdTable[0]))
#define PCAN1_ID_SUM   ((sizeof(PCan1IdTable)/sizeof(PCan1IdTable[0])))

volatile uint8_t CanData[PCAN1_DATA_MAX][8];
uint8_t timeout[PCAN1_DATA_MAX];

//数据清零
void ClearData(volatile u8* data,u8 ns)
{
    int i;
    for(i=0; i<ns; i++)
    {
        *data++ = 0;
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
	index = GetIndexFromID(id);
    ClearData(CanData[index],8);
    switch(id)
    {
		/*case 0x18FECA0B:
			ABS_DTC[0] = 0;
			break;
		case 0x1CEBFF0B:
			ABS_DTC[0] = 0;
			ABS_DTC[1] = 0;
			ABS_DTC[2] = 0;
			ABS_DTC[3] = 0;
			break;*/
		case 0x18FFEB97:
			veh_speed = 0;
			veh_speed_display = 0;
			eng_speed = 0;		  
			break;
		case 0x18FFF897:
			veh_soc = 0;
			break;
		case 0x18FF6597:
			for(i=0;i<4;i++)
				Fault[i].byte = 0;
		    break;
		case 0x181F041F:
			for(i=0;i<43;i++)
				PeiDianOutSta[i] = 0;
			break;
		case 0x181F051F:
			for(i=0;i<45;i++)
				PeiDianOutCur[i] = 0;
			break;
		case 0x181F071F:
			for(i=0;i<12;i++)
				PeiDianTemp[i] = 0;
			break;
		case 0x18FF56F6:
			for(i=0;i<MAX_MIEHUO;i++)
			{
				Meihuo[i].box = 0xFF;
				Meihuo[i].type = 0xFF;
				Meihuo[i].alarm_level= 0xFF;
				Meihuo[i].fault_status= 0xFF;
				Meihuo[i].zifa= 0xFF;
				Meihuo[i].faultcode= 0xFF;
				Meihuo[i].changjia= 0xFF;
				meihuo_life = 0;
			}
			break;
		
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

extern void CanRecvHook(u16 index);

void ClearCanDataManage(void)
{
    u8 i;
    for(i = 0; i< (PCAN1_DATA_MAX); i++)
    {
        if(timeout[i] > 100)
        {
            ClearCanData(Pcan1GetIDFromIndex(i));
			CanRecvHook(i);
        }
        else
        {
        	CanRecvHook(i);
            timeout[i]++;
        }
    }
}




static volatile uint8_t data[8] = {0,0,0,0,0,0,0,0};

void ReceCan(uint32_t id,volatile uint8_t *data)
{
   volatile static uint32_t sp1,sp2;
   volatile static uint16_t sp3,SP4;
   u32 temp = 0,temp_u16 = 0,temp_32;
   static u8 lastcode;
   u8 i;
   
	//CopyData(CanData[index],data,8);
	switch(id)
	{
		case 0x18FECA0B:
			ABS_DTC[0] = GetU32LEData(data[2],data[3],data[4],data[5]);
			ABS_DTC[1] = 0;
			ABS_DTC[2] = 0;
			ABS_DTC[3] = 0;
			break;
	  	case 0x1CEBFF0B:
		   if(data[0] == 1)
		   {
			  ABS_DTC[0] = GetU32LEData(data[3],data[4],data[5],data[6]);
			  lastcode = data[7];
		   }
		   else if(data[0] == 2)
		   {
			   ABS_DTC[1] = GetU32LEData(lastcode,data[1],data[2],data[3]);
			   ABS_DTC[2] = GetU32LEData(data[4],data[5],data[6],data[7]);
		   }
		   else if(data[0] == 3)
		   {
			   ABS_DTC[3] = GetU32LEData(data[1],data[2],data[3],data[4]);	   
		   }
		   break;

	   
       case 0x18FFEB97:

		  //输出轴转速
	  temp_u16 = GetU16LEData(data[0],data[1]);

      if(temp_u16 >= 15000)
	  	 temp_u16 = temp_u16 - 15000;
	  else 
	     temp_u16 = 15000 - temp_u16;
	  
	  SP4 = (odometer_const);
	  sp3 = temp_u16;
	  sp1 = (float)((float)sp3 * 60);
	  sp2 = ((sp1 * 10)/(unsigned long)SP4);
	  if(sp2 >= 1400)
		 sp2 = 1400;
	  veh_speed = sp2;
	  veh_speed_display = (veh_speed*0.01)*Oil_Alarm;
	  speed_life = 0; 
	  
	  //1 驱动电机转速
	  eng_speed = GetU16LEData(data[2],data[3]);
	  if(eng_speed >= 15000)
		  eng_speed = eng_speed - 15000;
	   else 
		  eng_speed = 15000 - eng_speed;

	  if(eng_speed > 6000)
		  eng_speed = 6000;
	  	  
		break;

	case 0x18FFF897:
	
		veh_soc = data[4];
		{
			if(TestBitFalse(data[7],2))
			{
				uint16_t temp = GetU16LE(data,2) + (32000-6000);
				i = Pcan1GetIndexFromID(0x18FFF897);
				if(i>=PCAN1_ID_SUM)
					break;

				CanData[i][2] = GetByteLSB0(temp);
				CanData[i][3] = GetByteLSB1(temp);
			}
		}

		break;
   case 0x18FF6597:
		temp_32 = ((u16)data[2]<<8) + data[1];
		temp_32 = temp_32>>5;
		if(temp_32 == 0)
		{
			for(i=0;i<4;i++)
				Fault[i].byte = 0;
		}
		else
		{
	        if(temp_32 == 1)
				Fault[0].bit.b0 = 1;
	        if(temp_32 == 2)
				Fault[0].bit.b1 = 1;
			if(temp_32 == 3)
			    Fault[0].bit.b2 = 1;
			if(temp_32 == 4)
			    Fault[0].bit.b3 = 1;
			if(temp_32 == 5)
			    Fault[0].bit.b4 = 1;
			if(temp_32 == 6)
			    Fault[0].bit.b5 = 1;
			if(temp_32 == 7)
			    Fault[0].bit.b6 = 1;					
			if(temp_32 == 8)
			    Fault[0].bit.b7 = 1;

			if(temp_32 == 9)
				Fault[1].bit.b0 = 1;
	        if(temp_32 == 10)
				Fault[1].bit.b1 = 1;
			if(temp_32 == 11)
			    Fault[1].bit.b2 = 1;
			if(temp_32 == 12)
			    Fault[1].bit.b3 = 1;
			if(temp_32 == 13)
			    Fault[1].bit.b4 = 1;
			if(temp_32 == 14)
			    Fault[1].bit.b5 = 1;
			if(temp_32 == 15)
			    Fault[1].bit.b6 = 1;
			if(temp_32 == 16)
			    Fault[1].bit.b7 = 1;
			
			if(temp_32 == 17)
				Fault[2].bit.b0 = 1;
	        if(temp_32 == 18)
				Fault[2].bit.b1 = 1;
			if(temp_32 == 19)
			    Fault[2].bit.b2 = 1;
			if(temp_32 == 20)
			    Fault[2].bit.b3 = 1;
			if(temp_32 == 21)
			    Fault[2].bit.b4 = 1;
			if(temp_32 == 22)
			    Fault[2].bit.b5 = 1;
			if(temp_32 == 23)
			    Fault[2].bit.b6 = 1;
			if(temp_32 == 24)
			    Fault[2].bit.b7 = 1;
			
			if(temp_32 == 25)
				Fault[3].bit.b0 = 1;
	        if(temp_32 == 26)
				Fault[3].bit.b1 = 1;
	        if(temp_32 == 27)
				Fault[3].bit.b2 = 1;
			if(temp_32 == 28)
				Fault[3].bit.b3 = 1;
			if(temp_32 == 29)
				Fault[3].bit.b4 = 1;
			if(temp_32 == 30)
				Fault[3].bit.b5 = 1;					
			if(temp_32 == 35)
				Fault[3].bit.b6 = 1;	
			if(temp_32 == 36)
			  Fault[3].bit.b7 = 1;	

			if(temp_32 == 37)
				Fault[4].bit.b0 = 1;
			if(temp_32 == 38)
				Fault[4].bit.b1 = 1;
			if(temp_32 == 39)
				Fault[4].bit.b2 = 1;
			if(temp_32 == 40)
				Fault[4].bit.b3 = 1;
			if(temp_32 == 41)
				Fault[4].bit.b4 = 1;
		}
   	    break;
		/*case 0x19FFBB1E:
			for(i=0;i<3;i++)
				PeiDianOutCur[data[0] * 3 + i] = GetU16LEData(data[i*2 + 1],data[i*2 + 2]);
			break;
		case 0x19FFBD1E:
			switch(data[0])
			{
				case 0:
					for(i=0;i<7;i++)
						PeiDianTemp[data[0]*7 + i] = data[i + 1];
					break;
				case 1:
					for(i=0;i<2;i++)
						PeiDianTemp[data[0]*7 + i] = data[i + 1];
					break;
				case 2:
					for(i=0;i<5;i++)
						PeiDianTemp[(data[0]-1)*9 + i] = data[i + 3];
					break;
				default:
					break;
			}
			break;*/
		case 0x181F041F:
			for(i=0;i<7;i++)
				PeiDianOutSta[data[0] * 7 + i] = data[i + 1];
			break;
		case 0x181F051F:
			for(i=0;i<3;i++)
				PeiDianOutCur[data[0] * 3 + i] = GetU16LEData(data[i*2 + 2],data[i*2 + 3]);
			break;
		case 0x181F071F:
			if((data[0] >=8) && (data[0] <=9))
			{
				for(i=0;i<6;i++)
					PeiDianTemp[(data[0] - 8)* 6 + i] = data[i + 2];
			}
			break;
		case 0x18FF56F6:
			if((data[0] > 0) && (data[0] < (MAX_MIEHUO+1)))
			{
				Meihuo[data[0] - 1].box = data[0];
				Meihuo[data[0] - 1].type = data[1];
				Meihuo[data[0] - 1].alarm_level= data[2];
				Meihuo[data[0] - 1].fault_status= data[3];
				Meihuo[data[0] - 1].zifa= data[4];
				Meihuo[data[0] - 1].faultcode= data[5];
				Meihuo[data[0] - 1].changjia= (data[6] & 0x1F);
				meihuo_life = data[7];
			}
			break;
		case 0x18fef433:
			switch(data[0])
			{
				case 0x10:
					data[0] = 2;
					break;
				case 0x11:
					data[0] = 3;
					break;
				case 0x12:
					data[0] = 4;
					break;
				case 0x13:
					data[0] = 5;
					break;
				default:
					break;
			}
			if(data[0] < 6)
			{
				taiya.press[data[0]] = data[1];
				taiya.temp[data[0]] = GetU16LEData(data[2],data[3]);
				taiya.alarm_status[data[0]].byte = data[7];
			}
			break;

			case  0x18FFC13A:
			{
				i = Pcan1GetIndexFromID(0x18FFC13A);
				if(i>=PCAN1_ID_SUM)
					break;

				CanData[i][5] = data[6];
				CanData[i][6] = data[5];
			}
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














































