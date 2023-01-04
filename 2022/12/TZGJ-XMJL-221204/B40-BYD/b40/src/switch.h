#ifndef __SWITCH_H__
#define __SWITCH_H__

#include "includes.h"

extern uint8_t in_sw[3];

#define OD_IN() ((GPIO_PTD(GPIOF)&(GPIO_PIN_6)) != 0x00U)//gpio_bit_get(GPIOF, GPIO_PIN_6)
#define ADD1_IN() ((GPIO_PTD(GPIOE)&(GPIO_PIN_4)) != 0x00U)//gpio_bit_get(GPIOE, GPIO_PIN_4)
#define KH1_IN() ((GPIO_PTD(GPIOE)&(GPIO_PIN_3)) != 0x00U)//gpio_bit_get(GPIOE, GPIO_PIN_3)  


extern void mod_addr_init (void);

//extern void din_init (void);
//extern void din_app (void);

#endif
