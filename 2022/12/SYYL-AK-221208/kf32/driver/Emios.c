/*
 * Emios.c
 *
 *  Created on: 2021-9-9
 *      Author: ART
 ����A5 A15Ƶ�ʲɼ�
 �˿� PD1 
      PD2   CCP21CH2

 ����˿�:  PC11    CCP1CH3
 ����PWM    PF2     ʹ��GPIO
 */
#include "system_init.h"

#define		PWM_Edge_Out				0	//���ض���PWM�ź�
#define		PWM_Center_Out 			    1	//���Ķ���PWM�ź�

#define		CCP_PWM_WORK			PWM_Edge_Out	//  ѡ��PWM����ģʽ��  0�����ض���PWM�ź�    1�����Ķ���PWM�ź�

/**
  * ����  CCPx PWM����GPIO��ӳ���á�
  * ���� : GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *     GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�һ��������ϡ�
  *    PinRemap: ������ӳ��ѡ��
  * ����  �ޡ�
  */
void CCPx_PWM_GPIO_Init(GPIO_SFRmap* GPIOx,uint16_t GpioPin,uint8_t PinRemap)													//CCP0 ��PWMģʽ���
{
	 static uint16_t GpioPinNum;

	GPIO_Write_Mode_Bits(GPIOx,GpioPin,GPIO_MODE_RMP);

	if(GpioPin==GPIO_PIN_MASK_0)
	{
		GpioPinNum =GPIO_Pin_Num_0;
	}else if(GpioPin==GPIO_PIN_MASK_1)
	{
		GpioPinNum =GPIO_Pin_Num_1;
	}else if(GpioPin==GPIO_PIN_MASK_2)
	{
		GpioPinNum =GPIO_Pin_Num_2;
	}else if(GpioPin==GPIO_PIN_MASK_3)
	{
		GpioPinNum =GPIO_Pin_Num_3;
	}else if(GpioPin==GPIO_PIN_MASK_4)
	{
		GpioPinNum =GPIO_Pin_Num_4;
	}else if(GpioPin==GPIO_PIN_MASK_5)
	{
		GpioPinNum =GPIO_Pin_Num_5;
	}else if(GpioPin==GPIO_PIN_MASK_6)
	{
		GpioPinNum =GPIO_Pin_Num_6;
	}else if(GpioPin==GPIO_PIN_MASK_7)
	{
		GpioPinNum =GPIO_Pin_Num_7;
	}else if(GpioPin==GPIO_PIN_MASK_8)
	{
		GpioPinNum =GPIO_Pin_Num_8;
	}else if(GpioPin==GPIO_PIN_MASK_9)
	{
		GpioPinNum =GPIO_Pin_Num_9;
	}else if(GpioPin==GPIO_PIN_MASK_10)
	{
		GpioPinNum =GPIO_Pin_Num_10;
	}else if(GpioPin==GPIO_PIN_MASK_11)
	{
		GpioPinNum =GPIO_Pin_Num_11;
	}else if(GpioPin==GPIO_PIN_MASK_12)
	{
		GpioPinNum =GPIO_Pin_Num_12;
	}else if(GpioPin==GPIO_PIN_MASK_13)
	{
		GpioPinNum =GPIO_Pin_Num_13;
	}else if(GpioPin==GPIO_PIN_MASK_14)
	{
		GpioPinNum =GPIO_Pin_Num_14;
	}else if(GpioPin==GPIO_PIN_MASK_15)
	{
		GpioPinNum =GPIO_Pin_Num_15;
	}

	GPIO_Pin_RMP_Config(GPIOx,GpioPinNum,PinRemap);     //��ӳ�书��

}


/**
  * ����  CCP20 CCP21 PWM������ܳ�ʼ��������
  * ���� : CCPx: ָ��CCP��ͨ�ö�ʱ���ڴ�ṹ��ָ�룬
  *               ȡֵ/CCP20_SFR/CCP21_SFR
  *    Channel:  CCP_CHANNEL_1: ͨ��1
  *              CCP_CHANNEL_2: ͨ��2
  *              CCP_CHANNEL_3: ͨ��3
  *              CCP_CHANNEL_4: ͨ��4
  *      Period�� ����ֵ��32λ��
  *     Duty��ռ�ձȣ�32λ��
  *
  * ����  �ޡ�
  */

void CCP2021_PWM_PPX_Duty(CCP_SFRmap* CCPx, uint32_t Channel,uint32_t Period,uint32_t Duty)
{

	TIM_Reset(CCPx);//��ʱ�����踴λ��ʹ������ʱ��

	CCP_PWM_Mode_Config(CCPx,Channel,CCP_PWM_MODE);								//CCP PWM����ͨ��ģʽ
	CCP_Channel_Output_Control(CCPx,Channel,CCP_CHANNEL_OUTPUT_PWM_ACTIVE);		//����CCPͨ���������PWM���������Ч
	CCP_Set_Compare_Result(CCPx,Channel,Duty);		

	GPTIM_Updata_Immediately_Config(CCPx,TRUE); 								//�������¿���
	GPTIM_Updata_Enable(CCPx,TRUE); 											//���ø���ʹ��
	GPTIM_Work_Mode_Config(CCPx,GPTIM_TIMER_MODE);								//��ʱģʽѡ��
	GPTIM_Set_Counter(CCPx,0);													//��ʱ������ֵ
	GPTIM_Set_Period(CCPx,Period);												//��ʱ������ֵPPX
	GPTIM_Set_Prescaler(CCPx,2);	
	
#if		(CCP_PWM_WORK == PWM_Edge_Out)
		GPTIM_Counter_Mode_Config(CCPx,GPTIM_COUNT_UP_OF);							//���ϼ���ģʽ,�����ض���PWM�ź�
#else
		GPTIM_Counter_Mode_Config(CCPx,GPTIM_COUNT_UP_DOWN_OF); 								//���ϡ����¼���ģʽ,�����Ķ���PWM�ź�
#endif
	
		GPTIM_Clock_Config(CCPx,GPTIM_SCLK);										//ѡ��SCLKʱ��
		GPTIM_Cmd(CCPx,TRUE);  

}





/**
  * ����  CCPx PWM������ܳ�ʼ��������
  * ���� : CCPx: ָ��CCP��ͨ�ö�ʱ���ڴ�ṹ��ָ�룬
  *               ȡֵCCP0_SFR/CCP1_SFR/CCP2_SFR/CCP3_SFR/CCP4_SFR/
  *               CCP18_SFR/CCP19_SFR/CCP22_SFR/CCP23_SFR��
  *    Channel:  CCP_CHANNEL_1: ͨ��1
  *              CCP_CHANNEL_2: ͨ��2
  *              CCP_CHANNEL_3: ͨ��3
  *              CCP_CHANNEL_4: ͨ��4
  *      Period�� ����ֵ��16λ��
  *        Duty�� ռ�ձȣ�16λ��
  *
  * ����  �ޡ�
  */

void CCPx_PWM_PPX_Duty(CCP_SFRmap* CCPx, uint32_t Channel,uint16_t Period,uint16_t Duty)
{
    static uint8_t lop = 0;
	//if(lop == 0)
	{
	//  lop = 1;
	  TIM_Reset(CCPx);//��ʱ�����踴λ��ʹ������ʱ��
	}
	CCP_PWM_Mode_Config(CCPx,Channel,CCP_PWM_MODE);								//CCP PWM����ͨ��ģʽ
	CCP_Channel_Output_Control(CCPx,Channel,CCP_CHANNEL_OUTPUT_PWM_ACTIVE);		//����CCPͨ���������PWM���������Ч
	CCP_Set_Compare_Result(CCPx,Channel,Duty);									//PWMռ�ձ�
	GPTIM_Updata_Immediately_Config(CCPx,TRUE);									//�������¿���
	GPTIM_Updata_Enable(CCPx,TRUE);												//���ø���ʹ��
	GPTIM_Work_Mode_Config(CCPx,GPTIM_TIMER_MODE);								//��ʱģʽѡ��
	GPTIM_Set_Counter(CCPx,0);													//��ʱ������ֵ
	GPTIM_Set_Period(CCPx,Period);											    //��ʱ������ֵPeriod
	GPTIM_Set_Prescaler(CCPx,119);											   //��ʱ��Ԥ��Ƶֵ
#if		CCP_PWM_WORK==PWM_Edge_Out
		GPTIM_Counter_Mode_Config(CCPx,GPTIM_COUNT_UP_OF);						   //���ϼ���ģʽ,�����ض���PWM�ź�
#else
	GPTIM_Counter_Mode_Config(CCPx,GPTIM_COUNT_UP_DOWN_OF);				       //���ϡ����¼���ģʽ,�����Ķ���PWM�ź�
#endif
	GPTIM_Clock_Config(CCPx,GPTIM_SCLK);										//ѡ��SCLKʱ��
	GPTIM_Cmd(CCPx,TRUE);

}

void CCPx_PWM_PPX_Duty_C3(CCP_SFRmap* CCPx, uint32_t Channel,uint16_t Period,uint16_t Duty)
{
    static uint8_t lop = 0;
	if(lop == 0)
	{
	  lop = 1;
	  TIM_Reset(CCPx);//��ʱ�����踴λ��ʹ������ʱ��
	}
	CCP_PWM_Mode_Config(CCPx,Channel,CCP_PWM_MODE);								//CCP PWM����ͨ��ģʽ
	CCP_Channel_Output_Control(CCPx,Channel,CCP_CHANNEL_OUTPUT_PWM_ACTIVE);		//����CCPͨ���������PWM���������Ч
	CCP_Set_Compare_Result(CCPx,Channel,Duty);									//PWMռ�ձ�
	GPTIM_Updata_Immediately_Config(CCPx,TRUE);									//�������¿���
	GPTIM_Updata_Enable(CCPx,TRUE);												//���ø���ʹ��
	GPTIM_Work_Mode_Config(CCPx,GPTIM_TIMER_MODE);								//��ʱģʽѡ��
	GPTIM_Set_Counter(CCPx,0);													//��ʱ������ֵ
	GPTIM_Set_Period(CCPx,Period);											    //��ʱ������ֵPeriod
	GPTIM_Set_Prescaler(CCPx,2399);											   //��ʱ��Ԥ��Ƶֵ
#if		CCP_PWM_WORK==PWM_Edge_Out
		GPTIM_Counter_Mode_Config(CCPx,GPTIM_COUNT_UP_OF);						   //���ϼ���ģʽ,�����ض���PWM�ź�
#else
	GPTIM_Counter_Mode_Config(CCPx,GPTIM_COUNT_UP_DOWN_OF);				       //���ϡ����¼���ģʽ,�����Ķ���PWM�ź�
#endif
	GPTIM_Clock_Config(CCPx,GPTIM_SCLK);										//ѡ��SCLKʱ��
	GPTIM_Cmd(CCPx,TRUE);

}

void PwmInit(void)
{
   CCPx_PWM_GPIO_Init(GPIOC_SFR,GPIO_PIN_MASK_11,GPIO_RMP_AF1_T1); //CCP1   PF0��ӳ��ΪPWM����  38HZ PWM���
   CCPx_PWM_PPX_Duty(CCP1_SFR,CCP_CHANNEL_3,2000,0);	//����CCP0	 ͨ��3 PB8 1KHZ ռ�ձ�Ϊ50% PWM���
   PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOCCLKEN,TRUE);
   PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_T1CLKEN,TRUE);

   // C3�źŶ˿�  CCP3CH2
   CCPx_PWM_GPIO_Init(GPIOA_SFR,GPIO_PIN_MASK_6,GPIO_RMP_AF1_T1);
   PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOACLKEN,TRUE);
   PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_T3CLKEN,TRUE);
   CCPx_PWM_PPX_Duty_C3(CCP3_SFR,CCP_CHANNEL_3,0,0);
   //
  // CCPx_PWM_PPX_Duty(CCP3_SFR,CCP_CHANNEL_2,2000,1000);
}

//�趨���⼶��
void SetBackGround(uint8_t level)
{
  static uint8_t ledgroundpre = 0xf;
  //if(level < 11)
  {
   // BACKGROUND(SET);
    if((backlight_level != ledgroundpre) || AUTOBACKGROUNDLING)
    {
      ledgroundpre = backlight_level;
  	  CCPx_PWM_PPX_Duty(CCP1_SFR,CCP_CHANNEL_3,2000,200*backlight_level);
	  AUTOBACKGROUNDLING = 0;
    }
  }
  //CCP_Set_Compare_Result(CCP3_SFR,CCP_CHANNEL_2,0);
  //GPTIM_Set_Period(CCP3_SFR,2000);
}

void BACKGROUND_OFF(void)
{
	CCPx_PWM_PPX_Duty(CCP1_SFR,CCP_CHANNEL_3,0,0);
    AUTOBACKGROUNDLING = 1;
}

void SetFreqOut(int freq)
{
	if(freq != 0)
	{
		
		CCPx_PWM_PPX_Duty_C3(CCP3_SFR,CCP_CHANNEL_2,50000/freq - 1,(50000/freq - 1)/2);
	}
	else
	{
		
		CCPx_PWM_PPX_Duty_C3(CCP3_SFR,CCP_CHANNEL_2,0,0);
	}
		
}


/*************************************************************************
* Function Name    : send_msg_bcm
* Description         : this function is send CAN message to BCM
* Parameters         : None
* Return Value       :None
**************************************************************************/

void C3_Sign_OUT(uint16_t speed,uint16_t hundred_meter)
{
    uint16_t freq;
    if(speed >= 1400)
        speed = 1400;
    if(hundred_meter == 0)
        hundred_meter = PULSE;

    SetFreqOut((speed * hundred_meter)/3600);

	//CCPx_PWM_PPX_Duty(CCP3_SFR,CCP_CHANNEL_2,2000,1000);

}


/*******************

 ����ΪPWM����  ��������500hz ռ�ձ�10% - 100%
 �������ΪƵ�ʲɼ�
 PD2   CCP21CH2

**************/

/**
  * ����  CCPx ��׽������ӳ���á�
  * ���� : GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *     GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�һ��������ϡ�
  *    PinRemap: ������ӳ��ѡ��
  * ����  �ޡ�
  */
void CCPx_Capture_GPIO_Init(GPIO_SFRmap* GPIOx,uint16_t GpioPin,uint8_t PinRemap)
{
	 static uint16_t GpioPinNum;


//	//////////////////////////////////////////////////////////////
	GPIO_Write_Mode_Bits(GPIOx,GpioPin,GPIO_MODE_RMP);  //����GPIOΪ��ӳ�书��

	if(GpioPin==GPIO_PIN_MASK_0)
	{
		GpioPinNum =GPIO_Pin_Num_0;
	}else if(GpioPin==GPIO_PIN_MASK_1)
	{
		GpioPinNum =GPIO_Pin_Num_1;
	}else if(GpioPin==GPIO_PIN_MASK_2)
	{
		GpioPinNum =GPIO_Pin_Num_2;
	}else if(GpioPin==GPIO_PIN_MASK_3)
	{
		GpioPinNum =GPIO_Pin_Num_3;
	}else if(GpioPin==GPIO_PIN_MASK_4)
	{
		GpioPinNum =GPIO_Pin_Num_4;
	}else if(GpioPin==GPIO_PIN_MASK_5)
	{
		GpioPinNum =GPIO_Pin_Num_5;
	}else if(GpioPin==GPIO_PIN_MASK_6)
	{
		GpioPinNum =GPIO_Pin_Num_6;
	}else if(GpioPin==GPIO_PIN_MASK_7)
	{
		GpioPinNum =GPIO_Pin_Num_7;
	}else if(GpioPin==GPIO_PIN_MASK_8)
	{
		GpioPinNum =GPIO_Pin_Num_8;
	}else if(GpioPin==GPIO_PIN_MASK_9)
	{
		GpioPinNum =GPIO_Pin_Num_9;
	}else if(GpioPin==GPIO_PIN_MASK_10)
	{
		GpioPinNum =GPIO_Pin_Num_10;
	}else if(GpioPin==GPIO_PIN_MASK_11)
	{
		GpioPinNum =GPIO_Pin_Num_11;
	}else if(GpioPin==GPIO_PIN_MASK_12)
	{
		GpioPinNum =GPIO_Pin_Num_12;
	}else if(GpioPin==GPIO_PIN_MASK_13)
	{
		GpioPinNum =GPIO_Pin_Num_13;
	}else if(GpioPin==GPIO_PIN_MASK_14)
	{
		GpioPinNum =GPIO_Pin_Num_14;
	}else if(GpioPin==GPIO_PIN_MASK_15)
	{
		GpioPinNum =GPIO_Pin_Num_15;
	}

	GPIO_Pin_RMP_Config(GPIOx,GpioPinNum,PinRemap);  //����GPIO��ӳ�����蹦��
}

/**
  * ����  CCPx��׽�������ó�ʼ��������
  * ���� : CCPx: ָ��CCP��ͨ�ö�ʱ���ڴ�ṹ��ָ�룬
  *               ȡֵCCP0_SFR/CCP1_SFR/CCP2_SFR/CCP3_SFR/CCP4_SFR/
  *               CCP18_SFR/CCP19_SFR/CCP20_SFR/CCP21_SFR/CCP22_SFR/CCP23_SFR��
  * ����  �ޡ�
  */
void CCPx_Capture_Mode_init(CCP_SFRmap* CCPx)
{
	/*���ö�ʱ����Ԥ��Ƶֵ �Լ���׽ͨ����ģʽ*/
	TIM_Reset(CCPx);										//��ʱ�����踴λ��ʹ������ʱ��
	CCP_PWM_Input_Measurement_Config(CCPx,TRUE);            //PWM�������ģʽʹ��
	GPTIM_Slave_Mode_Config(CCPx,GPTIM_SLAVE_RESET_MODE);   //���ô�ģʽ����λģʽ
	GPTIM_Trigger_Select_Config(CCPx,GPTIM_TRIGGER_CCPXCH2);  //ѡ�񴥷�ԴΪCH1
	//CCP_Capture_Mode_Config(CCPx, CCP_CHANNEL_1,CCP_CAP_FALLING_EDGE);      ///���ò�׽ͨ�� ģʽ:ÿ���½��ط�����׽
	//CCP_Capture_Mode_Config(CCPx, CCP_CHANNEL_2,CCP_CAP_RISING_EDGE);       ///���ò�׽ͨ�� ģʽ:ÿ�������ط�����׽
	CCP_Capture_Mode_Config(CCPx, CCP_CHANNEL_2,CCP_CAP_FALLING_EDGE);      ///���ò�׽ͨ�� ģʽ:ÿ���½��ط�����׽
	CCP_Capture_Mode_Config(CCPx, CCP_CHANNEL_3,CCP_CAP_RISING_EDGE); 

	GPTIM_Updata_Immediately_Config(CCPx,TRUE);				//�������¿���
	GPTIM_Updata_Enable(CCPx,TRUE);							//���ø���ʹ��
	GPTIM_Work_Mode_Config(CCPx,GPTIM_TIMER_MODE);			//��ʱģʽѡ��
	GPTIM_Set_Counter(CCPx,0);								//��ʱ������ֵ

	GPTIM_Set_Prescaler(CCPx,119);							//��ʱ��Ԥ��Ƶֵ Ԥ��ƵΪ119+1=120��Ƶ����ʱ��120M,1us����һ��
	GPTIM_Counter_Mode_Config(CCPx,GPTIM_COUNT_UP_OF);		//����,��������жϱ�־
	GPTIM_Clock_Config(CCPx,GPTIM_SCLK);					//ѡ��SCLKʱ��Ϊ��ʱ��ʱ��Դ
	GPTIM_Cmd(CCPx,TRUE);                                   //ʹ��ͨ�ö�ʱ��

}

/**
  * ����  �ⲿ�ж�(EINT)�ж�Դ����(���GPIPA~GPIOH)
  * ���� :  EintNum: �ⲿ�жϱ�ţ�
  *              ȡֵΪ��INT_EXTERNAL_INTERRUPT_0��INT_EXTERNAL_INTERRUPT_31�е�һ�� ��0~15��
  *
  * PeripheralSource: �����ж��ߵ��ж�����Դ�� INT_EXTERNAL_SOURCE_PA~INT_EXTERNAL_SOURCE_PF
  * ����  �ޡ�
  */
void EXIT_INTx_Config(uint32_t EintNum,uint32_t PeripheralSource)
{
	EINT_InitTypeDef EXIT_InitStructure;
	INT_External_Struct_Init(&EXIT_InitStructure);
	EXIT_InitStructure.m_Line = EintNum;                   //�����ⲿ�жϱ��
	EXIT_InitStructure.m_Mask = TRUE;                      //�����ⲿ�ж�ʹ�ܿ���
	EXIT_InitStructure.m_Rise = TRUE;                     //�����ⲿ�ж��������ж�ʹ��
	EXIT_InitStructure.m_Fall = FALSE;                     //�����ⲿ�ж��½����ж�ʹ��
	EXIT_InitStructure.m_Source = PeripheralSource;        //�����ⲿ�жϵ��ж�Դѡ��
	INT_External_Configuration(&EXIT_InitStructure);       //�ж����ù���
	INT_External_Source_Enable(EintNum,PeripheralSource);  //ʹ���ⲿ�ж�Դ


    if(EintNum==INT_EXTERNAL_INTERRUPT_0)
    {
    	INT_Interrupt_Enable(INT_EINT0,TRUE);								//ʹ���ж�EINT0
    }else if(EintNum==INT_EXTERNAL_INTERRUPT_1)
    {
    	INT_Interrupt_Enable(INT_EINT1,TRUE);								//ʹ���ж�EINT1
    }else if(EintNum==INT_EXTERNAL_INTERRUPT_2)
    {
    	INT_Interrupt_Enable(INT_EINT2,TRUE);								//ʹ���ж�EINT2
    }else if(EintNum==INT_EXTERNAL_INTERRUPT_3)
    {
    	INT_Interrupt_Enable(INT_EINT3,TRUE);								//ʹ���ж�EINT3
    }else if(EintNum==INT_EXTERNAL_INTERRUPT_4)
    {
    	INT_Interrupt_Enable(INT_EINT4,TRUE);								//ʹ���ж�EINT4
    }else if((EintNum>=INT_EXTERNAL_INTERRUPT_5)&&(EintNum<=INT_EXTERNAL_INTERRUPT_9))
    {
    	INT_Interrupt_Enable(INT_EINT9TO5,TRUE);							//ʹ���ж�EINT5~EINT9
    }else if((EintNum>=INT_EXTERNAL_INTERRUPT_10)&&(EintNum<=INT_EXTERNAL_INTERRUPT_15))
    {
    	INT_Interrupt_Enable(INT_EINT15TO10,TRUE);							//ʹ���ж�EINT10~EINT15
    }

	//INT_All_Enable (TRUE);      //ʹ�����ж�
}

void CaptureModeInit(void)
{
	//CCPx_Capture_GPIO_Init(GPIOD_SFR,GPIO_PIN_MASK_2,GPIO_RMP_AF3_T21);	//PE1��ӳ��Ϊ��׽
	//CCPx_Capture_GPIO_Init(GPIOG_SFR,GPIO_PIN_MASK_1,GPIO_RMP_AF3_T21);	//PG1��ӳ��Ϊ��׽
#if 0	
	CCPx_Capture_GPIO_Init(GPIOD_SFR,GPIO_PIN_MASK_2,GPIO_RMP_AF3_T21);	//PG2��ӳ��Ϊ��׽
	CCPx_Capture_GPIO_Init(GPIOD_SFR,GPIO_PIN_MASK_3,GPIO_RMP_AF3_T21);	//PG2��ӳ��Ϊ��׽
	
	PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIODCLKEN,TRUE);
	PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_T21CLKEN,TRUE);
	
    CCPx_Capture_Mode_init(CCP21_SFR);
#endif
	GPIOInit_Input_Config(GPIOD_SFR,GPIO_PIN_MASK_1);    //PD2��ʼ��Ϊ����
	EXIT_INTx_Config(INT_EXTERNAL_INTERRUPT_1,INT_EXTERNAL_SOURCE_PD);  //�ⲿ�ж�EINT7�ж�ԴPD7����
     INT_Interrupt_Priority_Config(INT_EINT1,INT_PRIORITY_GROUP_0VS4,7);
}


void GetCaptureHZ(void)
{
    meter.MeterA5   = A5Count * 2;
	A5Count = 0;
}
















