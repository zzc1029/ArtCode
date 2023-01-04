# 1 "../system/src/kf32a_basic_flash.c"
# 1 "/cygdrive/d/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/Release//"
# 1 "<command-line>"
# 1 "../system/src/kf32a_basic_flash.c"
# 16 "../system/src/kf32a_basic_flash.c"
# 1 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/kf32a_basic_flash.h" 1
# 14 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/kf32a_basic_flash.h"
# 1 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h" 1
# 20 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 21 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h" 2
# 1 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_Config.h" 1
# 15 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_Config.h"
# 1 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/__Kungfu32_chipmodel_define.h" 1
# 16 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_Config.h" 2
# 22 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h" 2
# 36 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 171 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 1127 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 1450 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 3317 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
typedef struct SYSCTL_MemMap {
    volatile uint32_t PSW;
    volatile uint32_t MCTL;
    volatile uint32_t ARCTL;
    volatile uint32_t VECTOFF;
          uint32_t RESEVRVE1;
    volatile uint32_t RAMSPA;
    volatile uint32_t MEMCTL;
}SYSCTL_SFRmap;
# 3406 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 4066 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 4721 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
typedef struct SYSTICK_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t RELOAD;
    volatile uint32_t CV;
    volatile uint32_t CALI;
}SYSTICK_SFRmap;
# 4775 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 4963 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 5573 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 6302 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
typedef struct QEI_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CNT;
    volatile uint32_t PPX;
    volatile uint32_t PRSC;
    volatile uint32_t DIER;
}QEI_SFRmap;
# 6420 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
typedef struct DAC_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t DAHD;
    volatile const uint32_t DATA;
    volatile uint32_t CTL1;
                   uint32_t RESERVED;
    volatile uint32_t CAL;
}DAC_SFRmap;
# 6573 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
typedef struct CMP_MemMap {
    volatile uint32_t CTL;





}CMP_SFRmap;
# 8136 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 8679 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
typedef struct IWDT_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t FD;
}IWDT_SFRmap;
# 8712 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
typedef struct WWDT_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t CNT;
}WWDT_SFRmap;
# 8752 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
typedef struct RST_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}RST_SFRmap;
# 9132 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
typedef struct PCLK_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}PCLK_SFRmap;
# 9512 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
typedef struct SPI_MemMap {
    volatile uint32_t BRGR;
    volatile uint32_t CTLR;
    volatile uint32_t BUFR;
    volatile uint32_t STR;
}SPI_SFRmap;
# 9672 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 9934 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 11943 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 12722 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 13117 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
typedef struct BKP_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t INT;
             uint32_t RESERVED[14];
    volatile uint32_t DATA[32];
}BKP_SFRmap;
# 13223 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 13421 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 13471 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
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
# 13925 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
typedef struct EXIC_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t STATE;
       uint32_t RESERVED1;
    volatile uint32_t WRITEBUF;
    volatile uint32_t READBUF;

}EXIC_SFRmap;
# 14005 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
typedef struct CFGL_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t IFR;
}CFGL_SFRmap;
# 14184 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
typedef struct OP_MemMap {
    volatile uint32_t CAL;
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
}OP_SFRmap;
# 14358 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/KF32A_BASIC.h"
static inline uint32_t
SFR_Config (uint32_t SfrMem, uint32_t SfrMask, uint32_t WriteVal)
{
    return ((SfrMem & SfrMask) | (WriteVal));
}
# 15 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/kf32a_basic_flash.h" 2



typedef enum
{
    LOCK = 0,
    UNLOCK = !LOCK
} LockStatus;





typedef union CheckSumStruct
{
    uint32_t m_ResultWord[4];
    uint32_t m_ResultShort[8];
    uint32_t m_ResultByte[16];
}FLASH_CheckSumResult;




typedef struct
{
    uint32_t m_Mode;

    uint32_t m_Zone;

    uint32_t m_Addr;

    uint32_t m_WriteSize;

    uint32_t * m_Data;

}FLASH_ProgramTypeDef;
# 142 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221206/kf32/system/inc/kf32a_basic_flash.h"
LockStatus FLASH_Get_NonVolatile_Memory_Unlock_Status_RAM (void);
void FLASH_Clear_NonVolatile_Memory_Unlock_Status_RAM (void);
void FLASH_Unlock_ISP_RAM (void);
LockStatus FLASH_Get_Flash_Unlock_Status_RAM (void);
void FLASH_Clear_Flash_Unlock_Status_RAM (void);
void FLASH_Unlock_Code_RAM (void);
LockStatus FLASH_Get_Config_Unlock_Status_RAM (void);
void FLASH_Clear_Config_Unlock_Status_RAM (void);
void FLASH_Unlock_User_Config_RAM (void);
void FLASH_Data_Write_Enable_RAM (FunctionalState NewState);
void FLASH_Zone_Config_RAM (uint32_t ZoneSelect);
void FLASH_Standby_Mode_Config_RAM (uint32_t ModeSelect);
void FLASH_IP_Config_RAM (uint32_t FlashIPSelect);
void FLASH_Read_Mode_Config_RAM (uint32_t ReadMode);
void FLASH_Calibration_Updata_Enable_RAM (FunctionalState NewState);
void FLASH_Information_Zone_Wipe_Unlock_Config_RAM (LockStatus NewState);
void FLASH_Half_Page_Write_Size_Config_RAM (uint32_t WriteSize);
void FLASH_Program_Cmd_Config_RAM (uint32_t CmdSelect);
void FLASH_Executive_Cmd_RAM (void);
void FLASH_NonVolatile_Memory_ECC_Enable_RAM (FunctionalState NewState);
void FLASH_Linear_Prefetch_Enable_RAM (FunctionalState NewState);
void FLASH_Period_Number_Config_RAM (uint32_t PeriodNum);
void FLASH_Program_Addr_Config_RAM (uint32_t ProgramAddr);
FlagStatus FLASH_Get_Program_Status_RAM (void);
FlagStatus FLASH_Get_Wipe_Status_RAM (void);
FlagStatus FLASH_Get_Compute_Complete_Status_RAM (void);
void FLASH_Clear_Compute_Complete_Status_RAM (void);

void FLASH_Forbid_Remap_Enable_RAM (FunctionalState NewState);
void FLASH_Forbid_SWD_Enable_RAM (FunctionalState NewState);
FlagStatus FLASH_Get_CFG_Error_Flag_RAM (void);
void FLASH_Clear_CFG_Error_Flag_RAM (void);

void FLASH_CheckSum_Addr_Config_RAM(uint32_t StartAddr, uint32_t StopAddr);
void FLASH_Start_SIG_Compute_Enable_RAM (FunctionalState NewState);
void FLASH_Get_CheckSum_Result_RAM (FLASH_CheckSumResult* CheckSumStruct);

void FLASH_Wipe_Configuration_RAM (uint32_t WipeMode,
                    uint32_t WipeAddr);
void FLASH_Program_Configuration_RAM (FLASH_ProgramTypeDef * flashProgramStruct);

void FLASH_Clear_NonVolatile_Memory_Unlock_Status (void);

void FLASH_Unlock_ISP (void);
void FLASH_Clear_Flash_Unlock_Status (void);
void FLASH_Unlock_Code (void);

void FLASH_Clear_Config_Unlock_Status (void);
void FLASH_Unlock_User_Config(void);

void FLASH_Zone_Config(uint32_t ZoneSelect);
void FLASH_Executive_Cmd(void);

FlagStatus FLASH_Get_Program_Status (void);

FlagStatus FLASH_Get_Wipe_Status (void);

void FLASH_Wipe_Configuration (uint32_t WipeMode,uint32_t WipeAddr);

uint32_t Read_Flash_or_CFR(uint32_t address,uint32_t ZoneSelect);
uint32_t Read_Flash_or_CFR_RAM (uint32_t address,uint32_t ZoneSelect);
void FLASH_Program_Configuration (FLASH_ProgramTypeDef * flashProgramStruct);
void FLASH_Program_Configuration_RAM (FLASH_ProgramTypeDef * flashProgramStruct);

uint32_t Read_Soft_Device_ID1(void);
uint32_t Read_Soft_Device_ID2(void);
uint32_t Read_Soft_Device_ID3(void);
uint32_t Read_Soft_Device_ID4(void);
# 17 "../system/src/kf32a_basic_flash.c" 2
# 49 "../system/src/kf32a_basic_flash.c"
void __attribute__((section(".indata")))
CHECK_RESTRICTION_RAM(int expr)
{
 while(!expr)
  ;
}


static inline uint32_t __attribute__((section(".indata")))
SFR_Config_RAM (uint32_t SfrMem, uint32_t SfrMask, uint32_t WriteVal)
{
    return ((SfrMem & SfrMask) | (WriteVal));
}






LockStatus __attribute__((section(".indata")))
FLASH_Get_NonVolatile_Memory_Unlock_Status_RAM (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) & ((uint32_t)1<<((0))))
    {

        return UNLOCK;
    }
    else
    {

        return LOCK;
    }
}






void __attribute__((section(".indata")))
FLASH_Clear_NonVolatile_Memory_Unlock_Status_RAM (void)
{
    uint32_t tmpreg = 0;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((0)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((0)))),
                        tmpreg);
}





void
FLASH_Clear_NonVolatile_Memory_Unlock_Status (void)
{
    uint32_t tmpreg = 0;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((0)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) = SFR_Config ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((0)))),
                        tmpreg);
}





void __attribute__((section(".indata")))
FLASH_Unlock_ISP_RAM (void)
{

    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->NVMUNLOCK) = ((uint32_t)0x87654321);
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->NVMUNLOCK) = ((uint32_t)0x05040302);
}






void
FLASH_Unlock_ISP (void)
{

    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->NVMUNLOCK) = ((uint32_t)0x87654321);
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->NVMUNLOCK) = ((uint32_t)0x05040302);
}





LockStatus __attribute__((section(".indata")))
FLASH_Get_Flash_Unlock_Status_RAM (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) & ((uint32_t)1<<((1))))
    {

        return UNLOCK;
    }
    else
    {

        return LOCK;
    }
}






void __attribute__((section(".indata")))
FLASH_Clear_Flash_Unlock_Status_RAM (void)
{
    uint32_t tmpreg = 0;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((1)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((1)))),
                        tmpreg);
}





void
FLASH_Clear_Flash_Unlock_Status (void)
{
    uint32_t tmpreg = 0;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((1)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) = SFR_Config ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((1)))),
                        tmpreg);
}





void __attribute__((section(".indata")))
FLASH_Unlock_Code_RAM (void)
{

    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->PROUNLOCK) = ((uint32_t)0x789ABCDE);
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->PROUNLOCK) = ((uint32_t)0x16151413);
}






void
FLASH_Unlock_Code (void)
{

    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->PROUNLOCK) = ((uint32_t)0x789ABCDE);
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->PROUNLOCK) = ((uint32_t)0x16151413);
}





LockStatus __attribute__((section(".indata")))
FLASH_Get_Config_Unlock_Status_RAM (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) & ((uint32_t)1<<((2))))
    {

        return UNLOCK;
    }
    else
    {

        return LOCK;
    }
}






void __attribute__((section(".indata")))
FLASH_Clear_Config_Unlock_Status_RAM (void)
{
    uint32_t tmpreg = 0;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((2)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((2)))),
                        tmpreg);
}





void
FLASH_Clear_Config_Unlock_Status (void)
{
    uint32_t tmpreg = 0;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((2)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) = SFR_Config ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((2)))),
                        tmpreg);
}





void __attribute__((section(".indata")))
FLASH_Unlock_User_Config_RAM (void)
{

    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFGUNLOCK) = ((uint32_t)0x879A43DE);
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFGUNLOCK) = ((uint32_t)0x27262524);
}






void
FLASH_Unlock_User_Config(void)
{

    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFGUNLOCK) = ((uint32_t)0x879A43DE);
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFGUNLOCK) = ((uint32_t)0x27262524);
}





void __attribute__((section(".indata")))
FLASH_Data_Write_Enable_RAM (FunctionalState NewState)
{

    CHECK_RESTRICTION_RAM((((NewState) == FALSE) || ((NewState) == TRUE)));


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((3)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((3)));
    }
}
# 325 "../system/src/kf32a_basic_flash.c"
void __attribute__((section(".indata")))
FLASH_Zone_Config_RAM (uint32_t ZoneSelect)
{

    CHECK_RESTRICTION_RAM((((ZoneSelect) == ((uint32_t)0<<(4))) || ((ZoneSelect) == ((uint32_t)1<<(4)))));


    if (ZoneSelect != ((uint32_t)0<<(4)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((4)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((4)));
    }
}







void
FLASH_Zone_Config(uint32_t ZoneSelect)
{

    ((void)0);


    if (ZoneSelect != ((uint32_t)0<<(4)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((4)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((4)));
    }
}
# 377 "../system/src/kf32a_basic_flash.c"
void __attribute__((section(".indata")))
FLASH_Standby_Mode_Config_RAM (uint32_t ModeSelect)
{
    uint32_t tmpreg = 0;


    CHECK_RESTRICTION_RAM((((ModeSelect) == ((uint32_t)0<<(5))) || ((ModeSelect) == ((uint32_t)1<<(5))) || ((ModeSelect) == ((uint32_t)2<<(5))) || ((ModeSelect) == ((uint32_t)3<<(5)))));


    tmpreg = ((uint32_t)0x50AF0000) | ModeSelect;
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((5)))),
                        tmpreg);
}
# 401 "../system/src/kf32a_basic_flash.c"
void __attribute__((section(".indata")))
FLASH_Read_Mode_Config_RAM (uint32_t ReadMode)
{

    CHECK_RESTRICTION_RAM((((ReadMode) == ((uint32_t)0<<(1))) || ((ReadMode) == ((uint32_t)1<<(1)))));


    if (ReadMode != ((uint32_t)0<<(0)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON1))),"i"((1)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON1))),"i"((1)));
    }
}






void __attribute__((section(".indata")))
FLASH_Calibration_Updata_Enable_RAM (FunctionalState NewState)
{
    uint32_t tmpreg = 0;


    CHECK_RESTRICTION_RAM((((NewState) == FALSE) || ((NewState) == TRUE)));


    tmpreg = ((uint32_t)0xA05F0000)
           | (NewState << (2));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON1) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON1),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<((2)))),
                        tmpreg);
}
# 448 "../system/src/kf32a_basic_flash.c"
void __attribute__((section(".indata")))
FLASH_Information_Zone_Wipe_Unlock_Config_RAM (LockStatus NewState)
{
    uint32_t tmpreg = 0;


    CHECK_RESTRICTION_RAM((((NewState) == LOCK) || ((NewState) == UNLOCK)));


    tmpreg = ((uint32_t)0xA05F0000)
           | (NewState << (15));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON1) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON1),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<((15)))),
                        tmpreg);
}






void __attribute__((section(".indata")))
FLASH_Half_Page_Write_Size_Config_RAM (uint32_t WriteSize)
{
    uint32_t tmpreg = 0;


    CHECK_RESTRICTION_RAM((((uint32_t)(WriteSize) >> 6) == 0));


    tmpreg = WriteSize << (5);
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD),
                        ~((uint32_t)0x3F<<((5))),
                        tmpreg);
}
# 493 "../system/src/kf32a_basic_flash.c"
void __attribute__((section(".indata")))
FLASH_Program_Cmd_Config_RAM (uint32_t CmdSelect)
{

    CHECK_RESTRICTION_RAM((((CmdSelect) == ((uint32_t)0x15<<(0))) || ((CmdSelect) == ((uint32_t)0x0A<<(0))) || ((CmdSelect) == ((uint32_t)0x1B<<(0))) || ((CmdSelect) == ((uint32_t)0x05<<(0)))));


    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD),
                        ~((uint32_t)0x1F<<((0))),
                        CmdSelect);
}







void __attribute__((section(".indata")))
FLASH_Executive_Cmd_RAM(void)
{
    uint32_t tmpreg = 0;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((0)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPTRG) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPTRG),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((0)))),
                        tmpreg);
}






void
FLASH_Executive_Cmd(void)
{
    uint32_t tmpreg = 0;


    tmpreg = ((uint32_t)0x50AF0000) | ((uint32_t)1<<((0)));
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPTRG) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPTRG),
                        ~(((uint32_t)0xFFFF0000) | ((uint32_t)1<<((0)))),
                        tmpreg);
}





void __attribute__((section(".indata")))
FLASH_NonVolatile_Memory_ECC_Enable_RAM (FunctionalState NewState)
{

    CHECK_RESTRICTION_RAM((((NewState) == FALSE) || ((NewState) == TRUE)));


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG))),"i"((7)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG))),"i"((7)));
    }
}






void __attribute__((section(".indata")))
FLASH_Linear_Prefetch_Enable_RAM (FunctionalState NewState)
{

    CHECK_RESTRICTION_RAM((((NewState) == FALSE) || ((NewState) == TRUE)));


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG))),"i"((6)));
    }
    else
    {

     __asm volatile("CLR [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG))),"i"((6)));
    }
}






void __attribute__((section(".indata")))
FLASH_Period_Number_Config_RAM (uint32_t PeriodNum)
{
    uint32_t tmpreg = 0;


    CHECK_RESTRICTION_RAM((((uint32_t)(PeriodNum) >> 4) == 0));


    tmpreg = (PeriodNum - 1) << (0);
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->CFG),
                        ~((uint32_t)0xF<<((0))),
                        tmpreg);
}






void __attribute__((section(".indata")))
FLASH_Program_Addr_Config_RAM (uint32_t ProgramAddr)
{
    uint32_t tmpreg = 0;


    CHECK_RESTRICTION_RAM((((uint32_t)(ProgramAddr) >> 20) == 0));


    tmpreg = ProgramAddr << (0);
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPADDR) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPADDR),
                        ~((uint32_t)0xFFFFF<<((0))),
                        tmpreg);
}






FlagStatus __attribute__((section(".indata")))
FLASH_Get_Program_Status_RAM (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((3))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}





FlagStatus
FLASH_Get_Program_Status (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((3))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 673 "../system/src/kf32a_basic_flash.c"
FlagStatus __attribute__((section(".indata")))
FLASH_Get_Wipe_Status_RAM (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((2))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






FlagStatus
FLASH_Get_Wipe_Status (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((2))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}





FlagStatus __attribute__((section(".indata")))
FLASH_Get_Compute_Complete_Status_RAM (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((1))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






void __attribute__((section(".indata")))
FLASH_Clear_Compute_Complete_Status_RAM (void)
{

    while(((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((1))))>>(1))
    {
     __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE))),"i"((1)));
    }
}
# 749 "../system/src/kf32a_basic_flash.c"
FlagStatus __attribute__((section(".indata")))
FLASH_Get_CFG_Error_Flag_RAM (void)
{
    if ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((0))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






void __attribute__((section(".indata")))
FLASH_Clear_CFG_Error_Flag_RAM (void)
{


    while(((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE) & ((uint32_t)1<<((0))))>>(0))
    {
     __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->STATE))),"i"((0)));
    }
}
# 787 "../system/src/kf32a_basic_flash.c"
void __attribute__((section(".indata")))
FLASH_CheckSum_Addr_Config_RAM(uint32_t StartAddr, uint32_t StopAddr)
{

    CHECK_RESTRICTION_RAM((((uint32_t)(StartAddr) >> 20) == 0));
    CHECK_RESTRICTION_RAM((((uint32_t)(StopAddr) >> 20) == 0));

    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSSTART) = StartAddr;
    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSSTOP) = StopAddr;
}






void __attribute__((section(".indata")))
FLASH_Start_SIG_Compute_Enable_RAM (FunctionalState NewState)
{

    CHECK_RESTRICTION_RAM((((NewState) == FALSE) || ((NewState) == TRUE)));


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSSTOP))),"i"((20)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSSTOP))),"i"((20)));
    }
}







void __attribute__((section(".indata")))
FLASH_Get_CheckSum_Result_RAM (FLASH_CheckSumResult* CheckSumStruct)
{
    uint32_t tmpreg = 0;


    tmpreg = (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSRES[0]);
    CheckSumStruct->m_ResultWord[0] = tmpreg;

    tmpreg = (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSRES[1]);
    CheckSumStruct->m_ResultWord[1] = tmpreg;

    tmpreg = (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSRES[2]);
    CheckSumStruct->m_ResultWord[2] = tmpreg;

    tmpreg = (((FLASH_SFRmap *) ((uint32_t)0x40200100))->CSRES[3]);
    CheckSumStruct->m_ResultWord[3] = tmpreg;
}
# 863 "../system/src/kf32a_basic_flash.c"
void __attribute__((section(".indata")))
FLASH_Wipe_Configuration_RAM (uint32_t WipeMode,uint32_t WipeAddr)
{
    uint32_t tmpreg = 0;


    CHECK_RESTRICTION_RAM((((WipeMode) == ((uint32_t)0)) || ((WipeMode) == ((uint32_t)1)) || ((WipeMode) == ((uint32_t)2))));
    CHECK_RESTRICTION_RAM((((uint32_t)(WipeAddr) >> 20) == 0));




    FLASH_Unlock_ISP_RAM();


 FLASH_Unlock_Code_RAM();


 FLASH_Unlock_User_Config_RAM();



    if (WipeMode != ((uint32_t)2))
    {

        (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPADDR) = WipeAddr;


        if (((uint32_t)1) == WipeMode)
        {



            __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((4)));
        }
        else
        {
            ;
        }
    }
    else
    {

    }

    if (WipeMode != ((uint32_t)2))
    {

        tmpreg = ((uint32_t)0x1B<<(0));
    }
    else
    {

        tmpreg = ((uint32_t)0x0A<<(0));
    }

    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD),
                        ~((uint32_t)0x1F<<((0))),
                        tmpreg);




    FLASH_Executive_Cmd_RAM();

    while(FLASH_Get_Wipe_Status_RAM());

    FLASH_Zone_Config_RAM (((uint32_t)0<<(4)));


 FLASH_Clear_NonVolatile_Memory_Unlock_Status_RAM ();
 FLASH_Clear_Flash_Unlock_Status_RAM ();
 FLASH_Clear_Config_Unlock_Status_RAM ();


}
# 949 "../system/src/kf32a_basic_flash.c"
void
FLASH_Wipe_Configuration (uint32_t WipeMode,uint32_t WipeAddr)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);




    FLASH_Unlock_ISP();


 FLASH_Unlock_Code();


 FLASH_Unlock_User_Config();



    if (WipeMode != ((uint32_t)2))
    {

        (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPADDR) = WipeAddr;


        if (((uint32_t)1) == WipeMode)
        {



            __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((4)));
        }
        else
        {
            ;
        }
    }
    else
    {

    }

    if (WipeMode != ((uint32_t)2))
    {

        tmpreg = ((uint32_t)0x1B<<(0));
    }
    else
    {

        tmpreg = ((uint32_t)0x0A<<(0));
    }

    (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD) = SFR_Config ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD),
                        ~((uint32_t)0x1F<<((0))),
                        tmpreg);




    FLASH_Executive_Cmd();

    while(FLASH_Get_Wipe_Status());

    FLASH_Zone_Config_RAM (((uint32_t)0<<(4)));


 FLASH_Clear_NonVolatile_Memory_Unlock_Status ();
 FLASH_Clear_Flash_Unlock_Status ();
 FLASH_Clear_Config_Unlock_Status ();


}







void __attribute__((section(".indata")))
FLASH_Program_Configuration_RAM (FLASH_ProgramTypeDef * flashProgramStruct)
{
 uint32_t tmpreg = 0;
 uint32_t tmpaddr = 0;
 uint32_t * tmpptr = 0;



 CHECK_RESTRICTION_RAM((((flashProgramStruct->m_Mode) == ((uint32_t)0x15)) || ((flashProgramStruct->m_Mode) == ((uint32_t)0x05))));
 CHECK_RESTRICTION_RAM((((flashProgramStruct->m_Zone) == ((uint32_t)0)) || ((flashProgramStruct->m_Zone) == ((uint32_t)1))));
 CHECK_RESTRICTION_RAM((((uint32_t)(flashProgramStruct->m_Addr) >> 20) == 0));
 CHECK_RESTRICTION_RAM((((uint32_t)(flashProgramStruct->m_WriteSize) >> 6) == 0));






    FLASH_Unlock_ISP_RAM();
    FLASH_Unlock_User_Config_RAM();
    FLASH_Unlock_Code_RAM();





    __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((3)));

    if (flashProgramStruct->m_Zone != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((4)));

    }
    else
    {
    }


   tmpaddr = flashProgramStruct->m_Addr;
   tmpptr = flashProgramStruct->m_Data;


    if (flashProgramStruct->m_Mode != ((uint32_t)0x15))
    {


        tmpreg = flashProgramStruct->m_Mode
               | (flashProgramStruct->m_WriteSize << (5));
        (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD) = SFR_Config_RAM((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD),
                            ~(((uint32_t)0x1F<<((0))) | ((uint32_t)0x3F<<((5)))),
                            tmpreg);
        FLASH_Executive_Cmd_RAM();
  unsigned char j;
  for(j=0;j<=0x3f;j++)
  {
   __asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));
   tmpaddr=tmpaddr+4;
   tmpptr++;
   __asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));
   tmpaddr=tmpaddr+4;
   tmpptr++;
   while(FLASH_Get_Program_Status_RAM());
  }
    }
    else
    {


        (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD) = SFR_Config_RAM ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD),
                            ~((uint32_t)0x1F<<((0))),
                            flashProgramStruct->m_Mode);



     __asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));
     tmpaddr=tmpaddr+4;
     tmpptr++;
     __asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));



        FLASH_Executive_Cmd_RAM();

    }

    while(FLASH_Get_Wipe_Status_RAM());




    FLASH_Zone_Config_RAM (((uint32_t)0<<(4)));

    FLASH_Data_Write_Enable_RAM (FALSE);

 FLASH_Clear_NonVolatile_Memory_Unlock_Status_RAM ();
 FLASH_Clear_Flash_Unlock_Status_RAM ();
 FLASH_Clear_Config_Unlock_Status_RAM ();

}





void
FLASH_Program_Configuration (FLASH_ProgramTypeDef * flashProgramStruct)
{
 uint32_t tmpreg = 0;
 uint32_t tmpaddr = 0;
 uint32_t * tmpptr = 0;



 ((void)0);
 ((void)0);
 ((void)0);
 ((void)0);






    FLASH_Unlock_ISP();
    FLASH_Unlock_User_Config();
    FLASH_Unlock_Code();





    __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((3)));

    if (flashProgramStruct->m_Zone != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCON0))),"i"((4)));

    }
    else
    {
    }


   tmpaddr = flashProgramStruct->m_Addr;
   tmpptr = flashProgramStruct->m_Data;


    if (flashProgramStruct->m_Mode != ((uint32_t)0x15))
    {


        tmpreg = flashProgramStruct->m_Mode
               | (flashProgramStruct->m_WriteSize << (5));
        (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD) = SFR_Config((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD),
                            ~(((uint32_t)0x1F<<((0))) | ((uint32_t)0x3F<<((5)))),
                            tmpreg);
        FLASH_Executive_Cmd();
  unsigned char j;
  for(j=0;j<=0x3f;j++)
  {
   __asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));
   tmpaddr=tmpaddr+4;
   tmpptr++;
   __asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));
   tmpaddr=tmpaddr+4;
   tmpptr++;
   while(FLASH_Get_Program_Status());
  }
    }
    else
    {


        (((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD) = SFR_Config ((((FLASH_SFRmap *) ((uint32_t)0x40200100))->ISPCMD),
                            ~((uint32_t)0x1F<<((0))),
                            flashProgramStruct->m_Mode);



     __asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));
     tmpaddr=tmpaddr+4;
     tmpptr++;
     __asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));



        FLASH_Executive_Cmd();

    }

    while(FLASH_Get_Wipe_Status());




    FLASH_Zone_Config (((uint32_t)0<<(4)));

    FLASH_Data_Write_Enable_RAM (FALSE);

 FLASH_Clear_NonVolatile_Memory_Unlock_Status ();
 FLASH_Clear_Flash_Unlock_Status ();
 FLASH_Clear_Config_Unlock_Status ();

}
# 1248 "../system/src/kf32a_basic_flash.c"
uint32_t read_data;
uint32_t __attribute__((section(".indata")))
Read_Flash_or_CFR_RAM (uint32_t address,uint32_t ZoneSelect)
{
 uint32_t *read_adr;
 CHECK_RESTRICTION_RAM((((ZoneSelect) == ((uint32_t)0)) || ((ZoneSelect) == ((uint32_t)1))));

 FLASH_Unlock_ISP_RAM();
 FLASH_Unlock_User_Config_RAM();
 FLASH_Unlock_Code_RAM();
 if(ZoneSelect!=((uint32_t)1))
 {
  read_adr = (uint32_t *)address;
  read_data = *read_adr;
 }
 else
 {
  FLASH_Zone_Config_RAM (((uint32_t)1<<(4)));
  read_adr = (uint32_t *)address;
  read_data = *read_adr;
  FLASH_Zone_Config_RAM (((uint32_t)0<<(4)));
 }

 FLASH_Clear_NonVolatile_Memory_Unlock_Status ();
 FLASH_Clear_Flash_Unlock_Status ();
 FLASH_Clear_Config_Unlock_Status ();
 return read_data;

}






uint32_t Read_Flash_or_CFR (uint32_t address,uint32_t ZoneSelect)
{
 uint32_t *read_adr;
 ((void)0);

 FLASH_Unlock_ISP_RAM();
 FLASH_Unlock_User_Config_RAM();
 FLASH_Unlock_Code_RAM();
 if(ZoneSelect!=((uint32_t)1))
 {
  read_adr = (uint32_t *)address;
  read_data = *read_adr;
 }
 else
 {
  FLASH_Zone_Config_RAM (((uint32_t)1<<(4)));
  read_adr = (uint32_t *)address;
  read_data = *read_adr;
  FLASH_Zone_Config_RAM (((uint32_t)0<<(4)));
 }

 FLASH_Clear_NonVolatile_Memory_Unlock_Status ();
 FLASH_Clear_Flash_Unlock_Status ();
 FLASH_Clear_Config_Unlock_Status ();
 return read_data;

}






uint32_t Read_Soft_Device_ID1(void)
{
 uint32_t Soft_Device_ID1;
 Soft_Device_ID1 = Read_Flash_or_CFR(0x444,((uint32_t)1));
 return Soft_Device_ID1;
}
uint32_t Read_Soft_Device_ID2(void)
{
 uint32_t Soft_Device_ID2;
 Soft_Device_ID2 = Read_Flash_or_CFR(0x448,((uint32_t)1));
 return Soft_Device_ID2;
}
uint32_t Read_Soft_Device_ID3(void)
{
 uint32_t Soft_Device_ID3;
 Soft_Device_ID3 = Read_Flash_or_CFR(0x44C,((uint32_t)1));
 return Soft_Device_ID3;
}
uint32_t Read_Soft_Device_ID4(void)
{
 uint32_t Soft_Device_ID4;
 Soft_Device_ID4 = Read_Flash_or_CFR(0x450,((uint32_t)1));
 return Soft_Device_ID4;
}
