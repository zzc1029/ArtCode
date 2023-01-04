# 1 "../system/src/kf32a_basic_atim.c"
# 1 "/cygdrive/d/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/Release//"
# 1 "<command-line>"
# 1 "../system/src/kf32a_basic_atim.c"
# 16 "../system/src/kf32a_basic_atim.c"
# 1 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_tim.h" 1
# 14 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_tim.h"
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
# 15 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_tim.h" 2
# 169 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_tim.h"
typedef struct
{
    uint16_t m_Counter;
    uint16_t m_Period;
    uint16_t m_Prescaler;
    uint16_t m_CounterMode;

    uint16_t m_Clock;

    uint16_t m_WorkMode;

    uint16_t m_MasterMode;

    uint16_t m_SlaveMode;

    uint16_t m_EXPulseSync;

    uint16_t m_MasterSlaveSync;

} BTIM_InitTypeDef;
# 284 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_tim.h"
typedef enum
{
    DIR_DOWN = 0,
    DIR_UP = !DIR_DOWN
} DIRStatus;





void TIM_Reset (void* TIMx);


void BTIM_Configuration (BTIM_SFRmap* BTIMx,
                    BTIM_InitTypeDef* btimInitStruct);
void BTIM_Struct_Init (BTIM_InitTypeDef* btimInitStruct);
void BTIM_Cmd (BTIM_SFRmap* BTIMx, FunctionalState NewState);
void BTIM_Set_Counter (BTIM_SFRmap* BTIMx, uint16_t Counter);
void BTIM_Set_Period (BTIM_SFRmap* BTIMx, uint16_t Period);
void BTIM_Set_Prescaler (BTIM_SFRmap* BTIMx, uint16_t Prescaler);
void BTIM_Counter_Mode_Config (BTIM_SFRmap* BTIMx, uint32_t CounterMode);
void BTIM_Clock_Config (BTIM_SFRmap* BTIMx, uint32_t NewClock);
void BTIM_External_Pulse_Sync_Config (BTIM_SFRmap* BTIMx, uint32_t PulseSync);
void BTIM_Work_Mode_Config (BTIM_SFRmap* BTIMx, uint32_t NewState);
void BTIM_Generate_Trigger_Config (BTIM_SFRmap* BTIMx, FunctionalState NewState);
void BTIM_Single_Pulse_Enable (BTIM_SFRmap* BTIMx, FunctionalState NewState);
void BTIM_Single_Pulse_Shut_Enable (BTIM_SFRmap* BTIMx,
                    FunctionalState NewState);
void BTIM_Updata_Immediately_Config (BTIM_SFRmap* BTIMx,
                    FunctionalState NewState);
void BTIM_Master_Slave_Snyc_Config (BTIM_SFRmap* BTIMx, FunctionalState NewState);
void BTIM_Trigger_Select_Config (BTIM_SFRmap* BTIMx,
                    uint32_t TriggerSelect);
void BTIM_Slave_Mode_Config (BTIM_SFRmap* BTIMx,
                    uint32_t SlaveMode);
void BTIM_Master_Mode_Config (BTIM_SFRmap* BTIMx,
                    uint32_t MasterMode);
void BTIM_Updata_Rising_Edge_Config (BTIM_SFRmap* BTIMx,
                    FunctionalState NewState);
void BTIM_Updata_Enable (BTIM_SFRmap* BTIMx, FunctionalState NewState);
DIRStatus BTIM_Get_Direction (BTIM_SFRmap* BTIMx);
uint16_t BTIM_Get_Counter (BTIM_SFRmap* BTIMx);
uint16_t BTIM_Get_Period (BTIM_SFRmap* BTIMx);
uint16_t BTIM_Get_Prescaler (BTIM_SFRmap* BTIMx);


void BTIM_Trigger_DMA_Enable (BTIM_SFRmap* BTIMx,
                    FunctionalState NewState);
void BTIM_Updata_DMA_Enable (BTIM_SFRmap* BTIMx,
                    FunctionalState NewState);
void BTIM_Overflow_INT_Enable (BTIM_SFRmap* BTIMx,
                    FunctionalState NewState);
void BTIM_Trigger_INT_Enable (BTIM_SFRmap* BTIMx,
                    FunctionalState NewState);
void BTIM_Updata_INT_Enable (BTIM_SFRmap* BTIMx, FunctionalState NewState);
INTStatus BTIM_Get_Trigger_DMA_INT_Status (BTIM_SFRmap* BTIMx);
INTStatus BTIM_Get_Updata_DMA_INT_Status (BTIM_SFRmap* BTIMx);
INTStatus BTIM_Get_Overflow_INT_Status (BTIM_SFRmap* BTIMx);
INTStatus BTIM_Get_Trigger_INT_Status (BTIM_SFRmap* BTIMx);
INTStatus BTIM_Get_Updata_INT_Status (BTIM_SFRmap* BTIMx);
FlagStatus BTIM_Get_Trigger_DMA_INT_Flag (BTIM_SFRmap* BTIMx);
FlagStatus BTIM_Get_Updata_DMA_INT_Flag (BTIM_SFRmap* BTIMx);
FlagStatus BTIM_Get_Overflow_INT_Flag (BTIM_SFRmap* BTIMx);
FlagStatus BTIM_Get_Trigger_INT_Flag (BTIM_SFRmap* BTIMx);
FlagStatus BTIM_Get_Updata_INT_Flag (BTIM_SFRmap* BTIMx);
void BTIM_Clear_Overflow_INT_Flag (BTIM_SFRmap* BTIMx);
void BTIM_Clear_Trigger_INT_Flag (BTIM_SFRmap* BTIMx);
void BTIM_Clear_Updata_INT_Flag (BTIM_SFRmap* BTIMx);
# 360 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_tim.h"
typedef struct
{
    uint32_t m_Counter;
    uint32_t m_Period;
    uint32_t m_Prescaler;
    uint16_t m_CounterMode;

    uint16_t m_Clock;

    uint16_t m_WorkMode;

    uint16_t m_MasterMode;

    uint16_t m_SlaveMode;

    uint16_t m_EXPulseSync;

    uint16_t m_MasterSlaveSync;

} GPTIM_InitTypeDef;




typedef struct
{
    uint16_t m_Channel;

    uint16_t m_CompareMode;

    uint32_t m_CompareValue;

} CCP_CompareInitTypeDef;




typedef struct
{
    uint16_t m_Channel;

    uint16_t m_CaptureMode;

    FunctionalState m_PWMInput;

    FunctionalState m_XORMode;

    FunctionalState m_ChannelCompare4;

} CCP_CaptureInitTypeDef;




typedef struct
{
    uint16_t m_Channel;

    uint16_t m_PwmMode;

    uint32_t m_DutyRatio;

    uint32_t m_OutputCtl;

    uint32_t m_SinglePWM;

    uint32_t m_CloseTimer;

} CCP_PWMInitTypeDef;
# 596 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_tim.h"
void GPTIM_Configuration(GPTIM_SFRmap* GPTIMx,
                    GPTIM_InitTypeDef* gptimInitStruct);
void GPTIM_Struct_Init (GPTIM_InitTypeDef* gptimInitStruct);
void GPTIM_Cmd (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Set_Counter (GPTIM_SFRmap* GPTIMx, uint32_t Counter);
void GPTIM_Set_Period (GPTIM_SFRmap* GPTIMx, uint32_t Period);
void GPTIM_Set_Prescaler (GPTIM_SFRmap* GPTIMx, uint32_t Prescaler);
void GPTIM_Counter_Mode_Config (GPTIM_SFRmap* GPTIMx, uint32_t CounterMode);
void GPTIM_Clock_Config (GPTIM_SFRmap* GPTIMx, uint32_t NewClock);
void GPTIM_External_Pulse_Sync_Config (GPTIM_SFRmap* GPTIMx,
                    uint32_t PulseSync);
void GPTIM_Work_Mode_Config (GPTIM_SFRmap* GPTIMx, uint32_t NewState);
void GPTIM_Updata_Immediately_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState NewState);
void GPTIM_Master_Slave_Snyc_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState NewState);
void GPTIM_Trigger_Select_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState TriggerSelect);
void GPTIM_Slave_Mode_Config (GPTIM_SFRmap* GPTIMx, FunctionalState SlaveMode);
void GPTIM_Master_Mode_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState MasterMode);
void GPTIM_Updata_Rising_Edge_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState NewState);
void GPTIM_Updata_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Trigger_DMA_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Updata_DMA_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Updata_INT_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Trigger_INT_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Generate_Trigger_Config (GPTIM_SFRmap* GPTIMx,
                    FunctionalState NewState);
DIRStatus GPTIM_Get_Direction (GPTIM_SFRmap* GPTIMx);
uint32_t GPTIM_Get_Counter (GPTIM_SFRmap* GPTIMx);
uint32_t GPTIM_Get_Period (GPTIM_SFRmap* GPTIMx);
uint32_t GPTIM_Get_Prescaler (GPTIM_SFRmap* GPTIMx);

void GPTIM_Overflow_INT_Enable (GPTIM_SFRmap* GPTIMx, FunctionalState NewState);
void GPTIM_Clear_Overflow_INT_Flag (GPTIM_SFRmap* GPTIMx);
void GPTIM_Clear_Updata_INT_Flag (GPTIM_SFRmap* GPTIMx);
void GPTIM_Clear_Trigger_INT_Flag (GPTIM_SFRmap* GPTIMx);
FlagStatus GPTIM_Get_Overflow_INT_Flag (GPTIM_SFRmap* GPTIMx);
FlagStatus GPTIM_Get_Updata_INT_Flag (GPTIM_SFRmap* GPTIMx);
FlagStatus GPTIM_Get_Trigger_INT_Flag (GPTIM_SFRmap* GPTIMx);
FlagStatus GPTIM_Get_Updata_DMA_INT_Flag (GPTIM_SFRmap* GPTIMx);
FlagStatus GPTIM_Get_Trigger_DMA_INT_Flag (GPTIM_SFRmap* GPTIMx);

void CCP_Compare_Configuration(CCP_SFRmap* CCPx,
                    CCP_CompareInitTypeDef* ccpInitStruct);
void CCP_Compare_Struct_Init (CCP_CompareInitTypeDef* ccpInitStruct);
void CCP_Capture_Configuration (CCP_SFRmap* CCPx,
                    CCP_CaptureInitTypeDef* ccpInitStruct);
void CCP_Capture_Struct_Init (CCP_CaptureInitTypeDef* ccpInitStruct);
void CCP_PWM_Configuration (CCP_SFRmap* CCPx,
                    CCP_PWMInitTypeDef* ccpInitStruct);
void CCP_PWM_Struct_Init (CCP_PWMInitTypeDef* ccpInitStruct);
void CCP_Capture_Mode_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    uint32_t EdgeConfig);
void CCP_Compare_Mode_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    uint32_t EdgeConfig);
void CCP_PWM_Mode_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    uint32_t EdgeConfig);
uint32_t CCP_Get_Capture_Result (CCP_SFRmap* CCPx, uint32_t Channel);
void CCP_Set_Compare_Result (CCP_SFRmap* CCPx, uint32_t Channel,
                    uint32_t Value);


uint32_t CCP_Get_Compare_Result (CCP_SFRmap* CCPx, uint32_t Channel);


void CCP_Compare_PWM_Signal_Clear (CCP_SFRmap* CCPx, uint32_t Channel,
                    FunctionalState NewState);
void CCP_Compare_Check_Config (CCP_SFRmap* CCPx, uint32_t CompareSelect);
void CCP_Channel_Output_Control (CCP_SFRmap* CCPx, uint32_t Channel,
                    uint32_t ChannelOutputCtl);
void CCP_Single_Pulse_Shut_Enable (CCP_SFRmap* CCPx, FunctionalState NewState);
void CCP_Single_Pulse_Enable (CCP_SFRmap* CCPx, FunctionalState NewState);
void CCP_PWM_Input_Measurement_Config (CCP_SFRmap* CCPx,
                    FunctionalState NewState);
void CCP_Input_XOR_Config (CCP_SFRmap* CCPx, FunctionalState NewState);
void CCP_Channel_DMA_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    FunctionalState NewState);
void CCP_Generate_Trigger_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    FunctionalState NewState);
void CCP_USART_Receive_Config (CCP_SFRmap* CCPx, FunctionalState NewState);

FlagStatus CCP_Get_Channel_Trigger_INT_Flag (CCP_SFRmap* CCPx, uint32_t Channel);
FlagStatus CCP_Get_Trigger_DMA_INT_Flag (CCP_SFRmap* CCPx, uint32_t Channel);
void CCP_Channel_INT_Config (CCP_SFRmap* CCPx, uint32_t Channel,
                    FunctionalState NewState);
void CCP_Clear_Channel_INT_Flag (CCP_SFRmap* CCPx, uint32_t Channel);







typedef struct
{
    uint16_t m_Counter;
    uint16_t m_Period;
    uint16_t m_Prescaler;
    uint16_t m_Postscaler;

    uint32_t m_CounterMode;

    uint16_t m_Clock;

    uint16_t m_WorkMode;

    uint16_t m_EXPulseSync;

} ATIM_InitTypeDef;




typedef struct
{
    uint32_t m_Channel;

    uint32_t m_Mode;

    FunctionalState m_PWMInput;

    FunctionalState m_XORMode;

} ECCP_CaptureInitTypeDef;




typedef struct
{
    uint32_t m_Channel;

    uint32_t m_Mode;

    uint16_t m_DutyRatio;

    uint8_t m_DeadTime;

    uint8_t m_OutputMode;

    uint16_t m_HOutputCtl;

    uint16_t m_LOutputCtl;

    FunctionalState m_PhaseMove;

    FunctionalState m_SinglePWM;

    FunctionalState m_CloseTimer;

} ECCP_PWMInitTypeDef;
# 1001 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_tim.h"
void ATIM_X_Configuration(ATIM_SFRmap* ATIMx, ATIM_InitTypeDef* atimInitStruct);
void ATIM_Z_Configuration(ATIM_SFRmap* ATIMx, ATIM_InitTypeDef* atimInitStruct);
void ATIM_Struct_Init (ATIM_InitTypeDef* atimInitStruct);
void ATIM_X_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Updata_Configuration (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter,
                    uint32_t UpdataOutput, uint32_t UpdataImmediately);
void ATIM_Z_Updata_Configuration (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter,
                    uint32_t UpdataOutput, uint32_t UpdataImmediately);
void ATIM_X_Updata_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Updata_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Set_Counter (ATIM_SFRmap* ATIMx, uint16_t Counter);
void ATIM_Z_Set_Counter (ATIM_SFRmap* ATIMx, uint16_t Counter);
void ATIM_X_Set_Period (ATIM_SFRmap* ATIMx, uint16_t Period);
void ATIM_Z_Set_Period (ATIM_SFRmap* ATIMx, uint16_t Period);
void ATIM_X_Set_Prescaler (ATIM_SFRmap* ATIMx, uint16_t Prescaler);
void ATIM_Z_Set_Prescaler (ATIM_SFRmap* ATIMx, uint16_t Prescaler);
void ATIM_X_Counter_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t CounterMode);
void ATIM_Z_Counter_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t CounterMode);
void ATIM_X_Clock_Config (ATIM_SFRmap* ATIMx, uint32_t NewClock);
void ATIM_Z_Clock_Config (ATIM_SFRmap* ATIMx, uint32_t NewClock);
void ATIM_X_Postscaler_Config (ATIM_SFRmap* ATIMx, uint32_t NewPostscaler);
void ATIM_Z_Postscaler_Config (ATIM_SFRmap* ATIMx, uint32_t NewPostscaler);
void ATIM_X_External_Pulse_Sync_Config (ATIM_SFRmap* ATIMx, uint32_t PulseSync);
void ATIM_Z_External_Pulse_Sync_Config (ATIM_SFRmap* ATIMx, uint32_t PulseSync);
void ATIM_X_Work_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t NewState);
void ATIM_Z_Work_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t NewState);
DIRStatus ATIM_X_Get_Direction (ATIM_SFRmap* ATIMx);
DIRStatus ATIM_Z_Get_Direction (ATIM_SFRmap* ATIMx);
void ATIM_X_Overflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Overflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Underflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Underflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_TriggerAD_Config (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_TriggerAD_Config (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Set_TriggerAD_Signal (ATIM_SFRmap* ATIMx,
                    uint16_t CompareAD0, uint16_t CompareAD1);
void ATIM_Z_Set_TriggerAD_Signal (ATIM_SFRmap* ATIMx, uint16_t CompareAD);
void ATIM_X_Updata_Immediately_Config (ATIM_SFRmap* ATIMx,
                    FunctionalState NewState);
void ATIM_Z_Updata_Immediately_Config (ATIM_SFRmap* ATIMx,
                    FunctionalState NewState);
void ATIM_X_Updata_Output_Ctl (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Updata_Output_Ctl (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Updata_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Updata_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Set_Updata_Counter (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter);
void ATIM_Z_Set_Updata_Counter (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter);
void ATIM_X_Slave_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t SlaveMode);
void ATIM_Z_Slave_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t SlaveMode);
void ATIM_Master_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t MasterMode);
void ATIM_Master_Slave_Snyc_Enable (ATIM_SFRmap* ATIMx,
                    FunctionalState NewState);
void ATIM_Trigger_Select_Config (ATIM_SFRmap* ATIMx,
                    FunctionalState TriggerSelect);
void ATIM_Timer_Unite_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
uint16_t ATIM_X_Get_Counter (ATIM_SFRmap* ATIMx);
uint16_t ATIM_Z_Get_Counter (ATIM_SFRmap* ATIMx);
uint16_t ATIM_X_Get_Period (ATIM_SFRmap* ATIMx);
uint16_t ATIM_Z_Get_Period (ATIM_SFRmap* ATIMx);
uint16_t ATIM_X_Get_Prescaler (ATIM_SFRmap* ATIMx);
uint16_t ATIM_Z_Get_Prescaler (ATIM_SFRmap* ATIMx);

void ATIM_X_Updata_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Updata_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Overflow_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Overflow_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Trigger_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Updata_DMA_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_Z_Updata_DMA_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
void ATIM_X_Trigger_DMA_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState);
FlagStatus ATIM_X_Get_Updata_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_Z_Get_Updata_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_X_Get_Overflow_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_Z_Get_Overflow_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_X_Get_Trigger_INT_Flag (ATIM_SFRmap* ATIMx);
void ATIM_X_Generate_Trigger_Config (ATIM_SFRmap* ATIMx,
                    FunctionalState NewState);
FlagStatus ATIM_X_Get_Updata_DMA_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_Z_Get_Updata_DMA_INT_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ATIM_X_Get_Trigger_DMA_INT_Flag (ATIM_SFRmap* ATIMx);
void ATIM_X_Clear_Updata_INT_Flag (ATIM_SFRmap* ATIMx);
void ATIM_Z_Clear_Updata_INT_Flag (ATIM_SFRmap* ATIMx);
void ATIM_X_Clear_Overflow_INT_Flag (ATIM_SFRmap* ATIMx);
void ATIM_Z_Clear_Overflow_INT_Flag (ATIM_SFRmap* ATIMx);
void ATIM_X_Clear_Trigger_INT_Flag (ATIM_SFRmap* ATIMx);

void ECCP_Compare_Configuration(ECCP_SFRmap* ECCPx, uint32_t Channel,
                    uint32_t CompareMode, uint16_t CompareValue);
void ECCP_Capture_Configuration (ECCP_SFRmap* ECCPx,
                    ECCP_CaptureInitTypeDef* eccpInitStruct);
void ECCP_Capture_Struct_Init (ECCP_CaptureInitTypeDef* eccpInitStruct);
void ECCP_PWM_Configuration (ECCP_SFRmap* ECCPx,
                    ECCP_PWMInitTypeDef* ECCP_InitStruct);
void ECCP_PWM_Struct_Init (ECCP_PWMInitTypeDef* ECCP_InitStruct);
void ECCP_Capture_Mode_Config (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, uint32_t EdgeConfig);
void ECCP_Compare_Mode_Config (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, uint32_t CmpConfig);
void ECCP_PWM_Mode_Config (ECCP_SFRmap* ECCPx, uint32_t PWMConfig);
uint16_t ECCP_Get_Capture_Result (ECCP_SFRmap* ECCPx, uint32_t Channel);
void ECCP_Set_Compare_Result (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, uint16_t Value);
void ECCP_Generate_Trigger_Config (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, FunctionalState NewState);
void ECCP_PWM_Input_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Input_XOR_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Single_Pulse_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Single_Pulse_Shut_Enable (ECCP_SFRmap* ECCPx,
                    FunctionalState NewState);
void ECCP_PWM_Restart_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Dead_Time_Config (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, uint8_t DeadTime);
void ECCP_Channel_Output_Control (ECCP_SFRmap* ECCPx, uint32_t Channel,
                    uint32_t Port, uint32_t ChannelOutputCtl);
void ECCP_Channel_Output_Mode (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, uint32_t ChannelOutputMode);
void ECCP_Channel_Work_State_Config (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, uint32_t WorkingState);
void
ECCP_CHANNEL4_Shutdown_SEL (ECCP_SFRmap* ECCPx,
                    uint32_t ShutDownSignal);
FlagStatus ECCP_Get_Channel_Work_State (ECCP_SFRmap* ECCPx, uint32_t Channel);
void ECCP_Channel_Shutdown_Signal (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, uint32_t ShutDownSignal);
void ECCP_Channel_Pin_Ctl (ECCP_SFRmap* ECCPx, uint32_t Channel,
                    uint32_t Port, uint32_t ChannelPinCtl);
void ECCP_Zero_Clock_Config (ECCP_SFRmap* ECCPx, uint32_t ZeroClock);
void ECCP_Channel_Pin_Tristate_Enable (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, uint32_t Port, uint32_t PinTristateCtl);

void ECCP_Channel_INT_Enable (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, FunctionalState NewState);
void ECCP_X_Turn_off_DMA_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Channel_DMA_Enable (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, FunctionalState NewState);
FlagStatus ECCP_Get_Channel_Trigger_INT_Flag (ECCP_SFRmap* ECCPx,
                    uint32_t Channel);
FlagStatus ECCP_X_Get_Turn_off_DMA_Flag (ATIM_SFRmap* ATIMx);
FlagStatus ECCP_Get_Trigger_DMA_INT_Flag (ECCP_SFRmap* ECCPx, uint32_t Channel);
void ECCP_Clear_Channel_INT_Flag (ECCP_SFRmap* ECCPx, uint32_t Channel);
void ECCP_PWM_Move_Phase_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState);
void ECCP_Channel_Zero_Detect_Sequential_Ctl (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, uint32_t NewState);
FlagStatus ECCP_Get_Channel_Zero_Detection_State (ECCP_SFRmap* ECCPx,
                    uint32_t Channel);
void ECCP_Clear_Channel_Zero_Detection_State (ECCP_SFRmap* ECCPx,
                    uint32_t Channel);
void ECCP_Channel_Zero_Detect_Enable (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, uint32_t NewState);
void ECCP_Channel_Zero_Voltage_Config (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, uint32_t ZeroDetectVoltage);
# 1161 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_tim.h"
typedef struct
{
    uint32_t m_Counter;
    uint32_t m_Period;
    uint32_t m_Prescaler;
    uint32_t m_Phase;
    uint32_t m_CounterMode;

    uint32_t m_Sync;

    uint32_t m_Clock;

    uint32_t m_WorkMode;

    FunctionalState m_PhaseEn;

    uint32_t m_PhaseDirection;

    FunctionalState m_GateEn;

} ETIM_InitTypeDef;
# 17 "../system/src/kf32a_basic_atim.c" 2
# 1 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_rst.h" 1
# 44 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_rst.h"
void RST_CTL0_Peripheral_Reset_Enable(uint32_t RST_CTL0Periph,
                    FunctionalState NewState);
void RST_CTL1_Peripheral_Reset_Enable(uint32_t RST_CTL1Periph,
                    FunctionalState NewState);
void RST_CTL2_Peripheral_Reset_Enable(uint32_t RST_CTL2Periph,
                    FunctionalState NewState);
void RST_CTL3_Peripheral_Reset_Enable(uint32_t RST_CTL3Periph,
                    FunctionalState NewState);
# 18 "../system/src/kf32a_basic_atim.c" 2
# 1 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_pclk.h" 1
# 40 "D:/zzc/project/pro_2022/pro_12/SYYL-AK-221208/kf32/system/inc/kf32a_basic_pclk.h"
void PCLK_CTL0_Peripheral_Clock_Enable (uint32_t PCLK_CTL0_bit,
                    FunctionalState NewState);
void PCLK_CTL1_Peripheral_Clock_Enable (uint32_t PCLK_CTL1_bit,
                    FunctionalState NewState);
void PCLK_CTL2_Peripheral_Clock_Enable (uint32_t PCLK_CTL2_bit,
                    FunctionalState NewState);
void PCLK_CTL3_Peripheral_Clock_Enable (uint32_t PCLK_CTL3_bit,
                    FunctionalState NewState);
# 19 "../system/src/kf32a_basic_atim.c" 2
# 64 "../system/src/kf32a_basic_atim.c"
void ATIM_X_Configuration(ATIM_SFRmap* ATIMx,
                    ATIM_InitTypeDef* atimInitStruct)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);


    ATIMx->TXCNT = (uint32_t)atimInitStruct->m_Counter;


    ATIMx->TXPPX = (uint32_t)atimInitStruct->m_Period;


    ATIMx->TXPRSC = (uint32_t)atimInitStruct->m_Prescaler;







    tmpreg = ((uint32_t)atimInitStruct->m_Postscaler << (3))
             | (atimInitStruct->m_CounterMode)
             | ((uint32_t)atimInitStruct->m_Clock)
             | ((uint32_t)atimInitStruct->m_WorkMode)
             | ((uint32_t)atimInitStruct->m_EXPulseSync);
    ATIMx->TXCTL = SFR_Config (ATIMx->TXCTL,
                          ~(((uint32_t)1<<((0))) | ((uint32_t)1<<((1))) | ((uint32_t)0xF<<((3))) | ((uint32_t)3<<((8))) | ((uint32_t)7<<((13)))),
                          tmpreg);
}







void ATIM_Z_Configuration(ATIM_SFRmap* ATIMx,
                    ATIM_InitTypeDef* atimInitStruct)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);


    ATIMx->TZCNT = (uint32_t)atimInitStruct->m_Counter;


    ATIMx->TZPPZ = (uint32_t)atimInitStruct->m_Period;


    ATIMx->TZPRSC = (uint32_t)atimInitStruct->m_Prescaler;







    tmpreg = ((uint32_t)atimInitStruct->m_Postscaler << (3))
             | (atimInitStruct->m_CounterMode)
             | ((uint32_t)atimInitStruct->m_Clock)
             | ((uint32_t)atimInitStruct->m_WorkMode)
             | ((uint32_t)atimInitStruct->m_EXPulseSync);
    ATIMx->TZCTL = SFR_Config (ATIMx->TZCTL,
                          ~(((uint32_t)1<<((0))) | ((uint32_t)1<<((1))) | ((uint32_t)0xF<<((3))) | ((uint32_t)3<<((8))) | ((uint32_t)7<<((13)))),
                          tmpreg);
}






void
ATIM_Struct_Init (ATIM_InitTypeDef* atimInitStruct)
{

    atimInitStruct->m_Counter = 0x00000000;

    atimInitStruct->m_Period = 0x0000FFFF;

    atimInitStruct->m_Prescaler = 0x00000000;

    atimInitStruct->m_Postscaler = 0x0;

    atimInitStruct->m_CounterMode = ((uint32_t)0x4 << (13));

    atimInitStruct->m_Clock = ((uint32_t)0x0 << (8));

    atimInitStruct->m_WorkMode = ((uint32_t)0 << (0));

    atimInitStruct->m_EXPulseSync = ((uint32_t)0x0 << (1));
}
# 179 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((2)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((2)));
    }
}
# 206 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((2)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((2)));
    }
}
# 236 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Updata_Configuration (ATIM_SFRmap* ATIMx,
                    uint8_t UpdataCounter,
                    uint32_t UpdataOutput,
                    uint32_t UpdataImmediately)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    ATIMx->TXUDTIM = UpdataCounter;




    tmpreg = (UpdataOutput << (2))
             | (UpdataImmediately << (3));
    ATIMx->PXUDCTL = SFR_Config (ATIMx->PXUDCTL,
                          ~(((uint32_t)1<<((2))) | ((uint32_t)1<<((3)))),
                          tmpreg);
}
# 272 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Updata_Configuration (ATIM_SFRmap* ATIMx,
                    uint8_t UpdataCounter,
                    uint32_t UpdataOutput,
                    uint32_t UpdataImmediately)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    ATIMx->TZUDTIM = UpdataCounter;




    tmpreg = (UpdataOutput << (4))
             | (UpdataImmediately << (5));
    ATIMx->PXUDCTL = SFR_Config (ATIMx->PXUDCTL,
                          ~(((uint32_t)1<<((4))) | ((uint32_t)1<<((5)))),
                          tmpreg);
}
# 305 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Updata_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((0)));
    }
}
# 332 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Updata_Cmd (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((1)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((1)));
    }
}







void
ATIM_X_Set_Counter (ATIM_SFRmap* ATIMx, uint16_t Counter)
{

    ((void)0);


    ATIMx->TXCNT = Counter;
}







void
ATIM_Z_Set_Counter (ATIM_SFRmap* ATIMx, uint16_t Counter)
{

    ((void)0);


    ATIMx->TZCNT = Counter;
}







void
ATIM_X_Set_Period (ATIM_SFRmap* ATIMx, uint16_t Period)
{

    ((void)0);


    ATIMx->TXPPX = Period;
}







void
ATIM_Z_Set_Period (ATIM_SFRmap* ATIMx, uint16_t Period)
{

    ((void)0);


    ATIMx->TZPPZ = Period;
}







void
ATIM_X_Set_Prescaler (ATIM_SFRmap* ATIMx, uint16_t Prescaler)
{

    ((void)0);


    ATIMx->TXPRSC = Prescaler;
}







void
ATIM_Z_Set_Prescaler (ATIM_SFRmap* ATIMx, uint16_t Prescaler)
{

    ((void)0);


    ATIMx->TZPRSC = Prescaler;
}
# 460 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Counter_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t CounterMode)
{

    ((void)0);
    ((void)0);


    ATIMx->TXCTL = SFR_Config (ATIMx->TXCTL,
                          ~((uint32_t)7<<((13))),
                          CounterMode);
}
# 485 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Counter_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t CounterMode)
{

    ((void)0);
    ((void)0);


    ATIMx->TZCTL = SFR_Config (ATIMx->TZCTL,
                          ~((uint32_t)7<<((13))),
                          CounterMode);
}
# 508 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Clock_Config (ATIM_SFRmap* ATIMx, uint32_t NewClock)
{

    ((void)0);
    ((void)0);


    ATIMx->TXCTL = SFR_Config (ATIMx->TXCTL,
                          ~((uint32_t)3<<((8))),
                          NewClock);
}
# 531 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Clock_Config (ATIM_SFRmap* ATIMx, uint32_t NewClock)
{

    ((void)0);
    ((void)0);


    ATIMx->TZCTL = SFR_Config (ATIMx->TZCTL,
                          ~((uint32_t)3<<((8))),
                          NewClock);
}
# 566 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Postscaler_Config (ATIM_SFRmap* ATIMx, uint32_t NewPostscaler)
{
 uint32_t tmpreg = 0;

    ((void)0);
    ((void)0);


    tmpreg = NewPostscaler << (3);
    ATIMx->TXCTL = SFR_Config (ATIMx->TXCTL,
                          ~((uint32_t)0xF<<((3))),
                          tmpreg);
}
# 603 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Postscaler_Config (ATIM_SFRmap* ATIMx, uint32_t NewPostscaler)
{
 uint32_t tmpreg = 0;

    ((void)0);
    ((void)0);


    tmpreg = NewPostscaler << (3);
    ATIMx->TZCTL = SFR_Config (ATIMx->TZCTL,
                          ~((uint32_t)0xF<<((3))),
                          tmpreg);
}
# 627 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_External_Pulse_Sync_Config (ATIM_SFRmap* ATIMx, uint32_t PulseSync)
{

    ((void)0);
    ((void)0);


    if (PulseSync != ((uint32_t)0x0 << (1)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((1)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((1)));
    }
}
# 656 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_External_Pulse_Sync_Config (ATIM_SFRmap* ATIMx, uint32_t PulseSync)
{

    ((void)0);
    ((void)0);


    if (PulseSync != ((uint32_t)0x0 << (1)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((1)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((1)));
    }
}
# 685 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Work_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != ((uint32_t)0 << (0)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((0)));
    }
}
# 714 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Work_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != ((uint32_t)0 << (0)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((0)));
    }
}






DIRStatus
ATIM_X_Get_Direction (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->TXCTL & ((uint32_t)1<<((7))))
    {

        return DIR_UP;
    }
    else
    {

        return DIR_DOWN;
    }
}






DIRStatus
ATIM_Z_Get_Direction (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->TZCTL & ((uint32_t)1<<((7))))
    {

        return DIR_UP;
    }
    else
    {

        return DIR_DOWN;
    }
}
# 789 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Overflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((12)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((12)));
    }
}
# 816 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Overflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((12)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((12)));
    }
}
# 843 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Underflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((11)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((11)));
    }
}
# 870 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Underflow_AD_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((11)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((11)));
    }
}
# 897 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_TriggerAD_Config (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((10)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TXCTL)),"i"((10)));
    }
}
# 924 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_TriggerAD_Config (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((10)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->TZCTL)),"i"((10)));
    }
}
# 951 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Set_TriggerAD_Signal (ATIM_SFRmap* ATIMx,
                    uint16_t CompareAD0, uint16_t CompareAD1)
{

    ((void)0);


    ATIMx->TXCCR0 = CompareAD0;
    ATIMx->TXCCR1 = CompareAD1;
}







void
ATIM_Z_Set_TriggerAD_Signal (ATIM_SFRmap* ATIMx,
                    uint16_t CompareAD)
{

    ((void)0);


    ATIMx->TZCCR0 = CompareAD;
}
# 987 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Updata_Immediately_Config (ATIM_SFRmap* ATIMx,
                    FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((3)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((3)));
    }
}
# 1015 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Updata_Immediately_Config (ATIM_SFRmap* ATIMx,
                    FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((5)));
    }
}
# 1043 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Updata_Output_Ctl (ATIM_SFRmap* ATIMx,
                    FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((2)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((2)));
    }
}
# 1072 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Updata_Output_Ctl (ATIM_SFRmap* ATIMx,
                    FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((4)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((4)));
    }
}
# 1100 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Updata_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((0)));
    }
}
# 1127 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Updata_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((1)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->PXUDCTL)),"i"((1)));
    }
}







void
ATIM_X_Set_Updata_Counter (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter)
{

    ((void)0);


    ATIMx->TXUDTIM = UpdataCounter;
}







void
ATIM_Z_Set_Updata_Counter (ATIM_SFRmap* ATIMx, uint8_t UpdataCounter)
{

    ((void)0);


    ATIMx->TZUDTIM = UpdataCounter;
}
# 1191 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Slave_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t SlaveMode)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = SlaveMode << (3);
    ATIMx->ECCPXCTL2 = SFR_Config (ATIMx->ECCPXCTL2,
                          ~((uint32_t)7<<((3))),
                          tmpreg);
}
# 1219 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Slave_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t SlaveMode)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = SlaveMode << (13);
    ATIMx->ECCPXCTL2 = SFR_Config (ATIMx->ECCPXCTL2,
                          ~((uint32_t)7<<((13))),
                          tmpreg);
}
# 1248 "../system/src/kf32a_basic_atim.c"
void
ATIM_Master_Mode_Config (ATIM_SFRmap* ATIMx, uint32_t MasterMode)
{

    ((void)0);
    ((void)0);


    ATIMx->ECCPXCTL2 = SFR_Config (ATIMx->ECCPXCTL2,
                          ~((uint32_t)7<<((0))),
                          MasterMode);
}
# 1268 "../system/src/kf32a_basic_atim.c"
void
ATIM_Master_Slave_Snyc_Enable (ATIM_SFRmap* ATIMx,
                    FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXCTL2)),"i"((9)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXCTL2)),"i"((9)));
    }
}
# 1304 "../system/src/kf32a_basic_atim.c"
void
ATIM_Trigger_Select_Config (ATIM_SFRmap* ATIMx,
                    uint32_t TriggerSelect)
{

    ((void)0);
    ((void)0);


    ATIMx->ECCPXCTL2 = SFR_Config (ATIMx->ECCPXCTL2,
                          ~((uint32_t)7<<((6))),
                          TriggerSelect);
}
# 1325 "../system/src/kf32a_basic_atim.c"
void
ATIM_Timer_Unite_Enable (ATIM_SFRmap* ATIMx,
                    FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXCTL3)),"i"((1)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXCTL3)),"i"((1)));
    }
}






uint16_t
ATIM_X_Get_Counter (ATIM_SFRmap* ATIMx)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = ATIMx->TXCNT;

    return tmpreg;
}






uint16_t
ATIM_Z_Get_Counter (ATIM_SFRmap* ATIMx)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = ATIMx->TZCNT;

    return tmpreg;
}






uint16_t
ATIM_X_Get_Period (ATIM_SFRmap* ATIMx)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = ATIMx->TXPPX;

    return tmpreg;
}






uint16_t
ATIM_Z_Get_Period (ATIM_SFRmap* ATIMx)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = ATIMx->TZPPZ;

    return tmpreg;
}






uint16_t
ATIM_X_Get_Prescaler (ATIM_SFRmap* ATIMx)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = ATIMx->TXPRSC;

    return tmpreg;
}






uint16_t
ATIM_Z_Get_Prescaler (ATIM_SFRmap* ATIMx)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = ATIMx->TZPRSC;

    return tmpreg;
}
# 1476 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Updata_INT_Enable (ATIM_SFRmap* ATIMx,
                    FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((8)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((8)));
    }
}
# 1505 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Updata_INT_Enable (ATIM_SFRmap* ATIMx,
                    FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((7)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((7)));
    }
}
# 1534 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Overflow_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((6)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((6)));
    }
}
# 1562 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Overflow_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((5)));
    }
}
# 1590 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Trigger_INT_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((4)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXIE)),"i"((4)));
    }
}
# 1618 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Updata_DMA_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXDE)),"i"((7)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXDE)),"i"((7)));
    }
}
# 1646 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Updata_DMA_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXDE)),"i"((6)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXDE)),"i"((6)));
    }
}
# 1674 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Trigger_DMA_Enable (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXDE)),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXDE)),"i"((5)));
    }
}







FlagStatus
ATIM_X_Get_Updata_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXEGIF & ((uint32_t)1<<((14))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus
ATIM_Z_Get_Updata_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXEGIF & ((uint32_t)1<<((13))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus
ATIM_X_Get_Overflow_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXEGIF & ((uint32_t)1<<((12))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus
ATIM_Z_Get_Overflow_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXEGIF & ((uint32_t)1<<((11))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus
ATIM_X_Get_Trigger_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXEGIF & ((uint32_t)1<<((10))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 1826 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Generate_Trigger_Config (ATIM_SFRmap* ATIMx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXEGIF)),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXEGIF)),"i"((5)));
    }
}







FlagStatus
ATIM_X_Get_Updata_DMA_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXDF & ((uint32_t)1<<((7))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus
ATIM_Z_Get_Updata_DMA_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXDF & ((uint32_t)1<<((6))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus
ATIM_X_Get_Trigger_DMA_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXDF & ((uint32_t)1<<((5))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 1928 "../system/src/kf32a_basic_atim.c"
void
ATIM_X_Clear_Updata_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((8)));
    while((ATIMx->ECCPXEGIF & ((uint32_t)1<<((14))))>>(14));
    __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((8)));
}
# 1947 "../system/src/kf32a_basic_atim.c"
void
ATIM_Z_Clear_Updata_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((7)));
    while((ATIMx->ECCPXEGIF & ((uint32_t)1<<((13))))>>(13));
    __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((7)));
}







void
ATIM_X_Clear_Overflow_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((6)));
    while((ATIMx->ECCPXEGIF & ((uint32_t)1<<((12))))>>(12));
    __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((6)));
}







void
ATIM_Z_Clear_Overflow_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((5)));
    while((ATIMx->ECCPXEGIF & ((uint32_t)1<<((11))))>>(11));
    __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((5)));
}







void
ATIM_X_Clear_Trigger_INT_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    __asm volatile("SET [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((4)));
    while((ATIMx->ECCPXEGIF & ((uint32_t)1<<((10))))>>(10));
    __asm volatile("CLR [%0], #%1"::"r"(&(ATIMx->ECCPXSRIC)),"i"((4)));
}
# 2040 "../system/src/kf32a_basic_atim.c"
void
ECCP_Compare_Configuration(ECCP_SFRmap* ECCPx, uint32_t Channel,
                    uint32_t CompareMode, uint16_t CompareValue)
{
    uint32_t tmpreg = 0;
    uint32_t tmpreg1 = 0;


    ((void)0);
    ((void)0);
    ((void)0);



    tmpreg = 4 * Channel;
    ECCPx->ECCPXCTL1 = SFR_Config (ECCPx->ECCPXCTL1,
                          ~(((uint32_t)0xF<<((0))) << tmpreg),
                          CompareMode << tmpreg);



    tmpreg1 = (uint32_t)ECCPx;
    tmpreg1 = tmpreg1 + ((uint32_t)0x84) + tmpreg;

    *(volatile uint32_t*)tmpreg1 = CompareValue;
}
# 2074 "../system/src/kf32a_basic_atim.c"
void
ECCP_Capture_Configuration (ECCP_SFRmap* ECCPx,
                    ECCP_CaptureInitTypeDef* eccpInitStruct)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);



    tmpreg = 4 * eccpInitStruct->m_Channel;
    ECCPx->ECCPXCTL1 = SFR_Config (ECCPx->ECCPXCTL1,
                          ~(((uint32_t)0xF<<((0))) << tmpreg),
                          eccpInitStruct->m_Mode << tmpreg);




    tmpreg = (eccpInitStruct->m_PWMInput << (12))
           | (eccpInitStruct->m_PWMInput << (11));
    ECCPx->ECCPXCTL2 = SFR_Config (ECCPx->ECCPXCTL2,
                          ~(((uint32_t)1<<((12))) | ((uint32_t)1<<((11)))),
                          tmpreg);
}






void
ECCP_Capture_Struct_Init (ECCP_CaptureInitTypeDef* eccpInitStruct)
{

    eccpInitStruct->m_Channel = ((uint32_t)0x0);

    eccpInitStruct->m_Mode = ((uint32_t)0x0);

    eccpInitStruct->m_PWMInput = FALSE;

    eccpInitStruct->m_XORMode = FALSE;
}
# 2129 "../system/src/kf32a_basic_atim.c"
void
ECCP_PWM_Configuration (ECCP_SFRmap* ECCPx,
                    ECCP_PWMInitTypeDef* eccpInitStruct)
{
    uint32_t tmpreg = 0;
    uint32_t tmpreg1 = 0;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);



    tmpreg = 4 * eccpInitStruct->m_Channel;
    ECCPx->ECCPXCTL1 = SFR_Config (ECCPx->ECCPXCTL1,
                          ~(((uint32_t)0xF<<((0))) << tmpreg),
                          eccpInitStruct->m_Mode << tmpreg);



    tmpreg1 = (uint32_t)ECCPx;
    tmpreg1 = tmpreg1 + ((uint32_t)0x84) + tmpreg;

    *(volatile uint32_t*)tmpreg1
        = (uint32_t)eccpInitStruct->m_DutyRatio;



    ECCPx->PXUDCTL = SFR_Config (ECCPx->PXUDCTL,
                        ~((uint32_t)1<<((6))),
                        eccpInitStruct->m_PhaseMove);



    if (((uint32_t)0x3) == eccpInitStruct->m_Channel)
    {
        tmpreg = ((uint32_t)eccpInitStruct->m_DeadTime
                    << (8));
        ECCPx->PXDTCTL = SFR_Config (ECCPx->PXDTCTL,
                            ~((uint32_t)0xFF<<((8))),
                            tmpreg);
    }
    else
    {
        tmpreg = ((uint32_t)eccpInitStruct->m_DeadTime
                    << (0));
        ECCPx->PXDTCTL = SFR_Config (ECCPx->PXDTCTL,
                            ~((uint32_t)0xFF<<((0))),
                            tmpreg);
    }



    tmpreg = eccpInitStruct->m_Channel;
    ECCPx->PXATRCTL = SFR_Config (ECCPx->PXATRCTL,
                          ~(((uint32_t)1<<((8))) << tmpreg),
                          (uint32_t)eccpInitStruct->m_OutputMode << tmpreg);




    tmpreg = 4 * eccpInitStruct->m_Channel;
    tmpreg1 = ((uint32_t)eccpInitStruct->m_HOutputCtl << (2))
            | ((uint32_t)eccpInitStruct->m_LOutputCtl << (0));
    ECCPx->PWMXOC = SFR_Config (ECCPx->PWMXOC,
                          ~((((uint32_t)3<<((0))) | ((uint32_t)3<<((2))))
                            << tmpreg),
                          tmpreg1 << tmpreg);



    tmpreg = (eccpInitStruct->m_SinglePWM << (10));
    ECCPx->ECCPXCTL2 = SFR_Config (ECCPx->ECCPXCTL2,
                          ~(((uint32_t)1<<((10)))),
                          tmpreg);



    tmpreg = (eccpInitStruct->m_CloseTimer << (0));
    ECCPx->ECCPXCTL3 = SFR_Config (ECCPx->ECCPXCTL3,
                          ~((uint32_t)1<<((0))),
                          tmpreg);
}






void
ECCP_PWM_Struct_Init (ECCP_PWMInitTypeDef* eccpInitStruct)
{

    eccpInitStruct->m_Channel = ((uint32_t)0x0);

    eccpInitStruct->m_Mode = ((uint32_t)0x0);

    eccpInitStruct->m_DutyRatio = 0x0000;

    eccpInitStruct->m_DeadTime = 0x00;

    eccpInitStruct->m_OutputMode = ((uint8_t)0x0);

    eccpInitStruct->m_HOutputCtl = ((uint16_t)0x0);

    eccpInitStruct->m_LOutputCtl = ((uint16_t)0x0);

    eccpInitStruct->m_PhaseMove = FALSE;

    eccpInitStruct->m_SinglePWM = FALSE;

    eccpInitStruct->m_CloseTimer = FALSE;
}
# 2267 "../system/src/kf32a_basic_atim.c"
void
ECCP_Capture_Mode_Config (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, uint32_t EdgeConfig)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = EdgeConfig << (4 * Channel);
    ECCPx->ECCPXCTL1 = SFR_Config (ECCPx->ECCPXCTL1,
                          ~(((uint32_t)0xF<<((0))) << (4 * Channel)),
                          tmpreg);
}
# 2303 "../system/src/kf32a_basic_atim.c"
void
ECCP_Compare_Mode_Config (ECCP_SFRmap* ECCPx,
                    uint32_t Channel, uint32_t CmpConfig)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = CmpConfig << (4 * Channel);
    ECCPx->ECCPXCTL1 = SFR_Config (ECCPx->ECCPXCTL1,
                          ~(((uint32_t)0xF<<((0))) << (4 * Channel)),
                          tmpreg);
}
# 2332 "../system/src/kf32a_basic_atim.c"
void
ECCP_PWM_Mode_Config (ECCP_SFRmap* ECCPx, uint32_t PWMConfig)
{
 uint32_t tmpreg = 0;

    ((void)0);
    ((void)0);


    tmpreg = PWMConfig << (0);
    ECCPx->ECCPXCTL1 = SFR_Config (ECCPx->ECCPXCTL1,
                          ~((uint32_t)0xF<<((0))),
                          tmpreg);
}
# 2358 "../system/src/kf32a_basic_atim.c"
uint16_t
ECCP_Get_Capture_Result (ECCP_SFRmap* ECCPx, uint32_t Channel)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = (uint32_t)ECCPx;
    tmpreg = tmpreg + ((uint32_t)0xD0) + (4 * Channel);


    return (*(volatile const uint16_t*) tmpreg);
}
# 2387 "../system/src/kf32a_basic_atim.c"
uint16_t
ECCP_Get_Compare_Result (ECCP_SFRmap* ECCPx, uint32_t Channel)
{
    uint32_t tmpreg = 0;


      ((void)0);
      ((void)0);



    tmpreg = (uint32_t)ECCPx;
    tmpreg = tmpreg + ((uint32_t)0x84) + (4 * Channel);


    return (*(volatile const uint16_t*) tmpreg);
}
# 2418 "../system/src/kf32a_basic_atim.c"
void
ECCP_Set_Compare_Result (ECCP_SFRmap* ECCPx, uint32_t Channel, uint16_t Value)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = (uint32_t)ECCPx;
    tmpreg = tmpreg + ((uint32_t)0x84) + (4 * Channel);


    *(volatile uint32_t*)tmpreg = (uint16_t)Value;
}
# 2448 "../system/src/kf32a_basic_atim.c"
void
ECCP_Generate_Trigger_Config (ECCP_SFRmap* ECCPx, uint32_t Channel,
                    FunctionalState NewState)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        ECCPx->ECCPXEGIF |= ((uint32_t)1<<((1))) << Channel;
    }
    else
    {

        ECCPx->ECCPXEGIF &= ~(((uint32_t)1<<((1))) << Channel);
    }
}
# 2478 "../system/src/kf32a_basic_atim.c"
void
ECCP_PWM_Input_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->ECCPXCTL2)),"i"((12)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->ECCPXCTL2)),"i"((12)));
    }
}
# 2506 "../system/src/kf32a_basic_atim.c"
void
ECCP_Input_XOR_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->ECCPXCTL2)),"i"((11)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->ECCPXCTL2)),"i"((11)));
    }
}
# 2534 "../system/src/kf32a_basic_atim.c"
void
ECCP_Single_Pulse_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->ECCPXCTL2)),"i"((10)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->ECCPXCTL2)),"i"((10)));
    }
}
# 2562 "../system/src/kf32a_basic_atim.c"
void
ECCP_Single_Pulse_Shut_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->ECCPXCTL3)),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->ECCPXCTL3)),"i"((0)));
    }
}
# 2590 "../system/src/kf32a_basic_atim.c"
void
ECCP_PWM_Restart_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->ECCPXCTL3)),"i"((2)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->ECCPXCTL3)),"i"((2)));
    }
}
# 2622 "../system/src/kf32a_basic_atim.c"
void
ECCP_Dead_Time_Config (ECCP_SFRmap* ECCPx, uint32_t Channel,
                    uint8_t DeadTime)
{
    uint32_t tmpreg = 0;

    ((void)0);
    ((void)0);


    if (((uint32_t)0x3) == Channel)
    {

        tmpreg = (uint32_t)DeadTime << (8);
        ECCPx->PXDTCTL = SFR_Config (ECCPx->PXDTCTL,
                             ~((uint32_t)0xFF<<((8))),
                             tmpreg);
    }
    else
    {

        tmpreg = (uint32_t)DeadTime << (0);
        ECCPx->PXDTCTL = SFR_Config (ECCPx->PXDTCTL,
                             ~((uint32_t)0xFF<<((0))),
                             tmpreg);
    }
}
# 2669 "../system/src/kf32a_basic_atim.c"
void
ECCP_Channel_Output_Control (ECCP_SFRmap* ECCPx, uint32_t Channel,
                    uint32_t Port, uint32_t ChannelOutputCtl)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = ChannelOutputCtl << (Port + Channel * 4);
    ECCPx->PWMXOC = SFR_Config (ECCPx->PWMXOC,
                          ~(((uint32_t)3<<((0))) << (Port + Channel * 4)),
                          tmpreg);
}
# 2702 "../system/src/kf32a_basic_atim.c"
void
ECCP_Channel_Output_Mode (ECCP_SFRmap* ECCPx, uint32_t Channel,
                    uint32_t ChannelOutputMode)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = ChannelOutputMode << ((8) + Channel);
    ECCPx->PXATRCTL = SFR_Config (ECCPx->PXATRCTL,
                          ~(((uint32_t)1<<((8))) << Channel),
                          tmpreg);
}
# 2734 "../system/src/kf32a_basic_atim.c"
void
ECCP_Channel_Work_State_Config (ECCP_SFRmap* ECCPx, uint32_t Channel,
                    uint32_t WorkingState)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = WorkingState << ((8) + Channel);
    ECCPx->PXASCTL0 = SFR_Config (ECCPx->PXASCTL0,
                          ~(((uint32_t)1<<((8))) << Channel),
                          tmpreg);
}
# 2763 "../system/src/kf32a_basic_atim.c"
FlagStatus
ECCP_Get_Channel_Work_State (ECCP_SFRmap* ECCPx, uint32_t Channel)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((8))) << Channel;
    if (ECCPx->PXASCTL0 & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 2803 "../system/src/kf32a_basic_atim.c"
void
ECCP_CHANNEL4_Shutdown_SEL (ECCP_SFRmap* ECCPx,
                    uint32_t ShutDownSignal)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    if (ShutDownSignal != ((uint32_t)0x0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->PXASCTL)),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->PXASCTL)),"i"((0)));
    }
}
# 2842 "../system/src/kf32a_basic_atim.c"
void
ECCP_Channel_Shutdown_Signal (ECCP_SFRmap* ECCPx, uint32_t Channel,
                    uint32_t ShutDownSignal)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = ShutDownSignal << (Channel * 2);
    ECCPx->PXASCTL0 = SFR_Config (ECCPx->PXASCTL0,
                          ~(((uint32_t)3<<((0))) << (Channel * 2)),
                          tmpreg);
}
# 2878 "../system/src/kf32a_basic_atim.c"
void
ECCP_Channel_Pin_Ctl (ECCP_SFRmap* ECCPx, uint32_t Channel,
                    uint32_t Port, uint32_t ChannelPinCtl)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = ChannelPinCtl << (Port + Channel * 4);
    ECCPx->PXASCTL1 = SFR_Config (ECCPx->PXASCTL1,
                          ~(((uint32_t)3<<((0))) << (Port + Channel * 2)),
                          tmpreg);
}
# 2914 "../system/src/kf32a_basic_atim.c"
void
ECCP_Zero_Clock_Config (ECCP_SFRmap* ECCPx,
                    uint32_t ZeroClock)
{

    ((void)0);
    ((void)0);


    ECCPx->ZPDCTL0 = SFR_Config (ECCPx->ZPDCTL0,
                          ~(((uint32_t)0xF<<((8)))),
                          ZeroClock);
}
# 2946 "../system/src/kf32a_basic_atim.c"
void
ECCP_Channel_Pin_Tristate_Enable (ECCP_SFRmap* ECCPx, uint32_t Channel,
                    uint32_t Port, uint32_t PinTristateCtl)
{
    uint32_t tmpreg = 0;
    uint32_t tmpreg1 = 0;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = (Port / 2) + (Channel * 2);
    tmpreg1 = PinTristateCtl << tmpreg;
    ECCPx->ZPDPORT = SFR_Config (ECCPx->ZPDPORT,
                          ~(((uint32_t)0xFF<<((0))) << tmpreg),
                          tmpreg1);
}
# 2987 "../system/src/kf32a_basic_atim.c"
void
ECCP_Channel_INT_Enable (ECCP_SFRmap* ECCPx, uint32_t Channel,
                    FunctionalState NewState)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        ECCPx->ECCPXIE |= ((uint32_t)1<<((0))) << Channel;
    }
    else
    {

        ECCPx->ECCPXIE &= ~(((uint32_t)1<<((0))) << Channel);
    }
}
# 3017 "../system/src/kf32a_basic_atim.c"
void
ECCP_X_Turn_off_DMA_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->ECCPXDE)),"i"((4)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->ECCPXDE)),"i"((4)));
    }
}
# 3050 "../system/src/kf32a_basic_atim.c"
void
ECCP_Channel_DMA_Enable (ECCP_SFRmap* ECCPx, uint32_t Channel,
                    FunctionalState NewState)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        ECCPx->ECCPXDE |= ((uint32_t)1<<((0))) << Channel;
    }
    else
    {

        ECCPx->ECCPXDE &= ~(((uint32_t)1<<((0))) << Channel);
    }
}
# 3083 "../system/src/kf32a_basic_atim.c"
FlagStatus
ECCP_Get_Channel_Trigger_INT_Flag (ECCP_SFRmap* ECCPx, uint32_t Channel)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = ((uint32_t)1<<((6))) << Channel;
    if (ECCPx->ECCPXEGIF & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus
ECCP_X_Get_Turn_off_DMA_Flag (ATIM_SFRmap* ATIMx)
{

    ((void)0);


    if (ATIMx->ECCPXDF & ((uint32_t)1<<((4))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 3141 "../system/src/kf32a_basic_atim.c"
FlagStatus
ECCP_Get_Trigger_DMA_INT_Flag (ECCP_SFRmap* ECCPx, uint32_t Channel)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = ((uint32_t)1<<((0))) << Channel;
    if (ECCPx->ECCPXDF & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 3174 "../system/src/kf32a_basic_atim.c"
void
ECCP_Clear_Channel_INT_Flag (ECCP_SFRmap* ECCPx, uint32_t Channel)
{
    uint32_t tmpreg = 0;
    uint32_t tmpreg1 = 0;

    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((0))) << Channel;
    tmpreg1 = ((uint32_t)1<<((6))) << Channel;
    ECCPx->ECCPXSRIC |= tmpreg;

    while((ECCPx->ECCPXEGIF & tmpreg1)>>((6)+Channel));

    ECCPx->ECCPXSRIC &= ~tmpreg;
}
# 3201 "../system/src/kf32a_basic_atim.c"
void
ECCP_PWM_Move_Phase_Enable (ECCP_SFRmap* ECCPx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(ECCPx->PXUDCTL)),"i"((6)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(ECCPx->PXUDCTL)),"i"((6)));
    }
}
# 3234 "../system/src/kf32a_basic_atim.c"
void
ECCP_Channel_Zero_Detect_Sequential_Ctl (ECCP_SFRmap* ECCPx, uint32_t Channel,
                    FunctionalState NewState)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = NewState << (Channel + (4));
    ECCPx->ZPDCTL0 = SFR_Config (ECCPx->ZPDCTL0,
                          ~(((uint32_t)1<<((4))) << Channel),
                          tmpreg);
}
# 3265 "../system/src/kf32a_basic_atim.c"
FlagStatus
ECCP_Get_Channel_Zero_Detection_State (ECCP_SFRmap* ECCPx,
                    uint32_t Channel)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((0))) << Channel;
    if (ECCPx->ZPDCTL0 & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 3300 "../system/src/kf32a_basic_atim.c"
void
ECCP_Clear_Channel_Zero_Detection_State (ECCP_SFRmap* ECCPx,
                    uint32_t Channel)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((0))) << Channel;
    ECCPx->ZPDCTL0 &= ~tmpreg;
}
# 3328 "../system/src/kf32a_basic_atim.c"
void
ECCP_Channel_Zero_Detect_Enable (ECCP_SFRmap* ECCPx, uint32_t Channel,
                    FunctionalState NewState)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = NewState << (Channel + (12));
    ECCPx->ZPDCTL1 = SFR_Config (ECCPx->ZPDCTL1,
                          ~(((uint32_t)1<<((12))) << Channel),
                          tmpreg);
}
# 3363 "../system/src/kf32a_basic_atim.c"
void
ECCP_Channel_Zero_Voltage_Config (ECCP_SFRmap* ECCPx, uint32_t Channel,
                    uint32_t ZeroDetectVoltage)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = ZeroDetectVoltage
             << (Channel * 3 + (0));
    ECCPx->ZPDCTL1 = SFR_Config (ECCPx->ZPDCTL1,
                          ~(((uint32_t)7<<((0))) << (Channel * 3)),
                          tmpreg);
}
