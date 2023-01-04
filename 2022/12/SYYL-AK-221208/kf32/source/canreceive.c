/*
 * canreceive.c
 *
 *  Created on: 2021-8-6
 *      Author: ART
 */

#include "system_init.h"

const uint32_t CanIdTable[] =
{
	0x0cf00400,//转速
	0x18FEEE00,//水温
	0x18FEEF00,//机油压力
	0x18FE56A3,//尿素液位
	0x18FEFF00,//油中积水
	0x18FEE400,//进气预热
	//0x18FD070F,//
	0x18FD7C00,//DPF灯
	//0x18FD0700,
	0x18FECA00,//发动机故障单报文
	0x18ECFF00,//发动机故障多报文
	0x18EBFF00,//发动机故障多报文
	//0x18FDC43E,
	//0x18FE4F0B,
	//0x104C0AA0,
	//0x0CF02FA0,
	//0x18F0010B,
	0x18FF0800,
	0x18FEF200,
	0x18FEE900,
	0x18FF0257,	//排放远程监控报文
};

#define CAN_DATA_MAX  (sizeof(CanIdTable)/sizeof(CanIdTable[0]))
#define CAN_ID_SUM   ((sizeof(CanIdTable)/sizeof(CanIdTable[0])))

volatile uint8_t CanData[CAN_DATA_MAX][8];
volatile uint16_t timeout[CAN_DATA_MAX];

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
    static u8 clear_alarm[2];
	u8 i;
    switch(id)
    {
		case 0x18FECA00:
			clear_alarm[0] = 1;
			break;
		case 0x18EBFF00:
			clear_alarm[1] = 1;
			break;	
        case 0x18FEEF00://发动机液体层/压力
            engine_oil_press=0;
            break;
        case 0x0cf00400:
            eng_speed=0;
            break;
        case 0x18FEEE00:
            WaterTem=40;
            break;
        case 0x18FEFF00:
            break;
	
		 /*ccase 0x0CF02FA0:
		 for(i = 0; i<8; i++)
			 add5[i].byte = 0;
		 break;
		case 0x104C0AA0:
		  for(i = 0; i <8; i++)
			  add4[i].byte = 0;
		  break;

		 case 0x18F0010B:
		  for(i = 0; i <8; i++)
			  add1[i].byte = 0;
		  break;*/
		  
		/*case 0x18FDC43E:
			 for(i = 0; i<8; i++)
			   add2[i].byte = 0;
			 break;
		case 0x18FE4F0B:
			 for(i = 0; i<8; i++)
			   add3[i].byte = 0;
			 break;
		case 0x18FD0700:
			for(i = 0; i<8; i++)
				_18FD0700[i] = 0;
			break;*/
		case 0x18FF0800: 
			MIL_light = 0;
			break;
		case 0x18FEF200: //瞬时油耗
			shunshiyouhao = 0;
			break;
		case 0x18FEE900: //瞬时油耗
			for(i = 0;i<4;i++)
				zongyouhao[i] =0;
			break;
	}
	if((clear_alarm[0] == 1)&&(clear_alarm[1] == 1))
	{
		clear_alarm[0] = 0;
		clear_alarm[1] = 0;
		MemClr(HybridFault1,40);
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
		if(i == ID(0x18FF0257))
		{
			if(timeout[i] > 1800)
			{
				ClearCanData(GetIDFromIndex(i));
				PAIFANG_LIXIAN = 1;
			}
			else
			{
			    timeout[i]++;
			}
		}
        else if(timeout[i] > 100)
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
   u8 i;
	switch(id)
	{
		
		case 0x18FEEF00://发动机液体层/压力
		    engine_oil_press = data[3]; 
		    break;
		case 0xcf00400:
	        eng_speed=(data[3]+((unsigned int)(data[4])<<8))*0.125;
	        break;
		case 0x18FEEE00:
	        WaterTem=data[0];
	        break;
	    case 0x18FE56A3:
			scr = data[0] * 4;
			if(scr >= 1000)
				scr = 1000;
			break;
		case 0x18FEFF00: //油中积水
			youjishui = data[0];
			NCD = data[1];
			break;
		case 0x18FEE400: //进气预热
			jinqiyure = data[3];
			break;
		/*case 0x18FD070F: //排气制动
			paiqizhidong = data[1];
			break;*/
		case 0x18FD7C00: //DPF灯
			DPF_light = data[0];
			DPF_ban_light = data[2];
			break;
		case 0x18FECE00: //DM5 就绪状态标志
			/*if((data[6] == 0)&&(data[7] == 0))
				DM5_READY = 1;
			else
				DM5_READY = 0;*/
			break;
		case 0x18FECA00: //发动机故障灯、驾驶员警告灯、MIL灯 
			CopyData(ERR_LIGHT,data,8); //混合动力系统故障(单个)
			HybridFault1[0] = ERR_LIGHT[BYTE3];
			HybridFault1[1] = ERR_LIGHT[BYTE4];
			HybridFault1[2] = ERR_LIGHT[BYTE5];
			HybridFault1[3] = ERR_LIGHT[BYTE6];
			MemClr(&HybridFault1[4],36);
			break;
		case 0x18ECFF00://多个混合动力故障
			Tot_packets = get_faualt_bytes(data[BYTE4]); //有效故障字节数
			Tot_packets = Tot_packets*4;
			Const_0X20  = data[BYTE1];//1 定值0x20
			pgn = (((u32)(data[BYTE8]))<<16)|(((u16)(data[BYTE7]))<<8)|data[BYTE6];
			break;	
		case 0x18EBFF00:
			temp_1 = data[BYTE1];//序号
			if((pgn == 0x00feca)&&(Const_0X20 == 0x20))
			{
				switch(temp_1)
				{
					case 0x01:
						MemCopy(HybridFault1,&data[BYTE4],5);
					//	Alarm_Fog = data[BYTE2];
						break;
					case 0x02:
						MemCopy(&HybridFault1[5],&data[BYTE2],7);
						break;
					case 0x03:
						MemCopy(&HybridFault1[12],&data[BYTE2],7);
						break;
					case 0x04:
						MemCopy(&HybridFault1[19],&data[BYTE2],7);
						break;
					case 0x05:
						MemCopy(&HybridFault1[26],&data[BYTE2],7);
						break;
					case 0x06:
						MemCopy(&HybridFault1[33],&data[BYTE2],7);
						break;
					default:
						break;
				}
			}
			MemClr(&HybridFault1[Tot_packets],40 - Tot_packets);
			break;
		/*case 0x18F0010B:
			for(temp = 0; temp<8; temp++)
				add1[temp].byte = data[temp];
			break;
		case 0x18FDC43E:
			  for(temp = 0; temp<8; temp++)
				  add2[temp].byte = data[temp];
			  break;
		case 0x18FE4F0B:
			for(temp = 0; temp<8; temp++)
				add3[temp].byte = data[temp];
			break;	
		case 0x104C0AA0:
			  for(temp = 0; temp<8; temp++)
				  add4[temp].byte = data[temp];
			  break;
		case 0x0CF02FA0:
				for(temp = 0; temp<8; temp++)
					add5[temp].byte = data[temp];
				break;
		case 0x18FD0700:
			CopyData(_18FD0700,data,8);
			break;*/
		case 0x18FF0800:
			MIL_light = data[3];
			break;
		case 0x18FEF200: //瞬时油耗
			shunshiyouhao = (data[2]+((unsigned int)(data[3])<<8))/512;
			break;
		case 0x18FEE900: //瞬时油耗
			for(i = 0;i<4;i++)
				zongyouhao[i] = data[4+i];
			break;
		case 0x18FF0257:
			PAIFANG_LIXIAN = 0;
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







































