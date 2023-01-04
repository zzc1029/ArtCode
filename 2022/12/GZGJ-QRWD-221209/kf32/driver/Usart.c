/**
  ******************************************************************************
  * �ļ���  Usart.c
  * ��  ��  ChipON_AE/FAE_Group
  * ��  ��  2019-10-19
  * ��  ��  ���ļ��ṩ�˴�������������ú���������
  *          + ���ڷ���
  *          + �����첽����
  *          + ����ͬ������
  *          + ���ڽ����ж�ʹ��
  ******************************************************************************/
#include "system_init.h"

void USART_Async_config(USART_SFRmap *USARTx);//�����첽ȫ˫������
void USART_Sync_config(USART_SFRmap* USARTx); //���ڰ�˫��ͬ������
void USART_ReceiveInt_config(USART_SFRmap *USARTx,InterruptIndex Peripheral);//���ڽ����ж�ʹ��
void USART_Send(USART_SFRmap* USARTx, uint8_t* Databuf, uint32_t length);//���ڷ��ͺ���

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
    USART_InitStructure.m_BaudRateInteger=195;         //USART��������������z��ȡֵΪ0~65535
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
  * ����   ���ڰ�˫��ͬ������(Ĭ����ģʽ��8bit���ͣ�9600������)
  * ����   ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR
  * ����   ��
  */
void USART_Sync_config(USART_SFRmap* USARTx)
{
	USART_InitTypeDef USART_InitStructure;

	USART_Struct_Init(&USART_InitStructure);
    USART_InitStructure.m_Mode=USART_MODE_HALFDUPLEXSYN;                        //��˫��
    USART_InitStructure.m_HalfDuplexClkSource=USART_MASTER_CLOCKSOURCE_INTER;   //��ģʽ
    USART_InitStructure.m_TransferDir=USART_DIRECTION_TRANSMIT;                 //���䷽��"����"
    USART_InitStructure.m_StopBits=USART_STOPBITS_1;                            //1λֹͣλ
   // USART_InitStructure.m_WordLength=USART_WORDLENGTH_9B;                       //9λ����
   // USART_InitStructure.m_Parity=USART_PARITY_ODD;                              //��У��
  //  USART_InitStructure.m_BaudRateBRCKS=USART_CLK_HFCLK;                        //�ڲ���Ƶʱ����Ϊ USART�����ʷ�����ʱ��
     USART_InitStructure.m_WordLength=USART_WORDLENGTH_8B;                       //9λ����
     USART_InitStructure.m_Parity=USART_PARITY_EVEN;                              //��У��    USART_PARITY_ODD
    USART_InitStructure.m_BaudRateBRCKS= USART_CLK_HFCLK;                          //  USART_CLK_SCLK
    /* ������ =Fck/(16*z��1+x/y)) ����ʱ���ڲ���Ƶ16M*/
    //4800    z:208    x:0    y:0
    //9600    z:104    x:0    y:0
    //19200   z:52     x:0    y:0
    //115200  z:8      x:1    y:13
    //������9600
   // USART_InitStructure.m_BaudRateInteger=104;         //USART��������������z��ȡֵΪ0~65535
    //USART_InitStructure.m_BaudRateNumerator=0;         //USART������С�����Ӳ���x��ȡֵΪ0~0xF
    //USART_InitStructure.m_BaudRateDenominator=0;       //USART������С����ĸ����y��ȡֵΪ0~0xF
    //������9600 781
    USART_InitStructure.m_BaudRateInteger=104;         //USART��������������z��ȡֵΪ0~65535
    USART_InitStructure.m_BaudRateNumerator=0;         //USART������С�����Ӳ���x��ȡֵΪ0~0xF
    USART_InitStructure.m_BaudRateDenominator=0;       //USART������С����ĸ����y��ȡֵΪ0~0xF  denominator

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

/**
  * ����   USART1������ӳ��
  * ����   ��
  * ����   ��
  */
void GPIO_USART2(void)
{
	/* �˿���ӳ��AF5 */
	//USART2_RX		PH15
	//USART2_TX0	PH13
	#if 1
	GPIO_InitTypeDef GPIO_InitStructure;

	/*����CAN��������Ϊ����ģʽ��������Ӧ�˿�ʱ��*/
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
	//GPIO_Write_Mode_Bits(GPIOH_SFR ,GPIO_PIN_MASK_13, GPIO_MODE_RMP);          //��ӳ��IO�ڹ���ģʽ
	//GPIO_Write_Mode_Bits(GPIOH_SFR ,GPIO_PIN_MASK_15, GPIO_MODE_RMP);          //��ӳ��IO�ڹ���ģʽ

	GPIO_Pin_RMP_Config(GPIOH_SFR ,GPIO_Pin_Num_13, GPIO_RMP_AF5_USART2);	  //��ӳ��ΪUSART1
	GPIO_Pin_RMP_Config (GPIOH_SFR ,GPIO_Pin_Num_15, GPIO_RMP_AF5_USART2);     //��ӳ��ΪUSART1
	GPIO_Pin_Lock_Config (GPIOH_SFR ,GPIO_PIN_MASK_13, TRUE);                  //��������
	GPIO_Pin_Lock_Config (GPIOH_SFR ,GPIO_PIN_MASK_15, TRUE);                  //��������
	
	PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOHCLKEN,TRUE);
    PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_USART2CLKEN,TRUE);
}


void USART2_Async_config(USART_SFRmap *USARTx)
{
	USART_InitTypeDef USART_InitStructure;

	USART_Struct_Init(&USART_InitStructure);
    USART_InitStructure.m_Mode=USART_MODE_FULLDUPLEXASY;                        //ȫ˫��
    USART_InitStructure.m_TransferDir=USART_DIRECTION_FULL_DUPLEX;              //���䷽��
    USART_InitStructure.m_WordLength=USART_WORDLENGTH_8B;                       //8λ����
    USART_InitStructure.m_StopBits=USART_STOPBITS_1;                            //1λֹͣλ
    USART_InitStructure.m_BaudRateBRCKS=USART_CLK_HFCLK;                        //�ڲ���Ƶʱ����Ϊ USART�����ʷ�����ʱ��

    /* ������ =Fck/(16*z��1+x/y)) ����ʱ���ڲ���Ƶ16M*/
    //4800    z:208    x:0    y:0
    //9600    z:104    x:0    y:0
    //19200   z:52     x:0    y:0
    //115200  z:8      x:1    y:13
    //������9600
    USART_InitStructure.m_BaudRateInteger=104;         //USART��������������z��ȡֵΪ0~65535
    USART_InitStructure.m_BaudRateNumerator=0;         //USART������С�����Ӳ���x��ȡֵΪ0~0xF
    USART_InitStructure.m_BaudRateDenominator=0;       //USART������С����ĸ����y��ȡֵΪ0~0xF


	USART_Reset(USARTx);                                       //USARTx��λ
	USART_Configuration(USARTx,&USART_InitStructure);          //USARTx����
    USART_Passageway_Select_Config(USARTx,USART_U7816R_PASSAGEWAY_TX0);//UASRTxѡ��TX0ͨ��
	USART_Clear_Transmit_BUFR_INT_Flag(USARTx);                //USARTx����BUF����
	USART_RESHD_Enable (USARTx, TRUE);						   //ʹ��RESHDλ
	USART_Cmd(USARTx,TRUE);                                    //USARTxʹ��
}



void UartInitToT123(void)
{
	//����USART2������ӳ�䣬PH13-RX��PH15-TX0
	GPIO_USART2();
	//ȫ˫���첽8bit 38400������
	USART_Async_config(USART2_SFR);
	//���ڽ����ж�ʹ��
	USART_ReceiveInt_config(USART2_SFR,INT_USART2);
    //Uart2 ���ڵ���ʹ�� ������9600 USART2_TX0	PB14
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
  * ����   ���ڷ����ͻ��з�
  * ����   ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR
  * ����   ��
  */
void Usart_line_feed(USART_SFRmap *USARTx)
{
	USART_SendData(USARTx,0x0D);
	while(!USART_Get_Transmitter_Empty_Flag(USARTx));
	USART_SendData(USARTx,0x0A);
	while(!USART_Get_Transmitter_Empty_Flag(USARTx));
}


//��������

