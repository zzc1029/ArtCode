/****************************************************************************************
 *
 * 文件名 kf_it.c
 * 作  者	ChipON_AE/FAE_Group
 * 版  本	V2.1
 * 日  期	2019-11-16
 * 描  述  该文件提供了例程串口中断入口地址
 *
 ****************************************************************************************/
#include"system_init.h"


//*****************************************************************************************
//                              CAN1中断函数
//*****************************************************************************************	//


void __attribute__((interrupt))_CAN2_exception (void)
{
	uint8_t i;
	uint32_t id;
	static uint8_t Receice_addr=0x00;//接收RAM偏移地址
	CAN_MessageTypeDef CAN_MessageStructrue;//接收报文结构体
	/* 清CAN中断标志 */
	INT_Clear_Interrupt_Flag(INT_CAN2);

	/* 判断是否为CAN接收标志 */
	if(CAN_Get_INT_Flag(CAN2_SFR,CAN_INT_RECEIVE) != RESET)
	{
		/* 接收RAM数据 */
		CAN_Receive_Message_Configuration(CAN2_SFR,Receice_addr,&CAN_MessageStructrue);
		/* RAM地址自跳 */
		Receice_addr+=0x10;
		/* 释放一次计数器 */
		CAN_Release_Receive_Buffer(CAN2_SFR,1);

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
	uint32_t id,delaycount = 0;
	static uint8_t Receice_addr=0x00;//接收RAM偏移地址
	static uint8_t bus_off_count = 0;
	CAN_MessageTypeDef CAN_MessageStructrue;//接收报文结构体
	/* 清CAN中断标志 */
	INT_Clear_Interrupt_Flag(INT_CAN0);

	/* 判断是否为CAN发送标志 */

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

	
	
	// BUS OFF重启

}


void __attribute__((interrupt))_CAN3_exception (void)
{
	uint8_t i;
	uint32_t id;
	static uint8_t Receice_addr=0x00;//接收RAM偏移地址
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
	    //bus off中断 重启
		


}


void __attribute__((interrupt))_CAN1_exception (void)
{
	uint8_t i;
	uint32_t id;
	static uint8_t Receice_addr=0x00;//接收RAM偏移地址
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

enum
{
	For0xAA,
	For0x4F,
	For0x4B,
	For0x9A,
};
//*****************************************************************************************
//    0x9A4B4FAA                             USART1中断函数
//*****************************************************************************************	
void __attribute__((interrupt))_USART2_exception (void)
{
	uint8_t data;
	static uint8_t status = For0xAA;
	const uint8_t Rec[] = {0xaa,0x4f,0x4b,0x9a};
	if(USART_Get_Receive_BUFR_Ready_Flag(USART2_SFR))
	{
		data = USART_ReceiveData(USART2_SFR);
		Uart2Receive[ReceIndex++] = data;
		if(ReceIndex > 7)
			ReceIndex = 0;
		switch(status)
		{
			case For0xAA:
				if(data == 0xAA)
					status = For0x4F;
				break;
			case For0x4F:
				if(data == 0x4F)
					status = For0x4B;
				else
					status = For0xAA;
				break;
			case For0x4B:
				if(data == 0x4B)
					status = For0x9A;
				else
					status = For0xAA;
				break;
			case For0x9A:
				if(data == 0x9A)
					t123Ans = 1;
				status = For0xAA;
				break;
		}
	}
}


//*****************************************************************************************
//                              T0中断函数  任务级别
//*****************************************************************************************
void __attribute__((interrupt))_T0_exception (void)
{
	GPTIM_Clear_Updata_INT_Flag(T0_SFR);							 //清更新时间标志位
	GPTIM_Clear_Overflow_INT_Flag(T0_SFR);						     //清T0溢出中断标志位
	sch_update();
}

//*****************************************************************************************
//                              T1中断函数  电机处理函数
//*****************************************************************************************
void __attribute__((interrupt))_T2_exception (void)
{
	GPTIM_Clear_Updata_INT_Flag(T2_SFR);							 //清更新时间标志位
	GPTIM_Clear_Overflow_INT_Flag(T2_SFR);						     //清T0溢出中断标志位
	SysTickPer1ms++;
	Motor_Isr();	
	if(TcanDelay > 0)
	   TcanDelay--;
	
	if(BcanDelay > 0)
	   BcanDelay--;
	
	if(PcanDelay > 0)
	   PcanDelay--;
	
	if(DcanDelay > 0)
	   DcanDelay--;
}

//*****************************************************************************************
//                             EINT2中断函数
//*****************************************************************************************
void __attribute__((interrupt)) _EINT1_exception (void)
{
	 if(INT_Get_External_Flag(INT_EXTERNAL_INTERRUPT_1) != RESET)
	 {
			INT_External_Clear_Flag(INT_EXTERNAL_INTERRUPT_1);
			A5Count++;
			//GPIO_Toggle_Output_Data_Config (GPIOF_SFR,GPIO_PIN_MASK_4);  //PB13翻转
	 }

}
