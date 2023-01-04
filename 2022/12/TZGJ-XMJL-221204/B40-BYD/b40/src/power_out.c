#include "power_out.h"
#include "switch.h"
#include "string.h"

//((adc_data_get() * PoutS[i].magic) >> 23) 
//BTS6163D:9000 
//BTS6143D : 10000
//BTS50085 :13000
//BTT6010 : 3900
//VND5T016 : 4200
//4096

//BTS6163D I = (50*ADC*K)/4096/R = ADC * 50*9000/4096/1000 = 1053257
//BTS6143D I = (50*ADC*K)/4096/R = ADC * 50*10000/4096/1000 = 1053257
//BTS50085 I = (50*ADC*K)/4096/R = ADC * 50*13000/4096/1500 = 1053257
//BTT6010 I = (50*ADC*K)/4096/R = ADC * 50*3900/4096/510 = 1053257
//VND5T016 I = (50*ADC*K)/4096/R = ADC * 50*4200/4096/510 = 1053257

//V2.41 VND5T016 + 510 omu * 12 | BTT6010 +510 omu * 3 (POUT1 POUT2 Pout3)
//V6.0 BTS6163D + 1K omu * 13 | BTS50085 +1.5K omu *2 (POUT1 POUT2)

#define MAGIC_BTS6163D_1K0R      460800
#define MAGIC_BTS6143D_1K0R      512000
#define MAGIC_BTS50085_1K5R      665600//此值是1K反馈电阻的MAGIC值，宏定义名称没改
#define MAGIC_BTT6010_510R       391529
#define MAGIC_VND5T016_510R      421647


#define FALUT_THRESHOLD_BTS6163D_1K0R      350 //4mA 9000
#define FALUT_THRESHOLD_BTS6143D_1K0R      380 //4*10000
#define FALUT_THRESHOLD_BTS50085_1K5R      420 //6.5*13000
#define FALUT_THRESHOLD_BTT6010_510R       220 //6mA*3900
#define FALUT_THRESHOLD_VND5T016_510R      400 //


#ifdef B40V60_BTS6143D

#define POUT01_MAGIC   MAGIC_BTS50085_1K5R
#define POUT02_MAGIC   MAGIC_BTS50085_1K5R
#define POUT03_MAGIC   MAGIC_BTS6143D_1K0R
#define POUT04_MAGIC   MAGIC_BTS6143D_1K0R
#define POUT05_MAGIC   MAGIC_BTS6143D_1K0R
#define POUT06_MAGIC   MAGIC_BTS6143D_1K0R
#define POUT07_MAGIC   MAGIC_BTS6143D_1K0R
#define POUT08_MAGIC   MAGIC_BTS6143D_1K0R
#define POUT09_MAGIC   MAGIC_BTS6143D_1K0R
#define POUT10_MAGIC   MAGIC_BTS6143D_1K0R
#define POUT11_MAGIC   MAGIC_BTS6143D_1K0R
#define POUT12_MAGIC   MAGIC_BTS6143D_1K0R
#define POUT13_MAGIC   MAGIC_BTS6143D_1K0R
#define POUT14_MAGIC   MAGIC_BTS6143D_1K0R
#define POUT15_MAGIC   MAGIC_BTS6143D_1K0R

#elif defined B40V60

#define POUT01_MAGIC   MAGIC_BTS50085_1K5R
#define POUT02_MAGIC   MAGIC_BTS50085_1K5R
#define POUT03_MAGIC   MAGIC_BTS6163D_1K0R
#define POUT04_MAGIC   MAGIC_BTS6163D_1K0R
#define POUT05_MAGIC   MAGIC_BTS6163D_1K0R
#define POUT06_MAGIC   MAGIC_BTS6163D_1K0R
#define POUT07_MAGIC   MAGIC_BTS6163D_1K0R
#define POUT08_MAGIC   MAGIC_BTS6163D_1K0R
#define POUT09_MAGIC   MAGIC_BTS6163D_1K0R
#define POUT10_MAGIC   MAGIC_BTS6163D_1K0R
#define POUT11_MAGIC   MAGIC_BTS6163D_1K0R
#define POUT12_MAGIC   MAGIC_BTS6163D_1K0R
#define POUT13_MAGIC   MAGIC_BTS6163D_1K0R
#define POUT14_MAGIC   MAGIC_BTS6163D_1K0R
#define POUT15_MAGIC   MAGIC_BTS6163D_1K0R

#else

#define POUT01_MAGIC   MAGIC_BTT6010_510R
#define POUT02_MAGIC   MAGIC_BTT6010_510R
#define POUT03_MAGIC   MAGIC_BTT6010_510R
#define POUT04_MAGIC   MAGIC_VND5T016_510R
#define POUT05_MAGIC   MAGIC_VND5T016_510R
#define POUT06_MAGIC   MAGIC_VND5T016_510R
#define POUT07_MAGIC   MAGIC_VND5T016_510R
#define POUT08_MAGIC   MAGIC_VND5T016_510R
#define POUT09_MAGIC   MAGIC_VND5T016_510R
#define POUT10_MAGIC   MAGIC_VND5T016_510R
#define POUT11_MAGIC   MAGIC_VND5T016_510R
#define POUT12_MAGIC   MAGIC_VND5T016_510R
#define POUT13_MAGIC   MAGIC_VND5T016_510R
#define POUT14_MAGIC   MAGIC_VND5T016_510R
#define POUT15_MAGIC   MAGIC_VND5T016_510R

#endif


PoutControl PoutS[POUT_COUNT] =
{
/* 0*/{.name = "A01",.gpio_periph = GPIOG, .pin = GPIO_PIN_4, .adc_ch = 01, .sc_threshold=FALUT_THRESHOLD_BTS50085_1K5R, .oct_threshold = OC_TIME_THRESHOLD_MS,.sct_threshold = SC_TIME_THRESHOLD_MS, .magic = POUT01_MAGIC, .oc_threshold = OC_THRESHOLD2,.pwmable = 0, .pwmstart = 3, .pwmend = 50}, 
/* 1*/{.name = "A09",.gpio_periph = GPIOD, .pin = GPIO_PIN_7, .adc_ch = 20, .sc_threshold=FALUT_THRESHOLD_BTS50085_1K5R, .oct_threshold = OC_TIME_THRESHOLD_MS,.sct_threshold = SC_TIME_THRESHOLD_MS, .magic = POUT02_MAGIC, .oc_threshold = OC_THRESHOLD2,.pwmable = 0, .pwmstart = 3, .pwmend = 50},
/* 2*/{.name = "A02",.gpio_periph = GPIOG, .pin = GPIO_PIN_5, .adc_ch = 10, .sc_threshold=FALUT_THRESHOLD_BTS6143D_1K0R, .oct_threshold = OC_TIME_THRESHOLD_MS,.sct_threshold = SC_TIME_THRESHOLD_MS, .magic = POUT03_MAGIC, .oc_threshold = OC_THRESHOLD, .pwmable = 0, .pwmstart = 3, .pwmend = 50},
/* 3*/{.name = "A10",.gpio_periph = GPIOC, .pin = GPIO_PIN_0, .adc_ch = 05, .sc_threshold=FALUT_THRESHOLD_BTS6143D_1K0R, .oct_threshold = OC_TIME_THRESHOLD_MS,.sct_threshold = SC_TIME_THRESHOLD_MS, .magic = POUT04_MAGIC, .oc_threshold = OC_THRESHOLD, .pwmable = 0, .pwmstart = 3, .pwmend = 50},
/* 4*/{.name = "A03",.gpio_periph = GPIOD, .pin = GPIO_PIN_2, .adc_ch = 02, .sc_threshold=FALUT_THRESHOLD_BTS6143D_1K0R, .oct_threshold = OC_TIME_THRESHOLD_MS,.sct_threshold = SC_TIME_THRESHOLD_MS, .magic = POUT05_MAGIC, .oc_threshold = OC_THRESHOLD, .pwmable = 0, .pwmstart = 3, .pwmend = 50},
/* 5*/{.name = "A11",.gpio_periph = GPIOB, .pin = GPIO_PIN_0, .adc_ch = 13, .sc_threshold=FALUT_THRESHOLD_BTS6143D_1K0R, .oct_threshold = OC_TIME_THRESHOLD_MS,.sct_threshold = SC_TIME_THRESHOLD_MS, .magic = POUT06_MAGIC, .oc_threshold = OC_THRESHOLD, .pwmable = 0, .pwmstart = 3, .pwmend = 50},
/* 6*/{.name = "A04",.gpio_periph = GPIOD, .pin = GPIO_PIN_3, .adc_ch = 19, .sc_threshold=FALUT_THRESHOLD_BTS6143D_1K0R, .oct_threshold = OC_TIME_THRESHOLD_MS,.sct_threshold = SC_TIME_THRESHOLD_MS, .magic = POUT07_MAGIC, .oc_threshold = OC_THRESHOLD, .pwmable = 0, .pwmstart = 3, .pwmend = 50},
/* 7*/{.name = "A12",.gpio_periph = GPIOC, .pin = GPIO_PIN_1, .adc_ch = 06, .sc_threshold=FALUT_THRESHOLD_BTS6143D_1K0R, .oct_threshold = OC_TIME_THRESHOLD_MS,.sct_threshold = SC_TIME_THRESHOLD_MS, .magic = POUT08_MAGIC, .oc_threshold = OC_THRESHOLD, .pwmable = 0, .pwmstart = 3, .pwmend = 50},
/* 8*/{.name = "A05",.gpio_periph = GPIOD, .pin = GPIO_PIN_4, .adc_ch = 11, .sc_threshold=FALUT_THRESHOLD_BTS6143D_1K0R, .oct_threshold = OC_TIME_THRESHOLD_MS,.sct_threshold = SC_TIME_THRESHOLD_MS, .magic = POUT09_MAGIC, .oc_threshold = OC_THRESHOLD, .pwmable = 0, .pwmstart = 3, .pwmend = 50},
/* 9*/{.name = "A13",.gpio_periph = GPIOA, .pin = GPIO_PIN_0, .adc_ch = 14, .sc_threshold=FALUT_THRESHOLD_BTS6143D_1K0R, .oct_threshold = OC_TIME_THRESHOLD_MS,.sct_threshold = SC_TIME_THRESHOLD_MS, .magic = POUT10_MAGIC, .oc_threshold = OC_THRESHOLD, .pwmable = 0, .pwmstart = 3, .pwmend = 50},
/*10*/{.name = "A06",.gpio_periph = GPIOD, .pin = GPIO_PIN_5, .adc_ch = 03, .sc_threshold=FALUT_THRESHOLD_BTS6143D_1K0R, .oct_threshold = OC_TIME_THRESHOLD_MS,.sct_threshold = SC_TIME_THRESHOLD_MS, .magic = POUT11_MAGIC, .oc_threshold = OC_THRESHOLD, .pwmable = 0, .pwmstart = 3, .pwmend = 50},
/*11*/{.name = "A14",.gpio_periph = GPIOC, .pin = GPIO_PIN_2, .adc_ch = 21, .sc_threshold=FALUT_THRESHOLD_BTS6143D_1K0R, .oct_threshold = OC_TIME_THRESHOLD_MS,.sct_threshold = SC_TIME_THRESHOLD_MS, .magic = POUT12_MAGIC, .oc_threshold = OC_THRESHOLD, .pwmable = 0, .pwmstart = 3, .pwmend = 50},
/*12*/{.name = "A07",.gpio_periph = GPIOF, .pin = GPIO_PIN_7, .adc_ch = 04, .sc_threshold=FALUT_THRESHOLD_BTS6143D_1K0R, .oct_threshold = OC_TIME_THRESHOLD_MS,.sct_threshold = SC_TIME_THRESHOLD_MS, .magic = POUT13_MAGIC, .oc_threshold = OC_THRESHOLD, .pwmable = 0, .pwmstart = 3, .pwmend = 50},
/*13*/{.name = "A42",.gpio_periph = GPIOB, .pin = GPIO_PIN_1, .adc_ch = 07, .sc_threshold=FALUT_THRESHOLD_BTS6143D_1K0R, .oct_threshold = OC_TIME_THRESHOLD_MS,.sct_threshold = SC_TIME_THRESHOLD_MS, .magic = POUT14_MAGIC, .oc_threshold = OC_THRESHOLD, .pwmable = 0, .pwmstart = 3, .pwmend = 50},
/*14*/{.name = "A08",.gpio_periph = GPIOD, .pin = GPIO_PIN_6, .adc_ch = 12, .sc_threshold=FALUT_THRESHOLD_BTS6143D_1K0R, .oct_threshold = OC_TIME_THRESHOLD_MS,.sct_threshold = SC_TIME_THRESHOLD_MS, .magic = POUT15_MAGIC, .oc_threshold = OC_THRESHOLD, .pwmable = 0, .pwmstart = 3, .pwmend = 50}
};

#define FR_ON() gpio_bit_set(GPIOE, GPIO_PIN_0)
#define FR_OFF() gpio_bit_reset(GPIOE, GPIO_PIN_0)

#define MAX_RETRY   3

volatile uint32_t pwmtime = 0;

static inline uint8_t GetDiag(PoutControl *p)
{
		if(p->rt_diag > 0)
			p->diag = 2;
		else
			p->diag = 0;
    return p->diag;
}

static inline uint8_t GetShortDiag(PoutControl *p)
{
		if(p->rt_diag >= 2)
			return 1;
		else
			return 0;			
}

static inline void ClearDiag(PoutControl *p)
{
    p->diag = 0;
}

void GetCurAndErr(uint16_t index, uint16_t adc)
{
		PoutControl *p = PoutS + index;
	
    p->cur_100ma = (p->cur_100ma >> 3) + ((((adc * p->magic) >> 22) * 7) >> 3); //a = 0.875	/*一阶低通滤波算法，具体叙述见DOC文档*/
	
		if(p->cur_100ma > p->sc_threshold)
		{
				if((int)(systick_ms - p->sc_time) >= 0)
					p->rt_diag = 2;  //short 
		}
    else if(p->cur_100ma > p->oc_threshold)
    {
				if(p->rt_diag == 2)
					p->rt_diag = 0;
				
				if((int)(systick_ms - p->oc_time) >= 0)
					p->rt_diag = 1;  //over load
								
				p->sc_time = systick_ms + p->sct_threshold;
    }
    else
    {
				p->oc_time = systick_ms + p->oct_threshold;
				p->sc_time = systick_ms + p->sct_threshold;
        p->rt_diag = 0;  //ok
    }
}

//output control
static int protothread_out(struct pt *pt, PoutControl *p)
{
    PT_BEGIN(pt);
	
    while(1)
    {
        switch(p->status)
        {
            case PS_Off: //off
								ClearDiag(p);
                GPIO_PTD(p->gpio_periph) &= ~(p->pin);  //after closed have 1ms err pluse
                PT_WAIT_UNTIL(pt, (p->cmd > 0)); //|| GetCurAndErr(p));
                p->status = PS_Start;
                break;

            case PS_Start: //start
								ClearDiag(p);
                if(p->pwmable)
                {
                    p->time = pwmtime;
                    for(p->pwmi = p->pwmstart; p->pwmi < p->pwmend; p->pwmi ++)
                    {
                        p->time += p->pwmi;
                        GPIO_PTD(p->gpio_periph) |= p->pin;

                        PT_WAIT_UNTIL(pt, ((int)(pwmtime - p->time) >= 0));
											
												// 100*0.1ms = 10ms check current
												// if(GetShortDiag(p))
												// {
												// 		p->status = PS_Err;
												//     goto SwitchEnd;
												// }
												
                        p->time += p->pwmend - p->pwmi;
                        GPIO_PTD(p->gpio_periph) &= ~(p->pin);

                        PT_WAIT_UNTIL(pt, ((int)(pwmtime - p->time) >= 0));

                        if(p->cmd == 0)
                        {
														p->status = PS_Off;
                            goto SwitchEnd;
                        }
                    }
										p->status = PS_On;
                }
								else
								{										
										p->status = PS_On;										
								}
                break;
							
            case PS_On: //on	
																
								GPIO_PTD(p->gpio_periph) |= p->pin;
								PT_WAIT_UNTIL(pt, (p->cmd == 0) || (GetDiag(p)));
								//-----------------------个别订单因启动电流大，使用启动1S内不判断过载和短路-------------
							//	p->time = systick_ms + 1000;
								//PT_WAIT_UNTIL(pt, (p->cmd == 0) || ((GetDiag(p)) && ((int)(systick_ms - p->time) > 0)));
								//--------------------------------------------------------------------------------------
								p->status = (p->cmd == 0) ? PS_Off : PS_Err;
								
                break;

            case PS_Err: //err
                GPIO_PTD(p->gpio_periph) &= ~(p->pin);
                if(p->errcount >= MAX_RETRY)
                {									
                    p->status = PS_Idle;
                }
                else
                {
                    p->errcount++;

                    p->time = systick_ms + 9999;
                    PT_WAIT_UNTIL(pt, ((int)(systick_ms - p->time) >= 0) || (p->cmd == 0));

                    FR_OFF();
                    p->time = systick_ms + 2;
                    PT_WAIT_UNTIL(pt, ((int)(systick_ms - p->time) >= 0));
                    FR_ON();

                    p->status = (p->cmd == 0) ? PS_Off : PS_Start;
                }
                break;
						case PS_Idle: //when failed 3 time, then go in idle state
								PT_WAIT_UNTIL(pt, p->errcount < MAX_RETRY);
							
								FR_OFF();
								p->time = systick_ms + 2;
								PT_WAIT_UNTIL(pt, ((int)(systick_ms - p->time) >= 0));
								FR_ON();

								p->status = PS_Off;
							break;
            default:
                p->status = PS_Off;
                break;

        }
SwitchEnd:
        PT_YIELD(pt);
        /* And we loop. */
    }
    PT_INFINITE_LOOP_END(pt);
}

static struct pt pts[POUT_COUNT];

static void power_out_init()
{
    int i;
    FR_ON();
    for(i = 0; i < POUT_COUNT; i++)
    {
        PT_INIT(pts + i);
			
				switch(MOD_ADDR)
				{
					case ADDR1_MOD:						
							#ifdef  NORMOL_OUTS_MOD1	
								if(strstr(NORMOL_OUTS_MOD1, PoutS[i].name))
								{
										PoutS[i].cmd = 1;
								}
							#endif
											
							#ifdef WIPER_OUTS
								if(strstr(WIPER_OUTS, PoutS[i].name))
								{
										PoutS[i].pwmstart = 40;  //20*60*0.1 = 120ms 
										PoutS[i].pwmend = 60;
										PoutS[i].oc_threshold = PoutS[i].sc_threshold;
								}
							#endif					
							break;
					case ADDR2_MOD:						
							#ifdef  NORMOL_OUTS_MOD2	
								if(strstr(NORMOL_OUTS_MOD2, PoutS[i].name))
								{
										PoutS[i].cmd = 1;
								}
							#endif
							#if ORDER_VERSION == 220102
								if(strstr("A01", PoutS[i].name))
								{
										PoutS[i].pwmstart = 0;
										PoutS[i].pwmend = 141;
										PoutS[i].oc_threshold = PoutS[i].sc_threshold = 1000;
								}
							#endif	
							break;
					case ADDR3_MOD:				
							#ifdef  NORMOL_OUTS_MOD3			
								if(strstr(NORMOL_OUTS_MOD3, PoutS[i].name))
								{
										PoutS[i].cmd = 1;
								}
							#endif
							
							#if ORDER_VERSION == 211101
								if(strstr("A01", PoutS[i].name))
								{
										PoutS[i].pwmstart = 15;
										PoutS[i].pwmend = 58;
										PoutS[i].pwmable = 1;
										PoutS[i].pwmfixed = 1;
								}							
							#endif
					
							#if ORDER_VERSION == 220102
								if(strstr("A01", PoutS[i].name))
								{
										PoutS[i].pwmstart = 0;
										PoutS[i].pwmend = 141;
										PoutS[i].oc_threshold = PoutS[i].sc_threshold = 2000;
								}
							#endif	
							break;
					case ADDR4_MOD:				
							#ifdef  NORMOL_OUTS_MOD4			
								if(strstr(NORMOL_OUTS_MOD4, PoutS[i].name))
								{
										PoutS[i].cmd = 1;
								}
							#endif
							#if ORDER_VERSION == 220102
								if(strstr("A02", PoutS[i].name))
								{
										PoutS[i].pwmstart = 0;
										PoutS[i].pwmend = 141;
										PoutS[i].oc_threshold = PoutS[i].sc_threshold = 1000;
								}
							#endif								
							break;
					default:
						break;
				}			
    }		
}
INIT_APP_EXPORT(power_out_init);

#pragma O3
#pragma Otime
void power_out()
{
#if (POUT_COUNT>9)
    protothread_out(pts + 0, PoutS + 0);
    protothread_out(pts + 1, PoutS + 1);
    protothread_out(pts + 2, PoutS + 2);
    protothread_out(pts + 3, PoutS + 3);
    protothread_out(pts + 4, PoutS + 4);
    protothread_out(pts + 5, PoutS + 5);
    protothread_out(pts + 6, PoutS + 6);
    protothread_out(pts + 7, PoutS + 7);
    protothread_out(pts + 8, PoutS + 8);
    protothread_out(pts + 9, PoutS + 9);
    protothread_out(pts + 10, PoutS + 10);
    protothread_out(pts + 11, PoutS + 11);
    protothread_out(pts + 12, PoutS + 12);
    protothread_out(pts + 13, PoutS + 13);
    protothread_out(pts + 14, PoutS + 14);
#endif
#if (POUT_COUNT>15)
    protothread_out(pts + 15, PoutS + 15);
#endif
#if (POUT_COUNT>16)
    protothread_out(pts + 16, PoutS + 16);
#endif
#if (POUT_COUNT>17)
    protothread_out(pts + 17, PoutS + 17);
#endif
#if (POUT_COUNT>18)
    protothread_out(pts + 18, PoutS + 18);
#endif
#if (POUT_COUNT>19)
    protothread_out(pts + 19, PoutS + 19);
#endif
#if (POUT_COUNT>20)
    protothread_out(pts + 20, PoutS + 20);
#endif
}
//INIT_APP_LOOP_EXPORT(power_out);

#ifdef TEMP_TEST
static struct pt pttest = {0};

static int protothread_out_temp_test(struct pt *pt)
{
    static uint32_t time = 0;
    static uint8_t out = 0;
    uint8_t i;
    PT_BEGIN(pt);

    while(1)
    {
        PT_DELAY_MS(pt, 2000);

        for(i = 0; i < POUT_COUNT; i++)
        {
            if(i & 1)
            {
                PoutS[i].cmd = out > 0;
            }
            else
            {
                PoutS[i].cmd = out == 0;
            }
        }

        out = !out;

    }
    PT_INFINITE_LOOP_END(pt);
}

static void power_out_temp_test()
{
    protothread_out_temp_test(&pttest);
}

INIT_APP_LOOP_EXPORT(power_out_temp_test);
#endif

