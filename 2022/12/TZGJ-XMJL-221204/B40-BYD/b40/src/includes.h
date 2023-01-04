#ifndef __INCLUDES_H__
#define __INCLUDES_H__

#include "BF7006AMxx_config.h"
#include "SEGGER_RTT.h"
#include "init_section.h"

#define LC_INCLUDE "lc-addrlabels.h"
#include "pt.h"

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

#include "config.h"


extern volatile uint32_t systick_ms;
extern uint8_t mod_addr;
extern uint8_t mod_addr_s0;

#define ADDR1_MOD   1  //前模块
#define ADDR2_MOD   2  //
#define ADDR3_MOD   3  //
#define ADDR4_MOD   4  //

#define MOD_ADDR 	mod_addr //
#define MOD_ADDR_S0 	mod_addr_s0 //


#define ID_BOOTLOADER   0X0526
#define ID_FW_UPDATE    0x06B0
#define ID_TX_TEST      0x0610
		
#define ID_FRT_PRO      0x0550
#define ID_REAR_PRO     0x0551
#define ID_TOP_PRO      0x0552

#define ID_TX_SW        0x0680
#define ID_TX_AD        0x0670
#define ID_TX_AD_ALL    0x0690
#define ID_TX_ST        0x0560
#define ID_TX_MILE      0x0450

#define ID_TX_CURRENT   0X0690

#define ID_RX_PWM       0x06E4
#define ID_RX_DASH      0x06A4
#define ID_RX_SET       0x0610
#define ID_ADD_DASH     0x06B4
#define ID_PWMTIME_SET  0x06F0

#endif
