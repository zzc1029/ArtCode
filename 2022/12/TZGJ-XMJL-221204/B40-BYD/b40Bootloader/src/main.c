#include "includes.h"
#include "switch.h"
#include "can_protol.h"
#include "BF7006AMxx_eflash.h"



volatile uint32_t systick_ms = 0; //
extern void InitSendFrame(void);


#define PL_ON() gpio_bit_set(GPIOE, GPIO_PIN_2)
#define CL_ON() gpio_bit_set(GPIOF, GPIO_PIN_2)

#define PL_OFF() gpio_bit_reset(GPIOE, GPIO_PIN_2)
#define CL_OFF() gpio_bit_reset(GPIOF, GPIO_PIN_2)

#define MI_IN() gpio_bit_get(GPIOE, GPIO_PIN_5)

uint8_t in_sw[3];

uint8_t mod_addr;

#define GET_MOD_ADDR() (((in_sw[1] >> 4) & 3) + 1)

void GetKeyIn()
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
}

uint16_t boot_funcid;
uint16_t boot_dataid;

int protothread_mod_addr_init (struct pt *pt)
{
    PT_BEGIN (pt);
    static uint32_t time;
		PT_DELAY_MS (pt, 1000);
    while (1)
    {
        PT_DELAY_MS (pt, 10);

        GetKeyIn();
        mod_addr = GET_MOD_ADDR();

        PT_DELAY_MS (pt, 10);

        GetKeyIn();
        if (mod_addr == GET_MOD_ADDR())
        {
            break;
        }
    }
    PT_END (pt);
}

extern void canhl_loop(void);

int main(void)
{
  static struct pt pt1;

  /* Disable interrupt */
  Disable_Irq();
	
  /* peripherals config */
  /* Please configure in Startup -> BF7006AMxx_config.c -> Configuration Wizard */
  peripherals_config();
	
	#define INPUT_PUPWR_ON()  gpio_bit_set(GPIOF, GPIO_PIN_4)
	INPUT_PUPWR_ON();
	
	InitSendFrame();

  /* Enable interrupt */
  Enable_Irq();

  /* Place your initialization code below */
  PT_INIT(&pt1);
	
	while (protothread_mod_addr_init (&pt1) != PT_ENDED);
	
	switch(mod_addr)
	{
		case 1:
			boot_funcid = FRONT_MOD;
			boot_dataid = FRONT_MOD_DATA;
			break;
		case 2:
			boot_funcid = REAR_MOD;
			boot_dataid = REAR_MOD_DATA;
			break;
		case 3:
			boot_funcid = TOP_MOD;
			boot_dataid = TOP_MOD_DATA;
			break;
		case 4:
		default:
			boot_funcid = TOP2_MOD;
			boot_dataid = TOP2_MOD_DATA;
			break;
	}
	
	PT_INIT(&pt1);
	
  while (1)
  {
    protothread_can_recv(&pt1);
		canhl_loop();
  }

  /* Should never reach here */
  return 0;
}

//--------------------------END OF FILE-----------------------------------
