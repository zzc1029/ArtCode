#include "includes.h"
#include "power_out.h"
#include "can_protol.h"
#include "switch.h"

#ifndef __LOGIC_H__
#define __LOGIC_H__


#ifdef MOD1_SW_DATA
extern uint8_t sw_1[3];
#endif
#ifdef MOD2_SW_DATA
extern uint8_t sw_2[3];
#endif
#ifdef MOD3_SW_DATA
extern uint8_t sw_3[3];
#endif
#ifdef MOD4_SW_DATA
extern uint8_t sw_4[3];
#endif

#define SW_A32  (in_sw[0] & 0x01)
#define SW_A18  (in_sw[0] & 0x02)
#define SW_A33  (in_sw[0] & 0x04)
#define SW_A19  (in_sw[0] & 0x08)
#define SW_A34  (in_sw[0] & 0x10)
#define SW_A20  (in_sw[0] & 0x20)
#define SW_A35  (in_sw[0] & 0x40)
#define SW_A21  (in_sw[0] & 0x80)
#define SW_A36  (in_sw[1] & 0x01)
#define SW_A22  (in_sw[1] & 0x02)
#define SW_A37  (in_sw[1] & 0x04)
#define SW_A23  (in_sw[1] & 0x08)
#define SW_A38  (in_sw[1] & 0x10)
#define SW_A24  (in_sw[1] & 0x20)
#define SW_A39  (in_sw[1] & 0x40)
#define SW_A17  (in_sw[2] & 0x01)
#define SW_A41  (in_sw[2] & 0x02)

#define OUT_A01  PoutS[0].cmd
#define OUT_A09  PoutS[1].cmd
#define OUT_A02  PoutS[2].cmd
#define OUT_A10  PoutS[3].cmd
#define OUT_A03  PoutS[4].cmd
#define OUT_A11  PoutS[5].cmd
#define OUT_A04  PoutS[6].cmd
#define OUT_A12  PoutS[7].cmd
#define OUT_A05  PoutS[8].cmd
#define OUT_A13  PoutS[9].cmd
#define OUT_A06  PoutS[10].cmd
#define OUT_A14  PoutS[11].cmd
#define OUT_A07  PoutS[12].cmd
#define OUT_A42  PoutS[13].cmd
#define OUT_A08  PoutS[14].cmd

#define MOD1_SW32  (sw_1[0] & 0x01)
#define MOD1_SW18  (sw_1[0] & 0x02)
#define MOD1_SW33  (sw_1[0] & 0x04)
#define MOD1_SW19  (sw_1[0] & 0x08)
#define MOD1_SW34  (sw_1[0] & 0x10)
#define MOD1_SW20  (sw_1[0] & 0x20)
#define MOD1_SW35  (sw_1[0] & 0x40)
#define MOD1_SW21  (sw_1[0] & 0x80)
#define MOD1_SW36  (sw_1[1] & 0x01)
#define MOD1_SW22  (sw_1[1] & 0x02)
#define MOD1_SW37  (sw_1[1] & 0x04)
#define MOD1_SW23  (sw_1[1] & 0x08)
#define MOD1_SW38  (sw_1[1] & 0x10)
#define MOD1_SW24  (sw_1[1] & 0x20)
#define MOD1_SW39  (sw_1[1] & 0x40)
#define MOD1_SW17  (sw_1[2] & 0x01)
#define MOD1_SW41  (sw_1[2] & 0x02)

#define MOD2_SW32  (sw_2[0] & 0x01)
#define MOD2_SW18  (sw_2[0] & 0x02)
#define MOD2_SW33  (sw_2[0] & 0x04)
#define MOD2_SW19  (sw_2[0] & 0x08)
#define MOD2_SW34  (sw_2[0] & 0x10)
#define MOD2_SW20  (sw_2[0] & 0x20)
#define MOD2_SW35  (sw_2[0] & 0x40)
#define MOD2_SW21  (sw_2[0] & 0x80)
#define MOD2_SW36  (sw_2[1] & 0x01)
#define MOD2_SW22  (sw_2[1] & 0x02)
#define MOD2_SW37  (sw_2[1] & 0x04)
#define MOD2_SW23  (sw_2[1] & 0x08)
#define MOD2_SW38  (sw_2[1] & 0x10)
#define MOD2_SW24  (sw_2[1] & 0x20)
#define MOD2_SW39  (sw_2[1] & 0x40)
#define MOD2_SW17  (sw_2[2] & 0x01)
#define MOD2_SW41  (sw_2[2] & 0x02)

#define MOD3_SW32  (sw_3[0] & 0x01)
#define MOD3_SW18  (sw_3[0] & 0x02)
#define MOD3_SW33  (sw_3[0] & 0x04)
#define MOD3_SW19  (sw_3[0] & 0x08)
#define MOD3_SW34  (sw_3[0] & 0x10)
#define MOD3_SW20  (sw_3[0] & 0x20)
#define MOD3_SW35  (sw_3[0] & 0x40)
#define MOD3_SW21  (sw_3[0] & 0x80)
#define MOD3_SW36  (sw_3[1] & 0x01)
#define MOD3_SW22  (sw_3[1] & 0x02)
#define MOD3_SW37  (sw_3[1] & 0x04)
#define MOD3_SW23  (sw_3[1] & 0x08)
#define MOD3_SW38  (sw_3[1] & 0x10)
#define MOD3_SW24  (sw_3[1] & 0x20)
#define MOD3_SW39  (sw_3[1] & 0x40)
#define MOD3_SW17  (sw_3[2] & 0x01)
#define MOD3_SW41  (sw_3[2] & 0x02)

#define MOD4_SW32  (sw_4[0] & 0x01)
#define MOD4_SW18  (sw_4[0] & 0x02)
#define MOD4_SW33  (sw_4[0] & 0x04)
#define MOD4_SW19  (sw_4[0] & 0x08)
#define MOD4_SW34  (sw_4[0] & 0x10)
#define MOD4_SW20  (sw_4[0] & 0x20)
#define MOD4_SW35  (sw_4[0] & 0x40)
#define MOD4_SW21  (sw_4[0] & 0x80)
#define MOD4_SW36  (sw_4[1] & 0x01)
#define MOD4_SW22  (sw_4[1] & 0x02)
#define MOD4_SW37  (sw_4[1] & 0x04)
#define MOD4_SW23  (sw_4[1] & 0x08)
#define MOD4_SW38  (sw_4[1] & 0x10)
#define MOD4_SW24  (sw_4[1] & 0x20)
#define MOD4_SW39  (sw_4[1] & 0x40)
#define MOD4_SW17  (sw_4[2] & 0x01)
#define MOD4_SW41  (sw_4[2] & 0x02)

#define CONNECTION(text1,text2) text1##text2
#define CONNECT(text1,text2) CONNECTION(text1,text2)

#define RESET_SWITCH_DELAY(cond, count)  \
	({                              \
		static int8_t CONNECT(timeout, __LINE__) = 0; \
		static int8_t CONNECT(first, __LINE__) = 0;   \
		if (CONNECT(timeout, __LINE__))               \
			CONNECT(timeout, __LINE__)--;             \
		if (cond)                  \
		{                          \
			if (CONNECT(first, __LINE__) == 0)        \
			{                      \
				CONNECT(first, __LINE__) = 1;         \
				CONNECT(timeout, __LINE__) = count;   \
			}                      \
		}                          \
		else                       \
		{                          \
			CONNECT(first, __LINE__) = 0;             \
		}                          \
		CONNECT(timeout, __LINE__) > 0;               \
	})
	
	
#define RESET_SWITCH_OP(cond, op)  \
	({                              \
		static int8_t CONNECT(first, __LINE__) = 0;   \
		if (cond)                  \
		{                          \
			if (CONNECT(first, __LINE__) == 0)        \
			{                      \
				CONNECT(first, __LINE__) = 1;         \
				op;       					\
			}                      \
		}                          \
		else                       \
		{                          \
			CONNECT(first, __LINE__) = 0;             \
		}                          \
	})
	
	
#define RESET_SWITCH_OP2(cond, op)  \
	({                              \
		static int8_t CONNECT(first, __LINE__) = 0;   \
		static int8_t CONNECT(flag, __LINE__) = -1;   \
		if (cond)                  \
		{                          \
			if (CONNECT(first, __LINE__) == 0)        \
			{                      \
				CONNECT(first, __LINE__) = 1;         \
				CONNECT(flag, __LINE__) = (op);       					\
			}                      \
		}                          \
		else                       \
		{                          \
			CONNECT(first, __LINE__) = 0;             \
			CONNECT(flag, __LINE__) = -1;\
		}                          \
		CONNECT(flag, __LINE__);\
	})
	
	
#endif

