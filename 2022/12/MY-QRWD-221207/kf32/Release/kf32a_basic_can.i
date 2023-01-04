# 1 "../system/src/kf32a_basic_can.c"
# 1 "/cygdrive/d/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/Release//"
# 1 "<command-line>"
# 1 "../system/src/kf32a_basic_can.c"
# 16 "../system/src/kf32a_basic_can.c"
# 1 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/kf32a_basic_can.h" 1
# 14 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/kf32a_basic_can.h"
# 1 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h" 1
# 20 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 21 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h" 2
# 1 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_Config.h" 1
# 15 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_Config.h"
# 1 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/__Kungfu32_chipmodel_define.h" 1
# 16 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_Config.h" 2
# 22 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h" 2
# 36 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 171 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 1127 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 1450 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 3317 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
typedef struct SYSCTL_MemMap {
    volatile uint32_t PSW;
    volatile uint32_t MCTL;
    volatile uint32_t ARCTL;
    volatile uint32_t VECTOFF;
          uint32_t RESEVRVE1;
    volatile uint32_t RAMSPA;
    volatile uint32_t MEMCTL;
}SYSCTL_SFRmap;
# 3406 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 4066 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 4721 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
typedef struct SYSTICK_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t RELOAD;
    volatile uint32_t CV;
    volatile uint32_t CALI;
}SYSTICK_SFRmap;
# 4775 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 4963 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 5573 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 6302 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
typedef struct QEI_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CNT;
    volatile uint32_t PPX;
    volatile uint32_t PRSC;
    volatile uint32_t DIER;
}QEI_SFRmap;
# 6420 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
typedef struct DAC_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t DAHD;
    volatile const uint32_t DATA;
    volatile uint32_t CTL1;
                   uint32_t RESERVED;
    volatile uint32_t CAL;
}DAC_SFRmap;
# 6573 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
typedef struct CMP_MemMap {
    volatile uint32_t CTL;





}CMP_SFRmap;
# 8136 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 8679 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
typedef struct IWDT_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t FD;
}IWDT_SFRmap;
# 8712 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
typedef struct WWDT_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t CNT;
}WWDT_SFRmap;
# 8752 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
typedef struct RST_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}RST_SFRmap;
# 9132 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
typedef struct PCLK_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}PCLK_SFRmap;
# 9512 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
typedef struct SPI_MemMap {
    volatile uint32_t BRGR;
    volatile uint32_t CTLR;
    volatile uint32_t BUFR;
    volatile uint32_t STR;
}SPI_SFRmap;
# 9672 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 9934 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 11943 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 12722 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 13117 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
typedef struct BKP_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t INT;
             uint32_t RESERVED[14];
    volatile uint32_t DATA[32];
}BKP_SFRmap;
# 13223 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 13421 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 13471 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
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
# 13925 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
typedef struct EXIC_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t STATE;
       uint32_t RESERVED1;
    volatile uint32_t WRITEBUF;
    volatile uint32_t READBUF;

}EXIC_SFRmap;
# 14005 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
typedef struct CFGL_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t IFR;
}CFGL_SFRmap;
# 14184 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
typedef struct OP_MemMap {
    volatile uint32_t CAL;
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
}OP_SFRmap;
# 14358 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/KF32A_BASIC.h"
static inline uint32_t
SFR_Config (uint32_t SfrMem, uint32_t SfrMask, uint32_t WriteVal)
{
    return ((SfrMem & SfrMask) | (WriteVal));
}
# 15 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/kf32a_basic_can.h" 2






typedef struct
{
    FunctionalState m_Enable;

    uint32_t m_Mode;

    uint32_t m_WorkSource;

    uint8_t m_BaudRate;

    uint8_t m_SyncJumpWidth;

    uint8_t m_TimeSeg1;

    uint8_t m_TimeSeg2;

    uint32_t m_BusSample;

    uint32_t m_Acceptance;

    uint32_t m_AcceptanceMask;

}CAN_InitTypeDef;




typedef struct
{
    uint8_t m_ErrorCode;

    uint8_t m_ErrorDirection;

    uint8_t m_ErrorSegment;

    uint8_t m_ArbitrationLost;

}CAN_ErrorTypeDef;




typedef struct
{
    uint32_t m_FrameFormat;

    uint32_t m_RemoteTransmit;

    uint32_t m_DataLength;

    uint32_t m_StandardID;

    uint32_t m_ExtendedID;

    uint8_t m_Data[16];

}CAN_MessageTypeDef;
# 319 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/kf32a_basic_can.h"
void CAN_Reset(CAN_SFRmap* CANx);
void CAN_Configuration(CAN_SFRmap* CANx, CAN_InitTypeDef* canInitStruct);
void CAN_Struct_Init (CAN_InitTypeDef* canInitStruct);

uint32_t CAN_Get_Receive_Message_Counter (CAN_SFRmap* CANx);
FlagStatus CAN_Get_Transmit_Status (CAN_SFRmap* CANx, uint32_t Type);
void CAN_Cmd (CAN_SFRmap* CANx, FunctionalState NewState);
void CAN_Clock_Source_Config (CAN_SFRmap* CANx, uint32_t ClockSource);
void CAN_Sleep_Mode_Enable (CAN_SFRmap* CANx, FunctionalState NewState);
void CAN_Reset_Mode_Enable (CAN_SFRmap* CANx, FunctionalState NewState);
void CAN_Work_Mode_Config (CAN_SFRmap* CANx, uint32_t ModeType);
void CAN_Bus_Sample_Times_Config (CAN_SFRmap* CANx, uint32_t Times);
void CAN_Time_Segment_Config (CAN_SFRmap* CANx,
                    uint32_t TimeSeg1, uint32_t TimeSeg2);
void CAN_Sync_Jump_Width_Config (CAN_SFRmap* CANx, uint32_t JumpWidth);
void CAN_Baud_Rate_Preset_Config (CAN_SFRmap* CANx, uint32_t BaudRate);
void CAN_Get_Error_Code (CAN_SFRmap* CANx, CAN_ErrorTypeDef* canErrorStruct);
uint8_t CAN_Get_Error_Warning_Limit (CAN_SFRmap* CANx);
uint8_t CAN_Get_Error_Counter (CAN_SFRmap* CANx, uint32_t Direction);
void CAN_Error_Warning_Limit_Config (CAN_SFRmap* CANx, uint8_t ErrorLimit);
void CAN_Error_Counter_Config (CAN_SFRmap* CANx,
                    uint32_t Direction, uint8_t ErrorCounter);
void CAN_Acceptance_Config (CAN_SFRmap* CANx, uint32_t Acceptance);
uint32_t CAN_Get_Acceptance (CAN_SFRmap* CANx);
void CAN_Acceptance_Mask_Config (CAN_SFRmap* CANx, uint32_t Acceptance);
uint32_t CAN_Get_Acceptance_Mask (CAN_SFRmap* CANx);

void CAN_Transmit_Message_Configuration (CAN_SFRmap* CANx,
                    CAN_MessageTypeDef* canInitStruct);
void CAN_Receive_Message_Configuration (CAN_SFRmap* CANx,
                    uint32_t ReceiveOffset, CAN_MessageTypeDef* canInitStruct);
void CAN_Message_Struct_Init (CAN_MessageTypeDef* canInitStruct);
void CAN_Clear_Buffer_Overflow_Flag (CAN_SFRmap* CANx);
void CAN_Release_Receive_Buffer (CAN_SFRmap* CANx, uint32_t ReleaseCount);
void CAN_Transmit_Single (CAN_SFRmap* CANx);
void CAN_Transmit_Repeat (CAN_SFRmap* CANx);
void CAN_Frame_Format_Config (CAN_SFRmap* CANx, uint32_t FrameFormat);
void CAN_Remote_Request_Config (CAN_SFRmap* CANx, uint32_t RemoteRequest);
void CAN_Data_Length_Config (CAN_SFRmap* CANx, uint32_t Length);
void CAN_Identification_Code_Config (CAN_SFRmap* CANx,
                    uint32_t FrameFormat, uint32_t IDCode);

FlagStatus CAN_Get_INT_Flag (CAN_SFRmap* CANx, uint32_t InterruptType);
void CAN_Clear_INT_Flag (CAN_SFRmap* CANx, uint32_t InterruptType);
void CAN_Set_INT_Enable (CAN_SFRmap* CANx,
                    uint32_t InterruptType, FunctionalState NewState);
# 17 "../system/src/kf32a_basic_can.c" 2
# 1 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/kf32a_basic_rst.h" 1
# 44 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/kf32a_basic_rst.h"
void RST_CTL0_Peripheral_Reset_Enable(uint32_t RST_CTL0Periph,
                    FunctionalState NewState);
void RST_CTL1_Peripheral_Reset_Enable(uint32_t RST_CTL1Periph,
                    FunctionalState NewState);
void RST_CTL2_Peripheral_Reset_Enable(uint32_t RST_CTL2Periph,
                    FunctionalState NewState);
void RST_CTL3_Peripheral_Reset_Enable(uint32_t RST_CTL3Periph,
                    FunctionalState NewState);
# 18 "../system/src/kf32a_basic_can.c" 2
# 1 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/kf32a_basic_pclk.h" 1
# 40 "D:/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/system/inc/kf32a_basic_pclk.h"
void PCLK_CTL0_Peripheral_Clock_Enable (uint32_t PCLK_CTL0_bit,
                    FunctionalState NewState);
void PCLK_CTL1_Peripheral_Clock_Enable (uint32_t PCLK_CTL1_bit,
                    FunctionalState NewState);
void PCLK_CTL2_Peripheral_Clock_Enable (uint32_t PCLK_CTL2_bit,
                    FunctionalState NewState);
void PCLK_CTL3_Peripheral_Clock_Enable (uint32_t PCLK_CTL3_bit,
                    FunctionalState NewState);
# 19 "../system/src/kf32a_basic_can.c" 2
# 67 "../system/src/kf32a_basic_can.c"
void
CAN_Reset(CAN_SFRmap* CANx)
{

    ((void)0);

    if (CANx == ((CAN_SFRmap *) ((uint32_t)0x40001100)))
    {
     PCLK_CTL2_Peripheral_Clock_Enable(((uint32_t)1<<((2))), TRUE);
        RST_CTL2_Peripheral_Reset_Enable(((uint32_t)1<<((2))), TRUE);
        RST_CTL2_Peripheral_Reset_Enable(((uint32_t)1<<((2))), FALSE);
    }


    if(CANx == ((CAN_SFRmap *) ((uint32_t)0x40001180)))
    {
     PCLK_CTL2_Peripheral_Clock_Enable(((uint32_t)1<<((3))), TRUE);
        RST_CTL2_Peripheral_Reset_Enable(((uint32_t)1<<((3))), TRUE);
        RST_CTL2_Peripheral_Reset_Enable(((uint32_t)1<<((3))), FALSE);
    }


    if(CANx == ((CAN_SFRmap *) ((uint32_t)0x40001900)))
    {
     PCLK_CTL2_Peripheral_Clock_Enable(((uint32_t)1<<((18))), TRUE);
        RST_CTL2_Peripheral_Reset_Enable(((uint32_t)1<<((18))), TRUE);
        RST_CTL2_Peripheral_Reset_Enable(((uint32_t)1<<((18))), FALSE);
    }


    if(CANx == ((CAN_SFRmap *) ((uint32_t)0x40001980)))
    {
     PCLK_CTL2_Peripheral_Clock_Enable(((uint32_t)1<<((19))), TRUE);
        RST_CTL2_Peripheral_Reset_Enable(((uint32_t)1<<((19))), TRUE);
        RST_CTL2_Peripheral_Reset_Enable(((uint32_t)1<<((19))), FALSE);
    }


    if(CANx == ((CAN_SFRmap *) ((uint32_t)0x40002880)))
    {
     PCLK_CTL3_Peripheral_Clock_Enable(((uint32_t)1<<((17))), TRUE);
        RST_CTL3_Peripheral_Reset_Enable(((uint32_t)1<<((17))), TRUE);
        RST_CTL3_Peripheral_Reset_Enable(((uint32_t)1<<((17))), FALSE);
    }


    if(CANx == ((CAN_SFRmap *) ((uint32_t)0x40002900)))
    {
     PCLK_CTL3_Peripheral_Clock_Enable(((uint32_t)1<<((18))), TRUE);
        RST_CTL3_Peripheral_Reset_Enable(((uint32_t)1<<((18))), TRUE);
        RST_CTL3_Peripheral_Reset_Enable(((uint32_t)1<<((18))), FALSE);
    }

}
# 129 "../system/src/kf32a_basic_can.c"
void
CAN_Configuration(CAN_SFRmap* CANx, CAN_InitTypeDef* canInitStruct)
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






    tmpreg = ((uint32_t)canInitStruct->m_Enable << (7))
           | canInitStruct->m_Mode
           | canInitStruct->m_WorkSource
           | ((uint32_t)1<<((0)));
    CANx->CTLR = SFR_Config (CANx->CTLR, ~(((uint32_t)1<<((7))) | ((uint32_t)3<<((5))) | ((uint32_t)1<<((2))) | ((uint32_t)1<<((1))) | ((uint32_t)1<<((0)))), tmpreg);







    tmpreg = ((uint32_t)canInitStruct->m_BaudRate << (0))
           | ((uint32_t)canInitStruct->m_SyncJumpWidth << (6))
           | ((uint32_t)canInitStruct->m_TimeSeg1 << (8))
           | ((uint32_t)canInitStruct->m_TimeSeg2 << (12))
           | (canInitStruct->m_BusSample);
    CANx->BRGR = SFR_Config (CANx->BRGR, ~(((uint32_t)0x3F<<((0))) | ((uint32_t)3<<((6))) | ((uint32_t)0xF<<((8))) | ((uint32_t)7<<((12))) | ((uint32_t)1<<((15)))), tmpreg);


    CANx->ACRR = canInitStruct->m_Acceptance;


    CANx->MSKR = canInitStruct->m_AcceptanceMask;


    __asm volatile("CLR [%0], #%1"::"r"(&(CANx->CTLR)),"i"((0)));
}






void
CAN_Struct_Init (CAN_InitTypeDef* canInitStruct)
{

    canInitStruct->m_Enable = FALSE;


    canInitStruct->m_Mode = ((uint32_t)0<<(1));


    canInitStruct->m_WorkSource = ((uint32_t)0<<(5));


    canInitStruct->m_BaudRate = 0;


    canInitStruct->m_SyncJumpWidth = 0;


    canInitStruct->m_TimeSeg1 = 0;


    canInitStruct->m_TimeSeg2 = 0;


    canInitStruct->m_BusSample = ((uint32_t)0<<(15));


    canInitStruct->m_Acceptance = 0;


    canInitStruct->m_AcceptanceMask = 0;
}
# 230 "../system/src/kf32a_basic_can.c"
uint32_t
CAN_Get_Receive_Message_Counter (CAN_SFRmap* CANx)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = CANx->CTLR;
    tmpreg &= ((uint32_t)0x1F<<((24)));
    tmpreg >>= (24);

    return tmpreg;
}
# 263 "../system/src/kf32a_basic_can.c"
FlagStatus
CAN_Get_Transmit_Status (CAN_SFRmap* CANx, uint32_t Type)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = CANx->CTLR;

    if (tmpreg & Type)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







void
CAN_Cmd (CAN_SFRmap* CANx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(CANx->CTLR)),"i"((7)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(CANx->CTLR)),"i"((7)));
    }
}
# 322 "../system/src/kf32a_basic_can.c"
void
CAN_Clock_Source_Config (CAN_SFRmap* CANx, uint32_t ClockSource)
{

    ((void)0);
    ((void)0);


    CANx->CTLR = SFR_Config (CANx->CTLR, ~((uint32_t)3<<((5))), ClockSource);
}







void
CAN_Sleep_Mode_Enable (CAN_SFRmap* CANx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(CANx->CTLR)),"i"((3)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(CANx->CTLR)),"i"((3)));
    }
}







void
CAN_Reset_Mode_Enable (CAN_SFRmap* CANx, FunctionalState NewState)
{

    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(CANx->CTLR)),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(CANx->CTLR)),"i"((0)));
    }
}
# 395 "../system/src/kf32a_basic_can.c"
void
CAN_Work_Mode_Config (CAN_SFRmap* CANx, uint32_t ModeType)
{

    ((void)0);
    ((void)0);


    CANx->CTLR = SFR_Config (CANx->CTLR,
                        ~(((uint32_t)1<<((1))) | ((uint32_t)1<<((2)))),
                        ModeType);
}
# 416 "../system/src/kf32a_basic_can.c"
void
CAN_Bus_Sample_Times_Config (CAN_SFRmap* CANx, uint32_t Times)
{

    ((void)0);
    ((void)0);


    if (Times != ((uint32_t)0<<(15)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&(CANx->BRGR)),"i"((15)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(CANx->BRGR)),"i"((15)));
    }
}
# 443 "../system/src/kf32a_basic_can.c"
void
CAN_Time_Segment_Config (CAN_SFRmap* CANx,
                    uint32_t TimeSeg1, uint32_t TimeSeg2)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = (TimeSeg1 << (8))
           | (TimeSeg2 << (12));
    CANx->BRGR = SFR_Config (CANx->BRGR,
                        ~(((uint32_t)0xF<<((8))) | ((uint32_t)7<<((12)))),
                        tmpreg);
}







void
CAN_Sync_Jump_Width_Config (CAN_SFRmap* CANx, uint32_t JumpWidth)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = JumpWidth << (6);
    CANx->BRGR = SFR_Config (CANx->BRGR, ~((uint32_t)3<<((6))), tmpreg);
}







void
CAN_Baud_Rate_Preset_Config (CAN_SFRmap* CANx, uint32_t BaudRate)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = BaudRate << (0);
    CANx->BRGR = SFR_Config (CANx->BRGR, ~((uint32_t)0x3F<<((0))), tmpreg);
}







void
CAN_Get_Error_Code (CAN_SFRmap* CANx, CAN_ErrorTypeDef* canErrorStruct)
{
    uint32_t tmpreg = 0;
    uint32_t tmpreg1 = 0;


    ((void)0);
    ((void)0);


    tmpreg = CANx->RCR;


    tmpreg1 = tmpreg & ((uint32_t)3<<((14)));
    tmpreg1 >>= (14);
    canErrorStruct->m_ErrorCode = tmpreg1;


    tmpreg1 = tmpreg & ((uint32_t)1<<((13)));
    tmpreg1 >>= (13);
    canErrorStruct->m_ErrorDirection = tmpreg1;


    tmpreg1 = tmpreg & ((uint32_t)0x1F<<((8)));
    tmpreg1 >>= (8);
    canErrorStruct->m_ErrorSegment = tmpreg1;


    tmpreg1 = tmpreg & ((uint32_t)0x1F<<((0)));
    tmpreg1 >>= (0);
    canErrorStruct->m_ArbitrationLost = tmpreg1;
}






uint8_t
CAN_Get_Error_Warning_Limit (CAN_SFRmap* CANx)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = CANx->EROR;

    return (uint8_t)tmpreg;
}
# 569 "../system/src/kf32a_basic_can.c"
uint8_t
CAN_Get_Error_Counter (CAN_SFRmap* CANx, uint32_t Direction)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = CANx->EROR;

    if (Direction != ((uint32_t)0))
    {

        tmpreg &= ((uint32_t)0xFF<<((0)));
        tmpreg >>= (0);
    }
    else
    {

        tmpreg &= ((uint32_t)0xFF<<((8)));
        tmpreg >>= (8);
    }

    return (uint8_t)tmpreg;
}







void
CAN_Error_Warning_Limit_Config (CAN_SFRmap* CANx, uint8_t ErrorLimit)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = ErrorLimit << (16);
    CANx->EROR = SFR_Config (CANx->EROR, ~((uint32_t)0xFF<<((16))), tmpreg);
}
# 625 "../system/src/kf32a_basic_can.c"
void
CAN_Error_Counter_Config (CAN_SFRmap* CANx,
                    uint32_t Direction, uint8_t ErrorCounter)
{
    uint32_t tmpreg = 0;
    uint32_t tmpmask = 0;


    ((void)0);
    ((void)0);

    if (Direction != ((uint32_t)0))
    {

        tmpreg = ErrorCounter << (0);
        tmpmask = ((uint32_t)0xFF<<((0)));
    }
    else
    {

        tmpreg = ErrorCounter << (8);
        tmpmask = ((uint32_t)0xFF<<((8)));
    }


    CANx->EROR = SFR_Config (CANx->EROR, ~tmpmask, tmpreg);
}







void
CAN_Acceptance_Config (CAN_SFRmap* CANx, uint32_t Acceptance)
{

    ((void)0);


    CANx->ACRR = Acceptance;
}






uint32_t
CAN_Get_Acceptance (CAN_SFRmap* CANx)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = CANx->ACRR;

    return tmpreg;
}







void
CAN_Acceptance_Mask_Config (CAN_SFRmap* CANx, uint32_t Acceptance)
{

    ((void)0);


    CANx->MSKR = Acceptance;
}






uint32_t
CAN_Get_Acceptance_Mask (CAN_SFRmap* CANx)
{
    uint32_t tmpreg = 0;


    ((void)0);


    tmpreg = CANx->MSKR;

    return tmpreg;
}
# 736 "../system/src/kf32a_basic_can.c"
void
CAN_Transmit_Message_Configuration (CAN_SFRmap* CANx,
                    CAN_MessageTypeDef* canInitStruct)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);





    tmpreg = (canInitStruct->m_FrameFormat << (7))
           | (canInitStruct->m_RemoteTransmit << (6))
           | (canInitStruct->m_DataLength << (0));
    CANx->INFR = SFR_Config (CANx->INFR, ~(((uint32_t)1<<((7))) | ((uint32_t)1<<((6))) | ((uint32_t)0xF<<((0)))), tmpreg);






    if (canInitStruct->m_FrameFormat != ((uint32_t)1))
    {

        tmpreg = (canInitStruct->m_StandardID << (21))
               | ((uint32_t)canInitStruct->m_Data[0] << (8))
               | ((uint32_t)canInitStruct->m_Data[1] << (0));
        CANx->TX0R = SFR_Config (CANx->TX0R, ~(((uint32_t)0x7FF<<((21))) | 0xFFFF), tmpreg);


        tmpreg = ((uint32_t)canInitStruct->m_Data[2] << (24))
               | ((uint32_t)canInitStruct->m_Data[3] << (16))
               | ((uint32_t)canInitStruct->m_Data[4] << (8))
               | ((uint32_t)canInitStruct->m_Data[5] << (0));
        CANx->TX1R = tmpreg;


        tmpreg = ((uint32_t)canInitStruct->m_Data[6] << (24))
               | ((uint32_t)canInitStruct->m_Data[7] << (16));
        CANx->TX2R = SFR_Config (CANx->TX2R, ~(0xFFFF0000), tmpreg);
    }
    else
    {

        tmpreg = canInitStruct->m_ExtendedID << (3);
        CANx->TX0R = SFR_Config (CANx->TX0R, ~(((uint32_t)0x1FFFFFFF<<((3)))), tmpreg);


        tmpreg = ((uint32_t)canInitStruct->m_Data[0] << (24))
               | ((uint32_t)canInitStruct->m_Data[1] << (16))
               | ((uint32_t)canInitStruct->m_Data[2] << (8))
               | ((uint32_t)canInitStruct->m_Data[3] << (0));
        CANx->TX1R = tmpreg;


        tmpreg = ((uint32_t)canInitStruct->m_Data[4] << (24))
               | ((uint32_t)canInitStruct->m_Data[5] << (16))
               | ((uint32_t)canInitStruct->m_Data[6] << (8))
               | ((uint32_t)canInitStruct->m_Data[7] << (0));
        CANx->TX2R = tmpreg;
    }
}
# 813 "../system/src/kf32a_basic_can.c"
void
CAN_Receive_Message_Configuration (CAN_SFRmap* CANx,
                    uint32_t ReceiveOffset, CAN_MessageTypeDef* canInitStruct)
{
    uint32_t tmpreg = 0;
    uint32_t tmpreg1 = 0;
    uint32_t tmpaddr = 0;
    uint8_t dataoffset[] = {1,0,7,6,5,4,11,10};
    uint32_t i = 0;


    ((void)0);
    ((void)0);


    tmpreg = (uint32_t)CANx;
    switch (tmpreg)
    {

  case ((uint32_t)0x40001100):
   tmpaddr = ((uint32_t)0x1FFEF800);
   break;


  case ((uint32_t)0x40001180):
   tmpaddr = ((uint32_t)0x1FFEF900);
   break;


  case ((uint32_t)0x40001900):
   tmpaddr = ((uint32_t)0x1FFEFA00);
   break;


  case ((uint32_t)0x40001980):
   tmpaddr = ((uint32_t)0x1FFEFB00);
   break;


  case ((uint32_t)0x40002880):
   tmpaddr = ((uint32_t)0x1FFEFC00);
   break;


  case ((uint32_t)0x40002900):
   tmpaddr = ((uint32_t)0x1FFEFD00);
   break;

  default:
   break;
    }
    tmpaddr += ReceiveOffset;
    tmpreg = *(volatile uint32_t *)tmpaddr;


    tmpreg1 = (tmpreg & ((uint32_t)1<<((7)))) >> (7);
    canInitStruct->m_FrameFormat = tmpreg1;


    tmpreg1 = (tmpreg & ((uint32_t)1<<((6)))) >> (6);
    canInitStruct->m_RemoteTransmit = tmpreg1;


    if (tmpreg1 != ((uint32_t)0))
    {
        return;
    }
    else
    {
        ;
    }


    tmpreg1 = (tmpreg & ((uint32_t)0xF<<((0)))) >> (0);
    canInitStruct->m_DataLength = tmpreg1;

    if (canInitStruct->m_FrameFormat != ((uint32_t)1))
    {


        tmpaddr += 4;
        tmpreg = *(volatile uint32_t *)tmpaddr;


        tmpreg1 = (tmpreg & ((uint32_t)0x7FF<<((21)))) >> (21);
        canInitStruct->m_StandardID = tmpreg1;


        for (i = 0; i < canInitStruct->m_DataLength; i++)
        {
            canInitStruct->m_Data[i] =
                    *(volatile uint8_t *)(tmpaddr + dataoffset[i]);
        }
    }
    else
    {


        tmpaddr += 4;
        tmpreg = *(volatile uint32_t *)tmpaddr;


        tmpreg1 = (tmpreg & ((uint32_t)0x1FFFFFFF<<((3)))) >> (3);
        canInitStruct->m_ExtendedID = tmpreg1;


        tmpaddr += 4;
        if (canInitStruct->m_DataLength < 4)
        {

            for (i = 0; i < canInitStruct->m_DataLength; i++)
            {
                canInitStruct->m_Data[i] =
                        *(volatile uint8_t *)(tmpaddr + 3 - i);
            }
        }
        else
        {

            for (i = 0; i < 4; i++)
            {
                canInitStruct->m_Data[i] =
                        *(volatile uint8_t *)(tmpaddr + 3 - i);
            }


            tmpaddr += 4;
            for (i = 4; i < canInitStruct->m_DataLength; i++)
            {
                canInitStruct->m_Data[i] =
                        *(volatile uint8_t *)(tmpaddr + 7 - i);
            }
        }
    }
}






void
CAN_Message_Struct_Init (CAN_MessageTypeDef* canInitStruct)
{
    uint32_t i = 0;


    canInitStruct->m_FrameFormat = ((uint32_t)0);


    canInitStruct->m_RemoteTransmit = ((uint32_t)0);


    canInitStruct->m_DataLength = 0;


    canInitStruct->m_StandardID = 0;


    canInitStruct->m_ExtendedID = 0;


    for (i = 0; i < 8; i++)
    {
        canInitStruct->m_Data[i] = 0;
    }
}






void
CAN_Clear_Buffer_Overflow_Flag (CAN_SFRmap* CANx)
{


    ((void)0);


    __asm volatile("SET [%0], #%1"::"r"(&(CANx->CTLR)),"i"((10)));
    while(!((CANx->CTLR & ((uint32_t)1<<((16))))>>(16)));
    __asm volatile("CLR [%0], #%1"::"r"(&(CANx->CTLR)),"i"((10)));

    __asm volatile("SET [%0], #%1"::"r"(&(CANx->CTLR)),"i"((11)));
    while((CANx->CTLR & ((uint32_t)1<<((17))))>>(17));
    __asm volatile("CLR [%0], #%1"::"r"(&(CANx->CTLR)),"i"((11)));
}







void
CAN_Release_Receive_Buffer (CAN_SFRmap* CANx, uint32_t ReleaseCount)
{
 uint32_t i,tmprmc;

    ((void)0);


    for(i=0;i<ReleaseCount;i++)
    {
        tmprmc = (CANx->CTLR&((uint32_t)0x1F<<((24))))>>(24);
        if(tmprmc == 0)
        {
         return ;
        }
        else
        {
      __asm volatile("SET [%0], #%1"::"r"(&(CANx->CTLR)),"i"((10)));
      while(tmprmc - ((CANx->CTLR&((uint32_t)0x1F<<((24))))>>(24)) != 1);
      __asm volatile("CLR [%0], #%1"::"r"(&(CANx->CTLR)),"i"((10)));
     }
    }
}







void
CAN_Transmit_Single (CAN_SFRmap* CANx)
{
 volatile unsigned char i=80;

    ((void)0);
    __asm volatile("CLR [%0], #%1"::"r"(&(CANx->CTLR)),"i"((8)));



    CANx->CTLR = CANx->CTLR | 0x300;



    __asm volatile("CLR [%0], #%1"::"r"(&(CANx->CTLR)),"i"((9)));
    __asm volatile("CLR [%0], #%1"::"r"(&(CANx->CTLR)),"i"((8)));
}







void
CAN_Transmit_Repeat (CAN_SFRmap* CANx)
{
 volatile unsigned int temp;

    ((void)0);


    __asm volatile("CLR [%0], #%1"::"r"(&(CANx->CTLR)),"i"((9)));
    __asm volatile("CLR [%0], #%1"::"r"(&(CANx->CTLR)),"i"((8)));
    __asm volatile("SET [%0], #%1"::"r"(&(CANx->CTLR)),"i"((8)));
    while((CANx->CTLR & ((uint32_t)1<<((21))))>>(21));
    __asm volatile("CLR [%0], #%1"::"r"(&(CANx->CTLR)),"i"((8)));
}
# 1086 "../system/src/kf32a_basic_can.c"
void
CAN_Frame_Format_Config (CAN_SFRmap* CANx, uint32_t FrameFormat)
{

    ((void)0);
    ((void)0);


    if (FrameFormat != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&(CANx->INFR)),"i"((7)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(CANx->INFR)),"i"((7)));
    }
}
# 1114 "../system/src/kf32a_basic_can.c"
void
CAN_Remote_Request_Config (CAN_SFRmap* CANx, uint32_t RemoteRequest)
{

    ((void)0);
    ((void)0);


    if (RemoteRequest != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&(CANx->INFR)),"i"((6)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(CANx->INFR)),"i"((6)));
    }
}
# 1141 "../system/src/kf32a_basic_can.c"
void
CAN_Data_Length_Config (CAN_SFRmap* CANx, uint32_t Length)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = Length << (0);
    CANx->EROR = SFR_Config (CANx->EROR, ~((uint32_t)0xF<<((0))), tmpreg);
}
# 1164 "../system/src/kf32a_basic_can.c"
void
CAN_Identification_Code_Config (CAN_SFRmap* CANx,
                    uint32_t FrameFormat, uint32_t IDCode)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    if (FrameFormat != ((uint32_t)0))
    {
        ((void)0);
    }
    else
    {
        ((void)0);
    }


    if (FrameFormat != ((uint32_t)0))
    {

        tmpreg = IDCode << (3);
        CANx->TX0R = SFR_Config (CANx->TX0R, ~((uint32_t)0x1FFFFFFF<<((3))), tmpreg);
    }
    else
    {

        tmpreg = IDCode << (21);
        CANx->TX0R = SFR_Config (CANx->TX0R, ~((uint32_t)0x7FF<<((21))), tmpreg);
    }
}
# 1218 "../system/src/kf32a_basic_can.c"
FlagStatus
CAN_Get_INT_Flag (CAN_SFRmap* CANx, uint32_t InterruptType)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = InterruptType << (0);

    if (CANx->IFR & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 1256 "../system/src/kf32a_basic_can.c"
void
CAN_Clear_INT_Flag (CAN_SFRmap* CANx, uint32_t InterruptType)
{
 uint32_t tmpreg = 0;

    ((void)0);
    ((void)0);


    tmpreg = InterruptType << (0);
    CANx->IER |= InterruptType << (16);
    while((CANx->IFR & tmpreg)>0);
    CANx->IER &= ~(InterruptType << (16));
}
# 1286 "../system/src/kf32a_basic_can.c"
void
CAN_Set_INT_Enable (CAN_SFRmap* CANx,
                    uint32_t InterruptType, FunctionalState NewState)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        CANx->IER |= InterruptType << (0);
    }
    else
    {

        CANx->IER &= ~(InterruptType << (0));
    }
}
