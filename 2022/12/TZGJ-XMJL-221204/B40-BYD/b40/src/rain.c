#include "rain.h"
#include "switch.h"

#if SUPPORT_WIPER == 1

#define RAIN_FAST_POUT PoutS[0]
#define RAIN_SLOW_POUT PoutS[1]
#define RAIN_Spray_POUT PoutS[2]

#define LOW_ON()    gpio_bit_set(GPIOG, GPIO_PIN_3)
#define LOW_OFF()   gpio_bit_reset(GPIOG, GPIO_PIN_3)


typedef enum
{
    None,
    Inter,
    Fast,
    Slow,
} RainCmd;


typedef enum
{
    RainNone,
    RainOp,
    RainWaitReset,
    RainLowEnable,
    RainInterDelay,
		RainOpEnd,
} RainState;


static RainState status;

typedef enum
{
    Disable,
    Enable
} RainSprayCmd;

static RainCmd rain_cmd;
static RainSprayCmd rain_spray_cmd;
static uint8_t rain_spray_time = 0;
static uint32_t start_time_stamp = 0;

static uint8_t wiper_brake_enable = 1;
static uint8_t wiper_brake_delay_ms = 20;

static uint8_t wiper_brake_pwm_enable = 0;


//雨刮逻辑：
//增加
//喷水端口仪表控制使能位：0x06A4 报文 Byte6 bit6 高有效  //高的话 喷水端口受仪表6A4控制，模块不写死端口，专门用于雨刮喷水不受控的订单
//稳刹PWM使能位：0x06A4 报文 Byte7 bit1 高有效
//稳刹使能位，0x06A4 报文 Byte7 bit0 高有效
//稳刹启动延迟时间：0x06A4 报文 Byte7 bit4-7 单位20ms，低于20ms自动调整到20ms


//间歇档，慢档以20RPM的频率刮
//喷水后慢档刮三次
inline void rain_cmd_parse(uint16_t cmd)
{
    uint8_t fast;
    uint8_t slow;
    uint8_t inter; //间歇

    if(cmd & 0x30)
    {
        fast = (cmd & 1) == 0x01;
        slow = (cmd & 2) == 0x02;
        inter = (cmd & 8) == 0x08; //间歇
        rain_spray_cmd = (RainSprayCmd)((cmd & 4) == 0x04);  //喷水
    }
    else
    {
        fast = 0;
        slow = 0;
        inter = 0; //间歇
        rain_spray_cmd = Disable; //喷水
    }

    if((cmd & 0x40) == 0)
    {
        RAIN_Spray_POUT.cmd = (rain_spray_cmd == Enable);
    }

    if(fast)
    {
        rain_cmd = Fast;
    }
    else if(slow)
    {
        rain_cmd = Slow;
    }
    else if(inter)
    {
        rain_cmd = Inter;
    }
    else
    {
        rain_cmd = None;
    }
		wiper_brake_pwm_enable = (cmd & 0x200) > 0;
		wiper_brake_enable = (cmd & 0x100) > 0;
		wiper_brake_delay_ms = (cmd >> 12) * 20;
		wiper_brake_delay_ms = wiper_brake_delay_ms > 20 ? wiper_brake_delay_ms : 20;
}

#define Mos_on LOW_ON
#define Mos_off LOW_OFF

inline  bool IsResetPostion()
{
    return (bool) WIPER_AT_RESET();
}


int protothread_rain(struct pt *pt)
{
    static uint32_t time = 0;
    static uint32_t slow_start_time = 0;
    PT_BEGIN(pt);

    while(1)
    {
        switch(status)
        {
            case RainNone://null
                PT_WAIT_UNTIL(pt, (rain_cmd != None) || (rain_spray_cmd != Disable));
                status = RainOp;
                break;

            case RainOp://op
							
                if(rain_spray_cmd == Enable)
                {
                    rain_spray_time = 3;
                }
                if(rain_cmd == Fast)
                {
                    RAIN_FAST_POUT.cmd = 1;
                    RAIN_SLOW_POUT.cmd = 0;
                }
                else
                {
                    RAIN_FAST_POUT.cmd = 0;
                    RAIN_SLOW_POUT.cmd = 1;
                    slow_start_time = systick_ms;
                }
                start_time_stamp = systick_ms;

                PT_WAIT_UNTIL(pt, (!IsResetPostion()));
																
                PT_DELAY_MS(pt, 10);
                PT_WAIT_UNTIL(pt, (!IsResetPostion()));

                status = RainWaitReset;

                break;

            case RainWaitReset://wait reset
                {
                    static RainSprayCmd last;
                    static RainCmd lastc;
                    PT_WAIT_UNTIL(pt, (rain_spray_cmd != last) || (rain_cmd != lastc) || (IsResetPostion()));

                    if((rain_spray_cmd == last) && (rain_cmd == lastc))
                    {
                        if(rain_spray_time > 0)
                        {
                            rain_spray_time --;
                        }
                        else if(rain_cmd <= Inter)
                        {
                            if((systick_ms - slow_start_time) > 300)
                            {
																//PT_DELAY_MS(pt, 10);//增加10ms延时等待雨刮运行到复位点中间
															  status = wiper_brake_enable ? RainLowEnable : RainOpEnd;
                                break;
                            }														
                        }
                    }

                    last = rain_spray_cmd;
                    lastc = rain_cmd;

                    status = RainOp;

                }
                break;
								
						case RainOpEnd:						
								RAIN_FAST_POUT.cmd = 0;
								RAIN_SLOW_POUT.cmd = 0;

								PT_DELAY_MS(pt, 10);
						
								if(rain_cmd == None)
								{
										status = RainNone;
								}
								else if(rain_cmd == Inter)
								{
										status = RainInterDelay;
								}
								else
								{
										status = RainOp;
								}
								break;

            case RainLowEnable://wen sha?
                {									
                    RAIN_FAST_POUT.cmd = 0;
                    RAIN_SLOW_POUT.cmd = 0;

                    PT_DELAY_MS(pt, wiper_brake_delay_ms);//等待 关闭完成，关闭命令之后会延迟1ms左右才能彻底关闭 延时20ms						

										if(wiper_brake_pwm_enable)
                    {
                        extern uint32_t pwmtime;
                        static uint8_t i;
                        time = pwmtime;
                        for(i = 0; i < 50; i +=5 )
                        {
														//50*10*0.1ms = 50ms
                            time += i;
                            Mos_on();  

                            PT_WAIT_UNTIL(pt, ((int)(pwmtime - time) >= 0));

                            time += 50 - i;
                            Mos_off();

                            PT_WAIT_UNTIL(pt, ((int)(pwmtime - time) >= 0));
                        }
                    }
                }

                Mos_on();
                time = systick_ms + 500;
                PT_WAIT_UNTIL(pt, ((int)(systick_ms - time) >= 0) || (rain_cmd > Inter) || (rain_spray_cmd != Disable));
                Mos_off();

                PT_DELAY_MS(pt, 10);

                if(rain_cmd == None)
                {
                    status = RainNone;
                }
                else if(rain_cmd == Inter)
                {
                    status = RainInterDelay;
                }
                else
                {
                    status = RainOp;
                }
                break;

            case RainInterDelay://inter delay
                time = (start_time_stamp == 0) ? systick_ms : start_time_stamp + 5000;
                PT_WAIT_UNTIL(pt, ((int)(systick_ms - time) >= 0) || (rain_cmd != Inter) || (rain_spray_cmd != Disable));
                if(rain_cmd != None)
                {
                    status = RainOp;
                }
                else
                {
                    status = RainNone;
                }
                break;
        }
        PT_YIELD(pt);
    }

    PT_INFINITE_LOOP_END(pt);
}

#ifdef RAIN_TEST
static struct pt pt_test;

uint8_t rain_test_delay = 0; //0-500
int protothread_rain_test(struct pt *pt)
{
    static uint32_t time;
    int i;
    PT_BEGIN(pt);
    while(1)
    {
        rain_cmd  = Fast;
        for(i = 0; i < POUT_COUNT; i++)
        {
            PoutS[i].cmd = 1;
        }

        PT_DELAY_MS(pt, 800 + (((uint16_t)rain_test_delay)));  //fast is 1.2s, and rest is 0.1s, run is 1.1s, slow is 2.1s
        //950+65*2 = 1080, 1200-150=1050, 1200-300 = 900;
        rain_cmd  = None;

        PT_DELAY_MS(pt, 2000);
        for(i = 0; i < POUT_COUNT; i++)
        {
            PoutS[i].cmd = 0;
        }

        PT_DELAY_MS(pt, 2000);
    }
    PT_END(pt);
}
#endif

static struct pt pt_rain;

static void rain_init()
{
    LOW_OFF();
    PT_INIT(&pt_rain);
#ifdef RAIN_TEST
    PT_INIT(&pt_test);
#endif
}
INIT_PREV_EXPORT(rain_init);

#ifndef WIPER_DISABLE
extern uint8_t WIPER_DISABLE;
#endif

void rain()
{
		if ((WIPER_DISABLE == 0) && (MOD_ADDR == ADDR1_MOD))
    {
        protothread_rain(&pt_rain);
#ifdef RAIN_TEST
        protothread_rain_test(&pt_test);
#endif
    }
}

//INIT_APP_LOOP_EXPORT(rain);

#endif //SUPPORT_WIPER
