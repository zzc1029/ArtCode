/*
 * Artpatch.h
 *
 *  Created on: 2021-9-26
 *      Author: ART
 */


#ifndef _ARTPATCH_H
#define _ARTPATCH_H



#define ARTGetU16Low(x)	(((x)>>0)&0xFF)
#define ARTGetU16High(x) 	(((x)>>8)&0xFF)

#define ARTTestBitTrue(byte,bit)    (((byte) & (1<<(bit))) > 0)
#define ARTTestBitFalse(byte,bit)    (((byte) & (1<<(bit))) == 0)


#define ARTGetBits(byte,offset,bits)    (((byte)>>(offset)) & ((1<<(bits))-1))


#define ARTTestBits(byte,offset,bits,comp)    (((byte) & (((1<<(bits))-1) << (offset))) == ((comp)<<(offset)))

#define ARTGETU32(l,ml,mh,h) ((((uint32_t)h)<<24)+(((uint32_t)mh)<<16)+(((uint32_t)ml)<<8)+l)
#define ARTGETU16(l,ml)   (uint16_t)ml)<<8)+l)

enum
{
   J1_01 = 0,
   J1_02,
   J1_03,
   J1_04,
   J1_05,
   J1_06,
   J1_07,
   J1_08,
   J1_09,
   J1_10,
   J1_11,
   J1_12,
   J1_13,
   J1_14,
   J1_15,
   J1_16,
   J1_17,
   J1_18,
   J1_19,
   J1_20,
   J1_21,
   J1_22,
   J1_23
};

#define  TEST_HZ   ((EMIOS_0.CH[23].CCNTR.R > 34999) || (EMIOS_0.CH[23].CCNTR.R < 15000))

#define  FrontState(state)     ((front_power[state/16].byte[state/2 - (state/16)*8] >> ((state%2)*4))&0x0f)
#define  RearState(state)      ((rear_power[state/16].byte[state/2 - (state/16)*8]  >> ((state%2)*4))&0x0f)
#define  TopState(state)       ((top_power[state/16].byte[state/2 - (state/16)*8]   >> ((state%2)*4))&0x0f)

//下面是B50定义方式
//#define  BACKLIGHT_SW_FEEDBACK         FrontState(J1_10)&&RearState(J1_05)&&RearState(J1_16)
//#define  LED_HBEAM_SW_FEEDBACK         FrontState(J1_13)
//#define  LED_LBEAM_SW_FEEDBACK         FrontState(J1_12)
//#define  LED_FFOG_SW_FEEDBACK          FrontState(J1_18)
//#define  LED_RFOG_SW_FEEDBACK          RearState(J1_09)
//#define  LED_BREAK_SW_FEEDBACK         RearState(J1_11)

//B50定义


enum
{
  A1 = 0,
  A9,
  A2,
  A10,
  A3,
  A11,
  A4,
  A12,
  A5,
  A13,
  A6,
  A14,
  A7,
  A42,
  A8
};

#define B40_FEEDBACK(module,num) (((((bcm_fb_st_##module##.dword)>>(num*2))&0x03) == 0) && ((bcm_out_st_##module##.word>>num)&0x01))

#define B40_FRONT_FEEDBACK(num)  (((((bcm_fb_st_f.dword)>>(num*2))&0x03) == 0) && ((bcm_out_st_f.word>>num)&0x01))
#define B40_REAR_FEEDBACK(num)   (((((bcm_fb_st_r.dword)>>(num*2))&0x03) == 0) && ((bcm_out_st_r.word>>num)&0x01))
#define B40_TOP_FEEDBACK(num)    (((((bcm_fb_st_t.dword)>>(num*2))&0x03) == 0) && ((bcm_out_st_t.word>>num)&0x01))










#endif
