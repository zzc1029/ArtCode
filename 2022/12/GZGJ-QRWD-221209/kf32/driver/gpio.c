/*
 * gpio.c
 *
 *  Created on: 2021-8-6
 *      Author: ART
 */


#include "system_init.h"


/**
  * 描述  GPIOx 输入初始化配置。
  * 输入 : GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 端口引脚掩码，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的一个或多个组合。
  * 返回  无。
  */
void GPIOInit_Input_Config(GPIO_SFRmap* GPIOx,uint16_t GpioPin)
{
	/*初始化复位GPIOx外设，使能GPIOx外设时钟*/
	//	GPIO_Reset(GPIOx);

	/* 配置 Pxy作为输入模式 */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_Struct_Init(&GPIO_InitStructure);
	GPIO_InitStructure.m_Pin = GpioPin;
	GPIO_InitStructure.m_Speed = GPIO_LOW_SPEED;                   //初始化 GPIO输出速度
	GPIO_InitStructure.m_Mode = GPIO_MODE_IN;                      //初始化 GPIO方向为输入
	GPIO_InitStructure.m_PullUp = GPIO_PULLUP;                     //初始化 GPIO是否上拉 不上拉  GPIO_NOPULL
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;                   //初始化 GPIO是否下拉 不下拉
	GPIO_Configuration(GPIOx,&GPIO_InitStructure);
}


/**
  * 描述  GPIOx 输出初始化配置。
  * 输入 : GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 端口引脚掩码，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的一个或多个组合。
  * 返回  无。
  */
void GPIOInit_Output_Config(GPIO_SFRmap* GPIOx,uint16_t GpioPin)
{
		/*初始化复位GPIOx外设，使能GPIOx外设时钟*/
		//	GPIO_Reset(GPIOx);

		/* 配置 Pxy作为输出模式参数 */
		GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_Struct_Init(&GPIO_InitStructure);
		GPIO_InitStructure.m_Pin = GpioPin;
		GPIO_InitStructure.m_Speed = GPIO_HIGH_SPEED;          //初始化 GPIO输出速度
		GPIO_InitStructure.m_Mode = GPIO_MODE_OUT;            //初始化 GPIO方向为输出
		GPIO_InitStructure.m_PullUp = GPIO_NOPULL;            //初始化 GPIO是否上拉
		GPIO_InitStructure.m_PullDown = GPIO_NOPULL;          //初始化 GPIO是否下拉
		GPIO_InitStructure.m_OpenDrain = GPIO_POD_PP;
		GPIO_Configuration(GPIOx,&GPIO_InitStructure);

		GPIO_Set_Output_Data_Bits(GPIOx,GpioPin,Bit_SET);					//先设置为高电平
		//GPIO_Set_Output_Data_Bits(GPIOx,GpioPin,Bit_SET);
}
void GPIOInit_PullOd_Config(GPIO_SFRmap* GPIOx,uint16_t GpioPin,GPIOMode_TypeDef Mode,GPIOPU_TypeDef pull,GPIOPOD_TypeDef state)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_Struct_Init(&GPIO_InitStructure);
	GPIO_InitStructure.m_Pin = GpioPin;
	GPIO_InitStructure.m_Speed = GPIO_HIGH_SPEED;		   //初始化 GPIO输出速度
	GPIO_InitStructure.m_Mode = Mode;			  //初始化 GPIO方向为输出
	GPIO_InitStructure.m_PullUp = pull;			  //初始化 GPIO是否上拉
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;		  //初始化 GPIO是否下拉
	GPIO_InitStructure.m_OpenDrain = state;
	GPIO_Configuration(GPIOx,&GPIO_InitStructure);
}


