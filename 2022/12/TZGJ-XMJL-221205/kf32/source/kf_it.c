/****************************************************************************************
 *
 * 文件名 kf_it.c
 * 作  者	ChipON_AE/FAE_Group
 * 版  本	V2.1
 * 日  期	2019-11-16
 * 描  述  该文件提供了中断入口地址,在CAN1中断处理RAM报文
 *
 ****************************************************************************************/
#include"system_init.h"


void __attribute__((interrupt))_CAN2_exception (void)
{
	uint8_t i;
	uint32_t id;
	static uint8_t Receice_addr = 0x00;//接收RAM偏移地址
	static uint8_t bus_off_count = 0;
	CAN_MessageTypeDef CAN_MessageStructrue;//接收报文结构体
	/* 清CAN中断标志 */
	INT_Clear_Interrupt_Flag(INT_CAN2);

	/* 判断是否为CAN接收标志 */
	if(CAN_Get_INT_Flag(CAN2_SFR,CAN_INT_RECEIVE) != RESET)
	{
		/* 接收RAM数据 */
		CAN_Receive_Message_Configuration(CAN2_SFR,Receice_addr,&CAN_MessageStructrue);
		/* RAM地址自跳 */
		Receice_addr += 0x10;
		/* 释放一次计数器 */
		CAN_Release_Receive_Buffer(CAN2_SFR,1);
        bus_off_count = 0;
		if(CAN_MessageStructrue.m_RemoteTransmit != CAN_DATA_FRAME)//远程帧  m_FrameFormat  接收函数已经ruturn，此无意义
		{
			//用户代码
		}
		else  //数据帧
		{
			Can2_Rx_Isr(CAN_MessageStructrue);
			/* 获取数据 */
			/* 打印数据 */
		}
	}
}


void __attribute__((interrupt))_CAN0_exception (void)
{
	uint8_t i;
	uint32_t id;
	static uint8_t Receice_addr=0x00;//接收RAM偏移地址
	static uint8_t bus_off_count;
	CAN_MessageTypeDef CAN_MessageStructrue;//接收报文结构体
	/* 清CAN中断标志 */
	INT_Clear_Interrupt_Flag(INT_CAN0);


	/* 判断是否为CAN接收标志 */
	if(CAN_Get_INT_Flag(CAN0_SFR,CAN_INT_RECEIVE) != RESET)
	{
		/* 接收RAM数据 */
		CAN_Receive_Message_Configuration(CAN0_SFR,Receice_addr,&CAN_MessageStructrue);
		/* RAM地址自跳 */
		Receice_addr+=0x10;
		/* 释放一次计数器 */
		CAN_Release_Receive_Buffer(CAN0_SFR,1);
        bus_off_count = 0;
		if(CAN_MessageStructrue.m_RemoteTransmit != CAN_DATA_FRAME)//远程帧  m_FrameFormat  接收函数已经ruturn，此无意义
		{
			//用户代码
		}
		else  //数据帧
		{
			Can0_Rx_Isr(CAN_MessageStructrue);
			/* 获取数据 */
		}
	}
}


void __attribute__((interrupt))_CAN3_exception (void)
{
	uint8_t i;
	uint32_t id;
	static uint8_t Receice_addr=0x00;//接收RAM偏移地址
	static uint8_t bus_off_count = 0;
	CAN_MessageTypeDef CAN_MessageStructrue;//接收报文结构体
	/* 清CAN中断标志 */
	INT_Clear_Interrupt_Flag(INT_CAN3);

	/* 判断是否为CAN接收标志 */
	if(CAN_Get_INT_Flag(CAN3_SFR,CAN_INT_RECEIVE) != RESET)
	{
		/* 接收RAM数据 */
		CAN_Receive_Message_Configuration(CAN3_SFR,Receice_addr,&CAN_MessageStructrue);
		/* RAM地址自跳 */
		Receice_addr+=0x10;
		/* 释放一次计数器 */
		CAN_Release_Receive_Buffer(CAN3_SFR,1);
        bus_off_count = 0;
		if(CAN_MessageStructrue.m_RemoteTransmit != CAN_DATA_FRAME)//远程帧  m_FrameFormat  接收函数已经ruturn，此无意义
		{
			//用户代码
		}
		else  //数据帧
		{
			Can3_Rx_Isr(CAN_MessageStructrue);
			/* 获取数据 */
			/* 打印数据 */
		}
	}
}


void __attribute__((interrupt))_CAN1_exception (void)
{
	uint8_t i;
	uint32_t id;
	static uint8_t Receice_addr=0x00;//接收RAM偏移地址
	static uint8_t bus_off_count = 0;
	CAN_MessageTypeDef CAN_MessageStructrue;//接收报文结构体
	/* 清CAN中断标志 */
	INT_Clear_Interrupt_Flag(INT_CAN1);

	/* 判断是否为CAN接收标志 */
	if(CAN_Get_INT_Flag(CAN1_SFR,CAN_INT_RECEIVE) != RESET)
	{
		/* 接收RAM数据 */
		CAN_Receive_Message_Configuration(CAN1_SFR,Receice_addr,&CAN_MessageStructrue);
		/* RAM地址自跳 */
		Receice_addr+=0x10;
		/* 释放一次计数器 */
		CAN_Release_Receive_Buffer(CAN1_SFR,1);
        bus_off_count = 0;
		if(CAN_MessageStructrue.m_RemoteTransmit != CAN_DATA_FRAME)//远程帧  m_FrameFormat  接收函数已经ruturn，此无意义
		{
			//用户代码
		}
		else  //数据帧
		{
			Can1_Rx_Isr(CAN_MessageStructrue);
			/* 获取数据 */
			/* 打印数据 */
		}
	}
}

void __attribute__((interrupt))_CAN4_exception (void)
{
	uint8_t i;
	uint32_t id;
	static uint8_t Receice_addr=0x00;//接收RAM偏移地址
	static uint8_t bus_off_count = 0;
	CAN_MessageTypeDef CAN_MessageStructrue;//接收报文结构体
	/* 清CAN中断标志 */
	INT_Clear_Interrupt_Flag(INT_CAN4);

	/* 判断是否为CAN发送标志 */
	//if(CAN_Get_INT_Flag(CAN4_SFR,CAN_INT_TRANSMIT) != RESET)
	//{
	//	CAN_Clear_INT_Flag(CAN4_SFR,CAN_INT_TRANSMIT);
	//}

	if(CAN_Get_INT_Flag(CAN4_SFR,CAN_INT_BUS_ERROR) != RESET)
	{
		CAN_Clear_INT_Flag(CAN4_SFR,CAN_INT_BUS_ERROR);
		
		//bus_off_count++;
		//if(bus_off_count > 20)
		//{
          CAN_Reset(CAN4_SFR);
		  Pcan3Inint();
		//  bus_off_count = 0;
		//}
		//else
		//{
		//	CAN_Reset_Mode_Enable(CAN4_SFR, FALSE);   
		//}			
	}


	/* 判断是否为CAN接收标志 */
	if(CAN_Get_INT_Flag(CAN4_SFR,CAN_INT_RECEIVE) != RESET)
	{
		/* 接收RAM数据 */
		CAN_Receive_Message_Configuration(CAN4_SFR,Receice_addr,&CAN_MessageStructrue);
		/* RAM地址自跳 */
		Receice_addr+=0x10;
		/* 释放一次计数器 */
		CAN_Release_Receive_Buffer(CAN4_SFR,1);

		if(CAN_MessageStructrue.m_RemoteTransmit != CAN_DATA_FRAME)//远程帧  m_FrameFormat  接收函数已经ruturn，此无意义
		{
			//用户代码
		}
		else  //数据帧
		{
			Can4_Rx_Isr(CAN_MessageStructrue);
			/* 获取数据 */
			/* 打印数据 */
		}
	}
}


//*****************************************************************************************
//                              T0中断函数  任务级别
//*****************************************************************************************
void __attribute__((interrupt))_T0_exception (void)
{
    static unsigned char flag = 0;
	GPTIM_Clear_Updata_INT_Flag(T0_SFR);							 //清更新时间标志位
	GPTIM_Clear_Overflow_INT_Flag(T0_SFR);						     //清T0溢出中断标志位
	sch_update();
    if(rs485style.len > 0)
	{
	   if(rs485style.timeout < 19)
	      rs485style.timeout++;
	}
}

//*****************************************************************************************
//                              T1中断函数  电机处理函数
//*****************************************************************************************
void __attribute__((interrupt))_T2_exception (void)
{
	GPTIM_Clear_Updata_INT_Flag(T2_SFR);							 //清更新时间标志位
	GPTIM_Clear_Overflow_INT_Flag(T2_SFR);						     //清T0溢出中断标志位
	SysTickPer1ms++;

    if(Pcan2Delay > 0)
	   Pcan2Delay--;
	
    if(Pcan3Delay > 0)
	   Pcan3Delay--;

    if(Pcan1Delay > 0)
	   Pcan1Delay--;

	if(DcanDelay > 0)
	   DcanDelay--;

	if(BcanDelay > 0)
	   BcanDelay--;
}


//                             EINT0中断函数
//*****************************************************************************************
//原PC0脚
/*void __attribute__((interrupt)) _EINT0_exception (void)
{
	 if(INT_Get_External_Flag(INT_EXTERNAL_INTERRUPT_0) != RESET)
	 {
			INT_External_Clear_Flag(INT_EXTERNAL_INTERRUPT_0);
			A5Count++;
	 }

}*/
//现PD14脚
void __attribute__((interrupt)) _EINT15TO10_exception (void)
{
	 if(INT_Get_External_Flag(INT_EXTERNAL_INTERRUPT_14) != RESET)
	 {
			INT_External_Clear_Flag(INT_EXTERNAL_INTERRUPT_14);
			A5Count++;
	 }

}



//                             EINT1中断函数
//*****************************************************************************************
void __attribute__((interrupt)) _EINT1_exception (void)
{
	 if(INT_Get_External_Flag(INT_EXTERNAL_INTERRUPT_1) != RESET)
	 {
			INT_External_Clear_Flag(INT_EXTERNAL_INTERRUPT_1);
			A15Count++;
	 }

}


