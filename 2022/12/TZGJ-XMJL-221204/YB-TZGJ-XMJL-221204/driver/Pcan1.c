/*
 * Dcan.c
 *
 *  Created on: 2021-9-19
 *      Author: ART
  注意:该文件用于仪表内CAN初始化以及发送接收函数20210919
 
 C16 C17 外CAN3:  1C2TX 1C2RX  PTA12  PTA11	 CAN2  AF9功能	  DCAN
 
 */

#include "system_init.h"
#include "canfifo.h" 

 static void xGPIO_Pcan1(void)
 {
	 GPIO_InitTypeDef GPIO_InitStructure;
 
	 /*配置CAN引脚类型为复用模式，开启对应端口时钟*/
	 GPIO_InitStructure.m_Mode = GPIO_MODE_RMP;
	 GPIO_InitStructure.m_Speed = GPIO_HIGH_SPEED;
	 GPIO_InitStructure.m_PullDown = GPIO_NOPULL;
	 GPIO_InitStructure.m_PullUp = GPIO_NOPULL;
	 GPIO_InitStructure.m_OpenDrain = GPIO_POD_PP;
	 GPIO_InitStructure.m_Pin = GPIO_PIN_MASK_0|GPIO_PIN_MASK_1;
	 GPIO_Configuration(GPIOB_SFR,&GPIO_InitStructure);

	 /*配置引脚映射功能为CAN模式  外设时钟 */
	 PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOACLKEN,TRUE);
	 PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_CAN2CLKEN,TRUE);
	 GPIO_Pin_RMP_Config(GPIOB_SFR,GPIO_Pin_Num_0,GPIO_RMP_AF9_CAN1);
	 GPIO_Pin_RMP_Config(GPIOB_SFR,GPIO_Pin_Num_1,GPIO_RMP_AF9_CAN1);
 }
 
 /*
 ------------------------------------------------------------------------------
 描述		 : can中断配置
 输入		 : 1.CANx: 指向CAN内存结构的指针，取值为CAN0_SFR~CAN3_SFR
 输出		 : 无
 备注		 :
 ============================================================================*/
 static void xINT_PCAN1(CAN_SFRmap* CANx)
 {
 
	 /* 开启发送中断 */
	 //CAN_Set_INT_Enable(CANx,CAN_INT_TRANSMIT,TRUE);
	 /* 开启接收中断 */
	 CAN_Set_INT_Enable(CANx,CAN_INT_RECEIVE,TRUE);
	 /* 开启包溢出中断 */
 //  CAN_Set_INT_Enable(CANx,CAN_INT_DATA_OVERFLOW,TRUE);
	 /* CAN中断配置 */
	 INT_Interrupt_Priority_Config(INT_CAN2,INT_PRIORITY_GROUP_0VS4,2);						 //CAN抢占优先级4,子优先级0
	 INT_Clear_Interrupt_Flag(INT_CAN2);								 //CAN清中断标志
	 INT_Interrupt_Enable(INT_CAN2,TRUE);								 //CAN中断使能
	 //INT_All_Enable (TRUE);
 }
 
 
 //Bcan INIT
 void Pcan1Inint(void)
 {
   xGPIO_Pcan1();
   xInit_CAN(CAN2_SFR,CAN_BAUDRATE_250K,CAN_MODE_NORMAL);
   xINT_PCAN1(CAN2_SFR);
 }

 // 以下是加入缓存发送BCAN报文
 SendToCan PCan1SendBuff;
 
 SendCanFifo PCan1Sendbuffx[CANSENDBUFFDEEP];
 
 SendCanFifo PCan1domsg;
 
 void Pcan1_fifo_init(SendToCan* fifo,SendCanFifo*buff,uint32_t len)
 {
	 fifo->wr_index = 0;
	 fifo->rd_index = 0;
	 fifo->ovfcount = 0;
	 fifo->max_len = len;
	 fifo->buff = buff;
 }
 
 
 void InitPCan1Send(void)
 {
	 Pcan1_fifo_init(&PCan1SendBuff,PCan1Sendbuffx,CANSENDBUFFDEEP);
	 PCan1domsg.sended = CANSENDED;
 }
 
 
 //添加数据
 uint32_t PCan1_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len)
 {
	 register uint32_t temp,j = 0;
	 temp = can_fifo_get_free(PCan1SendBuff);
	 if(1 > temp)
	 {
		 PCan1SendBuff.ovfcount++;
		 PCan1SendBuff.rd_index = PCan1SendBuff.wr_index;
		 return 0;
	 }
	 temp = (PCan1SendBuff.wr_index & (PCan1SendBuff.max_len - 1));
	 for(j = 0;j < len;j++)
		 PCan1SendBuff.buff[temp].data[j] = buffer[j];
	 
	 PCan1SendBuff.buff[temp].ID = id;
	 PCan1SendBuff.buff[temp].len = len;
	 PCan1SendBuff.buff[temp].type = CAN_FRAME_FORMAT_SFF;
	 PCan1SendBuff.buff[temp].sended = CANSENDED;
	 PCan1SendBuff.wr_index += 1;
	 return 1;
 
 }
 
 uint32_t PCan1_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len)
 {
	 register uint32_t temp,j = 0;
	 temp = can_fifo_get_free(PCan1SendBuff);
	 if(1 > temp)
	 {
		 PCan1SendBuff.ovfcount++;
		 PCan1SendBuff.rd_index = PCan1SendBuff.wr_index;
		 return 0;
	 }
	 temp = (PCan1SendBuff.wr_index & (PCan1SendBuff.max_len - 1));
	 for(j = 0;j < len;j++)
		 PCan1SendBuff.buff[temp].data[j] = buffer[j];
	 
	 PCan1SendBuff.buff[temp].ID = id;
	 PCan1SendBuff.buff[temp].len = len;
	 PCan1SendBuff.buff[temp].type = CAN_FRAME_FORMAT_EFF;
	 PCan1SendBuff.buff[temp].sended = CANSENDED;
	 PCan1SendBuff.wr_index += 1;
	 return 1;
 }
 
 
 
 
 uint32_t PCan1SendFifo(void)
 {
	 register uint32_t l,temp;
	 temp = can_fifo_get_count(PCan1SendBuff);
	 if(temp < 1)
	 {
		 return 0;
	 }
	 
	 temp = (PCan1SendBuff.rd_index & (PCan1SendBuff.max_len - 1));
	 for(l = 0;l < PCan1SendBuff.buff[temp].len; l++)
	   PCan1domsg.data[l] = PCan1SendBuff.buff[temp].data[l];
	 
	 PCan1domsg.ID = PCan1SendBuff.buff[temp].ID;
	 PCan1domsg.len = PCan1SendBuff.buff[temp].len;
	 PCan1domsg.type = PCan1SendBuff.buff[temp].type;
	 PCan1domsg.sended = CANSENDED;
	 PCan1SendBuff.rd_index += 1;
	 return 1;
 }
 
 void PCan1SendTo(void)
 {
	switch(PCan1domsg.sended)
	{
	  case CANSENDED:
		   if(PCan1SendFifo())
		   {
			 PCan1domsg.sended = CANDELAYING;
			 CAN_Transmit_DATA(CAN2_SFR,PCan1domsg.ID,PCan1domsg.data,PCan1domsg.len,CAN_DATA_FRAME,PCan1domsg.type);
		   }
		   break;
	  case CANDELAYING:
		   if((CAN_Get_Transmit_Status(CAN2_SFR,CAN_TX_COMPLETE_OFF_STATUS)))
		   {
			   SFR_CLR_BIT_ASM(CAN2_SFR->CTLR, CAN_CTLR_TXR_POS);
			   PCan1domsg.sended = CANSENDED;
		   }
		   break;
	  default:
		   break;
	}

	   if(CAN_Get_Transmit_Status(CAN2_SFR,CAN_BUS_OFF_STATUS))
	   {
		   Pcan1Inint();
	   }
 }




 // 以下DCAN接收CAN报文
 // Dcan 
#if 0
 const uint32_t DCanIdTable[] =
 {
	 /******* VCU  ***********************/
		 0x6A4,
		 0x6B4,
		 0X6E4,
		 0X520,
		 0X521,
		 0x522,
		 0x523,
		 0x524
 };
 
 
#define DCAN_DATA_MAX  (sizeof(DCanIdTable)/sizeof(DCanIdTable[0]))
#define DCAN_ID_SUM   ((sizeof(DCanIdTable)/sizeof(DCanIdTable[0])))
 
volatile uint8_t DCanData[DCAN_DATA_MAX][8];
 
 
 uint16_t DGetIndexFromID(uint32_t id)
 {
	 uint16_t i;
	 for(i=0;i<DCAN_ID_SUM;i++)
	 {
		 if(DCanIdTable[i] == id)
			 return i;
	 }
	 return DCAN_ID_SUM;
 }
 
 u16 DcanID(u32 id)
 {
	 u16 i;
	 for(i=0;i<DCAN_ID_SUM;i++)
	 {
		 if(DCanIdTable[i] == id)
			 return i;
	 }
	 return DCAN_ID_SUM;
 }
 
 u32 DcanGetIDFromIndex(u16 index)
 {
	 if(index<DCAN_ID_SUM)
	 {
		 return DCanIdTable[index];
	 }
	 else
	 {
		 return 0;
	 }
 }
 
 volatile static uint8_t data[8] = {0,0,0,0,0,0,0,0};
 //CAN1接收函数
 void Can2_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue)
 {
	u32 id = 0;
	volatile uint16_t index = 0;
	id = GetID(CAN_MessageStructrue);
	index = DGetIndexFromID(id);
	if(index < DCAN_ID_SUM)
	{
		//timeout 清零	 动作未加入
		GeCantData(CAN_MessageStructrue,DCanData[index]);
		switch(id)
		{
			case 0x521:
				data[0] = 0;
				for(;;);
				break;
			case 0x520:
				data[0] = 1;
				break;
			case 0x0CF101D0:
				data[0] = 45;
				break;
			default:
				 break;
		}
	}
 }
#endif
 





















