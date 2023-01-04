#ifndef __POWER_ON_H__
#define __POWER_ON_H__

#include "includes.h"

typedef enum
{
    PS_Off = 0,
    PS_Start,
    PS_On,
    PS_Err,
		PS_Idle
} PoutStatus;

typedef struct
{
    char name[8];
    uint32_t gpio_periph;
    uint32_t magic; //shift = 23
	
    uint32_t time;
	
    uint32_t oc_time;
    uint16_t oct_threshold;
	
    uint32_t sc_time;
    uint16_t sct_threshold;

    uint16_t cur_100ma;
    uint16_t oc_threshold;
    uint16_t sc_threshold; 

    uint8_t pin;
    uint8_t adc_ch;

    uint8_t cmd;
    uint8_t diag;
    uint8_t rt_diag; //实时故障报警
    PoutStatus status;
    uint8_t errcount;

    uint8_t pwmable;   //输出端口 PWM 有效
    uint8_t pwmfixed;   //输出端口 PWM 设置 固定，can无法修改
    uint8_t pwmstart;   
    uint8_t pwmend;  
    uint8_t pwmi;   	

} PoutControl;


enum{
	A1,
	A9,
	A2,
	A10,
	A3,
	A11,
	A4,
	A12,
	A5,
	A13,
	A6,
	A14,
	A7,
	A42,
	A8,
};

//cacl current for VND5T016  K = 4200
//Iout = v/r*k; r = 510 k = 4200 v = adc/4096 *5
//Iout = adc/4096*5/510*4200 = adc / 99.4742857 = adc * 0.01 A
//Iout(100mA) = Iout(A) * 10  = adc * 0.1 = adc /10;

//cacl current for BTT6010 K = 3900
//Iout = v/r*k; r = 510 k = 3900 v = adc/4096 *5
//Iout = adc/4096*5/510*3900 = adc / 107.126153846 = adc * 0.0093347886 A
//Iout(100mA) = Iout(A) * 10  = adc * 0.093347886 = adc /10;

#define POUT_COUNT 15
	
extern PoutControl PoutS[POUT_COUNT];
extern uint8_t rain_int_cmd;


#define OD_OUT(level) gpio_bit_write(GPIOF, GPIO_PIN_6, (FlagStatus)(level))

//extern void power_out_init (void);
//extern void power_out (void);

#endif
