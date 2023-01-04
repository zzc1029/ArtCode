/*
 * output.c
 *
 *  Created on: 2021-8-10
 *      Author: ART
 */

/*

POUT0_1   E3      IN_0: PC14   IS   :PC0   ADC_CH0
POUT2     E6      IN_2: PB6    IS_2 :PC1   ADC_CH1
POUT3     E7      IN_3: PB5    SEL_2:PC4   ADC_CH4
POUT1_1   E8      IN_1: PC12     SEL:PC13  ADC_CH13
WK_UP     A16     WK_IN:PTB4   WK_IS:PC2   ADC_CH2

注意:未按照老版本C52定义的顺序，与T123通讯部分要注意

*/


#include "system_init.h"

uint16_t adc_100ma_fd[OUTNUM];
SW_DIAGNOSE_PW sw_diagnose[OUTNUM/2];

TYPE_BYTE  output_s;
OP_Protect_PW op_protection[OUTNUM];
uint16_t short_out[OUTNUM]={0};
uint8_t  feed_buff[OUTNUM/2] = {0, 0};

	
uint16_t modle_protect[OUTNUM] = {40,40,40,40,40};
	
void OutPowerInit(void)
{
   // 控制端口
   //A16
   GPIOInit_Output_Config(E3_PORT,E3_PIN); 
   //E3
   GPIOInit_Output_Config(E6_PORT,E6_PIN);
   //E8
   GPIOInit_Output_Config(E7_PORT,E7_PIN);
   //E6
   GPIOInit_Output_Config(E8_PORT,E8_PIN);
   //E7
   GPIOInit_Output_Config(A16_PORT,A16_PIN);

   GPIO_Set_Output_Data_Bits(E3_PORT,E3_PIN,RESET);
   GPIO_Set_Output_Data_Bits(E6_PORT,E6_PIN,RESET);
   GPIO_Set_Output_Data_Bits(E7_PORT,E7_PIN,RESET);
   GPIO_Set_Output_Data_Bits(E8_PORT,E8_PIN,RESET); 
   GPIO_Set_Output_Data_Bits(A16_PORT,A16_PIN,RESET);



   // SEL1
   GPIOInit_Output_Config(GPIOC_SFR,GPIO_PIN_MASK_9);
   //SEL2
   GPIOInit_Output_Config(GPIOC_SFR,GPIO_PIN_MASK_8);

   
   // ADC 端口
   //E3&E8
   GPIO_Write_Mode_Bits(GPIOC_SFR,GPIO_PIN_MASK_10,GPIO_MODE_AN);  //ADC_CHANNEL_0
   //E6&E7
   GPIO_Write_Mode_Bits(GPIOC_SFR,GPIO_PIN_MASK_4,GPIO_MODE_AN);  //ADC_CHANNEL_1
  // GPIO_Write_Mode_Bits(GPIOC_SFR,GPIO_PIN_MASK_4,GPIO_MODE_AN);  //ADC_CHANNEL_4
  // GPIO_Write_Mode_Bits(GPIOC_SFR,GPIO_PIN_MASK_13,GPIO_MODE_AN); //ADC_CHANNEL_13 
   //A16
   GPIO_Write_Mode_Bits(GPIOC_SFR,GPIO_PIN_MASK_13,GPIO_MODE_AN);  //ADC_CHANNEL_2
}

//GPIO_Read_Output_Data_Bit (GPIO_SFRmap* GPIOx, uint16_t GpioPin) Bit_SET

void OpenPower(uint8_t i,BitAction res)
{
   switch(i)
   {
     case 0:
	 	    GPIO_Set_Output_Data_Bits(GPIOG_SFR,GPIO_PIN_MASK_6,res);
	 	   break;
	 case 1:
	 	   GPIO_Set_Output_Data_Bits(GPIOC_SFR,GPIO_PIN_MASK_3,res);
	 	   break;
	 case 2:
	 	   GPIO_Set_Output_Data_Bits(GPIOC_SFR,GPIO_PIN_MASK_2,res);
	      break;
	 case 3:
	 	  GPIO_Set_Output_Data_Bits(GPIOG_SFR,GPIO_PIN_MASK_7,res);
	 	  break;
	 case 4: 
	 	  GPIO_Set_Output_Data_Bits(GPIOC_SFR,GPIO_PIN_MASK_12,res);
	 	  break;
	 default:
	 	  break;
   }
}


void set_output(void)
{
    uint8_t i = 0;
    static uint8_t pwr_sw = 0;
    pwr_sw = (uint8_t)output_s.byte;


    for(i = 0; i < OUTNUM; i++)
    {
        if(((pwr_sw >> i)) & 0x01)
        {
        
            if(op_protection[i].shorted != 1)
            {
              OpenPower(i,Bit_SET);
            }
            else
            {
              OpenPower(i,Bit_RESET);
            }
        }
        else
        {
          OpenPower(i,Bit_RESET);
        }
    }
}


void output_protection(void)//3次重试
{
    uint8_t i;

    for (i = 0; i < OUTNUM; i++)
    {
        if(op_protection[i].shorted)
        {
            if(op_protection[i].handled)
            {
                if(op_protection[i].delay > 0)
                {
                    op_protection[i].delay--;
                }
                else
                {
                    short_out[i]++;
                    if(short_out[i] > 3)
                    {
                        short_out[i] = 4;
                        op_protection[i].shorted = 1;
                        op_protection[i].handled = 1;
                    }
                    else
                    {
	                    op_protection[i].shorted = 0;
	                    op_protection[i].handled = 0;
						                     
                    }
                }
            }
            else
            {
                op_protection[i].delay = PROTECT_DELAY;
                op_protection[i].handled = 1;
            }
        }
    }
}


uint8_t value = 0;
void feedback_diag(void)
{
    uint8_t i;
    uint8_t j,k;

	
    for(i = 0; i < OUTNUM; i++)
    {
        j = i / 4;
        k = i % 4 * 2;
		value= 0;
        switch(i)
        {
           case 0: 
		   	     value = GPIO_Read_Output_Data_Bit(E3_PORT,E3_PIN);
		   	     break;
           case 1: 
		   	     value = GPIO_Read_Output_Data_Bit(E6_PORT,E6_PIN);
		   	     break;
           case 2: 
		   	     value = GPIO_Read_Output_Data_Bit(E7_PORT,E7_PIN);
		   	     break;
           case 3: 
		   	     value = GPIO_Read_Output_Data_Bit(E8_PORT,E8_PIN);
		   	     break;
           case 4: 
		   	     value = GPIO_Read_Output_Data_Bit(A16_PORT,A16_PIN);
		   	     break;				 
		}
        if(value)                 //有输出
        {
            if(adc_100ma_fd[i] >= modle_protect[i])
            {
                feed_buff[j] |= 0x02 << k;
                op_protection[i].shorted = 1;
            }
            else
            {
                if((op_protection[i].shorted != 1))
                {
                  feed_buff[j] &= ~(0x03 << k);
				  feed_buff[j] |= 0x01 << k;
                }
            }
        }
        else
        {
            if(op_protection[i].shorted == 1)
                feed_buff[j] |= 0x02 << k;
            else
                feed_buff[j] &= ~(0x03 << k);
        }
    }

    sw_diagnose[0].byte  = feed_buff[0];
    sw_diagnose[1].byte  = feed_buff[1];

    output_protection();
}

















