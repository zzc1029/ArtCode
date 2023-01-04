/*
 * timer.c
 *
 *  Created on: 2021-7-26
 *      Author: ART
 */
#include "system_init.h"

/**
  * ����  ͨ�ö�ʱ��GPTIMx ��ʼ�����á�
  * ����  GPTIMx:ȡֵΪT0_SFR/T1_SFR/T2_SFR/T3_SFR/T4_SFR/ T18_SFR/T19_SFR/T20_SFR/T21_SFR/T22_SFR/T23_SFR��
  *  Peripheral��ȡֵΪINT_T0/INT_T1/INT_T2/INT_T3/INT_T4/INT_T18/INT_T19/INT_T20/INT_T21/INT_T22/INT_T23
  *
  * ����  �ޡ�
  */
void GENERAL_TIMER_Tx_Config(GPTIM_SFRmap* GPTIMx,InterruptIndex Peripheral,uint32_t num)
{
	//��ʱ����ʱ��Դѡ��ʱ��120M��������ʱ��24��Ƶ��0.2usִ�м���һ�Σ�����5000��1ms��һ���ж�
	TIM_Reset(GPTIMx);																//��ʱ�����踴λ��ʹ������ʱ��
	GPTIM_Updata_Immediately_Config(GPTIMx,TRUE);									//�������¿���
	GPTIM_Updata_Enable(GPTIMx,TRUE);												//���ø���ʹ��
	GPTIM_Work_Mode_Config(GPTIMx,GPTIM_TIMER_MODE);								//��ʱģʽѡ��
	GPTIM_Set_Counter(GPTIMx,0);													//��ʱ������ֵ
	GPTIM_Set_Period(GPTIMx,num);												    //��ʱ������ֵ
	GPTIM_Set_Prescaler(GPTIMx,23);				    								//��ʱ��Ԥ��Ƶֵ
	GPTIM_Counter_Mode_Config(GPTIMx,GPTIM_COUNT_UP_DOWN_OUF);						//����-���¼���,�������������жϱ�־
	GPTIM_Clock_Config(GPTIMx,GPTIM_SCLK);											//ѡ��SCLKʱ��
	//INT_Interrupt_Priority_Config(Peripheral,INT_PRIORITY_GROUP_0VS4,4);									//��ռ���ȼ�4,�����ȼ�0
	GPTIM_Overflow_INT_Enable(GPTIMx,TRUE);											//��������ж�ʹ��
	INT_Interrupt_Enable(Peripheral,TRUE);											//�����ж�ʹ��
	INT_Clear_Interrupt_Flag(Peripheral);											//���жϱ�־
	GPTIM_Cmd(GPTIMx,TRUE);															//��ʱ����������ʹ��													//ȫ�ֿ������ж�ʹ��,���ж�ʹ�ܿ��Ʋ�������λ/NMI/Ӳ�������ж�
}

//���񼶱�
void TastTimerInit(void)
{
	//��ʱ��T0����  10ms
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

//���񼶱�
void MotorTimerInit(void)
{
	//��ʱ��T0����  1ms	
	GENERAL_TIMER_Tx_Config(T2_SFR,INT_T2,4000);
	INT_Interrupt_Priority_Config(INT_T2,INT_PRIORITY_GROUP_0VS4,5);
}

void TimerInit(void)
{
	TastTimerInit();
	MotorTimerInit();
}
