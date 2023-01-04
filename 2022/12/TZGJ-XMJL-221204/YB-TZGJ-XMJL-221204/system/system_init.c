/**
  ******************************************************************************
  * 文件名  system_init.c
  * 作  者  ChipON_AE/FAE_Group
  * 版  本  V2.62
  * 日  期  2019-11-16
  * 描  述  该文件提供了外设时钟与系统时钟初始化
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
  * 描述  时钟默认配置。
  * 输入  无。
  * 返回  无。
*/
//原有
#if 0
static void SetSysClock(void)
{
	volatile unsigned int delay_C;
	/* 开启内部低频时钟 */
	OSC_INTLF_Software_Enable(TRUE);
	/* 使能内部高频时钟 */
	OSC_INTHF_Software_Enable(TRUE);
	FLASH_CFG = 0xC7;                         //恢复默认的FLASH延时配置
	OSC_SCK_Division_Config(SCLK_DIVISION_1); //主时钟分频选择
   //配置SCLK主时钟选择
	OSC_SCK_Source_Config(SCLK_SOURCE_INTHF); //选择内部高频作为系统时钟
	  /* 输入  SclkSource: SCLK主时钟选择，取值范围为：
	  *                     SCLK_SOURCE_INTHF: 选择INTHF作为系统时钟,
	  *                     SCLK_SOURCE_INTLF: 选择INTLF作为系统时钟,
	  *                     SCLK_SOURCE_EXTHF: 选择EXTHF作为系统时钟,
	  *                     SCLK_SOURCE_EXTLF: 选择EXTLF作为系统时钟,
	  *                     SCLK_SOURCE_PLL: 选择PLL输出作为系统时钟,
	  *                     SCLK_SOURCE_LP4M:  选择 LP4M 输出作为系统时钟
	  *                     */

	while (OSC_Get_INTHF_INT_Flag() != SET);
	/* 系统时钟选择 */
//	#ifndef SYSCLK_FREQ_HSE
//		#define SYSCLK_FREQ_HSI         //内部高频
//	#endif

	/* PLL时钟源选择 */
#ifdef SYSCLK_FREQ_HSI
	OSC_PLL_Input_Source_Config(PLL_INPUT_INTHF);   //PLL_INPUT_EXTHF选择外部时钟
	  /*                   PLL_INPUT_INTHF: 选择INTHF作为PLL输入时钟，
	  *                   PLL_INPUT_EXTHF: 选择EXTHF作为PLL输入时钟。
	  */
#else
	/* 开放备份域 */
	SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_PMWREN_POS);  //配置整个备份域可读写
	SFR_SET_BIT_ASM(PM_CTL0, PM_CTL0_BKPREGCLR_POS); //备份域退出复位状态
	SFR_SET_BIT_ASM(PM_CTL0, PM_CTL0_BKPWR_POS);     //备份区寄存器可读写
	SFR_CLR_BIT_ASM(PM_CTL0, PM_CTL0_IOLATCH_POS);   //IO解锁

	PM_EXTHF_PIN_Selection_Config(PM_EXTHF_PIN2_IO_PORT); //外部高频晶振PD9与PD10中晶振引脚
	OSC_EXTHF_Software_Enable(TRUE);                      //外部高频晶振使能
	OSC_EXTHF_Start_Delay_Config(EXT_START_DELAY_0);
	//选择外部晶振为系统时钟源
	OSC_PLL_Input_Source_Config(PLL_INPUT_EXTHF);
	delay_C = 0xA39;
	while (delay_C--); //等待外部高频时钟使能约4ms        /* while(OSC_Get_EXTHF_INT_Flag() != SET); */
	
#endif
	/* PLL倍频时钟选择 */
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
	//使能时钟源
	OSC_PLL_Software_Enable(TRUE);
	// PLL复位控制。
	OSC_PLL_RST();
	delay_C = 0x27f;
	while (delay_C--) ; //等待PLL使能约1ms        /* while (OSC_Get_PLL_INT_Flag() != SET); */
	
		
	/* 主时钟配置 */
	OSC_SCK_Division_Config(SCLK_DIVISION_1);
	//配置SCLK主时钟选择
	OSC_SCK_Source_Config(SCLK_SOURCE_PLL);
	/* 外设高速时钟 */
	OSC_HFCK_Division_Config(HFCK_DIVISION_1);
#ifdef SYSCLK_FREQ_HSI
	OSC_HFCK_Source_Config(HFCK_SOURCE_INTHF);
#else
	//描述  配置高频外设时钟源选择。
	OSC_HFCK_Source_Config(HFCK_SOURCE_EXTHF);//HFCK_SOURCE_INTHF
#endif
    //高频外设时钟允许使能
	OSC_HFCK_Enable(TRUE);
	/* 外设低速时钟 */
	OSC_LFCK_Division_Config(LFCK_DIVISION_1);
	OSC_LFCK_Source_Config(LFCK_INPUT_INTLF);
	OSC_LFCK_Enable(TRUE);
}
#endif

/**
  * 描述  时钟默认配置。
  * 输入  无。
  * 返回  无。
*/
#if 1
static void SetSysClock(void)
{
	volatile unsigned int delay_C;
	/* 开启内部低频时钟 */
	OSC_INTLF_Software_Enable(TRUE);
	/* 使能内部高频时钟 */
	OSC_INTHF_Software_Enable(TRUE);
	FLASH_CFG = 0xC7;                         //恢复默认的FLASH延时配置
	OSC_SCK_Division_Config(SCLK_DIVISION_1); //主时钟分频选择
	OSC_SCK_Source_Config(SCLK_SOURCE_INTHF); //选择内部高频作为系统时钟

	while (OSC_Get_INTHF_INT_Flag() != SET);
	/* PLL时钟源选择 */
#ifdef SYSCLK_FREQ_HSI
	OSC_PLL_Input_Source_Config(PLL_INPUT_INTHF);
#else
	/* 开放备份域 */
	SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_PMWREN_POS);  //配置整个备份域可读写
	SFR_SET_BIT_ASM(PM_CTL0, PM_CTL0_BKPREGCLR_POS); //备份域退出复位状态
	SFR_SET_BIT_ASM(PM_CTL0, PM_CTL0_BKPWR_POS);     //备份区寄存器可读写
	SFR_CLR_BIT_ASM(PM_CTL0, PM_CTL0_IOLATCH_POS);   //IO解锁

	PM_EXTHF_PIN_Selection_Config(PM_EXTHF_PIN2_IO_PORT); //外部高频晶振PD9与PD10中晶振引脚
	OSC_EXTHF_Software_Enable(TRUE);                      //外部高频晶振使能
	OSC_EXTHF_Start_Delay_Config(EXT_START_DELAY_0);
	OSC_PLL_Input_Source_Config(PLL_INPUT_EXTHF);
	delay_C = 0xA39;
	while (delay_C--); //等待外部高频时钟使能约4ms        /* while(OSC_Get_EXTHF_INT_Flag() != SET); */

#endif
	/* PLL倍频时钟选择 */
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
	while (delay_C--) ; //等待PLL使能约1ms        /* while (OSC_Get_PLL_INT_Flag() != SET); */


	/* 主时钟配置 */
	OSC_SCK_Division_Config(SCLK_DIVISION_1);
	OSC_SCK_Source_Config(SCLK_SOURCE_PLL);
	/* 外设高速时钟 */
	OSC_HFCK_Division_Config(HFCK_DIVISION_1);
#ifdef SYSCLK_FREQ_HSI
	OSC_HFCK_Source_Config(HFCK_SOURCE_INTHF);
#else
	OSC_HFCK_Source_Config(HFCK_SOURCE_EXTHF);
#endif
	OSC_HFCK_Enable(TRUE);
	/* 外设低速时钟 */
	OSC_LFCK_Division_Config(LFCK_DIVISION_1);
	OSC_LFCK_Source_Config(LFCK_INPUT_INTLF);
	OSC_LFCK_Enable(TRUE);
}
#endif

//配置系统时钟作为输出引脚
void Config_Out_Clock(void)
{
	OSC_SCLK_Output_Enable(TRUE);
	OSC_SCLK_Output_Select(CLKOUT_SCLK);//  CLKOUT_SCLK
	OSC_SCLK_Output_Division_Config(SCLK_DIVISION_16);
	//设置系统时钟16分频到PB9管脚输出
	GPIO_Write_Mode_Bits(GPIOB_SFR ,GPIO_PIN_MASK_9, GPIO_MODE_RMP);          //重映射IO口功能模式
	GPIO_Pin_RMP_Config (GPIOB_SFR ,GPIO_Pin_Num_9, GPIO_RMP_AF0_SYSTEM);	  //重映射为USART1
	GPIO_Pin_Lock_Config (GPIOB_SFR ,GPIO_PIN_MASK_9, TRUE);                  //配置锁存
}


void OSC_EXTHLF_Config(void)
{
	volatile unsigned int delay_C;
	/* 开启内部低频时钟 */
	OSC_INTLF_Software_Enable(ENABLE);
	/* 使能内部高频时钟 */
	OSC_INTHF_Software_Enable(ENABLE);  		  //开启需要约200us，非低功耗应用建议不要关闭
	FLASH_CFG = 0xC7;                         //恢复默认的FLASH延时配置
	OSC_SCK_Division_Config(SCLK_DIVISION_1); //主时钟分频选择
	OSC_SCK_Source_Config(SCLK_SOURCE_INTHF); //选择内部高频作为系统时钟
	while (OSC_Get_INTHF_INT_Flag() != SET);

	OSC_Backup_Write_Read_Enable(ENABLE);  			 //使能备份域读写功能
	SFR_SET_BIT_ASM(PM_CTL0, PM_CTL0_BKPREGCLR_POS); //备份域退出复位状态

	/*在备份域内配置晶振管脚*/

	PM_EXTLF_PIN_Selection_Config(PM_EXTLF_PIN2_IO_PORT); //外部低频晶振 PH8与PH9中晶振引脚
	OSC_EXTLF_Software_Enable(ENABLE);//外部低频晶振使能

	/************将OSCIN口设为数字输出低电平，可以提高外部高频晶振起振时间***********/
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_Struct_Init(&GPIO_InitStructure);
	GPIO_InitStructure.m_Pin = GPIO_PIN_MASK_9;
	GPIO_InitStructure.m_Speed = GPIO_LOW_SPEED;          //初始化 GPIO输出速度
	GPIO_InitStructure.m_Mode = GPIO_MODE_OUT;            //初始化 GPIO方向为输出
	GPIO_InitStructure.m_PullUp = GPIO_NOPULL;            //初始化 GPIO是否上拉
	GPIO_InitStructure.m_PullDown = GPIO_NOPULL;          //初始化 GPIO是否下拉
	GPIO_Configuration(GPIOD_SFR,&GPIO_InitStructure);
	GPIO_Set_Output_Data_Bits(GPIOD_SFR,GPIO_PIN_MASK_9,Bit_RESET);	 //先设置为低电平
	delay_C = 0xc8;
	while (delay_C--); //等待约200us
	/************结束***********/

	GPIO_Write_Mode_Bits(GPIOD_SFR, GPIO_PIN_MASK_9,GPIO_MODE_AN);  //将PD9设为模拟输入
	OSC_High_Speed_Enable (ENABLE);  //使能时钟频率低于20Mhz;OSC_HFOSCCAL1_HSFSEN=1;
	PM_EXTHF_PIN_Selection_Config(PM_EXTHF_PIN2_IO_PORT); //外部高频晶振PD9与PD10中晶振引脚
	OSC_EXTHF_Software_Enable(ENABLE); //外部高频晶振使能
	OSC_EXTHF_Start_Delay_Config(EXT_START_DELAY_128);   //外部高频晶振启动延时
	
	/************增加软件延时4ms时间***********/
	delay_C = 0xA39;
	while (delay_C--); //等待外部高频时钟使能约4ms         /* while(OSC_Get_EXTHF_INT_Flag() != SET); */
//	while(OSC_Get_EXTHF_INT_Flag() != SET);    //等待高频稳定标志位
	/************结束***********/
	
	/************系统时钟必须与PLL时钟源相同！！！！***********/
	OSC_SCK_Source_Config(SCLK_SOURCE_EXTHF);  //选择外部高频作为系统时钟
    OSC_PLL_Input_Source_Config(PLL_INPUT_EXTHF);        //PLL时钟源选用外部时钟源16M
    /************系统时钟必须与PLL时钟源相同！！！！***********/

	/* PLL倍频时钟选择 */
 //   OSC_PLL_Multiple_Value_Select(30,2,2);               //倍频因子 为7.5,PLL为  120MHZ
		/* PLL倍频时钟选择 */
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
	while (delay_C--) ; //等待PLL使能约1ms        /* while (OSC_Get_PLL_INT_Flag() != SET); */
	while (OSC_Get_PLL_INT_Flag() != SET);
	
	/* 主时钟配置 */
	OSC_SCK_Division_Config(SCLK_DIVISION_1);   //主时钟分频选择
	OSC_SCK_Source_Config(SCLK_SOURCE_PLL);     //选择PLL作为系统时钟

	OSC_Clock_Failure_Check_Enable(ENABLE);       //使能外部时钟故障检测

	/* 外设高速时钟 */
	OSC_HFCK_Division_Config(HFCK_DIVISION_1);
	OSC_HFCK_Source_Config(HFCK_SOURCE_EXTHF);    //选择EXTHF时钟作为HFCLK时钟
	OSC_HFCK_Enable(ENABLE);                        //HFCLK时钟信号允许

	OSC_LFCK_Division_Config(LFCK_DIVISION_1);	//低频时钟分频选择
	OSC_LFCK_Source_Config (LFCK_INPUT_EXTLF);  //选择EXTLF作为LFCLK时钟
	OSC_LFCK_Enable (ENABLE);					    //LFCLK时钟信号允许


	OSC_SCLK_Output_Division_Config(SCLK_DIVISION_128);					//1/128分频输出，观察用
	OSC_SCLK_Output_Enable(ENABLE);										//系统时钟输出使能
	//GPIO_Write_Mode_Bits(GPIOA_SFR,GPIO_PIN_MASK_0,GPIO_MODE_RMP);      //PA0功能重映射时钟输出
	//GPIO_Pin_RMP_Config(GPIOA_SFR,GPIO_Pin_Num_0,GPIO_RMP_AF0_SYSTEM);	//系统时钟输出
}


/**
  * 描述  系统初始化。
  * 输入  无。
  * 返回  无。
*/
void SystemInit(void)
{
	/* 时钟配置 */
	//SetSysClock();
	SYSCTL_Vector_Offset_Config(0x8000);
	OSC_EXTHLF_Config();
#if SCLKOUTEN
	Config_Out_Clock();
#endif

}

/**
  * 描述  systick_delay初始化
  * 输入  无。
  * 返回  无。
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
  * 描述  us延时,最大延时 nus<=0xffffff*1000*1000/SYSCLK/2
  * 	48M： 699050us
  * 	72M： 466033ms
  * 	96M： 349525ms
  * 	120M：279620ms
  * 输入  nus
  * 返回  无
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
  * 描述  ms延时,最大延时 nms<=0xffffff*1000/SYSCLK/2
  * 	48M： 699ms
  * 	72M： 466ms
  * 	96M： 349ms
  * 	120M：279ms
  * 输入  mus
  * 返回  无
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
 *  功 能 :	查询当前主时钟频率
 *  参 数 :	无
 *  返 回 :	当前时钟
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
