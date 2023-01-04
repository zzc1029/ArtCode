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

static void xGPIO_Bcan(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/*配置CAN引脚类型为复用模式，开启对应端口时钟*/
	GPIO_InitStructure.m_Mode = GPIO_MODE_RMP;
	GPIO_InitStructure.m_Speed = GPIO_HIGH_SPEED;
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;
	GPIO_InitStructure.m_PullUp = GPIO_NOPULL;
	GPIO_InitStructure.m_OpenDrain = GPIO_POD_PP;
	GPIO_InitStructure.m_Pin = GPIO_PIN_MASK_1|GPIO_PIN_MASK_2;
	GPIO_Configuration(GPIOE_SFR,&GPIO_InitStructure);
	PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_CAN3CLKEN,TRUE);
	PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOECLKEN,TRUE);
	GPIO_Pin_RMP_Config(GPIOE_SFR,GPIO_Pin_Num_1,GPIO_RMP_AF9_CAN1);
	GPIO_Pin_RMP_Config(GPIOE_SFR,GPIO_Pin_Num_2,GPIO_RMP_AF9_CAN1);
}

/*
------------------------------------------------------------------------------
描述		: can中断配置
输入		: 1.CANx: 指向CAN内存结构的指针，取值为CAN0_SFR~CAN3_SFR
输出		: 无
备注		:
============================================================================*/
static void xINT_BCAN(CAN_SFRmap* CANx)
{

	/* 开启发送中断 */
	//CAN_Set_INT_Enable(CANx,CAN_INT_TRANSMIT,TRUE);
	/* 开启接收中断 */
	CAN_Set_INT_Enable(CANx,CAN_INT_RECEIVE,TRUE);
	/* 开启包溢出中断 */
//	CAN_Set_INT_Enable(CANx,CAN_INT_DATA_OVERFLOW,TRUE);
	/* CAN中断配置 */
	INT_Interrupt_Priority_Config(INT_CAN3,INT_PRIORITY_GROUP_0VS4,1);						//CAN抢占优先级4,子优先级0
	INT_Clear_Interrupt_Flag(INT_CAN3);									//CAN清中断标志
	INT_Interrupt_Enable(INT_CAN3,TRUE);								//CAN中断使能
	//INT_All_Enable (TRUE);
}


//Bcan INIT
void BcanInint(void)
{
  xGPIO_Bcan();
  xInit_CAN(CAN3_SFR,CAN_BAUDRATE_125K,CAN_MODE_NORMAL);
  xINT_BCAN(CAN3_SFR);
}


// 以下是加入缓存发送BCAN报文
SendToCan BCanSendBuff;

SendCanFifo BCanSendbuffx[CANSENDBUFFDEEP];

SendCanFifo BCandomsg;

void Bcan_fifo_init(SendToCan* fifo,SendCanFifo*buff,uint32_t len)
{
    fifo->wr_index = 0;
    fifo->rd_index = 0;
    fifo->ovfcount = 0;
    fifo->max_len = len;
    fifo->buff = buff;
}


void InitBCanSend(void)
{
    Bcan_fifo_init(&BCanSendBuff,BCanSendbuffx,CANSENDBUFFDEEP);
    BCandomsg.sended = Sended;
}


//添加数据
uint32_t BCan_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len)
{
    register uint32_t temp,j = 0;
	if(BCanSendDisable)
		return 0;
    temp = can_fifo_get_free(BCanSendBuff);
	if(1 > temp)
    {
        BCanSendBuff.ovfcount++;
		BCanSendBuff.rd_index = BCanSendBuff.wr_index;
        return 0;
    }
	temp = (BCanSendBuff.wr_index & (BCanSendBuff.max_len - 1));
	for(j = 0;j < len;j++)
	  BCanSendBuff.buff[temp].data[j] = buffer[j];
	
	BCanSendBuff.buff[temp].ID = id;
	BCanSendBuff.buff[temp].len = len;
	BCanSendBuff.buff[temp].type = CAN_FRAME_FORMAT_SFF;
	BCanSendBuff.buff[temp].sended = SENDED;
	BCanSendBuff.wr_index += 1;
	return 1;

}

uint32_t BCan_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len)
{
    register uint32_t temp,j = 0;
	if(BCanSendDisable)
		return 0;
    temp = can_fifo_get_free(BCanSendBuff);
	if(1 > temp)
    {
        BCanSendBuff.ovfcount++;
		BCanSendBuff.rd_index = BCanSendBuff.wr_index;
        return 0;
    }
	temp = (BCanSendBuff.wr_index & (BCanSendBuff.max_len - 1));
	for(j = 0;j < len;j++)
	  BCanSendBuff.buff[temp].data[j] = buffer[j];
	
	BCanSendBuff.buff[temp].ID = id;
	BCanSendBuff.buff[temp].len = len;
	BCanSendBuff.buff[temp].type = CAN_FRAME_FORMAT_EFF;
	BCanSendBuff.buff[temp].sended = SENDED;
	BCanSendBuff.wr_index += 1;
	return 1;

}




uint32_t BCanSendFifo(void)
{
    register uint32_t l,temp;
	if(BCanSendDisable)
		return 0;
    temp = can_fifo_get_count(BCanSendBuff);
    if(temp < 1)
    {
        return 0;
    }
	
	temp = (BCanSendBuff.rd_index & (BCanSendBuff.max_len - 1));
	
	for(l = 0;l < BCanSendBuff.buff[temp].len; l++)
      BCandomsg.data[l] = BCanSendBuff.buff[temp].data[l];
	
	BCandomsg.ID = BCanSendBuff.buff[temp].ID;
	BCandomsg.len = BCanSendBuff.buff[temp].len;
	BCandomsg.type = BCanSendBuff.buff[temp].type;
	BCandomsg.sended = SENDED;
	BCanSendBuff.rd_index += 1;
	return 1;
}

void BCanSendTo(void)
{
   switch(BCandomsg.sended)
   {
     case SENDED:
	 	  if(BCanSendFifo())
	 	  {
		    BCandomsg.sended = DELAYING;
			CAN_Transmit_DATA(CAN3_SFR,BCandomsg.ID,BCandomsg.data,BCandomsg.len,CAN_DATA_FRAME,BCandomsg.type);
	 	  }
	 	  break;
     case DELAYING:
	 	  if(CAN_Get_Transmit_Status(CAN3_SFR,CAN_TX_COMPLETE_OFF_STATUS))
	 	  {
			SFR_CLR_BIT_ASM(CAN3_SFR->CTLR, CAN_CTLR_TXR_POS);
		  	BCandomsg.sended = SENDED;
			BcanDelay = 0;
	 	  }
	 	  break;
	 default:
	 	  break;
   }
   if(CAN_Get_Transmit_Status(CAN3_SFR,CAN_BUS_OFF_STATUS))
   {
	   BcanInint();
   }
}

// 以下BCAN接收CAN报文
// Bcan 
const uint32_t BCanIdTable[] =
{
	/******* VCU  ***********************/
        0x681,
	    0x671,
		0x561,
        0x682,
	    0x672,
		0x562,
        0x683,
	    0x673,
		0x563,
        //默认仪表boot
        0x526,
        //参数设置
        0x616,
        //烧录程序ID
        0x520,
        0x521,
        0x522,
        0x523,
        0x524,
        0x525,
        0x530,
};


#define BCAN_DATA_MAX  (sizeof(BCanIdTable)/sizeof(BCanIdTable[0]))
#define BCAN_ID_SUM   ((sizeof(BCanIdTable)/sizeof(BCanIdTable[0])))

volatile uint8_t BCanData[BCAN_DATA_MAX][8];


uint16_t BGetIndexFromID(uint32_t id)
{
	uint16_t i;
	for(i=0;i<BCAN_ID_SUM;i++)
	{
		if(BCanIdTable[i] == id)
			return i;
	}
	return BCAN_ID_SUM;
}

u16 BcanID(u32 id)
{
	u16 i;
	for(i=0;i<BCAN_ID_SUM;i++)
	{
		if(BCanIdTable[i] == id)
			return i;
	}
	return BCAN_ID_SUM;
}

u32 BcanGetIDFromIndex(u16 index)
{
	if(index<BCAN_ID_SUM)
	{
		return BCanIdTable[index];
	}
	else
	{
		return 0;
	}
}



static volatile uint8_t Bdata[8] = {0,0,0,0,0,0,0,0};
//CAN1接收函数
void Can3_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue)
{
   u32 id = 0;
   uint16_t index = 0;
   id = GetID(CAN_MessageStructrue);
   index = BGetIndexFromID(id);
   if(index < BCAN_ID_SUM)
   {
	   //timeout 清零   动作未加入
	   GeCantData(CAN_MessageStructrue,BCanData[index]);
	   GeCantData(CAN_MessageStructrue,Bdata);
	   switch(id)
	   {
	       //前部模块信息
		   case 0x681:
			   fbcm_off_line = 0;
			   bcm_sw1_f.word = ((uint16_t)Bdata[1]<<8)+ Bdata[0];
			   bcm_sw2_f.byte = Bdata[2];
			   bcm_sw1_f.word ^= fmode_mask.U16[0];
			   bcm_sw2_f.byte ^= fmode_mask.U16[1];
			   bcm_frq_f = (uint16_t)(((uint16_t)Bdata[4]<<8)+ Bdata[3]);

			   break;
		   case 0x0671:
			   bcm_senor1_f = (uint16_t)(((uint16_t)Bdata[1]<<8)+ Bdata[0]);
               bcm_senor2_f = (uint16_t)(((uint16_t)Bdata[3]<<8)+ Bdata[2]);
			   break;
		   case 0x561:
			   bcm_out_st_f.word = ((uint16_t)Bdata[1]<<8)+ Bdata[0];
               bcm_fb_st_f.dword = ((uint32_t)Bdata[5]<<24) + ((uint32_t)Bdata[4]<<16)\
                            +((uint16_t)Bdata[3]<<8) + Bdata[2];
			   break;
           //后部模块信息
		   case 0x682:
			   rbcm_off_line = 0;
			   bcm_sw1_r.word = ((uint16_t)Bdata[1]<<8)+ Bdata[0];
			   bcm_sw2_r.byte = Bdata[2];
			   bcm_sw1_r.word ^= rmode_mask.U16[0];
			   bcm_sw2_r.byte ^= rmode_mask.U16[1];
			   bcm_frq_r = (uint16_t)(((uint16_t)Bdata[4]<<8)+ Bdata[3]);

			   break;
		   case 0x0672:
			   bcm_senor1_r = (uint16_t)(((uint16_t)Bdata[1]<<8)+ Bdata[0]);
               bcm_senor2_r = (uint16_t)(((uint16_t)Bdata[3]<<8)+ Bdata[2]);
			   break;
		   case 0x562:
			   bcm_out_st_r.word = ((uint16_t)Bdata[1]<<8)+ Bdata[0];
               bcm_fb_st_r.dword = ((uint32_t)Bdata[5]<<24) + ((uint32_t)Bdata[4]<<16)\
                            +((uint16_t)Bdata[3]<<8) + Bdata[2];
			   break;	
           //顶部模块信息
		   case 0x683:
			   tbcm_off_line = 0;
			   bcm_sw1_t.word = ((uint16_t)Bdata[1]<<8)+ Bdata[0];
			   bcm_sw2_t.byte = Bdata[2];
			   bcm_sw1_t.word ^= tmode_mask.U16[0];
			   bcm_sw2_t.byte ^= tmode_mask.U16[1];
			   bcm_frq_t = (uint16_t)(((uint16_t)Bdata[4]<<8)+ Bdata[3]);

			   break;
		   case 0x0673:
			   bcm_senor1_t = (uint16_t)(((uint16_t)Bdata[1]<<8)+ Bdata[0]);
               bcm_senor2_t = (uint16_t)(((uint16_t)Bdata[3]<<8)+ Bdata[2]);
			   break;
		   case 0x563:
			   bcm_out_st_t.word = ((uint16_t)Bdata[1]<<8)+ Bdata[0];
               bcm_fb_st_t.dword = ((uint32_t)Bdata[5]<<24) + ((uint32_t)Bdata[4]<<16)\
                            +((uint16_t)Bdata[3]<<8) + Bdata[2];
			   break;
               //参数设置
          case 0x616:
                
			   break;
		 case 0x520:
		 case 0x521:
		 case 0x522:
		 case 0x523:
		 case 0x524:
		 case 0x525:
		 	  if(Bdata[0] == 3)
                BCanSendDisable = 0;
              else
                BCanSendDisable = 1;
		      break;
		 case 0x526:
				switch (Bdata[0])
				{
					case BLCMD_ToBootStatus:
						 ERASEPAGE(0x8000);
						 SYSCTL_System_Reset_Enable(TRUE);
						break;
					case BLCMD_GetInfo:
						blstatus = BL_GetInfo;
						break;
				}
			  break;
		case 0x530:
			 bootloader = Bdata[0];
			 if(bootloader == 0x1)
			 {
                bootcmd = 0xa0;
				bootloader = 0;
			 }
			 break;
		   default:
			    break;
	   }
   }
}











