#ifndef __SWITCH_H__
#define __SWITCH_H__

#include "includes.h"



extern uint8_t in_sw[3];

#define OD_IN() gpio_bit_get(GPIOF, GPIO_PIN_6)
#define ADD1_IN() gpio_bit_get(GPIOE, GPIO_PIN_4)
#define KH1_IN() gpio_bit_get(GPIOE, GPIO_PIN_3)


#define MOD_ADDR ((in_sw[1] >> 4) & 3)

extern int protothread_in (struct pt *pt);



#endif
