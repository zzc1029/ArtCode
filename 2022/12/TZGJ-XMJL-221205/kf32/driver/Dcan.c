/*
 * Pcan1.c
 *
 *  Created on: 2021-9-19
 *      Author: ART
  注意:该文件用于仪表外CAN1初始化以及发送接收函数20210919
 C5 C6  外CAN1:  1C1TX 1C1RX  PTA4   PTA5   CAN1  AF9功能
 */


#include "system_init.h"
#include "canfifo.h" 
 
 static void xGPIO_Pcan(void)
 {
	 GPIO_InitTypeDef GPIO_InitStructure;
 
	 /*配置CAN引脚类型为复用模式，开启对应端口时钟*/
	 GPIO_InitStructure.m_Mode = GPIO_MODE_RMP;
	 GPIO_InitStructure.m_Speed = GPIO_HIGH_SPEED;
	 GPIO_InitStructure.m_PullDown = GPIO_NOPULL;
	 GPIO_InitStructure.m_PullUp = GPIO_NOPULL;
	 GPIO_InitStructure.m_OpenDrain = GPIO_POD_PP;
	 GPIO_InitStructure.m_Pin = GPIO_PIN_MASK_5|GPIO_PIN_MASK_4;
	 GPIO_Configuration(GPIOA_SFR,&GPIO_InitStructure);
	 
	 PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOACLKEN,TRUE);
	 PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_CAN1CLKEN,TRUE);
	 GPIO_Pin_RMP_Config(GPIOA_SFR,GPIO_Pin_Num_5,GPIO_RMP_AF9_CAN1);
	 GPIO_Pin_RMP_Config(GPIOA_SFR,GPIO_Pin_Num_4,GPIO_RMP_AF9_CAN1);
 }
 
 /*
 ------------------------------------------------------------------------------
 描述		 : can中断配置
 输入		 : 1.CANx: 指向CAN内存结构的指针，取值为CAN0_SFR~CAN3_SFR
 输出		 : 无
 备注		 :
 ============================================================================*/
 static void xINT_PCAN(CAN_SFRmap* CANx)
 {
 
	 /* 开启发送中断 */
	 //CAN_Set_INT_Enable(CANx,CAN_INT_TRANSMIT,TRUE);
	 /* 开启接收中断 */
	 CAN_Set_INT_Enable(CANx,CAN_INT_RECEIVE,TRUE);
	 /* 开启包溢出中断 */
 //  CAN_Set_INT_Enable(CANx,CAN_INT_DATA_OVERFLOW,TRUE);
	 /* CAN中断配置 */
	 INT_Interrupt_Priority_Config(INT_CAN1,INT_PRIORITY_GROUP_0VS4,2);						 //CAN抢占优先级4,子优先级0
	 INT_Clear_Interrupt_Flag(INT_CAN1);								 //CAN清中断标志
	 INT_Interrupt_Enable(INT_CAN1,TRUE);								 //CAN中断使能
	 //INT_All_Enable (TRUE);
 }

 //Pcan INIT
 void DcanInint(void)
 {
   xGPIO_Pcan();
   xInit_CAN(CAN1_SFR,CAN_BAUDRATE_250K,CAN_MODE_NORMAL);
   xINT_PCAN(CAN1_SFR);
 }


 // 以下是加入缓存发送PCAN报文
 SendToCan DCanSendBuff;
 
 SendCanFifo DCanSendbuffx[CANSENDBUFFDEEP];
 
 SendCanFifo DCandomsg;
 
 void Dcan_fifo_init(SendToCan* fifo,SendCanFifo*buff,uint32_t len)
 {
	 fifo->wr_index = 0;
	 fifo->rd_index = 0;
	 fifo->ovfcount = 0;
	 fifo->max_len = len;
	 fifo->buff = buff;
 }
 
 
 void InitDCanSend(void)
 {
	 Dcan_fifo_init(&DCanSendBuff,DCanSendbuffx,CANSENDBUFFDEEP);
	 DCandomsg.sended = CANSENDED;
 }
 
 
 //添加数据
 uint32_t DCan_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len)
 {
	 register uint32_t temp,j = 0;
	 temp = can_fifo_get_free(DCanSendBuff);
	 if(DCanSendDisablel == 0)
	 {
	    DCanSendBuff.rd_index = DCanSendBuff.wr_index;
	 	return 0;
	 }

	 if(1 > temp)
	 {
		 DCanSendBuff.ovfcount++;
		 DCanSendBuff.rd_index = DCanSendBuff.wr_index;
		 return 0;
	 }
	 temp = (DCanSendBuff.wr_index & (DCanSendBuff.max_len - 1));
	 for(j = 0;j < len;j++)
	   DCanSendBuff.buff[temp].data[j] = buffer[j];
	 
	 DCanSendBuff.buff[temp].ID = id;
	 DCanSendBuff.buff[temp].len = len;
	 DCanSendBuff.buff[temp].type = CAN_FRAME_FORMAT_SFF;
	 DCanSendBuff.buff[temp].sended = CANSENDED;
	 DCanSendBuff.wr_index += 1;
	 return 1;
 
 }
 
 uint32_t DCan_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len)
 {
	 register uint32_t temp,j = 0;
	 temp = can_fifo_get_free(DCanSendBuff);
	 if(DCanSendDisablel == 0)
	 {
	    DCanSendBuff.rd_index = DCanSendBuff.wr_index;
	 	return 0;
	 }
	 if(1 > temp)
	 {
		 DCanSendBuff.ovfcount++; 
		 DCanSendBuff.rd_index = DCanSendBuff.wr_index;
		 return 0;
	 }
	 temp = (DCanSendBuff.wr_index & (DCanSendBuff.max_len - 1));
	 for(j = 0;j < len;j++)
	   DCanSendBuff.buff[temp].data[j] = buffer[j];
	 
	 DCanSendBuff.buff[temp].ID = id;
	 DCanSendBuff.buff[temp].len = len;
	 DCanSendBuff.buff[temp].type = CAN_FRAME_FORMAT_EFF;
	 DCanSendBuff.buff[temp].sended = CANSENDED;
	 DCanSendBuff.wr_index += 1;
	 return 1;
 
 }
 
 
 
 
 uint32_t DCanSendFifo(void)
 {
	 register uint32_t l,temp;
	 temp = can_fifo_get_count(DCanSendBuff);
	 if(temp < 1)
	 {
		 return 0;
	 }
	 
	 temp = (DCanSendBuff.rd_index & (DCanSendBuff.max_len - 1));
	 
	 for(l = 0;l < DCanSendBuff.buff[temp].len; l++)
	   DCandomsg.data[l] = DCanSendBuff.buff[temp].data[l];
	 
	 DCandomsg.ID = DCanSendBuff.buff[temp].ID;
	 DCandomsg.len = DCanSendBuff.buff[temp].len;
	 DCandomsg.type = DCanSendBuff.buff[temp].type;
	 DCandomsg.sended = CANSENDED;
	 DCanSendBuff.rd_index += 1;
	 return 1;
	 
 }
 
 void DCanSendTo(void)
 {
	switch(DCandomsg.sended)
	{
	  case CANSENDED:
		   if(DCanSendFifo())
		   {
			 DCandomsg.sended = CANDELAYING;
			 CAN_Transmit_DATA(CAN1_SFR,DCandomsg.ID,DCandomsg.data,DCandomsg.len,CAN_DATA_FRAME,DCandomsg.type);
		   }
		   break;
	  case CANDELAYING:
		   if((CAN_Get_Transmit_Status(CAN1_SFR,CAN_TX_COMPLETE_OFF_STATUS)))
		   {
			 SFR_CLR_BIT_ASM(CAN1_SFR->CTLR, CAN_CTLR_TXR_POS);
			 DCandomsg.sended = CANSENDED;
		   }
		   break;
	  default:
		   break;
	}
	   if(CAN_Get_Transmit_Status(CAN1_SFR,CAN_BUS_OFF_STATUS))
	   {
		   DcanInint();
	   }
 }




 // 以下BCAN接收CAN报文
 // Bcan 
 const uint32_t PCanIdTable[] =
 {
	 /******* VCU  ***********************/
	 0x12345678,
	 0x643,
	 0x532
 };
 
 
#define PCAN_DATA_MAX  (sizeof(PCanIdTable)/sizeof(PCanIdTable[0]))
#define PCAN_ID_SUM   ((sizeof(PCanIdTable)/sizeof(PCanIdTable[0])))
 
volatile uint8_t PCanData[PCAN_DATA_MAX][8];
 
 
 uint16_t PGetIndexFromID(uint32_t id)
 {
	 uint16_t i;
	 for(i=0;i<PCAN_ID_SUM;i++)
	 {
		 if(PCanIdTable[i] == id)
			 return i;
	 }
	 return PCAN_ID_SUM;
 }
 
 u16 PcanID(u32 id)
 {
	 u16 i;
	 for(i=0;i<PCAN_ID_SUM;i++)
	 {
		 if(PCanIdTable[i] == id)
			 return i;
	 }
	 return PCAN_ID_SUM;
 }
 
 u32 PcanGetIDFromIndex(u16 index)
 {
	 if(index<PCAN_ID_SUM)
	 {
		 return PCanIdTable[index];
	 }
	 else
	 {
		 return 0;
	 }
 }
 
 volatile static uint8_t data[8] = {0,0,0,0,0,0,0,0};
 
 //CAN0接收函数，一般需要CAN1,CAN2接收相同ID，此函数暂定
 void Can1_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue)
 {
	u32 id = 0;
	uint16_t index = 0;
	id = GetID(CAN_MessageStructrue);
	index = PGetIndexFromID(id);
	if(index < PCAN_ID_SUM)
	{
		//timeout 清零	 动作未加入
		GeCantData(CAN_MessageStructrue,PCanData[index]);
		GeCantData(CAN_MessageStructrue,data);
		switch(id)
		{
		  case 0x12345678:
				ReInitDisplayFlag = 1;
				break;
		   case 0x643:
			   avtest = data[0]; 
		   break;
		   case 0x532:
		   	    if((data[0] == 3)||(data[0] == 8)||(data[0] == 6))
                {
		   	    	DCanSendDisablel = 1;
                }
                else
                {
                	DCanSendDisablel = 0;
                }
		   break;
			default:
				 break;
		}
	}
 }




















