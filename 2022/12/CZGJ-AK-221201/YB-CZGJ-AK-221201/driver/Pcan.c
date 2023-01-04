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
 void PcanInint(void)
 {
   xGPIO_Pcan();
   xInit_CAN(CAN1_SFR,CAN_BAUDRATE_250K,CAN_MODE_NORMAL);
   xINT_PCAN(CAN1_SFR);
 }


 // 以下是加入缓存发送PCAN报文
 SendToCan PCanSendBuff;
 
 SendCanFifo PCanSendbuffx[CANSENDBUFFDEEP];
 
 SendCanFifo PCandomsg;
 
 void Pcan_fifo_init(SendToCan* fifo,SendCanFifo*buff,uint32_t len)
 {
	 fifo->wr_index = 0;
	 fifo->rd_index = 0;
	 fifo->ovfcount = 0;
	 fifo->max_len = len;
	 fifo->buff = buff;
 }
 
 
 void InitPCanSend(void)
 {
	 Pcan_fifo_init(&PCanSendBuff,PCanSendbuffx,CANSENDBUFFDEEP);
	 PCandomsg.sended = Sended;
 }
 
 
 //添加数据
 uint32_t PCan_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len)
 {
	 register uint32_t temp,j = 0;
	 temp = can_fifo_get_free(PCanSendBuff);
	 if(1 > temp)
	 {
		 PCanSendBuff.ovfcount++;
		 PCanSendBuff.rd_index = PCanSendBuff.wr_index;
		 return 0;
	 }
	 temp = (PCanSendBuff.wr_index & (PCanSendBuff.max_len - 1));
	 for(j = 0;j < len;j++)
	   PCanSendBuff.buff[temp].data[j] = buffer[j];
	 
	 PCanSendBuff.buff[temp].ID = id;
	 PCanSendBuff.buff[temp].len = len;
	 PCanSendBuff.buff[temp].type = CAN_FRAME_FORMAT_SFF;
	 PCanSendBuff.buff[temp].sended = SENDED;
	 PCanSendBuff.wr_index += 1;
	 return 1;
 
 }
 
 uint32_t PCan_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len)
 {
	 register uint32_t temp,j = 0;
	 temp = can_fifo_get_free(PCanSendBuff);
	 if(1 > temp)
	 {
		 PCanSendBuff.ovfcount++; 
		 PCanSendBuff.rd_index = PCanSendBuff.wr_index;
		 return 0;
	 }
	 temp = (PCanSendBuff.wr_index & (PCanSendBuff.max_len - 1));
	 for(j = 0;j < len;j++)
	   PCanSendBuff.buff[temp].data[j] = buffer[j];
	 
	 PCanSendBuff.buff[temp].ID = id;
	 PCanSendBuff.buff[temp].len = len;
	 PCanSendBuff.buff[temp].type = CAN_FRAME_FORMAT_EFF;
	 PCanSendBuff.buff[temp].sended = SENDED;
	 PCanSendBuff.wr_index += 1;
	 return 1;
 
 }
 
 
 
 
 uint32_t PCanSendFifo(void)
 {
	 register uint32_t l,temp;
	 temp = can_fifo_get_count(PCanSendBuff);
	 if(temp < 1)
	 {
		 return 0;
	 }
	 
	 temp = (PCanSendBuff.rd_index & (PCanSendBuff.max_len - 1));
	 
	 for(l = 0;l < PCanSendBuff.buff[temp].len; l++)
	   PCandomsg.data[l] = PCanSendBuff.buff[temp].data[l];
	 
	 PCandomsg.ID = PCanSendBuff.buff[temp].ID;
	 PCandomsg.len = PCanSendBuff.buff[temp].len;
	 PCandomsg.type = PCanSendBuff.buff[temp].type;
	 PCandomsg.sended = SENDED;
	 PCanSendBuff.rd_index += 1;
	 return 1;
	 
 }
 
 void PCanSendTo(void)
 {
	switch(PCandomsg.sended)
	{
	  case SENDED:
		   if(PCanSendFifo())
		   {
			 PCandomsg.sended = DELAYING;
			 CAN_Transmit_DATA(CAN1_SFR,PCandomsg.ID,PCandomsg.data,PCandomsg.len,CAN_DATA_FRAME,PCandomsg.type);
		   }
		   break;
	  case DELAYING:
		   if(CAN_Get_Transmit_Status(CAN1_SFR,CAN_TX_BUFFER_STATUS))
		   {
			 PCandomsg.sended = SENDED;
			 SFR_CLR_BIT_ASM(CAN1_SFR->CTLR, CAN_CTLR_TXR_POS);
		   }
		   break;
	  default:
		   break;
	}
	if(CAN_Get_Transmit_Status(CAN1_SFR,CAN_BUS_OFF_STATUS))
	{
		PcanInint();
	}
 }
























