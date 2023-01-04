# 1 "../system/src/kf32a_basic_rtc.c"
# 1 "/cygdrive/d/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/Release//"
# 1 "<command-line>"
# 1 "../system/src/kf32a_basic_rtc.c"
# 19 "../system/src/kf32a_basic_rtc.c"
# 1 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_osc.h" 1
# 14 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_osc.h"
# 1 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h" 1
# 20 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 21 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h" 2
# 1 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_Config.h" 1
# 15 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_Config.h"
# 1 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/__Kungfu32_chipmodel_define.h" 1
# 16 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_Config.h" 2
# 22 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h" 2
# 36 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 171 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 1127 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 1450 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 3317 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
typedef struct SYSCTL_MemMap {
    volatile uint32_t PSW;
    volatile uint32_t MCTL;
    volatile uint32_t ARCTL;
    volatile uint32_t VECTOFF;
          uint32_t RESEVRVE1;
    volatile uint32_t RAMSPA;
    volatile uint32_t MEMCTL;
}SYSCTL_SFRmap;
# 3406 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 4066 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 4721 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
typedef struct SYSTICK_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t RELOAD;
    volatile uint32_t CV;
    volatile uint32_t CALI;
}SYSTICK_SFRmap;
# 4775 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 4963 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 5573 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 6302 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
typedef struct QEI_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CNT;
    volatile uint32_t PPX;
    volatile uint32_t PRSC;
    volatile uint32_t DIER;
}QEI_SFRmap;
# 6420 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
typedef struct DAC_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t DAHD;
    volatile const uint32_t DATA;
    volatile uint32_t CTL1;
                   uint32_t RESERVED;
    volatile uint32_t CAL;
}DAC_SFRmap;
# 6573 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
typedef struct CMP_MemMap {
    volatile uint32_t CTL;





}CMP_SFRmap;
# 8136 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 8679 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
typedef struct IWDT_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t FD;
}IWDT_SFRmap;
# 8712 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
typedef struct WWDT_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t CNT;
}WWDT_SFRmap;
# 8752 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
typedef struct RST_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}RST_SFRmap;
# 9132 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
typedef struct PCLK_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}PCLK_SFRmap;
# 9512 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
typedef struct SPI_MemMap {
    volatile uint32_t BRGR;
    volatile uint32_t CTLR;
    volatile uint32_t BUFR;
    volatile uint32_t STR;
}SPI_SFRmap;
# 9672 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 9934 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 11943 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 12722 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 13117 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
typedef struct BKP_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t INT;
             uint32_t RESERVED[14];
    volatile uint32_t DATA[32];
}BKP_SFRmap;
# 13223 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 13421 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 13471 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
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
# 13925 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
typedef struct EXIC_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t STATE;
       uint32_t RESERVED1;
    volatile uint32_t WRITEBUF;
    volatile uint32_t READBUF;

}EXIC_SFRmap;
# 14005 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
typedef struct CFGL_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t IFR;
}CFGL_SFRmap;
# 14184 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
typedef struct OP_MemMap {
    volatile uint32_t CAL;
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
}OP_SFRmap;
# 14358 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/KF32A_BASIC.h"
static inline uint32_t
SFR_Config (uint32_t SfrMem, uint32_t SfrMask, uint32_t WriteVal)
{
    return ((SfrMem & SfrMask) | (WriteVal));
}
# 15 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_osc.h" 2






typedef struct
{
    uint32_t m_InputSource;


    uint32_t m_CLKDivision;


    uint32_t m_PLLInputSource;


    uint32_t m_StartDelay;

} OSC_InitTypeDef;
# 267 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_osc.h"
void OSC_SCLK_Configuration (OSC_InitTypeDef* oscInitStruct);
void OSC_HFCK_Configuration (OSC_InitTypeDef* oscInitStruct);
void OSC_LFCK_Configuration (OSC_InitTypeDef* oscInitStruct);
void OSC_Struct_Init (OSC_InitTypeDef* oscInitStruct);

void OSC_LFCK_Division_Config (uint32_t LFDivision);
void OSC_HFCK_Division_Config (uint32_t HFDivision);
void OSC_SCK_Division_Config (uint32_t SclkDivision);
void OSC_PLL_Input_Source_Config (uint32_t NewState);
void OSC_HFCK_Source_Config (uint32_t HFSource);
void OSC_HFCK_Enable (FunctionalState NewState);
void OSC_LFCK_Source_Config (uint32_t NewState);
void OSC_LFCK_Enable (FunctionalState NewState);
void OSC_SCK_Source_Config (uint32_t SclkSource);
void OSC_Backup_Write_Read_Enable (FunctionalState NewState);
void OSC_SCLK_Output_Enable (FunctionalState NewState);
void OSC_SCLK_Output_Select (uint32_t SclkSource);
void OSC_SCLK_Output_Division_Config (uint32_t OutputDivision);
void OSC_Clock_Failure_Check_Enable (FunctionalState NewState);
void OSC_PLL_Multiple_Value_Select (uint32_t PLLmultiple_M,uint32_t PLLmultiple_N,uint32_t PLLmultiple_NO);
void OSC_PLL_Start_Delay_Config (uint32_t PLLDelay);
void OSC_EXTHF_Start_Delay_Config (uint32_t ExternalDelay);
void OSC_EXTLF_Start_Delay_Config (uint32_t ExternalDelay);
void OSC_PLL_Software_Enable (FunctionalState NewState);
void OSC_EXTHF_Software_Enable (FunctionalState NewState);
void OSC_EXTLF_Software_Enable (FunctionalState NewState);
void OSC_INTHF_Software_Enable (FunctionalState NewState);
void OSC_INTLF_Software_Enable (FunctionalState NewState);
void OSC_Zero_Drift_Config (uint32_t Scale, FunctionalState NewState);
void OSC_Positive_Drift_Config (uint32_t PositiveDrift);
void OSC_Negative_Drift_Config (uint32_t PositiveDrift);
void OSC_Current_Gain_Config (uint32_t PositiveDrift);
void OSC_High_Speed_Enable (FunctionalState NewState);
void OSC_External_Input_Enable (FunctionalState NewState);
void OSC_Feedback_Resistance_Config (uint32_t NewState);
void OSC_PLL_Feedback_Test_Enable (FunctionalState NewState);
void OSC_PLL_Zero_Source_Enable (FunctionalState NewState);
void OSC_PLL_Vref2_Enable (FunctionalState NewState);
void OSC_PLL_Vref0p5_Enable (FunctionalState NewState);
void OSC_PLL_Vref1p2_Enable (FunctionalState NewState);
void OSC_PLL_Low_Power_20nA_Enable (FunctionalState NewState);
void OSC_PLL_Vref1p14_Enable (FunctionalState NewState);
void OSC_PLL_Low_Power_100nA_Enable (FunctionalState NewState);
void OSC_PLL_LDO_Enable (FunctionalState NewState);

void OSC_PLL_INT_Enable (FunctionalState NewState);
void OSC_EXTHF_INT_Enable (FunctionalState NewState);
void OSC_EXTLF_INT_Enable (FunctionalState NewState);
void OSC_INTHF_INT_Enable (FunctionalState NewState);
void OSC_INTLF_INT_Enable (FunctionalState NewState);
FlagStatus OSC_Get_Clock_Failure_INT_Flag (void);
FlagStatus OSC_Get_PLL_INT_Flag (void);
FlagStatus OSC_Get_EXTHF_INT_Flag (void);
FlagStatus OSC_Get_EXTLF_INT_Flag (void);
FlagStatus OSC_Get_INTHF_INT_Flag (void);
FlagStatus OSC_Get_INTLF_INT_Flag (void);
FlagStatus OSC_Get_LP4MIF_INT_Flag (void);
void OSC_PLL_RST(void);
# 20 "../system/src/kf32a_basic_rtc.c" 2
# 1 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_bkp.h" 1
# 62 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_bkp.h"
void BKP_Reset (void);
void BKP_Write_And_Read_Enable (FunctionalState NewState);

void BKP_Reset_Enable (FunctionalState NewState);
void BKP_Pin_Effective_Level_Config (uint32_t PinSel, uint32_t Effective);
void BKP_Pin_Enable (uint32_t PinSel, FunctionalState NewState);
void BKP_RTC_Clock_Config (uint32_t Source);
void BKP_External_Clock_Bypass_Enable (uint32_t Source,
                    FunctionalState NewState);
void BKP_Data_Config (uint32_t OrderNumber, uint32_t WriteData);
uint32_t BKP_Get_Data (uint32_t OrderNumber);

void BKP_Pin_TAMP_INT_Enable (uint32_t PinSel, FunctionalState NewState);
FlagStatus BKP_Get_Pin_TAMP_INT_Flag (uint32_t PinSel);
void BKP_Clear_Pin_TAMP_INT_Flag (uint32_t PinSel);
# 21 "../system/src/kf32a_basic_rtc.c" 2
# 1 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_rtc.h" 1
# 20 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_rtc.h"
typedef struct
{
    uint8_t m_Hours;

    uint8_t m_Minutes;

    uint8_t m_Seconds;

    uint8_t m_AMPM;

}RTC_TimeTypeDef;




typedef struct
{
    uint8_t m_WeekDay;

    uint8_t m_Day;

    uint8_t m_Month;

    uint8_t m_Year;

}RTC_DateTypeDef;




typedef struct
{
    uint32_t m_ClockSource;

    uint32_t m_HourFormat;

    RTC_TimeTypeDef m_TimeStruct;
    RTC_DateTypeDef m_DateStruct;
}RTC_InitTypeDef;




typedef struct
{
    uint8_t m_WeekDay;

    uint8_t m_Hours;

    uint8_t m_Minutes;

    uint8_t m_Seconds;

    uint8_t m_AMPM;

    uint32_t m_WeekDayEnable;

    uint32_t m_HoursEnable;

    uint32_t m_MinutesEnable;

    uint32_t m_SecondsEnable;

}RTC_AlarmTypeDef;
# 290 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_rtc.h"
void RTC_Reset (void);
void RTC_Configuration (uint32_t TimeFormat,
                    RTC_InitTypeDef * rtcInitStruct);
void RTC_Time_Struct_Init (RTC_TimeTypeDef* rtcTimeInitStruct);
void RTC_Date_Struct_Init (RTC_DateTypeDef* rtcDateInitStruct);
void RTC_Struct_Init (RTC_InitTypeDef * rtcInitStruct);
void RTC_Get_Time_Configuration (uint32_t TimeFormat,
                    RTC_TimeTypeDef* rtcTimeStruct);
void RTC_Get_Date_Configuration (uint32_t TimeFormat,
                    RTC_DateTypeDef* rtcDateStruct);
void RTC_Alarm_Configuration (uint32_t AlarmSelect,
                    uint32_t TimeFormat,
                    RTC_AlarmTypeDef* rtcAlarmInitStruct);
void RTC_Alarm_Struct_Init (RTC_AlarmTypeDef* rtcAlarmInitStruct);

void RTC_Clock_Calibration_Config (int8_t Calibration);
void RTC_Time_Tick_Output_Enable (FunctionalState NewState);
void RTC_Time_Stamp_Channel_Enable (uint32_t TimeStampChannel,FunctionalState NewState);
void RTC_Time_Stamp_Edge_Config (uint32_t TimeStamp);
void RTC_Time_Stamp_Edge_Enable (FunctionalState NewState);
void RTC_Add_One_Hour_Enable (FunctionalState NewState);
void RTC_Sub_One_Hour_Enable (FunctionalState NewState);
void RTC_Time_Tick_Config (uint32_t Calibration);
void RTC_Reset_Config (void);
FlagStatus RTC_Get_Leap_Year_Flag (void);
void RTC_Hour_Format_Config (uint32_t HourFormat);
void RTC_Config_Mode_Enable (uint32_t ConfigMode);
FlagStatus RTC_Get_Operation_Off_Flag (void);
FlagStatus RTC_Get_Action_State_Flag (void);
void RTC_Enable (FunctionalState NewState);

void RTC_Alarm_A_Enable (FunctionalState NewState);
void RTC_Alarm_A_Weekday_Enable (FunctionalState NewState);
void RTC_Alarm_A_Weekday_Config (uint8_t Weekday);
void RTC_Alarm_A_Hours_Enable (FunctionalState NewState);
void RTC_Alarm_A_AMPM_Config (uint32_t NewSelect);
void RTC_Alarm_A_Hours_Config (uint32_t Hour);
void RTC_Alarm_A_Minutes_Enable (FunctionalState NewState);
void RTC_Alarm_A_Minutes_Config (uint32_t Minutes);
void RTC_Alarm_A_Seconds_Enable (FunctionalState NewState);
void RTC_Alarm_A_Seconds_Config (uint32_t Seconds);
void RTC_Alarm_B_Enable (FunctionalState NewState);
void RTC_Alarm_B_Weekday_Enable (FunctionalState NewState);
void RTC_Alarm_B_Weekday_Config (uint8_t Weekday);
void RTC_Alarm_B_Hours_Enable (FunctionalState NewState);
void RTC_Alarm_B_AMPM_Config (uint32_t NewSelect);
void RTC_Alarm_B_Hours_Config (uint32_t Hour);
void RTC_Alarm_B_Minutes_Enable (FunctionalState NewState);
void RTC_Alarm_B_Minutes_Config (uint32_t Minutes);
void RTC_Alarm_B_Seconds_Enable (FunctionalState NewState);
void RTC_Alarm_B_Seconds_Config (uint32_t Seconds);

void RTC_Weekday_Config (uint8_t Weekday);
void RTC_AMPM_Config (uint32_t NewSelect);
void RTC_Hours_Config (uint32_t Hour);
void RTC_Minutes_Config (uint32_t Minutes);
void RTC_Seconds_Config (uint32_t Seconds);
void RTC_Year_Config (uint32_t Year);
void RTC_Month_Config (uint32_t Month);
void RTC_Day_Config (uint32_t Day);
void RTC_Weekday_Backup_Config (uint8_t Weekday);
void RTC_AMPM_Backup_Config (uint32_t NewSelect);
void RTC_Hours_Backup_Config (uint32_t Hour);
void RTC_Minutes_Backup_Config (uint32_t Minutes);
void RTC_Seconds_Backup_Config (uint32_t Seconds);
void RTC_Year_Backup_Config (uint32_t Year);
void RTC_Month_Backup_Config (uint32_t Month);
void RTC_Day_Backup_Config (uint32_t Day);

void RTC_Timer1_Config (uint16_t Counter);
void RTC_Timer0_Config (uint16_t Counter);
void RTC_Timer1_Enable (uint32_t TimerEnable);
void RTC_Timer0_Enable (uint32_t TimerEnable);
void RTC_Timer1_Source_Config (uint16_t Counter);
void RTC_Timer0_Source_Config (uint16_t Counter);

void RTC_Time_Stamp_INT_Enable (FunctionalState NewState);
void RTC_Time_Stamp_Overflow_INT_Enable (FunctionalState NewState);
void RTC_Timer1_INT_Enable (FunctionalState NewState);
void RTC_Timer0_INT_Enable (FunctionalState NewState);
void RTC_Time_Tick_INT_Enable (FunctionalState NewState);
void RTC_Alarm_B_INT_Enable (FunctionalState NewState);
void RTC_Alarm_A_INT_Enable (FunctionalState NewState);
void RTC_Days_INT_Enable (FunctionalState NewState);
void RTC_Hours_INT_Enable (FunctionalState NewState);
void RTC_Minutes_INT_Enable (FunctionalState NewState);
void RTC_Seconds_INT_Enable (FunctionalState NewState);
FlagStatus RTC_Get_Time_Stamp_INT_Flag (void);
FlagStatus RTC_Get_Time_Stamp_Overflow_INT_Flag (void);
FlagStatus RTC_Get_Timer1_INT_Flag (void);
FlagStatus RTC_Get_Timer0_INT_Flag (void);
FlagStatus RTC_Get_Time_Tick_INT_Flag (void);
FlagStatus RTC_Get_Alarm_B_INT_Flag (void);
FlagStatus RTC_Get_Alarm_A_INT_Flag (void);
FlagStatus RTC_Get_Days_INT_Flag (void);
FlagStatus RTC_Get_Hours_INT_Flag (void);
FlagStatus RTC_Get_Minutes_INT_Flag (void);
FlagStatus RTC_Get_Seconds_INT_Flag (void);
void RTC_Clear_Time_Stamp_INT_Flag (void);
void RTC_Clear_Time_Stamp_Overflow_INT_Flag (void);
void RTC_Clear_Timer1_INT_Flag (void);
void RTC_Clear_Timer0_INT_Flag (void);
void RTC_Clear_Time_Tick_INT_Flag (void);
void RTC_Clear_Alarm_B_INT_Flag (void);
void RTC_Clear_Alarm_A_INT_Flag (void);
void RTC_Clear_Days_INT_Flag (void);
void RTC_Clear_Hours_INT_Flag (void);
void RTC_Clear_Minutes_INT_Flag (void);
void RTC_Clear_Seconds_INT_Flag (void);
# 22 "../system/src/kf32a_basic_rtc.c" 2
# 47 "../system/src/kf32a_basic_rtc.c"
static uint8_t RTC_Byte_To_Bcd (uint8_t Value);
static uint8_t RTC_Bcd_To_Byte (uint8_t Value);
# 59 "../system/src/kf32a_basic_rtc.c"
void
RTC_Reset (void)
{

    __asm volatile("SET [%0], #%1"::"r"(&((((OSC_SFRmap *) ((uint32_t)0x40000000))->CTL0))),"i"((0)));
    __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((22)));
    __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((7)));


    __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((6)));

    __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((6)));
}
# 81 "../system/src/kf32a_basic_rtc.c"
void
RTC_Configuration (uint32_t TimeFormat, RTC_InitTypeDef * rtcInitStruct)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);
    if (TimeFormat != ((uint32_t)0))
    {
        if (((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR) & ((uint32_t)1<<((4)))) != ((uint32_t)0<<(4)))
        {
            ((void)0);
            ((void)0);
        }
        else
        {
            ((void)0);
            if(rtcInitStruct->m_TimeStruct.m_Hours>=12)
            {
                rtcInitStruct->m_TimeStruct.m_AMPM = ((uint32_t)1);
            }
            else
            {
                rtcInitStruct->m_TimeStruct.m_AMPM = ((uint32_t)0);
            }
        }
        ((void)0);
        ((void)0);
        ((void)0);
        ((void)0);
        ((void)0);
        ((void)0);
    }
    else
    {
        if (((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR) & ((uint32_t)1<<((4)))) != ((uint32_t)0<<(4)))
        {
            ((void)0)
                                                                              ;
            ((void)0);
        }
        else
        {
            ((void)0)
                                                                              ;
            if(rtcInitStruct->m_TimeStruct.m_Hours>=12)
            {
                rtcInitStruct->m_TimeStruct.m_AMPM = ((uint32_t)1);
            }
            else
            {
                rtcInitStruct->m_TimeStruct.m_AMPM = ((uint32_t)0);
            }
        }
        ((void)0)
                                                                                ;
        ((void)0)
                                                                                ;
        ((void)0);
        ((void)0)
                                                                            ;
        ((void)0);
        ((void)0)
                                                                             ;
    }


    __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((3)));







    if (TimeFormat != ((uint32_t)0))
    {
        tmpreg = ((uint32_t)rtcInitStruct->m_DateStruct.m_WeekDay
                    << (24))
               | ((uint32_t)RTC_Byte_To_Bcd(rtcInitStruct->m_TimeStruct.m_Hours)
                    << (16))
               | ((uint32_t)RTC_Byte_To_Bcd(rtcInitStruct->m_TimeStruct.m_Minutes)
                    << (8))
               | ((uint32_t)RTC_Byte_To_Bcd(rtcInitStruct->m_TimeStruct.m_Seconds)
                    << (0))
               | ((uint32_t)rtcInitStruct->m_TimeStruct.m_AMPM << (22));
    }
    else
    {
        tmpreg = ((uint32_t)rtcInitStruct->m_DateStruct.m_WeekDay << (24))
               | ((uint32_t)rtcInitStruct->m_TimeStruct.m_Hours << (16))
               | ((uint32_t)rtcInitStruct->m_TimeStruct.m_Minutes << (8))
               | ((uint32_t)rtcInitStruct->m_TimeStruct.m_Seconds << (0))
               | ((uint32_t)rtcInitStruct->m_TimeStruct.m_AMPM << (22));
    }
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMR),
                          ~(((uint32_t)7<<((24))) | ((uint32_t)1<<((22))) | ((uint32_t)0x3F<<((16))) | ((uint32_t)0x7F<<((8))) | ((uint32_t)0x7F<<((0)))),
                          tmpreg);





    if (TimeFormat != ((uint32_t)0))
    {
        tmpreg = ((uint32_t)RTC_Byte_To_Bcd(rtcInitStruct->m_DateStruct.m_Month)
                    << (8))
               | ((uint32_t)RTC_Byte_To_Bcd(rtcInitStruct->m_DateStruct.m_Day)
                    << (0))
               | ((uint32_t)RTC_Byte_To_Bcd(rtcInitStruct->m_DateStruct.m_Year)
                    << (16));
    }
    else
    {
        tmpreg = ((uint32_t)rtcInitStruct->m_DateStruct.m_Month << (8))
               | ((uint32_t)rtcInitStruct->m_DateStruct.m_Day << (0))
               | ((uint32_t)rtcInitStruct->m_DateStruct.m_Year << (16));
    }
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->DTR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->DTR),
                          ~(((uint32_t)0x7F<<((0))) | ((uint32_t)0x7F<<((8))) | ((uint32_t)0x3F<<((16)))),
                          tmpreg);



    tmpreg = rtcInitStruct->m_HourFormat;
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR),
                          ~((uint32_t)1<<((4))),
                          tmpreg);



    (((BKP_SFRmap *) ((uint32_t)0x40001400))->CTL) = SFR_Config ((((BKP_SFRmap *) ((uint32_t)0x40001400))->CTL),
                          ~((uint32_t)3<<((8))),
                          rtcInitStruct->m_ClockSource);


    __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((3)));
}






void
RTC_Time_Struct_Init (RTC_TimeTypeDef* rtcTimeInitStruct)
{


    rtcTimeInitStruct->m_Hours = 0;

    rtcTimeInitStruct->m_Minutes = 0;

    rtcTimeInitStruct->m_Seconds = 0;

    rtcTimeInitStruct->m_AMPM = ((uint32_t)0);
}






void
RTC_Date_Struct_Init (RTC_DateTypeDef* rtcDateInitStruct)
{


    rtcDateInitStruct->m_WeekDay = ((uint8_t)0x01);

    rtcDateInitStruct->m_Year = 0;

    rtcDateInitStruct->m_Month = ((uint8_t)0x01);

    rtcDateInitStruct->m_Day = 1;
}






void
RTC_Struct_Init (RTC_InitTypeDef * rtcInitStruct)
{

    rtcInitStruct->m_ClockSource = ((uint32_t)0<<(8));

    rtcInitStruct->m_HourFormat = ((uint32_t)0<<(4));

    rtcInitStruct->m_TimeStruct.m_Hours = 0;

    rtcInitStruct->m_TimeStruct.m_Minutes = 0;

    rtcInitStruct->m_TimeStruct.m_Seconds = 0;

    rtcInitStruct->m_TimeStruct.m_AMPM = ((uint32_t)0);

    rtcInitStruct->m_DateStruct.m_WeekDay = ((uint8_t)0x01);

    rtcInitStruct->m_DateStruct.m_Year = 0;

    rtcInitStruct->m_DateStruct.m_Month = ((uint8_t)0x01);

    rtcInitStruct->m_DateStruct.m_Day = 1;
}
# 298 "../system/src/kf32a_basic_rtc.c"
void
RTC_Get_Time_Configuration (uint32_t TimeFormat,
                    RTC_TimeTypeDef* rtcTimeStruct)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = (((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMR);


    rtcTimeStruct->m_Hours = (uint8_t)((tmpreg & ((uint32_t)0x3F<<((16))))
                            >> (16));
    rtcTimeStruct->m_Minutes = (uint8_t)((tmpreg & ((uint32_t)0x7F<<((8))))
                              >> (8));
    rtcTimeStruct->m_Seconds = (uint8_t)((tmpreg & ((uint32_t)0x7F<<((0))))
                              >> (0));
    rtcTimeStruct->m_AMPM = (uint8_t)((tmpreg & ((uint32_t)1<<((22))))
                           >> (22));


    if (TimeFormat != ((uint32_t)0))
    {
        rtcTimeStruct->m_Hours = RTC_Bcd_To_Byte(rtcTimeStruct->m_Hours);
        rtcTimeStruct->m_Minutes = RTC_Bcd_To_Byte(rtcTimeStruct->m_Minutes);
        rtcTimeStruct->m_Seconds = RTC_Bcd_To_Byte(rtcTimeStruct->m_Seconds);
    }
}
# 337 "../system/src/kf32a_basic_rtc.c"
void
RTC_Get_Date_Configuration (uint32_t TimeFormat,
                    RTC_DateTypeDef* rtcDateStruct)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = (((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMR);


    rtcDateStruct->m_WeekDay = (uint8_t)((tmpreg & ((uint32_t)7<<((24))))
                              >> (24));


    tmpreg = (((RTC_SFRmap *) ((uint32_t)0x40000F00))->DTR);


    rtcDateStruct->m_Year = (uint8_t)((tmpreg & ((uint32_t)0x3F<<((16))))
                           >> (16));
    rtcDateStruct->m_Month = (uint8_t)((tmpreg & ((uint32_t)0x7F<<((8))))
                           >> (8));
    rtcDateStruct->m_Day = (uint8_t)((tmpreg & ((uint32_t)0x7F<<((0))))
                           >> (0));


    if (TimeFormat != ((uint32_t)0))
    {
        rtcDateStruct->m_Year = RTC_Bcd_To_Byte(rtcDateStruct->m_Year);
        rtcDateStruct->m_Month = RTC_Bcd_To_Byte(rtcDateStruct->m_Month);
        rtcDateStruct->m_Day = RTC_Bcd_To_Byte(rtcDateStruct->m_Day);
    }
}
# 385 "../system/src/kf32a_basic_rtc.c"
void
RTC_Alarm_Configuration (uint32_t AlarmSelect,
                    uint32_t TimeFormat,
                    RTC_AlarmTypeDef* rtcAlarmInitStruct)
{
    uint32_t tmpreg = 0;
    uint32_t tmpaddr = 0;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);

    if (TimeFormat != ((uint32_t)0))
    {
        if (((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR) & ((uint32_t)1<<((4)))) != ((uint32_t)0<<(4)))
        {
            ((void)0);
            ((void)0);
        }
        else
        {
            rtcAlarmInitStruct->m_AMPM = ((uint32_t)0);
            ((void)0);
        }
        ((void)0);
        ((void)0);
        ((void)0);
    }
    else
    {
        if (((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR) & ((uint32_t)1<<((4)))) != ((uint32_t)0<<(4)))
        {
            ((void)0)
                                                                      ;
            ((void)0);
        }
        else
        {
            rtcAlarmInitStruct->m_AMPM = ((uint32_t)0);
            ((void)0)
                                                                      ;
        }
        ((void)0)
                                                                        ;
        ((void)0)
                                                                        ;
        ((void)0);
    }


    __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((3)));


    tmpaddr = (uint32_t)&(((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA);
    tmpaddr += AlarmSelect;
# 455 "../system/src/kf32a_basic_rtc.c"
    if (TimeFormat != ((uint32_t)0))
    {
        tmpreg = (rtcAlarmInitStruct->m_WeekDayEnable << (27))
               | (rtcAlarmInitStruct->m_HoursEnable << (23))
               | (rtcAlarmInitStruct->m_MinutesEnable << (15))
               | (rtcAlarmInitStruct->m_SecondsEnable << (7))
               | ((uint32_t)rtcAlarmInitStruct->m_AMPM << (22))
               | ((uint32_t)rtcAlarmInitStruct->m_WeekDay << (24))
               | ((uint32_t)RTC_Byte_To_Bcd(rtcAlarmInitStruct->m_Hours)
                    << (16))
               | ((uint32_t)RTC_Byte_To_Bcd(rtcAlarmInitStruct->m_Minutes)
                    << (8))
               | ((uint32_t)RTC_Byte_To_Bcd(rtcAlarmInitStruct->m_Seconds)
                    << (0));
    }
    else
    {
        tmpreg = (rtcAlarmInitStruct->m_WeekDayEnable << (27))
               | (rtcAlarmInitStruct->m_HoursEnable << (23))
               | (rtcAlarmInitStruct->m_MinutesEnable << (15))
               | (rtcAlarmInitStruct->m_SecondsEnable << (7))
               | ((uint32_t)rtcAlarmInitStruct->m_AMPM << (22))
               | ((uint32_t)rtcAlarmInitStruct->m_WeekDay << (24))
               | ((uint32_t)rtcAlarmInitStruct->m_Hours << (16))
               | ((uint32_t)rtcAlarmInitStruct->m_Minutes << (8))
               | ((uint32_t)rtcAlarmInitStruct->m_Seconds << (0));
    }

    *(volatile uint32_t *)tmpaddr =
                    SFR_Config (*(volatile uint32_t *)tmpaddr,
                                ~(((uint32_t)0x7F<<((0))) | ((uint32_t)1<<((7))) | ((uint32_t)0x7F<<((8))) | ((uint32_t)1<<((15))) | ((uint32_t)0x3F<<((16))) | ((uint32_t)1<<((22))) | ((uint32_t)1<<((23))) | ((uint32_t)7<<((24))) | ((uint32_t)1<<((27)))),
                                tmpreg);


    __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((3)));
}






void
RTC_Alarm_Struct_Init (RTC_AlarmTypeDef* rtcAlarmInitStruct)
{

    rtcAlarmInitStruct->m_AMPM = ((uint32_t)0);

    rtcAlarmInitStruct->m_WeekDay = ((uint8_t)0x01);

    rtcAlarmInitStruct->m_WeekDayEnable = FALSE;

    rtcAlarmInitStruct->m_Hours = 0;

    rtcAlarmInitStruct->m_HoursEnable = FALSE;

    rtcAlarmInitStruct->m_Minutes = 0;

    rtcAlarmInitStruct->m_MinutesEnable = FALSE;

    rtcAlarmInitStruct->m_Seconds = 0;

    rtcAlarmInitStruct->m_SecondsEnable = FALSE;
}
# 532 "../system/src/kf32a_basic_rtc.c"
void
RTC_Clock_Calibration_Config (int8_t Calibration)
{
    uint32_t tmpreg = 0;


    tmpreg = (uint32_t)Calibration << (24);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR), ~((uint32_t)0xFF<<((24))), tmpreg);
}






void
RTC_Time_Tick_Output_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((23)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((23)));
    }
}
# 578 "../system/src/kf32a_basic_rtc.c"
void
RTC_Time_Stamp_Channel_Enable (uint32_t TimeStampChannel,FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {
     (((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR) |= TimeStampChannel;
    }
    else
    {

     (((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR) &= ~TimeStampChannel;
    }
}
# 604 "../system/src/kf32a_basic_rtc.c"
void
RTC_Time_Stamp_Edge_Config (uint32_t TimeStamp)
{

    ((void)0);


    if (TimeStamp != ((uint32_t)0 << (22)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((22)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((22)));
    }
}






void
RTC_Time_Stamp_Edge_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((21)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((21)));
    }
}






void
RTC_Add_One_Hour_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((20)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((20)));
    }
}






void
RTC_Sub_One_Hour_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((19)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((19)));
    }
}
# 708 "../system/src/kf32a_basic_rtc.c"
void
RTC_Time_Tick_Config (uint32_t Calibration)
{

    ((void)0);


    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR), ~((uint32_t)7<<((16))), Calibration);
}







void
RTC_Reset_Config (void)
{


    __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((6)));

    __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((6)));
}






FlagStatus
RTC_Get_Leap_Year_Flag (void)
{

    if ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR) & ((uint32_t)1<<((5))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 762 "../system/src/kf32a_basic_rtc.c"
void
RTC_Hour_Format_Config (uint32_t HourFormat)
{

    ((void)0);


    if (HourFormat != ((uint32_t)0<<(4)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((4)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((4)));
    }
}






void
RTC_Config_Mode_Enable (FunctionalState ConfigMode)
{

    ((void)0);


    if (ConfigMode != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((3)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((3)));
    }
}







FlagStatus
RTC_Get_Operation_Off_Flag (void)
{

    if ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR) & ((uint32_t)1<<((2))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus
RTC_Get_Action_State_Flag (void)
{

    if ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR) & ((uint32_t)1<<((1))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






void
RTC_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->CR))),"i"((0)));
    }
}
# 885 "../system/src/kf32a_basic_rtc.c"
void
RTC_Alarm_A_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA))),"i"((31)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA))),"i"((31)));
    }
}






void
RTC_Alarm_A_Weekday_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA))),"i"((27)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA))),"i"((27)));
    }
}
# 940 "../system/src/kf32a_basic_rtc.c"
void
RTC_Alarm_A_Weekday_Config (uint8_t Weekday)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = (uint32_t)Weekday << (24);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA), ~((uint32_t)7<<((24))), tmpreg);
}






void
RTC_Alarm_A_Hours_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA))),"i"((23)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA))),"i"((23)));
    }
}
# 984 "../system/src/kf32a_basic_rtc.c"
void
RTC_Alarm_A_AMPM_Config (uint32_t NewSelect)
{

    ((void)0);


    if (NewSelect != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA))),"i"((22)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA))),"i"((22)));
    }
}






void
RTC_Alarm_A_Hours_Config (uint32_t Hour)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Hour);
    tmpreg <<= (16);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA), ~((uint32_t)0x3F<<((16))), tmpreg);
}






void
RTC_Alarm_A_Minutes_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA))),"i"((15)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA))),"i"((15)));
    }
}






void
RTC_Alarm_A_Minutes_Config (uint32_t Minutes)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Minutes);
    tmpreg <<= (8);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA), ~((uint32_t)0x7F<<((8))), tmpreg);
}






void
RTC_Alarm_A_Seconds_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA))),"i"((7)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA))),"i"((7)));
    }
}






void
RTC_Alarm_A_Seconds_Config (uint32_t Seconds)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Seconds);
    tmpreg <<= (0);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRA), ~((uint32_t)0x7F<<((0))), tmpreg);
}






void
RTC_Alarm_B_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB))),"i"((31)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB))),"i"((31)));
    }
}






void
RTC_Alarm_B_Weekday_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB))),"i"((27)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB))),"i"((27)));
    }
}
# 1168 "../system/src/kf32a_basic_rtc.c"
void
RTC_Alarm_B_Weekday_Config (uint8_t Weekday)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = (uint32_t)Weekday << (24);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB), ~((uint32_t)7<<((24))), tmpreg);
}






void
RTC_Alarm_B_Hours_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB))),"i"((23)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB))),"i"((23)));
    }
}
# 1212 "../system/src/kf32a_basic_rtc.c"
void
RTC_Alarm_B_AMPM_Config (uint32_t NewSelect)
{

    ((void)0);


    if (NewSelect != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB))),"i"((22)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB))),"i"((22)));
    }
}






void
RTC_Alarm_B_Hours_Config (uint32_t Hour)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Hour);
    tmpreg <<= (16);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB), ~((uint32_t)0x3F<<((16))), tmpreg);
}






void
RTC_Alarm_B_Minutes_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB))),"i"((15)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB))),"i"((15)));
    }
}






void
RTC_Alarm_B_Minutes_Config (uint32_t Minutes)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Minutes);
    tmpreg <<= (8);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB), ~((uint32_t)0x7F<<((8))), tmpreg);
}






void
RTC_Alarm_B_Seconds_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB))),"i"((7)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB))),"i"((7)));
    }
}






void
RTC_Alarm_B_Seconds_Config (uint32_t Seconds)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Seconds);
    tmpreg <<= (0);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->ALRB), ~((uint32_t)0x7F<<((0))), tmpreg);
}
# 1355 "../system/src/kf32a_basic_rtc.c"
void
RTC_Weekday_Config (uint8_t Weekday)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = (uint32_t)Weekday << (24);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMR), ~((uint32_t)7<<((24))), tmpreg);
}
# 1375 "../system/src/kf32a_basic_rtc.c"
void
RTC_AMPM_Config (uint32_t NewSelect)
{

    ((void)0);


    if (NewSelect != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMR))),"i"((22)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMR))),"i"((22)));
    }
}






void
RTC_Hours_Config (uint32_t Hour)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Hour);
    tmpreg <<= (16);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMR), ~((uint32_t)0x3F<<((16))), tmpreg);
}






void
RTC_Minutes_Config (uint32_t Minutes)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Minutes);
    tmpreg <<= (8);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMR), ~((uint32_t)0x7F<<((8))), tmpreg);
}






void
RTC_Seconds_Config (uint32_t Seconds)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Seconds);
    tmpreg <<= (0);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMR), ~((uint32_t)0x7F<<((0))), tmpreg);
}






void
RTC_Year_Config (uint32_t Year)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Year);
    tmpreg <<= (16);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->DTR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->DTR), ~((uint32_t)0x3F<<((16))), tmpreg);
}
# 1487 "../system/src/kf32a_basic_rtc.c"
void
RTC_Month_Config (uint32_t Month)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = Month << (8);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->DTR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->DTR), ~((uint32_t)0x7F<<((8))), tmpreg);
}






void
RTC_Day_Config (uint32_t Day)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Day);
    tmpreg <<= (0);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->DTR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->DTR), ~((uint32_t)0x7F<<((0))), tmpreg);
}
# 1531 "../system/src/kf32a_basic_rtc.c"
void
RTC_Weekday_Backup_Config (uint8_t Weekday)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = (uint32_t)Weekday << (24);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMBR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMBR), ~((uint32_t)7<<((24))), tmpreg);
}
# 1551 "../system/src/kf32a_basic_rtc.c"
void
RTC_AMPM_Backup_Config (uint32_t NewSelect)
{

    ((void)0);


    if (NewSelect != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMBR))),"i"((22)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMBR))),"i"((22)));
    }
}






void
RTC_Hours_Backup_Config (uint32_t Hour)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Hour);
    tmpreg <<= (16);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMBR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMBR), ~((uint32_t)0x3F<<((16))), tmpreg);
}






void
RTC_Minutes_Backup_Config (uint32_t Minutes)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Minutes);
    tmpreg <<= (8);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMBR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMBR), ~((uint32_t)0x7F<<((8))), tmpreg);
}






void
RTC_Seconds_Backup_Config (uint32_t Seconds)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Seconds);
    tmpreg <<= (0);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMBR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMBR), ~((uint32_t)0x7F<<((0))), tmpreg);
}






void
RTC_Year_Backup_Config (uint32_t Year)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Year);
    tmpreg <<= (16);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->DTBR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->DTBR), ~((uint32_t)0x3F<<((16))), tmpreg);
}
# 1663 "../system/src/kf32a_basic_rtc.c"
void
RTC_Month_Backup_Config (uint32_t Month)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = Month << (8);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->DTBR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->DTBR), ~((uint32_t)0x7F<<((8))), tmpreg);
}






void
RTC_Day_Backup_Config (uint32_t Day)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = RTC_Byte_To_Bcd(Day);
    tmpreg <<= (0);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->DTBR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->DTBR), ~((uint32_t)0x7F<<((0))), tmpreg);
}
# 1707 "../system/src/kf32a_basic_rtc.c"
void
RTC_Timer1_Config (uint16_t Counter)
{
    uint32_t tmpreg = 0;


    tmpreg = (uint32_t)Counter << (16);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMER) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMER), ~((uint32_t)0xFFFF<<((16))), tmpreg);
}






void
RTC_Timer0_Config (uint16_t Counter)
{
    uint32_t tmpreg = 0;


    tmpreg = (uint32_t)Counter << (0);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMER) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TMER), ~((uint32_t)0xFFFF<<((0))), tmpreg);
}






void
RTC_Timer1_Enable (FunctionalState TimerEnable)
{

    ((void)0);


    if (TimerEnable != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TCR))),"i"((9)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TCR))),"i"((9)));
    }
}






void
RTC_Timer0_Enable (FunctionalState TimerEnable)
{

    ((void)0);


    if (TimerEnable != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TCR))),"i"((8)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TCR))),"i"((8)));
    }
}
# 1794 "../system/src/kf32a_basic_rtc.c"
void
RTC_Timer1_Source_Config (uint16_t ClockSource)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = (uint32_t)ClockSource << (4);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->TCR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TCR), ~((uint32_t)0xF<<((4))), tmpreg);
}
# 1820 "../system/src/kf32a_basic_rtc.c"
void
RTC_Timer0_Source_Config (uint16_t ClockSource)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = (uint32_t)ClockSource << (0);
    (((RTC_SFRmap *) ((uint32_t)0x40000F00))->TCR) = SFR_Config ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->TCR), ~((uint32_t)0xF<<((0))), tmpreg);
}
# 1846 "../system/src/kf32a_basic_rtc.c"
void
RTC_Time_Stamp_INT_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((11)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((11)));
    }
}






void
RTC_Time_Stamp_Overflow_INT_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((10)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((10)));
    }
}






void
RTC_Timer1_INT_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((9)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((9)));
    }
}






void
RTC_Timer0_INT_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((8)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((8)));
    }
}






void
RTC_Time_Tick_INT_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((6)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((6)));
    }
}






void
RTC_Alarm_B_INT_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((5)));
    }
}






void
RTC_Alarm_A_INT_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((4)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((4)));
    }
}






void
RTC_Days_INT_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((3)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((3)));
    }
}






void
RTC_Hours_INT_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((2)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((2)));
    }
}






void
RTC_Minutes_INT_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((1)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((1)));
    }
}






void
RTC_Seconds_INT_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IER))),"i"((0)));
    }
}






FlagStatus
RTC_Get_Time_Stamp_INT_Flag (void)
{

    if ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((11))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus
RTC_Get_Time_Stamp_Overflow_INT_Flag (void)
{

    if ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((10))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus
RTC_Get_Timer1_INT_Flag (void)
{

    if ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((9))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus
RTC_Get_Timer0_INT_Flag (void)
{

    if ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((8))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus
RTC_Get_Time_Tick_INT_Flag (void)
{

    if ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((6))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus
RTC_Get_Alarm_B_INT_Flag (void)
{

    if ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((5))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus
RTC_Get_Alarm_A_INT_Flag (void)
{

    if ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((4))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus
RTC_Get_Days_INT_Flag (void)
{

    if ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((3))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus
RTC_Get_Hours_INT_Flag (void)
{

    if ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((2))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus
RTC_Get_Minutes_INT_Flag (void)
{

    if ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((1))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus
RTC_Get_Seconds_INT_Flag (void)
{

    if ((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((0))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






void
RTC_Clear_Time_Stamp_INT_Flag (void)
{

    __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((27)));
    while((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((11))));
    __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((27)));
}






void
RTC_Clear_Time_Stamp_Overflow_INT_Flag (void)
{

    __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((26)));
    while((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((10))));
    __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((26)));
}






void
RTC_Clear_Timer1_INT_Flag (void)
{

    __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((25)));
    while((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((9))));
    __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((25)));
}






void
RTC_Clear_Timer0_INT_Flag (void)
{

    __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((24)));
    while((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((8))));
    __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((24)));
}






void
RTC_Clear_Time_Tick_INT_Flag (void)
{

    __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((22)));
    while((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((6))));
    __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((22)));
}






void
RTC_Clear_Alarm_B_INT_Flag (void)
{

    __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((21)));
    while((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((5))));
    __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((21)));
}






void
RTC_Clear_Alarm_A_INT_Flag (void)
{

    __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((20)));
    while((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((4))));
    __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((20)));
}






void
RTC_Clear_Days_INT_Flag (void)
{

    __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((19)));
    while((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((3))));
    __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((19)));
}






void
RTC_Clear_Hours_INT_Flag (void)
{

    __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((18)));
    while((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((2))));
    __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((18)));
}






void
RTC_Clear_Minutes_INT_Flag (void)
{

    __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((17)));
    while((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((1))));
    __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((17)));
}






void
RTC_Clear_Seconds_INT_Flag (void)
{

    __asm volatile("SET [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((16)));
    while((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR) & ((uint32_t)1<<((0))));
    __asm volatile("CLR [%0], #%1"::"r"(&((((RTC_SFRmap *) ((uint32_t)0x40000F00))->IFR))),"i"((16)));
}
# 2502 "../system/src/kf32a_basic_rtc.c"
static uint8_t
RTC_Byte_To_Bcd (uint8_t Value)
{
    uint8_t bcdhigh = 0;
    uint8_t bcdlow = 0;

    bcdhigh = Value / ((uint8_t)10);
    bcdlow = Value - bcdhigh * ((uint8_t)10);

    return (uint8_t)((bcdhigh << (uint8_t)4) | bcdlow);
}






static uint8_t
RTC_Bcd_To_Byte (uint8_t Value)
{
    uint8_t tmp = 0;

    tmp = (Value >> (uint8_t)4) * ((uint8_t)10);

    return (tmp + (Value & (uint8_t)0xF));
}
