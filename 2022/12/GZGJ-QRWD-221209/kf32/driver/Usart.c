/**
  ******************************************************************************
  * 文件名  Usart.c
  * 作  者  ChipON_AE/FAE_Group
  * 日  期  2019-10-19
  * 描  述  该文件提供了串口例程相关配置函数，包括
  *          + 串口发送
  *          + 串口异步配置
  *          + 串口同步配置
  *          + 串口接收中断使能
  ******************************************************************************/
#include "system_init.h"

void USART_Async_config(USART_SFRmap *USARTx);//串口异步全双工配置
void USART_Sync_config(USART_SFRmap* USARTx); //串口半双工同步配置
void USART_ReceiveInt_config(USART_SFRmap *USARTx,InterruptIndex Peripheral);//串口接收中断使能
void USART_Send(USART_SFRmap* USARTx, uint8_t* Databuf, uint32_t length);//串口发送函数

/**
  * 描述   串口发送
  * 输入   USARTx:   指向USART内存结构的指针，取值为USART0_SFR~USART8_SFR
  *      Databuf：   指向发送数据的指针
  *      length：      发送的长度
  * 返回   无
  */
void USART_Send(USART_SFRmap* USARTx, uint8_t* Databuf, uint32_t length)
{
	uint32_t i;
	for(i=0;i<length;i++)
	{
		//串口发送
		USART_SendData(USARTx,Databuf[i]);
		//发送完成标志
		while(!USART_Get_Transmitter_Empty_Flag(USARTx));
	}
}

/**
  * 描述  串口异步全双工配置(默认8bit收发使能  全双工 9600)
  * 输入   指向USART内存结构的指针，取值为USART0_SFR~USART8_SFR
  * 返回   无
  */
void USART_Async_config(USART_SFRmap *USARTx)
{
	USART_InitTypeDef USART_InitStructure;

	USART_Struct_Init(&USART_InitStructure);
    USART_InitStructure.m_Mode=USART_MODE_FULLDUPLEXASY;                        //全双工
    USART_InitStructure.m_TransferDir=USART_DIRECTION_FULL_DUPLEX;              //传输方向
    USART_InitStructure.m_WordLength=USART_WORDLENGTH_8B;                       //8位数据
    USART_InitStructure.m_StopBits=USART_STOPBITS_1;                            //1位停止位
  //  USART_InitStructure.m_BaudRateBRCKS=USART_CLK_HFCLK;                        //内部高频时钟作为 USART波特率发生器时钟
    USART_InitStructure.m_BaudRateBRCKS = USART_CLK_SCLK;                   //SCLK_SOURCE_PLL
    /* 波特率 =Fck/(16*z（1+x/y)) 外设时钟内部高频16M*/
    //4800    z:208    x:0    y:0
    //9600    z:104    x:0    y:0
    //19200   z:52     x:0    y:0
    //115200  z:8      x:1    y:13
    //波特率9600
    //USART_InitStructure.m_BaudRateInteger=104;         //USART波特率整数部分z，取值为0~65535
    //USART_InitStructure.m_BaudRateNumerator=0;         //USART波特率小数分子部分x，取值为0~0xF
    //USART_InitStructure.m_BaudRateDenominator=0;       //USART波特率小数分母部分y，取值为0~0xF

    /*
            与T123通讯波特率确定38400
           小数部分不需要设置，设置反而发不出数据（那为啥要用小数呢，又不能减少误差）
          注意：只需要把分子设为0就行   USART_InitStructure.m_BaudRateNumerator=0;
    */
#ifdef SYSCLK_FREQ_120MHz
    USART_InitStructure.m_BaudRateInteger=195;         //USART波特率整数部分z，取值为0~65535
#elif SYSCLK_FREQ_96MHz
    USART_InitStructure.m_BaudRateInteger=156;
#elif SYSCLK_FREQ_72MHz
    USART_InitStructure.m_BaudRateInteger=117;
#elif SYSCLK_FREQ_48MHz
    USART_InitStructure.m_BaudRateInteger=78;
#endif
    USART_InitStructure.m_BaudRateNumerator=0;         //USART波特率小数分子部分x，取值为0~0xF
    USART_InitStructure.m_BaudRateDenominator=0;       //USART波特率小数分母部分y，取值为0~0xF
    //设置小数还不能用，那为啥要小数部分呢


	USART_Reset(USARTx);                                       //USARTx复位
	USART_Configuration(USARTx,&USART_InitStructure);          //USARTx配置
    USART_Passageway_Select_Config(USARTx,USART_U7816R_PASSAGEWAY_TX0);//UASRTx选择TX0通道
	USART_Clear_Transmit_BUFR_INT_Flag(USARTx);                //USARTx发送BUF清零
	USART_RESHD_Enable (USARTx, TRUE);						   //使能RESHD位
	USART_Cmd(USARTx,TRUE);                                    //USARTx使能
}

/**
  * 描述   串口半双工同步配置(默认主模式，8bit发送，9600波特率)
  * 输入   指向USART内存结构的指针，取值为USART0_SFR~USART8_SFR
  * 返回   无
  */
void USART_Sync_config(USART_SFRmap* USARTx)
{
	USART_InitTypeDef USART_InitStructure;

	USART_Struct_Init(&USART_InitStructure);
    USART_InitStructure.m_Mode=USART_MODE_HALFDUPLEXSYN;                        //半双工
    USART_InitStructure.m_HalfDuplexClkSource=USART_MASTER_CLOCKSOURCE_INTER;   //主模式
    USART_InitStructure.m_TransferDir=USART_DIRECTION_TRANSMIT;                 //传输方向"发送"
    USART_InitStructure.m_StopBits=USART_STOPBITS_1;                            //1位停止位
   // USART_InitStructure.m_WordLength=USART_WORDLENGTH_9B;                       //9位数据
   // USART_InitStructure.m_Parity=USART_PARITY_ODD;                              //奇校验
  //  USART_InitStructure.m_BaudRateBRCKS=USART_CLK_HFCLK;                        //内部高频时钟作为 USART波特率发生器时钟
     USART_InitStructure.m_WordLength=USART_WORDLENGTH_8B;                       //9位数据
     USART_InitStructure.m_Parity=USART_PARITY_EVEN;                              //奇校验    USART_PARITY_ODD
    USART_InitStructure.m_BaudRateBRCKS= USART_CLK_HFCLK;                          //  USART_CLK_SCLK
    /* 波特率 =Fck/(16*z（1+x/y)) 外设时钟内部高频16M*/
    //4800    z:208    x:0    y:0
    //9600    z:104    x:0    y:0
    //19200   z:52     x:0    y:0
    //115200  z:8      x:1    y:13
    //波特率9600
   // USART_InitStructure.m_BaudRateInteger=104;         //USART波特率整数部分z，取值为0~65535
    //USART_InitStructure.m_BaudRateNumerator=0;         //USART波特率小数分子部分x，取值为0~0xF
    //USART_InitStructure.m_BaudRateDenominator=0;       //USART波特率小数分母部分y，取值为0~0xF
    //波特率9600 781
    USART_InitStructure.m_BaudRateInteger=104;         //USART波特率整数部分z，取值为0~65535
    USART_InitStructure.m_BaudRateNumerator=0;         //USART波特率小数分子部分x，取值为0~0xF
    USART_InitStructure.m_BaudRateDenominator=0;       //USART波特率小数分母部分y，取值为0~0xF  denominator

	USART_Reset(USARTx);                                       //USARTx复位
	USART_Configuration(USARTx,&USART_InitStructure);          //USARTx配置
	USART_Passageway_Select_Config(USARTx,USART_U7816R_PASSAGEWAY_TX0);//UASRTx选择TX0通道
	USART_Clear_Transmit_BUFR_INT_Flag(USARTx);                //USARTx发送BUF清零
	USART_RESHD_Enable (USARTx, TRUE);						   //使能RESHD位
	USART_Cmd(USARTx,TRUE);                                    //USARTx使能
}


/**
  * 描述   串口接收中断配置
  * 输入   USARTx:指向USART内存结构的指针，取值为USART0_SFR~USART8_SFR
  *      Peripheral:外设或内核中断向量编号，取值范围为：
  *                 枚举类型InterruptIndex中的外设中断向量编号
  * 返回   无
  */
void USART_ReceiveInt_config(USART_SFRmap *USARTx,InterruptIndex Peripheral)
{
	USART_RDR_INT_Enable(USARTx,TRUE);
	INT_Interrupt_Enable(Peripheral,TRUE);
	USART_ReceiveData(USARTx);//清接收标志位
	//INT_All_Enable(TRUE);
}

/**
  * 描述   USART1引脚重映射
  * 输入   无
  * 返回   无
  */
void GPIO_USART2(void)
{
	/* 端口重映射AF5 */
	//USART2_RX		PH15
	//USART2_TX0	PH13
	#if 1
	GPIO_InitTypeDef GPIO_InitStructure;

	/*配置CAN引脚类型为复用模式，开启对应端口时钟*/
	GPIO_InitStructure.m_Mode = GPIO_MODE_RMP;
	GPIO_InitStructure.m_Speed = GPIO_HIGH_SPEED;
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;
	GPIO_InitStructure.m_PullUp = GPIO_NOPULL;
	GPIO_InitStructure.m_OpenDrain = GPIO_POD_PP;
	GPIO_InitStructure.m_Pin = GPIO_PIN_MASK_13;
	GPIO_Configuration(GPIOH_SFR,&GPIO_InitStructure);

	GPIO_InitStructure.m_Mode = GPIO_MODE_RMP;
	GPIO_InitStructure.m_Speed = GPIO_HIGH_SPEED;
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;
	GPIO_InitStructure.m_PullUp = GPIO_PULLUP;
	GPIO_InitStructure.m_OpenDrain = GPIO_POD_PP;
	GPIO_InitStructure.m_Pin = GPIO_PIN_MASK_15;
	GPIO_Configuration(GPIOH_SFR,&GPIO_InitStructure);	
	#endif
    //GPIOInit_Output_Config(GPIOH_SFR,GPIO_PIN_MASK_13);	
	//GPIO_Write_Mode_Bits(GPIOH_SFR ,GPIO_PIN_MASK_13, GPIO_MODE_RMP);          //重映射IO口功能模式
	//GPIO_Write_Mode_Bits(GPIOH_SFR ,GPIO_PIN_MASK_15, GPIO_MODE_RMP);          //重映射IO口功能模式

	GPIO_Pin_RMP_Config(GPIOH_SFR ,GPIO_Pin_Num_13, GPIO_RMP_AF5_USART2);	  //重映射为USART1
	GPIO_Pin_RMP_Config (GPIOH_SFR ,GPIO_Pin_Num_15, GPIO_RMP_AF5_USART2);     //重映射为USART1
	GPIO_Pin_Lock_Config (GPIOH_SFR ,GPIO_PIN_MASK_13, TRUE);                  //配置锁存
	GPIO_Pin_Lock_Config (GPIOH_SFR ,GPIO_PIN_MASK_15, TRUE);                  //配置锁存
	
	PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOHCLKEN,TRUE);
    PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_USART2CLKEN,TRUE);
}


void USART2_Async_config(USART_SFRmap *USARTx)
{
	USART_InitTypeDef USART_InitStructure;

	USART_Struct_Init(&USART_InitStructure);
    USART_InitStructure.m_Mode=USART_MODE_FULLDUPLEXASY;                        //全双工
    USART_InitStructure.m_TransferDir=USART_DIRECTION_FULL_DUPLEX;              //传输方向
    USART_InitStructure.m_WordLength=USART_WORDLENGTH_8B;                       //8位数据
    USART_InitStructure.m_StopBits=USART_STOPBITS_1;                            //1位停止位
    USART_InitStructure.m_BaudRateBRCKS=USART_CLK_HFCLK;                        //内部高频时钟作为 USART波特率发生器时钟

    /* 波特率 =Fck/(16*z（1+x/y)) 外设时钟内部高频16M*/
    //4800    z:208    x:0    y:0
    //9600    z:104    x:0    y:0
    //19200   z:52     x:0    y:0
    //115200  z:8      x:1    y:13
    //波特率9600
    USART_InitStructure.m_BaudRateInteger=104;         //USART波特率整数部分z，取值为0~65535
    USART_InitStructure.m_BaudRateNumerator=0;         //USART波特率小数分子部分x，取值为0~0xF
    USART_InitStructure.m_BaudRateDenominator=0;       //USART波特率小数分母部分y，取值为0~0xF


	USART_Reset(USARTx);                                       //USARTx复位
	USART_Configuration(USARTx,&USART_InitStructure);          //USARTx配置
    USART_Passageway_Select_Config(USARTx,USART_U7816R_PASSAGEWAY_TX0);//UASRTx选择TX0通道
	USART_Clear_Transmit_BUFR_INT_Flag(USARTx);                //USARTx发送BUF清零
	USART_RESHD_Enable (USARTx, TRUE);						   //使能RESHD位
	USART_Cmd(USARTx,TRUE);                                    //USARTx使能
}



void UartInitToT123(void)
{
	//配置USART2引脚重映射，PH13-RX，PH15-TX0
	GPIO_USART2();
	//全双工异步8bit 38400波特率
	USART_Async_config(USART2_SFR);
	//串口接收中断使能
	USART_ReceiveInt_config(USART2_SFR,INT_USART2);
    //Uart2 用于调试使用 波特率9600 USART2_TX0	PB14
    INT_Interrupt_Priority_Config(INT_USART2,INT_PRIORITY_GROUP_0VS4,6);
}

void Uart2Send(uint8_t *pBuf, uint32_t cnt)
{
	USART_Send(USART2_SFR,pBuf,cnt);
}

void TransmitDataTo123(uint8_t *pBuf, uint32_t cnt)
{
	USART_Send(USART2_SFR,pBuf,cnt);
}

/**
  * 描述   串口发闪送换行符
  * 输入   指向USART内存结构的指针，取值为USART0_SFR~USART8_SFR
  * 返回   无
  */
void Usart_line_feed(USART_SFRmap *USARTx)
{
	USART_SendData(USARTx,0x0D);
	while(!USART_Get_Transmitter_Empty_Flag(USARTx));
	USART_SendData(USARTx,0x0A);
	while(!USART_Get_Transmitter_Empty_Flag(USARTx));
}


//以下配置

