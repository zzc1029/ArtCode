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
 
 static void xGPIO_Dcan(void)
 {
	 GPIO_InitTypeDef GPIO_InitStructure;
 
	 /*配置CAN引脚类型为复用模式，开启对应端口时钟*/
	 GPIO_InitStructure.m_Mode = GPIO_MODE_RMP;
	 GPIO_InitStructure.m_Speed = GPIO_HIGH_SPEED;
	 GPIO_InitStructure.m_PullDown = GPIO_NOPULL;
	 GPIO_InitStructure.m_PullUp = GPIO_NOPULL;
	 GPIO_InitStructure.m_OpenDrain = GPIO_POD_PP;
	 GPIO_InitStructure.m_Pin = GPIO_PIN_MASK_11|GPIO_PIN_MASK_12;
	 GPIO_Configuration(GPIOA_SFR,&GPIO_InitStructure);
	 /*配置引脚映射功能为CAN模式  外设时钟 */
	 PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOACLKEN,TRUE);
	 PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_CAN2CLKEN,TRUE);
	 GPIO_Pin_RMP_Config(GPIOA_SFR,GPIO_Pin_Num_11,GPIO_RMP_AF9_CAN1);
	 GPIO_Pin_RMP_Config(GPIOA_SFR,GPIO_Pin_Num_12,GPIO_RMP_AF9_CAN1);
 }
 
 /*
 ------------------------------------------------------------------------------
 描述		 : can中断配置
 输入		 : 1.CANx: 指向CAN内存结构的指针，取值为CAN0_SFR~CAN3_SFR
 输出		 : 无
 备注		 :
 ============================================================================*/
 static void xINT_DCAN(CAN_SFRmap* CANx)
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
 void DcanInint(void)
 {
   xGPIO_Dcan();
   xInit_CAN(CAN2_SFR,CAN_BAUDRATE_250K,CAN_MODE_NORMAL);
   xINT_DCAN(CAN2_SFR);
 }

 // 以下是加入缓存发送BCAN报文
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
	 DCandomsg.sended = Sended;
 }
 
 
 //添加数据
 uint32_t DCan_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len)
 {
	 register uint32_t temp,j = 0;
	 temp = can_fifo_get_free(DCanSendBuff);
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
	 DCanSendBuff.buff[temp].sended = SENDED;
	 DCanSendBuff.wr_index += 1;
	 return 1;
 
 }
 
 uint32_t DCan_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len)
 {
	 register uint32_t temp,j = 0;
	 temp = can_fifo_get_free(DCanSendBuff);
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
	 DCanSendBuff.buff[temp].sended = SENDED;
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
	 DCandomsg.sended = SENDED;
	 DCanSendBuff.rd_index += 1;
	 return 1;
 }
 
 void DCanSendTo(void)
 {
	switch(DCandomsg.sended)
	{
	  case SENDED:
		   if(DCanSendFifo())
		   {
			 DCandomsg.sended = DELAYING;
			 CAN_Transmit_DATA(CAN2_SFR,DCandomsg.ID,DCandomsg.data,DCandomsg.len,CAN_DATA_FRAME,DCandomsg.type);
		   }
		   break;
	  case DELAYING:
		   if((CAN_Get_Transmit_Status(CAN2_SFR,CAN_TX_COMPLETE_OFF_STATUS)))
		   {
			 DCandomsg.sended = SENDED;
			 SFR_CLR_BIT_ASM(CAN2_SFR->CTLR, CAN_CTLR_TXR_POS);
		   }
		   break;
	  default:
		   break;
	}
	if(CAN_Get_Transmit_Status(CAN2_SFR,CAN_BUS_OFF_STATUS))
	{
		DcanInint();
	}
 }


 
 





















