/*
 * watchdog.c
 *
 *  Created on: 2021-8-4
 *      Author: ART
 */


#include "system_init.h"


uint32_t WWDGCNT_DATA = 0;


//#define    KEYUSERE    GPIO_Read_Input_Data_Bit(GPIOD_SFR,GPIO_PIN_MASK_7)  //��ȡPD7�������ƽ
/**
  * ����  GPIOx �����ʼ�����á�
  * ���� : GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�һ��������ϡ�
  * ����  �ޡ�
  */
#if 0
void GPIOInit_Output_Config(GPIO_SFRmap* GPIOx,uint16_t GpioPin)
{
	/*��ʼ����λGPIOx���裬ʹ��GPIOx����ʱ��*/
		GPIO_Reset(GPIOx);

	/* ���� Pxy��Ϊ���ģʽ���� */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_Struct_Init(&GPIO_InitStructure);
	GPIO_InitStructure.m_Pin = GpioPin;
	GPIO_InitStructure.m_Speed = GPIO_LOW_SPEED;          //��ʼ�� GPIO����ٶ�
	GPIO_InitStructure.m_Mode = GPIO_MODE_OUT;            //��ʼ�� GPIO����Ϊ���
	GPIO_InitStructure.m_PullUp = GPIO_NOPULL;            //��ʼ�� GPIO�Ƿ�����
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;          //��ʼ�� GPIO�Ƿ�����
	GPIO_Configuration(GPIOx,&GPIO_InitStructure);

	GPIO_Set_Output_Data_Bits(GPIOx,GpioPin,Bit_SET);	  //������Ϊ�ߵ�ƽ

}
#endif


/**
  * ����  ���ڿ��Ź�ʹ�ô���ֵ���á�
  * ���� : Threshold�����ô��ڿ��Ź��ɲ���������ֵȡֵΪ0~0x3F
  *
  * Ԥ��Ƶ��СΪ64��������262144��Ƶ
  * ����  �ޡ�
  */
void WWDT_Config_TH(uint32_t Threshold)
{
	WWDT_Reset();                                  //��λ���ڿ��Ź�����ʹ�ܴ��ڿ��Ź�ʱ��
	WWDT_Threshold_Config(Threshold);              //���ô��ڿ��Ź��ɲ���������ֵ
	WWDT_Prescaler_Config(WWDT_PRESCALER_1024);      //����Ԥ��Ƶ1��64��32KHZʱ��Դ��Ƶ��Ϊ500HZ,2ms����һ�ε�40H���жϣ���2048ms��һ���ж�
	WWDT_Enable (TRUE);
#if WWDT_Enable_INT
	WWDT_INT_Enable(TRUE);                            //ʹ��WWDT�ж�
    INT_Interrupt_Enable(INT_WWDT,TRUE);			  //��WWDT�ж�
	INT_All_Enable (TRUE);
#endif
}


/**
  * ����  �趨����ֵ�����ֵǰ�Ĵ�����ȥι�����㡣
  * ���� : ��
  *
  * ����  �ޡ�
  */
void WWDT_Clear(void)
{
	WWDGCNT_DATA = WWDT_Get_Counter();            //��ȡ���ڿ��Ź�����ֵ
	if((WWDGCNT_DATA > WWDT_Threshold) && (WWDGCNT_DATA < 0x3F))
	{
		WWDT_Counter_Config(0);                    //�����Ĵ�������
	}
}


























