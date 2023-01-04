/**
  ******************************************************************************
  * �ļ���  system_init.c
  * ��  ��  ChipON_AE/FAE_Group
  * ��  ��  V2.62
  * ��  ��  2019-11-16
  * ��  ��  ���ļ��ṩ������ʱ����ϵͳʱ�ӳ�ʼ��
  *
  ******************************************************************************
  */
#include "system_init.h"

#define INTHF_FREQ_16MHz	   16000000
#define INTLF_FREQ_32KHz	   32000
#define EXTHF_FREQ_16MHz	   16000000
#define EXTLF_FREQ_32768Hz	   32768
#define LP4M_FREQ_4MHz		   4000000

static uint8_t 	fac_us;
static uint16_t fac_ms;

/**
  * ����  ʱ��Ĭ�����á�
  * ����  �ޡ�
  * ����  �ޡ�
*/
//ԭ��
#if 0
static void SetSysClock(void)
{
	volatile unsigned int delay_C;
	/* �����ڲ���Ƶʱ�� */
	OSC_INTLF_Software_Enable(TRUE);
	/* ʹ���ڲ���Ƶʱ�� */
	OSC_INTHF_Software_Enable(TRUE);
	FLASH_CFG = 0xC7;                         //�ָ�Ĭ�ϵ�FLASH��ʱ����
	OSC_SCK_Division_Config(SCLK_DIVISION_1); //��ʱ�ӷ�Ƶѡ��
   //����SCLK��ʱ��ѡ��
	OSC_SCK_Source_Config(SCLK_SOURCE_INTHF); //ѡ���ڲ���Ƶ��Ϊϵͳʱ��
	  /* ����  SclkSource: SCLK��ʱ��ѡ��ȡֵ��ΧΪ��
	  *                     SCLK_SOURCE_INTHF: ѡ��INTHF��Ϊϵͳʱ��,
	  *                     SCLK_SOURCE_INTLF: ѡ��INTLF��Ϊϵͳʱ��,
	  *                     SCLK_SOURCE_EXTHF: ѡ��EXTHF��Ϊϵͳʱ��,
	  *                     SCLK_SOURCE_EXTLF: ѡ��EXTLF��Ϊϵͳʱ��,
	  *                     SCLK_SOURCE_PLL: ѡ��PLL�����Ϊϵͳʱ��,
	  *                     SCLK_SOURCE_LP4M:  ѡ�� LP4M �����Ϊϵͳʱ��
	  *                     */

	while (OSC_Get_INTHF_INT_Flag() != SET);
	/* ϵͳʱ��ѡ�� */
//	#ifndef SYSCLK_FREQ_HSE
//		#define SYSCLK_FREQ_HSI         //�ڲ���Ƶ
//	#endif

	/* PLLʱ��Դѡ�� */
#ifdef SYSCLK_FREQ_HSI
	OSC_PLL_Input_Source_Config(PLL_INPUT_INTHF);   //PLL_INPUT_EXTHFѡ���ⲿʱ��
	  /*                   PLL_INPUT_INTHF: ѡ��INTHF��ΪPLL����ʱ�ӣ�
	  *                   PLL_INPUT_EXTHF: ѡ��EXTHF��ΪPLL����ʱ�ӡ�
	  */
#else
	/* ���ű����� */
	SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_PMWREN_POS);  //��������������ɶ�д
	SFR_SET_BIT_ASM(PM_CTL0, PM_CTL0_BKPREGCLR_POS); //�������˳���λ״̬
	SFR_SET_BIT_ASM(PM_CTL0, PM_CTL0_BKPWR_POS);     //�������Ĵ����ɶ�д
	SFR_CLR_BIT_ASM(PM_CTL0, PM_CTL0_IOLATCH_POS);   //IO����

	PM_EXTHF_PIN_Selection_Config(PM_EXTHF_PIN2_IO_PORT); //�ⲿ��Ƶ����PD9��PD10�о�������
	OSC_EXTHF_Software_Enable(TRUE);                      //�ⲿ��Ƶ����ʹ��
	OSC_EXTHF_Start_Delay_Config(EXT_START_DELAY_0);
	//ѡ���ⲿ����Ϊϵͳʱ��Դ
	OSC_PLL_Input_Source_Config(PLL_INPUT_EXTHF);
	delay_C = 0xA39;
	while (delay_C--); //�ȴ��ⲿ��Ƶʱ��ʹ��Լ4ms        /* while(OSC_Get_EXTHF_INT_Flag() != SET); */
	
#endif
	/* PLL��Ƶʱ��ѡ�� */
#ifdef SYSCLK_FREQ_48MHz
	FLASH_CFG = 0xC3;
	OSC_PLL_Multiple_Value_Select(48, 2, 8);
#elif defined SYSCLK_FREQ_64MHz
	FLASH_CFG = 0xC3;
	OSC_PLL_Multiple_Value_Select(32,2,4);
#elif defined SYSCLK_FREQ_72MHz
	FLASH_CFG = 0xC3;
	OSC_PLL_Multiple_Value_Select(36, 2, 4);
#elif defined SYSCLK_FREQ_96MHz
	FLASH_CFG = 0xC3;
	OSC_PLL_Multiple_Value_Select(12, 1, 2);
#elif defined SYSCLK_FREQ_120MHz
	FLASH_CFG = 0xC4;
	OSC_PLL_Multiple_Value_Select(30, 2, 2);
#endif
	OSC_PLL_Start_Delay_Config(PLL_START_DELAY_8192);
	//ʹ��ʱ��Դ
	OSC_PLL_Software_Enable(TRUE);
	// PLL��λ���ơ�
	OSC_PLL_RST();
	delay_C = 0x27f;
	while (delay_C--) ; //�ȴ�PLLʹ��Լ1ms        /* while (OSC_Get_PLL_INT_Flag() != SET); */
	
		
	/* ��ʱ������ */
	OSC_SCK_Division_Config(SCLK_DIVISION_1);
	//����SCLK��ʱ��ѡ��
	OSC_SCK_Source_Config(SCLK_SOURCE_PLL);
	/* �������ʱ�� */
	OSC_HFCK_Division_Config(HFCK_DIVISION_1);
#ifdef SYSCLK_FREQ_HSI
	OSC_HFCK_Source_Config(HFCK_SOURCE_INTHF);
#else
	//����  ���ø�Ƶ����ʱ��Դѡ��
	OSC_HFCK_Source_Config(HFCK_SOURCE_EXTHF);//HFCK_SOURCE_INTHF
#endif
    //��Ƶ����ʱ������ʹ��
	OSC_HFCK_Enable(TRUE);
	/* �������ʱ�� */
	OSC_LFCK_Division_Config(LFCK_DIVISION_1);
	OSC_LFCK_Source_Config(LFCK_INPUT_INTLF);
	OSC_LFCK_Enable(TRUE);
}
#endif

/**
  * ����  ʱ��Ĭ�����á�
  * ����  �ޡ�
  * ����  �ޡ�
*/
#if 1
static void SetSysClock(void)
{
	volatile unsigned int delay_C;
	/* �����ڲ���Ƶʱ�� */
	OSC_INTLF_Software_Enable(TRUE);
	/* ʹ���ڲ���Ƶʱ�� */
	OSC_INTHF_Software_Enable(TRUE);
	FLASH_CFG = 0xC7;                         //�ָ�Ĭ�ϵ�FLASH��ʱ����
	OSC_SCK_Division_Config(SCLK_DIVISION_1); //��ʱ�ӷ�Ƶѡ��
	OSC_SCK_Source_Config(SCLK_SOURCE_INTHF); //ѡ���ڲ���Ƶ��Ϊϵͳʱ��

	while (OSC_Get_INTHF_INT_Flag() != SET);
	/* PLLʱ��Դѡ�� */
#ifdef SYSCLK_FREQ_HSI
	OSC_PLL_Input_Source_Config(PLL_INPUT_INTHF);
#else
	/* ���ű����� */
	SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_PMWREN_POS);  //��������������ɶ�д
	SFR_SET_BIT_ASM(PM_CTL0, PM_CTL0_BKPREGCLR_POS); //�������˳���λ״̬
	SFR_SET_BIT_ASM(PM_CTL0, PM_CTL0_BKPWR_POS);     //�������Ĵ����ɶ�д
	SFR_CLR_BIT_ASM(PM_CTL0, PM_CTL0_IOLATCH_POS);   //IO����

	PM_EXTHF_PIN_Selection_Config(PM_EXTHF_PIN2_IO_PORT); //�ⲿ��Ƶ����PD9��PD10�о�������
	OSC_EXTHF_Software_Enable(TRUE);                      //�ⲿ��Ƶ����ʹ��
	OSC_EXTHF_Start_Delay_Config(EXT_START_DELAY_0);
	OSC_PLL_Input_Source_Config(PLL_INPUT_EXTHF);
	delay_C = 0xA39;
	while (delay_C--); //�ȴ��ⲿ��Ƶʱ��ʹ��Լ4ms        /* while(OSC_Get_EXTHF_INT_Flag() != SET); */

#endif
	/* PLL��Ƶʱ��ѡ�� */
#ifdef SYSCLK_FREQ_48MHz
	FLASH_CFG = 0xC3;
	OSC_PLL_Multiple_Value_Select(48, 2, 8);
#elif defined SYSCLK_FREQ_64MHz
	FLASH_CFG = 0xC3;
	OSC_PLL_Multiple_Value_Select(32,2,4);
#elif defined SYSCLK_FREQ_72MHz
	FLASH_CFG = 0xC3;
	OSC_PLL_Multiple_Value_Select(36, 2, 4);
#elif defined SYSCLK_FREQ_96MHz
	FLASH_CFG = 0xC3;
	OSC_PLL_Multiple_Value_Select(12, 1, 2);
#elif defined SYSCLK_FREQ_120MHz
	FLASH_CFG = 0xC4;
	OSC_PLL_Multiple_Value_Select(30, 2, 2);
#endif
	OSC_PLL_Start_Delay_Config(PLL_START_DELAY_8192);
	OSC_PLL_Software_Enable(TRUE);
	OSC_PLL_RST();
	delay_C = 0x27f;
	while (delay_C--) ; //�ȴ�PLLʹ��Լ1ms        /* while (OSC_Get_PLL_INT_Flag() != SET); */


	/* ��ʱ������ */
	OSC_SCK_Division_Config(SCLK_DIVISION_1);
	OSC_SCK_Source_Config(SCLK_SOURCE_PLL);
	/* �������ʱ�� */
	OSC_HFCK_Division_Config(HFCK_DIVISION_1);
#ifdef SYSCLK_FREQ_HSI
	OSC_HFCK_Source_Config(HFCK_SOURCE_INTHF);
#else
	OSC_HFCK_Source_Config(HFCK_SOURCE_EXTHF);
#endif
	OSC_HFCK_Enable(TRUE);
	/* �������ʱ�� */
	OSC_LFCK_Division_Config(LFCK_DIVISION_1);
	OSC_LFCK_Source_Config(LFCK_INPUT_INTLF);
	OSC_LFCK_Enable(TRUE);
}
#endif

//����ϵͳʱ����Ϊ�������
void Config_Out_Clock(void)
{
	OSC_SCLK_Output_Enable(TRUE);
	OSC_SCLK_Output_Select(CLKOUT_SCLK);//  CLKOUT_SCLK
	OSC_SCLK_Output_Division_Config(SCLK_DIVISION_16);
	//����ϵͳʱ��16��Ƶ��PB9�ܽ����
	GPIO_Write_Mode_Bits(GPIOB_SFR ,GPIO_PIN_MASK_9, GPIO_MODE_RMP);          //��ӳ��IO�ڹ���ģʽ
	GPIO_Pin_RMP_Config (GPIOB_SFR ,GPIO_Pin_Num_9, GPIO_RMP_AF0_SYSTEM);	  //��ӳ��ΪUSART1
	GPIO_Pin_Lock_Config (GPIOB_SFR ,GPIO_PIN_MASK_9, TRUE);                  //��������
}


void OSC_EXTHLF_Config(void)
{
	volatile unsigned int delay_C;
	/* �����ڲ���Ƶʱ�� */
	OSC_INTLF_Software_Enable(ENABLE);
	/* ʹ���ڲ���Ƶʱ�� */
	OSC_INTHF_Software_Enable(ENABLE);  		  //������ҪԼ200us���ǵ͹���Ӧ�ý��鲻Ҫ�ر�
	FLASH_CFG = 0xC7;                         //�ָ�Ĭ�ϵ�FLASH��ʱ����
	OSC_SCK_Division_Config(SCLK_DIVISION_1); //��ʱ�ӷ�Ƶѡ��
	OSC_SCK_Source_Config(SCLK_SOURCE_INTHF); //ѡ���ڲ���Ƶ��Ϊϵͳʱ��
	while (OSC_Get_INTHF_INT_Flag() != SET);

	OSC_Backup_Write_Read_Enable(ENABLE);  			 //ʹ�ܱ������д����
	SFR_SET_BIT_ASM(PM_CTL0, PM_CTL0_BKPREGCLR_POS); //�������˳���λ״̬

	/*�ڱ����������þ���ܽ�*/

	PM_EXTLF_PIN_Selection_Config(PM_EXTLF_PIN2_IO_PORT); //�ⲿ��Ƶ���� PH8��PH9�о�������
	OSC_EXTLF_Software_Enable(ENABLE);//�ⲿ��Ƶ����ʹ��

	/************��OSCIN����Ϊ��������͵�ƽ����������ⲿ��Ƶ��������ʱ��***********/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_Struct_Init(&GPIO_InitStructure);
	GPIO_InitStructure.m_Pin = GPIO_PIN_MASK_9;
	GPIO_InitStructure.m_Speed = GPIO_LOW_SPEED;          //��ʼ�� GPIO����ٶ�
	GPIO_InitStructure.m_Mode = GPIO_MODE_OUT;            //��ʼ�� GPIO����Ϊ���
	GPIO_InitStructure.m_PullUp = GPIO_NOPULL;            //��ʼ�� GPIO�Ƿ�����
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;          //��ʼ�� GPIO�Ƿ�����
	GPIO_Configuration(GPIOD_SFR,&GPIO_InitStructure);
	GPIO_Set_Output_Data_Bits(GPIOD_SFR,GPIO_PIN_MASK_9,Bit_RESET);	 //������Ϊ�͵�ƽ
	delay_C = 0xc8;
	while (delay_C--); //�ȴ�Լ200us
	/************����***********/

	GPIO_Write_Mode_Bits(GPIOD_SFR, GPIO_PIN_MASK_9,GPIO_MODE_AN);  //��PD9��Ϊģ������
	OSC_High_Speed_Enable (ENABLE);  //ʹ��ʱ��Ƶ�ʵ���20Mhz;OSC_HFOSCCAL1_HSFSEN=1;
	PM_EXTHF_PIN_Selection_Config(PM_EXTHF_PIN2_IO_PORT); //�ⲿ��Ƶ����PD9��PD10�о�������
	OSC_EXTHF_Software_Enable(ENABLE); //�ⲿ��Ƶ����ʹ��
	OSC_EXTHF_Start_Delay_Config(EXT_START_DELAY_128);   //�ⲿ��Ƶ����������ʱ
	
	/************���������ʱ4msʱ��***********/
	delay_C = 0xA39;
	while (delay_C--); //�ȴ��ⲿ��Ƶʱ��ʹ��Լ4ms         /* while(OSC_Get_EXTHF_INT_Flag() != SET); */
//	while(OSC_Get_EXTHF_INT_Flag() != SET);    //�ȴ���Ƶ�ȶ���־λ
	/************����***********/
	
	/************ϵͳʱ�ӱ�����PLLʱ��Դ��ͬ��������***********/
	OSC_SCK_Source_Config(SCLK_SOURCE_EXTHF);  //ѡ���ⲿ��Ƶ��Ϊϵͳʱ��
    OSC_PLL_Input_Source_Config(PLL_INPUT_EXTHF);        //PLLʱ��Դѡ���ⲿʱ��Դ16M
    /************ϵͳʱ�ӱ�����PLLʱ��Դ��ͬ��������***********/

	/* PLL��Ƶʱ��ѡ�� */
 //   OSC_PLL_Multiple_Value_Select(30,2,2);               //��Ƶ���� Ϊ7.5,PLLΪ  120MHZ
		/* PLL��Ƶʱ��ѡ�� */
#ifdef SYSCLK_FREQ_48MHz
		FLASH_CFG = 0xC3;
		OSC_PLL_Multiple_Value_Select(48, 2, 8);
#elif defined SYSCLK_FREQ_64MHz
		FLASH_CFG = 0xC3;
		OSC_PLL_Multiple_Value_Select(32,2,4);
#elif defined SYSCLK_FREQ_72MHz
		FLASH_CFG = 0xC3;
		OSC_PLL_Multiple_Value_Select(36, 2, 4);
#elif defined SYSCLK_FREQ_96MHz
		FLASH_CFG = 0xC3;
		OSC_PLL_Multiple_Value_Select(12, 1, 2);
#elif defined SYSCLK_FREQ_120MHz
		FLASH_CFG = 0xC4;
		OSC_PLL_Multiple_Value_Select(30, 2, 2);
#endif

	OSC_PLL_Start_Delay_Config(PLL_START_DELAY_8192);
	OSC_PLL_Software_Enable(ENABLE);
	OSC_PLL_RST();
	delay_C = 0x27f;
	while (delay_C--) ; //�ȴ�PLLʹ��Լ1ms        /* while (OSC_Get_PLL_INT_Flag() != SET); */
	while (OSC_Get_PLL_INT_Flag() != SET);
	
	/* ��ʱ������ */
	OSC_SCK_Division_Config(SCLK_DIVISION_1);   //��ʱ�ӷ�Ƶѡ��
	OSC_SCK_Source_Config(SCLK_SOURCE_PLL);     //ѡ��PLL��Ϊϵͳʱ��

	OSC_Clock_Failure_Check_Enable(ENABLE);       //ʹ���ⲿʱ�ӹ��ϼ��

	/* �������ʱ�� */
	OSC_HFCK_Division_Config(HFCK_DIVISION_1);
	OSC_HFCK_Source_Config(HFCK_SOURCE_EXTHF);    //ѡ��EXTHFʱ����ΪHFCLKʱ��
	OSC_HFCK_Enable(ENABLE);                        //HFCLKʱ���ź�����

	OSC_LFCK_Division_Config(LFCK_DIVISION_1);	//��Ƶʱ�ӷ�Ƶѡ��
	OSC_LFCK_Source_Config (LFCK_INPUT_EXTLF);  //ѡ��EXTLF��ΪLFCLKʱ��
	OSC_LFCK_Enable (ENABLE);					    //LFCLKʱ���ź�����


	OSC_SCLK_Output_Division_Config(SCLK_DIVISION_128);					//1/128��Ƶ������۲���
	OSC_SCLK_Output_Enable(ENABLE);										//ϵͳʱ�����ʹ��
	//GPIO_Write_Mode_Bits(GPIOA_SFR,GPIO_PIN_MASK_0,GPIO_MODE_RMP);      //PA0������ӳ��ʱ�����
	//GPIO_Pin_RMP_Config(GPIOA_SFR,GPIO_Pin_Num_0,GPIO_RMP_AF0_SYSTEM);	//ϵͳʱ�����
}


/**
  * ����  ϵͳ��ʼ����
  * ����  �ޡ�
  * ����  �ޡ�
*/
void SystemInit(void)
{
	/* ʱ������ */
	//SetSysClock();
	SYSCTL_Vector_Offset_Config(0x8000);
	OSC_EXTHLF_Config();
#if SCLKOUTEN
	Config_Out_Clock();
#endif

}

/**
  * ����  systick_delay��ʼ��
  * ����  �ޡ�
  * ����  �ޡ�
*/
void systick_delay_init(void)
{
#ifdef SYSCLK_FREQ_48MHz
	uint32_t SystemCoreClock = SYSCLK_FREQ_48MHz;
#elif defined SYSCLK_FREQ_64MHz
	uint32_t SystemCoreClock = SYSCLK_FREQ_64MHz;
#elif defined SYSCLK_FREQ_72MHz
	uint32_t SystemCoreClock = SYSCLK_FREQ_72MHz;
#elif defined SYSCLK_FREQ_96MHz
	uint32_t SystemCoreClock = SYSCLK_FREQ_96MHz;
#elif defined SYSCLK_FREQ_120MHz
	uint32_t SystemCoreClock = SYSCLK_FREQ_120MHz;
#endif
	SYSTICK_Cmd(FALSE);
	SYSTICK_Clock_Config(SYSTICK_SYS_CLOCK_DIV_2);
	SFR_CLR_BIT_ASM(ST_CALI, ST_CALII_STCLKREF_POS);
	//fac_us = SystemCoreClock / 2000000;
	//fac_ms = fac_us * 1000;
}


/**
  * ����  us��ʱ,�����ʱ nus<=0xffffff*1000*1000/SYSCLK/2
  * 	48M�� 699050us
  * 	72M�� 466033ms
  * 	96M�� 349525ms
  * 	120M��279620ms
  * ����  nus
  * ����  ��
*/
void systick_delay_us(unsigned int nus)
{
	uint32_t temp;
	SYSTICK_SFR->RELOAD = fac_us * nus;
	SYSTICK_SFR->CV = 0;
	SYSTICK_SFR->CTL |= ST_CTL_STEN;
	do
	{
		temp = ST_CTL;
	} while ((temp & 0x01) && !(temp & (1 << 16)));
	SYSTICK_SFR->CTL &= ~ST_CTL_STEN;
	SYSTICK_SFR->CV = 0;
}

/**
  * ����  ms��ʱ,�����ʱ nms<=0xffffff*1000/SYSCLK/2
  * 	48M�� 699ms
  * 	72M�� 466ms
  * 	96M�� 349ms
  * 	120M��279ms
  * ����  mus
  * ����  ��
*/
void systick_delay_ms(unsigned int nms)
{
	uint32_t temp;
	SYSTICK_SFR->RELOAD = (uint32_t)nms * fac_ms;
	SYSTICK_SFR->CV = 0;
	SYSTICK_SFR->CTL |= ST_CTL_STEN;
	do
	{
		temp = ST_CTL;
	} while ((temp & 0x01) && !(temp & (1 << 16)));
	SYSTICK_SFR->CTL &= ~ST_CTL_STEN;
	SYSTICK_SFR->CV = 0;
}

/**
 *  �� �� :	��ѯ��ǰ��ʱ��Ƶ��
 *  �� �� :	��
 *  �� �� :	��ǰʱ��
 */
uint32_t SystemCoreClockUpdate(void)
{
	uint32_t SystemCoreClock;
    uint32_t tmp = 0, pll_n = 1, pll_m = 0, pll_no = 1;
	uint32_t sckdivfactor = 1;
	uint32_t pllsource = INTHF_FREQ_16MHz;
	tmp = ((OSC_CTL0 >> OSC_CTL0_SCKS0_POS) & 0x07);
	switch (tmp) {
		case SCLK_SOURCE_INTHF:
			SystemCoreClock = INTHF_FREQ_16MHz;
			break;
		case SCLK_SOURCE_INTLF:
			SystemCoreClock = INTLF_FREQ_32KHz;
			break;
		case SCLK_SOURCE_EXTHF:
			SystemCoreClock = EXTHF_FREQ_16MHz;
			break;
		case SCLK_SOURCE_EXTLF:
			SystemCoreClock = EXTLF_FREQ_32768Hz;
			break;
		case SCLK_SOURCE_LP4M:
			SystemCoreClock = LP4M_FREQ_4MHz;
			break;
		case SCLK_SOURCE_PLL:
			if ((OSC_CTL0 >> OSC_CTL0_PLL0CKS_POS) & 0x01) {
				pllsource = EXTHF_FREQ_16MHz;
			} else {
				pllsource = INTHF_FREQ_16MHz;
			}
			pll_m = ((PLL_CTL >> PLL_CTL_M0_POS) & 0x3fff);
			pll_n = ((PLL_CTL >> PLL_CTL_N0_POS) & 0x0f);
			pll_no = (0x01 << ((PLL_CTL >> PLL_CTL_OD0_POS) & 0x03));
			sckdivfactor = (0x01 << ((OSC_CTL0 >> OSC_CTL0_SCKDIV0_POS) & 0x07));
			SystemCoreClock = pllsource * pll_m / (pll_n * pll_no * sckdivfactor);
			break;
		default:
			SystemCoreClock = INTHF_FREQ_16MHz;
			break;
	}
	return SystemCoreClock;
}
