#include "includes.h"
#include "power_out.h"
#include "can_protol.h"
#include "switch.h"
#include "logic.h"

#if 0

#ifdef  LOGIC3


static int protothread_logic (struct pt *pt)
{
    uint32_t ad;
    PT_BEGIN (pt);

    static uint32_t time;
    while (1)
    {
        PT_WAIT_UNTIL (pt, (OUT_A01 > 0));
			
				PoutS[A8].oc_threshold = PoutS[A8].sc_threshold = 10000;
			
				PT_DELAY_MS(pt,5000);
			
				PoutS[A8].oc_threshold = PoutS[A8].sc_threshold = 1000;
			
    }
    PT_INFINITE_LOOP_END (pt);
}
static struct pt ptlogic;
static void logic3_init()
{
    PT_INIT (&ptlogic);
}
INIT_COMPONENT_EXPORT(logic3_init);

void logic3_app()
{
		if(MOD_ADDR == ADDR3_MOD)
    {
			protothread_logic (&ptlogic);
    }
}
//INIT_APP_LOOP_EXPORT(logic_app);
#endif

#endif

