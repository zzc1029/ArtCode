/*
 * timer.c
 *
 *  Created on: 2021-7-26
 *      Author: ART
 */
#include "system_init.h"

/**
  * 描述  通用定时器GPTIMx 初始化配置。
  * 输入  GPTIMx:取值为T0_SFR/T1_SFR/T2_SFR/T3_SFR/T4_SFR/ T18_SFR/T19_SFR/T20_SFR/T21_SFR/T22_SFR/T23_SFR。
  *  Peripheral：取值为INT_T0/INT_T1/INT_T2/INT_T3/INT_T4/INT_T18/INT_T19/INT_T20/INT_T21/INT_T22/INT_T23
  *
  * 返回  无。
  */
void GENERAL_TIMER_Tx_Config(GPTIM_SFRmap* GPTIMx,InterruptIndex Peripheral,uint32_t num)
{
	//定时器的时钟源选主时钟120M，经过定时器24分频，0.2us执行计数一次，计数5000次1ms进一次中断
	TIM_Reset(GPTIMx);																//定时器外设复位，使能外设时钟
	GPTIM_Updata_Immediately_Config(GPTIMx,TRUE);									//立即更新控制
	GPTIM_Updata_Enable(GPTIMx,TRUE);												//配置更新使能
	GPTIM_Work_Mode_Config(GPTIMx,GPTIM_TIMER_MODE);								//定时模式选择
	GPTIM_Set_Counter(GPTIMx,0);													//定时器计数值
	GPTIM_Set_Period(GPTIMx,num);												    //定时器周期值
	GPTIM_Set_Prescaler(GPTIMx,23);				    								//定时器预分频值
	GPTIM_Counter_Mode_Config(GPTIMx,GPTIM_COUNT_UP_DOWN_OUF);						//向上-向下计数,上溢和下溢产生中断标志
	GPTIM_Clock_Config(GPTIMx,GPTIM_SCLK);											//选用SCLK时钟
	//INT_Interrupt_Priority_Config(Peripheral,INT_PRIORITY_GROUP_0VS4,4);									//抢占优先级4,子优先级0
	GPTIM_Overflow_INT_Enable(GPTIMx,TRUE);											//计数溢出中断使能
	INT_Interrupt_Enable(Peripheral,TRUE);											//外设中断使能
	INT_Clear_Interrupt_Flag(Peripheral);											//清中断标志
	GPTIM_Cmd(GPTIMx,TRUE);															//定时器启动控制使能													//全局可屏蔽中断使能,该中断使能控制不包含复位/NMI/硬件错误中断
}

//任务级别
void TastTimerInit(void)
{
	//定时器T0配置  10ms
#ifdef SYSCLK_FREQ_120MHz
	GENERAL_TIMER_Tx_Config(T0_SFR,INT_T0,50000);
#elif SYSCLK_FREQ_96MHz
    GENERAL_TIMER_Tx_Config(T0_SFR,INT_T0,40000);
#elif SYSCLK_FREQ_72MHz
	GENERAL_TIMER_Tx_Config(T0_SFR,INT_T0,30000);
#elif SYSCLK_FREQ_48MHz
	GENERAL_TIMER_Tx_Config(T0_SFR,INT_T0,20000);
#endif
INT_Interrupt_Priority_Config(INT_T0,INT_PRIORITY_GROUP_0VS4,4);

}

//任务级别
void MotorTimerInit(void)
{
	//定时器T0配置  1ms	
	GENERAL_TIMER_Tx_Config(T2_SFR,INT_T2,4000);
	INT_Interrupt_Priority_Config(INT_T2,INT_PRIORITY_GROUP_0VS4,5);
}

void TimerInit(void)
{
	TastTimerInit();
	MotorTimerInit();
}
