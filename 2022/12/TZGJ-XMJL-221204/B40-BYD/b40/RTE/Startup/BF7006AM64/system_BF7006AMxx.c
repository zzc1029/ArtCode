/**************************************************************************//**
 * @file     system_ARMCM0.c
 * @brief    CMSIS Device System Source File for
 *           ARMCM0 Device Series
 * @version  V1.08
 * @date     23. November 2012
 *
 * @note
 *
 ******************************************************************************/
/* Copyright (c) 2011 - 2012 ARM LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/

/*!
    \file  system_BF7006AMxx.c
    \brief system function
*/

/*
    Copyright (C) 2017 Byd

    2021-03-03, V1.0.3, add variable SystemCoreClock update function in SystemCoreClockUpdate(void)
                        add Configuration Wizard to configure system interrupt vector offset and system clock
*/
//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------
#include "BF7006AMXX.h"
#include "BF7006AMXX_sysctrl.h"

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define PLL_32M_DIV_1       ((uint32_t)32000000)        /* PLL frequency 32M HZ divide 1 */
#define PLL_32M_DIV_2       ((uint32_t)16000000)        /* PLL frequency 32M HZ divide 2 */
#define PLL_32M_DIV_4       ((uint32_t) 8000000)        /* PLL frequency 32M HZ divide 4 */
#define XTAL_16M            ((uint32_t)16000000)        /* Oscillator frequency 16M HZ   */
#define XTAL_12M            ((uint32_t)12000000)        /* Oscillator frequency 12M HZ   */
#define XTAL_8M             ((uint32_t) 8000000)        /* Oscillator frequency 8M HZ    */

#define XTAL                XTAL_8M                    /* Define XTAL frequency here    */
#define SYSTEM_CLOCK        SYSTEM_CLK

#define XTAL_NONE       0x0
#define XTAL_16MHz      0x1
#define XTAL_12MHz      0x2
#define XTAL_8MHz       0x3

#define SYSCLK_32M      (uint32_t)32000000
#define SYSCLK_16M      (uint32_t)16000000
#define SYSCLK_12M      (uint32_t)12000000
#define SYSCLK_8M       (uint32_t) 8000000

//  <o>System Clock Select
//    <0=>RC 1MHz -> PLL 32MHz
//    <1=>RC 1MHz -> PLL 16MHz
//    <2=>RC 1MHz -> PLL 8MHz
//    <3=>XTAL 8MHz -> PLL 32MHz
//    <4=>XTAL 8MHz -> PLL 16MHz
//    <5=>XTAL 8MHz -> PLL 8MHz
//    <6=>XTAL 12MHz -> PLL 32MHz
//    <7=>XTAL 12MHz -> PLL 16MHz
//    <8=>XTAL 12MHz -> PLL 8MHz
//    <9=>XTAL 16MHz -> PLL 32MHz
//    <10=>XTAL 16MHz -> PLL 16MHz
//    <11=>XTAL 16MHz -> PLL 8MHz
//    <12=>XTAL 16MHz -> 16MHz
//    <13=>XTAL 12MHz -> 12MHz
//    <14=>XTAL 8MHz -> 8MHz
//  <i>System clock source and frequency configuration
#define SysClkSel 3

#if SysClkSel == 0
    #define PLL_SOURCE_SEL      SYS_PLL_SEL_RC1M
    #define SYSTEM_CLK_FREQ     SYS_CLK_32M
    #define XTAL_FREQ           XTAL_NONE
    #define SYSTEM_CLK          SYSCLK_32M
#elif SysClkSel == 1
    #define PLL_SOURCE_SEL      SYS_PLL_SEL_RC1M
    #define SYSTEM_CLK_FREQ     SYS_CLK_16M
    #define XTAL_FREQ           XTAL_NONE
    #define SYSTEM_CLK          SYSCLK_16M
#elif SysClkSel == 2
    #define PLL_SOURCE_SEL      SYS_PLL_SEL_RC1M
    #define SYSTEM_CLK_FREQ     SYS_CLK_8M
    #define XTAL_FREQ           XTAL_NONE
    #define SYSTEM_CLK          SYSCLK_8M
#elif SysClkSel == 3
    #define PLL_SOURCE_SEL      SYS_PLL_SEL_XTAL_8M
    #define SYSTEM_CLK_FREQ     SYS_CLK_32M
    #define XTAL_FREQ           XTAL_8MHz
    #define SYSTEM_CLK          SYSCLK_32M
#elif SysClkSel == 4
    #define PLL_SOURCE_SEL      SYS_PLL_SEL_XTAL_8M
    #define SYSTEM_CLK_FREQ     SYS_CLK_16M
    #define XTAL_FREQ           XTAL_8MHz
    #define SYSTEM_CLK          SYSCLK_16M
#elif SysClkSel == 5
    #define PLL_SOURCE_SEL      SYS_PLL_SEL_XTAL_8M
    #define SYSTEM_CLK_FREQ     SYS_CLK_8M
    #define XTAL_FREQ           XTAL_8MHz
    #define SYSTEM_CLK          SYSCLK_8M
#elif SysClkSel == 6
    #define PLL_SOURCE_SEL      SYS_PLL_SEL_XTAL_12M
    #define SYSTEM_CLK_FREQ     SYS_CLK_32M
    #define XTAL_FREQ           XTAL_12MHz
    #define SYSTEM_CLK          SYSCLK_32M
#elif SysClkSel == 7
    #define PLL_SOURCE_SEL      SYS_PLL_SEL_XTAL_12M
    #define SYSTEM_CLK_FREQ     SYS_CLK_16M
    #define XTAL_FREQ           XTAL_12MHz
    #define SYSTEM_CLK          SYSCLK_16M
#elif SysClkSel == 8
    #define PLL_SOURCE_SEL      SYS_PLL_SEL_XTAL_12M
    #define SYSTEM_CLK_FREQ     SYS_CLK_8M
    #define XTAL_FREQ           XTAL_12MHz
    #define SYSTEM_CLK          SYSCLK_8M
#elif SysClkSel == 9
    #define PLL_SOURCE_SEL      SYS_PLL_SEL_XTAL_16M
    #define SYSTEM_CLK_FREQ     SYS_CLK_32M
    #define XTAL_FREQ           XTAL_16MHz
    #define SYSTEM_CLK          SYSCLK_32M
#elif SysClkSel == 10
    #define PLL_SOURCE_SEL      SYS_PLL_SEL_XTAL_16M
    #define SYSTEM_CLK_FREQ     SYS_CLK_16M
    #define XTAL_FREQ           XTAL_16MHz
    #define SYSTEM_CLK          SYSCLK_16M
#elif SysClkSel == 11
    #define PLL_SOURCE_SEL      SYS_PLL_SEL_XTAL_16M
    #define SYSTEM_CLK_FREQ     SYS_CLK_8M
    #define XTAL_FREQ           XTAL_16MHz
    #define SYSTEM_CLK          SYSCLK_8M
#elif SysClkSel == 12
    #define PLL_SOURCE_SEL      SYS_PLL_SEL_XTAL_16M
    #define SYSTEM_CLK_FREQ     SYS_CLK_XTAL
    #define XTAL_FREQ           XTAL_16MHz
    #define SYSTEM_CLK          SYSCLK_16M
#elif SysClkSel == 13
    #define PLL_SOURCE_SEL      SYS_PLL_SEL_XTAL_12M
    #define SYSTEM_CLK_FREQ     SYS_CLK_XTAL
    #define XTAL_FREQ           XTAL_12MHz
    #define SYSTEM_CLK          SYSCLK_12M
#elif SysClkSel == 14
    #define PLL_SOURCE_SEL      SYS_PLL_SEL_XTAL_8M
    #define SYSTEM_CLK_FREQ     SYS_CLK_XTAL
    #define XTAL_FREQ           XTAL_8MHz
    #define SYSTEM_CLK          SYSCLK_8M
#endif

/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock = (uint32_t)SYSTEM_CLOCK;  /*!< System Clock Frequency (Core Clock)*/

/*----------------------------------------------------------------------------
  Clock functions
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)                   /* Get Core Clock Frequency */
{
    if(SYS_CLK_SEL == SYS_CLK_XTAL){
        #ifdef XTAL
            SystemCoreClock = XTAL;
        #endif
    }else{
        switch(SYS_CLK_SEL){
        case SYS_CLK_32M:
            SystemCoreClock = (uint32_t)32000000;
            break;
        case SYS_CLK_16M:
            SystemCoreClock = (uint32_t)16000000;
            break;
        case SYS_CLK_8M:
            SystemCoreClock = (uint32_t)8000000;
            break;
        default:
            #ifdef XTAL
                SystemCoreClock = XTAL;
            #endif
        }
    }
}

/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */
void SystemInit (void)
{
//  <o>System interrupt vector offset
    //#define SYSTEM_INTERRUPT_VECTOR_OFFSET 0x00000000UL
	  extern uint32_t __Vectors;

    /* system interrupt vector offset set */
    system_intvector_offset((uint32_t)&__Vectors);

    system_clk_sel(PLL_SOURCE_SEL,SYSTEM_CLK_FREQ,XTAL_FREQ);

//  <h> BOR
//    <q0> BOR enable
//    <i> Brown out reset enable
//    <o1> BOR delay 
//      <0=>No delay
//      <1=>Delay 100 us
//    <i> Brown out reset delay config
//  </h>
#define BOR_ENABLE 1
#define BOR_DELAY 1
#if BOR_ENABLE == 1
    #define BOR_ENABLE_OPTION ENABLE
#else
    #define BOR_ENABLE_OPTION DISABLE
#endif
#if BOR_DELAY == 1
    #define BOR_DELAY_OPTION ENABLE
#else
    #define BOR_DELAY_OPTION DISABLE
#endif
    bor_init(BOR_ENABLE_OPTION,BOR_DELAY_OPTION);

//  <h> LVDT
//    <q0> LVDT enable
//    <i> Low voltage detect enable
//    <o1> LVDT gear
//      <0=> 3.5V
//      <1=> 4.0V
//      <2=> 4.5V
//    <i> LVDT gear select
//    <q2> LVDT interrupt enable
//    <i> LVDT interrupt enable
//  </h>
#define LVDT_ENABLE 1
#define LVDT_GEAR 0
#define LVDT_INT_ENABLE 1
#if LVDT_ENABLE == 1
    #define LVDT_ENABLE_OPTION ENABLE
#else
    #define LVDT_ENABLE_OPTION DISABLE
#endif
#if LVDT_INT_ENABLE == 1
    #define LVDT_INT_ENABLE_OPTION ENABLE
#else
    #define LVDT_INT_ENABLE_OPTION DISABLE
#endif
    lvdt_init(LVDT_ENABLE_OPTION,LVDT_GEAR,LVDT_INT_ENABLE_OPTION);

//  <q> RESET filter enable
//  <i> RESET pin filter enable
#define RESET_FILTER_ENABLE 1
#if RESET_FILTER_ENABLE == 1
    #define RESET_FILTER_OPTION ENABLE
#else
    #define RESET_FILTER_OPTION DISABLE
#endif
    reset_filter(RESET_FILTER_OPTION);

//  <o> FLASH protect size
//    <0x0=> No protection
//    <0x1=> 2k Bytes
//    <0x2=> 4k Bytes
//    <0x3=> 6k Bytes
//    <0x4=> 8k Bytes
//    <0x5=> 10k Bytes
//    <0x6=> 12k Bytes
//    <0x7=> 14k Bytes
//    <0x8=> 16k Bytes
//    <0x9=> 18k Bytes
//    <0xA=> 20k Bytes
//    <0xB=> 22k Bytes
//    <0xC=> 24k Bytes
//    <0xD=> 26k Bytes
//    <0xE=> 28k Bytes
//    <0xF=> 30k Bytes
//    <0x10=> 32k Bytes
//    <0x11=> 34k Bytes
//    <0x12=> 36k Bytes
//    <0x13=> 38k Bytes
//    <0x14=> 40k Bytes
//    <0x15=> 42k Bytes
//    <0x16=> 44k Bytes
//    <0x17=> 46k Bytes
//    <0x18=> 48k Bytes
//    <0x19=> 50k Bytes
//    <0x1A=> 52k Bytes
//    <0x1B=> 54k Bytes
//    <0x1C=> 56k Bytes
//    <0x1D=> 58k Bytes
//    <0x1E=> 60k Bytes
//    <0x1F=> 62k Bytes
//    <0x20=> 64k Bytes
//    <0x21=> 66k Bytes
//    <0x22=> 68k Bytes
//    <0x23=> 70k Bytes
//    <0x24=> 72k Bytes
//    <0x25=> 74k Bytes
//    <0x26=> 76k Bytes
//    <0x27=> 78k Bytes
//    <0x28=> 80k Bytes
//    <0x29=> 82k Bytes
//    <0x2A=> 84k Bytes
//    <0x2B=> 86k Bytes
//    <0x2C=> 88k Bytes
//    <0x2D=> 90k Bytes
//    <0x2E=> 92k Bytes
//    <0x2F=> 94k Bytes
//    <0x30=> 96k Bytes
//  <i> FLASH protect size select
#ifdef BF7x06AMxx_EFLASH_DRIVER_PRESENT
    flash_protect(0);
#endif

//  <o> EEPROM protect size
//    <0x0=> No protection
//    <0x1=> 64 Bytes
//    <0x2=> 128 Bytes
//    <0x3=> 192 Bytes
//    <0x4=> 256 Bytes
//    <0x5=> 320 Bytes
//    <0x6=> 384 Bytes
//    <0x7=> 448 Bytes
//    <0x8=> 512 Bytes
//    <0x9=> 576 Bytes
//    <0xA=> 640 Bytes
//    <0xB=> 704 Bytes
//    <0xC=> 768 Bytes
//    <0xD=> 832 Bytes
//    <0xE=> 896 Bytes
//    <0xF=> 960 Bytes
//    <0x10=> 1024 Bytes
//    <0x11=> 1088 Bytes
//    <0x12=> 1152 Bytes
//    <0x13=> 1216 Bytes
//    <0x14=> 1280 Bytes
//    <0x15=> 1344 Bytes
//    <0x16=> 1408 Bytes
//    <0x17=> 1472 Bytes
//    <0x18=> 1536 Bytes
//    <0x19=> 1600 Bytes
//    <0x1A=> 1664 Bytes
//    <0x1B=> 1728 Bytes
//    <0x1C=> 1792 Bytes
//    <0x1D=> 1856 Bytes
//    <0x1E=> 1920 Bytes
//    <0x1F=> 1984 Bytes
//    <0x20=> 2048 Bytes
//  <i> EEPROM protect size select
#ifdef BF7x06AMxx_EFLASH_DRIVER_PRESENT
    eeprom_protect(0);
#endif
}
