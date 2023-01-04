/*
 * Bcan.c
 *
 *  Created on: 2021-9-19
 *      Author: ART
 注意:该文件用于仪表内CAN初始化以及发送接收函数20210919
 C3 C4   内CAN:   1C4TX 1C4RX  PTE2   PTE1   CAN3  AF9功能
 */

#include "system_init.h"
#include "canfifo.h" 

static void xGPIO_Pcan3(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/*配置CAN引脚类型为复用模式，开启对应端口时钟*/
	GPIO_InitStructure.m_Mode = GPIO_MODE_RMP;
	GPIO_InitStructure.m_Speed = GPIO_HIGH_SPEED;
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;
	GPIO_InitStructure.m_PullUp = GPIO_NOPULL;
	GPIO_InitStructure.m_OpenDrain = GPIO_POD_PP;
	GPIO_InitStructure.m_Pin = GPIO_PIN_MASK_5|GPIO_PIN_MASK_6;
	GPIO_Configuration(GPIOD_SFR,&GPIO_InitStructure);
	PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_CAN4CLKEN,TRUE);
	PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIODCLKEN,TRUE);
	GPIO_Pin_RMP_Config(GPIOD_SFR,GPIO_Pin_Num_5,GPIO_RMP_AF9_CAN1);
	GPIO_Pin_RMP_Config(GPIOD_SFR,GPIO_Pin_Num_6,GPIO_RMP_AF9_CAN1);
}

/*
------------------------------------------------------------------------------
描述		: can中断配置
输入		: 1.CANx: 指向CAN内存结构的指针，取值为CAN0_SFR~CAN3_SFR
输出		: 无
备注		:
============================================================================*/
static void xINT_PCAN3(CAN_SFRmap* CANx)
{

	/* 开启发送中断 */
	//CAN_Set_INT_Enable(CANx,CAN_INT_TRANSMIT,TRUE);
	/* 开启接收中断 */
	CAN_Set_INT_Enable(CANx,CAN_INT_RECEIVE,TRUE);
	/* 开启包溢出中断 */
//	CAN_Set_INT_Enable(CANx,CAN_INT_DATA_OVERFLOW,TRUE);
	/* CAN中断配置 */
	INT_Interrupt_Priority_Config(INT_CAN4,INT_PRIORITY_GROUP_0VS4,1);						//CAN抢占优先级4,子优先级0
	INT_Clear_Interrupt_Flag(INT_CAN4);									//CAN清中断标志
	INT_Interrupt_Enable(INT_CAN4,TRUE);								//CAN中断使能
	//INT_All_Enable (TRUE);
}


//Bcan INIT
void Pcan3Inint(void)
{
  xGPIO_Pcan3();
  xInit_CAN(CAN4_SFR,CAN_BAUDRATE_250K,CAN_MODE_NORMAL);
  xINT_PCAN3(CAN4_SFR);
}


// 以下是加入缓存发送BCAN报文
SendToCan PCan3SendBuff;

SendCanFifo PCan3Sendbuffx[CANSENDBUFFDEEP];

SendCanFifo PCan3domsg;

void Pcan3_fifo_init(SendToCan* fifo,SendCanFifo*buff,uint32_t len)
{
    fifo->wr_index = 0;
    fifo->rd_index = 0;
    fifo->ovfcount = 0;
    fifo->max_len = len;
    fifo->buff = buff;
}


void InitPCan3Send(void)
{
    Pcan3_fifo_init(&PCan3SendBuff,PCan3Sendbuffx,CANSENDBUFFDEEP);
    PCan3domsg.sended = CANSENDED;
}


//添加数据
uint32_t PCan3_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len)
{
    register uint32_t temp,j = 0;
	//if(CanSendDisable)
	//	return 0;
    temp = can_fifo_get_free(PCan3SendBuff);
	if(1 > temp)
    {
		PCan3SendBuff.ovfcount++;
		PCan3SendBuff.rd_index = PCan3SendBuff.wr_index;
        return 0;
    }
	temp = (PCan3SendBuff.wr_index & (PCan3SendBuff.max_len - 1));
	for(j = 0;j < len;j++)
		PCan3SendBuff.buff[temp].data[j] = buffer[j];
	
	PCan3SendBuff.buff[temp].ID = id;
	PCan3SendBuff.buff[temp].len = len;
	PCan3SendBuff.buff[temp].type = CAN_FRAME_FORMAT_SFF;
	PCan3SendBuff.buff[temp].sended = CANSENDED;
	PCan3SendBuff.wr_index += 1;
	return 1;

}

uint32_t PCan3_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len)
{
    register uint32_t temp,j = 0;
	//if(BCanSendDisable)
	//	return 0;
    temp = can_fifo_get_free(PCan3SendBuff);
	if(1 > temp)
    {
		PCan3SendBuff.ovfcount++;
		PCan3SendBuff.rd_index = PCan3SendBuff.wr_index;
        return 0;
    }
	temp = (PCan3SendBuff.wr_index & (PCan3SendBuff.max_len - 1));
	for(j = 0;j < len;j++)
		PCan3SendBuff.buff[temp].data[j] = buffer[j];
	
	PCan3SendBuff.buff[temp].ID = id;
	PCan3SendBuff.buff[temp].len = len;
	PCan3SendBuff.buff[temp].type = CAN_FRAME_FORMAT_EFF;
	PCan3SendBuff.buff[temp].sended = CANSENDED;
	PCan3SendBuff.wr_index += 1;
	return 1;

}




uint32_t PCan3SendFifo(void)
{
    register uint32_t l,temp;
    temp = can_fifo_get_count(PCan3SendBuff);
    if(temp < 1)
    {
        return 0;
    }
	
	temp = (PCan3SendBuff.rd_index & (PCan3SendBuff.max_len - 1));
	
	for(l = 0;l < PCan3SendBuff.buff[temp].len; l++)
      PCan3domsg.data[l] = PCan3SendBuff.buff[temp].data[l];
	
	PCan3domsg.ID = PCan3SendBuff.buff[temp].ID;
	PCan3domsg.len = PCan3SendBuff.buff[temp].len;
	PCan3domsg.type = PCan3SendBuff.buff[temp].type;
	PCan3domsg.sended = CANSENDED;
	PCan3SendBuff.rd_index += 1;
	return 1;
}

void PCan3SendTo(void)
{
   switch(PCan3domsg.sended)
   {
     case CANSENDED:
	 	  if(PCan3SendFifo())
	 	  {
		    PCan3domsg.sended = CANDELAYING;
			CAN_Transmit_DATA(CAN4_SFR,PCan3domsg.ID,PCan3domsg.data,PCan3domsg.len,CAN_DATA_FRAME,PCan3domsg.type);
	 	  }
	 	  break;
     case CANDELAYING:
	 	  if((CAN_Get_Transmit_Status(CAN4_SFR,CAN_TX_COMPLETE_OFF_STATUS)))
	 	  {
			SFR_CLR_BIT_ASM(CAN4_SFR->CTLR, CAN_CTLR_TXR_POS);
		  	PCan3domsg.sended = CANSENDED;
	 	  }
	 	  break;
	 default:
	 	  break;
   }
   if(CAN_Get_Transmit_Status(CAN4_SFR,CAN_BUS_OFF_STATUS))
   {
	   Pcan3Inint();
   }
}

// 以下BCAN接收CAN报文
// Bcan













