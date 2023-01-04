#include "includes.h"
//#include "power.h"
#include "eeprom.h"

extern uint32_t EepromFlag;

#ifdef B40V60

	//PTF3 唤醒输入，控低输入，高有效
	//PTD1 电源维持，高有效
	#define POWER_ON()  gpio_bit_set(GPIOD, GPIO_PIN_1)
	#define POWER_OFF() gpio_bit_reset(GPIOD, GPIO_PIN_1)

	#define WAKE_UP_IS_OFF()  ((GPIO_PTD(GPIOF)&(GPIO_PIN_3)) == 0x00U) //gpio_bit_get(GPIOF, GPIO_PIN_3)

#else
	
	#define POWER_ON()  
	#define POWER_OFF() 
	#define WAKE_UP_IS_OFF()  0

#endif

int protothread_power (struct pt *pt)
{
    PT_BEGIN (pt);
		static struct pt ptx;

    static uint32_t time;

    /* We loop forever here. */
    while (1)
    {
        PT_DELAY_MS (pt, 1000);
				if(WAKE_UP_IS_OFF())
				{
					PT_DELAY_MS (pt, 1000); // wait 1000ms 
					
					//save odo and trip;
					PT_WAIT_UNTIL (pt, (EepromFlag == 0));
					EepromFlag = 1;
					PT_SPAWN (pt, &ptx, save_odo_pt (&ptx));
					EepromFlag = 0;
					
					POWER_OFF();  					// and power off
				}
				else
				{
					POWER_ON();				
				}
    }

    /* All protothread functions must end with PT_END() which takes a
       pointer to a struct pt. */
    PT_INFINITE_LOOP_END (pt);
}
static struct pt pt1;
static void power_init()
{
		POWER_ON();
    PT_INIT (&pt1);
}
INIT_BOARD_EXPORT(power_init);

void power_app()
{
    protothread_power (&pt1);
}

//INIT_APP_LOOP_EXPORT(power_app);

