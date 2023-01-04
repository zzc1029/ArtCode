/*
 * ZD240Cx.h
 *
 *  Created on: 2022-5-5
 *      Author: ART
 */

#ifndef ZD240CX_H_
#define ZD240CX_H_

//实际使用ZD240C8   8K bits   1024bytes  16bytes one page  64pages

#define  ZD240C8_ADDR  0XA0


// SCL  PH12
// SDA  PH13

#define SDA_PORT GPIOH_SFR
#define SCL_PORT GPIOH_SFR
#define WP_PORT	 GPIOA_SFR

#define SDA_PIN  GPIO_PIN_MASK_13
#define SCL_PIN  GPIO_PIN_MASK_12
#define WP_PIN   GPIO_PIN_MASK_1

#define ZD_SDA_input()        GPIOInit_PullOd_Config(SDA_PORT,SDA_PIN,GPIO_MODE_IN,GPIO_NOPULL,GPIO_POD_OD)//GPIOInit_InputNOPULL_Config(SDA_PORT,SDA_PIN);  
#define ZD_SDA_output()       GPIOInit_PullOd_Config(SDA_PORT,SDA_PIN,GPIO_MODE_OUT,GPIO_NOPULL,GPIO_POD_OD)//GPIOInit_Output_OD_Config(SDA_PORT,SDA_PIN);

#define ZD_SCL_input()        GPIOInit_PullOd_Config(SCL_PORT,SCL_PIN,GPIO_MODE_IN,GPIO_NOPULL,GPIO_POD_PP)//GPIOInit_InputNOPULL_Config(GPIOB_SFR,SCL_PIN)//GPIOInit_InputNOPULL_Config(SCL_PORT,SCL_PIN); 
#define ZD_SCL_output()       GPIOInit_Output_Config(SCL_PORT,SCL_PIN);

#define ZD_SCL(state)         GPIO_Set_Output_Data_Bits(SCL_PORT,SCL_PIN, state)
#define ZD_SDA(state)         GPIO_Set_Output_Data_Bits(SDA_PORT,SDA_PIN, state)

#define ZD_READ_SDA           GPIO_Read_Input_Data_Bit(SDA_PORT,SDA_PIN)

//--------------------
#define ZD_WP_CONFIG()	      GPIOInit_Output_Config(WP_PORT,WP_PIN) 
#define ZD_WP_OUTPUT(state)   GPIO_Set_Output_Data_Bits(WP_PORT,WP_PIN, state)
//---------------------
void ZD_iic_init(void);

void ZD_write_add(unsigned int address,unsigned char date);
unsigned char ZD_read_add(unsigned int address);
unsigned char ZD_read_bytes(unsigned int address,unsigned char *date,unsigned int readnum);
void ZD_write_bytes(unsigned int address,unsigned char *date,unsigned char writenum);


#if 0
#define IIC_400K	400000
#define IIC_SOURCE  I2C3_SFR

void I2C_GPIO_init(void);
void I2C_init_Master(I2C_SFRmap* I2Cx);
void I2C_Byte_Write(uint16_t Write_i2c_Addr,uint32_t I2C_data);
void I2C_Buffer_write(uint16_t Write_i2c_Addr,uint8_t *p_buffer,uint16_t number_of_byte);
void I2C_byte_read(uint16_t Read_i2c_Addr,uint32_t I2C_data,uint16_t number_of_byte);
void I2C_Buffer_read(uint16_t Read_I2C_Addr,uint8_t *p_buffer,uint16_t number_of_byte);
#endif

#endif /* ZD240CX_H_ */
