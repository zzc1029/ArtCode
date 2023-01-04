#include "init_section.h"
#include "includes.h"

static void init_start(void)
{
}
INIT_EXPORT(init_start, "0");
 
static void init_board_start(void)
{
    /* Disable interrupt */
    Disable_Irq();

    /* peripherals config */
    /* Please configure in Startup -> BF7006AMxx_config.c -> Configuration Wizard */
    peripherals_config();

}
INIT_EXPORT(init_board_start, "0.end");

static void init_board_end(void)
{
	Enable_Irq();
}
INIT_EXPORT(init_board_end, "3.end");

static void init_app_end(void)
{
}
INIT_EXPORT(init_app_end, "6.end");

static void app_end(void)
{
}
INIT_EXPORT(app_end, "7.end");

#define FUNC_NAME(fn)  __stan_init_##fn

void auto_init()
{
	volatile const init_fn_t *fn_ptr;
	for (fn_ptr = &FUNC_NAME(init_board_start); fn_ptr < &FUNC_NAME(init_app_end); fn_ptr++)
	{
		(*fn_ptr)();
	}
}


//const init_fn_t *fn_ptr = &FUNC_NAME(init_app_end)+1;

//#pragma O3
__inline void auto_loop()
{
	const init_fn_t *fn_ptr;
//	#pragma unroll_completely
	for (fn_ptr = (&FUNC_NAME(init_app_end))+1; fn_ptr < &FUNC_NAME(app_end); fn_ptr++)
	{
		(*fn_ptr)();
	}
	
//	const init_fn_t *fn_ptr = &FUNC_NAME(init_app_end)+1;
//	(*(fn_ptr++))();
//	(*(fn_ptr++))();
//	(*(fn_ptr++))();
//	(*(fn_ptr++))();
//	(*(fn_ptr++))();
//	(*(fn_ptr++))();
//	(*(fn_ptr++))();
//	
//	unsigned int i = &FUNC_NAME(app_end)-&FUNC_NAME(init_app_end)-1;
//	if(i>6)
//	{
//		(*(fn_ptr+i--))();
//		(*(fn_ptr+i--))();
//		(*(fn_ptr+i--))();
//		(*(fn_ptr+i--))();
//		(*(fn_ptr+i--))();
//		(*(fn_ptr+i--))();
//		(*(fn_ptr+i--))();
//	}
//	for (; i!= 0; i--)
//	{
//		(*(fn_ptr+i))();
//	}
}

