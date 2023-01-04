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
  //  while((!CAN_Get_Transmit_Status(CANx,CAN_TX_COMPLETE_OFF_STATUS)))
  //  ;
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
	x=CAN_ERROR_NOERROR;
	return x;
}

void CanInit(void)
{
	xGPIO_CAN();//CAN引脚重映射
	xInit_CAN(CAN0_SFR,CAN_BAUDRATE_250K,CAN_MODE_NORMAL);//CAN模块初始化，125K,正常模式,滤波寄存器组在can.c的宏定义修改
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


void InitCan1Send(void)
{
    can1_fifo_init(&CanSendBuff,CanSendbuffx,CANSENDBUFFDEEP);
    Candomsg.sended = Sended;
}


//添加数据
uint32_t Can_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len)
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
	CanSendBuff.buff[temp].sended = SENDED;
	CanSendBuff.wr_index += 1;
	return 1;

}

uint32_t Can_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len)
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
	CanSendBuff.buff[temp].sended = SENDED;
	CanSendBuff.wr_index += 1;
	return 1;

}


uint32_t CanSendFifo(void)
{
    register uint32_t l,temp;
    //volatile uint32_t l,temp;
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
	Candomsg.sended = SENDED;
	CanSendBuff.rd_index += 1;
	return 1;
}

void Can1SendFifo(void)
{
   switch(Candomsg.sended)
   {
     case SENDED:	
	 	  //if(CanSendFifo()) //20211225日前处理方式
	 	  if((CanSendFifo() /*&& (CAN_Get_Transmit_Status(CAN0_SFR,CAN_TX_BUFFER_STATUS))*/)/* && ((CAN_Get_Transmit_Status(CAN0_SFR,CAN_TX_COMPLETE_OFF_STATUS) == RESET))*/)
	 	  {
		    Candomsg.sended = DELAYING;
			CAN_Transmit_DATA(CAN0_SFR,Candomsg.ID,Candomsg.data,Candomsg.len,CAN_DATA_FRAME,Candomsg.type);
	 	  }
	 	  break;
     case DELAYING:
	 	  
		  if((CAN_Get_Transmit_Status(CAN0_SFR,CAN_TX_COMPLETE_OFF_STATUS)))
		  {
			 SFR_CLR_BIT_ASM(CAN0_SFR->CTLR, CAN_CTLR_TXR_POS);
             Candomsg.sended = SENDED;
		  }
		  
	 	  break;
	 default:
	 	  break;
   }
   if(CAN_Get_Transmit_Status(CAN0_SFR,CAN_BUS_OFF_STATUS))
	{
		CanInit();
	}
}



/*
//#define CAN_TX_STATUS                   ((uint32_t)CAN_CTLR_TXSTA)

TXSTA 发送状态标志位，当节点处于空闲和接收状态时，TXSTA=0；在节点发送帧起
始位时，TXSTA 立即置 1，当发送完帧间域并回到空闲状态时 TXSTA 自动清零。当出现发
送错误且主动发送错误帧时，TXSTA 仍然保持 1。

#define CAN_TX_COMPLETE_OFF_STATUS      ((uint32_t)CAN_CTLR_TCSTA)
TCSTA 发送完毕状态，该位初始状态为 1，置 1 发送请求 TXR 位后 TCSTA 标志会立
即清零，等到当前发送帧的帧结尾发送完毕后（或者遇到了错误或总裁丢失且没有使能重发
送时），TCSTA 重新置 1。

#define CAN_TX_BUFFER_STATUS            ((uint32_t)CAN_CTLR_TXBSTA)
TXBSTA 发送缓冲器状态，TXBSTA=0 时表示模块接收到了发送请求并处于发送状态 
中，此时禁止 CPU 写发送缓冲器，等到当前发送帧的帧结尾发送完毕后（或者遇到了错误 
或总裁丢失且没有使能重发送时）TXBSTA 重新置 1。当模块处于空闲且没有接收到发送请 
求，TXBSTA 会一直保持 1，表示允许 CPU 写发送缓冲器。


/*


/*

CAN初始化记录:


C3 C4   内CAN:   1C4TX 1C4RX  PTE2   PTE1   CAN3  AF9功能    BCAN(额外定义)

C5 C6   外CAN1:  1C1TX 1C1RX  PTA3   PTA2   CAN0  AF9功能    TCAN

C7 C8   外CAN2:  1C3TX 1C3RX  PTA5   PTA4   CAN1  AF9功能    PCAN

C16 C17 外CAN3:  1C2TX 1C2RX  PTA12  PTA11   CAN2  AF9功能    DCAN


*/





