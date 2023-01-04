#include "includes.h"
#include "switch.h"

uint8_t mod_addr;
uint8_t mod_addr_s0;

#define PL_ON() gpio_bit_set(GPIOE, GPIO_PIN_2)
#define CL_ON() gpio_bit_set(GPIOF, GPIO_PIN_2)

#define PL_OFF() gpio_bit_reset(GPIOE, GPIO_PIN_2)
#define CL_OFF() gpio_bit_reset(GPIOF, GPIO_PIN_2)

#define MI_IN() gpio_bit_get(GPIOE, GPIO_PIN_5)

#define GET_MOD_ADDR() ((in_sw[1] >> 4) & 3)




uint8_t in_sw[3];

/*
============================165工作逻辑==========================
1、PIN1（KL）低电平，P0-P7（或A-H）状态置入寄存器；高电平则禁止获取状态值；
2、CLK1、CLK2功能相同，可交换使用。当CLK1或CLK2有一个为低，且KL为高时，另一个时钟可输入。
3、控制CLK的高低电平转换，依次获取P0-P7的值。
*/
static void GetKeyIn()
{
    int i;
    uint16_t key_in = 0;

    PL_OFF();
    NOP();
    PL_ON();

    key_in = 0;
    for (i = 0; i < 16; i++)
    {
        CL_OFF();
        key_in <<= 1;
        key_in |= MI_IN();
        CL_ON();
    }

    key_in = ~key_in;

    in_sw[0] = key_in;
    in_sw[1] = key_in >> 8;

    in_sw[2] = ADD1_IN() == 0;
    in_sw[2] <<= 1;
    in_sw[2] += KH1_IN();
}

static uint8_t get_bit_count (uint16_t n)
{
    uint8_t table[256] =
    {
        0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
        1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
        1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
        1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
        3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
        1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
        3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
        3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
        3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
        4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
    };

    return table[n & 0xff] + table[n >> 8];
}

int protothread_add_smooth (struct pt *pt)
{
    PT_BEGIN (pt);

    static uint32_t time;

    /* We loop forever here. */
    while (1)
    {

        PT_DELAY_MS (pt, 1);

        {
            static uint16_t add = 0xFF; //low
            static uint16_t kh1 = 0;  //high
            add <<= 1;
            add |= ADD1_IN();

            kh1 <<= 1;
            kh1 |= KH1_IN();

            in_sw[2] = get_bit_count (kh1) >= 8;
            in_sw[2] += (get_bit_count (add) <= 8) << 1;

        }
        /* And we loop. */
    }
    PT_INFINITE_LOOP_END (pt);
}

int protothread_in (struct pt *pt)
{
    PT_BEGIN (pt);

    static uint32_t time;

    /* We loop forever here. */
    while (1)
    {
        PT_DELAY_MS (pt, 20);

        GetKeyIn();

        /* And we loop. */
    }
    PT_INFINITE_LOOP_END (pt);
}


int protothread_mod_addr_init (struct pt *pt)
{
    PT_BEGIN (pt);

    static uint32_t time;

		PT_DELAY_MS (pt, 333);
		wdt_clear();						//看门狗0.5s溢出，所以此处需要喂狗，否则软件在执行下面一个PT_DELAY_MS()时会复位
		PT_DELAY_MS (pt, 333);
		wdt_clear();
		PT_DELAY_MS (pt, 333);
		wdt_clear();

    /* We loop forever here. */
    while (1)
    {
        PT_DELAY_MS (pt, 10);

        GetKeyIn();
        mod_addr_s0 = GET_MOD_ADDR();

        PT_DELAY_MS (pt, 10);

        GetKeyIn();
        if (mod_addr_s0 == GET_MOD_ADDR())
        {
            break;
        }
        /* And we loop. */
				wdt_clear();
    }

		#ifdef DEBUG
		mod_addr = 3;
		#else
    mod_addr = mod_addr_s0 + 1;
		#endif

    PT_END (pt);
}

static struct pt pt1;

//protothread_add_smooth(pts +POUT_COUNT + 6);
static void din_init()
{
    PT_INIT (&pt1);
	
		#ifdef B40V60
		//PTF4 控低开关 上拉电控制，高有效
		#define INPUT_PUPWR_ON()  gpio_bit_set(GPIOF, GPIO_PIN_4)
		INPUT_PUPWR_ON();
		#endif
}
INIT_COMPONENT_EXPORT(din_init);

void din_app()
{
    protothread_in (&pt1);
}
//INIT_APP_LOOP_EXPORT(din_app);

static void mod_addr_init()
{
    while (protothread_mod_addr_init (&pt1) != PT_ENDED);
    PT_INIT (&pt1);
}
INIT_ENV_EXPORT(mod_addr_init);

