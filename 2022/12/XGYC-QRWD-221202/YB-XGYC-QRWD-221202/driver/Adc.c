/*
 * Adc.c
 *
 *  Created on: 2021-8-6
 *      Author: ART
 */

#include "system_init.h"

/* C52
   A2   SER5       MCU_AD_R5     PG2    ADC_CH20
   A3   SER3       MCU_AD_R3     PG3    ADC_CH21
   A4   SER1       MCU_AD_R1     PG4    ADC_CH22
   A13  SER4       MCU_AD_R4     PG1    ADC_CH19
   A14  SER2       MCU_AD_R2     PG5    ADC_CH23
                   AD_V          PG0    ADC_CH18 //采样24V电压
*/

/* C90
   A2   SER5   510*2    AD_R5     PG5    ADC_CH23
   A3   SER3   510*2    AD_R3     PG3    ADC_CH21
   A4   SER1   510*2    AD_R1     PG1    ADC_CH19
   A13  SER4   510*2    AD_R4     PG4    ADC_CH22
   A14  SER2   510*2    AD_R2     PG2    ADC_CH20
                        AD_V      PG0    ADC_CH18 //采样24V电压
*/




Meter meter;


void AdcPortInit(void)
{
   //GPIO_Write_Mode_Bits(GPIOC_SFR,GPIO_PIN_MASK_1,GPIO_MODE_AN);//ADC_CHANNEL_1
   GPIO_Write_Mode_Bits(GPIOG_SFR,GPIO_PIN_MASK_2,GPIO_MODE_AN);//ADC_CHANNEL_1   
   GPIO_Write_Mode_Bits(GPIOG_SFR,GPIO_PIN_MASK_3,GPIO_MODE_AN);//ADC_CHANNEL_1
   GPIO_Write_Mode_Bits(GPIOG_SFR,GPIO_PIN_MASK_4,GPIO_MODE_AN);//ADC_CHANNEL_1
   GPIO_Write_Mode_Bits(GPIOG_SFR,GPIO_PIN_MASK_1,GPIO_MODE_AN);//ADC_CHANNEL_1
   GPIO_Write_Mode_Bits(GPIOG_SFR,GPIO_PIN_MASK_5,GPIO_MODE_AN);//ADC_CHANNEL_1  
   GPIO_Write_Mode_Bits(GPIOG_SFR,GPIO_PIN_MASK_0,GPIO_MODE_AN);//ADC_CHANNEL_1
}

void Delay(volatile uint32_t cnt)
{
	while(cnt--);
}


void Init_adc(void)
{
	ADC_InitTypeDef adcStruct;

	ADC_Reset (ADC0_SFR); //复位ADC外设并打开ADC的时钟

	/* 初始化 ADC时钟源选择 */
	adcStruct.m_Clock = ADC_HFCLK;
	/* 初始化 ADC时钟分频 */
	//adcStruct.m_ClockDiv = ADC_CLK_500KHZ; //选择内部专用500K时钟源，前面时钟源的选择将失效
	//-----------------2022.5.6修改时钟频率--------------------//
	adcStruct.m_ClockDiv = ADC_CLK_DIV_32;
	/* 初始化 ADC扫描模式使能 */
	adcStruct.m_ScanMode = FALSE;  //不使用扫描模式，一次触发只转换第一个通道
	/* 初始化 ADC连续转换模式 */
	adcStruct.m_ContinuousMode = ADC_SINGLE_MODE; //不使用连续转换功能，只对设置的通道采样一遍
	/* 初始化 ADC转换结果输出格式 */
	adcStruct.m_DataAlign = ADC_DATAALIGN_RIGHT; //转换的结果右对齐
	/* 初始化 ADC常规通道外部触发转换模式使能 */
	adcStruct.m_ExternalTrig_EN = FALSE; //常规通道失能外部条件触发ADC转换，
	/* 初始化 ADC常规通道外部触发事件 */
	adcStruct.m_ExternalTrig = ADC_EXTERNALTRIG_T1TRGO; //常规通道外部触发信号源配置为T1TRGO
	/* 初始化 ADC高优先级通道外部触发转换模式使能 */
	adcStruct.m_HPExternalTrig_EN = FALSE; //高优先级通道失能外部条件触发ADC转换，
	/* 初始化 高优先级通道外部触发事件 */
	adcStruct.m_HPExternalTrig = ADC_HPEXTERNALTRIG_CCP1_CH1; //高优先级通道触发信号源配置为CCP1的通道1
	/* 参考电压选择，取值为宏“ADC参考电压选择”中的一个。 */
	adcStruct.m_VoltageRef=ADC_REF_AVDD; //转换的参考电压源配置为VDDA
	/* 初始化 ADC常规通道扫描长度 */
	adcStruct.m_NumOfConv = 1; //扫描的长度配置为1个通道
	/* 初始化 ADC高优先级通道扫描长度 */
	adcStruct.m_NumOfHPConv = 1; //高优先级通道的扫描长度
	ADC_Configuration (ADC0_SFR, &adcStruct);

	ADC_Cmd (ADC0_SFR, TRUE); //ADC使能

	Delay(0xFF);  //ADC使能后需要一段短暂的时间，等待电路充电完毕后，才能去采样，否者可能存在较大的采样误差
}

#define Filter(samp)                                    \
    {                                                   \
        static uint8_t aver_count = 0,filter_count = 0; \
        static uint16_t log[16];                        \
        static uint32_t sum;                            \
        if (filter_count == 0)                          \
        {                                               \
            sum = (samp);                               \
            log[0] = (samp);                            \
            filter_count ++;                            \
        }                                               \
        else                                            \
        {                                               \
            if (filter_count < 16)                      \
            {                                           \
                sum += (samp);                          \
                log[filter_count] = (samp);             \
                samp = sum / (filter_count + 1);        \
                filter_count ++;                        \
            }                                           \
            else                                        \
            {                                           \
                sum = sum - log[aver_count];            \
                sum += (samp);                          \
                log[aver_count] = (samp);               \
                samp = sum / 16;                        \
                aver_count++;                           \
                if (aver_count > 15)                    \
                {                                       \
                    aver_count = 0;                     \
                }                                       \
            }                                           \
        }                                               \
    }


void AdcInit(void)
{
    AdcPortInit();
	Init_adc();
	//ADC_Regular_Channel_Config (ADC0_SFR, ADC_CHANNEL_1,  0x01); //ADC0常规通道1的采样源设置为ADC_CHANNEL_1
	ADC_Regular_Channel_Config (ADC0_SFR, ADC_CHANNEL_23, 0x01); //ADC0常规通道1的采样源设置为ADC_CHANNEL_1
	ADC_Software_Start_Conv(ADC0_SFR);		//软件触发转换
}


volatile uint16_t  buf_16,flag = 0,Volt,e3e8state = E3,e6e7state = E6;

uint16_t ResultBat;
uint16_t ResultPA2;
uint16_t ResultPA3;
uint16_t ResultPA4;
uint16_t ResultPA13;
uint16_t ResultPA14;

void  ReadAdcResult(void)
{
	while(!ADC_Get_INT_Flag(ADC0_SFR,ADC_INT_EOC)); //等待转换结束，
	buf_16 = ADC_Get_Conversion_Value(ADC0_SFR); //读取ADC数据寄存器,同时硬件会自动清零EOCIF
	#if 1
    switch(flag)
    {
      case metera2:
		    buf_16 = buf_16<<1;
	  	   #if(A2_TYE == RES)
		    meter.MeterA2 = buf_16*(VREF/4095.0);
		    meter.MeterA2 = (A2_PULL*meter.MeterA2)/(5000 - meter.MeterA2);
			#elif(A2_TYE == VOLT)
			buf_16 = buf_16<<1;
			meter.MeterA2 = buf_16*(VREF/4095.0);
			#endif
			Filter(meter.MeterA2);
	  	    ADC_Regular_Channel_Config (ADC0_SFR, ADC_CHANNEL_21, 0x01);
	  	    flag = metera3; 
	  	    break;
			
	  case metera3:
		    buf_16 = buf_16<<1;
	  	   #if(A3_TYE == RES)
		   	meter.MeterA3 = buf_16*(VREF/4095.0);
		    meter.MeterA3 = (A3_PULL*meter.MeterA3)/(5000 - meter.MeterA3);
			#elif(A3_TYE == VOLT)
			buf_16 = buf_16<<1;
			meter.MeterA3 = buf_16*(VREF/4095.0);
			#endif	 
			Filter(meter.MeterA3);
		    ADC_Regular_Channel_Config (ADC0_SFR, ADC_CHANNEL_19, 0x01);
	  	    flag = metera4; 
	  	    break;	
			
	  case metera4:
	  	   buf_16 = buf_16<<1;
	  	   #if(A4_TYE == RES)
		    meter.MeterA4 = buf_16*(VREF/4095.0);
		    meter.MeterA4 = (A4_PULL*meter.MeterA4)/(5000 - meter.MeterA4);
			#elif(A4_TYE == VOLT)
			buf_16 = buf_16<<1;
			meter.MeterA4 = buf_16*(VREF/4095.0);
			#endif	
			Filter(meter.MeterA4);
	  	    ADC_Regular_Channel_Config (ADC0_SFR, ADC_CHANNEL_22, 0x01);
	  	    flag = metera13; 
	  	    break;		
			
	  case metera13:
	  	   buf_16 = buf_16<<1;
	  	   #if(A13_TYE == RES)
		   meter.MeterA13 = buf_16*(VREF/4095.0);
		   meter.MeterA13 = (A13_PULL*meter.MeterA13)/(5000 - meter.MeterA13);
			#elif(A13_TYE == VOLT)
			buf_16 = buf_16<<1;
			meter.MeterA13 = buf_16*(VREF/4095.0);
			#endif
			Filter(meter.MeterA13);
	  	    ADC_Regular_Channel_Config (ADC0_SFR, ADC_CHANNEL_20, 0x01);
	  	    flag = metera14; 
	  	    break;	
			
	  case metera14:
	  	   buf_16 = buf_16<<1;
		 
	  	   #if(A14_TYE == RES)
		   meter.MeterA14 = buf_16*(VREF/4095.0);
		   meter.MeterA14 = (A14_PULL*meter.MeterA14)/(5000 - meter.MeterA14);
			#elif(A14_TYE == VOLT)
			buf_16 = buf_16<<1;
			meter.MeterA14 = buf_16*(VREF/4095.0);
			#endif	
			Filter(meter.MeterA14);
	  	    ADC_Regular_Channel_Config (ADC0_SFR, ADC_CHANNEL_18, 0x01);
	  	    flag = metervbat; 
	  	    break;	
			
	  case metervbat:
			Vbat= (buf_16*VREF/4096.0);
			Vbat = Vbat*16*1.03;
			Vbat = Vbat/100;
		    Filter(Vbat);
	  	    //ADC_Regular_Channel_Config (ADC0_SFR, ADC_CHANNEL_0, 0x01);
	  	    //flag = meterE3E8; 
	  	    ADC_Regular_Channel_Config (ADC0_SFR, ADC_CHANNEL_10, 0x01);
	  	    flag = meterE3E8; 
	  	    break;	 
	  case meterE3E8:
	  	    if(e3e8state == E3)
	  	    {
			  adc_100ma_fd[0] = buf_16*(VREF/4095.0)/100;
			  adc_100ma_fd[0] = (uint16_t)adc_100ma_fd[0] * 2250/1200;
		      Filter(adc_100ma_fd[0]);
			  e3e8state = E8;
	  	    }
			else
			{
				adc_100ma_fd[3] = buf_16*(VREF/4095.0)/100;
				adc_100ma_fd[3] = (uint16_t)adc_100ma_fd[3] * 2250/1200;
				Filter(adc_100ma_fd[3]);
				e3e8state = E3;
			}
			SEL_E3E8(e3e8state);
	  	    ADC_Regular_Channel_Config (ADC0_SFR, ADC_CHANNEL_4, 0x01);
	  	    flag = meterE6E7; 	  	
	  	   break;
	  case meterE6E7:
	  	    if(e6e7state == E6)
	  	    {
			  adc_100ma_fd[1] = buf_16*(VREF/4095.0)/100;
			  adc_100ma_fd[1] = (uint16_t)adc_100ma_fd[1] * 2250/1200;
		      Filter(adc_100ma_fd[1]);
			  e6e7state = E7;
	  	    }
			else
			{
				adc_100ma_fd[2] = buf_16*(VREF/4095.0)/100;
				adc_100ma_fd[2] = (uint16_t)adc_100ma_fd[2] * 2250/1200;
				Filter(adc_100ma_fd[2]);
				e6e7state = E6;
			}
			SEL_E6E7(e6e7state);
	  	    ADC_Regular_Channel_Config (ADC0_SFR, ADC_CHANNEL_13, 0x01);
	  	    flag = meterA16; 	  	
	  	   break;
	  case meterA16:
			adc_100ma_fd[4] = buf_16*(VREF/4095.0);
			adc_100ma_fd[4] = (uint16_t)adc_100ma_fd[4] * 2250/1200;
		    Filter(adc_100ma_fd[4]);
	  	    ADC_Regular_Channel_Config (ADC0_SFR, ADC_CHANNEL_23, 0x01);
	  	    flag = metera2; 	  	
	  	   break;			   
	}
	#endif
	ADC_Software_Start_Conv(ADC0_SFR);
}













