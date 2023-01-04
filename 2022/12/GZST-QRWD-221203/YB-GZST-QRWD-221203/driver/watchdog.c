/*
 * watchdog.c
 *
 *  Created on: 2021-8-4
 *      Author: ART
 */


#include "system_init.h"


uint32_t WWDGCNT_DATA = 0;


//#define    KEYUSERE    GPIO_Read_Input_Data_Bit(GPIOD_SFR,GPIO_PIN_MASK_7)  //读取PD7的输入电平
/**
  * 描述  GPIOx 输出初始化配置。
  * 输入 : GPIOx: 指向GPIO内存结构的指针，取值为GPIOA_SFR~GPIOH_SFR。
  *       GpioPin: 端口引脚掩码，取值为GPIO_PIN_MASK_0~GPIO_PIN_MASK_15中的一个或多个组合。
  * 返回  无。
  */
#if 0
void GPIOInit_Output_Config(GPIO_SFRmap* GPIOx,uint16_t GpioPin)
{
	/*初始化复位GPIOx外设，使能GPIOx外设时钟*/
		GPIO_Reset(GPIOx);

	/* 配置 Pxy作为输出模式参数 */
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_Struct_Init(&GPIO_InitStructure);
	GPIO_InitStructure.m_Pin = GpioPin;
	GPIO_InitStructure.m_Speed = GPIO_LOW_SPEED;          //初始化 GPIO输出速度
	GPIO_InitStructure.m_Mode = GPIO_MODE_OUT;            //初始化 GPIO方向为输出
	GPIO_InitStructure.m_PullUp = GPIO_NOPULL;            //初始化 GPIO是否上拉
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;          //初始化 GPIO是否下拉
	GPIO_Configuration(GPIOx,&GPIO_InitStructure);

	GPIO_Set_Output_Data_Bits(GPIOx,GpioPin,Bit_SET);	  //先设置为高电平

}
#endif


/**
  * 描述  窗口看门狗使用窗口值配置。
  * 输入 : Threshold：设置窗口看门狗可操作区下限值取值为0~0x3F
  *
  * 预分频大小为64，最大可设262144分频
  * 返回  无。
  */
void WWDT_Config_TH(uint32_t Threshold)
{
	WWDT_Reset();                                  //复位窗口看门狗，并使能窗口看门狗时钟
	WWDT_Threshold_Config(Threshold);              //设置窗口看门狗可操作区下限值
	WWDT_Prescaler_Config(WWDT_PRESCALER_1024);      //设置预分频1：64，32KHZ时钟源，频率为500HZ,2ms计数一次到40H进中断，即2048ms进一次中断
	WWDT_Enable (TRUE);
#if WWDT_Enable_INT
	WWDT_INT_Enable(TRUE);                            //使能WWDT中断
    INT_Interrupt_Enable(INT_WWDT,TRUE);			  //打开WWDT中断
	INT_All_Enable (TRUE);
#endif
}


/**
  * 描述  设定下限值到溢出值前的窗口内去喂狗清零。
  * 输入 : 无
  *
  * 返回  无。
  */
void WWDT_Clear(void)
{
	WWDGCNT_DATA = WWDT_Get_Counter();            //获取窗口看门狗计数值
	if((WWDGCNT_DATA > WWDT_Threshold) && (WWDGCNT_DATA < 0x3F))
	{
		WWDT_Counter_Config(0);                    //计数寄存器清零
	}
}


























