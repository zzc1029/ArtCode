/*
 * Adc.h
 *
 *  Created on: 2021-8-6
 *      Author: ART
 */
 
#ifndef _ADC_H
#define _ADC_H

#define VREF 3300

enum
{
   metera2 = 0,
   metera3 = 1,
   metera4 = 2,
   metera13 = 3,
   metera14 = 4,
   metervbat = 5,
   meterE3E8,
   meterE6E7,
   //meterE7,
   //meterE8,
   meterA16
};

extern Meter meter;

typedef union Adc_value_name
{
	unsigned short buf_16;
	unsigned char buf_8[2];
}Adc_value;


void Init_adc(void);
void AdcInit(void);
void ReadAdcResult(void);







#endif

