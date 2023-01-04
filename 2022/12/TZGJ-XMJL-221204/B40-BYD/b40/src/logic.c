#include "includes.h"
#include "power_out.h"
#include "can_protol.h"
#include "switch.h"
#include "logic.h"


#ifdef LOGIC


int protothread_logic (struct pt *pt)
{
    uint32_t ad;
    PT_BEGIN (pt);

    static uint32_t time;
    while (1)
    {
        time = systick_ms + 100;
        
				if((KEY_ON == 0) && (KEY_ACC == 0))
				{
						OUT_A42 = SW_A34;		
						OUT_A08 = SW_A20;
						OUT_A03 = SW_A35;
						OUT_A11 = SW_A21;
				}

        PT_WAIT_UNTIL (pt, ((int) (systick_ms - time) >= 0));
    }
    PT_INFINITE_LOOP_END (pt);
}
static struct pt ptlogic;
static void logic_init()
{
    PT_INIT (&ptlogic);
}
INIT_COMPONENT_EXPORT(logic_init);

void logic_app()
{
		if(MOD_ADDR == ADDR3_MOD)
			protothread_logic (&ptlogic);
}
//INIT_APP_LOOP_EXPORT(logic_app);
#endif
