# 1 "../system/src/kf32a_basic_adc.c"
# 1 "/cygdrive/h/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/Release//"
# 1 "<command-line>"
# 1 "../system/src/kf32a_basic_adc.c"
# 18 "../system/src/kf32a_basic_adc.c"
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_adc.h" 1
# 15 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_adc.h"
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h" 1
# 20 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 21 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_Config.h" 1
# 15 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_Config.h"
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/__Kungfu32_chipmodel_define.h" 1
# 16 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_Config.h" 2
# 22 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h" 2
# 36 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 171 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 1127 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 1450 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 3317 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
typedef struct SYSCTL_MemMap {
    volatile uint32_t PSW;
    volatile uint32_t MCTL;
    volatile uint32_t ARCTL;
    volatile uint32_t VECTOFF;
          uint32_t RESEVRVE1;
    volatile uint32_t RAMSPA;
    volatile uint32_t MEMCTL;
}SYSCTL_SFRmap;
# 3406 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 4066 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 4721 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
typedef struct SYSTICK_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t RELOAD;
    volatile uint32_t CV;
    volatile uint32_t CALI;
}SYSTICK_SFRmap;
# 4775 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 4963 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 5573 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 6302 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
typedef struct QEI_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CNT;
    volatile uint32_t PPX;
    volatile uint32_t PRSC;
    volatile uint32_t DIER;
}QEI_SFRmap;
# 6420 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
typedef struct DAC_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t DAHD;
    volatile const uint32_t DATA;
    volatile uint32_t CTL1;
                   uint32_t RESERVED;
    volatile uint32_t CAL;
}DAC_SFRmap;
# 6573 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
typedef struct CMP_MemMap {
    volatile uint32_t CTL;





}CMP_SFRmap;
# 8136 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 8679 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
typedef struct IWDT_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t FD;
}IWDT_SFRmap;
# 8712 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
typedef struct WWDT_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t CNT;
}WWDT_SFRmap;
# 8752 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
typedef struct RST_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}RST_SFRmap;
# 9132 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
typedef struct PCLK_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}PCLK_SFRmap;
# 9512 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
typedef struct SPI_MemMap {
    volatile uint32_t BRGR;
    volatile uint32_t CTLR;
    volatile uint32_t BUFR;
    volatile uint32_t STR;
}SPI_SFRmap;
# 9672 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 9934 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 11943 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 12722 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 13117 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
typedef struct BKP_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t INT;
             uint32_t RESERVED[14];
    volatile uint32_t DATA[32];
}BKP_SFRmap;
# 13223 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 13421 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 13471 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 13925 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
typedef struct EXIC_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t STATE;
       uint32_t RESERVED1;
    volatile uint32_t WRITEBUF;
    volatile uint32_t READBUF;

}EXIC_SFRmap;
# 14005 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
typedef struct CFGL_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t IFR;
}CFGL_SFRmap;
# 14184 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
typedef struct OP_MemMap {
    volatile uint32_t CAL;
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
}OP_SFRmap;
# 14358 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
static inline uint32_t
SFR_Config (uint32_t SfrMem, uint32_t SfrMask, uint32_t WriteVal)
{
    return ((SfrMem & SfrMask) | (WriteVal));
}
# 16 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_adc.h" 2





typedef struct
{
    uint32_t m_Clock;

    uint32_t m_ClockDiv;

    FunctionalState m_ScanMode;

    uint32_t m_ContinuousMode;

    uint32_t m_DataAlign;

    FunctionalState m_ExternalTrig_EN;

    uint32_t m_ExternalTrig;

    FunctionalState m_HPExternalTrig_EN;

    uint32_t m_HPExternalTrig;

    uint32_t m_VoltageRef;

    uint32_t m_NumOfConv;

    uint32_t m_NumOfHPConv;

}ADC_InitTypeDef;




typedef struct
{
    uint32_t m_FastDelay;

    uint32_t m_SlowDelay;

}ADC0_DELAY_InitTypeDef;




typedef struct
{
    uint32_t m_WDSingleCH;

    FunctionalState m_HPChannelWDEN;

    FunctionalState m_ChannelWDEN;

    uint32_t m_WDChannel;

    uint32_t m_Threshold_H;

    uint32_t m_Threshold_L;

}ADC_WD_InitTypeDef;
# 720 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_adc.h"
void ADC_Reset (ADC_SFRmap* ADCx);
void ADC_Configuration (ADC_SFRmap* ADCx, ADC_InitTypeDef* adcInitStruct);
void ADC_Struct_Init (ADC_InitTypeDef* adcInitStruct);
void ADC_Delay_Configuration (ADC0_DELAY_InitTypeDef* adc0Delay);
void ADC_Delay_Struct_Init (ADC0_DELAY_InitTypeDef* adc0Delay);
void ADC_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);

void ADC_Analog_Watchdog_Configuration (ADC_SFRmap* ADCx,
                    ADC_WD_InitTypeDef * adcAnalogWatchdog);
void ADC_Analog_Watchdog_Struct_Init (ADC_WD_InitTypeDef* adcAnalogWatchdog);

void ADC_Watchdog_Single_Channel_Enable (ADC_SFRmap* ADCx,
                    FunctionalState NewState);
void ADC_Scan_Mode_Enable (ADC_SFRmap* ADCx, FunctionalState NewState);
void ADC_Bosssel_Comparator_Calibration (ADC_SFRmap* ADCx,
                    FunctionalState NewState);
void ADC_Bosssel_Calibration (ADC_SFRmap* ADCx, FunctionalState NewState);
void ADC_Trim_Current_Intensity_Bias (ADC_SFRmap* ADCx,
                    FunctionalState NewState);
void ADC_Analog_Clock_Config (ADC_SFRmap* ADCx, uint32_t ClockSelect);
void ADC_Data_Align_Config (ADC_SFRmap* ADCx, uint32_t DataAlign);
void ADC_Clock_Source_Config (ADC_SFRmap* ADCx, uint32_t ClockSource);
void ADC_Regular_Channel_DMA_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
void ADC_High_Priority_Channel_DMA_Cmd (ADC_SFRmap* ADCx,
     uint32_t HPChannel,FunctionalState NewState);
void ADC_Double_Mode_Config (uint32_t WorkMode);
void ADC_Reference_Voltage_Config (ADC_SFRmap* ADCx, uint32_t RefVoltage);
void ADC_Analog_Watchdog_Channel_Config (ADC_SFRmap* ADCx, uint32_t Channel);

void ADC_Regular_Channel_Watchdog_Enable (ADC_SFRmap* ADCx,
                    FunctionalState NewState);
void ADC_External_Trig_Conv_Enable (ADC_SFRmap* ADCx,
                    FunctionalState NewState);
void ADC_External_Trig_Conv_Config (ADC_SFRmap* ADCx,
                    uint32_t ExternalTrigEvent);
void ADC_Regular_Channel_Config (ADC_SFRmap* ADCx,
                    uint32_t Channel, uint32_t Rank);
void ADC_Regular_Sequencer_Length_Config (ADC_SFRmap* ADCx, uint32_t Length);
void ADC_Regular_Channel_TxCCRy_Trig_Enable (ADC_SFRmap* ADCx,
        uint32_t ExternalTrigEvent, FunctionalState NewState);
void ADC_Software_Start_Conv(ADC_SFRmap* ADCx);
void ADC_Continuous_Mode_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
void ADC_Disc_Mode_Channel_Count_Config (ADC_SFRmap* ADCx, uint8_t Number);
void ADC_Disc_Mode_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
uint16_t ADC_Get_Conversion_Value (ADC_SFRmap* ADCx);

void ADC_High_Priority_Watchdog_Enable (ADC_SFRmap* ADCx,
                    FunctionalState NewState);
void ADC_HPExternal_Trig_Conv_Enable (ADC_SFRmap* ADCx,
                    FunctionalState NewState);
void ADC_High_Priority_Channel_Config (ADC_SFRmap* ADCx,
                    uint32_t Channel, uint32_t Rank);
void ADC_High_Priority_Sequencer_Length_Config (ADC_SFRmap* ADCx,
                    uint32_t Length);
void ADC_Set_HPChannel_Conv_Value_Offset (ADC_SFRmap* ADCx,
                    uint32_t HPDoffChannel, uint32_t Offset);
void ADC_HPExternal_Trig_Conv_Config (ADC_SFRmap* ADCx,
                    uint32_t HPExternalTrigEvent);
void ADC_Software_HPStart_Conv (ADC_SFRmap* ADCx);
void ADC_HPAuto_Conv_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
void ADC_HPDisc_Mode_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState);
uint16_t ADC_Get_HPConversion_Data (ADC_SFRmap* ADCx, uint8_t HPDataChannel);

void ADC_Set_INT_Enable (ADC_SFRmap* ADCx,
                    uint32_t InterruptType, FunctionalState NewState);
FlagStatus ADC_Get_INT_Flag (ADC_SFRmap* ADCx, uint32_t InterruptType);
void ADC_Clear_INT_Flag (ADC_SFRmap* ADCx, uint32_t InterruptType);
INTStatus ADC_Get_INT_Status (ADC_SFRmap* ADCx, uint32_t InterruptType);
# 19 "../system/src/kf32a_basic_adc.c" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_rst.h" 1
# 44 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_rst.h"
void RST_CTL0_Peripheral_Reset_Enable(uint32_t RST_CTL0Periph,
                    FunctionalState NewState);
void RST_CTL1_Peripheral_Reset_Enable(uint32_t RST_CTL1Periph,
                    FunctionalState NewState);
void RST_CTL2_Peripheral_Reset_Enable(uint32_t RST_CTL2Periph,
                    FunctionalState NewState);
void RST_CTL3_Peripheral_Reset_Enable(uint32_t RST_CTL3Periph,
                    FunctionalState NewState);
# 20 "../system/src/kf32a_basic_adc.c" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_pclk.h" 1
# 40 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_pclk.h"
void PCLK_CTL0_Peripheral_Clock_Enable (uint32_t PCLK_CTL0_bit,
                    FunctionalState NewState);
void PCLK_CTL1_Peripheral_Clock_Enable (uint32_t PCLK_CTL1_bit,
                    FunctionalState NewState);
void PCLK_CTL2_Peripheral_Clock_Enable (uint32_t PCLK_CTL2_bit,
                    FunctionalState NewState);
void PCLK_CTL3_Peripheral_Clock_Enable (uint32_t PCLK_CTL3_bit,
                    FunctionalState NewState);
# 21 "../system/src/kf32a_basic_adc.c" 2
# 57 "../system/src/kf32a_basic_adc.c"
void
ADC_Reset (ADC_SFRmap* ADCx)
{

    ((void)0);


    if (ADCx == ((ADC_SFRmap *) ((uint32_t)0x40000580)))
    {
        RST_CTL1_Peripheral_Reset_Enable(((uint32_t)1<<((11))), TRUE);
        RST_CTL1_Peripheral_Reset_Enable(((uint32_t)1<<((11))), FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(((uint32_t)1<<((11))), TRUE);
    }


    if (ADCx == ((ADC_SFRmap *) ((uint32_t)0x40000600)))
    {
        RST_CTL1_Peripheral_Reset_Enable(((uint32_t)1<<((12))), TRUE);
        RST_CTL1_Peripheral_Reset_Enable(((uint32_t)1<<((12))), FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(((uint32_t)1<<((12))), TRUE);
    }


    if (ADCx == ((ADC_SFRmap *) ((uint32_t)0x40000680)))
    {
        RST_CTL1_Peripheral_Reset_Enable(((uint32_t)1<<((13))), TRUE);
        RST_CTL1_Peripheral_Reset_Enable(((uint32_t)1<<((13))), FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(((uint32_t)1<<((13))), TRUE);
    }

}







void
ADC_Configuration (ADC_SFRmap* ADCx, ADC_InitTypeDef* adcInitStruct)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);







    tmpreg = (uint32_t)(adcInitStruct->m_Clock |
                        adcInitStruct->m_ClockDiv |
                        ((uint32_t)adcInitStruct->m_ScanMode << 17) |
                        adcInitStruct->m_ContinuousMode |
                        adcInitStruct->m_DataAlign
                        );
    ADCx->CTL0 = SFR_Config (ADCx->CTL0, ~(((uint32_t)3<<((1))) | ((uint32_t)7<<((8))) | ((uint32_t)1<<((17))) | ((uint32_t)1<<((18))) | ((uint32_t)1<<((3)))), tmpreg);







    tmpreg = (uint32_t)(((uint32_t)adcInitStruct->m_ExternalTrig_EN << 11) |
                         ((uint32_t)adcInitStruct->m_HPExternalTrig_EN << 27) |
                         adcInitStruct->m_ExternalTrig |
                         adcInitStruct->m_HPExternalTrig |
                         adcInitStruct->m_VoltageRef);
    ADCx->CTL1 = SFR_Config (ADCx->CTL1, ~(((uint32_t)1<<((11))) | ((uint32_t)1<<((27))) | ((uint32_t)0x7F<<((4))) | ((uint32_t)0x7F<<((20))) | ((uint32_t)7<<((17)))), tmpreg);



    tmpreg = (adcInitStruct->m_NumOfConv - 1) << 28;
    ADCx->SCANSQ3 = SFR_Config (ADCx->SCANSQ3,
                                  ~((uint32_t)0xF<<((28))),
                                  tmpreg);



    tmpreg = (adcInitStruct->m_NumOfHPConv - 1) << 28;
    ADCx->HSCANSQ = SFR_Config (ADCx->HSCANSQ,
                                  ~((uint32_t)0x3<<((28))),
                                  tmpreg);
}






void
ADC_Struct_Init (ADC_InitTypeDef* adcInitStruct)
{

    adcInitStruct->m_Clock = ((uint32_t)0<<(1));


    adcInitStruct->m_ClockDiv = ((uint32_t)0<<(8));


    adcInitStruct->m_ScanMode = FALSE;


    adcInitStruct->m_ContinuousMode = ((uint32_t)0<<(18));


    adcInitStruct->m_DataAlign = ((uint32_t)0<<(3));


    adcInitStruct->m_ExternalTrig_EN = FALSE;


    adcInitStruct->m_ExternalTrig = ((uint32_t)0x0<<(4));


    adcInitStruct->m_HPExternalTrig_EN = FALSE;


    adcInitStruct->m_HPExternalTrig = ((uint32_t)0x0<<(20));


    adcInitStruct->m_VoltageRef = ((uint32_t)1<<(17));


    adcInitStruct->m_NumOfConv = 1;


    adcInitStruct->m_NumOfHPConv = 1;
}






void
ADC_Delay_Configuration (ADC0_DELAY_InitTypeDef* adc0Delay)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);




    tmpreg = (((uint32_t)(adc0Delay->m_SlowDelay - 1) << 16) |
              ((uint32_t)(adc0Delay->m_FastDelay - 1)));

    (((ADC_DELAY_SFRmap *) ((uint32_t)0x400005D4))->DELAY) = SFR_Config ((((ADC_DELAY_SFRmap *) ((uint32_t)0x400005D4))->DELAY),
                               ~(((uint32_t)0x3F<<((0))) | ((uint32_t)0x3F<<((16)))),
                               tmpreg);

}






void
ADC_Delay_Struct_Init (ADC0_DELAY_InitTypeDef* adc0Delay)
{

    adc0Delay->m_FastDelay = 0x06;


    adc0Delay->m_SlowDelay = 0x0D;
}







void
ADC_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);

    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((0)));
    }
}
# 281 "../system/src/kf32a_basic_adc.c"
void
ADC_Analog_Watchdog_Configuration (ADC_SFRmap* ADCx,
                    ADC_WD_InitTypeDef * adcAnalogWatchdog)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);





    tmpreg = (uint32_t)(adcAnalogWatchdog->m_WDSingleCH |
                  ((uint32_t)adcAnalogWatchdog->m_HPChannelWDEN << 30) |
                  ((uint32_t)adcAnalogWatchdog->m_ChannelWDEN << 29));
    ADCx->CTL0 = SFR_Config (ADCx->CTL0,
                               ~(((uint32_t)1<<((31))) | ((uint32_t)1<<((30))) | ((uint32_t)1<<((29)))),
                               tmpreg);



    tmpreg = adcAnalogWatchdog->m_WDChannel;
    ADCx->SCANSQ3 = SFR_Config (ADCx->SCANSQ3,
                               ~((uint32_t)0x3F<<((20))),
                               tmpreg);



    tmpreg = adcAnalogWatchdog->m_Threshold_H;
    ADCx->WDH = SFR_Config (ADCx->WDH,
                              ~((uint32_t)0xFFF<<((0))),
                              tmpreg);



    tmpreg = adcAnalogWatchdog->m_Threshold_L;
    ADCx->WDL = SFR_Config (ADCx->WDL,
                              ~((uint32_t)0xFFF<<((0))),
                              tmpreg);
}






void
ADC_Analog_Watchdog_Struct_Init (ADC_WD_InitTypeDef* adcAnalogWatchdog)
{

    adcAnalogWatchdog->m_WDSingleCH = ((uint32_t)0<<(31));


    adcAnalogWatchdog->m_HPChannelWDEN = FALSE;


    adcAnalogWatchdog->m_ChannelWDEN = FALSE;


    adcAnalogWatchdog->m_WDChannel = ((uint32_t)0<<(20));


    adcAnalogWatchdog->m_Threshold_H = 0x0;


    adcAnalogWatchdog->m_Threshold_L = 0x0;
}
# 369 "../system/src/kf32a_basic_adc.c"
void
ADC_Watchdog_Single_Channel_Enable (ADC_SFRmap* ADCx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((31)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((31)));
    }
}







void
ADC_Scan_Mode_Enable (ADC_SFRmap* ADCx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((17)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((17)));
    }
}







void
ADC_Bosssel_Comparator_Calibration (ADC_SFRmap* ADCx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((16)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((16)));
    }
}







void
ADC_Bosssel_Calibration (ADC_SFRmap* ADCx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((15)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((15)));
    }
}







void
ADC_Trim_Current_Intensity_Bias (ADC_SFRmap* ADCx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((14)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((14)));
    }
}
# 506 "../system/src/kf32a_basic_adc.c"
void
ADC_Analog_Clock_Config (ADC_SFRmap* ADCx, uint32_t ClockSelect)
{

    ((void)0);
    ((void)0);


    ADCx->CTL0 = SFR_Config (ADCx->CTL0,
                               ~((uint32_t)7<<((8))),
                               ClockSelect);
}
# 527 "../system/src/kf32a_basic_adc.c"
void
ADC_Data_Align_Config (ADC_SFRmap* ADCx, uint32_t DataAlign)
{

    ((void)0);
    ((void)0);


    ADCx->CTL0 = SFR_Config (ADCx->CTL0,
                               ~((uint32_t)1<<((3))),
                               DataAlign);
}
# 549 "../system/src/kf32a_basic_adc.c"
void
ADC_Clock_Source_Config (ADC_SFRmap* ADCx, uint32_t ClockSource)
{

    ((void)0);
    ((void)0);


    ADCx->CTL0 = SFR_Config (ADCx->CTL0,
                               ~((uint32_t)3<<((1))),
                               ClockSource);
}







void
ADC_Regular_Channel_DMA_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);

    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((13)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((13)));
    }
}
# 598 "../system/src/kf32a_basic_adc.c"
void
ADC_High_Priority_Channel_DMA_Cmd (ADC_SFRmap* ADCx,
     uint32_t HPChannel,FunctionalState NewState)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {
     ADCx->CTL0 |= HPChannel;
    }
    else
    {
     ADCx->CTL0 &= ~HPChannel;
    }
}
# 631 "../system/src/kf32a_basic_adc.c"
void
ADC_Double_Mode_Config (uint32_t WorkMode)
{

    ((void)0);



    (((ADC_SFRmap *) ((uint32_t)0x40000580))->CTL1) = SFR_Config ((((ADC_SFRmap *) ((uint32_t)0x40000580))->CTL1),
                               ~((uint32_t)0xF<<((28))),
                               WorkMode);

}
# 654 "../system/src/kf32a_basic_adc.c"
void
ADC_Reference_Voltage_Config (ADC_SFRmap* ADCx, uint32_t RefVoltage)
{

    ((void)0);
    ((void)0);


    ADCx->CTL1 = SFR_Config (ADCx->CTL1,
                               ~((uint32_t)7<<((17))),
                               RefVoltage);
}







void
ADC_Analog_Watchdog_Channel_Config (ADC_SFRmap* ADCx, uint32_t Channel)
{

    ((void)0);
    ((void)0);


    ADCx->SCANSQ3 = SFR_Config (ADCx->SCANSQ3,
                               ~((uint32_t)0x3F<<((20))),
                               Channel);
}
# 699 "../system/src/kf32a_basic_adc.c"
void
ADC_Regular_Channel_Watchdog_Enable (ADC_SFRmap* ADCx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((29)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((29)));
    }
}







void
ADC_External_Trig_Conv_Enable (ADC_SFRmap* ADCx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL1)),"i"((11)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ADCx->CTL1)),"i"((11)));
    }
}
# 821 "../system/src/kf32a_basic_adc.c"
void
ADC_External_Trig_Conv_Config (ADC_SFRmap* ADCx,
                    uint32_t ExternalTrigEvent)
{

    ((void)0);
    ((void)0);


    ADCx->CTL1 = SFR_Config (ADCx->CTL1,
                               ~((uint32_t)0x7F<<((4))),
                               ExternalTrigEvent);
}
# 843 "../system/src/kf32a_basic_adc.c"
void
ADC_Regular_Channel_Config (ADC_SFRmap* ADCx, uint32_t Channel, uint32_t Rank)
{
    uint32_t tmpreg = 0;
    uint32_t tmpmask = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    if (Rank < 6)
    {

        tmpreg = (uint32_t)Channel << (6 * (Rank - 1));
        tmpmask = ((uint32_t)0x3F<<((0))) << (6 * (Rank - 1));
        ADCx->SCANSQ0 = SFR_Config (ADCx->SCANSQ0,
                              ~tmpmask,
                              tmpreg);
    }

    else if (Rank < 11)
    {

        tmpreg = (uint32_t)Channel << (6 * (Rank - 6));
        tmpmask = ((uint32_t)0x3F<<((0))) << (6 * (Rank - 6));
        ADCx->SCANSQ1 = SFR_Config (ADCx->SCANSQ1,
                              ~tmpmask,
                              tmpreg);
    }

    else if (Rank < 16)
    {

        tmpreg = (uint32_t)Channel << (6 * (Rank - 11));
        tmpmask = ((uint32_t)0x3F<<((0))) << (6 * (Rank - 11));
        ADCx->SCANSQ2 = SFR_Config (ADCx->SCANSQ2,
                              ~tmpmask,
                              tmpreg);
    }

    else
    {

        tmpreg = (uint32_t)Channel << (6 * (Rank - 16));
        tmpmask = ((uint32_t)0x3F<<((0))) << (6 * (Rank - 16));
        ADCx->SCANSQ3 = SFR_Config (ADCx->SCANSQ3,
                              ~tmpmask,
                              tmpreg);
    }
}







void
ADC_Regular_Sequencer_Length_Config (ADC_SFRmap* ADCx, uint32_t Length)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);



    tmpreg = (Length - 1) << (28);
    ADCx->SCANSQ3 = SFR_Config (ADCx->SCANSQ3,
                          ~((uint32_t)0xF<<((28))),
                          tmpreg);
}
# 932 "../system/src/kf32a_basic_adc.c"
void
ADC_Regular_Channel_TxCCRy_Trig_Enable (ADC_SFRmap* ADCx,
        uint32_t ExternalTrigEvent, FunctionalState NewState)
{
    uint32_t tmpreg = 0;

    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = ExternalTrigEvent;
    tmpreg = (uint32_t)0x01 << tmpreg;

    if (NewState != FALSE)
    {

        ADCx->STATE |= tmpreg;
    }
    else
    {

        ADCx->STATE &= (~tmpreg);
    }
}






void
ADC_Software_Start_Conv(ADC_SFRmap* ADCx)
{

    ((void)0);


    __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL1)),"i"((2)));
}







void
ADC_Continuous_Mode_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);

    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((18)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((18)));
    }
}







void
ADC_Disc_Mode_Channel_Count_Config (ADC_SFRmap* ADCx, uint8_t Number)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = (uint32_t)(Number - 1) << (26);
    ADCx->CTL0 = SFR_Config (ADCx->CTL0,
                               ~((uint32_t)7<<((26))),
                               tmpreg);
}







void
ADC_Disc_Mode_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);

    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((20)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((20)));
    }
}






uint16_t
ADC_Get_Conversion_Value (ADC_SFRmap* ADCx)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = ADCx->DATA;

    return (uint16_t) tmpreg;
}
# 1077 "../system/src/kf32a_basic_adc.c"
void
ADC_High_Priority_Watchdog_Enable (ADC_SFRmap* ADCx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((30)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((30)));
    }
}







void
ADC_HPExternal_Trig_Conv_Enable (ADC_SFRmap* ADCx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL1)),"i"((27)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ADCx->CTL1)),"i"((27)));
    }
}
# 1131 "../system/src/kf32a_basic_adc.c"
void
ADC_High_Priority_Channel_Config (ADC_SFRmap* ADCx,
                    uint32_t Channel, uint32_t Rank)
{
    uint32_t tmpreg = 0;
    uint32_t tmpmask = 0;


    ((void)0);
    ((void)0);
    ((void)0);




    tmpreg = (uint32_t)Channel << (6 * (Rank - 1));
    tmpmask = ((uint32_t)0x3F<<((0))) << (6 * (Rank - 1));
    ADCx->HSCANSQ = SFR_Config (ADCx->HSCANSQ,
                          ~tmpmask,
                          tmpreg);
}







void
ADC_High_Priority_Sequencer_Length_Config (ADC_SFRmap* ADCx, uint32_t Length)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = (Length - 1) << (28);
    ADCx->HSCANSQ = SFR_Config (ADCx->HSCANSQ,
                               ~((uint32_t)0x3<<((28))),
                               tmpreg);
}
# 1186 "../system/src/kf32a_basic_adc.c"
void
ADC_Set_HPChannel_Conv_Value_Offset (ADC_SFRmap* ADCx,
                    uint32_t HPDoffChannel, uint32_t Offset)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);



    tmpreg = (uint32_t)ADCx;
    tmpreg += HPDoffChannel;


    *(volatile uint32_t *) tmpreg = Offset;
}
# 1282 "../system/src/kf32a_basic_adc.c"
void
ADC_HPExternal_Trig_Conv_Config (ADC_SFRmap* ADCx,
                    uint32_t HPExternalTrigEvent)
{

    ((void)0);
    ((void)0);


    ADCx->CTL1 = SFR_Config (ADCx->CTL1,
                               ~((uint32_t)0x7F<<((20))),
                               HPExternalTrigEvent);
}






void
ADC_Software_HPStart_Conv (ADC_SFRmap* ADCx)
{

    ((void)0);


    __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL1)),"i"((3)));
}







void
ADC_HPAuto_Conv_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);

    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((19)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((19)));
    }
}







void
ADC_HPDisc_Mode_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);

    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((21)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ADCx->CTL0)),"i"((21)));
    }
}
# 1371 "../system/src/kf32a_basic_adc.c"
uint16_t
ADC_Get_HPConversion_Data (ADC_SFRmap* ADCx, uint8_t HPDataChannel)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);



    tmpreg = (uint32_t)ADCx;
    tmpreg += HPDataChannel;


    tmpreg = *(volatile uint32_t *) tmpreg;
    return (uint16_t) tmpreg;
}
# 1408 "../system/src/kf32a_basic_adc.c"
void
ADC_Set_INT_Enable (ADC_SFRmap* ADCx,
                    uint32_t InterruptType, FunctionalState NewState)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = (InterruptType & 0x0F);
    tmpreg = (uint32_t)0x01 << tmpreg;

    if (NewState != FALSE)
    {

        ADCx->STATE |= tmpreg;
    }
    else
    {

        ADCx->STATE &= (~tmpreg);
    }
}
# 1445 "../system/src/kf32a_basic_adc.c"
FlagStatus
ADC_Get_INT_Flag (ADC_SFRmap* ADCx, uint32_t InterruptType)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = ((InterruptType >> 8)&0x0F);
    tmpreg = (uint32_t)0x01 << tmpreg;
    if ((ADCx->STATE & tmpreg) != RESET)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 1479 "../system/src/kf32a_basic_adc.c"
void
ADC_Clear_INT_Flag (ADC_SFRmap* ADCx, uint32_t InterruptType)
{
    uint32_t tmpreg = 0;
    uint32_t tmpreg1 = 0;
    uint32_t tmpreg2 = 0;

    ((void)0);
    ((void)0);


    tmpreg = InterruptType >> 16;
    tmpreg = (uint32_t)0x01 << tmpreg;


    ADCx->STATE |= tmpreg;

    tmpreg1 = (InterruptType >> 8)&0x0f;
    tmpreg2 = (ADCx->STATE) & ((uint32_t)(0x01 << tmpreg1));
    while(tmpreg2>>tmpreg1);

    ADCx->STATE &= ~tmpreg;
}
# 1513 "../system/src/kf32a_basic_adc.c"
INTStatus
ADC_Get_INT_Status (ADC_SFRmap* ADCx, uint32_t InterruptType)
{
    uint32_t tmpmask = 0;
    uint32_t enablestatus = 0;
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = ADCx->STATE;


    enablestatus = (tmpreg & ((uint32_t)0x01 << InterruptType)) ;


    tmpmask = tmpreg & ((uint32_t)0x01 << ((InterruptType >> 8)));


    if ((tmpmask != (uint32_t)RESET) && enablestatus)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}