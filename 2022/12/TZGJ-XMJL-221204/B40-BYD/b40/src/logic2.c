#include "includes.h"
#include "power_out.h"
#include "can_protol.h"
#include "switch.h"
#include "logic.h"

#ifdef LOGIC2


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
					if(MOD_ADDR == ADDR2_MOD)
					{
							int8_t flag2 = RESET_SWITCH_OP2(SW_A22,(SW_A39 == 0));
						
							OUT_A02 = RESET_SWITCH_DELAY((flag2 == 0),10); //开
							OUT_A03 = RESET_SWITCH_DELAY((flag2 == 1),10); //关
							
					}
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
		protothread_logic (&ptlogic);
}
//INIT_APP_LOOP_EXPORT(logic_app);
#endif
