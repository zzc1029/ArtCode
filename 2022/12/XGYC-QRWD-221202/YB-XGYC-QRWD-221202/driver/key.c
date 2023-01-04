/*
 * key.c
 *
 *  Created on: 2021-8-6
 *      Author: ART
 */


#include "system_init.h"
#include "keyfifo.h"

void KeyIoInit(void)
{
	//配置按键  ,后期根据硬件修改
	GPIOInit_Input_Config(GPIOA_SFR,GPIO_PIN_MASK_11);
	GPIOInit_Input_Config(GPIOA_SFR,GPIO_PIN_MASK_10);
	GPIOInit_Input_Config(GPIOA_SFR,GPIO_PIN_MASK_12);
	GPIOInit_Input_Config(GPIOA_SFR,GPIO_PIN_MASK_9);
}


static const KEY_EVENT KeyEvent[][3] =
{
	{IN_KEY_NONE,			IN_KEY_NONE,		IN_KEY_NONE 	},	//NO KEY
	{IN_KEY1_SP, 			IN_KEY1_CP,			IN_KEY1_RP		},
	{IN_KEY2_SP, 			IN_KEY2_CP,			IN_KEY2_RP		},
	{IN_KEY3_SP,			IN_KEY3_CP, 		IN_KEY3_RP		},
	{IN_KEY4_SP, 			IN_KEY4_CP,			IN_KEY4_RP		},
};


/*************************************************************************
* Function Name    : fst_bit_num_get
* Description		  : First bit position No. from bit0 (bit0 No. = 1).
* Parameters		 : temp
* Return Value	 :position
**************************************************************************/
uint8_t fst_bit_num_get(uint8_t temp)
{
	uint8_t	i = 0;

	while (temp)
	{
		i++;
		if (temp & 0x01)
		{
			break;
		}
		temp >>= 1;
	}
	return i;
}

/*************************************************************************
* Function Name    : read_key_port
* Description		  : read key from gpio
* Parameters		 : None
* Return Value	 :key
**************************************************************************/
uint8_t read_key_port(void)
{
	uint8_t key_dat = 0;
	if((KEY1 & KEY_MASK) == 0)
	{
		key_dat |= 0x01;
	}
	if((KEY2 & KEY_MASK) == 0)
	{
		key_dat |= 0x02;
	}
	if((KEY3 & KEY_MASK) == 0)
	{
		key_dat |= 0x04;
	}
	if((KEY4 & KEY_MASK) == 0)
	{
		key_dat |= 0x08;
	}

	return key_dat;

}

/*************************************************************************
* Function Name    : get_key
* Description		  : read which key press
* Parameters		 : None
* Return Value	 :key press
**************************************************************************/
KEY_EVENT get_key(void)
{
	static uint8_t key_state = KEY_STATE_IDLE;
	static uint8_t key_time = 0;
	static uint8_t key_index;
	KEY_EVENT key_return = IN_KEY_NONE;

	uint8_t key_value;


	key_value = read_key_port();
	if(key_value)
	{
		key_index = fst_bit_num_get(key_value);
	}

	switch(key_state)
	{
		case KEY_STATE_IDLE:
			if(key_value)
			{
				key_state = KEY_STATE_JITTER;
			}
			break;

		case KEY_STATE_JITTER:
			if(key_value)
			{
				key_time = 0;
				key_state = KEY_STATE_PRESS_DOWN;
			}
			else
			{
				key_state = KEY_STATE_IDLE;
			}
			break;

		case KEY_STATE_PRESS_DOWN:
			if(!key_value)
			{
				key_return = KeyEvent[key_index][0];
				key_state = KEY_STATE_IDLE;
			}
			else if(++key_time >= 50)
			{
				key_return = KeyEvent[key_index][1];
				key_state = KEY_STATE_PR;
				key_time = 0;
			}
			break;

		case KEY_STATE_PR:
			if(!key_value)
			{
				key_state = KEY_STATE_IDLE;
			}
			break;

		default:
			break;
	}
	return key_return;
}




void key_task(void)
{

	KEY_EVENT event;
	event = get_key();
	if(event)
	{
		message_send(MSG_FIFO_KEY,event);
	}
}













