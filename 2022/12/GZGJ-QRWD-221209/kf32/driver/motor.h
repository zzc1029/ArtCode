/*
 * motor.h
 *
 *  Created on: 2021-8-10
 *      Author: ART
 */

#ifndef _MOTOR_H_
#define _MOTOR_H_



/***ָ���λ�ã��Ǳ����泯�ϣ�0��1��������ָ�룬һ��0��ת�ٱ�1�ǳ��ٱ�****



                    2 (bar2)         3(����)

           0  (veh_soc)                          1(bar1)

           4 (Vbat)                           5(ת��)



***************************************************************************/

#define MOTOR1CW()   GPIO_Set_Output_Data_Bits(GPIOD_SFR,GPIO_PIN_MASK_5, SET)
#define MOTOR1CCW()  GPIO_Set_Output_Data_Bits(GPIOD_SFR,GPIO_PIN_MASK_5, RESET)
#define MOTOR2CW()   GPIO_Set_Output_Data_Bits(GPIOD_SFR,GPIO_PIN_MASK_6, SET)
#define MOTOR2CCW()  GPIO_Set_Output_Data_Bits(GPIOD_SFR,GPIO_PIN_MASK_6, RESET)

#define MOTOR3CW()   GPIO_Set_Output_Data_Bits(GPIOH_SFR,GPIO_PIN_MASK_9, SET)
#define MOTOR3CCW()  GPIO_Set_Output_Data_Bits(GPIOH_SFR,GPIO_PIN_MASK_9, RESET)

#define MOTOR4CW()   GPIO_Set_Output_Data_Bits(GPIOH_SFR,GPIO_PIN_MASK_5, SET)
#define MOTOR4CCW()  GPIO_Set_Output_Data_Bits(GPIOH_SFR,GPIO_PIN_MASK_5, RESET)
#define MOTOR5CW()   GPIO_Set_Output_Data_Bits(GPIOD_SFR,GPIO_PIN_MASK_13, SET)
#define MOTOR5CCW()  GPIO_Set_Output_Data_Bits(GPIOD_SFR,GPIO_PIN_MASK_13, RESET)

#define MOTOR6CW()   GPIO_Set_Output_Data_Bits(GPIOH_SFR,GPIO_PIN_MASK_14, SET)
#define MOTOR6CCW()  GPIO_Set_Output_Data_Bits(GPIOH_SFR,GPIO_PIN_MASK_14, RESET)



#define MOTOR1FEN(state) GPIO_Set_Output_Data_Bits(GPIOD_SFR,GPIO_PIN_MASK_4, state)
#define MOTOR2FEN(state) GPIO_Set_Output_Data_Bits(GPIOD_SFR,GPIO_PIN_MASK_7, state)
#define MOTOR3FEN(state) GPIO_Set_Output_Data_Bits(GPIOH_SFR,GPIO_PIN_MASK_8, state)
#define MOTOR4FEN(state) GPIO_Set_Output_Data_Bits(GPIOH_SFR,GPIO_PIN_MASK_6, state)
#define MOTOR5FEN(state) GPIO_Set_Output_Data_Bits(GPIOD_SFR,GPIO_PIN_MASK_14, state)
#define MOTOR6FEN(state) GPIO_Set_Output_Data_Bits(GPIOH_SFR,GPIO_PIN_MASK_12, state)



typedef struct _MOTOR_TYPE
{
	uint16_t cur_step;	//current step	
	uint16_t pre_step;	//pre step
	uint16_t diff_step;	//different step
	uint16_t step_delay;	//! Peroid of next timer delay.
	uint16_t delay;	//! Peroid of next timer delay.
}MOTOR_T;


typedef struct _MOTOR_Data
{
	volatile uint16_t * Data;	//current step	
	float scale;
	uint16_t maxstep;
	uint16_t min;
	uint16_t max;
	
//	vuint8_t* C;	
//	vuint8_t* F;
	
}MOTOR_Data;


typedef struct
{
	void (*operate)();
	uint16_t delay;
	uint16_t period;
}Task_t;

extern MOTOR_T motorctrl[6];
extern MOTOR_Data motor[6];

//�����ʼ��
void InitMotor(void);
//�����������
void motor_task(void);
//��ʱ������
void  Motor_Isr(void);

// ����ϵ縴λ
void reset_motor(void);


#endif



