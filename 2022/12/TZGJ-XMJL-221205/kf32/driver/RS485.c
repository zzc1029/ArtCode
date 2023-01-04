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
  * ����  �����첽ȫ˫������(Ĭ��8bit�շ�ʹ��  ȫ˫�� 9600)
  * ����   ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR
  * ����   ��
  */
void USART_Async_config(USART_SFRmap *USARTx)
{
	USART_InitTypeDef USART_InitStructure;

	USART_Struct_Init(&USART_InitStructure);
    USART_InitStructure.m_Mode=USART_MODE_FULLDUPLEXASY;                        //ȫ˫��
    USART_InitStructure.m_TransferDir=USART_DIRECTION_FULL_DUPLEX;              //���䷽��
    USART_InitStructure.m_WordLength=USART_WORDLENGTH_8B;                       //8λ����
    USART_InitStructure.m_StopBits=USART_STOPBITS_1;                            //1λֹͣλ
  //  USART_InitStructure.m_BaudRateBRCKS=USART_CLK_HFCLK;                        //�ڲ���Ƶʱ����Ϊ USART�����ʷ�����ʱ��
    USART_InitStructure.m_BaudRateBRCKS = USART_CLK_SCLK;                   //SCLK_SOURCE_PLL
    /* ������ =Fck/(16*z��1+x/y)) ����ʱ���ڲ���Ƶ16M*/
    //4800    z:208    x:0    y:0
    //9600    z:104    x:0    y:0
    //19200   z:52     x:0    y:0
    //115200  z:8      x:1    y:13
    //������9600
    //USART_InitStructure.m_BaudRateInteger=104;         //USART��������������z��ȡֵΪ0~65535
    //USART_InitStructure.m_BaudRateNumerator=0;         //USART������С�����Ӳ���x��ȡֵΪ0~0xF
    //USART_InitStructure.m_BaudRateDenominator=0;       //USART������С����ĸ����y��ȡֵΪ0~0xF

    /*
            ��T123ͨѶ������ȷ��38400
           С�����ֲ���Ҫ���ã����÷������������ݣ���ΪɶҪ��С���أ��ֲ��ܼ�����
          ע�⣺ֻ��Ҫ�ѷ�����Ϊ0����   USART_InitStructure.m_BaudRateNumerator=0;
    */
#ifdef SYSCLK_FREQ_120MHz
    USART_InitStructure.m_BaudRateInteger=781;         //USART��������������z��ȡֵΪ0~65535
#elif SYSCLK_FREQ_96MHz
    USART_InitStructure.m_BaudRateInteger=156;
#elif SYSCLK_FREQ_72MHz
    USART_InitStructure.m_BaudRateInteger=117;
#elif SYSCLK_FREQ_48MHz
    USART_InitStructure.m_BaudRateInteger=78;
#endif
    USART_InitStructure.m_BaudRateNumerator=0;         //USART������С�����Ӳ���x��ȡֵΪ0~0xF
    USART_InitStructure.m_BaudRateDenominator=0;       //USART������С����ĸ����y��ȡֵΪ0~0xF
    //����С���������ã���ΪɶҪС��������


	USART_Reset(USARTx);                                       //USARTx��λ
	USART_Configuration(USARTx,&USART_InitStructure);          //USARTx����
    USART_Passageway_Select_Config(USARTx,USART_U7816R_PASSAGEWAY_TX0);//UASRTxѡ��TX0ͨ��
	USART_Clear_Transmit_BUFR_INT_Flag(USARTx);                //USARTx����BUF����
	USART_RESHD_Enable (USARTx, TRUE);						   //ʹ��RESHDλ
	USART_Cmd(USARTx,TRUE);                                    //USARTxʹ��
}



/**
  * ����   ���ڽ����ж�����
  * ����   USARTx:ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR
  *      Peripheral:������ں��ж�������ţ�ȡֵ��ΧΪ��
  *                 ö������InterruptIndex�е������ж��������
  * ����   ��
  */
void USART_ReceiveInt_config(USART_SFRmap *USARTx,InterruptIndex Peripheral)
{
	USART_RDR_INT_Enable(USARTx,TRUE);
	INT_Interrupt_Enable(Peripheral,TRUE);
	USART_ReceiveData(USARTx);//����ձ�־λ
	//INT_All_Enable(TRUE);
}


void ConfigRS485(USART_SFRmap *USARTx)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/*����CAN��������Ϊ����ģʽ��������Ӧ�˿�ʱ��*/
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

      //��ӳ��IO�ڹ���ģʽ

	GPIO_Pin_RMP_Config(GPIOB_SFR ,GPIO_Pin_Num_6, GPIO_RMP_AF5_USART0);	  //��ӳ��ΪUSART1
	GPIO_Pin_RMP_Config (GPIOB_SFR ,GPIO_Pin_Num_7, GPIO_RMP_AF5_USART0);     //��ӳ��ΪUSART1
	GPIO_Pin_Lock_Config (GPIOH_SFR ,GPIO_PIN_MASK_6, TRUE);                  //��������
	GPIO_Pin_Lock_Config (GPIOH_SFR ,GPIO_PIN_MASK_7, TRUE);                  //��������
	
	PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOHCLKEN,TRUE);
    PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_USART0CLKEN,TRUE);


    RS485IoInit();
   	//ȫ˫���첽8bit 38400������
	USART_Async_config(USART0_SFR);
	//���ڽ����ж�ʹ��
	USART_ReceiveInt_config(USART0_SFR,INT_USART0);
    //Uart2 ���ڵ���ʹ�� ������9600 USART2_TX0	PB14
    INT_Interrupt_Priority_Config(INT_USART0,INT_PRIORITY_GROUP_0VS4,6);
}



/**
  * ����   ���ڷ���
  * ����   USARTx:   ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR
  *      Databuf��   ָ�������ݵ�ָ��
  *      length��      ���͵ĳ���
  * ����   ��
  */
void USART_Send(USART_SFRmap* USARTx, uint8_t* Databuf, uint32_t length)
{
	uint32_t i;
	for(i=0;i<length;i++)
	{
		//���ڷ���
		USART_SendData(USARTx,Databuf[i]);
		//������ɱ�־
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

//����Э��������У��
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






















