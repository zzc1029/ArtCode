#include "includes.h"
#include "power_out.h"
#include "adc.h"
#include "switch.h"
#include "can_protol.h"
#include "pluse.h"
#include "rain.h"
#include "power.h"
#include "eeprom.h"
#include "BF7006AMxx_eflash.h"
#include "init_section.h"


volatile uint32_t systick_ms = 0; //


__weak void din_app(){}
__weak void ain_app(){}
__weak void rain(){}
__weak void power_out(){}
__weak void power_app(){}
__weak void pluse_app(){}
__weak void can_app(){}
__weak void canhl_loop(){}
__weak void logic_app(){}
__weak void logic3_app(){}
	
//#define MAIN_TEST
	
	
int main (void)
{
	#ifdef DEBUG
    SEGGER_RTT_Init();
	#endif
	
    #ifdef MAIN_TEST
    SysTick_Config (0xFFFFFF);
    SysTick->VAL = 0XFFFFFF;
    #endif
	
		auto_init();
	
    /* Place your initialization code below */

    #ifdef MAIN_TEST
    SysTick->VAL = 0XFFFFFF;
    #endif
	
    while (1)
    {
        /* Place your code here */
				din_app();
				ain_app();
				rain();
				power_out();
				power_app();
				pluse_app();
				can_app();
				canhl_loop();
				logic_app();
				logic3_app();
			
			#ifdef DEBUG
				auto_loop();			  
			#endif
	
        #ifdef MAIN_TEST
        {
            //测试大约18KHz的运行周期，最大-最小18.8K-13K，0.1ms肯定运行一次，所以PWM采用的10K比较合适
						//测试效率：普通模式，平均运行一次时间2027，打开ONS选项 2065 ； PT模式，平均运行一次时间2106，打开ONS选项后2150
						//优化之后约2076
						//增加80个指令周期
						//约15.2K,最小周期8.47KHz
						//17.5K-5K
            static uint32_t test = 0;
            static uint32_t min = 0xFFFFFFFF;
            static uint32_t sum = 0;
            static uint32_t max = 0;
            uint32_t time;

            test++;

            time = 0XFFFFFF - SysTick->VAL;

            min = min > time ? time : min;
            max = max > time ? max : time;

            sum += time;

            if ((test & 0x7FF) == 1)
            {
                SEGGER_RTT_printf (0, "sum .1/32M %d,%d,%d\n", sum / test, min, max);
                min = 0xFFFFFFFF;
                max = 0;
                if (sum > 0xF0000000)
                {
                    sum = 0;
                    test = 0;
                }
            }

            SysTick->VAL = 0XFFFFFF;
        }
        #endif
    }

}


//--------------------------END OF FILE-----------------------------------
