/*
 * led.c
 *
 *  Created on: 2021-8-7
 *      Author: ART
 */

#include "system_init.h"



/*

MCLK2:    PB0
LED_CS:   PA8
MOSI:     PA7

*/
void LedPortInit(void)
{
	GPIOInit_Output_Config(GPIOB_SFR,GPIO_PIN_MASK_0);
	GPIOInit_Output_Config(GPIOA_SFR,GPIO_PIN_MASK_8);
	GPIOInit_Output_Config(GPIOA_SFR,GPIO_PIN_MASK_7);
	
	//øÿ÷∆595µÁ‘¥
	GPIOInit_Output_Config(GPIOE_SFR,GPIO_PIN_MASK_0);
	GPIO_Set_Output_Data_Bits(GPIOE_SFR,GPIO_PIN_MASK_0, RESET);
}

TYPE_BYTE led[3];


/*************************************************************************
* Function Name    : led_out
* Description		  : this function is driver of 74HC595
* Parameters		 : None
* Return Value	 :None
**************************************************************************/
void led_out(void)
{
	uint8_t i,j, k;
   	uint8_t dump;
	GPIO_Set_Output_Data_Bits(GPIOE_SFR,GPIO_PIN_MASK_0, SET);	
	for(j = 0; j < 3; j++)
	{
		dump = led[j].byte;
		for(i=0;i<8;i++)
	 	{	
	 		HC595_SHCP(RESET);
			if(dump & 0x80)
	 		{
	 			
	 			HC595_DS(RESET);
			}
			else
			{
				HC595_DS(SET);
			}
			dump <<= 1;
		
			for(k = 0; k < 7; k++)
			{
				asm("nop");
			}
			HC595_SHCP(SET);
	    	
	    	for(k = 0; k < 7; k++)
			{
				asm("nop");
			}
		}
	}
	
	HC595_STCP(RESET);
	for(k = 0; k < 7; k++)
	{
		asm("nop");
	}
	HC595_STCP(SET);
	
}


















