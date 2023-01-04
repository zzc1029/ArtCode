# 1 "../system/src/kf32a_basic_int.c"
# 1 "/cygdrive/d/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/Debug//"
# 1 "<command-line>"
# 1 "../system/src/kf32a_basic_int.c"
# 15 "../system/src/kf32a_basic_int.c"
# 1 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/kf32a_basic_int.h" 1
# 14 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/kf32a_basic_int.h"
# 1 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h" 1
# 20 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
# 1 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys/stdint.h" 1
# 16 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys/stdint.h"
# 1 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys/stddef.h" 1
# 24 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys/stddef.h"
typedef int ptrdiff_t;





typedef unsigned int size_t;




typedef unsigned short wchar_t;
# 17 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys/stdint.h" 2




typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef unsigned char uint_least8_t;
typedef short int_least16_t;
typedef unsigned short uint_least16_t;
typedef int int_least32_t;
typedef unsigned int uint_least32_t;
typedef long long int_least64_t;
typedef unsigned long long uint_least64_t;





typedef char int_fast8_t;
typedef unsigned char uint_fast8_t;
typedef short int_fast16_t;
typedef unsigned short uint_fast16_t;
typedef int int_fast32_t;
typedef unsigned int uint_fast32_t;
typedef long long int_fast64_t;
typedef unsigned long long uint_fast64_t;
# 60 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys/stdint.h"
  typedef int intptr_t;
# 69 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys/stdint.h"
  typedef unsigned int uintptr_t;




typedef long long intmax_t;
typedef unsigned long long uintmax_t;
# 21 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h" 2
# 1 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_Config.h" 1
# 15 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_Config.h"
# 1 "D:\\zzc\\project\\pro_2021\\pro_12\\FYGJ-AK-211230\\code\\ART_BOOT/__Kungfu32_chipmodel_define.h" 1
# 16 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_Config.h" 2
# 22 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h" 2
# 36 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef enum
{
    FALSE = 0,
    TRUE = !FALSE
} FunctionalState;



typedef enum
{
    RESET = 0,
    SET = !RESET
} FlagStatus, INTStatus;


typedef enum
{
    FAILURE = 0,
    SUCCESS = !FAILURE
} RetStatus;


typedef enum
{
    DISABLE = 0,
    ENABLE = !DISABLE
} AbleStatus;






typedef enum {
    INT_Initial_SP = 0,
    INT_Reset = 1,
    INT_NMI = 2,
    INT_HardFault = 3,
    INT_Reserved4 = 4,
    INT_StackFault = 5,
    INT_AriFault = 6,
    INT_Reserved7 = 7,
    INT_Reserved8 = 8,
    INT_Reserved9 = 9,
    INT_Reserved10 = 10,
    INT_SVCAll = 11,
    INT_Reserved12 = 12,
    INT_Reserved13 = 13,
    INT_SoftSV = 14,
    INT_SysTick = 15,
    INT_WWDT = 16,
    INT_EINT16 = 17,
    INT_EINT0 = 18,
    INT_EINT1 = 19,
    INT_EINT2 = 20,
    INT_EINT3 = 21,
    INT_EINT4 = 22,
    INT_EINT9TO5 = 23,
    INT_EINT15TO10 = 24,
    INT_T1 = 25,
    INT_T3 = 26,
    INT_T5 = 27,
    INT_T6 = 28,
    INT_QEI = 29,
    INT_T7 = INT_QEI,
    INT_T8 = INT_QEI,
    INT_CAN2 = 30,
    INT_CAN3 = 31,
    INT_CAN4 = 32,
    INT_T14 = 33,
    INT_T15 = 34,
    INT_CAN5 = 35,
    INT_EXIC = 36,
    INT_ADC0 = 37,
    INT_ADC1 = 38,
    INT_CFGL = 39,
    INT_LCD = 40,
    INT_T0 = 41,
    INT_DMA0 = 42,
    INT_CMP = 43,
    INT_USART0 = 44,
    INT_USART1 = 45,
    INT_SPI0 = 46,
    INT_SPI1 = 47,
    INT_DMA1 = 48,
    INT_EINT19TO17 = 49,
    INT_CAN0 = 50,
    INT_CAN1 = 51,
    INT_T9 = 52,
    INT_T10 = 53,
    INT_EINT21TO20 = 54,
    INT_EINT31TO22 = 55,
    INT_OSC = 56,
    INT_CLK = INT_OSC,
    INT_I2C0 = 57,
    INT_I2C1 = 58,
    INT_I2C2 = 59,
    INT_USB = 60,
    INT_T2 = 61,
    INT_T4 = 62,
    INT_CTOUCH = 63,
    INT_USART2 = 64,
    INT_USART3 = 65,
    INT_USART4 = 66,
    INT_SPI2 = 67,
    INT_SPI3 = 68,
    INT_ADC2 = 69,
    INT_T18 = 70,
    INT_T19 = 71,
    INT_T22 = 72,
    INT_T23 =INT_T22,
    INT_WKP0 = 73,
    INT_WKP1 =INT_WKP0,
    INT_WKP2 =INT_WKP0,
    INT_WKP3 =INT_WKP0,
    INT_WKP4 =INT_WKP0,
    INT_T20 = 74,
    INT_T21 = 75,
    INT_I2C3 = 76,
    INT_USART5 = 77,
    INT_USART6 = 78,
    INT_USART7 = 79,
} InterruptIndex;
# 171 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct GPIO_MemMap {
    volatile const uint32_t PIR;
    volatile uint32_t POR;
    volatile uint32_t PUR;
    volatile uint32_t PDR;
    volatile uint32_t PODR;
    volatile uint32_t PMOD;
    volatile uint32_t OMOD;
    volatile uint32_t LOCK;
    volatile uint32_t RMP[2];
                uint32_t RESERVED;
    volatile uint32_t CTMDCTL[2];
}GPIO_SFRmap;
# 1127 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct OSC_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t INT;
    volatile uint32_t CTL2;
    volatile uint32_t HFOSCCAL0;
    volatile uint32_t HFOSCCAL1;
}OSC_SFRmap;


typedef struct PLL_MemMap {
   volatile uint32_t CTL;
}PLL_SFRmap;
# 1450 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct INT_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t EIE0;
             uint32_t RESERVED1;
    volatile uint32_t EIE1;
             uint32_t RESERVED2;
    volatile uint32_t EIE2;
       uint32_t RESERVED3;
    volatile uint32_t EIF0;
             uint32_t RESERVED4;
    volatile uint32_t EIF1;
             uint32_t RESERVED5;
    volatile uint32_t EIF2;
             uint32_t RESERVED6;
    volatile uint32_t IP0;
    volatile uint32_t IP1;
    volatile uint32_t IP2;
    volatile uint32_t IP3;
    volatile uint32_t IP4;
    volatile uint32_t IP5;
    volatile uint32_t IP6;
    volatile uint32_t IP7;
    volatile uint32_t IP8;
    volatile uint32_t IP9;
    volatile uint32_t IP10;
    volatile uint32_t IP11;
    volatile uint32_t IP12;
    volatile uint32_t IP13;
    volatile uint32_t IP14;
    volatile uint32_t IP15;
    volatile uint32_t IP16;
    volatile uint32_t IP17;
    volatile uint32_t IP18;
    volatile uint32_t EINTMASK;
    volatile uint32_t EINTRISE;
    volatile uint32_t EINTFALL;
    volatile uint32_t EINTF;
             uint32_t RESERVED7;
    volatile uint32_t EINTSS0;
    volatile uint32_t EINTSS1;
    volatile uint32_t CTL1;
}INT_SFRmap;
# 3317 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct SYSCTL_MemMap {
    volatile uint32_t PSW;
    volatile uint32_t MCTL;
    volatile uint32_t ARCTL;
    volatile uint32_t VECTOFF;
          uint32_t RESEVRVE1;
    volatile uint32_t RAMSPA;
    volatile uint32_t MEMCTL;
}SYSCTL_SFRmap;
# 3406 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct ADC_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t SCANSQ0;
    volatile uint32_t SCANSQ1;
    volatile uint32_t SCANSQ2;
    volatile uint32_t HSCANSQ;
    volatile uint32_t WDH;
    volatile uint32_t WDL;
    volatile const uint32_t DATA;
    volatile const uint32_t HPDATA0;
    volatile const uint32_t HPDATA1;
    volatile const uint32_t HPDATA2;
    volatile const uint32_t HPDATA3;
    volatile uint32_t HPOFF0;
    volatile uint32_t HPOFF1;
    volatile uint32_t HPOFF2;
    volatile uint32_t HPOFF3;
    volatile uint32_t SCANSQ3;
                   uint32_t RESERVED[2];
    volatile uint32_t STATE;
    volatile uint32_t DELAY;
}ADC_SFRmap;

typedef struct ADC_Delay_MemMap
{
    volatile uint32_t DELAY;
}ADC_DELAY_SFRmap;
# 4066 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct DMA_MemMap {
    union {
        struct
        {
            volatile uint32_t CTLR1;
            volatile uint32_t CTLR2;
            volatile uint32_t CTLR3;
            volatile uint32_t CTLR4;
            volatile uint32_t CTLR5;
            volatile uint32_t CTLR6;
            volatile uint32_t CTLR7;
        };
        volatile uint32_t CTLR[7];
    };
                   uint32_t RESERVED1;
    union {
        struct
        {
            volatile uint32_t PADDR1;
            volatile uint32_t PADDR2;
            volatile uint32_t PADDR3;
            volatile uint32_t PADDR4;
            volatile uint32_t PADDR5;
            volatile uint32_t PADDR6;
            volatile uint32_t PADDR7;
        };
        volatile uint32_t PADDR[7];
    };
                   uint32_t RESERVED2;
    union {
        struct
        {
            volatile uint32_t MADDR1;
            volatile uint32_t MADDR2;
            volatile uint32_t MADDR3;
            volatile uint32_t MADDR4;
            volatile uint32_t MADDR5;
            volatile uint32_t MADDR6;
            volatile uint32_t MADDR7;
        };
        volatile uint32_t MADDR[7];
    };
                   uint32_t RESERVED3;
    union {
        struct
        {
            volatile const uint32_t CPAR1;
            volatile const uint32_t CPAR2;
            volatile const uint32_t CPAR3;
            volatile const uint32_t CPAR4;
            volatile const uint32_t CPAR5;
            volatile const uint32_t CPAR6;
            volatile const uint32_t CPAR7;
        };
        volatile const uint32_t CPAR[7];
    };
                   uint32_t RESERVED4;
    union {
        struct
        {
            volatile const uint32_t CMAR1;
            volatile const uint32_t CMAR2;
            volatile const uint32_t CMAR3;
            volatile const uint32_t CMAR4;
            volatile const uint32_t CMAR5;
            volatile const uint32_t CMAR6;
            volatile const uint32_t CMAR7;
        };
        volatile const uint32_t CMAR[7];
    };
                   uint32_t RESERVED5;
    union {
        struct
        {
            volatile const uint32_t NCT1;
            volatile const uint32_t NCT2;
            volatile const uint32_t NCT3;
            volatile const uint32_t NCT4;
            volatile const uint32_t NCT5;
            volatile const uint32_t NCT6;
            volatile const uint32_t NCT7;
        };
        volatile const uint32_t NCT[7];
    };
                   uint32_t RESERVED6;
    volatile uint32_t LIFR;
    volatile uint32_t LIER;
}DMA_SFRmap;
# 4721 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct SYSTICK_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t RELOAD;
    volatile uint32_t CV;
    volatile uint32_t CALI;
}SYSTICK_SFRmap;
# 4775 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct BTIM_MemMap {
    volatile uint32_t CNT;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t PRSC;
    volatile uint32_t PPX;
    volatile uint32_t DIER;
    volatile const uint32_t SR;
    volatile uint32_t SRIC;
}BTIM_SFRmap;
# 4963 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct GPTIM_MemMap {
    volatile uint32_t CNT;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t PRSC;
    volatile uint32_t PPX;
    volatile uint32_t UDTIM;
                   uint32_t RESERVED1[2];
    volatile const uint32_t CCPXC1;
    volatile const uint32_t CCPXC2;
    volatile const uint32_t CCPXC3;
    volatile const uint32_t CCPXC4;
    volatile uint32_t CCPXSRIC;
    volatile const uint32_t CCPXDF;
                   uint32_t RESERVED2[2];
    volatile uint32_t CCPXCTL1;
    volatile uint32_t CCPXR1;
    volatile uint32_t CCPXR2;
    volatile uint32_t CCPXR3;
    volatile uint32_t CCPXR4;
    volatile uint32_t CCPXCTL2;
    volatile uint32_t CCPXCTL3;
    volatile uint32_t CCPXEGIF;
}GPTIM_SFRmap, CCP_SFRmap;
# 5573 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct ATIM_MemMap {
    volatile uint32_t TXCNT;
    volatile uint32_t TZCNT;
    volatile uint32_t TXPPX;
    volatile uint32_t TZPPZ;
    volatile uint32_t TXPRSC;
    volatile uint32_t TZPRSC;
    volatile uint32_t TXCCR0;
    volatile uint32_t TXCCR1;
    volatile uint32_t TZCCR0;
    volatile uint32_t TXCTL;
    volatile uint32_t TZCTL;
    volatile uint32_t PXPDCTL;
    volatile uint32_t PXASCTL;
          uint32_t RESERVED1[19];
    volatile uint32_t ECCPXCTL1;
    volatile uint32_t ECCPXR1;
    volatile uint32_t ECCPXR2;
    volatile uint32_t ECCPXR3;
    volatile uint32_t ECCPXR4;
    volatile uint32_t PXUDCTL;
    volatile uint32_t ECCPXCTL2;
    volatile uint32_t PXDTCTL;
    volatile uint32_t PWMXOC;
    volatile uint32_t PXATRCTL;
    volatile uint32_t PXASCTL0;
    volatile uint32_t PXASCTL1;
    volatile uint32_t ZPDCTL0;
    volatile uint32_t ZPDCTL1;
    volatile uint32_t ZPDPORT;
    volatile uint32_t ECCPXIE;
    volatile uint32_t ECCPXEGIF;
    volatile uint32_t TXUDTIM;
    volatile uint32_t TZUDTIM;
    volatile const uint32_t ECCPXDF;
    volatile const uint32_t ECCPXC1;
    volatile const uint32_t ECCPXC2;
    volatile const uint32_t ECCPXC3;
    volatile const uint32_t ECCPXC4;
                   uint32_t RESERVED2;
    volatile uint32_t ECCPXDE;
    volatile uint32_t ECCPXSRIC;
    volatile uint32_t ECCPXCTL3;
}ATIM_SFRmap, ECCP_SFRmap;
# 6302 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct QEI_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CNT;
    volatile uint32_t PPX;
    volatile uint32_t PRSC;
    volatile uint32_t DIER;
}QEI_SFRmap;
# 6420 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct DAC_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t DAHD;
    volatile const uint32_t DATA;
    volatile uint32_t CTL1;
                   uint32_t RESERVED;
    volatile uint32_t CAL;
}DAC_SFRmap;
# 6573 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct CMP_MemMap {
    volatile uint32_t CTL;





}CMP_SFRmap;
# 8136 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct RTC_MemMap {
    volatile uint32_t CR;
    volatile uint32_t ALRA;
    volatile uint32_t TMR;
    volatile uint32_t DTR;
    volatile uint32_t ALRB;
    volatile uint32_t TMER;
    volatile uint32_t TCR;
    volatile uint32_t IER;
    volatile uint32_t IFR;
    volatile uint32_t TMBR;
    volatile uint32_t DTBR;
}RTC_SFRmap;
# 8679 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct IWDT_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t FD;
}IWDT_SFRmap;
# 8712 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct WWDT_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t CNT;
}WWDT_SFRmap;
# 8752 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct RST_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}RST_SFRmap;
# 9132 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct PCLK_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}PCLK_SFRmap;
# 9512 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct SPI_MemMap {
    volatile uint32_t BRGR;
    volatile uint32_t CTLR;
    volatile uint32_t BUFR;
    volatile uint32_t STR;
}SPI_SFRmap;
# 9672 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct I2C_MemMap {
    volatile uint32_t CTLR;
    volatile uint32_t SR;
    volatile uint32_t BUFR;
    volatile uint32_t ADDR0;
    volatile uint32_t BRGR;
    volatile uint32_t ADDR1;
    volatile uint32_t ADDR2;
    volatile uint32_t ADDR3;
    volatile uint32_t IER;
    volatile uint32_t TPSR;
}I2C_SFRmap;
# 9934 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct USART_MemMap {
    volatile uint32_t CTLR;
    volatile uint32_t BRGR;
    volatile uint32_t STR;
    union {
        volatile uint32_t TBUFR;
        volatile const uint32_t RBUFR;
    };
    volatile uint32_t U7816R;
    volatile uint32_t IER;
    volatile uint32_t ADM;
}USART_SFRmap;
# 11943 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct CAN_MemMap {
    volatile uint32_t CTLR;
    volatile uint32_t BRGR;
    volatile const uint32_t RCR;
    volatile uint32_t EROR;
    volatile uint32_t ACRR;
    volatile uint32_t MSKR;
    volatile uint32_t IER;
    volatile uint32_t IFR;
    volatile uint32_t INFR;
    volatile uint32_t TX0R;
    volatile uint32_t TX1R;
    volatile uint32_t TX2R;
}CAN_SFRmap;
# 12722 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct PM_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile const uint32_t STA0;
    volatile const uint32_t STA1;
    volatile uint32_t STAC;
    volatile uint32_t CTL2;
    volatile uint32_t CAL0;
    volatile uint32_t CAL1;
    volatile uint32_t CAL2;
}PM_SFRmap;
# 13117 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct BKP_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t INT;
             uint32_t RESERVED[14];
    volatile uint32_t DATA[32];
}BKP_SFRmap;
# 13223 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct FLASH_MemMap {
    volatile uint32_t ISPCON0;
    volatile uint32_t ISPCON1;
    volatile uint32_t ISPCMD;
    volatile uint32_t ISPTRG;
             uint32_t RESERVED1;
    volatile uint32_t CFG;
             uint32_t RESERVED2;
    volatile uint32_t ISPADDR;
    volatile uint32_t STATE;
             uint32_t RESERVED3;
    volatile uint32_t NVMUNLOCK;
    volatile uint32_t PROUNLOCK;
    volatile uint32_t CFGUNLOCK;
             uint32_t RESERVED4;
    volatile uint32_t CSSTART;
    volatile uint32_t CSSTOP;
    volatile uint32_t CSRES[4];
}FLASH_SFRmap;
# 13421 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct CRC_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t DATA;
    volatile uint32_t RSLT;
    volatile uint32_t INIT;
    volatile uint32_t PLN;
    volatile uint32_t RXOR;
    volatile uint32_t IDATA;
    volatile uint32_t TEMP;
}CRC_SFRmap;
# 13471 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct AES_MemMap {
    volatile uint32_t CTL;
       uint32_t RESERVED1;
       uint32_t RESERVED2;
       uint32_t RESERVED3;
    volatile uint32_t KEY0;
    volatile uint32_t KEY1;
    volatile uint32_t KEY2;
    volatile uint32_t KEY3;
    volatile uint32_t INPUT0;
    volatile uint32_t INPUT1;
    volatile uint32_t INPUT2;
    volatile uint32_t INPUT3;
    volatile uint32_t OUTPUT0;
    volatile uint32_t OUTPUT1;
    volatile uint32_t OUTPUT2;
    volatile uint32_t OUTPUT3;
}AES_SFRmap;
# 13925 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct EXIC_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t STATE;
       uint32_t RESERVED1;
    volatile uint32_t WRITEBUF;
    volatile uint32_t READBUF;

}EXIC_SFRmap;
# 14005 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct CFGL_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t IFR;
}CFGL_SFRmap;
# 14184 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
typedef struct OP_MemMap {
    volatile uint32_t CAL;
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
}OP_SFRmap;
# 14358 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/KF32A_BASIC.h"
static inline uint32_t
SFR_Config (uint32_t SfrMem, uint32_t SfrMask, uint32_t WriteVal)
{
    return ((SfrMem & SfrMask) | (WriteVal));
}
# 15 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/kf32a_basic_int.h" 2
# 24 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/kf32a_basic_int.h"
typedef struct
{
    uint32_t m_Line;

    FunctionalState m_Mask;

    FunctionalState m_Rise;

    FunctionalState m_Fall;

    uint32_t m_Source;

} EINT_InitTypeDef;
# 143 "D:/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/system/inc/kf32a_basic_int.h"
uint8_t INT_Get_Interrupt_Action (void);
uint8_t INT_Get_Priority_Pending_Action (void);
void INT_Priority_Base (uint8_t PriBase);
uint8_t INT_Get_Priority_Base (void);
void INT_Stack_Align_Config (uint32_t StackAlign);
void INT_Fault_Masking_Config (FunctionalState NewState);
FlagStatus INT_Get_Pre_Empty (void);
FlagStatus INT_Get_Pending_Flag (void);
void INT_Priority_Group_Config (uint32_t PriorityGroup);
uint32_t INT_Get_Priority_Group (void);
void INT_All_Enable (FunctionalState NewState);
void INT_Interrupt_Enable (InterruptIndex Peripheral,
                    FunctionalState NewState);
void INT_Set_Systick_Flag (void);
void INT_Set_PendSV_Flag (void);
FlagStatus INT_Get_Interrupt_Flag (InterruptIndex Peripheral);
void INT_Clear_Interrupt_Flag (InterruptIndex Peripheral);
void INT_Interrupt_Priority_Config (InterruptIndex Peripheral,
                    uint32_t Preemption, uint32_t SubPriority);
void INT_Set_Interrupt_Priority(InterruptIndex Peripheral, uint32_t Priority);
void INT_Stack_Delay_Enable (uint8_t IntDelay);
void INT_Vector_Offset_Config (uint32_t VectorOffset);

void INT_External_Configuration (EINT_InitTypeDef* eintInitStruct);
void INT_External_Struct_Init (EINT_InitTypeDef* eintInitStruct);

void INT_External_Mask_Enable (uint32_t EintMask, FunctionalState NewState);
void INT_External_Rise_Enable (uint32_t EintMask, FunctionalState NewState);
void INT_External_Fall_Enable (uint32_t EintMask, FunctionalState NewState);
FlagStatus INT_Get_External_Flag (uint32_t EintNum);
void INT_External_Clear_Flag (uint32_t EintNum);
void INT_External_Source_Enable (uint32_t EintNum, uint32_t PeripheralSource);
# 16 "../system/src/kf32a_basic_int.c" 2
# 33 "../system/src/kf32a_basic_int.c"
uint8_t
INT_Get_Interrupt_Action (void)
{
    uint32_t tmpreg = 0;


    tmpreg = (((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0);
    tmpreg &= ((uint32_t)0x7F<<((24)));
    tmpreg >>= (24);

    return (uint8_t)tmpreg;
}






uint8_t
INT_Get_Priority_Pending_Action (void)
{
    uint32_t tmpreg = 0;


    tmpreg = (((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0);
    tmpreg &= ((uint32_t)0x7F<<((16)));
    tmpreg >>= (16);

    return (uint8_t)tmpreg;
}






void
INT_Priority_Base (uint8_t PriBase)
{
    uint32_t tmpreg = 0;

    ((void)0);



    tmpreg = (uint32_t)PriBase << (12);
    (((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0) = SFR_Config ((((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0),
                          ~((uint32_t)0xF<<((12))),
                          tmpreg);
}






uint8_t
INT_Get_Priority_Base (void)
{
    uint32_t tmpreg = 0;


    tmpreg = (((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0);
    tmpreg &= ((uint32_t)0xF<<((12)));
    tmpreg >>= (12);

    return (uint8_t)tmpreg;
}
# 110 "../system/src/kf32a_basic_int.c"
void
INT_Stack_Align_Config (uint32_t StackAlign)
{
    ((void)0);


    if (StackAlign != ((uint32_t)0<<((7))))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0))),"i"((7)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0))),"i"((7)));
    }
}







void
INT_Fault_Masking_Config (FunctionalState NewState)
{
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0))),"i"((6)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0))),"i"((6)));
    }
}






FlagStatus
INT_Get_Pre_Empty (void)
{
    uint32_t tmpreg = 0;


    tmpreg = (((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0);
    if (tmpreg & ((uint32_t)1<<((5))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus
INT_Get_Pending_Flag (void)
{
    uint32_t tmpreg = 0;


    tmpreg = (((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0);
    if (tmpreg & ((uint32_t)1<<((4))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 210 "../system/src/kf32a_basic_int.c"
void
INT_Priority_Group_Config (uint32_t PriorityGroup)
{
    ((void)0);



    (((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0) = SFR_Config ((((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0),
                          ~((uint32_t)3<<((1))),
                          PriorityGroup);
}






uint32_t
INT_Get_Priority_Group (void)
{
    uint32_t tmpreg = 0;


    tmpreg = (((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0);
    tmpreg &= ((uint32_t)3<<((1)));

    return tmpreg;
}







void
INT_All_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0))),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0))),"i"((0)));
    }
}
# 273 "../system/src/kf32a_basic_int.c"
void
INT_Interrupt_Enable (InterruptIndex Peripheral, FunctionalState NewState)
{
    uint32_t tmpreg = 0;
    uint32_t tmpreg1 = 0;


    ((void)0);
    ((void)0);

    if (Peripheral <= INT_SysTick)
    {

        tmpreg = Peripheral - INT_StackFault;
        tmpreg1 = ((uint32_t)1<<((5))) << tmpreg;
        (((INT_SFRmap *) ((uint32_t)0x40200000))->EIE0) = SFR_Config ((((INT_SFRmap *) ((uint32_t)0x40200000))->EIE0),
                          ~tmpreg1,
                          NewState << (tmpreg+5));
    }
    else if (Peripheral <= INT_SPI1)
    {

        tmpreg = Peripheral - INT_WWDT;
        tmpreg1 = ((uint32_t)1<<((0))) << tmpreg;
        (((INT_SFRmap *) ((uint32_t)0x40200000))->EIE1) = SFR_Config ((((INT_SFRmap *) ((uint32_t)0x40200000))->EIE1),
                          ~tmpreg1,
                          NewState << tmpreg);
    }
    else if (Peripheral <= INT_USART7)
    {

        tmpreg = Peripheral - INT_DMA1;
        tmpreg1 = ((uint32_t)1<<((0))) << tmpreg;
        (((INT_SFRmap *) ((uint32_t)0x40200000))->EIE2) = SFR_Config ((((INT_SFRmap *) ((uint32_t)0x40200000))->EIE2),
                          ~tmpreg1,
                          NewState << tmpreg);
    }
    else
    {


    }
}






void
INT_Set_Systick_Flag (void)
{
    __asm volatile("SET [%0], #%1"::"r"(&((((INT_SFRmap *) ((uint32_t)0x40200000))->EIF0))),"i"((15)));
}






void
INT_Set_PendSV_Flag (void)
{
    __asm volatile("SET [%0], #%1"::"r"(&((((INT_SFRmap *) ((uint32_t)0x40200000))->EIF0))),"i"((14)));
}
# 346 "../system/src/kf32a_basic_int.c"
FlagStatus
INT_Get_Interrupt_Flag (InterruptIndex Peripheral)
{
    uint32_t tmpreg = 0;
    uint32_t tmpreg1 = 0;


    ((void)0);

    if (Peripheral <= INT_SysTick)
    {

        tmpreg = ((uint32_t)1<<((2))) << (Peripheral - INT_NMI);
        tmpreg1 = (((INT_SFRmap *) ((uint32_t)0x40200000))->EIF0);
        if ((((INT_SFRmap *) ((uint32_t)0x40200000))->EIF0) & tmpreg)
        {

            return SET;
        }
        else
        {

            return RESET;
        }
    }
    else if (Peripheral <= INT_SPI1)
    {

        tmpreg = ((uint32_t)1<<((0))) << (Peripheral - INT_WWDT);
        tmpreg1 = (((INT_SFRmap *) ((uint32_t)0x40200000))->EIF1);
        if ((((INT_SFRmap *) ((uint32_t)0x40200000))->EIF1) & tmpreg)
        {

            return SET;
        }
        else
        {

            return RESET;
        }
    }
    else if (Peripheral <= INT_USART7)
    {

        tmpreg = ((uint32_t)1<<((0))) << (Peripheral - INT_DMA1);
        tmpreg1 = (((INT_SFRmap *) ((uint32_t)0x40200000))->EIF2);

    }
    else
    {


    }


    if ((*(volatile uint32_t*)tmpreg1) & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






void
INT_Clear_Interrupt_Flag (InterruptIndex Peripheral)
{
    uint32_t tmpreg = 0;
    volatile uint32_t *tmpreg1 = 0;


    ((void)0);

    if (Peripheral <= INT_SysTick)
    {

        tmpreg = ((uint32_t)1<<((2))) << (Peripheral - INT_NMI);
        tmpreg1 = &(((INT_SFRmap *) ((uint32_t)0x40200000))->EIF0);
    }
    else if (Peripheral <= INT_SPI1)
    {

        tmpreg = ((uint32_t)1<<((0))) << (Peripheral - INT_WWDT);
        tmpreg1 = &(((INT_SFRmap *) ((uint32_t)0x40200000))->EIF1);
    }
    else if (Peripheral <= INT_USART7)
    {

        tmpreg = ((uint32_t)1<<((0))) << (Peripheral - INT_DMA1);
        tmpreg1 = &(((INT_SFRmap *) ((uint32_t)0x40200000))->EIF2);
    }
    else
    {


    }



    *tmpreg1 &= ~tmpreg;

}
# 470 "../system/src/kf32a_basic_int.c"
void
INT_Interrupt_Priority_Config (InterruptIndex Peripheral,
                    uint32_t Preemption, uint32_t SubPriority)
{
    uint32_t tmpreg = 0;
    uint32_t regoffset = 0;
    uint32_t bitoffset = 0;
    uint32_t priorityconfig = 0;


    tmpreg = (((INT_SFRmap *) ((uint32_t)0x40200000))->CTL0);
    tmpreg &= ((uint32_t)3<<((1)));


    ((void)0);
    ((void)0);


    switch (tmpreg)
    {
    case ((uint32_t)0<<((1))):
        priorityconfig = (Preemption << 1) | (SubPriority & 0x1);
        break;
    case ((uint32_t)1<<((1))):
        priorityconfig = (Preemption << 2) | (SubPriority & 0x3);
        break;
    case ((uint32_t)2<<((1))):
        priorityconfig = (Preemption << 3) | (SubPriority & 0x7);
        break;
    case ((uint32_t)3<<((1))):
        priorityconfig = SubPriority & 0xF;
        break;
    default:
        ((void)0);
        break;
    }


    if (Peripheral <= INT_USART7)
    {


        regoffset = (Peripheral - INT_Reserved4) >> 2;
        tmpreg = (uint32_t)&(((INT_SFRmap *) ((uint32_t)0x40200000))->IP0);
        tmpreg = tmpreg + (regoffset << 2);
    }
    else
    {
    }


    bitoffset = ((Peripheral & 0x3) * 8) + 4;
    *(volatile uint32_t*)tmpreg
          = SFR_Config (*(volatile uint32_t*)tmpreg,
                      ~(((uint32_t)0xF) << bitoffset),
                      priorityconfig << bitoffset);
}
# 538 "../system/src/kf32a_basic_int.c"
void
INT_Set_Interrupt_Priority(InterruptIndex Peripheral, uint32_t Priority)
{
    uint32_t tmpreg = 0;
    uint32_t regoffset = 0;
    uint32_t bitoffset = 0;

    regoffset = (Peripheral - INT_Reserved4) >> 2;
    tmpreg = (uint32_t)&(((INT_SFRmap *) ((uint32_t)0x40200000))->IP0);
    tmpreg = tmpreg + (regoffset << 2);
    bitoffset = ((Peripheral & 0x3) << 0X03) + 4;
    *(volatile uint32_t*)tmpreg
               = SFR_Config (*(volatile uint32_t*)tmpreg,
               ~((uint32_t)0x0f << bitoffset),
               Priority << bitoffset);
}







void
INT_Stack_Delay_Enable (uint8_t IntDelay)
{

    (((INT_SFRmap *) ((uint32_t)0x40200000))->CTL1) = SFR_Config ((((INT_SFRmap *) ((uint32_t)0x40200000))->CTL1),
                      ~(((uint32_t)0xFF<<((0)))),
                      (uint32_t)IntDelay << (0));
}
# 582 "../system/src/kf32a_basic_int.c"
void
INT_External_Configuration (EINT_InitTypeDef* eintInitStruct)
{
    uint32_t eintoffset = 0;
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);

    eintoffset = eintInitStruct->m_Line;



    (((INT_SFRmap *) ((uint32_t)0x40200000))->EINTRISE) = SFR_Config ((((INT_SFRmap *) ((uint32_t)0x40200000))->EINTRISE),
                          ~(((uint32_t)1<<((0))) << eintoffset),
                          eintInitStruct->m_Rise << eintoffset);




    (((INT_SFRmap *) ((uint32_t)0x40200000))->EINTFALL) = SFR_Config ((((INT_SFRmap *) ((uint32_t)0x40200000))->EINTFALL),
                          ~(((uint32_t)1<<((0))) << eintoffset),
                          eintInitStruct->m_Fall << eintoffset);




    if (eintoffset < 8)
    {
        tmpreg = eintInitStruct->m_Line * 4;
        (((INT_SFRmap *) ((uint32_t)0x40200000))->EINTSS0) = SFR_Config ((((INT_SFRmap *) ((uint32_t)0x40200000))->EINTSS0),
                          ~(((uint32_t)0x7) << tmpreg),
                          eintInitStruct->m_Source << tmpreg);
    }
    else if (eintoffset < 16)
    {
        tmpreg = (eintInitStruct->m_Line - 8) * 4;
        (((INT_SFRmap *) ((uint32_t)0x40200000))->EINTSS1) = SFR_Config ((((INT_SFRmap *) ((uint32_t)0x40200000))->EINTSS1),
                          ~(((uint32_t)0x7) << tmpreg),
                          eintInitStruct->m_Source << tmpreg);
    }
    else
    {
    }




    (((INT_SFRmap *) ((uint32_t)0x40200000))->EINTMASK) = SFR_Config ((((INT_SFRmap *) ((uint32_t)0x40200000))->EINTMASK),
                          ~(((uint32_t)1<<((0))) << eintoffset),
                          eintInitStruct->m_Mask << eintoffset);
}






void
INT_External_Struct_Init (EINT_InitTypeDef* eintInitStruct)
{

    eintInitStruct->m_Line = ((uint32_t)0);

    eintInitStruct->m_Mask = FALSE;

    eintInitStruct->m_Rise = FALSE;

    eintInitStruct->m_Fall = FALSE;

    eintInitStruct->m_Source = ((uint32_t)0);
}
# 674 "../system/src/kf32a_basic_int.c"
void
INT_External_Mask_Enable (uint32_t EintMask, FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {
        (((INT_SFRmap *) ((uint32_t)0x40200000))->EINTMASK) |= EintMask;
    }
    else
    {
        (((INT_SFRmap *) ((uint32_t)0x40200000))->EINTMASK) &= ~EintMask;
    }
}
# 699 "../system/src/kf32a_basic_int.c"
void
INT_External_Rise_Enable (uint32_t EintMask, FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {
        (((INT_SFRmap *) ((uint32_t)0x40200000))->EINTRISE) |= EintMask;
    }
    else
    {
        (((INT_SFRmap *) ((uint32_t)0x40200000))->EINTRISE) &= ~EintMask;
    }
}
# 724 "../system/src/kf32a_basic_int.c"
void
INT_External_Fall_Enable (uint32_t EintMask, FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {
        (((INT_SFRmap *) ((uint32_t)0x40200000))->EINTFALL) |= EintMask;
    }
    else
    {
        (((INT_SFRmap *) ((uint32_t)0x40200000))->EINTFALL) &= ~EintMask;
    }
}
# 749 "../system/src/kf32a_basic_int.c"
FlagStatus
INT_Get_External_Flag (uint32_t EintNum)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = ((uint32_t)1<<((0))) << EintNum;
    if ((((INT_SFRmap *) ((uint32_t)0x40200000))->EINTF) & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 779 "../system/src/kf32a_basic_int.c"
void
INT_External_Clear_Flag (uint32_t EintNum)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = ((uint32_t)1<<((0))) << EintNum;
    while(((((INT_SFRmap *) ((uint32_t)0x40200000))->EINTF) & tmpreg)>>(EintNum+(0)))
    {
     (((INT_SFRmap *) ((uint32_t)0x40200000))->EINTF) &= ~tmpreg;
    }
}
# 819 "../system/src/kf32a_basic_int.c"
void
INT_External_Source_Enable (uint32_t EintNum, uint32_t PeripheralSource)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = (EintNum % 8) * 4;
    if (EintNum < 8)
    {
        (((INT_SFRmap *) ((uint32_t)0x40200000))->EINTSS0) = SFR_Config ((((INT_SFRmap *) ((uint32_t)0x40200000))->EINTSS0),
                          ~(((uint32_t)0x7) << tmpreg),
                          PeripheralSource << tmpreg);
    }
    else if (EintNum < 16)
    {
        (((INT_SFRmap *) ((uint32_t)0x40200000))->EINTSS1) = SFR_Config ((((INT_SFRmap *) ((uint32_t)0x40200000))->EINTSS1),
                          ~(((uint32_t)0x7) << tmpreg),
                          PeripheralSource << tmpreg);
    }
    else
    {
    }
}
