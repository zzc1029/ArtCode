/*
 * key.h
 * °´¼üÇý¶¯º¯Êý
 *  Created on: 2021-8-6
 *      Author: ART
 */
#ifndef _KEY_H_
#define _KEY_H_

#define KEY1	GPIO_Read_Input_Data_Bit(GPIOA_SFR,GPIO_PIN_MASK_9)
#define KEY2	GPIO_Read_Input_Data_Bit(GPIOA_SFR,GPIO_PIN_MASK_10)
#define KEY3	GPIO_Read_Input_Data_Bit(GPIOA_SFR,GPIO_PIN_MASK_13)
#define KEY4	GPIO_Read_Input_Data_Bit(GPIOA_SFR,GPIO_PIN_MASK_14)
#define KEY5	GPIO_Read_Input_Data_Bit(GPIOE_SFR,GPIO_PIN_MASK_6)
#define KEY6	GPIO_Read_Input_Data_Bit(GPIOA_SFR,GPIO_PIN_MASK_15)

typedef enum _KEY_EVENT
{
	IN_KEY_NONE = 0x00,
	IN_KEY1_SP,
	IN_KEY1_CP,
	IN_KEY2_SP,
	IN_KEY2_CP,
	IN_KEY3_SP,
	IN_KEY3_CP,
	IN_KEY4_SP,
	IN_KEY4_CP,
	IN_KEY5_SP,
	IN_KEY5_CP,
	IN_KEY6_SP,
	IN_KEY6_CP,
	IN_KEY1_RP,
	IN_KEY2_RP,
	IN_KEY3_RP,
	IN_KEY4_RP,
	IN_KEY5_RP,
	IN_KEY6_RP

}KEY_EVENT;

typedef enum _KEY_STATE
{
	KEY_STATE_IDLE,
	KEY_STATE_JITTER,
	KEY_STATE_PRESS_DOWN,
	KEY_STATE_PR
} KEY_STATE;


#define KEY_MASK 0x01


void KeyIoInit(void);

void key_task(void);






#endif




