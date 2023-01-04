#include "includes.h"
#include "power_out.h"
#include "can_protol.h"
#include "switch.h"
#include "logic.h"

#ifdef LOGIC1


//F_SW4	A19	控地 开关输入	右门1关开关
//F_SW5	A34	控地 开关输入	右门1开开关
//F_SW6	A20	控地 开关输入	右门2关开关
//F_SW7	A35	控地 开关输入	右门2开开关
//F_SW8	A21	控地 开关输入	左门关开关
//F_SW9	A36	控地 开关输入	左门开开关

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
					if(MOD_ADDR == ADDR3_MOD)
					{						
							OUT_A02 = RESET_SWITCH_DELAY(MOD1_SW36,10);
							OUT_A03 = RESET_SWITCH_DELAY(MOD1_SW21,10);
					}
					else if(MOD_ADDR == ADDR2_MOD)
					{
							int8_t flag2 = RESET_SWITCH_OP2(SW_A22,(SW_A39 == 0));
						
							OUT_A02 = RESET_SWITCH_DELAY(MOD1_SW34||(flag2 == 0),10); //开
							OUT_A03 = RESET_SWITCH_DELAY(MOD1_SW19||(flag2 == 1),10); //关
							
							OUT_A10 = RESET_SWITCH_DELAY(MOD1_SW35,10);
							OUT_A11 = RESET_SWITCH_DELAY(MOD1_SW20,10);
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
