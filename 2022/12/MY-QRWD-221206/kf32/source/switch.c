/*
 * switch.c
 *
 *  Created on: 2021-8-7
 *      Author: ART
 MCLK:92脚位  PG7  PF3
 */

#include "system_init.h"

void HC165PortInit(void)
{
  GPIOInit_Output_Config(GPIOB_SFR,GPIO_PIN_MASK_1); 
  GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_1, RESET);
  GPIOInit_Output_Config(GPIOB_SFR,GPIO_PIN_MASK_3); 
  GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_3, RESET);
  // SCLK 输出
  GPIOInit_Output_Config(GPIOG_SFR,GPIO_PIN_MASK_7);
  // PL 输出
  GPIOInit_Output_Config(GPIOF_SFR,GPIO_PIN_MASK_3);
  // MISO 输入
  GPIOInit_Input_Config(GPIOC_SFR,GPIO_PIN_MASK_8);  

  //
  GPIO_Set_Output_Data_Bits(GPIOG_SFR,GPIO_PIN_MASK_7, RESET);
  GPIO_Set_Output_Data_Bits(GPIOF_SFR,GPIO_PIN_MASK_3, RESET);

  
  // PC14 输入  PTC14
  GPIOInit_Input_Config(GPIOC_SFR,GPIO_PIN_MASK_10);  
  // PC15 输入  PTC15
  GPIOInit_Input_Config(GPIOC_SFR,GPIO_PIN_MASK_9);  

  // PB12 输入  PTA12  IL1
  GPIOInit_Input_Config(GPIOB_SFR,GPIO_PIN_MASK_13); 
  
  // PB13 输入  PTA20  IL2
  GPIOInit_Input_Config(GPIOB_SFR,GPIO_PIN_MASK_14);  
  
  // PB7 输入  PTA15  IL3
  GPIOInit_Input_Config(GPIOB_SFR,GPIO_PIN_MASK_7); 
  // PB8 输入  PTA6  IL4
  GPIOInit_Input_Config(GPIOB_SFR,GPIO_PIN_MASK_8);    
}


TYPE_QWORD port_mask;
TYPE_WORD  port_a;
TYPE_WORD  port_c;
TYPE_WORD  port_d;
TYPE_WORD  port_b;
TYPE_BYTE sw_input[5] = {0, 0, 0, 0, 0};

volatile uint8_t i, j, k;

/*************************************************************************
* Function Name    : switch_task
* Description         : this function is read switch form 74HC165
* Parameters         : None
* Return Value       :None
**************************************************************************/
void switch_task(void)
{
	uint8_t dump;
	HC165_PL(RESET);
	for(k = 0; k < 9; k++)
	{
		asm("nop");
	}
	HC165_PL(SET);
	dump=0;
	for(j = 0; j < 5; j++)
	{
		for(i=0;i<8;i++)
		{
			HC165_CP(RESET);
			for(k = 0; k < 9; k++)
			{
				asm("nop");
			}
			dump = (dump<<1);
			dump |= HC165_Q7;
			HC165_CP(SET);
			for(k = 0; k < 9; k++)
			{
				asm("nop");
			}
		}
		sw_input[j].byte = dump ^ port_mask.byte[j];
	}

	
	port_a.bit.b0 = sw_input[0].bit.b3;		//A7
	port_a.bit.b1 = sw_input[0].bit.b2;		//A8
	port_a.bit.b2 = sw_input[0].bit.b1;		//A9
	port_a.bit.b3 = sw_input[0].bit.b0;		//A10
	port_a.bit.b4 = sw_input[0].bit.b7;		//A17
	port_a.bit.b5 = sw_input[0].bit.b6;		//A18
	port_a.bit.b6 = sw_input[0].bit.b5;		//A19

    // PTA6
	port_a.bit.b7  = (GPIO_Read_Input_Data_Bit(GPIOB_SFR,GPIO_PIN_MASK_8) == RESET);		
    // PTA12
	port_a.bit.b8  = (GPIO_Read_Input_Data_Bit(GPIOB_SFR,GPIO_PIN_MASK_13) == RESET);
    // PTA15
	port_a.bit.b9  = (GPIO_Read_Input_Data_Bit(GPIOB_SFR,GPIO_PIN_MASK_7) == RESET);
    // PTA20
	port_a.bit.b10 = (GPIO_Read_Input_Data_Bit(GPIOB_SFR,GPIO_PIN_MASK_14) == RESET);


	port_c.bit.b0 = sw_input[1].bit.b7;		//C10
	port_c.bit.b1 = sw_input[1].bit.b6;		//C11
	port_c.bit.b2 = sw_input[1].bit.b5;		//C12
	port_c.bit.b3 = sw_input[1].bit.b4;		//C13
	port_c.bit.b4 = sw_input[0].bit.b4;		//C20

    // PTC14
	port_c.bit.b8 = (GPIO_Read_Input_Data_Bit(GPIOC_SFR,GPIO_PIN_MASK_10) == RESET);		//C20
	// PTC15
	port_c.bit.b9 = (GPIO_Read_Input_Data_Bit(GPIOC_SFR,GPIO_PIN_MASK_9)  == RESET);		//C20



	port_d.bit.b0 = sw_input[1].bit.b2;		//D1
	port_d.bit.b1 = sw_input[1].bit.b0;		//D2
	port_d.bit.b2 = sw_input[2].bit.b6;		//D3
	port_d.bit.b3 = sw_input[2].bit.b4;		//D4
	port_d.bit.b4 = sw_input[2].bit.b2;		//D5
	port_d.bit.b5 = sw_input[2].bit.b0;		//D6
	port_d.bit.b6 = sw_input[3].bit.b6;		//D7
	port_d.bit.b7 = sw_input[3].bit.b4;		//D8
	port_d.bit.b8 = sw_input[1].bit.b3;		//D9
	port_d.bit.b9 = sw_input[1].bit.b1;		//D10
	port_d.bit.b10 = sw_input[2].bit.b7;	//D11
	port_d.bit.b11 = sw_input[2].bit.b5;	//D12
	port_d.bit.b12 = sw_input[2].bit.b3;	//D13
	port_d.bit.b13 = sw_input[2].bit.b1;	//D14
	port_d.bit.b14 = sw_input[3].bit.b7;	//D15
	port_d.bit.b15 = sw_input[3].bit.b5;	//D16

	port_b.bit.b0 = sw_input[3].bit.b2;		//B1
	port_b.bit.b1 = sw_input[3].bit.b0;		//B2
	port_b.bit.b2 = sw_input[4].bit.b6;		//B3
	port_b.bit.b3 = sw_input[4].bit.b4;		//B4
	port_b.bit.b4 = sw_input[4].bit.b2;		//B5
	port_b.bit.b5 = sw_input[4].bit.b0;		//B6
	port_b.bit.b6 = sw_input[3].bit.b3;		//B7
	port_b.bit.b7 = sw_input[3].bit.b1;		//B8
	port_b.bit.b8 = sw_input[4].bit.b7;		//B9
	port_b.bit.b9 = sw_input[4].bit.b5;		//B10
	port_b.bit.b10 = sw_input[4].bit.b3;	//B11
	port_b.bit.b11 = sw_input[4].bit.b1;	//B12


 //1  
}

















