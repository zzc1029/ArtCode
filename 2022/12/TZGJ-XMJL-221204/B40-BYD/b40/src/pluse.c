#include "includes.h"
#include "eeprom.h"

uint16_t pluse_count = 0;
uint16_t pluse_100ms = 0;
uint8_t pluse_flag = 0;

uint32_t odo_100m;
uint32_t last_odo_100m;

uint16_t trip_100m;
uint16_t freq;

static uint16_t CaclFreq (uint16_t pluse_count_100ms)
{
    static uint16_t buffer[10] = {0};
    static uint8_t i = 0;
    static uint8_t j = 0;
    static uint16_t sum = 0;

    i = i >= 9 ? 0 : ++i;
    j = j < 10 ? ++j : j;

    sum -= buffer[i];
    buffer[i] = pluse_count_100ms;
    sum += buffer[i];

    return sum * 10 / j;
}


static int protothread_pluse (struct pt *pt)
{
    PT_BEGIN (pt);

    static uint16_t pluse_temp = 0;
    static struct pt ptx;


    /* We loop forever here. */
    while (1)
    {
        PT_WAIT_UNTIL (pt, (pluse_flag > 0));
        pluse_flag = 0;

        {
            uint16_t temp;
            NVIC_DisableIRQ (RTC_IRQn);
            temp = pluse_100ms;
            pluse_100ms = 0;
            NVIC_EnableIRQ (RTC_IRQn);
            pluse_temp += temp;
            freq = CaclFreq (temp);
        }

        {
            uint8_t temp_100m = pluse_temp / param.pluse;
            pluse_temp %= param.pluse;

            trip_100m += temp_100m;
            odo_100m += temp_100m;

            if (last_odo_100m < odo_100m)
            {
                PT_WAIT_UNTIL (pt, (EepromFlag == 0));
                EepromFlag = 1;
                PT_SPAWN (pt, &ptx, save_odo_pt (&ptx));
                EepromFlag = 0;

                last_odo_100m = odo_100m + 10;
            }
            #ifdef PLUSE_DEBUG
            SEGGER_RTT_TerminalPrintf (0, "trip_100m:%d, Freq:%d \n", trip_100m, freq);
            #endif
        }

        /* And we loop. */
    }
    PT_INFINITE_LOOP_END (pt);
}


#ifdef PLUSE_TEST
static struct pt pt_test;

int protothread_pluse_test (struct pt *pt)
{
    static uint32_t time;
    static struct pt ptx;
    PT_BEGIN (pt);
    while (1)
    {
        PT_DELAY_MS (pt, 100);

        odo_100m++;
        trip_100m++;

        PT_WAIT_UNTIL (pt, (EepromFlag == 0));
        EepromFlag = 1;
        PT_SPAWN (pt, &ptx, save_odo_pt (&ptx));
        EepromFlag = 0;

    }
    PT_END (pt);
}
#endif

static struct pt pt1;
static void pluse_init()
{
    PT_INIT (&pt1);
    #ifdef PLUSE_TEST
    PT_INIT (&pt_test);
    #endif
}
INIT_COMPONENT_EXPORT(pluse_init);

void pluse_app()
{
    protothread_pluse (&pt1);
    #ifdef PLUSE_TEST
    protothread_pluse_test (&pt_test);
    #endif
}
//INIT_APP_LOOP_EXPORT(pluse_app);
