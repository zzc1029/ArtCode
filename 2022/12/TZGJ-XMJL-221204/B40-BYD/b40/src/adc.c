#include "includes.h"
#include "power_out.h"

//#define DEBUG

uint16_t P25, P40;


#define avarge(name, data) avarge##name(data)
#define avargename(name) avarge##name

#define AVARGE_FUNC(name, bufferlen)                    \
    uint16_t avarge##name(uint16_t data);               \
    uint16_t avarge##name(uint16_t data)                \
    {                                                   \
        static uint8_t count = 0;                       \
        static uint8_t first = 0;                       \
        static uint16_t buffer[(1 << bufferlen)] = {0}; \
        static uint32_t sum = 0;                        \
        sum -= buffer[count & ((1 << bufferlen) - 1)];  \
        buffer[count & ((1 << bufferlen) - 1)] = data;  \
        sum += data;                                    \
        count++;                                        \
        if (first < (1 << bufferlen))                   \
        {                                               \
            first++;                                    \
            return sum / first;                         \
        }                                               \
        else                                            \
            return sum >> bufferlen;                    \
    }


AVARGE_FUNC (F, 5);
AVARGE_FUNC (G, 5);
		
		
static uint16_t Filter(uint16_t newdata,uint16_t olddata, uint8_t k)
{
	if(newdata < olddata)
	{
		
	}
}


int protothread_adc (struct pt *pt)
{
    uint32_t ad;
    PT_BEGIN (pt);

    static uint32_t time;
    static uint32_t time1;
    static int i = 0;

    /* We loop forever here. */
    while (1)
    {
        time1 = systick_ms + 50;
        for (i = 0; i < POUT_COUNT; i++)
        {
            PT_DELAY_MS (pt, 1);
            adc_start_convert (PoutS[i].adc_ch);
            PT_DELAY_MS (pt, 1);
            //ad = avages[i](adc_data_get());
						{
							extern void GetCurAndErr(uint16_t index, uint16_t adc);
							GetCurAndErr(i, adc_data_get());	
						}				
            //PoutS[i].cur_100ma = (PoutS[i].cur_100ma >> 3) + ((((adc_data_get() * PoutS[i].magic) >> 23) * 7) >> 3); //a = 0.875					
        }
				
        // ad r1
        PT_DELAY_MS (pt, 1);
        adc_start_convert (22);
        PT_DELAY_MS (pt, 1);

        ad = avarge (F, adc_data_get());
        #if (defined SENSE_SER1_P25_SET) && (SENSE_SER1_P25_SET > 0)
        if (ad > 3511)
        {
            P25 = 6 * SENSE_SER1_P25_SET;
        }
        else
        {
            P25 = ad * SENSE_SER1_P25_SET / (4096 - ad);    // unit is oumu
        }
        #else
        //P25 = (ad * 5000) >> 12; //unit is mV  //4096*5000
        P25 = (ad * 500) >> 12; //unit is 10mV  //4096*5000
        #endif

        // ad r2
        PT_DELAY_MS (pt, 1);
        adc_start_convert (15);
        PT_DELAY_MS (pt, 1);

        ad = avarge (G, adc_data_get());
        #if (defined SENSE_SER2_P40_SET) && (SENSE_SER2_P40_SET > 0)
        if (ad > 3511)
        {
            P40 = 6 * SENSE_SER2_P40_SET;
        }
        else
        {
            P40 = ad * SENSE_SER2_P40_SET / (4096 - ad);    // unit is oumu
        }
        #else
        //P40 = (ad * 5000) >> 12; //unit is mV
        P40 = (ad * 500) >> 12; //unit is 10mV
        #endif
				

        /* And we loop. */
        #ifdef ADC_DEBUG
        SEGGER_RTT_printf (0, "cur unit 0.1A :%d,%d,%d\n", PoutS[0].cur_100ma, PoutS[1].cur_100ma, PoutS[2].cur_100ma);
        #endif

        PT_WAIT_UNTIL (pt, ((int) (systick_ms - time1) >= 0));
        //PT_DELAY_MS(pt,15);
    }

    /* All protothread functions must end with PT_END() which takes a
       pointer to a struct pt. */
    PT_INFINITE_LOOP_END (pt);
}
static struct pt pt1;
static void ain_init()
{
    PT_INIT (&pt1);

		#ifdef B40V60
			//PTC7 传感器上拉电路使能， 
			#define SER_RES_MODE() gpio_bit_set(GPIOC, GPIO_PIN_7)
			#define SER_VOL_MODE() gpio_bit_reset(GPIOC, GPIO_PIN_7)
		
			#if ((SENSE_SER1_P25_SET == TYPE_VOL) && (SENSE_SER2_P40_SET == TYPE_VOL))
				SER_VOL_MODE();
			#else
				SER_RES_MODE();
			#endif
		#endif
	
}
INIT_COMPONENT_EXPORT(ain_init);

void ain_app()
{
    protothread_adc (&pt1);
}
//INIT_APP_LOOP_EXPORT(ain_app);

