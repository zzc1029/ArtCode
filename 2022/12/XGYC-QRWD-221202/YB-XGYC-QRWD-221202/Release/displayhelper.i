# 1 "../source/displayhelper.c"
# 1 "/cygdrive/h/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/Release//"
# 1 "<command-line>"
# 1 "../source/displayhelper.c"







# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 1
# 14 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h"
# 1 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys/string.h" 1
# 17 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys/string.h"
typedef unsigned int size_t;






extern int ffs (int);
extern int ffsl (long);
extern int ffsll (long long);
extern void * memchr(const void *, int, size_t);
extern int memcmp(const void *, const void *, size_t);
extern void * memcpy(void *, const void *, size_t);
extern void * memmove(void *, const void *, size_t);
extern void * memset(void *, int, size_t);
extern int strcasecmp (const char *, const char *);
extern char * strcat(char *, const char *);
extern char * strchr(const char *, int);
extern int strcmp(const char *, const char *);
extern int strcoll(const char *, const char *);
extern char * strcpy(char *, const char *);
extern size_t strcspn(const char *, const char *);

extern size_t strlen(const char *);
extern int strncasecmp (const char *, const char *, size_t);
extern char * strncat(char *, const char *, size_t);
extern int strncmp(const char *, const char *, size_t);
extern char * strncpy(char *, const char *, size_t);
extern char * strpbrk(const char *, const char *);
extern char * strrchr(const char *, int);
extern size_t strspn(const char *, const char *);
extern char * strstr(const char *, const char *);
extern char * strtok(char *, const char *);
extern size_t strxfrm(char *, const char *, size_t);


extern char * strdup(const char *);
# 15 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys/stdint.h" 1
# 16 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys/stdint.h"
# 1 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys/stddef.h" 1
# 24 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys/stddef.h"
typedef int ptrdiff_t;
# 35 "C:/Program Files (x86)/ChipON IDE/KungFu32/ChiponCC32/include/Sys/stddef.h"
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
# 16 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2

# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h" 1
# 21 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h"
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
# 18 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_adc.h" 1
# 15 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_adc.h"
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/KF32A_BASIC.h" 1
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
# 19 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_aes.h" 1
# 25 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_aes.h"
typedef struct
{
 uint32_t m_OFB;

 uint32_t m_ClockSelect;

 uint32_t m_ClockDiv;

 uint32_t m_Run;

 uint32_t m_FinishIntEn;

 uint32_t m_FinishIntClr;


} AES_InitTypeDef;
# 106 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_aes.h"
uint32_t GET_AES_OUTPUT0_DATA (void);
uint32_t GET_AES_OUTPUT1_DATA (void);
uint32_t GET_AES_OUTPUT2_DATA (void);
uint32_t GET_AES_OUTPUT3_DATA (void);
void AES_INPUT0_DATA (uint32_t DATA);
void AES_INPUT1_DATA (uint32_t DATA);
void AES_INPUT2_DATA (uint32_t DATA);
void AES_INPUT3_DATA (uint32_t DATA);
void AES_KEY0_DATA (uint32_t DATA);
void AES_KEY1_DATA (uint32_t DATA);
void AES_KEY2_DATA (uint32_t DATA);
void AES_KEY3_DATA (uint32_t DATA);
void AES_Struct_Init (AES_InitTypeDef* AESInitStruct);
void AES_Configuration (AES_InitTypeDef* AESInitStruct);
void AES_Reset ();
void AES_Start ();
void AES_CLR_Flag_Status ();
FlagStatus AES_Get_Flag_Status (void);
# 20 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_bkp.h" 1
# 62 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_bkp.h"
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
# 21 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_can.h" 1
# 21 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_can.h"
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
# 319 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_can.h"
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
# 22 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_cfgl.h" 1
# 25 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_cfgl.h"
typedef struct
{
 uint32_t m_Module_EN;

 uint32_t m_Output_EN;

 uint32_t m_RaiseINT_EN;

 uint32_t m_FallINT_EN;

 uint32_t m_Mode_Sel;

 uint32_t m_Output_Pol;

 uint32_t m_G4Output_POL;

 uint32_t m_G3Output_POL;

 uint32_t m_G2Output_POL;

 uint32_t m_G1Output_POL;

 uint32_t m_G4Input_Sel;

 uint32_t m_G3Input_Sel;

 uint32_t m_G2Input_Sel;

 uint32_t m_G1Input_Sel;

 uint32_t m_CH4Data_Sel;

 uint32_t m_CH5CH6Data_Sel;

 FunctionalState m_G4D4_Inphase_EN;

 FunctionalState m_G4D4_Inverse_EN;

 FunctionalState m_G4D3_Inphase_EN;

 FunctionalState m_G4D3_Inverse_EN;

 FunctionalState m_G4D2_Inphase_EN;

 FunctionalState m_G4D2_Inverse_EN;

 FunctionalState m_G4D1_Inphase_EN;

 FunctionalState m_G4D1_Inverse_EN;

 FunctionalState m_G3D4_Inphase_EN;

 FunctionalState m_G3D4_Inverse_EN;

 FunctionalState m_G3D3_Inphase_EN;

 FunctionalState m_G3D3_Inverse_EN;

 FunctionalState m_G3D2_Inphase_EN;

 FunctionalState m_G3D2_Inverse_EN;

 FunctionalState m_G3D1_Inphase_EN;

 FunctionalState m_G3D1_Inverse_EN;

 FunctionalState m_G2D4_Inphase_EN;

 FunctionalState m_G2D4_Inverse_EN;

 FunctionalState m_G2D3_Inphase_EN;

 FunctionalState m_G2D3_Inverse_EN;

 FunctionalState m_G2D2_Inphase_EN;

 FunctionalState m_G2D2_Inverse_EN;

 FunctionalState m_G2D1_Inphase_EN;

 FunctionalState m_G2D1_Inverse_EN;

 FunctionalState m_G1D4_Inphase_EN;

 FunctionalState m_G1D4_Inverse_EN;

 FunctionalState m_G1D3_Inphase_EN;

 FunctionalState m_G1D3_Inverse_EN;

 FunctionalState m_G1D2_Inphase_EN;

 FunctionalState m_G1D2_Inverse_EN;

 FunctionalState m_G1D1_Inphase_EN;

 FunctionalState m_G1D1_Inverse_EN;

} CFGL_InitTypeDef;
# 338 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_cfgl.h"
FlagStatus CFGL1_OUT_STATE ();
FlagStatus CFGL2_OUT_STATE ();
FlagStatus CFGL2_Get_INT_Flag ();
FlagStatus CFGL1_Get_INT_Flag ();
void CFGL1_FALLINT_Enable (FunctionalState NewState);
void CFGL1_RISEINT_Enable (FunctionalState NewState);
void CFGL2_FALLINT_Enable (FunctionalState NewState);
void CFGL2_RISEINT_Enable (FunctionalState NewState);
void CFGL1_OUT_SYNCHRO_Enable (FunctionalState NewState);
void CFGL2_OUT_SYNCHRO_Enable (FunctionalState NewState);
void CFGL_Configuration (CFGL_SFRmap* CFGLx, CFGL_InitTypeDef* CFGLInitStruct);
void CFGL_Reset ();
void CFGL1_Clear_RISEINT_Flag (void);
void CFGL1_Clear_FALLINT_Flag (void);
void CFGL1_Clear_RISEFALLINT_Flag (void);
void CFGL2_Clear_RISEINT_Flag (void);
void CFGL2_Clear_FALLINT_Flag (void);
void CFGL2_Clear_RISEFALLINT_Flag (void);
void CFGL_Struct_Init (CFGL_InitTypeDef* CFGLInitStruct);
# 23 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_cmp.h" 1
# 29 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_cmp.h"
typedef struct
{
 uint32_t m_PositiveInput;

    uint32_t m_NegativeInput;

    FunctionalState m_FallTriggerEnable;

    FunctionalState m_RiseTriggerEnable;

    uint32_t m_Clock;

    uint32_t m_FrequencyDivision;

    uint32_t m_SampleNumber;

    FunctionalState m_FilterEnable;

    FunctionalState m_ScopecontrolEnable;

    uint32_t m_OutputPolarity;

    FunctionalState m_CmpEnable;

}CMP_InitTypeDef;
# 412 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_cmp.h"
void CMP_Reset (void);
void CMP_Configuration (CMP_SFRmap * CMPx, CMP_InitTypeDef* CMPInitStruct);
void CMP_Struct_Init (CMP_InitTypeDef* CMPInitStruct);
void CMP0_Cmd (FunctionalState NewState);
void CMP1_Cmd (FunctionalState NewState);
void CMP2_Cmd (FunctionalState NewState);
void CMP3_Cmd (FunctionalState NewState);
void CMP0_POSITIVE_INPUT_SELECT (uint32_t Select);
void CMP0_NEGATIVE_INPUT_SELECT (uint32_t Select);
void CMP1_POSITIVE_INPUT_SELECT (uint32_t Select);
void CMP1_NEGATIVE_INPUT_SELECT (uint32_t Select);
void CMP2_POSITIVE_INPUT_SELECT (uint32_t Select);
void CMP2_NEGATIVE_INPUT_SELECT (uint32_t Select);
void CMP3_POSITIVE_INPUT_SELECT (uint32_t Select);
void CMP3_NEGATIVE_INPUT_SELECT (uint32_t Select);
void CMP0_OUTPUT_POL_SELECT (uint32_t Select);
void CMP1_OUTPUT_POL_SELECT (uint32_t Select);
void CMP2_OUTPUT_POL_SELECT (uint32_t Select);
void CMP3_OUTPUT_POL_SELECT (uint32_t Select);
void CMP_OUTPUT_SELECT (uint32_t Select);
FlagStatus CMP0_Read_Output_State ();
FlagStatus CMP1_Read_Output_State ();
FlagStatus CMP2_Read_Output_State ();
FlagStatus CMP3_Read_Output_State ();
FlagStatus CMP0_Get_Updata_INT_Flag ();
FlagStatus CMP1_Get_Updata_INT_Flag ();
FlagStatus CMP2_Get_Updata_INT_Flag ();
FlagStatus CMP3_Get_Updata_INT_Flag ();
void CMP_Trigger_Select_Config (uint32_t TriggerSelect);
void CMP0_Clear_Trigger_INT_Flag ();
void CMP1_Clear_Trigger_INT_Flag ();
void CMP2_Clear_Trigger_INT_Flag ();
void CMP3_Clear_Trigger_INT_Flag ();
void CMP0_INT_Enable (FunctionalState NewState);
void CMP1_INT_Enable (FunctionalState NewState);
void CMP2_INT_Enable (FunctionalState NewState);
void CMP3_INT_Enable (FunctionalState NewState);
void CMP0_INT_Enable (FunctionalState NewState);
void CMP1_INT_Enable (FunctionalState NewState);
void CMP2_INT_Enable (FunctionalState NewState);
void CMP3_INT_Enable (FunctionalState NewState);
void CMP_SluggishVoltage_Select (uint32_t Select);
void CMP_HALLMODE_Select (uint32_t Select);
void CMP_BEMF_Enable (FunctionalState NewState);
void CMP_FLTINSEL_Select (uint32_t Select);
# 24 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_crc.h" 1
# 25 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_crc.h"
typedef struct
{
 uint32_t m_CalUnitReset;

 uint32_t m_InputSize;

 uint32_t m_InputReverse;

 uint32_t m_ResultReverse;

 uint32_t m_Data;
 uint32_t m_Result;
 uint32_t m_InitialData;
 uint32_t m_Polynomial;
 uint32_t m_ResultXOR;
 uint32_t m_IndepentData;
 uint32_t m_Temp;
} CRC_InitTypeDef;
# 81 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_crc.h"
void CRC_Reset ();
void CRC_Configuration (CRC_InitTypeDef* CRCInitStruct);
void CRC_Struct_Init (CRC_InitTypeDef* CRCInitStruct);
void CRC_INPUT_DATA (uint32_t DATA);
uint32_t CRC_GET_RESULT ();
void CRC_SET_INITVALUE (uint32_t DATA);
void CRC_SET_PLN (uint32_t DATA);
void CRC_SET_RXOR (uint32_t DATA);
void CRC_SET_IDATA (uint32_t DATA);
uint32_t CRC_GET_TEMP ();
void CRC_SET_RSET ();
# 25 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_dac.h" 1
# 28 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_dac.h"
typedef struct
{
    FunctionalState m_TriggerEnable;

    uint32_t m_TriggerEvent;

    FunctionalState m_TriggerDMAEnable;

    uint32_t m_Wave;

    uint32_t m_Mas;

    uint32_t m_Clock;

    uint32_t m_ClockDiv;

    uint32_t m_ReferenceVoltage;

    FunctionalState m_OutputBuffer;

    uint32_t m_OutputPin;

    uint32_t m_Output;

}DAC_InitTypeDef;




typedef struct
{
    uint32_t m_PPositrim;

    uint32_t m_PNegatrim;

    uint32_t m_NPositrim;

    uint32_t m_NNegatrim;

    uint32_t m_Buftrim;

}DAC_CALTypeDef;
# 203 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_dac.h"
void DAC_Reset (DAC_SFRmap* DACx);
void DAC_Configuration (DAC_SFRmap* DACx, DAC_InitTypeDef* dacInitStruct);
void DAC_Struct_Init (DAC_InitTypeDef* dacInitStruct);
void DAC_Cmd (DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_Software_Trigger_Cmd (DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_DMA_Cmd (DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_Output_Buffer_Config (DAC_SFRmap* DACx, FunctionalState NewState);
void DAC_Output_Port_Config (DAC_SFRmap* DACx, FunctionalState NewState);

void DAC_Write_Output_Data (DAC_SFRmap* DACx, uint32_t Value);
uint32_t DAC_Read_Output_Data (DAC_SFRmap* DACx);

void DAC_Calibration_Config (DAC_SFRmap* DACx, DAC_CALTypeDef* dacInitStruct);
void DAC_Calibration_Struct_Init (DAC_CALTypeDef* dacCalStruct);
# 26 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_dma.h" 1
# 20 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_dma.h"
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
# 127 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_dma.h"
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
# 27 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_flash.h" 1
# 18 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_flash.h"
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
# 142 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_flash.h"
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
# 28 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_gpio.h" 1
# 33 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_gpio.h"
typedef enum
{
    GPIO_NOPULL = 0x00,
    GPIO_PULLUP = 0x01
}GPIOPU_TypeDef, GPIOPD_TypeDef;
# 47 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_gpio.h"
typedef enum
{
    GPIO_POD_PP = 0x00,
    GPIO_POD_OD = 0x01
}GPIOPOD_TypeDef;






typedef enum
{
    GPIO_MODE_IN = 0x00,
    GPIO_MODE_OUT = 0x01,
    GPIO_MODE_RMP = 0x02,
    GPIO_MODE_AN = 0x03
}GPIOMode_TypeDef;
# 73 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_gpio.h"
typedef enum
{
    GPIO_LOW_SPEED = 0,
    GPIO_HIGH_SPEED = 1
}GPIOSpeed_TypeDef;






typedef struct
{
    uint32_t m_Pin;


    GPIOMode_TypeDef m_Mode;


    GPIOSpeed_TypeDef m_Speed;


    GPIOPOD_TypeDef m_OpenDrain;


    GPIOPU_TypeDef m_PullUp;


    GPIOPD_TypeDef m_PullDown;

}GPIO_InitTypeDef;




typedef enum
{
    Bit_RESET = 0,
    Bit_SET = !Bit_RESET
}BitAction;
# 278 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_gpio.h"
void GPIO_Reset (GPIO_SFRmap* GPIOx);
void GPIO_Configuration (GPIO_SFRmap* GPIOx, GPIO_InitTypeDef* gpioInitStruct);
void GPIO_Struct_Init (GPIO_InitTypeDef* gpioInitStruct);
void GPIO_Pin_Lock_Config (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPin, FunctionalState NewState);
void GPIO_Pull_Up_Enable (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPin, FunctionalState NewState);
void GPIO_Toggle_Pull_Up_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin);
void GPIO_Pull_Down_Enable (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPin, FunctionalState NewState);
void GPIO_Toggle_Pull_Down_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin);
void GPIO_Open_Drain_Enable (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPin, GPIOPOD_TypeDef NewState);
void GPIO_Toggle_Open_Drain_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin);
void GPIO_Write_Mode_Bits (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPin, GPIOMode_TypeDef NewState);
void GPIO_Speed_Config (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPin, GPIOSpeed_TypeDef NewState);
void GPIO_Toggle_Speed_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin);

BitAction GPIO_Read_Input_Data_Bit (GPIO_SFRmap* GPIOx, uint16_t GpioPin);
uint16_t GPIO_Read_Input_Data (GPIO_SFRmap* GPIOx);
BitAction GPIO_Read_Output_Data_Bit (GPIO_SFRmap* GPIOx, uint16_t GpioPin);
uint16_t GPIO_Read_Output_Data (GPIO_SFRmap* GPIOx);
void GPIO_Set_Output_Data_Bits (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPin, BitAction BitsValue);
void GPIO_Toggle_Output_Data_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin);

void GPIO_Pin_RMP_Config (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPinNum, uint8_t PinRemap);
# 29 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_i2c.h" 1
# 30 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_i2c.h"
typedef struct
{
    uint32_t m_Mode;

    uint32_t m_ClockSource;

    uint32_t m_BADR10;

    uint32_t m_MasterSlave;

    uint16_t m_BaudRateL;

    uint16_t m_BaudRateH;

    FunctionalState m_AckEn;

    uint32_t m_AckData;

}I2C_InitTypeDef;
# 185 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_i2c.h"
void I2C_Reset (I2C_SFRmap* I2Cx);
void I2C_Configuration (I2C_SFRmap* I2Cx,I2C_InitTypeDef* i2cInitStruct);
void I2C_Struct_Init (I2C_InitTypeDef* I2C_InitStruct);

void I2C_Cmd(I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Bufr_Address_Config(I2C_SFRmap* I2Cx,uint32_t NewState);
void I2C_Generate_START(I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Generate_STOP(I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Ack_Config (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Ack_DATA_Config (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Call_Cmd (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Clock_Config (I2C_SFRmap* I2Cx,uint32_t ClkSource);
void I2C_MATCH_ADDRESS_Config (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_SCL_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_NMENA_Enable(I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_SMBUS_Enable(I2C_SFRmap* I2Cx,uint32_t NewState);
void I2C_SMBT_Config(I2C_SFRmap* I2Cx,uint32_t NewState);
void I2C_SMBus_ALERT_Config(I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_SendData (I2C_SFRmap* I2Cx,uint32_t Data);
uint32_t I2C_ReceiveData(I2C_SFRmap* I2Cx);
void I2C_ARP_Enable(I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_ADDR_Config(I2C_SFRmap* I2Cx, uint32_t AddrSelect, uint32_t Data);
void I2C_MSK_Config(I2C_SFRmap* I2Cx, uint32_t AddrSelect, uint32_t DataMask);
void I2C_BRGH_Config (I2C_SFRmap* I2Cx,uint16_t Period);
void I2C_BRGL_Config (I2C_SFRmap* I2Cx,uint16_t Period);

void I2C_Start_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Stop_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Ack_Fail_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Arbitration_Lost_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_SMBus_Alert_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_SMBus_HostHead_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_SMBus_Device_Defaultaddress_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_ISIE_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Receive_DMA_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
void I2C_Transmit_DMA_INT_Enable (I2C_SFRmap* I2Cx,FunctionalState NewState);
FlagStatus I2C_Get_Start_Flag (I2C_SFRmap* I2Cx);
void I2C_Clear_Start_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Stop_Flag (I2C_SFRmap* I2Cx);
void I2C_Clear_Stop_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Address_Match_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_HighAddress_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Data_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Ack_Fail_Flag (I2C_SFRmap* I2Cx);
void I2C_Clear_Ack_Fail_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Arbitration_Lost_Flag (I2C_SFRmap* I2Cx);
void I2C_Clear_Arbitration_Lost_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Write_Read_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_SMBus_Alert_Flag (I2C_SFRmap* I2Cx);
void I2C_Clear_SMBus_Alert_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_SMBus_Host_Header_Flag (I2C_SFRmap* I2Cx);
void I2C_Clear_SMBus_Host_Header_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_SMBus_Device_Default_Flag (I2C_SFRmap* I2Cx);
void I2C_Clear_SMBus_Device_Default_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_INTERRUPT_Flag (I2C_SFRmap* I2Cx);
void I2C_Clear_INTERRUPT_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Receive_Buff_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Transmit_Buff_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Receive_DMA_Flag (I2C_SFRmap* I2Cx);
FlagStatus I2C_Get_Transmit_DMA_Flag (I2C_SFRmap* I2Cx);
void I2C_SendData8 (I2C_SFRmap* I2Cx, uint8_t Data);
# 30 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_int.h" 1
# 24 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_int.h"
typedef struct
{
    uint32_t m_Line;

    FunctionalState m_Mask;

    FunctionalState m_Rise;

    FunctionalState m_Fall;

    uint32_t m_Source;

} EINT_InitTypeDef;
# 143 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_int.h"
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
# 31 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_iwdt.h" 1
# 52 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_iwdt.h"
void IWDT_Prescaler_Config (uint32_t Prescaler);
void IWDT_Overflow_Config (uint32_t Overflow);
void IWDT_Enable (uint32_t NewState);
void IWDT_Feed_The_Dog (void);
# 32 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_led.h" 1
# 20 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_led.h"
typedef struct
{
 FunctionalState m_Module_Enable;

 uint32_t m_Output_Control_Select;

 uint32_t m_Anodic_Cathodal_Sel;

 uint32_t m_Source_Clock_Sel;

 uint32_t m_Clock_Division;

 uint32_t m_Clock_PreDivision;


 FunctionalState m_Output_SEG12_15_Enable;

 FunctionalState m_Output_SEG8_11_Enable;

 FunctionalState m_Output_SEG0_7_Enable;

 uint32_t m_COM_Number_Select;

 uint32_t m_Lum_Select;






}LED_InitTypeDef;
# 33 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_lcd.h" 1
# 20 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_lcd.h"
typedef struct
{
    uint64_t m_SegPin;

    uint32_t m_SegPinEn;

    FunctionalState m_Analog;

    uint32_t m_ClockSource;


    uint32_t m_SourcePrescaler;

    uint32_t m_LCDPrescaler;

    uint32_t m_CommonPort;

    uint32_t m_VoltageSelect;

}LCD_InitTypeDef;
# 34 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_op.h" 1
# 195 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_op.h"
void OP_Reset(void);
void OP_CAL_Configure( uint32_t OPx , uint32_t CAL_VALUE);
void OP_GAIN_SELSECT(uint32_t OPx , uint32_t GAIN_VALUE);
void OP_OUTPUT_EN(uint32_t OPx,FunctionalState NewState);
void OP_MODULE_EN(uint32_t OPx,FunctionalState NewState);
void OP3_POSITIVE_INPUT_SELSECT(uint32_t SEL);
# 35 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_osc.h" 1
# 21 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_osc.h"
typedef struct
{
    uint32_t m_InputSource;


    uint32_t m_CLKDivision;


    uint32_t m_PLLInputSource;


    uint32_t m_StartDelay;

} OSC_InitTypeDef;
# 267 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_osc.h"
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
# 36 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
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
# 37 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_pm.h" 1
# 429 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_pm.h"
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
# 38 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_qei.h" 1
# 21 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_qei.h"
typedef struct
{
    FunctionalState m_IndexReset;

    FunctionalState m_DirectionEn;

    uint32_t m_WorkClock;

    FunctionalState m_DigitalFilterEn;

    uint32_t m_DigitalFilterPrescaler;

    FunctionalState m_SwapABEn;

    uint16_t m_Counter;

    uint16_t m_Period;

    uint16_t m_Prescaler;

}QEI_InitTypeDef;




typedef struct
{
    uint16_t m_Counter;

    uint16_t m_Period;

    uint16_t m_Prescaler;

    uint32_t m_CounterMode;

    uint32_t m_ClockSource;

}QEI_TimerTypeDef;
# 148 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_qei.h"
void QEI_Reset (QEI_SFRmap* QEIx);
void QEI_Configuration(QEI_SFRmap* QEIx, QEI_InitTypeDef* qeiInitStruct);
void QEI_Timer_Configuration(QEI_SFRmap* QEIx,
                    QEI_TimerTypeDef* qeiTimerInitStruct);
void QEI_Struct_Init (QEI_InitTypeDef* qeiInitStruct);
void QEI_Timer_Struct_Init (QEI_TimerTypeDef* qeiTimerInitStruct);

void QEI_Encoder_Mode_Config (QEI_SFRmap* QEIx, uint32_t PortMode);
void QEI_Location_Counter_Reset_Enable (QEI_SFRmap* QEIx,
                    FunctionalState NewState);
void QEI_Timer_Source_Clock_Config (QEI_SFRmap* QEIx, uint32_t TimerClock);
FlagStatus QEI_Get_Index_Pin_State (QEI_SFRmap* QEIx);
void QEI_Location_Counter_Output_Enable (QEI_SFRmap* QEIx,
                    FunctionalState NewState);
void QEI_Location_Counter_Direction_Config (QEI_SFRmap* QEIx,
                    uint32_t Direction);
FlagStatus QEI_Get_Location_Counter_Direction (QEI_SFRmap* QEIx);
void QEI_Source_Clock_Config (QEI_SFRmap* QEIx, uint32_t PeripheralClock);
void QEI_Digital_Filter_Output_Enable (QEI_SFRmap* QEIx,
                    FunctionalState NewState);
void QEI_Digital_Filter_Clock_Config (QEI_SFRmap* QEIx,
                    uint32_t PeripheralClock);
void QEI_Swap_Phase_AB_Enable (QEI_SFRmap* QEIx, FunctionalState NewState);
void QEI_Timer_Counter_Config (QEI_SFRmap* QEIx, uint16_t Counter);
uint16_t QEI_Get_Timer_Counter (QEI_SFRmap* QEIx);
void QEI_Timer_Period_Config (QEI_SFRmap* QEIx, uint16_t Period);
uint16_t QEI_Get_Timer_Period (QEI_SFRmap* QEIx);
void QEI_Timer_Prescaler_Config (QEI_SFRmap* QEIx, uint16_t Prescaler);

FlagStatus QEI_Get_INT_Flag (QEI_SFRmap* QEIx, uint32_t InterruptType);
void QEI_Clear_INT_Flag (QEI_SFRmap* QEIx, uint32_t InterruptType);
void QEI_Set_INT_Enable (QEI_SFRmap* QEIx,
                    uint32_t InterruptType, FunctionalState NewState);
FlagStatus QEI_Get_Counter_Overflow_INT_Flag (QEI_SFRmap* QEIx);
FlagStatus QEI_Get_Phase_Error_INT_Flag (QEI_SFRmap* QEIx);
FlagStatus QEI_Get_Count_Error_INT_Flag (QEI_SFRmap* QEIx);
void QEI_Clear_Timer_Overflow_INT_Flag (QEI_SFRmap* QEIx);
void QEI_Clear_Phase_Error_INT_Flag (QEI_SFRmap* QEIx);
void QEI_Clear_Counter_Error_INT_Flag (QEI_SFRmap* QEIx);
void QEI_Timer_Overflow_INT_Enable (QEI_SFRmap* QEIx,FunctionalState NewState);
void QEI_Phase_Error_INT_Enable (QEI_SFRmap* QEIx, FunctionalState NewState);
void QEI_Counter_Error_INT_Enable (QEI_SFRmap* QEIx, FunctionalState NewState);
# 39 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
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
# 40 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_rtc.h" 1
# 20 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_rtc.h"
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
# 290 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_rtc.h"
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
# 41 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_spi.h" 1
# 30 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_spi.h"
typedef struct
{
    uint32_t m_Mode;

    uint32_t m_Clock;

    uint32_t m_FirstBit;

    uint32_t m_CKP;

    uint32_t m_CKE;

    uint32_t m_DataSize;

    uint16_t m_BaudRate;

}SPI_InitTypeDef;




typedef struct
{
    uint32_t m_Mode;

    uint32_t m_Standard;

    uint32_t m_PCM;

    uint32_t m_Clock;

    uint32_t m_CKP;

    uint8_t m_Prescaler;

}I2S_InitTypeDef;
# 217 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_spi.h"
void SPI_Reset(SPI_SFRmap* SPIx);
void SPI_Configuration(SPI_SFRmap* SPIx, SPI_InitTypeDef* spiInitStruct);
void I2S_Configuration(SPI_SFRmap* SPIx, I2S_InitTypeDef* i2sInitStruct);
void SPI_Struct_Init(SPI_InitTypeDef* SPI_InitStruct);
void I2S_Struct_Init(I2S_InitTypeDef* I2S_InitStruct);

void SPI_Cmd (SPI_SFRmap* SPIx, FunctionalState NewState);
void I2S_Mode_Select(SPI_SFRmap* SPIx, FunctionalState NewState);
uint32_t SPI_I2S_ReceiveData(SPI_SFRmap* SPIx);
void SPI_I2S_SendData8(SPI_SFRmap* SPIx, uint8_t Data);
void SPI_I2S_SendData32(SPI_SFRmap* SPIx, uint32_t Data);
void SPI_BaudRate_Config (SPI_SFRmap* SPIx, uint16_t BAUDRATE);
void I2S_DIV_Config (SPI_SFRmap* SPIx, uint8_t DIV);
void SPI_MODE_Config (SPI_SFRmap* SPIx, uint32_t MODE);
void SPI_CLK_Config (SPI_SFRmap* SPIx, uint32_t ClockSource);
void SPI_Data_Direction_Config(SPI_SFRmap* SPIx, uint32_t DataDirection);
void SPI_Clock_Polarity_Config (SPI_SFRmap* SPIx, uint32_t Polarity);
void SPI_Clock_Edge_Config (SPI_SFRmap* SPIx, uint32_t ClockEdge);
void SPI_BIT_SELECT_Config(SPI_SFRmap* SPIx, uint32_t DataSize);
void SPI_I2S_MODE_Config (SPI_SFRmap* SPIx, uint32_t Mode);
void SPI_I2S_STANDARD_Config(SPI_SFRmap* SPIx, uint32_t Standard);
void SPI_PCM_Config (SPI_SFRmap* SPIx, uint32_t NewState);
void SPI_CHLEN_Config (SPI_SFRmap* SPIx, uint32_t NewState);
void SPI_PCM_CLOCK_Polarity_Config(SPI_SFRmap* SPIx, uint32_t NewState);
void SPI_MAIN_CLOCK_OUT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState);

void SPI_Receive_Overflow_INT_Enable (SPI_SFRmap* SPIx,
                    FunctionalState NewState);
void SPI_Transmit_Overflow_INT_Enable (SPI_SFRmap* SPIx,
                    FunctionalState NewState);
void SPI_RNEIE_INT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState);
void SPI_TNEIE_INT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState);
void SPI_Receive_DMA_INT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState);
void SPI_Transmit_DMA_INT_Enable (SPI_SFRmap* SPIx, FunctionalState NewState);
void SPI_Transmit_CHSIDE_INT_Enable (SPI_SFRmap* SPIx,
                    FunctionalState NewState);
FlagStatus SPI_Get_BUSY_Flag (SPI_SFRmap* SPIx);
FlagStatus SPI_Get_Receive_Overflow_Flag (SPI_SFRmap* SPIx);
FlagStatus SPI_Get_Transmit_Overflow_Flag (SPI_SFRmap* SPIx);
FlagStatus SPI_Get_Receive_Buf_Flag (SPI_SFRmap* SPIx);
FlagStatus SPI_Get_Transmit_Buf_Flag (SPI_SFRmap* SPIx);
void SPI_Clear_Receive_Overflow_INT_Flag (SPI_SFRmap* SPIx);
void SPI_Clear_Transmit_Overflow_INT_Flag (SPI_SFRmap* SPIx);
# 42 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_sysctl.h" 1
# 97 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_sysctl.h"
FlagStatus SYSCTL_Get_V_Flag (void);
FlagStatus SYSCTL_Get_C_Flag (void);
FlagStatus SYSCTL_Get_Z_Flag (void);
FlagStatus SYSCTL_Get_N_Flag (void);
void SYSCTL_Set_V_Flag (FunctionalState NewState);
void SYSCTL_Set_C_Flag (FunctionalState NewState);
void SYSCTL_Set_Z_Flag (FunctionalState NewState);
void SYSCTL_Set_N_Flag (FunctionalState NewState);
void SYSCTL_Sleep_On_Exit_Enable (FunctionalState NewState);
void SYSCTL_Deep_Sleep_Enable (FunctionalState NewState);
void SYSCTL_Interrupt_Awake_Enable (FunctionalState NewState);
FlagStatus SYSCTL_Stack_Align_State (void);
void SYSCTL_Super_User_Config (FunctionalState NewState);
FlagStatus SYSCTL_Stack_Pointer_State (void);
void SYSCTL_Stack_Pointer_Config (uint32_t PresentSP);
void SYSCTL_Exception_Reset_Enable (FunctionalState NewState);
void SYSCTL_System_Reset_Enable (FunctionalState NewState);
void SYSCTL_Vector_Offset_Config (uint32_t VectorOffset);
void SYSCTL_Ram_Space_Config (uint32_t RamSpace);
void SYSCTL_Flash_Start_Remap_Config (uint32_t MemCtl);
# 43 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_systick.h" 1
# 22 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_systick.h"
typedef struct
{
    uint32_t m_Period;
    uint32_t m_Clock;

    uint32_t m_SysTickINT;

} SYSTICK_InitTypeDef;
# 46 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_systick.h"
void SYSTICK_Configuration (uint32_t Clock, uint32_t SysTickINT,
                    uint32_t Reload);

void SYSTICK_Cmd (FunctionalState NewState);
void SYSTICK_Clock_Config (uint32_t SysClock);
void SYSTICK_Systick_INT_Enable (uint32_t SysClock);
FlagStatus SYSTICK_Get_Count_Zero_Flag (void);
void SYSTICK_Reload_Config (uint32_t Reload);
void SYSTICK_Counter_Updata (void);
uint32_t SYSTICK_Get_Reload (void);
uint32_t SYSTICK_Get_Counter (void);
# 44 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_tim.h" 1
# 169 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_tim.h"
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
# 284 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_tim.h"
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
# 360 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_tim.h"
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
# 596 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_tim.h"
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
# 1001 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_tim.h"
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
# 1161 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_tim.h"
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
# 45 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_usart.h" 1
# 36 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_usart.h"
typedef struct
{
    uint32_t m_Mode;

    uint32_t m_HalfDuplexClkSource;
    uint32_t m_TransferDir;
    uint32_t m_WordLength;
    uint32_t m_StopBits;
    uint32_t m_Bit9SEL;
    uint32_t m_Parity;
    uint32_t m_ReceiveOrder;
    uint32_t m_TransmitOrder;
    uint32_t m_BRAutoDetect;
    uint32_t m_HardwareFlowControl;
    uint16_t m_BaudRateBRCKS;
    uint16_t m_BaudRateInteger;
    uint16_t m_BaudRateNumerator;
    uint16_t m_BaudRateDenominator;
} USART_InitTypeDef;




typedef struct
{
    uint32_t m_ErrorSignal;

    uint32_t m_PassagewaySelect;

    uint32_t m_TransmitRepeat;

    uint32_t m_ReceiveRepeat;

    FunctionalState m_Clkout;

    uint8_t m_ClkDiv;

    uint8_t m_Egt;

} U7816R_InitTypeDef;
# 325 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_usart.h"
void USART_Reset (USART_SFRmap* USARTx);
void USART_Configuration (USART_SFRmap* USARTx,
                    USART_InitTypeDef* usartInitStruct);
void USART_U7816R_Configuration (USART_SFRmap* USARTx,
                    U7816R_InitTypeDef* usartInitStruct);
void USART_Struct_Init(USART_InitTypeDef* usartInitStruct);
void USART_U7816R_Struct_Init(U7816R_InitTypeDef* usartInitStruct);

void USART_Cmd (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_BaudRate_Clock_Config(USART_SFRmap* USARTx, uint32_t CLK);
void USART_HalfDuplex_ClockPolarity_Config(USART_SFRmap* USARTx,
                    uint32_t NewState);
void USART_Transmit_Order_Config (USART_SFRmap* USARTx, uint32_t NewState);
void USART_Receive_Order_Config (USART_SFRmap* USARTx, uint32_t NewState);
void USART_Infrare_Detector_Voltage_Config (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_WeakUP_Enable(USART_SFRmap* USARTx, FunctionalState NewState);
void USART_Clock_Source_Config(USART_SFRmap* USARTx, uint32_t ClockSource);
void USART_Address_Detection_Enable(USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_Auto_BaudRate_Detection_Enable(USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_Send_Blank_Enable(USART_SFRmap* USARTx, FunctionalState NewState);
void USART_SYN_Choice_Config(USART_SFRmap* USARTx, uint32_t NewMode);
void USART_Transmit_Data_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_Receive_Data_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_STOP_Word_Config(USART_SFRmap* USARTx, uint32_t NewLength);
void USART_Transmit_9Word_Select_Config (USART_SFRmap* USARTx,
                    uint32_t NewState);
void USART_Parity_Select_Config(USART_SFRmap* USARTx, uint32_t NewState);
void USART_9Data_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_CTS_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_RTS_Enable(USART_SFRmap* USARTx, FunctionalState NewState);
void USART_Infrare_Detector_Enable(USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_Singlet_Line_Mode_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_BaudRate_Integer_Config(USART_SFRmap* USARTx, uint16_t DIV);
void USART_BaudRate_Decimal1_Config(USART_SFRmap* USARTx, uint32_t DIV);
void USART_BaudRate_Decimal2_Config(USART_SFRmap* USARTx, uint32_t DIV);
void USART_SendData(USART_SFRmap* USARTx, uint8_t Data);
void USART_TransmitData(USART_SFRmap* USARTx, uint8_t Data);
uint32_t USART_ReceiveData(USART_SFRmap* USARTx);
void USART_Address_Match_Config(USART_SFRmap* USARTx, uint8_t DIV);
void USART_Send_Idle_Frame_Enable(USART_SFRmap* USARTx, FunctionalState NewState);
void USART_Receive_Idle_Frame_Config(USART_SFRmap* USARTx, FunctionalState NewState);


void USART_7816_Cmd(USART_SFRmap* USARTx, FunctionalState NewState);
void USART_7816_CLKOUT_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_7816_Error_Signal_Config (USART_SFRmap* USARTx,
                    uint32_t ERRORSIGNAL);
void USART_Passageway_Select_Config(USART_SFRmap* USARTx, uint32_t NewState);
void USART_BGT_Config(USART_SFRmap* USARTx, FunctionalState NewState);
void USART_Transmit_Repeat_Enable(USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_Receive_Repeat_Enable(USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_Transmit_Repeat_Times_Config(USART_SFRmap* USARTx, uint32_t SELECT);
void USART_Receive_Repeat_Times_Config(USART_SFRmap* USARTx, uint32_t SELECT);
void USART_7816_CLKDIV_Config (USART_SFRmap* USARTx, uint8_t DIV);
void USART_7816_EGT_Config(USART_SFRmap* USARTx, uint8_t EGT);
void USART_7816_Resend_Mode_Select(USART_SFRmap* USARTx, FunctionalState NewState);


void USART_Receive_Overflow_INT_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_Parity_ERROR_INT_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_Frame_ERROE_INT_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_Blank_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_Auto_BaudRate_TimeOver_INT_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_WeakUP_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_Transmit_ERROR_INT_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_Receive_ERROR_INT_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_CTS_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_RDR_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_TFE_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_TXE_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
void USART_Receive_DMA_INT_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_Transmit_DMA_INT_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState);
void USART_IDLE_INT_Enable(USART_SFRmap* USARTx, FunctionalState NewState);
void USART_UADM_INT_Enable(USART_SFRmap* USARTx, FunctionalState NewState);
FlagStatus USART_Get_Receive_Overflow_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Parity_ERROR_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Frame_ERROR_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Blank_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Auto_Baudrate_TimeOver_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_WeakUP_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_7816Transmit_ERROR_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_7816Receive_ERROR_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_CTS_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Receive_BUFR_Ready_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Transmit_BUFR_Empty_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Transmitter_Empty_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Receive_Frame_Idel_Flag(USART_SFRmap* USARTx);
void USART_Clear_Receive_Overflow_INT_Flag (USART_SFRmap* USARTx);
void USART_Clear_Parity_ERROR_INT_Flag (USART_SFRmap* USARTx);
void USART_Clear_Frame_ERROR_INT_Flag (USART_SFRmap* USARTx);
void USART_Clear_Blank_INT_Flag (USART_SFRmap* USARTx);
void USART_Clear_Auto_BaudRate_TimeOver_INT_Flag (USART_SFRmap* USARTx);
void USART_Clear_WeakUP_INT_Flag (USART_SFRmap* USARTx);
void USART_Clear_Transmit_ERROR_INT_Flag (USART_SFRmap* USARTx);
void USART_Clear_Receive_ERROR_INT_Flag (USART_SFRmap* USARTx);
void USART_Clear_CTS_INT_Flag (USART_SFRmap* USARTx);
void USART_Clear_UADM_INT_Flag (USART_SFRmap* USARTx);
void USART_Clear_IDLE_INT_Flag (USART_SFRmap* USARTx);
void USART_Clear_Receive_BUFR_INT_Flag (USART_SFRmap* USARTx);
void USART_Clear_Transmit_BUFR_INT_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_WUEN_Flag (USART_SFRmap* USARTx);
FlagStatus USART_Get_Auto_BaudRate_Detection_Flag(USART_SFRmap* USARTx);
void USART_RESHD_Enable (USART_SFRmap* USARTx, FunctionalState NewState);
# 46 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_usb.h" 1
# 20 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_usb.h"
typedef struct
{
    uint32_t m_Speed;

    FunctionalState m_Pullup;

    uint32_t m_DoubleBufferCfg;

    FunctionalState m_DoubleBufferRst;

    uint32_t m_EndPointMask;

    FunctionalState m_Handshake;

    FunctionalState m_Bidirectional;

    FunctionalState m_Output;

    FunctionalState m_Input;

}USB_InitTypeDef;




typedef struct
{
    uint16_t m_EndPoint;

    uint16_t m_Direction;

    uint16_t m_BDPointer;

    uint16_t m_BufferAddr;

    uint32_t m_ByteCount;

    uint32_t m_Own;

    uint32_t m_DataToggleSync;

    FunctionalState m_DataToggleSyncEn;

    FunctionalState m_BufferStall;

}USB_BufferTypeDef;




typedef struct
{
    uint8_t m_EndPoint;

    uint8_t m_BDDirection;

    uint8_t m_BDPointer;

}USB_StateTypeDef;
# 47 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_wwdt.h" 1
# 66 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/inc/kf32a_basic_wwdt.h"
void WWDT_Reset (void);
void WWDT_Threshold_Config (uint32_t Threshold);
void WWDT_Prescaler_Config (uint32_t Prescaler);
void WWDT_Enable (uint32_t NewState);
void WWDT_Counter_Config (uint32_t Counter);
uint32_t WWDT_Get_Counter (void);

void WWDT_INT_Enable (uint32_t NewState);
FlagStatus WWDT_Get_INT_Flag (void);
void WWDT_Clear_INT_Flag (void);
# 48 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2


# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/typedef.h" 1
# 11 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/typedef.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef int s16;

typedef struct
{
 unsigned char b0:1;
 unsigned char b1:1;
 unsigned char b2:1;
 unsigned char b3:1;
 unsigned char b4:1;
 unsigned char b5:1;
 unsigned char b6:1;
 unsigned char b7:1;
} BYTE_FIELD;

typedef struct
{
 unsigned char bits0:2;
 unsigned char bits1:2;
 unsigned char bits2:2;
 unsigned char bits3:2;
} Bits_FIELD;


typedef union
{
 unsigned char byte;
 BYTE_FIELD bit;
 Bits_FIELD bits;
} TYPE_BYTE;




typedef struct
{
 unsigned short b0:1;
 unsigned short b1:1;
 unsigned short b2:1;
 unsigned short b3:1;
 unsigned short b4:1;
 unsigned short b5:1;
 unsigned short b6:1;
 unsigned short b7:1;
 unsigned short b8:1;
 unsigned short b9:1;
 unsigned short b10:1;
 unsigned short b11:1;
 unsigned short b12:1;
 unsigned short b13:1;
 unsigned short b14:1;
 unsigned short b15:1;
} WORD_FIELD;

typedef union
{
 unsigned short word;
 unsigned char byte[2];
 WORD_FIELD bit;
} TYPE_WORD;

typedef struct
{
 unsigned int b31:1;
 unsigned int b30:1;
 unsigned int b29:1;
 unsigned int b28:1;
 unsigned int b27:1;
 unsigned int b26:1;
 unsigned int b25:1;
 unsigned int b24:1;
 unsigned int b23:1;
 unsigned int b22:1;
 unsigned int b21:1;
 unsigned int b20:1;
 unsigned int b19:1;
 unsigned int b18:1;
 unsigned int b17:1;
 unsigned int b16:1;
 unsigned int b15:1;
 unsigned int b14:1;
 unsigned int b13:1;
 unsigned int b12:1;
 unsigned int b11:1;
 unsigned int b10:1;
 unsigned int b9:1;
 unsigned int b8:1;
 unsigned int b7:1;
 unsigned int b6:1;
 unsigned int b5:1;
 unsigned int b4:1;
 unsigned int b3:1;
 unsigned int b2:1;
 unsigned int b1:1;
 unsigned int b0:1;
} DWORD_FIELD;

typedef struct
{
 unsigned short b0:2;
 unsigned short b1:2;
 unsigned short b2:2;
 unsigned short b3:2;
 unsigned short b4:2;
 unsigned short b5:2;
 unsigned short b6:2;
 unsigned short b7:2;
 unsigned short b8:2;
 unsigned short b9:2;
 unsigned short b10:2;
 unsigned short b11:2;
 unsigned short b12:2;
 unsigned short b13:2;
 unsigned short b14:2;
 unsigned short b15:2;
} DWORD_FIELD_2bit;


typedef union
{
 unsigned int dword;
 unsigned char byte[4];
 DWORD_FIELD bit;
 DWORD_FIELD_2bit BIT;
} TYPE_DWORD;



typedef struct
{
 unsigned long long b63:1;
 unsigned long long b62:1;
 unsigned long long b61:1;
 unsigned long long b60:1;
 unsigned long long b59:1;
 unsigned long long b58:1;
 unsigned long long b57:1;
 unsigned long long b56:1;
 unsigned long long b55:1;
 unsigned long long b54:1;
 unsigned long long b53:1;
 unsigned long long b52:1;
 unsigned long long b51:1;
 unsigned long long b50:1;
 unsigned long long b49:1;
 unsigned long long b48:1;
 unsigned long long b47:1;
 unsigned long long b46:1;
 unsigned long long b45:1;
 unsigned long long b44:1;
 unsigned long long b43:1;
 unsigned long long b42:1;
 unsigned long long b41:1;
 unsigned long long b40:1;
 unsigned long long b39:1;
 unsigned long long b38:1;
 unsigned long long b37:1;
 unsigned long long b36:1;
 unsigned long long b35:1;
 unsigned long long b34:1;
 unsigned long long b33:1;
 unsigned long long b32:1;
 unsigned long long b31:1;
 unsigned long long b30:1;
 unsigned long long b29:1;
 unsigned long long b28:1;
 unsigned long long b27:1;
 unsigned long long b26:1;
 unsigned long long b25:1;
 unsigned long long b24:1;
 unsigned long long b23:1;
 unsigned long long b22:1;
 unsigned long long b21:1;
 unsigned long long b20:1;
 unsigned long long b19:1;
 unsigned long long b18:1;
 unsigned long long b17:1;
 unsigned long long b16:1;
 unsigned long long b15:1;
 unsigned long long b14:1;
 unsigned long long b13:1;
 unsigned long long b12:1;
 unsigned long long b11:1;
 unsigned long long b10:1;
 unsigned long long b9:1;
 unsigned long long b8:1;
 unsigned long long b7:1;
 unsigned long long b6:1;
 unsigned long long b5:1;
 unsigned long long b4:1;
 unsigned long long b3:1;
 unsigned long long b2:1;
 unsigned long long b1:1;
 unsigned long long b0:1;
} QWORD_FIELD;

typedef union
{
 unsigned long long qword;
 TYPE_BYTE byte[8];
 QWORD_FIELD bit;
} TYPE_QWORD;


typedef struct
{
 unsigned long long b0:1;
 unsigned long long b1:1;
 unsigned long long b2:1;
 unsigned long long b3:1;
 unsigned long long b4:1;
 unsigned long long b5:1;
 unsigned long long b6:1;
 unsigned long long b7:1;
 unsigned long long b8:1;
 unsigned long long b9:1;
 unsigned long long b10:1;
 unsigned long long b11:1;
 unsigned long long b12:1;
 unsigned long long b13:1;
 unsigned long long b14:1;
 unsigned long long b15:1;
 unsigned long long b16:1;
 unsigned long long b17:1;
 unsigned long long b18:1;
 unsigned long long b19:1;
 unsigned long long b20:1;
 unsigned long long b21:1;
 unsigned long long b22:1;
 unsigned long long b23:1;
 unsigned long long b24:1;
 unsigned long long b25:1;
 unsigned long long b26:1;
 unsigned long long b27:1;
 unsigned long long b28:1;
 unsigned long long b29:1;
 unsigned long long b30:1;
 unsigned long long b31:1;
 unsigned long long b32:1;
 unsigned long long b33:1;
 unsigned long long b34:1;
 unsigned long long b35:1;
 unsigned long long b36:1;
 unsigned long long b37:1;
 unsigned long long b38:1;
 unsigned long long b39:1;
 unsigned long long b40:1;
 unsigned long long b41:1;
 unsigned long long b42:1;
 unsigned long long b43:1;
 unsigned long long b44:1;
 unsigned long long b45:1;
 unsigned long long b46:1;
 unsigned long long b47:1;
 unsigned long long b48:1;
 unsigned long long b49:1;
 unsigned long long b50:1;
 unsigned long long b51:1;
 unsigned long long b52:1;
 unsigned long long b53:1;
 unsigned long long b54:1;
 unsigned long long b55:1;
 unsigned long long b56:1;
 unsigned long long b57:1;
 unsigned long long b58:1;
 unsigned long long b59:1;
 unsigned long long b60:1;
 unsigned long long b61:1;
 unsigned long long b62:1;
 unsigned long long b63:1;

} QQWORD_FIELD;

typedef union
{
 unsigned long long qword;
 unsigned char byte[8];
 QQWORD_FIELD bit;
} TYPE_QQWORD;


typedef struct
{
   uint16_t MeterA2;
   uint16_t MeterA3;
   uint16_t MeterA4;
   uint16_t MeterA13;
   uint16_t MeterA14;
   uint16_t MeterA15;
   uint16_t MeterA5;
}Meter;



typedef struct
{
    uint8_t secs;
    uint8_t mins;
    uint8_t hours;
    uint8_t day;
    uint8_t month;
    uint8_t year;
    uint8_t week;
}rtc_t;
# 51 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2

# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/config.h" 1
# 341 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/config.h"
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Artpatch.h" 1
# 29 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Artpatch.h"
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
# 73 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Artpatch.h"
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
# 342 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/config.h" 2
# 53 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/MeterConfig.h" 1
# 139 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/MeterConfig.h"
extern TYPE_BYTE led[8];
# 458 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/MeterConfig.h"
extern volatile uint8_t pcan_off_line;
extern volatile uint8_t fbcm_off_line;
extern volatile uint8_t rbcm_off_line;
extern volatile uint8_t tbcm_off_line;

extern TYPE_QQWORD tip_code1,tip_code2,tip_code3,tip_code4;
# 745 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/MeterConfig.h"
extern volatile TYPE_WORD bcm_sw1_f;
extern volatile TYPE_BYTE bcm_sw2_f;
extern volatile uint16_t bcm_frq_f;
extern volatile uint16_t bcm_senor1_f;
extern volatile uint16_t bcm_senor2_f;
extern volatile TYPE_WORD bcm_out_st_f;
extern volatile TYPE_DWORD bcm_fb_st_f;

extern volatile TYPE_WORD bcm_sw1_r;
extern volatile TYPE_BYTE bcm_sw2_r;
extern volatile uint16_t bcm_frq_r;
extern volatile uint16_t bcm_senor1_r;
extern volatile uint16_t bcm_senor2_r;
extern volatile TYPE_WORD bcm_out_st_r;
extern volatile TYPE_DWORD bcm_fb_st_r;

extern volatile TYPE_WORD bcm_sw1_t;
extern volatile TYPE_BYTE bcm_sw2_t;
extern volatile uint16_t bcm_frq_t;
extern volatile uint16_t bcm_senor1_t;
extern volatile uint16_t bcm_senor2_t;
extern volatile TYPE_WORD bcm_out_st_t;
extern volatile TYPE_DWORD bcm_fb_st_t;
extern TYPE_BYTE ctrl_cmd[8];

extern TYPE_WORD F_Set_PWM,R_Set_PWM,T_Set_PWM;




typedef struct
{
 unsigned char bs0:2;
 unsigned char bs1:2;
 unsigned char bs2:2;
 unsigned char bs3:2;
} BYTE_2BITFIELD;


typedef union
{
 unsigned char byte;
 BYTE_FIELD bit;
 BYTE_2BITFIELD bit2;
} TYPE_8BIT;


typedef union
{
 unsigned int U32;
 unsigned int U16[2];
 TYPE_8BIT U8[4];
 DWORD_FIELD bit;
 DWORD_FIELD_2bit bit2;
} TYPE_32BIT;

extern TYPE_32BIT fmode_mask,rmode_mask,tmode_mask;
# 873 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/MeterConfig.h"
void CopyReceData(uint8_t *Des,volatile uint8_t *Souc,uint8_t n);

void power_task(void);


void PortInit(void);
void MeterAndBCMPortInit(void);
void Send_PWM_Bcm(void);

void RainConfig(void);
# 54 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/system.h" 1
# 11 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/system.h"
extern uint8_t BCanSendDisable;
extern volatile uint8_t BcanDelay,Pcan1Delay,Pcan2Delay,Pcan3Delay,DcanDelay,speed_life;
extern uint8_t tmp_buff[7];
extern rtc_t rtc;
extern volatile uint32_t SysTickPer1ms;
extern volatile uint32_t A5Count,A15Count;
extern u8 initflag;

extern uint16_t Vbat;
extern volatile uint16_t eng_speed;
extern volatile uint16_t veh_speed;
extern volatile uint16_t veh_speed_display;
extern uint16_t veh_bar1;
extern uint16_t veh_bar2;
extern volatile uint16_t veh_soc;
extern uint16_t speed_count;

extern uint32_t Veh_odo,Pre_odo,Set_Veh_odo;
extern uint16_t Veh_trip;

extern uint8_t Temp_Vbat;
extern uint8_t fuel_percent;





extern volatile uint8_t FrontCurrent[16];



extern volatile uint8_t RearCurrent[16];



extern volatile uint8_t TopCurrent[16];




enum
{
    BYTE1 = 0,
    BYTE2,
    BYTE3,
    BYTE4,
    BYTE5,
    BYTE6,
    BYTE7,
    BYTE8
};


typedef struct{
 unsigned char luntai[6];
 unsigned int yali[6];
 unsigned int wendu[6];
 unsigned char fault_status[6];
 unsigned char error[6];
 unsigned char fangbaotai[2];
 unsigned int life;
}TAIYA;
extern volatile TAIYA taiya;
# 115 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/system.h"
extern TYPE_QWORD Art,CanSend_Flag;
# 190 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/system.h"
extern u32 All_Spn[10];
extern u8 All_Fmi[10];
extern u8 All_Oc[10];

extern volatile uint8_t pengzhang_shuixiang;
# 242 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/system.h"
void Sendspeed(void);
void calulate_speed(void);
void Acquisition_Task (void);
void SystemLogic(void);
u8 JudgeMAInBuff(volatile u8 *p,volatile u8 data);
void singleMile(void);
void BuzzLogic(void);
# 55 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/sch.h" 1
# 17 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/sch.h"
typedef struct
{

   void (* pTask)(void);


   uint16_t Delay;


   uint16_t Period;


   uint8_t RunMe;

   } sTask;



extern void sch_dispatch_tasks(void);
extern uint8_t sch_add_task(void (*) (void), const uint16_t, const uint16_t);
extern uint8_t sch_delete_task(const uint8_t);
extern void SCH_Report_Status(void);
extern void sch_init(void);
extern void sch_update(void);
# 56 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/gpio.h" 1
# 18 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/gpio.h"
void GPIOInit_Output_Config(GPIO_SFRmap* GPIOx,uint16_t GpioPin);
void GPIOInit_Input_Config(GPIO_SFRmap* GPIOx,uint16_t GpioPin);
void GPIOInit_PullOd_Config(GPIO_SFRmap* GPIOx,uint16_t GpioPin,GPIOMode_TypeDef Mode,GPIOPU_TypeDef pull,GPIOPOD_TypeDef state);
# 57 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/timer.h" 1
# 17 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/timer.h"
void TimerInit(void);
# 58 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/canreceive.h" 1
# 16 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/canreceive.h"
u16 GetU16From2U8(u8 data_h,u8 data_l,u8 sort);

extern volatile uint8_t CanData[][8];
extern uint8_t timeout[];
void CopyData(volatile uint8_t *Des,volatile uint8_t *Souc,uint8_t n);

void ClearCanDataManage(void);



void ClearData(volatile u8* data,u8 ns);
uint16_t Pcan1GetIndexFromID(uint32_t id);




u32 GetID(CAN_MessageTypeDef CAN_MessageStructrue);

void GeCantData(CAN_MessageTypeDef CAN_MessageStructrue,volatile u8 *data);

void Can2_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);
u32 Pcan1GetIDFromIndex(u16 index);
# 59 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Bcan.h" 1
# 17 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Bcan.h"
typedef enum
{

    CAN_BAUDRATE_125K = 1,
    CAN_BAUDRATE_250K = 2,
    CAN_BAUDRATE_500K = 3
} CAN_BaudRateT;


typedef enum
{
    CAN_ERROR_NOERROR = 0,
    CAN_ERROR_BUFFERFULL=1,
    CAN_WAIT_SEND
} CAN_ErrorT;






void xInit_CAN(CAN_SFRmap* CANx,uint8_t Bdrt,uint32_t MODE);
void BcanInit(void);

uint32_t BCan_Standard_Tx_Bytes( uint16_t id,uint8_t * buffer,uint8_t len);

uint32_t BCan_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);


CAN_ErrorT CAN_Transmit_DATA(CAN_SFRmap* CANx,
      uint32_t TargetID,
      uint8_t* data ,
      uint8_t lenth,
      uint32_t MsgType,
      uint32_t RmtFrm
      );

void InitBCanSend(void);


void BCanSendTo(void);

volatile extern uint8_t BCanData[][8];
void Can0_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);
# 60 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Pcan1.h" 1
# 16 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Pcan1.h"
void Pcan1Inint(void);
void InitPCan1Send(void);

uint32_t PCan1_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);
uint32_t PCan1_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len);

void PCan1SendTo(void);




void Can2_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);
# 61 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Pcan2.h" 1
# 15 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Pcan2.h"
void Pcan2Inint(void);
void InitPCan2Send(void);

uint32_t PCan2_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);
uint32_t PCan2_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len);

void PCan2SendTo(void);


void Can3_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);
# 62 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Pcan3.h" 1
# 15 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Pcan3.h"
void Pcan3Inint(void);
void InitPCan3Send(void);

uint32_t PCan3_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);
uint32_t PCan3_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len);

void PCan3SendTo(void);


void Can4_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);
# 63 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Dcan.h" 1
# 11 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Dcan.h"
extern volatile uint8_t PCanData[][8];



void DcanInint(void);
void InitDCanSend(void);

uint32_t DCan_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);
uint32_t DCan_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len);



void DCanSendTo(void);


void Can1_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);
# 64 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/switch.h" 1
# 22 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/switch.h"
extern TYPE_WORD port_a;
extern TYPE_WORD port_c;
extern TYPE_WORD port_d;
extern TYPE_WORD port_b;
# 88 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/switch.h"
extern TYPE_QWORD port_mask;
extern TYPE_BYTE sw_input[6];

void HC165PortInit(void);
void switch_task(void);
# 65 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/led.h" 1
# 11 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/led.h"
extern TYPE_WORD ledlogic;

void Ledinit(void);
# 27 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/led.h"
void led_out(void);
# 66 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/key.h" 1
# 16 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/key.h"
typedef enum _KEY_EVENT
{
 IN_KEY_NONE = 0x00,
 IN_KEY1_SP,
 IN_KEY1_CP,
 IN_KEY2_SP,
 IN_KEY2_CP,
 IN_KEY3_SP,
 IN_KEY3_CP,
 IN_KEY4_SP,
 IN_KEY4_CP,
 IN_KEY5_SP,
 IN_KEY5_CP,
 IN_KEY6_SP,
 IN_KEY6_CP,
 IN_KEY1_RP,
 IN_KEY2_RP,
 IN_KEY3_RP,
 IN_KEY4_RP,

}KEY_EVENT;

typedef enum _KEY_STATE
{
 KEY_STATE_IDLE,
 KEY_STATE_JITTER,
 KEY_STATE_PRESS_DOWN,
 KEY_STATE_PR
} KEY_STATE;





void KeyIoInit(void);

void key_task(void);
# 67 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Output.h" 1
# 14 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Output.h"
extern TYPE_BYTE output_s;
extern uint8_t feed_buff[];
extern uint16_t adc_100ma_fd[5];
# 48 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Output.h"
enum
{
 E3,
 E8
};
enum
{
  E6,
  E7
};




typedef union {
 uint8_t byte;
 struct
 {
  uint8_t bit4 : 2;
  uint8_t bit3 : 2;
  uint8_t bit2 : 2;
  uint8_t bit1 : 2;
 }bits;
}SW_DIAGNOSE_PW;


typedef struct {
 uint8_t shorted :1;
 uint8_t delay :6;
 uint8_t handled :1;
 uint8_t short_thr;
}OP_Protect_PW;

extern OP_Protect_PW op_protection[];
extern SW_DIAGNOSE_PW sw_diagnose[];

void OutPowerInit(void);
void feedback_diag(void);
void set_output(void);
# 68 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Adc.h" 1
# 13 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Adc.h"
enum
{
   metera2 = 0,
   metera3 = 1,
   metera4 = 2,
   metera13 = 3,
   metera14 = 4,
   metervbat = 5,
   meterE3E8,
   meterE6E7,


   meterA16
};

extern Meter meter;

typedef union Adc_value_name
{
 unsigned short buf_16;
 unsigned char buf_8[2];
}Adc_value;


void Init_adc(void);
void AdcInit(void);
void ReadAdcResult(void);
# 69 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2

# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/flash.h" 1
# 28 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/flash.h"
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 1
# 29 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/flash.h" 2
# 39 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/flash.h"
void FLASH_HALFPAGE_WRITECODE_fun(uint32_t address,uint32_t *p_FlashBuffer,uint32_t length);
void FLASH_PageWrite_fun(uint32_t address,uint32_t *p_FlashBuffer,uint8_t length);
void FLASH_WriteCODE_ONE(uint32_t address,uint32_t *p_FlashBuffer);
void FLASH_READCODE_fun(uint32_t address,uint32_t *p_FlashBuffer,uint32_t length);


void FLASH_WriteCFG_ONE(uint32_t address,uint32_t *p_FlashBuffer);
void FLASH_HALFPAGE_WRITECFG_fun(uint32_t address,uint32_t *p_FlashBuffer,uint32_t length);
void FLASH_PageWrite_CFG_fun(uint32_t address,uint32_t *p_FlashBuffer,uint8_t length);



void FLASH_WriteByte(uint32_t address,uint8_t p_FlashBuffer);
void FLASH_WriteHalfWord(uint32_t address,uint16_t p_FlashBuffer);
void FLASH_WriteWord(uint32_t address,uint64_t p_FlashBuffer);
void FLASH_WriteNByte(uint32_t address,uint8_t *p_FlashBuffer,uint32_t leng);

uint32_t FLASH_ReadByte(uint32_t address,uint8_t *p_FlashBuffer);
uint32_t FLASH_ReadHalWord(uint32_t address,uint16_t *p_FlashBuffer);
uint32_t FLASH_ReadWord(uint32_t address,uint32_t *p_FlashBuffer);
void FLASH_ReadNByte(uint32_t address,uint8_t *p_FlashBuffer,uint32_t leng);


uint64_t FLASH_ReadDWord(uint32_t address,uint64_t *p_FlashBuffer);
# 71 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/eeprom.h" 1
# 32 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/eeprom.h"
typedef union
{
    BYTE_FIELD databit1[32];
    uint8_t data8[32];
    uint16_t data16[16];
    uint32_t data32[8];
 uint64_t data64[4];
    struct
    {
        BYTE_FIELD Switch;
        uint8_t backlight;

        uint16_t pulse;

        uint16_t subi;
        uint16_t trip;

  uint8_t coef;

  uint8_t speed_alarm;
        uint8_t air_alarm;
  uint8_t oil_alarm;
     uint8_t ranyou_alarm;
     uint8_t air_coef;
     uint8_t air2_coef;
     BYTE_FIELD video;
     uint8_t fuel_coef;
  uint8_t rain_time;


  uint8_t resv[9];
        uint8_t checksum;
    } Data;
} EEPROMDataStru;

extern EEPROMDataStru MeterPara;
# 78 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/eeprom.h"
uint32_t ReadAdd(uint32_t address);

uint32_t WriteDlong(uint32_t address,uint32_t data1,uint32_t data2);

extern uint8_t Air_Alarm,Speed_Alarm,Oil_Alarm,Ranyou_Alarm,Air_Coef,Air2_Coef,Coef;
extern uint8_t Rain_Delay_Time,Fuel_Coef;
extern uint8_t backlight_level,Bus_Type;
extern uint16_t odometer_const,odometer_const_2012,Pulse;

extern uint8_t Set_Air_Alarm,Set_Speed_Alarm,Set_Oil_Alarm,Set_Ranyou_Alarm,Set_Air_Coef,Set_Air2_Coef,Set_Coef;
extern uint8_t Set_Rain_Delay_Time,Set_Fuel_Coef;
extern uint8_t Set_backlight_level,Set_Bus_Type;
extern uint16_t Set_odometer_const,Set_odometer_const_2012,Set_Pulse;
extern uint8_t Set_buzz,Coef_2012;





uint32_t ReadVehodo(void);

uint32_t SaveVehodo(void);

void EraseMile(void);


uint32_t ReadMeterPara(void);
uint32_t SaveMeterPara(void);




uint32_t ReadBlockPara(uint32_t addr);

uint32_t WriteDlong(uint32_t address,uint32_t data1,uint32_t data2);


void SaveODO(void);



void FLASH_PageWrite_fun(uint32_t address,uint32_t *p_FlashBuffer,uint8_t length);

void FLASH_READCODE_fun(uint32_t address,uint32_t *p_FlashBuffer,uint32_t length);
# 72 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2

# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/displayhelper.h" 1
# 18 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/displayhelper.h"
typedef struct
{
 u32(*operate)(u8 key, u8 initpw);
 uint16_t id;
 uint16_t rever;
} DisMenuStruct;
# 33 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/displayhelper.h"
typedef void (*SendPackFunc)(u8 initpw);
# 173 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/displayhelper.h"
enum{
 TV1,
 TV2,
 TV3,
 TV4,
 TVNo,
};

enum
{
  Meter_B50 = 0x00,
  front_in,
  front_out,
  rear_in,
  rear_out,

  top_in,

  top_out
};





extern u8 ClearBufferDisable;



extern void ChangeToSubPageCache(uint8_t menu, uint8_t subpage);
void ChangeToSubPage(uint8_t menu, uint8_t subpage);
void Constant_display_Task();



extern void ChangeToPage(u8 m);
extern void AddMenu(u32 (*operate)(u8 key, u8 initpw),u32 id);

extern void clr_trip(void);
extern void display_task();
void SendKeyToGPU(u8 key);

extern void u32tostr(u32 dataxxx,u8 * out,u8 optionx,u8 CharNum);

extern void roll_alarm_Task(void);

extern void SetHightLightSymbl();
extern uint16_t GetWenziWarnCode(uint16_t count);

void InitDisplayHelper(void);
# 74 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/display.h" 1
# 38 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/display.h"
enum
{
 DIS_MAIN_MENU = 0X00,
    DIS_ART_INFORMATION,
    DIS_VCU_MENU,
    DIS_MCU_MENU,
    DIS_BMS_MENU,
    DIS_BATCELL_MENU,
    DIS_FUZU_MENU,
    DIS_PARAM_MENU,
    DIS_TMS_MENU,
    DIS_MIEHUO_MENU,

    DIS_AP_MENU,

    DIS_RUNHUA_MENU,
    DIS_TAIYA_MENU,
    DIS_FACTORY_SET_MENU,
    DIS_SYSTEM_SET_MENU,
    DIS_USED_END,
    DIS_VEDIO,
    DIS_MAIN,
    DIS_HELP_MENU = 0x80,

    DIS_CHOOSE_MENU

};

enum{
 MODE_ACC,
 MODE_NORMAL,
 MODE_OTHER
};

enum{
  SET_KEY = 0x80,
  SET_MODE,
  SET_JMP_PAGE
};

enum
{
 PassWordPage = 1,
 NoEncryptSetPage,
 EncryptSetPage
};


enum{
 PAGE_METER,

 PAGE_FMODE,


 PAGE_RMODE,


 PAGE_TMODE


};

enum{
 PAGE_ARTSET_PASSWORD,
 PAGE_ARTSET_MILESET
};

enum {
 CMD_DEC_MENU = 1,
 CMD_INC_MENU,
 CMD_DIS_MENU,
 CMD_DIS_PAGE,
 CMD_DIS_MAIN,
 CMD_JMP_PAGE
};


enum
{
 PAGE_MAIN = 0x01,
 PAGE_MENU,
 PAGE_ARTAV,


 PAGE_0X20 = 0x20,
 PAGE_0X21,
 PAGE_0X22,
 PAGE_0X23,
 PAGE_0X24,
 PAGE_0X25,
 PAGE_0X26,
 PAGE_0X27,
 PAGE_0X28,
 PAGE_0X29,
 PAGE_0X2A,
 PAGE_0X2B,
 PAGE_0X2C,
 PAGE_0X2D,
 PAGE_0X2E,
 PAGE_0X2F,
 PAGE_0X30,
 PAGE_0X31,
 PAGE_0X32,
 PAGE_0X33,
 PAGE_0X34,
 PAGE_0X35,
};

enum
{
    MAIN,
    CHARGE,
    MAINMax,
};


enum
{
  METER,
  FRONTMODULE,
  REARMODULE
};

enum
{
  FAULT0,
  FAULT1,
  FAULT2,
  FAULT3
};

enum
{
  BC0,
  BC1
};

enum BusType
{
  PUBLIC,
  TOURING
};


void SendPAGE_MAIN04(u8 initpw);
void SendPAGE_MAIN05(u8 initpw);
void SendPAGE_MAIN06(u8 initpw);



extern volatile u8 ReInitDisplayFlag;
extern uint8_t dis_mod;
extern volatile u8 avtest;
extern volatile u8 DCanSendDisablel;
extern u8 Send_To_DP_Data[12];



extern volatile u8 DCDC1[8],DriverOperateStatus,OnOffStatus;
extern volatile u8 _0C04A1A7_DATA[8],_0C06A1A7_DATA[8],_0C09A1A7_DATA[8],_181AD0F3_DATA[8],_181BD0F3_DATA[8];
extern volatile u8 _181CD0F3_DATA[8],_181DD0F3_DATA[8],_181ED0F3_DATA[8];
extern volatile u8 _0C0CA7F2_DATA[8],_0C0AA7F0_DATA[8],_0C08A7F4_DATA[8],_180AA7A3_DATA[8];
extern volatile u8 _180BA7A3_DATA[8],_180CA7A3_DATA[8],_0C01A70A_DATA[8],_0C02A70A_DATA[8],_0C03A70A_DATA[8];
extern volatile u8 _0C04A70A_DATA[8],_1818D0F3_DATA[8],_1819D0F3_DATA[8],_18EFA1A5_DATA[8];
extern volatile u8 _180028F3_DATA[8],_180128F3_DATA[8],_180228F3_DATA[8],_180328F3_DATA[8],_180428F3_DATA[8];
extern volatile u8 _180528F3_DATA[8],_180028F4_DATA[8],_180128F4_DATA[8];
extern volatile u8 _180228F4_DATA[8],_180328F4_DATA[8],_0CFFF3A7_DATA[8],_0CFEEC21_DATA[8];
extern volatile u8 EngineWaterTemp,EngineLoad,EngineTatgetAccelerator,EngineActualAccelerator,VCU_Life,EngineInputAirTemp,FuelConsumption_Instant;
extern volatile u16 EngineSpeed,scr,oil_prss,shunshigonglv,FuelConsumption_100KM_Subtotal,FuelConsumption_100KM_Acctotal,shengyugonglv,Motor_Current;
extern volatile u32 OilAccumulation;
extern volatile u8 VCUSofeVersion[8],ECUSofeVersion[8],EECUSofeVersion[8],SystemMode,SystemStatus,xuedimoshi,qianyinli;
extern volatile u16 can_err_time,SystemCode;
extern volatile u8 DrivingRange,baigongli[2],AlarmFlag[4],E_MotorError[4],BmsMonoData[5][8],DebugData[8];


extern volatile TYPE_BYTE AIR[8],YUN_TONG[8],fuzhu[8],add1[8],add2[8],add3[8];
extern volatile u8 ECASFault[40];




typedef struct{
 unsigned int ivoltage;
 unsigned int icurrent;
 unsigned int itorque;

 unsigned int ispeed;
 unsigned char itemp;
 unsigned char etemp;

 unsigned char iversion[8];
}bus_motor;
extern volatile bus_motor MOTOR;


typedef struct{
 unsigned char itemp;
 unsigned char etemp;
 unsigned char iversion[8];
 unsigned int ifault_code;
 unsigned char ifault_level;
 unsigned char ibus_model;
 unsigned char ilife;
 unsigned char K_control;
 unsigned char iready;
 unsigned char igear;
 unsigned char iswitching;
 unsigned char icharge;
}bus_control;
extern volatile bus_control CONTROL;


typedef struct{
 unsigned char ispeed_up;
 unsigned char ibraking;
}footboard;
extern volatile footboard STEP;

typedef struct{
 u16 voltage_out;
 u16 current;
 u16 voltage_input;
 u8 temp;
 u8 faultcode;
}dcdc;
extern volatile dcdc DC_DC;


typedef struct{
 unsigned int ivoltage;
 unsigned int icadc;
 unsigned char isoc;
 unsigned char istatus[3];
 unsigned int imax_charge;
 unsigned int imax_discharge;
 unsigned char isystem_fault;
 unsigned int iaverage_voltage;
 unsigned char imono_max_temp;
 unsigned int itotal_anode_riso;
 unsigned int itotal_cathode_riso;
 unsigned int imono_max_voltage;
 unsigned int imono_min_voltage;
 unsigned char VIN;
 unsigned char status_flag4;
 unsigned char ChargeOutletTemp1;
 unsigned char ChargeOutletTemp2;
 unsigned char ChargeOutletTemp3;
 unsigned char ChargeOutletTemp4;
 unsigned char error_total;
 unsigned char status_flag5;
 unsigned int rated_capacity;
 unsigned int rated_voltage;
 unsigned int battery_series_num;
 unsigned char battery_parallel_num;
 unsigned char temp_sensor_num;
 unsigned char imono_max_temp_2;
 unsigned char maxtemp_pos_x;
 unsigned char maxtemp_pos_y;
 unsigned char imono_min_temp;
 unsigned char mintemp_pos_x;
 unsigned char mintemp_pos_y;
 unsigned char battery_typeinfo;
 unsigned char battery_cooling_methods;

 unsigned char maxvol_pos_x;
 unsigned char maxvol_pos_y;
 unsigned char minvol_pos_x;
 unsigned char minvol_pos_y;


}battery;
extern volatile battery BMS;

typedef struct{
 unsigned int inumber[10];
 unsigned int ivoltage[10];
 unsigned char isampl_number[10];
 unsigned char itemp[10];
}mono_battery;
extern volatile mono_battery BMS_MONO;

typedef struct{
 unsigned char box[10];
 unsigned char type[10];
 unsigned char alarm_level[10];
 unsigned char fault_status[10];
 unsigned char zifa_status[10];
 unsigned char fault_code[10];
 unsigned char rolling_count[10];
}miehuo;
extern volatile miehuo MIEHUO;

void InitDisplay();
# 75 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/bootloader.h" 1
# 34 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/bootloader.h"
typedef enum
{
 BL_Nop,
 BL_ToBoot,
 BL_GetInfo
} BLStauts;

typedef enum
{
 BLCMD_ToBootStatus = 5,
 BLCMD_GetInfo,
} BLCmd;
# 63 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/source/bootloader.h"
extern volatile BLStauts blstatus;


void BootloaderInit(CAN_SFRmap* can);
void BootloaderLoop(void);
void BootloaderHandleRxMsg(CAN_MessageTypeDef * RxMessage);
# 76 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/emios.h" 1
# 14 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/emios.h"
void PwmInit(void);
void SetBackGround(uint8_t level);
void BACKGROUND_OFF(void);


void C3_Sign_OUT(uint16_t speed,uint16_t hundred_meter);


void CaptureModeInit(void);
void GetCaptureHZ(void);
# 77 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Rtc.h" 1
# 11 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/Rtc.h"
void RtcInit(void);
void get_date(void);
void set_date(void);

void config_rtc(void);
uint8_t is_leap_year(void);
extern const uint8_t days_in_mo[13];
# 78 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/T123AI.h" 1
# 63 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/T123AI.h"
extern uint16_t t123Ans;

typedef struct xSendToT123Stru
{
 u8 sended;
 u8 loop;
 u8 delay;
 u8 data[12];

}SendToT123Stru;


enum {
 Sended,
 Ready,
 Check1,
 Check2,



 SendErr,
 SendNop
};

typedef struct SendToT123Xx
{
 int wr_index;
 int rd_index;
 int ovfcount;
 int errcount;
 SendToT123Stru * buff;
 int max_len;
} SendToT123X;

extern SendToT123X SendBuff;
extern u8 SendToT123Loop;
extern u8 SendToT123Delay;


extern uint32_t fifo_in(SendToT123X*fifo);
extern void fifo_init(SendToT123X* fifo,SendToT123Stru*buff,uint32_t len);
extern uint32_t fifo_out(SendToT123X *fifo);
extern void fifo_reset(SendToT123X*fifo);


extern void SendToT123();

extern void InitSendToT123();

extern void fifo_set_free(SendToT123X*fifo);
# 79 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2



# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/watchdog.h" 1
# 14 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/watchdog.h"
void WWDT_Config_TH(uint32_t Threshold);
void WWDT_Clear(void);
# 83 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/EElogic.h" 1
# 12 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/EElogic.h"
typedef union
{
    BYTE_FIELD databit1[16];
    uint8_t data8[16];
    uint16_t data16[8];
    struct
    {
        uint32_t odo;
        uint16_t trip;
  uint8_t resv[9];
        uint8_t checksum;
    } Data;
} EEDataStru;


typedef union
{
  uint8_t data8[8];
  struct
  {
    uint8_t cmd;
 uint8_t setdata;
    uint16_t addr;
 uint8_t resv[3];
 uint8_t checksum;
  }Data;
}EECan;

typedef union
{
    BYTE_FIELD databit1[32];
    uint8_t data8[32];
    uint16_t data16[16];
    uint32_t data32[8];
 uint64_t data64[4];
    struct
    {
        BYTE_FIELD Switch;
        uint8_t backlight;

        uint16_t pulse;

        uint16_t subi;
        uint16_t trip;

  uint8_t coef;

  uint8_t speed_alarm;
        uint8_t air_alarm;
  uint8_t oil_alarm;
     uint8_t ranyou_alarm;
     uint8_t air_coef;
     uint8_t air2_coef;
     BYTE_FIELD video;
     uint8_t fuel_coef;
  uint8_t rain_time;


  uint8_t resv[13];
        uint8_t checksum;
    } Data;
} EEParaStru;


extern void DelayKong(volatile uint32_t a, volatile uint32_t b);

extern TYPE_BYTE EEflag;
extern EECan CanSetEEByte;
# 105 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/EElogic.h"
enum
{
  mainmilepage = 16,
  backupmilepage,
  mainparal,
  mainparah,
  backupparal,
  backupparah,
};

typedef enum
{
  EENOP,
  EEMAINODO,
  EEBACKUPODO,
  EEMAINPARAL,
  EEMAINPARAH,
  EEBACKPARAL,
  EEBACKPARAH,

  EECANSETBYTE,

  EECANSETBACK,
}EEstep;
# 147 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/EElogic.h"
void ZD24C0xReadVehodo(void);

void ZD24C0xReadMeterPara(void);

void WriteEE(void);

void ReadAllZD24c0x(void);
# 84 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/ZD240Cx.h" 1
# 42 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/ZD240Cx.h"
void ZD_iic_init(void);

void ZD_write_add(unsigned int address,unsigned char date);
unsigned char ZD_read_add(unsigned int address);
unsigned char ZD_read_bytes(unsigned int address,unsigned char *date,unsigned int readnum);
void ZD_write_bytes(unsigned int address,unsigned char *date,unsigned char writenum);
# 85 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h" 2
# 122 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/system/system_init.h"
static void SetSysClock(void);
void SystemInit(void);
# 9 "../source/displayhelper.c" 2
# 1 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/keyfifo.h" 1
# 12 "H:/art_service/code/YB_2022/12/XGYC-QRWD-221202/YB-XGYC-QRWD-221202/driver/keyfifo.h"
typedef enum _MESSAGE
{
  MSG_NONE = 0x00

} MESSAGE;



typedef enum _MSG_FIFO_INDEX
{
 MSG_FIFO_KEY = 0,
 MSG_FIFO_DISP ,
 MSG_FIFO_SYS,
 MSG_FIFO_COUNT

} MSG_FIFO_INDEX;


typedef struct _MESSAGE_FIFO
{
  unsigned char IndexHead;
  unsigned char Count;
  unsigned char Buf[8];

} MESSAGE_FIFO;


extern MESSAGE_FIFO MsgFifos[MSG_FIFO_COUNT];
extern void message_init(void);


extern void message_send(unsigned char MsgFifoIndex, unsigned char event);

extern unsigned char message_get(unsigned char MsgFifoIndex);
# 10 "../source/displayhelper.c" 2




 static uint32_t VedioManual = 0;
 u8 initflag = 1;
 static uint8_t choose_menu = 0;
 static u8 timedata[5];

 static u8 NoEncryptSetVar[8] = {0};
 const uint16_t password = 1127;
 static u16 set_password;




 DisMenuStruct disp[25];
 u32 MenuNum = 0;



 u8 SetOption = 0;
 u8 ClearBufferDisable = 0;

 typedef struct
 {
  unsigned char bs0: 4;
  unsigned char bs1: 4;
 } BYTE_4BITFIELD;

 typedef union
 {
  unsigned char byte;
  BYTE_4BITFIELD bit;
 } BYTE_4Bit_Union;


 static BYTE_4Bit_Union PageInfo[8] = {0};


 void SendKeyToGPU(u8 key)
 {
  uint8_t i;
  for(i = 1; i < 12; i++)
  {
   Send_To_DP_Data[i] = 0;
  }

  Send_To_DP_Data[0] = 0x80;
  Send_To_DP_Data[1] = 0x03;
  Send_To_DP_Data[2] = 0x02;

  Send_To_DP_Data[3] = key;

  fifo_in(&SendBuff);

 }


 void ChangeToSubPageCache(uint8_t menu, uint8_t subpage)
 {
  uint8_t i;
  for(i = 1; i < 12; i++)
  {
   Send_To_DP_Data[i] = 0;
  }

  Send_To_DP_Data[0] = 0x80;
  Send_To_DP_Data[1] = 0x03;
  Send_To_DP_Data[2] = 0x01;

  switch(menu)
  {
   case SET_MODE:
    if(Art.bit.b8 && Art.bit.b9 && Art.bit.b10 && Art.bit.b11)
    {
     PageInfo[0].bit.bs0 = subpage | 0x04 ;
    }
    else
    {
     PageInfo[0].bit.bs0 = subpage ;
    }
    break;
   case DIS_VEDIO:
    PageInfo[0].bit.bs1 = subpage;
    break;
   case DIS_SYSTEM_SET_MENU:
    PageInfo[1].bit.bs0 = subpage;
    break;
   case DIS_BMS_MENU:
    PageInfo[1].bit.bs1 = subpage;
    break;
   case DIS_ART_INFORMATION:
    PageInfo[2].bit.bs0 = subpage;
    break;
   case DIS_MAIN:
    PageInfo[2].bit.bs1 = subpage;
    break;
   case DIS_FUZU_MENU:
    PageInfo[3].bit.bs0 = subpage;
    break;
   case SET_JMP_PAGE:
    choose_menu = subpage;
    PageInfo[7].byte = subpage;
    break;
  }

  PageInfo[6].byte = dis_mod;

  for(i = 0; i < 8; i++)
  {
   Send_To_DP_Data[i + 3] = PageInfo[i].byte;
  }


 }


 void ChangeToSubPage(uint8_t menu, uint8_t subpage)
 {
  ChangeToSubPageCache(menu, subpage);
  fifo_in(&SendBuff);
  if(SET_JMP_PAGE == menu)
  {
   SendKeyToGPU(CMD_JMP_PAGE);
  }
 }




 void PushDataToGPU()
 {
  uint8_t i;

  Send_To_DP_Data[0] = 0x80;
  Send_To_DP_Data[1] = 0x03;
  Send_To_DP_Data[2] = 0x01;

  for(i = 0; i < 8; i++)
  {
   Send_To_DP_Data[i + 3] = PageInfo[i].byte;
  }

  fifo_in(&SendBuff);
 }
# 164 "../source/displayhelper.c"
 static u32 MainMesg(u8 key, u8 initpw)
 {
  u8 changeflag = 0xFF;
  static u8 lastflag = 0xFF,lop= 0;

  if((initpw))
  {
   SendKeyToGPU(CMD_DIS_PAGE);

   lastflag = 0xFF;
  }

  if(Art.bit.b13)
  {
      switch(lop)
      {
            case 0:
      SendPAGE_MAIN04(1);
      break;
   case 4:
      SendPAGE_MAIN05(1);
      break;
      case 8:
      SendPAGE_MAIN06(1);
      break;
   }
   lop++;
   if(lop > 10)
    lop = 0;
  }

  switch(key)
  {
   case IN_KEY1_SP:
    return DIS_CHOOSE_MENU;
   case IN_KEY3_CP:
    if(0 == 1)
    {
     clr_trip();
    }
    else
    {
     Art.bit.b14 = 1;
     Veh_trip = 0;

     EEflag.bit.b0 = 1;
    }
    break;

     case IN_KEY4_CP:

    break;
  }
  return DIS_MAIN_MENU;
 }



 static u32 MenuMesg(u8 key, u8 initpw)
 {
  u8 sendflag = 0;
  static u8 InitNoEncryptSetFlag = 0;
  if(initpw)
  {
   SendKeyToGPU(CMD_DIS_MENU);
  }
  switch(key)
  {
   case IN_KEY4_SP:
    return choose_menu;
   case IN_KEY2_SP:
    choose_menu++;
    if(choose_menu >= DIS_USED_END)
    {
     choose_menu = DIS_MAIN_MENU;
    }

    SendKeyToGPU(CMD_INC_MENU);
    break;
   case IN_KEY3_SP:
    if(choose_menu == DIS_MAIN_MENU)
    {
     choose_menu = DIS_USED_END;
    }

    choose_menu--;
    SendKeyToGPU(CMD_DEC_MENU);
    break;
  }

  return DIS_CHOOSE_MENU;

 }


enum
{
    TONY_METER = 0,

    FMode,


    RMode,


    TMode,

    ARTNum
};


void art_fmod_1(u8 initpw)
{
    TYPE_DWORD front_power_state;

    u8 i; u8 change = 0; static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; for(i = 1; i < 12; i++) Send_To_DP_Data[i] = 0;;

    front_power_state.BIT.b0 = (bcm_out_st_f.bit.b0) ? bcm_fb_st_f.BIT.b0 : 3;
    front_power_state.BIT.b1 = (bcm_out_st_f.bit.b2) ? bcm_fb_st_f.BIT.b2 : 3;
    front_power_state.BIT.b2 = (bcm_out_st_f.bit.b4) ? bcm_fb_st_f.BIT.b4 : 3;
    front_power_state.BIT.b3 = (bcm_out_st_f.bit.b6) ? bcm_fb_st_f.BIT.b6 : 3;

    front_power_state.BIT.b4 = (bcm_out_st_f.bit.b8) ? bcm_fb_st_f.BIT.b8 : 3;
    front_power_state.BIT.b5 = (bcm_out_st_f.bit.b10) ? bcm_fb_st_f.BIT.b10 : 3;
    front_power_state.BIT.b6 = (bcm_out_st_f.bit.b12) ? bcm_fb_st_f.BIT.b12 : 3;
    front_power_state.BIT.b7 = (bcm_out_st_f.bit.b14) ? bcm_fb_st_f.BIT.b14 : 3;

    front_power_state.BIT.b8 = (bcm_out_st_f.bit.b1) ? bcm_fb_st_f.BIT.b1 : 3;
    front_power_state.BIT.b9 = (bcm_out_st_f.bit.b3) ? bcm_fb_st_f.BIT.b3 : 3;
    front_power_state.BIT.b10 = (bcm_out_st_f.bit.b5) ? bcm_fb_st_f.BIT.b5 : 3;
    front_power_state.BIT.b11 = (bcm_out_st_f.bit.b7) ? bcm_fb_st_f.BIT.b7 : 3;

    front_power_state.BIT.b12 = (bcm_out_st_f.bit.b9) ? bcm_fb_st_f.BIT.b9 : 3;
    front_power_state.BIT.b13 = (bcm_out_st_f.bit.b11) ? bcm_fb_st_f.BIT.b11 : 3;
    front_power_state.BIT.b14 = (bcm_out_st_f.bit.b13) ? bcm_fb_st_f.BIT.b13 : 3;

    Send_To_DP_Data[0] = 0x08;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x01;
    Send_To_DP_Data[3] = front_power_state.byte[0];
    Send_To_DP_Data[4] = front_power_state.byte[1];
    Send_To_DP_Data[5] = front_power_state.byte[2];
    Send_To_DP_Data[6] = front_power_state.byte[3];
    Send_To_DP_Data[7] = bcm_sw1_f.byte[0];
    Send_To_DP_Data[8] = bcm_sw1_f.byte[1];
    Send_To_DP_Data[9] = bcm_sw2_f.byte;
    for(i=3; i<11; i++) { if(data1save[i] != Send_To_DP_Data[i]) { data1save[i] = Send_To_DP_Data[i]; change ++; } } if((change>0) ||(initpw)) { fifo_in(&SendBuff); };
}

void art_fmod_2(u8 initpw)
{
 u16 temp;
    u8 i; u8 change = 0; static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; for(i = 1; i < 12; i++) Send_To_DP_Data[i] = 0;;

    Send_To_DP_Data[0] = 0x08;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x02;
 temp = bcm_senor1_f * Air_Coef*0.1;
    Send_To_DP_Data[3] = temp;
    Send_To_DP_Data[4] = temp >> 8;
 temp = bcm_senor2_f * Air_Coef*0.1;
    Send_To_DP_Data[5] = temp;
    Send_To_DP_Data[6] = temp >> 8;
    Send_To_DP_Data[7] = bcm_frq_f;
    Send_To_DP_Data[8] = bcm_frq_f >> 8;

    for(i=3; i<11; i++) { if(data1save[i] != Send_To_DP_Data[i]) { data1save[i] = Send_To_DP_Data[i]; change ++; } } if((change>0) ||(initpw)) { fifo_in(&SendBuff); };
}



SendPackFunc ART_FMODE_Sendfuncs[] =
{
    art_fmod_1,
    art_fmod_2
};
void ART_FMODE_Send(u8 initpw) { u8 i=0; static u8 fan = 0; if(fan>= (sizeof(ART_FMODE_Sendfuncs)/sizeof(SendPackFunc))) fan = 0; if(initpw) { for(i=0;i<(sizeof(ART_FMODE_Sendfuncs)/sizeof(SendPackFunc));i++) (*(ART_FMODE_Sendfuncs[i]))(initpw); } else (*(ART_FMODE_Sendfuncs[fan]))(0); fan++; };

void art_rmod_1(u8 initpw)
{
    TYPE_DWORD middle_power_state;

    u8 i; u8 change = 0; static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; for(i = 1; i < 12; i++) Send_To_DP_Data[i] = 0;;

    middle_power_state.BIT.b0 = (bcm_out_st_r.bit.b0) ? bcm_fb_st_r.BIT.b0 : 3;
    middle_power_state.BIT.b1 = (bcm_out_st_r.bit.b2) ? bcm_fb_st_r.BIT.b2 : 3;
    middle_power_state.BIT.b2 = (bcm_out_st_r.bit.b4) ? bcm_fb_st_r.BIT.b4 : 3;
    middle_power_state.BIT.b3 = (bcm_out_st_r.bit.b6) ? bcm_fb_st_r.BIT.b6 : 3;

    middle_power_state.BIT.b4 = (bcm_out_st_r.bit.b8) ? bcm_fb_st_r.BIT.b8 : 3;
    middle_power_state.BIT.b5 = (bcm_out_st_r.bit.b10) ? bcm_fb_st_r.BIT.b10 : 3;
    middle_power_state.BIT.b6 = (bcm_out_st_r.bit.b12) ? bcm_fb_st_r.BIT.b12 : 3;
    middle_power_state.BIT.b7 = (bcm_out_st_r.bit.b14) ? bcm_fb_st_r.BIT.b14 : 3;

    middle_power_state.BIT.b8 = (bcm_out_st_r.bit.b1) ? bcm_fb_st_r.BIT.b1 : 3;
    middle_power_state.BIT.b9 = (bcm_out_st_r.bit.b3) ? bcm_fb_st_r.BIT.b3 : 3;
    middle_power_state.BIT.b10 = (bcm_out_st_r.bit.b5) ? bcm_fb_st_r.BIT.b5 : 3;
    middle_power_state.BIT.b11 = (bcm_out_st_r.bit.b7) ? bcm_fb_st_r.BIT.b7 : 3;

    middle_power_state.BIT.b12 = (bcm_out_st_r.bit.b9) ? bcm_fb_st_r.BIT.b9 : 3;
    middle_power_state.BIT.b13 = (bcm_out_st_r.bit.b11) ? bcm_fb_st_r.BIT.b11 : 3;
    middle_power_state.BIT.b14 = (bcm_out_st_r.bit.b13) ? bcm_fb_st_r.BIT.b13 : 3;

    Send_To_DP_Data[0] = 0x09;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x01;
    Send_To_DP_Data[3] = middle_power_state.byte[0];
    Send_To_DP_Data[4] = middle_power_state.byte[1];
    Send_To_DP_Data[5] = middle_power_state.byte[2];
    Send_To_DP_Data[6] = middle_power_state.byte[3];
    Send_To_DP_Data[7] = bcm_sw1_r.byte[0];
    Send_To_DP_Data[8] = bcm_sw1_r.byte[1];
    Send_To_DP_Data[9] = bcm_sw2_r.byte;
    for(i=3; i<11; i++) { if(data1save[i] != Send_To_DP_Data[i]) { data1save[i] = Send_To_DP_Data[i]; change ++; } } if((change>0) ||(initpw)) { fifo_in(&SendBuff); };
}

extern u8 Frist_Temp_1;
void art_rmod_2(u8 initpw)
{
    u8 i; u8 change = 0; static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; for(i = 1; i < 12; i++) Send_To_DP_Data[i] = 0;;

    Send_To_DP_Data[0] = 0x09;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x02;

    Send_To_DP_Data[3] = bcm_senor1_r;
    Send_To_DP_Data[4] = bcm_senor1_r >> 8;
    Send_To_DP_Data[5] = bcm_senor2_r;
    Send_To_DP_Data[6] = bcm_senor2_r >> 8;
    Send_To_DP_Data[7] = bcm_frq_r;
    Send_To_DP_Data[8] = bcm_frq_r >> 8;
    Send_To_DP_Data[9] = Temp_Vbat;

    for(i=3; i<11; i++) { if(data1save[i] != Send_To_DP_Data[i]) { data1save[i] = Send_To_DP_Data[i]; change ++; } } if((change>0) ||(initpw)) { fifo_in(&SendBuff); };
}



SendPackFunc ART_RMODE_Sendfuncs[] =
{
    art_rmod_1,
    art_rmod_2
};
void ART_RMODE_Send(u8 initpw) { u8 i=0; static u8 fan = 0; if(fan>= (sizeof(ART_RMODE_Sendfuncs)/sizeof(SendPackFunc))) fan = 0; if(initpw) { for(i=0;i<(sizeof(ART_RMODE_Sendfuncs)/sizeof(SendPackFunc));i++) (*(ART_RMODE_Sendfuncs[i]))(initpw); } else (*(ART_RMODE_Sendfuncs[fan]))(0); fan++; };


void art_tmod_1(u8 initpw)
{
    TYPE_DWORD top_power_state;

    u8 i; u8 change = 0; static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; for(i = 1; i < 12; i++) Send_To_DP_Data[i] = 0;;

    top_power_state.BIT.b0 = (bcm_out_st_t.bit.b0 == 1) ? bcm_fb_st_t.BIT.b0 : 3;
    top_power_state.BIT.b1 = (bcm_out_st_t.bit.b2 == 1) ? bcm_fb_st_t.BIT.b2 : 3;
    top_power_state.BIT.b2 = (bcm_out_st_t.bit.b4 == 1) ? bcm_fb_st_t.BIT.b4 : 3;
    top_power_state.BIT.b3 = (bcm_out_st_t.bit.b6 == 1) ? bcm_fb_st_t.BIT.b6 : 3;

    top_power_state.BIT.b4 = (bcm_out_st_t.bit.b8 == 1) ? bcm_fb_st_t.BIT.b8 : 3;
    top_power_state.BIT.b5 = (bcm_out_st_t.bit.b10 == 1) ? bcm_fb_st_t.BIT.b10 : 3;
    top_power_state.BIT.b6 = (bcm_out_st_t.bit.b12 == 1) ? bcm_fb_st_t.BIT.b12 : 3;
    top_power_state.BIT.b7 = (bcm_out_st_t.bit.b14 == 1) ? bcm_fb_st_t.BIT.b14 : 3;
    top_power_state.BIT.b8 = (bcm_out_st_t.bit.b1 == 1) ? bcm_fb_st_t.BIT.b1 : 3;
    top_power_state.BIT.b9 = (bcm_out_st_t.bit.b3 == 1) ? bcm_fb_st_t.BIT.b3 : 3;
    top_power_state.BIT.b10 = (bcm_out_st_t.bit.b5 == 1) ? bcm_fb_st_t.BIT.b5 : 3;
    top_power_state.BIT.b11 = (bcm_out_st_t.bit.b7 == 1) ? bcm_fb_st_t.BIT.b7 : 3;

    top_power_state.BIT.b12 = (bcm_out_st_t.bit.b9 == 1) ? bcm_fb_st_t.BIT.b9 : 3;
    top_power_state.BIT.b13 = (bcm_out_st_t.bit.b11 == 1) ? bcm_fb_st_t.BIT.b11 : 3;
    top_power_state.BIT.b14 = (bcm_out_st_t.bit.b13 == 1) ? bcm_fb_st_t.BIT.b13 : 3;

    Send_To_DP_Data[0] = 0x0A;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x01;

    Send_To_DP_Data[3] = top_power_state.byte[0];
    Send_To_DP_Data[4] = top_power_state.byte[1];
    Send_To_DP_Data[5] = top_power_state.byte[2];
    Send_To_DP_Data[6] = top_power_state.byte[3];
    Send_To_DP_Data[7] = bcm_sw1_t.byte[0];
    Send_To_DP_Data[8] = bcm_sw1_t.byte[1];
    Send_To_DP_Data[9] = bcm_sw2_t.byte;

    for(i=3; i<11; i++) { if(data1save[i] != Send_To_DP_Data[i]) { data1save[i] = Send_To_DP_Data[i]; change ++; } } if((change>0) ||(initpw)) { fifo_in(&SendBuff); };
}

void art_tmod_2(u8 initpw)
{
    u8 i; u8 change = 0; static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; for(i = 1; i < 12; i++) Send_To_DP_Data[i] = 0;;

    Send_To_DP_Data[0] = 0x0A;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x02;

    Send_To_DP_Data[3] = bcm_senor1_t;
    Send_To_DP_Data[4] = bcm_senor1_t >> 8;
    Send_To_DP_Data[5] = bcm_senor2_t;
    Send_To_DP_Data[6] = bcm_senor2_t >> 8;
    Send_To_DP_Data[7] = bcm_frq_t;
    Send_To_DP_Data[8] = bcm_frq_t >> 8;

    for(i=3; i<11; i++) { if(data1save[i] != Send_To_DP_Data[i]) { data1save[i] = Send_To_DP_Data[i]; change ++; } } if((change>0) ||(initpw)) { fifo_in(&SendBuff); };
}



SendPackFunc ART_TMODE_Sendfuncs[] =
{
    art_tmod_1,
    art_tmod_2
};
void ART_TMODE_Send(u8 initpw) { u8 i=0; static u8 fan = 0; if(fan>= (sizeof(ART_TMODE_Sendfuncs)/sizeof(SendPackFunc))) fan = 0; if(initpw) { for(i=0;i<(sizeof(ART_TMODE_Sendfuncs)/sizeof(SendPackFunc));i++) (*(ART_TMODE_Sendfuncs[i]))(initpw); } else (*(ART_TMODE_Sendfuncs[fan]))(0); fan++; };
# 491 "../source/displayhelper.c"
void Art_Meter_1(u8 initpw)
{
    static TYPE_BYTE temp = {0};

    u8 i; u8 change = 0; static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; for(i = 1; i < 12; i++) Send_To_DP_Data[i] = 0;;


    Send_To_DP_Data[0] = 0x07;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x01;


    temp.byte = 0;
    temp.bit.b0 = port_a.bit.b3;
    temp.bit.b1 = port_a.bit.b2;
    temp.bit.b2 = port_a.bit.b1;
    temp.bit.b3 = port_a.bit.b0;
    temp.bit.b4 = port_a.bit.b5;
    temp.bit.b5 = port_a.bit.b4;
    temp.bit.b6 = port_a.bit.b6;
    temp.bit.b7 = port_b.bit.b0;

    Send_To_DP_Data[3] = temp.byte;

    temp.byte = 0;
    temp.bit.b0 = port_b.bit.b1;
    temp.bit.b1 = port_b.bit.b2;
    temp.bit.b2 = port_b.bit.b3;
    temp.bit.b3 = port_b.bit.b4;
    temp.bit.b4 = port_b.bit.b5;
    temp.bit.b5 = port_b.bit.b6;
    temp.bit.b6 = port_b.bit.b7;
    temp.bit.b7 = port_b.bit.b8;

    Send_To_DP_Data[4] = temp.byte;

    temp.byte = 0;
    temp.bit.b0 = port_b.bit.b9;
    temp.bit.b1 = port_b.bit.b10;
    temp.bit.b2 = port_b.bit.b11;
    temp.bit.b3 = port_c.bit.b0;
    temp.bit.b4 = port_c.bit.b1;
    temp.bit.b5 = port_c.bit.b2;
    temp.bit.b6 = port_c.bit.b3;
    temp.bit.b7 = port_c.bit.b4;

    Send_To_DP_Data[5] = temp.byte;

    temp.byte = 0;
    temp.bit.b0 = port_c.bit.b5;
    temp.bit.b1 = port_c.bit.b6;
    temp.bit.b2 = port_c.bit.b7;
    temp.bit.b3 = port_c.bit.b8;
    temp.bit.b4 = port_d.bit.b0;
    temp.bit.b5 = port_d.bit.b1;
    temp.bit.b6 = port_d.bit.b2;
    temp.bit.b7 = port_d.bit.b3;

    Send_To_DP_Data[6] = temp.byte;

    temp.byte = 0;
    temp.bit.b0 = port_d.bit.b4;
    temp.bit.b1 = port_d.bit.b5;
    temp.bit.b2 = port_d.bit.b6;
    temp.bit.b3 = port_d.bit.b7;
    temp.bit.b4 = port_d.bit.b8;
    temp.bit.b5 = port_d.bit.b9;
    temp.bit.b6 = port_d.bit.b10;
    temp.bit.b7 = port_d.bit.b11;

    Send_To_DP_Data[7] = temp.byte;

    temp.byte = 0;
    temp.bit.b0 = port_d.bit.b12;
    temp.bit.b1 = port_d.bit.b13;
    temp.bit.b2 = port_d.bit.b14;
    temp.bit.b3 = port_d.bit.b15;
    temp.bit.b4 = port_a.bit.b7;
    temp.bit.b5 = 0;

    temp.bits.bits3 = output_s.bit.b4 ? ((sw_diagnose[1].bits.bit4 == 2) ? 2 : 0) : 3;
 Send_To_DP_Data[8] = temp.byte;

    temp.byte = 0;

    temp.bits.bits0 = output_s.bit.b0 ? ((sw_diagnose[0].bits.bit4 == 2) ? 2 : 0) : 3;
    temp.bits.bits1 = output_s.bit.b1 ? ((sw_diagnose[0].bits.bit2 == 2) ? 2 : 0) : 3;
    temp.bits.bits2 = output_s.bit.b2 ? ((sw_diagnose[0].bits.bit3 == 2) ? 2 : 0) : 3;
    temp.bits.bits3 = output_s.bit.b3 ? ((sw_diagnose[0].bits.bit1 == 2) ? 2 : 0) : 3;

    Send_To_DP_Data[9] = temp.byte;
    for(i=3; i<11; i++) { if(data1save[i] != Send_To_DP_Data[i]) { data1save[i] = Send_To_DP_Data[i]; change ++; } } if((change>0) ||(initpw)) { fifo_in(&SendBuff); };
}

void Art_Meter_2(u8 initpw)
{
    u8 i; u8 change = 0; static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; for(i = 1; i < 12; i++) Send_To_DP_Data[i] = 0;;
    Send_To_DP_Data[0] = 0x07;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x02;

    Send_To_DP_Data[3] = meter.MeterA5;
    Send_To_DP_Data[4] = meter.MeterA5 >> 8;
    Send_To_DP_Data[5] = meter.MeterA15;
    Send_To_DP_Data[6] = meter.MeterA15 >> 8;
    Send_To_DP_Data[7] = meter.MeterA2;
    Send_To_DP_Data[8] = meter.MeterA2 >> 8;
    Send_To_DP_Data[9] = 0;
    Send_To_DP_Data[10] = 0;

    for(i=3; i<11; i++) { if(data1save[i] != Send_To_DP_Data[i]) { data1save[i] = Send_To_DP_Data[i]; change ++; } } if((change>0) ||(initpw)) { fifo_in(&SendBuff); };
}

void Art_Meter_3(u8 initpw)
{
    u8 i; u8 change = 0; static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; for(i = 1; i < 12; i++) Send_To_DP_Data[i] = 0;;

    Send_To_DP_Data[0] = 0x07;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x03;


    Send_To_DP_Data[3] = meter.MeterA3;
    Send_To_DP_Data[4] = meter.MeterA3 >> 8;
    Send_To_DP_Data[5] = meter.MeterA4;
    Send_To_DP_Data[6] = meter.MeterA4 >> 8;
    Send_To_DP_Data[7] = meter.MeterA13;
    Send_To_DP_Data[8] = meter.MeterA13 >> 8;
    Send_To_DP_Data[9] = meter.MeterA14;
    Send_To_DP_Data[10] = meter.MeterA14 >> 8;


    for(i=3; i<11; i++) { if(data1save[i] != Send_To_DP_Data[i]) { data1save[i] = Send_To_DP_Data[i]; change ++; } } if((change>0) ||(initpw)) { fifo_in(&SendBuff); };
}

void Art_Meter_4(u8 initpw)
{
    TYPE_BYTE temp;

    u8 i; u8 change = 0; static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; for(i = 1; i < 12; i++) Send_To_DP_Data[i] = 0;;

    Send_To_DP_Data[0] = 0x07;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x04;

 Send_To_DP_Data[3] = 1;
# 652 "../source/displayhelper.c"
    for(i=3; i<11; i++) { if(data1save[i] != Send_To_DP_Data[i]) { data1save[i] = Send_To_DP_Data[i]; change ++; } } if((change>0) ||(initpw)) { fifo_in(&SendBuff); };
}
# 676 "../source/displayhelper.c"
SendPackFunc ART_METER_Sendfuncs[] =
{
    Art_Meter_1,
    Art_Meter_2,
    Art_Meter_3,
    Art_Meter_4,
};
void ART_METER_Send(u8 initpw) { u8 i=0; static u8 fan = 0; if(fan>= (sizeof(ART_METER_Sendfuncs)/sizeof(SendPackFunc))) fan = 0; if(initpw) { for(i=0;i<(sizeof(ART_METER_Sendfuncs)/sizeof(SendPackFunc));i++) (*(ART_METER_Sendfuncs[i]))(initpw); } else (*(ART_METER_Sendfuncs[fan]))(0); fan++; };



u32 ArtMesg(u8 key, u8 initpw)
{
    static u8 flag = 0;
    u8 changescreenflag = 0;

    if(initpw)
    {
        changescreenflag = 1;
        SendKeyToGPU(CMD_DIS_PAGE);
    }

    switch(key)
    {
        case IN_KEY2_SP:
            flag++;
            flag = (flag >= ARTNum) ? TONY_METER : flag;
            changescreenflag = 1;
            break;
        case IN_KEY3_SP:
            flag = (flag == TONY_METER) ? ARTNum : flag;
            flag--;
            changescreenflag = 1;
            break;
    }
    if(changescreenflag)
    {
        switch(flag)
        {
            case TONY_METER:
                ChangeToSubPage(DIS_ART_INFORMATION, PAGE_METER);
                break;


            case FMode:
                ChangeToSubPage(DIS_ART_INFORMATION, PAGE_FMODE);
                break;



            case RMode:
                ChangeToSubPage(DIS_ART_INFORMATION, PAGE_RMODE);
                break;



            case TMode:
                ChangeToSubPage(DIS_ART_INFORMATION, PAGE_TMODE);
                break;


        }
    }

    switch(flag)
    {
        case TONY_METER:
            ART_METER_Send(changescreenflag);
            break;


        case FMode:
            ART_FMODE_Send(changescreenflag);
            break;



        case RMode:
            ART_RMODE_Send(changescreenflag);
            break;



        case TMode:
            ART_TMODE_Send(changescreenflag);
            break;

    }

    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }
    return DIS_ART_INFORMATION;
}




void u32tostr(u32 dataxxx, u8 *out, u8 optionx, u8 CharNum)
{
    { u8 tempx[10] = {0}; u8 i,j,k,option=11; if(optionx) option = 0; for(i=0; dataxxx>0; dataxxx/=10) { tempx[i++] = dataxxx%10; } if(i == 0) { tempx[i++] = 0; } if(CharNum >= i) { k = CharNum-i; for(j=0; j<CharNum; j++) { if(j<k) out[j] = option; else out[j] = tempx[--i]; } } else { for(j=0;j<CharNum;j++) out[j] = 11; out[1] = 10; } };
}
# 792 "../source/displayhelper.c"
 void NoEncryptSetToGPU()
 {
  u8 initpw = 1;

  u8 i; u8 change = 0; static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; for(i = 1; i < 12; i++) Send_To_DP_Data[i] = 0;;

  Send_To_DP_Data[0] = 4;
  Send_To_DP_Data[1] = 2;
  Send_To_DP_Data[2] = 1;
  Send_To_DP_Data[3] = NoEncryptSetVar[0];
  Send_To_DP_Data[4] = NoEncryptSetVar[1];
  Send_To_DP_Data[5] = NoEncryptSetVar[2];
  Send_To_DP_Data[6] = NoEncryptSetVar[3];
  Send_To_DP_Data[7] = NoEncryptSetVar[4];
  Send_To_DP_Data[8] = NoEncryptSetVar[5];
  Send_To_DP_Data[9] = NoEncryptSetVar[6];
  Send_To_DP_Data[10] = NoEncryptSetVar[7];

  for(i=3; i<11; i++) { if(data1save[i] != Send_To_DP_Data[i]) { data1save[i] = Send_To_DP_Data[i]; change ++; } } if((change>0) ||(initpw)) { fifo_in(&SendBuff); };
 }


 void UpdateNoEncryptSetVar()
 {
  NoEncryptSetVar[1] = rtc.year;
  NoEncryptSetVar[2] = rtc.month;
  NoEncryptSetVar[3] = rtc.day;
  NoEncryptSetVar[4] = rtc.hours;
  NoEncryptSetVar[5] = rtc.mins;
  NoEncryptSetVar[6] = (Art.bit.b2 > 0) ;
  NoEncryptSetVar[7] = backlight_level;
 }

 void InitNoEncryptSetVar()
 {
  NoEncryptSetVar[0] = 0;
  UpdateNoEncryptSetVar();
 }

void SaveTime()
{
    rtc.hours = timedata[0];
    rtc.mins = timedata[1];
    rtc.year = timedata[2];
    rtc.month = timedata[3];
    rtc.day = timedata[4];
    rtc.secs = timedata[5];
    set_date();
}



 u8 ChangeTime(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 state = 0;
  rtc_t rtcx;
  u8 color;
  u8 i;
  static u16 data[6];
  u32 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;
   for(i = 0; i < 5; i++)
   {
    data[i] = timedata[i];
   }

   sendflag = 1;
   index = 0;
   state = 0;
  }

  switch(key)
  {
   case IN_KEY2_SP:
    data[index] ++;
    switch(index)
    {
     case 0:
      data[0] = data[0] > 23 ? 0 : data[0];
      break;
     case 1:
      data[1] = data[1] > 59 ? 0 : data[1];
      break;
     case 2:
      data[2] = data[2] > 99 ? 0 : data[2];
      break;
     case 3:
      data[3] = data[3] > 12 ? 1 : data[3];
      break;
     case 4:
      data[4] = (data[4] > (((data[3] == 2) && is_leap_year()) ? 29 : days_in_mo[data[3]])) ? 1 : data[4];
      break;
    }
    sendflag = 1;
    break;
   case IN_KEY3_SP:
    switch(index)
    {
     case 0:
      data[0] = data[0] <= 0 ? 24 : data[0];;
      break;
     case 1:
      data[1] = data[1] <= 0 ? 60 : data[1];
      break;
     case 2:
      data[2] = data[2] <= 0 ? 100 : data[2];
      break;
     case 3:
      data[3] = data[3] <= 1 ? 13 : data[3];
      break;
     case 4:
      data[4] = data[4] <= 1 ? ((((data[3] == 2) && is_leap_year()) ? 28 : days_in_mo[data[3]]) + 1) : data[4];
      break;
    }
    data[index] --;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 4)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;

   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;

   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;

  }
  if((sendflag == 1))
  {
   for(i = 0; i < 5; i++)
   {
    timedata[i] = data[i];
   }
   NoEncryptSetVar[0] = index + 0;
   NoEncryptSetVar[1] = data[2];
   NoEncryptSetVar[2] = data[3];
   NoEncryptSetVar[3] = data[4];
   NoEncryptSetVar[4] = data[0];
   NoEncryptSetVar[5] = data[1];
   NoEncryptSetToGPU();
   sendflag = 0;
  }

  return 0;

 }


 static u8 ChangeBackLight(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
    backlight_level ++;
    backlight_level = backlight_level >= 9 ? 0 : backlight_level;
    sendflag = 1;
    break;
   case IN_KEY3_SP:
    backlight_level = backlight_level <= 0 ? 9 : backlight_level;
    backlight_level --;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 0)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;
   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;
   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   NoEncryptSetVar[0] = index + (0 + (1*5));
   NoEncryptSetVar[7] = backlight_level;
   NoEncryptSetToGPU();

   sendflag = 0;
  }

  return 0;
 }







 static u8 ChangeBuzz(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
   case IN_KEY3_SP:
    Art.bit.b2 ^= 1;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 0)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;
   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;
   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   NoEncryptSetVar[0] = index + ((0 + (1*5)) + (1*1));
   NoEncryptSetVar[6] = ((Art.bit.b2 > 0));
   NoEncryptSetToGPU();
   sendflag = 0;
  }

  return 0;
 }





 enum
 {

  TimeIndex,


  BLIndex,


  BuzzIndex,

  NoEncryptSystemSetLast
 };

 void ReInitSystemPage()
 {
  timedata[0] = rtc.hours;
  timedata[1] = rtc.mins;
  timedata[2] = rtc.year;
  timedata[3] = rtc.month;
  timedata[4] = rtc.day;
  timedata[5] = rtc.secs;
  Set_backlight_level = backlight_level;
  Art.bit.b43 = Art.bit.b2;

 }

 void SaveChangeNoEncrypt()
 {
  if((Set_backlight_level != backlight_level) || (Art.bit.b43 != Art.bit.b2))
  {

   Set_backlight_level = backlight_level;
   Art.bit.b43 = Art.bit.b2;

        EEflag.bit.b1 = 1;

   SetBackGround(backlight_level);

  }
 }


 u32 NoEncryptSystemSet(u8 key, u8 initpw)
 {
  static u32 flag = 0;
  static u8 initflag = 0;
  static u8 LastNoEncryptSystemSetPage = NoEncryptSystemSetLast;
  static u8 reinitflag = 0;

  if(initpw)
  {




   SendKeyToGPU(CMD_DIS_PAGE);
   ReInitSystemPage();


   NoEncryptSetVar[6] = ((Art.bit.b2 > 0));
   LastNoEncryptSystemSetPage = flag;
   flag = 0;
   reinitflag = 1;
  }

  if((LastNoEncryptSystemSetPage == flag) && reinitflag)
  {
   initflag = 1;
   reinitflag = 0;
  }

  switch(flag)
  {

   case TimeIndex:
    flag += ChangeTime(key, initflag);
    initflag = 0;
    break;


   case BLIndex:
    flag += ChangeBackLight(key, initflag);
    initflag = 0;
    break;


   case BuzzIndex:
    flag += ChangeBuzz(key, initflag);
    initflag = 0;
    break;




  }

  flag = (flag >= NoEncryptSystemSetLast ? 0 : flag);

  if(key == IN_KEY4_SP)
  {
   SaveTime();
   SaveChangeNoEncrypt();


   return DIS_CHOOSE_MENU;
  }

  return DIS_FACTORY_SET_MENU;
 }


static BYTE_4Bit_Union ESSetData[24];
# 1312 "../source/displayhelper.c"
void SendESSetDataToGPU()
{
    u8 i;
    Send_To_DP_Data[0] = 4;
    Send_To_DP_Data[1] = 3;
    Send_To_DP_Data[2] = 1;

    for(i = 0; i < 8; i++)
    {
        Send_To_DP_Data[i + 3] = ESSetData[i].byte;
    }

    fifo_in(&SendBuff);

    Send_To_DP_Data[0] = 4;
    Send_To_DP_Data[1] = 3;
    Send_To_DP_Data[2] = 2;

    for(i = 0; i < 8; i++)
    {
        Send_To_DP_Data[i + 3] = ESSetData[i + 8].byte;
    }

    fifo_in(&SendBuff);

    Send_To_DP_Data[0] = 4;
    Send_To_DP_Data[1] = 3;
    Send_To_DP_Data[2] = 3;

    for(i = 0; i < 8; i++)
    {
        Send_To_DP_Data[i + 3] = ESSetData[i + 16].byte;
    }

    fifo_in(&SendBuff);
}




 static u8 ChangeLicheng(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;

   u32tostr(Set_Veh_odo, setbcd, 1, 7);
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
    setbcd[index] ++;
    setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
    sendflag = 1;
    break;
   case IN_KEY3_SP:
    setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
    setbcd[index] --;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 6)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;

   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;

   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   Set_Veh_odo = 0;
   for(i = 0; i < 7; i++)
   {
    Set_Veh_odo*= 10;
    Set_Veh_odo += setbcd[i];
    ESSetData[i + 1].byte = setbcd[i];
   }
   ESSetData[0].byte = index + 0;

   SendESSetDataToGPU();
   sendflag = 0;
  }

  return 0;
 }





 static u8 ChangeSubi(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;

   u32tostr(Set_odometer_const, setbcd, 1, 4);
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
    setbcd[index] ++;
    setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
    sendflag = 1;
    break;
   case IN_KEY3_SP:
    setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
    setbcd[index] --;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 3)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;
   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;
   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   Set_odometer_const = 0;
   for(i = 0; i < 4; i++)
   {
    Set_odometer_const *= 10;
    Set_odometer_const += setbcd[i];
   }

   ESSetData[0].byte = index + (0 + (1*7));
   ESSetData[8].bit.bs0 = setbcd[0];
   ESSetData[8].bit.bs1 = setbcd[1];
   ESSetData[9].bit.bs0 = setbcd[2];
   ESSetData[9].bit.bs1 = setbcd[3];

   SendESSetDataToGPU();

   sendflag = 0;
  }

  return 0;
 }


 static u8 ChangePulse(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;

   u32tostr(Set_Pulse, setbcd, 1, 4);
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
    setbcd[index] ++;
    setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
    sendflag = 1;
    break;
   case IN_KEY3_SP:
    setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
    setbcd[index] --;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 3)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;
   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;
   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   Set_Pulse = 0;
   for(i = 0; i < 4; i++)
   {
    Set_Pulse *= 10;
    Set_Pulse += setbcd[i];
   }

   ESSetData[0].byte = index + ((0 + (1*7)) + (1*4));
   ESSetData[10].bit.bs0 = setbcd[0];
   ESSetData[10].bit.bs1 = setbcd[1];
   ESSetData[11].bit.bs0 = setbcd[2];
   ESSetData[11].bit.bs1 = setbcd[3];

   SendESSetDataToGPU();

   sendflag = 0;
  }

  return 0;
 }



 static u8 ChangeCoef(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;

   u32tostr(Set_Coef, setbcd, 1, 3);
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
    setbcd[index] ++;
    setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
    sendflag = 1;
    break;
   case IN_KEY3_SP:
    setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
    setbcd[index] --;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 2)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;
   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;
   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   Set_Coef = 0;
   for(i = 0; i < 3; i++)
   {
    Set_Coef *= 10;
    Set_Coef += setbcd[i];
   }

   ESSetData[0].byte = index + (((0 + (1*7)) + (1*4))+(1*4));
   ESSetData[12].bit.bs0 = setbcd[0];
   ESSetData[12].bit.bs1 = setbcd[1];
   ESSetData[13].bit.bs0 = setbcd[2];

   SendESSetDataToGPU();


   sendflag = 0;
  }
  return 0;
 }




 static u8 ChangeAirCoef(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;

   u32tostr(Set_Air_Coef, setbcd, 1, 3);
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
    setbcd[index] ++;
    setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
    sendflag = 1;
    break;
   case IN_KEY3_SP:
    setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
    setbcd[index] --;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 2)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;
   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;
   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   Set_Air_Coef = 0;
   for(i = 0; i < 3; i++)
   {
    Set_Air_Coef *= 10;
    Set_Air_Coef += setbcd[i];
   }


   ESSetData[0].byte = index + ((((0 + (1*7)) + (1*4))+(1*4))+(1*3));
   ESSetData[13].bit.bs1 = setbcd[0];
   ESSetData[14].bit.bs0 = setbcd[1];
   ESSetData[14].bit.bs1 = setbcd[2];

   SendESSetDataToGPU();

   sendflag = 0;
  }
  return 0;
 }





 static u8 ChangeHSValue(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;
   u32tostr(Set_Speed_Alarm, setbcd, 1, 3);
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
    setbcd[index] ++;
    setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
    sendflag = 1;
    break;
   case IN_KEY3_SP:
    setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
    setbcd[index] --;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 2)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;
   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;
   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   Set_Speed_Alarm = 0;
   for(i = 0; i < 3; i++)
   {
    Set_Speed_Alarm *= 10;
    Set_Speed_Alarm += setbcd[i];
   }

   ESSetData[0].byte = index + (((((0 + (1*7)) + (1*4))+(1*4))+(1*3))+(1*3));
   ESSetData[15].bit.bs0 = setbcd[0];
   ESSetData[15].bit.bs1 = setbcd[1];
   ESSetData[16].bit.bs0 = setbcd[2];

   SendESSetDataToGPU();

   sendflag = 0;
  }
  return 0;
 }





 static u8 ChangeAirAlarm(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;

   u32tostr(Set_Air_Alarm, setbcd, 1, 3);
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
    setbcd[index] ++;
    setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
    sendflag = 1;
    break;
   case IN_KEY3_SP:
    setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
    setbcd[index] --;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 2)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;
   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;
   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   Set_Air_Alarm = 0;
   for(i = 0; i < 3; i++)
   {
    Set_Air_Alarm *= 10;
    Set_Air_Alarm += setbcd[i];
   }

   ESSetData[0].byte = index + ((((((0 + (1*7)) + (1*4))+(1*4))+(1*3))+(1*3))+(1*3));
   ESSetData[16].bit.bs1 = setbcd[0];
   ESSetData[17].bit.bs0 = setbcd[1];
   ESSetData[17].bit.bs1 = setbcd[2];

   SendESSetDataToGPU();


   sendflag = 0;
  }
  return 0;
 }





 static u8 ChangeOilAlarm(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;

   u32tostr(Set_Oil_Alarm, setbcd, 1, 3);
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
    setbcd[index] ++;
    setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
    sendflag = 1;
    break;
   case IN_KEY3_SP:
    setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
    setbcd[index] --;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 2)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;
   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;
   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   Set_Oil_Alarm= 0;
   for(i = 0; i < 3; i++)
   {
    Set_Oil_Alarm *= 10;
    Set_Oil_Alarm += setbcd[i];
   }
   ESSetData[0].byte = index + (((((((0 + (1*7)) + (1*4))+(1*4))+(1*3))+(1*3))+(1*3))+(1*3));
   ESSetData[18].bit.bs0 = setbcd[0];
   ESSetData[18].bit.bs1 = setbcd[1];
   ESSetData[19].bit.bs0 = setbcd[2];

   SendESSetDataToGPU();

   sendflag = 0;
  }
  return 0;
 }




 static u8 ChangeFuelCoef(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;

   u32tostr(Set_Fuel_Coef, setbcd, 1, 3);
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
    setbcd[index] ++;
    setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
    sendflag = 1;
    break;
   case IN_KEY3_SP:
    setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
    setbcd[index] --;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index >= (1*3))
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;
   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;
   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   Set_Fuel_Coef = 0;
   for(i = 0; i < 3; i++)
   {
    Set_Fuel_Coef *= 10;
    Set_Fuel_Coef += setbcd[i];
   }
   ESSetData[0].byte = index + ((((((((0 + (1*7)) + (1*4))+(1*4))+(1*3))+(1*3))+(1*3))+(1*3))+(1*3));
   ESSetData[21].bit.bs0 = setbcd[0];
   ESSetData[21].bit.bs1 = setbcd[1];
   ESSetData[22].bit.bs0 = setbcd[2];

   SendESSetDataToGPU();
   sendflag = 0;
  }
  return 0;
 }





 static u8 ChangeRanYou(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;

   u32tostr(Set_Ranyou_Alarm, setbcd, 1, 3);
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
    setbcd[index] ++;
    setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
    sendflag = 1;
    break;
   case IN_KEY3_SP:
    setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
    setbcd[index] --;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 2)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;
   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;
   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   Set_Ranyou_Alarm = 0;
   for(i = 0; i < 3; i++)
   {
    Set_Ranyou_Alarm *= 10;
    Set_Ranyou_Alarm += setbcd[i];
   }

   ESSetData[0].byte = index + (((((((((0 + (1*7)) + (1*4))+(1*4))+(1*3))+(1*3))+(1*3))+(1*3))+(1*3))+(1*3));
   ESSetData[19].bit.bs1 = setbcd[0];
   ESSetData[20].bit.bs0 = setbcd[1];
   ESSetData[20].bit.bs1 = setbcd[2];
   SendESSetDataToGPU();
   sendflag = 0;

  }
  return 0;
 }




 static u8 ChangeVideoAv1(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
   case IN_KEY3_SP:
    Art.bit.b8 ^= 1;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 0)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;
   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;
   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   ESSetData[0].byte = index + ((((((((((0 + (1*7)) + (1*4))+(1*4))+(1*3))+(1*3))+(1*3))+(1*3))+(1*3))+(1*3))+(1*3));
   ESSetData[22].byte &= (~(1 << 4));
   ESSetData[22].byte |= Art.bit.b8 << 4;
   SendESSetDataToGPU();
   sendflag = 0;
  }

  return 0;
 }



 static u8 ChangeVideoAv2(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
   case IN_KEY3_SP:
    Art.bit.b9 ^= 1;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 0)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;
   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;
   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   ESSetData[0].byte = index + (((((((((((0 + (1*7)) + (1*4))+(1*4))+(1*3))+(1*3))+(1*3))+(1*3))+(1*3))+(1*3))+(1*3))+(1));
   ESSetData[22].byte &= (~(1 << 5));
   ESSetData[22].byte |= Art.bit.b9 << 5;
   SendESSetDataToGPU();
   sendflag = 0;
  }

  return 0;
 }



 static u8 ChangeVideoAv3(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
   case IN_KEY3_SP:
    Art.bit.b10 ^= 1;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 0)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;
   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;
   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   ESSetData[0].byte = index + ((((((((((((0 + (1*7)) + (1*4))+(1*4))+(1*3))+(1*3))+(1*3))+(1*3))+(1*3))+(1*3))+(1*3))+(1))+(1));
   ESSetData[22].byte &= (~(1 << 6));
   ESSetData[22].byte |= Art.bit.b10 << 6;
   SendESSetDataToGPU();
   sendflag = 0;
  }

  return 0;
 }


 static u8 ChangeVideoAv4(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
   case IN_KEY3_SP:
    Art.bit.b11 ^= 1;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    if(index > 0)
    {
     index = 0;
     initflag = 1;
     return 1;
    }
    sendflag = 1;
    break;
   case IN_KEY1_CP:
    index = 0;
    initflag = 1;
    return 1;
   case IN_KEY4_SP:
    {
     initflag = 1;
    }
    return 0;
   default:
    break;
  }

  if(sendflag == 1)
  {
   ESSetData[0].byte = index + (((((((((((((0 + (1*7)) + (1*4))+(1*4))+(1*3))+(1*3))+(1*3))+(1*3))+(1*3))+(1*3))+(1*3))+(1))+(1))+(1));
   ESSetData[22].byte &= (~(1 << 7));
   ESSetData[22].byte |= Art.bit.b11 << 7;
   SendESSetDataToGPU();
   sendflag = 0;
  }

  return 0;
 }





 static s16 CheckPassword(u8 key, u8 initpw)
 {
  static u8 index = 0;
  static u8 initflag = 1;
  static u8 setbcd[10] = {0};
  u8 i;

  u8 sendflag = 0;

  if(initpw)
  {
   initflag = 1;
  }

  if(initflag)
  {
   initflag = 0;
   set_password = 0;
   u32tostr(set_password, setbcd, 1, 4);
   index = 0;
   sendflag = 1;
  }

  switch(key)
  {
   case IN_KEY2_SP:
    setbcd[index] ++;
    setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
    sendflag = 1;
    break;
   case IN_KEY3_SP:
    setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
    setbcd[index] --;
    sendflag = 1;
    break;
   case IN_KEY1_SP:
    index ++;
    index = (index > 3 ? 0 : index);
    sendflag = 1;
    break;
   case IN_KEY4_SP:
    {
     initflag = 1;

     for(i = 1; i < 12; i++)
     {
      Send_To_DP_Data[i] = 0;
     }

     Send_To_DP_Data[0] = 4;
     Send_To_DP_Data[1] = 1;
     Send_To_DP_Data[2] = 1;
     Send_To_DP_Data[3] = 0;
     Send_To_DP_Data[4] = 0;
     Send_To_DP_Data[5] = 0;
     Send_To_DP_Data[6] = 0;
     Send_To_DP_Data[7] = 0;

     fifo_in(&SendBuff);

     if(set_password == password)
     {
      return 1;
     }
     else
     {
      return -1;
     }
    }
   default:
    break;
  }

  if(sendflag == 1)
  {
   set_password = 0;
   for(i = 0; i < 4; i++)
   {
    set_password *= 10;
    set_password += setbcd[i];
   }

   for(i = 1; i < 12; i++)
   {
    Send_To_DP_Data[i] = 0;
   }

   Send_To_DP_Data[0] = 4;
   Send_To_DP_Data[1] = 1;
   Send_To_DP_Data[2] = 1;
   Send_To_DP_Data[3] = index;
   Send_To_DP_Data[4] = setbcd[0];
   Send_To_DP_Data[5] = setbcd[1];
   Send_To_DP_Data[6] = setbcd[2];
   Send_To_DP_Data[7] = setbcd[3];

   fifo_in(&SendBuff);
   sendflag = 0;
  }

  return 0;
 }

 enum
 {

  LiChengIndex,


  SubiIndex,


  PulseIndex,


  CoefIndex,


  AirCoefIndex,


  HSValueIndex,


  AirAlarmIndex,


  OilAlarmIndex,


  FuelCoefIndex,



  RanYouIndex,



  VideoAv1Index,


  VideoAv2Index,


  VideoAv3Index,


  VideoAv4Index,


  EncryptSystemSetLast
 };




 void SaveChangeEncrypt()
 {
  uint32_t address = 0x800000;
  u8 i = 0, k;
  if((Set_odometer_const != odometer_const) || (Veh_odo != Set_Veh_odo) || (Set_Pulse != Pulse) || (Set_Coef != Coef) ||
  (Set_Air2_Coef != Air2_Coef)|| (Set_Air_Coef != Air_Coef) || (Set_Fuel_Coef != Fuel_Coef) || (Set_Speed_Alarm != Speed_Alarm) || (Set_Air_Alarm != Air_Alarm) ||
    (Set_Oil_Alarm != Oil_Alarm) || (Set_Ranyou_Alarm != Ranyou_Alarm) || (Art.bit.b8 != Art.bit.b3) ||
    (Art.bit.b9 != Art.bit.b4) || (Art.bit.b10 != Art.bit.b5) || (Art.bit.b11 != Art.bit.b6))
  {
      if(Veh_odo != Set_Veh_odo)
      {
            Veh_odo = Set_Veh_odo;

   EEflag.bit.b0 = 1;
   }


   odometer_const = Set_odometer_const;
   Pulse = Set_Pulse;
   Coef = Set_Coef;
   Speed_Alarm = Set_Speed_Alarm;
   Air_Coef = Set_Air_Coef;
   Air2_Coef = Set_Air2_Coef;
   Air_Alarm = Set_Air_Alarm;
   Oil_Alarm = Set_Oil_Alarm;
   Fuel_Coef = Set_Fuel_Coef;
   Ranyou_Alarm = Set_Ranyou_Alarm;
   Art.bit.b3 = Art.bit.b8;
   Art.bit.b5 = Art.bit.b9;
   Art.bit.b4 = Art.bit.b10;
   Art.bit.b6 = Art.bit.b11;



   EEflag.bit.b1 = 1;
  }


 }


 void display_total_miles(u8 initw);
 u32 EncryptSystemSet(u8 key, u8 initpw)
 {
  static u32 flag = 0;
  static u32 flag1 = 0;

  static u8 initflag = 0;
  static u8 LastEncryptSystemSetPage = EncryptSystemSetLast;
  static u8 reinitflag = 0;


  if(initpw)
  {
   SendKeyToGPU(CMD_DIS_PAGE);
   flag = 0;

   LastEncryptSystemSetPage = flag1;
   flag1 = 0;
   reinitflag = 1;
  }

  if((LastEncryptSystemSetPage == flag1) && reinitflag)
  {
   initflag = 1;
   reinitflag = 0;
  }

  switch(flag)
  {
   case 0:
    {
     int32_t f = CheckPassword(key, initpw);
     if(f == 1)
     {
      u8 setbcd[8];
      flag = 1;

      Set_Veh_odo = Veh_odo;
      Set_odometer_const = odometer_const;
      Set_Pulse = Pulse;
      Set_Coef = Coef;
      Set_Speed_Alarm = Speed_Alarm;
      Set_Air_Coef = Air_Coef;

      Set_Air_Alarm = Air_Alarm;
      Set_Oil_Alarm = Oil_Alarm;
      Set_Fuel_Coef = Fuel_Coef;
      Set_Ranyou_Alarm = Ranyou_Alarm;
      Art.bit.b8 = Art.bit.b3;
      Art.bit.b9 = Art.bit.b5;
      Art.bit.b10 = Art.bit.b4;
      Art.bit.b11 = Art.bit.b6;


      ESSetData[0].byte = 0;
      u32tostr(Set_Veh_odo, setbcd, 1, 7);
      ESSetData[1].byte = setbcd[0];
      ESSetData[2].byte = setbcd[1];
      ESSetData[3].byte = setbcd[2];
      ESSetData[4].byte = setbcd[3];
      ESSetData[5].byte = setbcd[4];
      ESSetData[6].byte = setbcd[5];
      ESSetData[7].byte = setbcd[6];

      u32tostr(Set_odometer_const, setbcd, 1, 4);
      ESSetData[8].bit.bs0 = setbcd[0];
      ESSetData[8].bit.bs1 = setbcd[1];
      ESSetData[9].bit.bs0 = setbcd[2];
      ESSetData[9].bit.bs1 = setbcd[3];

      u32tostr(Set_Pulse, setbcd, 1, 4);
      ESSetData[10].bit.bs0 = setbcd[0];
      ESSetData[10].bit.bs1 = setbcd[1];
      ESSetData[11].bit.bs0 = setbcd[2];
      ESSetData[11].bit.bs1 = setbcd[3];

      u32tostr(Set_Coef, setbcd, 1, 3);
      ESSetData[12].bit.bs0 = setbcd[0];
      ESSetData[12].bit.bs1 = setbcd[1];
      ESSetData[13].bit.bs0 = setbcd[2];

      u32tostr(Set_Air_Coef, setbcd, 1, 3);
      ESSetData[13].bit.bs1 = setbcd[0];
      ESSetData[14].bit.bs0 = setbcd[1];
      ESSetData[14].bit.bs1 = setbcd[2];

      u32tostr(Set_Speed_Alarm, setbcd, 1, 3);
      ESSetData[15].bit.bs0 = setbcd[0];
      ESSetData[15].bit.bs1 = setbcd[1];
      ESSetData[16].bit.bs0 = setbcd[2];

      u32tostr(Set_Air_Alarm, setbcd, 1, 3);
      ESSetData[16].bit.bs1 = setbcd[0];
      ESSetData[17].bit.bs0 = setbcd[1];
      ESSetData[17].bit.bs1 = setbcd[2];

      u32tostr(Set_Oil_Alarm, setbcd, 1, 3);
      ESSetData[18].bit.bs0 = setbcd[0];
      ESSetData[18].bit.bs1 = setbcd[1];
      ESSetData[19].bit.bs0 = setbcd[2];

      u32tostr(Set_Ranyou_Alarm, setbcd, 1, 3);
      ESSetData[19].bit.bs1 = setbcd[0];
      ESSetData[20].bit.bs0 = setbcd[1];
      ESSetData[20].bit.bs1 = setbcd[2];

      u32tostr(Set_Fuel_Coef, setbcd, 1, 3);
      ESSetData[21].bit.bs0 = setbcd[0];
      ESSetData[21].bit.bs1 = setbcd[1];
      ESSetData[22].bit.bs0 = setbcd[2];

      ESSetData[22].byte |= (u8)Art.bit.b8 << 4;
      ESSetData[22].byte |= (u8)Art.bit.b9 << 5;
      ESSetData[22].byte |= (u8)Art.bit.b10 << 6;
      ESSetData[22].byte |= (u8)Art.bit.b11 << 7;


      SendESSetDataToGPU();
      ChangeToSubPage(DIS_SYSTEM_SET_MENU, PAGE_ARTSET_MILESET);
     }
     else if(f == -1)
     {
      ChangeToSubPage(DIS_SYSTEM_SET_MENU, PAGE_ARTSET_PASSWORD);
      return DIS_CHOOSE_MENU;
     }
    }
    break;
   case 1:
    switch(flag1)
    {

     case LiChengIndex:
      flag1 += ChangeLicheng(key, initflag);
      initflag = 0;
      break;


     case SubiIndex:
      flag1 += ChangeSubi(key, initflag);
      initflag = 0;
      break;


     case PulseIndex:
      flag1 += ChangePulse(key, initflag);
      initflag = 0;
      break;


     case CoefIndex:
      flag1 += ChangeCoef(key, initflag);
      initflag = 0;
      break;



     case AirCoefIndex:
      flag1 += ChangeAirCoef(key, initflag);
      initflag = 0;
      break;



     case HSValueIndex:
      flag1 += ChangeHSValue(key, initflag);
      initflag = 0;
      break;


     case AirAlarmIndex:
      flag1 += ChangeAirAlarm(key, initflag);
      initflag = 0;
      break;


     case OilAlarmIndex:
      flag1 += ChangeOilAlarm(key, initflag);
      initflag = 0;
      break;


     case FuelCoefIndex:
      flag1 += ChangeFuelCoef(key, initflag);
      initflag = 0;
      break;


     case RanYouIndex:
      flag1 += ChangeRanYou(key, initflag);
      initflag = 0;
      break;


     case VideoAv1Index:
      flag1 += ChangeVideoAv1(key, initflag);
      initflag = 0;
      break;


     case VideoAv2Index:
      flag1 += ChangeVideoAv2(key, initflag);
      initflag = 0;
      break;


     case VideoAv3Index:
      flag1 += ChangeVideoAv3(key, initflag);
      initflag = 0;
      break;


     case VideoAv4Index:
      flag1 += ChangeVideoAv4(key, initflag);
      initflag = 0;
      break;


    }

    flag1 = (flag1 >= EncryptSystemSetLast ? 0 : flag1);
    if(key == IN_KEY4_SP)
    {
     SaveChangeEncrypt();
     ChangeToSubPage(DIS_SYSTEM_SET_MENU, PAGE_ARTSET_PASSWORD);
     flag = 0;
     return DIS_CHOOSE_MENU;
    }
    break;

  }

  return DIS_SYSTEM_SET_MENU;
 }




 static inline u8 getVideo()
 {
  if((0 && 1 && (Art.bit.b3)))
  {
   return 1;
  }
  if((0))
  {
   return 2;
  }
  if((0 && 1 && (Art.bit.b5)))
  {
   return 3;
  }
  if((0 && 1 && (Art.bit.b4)))
  {
   return 4;
  }
  return 0;
 }

 u8 VedioCheck(u8 key)
 {
  static u8 video_status = 0;
  static u8 video = 0;
  static u8 video_bak = 0xFF;

  if(port_a.bit.b7 == 0)
  {
   if(video > 0)
   {
    video_bak = 0xFF;
    video = 0;
    goto ChangVideo;
   }
   else
   {
    return key;
   }
  }

  video_status = getVideo();
  if(video_status != video_bak)
  {
   video_bak = video_status;
   video = video_status;
   goto ChangVideo;
  }

  if(key == IN_KEY4_CP)
  {
   if(video < 4)
   {
    video ++;
   }
   else
   {
    video = 0;
   }
   goto ChangVideo;
  }

  if(video > 0)
  {
   return IN_KEY_NONE;
  }
  else
  {
   return key;
  }

 ChangVideo:

  video = video > 4 ? 4 : video;
  ChangeToSubPage(DIS_VEDIO, video);
  return IN_KEY_NONE;
 }




 void ReInitDisplay(void)
 {
  u8 i;
  VedioManual = 0;
  initflag = 1;
  choose_menu = 0;

  dis_mod = DIS_MAIN_MENU;
 }



 void display_task(void)
 {
  u8 i, key;
  static u8 vedio_time;
  static u8 lastmode = DIS_MAIN_MENU;


  key = message_get(MSG_FIFO_KEY);

  key = VedioCheck(key);


  for(i = 0; i < 25; i++)
  {
   if((disp[i].operate != 0) && (disp[i].id == dis_mod))
   {
    lastmode = dis_mod;
    dis_mod = (*disp[i].operate)(key, initflag);
    initflag = 0;
    if(dis_mod != lastmode)
    {
     initflag = 1;
    }
    break;
   }
  }

  if(i == 25)
  {
   dis_mod = DIS_CHOOSE_MENU;
  }


  if(ReInitDisplayFlag)
  {
   ReInitDisplayFlag = 0;
   ReInitDisplay();
   i = 0;
   lastmode = DIS_MAIN_MENU;
  }

 }

 void InitDispStru(void)
 {
  u8 i = 0;
  for(i = 0; i < 25; i++)
  {
   disp[i].operate = 0;
  }
 }
 void AddMenu(u32(*operate)(u8 key, u8 initpw), u32 id)
 {
  DisMenuStruct *p;
  if(MenuNum >= 25)
  {
   return ;
  }
  p = &disp[MenuNum++];
  p->id = id;
  p->operate = operate;
 }

 void InitDisplayHelper(void)
 {
  SendKeyToGPU(CMD_DIS_MAIN);
  InitNoEncryptSetVar();

  InitDispStru();


  AddMenu(MainMesg, DIS_MAIN_MENU);


  AddMenu(NoEncryptSystemSet, DIS_FACTORY_SET_MENU);
  AddMenu(EncryptSystemSet, DIS_SYSTEM_SET_MENU);
  AddMenu(ArtMesg, DIS_ART_INFORMATION);

  AddMenu(MenuMesg, DIS_CHOOSE_MENU);
 }
# 3123 "../source/displayhelper.c"
 void Send_Time_ToDis(u8 initpw)
 {
  u8 i; u8 change = 0; static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; for(i = 1; i < 12; i++) Send_To_DP_Data[i] = 0;;

  Send_To_DP_Data[0] = 0x80;
  Send_To_DP_Data[1] = 01;
  Send_To_DP_Data[2] = 2;

  Send_To_DP_Data[3] = rtc.year;
  Send_To_DP_Data[4] = rtc.month;
  Send_To_DP_Data[5] = rtc.day;
  Send_To_DP_Data[6] = rtc.hours;
  Send_To_DP_Data[7] = rtc.mins;
  Send_To_DP_Data[8] = rtc.secs;
  Send_To_DP_Data[9] = Veh_trip;
  Send_To_DP_Data[10] = Veh_trip >> 8;

  for(i=3; i<11; i++) { if(data1save[i] != Send_To_DP_Data[i]) { data1save[i] = Send_To_DP_Data[i]; change ++; } } if((change>0) ||(initpw)) { fifo_in(&SendBuff); };
 }


 void Send_Symbol_ToDis(u8 initpw)
 {
  u8 i; u8 change = 0; static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; for(i = 1; i < 12; i++) Send_To_DP_Data[i] = 0;;

  Send_To_DP_Data[0] = 0x80;
  Send_To_DP_Data[1] = 1;
  Send_To_DP_Data[2] = 3;

  Send_To_DP_Data[3] = led[0].byte;
  Send_To_DP_Data[4] = led[1].byte;
  Send_To_DP_Data[5] = led[2].byte;
  Send_To_DP_Data[6] = led[3].byte;
  Send_To_DP_Data[7] = led[4].byte;
  Send_To_DP_Data[8] = led[5].byte;
  Send_To_DP_Data[9] = led[6].byte;
  Send_To_DP_Data[10] = led[7].byte;

  for(i=3; i<11; i++) { if(data1save[i] != Send_To_DP_Data[i]) { data1save[i] = Send_To_DP_Data[i]; change ++; } } if((change>0) ||(initpw)) { fifo_in(&SendBuff); };
 }

 void Send_Guide_ToDis1(u8 initpw)
 {
  u8 i; u8 change = 0; static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; for(i = 1; i < 12; i++) Send_To_DP_Data[i] = 0;;

  Send_To_DP_Data[0] = 0x80;
  Send_To_DP_Data[1] = 2;
  Send_To_DP_Data[2] = 1;

  Send_To_DP_Data[3] = veh_speed_display;
  Send_To_DP_Data[4] = veh_speed_display >> 8;
  Send_To_DP_Data[5] = eng_speed;
  Send_To_DP_Data[6] = eng_speed >> 8;
  Send_To_DP_Data[7] = veh_bar1;
  Send_To_DP_Data[8] = veh_bar2;
  Send_To_DP_Data[9] = (Vbat >> 1);
   Send_To_DP_Data[10] = veh_soc;
  for(i=3; i<11; i++) { if(data1save[i] != Send_To_DP_Data[i]) { data1save[i] = Send_To_DP_Data[i]; change ++; } } if((change>0) ||(initpw)) { fifo_in(&SendBuff); };
 }

 void Send_Guide_ToDis2(u8 initpw)
 {
   u16 u16_data;
  static u8 soc_count = 0;
  u8 i; u8 change = 0; static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}; for(i = 1; i < 12; i++) Send_To_DP_Data[i] = 0;;

  Send_To_DP_Data[0] = 0x80;
  Send_To_DP_Data[1] = 2;
  Send_To_DP_Data[2] = 2;

   soc_count++;
  if((soc_count >= 100) || (soc_count < veh_soc))
   soc_count = veh_soc;
  Send_To_DP_Data[3] = CanData[Pcan1GetIndexFromID(0x0C04A1A7)][6];
     Send_To_DP_Data[4] = CanData[Pcan1GetIndexFromID(0x0C04A1A7)][7];
  Send_To_DP_Data[5] = 0;
  Send_To_DP_Data[6] = soc_count;
  Send_To_DP_Data[7] = 0;
     Send_To_DP_Data[8] = 0;
     Send_To_DP_Data[9] = 0;
     Send_To_DP_Data[10] = 0;

  for(i=3; i<11; i++) { if(data1save[i] != Send_To_DP_Data[i]) { data1save[i] = Send_To_DP_Data[i]; change ++; } } if((change>0) ||(initpw)) { fifo_in(&SendBuff); };
 }

 void Constant_display_Task()
 {
  static u8 count = 0;
  static u8 temp = 0;
  static u8 count2 = 100;

  Send_Symbol_ToDis(1);
  PushDataToGPU();

  if(count >= 5)
  {
   Send_Time_ToDis(1);
   Send_Guide_ToDis1(1);
   Send_Guide_ToDis2(1);
   count = 0;
  }

  if(dis_mod != DIS_FACTORY_SET_MENU)
  {
   UpdateNoEncryptSetVar();

   if(temp != NoEncryptSetVar[5])
   {
    if(count2 == 0)
    {
     count2 = 10;
    }
    temp = NoEncryptSetVar[5];
   }

   if(count2)
   {
    count2--;
    NoEncryptSetToGPU();
   }
  }

  count++;
 }




 void roll_alarm_Task(void)
 {
  if((port_a.bit.b7 && (Art.bit.b13)) || port_a.bit.b0)
  {
   uint8_t i;
   uint16_t alarm_count = 0xFF;
   static uint16_t x = 0;
   u64 data[4];
   u64 temp;

   for(i = 1; i < 12; i++)
   {
    Send_To_DP_Data[i] = 0;
   }

   Send_To_DP_Data[0] = 0x80;
   Send_To_DP_Data[1] = PAGE_MAIN;
   Send_To_DP_Data[2] = 0x01;

   data[0] = tip_code1.qword;
   data[1] = tip_code2.qword;
   data[2] = tip_code3.qword;
   data[3] = tip_code4.qword;

   for(i = 0; i < (sizeof(data) / sizeof(data[0])); i++)
   {
    if(data[i] != 0)
    {
     break;
    }
   }

   if(i == (sizeof(data) / sizeof(data[0])))
   {
    goto end;
   }

   for(; x < (sizeof(data) * 8); x++)
   {

    if(((data[x >> 6] >> (x & (0x3F))) & 0x01) == 0x01)
    {
     alarm_count = x;
     x++;
     break;
    }

   }

 end:
   Send_To_DP_Data[3] = (u8)(alarm_count + 1);
   Send_To_DP_Data[4] = 0;

   {
    u16 errcode = GetWenziWarnCode(Send_To_DP_Data[3]);
    Send_To_DP_Data[5] = (((errcode)>>0)&0xFF);
    Send_To_DP_Data[6] = (((errcode)>>8)&0xFF);
   }

   Send_To_DP_Data[7] = Veh_odo;
   Send_To_DP_Data[8] = Veh_odo >> 8;
   Send_To_DP_Data[9] = Veh_odo >> 16;
   Send_To_DP_Data[10] = Veh_odo >> 24;

   fifo_in(&SendBuff);

   if(alarm_count == 0xFF)
   {
    x = 0;
   }
  }
 }