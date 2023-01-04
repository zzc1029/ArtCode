/*
 * iic.h
 *
 *  Created on: 2021-8-10
 *      Author: ART
 */
#ifndef _IIC_H_
#define _IIC_H_



#define ISL1208_ADDR 0xde

#define  WRITE      0
#define  READ       1
// SCL  PF0
// SDA  PB15

#define SDA_input()        GPIOInit_Input_Config(GPIOB_SFR,GPIO_PIN_MASK_15);  
#define SDA_output()       GPIOInit_Output_Config(GPIOB_SFR,GPIO_PIN_MASK_15);

#define SCL_input()        GPIOInit_Input_Config(GPIOF_SFR,GPIO_PIN_MASK_0); 
#define SCL_output()       GPIOInit_Output_Config(GPIOF_SFR,GPIO_PIN_MASK_0);

#define SCL(state)         GPIO_Set_Output_Data_Bits(GPIOF_SFR,GPIO_PIN_MASK_0, state)
#define SDA(state)         GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_15, state)

#define READ_SDA           GPIO_Read_Input_Data_Bit(GPIOB_SFR,GPIO_PIN_MASK_15)


void iic_init(void);
void delay_(volatile unsigned int ms);

void write_add(unsigned char address,unsigned char date);
unsigned char read_add(unsigned char address);


#endif





