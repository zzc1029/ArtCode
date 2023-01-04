/*
 * iic.h
 *
 *  Created on: 2021-8-10
 *      Author: ART
 */
#ifndef _IIC_H_
#define _IIC_H_


#if 0
#define	MODE_Master	1					 //主机模式
#define	MODE_Slave	0                    //从机模式

#define	IIC_MODE	MODE_Master			//0——从机模式，1——主机模式

#define	IIC_10BIT_Address		0	    //0——7位地址模式，1——10位地址模式

#define ISL1208_ADDR 0xde

//主机模式下波特率的选择
//#define IIC_100K	100000
#define IIC_400K	400000
//#define IIC_1M	1000000

#define I2C_OK                 1
#define I2C_FAIL               0



void I2C_GPIO_init(void);
void I2C_init_Slave(I2C_SFRmap* I2Cx,uint16_t I2C_ADDRESS);
void I2C_init_Master(I2C_SFRmap* I2Cx);
void I2C_Byte_Write(uint16_t Write_i2c_Addr,uint32_t I2C_data);
void I2C_Buffer_write(uint16_t Write_i2c_Addr,uint8_t *p_buffer,uint16_t number_of_byte);
void I2C_byte_read(uint16_t Read_I2C_Addr,uint32_t I2C_data,uint16_t number_of_byte);
void I2C_Buffer_read(uint16_t Read_I2C_Addr,uint8_t *p_buffer,uint16_t number_of_byte);
#endif

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





