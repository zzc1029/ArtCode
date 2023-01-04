#include "includes.h"
#include "power_out.h"
#include "can_protol.h"
#include "switch.h"
#include "logic.h"

#ifdef LOGIC4

static int protothread_logic (struct pt *pt)
{
		static uint8_t  sw_save = 0;
    PT_BEGIN (pt);

    static uint32_t time;
		OUT_A08 = 1;
	
    while (1)
    {
				if ((KEY_ON == 0) && (KEY_ACC == 0))
				{
						OUT_A08 = !SW_A18;
				}			
				PT_DELAY_MS(pt,100);
    }
    PT_INFINITE_LOOP_END (pt);
}
static struct pt ptlogic;
static void logic3_init()
{
    PT_INIT (&ptlogic);
}
INIT_COMPONENT_EXPORT(logic3_init);

void logic_app()
{
		if(MOD_ADDR == ADDR3_MOD)
    {
			protothread_logic (&ptlogic);
    }
}
//INIT_APP_LOOP_EXPORT(logic_app);
#endif
