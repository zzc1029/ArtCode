# 1 "../system/src/kf32a_basic_dma.c"
# 1 "G:\\workspace32\\YB-CZGJ-AK-221201\\Release//"
# 1 "<command-line>"
# 1 "../system/src/kf32a_basic_dma.c"
# 15 "../system/src/kf32a_basic_dma.c"
# 1 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/kf32a_basic_dma.h" 1
# 14 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/kf32a_basic_dma.h"
# 1 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h" 1
# 20 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
# 1 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChipONCC32/include/Sys/stdint.h" 1
# 16 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChipONCC32/include/Sys/stdint.h"
# 1 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChipONCC32/include/Sys/stddef.h" 1
# 24 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChipONCC32/include/Sys/stddef.h"
typedef int ptrdiff_t;





typedef unsigned int size_t;




typedef unsigned short wchar_t;
# 17 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChipONCC32/include/Sys/stdint.h" 2




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
# 60 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChipONCC32/include/Sys/stdint.h"
  typedef int intptr_t;
# 69 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChipONCC32/include/Sys/stdint.h"
  typedef unsigned int uintptr_t;




typedef long long intmax_t;
typedef unsigned long long uintmax_t;
# 21 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h" 2
# 1 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_Config.h" 1
# 15 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_Config.h"
# 1 "G:/workspace32/YB-CZGJ-AK-221201/__Kungfu32_chipmodel_define.h" 1
# 16 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_Config.h" 2
# 22 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h" 2
# 36 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 171 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 1127 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 1450 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 3317 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
typedef struct SYSCTL_MemMap {
    volatile uint32_t PSW;
    volatile uint32_t MCTL;
    volatile uint32_t ARCTL;
    volatile uint32_t VECTOFF;
          uint32_t RESEVRVE1;
    volatile uint32_t RAMSPA;
    volatile uint32_t MEMCTL;
}SYSCTL_SFRmap;
# 3406 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 4066 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 4721 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
typedef struct SYSTICK_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t RELOAD;
    volatile uint32_t CV;
    volatile uint32_t CALI;
}SYSTICK_SFRmap;
# 4775 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 4963 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 5573 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 6302 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
typedef struct QEI_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CNT;
    volatile uint32_t PPX;
    volatile uint32_t PRSC;
    volatile uint32_t DIER;
}QEI_SFRmap;
# 6420 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
typedef struct DAC_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t DAHD;
    volatile const uint32_t DATA;
    volatile uint32_t CTL1;
                   uint32_t RESERVED;
    volatile uint32_t CAL;
}DAC_SFRmap;
# 6573 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
typedef struct CMP_MemMap {
    volatile uint32_t CTL;





}CMP_SFRmap;
# 8136 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 8679 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
typedef struct IWDT_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t FD;
}IWDT_SFRmap;
# 8712 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
typedef struct WWDT_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t CNT;
}WWDT_SFRmap;
# 8752 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
typedef struct RST_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}RST_SFRmap;
# 9132 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
typedef struct PCLK_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}PCLK_SFRmap;
# 9512 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
typedef struct SPI_MemMap {
    volatile uint32_t BRGR;
    volatile uint32_t CTLR;
    volatile uint32_t BUFR;
    volatile uint32_t STR;
}SPI_SFRmap;
# 9672 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 9934 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 11943 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 12722 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 13117 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
typedef struct BKP_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t INT;
             uint32_t RESERVED[14];
    volatile uint32_t DATA[32];
}BKP_SFRmap;
# 13223 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 13421 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 13471 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
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
# 13925 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
typedef struct EXIC_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t STATE;
       uint32_t RESERVED1;
    volatile uint32_t WRITEBUF;
    volatile uint32_t READBUF;

}EXIC_SFRmap;
# 14005 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
typedef struct CFGL_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t IFR;
}CFGL_SFRmap;
# 14184 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
typedef struct OP_MemMap {
    volatile uint32_t CAL;
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
}OP_SFRmap;
# 14358 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/KF32A_BASIC.h"
static inline uint32_t
SFR_Config (uint32_t SfrMem, uint32_t SfrMask, uint32_t WriteVal)
{
    return ((SfrMem & SfrMask) | (WriteVal));
}
# 15 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/kf32a_basic_dma.h" 2





typedef struct
{
    uint8_t m_Channel;

    uint8_t m_Direction;

    uint8_t m_PeripheralDataSize;

    uint8_t m_MemoryDataSize;

    uint16_t m_Priority;

    uint16_t m_Number;

    FunctionalState m_PeripheralInc;

    FunctionalState m_MemoryInc;

    FunctionalState m_LoopMode;

    uint32_t m_BlockMode;

    uint32_t m_PeriphAddr;

    uint32_t m_MemoryAddr;

}DMA_InitTypeDef;
# 127 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/kf32a_basic_dma.h"
void DMA_Reset (DMA_SFRmap* DMAx);
void DMA_Configuration (DMA_SFRmap* DMAx, DMA_InitTypeDef* dmaInitStruct);
void DMA_Struct_Init (DMA_InitTypeDef* dmaInitStruct);

void DMA_Transfer_Number_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint16_t Number);
void DMA_Memory_To_Memory_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState);
void DMA_Channel_Priority_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Priority);
void DMA_Peripheral_Data_Width_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Width);
void DMA_Memory_Data_Width_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Width);
void DMA_Peripheral_addr_increase_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState);
void DMA_Memory_addr_increase_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState);
void DMA_Loop_Mode_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState);
void DMA_Transfer_Direction_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Direction);
void DMA_Transfer_Mode_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t BlockMode);
void DMA_Oneshot_Enable (DMA_SFRmap* DMAx,
                                        uint32_t Channel, FunctionalState NewState);
void DMA_Channel_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState);
void DMA_Peripheral_Start_Address_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Address);
void DMA_Memory_Start_Address_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Address);
uint32_t DMA_Get_Peripheral_Current_Address (DMA_SFRmap* DMAx,
                    uint32_t Channel);
uint32_t DMA_Get_Memory_Current_Address (DMA_SFRmap* DMAx, uint32_t Channel);
uint16_t DMA_Get_Transfer_Number_Remain (DMA_SFRmap* DMAx, uint32_t Channel);

FlagStatus DMA_Get_INT_Flag (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t InterruptType);
void DMA_Clear_INT_Flag (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t InterruptType);
void DMA_Set_INT_Enable (DMA_SFRmap* DMAx, uint32_t Channel,
                    uint32_t InterruptType, FunctionalState NewState);
FlagStatus DMA_Get_Error_Transfer_INT_Flag (DMA_SFRmap* DMAx,
                    uint32_t Channel);
FlagStatus DMA_Get_Half_Transfer_INT_Flag (DMA_SFRmap* DMAx, uint32_t Channel);
FlagStatus DMA_Get_Finish_Transfer_INT_Flag (DMA_SFRmap* DMAx,
                    uint32_t Channel);
void DMA_Error_Transfer_INT_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState);
void DMA_Half_Transfer_INT_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState);
void DMA_Finish_Transfer_INT_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState);
# 16 "../system/src/kf32a_basic_dma.c" 2
# 1 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/kf32a_basic_rst.h" 1
# 44 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/kf32a_basic_rst.h"
void RST_CTL0_Peripheral_Reset_Enable(uint32_t RST_CTL0Periph,
                    FunctionalState NewState);
void RST_CTL1_Peripheral_Reset_Enable(uint32_t RST_CTL1Periph,
                    FunctionalState NewState);
void RST_CTL2_Peripheral_Reset_Enable(uint32_t RST_CTL2Periph,
                    FunctionalState NewState);
void RST_CTL3_Peripheral_Reset_Enable(uint32_t RST_CTL3Periph,
                    FunctionalState NewState);
# 17 "../system/src/kf32a_basic_dma.c" 2
# 1 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/kf32a_basic_pclk.h" 1
# 40 "G:/workspace32/YB-CZGJ-AK-221201/system/inc/kf32a_basic_pclk.h"
void PCLK_CTL0_Peripheral_Clock_Enable (uint32_t PCLK_CTL0_bit,
                    FunctionalState NewState);
void PCLK_CTL1_Peripheral_Clock_Enable (uint32_t PCLK_CTL1_bit,
                    FunctionalState NewState);
void PCLK_CTL2_Peripheral_Clock_Enable (uint32_t PCLK_CTL2_bit,
                    FunctionalState NewState);
void PCLK_CTL3_Peripheral_Clock_Enable (uint32_t PCLK_CTL3_bit,
                    FunctionalState NewState);
# 18 "../system/src/kf32a_basic_dma.c" 2
# 40 "../system/src/kf32a_basic_dma.c"
void
DMA_Reset (DMA_SFRmap* DMAx)
{

    ((void)0);

    if (DMAx == ((DMA_SFRmap *) ((uint32_t)0x40001600)))
    {
        RST_CTL2_Peripheral_Reset_Enable(((uint32_t)1<<((12))), TRUE);
        RST_CTL2_Peripheral_Reset_Enable(((uint32_t)1<<((12))), FALSE);
        PCLK_CTL2_Peripheral_Clock_Enable(((uint32_t)1<<((12))), TRUE);
    }


    if (DMAx == ((DMA_SFRmap *) ((uint32_t)0x40001700)))
    {
        RST_CTL2_Peripheral_Reset_Enable(((uint32_t)1<<((14))), TRUE);
        RST_CTL2_Peripheral_Reset_Enable(((uint32_t)1<<((14))), FALSE);
        PCLK_CTL2_Peripheral_Clock_Enable(((uint32_t)1<<((14))), TRUE);
    }

}







void
DMA_Configuration (DMA_SFRmap* DMAx,
                    DMA_InitTypeDef* dmaInitStruct)
{
    uint32_t tmpreg = 0;
    uint32_t tmpchannel = 0;


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

    tmpchannel = dmaInitStruct->m_Channel;
# 100 "../system/src/kf32a_basic_dma.c"
    tmpreg = ((uint32_t)dmaInitStruct->m_Number << (16))
           | ((uint32_t)dmaInitStruct->m_Priority)
           | ((uint32_t)dmaInitStruct->m_PeripheralDataSize << (10))
           | ((uint32_t)dmaInitStruct->m_MemoryDataSize << (8))
           | (dmaInitStruct->m_PeripheralInc << (7))
           | (dmaInitStruct->m_MemoryInc << (6))
           | (dmaInitStruct->m_LoopMode << (5))
           | ((uint32_t)dmaInitStruct->m_Direction)
           | (dmaInitStruct->m_BlockMode);
    DMAx->CTLR[tmpchannel] = SFR_Config (DMAx->CTLR[tmpchannel],
                          ~(((uint32_t)0xFFFF<<((16))) | ((uint32_t)3<<((13))) | ((uint32_t)3<<((10))) | ((uint32_t)3<<((8))) | ((uint32_t)1<<((7))) | ((uint32_t)1<<((6))) | ((uint32_t)1<<((5))) | ((uint32_t)1<<((4))) | ((uint32_t)1<<((3)))),
                          tmpreg);


    DMAx->PADDR[tmpchannel] = dmaInitStruct->m_PeriphAddr;


    DMAx->MADDR[tmpchannel] = dmaInitStruct->m_MemoryAddr;
}






void
DMA_Struct_Init (DMA_InitTypeDef* dmaInitStruct)
{

    dmaInitStruct->m_Channel = ((uint32_t)0);

    dmaInitStruct->m_Priority = ((uint32_t)0<<(13));

    dmaInitStruct->m_Direction = ((uint32_t)0<<(4));

    dmaInitStruct->m_PeripheralDataSize = ((uint32_t)0);

    dmaInitStruct->m_MemoryDataSize = ((uint32_t)0);

    dmaInitStruct->m_Number = 0;

    dmaInitStruct->m_PeripheralInc = FALSE;

    dmaInitStruct->m_MemoryInc = FALSE;

    dmaInitStruct->m_LoopMode = FALSE;

    dmaInitStruct->m_BlockMode = ((uint32_t)0<<(3));

    dmaInitStruct->m_PeriphAddr = 0;

    dmaInitStruct->m_MemoryAddr = 0;
}
# 175 "../system/src/kf32a_basic_dma.c"
void
DMA_Transfer_Number_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint16_t Number)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = (uint32_t)Number << (16);
    DMAx->CTLR[Channel] = SFR_Config (DMAx->CTLR[Channel],
                                ~((uint32_t)0xFFFF<<((16))),
                                tmpreg);
}
# 206 "../system/src/kf32a_basic_dma.c"
void
DMA_Memory_To_Memory_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((15)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((15)));
    }
}
# 246 "../system/src/kf32a_basic_dma.c"
void
DMA_Channel_Priority_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Priority)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = (uint32_t)Priority << (13);
    DMAx->CTLR[Channel] = SFR_Config (DMAx->CTLR[Channel],
                                ~((uint32_t)3<<((13))),
                                tmpreg);
}
# 281 "../system/src/kf32a_basic_dma.c"
void
DMA_Peripheral_Data_Width_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Width)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = Width << (10);
    DMAx->CTLR[Channel] = SFR_Config (DMAx->CTLR[Channel],
                                ~((uint32_t)3<<((10))),
                                tmpreg);
}
# 316 "../system/src/kf32a_basic_dma.c"
void
DMA_Memory_Data_Width_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Width)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = Width << (8);
    DMAx->CTLR[Channel] = SFR_Config (DMAx->CTLR[Channel],
                                ~((uint32_t)3<<((8))),
                                tmpreg);
}
# 348 "../system/src/kf32a_basic_dma.c"
void
DMA_Peripheral_addr_increase_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((7)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((7)));
    }
}
# 384 "../system/src/kf32a_basic_dma.c"
void
DMA_Memory_addr_increase_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((6)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((6)));
    }
}
# 420 "../system/src/kf32a_basic_dma.c"
void
DMA_Loop_Mode_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((5)));
    }
}
# 458 "../system/src/kf32a_basic_dma.c"
void
DMA_Transfer_Direction_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Direction)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (Direction != ((uint32_t)0<<(4)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((4)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((4)));
    }
}
# 496 "../system/src/kf32a_basic_dma.c"
void
DMA_Transfer_Mode_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t BlockMode)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (BlockMode != ((uint32_t)0<<(3)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((3)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((3)));
    }
}
# 532 "../system/src/kf32a_basic_dma.c"
void
DMA_Oneshot_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((12)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((12)));
    }
}
# 567 "../system/src/kf32a_basic_dma.c"
void
DMA_Channel_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{

    ((void)0);
    ((void)0);
    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&(DMAx->CTLR[Channel])),"i"((0)));
    }
}
# 603 "../system/src/kf32a_basic_dma.c"
void
DMA_Peripheral_Start_Address_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Address)
{

    ((void)0);
    ((void)0);


    DMAx->PADDR[Channel] = Address;
}
# 629 "../system/src/kf32a_basic_dma.c"
void
DMA_Memory_Start_Address_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Address)
{

    ((void)0);
    ((void)0);


    DMAx->MADDR[Channel] = Address;
}
# 654 "../system/src/kf32a_basic_dma.c"
uint32_t
DMA_Get_Peripheral_Current_Address (DMA_SFRmap* DMAx, uint32_t Channel)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = DMAx->CPAR[Channel];
    return tmpreg;
}
# 681 "../system/src/kf32a_basic_dma.c"
uint32_t
DMA_Get_Memory_Current_Address (DMA_SFRmap* DMAx, uint32_t Channel)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = DMAx->CMAR[Channel];
    return tmpreg;
}
# 708 "../system/src/kf32a_basic_dma.c"
uint16_t
DMA_Get_Transfer_Number_Remain (DMA_SFRmap* DMAx, uint32_t Channel)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = DMAx->NCT[Channel] & ((uint32_t)0xFFFF<<((16)));
    tmpreg >>= (16);

    return (uint16_t)tmpreg;
}
# 748 "../system/src/kf32a_basic_dma.c"
FlagStatus
DMA_Get_INT_Flag (DMA_SFRmap* DMAx, uint32_t Channel, uint32_t InterruptType)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpreg = InterruptType << (Channel * 3);

    if (DMAx->LIFR & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 790 "../system/src/kf32a_basic_dma.c"
void
DMA_Clear_INT_Flag (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t InterruptType)
{
    uint32_t tmpmask = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpmask = InterruptType << (Channel * 3);
    DMAx->LIFR &= ~tmpmask;
}
# 824 "../system/src/kf32a_basic_dma.c"
void
DMA_Set_INT_Enable (DMA_SFRmap* DMAx, uint32_t Channel,
                    uint32_t InterruptType, FunctionalState NewState)
{
    uint32_t tmpmask = 0;


    ((void)0);
    ((void)0);
    ((void)0);
    ((void)0);


    tmpmask = InterruptType << (Channel * 3);
    if (NewState != FALSE)
    {
        DMAx->LIER |= tmpmask;
    }
    else
    {
        DMAx->LIER &= ~tmpmask;
    }
}
# 861 "../system/src/kf32a_basic_dma.c"
FlagStatus
DMA_Get_Error_Transfer_INT_Flag (DMA_SFRmap* DMAx, uint32_t Channel)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);

    tmpreg = ((uint32_t)1<<((2))) << (Channel * 3);

    if (DMAx->LIFR & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 897 "../system/src/kf32a_basic_dma.c"
FlagStatus
DMA_Get_Half_Transfer_INT_Flag (DMA_SFRmap* DMAx, uint32_t Channel)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);

    tmpreg = ((uint32_t)1<<((1))) << (Channel * 3);

    if (DMAx->LIFR & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 933 "../system/src/kf32a_basic_dma.c"
FlagStatus
DMA_Get_Finish_Transfer_INT_Flag (DMA_SFRmap* DMAx, uint32_t Channel)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);

    tmpreg = ((uint32_t)1<<((0))) << (Channel * 3);

    if (DMAx->LIFR & tmpreg)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 970 "../system/src/kf32a_basic_dma.c"
void
DMA_Error_Transfer_INT_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{
    uint32_t tmpmask = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpmask = ((uint32_t)1<<((2))) << (Channel * 3);
    if (NewState != FALSE)
    {
        DMAx->LIER |= tmpmask;
    }
    else
    {
        DMAx->LIER &= ~tmpmask;
    }
}
# 1007 "../system/src/kf32a_basic_dma.c"
void
DMA_Half_Transfer_INT_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{
    uint32_t tmpmask = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpmask = ((uint32_t)1<<((1))) << (Channel * 3);
    if (NewState != FALSE)
    {
        DMAx->LIER |= tmpmask;
    }
    else
    {
        DMAx->LIER &= ~tmpmask;
    }
}
# 1044 "../system/src/kf32a_basic_dma.c"
void
DMA_Finish_Transfer_INT_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{
    uint32_t tmpmask = 0;


    ((void)0);
    ((void)0);
    ((void)0);


    tmpmask = ((uint32_t)1<<((0))) << (Channel * 3);
    if (NewState != FALSE)
    {
        DMAx->LIER |= tmpmask;
    }
    else
    {
        DMAx->LIER &= ~tmpmask;
    }
}