#include "includes.h"
#include "power_out.h"
#include "can_protol.h"
#include "switch.h"
#include "logic.h"

#ifdef LOGIC5

inline int int_logic_app()
{	
		static struct pt ptlogic;
	
		if(MOD_ADDR == ADDR3_MOD)
    {
				struct pt * pt = &ptlogic;
			
				PT_BEGIN (pt);

				static uint32_t time;
				while (1)
				{
						time = systick_ms + 100;        
					
						if((KEY_ON == 0) && (KEY_ACC == 0))
						{
								//F_SW19	控地 开关输入	门1关开关
								//F_SW34	控地 开关输入	门1开开关
								//F_SW20	控地 开关输入	门2关开关
								//F_SW35	控地 开关输入	门2开开关
								//SW_A22 控地 开关输入	门复位开开关
								//OUT_A02 门2开
								//OUT_A03 门2关
								//OUT_A07 门1开
								//OUT_A42 门1关
						//--------------------门控制-----------------------------
							  //int8_t flag = RESET_SWITCH_OP2(SW_A22,(SW_A39 == 0));
								OUT_A13 = RESET_SWITCH_DELAY(SW_A37,10); //中门开
								OUT_A02 = RESET_SWITCH_DELAY(SW_A22,10);//中门关
							//	OUT_A42 = RESET_SWITCH_DELAY(SW_A34,10); //前门开
							//	OUT_A08 = RESET_SWITCH_DELAY(SW_A20,10);//前门关
								//OUT_A07 = RESET_SWITCH_DELAY(MOD1_SW34||(flag == 0),10); //开
								//OUT_A42 = RESET_SWITCH_DELAY(MOD1_SW19||(flag == 1),10);//关
								
								/*OUT_A02 = RESET_SWITCH_DELAY(MOD1_SW35,10);
								OUT_A03 = RESET_SWITCH_DELAY(MOD1_SW20,10);*/
						//--------------------------------------------------------
							 //OUT_A05 = 1;//RESET_SWITCH_DELAY(1,10);
						}
						PT_WAIT_UNTIL (pt, ((int) (systick_ms - time) >= 0));
				}
				PT_INFINITE_LOOP_END (pt);
    }
		return 0;
}

void logic_app()
{
	int_logic_app();
}

//INIT_APP_LOOP_EXPORT((init_fn_t*)logic_app);
#endif
