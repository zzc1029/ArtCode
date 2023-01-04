/*
 * Dcan.c
 *
 *  Created on: 2021-9-19
 *      Author: ART
  ע��:���ļ������Ǳ���CAN��ʼ���Լ����ͽ��պ���20210919
 
 C16 C17 ��CAN3:  1C2TX 1C2RX  PTA12  PTA11	 CAN2  AF9����	  DCAN
 
 */

#include "system_init.h"
#include "canfifo.h" 
 
 static void xGPIO_Dcan(void)
 {
	 GPIO_InitTypeDef GPIO_InitStructure;
 
	 /*����CAN��������Ϊ����ģʽ��������Ӧ�˿�ʱ��*/
	 GPIO_InitStructure.m_Mode = GPIO_MODE_RMP;
	 GPIO_InitStructure.m_Speed = GPIO_HIGH_SPEED;
	 GPIO_InitStructure.m_PullDown = GPIO_NOPULL;
	 GPIO_InitStructure.m_PullUp = GPIO_NOPULL;
	 GPIO_InitStructure.m_OpenDrain = GPIO_POD_PP;
	 GPIO_InitStructure.m_Pin = GPIO_PIN_MASK_11|GPIO_PIN_MASK_12;
	 GPIO_Configuration(GPIOA_SFR,&GPIO_InitStructure);
	 /*��������ӳ�书��ΪCANģʽ  ����ʱ�� */
	 PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOACLKEN,TRUE);
	 PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_CAN2CLKEN,TRUE);
	 GPIO_Pin_RMP_Config(GPIOA_SFR,GPIO_Pin_Num_11,GPIO_RMP_AF9_CAN1);
	 GPIO_Pin_RMP_Config(GPIOA_SFR,GPIO_Pin_Num_12,GPIO_RMP_AF9_CAN1);
 }
 
 /*
 ------------------------------------------------------------------------------
 ����		 : can�ж�����
 ����		 : 1.CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN3_SFR
 ���		 : ��
 ��ע		 :
 ============================================================================*/
 static void xINT_DCAN(CAN_SFRmap* CANx)
 {
 
	 /* ���������ж� */
	 //CAN_Set_INT_Enable(CANx,CAN_INT_TRANSMIT,TRUE);
	 /* ���������ж� */
	 CAN_Set_INT_Enable(CANx,CAN_INT_RECEIVE,TRUE);
	 /* ����������ж� */
 //  CAN_Set_INT_Enable(CANx,CAN_INT_DATA_OVERFLOW,TRUE);
	 /* CAN�ж����� */
	 INT_Interrupt_Priority_Config(INT_CAN2,INT_PRIORITY_GROUP_0VS4,2);						 //CAN��ռ���ȼ�4,�����ȼ�0
	 INT_Clear_Interrupt_Flag(INT_CAN2);								 //CAN���жϱ�־
	 INT_Interrupt_Enable(INT_CAN2,TRUE);								 //CAN�ж�ʹ��
	 //INT_All_Enable (TRUE);
 }
 
 
 //Bcan INIT
 void DcanInint(void)
 {
   xGPIO_Dcan();
   xInit_CAN(CAN2_SFR,CAN_BAUDRATE_250K,CAN_MODE_NORMAL);
   xINT_DCAN(CAN2_SFR);
 }

 // �����Ǽ��뻺�淢��BCAN����
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
 
 
 //�������
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


 
 





















