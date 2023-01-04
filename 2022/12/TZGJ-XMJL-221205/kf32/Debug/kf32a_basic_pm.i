# 1 "../system/src/kf32a_basic_pm.c"
# 1 "/cygdrive/h/workspace32/App/Debug//"
# 1 "<command-line>"
# 1 "../system/src/kf32a_basic_pm.c"
# 15 "../system/src/kf32a_basic_pm.c"
# 1 "H:/workspace32/App/system/inc/kf32a_basic_pm.h" 1
# 14 "H:/workspace32/App/system/inc/kf32a_basic_pm.h"
# 1 "H:/workspace32/App/system/inc/KF32A_BASIC.h" 1
# 20 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 21 "H:/workspace32/App/system/inc/KF32A_BASIC.h" 2
# 1 "H:/workspace32/App/system/inc/KF32A_Config.h" 1
# 15 "H:/workspace32/App/system/inc/KF32A_Config.h"
# 1 "H:\\workspace32\\App/__Kungfu32_chipmodel_define.h" 1
# 16 "H:/workspace32/App/system/inc/KF32A_Config.h" 2
# 22 "H:/workspace32/App/system/inc/KF32A_BASIC.h" 2
# 36 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 171 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 1127 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 1450 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 3317 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
typedef struct SYSCTL_MemMap {
    volatile uint32_t PSW;
    volatile uint32_t MCTL;
    volatile uint32_t ARCTL;
    volatile uint32_t VECTOFF;
          uint32_t RESEVRVE1;
    volatile uint32_t RAMSPA;
    volatile uint32_t MEMCTL;
}SYSCTL_SFRmap;
# 3406 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 4066 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 4721 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
typedef struct SYSTICK_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t RELOAD;
    volatile uint32_t CV;
    volatile uint32_t CALI;
}SYSTICK_SFRmap;
# 4775 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 4963 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 5573 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 6302 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
typedef struct QEI_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CNT;
    volatile uint32_t PPX;
    volatile uint32_t PRSC;
    volatile uint32_t DIER;
}QEI_SFRmap;
# 6420 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
typedef struct DAC_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t DAHD;
    volatile const uint32_t DATA;
    volatile uint32_t CTL1;
                   uint32_t RESERVED;
    volatile uint32_t CAL;
}DAC_SFRmap;
# 6573 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
typedef struct CMP_MemMap {
    volatile uint32_t CTL;





}CMP_SFRmap;
# 8136 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 8679 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
typedef struct IWDT_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t FD;
}IWDT_SFRmap;
# 8712 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
typedef struct WWDT_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t CNT;
}WWDT_SFRmap;
# 8752 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
typedef struct RST_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}RST_SFRmap;
# 9132 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
typedef struct PCLK_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t CTL2;
    volatile uint32_t CTL3;
}PCLK_SFRmap;
# 9512 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
typedef struct SPI_MemMap {
    volatile uint32_t BRGR;
    volatile uint32_t CTLR;
    volatile uint32_t BUFR;
    volatile uint32_t STR;
}SPI_SFRmap;
# 9672 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 9934 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 11943 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 12722 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 13117 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
typedef struct BKP_MemMap {
    volatile uint32_t CTL;
    volatile uint32_t INT;
             uint32_t RESERVED[14];
    volatile uint32_t DATA[32];
}BKP_SFRmap;
# 13223 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 13421 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 13471 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
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
# 13925 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
typedef struct EXIC_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t STATE;
       uint32_t RESERVED1;
    volatile uint32_t WRITEBUF;
    volatile uint32_t READBUF;

}EXIC_SFRmap;
# 14005 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
typedef struct CFGL_MemMap {
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
    volatile uint32_t IFR;
}CFGL_SFRmap;
# 14184 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
typedef struct OP_MemMap {
    volatile uint32_t CAL;
    volatile uint32_t CTL0;
    volatile uint32_t CTL1;
}OP_SFRmap;
# 14358 "H:/workspace32/App/system/inc/KF32A_BASIC.h"
static inline uint32_t
SFR_Config (uint32_t SfrMem, uint32_t SfrMask, uint32_t WriteVal)
{
    return ((SfrMem & SfrMask) | (WriteVal));
}
# 15 "H:/workspace32/App/system/inc/kf32a_basic_pm.h" 2
# 429 "H:/workspace32/App/system/inc/kf32a_basic_pm.h"
void PM_IO_Latch_Enable (FunctionalState NewState);
FlagStatus PM_Get_IO_Latch_Status (void);
void PM_Internal_Low_Frequency_Enable (FunctionalState NewState);
void PM_External_Low_Frequency_Enable (FunctionalState NewState);
void PM_External_Low_Frequency_Clock_Enable (FunctionalState NewState);
void PM_Main_Bandgap_Enable (FunctionalState NewState);
void PM_LDO18_Enable (FunctionalState NewState);
void PM_Backup_Registers_Reset_Config (uint32_t BkpReset);
void PM_Independent_Watchdog_Reset_Config (uint32_t IWDTReset);
void PM_SRAMA_In_Standby_Work_Mode_Config (uint32_t WorkMode);
void PM_LPRAM_In_Standby_Work_Mode_Config (uint32_t WorkMode);
void PM_Backup_POR_Delay_Time_Config (uint32_t DelayTime);
void PM_Main_POR_Delay_Time_Config (uint32_t DelayTime);
void PM_Peripheral_IO_Port_Config (uint32_t PeripheralPort);
void PM_OCAL0LOCK_Enable (FunctionalState NewState);
void PM_MEMSEL_Enable (FunctionalState NewState);
void PM_Flash_Power_Off_Enable (FunctionalState NewState);
void PM_Backup_Write_And_Read_Enable (FunctionalState NewState);
void PM_LPR_Software_Enable (FunctionalState NewState);
void PM_Low_Power_Mode_Config (uint32_t LowPowerMode);
void PM_BOR_Enable (FunctionalState NewState);
void PM_Low_Power_BOR_Enable (FunctionalState NewState);
void PM_Temperature_Sensor_Enable (FunctionalState NewState);
void PM_Temperature_Sensor_Buffer_Enable (FunctionalState NewState);
void PM_Reference_Voltage_Enable (FunctionalState NewState);
void PM_Internal_Test_Buffer_Clock_Enable (FunctionalState NewState);
void PM_Internal_Test_Buffer_Clock_Scaler_Config (uint32_t SclkScaler);
void PM_CCP0CLKLPEN_Enable (FunctionalState NewState);
void PM_PLL0_Output_Buffer_Enable (FunctionalState NewState);
void PM_PLL1_Output_Buffer_Enable (FunctionalState NewState);
void PM_PLL2_Output_Buffer_Enable (FunctionalState NewState);
void PM_PLL0LDO_Output_Buffer_Enable (FunctionalState NewState);
void PM_PLL1LDO_Output_Buffer_Enable (FunctionalState NewState);
void PM_PLL2LDO_Output_Buffer_Enable (FunctionalState NewState);
void PM_Battery_BOR_Config (uint32_t Voltage);
void PM_Battery_BOR_Enable (FunctionalState NewState);
void PM_Peripheral_Voltage_Monitoring_Enable (FunctionalState NewState);
void PM_Voltage_Detection_Config (uint32_t Voltage);
void PM_Voltage_Detection_Enable (FunctionalState NewState);
void PM_EXTLF_PIN_Selection_Config (uint32_t PeripheralPort);
void PM_EXTHF_PIN_Selection_Config (uint32_t PeripheralPort);
void PM_External_Wakeup_Pin_Enable (uint32_t PinSel, FunctionalState NewState);
void PM_External_Wakeup_Edge_Config (uint32_t PinSel, uint32_t TriggerEdge);
void PM_Stop_Mode_Peripheral_INLF_Enable (uint32_t Peripheral,
                    FunctionalState NewState);
void PM_Peripheral_Reset_Config (uint32_t Peripheral, uint32_t ResetStatus);

void PM_Vdd_Por_Enable (FunctionalState NewState);
void PM_Low_Power_Bandgap_Enable (FunctionalState NewState);
void PM_Power_Dissipation_Mode_Config (uint32_t Mode);
void PM_Power_Dissipation_Mode_Delay_Config (uint32_t DelayTime);
void PM_Internal_Test_Buffer_Enable (FunctionalState NewState);


void PM_Clear_Reset_And_Wakeup_Flag (uint32_t EventSel);
FlagStatus PM_Get_IWDT_Reset_Flag (uint32_t EventSel);
void PM_Clear_External_Wakeup_Pin_Flag (uint32_t EventSel);
FlagStatus PM_Get_Low_Power_Running_State (void);
FlagStatus PM_Get_LPR_Status (void);
FlagStatus PM_Get_Peripheral_Voltage_Detection_Status (void);

void PM_Zero_Drift_Current_Config (uint32_t Calibration);
void PM_BOR_Voltage_Config (uint32_t Voltage);
void PM_Main_Regulator_Voltage_Config (uint32_t MRSel, uint32_t Voltage);
void PM_Main_Regulator_HV_Enable (FunctionalState NewState);
void PM_Reference_Calibration_Config (uint32_t Reference,
                    uint32_t Calibration);
void PM_INTLF_Bias_Current_Config (uint32_t Calibration);
void PM_EXTLF_Bias_Current_Config (uint32_t Calibration);
void PM_INTLF_Capacitance_Calibration_Config (uint32_t Calibration);
void PM_LP_Bias_Calibration_Config (uint32_t Calibration);
void PM_LPBG_Pump_Calibration_Config (uint32_t Calibration);
void PM_EXTLF_N_Bias_Current_Config (uint32_t Calibration);

void PM_LDO18_Module_Config (uint32_t LDO18Config);
void PM_Main_Regulator_Bandgap_Config (uint32_t ModeSel);
void PM_LPR_Module_Config (uint32_t ModeSel);
void PM_VREF_SELECT (uint32_t Voltage);
void PM_VREF_Software_Enable (FunctionalState NewState);
# 16 "../system/src/kf32a_basic_pm.c" 2
# 1 "H:/workspace32/App/system/inc/kf32a_basic_osc.h" 1
# 21 "H:/workspace32/App/system/inc/kf32a_basic_osc.h"
typedef struct
{
    uint32_t m_InputSource;


    uint32_t m_CLKDivision;


    uint32_t m_PLLInputSource;


    uint32_t m_StartDelay;

} OSC_InitTypeDef;
# 267 "H:/workspace32/App/system/inc/kf32a_basic_osc.h"
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
# 17 "../system/src/kf32a_basic_pm.c" 2
# 27 "../system/src/kf32a_basic_pm.c"
void
PM_IO_Latch_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((31)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((31)));
    }
}






FlagStatus
PM_Get_IO_Latch_Status (void)
{

    if ((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0) & ((uint32_t)1<<((31))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}






void
PM_Internal_Low_Frequency_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((29)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((29)));
    }
}






void
PM_External_Low_Frequency_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((28)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((28)));
    }
}






void
PM_External_Low_Frequency_Clock_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((27)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((27)));
    }
}






void
PM_Main_Bandgap_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((25)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((25)));
    }
}






void
PM_LDO18_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((24)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((24)));
    }
}
# 194 "../system/src/kf32a_basic_pm.c"
void
PM_Backup_Registers_Reset_Config (uint32_t BkpReset)
{

    ((void)0);


    if (BkpReset != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((22)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((22)));
    }
}
# 220 "../system/src/kf32a_basic_pm.c"
void
PM_Independent_Watchdog_Reset_Config (uint32_t IWDTReset)
{

    ((void)0);


    if (IWDTReset != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((21)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((21)));
    }
}
# 246 "../system/src/kf32a_basic_pm.c"
void
PM_SRAMA_In_Standby_Work_Mode_Config (uint32_t WorkMode)
{

    ((void)0);


    if (WorkMode != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((20)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((20)));
    }
}
# 272 "../system/src/kf32a_basic_pm.c"
void
PM_LPRAM_In_Standby_Work_Mode_Config (uint32_t WorkMode)
{

    ((void)0);


    if (WorkMode != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((19)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((19)));
    }
}
# 299 "../system/src/kf32a_basic_pm.c"
void
PM_Backup_POR_Delay_Time_Config (uint32_t DelayTime)
{

    ((void)0);


    if (DelayTime != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((14)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((14)));
    }
}
# 325 "../system/src/kf32a_basic_pm.c"
void
PM_Main_POR_Delay_Time_Config (uint32_t DelayTime)
{

    ((void)0);


    if (DelayTime != ((uint32_t)0))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((15)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((15)));
    }
}
# 351 "../system/src/kf32a_basic_pm.c"
void
PM_Peripheral_IO_Port_Config (uint32_t PeripheralPort)
{

    ((void)0);


    if (PeripheralPort != ((uint32_t)0<<(13)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((13)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((13)));
    }
}





void
PM_OCAL0LOCK_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((6)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((6)));
    }
}






void
PM_MEMSEL_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((3)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((3)));
    }
}







void
PM_Flash_Power_Off_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2))),"i"((11)));
    }
    else
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2))),"i"((11)));
    }
}






void
PM_CCP0CLKLPEN_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2))),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2))),"i"((5)));
    }
}





void
PM_Backup_Write_And_Read_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((7)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((7)));
    }
}





void
PM_VREF_Software_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((5)));
    }
}
# 520 "../system/src/kf32a_basic_pm.c"
void
PM_VREF_SELECT (uint32_t Voltage)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1), ~((uint32_t)0x3<<((6))), Voltage);
}





void
PM_LPR_Software_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((5)));
    }
}
# 562 "../system/src/kf32a_basic_pm.c"
void
PM_Low_Power_Mode_Config (uint32_t LowPowerMode)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0), ~((uint32_t)7<<((0))), LowPowerMode);
}






void
PM_BOR_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((31)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((31)));
    }
}






void
PM_Low_Power_BOR_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((30)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((30)));
    }
}






void
PM_Temperature_Sensor_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((29)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((29)));
    }
}






void
PM_Temperature_Sensor_Buffer_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((28)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((28)));
    }
}






void
PM_Reference_Voltage_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((5)));
    }
}






void
PM_Internal_Test_Buffer_Clock_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((25)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((25)));
    }
}
# 729 "../system/src/kf32a_basic_pm.c"
void
PM_Internal_Test_Buffer_Clock_Scaler_Config (uint32_t SclkScaler)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1), ~((uint32_t)7<<((22))), SclkScaler);
}






void
PM_PLL0_Output_Buffer_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((21)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((21)));
    }
}






void
PM_PLL1_Output_Buffer_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((20)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((20)));
    }
}






void
PM_PLL2_Output_Buffer_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((19)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((19)));
    }
}






void
PM_PLL0LDO_Output_Buffer_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((18)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((18)));
    }
}






void
PM_PLL1LDO_Output_Buffer_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((17)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((17)));
    }
}






void
PM_PLL2LDO_Output_Buffer_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((16)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((16)));
    }
}
# 894 "../system/src/kf32a_basic_pm.c"
void
PM_Battery_BOR_Config (uint32_t Voltage)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1), ~((uint32_t)7<<((12))), Voltage);
}






void
PM_Battery_BOR_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((15)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((15)));
    }
}






void
PM_Peripheral_Voltage_Monitoring_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((5)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((5)));
    }
}
# 964 "../system/src/kf32a_basic_pm.c"
void
PM_Voltage_Detection_Config (uint32_t Voltage)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1), ~((uint32_t)7<<((2))), Voltage);
}






void
PM_Voltage_Detection_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((0)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((0)));
    }
}
# 1009 "../system/src/kf32a_basic_pm.c"
void
PM_External_Wakeup_Pin_Enable (uint32_t PinSel, FunctionalState NewState)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((27))) << PinSel;
    if (NewState != FALSE)
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) |= tmpreg;
    }
    else
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) &= ~tmpreg;
    }
}
# 1045 "../system/src/kf32a_basic_pm.c"
void
PM_External_Wakeup_Edge_Config (uint32_t PinSel, uint32_t TriggerEdge)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((22))) << PinSel;
    if (TriggerEdge != ((uint32_t)0))
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) |= tmpreg;
    }
    else
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) &= ~tmpreg;
    }
}
# 1078 "../system/src/kf32a_basic_pm.c"
void
PM_Stop_Mode_Peripheral_INLF_Enable (uint32_t Peripheral,
                    FunctionalState NewState)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((4))) << Peripheral;
    if (NewState != FALSE)
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) |= tmpreg;
    }
    else
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) &= ~tmpreg;
    }
}
# 1114 "../system/src/kf32a_basic_pm.c"
void
PM_Peripheral_Reset_Config (uint32_t Peripheral, uint32_t ResetStatus)
{
    uint32_t tmpreg = 0;


    ((void)0);
    ((void)0);


    tmpreg = ((uint32_t)1<<((0))) << Peripheral;
    if (ResetStatus != ((uint32_t)0))
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) |= tmpreg;
    }
    else
    {

        (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL2) &= ~tmpreg;
    }
}







void
PM_Vdd_Por_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((30)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((30)));
    }
}






void
PM_Low_Power_Bandgap_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((23)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((23)));
    }
}
# 1193 "../system/src/kf32a_basic_pm.c"
void
PM_Power_Dissipation_Mode_Config (uint32_t Mode)
{

    ((void)0);


    if (Mode != ((uint32_t)0<<(11)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((11)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0))),"i"((11)));
    }
}
# 1220 "../system/src/kf32a_basic_pm.c"
void
PM_Power_Dissipation_Mode_Delay_Config (uint32_t DelayTime)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL0), ~((uint32_t)3<<((9))), DelayTime);
}






void
PM_Internal_Test_Buffer_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((26)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CTL1))),"i"((26)));
    }
}
# 1273 "../system/src/kf32a_basic_pm.c"
void
PM_Clear_Reset_And_Wakeup_Flag (uint32_t EventSel)
{
    uint32_t tmpreg = 0;
    uint32_t tmpmask = 0;


    ((void)0);
    tmpmask = (uint32_t)1 << EventSel;

    __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->STA0))),"i"((31)));
    while((((PM_SFRmap *) ((uint32_t)0x40001580))->STA0) & tmpmask);
    __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->STA0))),"i"((31)));
}
# 1305 "../system/src/kf32a_basic_pm.c"
FlagStatus
PM_Get_IWDT_Reset_Flag (uint32_t EventSel)
{
    uint32_t tmpreg = 0;
    uint32_t tmpmask = 0;


    ((void)0);

    if (EventSel < 32)
    {
        tmpreg = (((PM_SFRmap *) ((uint32_t)0x40001580))->STA0);
        tmpmask = (uint32_t)1 << EventSel;
    }
    else
    {
        tmpreg = (((PM_SFRmap *) ((uint32_t)0x40001580))->STA1);
        tmpmask = (uint32_t)1 << (EventSel - 32);
    }


    if (tmpreg & tmpmask)
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 1348 "../system/src/kf32a_basic_pm.c"
void
PM_Clear_External_Wakeup_Pin_Flag (uint32_t EventSel)
{
    uint32_t tmpreg = 0;
    uint32_t tmpmask = 0;

    ((void)0);
    tmpmask = (uint32_t)1 << (EventSel - 32);

    (((PM_SFRmap *) ((uint32_t)0x40001580))->STAC) |= tmpmask;
    while((((PM_SFRmap *) ((uint32_t)0x40001580))->STA1) & tmpmask);
    (((PM_SFRmap *) ((uint32_t)0x40001580))->STAC) &= ~tmpmask;
}






FlagStatus
PM_Get_Low_Power_Running_State (void)
{

    if ((((PM_SFRmap *) ((uint32_t)0x40001580))->STA0) & ((uint32_t)1<<((1))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus
PM_Get_LPR_Status (void)
{

    if ((((PM_SFRmap *) ((uint32_t)0x40001580))->STA0) & ((uint32_t)1<<((0))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}







FlagStatus
PM_Get_Peripheral_Voltage_Detection_Status (void)
{

    if ((((PM_SFRmap *) ((uint32_t)0x40001580))->STA1) & ((uint32_t)1<<((0))))
    {

        return SET;
    }
    else
    {

        return RESET;
    }
}
# 1443 "../system/src/kf32a_basic_pm.c"
void
PM_Zero_Drift_Current_Config (uint32_t Calibration)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0), ~((uint32_t)3<<((24))), Calibration);
}
# 1462 "../system/src/kf32a_basic_pm.c"
void
PM_BOR_Voltage_Config (uint32_t Voltage)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0), ~((uint32_t)3<<((20))), Voltage);
}
# 1484 "../system/src/kf32a_basic_pm.c"
void
PM_Main_Regulator_Voltage_Config (uint32_t MRSel, uint32_t Voltage)
{
    uint32_t tmpreg = 0;
    uint32_t tmpmask = 0;


    ((void)0);
    ((void)0);


    tmpreg = Voltage << MRSel;
    tmpmask = (uint32_t)0xF << MRSel;
    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0), ~tmpmask, tmpreg);
}






void
PM_Main_Regulator_HV_Enable (FunctionalState NewState)
{

    ((void)0);


    if (NewState != FALSE)
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0))),"i"((15)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0))),"i"((15)));
    }
}
# 1536 "../system/src/kf32a_basic_pm.c"
void
PM_Reference_Calibration_Config (uint32_t Reference, uint32_t Calibration)
{
    uint32_t tmpreg = 0;
    uint32_t tmpmask = 0;


    switch (Reference)
    {
        case ((8)):
            ((void)0);
            tmpreg = Calibration << ((8));
            tmpmask = ((uint32_t)0x1F<<((8)));
            break;
        case ((4)):
            ((void)0);
            tmpreg = Calibration << ((4));
            tmpmask = ((uint32_t)0xF<<((4)));
            break;
        case ((0)):
            ((void)0);
            tmpreg = Calibration << ((0));
            tmpmask = ((uint32_t)0xF<<((0)));
            break;
        default:
            ((void)0);
            break;
    }


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0), ~tmpmask, tmpreg);
}
# 1582 "../system/src/kf32a_basic_pm.c"
void
PM_INTLF_Bias_Current_Config (uint32_t Calibration)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1), ~((uint32_t)7<<((29))), Calibration);
}
# 1605 "../system/src/kf32a_basic_pm.c"
void
PM_EXTLF_Bias_Current_Config (uint32_t Calibration)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1), ~((uint32_t)0xF<<((4))), Calibration);
}






void
PM_INTLF_Capacitance_Calibration_Config (uint32_t Calibration)
{
 uint32_t tmpreg=0;

    ((void)0);


    tmpreg = Calibration << (4);
    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1), ~((uint32_t)0xF<<((4))), tmpreg);
}






void
PM_LP_Bias_Calibration_Config (uint32_t Calibration)
{
 uint32_t tmpreg=0;

    ((void)0);


    tmpreg = Calibration << (20);
    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1), ~((uint32_t)0x7<<((20))), tmpreg);
}






void
PM_LPBG_Pump_Calibration_Config (uint32_t Calibration)
{
 uint32_t tmpreg=0;

    ((void)0);


    tmpreg = Calibration << (16);
    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1), ~((uint32_t)0x7<<((16))), tmpreg);

}
# 1676 "../system/src/kf32a_basic_pm.c"
void
PM_EXTLF_N_Bias_Current_Config (uint32_t Calibration)
{

    ((void)0);


    (((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1) = SFR_Config ((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1), ~((uint32_t)3<<((0))), Calibration);
}







void
PM_EXTLF_PIN_Selection_Config (uint32_t PeripheralPort)
{

    ((void)0);


    if (PeripheralPort != ((uint32_t)0<<(19)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1))),"i"((19)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1))),"i"((19)));
    }
}
# 1718 "../system/src/kf32a_basic_pm.c"
void
PM_EXTHF_PIN_Selection_Config (uint32_t PeripheralPort)
{

    ((void)0);


    if (PeripheralPort != ((uint32_t)0<<(15)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1))),"i"((15)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL1))),"i"((15)));
    }
}
# 1751 "../system/src/kf32a_basic_pm.c"
void
PM_LDO18_Module_Config (uint32_t LDO18Config)
{

    ((void)0);


    if (LDO18Config != ((uint32_t)0<<(31)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0))),"i"((31)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0))),"i"((31)));
    }
}
# 1777 "../system/src/kf32a_basic_pm.c"
void
PM_Main_Regulator_Bandgap_Config (uint32_t ModeSel)
{

    ((void)0);


    if (ModeSel != ((uint32_t)0<<(30)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0))),"i"((30)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0))),"i"((30)));
    }
}
# 1803 "../system/src/kf32a_basic_pm.c"
void
PM_LPR_Module_Config (uint32_t ModeSel)
{

    ((void)0);


    if (ModeSel != ((uint32_t)0<<(29)))
    {

        __asm volatile("SET [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0))),"i"((30)));
    }
    else
    {

        __asm volatile("CLR [%0], #%1"::"r"(&((((PM_SFRmap *) ((uint32_t)0x40001580))->CAL0))),"i"((30)));
    }
}
