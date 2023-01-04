/*
 * gpio.h
 *
 *  Created on: 2021-8-6
 *      Author: ART
 */

#ifndef _GPIO_H_
#define _GPIO_H_








void GPIOInit_Output_Config(GPIO_SFRmap* GPIOx,uint16_t GpioPin);
void GPIOInit_Input_Config(GPIO_SFRmap* GPIOx,uint16_t GpioPin);
void GPIOInit_PullOd_Config(GPIO_SFRmap* GPIOx,uint16_t GpioPin,GPIOMode_TypeDef Mode,GPIOPU_TypeDef pull,GPIOPOD_TypeDef state);









#endif


