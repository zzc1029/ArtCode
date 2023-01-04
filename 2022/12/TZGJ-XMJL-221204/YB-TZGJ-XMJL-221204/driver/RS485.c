/*
 * RS485.c
 *
 *  Created on: 2022-11-15
 *      Author: ART
 */


#include "system_init.h"


RS485Style  rs485style;


void RS485IoInit(void)
{
  GPIOInit_Output_Config(GPIOB_SFR,GPIO_PIN_MASK_4);
  GPIOInit_Output_Config(GPIOB_SFR,GPIO_PIN_MASK_5);

  GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_4, RESET);
  GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_5, RESET);

  //RX1 PB6  TX1  PB7
  
}

#define RS485SENDEN()\
  GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_4, SET);\
  GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_5, SET);\

#define RS485RECE()\
  GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_4, RESET);\
  GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_5, RESET);\




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
    USART_InitStructure.m_BaudRateInteger=781;         //USART波特率整数部分z，取值为0~65535
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


void ConfigRS485(USART_SFRmap *USARTx)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/*配置CAN引脚类型为复用模式，开启对应端口时钟*/
	GPIO_InitStructure.m_Mode = GPIO_MODE_RMP;
	GPIO_InitStructure.m_Speed = GPIO_HIGH_SPEED;
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;
	GPIO_InitStructure.m_PullUp = GPIO_NOPULL;
	GPIO_InitStructure.m_OpenDrain = GPIO_POD_PP;
	GPIO_InitStructure.m_Pin = GPIO_PIN_MASK_6;
	GPIO_Configuration(GPIOB_SFR,&GPIO_InitStructure);

	GPIO_InitStructure.m_Mode = GPIO_MODE_RMP;
	GPIO_InitStructure.m_Speed = GPIO_HIGH_SPEED;
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;
	GPIO_InitStructure.m_PullUp = GPIO_PULLUP;
	GPIO_InitStructure.m_OpenDrain = GPIO_POD_PP;
	GPIO_InitStructure.m_Pin = GPIO_PIN_MASK_7;
	GPIO_Configuration(GPIOB_SFR,&GPIO_InitStructure);	

      //重映射IO口功能模式

	GPIO_Pin_RMP_Config(GPIOB_SFR ,GPIO_Pin_Num_6, GPIO_RMP_AF5_USART0);	  //重映射为USART1
	GPIO_Pin_RMP_Config (GPIOB_SFR ,GPIO_Pin_Num_7, GPIO_RMP_AF5_USART0);     //重映射为USART1
	GPIO_Pin_Lock_Config (GPIOH_SFR ,GPIO_PIN_MASK_6, TRUE);                  //配置锁存
	GPIO_Pin_Lock_Config (GPIOH_SFR ,GPIO_PIN_MASK_7, TRUE);                  //配置锁存
	
	PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOHCLKEN,TRUE);
    PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_USART0CLKEN,TRUE);


    RS485IoInit();
   	//全双工异步8bit 38400波特率
	USART_Async_config(USART0_SFR);
	//串口接收中断使能
	USART_ReceiveInt_config(USART0_SFR,INT_USART0);
    //Uart2 用于调试使用 波特率9600 USART2_TX0	PB14
    INT_Interrupt_Priority_Config(INT_USART0,INT_PRIORITY_GROUP_0VS4,6);
}



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


void UartSend(uint8_t *pBuf, uint32_t cnt)
{
    RS485SENDEN();
	USART_Send(USART0_SFR,pBuf,cnt);
	RS485RECE();
}



void __attribute__((interrupt))_USART0_exception (void)
{

	if(USART_Get_Receive_BUFR_Ready_Flag(USART0_SFR))
	{
	    if(rs485style.len < RS485MAXLEN)
	    {
	       if(rs485style.len == 0)
	       {
              rs485style.timeout = 0;
		   }
		   rs485style.data[rs485style.len++] = USART_ReceiveData(USART0_SFR);
	    }
	}
}

//按照协议加入异或校验
uint8_t CheckXor(uint8_t *buf,uint8_t len)
{
   uint8_t xor = 0,i = 0;
   for(i = 0;i < len;i++)
   {
      xor ^= *buf++; 
   }
   return xor;
}

#define XOR_EN  UNUSED

int ReadRS485(void)
{
   uint8_t i;
   if(rs485style.timeout > RS485TIMEOUT)
   {
     #if XOR_EN
     if(CheckXor(rs485style.data,rs485style.data[2]) == rs485style.data[rs485style.data[2]])
	 #endif 
     {
	   if(((rs485style.data[0] == 0x55) && (rs485style.data[1] == 0xaa)) && (rs485style.len == (rs485style.data[2] + 1)))
	   {
         for(i = 0;i < rs485style.data[2] + 1;i++)
         {
            rs485style.disdata[i] = rs485style.data[i];
		 }
		 #if !XOR_EN
		 UartSend(rs485style.disdata,rs485style.disdata[2] + 1);
		 #endif
	   }
     }
	// UartSend(rs485style.disdata,rs485style.data[2] + 1);
	 rs485style.len = 0;
	 rs485style.timeout = 0;
   }
   return 1;
}






















