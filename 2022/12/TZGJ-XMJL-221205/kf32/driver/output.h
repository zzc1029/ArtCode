/*
 * output.h
 *
 *  Created on: 2021-8-10
 *      Author: ART
 */
#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#define PROTECT_DELAY		10	//10秒恢复

#define OUTNUM  5

extern TYPE_BYTE  output_s;
extern uint8_t  feed_buff[];
extern uint16_t adc_100ma_fd[OUTNUM];

#define E3_PORT    GPIOG_SFR
#define E3_PIN     GPIO_PIN_MASK_6

#define E6_PORT    GPIOC_SFR
#define E6_PIN     GPIO_PIN_MASK_3

#define E7_PORT    GPIOC_SFR
#define E7_PIN     GPIO_PIN_MASK_2

#define E8_PORT    GPIOG_SFR
#define E8_PIN     GPIO_PIN_MASK_7

#define A16_PORT   GPIOC_SFR
#define A16_PIN    GPIO_PIN_MASK_12



#define METER_OPEN_E3  		output_s.bit.b0
#define METER_OPEN_E6  		output_s.bit.b1
#define METER_OPEN_E7  		output_s.bit.b2
#define METER_OPEN_E8  		output_s.bit.b3
#define METER_OPEN_WAKE_UP  output_s.bit.b4 //24V唤醒信号输出(AMP20接口的A16)

#define METER_OUT_E3       sw_diagnose[0].bits.bit4
#define METER_OUT_E8       sw_diagnose[0].bits.bit1
#define METER_OUT_E7       sw_diagnose[0].bits.bit2
#define METER_OUT_E6       sw_diagnose[0].bits.bit3

#define METER_OUT_WAKE_UP  sw_diagnose[1].bits.bit4

enum
{
 E3,
 E8	
};
enum
{
  E6,
  E7
};

#define SEL_E3E8(n)   GPIO_Set_Output_Data_Bits(GPIOC_SFR,GPIO_PIN_MASK_9,n);
#define SEL_E6E7(n)   GPIO_Set_Output_Data_Bits(GPIOC_SFR,GPIO_PIN_MASK_8,n);

typedef	union {
	uint8_t byte;
	struct
	{
		uint8_t bit4 : 2;
		uint8_t bit3 : 2;
		uint8_t bit2 : 2;
		uint8_t bit1 : 2;
	}bits;
}SW_DIAGNOSE_PW;


typedef struct {
	uint8_t  shorted :1;
	uint8_t  delay :6;
	uint8_t  handled  :1;	
	uint8_t  short_thr;
}OP_Protect_PW;

extern OP_Protect_PW op_protection[];
extern SW_DIAGNOSE_PW sw_diagnose[];

void OutPowerInit(void);
void feedback_diag(void);
void set_output(void);












#endif



