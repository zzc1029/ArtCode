/*
 * led.h
 *
 *  Created on: 2021-8-7
 *      Author: ART
 */

#ifndef _LED_H_
#define _LED_H_



/*Define 74HC595 Pins	*/
#define HC595_DS(state)		GPIO_Set_Output_Data_Bits(GPIOA_SFR,GPIO_PIN_MASK_7, state)		//serial data input
#define HC595_SHCP(state)	GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_0, state)		//shift register clock input

//#define HC595_DS(state)     	GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_0, state)		//shift register clock input

//#define HC595_SHCP(state)		GPIO_Set_Output_Data_Bits(GPIOA_SFR,GPIO_PIN_MASK_7, state)		//serial data input

#define HC595_STCP(state)	GPIO_Set_Output_Data_Bits(GPIOA_SFR,GPIO_PIN_MASK_8, state)		//storage register clock input

extern TYPE_BYTE led[3];

#define RFOG_WL				led[0].bit.b0		//rear fog light
#define ABS_WL				led[0].bit.b1		//ABS
#define RIGHT				led[0].bit.b2		//turn right light
#define POWER_WL			led[0].bit.b3		//main power
#define OIL_LOW_WL			led[0].bit.b4		//oil pressure 
#define FILTER_WL			led[0].bit.b5		//air filter
#define DRYER_WL			led[0].bit.b6		//dryer
#define BATTERY_LOW_WL		led[0].bit.b7		//battery voltage

#define PARK_WL  			led[1].bit.b0		//low beam light  
#define STOP_WL				led[1].bit.b1		//stop light
#define HBEAM_WL			led[1].bit.b2		//high beam light
#define SERVICE_WL			led[1].bit.b3		//service light
#define AIR_LOW_WL			led[1].bit.b4		//air pressure 
#define PREHEAT_WL			led[1].bit.b5		//engine preheat
#define ENG_FAULT_WL		led[1].bit.b6		//engine fault
#define FFOG_WL				led[1].bit.b7		//front fog light

#define LEFT				led[2].bit.b0		//turn left lithg
#define LBEAM_WL			led[2].bit.b1		//parking
#define ENG_TEMP_HOT_WL		led[2].bit.b2		//coolant temperature
#define ENG_DOOR_WL			led[2].bit.b3		//engine root door open
#define MDOOR_WL			led[2].bit.b4		//middle door open
#define FUEL_LOW_WL			led[2].bit.b5		//fuel level
#define FDOOR_WL			led[2].bit.b6		//front door open
#define GENERATOR1_WL		led[2].bit.b7


void LedPortInit(void);
void led_out(void);


#endif

