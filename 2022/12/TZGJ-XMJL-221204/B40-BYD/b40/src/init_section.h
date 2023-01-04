#ifndef __INIT_SECTION_H__
#define __INIT_SECTION_H__


typedef void (*init_fn_t)(void);

#define INIT_EXPORT(fn, level)  __attribute__((used)) const init_fn_t __stan_init_##fn  __attribute__((section(".init_fn." level))) = fn

#define EXTERN_FUNC_NAME(fn)  extern const init_fn_t __stan_init_##fn

//工作在开中断之前
#define INIT_BOARD_EXPORT(fn)           		INIT_EXPORT(fn, "1") 
#define INIT_PREV_EXPORT(fn)       					INIT_EXPORT(fn, "2")
#define INIT_DEVICE_EXPORT(fn)       				INIT_EXPORT(fn, "3")

//以下函数工作在开中断之后,按照顺序初始化
#define INIT_COMPONENT_EXPORT(fn)           INIT_EXPORT(fn, "4")
#define INIT_ENV_EXPORT(fn)           			INIT_EXPORT(fn, "5")
#define INIT_APP_EXPORT(fn)           			INIT_EXPORT(fn, "6")

#define INIT_APP_LOOP_EXPORT(fn)      			INIT_EXPORT(fn, "7")


EXTERN_FUNC_NAME(init_board_start); 
EXTERN_FUNC_NAME(init_app_end); 


extern __inline void auto_loop(void);
extern void auto_init(void);

#endif
