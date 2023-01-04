/**
  ******************************************************************************
  * 文件名 can.c
  * 作  者  ChipON_AE/FAE_Group
  * 日  期  2019-10-19
  * 描  述  该文件提供了CAN模块相关的配置与发送功能，包括
  *          + CAN引脚重映射
  *          + CAN中断配置
  *          + CAN发送
  *          + CAN初始化
  ******************************************************************************/
#include "system_init.h"
#include "canfifo.h" 




/*============================================================================
 *void xGPIO_CAN()
------------------------------------------------------------------------------
描述		: can引脚重定义
输入		: 无
输出		: 无
备注		:
============================================================================*/
void xGPIO_CAN(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/*配置CAN引脚类型为复用模式，开启对应端口时钟*/
	GPIO_InitStructure.m_Mode = GPIO_MODE_RMP;
	GPIO_InitStructure.m_Speed = GPIO_HIGH_SPEED;
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;
	GPIO_InitStructure.m_PullUp = GPIO_NOPULL;
	GPIO_InitStructure.m_OpenDrain = GPIO_POD_PP;
	GPIO_InitStructure.m_Pin = GPIO_PIN_MASK_2|GPIO_PIN_MASK_3;
	GPIO_Configuration(GPIOA_SFR,&GPIO_InitStructure);

	GPIO_Pin_RMP_Config(GPIOA_SFR,GPIO_Pin_Num_2,GPIO_RMP_AF9_CAN1);
	GPIO_Pin_RMP_Config(GPIOA_SFR,GPIO_Pin_Num_3,GPIO_RMP_AF9_CAN1);

	PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOACLKEN,TRUE);
	PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_CAN0CLKEN,TRUE);
}
/*============================================================================
 *void xInit_CAN(CAN_SFRmap* CANx,uint8_t Bdrt,uint32_t MODE)
------------------------------------------------------------------------------
描述		: can模块初始化
输入		: 1.CANx: 指向CAN内存结构的指针，取值为CAN0_SFR~CAN3_SFR
		  2.Bdrt  波特率，见canhl.h定义
		  3.MODE  工作模式：CAN_MODE_NORMAL CAN_MODE_SILENT CAN_MODE_LOOPBACK CAN_MODE_SILENT_LOOPBACK
输出		: 无
备注		:
============================================================================*/
void xInit_CAN(CAN_SFRmap* CANx,uint8_t Bdrt,uint32_t MODE)
{
	CAN_InitTypeDef CAN_InitStructure;
	/* CAN时钟使能，复位禁能 */

	CAN_Reset(CANx);
	CAN_InitStructure.m_Acceptance = xCAN_ACR;                    //验收滤波
	CAN_InitStructure.m_AcceptanceMask = xCAN_MSK;		          //验收屏蔽
	CAN_InitStructure.m_WorkSource = CAN_SOURCE_SCLK_DIV_2;      //CAN时钟内部高频

	if(Bdrt==CAN_BAUDRATE_125K)
	{
#ifdef SYSCLK_FREQ_120MHz
		CAN_InitStructure.m_BaudRate = 29;					  //时钟分频  2M
#elif SYSCLK_FREQ_96MHz
		CAN_InitStructure.m_BaudRate = 23;
#elif 	SYSCLK_FREQ_72MHz
		CAN_InitStructure.m_BaudRate = 17;
#elif 	SYSCLK_FREQ_48MHz
		CAN_InitStructure.m_BaudRate = 11;
#endif
	}
	else if(Bdrt==CAN_BAUDRATE_250K)
	{
#ifdef SYSCLK_FREQ_120MHz
		CAN_InitStructure.m_BaudRate = 14;					  //时钟分频  4M
#elif SYSCLK_FREQ_96MHz
		CAN_InitStructure.m_BaudRate = 11;
#elif 	SYSCLK_FREQ_72MHz
		CAN_InitStructure.m_BaudRate = 8;
#elif 	SYSCLK_FREQ_48MHz
		CAN_InitStructure.m_BaudRate = 5;
#endif
	}
	else if(Bdrt==CAN_BAUDRATE_500K)
	{
#ifdef SYSCLK_FREQ_96MHz
		CAN_InitStructure.m_BaudRate = 5; //时钟分频  8M
#elif 	SYSCLK_FREQ_48MHz
		CAN_InitStructure.m_BaudRate = 2;
#endif
	}

	//TSEG1设置与TSEG2设置比值一般为70-80%配合CAN的采样要求
	/*
	 采样率可设置：（1 + m_TimeSeg1）/(1 + m_TimeSeg1 + m_TimeSeg2) 最好设置在85%~90%。

	 */
	CAN_InitStructure.m_TimeSeg1 = 11;						   //TSEG1
	CAN_InitStructure.m_TimeSeg2 = 2;						   //TSEG2
	//CAN_InitStructure.m_TimeSeg1 = 4;						   //TSEG1
	//CAN_InitStructure.m_TimeSeg2 = 1;						   //TSEG2
	CAN_InitStructure.m_BusSample = CAN_BUS_SAMPLE_3_TIMES;	   //采样点次数
	CAN_InitStructure.m_SyncJumpWidth = 1;					   //同步跳转宽度
	CAN_InitStructure.m_Enable = TRUE;						   //使能
	CAN_InitStructure.m_Mode = MODE;				           //模式
	CAN_Configuration(CANx,&CAN_InitStructure);			   //写入配置
}
/*============================================================================
 *void xINT_CAN(CAN_SFRmap* CANx)
------------------------------------------------------------------------------
描述		: can中断配置
输入		: 1.CANx: 指向CAN内存结构的指针，取值为CAN0_SFR~CAN3_SFR
输出		: 无
备注		:
============================================================================*/
void xINT_CAN(CAN_SFRmap* CANx)
{

	/* 开启发送中断 */
	//CAN_Set_INT_Enable(CANx,CAN_INT_TRANSMIT,TRUE);
	/* 开启接收中断 */
	CAN_Set_INT_Enable(CANx,CAN_INT_RECEIVE,TRUE);
	/* 开启包溢出中断 */
//	CAN_Set_INT_Enable(CANx,CAN_INT_DATA_OVERFLOW,TRUE);
	/* CAN中断配置 */
	INT_Interrupt_Priority_Config(INT_CAN0,INT_PRIORITY_GROUP_0VS4,0);						//CAN抢占优先级4,子优先级0
	INT_Clear_Interrupt_Flag(INT_CAN0);									//CAN清中断标志
	INT_Interrupt_Enable(INT_CAN0,TRUE);								//CAN中断使能
}

/*============================================================================
 *void CAN_Transmit_DATA(CAN_SFRmap* CANx, uint8_t *data , uint8_t lenth)
------------------------------------------------------------------------------
描述		: 数据发送加载
输入		: 1.要初始化的CAN标号	CAN0_SFR、CAN1_SFR、CAN2_SFR
		  2.ID
		  2.发送数据数组地址
		  3.发送数据长度
		  4.帧类型        CAN_DATA_FRAME数据帧                     CAN_REMOTE_FRAME远程帧
		  5.帧格式        CAN_FRAME_FORMAT_SFF标准帧     CAN_FRAME_FORMAT_EFF扩展帧
输出		: CAN_ERROR_BUFFERFULL  CAN_ERROR_NOERROR
备注		:
============================================================================*/
CAN_ErrorT CAN_Transmit_DATA(CAN_SFRmap* CANx,   //CAN通道
						uint32_t  TargetID,//ID
						uint8_t*  data ,   //数据指针
						uint8_t   lenth,   //长度
						uint32_t  MsgType, //帧类型        CAN_DATA_FRAME//数据帧           CAN_REMOTE_FRAME//远程帧
						uint32_t  RmtFrm   //帧格式        CAN_FRAME_FORMAT_SFF//标准帧     CAN_FRAME_FORMAT_EFF//扩展帧
						)
{
	CAN_ErrorT x;
	uint8_t i;
	uint16_t j = 0xffff;
	CAN_MessageTypeDef	CAN_MessageStructure;

	CAN_MessageStructure.m_FrameFormat = RmtFrm;             	 //帧格式
	CAN_MessageStructure.m_RemoteTransmit = MsgType;		 	 //帧类型
	if(RmtFrm==CAN_FRAME_FORMAT_SFF)//标准帧
	{
		CAN_MessageStructure.m_StandardID = TargetID;			 //标准帧ID
		CAN_MessageStructure.m_ExtendedID = 0;			         //扩展帧ID
	}
	else if(RmtFrm==CAN_FRAME_FORMAT_EFF)//扩展帧
	{
		CAN_MessageStructure.m_StandardID = 0;					 //标准帧ID
		CAN_MessageStructure.m_ExtendedID = TargetID;			 //扩展帧ID
	}
	if(lenth>8)
	{
		lenth=8;
	}
	CAN_MessageStructure.m_DataLength = lenth;			    	 //长度
	for(i=0;i<lenth;i++)
	{
		CAN_MessageStructure.m_Data[i] = data[i];				 //数据
	}

	/* 发送缓冲器空 */
	if((!CAN_Get_Transmit_Status(CANx,CAN_TX_BUFFER_STATUS)))
	{
		x=CAN_ERROR_BUFFERFULL;
		return x;
    }

	/* 转载数据到发送缓冲器 */
	CAN_Transmit_Message_Configuration(CANx,&CAN_MessageStructure);
	/* 单次发送 */
	//CAN_Transmit_Single(CANx);
	SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_ATX_POS);
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_ATX_POS);
	SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_TXR_POS);
	SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_TXR_POS);
	//CAN_Transmit_Repeat(CANx);

	x=CAN_ERROR_NOERROR;
	return x;
}

void BcanInit(void)
{
	xGPIO_CAN();//CAN引脚重映射
	xInit_CAN(CAN0_SFR,CAN_BAUDRATE_125K,CAN_MODE_NORMAL);//CAN模块初始化，125K,正常模式,滤波寄存器组在can.c的宏定义修改
	xINT_CAN(CAN0_SFR);//使能CAN接收中断
}

//发送标准数据帧
//CAN_ErrorT Can_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len)
//{
//	CAN_ErrorT sendres = CAN_WAIT_SEND;
//	sendres = CAN_Transmit_DATA(CAN1_SFR,id,buffer,len,CAN_DATA_FRAME,CAN_FRAME_FORMAT_SFF);
//	return sendres;
//}

SendToCan CanSendBuff;

SendCanFifo CanSendbuffx[CANSENDBUFFDEEP];

SendCanFifo Candomsg;

void can1_fifo_init(SendToCan* fifo,SendCanFifo*buff,uint32_t len)
{
    fifo->wr_index = 0;
    fifo->rd_index = 0;
    fifo->ovfcount = 0;
    fifo->max_len = len;
    fifo->buff = buff;
}


void InitBCanSend(void)
{
    can1_fifo_init(&CanSendBuff,CanSendbuffx,CANSENDBUFFDEEP);
    Candomsg.sended = CANSENDED;
}


//添加数据
uint32_t BCan_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len)
{
    register uint32_t temp,j = 0;
    temp = can_fifo_get_free(CanSendBuff);
	if(1 > temp)
    {
        CanSendBuff.ovfcount++;
		CanSendBuff.rd_index = CanSendBuff.wr_index;
        return 0;
    }
	temp = (CanSendBuff.wr_index & (CanSendBuff.max_len - 1));
	for(j = 0;j < len;j++)
	  CanSendBuff.buff[temp].data[j] = buffer[j];
	
	CanSendBuff.buff[temp].ID = id;
	CanSendBuff.buff[temp].len = len;
	CanSendBuff.buff[temp].type = CAN_FRAME_FORMAT_SFF;
	CanSendBuff.buff[temp].sended = CANSENDED;
	CanSendBuff.wr_index += 1;
	return 1;

}

uint32_t BCan_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len)
{
    register uint32_t temp,j = 0;
    temp = can_fifo_get_free(CanSendBuff);
	if(1 > temp)
    {
        CanSendBuff.ovfcount++;
		CanSendBuff.rd_index = CanSendBuff.wr_index;
        return 0;
    }
	temp = (CanSendBuff.wr_index & (CanSendBuff.max_len - 1));
	for(j = 0;j < len;j++)
	  CanSendBuff.buff[temp].data[j] = buffer[j];
	
	CanSendBuff.buff[temp].ID = id;
	CanSendBuff.buff[temp].len = len;
	CanSendBuff.buff[temp].type = CAN_FRAME_FORMAT_EFF;
	CanSendBuff.buff[temp].sended = CANSENDED;
	CanSendBuff.wr_index += 1;
	return 1;

}


uint32_t BCanSendFifo(void)
{
    register uint32_t l,temp;
    temp = can_fifo_get_count(CanSendBuff);
    if(temp < 1)
    {
        return 0;
    }
	
	temp = (CanSendBuff.rd_index & (CanSendBuff.max_len - 1));
	
	for(l = 0;l < CanSendBuff.buff[temp].len; l++)
      Candomsg.data[l] = CanSendBuff.buff[temp].data[l];
	
	Candomsg.ID = CanSendBuff.buff[temp].ID;
	Candomsg.len = CanSendBuff.buff[temp].len;
	Candomsg.type = CanSendBuff.buff[temp].type;
	Candomsg.sended = CANSENDED;
	CanSendBuff.rd_index += 1;
	return 1;
}

void BCanSendTo(void)
{
   switch(Candomsg.sended)
   {
     case CANSENDED:
	 	  if(BCanSendFifo())
	 	  {
		    Candomsg.sended = CANDELAYING;
			CAN_Transmit_DATA(CAN0_SFR,Candomsg.ID,Candomsg.data,Candomsg.len,CAN_DATA_FRAME,Candomsg.type);
	 	  }
	 	  break;
     case CANDELAYING:
	 	  if((CAN_Get_Transmit_Status(CAN0_SFR,CAN_TX_COMPLETE_OFF_STATUS)))
	 	  {
			SFR_CLR_BIT_ASM(CAN0_SFR->CTLR, CAN_CTLR_TXR_POS);
		  	Candomsg.sended = CANSENDED;
	 	  }
	 	  break;
	 default:

	 	  break;
   }

   if(CAN_Get_Transmit_Status(CAN0_SFR,CAN_BUS_OFF_STATUS))
   {
	   BcanInit();
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
        //最新模块程序添加功率器件反馈电流值
        #if Has_Fmode
        0x690,
        0x691,
        #endif
		#if Has_Rmode
        0x692,
        0x693,
        #endif
		#if Has_Tmode
        0x694,
        0x695
        #endif
};


#define BCAN_DATA_MAX  (sizeof(BCanIdTable)/sizeof(BCanIdTable[0]))
#define BCAN_ID_SUM   ((sizeof(BCanIdTable)/sizeof(BCanIdTable[0])))

volatile uint8_t BCanData[BCAN_DATA_MAX][8];


uint16_t BcanGetIndexFromID(uint32_t id)
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
	if(index < BCAN_ID_SUM)
	{
		return BCanIdTable[index];
	}
	else
	{
		return 0;
	}
}



static volatile uint8_t data[8] = {0,0,0,0,0,0,0,0};
//CAN0接收函数
void Can0_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue)
{
   u32 id = 0;
   uint16_t index = 0;
   id = GetID(CAN_MessageStructrue);
   index = BcanGetIndexFromID(id);
   if(index < BCAN_ID_SUM)
   {
	   //timeout 清零   动作未加入
	   GeCantData(CAN_MessageStructrue,BCanData[index]);
	   GeCantData(CAN_MessageStructrue,data);
	   switch(id)
	   {
	       //前部模块信息
		   case 0x681:
			   fbcm_off_line = 0;
			   bcm_sw1_f.word = ((uint16_t)data[1]<<8)+ data[0];
			   bcm_sw2_f.byte = data[2];
			   bcm_sw1_f.word ^= fmode_mask.U16[0];
			   bcm_sw2_f.byte ^= fmode_mask.U16[1];
			   bcm_frq_f = (uint16_t)(((uint16_t)data[4]<<8)+ data[3]);

			   break;
		   case 0x0671:
			   bcm_senor1_f = (uint16_t)(((uint16_t)data[1]<<8)+ data[0]);
               bcm_senor2_f = (uint16_t)(((uint16_t)data[3]<<8)+ data[2]);
			   break;
		   case 0x561:
			   bcm_out_st_f.word = ((uint16_t)data[1]<<8)+ data[0];
               bcm_fb_st_f.dword = ((uint32_t)data[5]<<24) + ((uint32_t)data[4]<<16)\
                            +((uint16_t)data[3]<<8) + data[2];
			   break;
           //后部模块信息
		   case 0x682:
			   rbcm_off_line = 0;
			   bcm_sw1_r.word = ((uint16_t)data[1]<<8)+ data[0];
			   bcm_sw2_r.byte = data[2];
			   bcm_sw1_r.word ^= rmode_mask.U16[0];
			   bcm_sw2_r.byte ^= rmode_mask.U16[1];
			   bcm_frq_r = (uint16_t)(((uint16_t)data[4]<<8)+ data[3]);

			   break;
		   case 0x0672:
			   bcm_senor1_r = (uint16_t)(((uint16_t)data[1]<<8)+ data[0]);
               bcm_senor2_r = (uint16_t)(((uint16_t)data[3]<<8)+ data[2]);
			   break;
		   case 0x562:
			   bcm_out_st_r.word = ((uint16_t)data[1]<<8)+ data[0];
               bcm_fb_st_r.dword = ((uint32_t)data[5]<<24) + ((uint32_t)data[4]<<16)\
                            +((uint16_t)data[3]<<8) + data[2];
			   break;
           //顶部模块信息
		   case 0x683:
			   tbcm_off_line = 0;
			   bcm_sw1_t.word = ((uint16_t)data[1]<<8)+ data[0];
			   bcm_sw2_t.byte = data[2];
			   bcm_sw1_t.word ^= tmode_mask.U16[0];
			   bcm_sw2_t.byte ^= tmode_mask.U16[1];
			   bcm_frq_t = (uint16_t)(((uint16_t)data[4]<<8)+ data[3]);

			   break;
		   case 0x0673:
			   bcm_senor1_t = (uint16_t)(((uint16_t)data[1]<<8)+ data[0]);
               bcm_senor2_t = (uint16_t)(((uint16_t)data[3]<<8)+ data[2]);
			   break;
		   case 0x563:
			   bcm_out_st_t.word = ((uint16_t)data[1]<<8)+ data[0];
               bcm_fb_st_t.dword = ((uint32_t)data[5]<<24) + ((uint32_t)data[4]<<16)\
                            +((uint16_t)data[3]<<8) + data[2];
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
		 	  if(data[0] == 3)
                BCanSendDisable = 0;
              else
                BCanSendDisable = 1;
		      break;
		case 0x530:
			// bootloader = data[0];
			// if(bootloader == 0x1)
			// {
              //  bootcmd = 0xa0;
			//	bootloader = 0;
			// }
			 break;
		 case 0x526:
				switch (data[0])
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

		#if Has_Fmode
        case 0x690:
			 CopyData(FrontCurrent,data,8);
			 break;
		case 0x691:
			 CopyData(FrontCurrent,data + 8,8);
			 break;
		#endif
        #if Has_Rmode
        case 0x692:
			 CopyData(RearCurrent,data,8);
			 break;
		case 0x693:
			 CopyData(RearCurrent,data + 8,8);
			 break;
       #endif
       #if Has_Tmode
        case 0x694:
			 CopyData(TopCurrent,data,8);
			 break;
		case 0x695:
			 CopyData(TopCurrent,data + 8,8);
			 break;
        #endif

		   default:
			    break;
	   }
   }
}




/*

CAN初始化记录:

C3 C4   外CAN1:  1C1TX 1C1RX  PTA3   PTA2   CAN0  AF9功能    TCAN

C5 C6   内CAN:   1C4TX 1C4RX  PTB0   PTB1   CAN2  AF9功能    BCAN(额外定义)



C7 C8   外CAN2:  1C3TX 1C3RX  PTA5   PTA4   CAN1  AF9功能    PCAN

C16 C17 外CAN3:  1C2TX 1C2RX  PTA12  PTA11   CAN2  AF9功能    DCAN


*/





