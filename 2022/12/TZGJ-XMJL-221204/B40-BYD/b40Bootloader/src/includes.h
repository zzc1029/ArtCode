#ifndef __INCLUDES_H__
#define __INCLUDES_H__

#include "BF7006AMxx_config.h"
#include "SEGGER_RTT.h"

#define LC_INCLUDE "lc-addrlabels.h"
#include "pt.h"

extern volatile uint32_t systick_ms;

#define PT_DELAY_MS(pt, ms)                             \
    {                                                     \
        time = systick_ms + (ms);                           \
        PT_WAIT_UNTIL(pt, ((int)(systick_ms - time) >= 0)); \
    }

#define PT_LOOP(pt)    \
    do                   \
    {                    \
        LC_SET((pt)->lc);  \
        return PT_WAITING; \
    } while (0)

#define FRONT_MOD	 	(0x520)
#define REAR_MOD		(0x521)
#define TOP_MOD			(0x522)
#define TOP2_MOD			(0x523)

#define FRONT_MOD_DATA	(0x527)
#define REAR_MOD_DATA		(0x528)
#define TOP_MOD_DATA		(0x529)
#define TOP2_MOD_DATA		(0x52A)


extern uint16_t boot_funcid;
extern uint16_t boot_dataid;

#endif
