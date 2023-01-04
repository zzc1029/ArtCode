/*
 * gpio.c
 *
 *  Created on: 2021-8-6
 *      Author: ART
 */


#include "system_init.h"


/**
  * ����  GPIOx �����ʼ�����á�
  * ���� : GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�һ��������ϡ�
  * ����  �ޡ�
  */
void GPIOInit_Input_Config(GPIO_SFRmap* GPIOx,uint16_t GpioPin)
{
	/*��ʼ����λGPIOx���裬ʹ��GPIOx����ʱ��*/
	//	GPIO_Reset(GPIOx);

	/* ���� Pxy��Ϊ����ģʽ */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_Struct_Init(&GPIO_InitStructure);
	GPIO_InitStructure.m_Pin = GpioPin;
	GPIO_InitStructure.m_Speed = GPIO_LOW_SPEED;                   //��ʼ�� GPIO����ٶ�
	GPIO_InitStructure.m_Mode = GPIO_MODE_IN;                      //��ʼ�� GPIO����Ϊ����
	GPIO_InitStructure.m_PullUp = GPIO_PULLUP;                     //��ʼ�� GPIO�Ƿ����� ������  GPIO_NOPULL
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;                   //��ʼ�� GPIO�Ƿ����� ������
	GPIO_Configuration(GPIOx,&GPIO_InitStructure);
}


/**
  * ����  GPIOx �����ʼ�����á�
  * ���� : GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�һ��������ϡ�
  * ����  �ޡ�
  */
void GPIOInit_Output_Config(GPIO_SFRmap* GPIOx,uint16_t GpioPin)
{
		/*��ʼ����λGPIOx���裬ʹ��GPIOx����ʱ��*/
		//	GPIO_Reset(GPIOx);

		/* ���� Pxy��Ϊ���ģʽ���� */
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_Struct_Init(&GPIO_InitStructure);
		GPIO_InitStructure.m_Pin = GpioPin;
		GPIO_InitStructure.m_Speed = GPIO_HIGH_SPEED;          //��ʼ�� GPIO����ٶ�
		GPIO_InitStructure.m_Mode = GPIO_MODE_OUT;            //��ʼ�� GPIO����Ϊ���
		GPIO_InitStructure.m_PullUp = GPIO_NOPULL;            //��ʼ�� GPIO�Ƿ�����
		GPIO_InitStructure.m_PullDown = GPIO_NOPULL;          //��ʼ�� GPIO�Ƿ�����
		GPIO_InitStructure.m_OpenDrain = GPIO_POD_PP;
		GPIO_Configuration(GPIOx,&GPIO_InitStructure);

		GPIO_Set_Output_Data_Bits(GPIOx,GpioPin,Bit_SET);					//������Ϊ�ߵ�ƽ
		//GPIO_Set_Output_Data_Bits(GPIOx,GpioPin,Bit_SET);
}
void GPIOInit_PullOd_Config(GPIO_SFRmap* GPIOx,uint16_t GpioPin,GPIOMode_TypeDef Mode,GPIOPU_TypeDef pull,GPIOPOD_TypeDef state)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_Struct_Init(&GPIO_InitStructure);
	GPIO_InitStructure.m_Pin = GpioPin;
	GPIO_InitStructure.m_Speed = GPIO_HIGH_SPEED;		   //��ʼ�� GPIO����ٶ�
	GPIO_InitStructure.m_Mode = Mode;			  //��ʼ�� GPIO����Ϊ���
	GPIO_InitStructure.m_PullUp = pull;			  //��ʼ�� GPIO�Ƿ�����
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;		  //��ʼ�� GPIO�Ƿ�����
	GPIO_InitStructure.m_OpenDrain = state;
	GPIO_Configuration(GPIOx,&GPIO_InitStructure);
}


