/*
 * led.c
 *
 *  Created on: 2021-11-30
 *      Author: ART
 */


#include "system_init.h"
TYPE_WORD ledlogic;


void Ledinit(void)
{
   //1 LED1
   GPIOInit_Output_Config(GPIOB_SFR,GPIO_PIN_MASK_11);
   //1 LED2
   GPIOInit_Output_Config(GPIOB_SFR,GPIO_PIN_MASK_12);
   //1 LED3
   GPIOInit_Output_Config(GPIOB_SFR,GPIO_PIN_MASK_13);
   //1 LED4
   GPIOInit_Output_Config(GPIOB_SFR,GPIO_PIN_MASK_14);
   //1 LED5
   GPIOInit_Output_Config(GPIOE_SFR,GPIO_PIN_MASK_6);
   //1 LED6
   GPIOInit_Output_Config(GPIOA_SFR,GPIO_PIN_MASK_13);
   //1 LED7
   GPIOInit_Output_Config(GPIOA_SFR,GPIO_PIN_MASK_8);
   //1 LED8
   GPIOInit_Output_Config(GPIOF_SFR,GPIO_PIN_MASK_1);
   //1 LED9
   GPIOInit_Output_Config(GPIOF_SFR,GPIO_PIN_MASK_2);
   //1 LED10
   GPIOInit_Output_Config(GPIOF_SFR,GPIO_PIN_MASK_3);
   //1 LED11
   GPIOInit_Output_Config(GPIOF_SFR,GPIO_PIN_MASK_4);

  //
    GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_11, RESET);
    GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_12, RESET);
	GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_13, RESET);
    GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_14, RESET);
	GPIO_Set_Output_Data_Bits(GPIOE_SFR,GPIO_PIN_MASK_6,  RESET);
    GPIO_Set_Output_Data_Bits(GPIOA_SFR,GPIO_PIN_MASK_13, RESET);
	GPIO_Set_Output_Data_Bits(GPIOA_SFR,GPIO_PIN_MASK_8,  RESET);
    GPIO_Set_Output_Data_Bits(GPIOF_SFR,GPIO_PIN_MASK_1,  RESET);
	GPIO_Set_Output_Data_Bits(GPIOF_SFR,GPIO_PIN_MASK_2,  RESET);
    GPIO_Set_Output_Data_Bits(GPIOF_SFR,GPIO_PIN_MASK_3,  RESET);
	GPIO_Set_Output_Data_Bits(GPIOF_SFR,GPIO_PIN_MASK_4,  RESET);
}


void led_out(void)
{
	GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_11, LEFT_WL);
	GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_12, LBEAM_WL);
	GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_13, HBEAM_WL);
	GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_14, FFOG_WL);
	GPIO_Set_Output_Data_Bits(GPIOE_SFR,GPIO_PIN_MASK_6,  RFOG_WL);
	GPIO_Set_Output_Data_Bits(GPIOA_SFR,GPIO_PIN_MASK_13, PARK_WL);
	GPIO_Set_Output_Data_Bits(GPIOA_SFR,GPIO_PIN_MASK_8,  AIR_LOW_WL);
	GPIO_Set_Output_Data_Bits(GPIOF_SFR,GPIO_PIN_MASK_1,  FDOOR_WL);
	GPIO_Set_Output_Data_Bits(GPIOF_SFR,GPIO_PIN_MASK_2,  MDOOR_WL);
	GPIO_Set_Output_Data_Bits(GPIOF_SFR,GPIO_PIN_MASK_3,  POWER_WL);
	GPIO_Set_Output_Data_Bits(GPIOF_SFR,GPIO_PIN_MASK_4,  RIGHT_SW);  
}








