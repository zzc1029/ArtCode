/*
 * motor.c
 *
 *  Created on: 2021-8-10
 *      Author: ART

 MD1F:  PTD4
 MD1C:  PTD5
 
 MD2F:  PTD7
 MD2C:  PTD6

//与OSC引脚撞一起  下一版本调试
 MD3F:  PTD10
 MD3C:  PTD9

 MD4F:  PTH6
 MD4C:  PTH5

 MD5F:  PTD14
 MD5C:  PTD13


 MD6F:  PTH12
 MD6C:  PTH14
 
 */
#include "system_init.h"

MOTOR_Data motor[6];
MOTOR_T motorctrl[6];

void MotorPortInit(void)
{
	//MD1F:  PTD4
	GPIOInit_Output_Config(GPIOD_SFR,GPIO_PIN_MASK_4);
	GPIO_Set_Output_Data_Bits(GPIOD_SFR,GPIO_PIN_MASK_4, RESET);
	//MD1C:  PTD5
	GPIOInit_Output_Config(GPIOD_SFR,GPIO_PIN_MASK_5);
	//MD2F:  PTD6
	GPIOInit_Output_Config(GPIOD_SFR,GPIO_PIN_MASK_6);	
	GPIO_Set_Output_Data_Bits(GPIOD_SFR,GPIO_PIN_MASK_6, RESET);
	//MD2C:  PTD7
	GPIOInit_Output_Config(GPIOD_SFR,GPIO_PIN_MASK_7);
	
	//MD3F:  PTH8
	GPIOInit_Output_Config(GPIOH_SFR,GPIO_PIN_MASK_8);
	//MD3C:  PTH9
	GPIOInit_Output_Config(GPIOH_SFR,GPIO_PIN_MASK_9);
    GPIO_Set_Output_Data_Bits(GPIOH_SFR,GPIO_PIN_MASK_8, RESET);	
	//GPIO_Set_Output_Data_Bits(GPIOH_SFR,GPIO_PIN_MASK_9, RESET);
	
	//MD4F:  PTH5
	GPIOInit_Output_Config(GPIOH_SFR,GPIO_PIN_MASK_5);
	GPIO_Set_Output_Data_Bits(GPIOH_SFR,GPIO_PIN_MASK_5, RESET);
	//MD4C:  PTH6
	GPIOInit_Output_Config(GPIOH_SFR,GPIO_PIN_MASK_6);
	
	//MD5C:  PTD13
	GPIOInit_Output_Config(GPIOD_SFR,GPIO_PIN_MASK_13);

	//MD5F:  PTD14
	GPIOInit_Output_Config(GPIOD_SFR,GPIO_PIN_MASK_14);
	GPIO_Set_Output_Data_Bits(GPIOD_SFR,GPIO_PIN_MASK_14, RESET);
	
	//MD6C:  PTH14
	GPIOInit_Output_Config(GPIOH_SFR,GPIO_PIN_MASK_14);
	GPIO_Set_Output_Data_Bits(GPIOH_SFR,GPIO_PIN_MASK_14, RESET);
	//MD6F:  PTH12
	GPIOInit_Output_Config(GPIOH_SFR,GPIO_PIN_MASK_12);
	GPIO_Set_Output_Data_Bits(GPIOH_SFR,GPIO_PIN_MASK_12, RESET);

}
/*
M1: MC5D MD5F 





*/

   
void InitMotor(void)
{
    MotorPortInit();
    motor[0].Data = Rotate_Speed_SOURCE;
    motor[0].maxstep = 2700;    
    motor[0].min = 0;
    motor[0].max = 6000;
    motor[0].scale = (float)(motor[0].maxstep)/(motor[0].max-motor[0].min);
    

    //显示范围0~140Km/h 内部变量范围 0-1400
    motor[1].Data = Vehicle_Speed_SOURCE;
    motor[1].maxstep = 2700;
    motor[1].min = 0;
    motor[1].max = 1400;
    motor[1].scale = (float)(motor[1].maxstep)/(motor[1].max-motor[1].min);    

	//显示范围80-120度
	motor[2].Data = Motor2_SOURCE;
	motor[2].maxstep = 960;
    motor[2].min = 0;
    motor[2].max = 120;
	motor[2].scale = (float)(motor[2].maxstep)/(motor[2].max-motor[2].min);	  

	//显示范围0~10bar 内部变量范围 0-100
	motor[3].Data = Motor3_SOURCE;
	motor[3].maxstep = 960;
    motor[3].min = 0;
    motor[3].max = 120;
	motor[3].scale = (float)(motor[3].maxstep)/(motor[3].max-motor[3].min);  

	//显示范围0~1 内部变量范围 0-100
	motor[4].Data = Motor4_SOURCE;
	motor[4].maxstep = 960;
    motor[4].min = 0;
    motor[4].max = 100;
	motor[4].scale = (float)(motor[4].maxstep)/(motor[4].max-motor[4].min);  

	//指针范围0-960，内部变量范围 160-320
	motor[5].Data = Motor5_SOURCE;
	motor[5].maxstep = 960;
    motor[5].min = 160;
    motor[5].max = 320;
	motor[5].scale = (float)(motor[5].maxstep)/(motor[5].max-motor[5].min);  
}



static void TurnSpeed(MOTOR_T * motorctrl)
{

    if(motorctrl[0].diff_step > 480)
    {
        motorctrl[0].step_delay = 1;
    }
    else if(motorctrl[0].diff_step > 360)
    {
        motorctrl[0].step_delay = 2;
    }
    else if(motorctrl[0].diff_step > 240)
    {
        motorctrl[0].step_delay = 3;
    }
    else if(motorctrl[0].diff_step > 180)
    {
        motorctrl[0].step_delay = 4;
    }
    else if(motorctrl[0].diff_step > 120)
    {
        motorctrl[0].step_delay = 5;
    }
    else if(motorctrl[0].diff_step > 80)
    {
        motorctrl[0].step_delay = 6;
    }
    else if(motorctrl[0].diff_step > 60)
    {
        motorctrl[0].step_delay = 7;
    }
    else if(motorctrl[0].diff_step > 48)
    {
        motorctrl[0].step_delay = 8;
    }
    else if(motorctrl[0].diff_step > 36)
    {
        motorctrl[0].step_delay = 9;
    }
    else if(motorctrl[0].diff_step > 24)
    {
        motorctrl[0].step_delay = 10;
    }
    else if(motorctrl[0].diff_step > 12)
    {
        motorctrl[0].step_delay = 15;
    }
    else
    {
        motorctrl[0].step_delay = 20;
    }

}



//大表任务   转速
void MotorTaskEngspeed(MOTOR_T * motorctrlx,MOTOR_Data * motorx)
{
    if(motorx->Data == 0)
        motorctrlx->cur_step = 0;
    else
        motorctrlx->cur_step = (*(motorx->Data))*(motorx->scale);

    if(motorctrlx->cur_step >= motorx->maxstep)
        motorctrlx->cur_step = motorx->maxstep;
    if(motorctrlx->cur_step >= motorctrlx->pre_step)
    {
        MOTOR5CCW();
        motorctrlx->diff_step = motorctrlx->cur_step - motorctrlx->pre_step;
    }
    else
    {
        MOTOR5CW();
        motorctrlx->diff_step = motorctrlx->pre_step - motorctrlx->cur_step;
    }

    TurnSpeed(motorctrlx);
}

//大表任务   转速
void MotorTaskVehspeed(MOTOR_T * motorctrlx,MOTOR_Data * motorx)
{
    if(motorx->Data == 0)
        motorctrlx->cur_step = 0;
    else
        motorctrlx->cur_step = (*(motorx->Data))*(motorx->scale);

    if(motorctrlx->cur_step >= motorx->maxstep)
        motorctrlx->cur_step = motorx->maxstep;
    if(motorctrlx->cur_step >= motorctrlx->pre_step)
    {
        MOTOR3CCW();
        motorctrlx->diff_step = motorctrlx->cur_step - motorctrlx->pre_step;
    }
    else
    {
        MOTOR3CW();
        motorctrlx->diff_step = motorctrlx->pre_step - motorctrlx->cur_step;
    }
    TurnSpeed(motorctrlx);
}

//小表任务   气压1
void MotorTaskVehbar1(MOTOR_T * motorctrlx,MOTOR_Data * motorx)
{
    if(motorx->Data == 0)
        motorctrlx->cur_step = 0;
    else
        motorctrlx->cur_step = (*(motorx->Data))*(motorx->scale);

    if(motorctrlx->cur_step >= motorx->maxstep)
        motorctrlx->cur_step = motorx->maxstep;
    if(motorctrlx->cur_step >= motorctrlx->pre_step)
    {
        MOTOR4CCW();
        motorctrlx->diff_step = motorctrlx->cur_step - motorctrlx->pre_step;
    }
    else
    {
        MOTOR4CW();
        motorctrlx->diff_step = motorctrlx->pre_step - motorctrlx->cur_step;
    }

    TurnSpeed(motorctrlx);
}
//小表任务   气压2
void MotorTaskVehbar2(MOTOR_T * motorctrlx,MOTOR_Data * motorx)
{
    if(motorx->Data == 0)
        motorctrlx->cur_step = 0;
    else
        motorctrlx->cur_step = (*(motorx->Data))*(motorx->scale);

    if(motorctrlx->cur_step >= motorx->maxstep)
        motorctrlx->cur_step = motorx->maxstep;
    if(motorctrlx->cur_step >= motorctrlx->pre_step)
    {
        MOTOR2CCW();
        motorctrlx->diff_step = motorctrlx->cur_step - motorctrlx->pre_step;
    }
    else
    {
        MOTOR2CW();
        motorctrlx->diff_step = motorctrlx->pre_step - motorctrlx->cur_step;
    }

    TurnSpeed(motorctrlx);
}


//小表任务   SOC
void MotorTaskVehSOC(MOTOR_T * motorctrlx,MOTOR_Data * motorx)
{
    if(motorx->Data == 0)
        motorctrlx->cur_step = 0;
    else
        motorctrlx->cur_step = (*(motorx->Data))*(motorx->scale);

    if(motorctrlx->cur_step >= motorx->maxstep)
        motorctrlx->cur_step = motorx->maxstep;
    if(motorctrlx->cur_step >= motorctrlx->pre_step)
    {
        MOTOR6CCW();
        motorctrlx->diff_step = motorctrlx->cur_step - motorctrlx->pre_step;
    }
    else
    {
        MOTOR6CW();
        motorctrlx->diff_step = motorctrlx->pre_step - motorctrlx->cur_step;
    }

    TurnSpeed(motorctrlx);
}



//小表任务  Vbat
void MotorTaskVehVbat(MOTOR_T * motorctrlx,MOTOR_Data * motorx)
{
    if(motorx->Data == 0)
        motorctrlx->cur_step = 0;
    else
    {
        if((*(motorx->Data)) > motorx->max)
        {
            motorctrlx->cur_step = motorx->maxstep;
        }
        else if((*(motorx->Data)) < motorx->min)
        {
            motorctrlx->cur_step = 0;
        }
        else
        {
            motorctrlx->cur_step = ((*(motorx->Data))-motorx->min)*(motorx->scale);
        }
    }

    if(motorctrlx->cur_step >= motorctrlx->pre_step)
    {
        MOTOR1CCW();
        motorctrlx->diff_step = motorctrlx->cur_step - motorctrlx->pre_step;
    }
    else
    {
        MOTOR1CW();
        motorctrlx->diff_step = motorctrlx->pre_step - motorctrlx->cur_step;
    }

    TurnSpeed(motorctrlx);
}

Task_t gauge_task[6]=
{
    {(*MotorTaskEngspeed),        1, 5}, //eng_speed
    {(*MotorTaskVehspeed),        2, 6}, //veh_speed
    {(*MotorTaskVehbar1),         3, 7}, //vbat
    {(*MotorTaskVehbar2),         4, 8}, //veh_bar1
	{(*MotorTaskVehSOC),          5, 9} ,   
    {(*MotorTaskVehVbat),         6, 10} //veh_bar2 
};


inline void delay_us(volatile uint16_t n)
{
	while(n-- > 0)
	{
		;
	}
}

const uint16_t delay_time[13] = {6870, 5830, 4590, 3500, 3450, 3260, 3130, 3020, 2930, 2860,2790, 2640,2500};

void reset_motor(void)
{
	volatile uint16_t i = 0, j, k;

	MOTOR6CW();
	MOTOR5CW();
	MOTOR4CW();
	MOTOR3CW();
	MOTOR2CW();
	MOTOR1CW();

	for(i = 0; i < 230; i++)
	{
		for(j = 0; j < 12; j++)
		{
			MOTOR1FEN(SET);
			MOTOR2FEN(SET);
			MOTOR3FEN(SET);
			MOTOR4FEN(SET);
			MOTOR5FEN(SET);
			MOTOR6FEN(SET);

			for(k = 0; k < 6; k++)
			{
				asm("nop");
			}
			MOTOR1FEN(RESET);
			MOTOR2FEN(RESET);
			MOTOR3FEN(RESET);
			MOTOR4FEN(RESET);
			MOTOR5FEN(RESET);
			MOTOR6FEN(RESET);

			if(i < 12)
			{
				delay_us(delay_time[i]);
			}
			else
			{
				delay_us(delay_time[12]);
			}	
		}
		
	}
}


void motor_task(void)
{

    uint8_t i;
    static uint8_t flag = 0;
	

#ifdef SELF_TEST_BY_METRE

    if(KEY_ON && SELF_TEST)
    {
        if(!HALF_SELF_TEST_TIME)
        {
            motorctrl[0].cur_step   = motor[0].maxstep;
            motorctrl[1].cur_step   = motor[1].maxstep;
            motorctrl[2].cur_step   = motor[2].maxstep;
            motorctrl[3].cur_step   = motor[3].maxstep;
            motorctrl[4].cur_step   = motor[4].maxstep;
            motorctrl[5].cur_step   = motor[5].maxstep;

            motorctrl[0].step_delay = 0;
            motorctrl[1].step_delay = 0;
            motorctrl[2].step_delay = 3;
            motorctrl[3].step_delay = 3;
            motorctrl[4].step_delay = 3;
            motorctrl[5].step_delay = 3;
            MOTOR1CCW();
			MOTOR2CCW();
			MOTOR3CCW();
			MOTOR4CCW();
			MOTOR5CCW();
			MOTOR6CCW();
        }
        else
        {
            motorctrl[0].cur_step   = 0;
            motorctrl[1].cur_step   = 0;
            motorctrl[2].cur_step   = 0;
            motorctrl[3].cur_step   = 0;
            motorctrl[4].cur_step   = 0;
            motorctrl[5].cur_step   = 0;

            motorctrl[0].step_delay = 0;
            motorctrl[1].step_delay = 0;
            motorctrl[2].step_delay = 3;
            motorctrl[3].step_delay = 3;
            motorctrl[4].step_delay = 3;
            motorctrl[5].step_delay = 3;

            MOTOR1CW();
			MOTOR2CW();
			MOTOR3CW();
			MOTOR4CW();
			MOTOR5CW();
			MOTOR6CW();
        }
    }
    else if(KEY_ON && (Vbat >= LEAST_VOLTAGE))
#else
    if(KEY_ON && (Vbat >= LEAST_VOLTAGE))
#endif
    {
        for(i = 0; i < ((sizeof(gauge_task)/sizeof(Task_t))); i++)//
        {
            if(gauge_task[i].delay == 0)
            {
                (*gauge_task[i].operate)(&(motorctrl[i]),&(motor[i]));
                gauge_task[i].delay = gauge_task[i].period;
            }
            else
            {
                gauge_task[i].delay--;
            }
        }
    }
    else
    {
        motorctrl[0].cur_step   = 0;
        motorctrl[1].cur_step   = 0;
        motorctrl[2].cur_step   = 0;
        motorctrl[3].cur_step   = 0;
        motorctrl[4].cur_step   = 0;
        motorctrl[5].cur_step   = 0;

        motorctrl[0].step_delay = 0;
        motorctrl[1].step_delay = 0;
        motorctrl[2].step_delay = 3;
        motorctrl[3].step_delay = 3;
        motorctrl[4].step_delay = 3;
        motorctrl[5].step_delay = 3;

		MOTOR6CW();
		MOTOR5CW();
		MOTOR4CW();
		MOTOR3CW();
		MOTOR2CW();
		MOTOR1CW();
    }
}




/*************************************************************************
Function Name    : pit_isr
Parameters       : None
Return Value         : None
Notes           : Triggered when    period interrupt timer time-out
**************************************************************************/
void  Motor_Isr(void)
{
    static uint32_t step_delay[(sizeof(gauge_task)/sizeof(Task_t))] = {0};
    volatile uint8_t  i,k;

    for(i=0; i<(sizeof(gauge_task)/sizeof(Task_t)); i++)
    {
        if(step_delay[i]++ >= motorctrl[i].step_delay)
        {
            if(motorctrl[i].cur_step != motorctrl[i].pre_step)
            {
                if(motorctrl[i].cur_step > motorctrl[i].pre_step)
                {
                    motorctrl[i].pre_step++;
                }
                else
                {
                    motorctrl[i].pre_step--;
                }
				switch(i)
				{
                  case 0:
				  	    MOTOR5FEN(SET);
				        break;
	              case 1:
				  	    MOTOR3FEN(SET);
				        break;
			      case 2:
				  	    MOTOR4FEN(SET);
				        break;
				  case 3:
				  	    MOTOR2FEN(SET);
				        break;
				  case 4:
				  	    MOTOR6FEN(SET);
				        break; 
				  case 5:
				  	    MOTOR1FEN(SET);
				        break;
				  default:
				  	    break;
				}

                for(k = 0; k < 6; k++)
	            {
	                asm("nop");
	            }
				switch(i)
				{
                  case 0:
				  	    MOTOR5FEN(RESET);
				        break;
	              case 1:
				  	    MOTOR3FEN(RESET);
				        break;
			      case 2:
				  	    MOTOR4FEN(RESET);
				        break;
				  case 3:
				  	    MOTOR2FEN(RESET);
				        break;
				  case 4:
				  	    MOTOR6FEN(RESET);
				        break; 
				  case 5:
				  	    MOTOR1FEN(RESET);
				        break;
				  default:
				  	    break;
				}

            }
            step_delay[i] = 1;
        }
    }
}





