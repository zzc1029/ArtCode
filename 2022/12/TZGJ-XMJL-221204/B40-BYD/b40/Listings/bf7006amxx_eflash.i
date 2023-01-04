# 1 "RTE\\Device\\BF7006AM64\\BF7006AMxx_eflash.c"



 







 

# 1 "RTE\\Device\\BF7006AM64\\BF7006AMxx_eflash.h"



 







 




# 1 ".\\RTE\\CMSIS\\BF7006AM64\\BF7006AMxx.h"



 





 








typedef enum {FALSE = 0, TRUE = !FALSE} bool;



typedef enum {RESET = 0U, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0U, ENABLE = !DISABLE} FunctionalState;


typedef enum {ERROR = 0U, SUCCESS = !ERROR} ErrorStatus;


    
typedef unsigned char           UINT8;               
typedef unsigned short          UINT16;              
typedef unsigned int            UINT32;              
typedef signed char             INT8;                
typedef short                   INT16;               
typedef signed int              INT32;               
typedef void(*pt2Func)(void);                        
typedef void(*pt2FuncU8)(UINT8);                     
typedef void(*pt2FuncU32)(UINT32);                   
typedef void(*pt2FuncU32U8)(UINT32,UINT8);           
    
 










 
typedef enum IRQn
{
 
  NonMaskableInt_IRQn           = -14,       
  HardFault_IRQn                = -13,       
  SVCall_IRQn                   =  -5,       
  PendSV_IRQn                   =  -2,       
  SysTick_IRQn                  =  -1,       

 
  RESERVED0                     =   0,       
  SYS_IRQn                      =   1,       
  RESERVED1                     =   2,       
  RESERVED2                     =   3,       
  LVDT_IRQn                     =   4,       
  PWM_CH0_IRQn                  =   5,       
  PWM_CH1_IRQn                  =   6,       
  PWM_CH2_IRQn                  =   7,       
  PWM_CH3_IRQn                  =   8,       
  PWM_CH4_IRQn                  =   9,       
  PWM_CH5_IRQn                  =  10,       
  PWM_TOF_IRQN                  =  11,       
  RESERVED4                     =  12,       
  RESERVED5                     =  13,       
  RESERVED6                     =  14,       
  RESERVED7                     =  15,       
  SCI0_ERR_IRQn                 =  16,       
  SCI0_RX_IRQn                  =  17,       
  SCI0_TX_IRQn                  =  18,       
  SCI1_ERR_IRQn                 =  19,       
  SCI1_RX_IRQn                  =  20,       
  SCI1_TX_IRQn                  =  21,       
  GPIO_IRQn                     =  22,       
  ADC_IRQn                      =  23,       
  RESERVED8                     =  24,       
  RTC_IRQn                      =  25,       
  CAN_WAKE_IRQn                 =  26,       
  CAN_ERR_IRQn                  =  27,       
  CAN_RX_IRQn                   =  28,       
  CAN_TX_IRQn                   =  29,       
  TIMER0_IRQn                   =  30,       
  TIMER1_IRQn                   =  31,       
} IRQn_Type;

 
 
 

 





# 1 ".\\RTE\\CMSIS\\BF7006AM64\\core_cm0.h"
 




 
















 










# 1 ".\\RTE\\CMSIS\\BF7006AM64\\stdint.h"
 
 





 









     
# 27 ".\\RTE\\CMSIS\\BF7006AM64\\stdint.h"
     











# 46 ".\\RTE\\CMSIS\\BF7006AM64\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
# 216 ".\\RTE\\CMSIS\\BF7006AM64\\stdint.h"

     



     






     
    
 



# 241 ".\\RTE\\CMSIS\\BF7006AM64\\stdint.h"

     







     










     











# 305 ".\\RTE\\CMSIS\\BF7006AM64\\stdint.h"






 
# 35 ".\\RTE\\CMSIS\\BF7006AM64\\core_cm0.h"

















 




 



 

 









 







# 112 ".\\RTE\\CMSIS\\BF7006AM64\\core_cm0.h"

# 1 ".\\RTE\\CMSIS\\BF7006AM64\\cmsis_compiler.h"
 




 
















 




# 29 ".\\RTE\\CMSIS\\BF7006AM64\\cmsis_compiler.h"



 
# 1 ".\\RTE\\CMSIS\\BF7006AM64\\cmsis_armcc.h"
 




 
















 









 













   
   


 
# 82 ".\\RTE\\CMSIS\\BF7006AM64\\cmsis_armcc.h"


 



 





 
 






 
 





 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}






 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}






 
static __inline uint32_t __get_IPSR(void)
{
  register uint32_t __regIPSR          __asm("ipsr");
  return(__regIPSR);
}






 
static __inline uint32_t __get_APSR(void)
{
  register uint32_t __regAPSR          __asm("apsr");
  return(__regAPSR);
}






 
static __inline uint32_t __get_xPSR(void)
{
  register uint32_t __regXPSR          __asm("xpsr");
  return(__regXPSR);
}






 
static __inline uint32_t __get_PSP(void)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  return(__regProcessStackPointer);
}






 
static __inline void __set_PSP(uint32_t topOfProcStack)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  __regProcessStackPointer = topOfProcStack;
}






 
static __inline uint32_t __get_MSP(void)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  return(__regMainStackPointer);
}






 
static __inline void __set_MSP(uint32_t topOfMainStack)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  __regMainStackPointer = topOfMainStack;
}






 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}






 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}


# 318 ".\\RTE\\CMSIS\\BF7006AM64\\cmsis_armcc.h"


# 356 ".\\RTE\\CMSIS\\BF7006AM64\\cmsis_armcc.h"



 


 



 




 






 







 






 








 










 










 











 








 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
  rev16 r0, r0
  bx lr
}








 

__attribute__((section(".revsh_text"))) static __inline __asm int32_t __REVSH(int32_t value)
{
  revsh r0, r0
  bx lr
}









 









 








 




__attribute__((always_inline)) static __inline uint32_t __RBIT(uint32_t value)
{
  uint32_t result;
  int32_t s = (4   * 8) - 1;  

  result = value;                       
  for (value >>= 1U; value; value >>= 1U)
  {
    result <<= 1U;
    result |= value & 1U;
    s--;
  }
  result <<= s;                         
  return(result);
}








 



# 712 ".\\RTE\\CMSIS\\BF7006AM64\\cmsis_armcc.h"

   


 



 

# 794 ".\\RTE\\CMSIS\\BF7006AM64\\cmsis_armcc.h"
 


# 35 ".\\RTE\\CMSIS\\BF7006AM64\\cmsis_compiler.h"




 
# 220 ".\\RTE\\CMSIS\\BF7006AM64\\cmsis_compiler.h"




# 114 ".\\RTE\\CMSIS\\BF7006AM64\\core_cm0.h"

















 
# 148 ".\\RTE\\CMSIS\\BF7006AM64\\core_cm0.h"

 






 
# 164 ".\\RTE\\CMSIS\\BF7006AM64\\core_cm0.h"

 




 










 



 






 



 
typedef union
{
  struct
  {
    uint32_t _reserved0:28;               
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} APSR_Type;

 















 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:23;               
  } b;                                    
  uint32_t w;                             
} IPSR_Type;

 






 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:15;               
    uint32_t T:1;                         
    uint32_t _reserved1:3;                
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} xPSR_Type;

 





















 
typedef union
{
  struct
  {
    uint32_t _reserved0:1;                
    uint32_t SPSEL:1;                     
    uint32_t _reserved1:30;               
  } b;                                    
  uint32_t w;                             
} CONTROL_Type;

 



 







 



 
typedef struct
{
  volatile uint32_t ISER[1U];                
        uint32_t RESERVED0[31U];
  volatile uint32_t ICER[1U];                
        uint32_t RSERVED1[31U];
  volatile uint32_t ISPR[1U];                
        uint32_t RESERVED2[31U];
  volatile uint32_t ICPR[1U];                
        uint32_t RESERVED3[31U];
        uint32_t RESERVED4[64U];
  volatile uint32_t IP[8U];                  
}  NVIC_Type;

 







 



 
typedef struct
{
  volatile const  uint32_t CPUID;                   
  volatile uint32_t ICSR;                    
        uint32_t RESERVED0;
  volatile uint32_t AIRCR;                   
  volatile uint32_t SCR;                     
  volatile uint32_t CCR;                     
        uint32_t RESERVED1;
  volatile uint32_t SHP[2U];                 
  volatile uint32_t SHCSR;                   
} SCB_Type;

 















 



























 















 









 






 



 







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t LOAD;                    
  volatile uint32_t VAL;                     
  volatile const  uint32_t CALIB;                   
} SysTick_Type;

 












 



 



 









 








 
 







 






 







 


 







 

 










 









 


 



 





 


 
 
# 576 ".\\RTE\\CMSIS\\BF7006AM64\\core_cm0.h"
 












 
 










 
static __inline void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetEnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[0U] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_DisableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);
  }
}









 
static __inline uint32_t __NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0U] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}







 
static __inline void __NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
  }
}










 
static __inline void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )]  = ((uint32_t)(((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )]  & ~(0xFFUL << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL))) |
       (((priority << (8U - 2)) & (uint32_t)0xFFUL) << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)));
  }
  else
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] = ((uint32_t)(((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] & ~(0xFFUL << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL))) |
       (((priority << (8U - 2)) & (uint32_t)0xFFUL) << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)));
  }
}










 
static __inline uint32_t __NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[ ( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )] >> ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL) ) & (uint32_t)0xFFUL) >> (8U - 2)));
  }
  else
  {
    return((uint32_t)(((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] >> ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL) ) & (uint32_t)0xFFUL) >> (8U - 2)));
  }
}










 
static __inline void __NVIC_SetVector(IRQn_Type IRQn, uint32_t vector)
{
  uint32_t *vectors = (uint32_t *)0x0U;
  vectors[(int32_t)IRQn + 16] = vector;
}









 
static __inline uint32_t __NVIC_GetVector(IRQn_Type IRQn)
{
  uint32_t *vectors = (uint32_t *)0x0U;
  return vectors[(int32_t)IRQn + 16];
}





 
static __inline void NVIC_SystemReset(void)
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                          
 
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = ((0x5FAUL << 16U) |
                 (1UL << 2U));
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                           

  for(;;)                                                            
  {
    __nop();
  }
}

 


 





 








 
static __inline uint32_t SCB_GetFPUType(void)
{
    return 0U;            
}


 



 





 













 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);                                                    
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = (uint32_t)(ticks - 1UL);                          
  __NVIC_SetPriority (SysTick_IRQn, (1UL << 2) - 1UL);  
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0UL;                                              
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2U) |
                   (1UL << 1U)   |
                   (1UL );                          
  return (0UL);                                                      
}



 










# 110 ".\\RTE\\CMSIS\\BF7006AM64\\BF7006AMxx.h"
# 1 ".\\RTE\\CMSIS\\BF7006AM64\\system_ARMCM0.h"
 








 

























 





# 43 ".\\RTE\\CMSIS\\BF7006AM64\\system_ARMCM0.h"






extern uint32_t SystemCoreClock;      










 
extern void SystemInit (void);









 
extern void SystemCoreClockUpdate (void);





# 111 ".\\RTE\\CMSIS\\BF7006AM64\\BF7006AMxx.h"

 
 
 

 

  #pragma push
  #pragma anon_unions
# 133 ".\\RTE\\CMSIS\\BF7006AM64\\BF7006AMxx.h"





 
static __inline void System_Sleeping(void)
{
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SCR &= (uint32_t)(~(1UL << 2U));
    __wfi();
}




 
static __inline void System_SleepDeep(void)
{
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SCR |= (uint32_t)(1UL << 2U);
    __wfi();
}





 
static __inline void set_MSP(uint32_t topOfMainStack)
{
    __set_MSP(topOfMainStack);
}





 
static __inline void set_PSP(uint32_t topOfProcStack)
{
    __set_PSP(topOfProcStack);
}




 
static __inline void NOP(void)
{
    __nop();
}




 
static __inline void Enable_Irq(void)
{
    __enable_irq();
}




 
static __inline void Disable_Irq(void)
{
    __disable_irq();
}

 
 
 
 






 
# 223 ".\\RTE\\CMSIS\\BF7006AM64\\BF7006AMxx.h"




# 234 ".\\RTE\\CMSIS\\BF7006AM64\\BF7006AMxx.h"




 

  #pragma pop
# 254 ".\\RTE\\CMSIS\\BF7006AM64\\BF7006AMxx.h"





# 18 "RTE\\Device\\BF7006AM64\\BF7006AMxx_eflash.h"
# 1 "RTE\\Device\\BF7006AM64\\BF7006AMxx_wdt.h"



 






 




# 17 "RTE\\Device\\BF7006AM64\\BF7006AMxx_wdt.h"

 




 

 
# 32 "RTE\\Device\\BF7006AM64\\BF7006AMxx_wdt.h"
 

 
 



 



 



 



 



 



 
 
void wdt_clear(void);
 
void wdt_updata(uint16_t wdt_cs);
 
void wdt_config(uint16_t wdt_cs);
 
void wdt_overflow_count(uint16_t wdt_cnt);
 
void wdt_overflow_count_win(uint16_t wdt_cnt);

# 19 "RTE\\Device\\BF7006AM64\\BF7006AMxx_eflash.h"
# 1 "RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"



 







 




# 18 "RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"

 
# 47 "RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"

 
 






 




 




 
# 75 "RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"

 
# 87 "RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"

 
# 99 "RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"

 



 



 
 




 






 





 
# 146 "RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"

 
# 157 "RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"

 



 


 




 



 





 



 
 
void sci1_port_sel(uint8_t port_sel);

 
void system_clk_sel(uint32_t pll_source_sel,uint32_t clk_sel,uint8_t xtal_freq);
 
ErrorStatus xtal_init(void);
 
void xtal_sleepdeep_pd(FunctionalState pd_en);
 
void rc128k_pd(FunctionalState pd_en);
 
void clock_out(uint8_t clk_source);
 
void clock2_out(uint8_t clk2_source);


 
void system_intvector_offset(uint32_t offset_addr);

 
void system_int_cfg(uint8_t int_state,FunctionalState en_state);
 
uint16_t system_intflg_get(void);
 
void system_intflg_clr(uint16_t int_flg);

 
void lvdt_init(FunctionalState lvdt_en,uint8_t lvdt_vol_gear,FunctionalState int_en);
 
void lvdt_enable(void);
 
void lvdt_disable(void);
 
uint8_t lvdt_int_flag_get(void);
 
void lvdt_int_flag_clr(uint8_t int_flag);

 
void bor_init(FunctionalState bor_en,FunctionalState filter_en);
 
void bor_enbale(void);
 
void bor_disable(void);
 
void bor_filter_enbale(void);
 
void bor_filter_disable(void);

 
void reset_filter(FunctionalState filter_en);
 
uint16_t rst_flag_get(void);
 
void rst_flag_clr(uint16_t rst_flag);

 
extern volatile uint8_t xtal_timeout;
# 20 "RTE\\Device\\BF7006AM64\\BF7006AMxx_eflash.h"

 










 

 
 



 



 
 

 

 

 

 


 



     

 

 


 
 

 

 

 

 



     

 

 


 
 
ErrorStatus ecc_enable(void);
 
ErrorStatus ecc_disable(void);

 
 
ErrorStatus flash_sector_erase(uint8_t sector_num,bool is_wait_done);
 
ErrorStatus flash_Nsectors_erase(uint8_t sector_num,uint8_t len);
 
ErrorStatus flash_mass_erase(bool is_wait_done);
 
ErrorStatus flash_prog_word(uint32_t addr,uint32_t data);
 
ErrorStatus flash_prog_Nwords(uint32_t addr,uint32_t data[],uint32_t len);
 
bool is_flash_idle(void);
 
ErrorStatus wait_flash_prog_erae_done(void);
 
ErrorStatus flash_word_get(uint32_t addr,uint32_t *red_dat);
 
ErrorStatus flash_Nwords_get(uint32_t addr,uint32_t *red_dat,uint32_t len);
 
void flash_protect(uint8_t protect_page);

 
 
ErrorStatus eeprom_sector_erase(uint8_t sector_num,bool is_wait_done);
 
ErrorStatus eeprom_Nsectors_erase(uint8_t sector_num,uint8_t len);
 
ErrorStatus eeprom_mass_erase(bool is_wait_done);
 
ErrorStatus eeprom_prog_word(uint32_t addr,uint32_t data);
 
ErrorStatus eeprom_prog_Nwords(uint32_t addr,uint32_t data[],uint32_t len);
 
bool is_eeprom_idle(void);
 
ErrorStatus wait_eeprom_prog_erae_done(void);
 
ErrorStatus eeprom_word_get(uint32_t addr,uint32_t *red_dat);
 
ErrorStatus eeprom_Nwords_get(uint32_t addr,uint32_t *red_dat,uint32_t len);
 
void eeprom_protect(uint8_t protect_page);

# 15 "RTE\\Device\\BF7006AM64\\BF7006AMxx_eflash.c"






 
ErrorStatus ecc_enable(void)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x200U))))) = 0x01U;
    if(((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x200U))))) != 0x01U){
        return ERROR;
    }
    return SUCCESS;
}






 
ErrorStatus ecc_disable(void)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x200U))))) = 0x00U;
    if(((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x200U))))) != 0x00U){
        return ERROR;
    }
    return SUCCESS;
}







 
ErrorStatus flash_sector_erase(uint8_t sector_num,bool is_wait_done)
{
    uint32_t *addr;
    if(sector_num >= 96U){
        return ERROR;
    }
    if(is_flash_idle()){
        addr = (uint32_t *)((uint32_t)sector_num << 10U);
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x00U))))) = 0xaa55U;
        if(is_wait_done){
            ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x04U))))) = 0xa5U;
        }else{
            ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x04U))))) = 0x5aU;
        }
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x08U))))) = 0x55U;
        if(addr != ((void *)0)){
            *addr = 0x00U;
        }
        if(is_wait_done){
            if(wait_flash_prog_erae_done() == ERROR){
                return ERROR;
            }
        }
        return SUCCESS;
    }else{
        return ERROR;
    }
}







 
ErrorStatus flash_Nsectors_erase(uint8_t sector_num,uint8_t len)
{
    while(len != 0U){
        if(flash_sector_erase(sector_num,TRUE) == ERROR){
            return ERROR;
        }
        len --;
        sector_num ++;
        wdt_clear();
    }
    return SUCCESS;
}








 
ErrorStatus flash_mass_erase(bool is_wait_done)
{
    if(is_flash_idle()){
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x00U))))) = 0xaa55U;
        if(is_wait_done){
            ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x04U))))) = 0xa5U;
        }else{
            ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x04U))))) = 0x5aU;
        }
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x08U))))) = 0xaaU;
        if(is_wait_done){
            if(wait_flash_prog_erae_done() == ERROR){
                return ERROR;
            }
        }
        return SUCCESS;
    }else{
        return ERROR;
    }
}







 
ErrorStatus flash_prog_word(uint32_t addr,uint32_t data)
{
    if(addr > (((uint32_t)0x00000000) + 0x17FFFU)){
        return ERROR;
    }
    if(is_flash_idle()){
        addr &= ~0x3U;
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x00U))))) = 0xaa55U;
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x04U))))) = 0xa5U;
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x08U))))) = 0x33U;
        *(uint32_t *)addr = data;
        if(wait_flash_prog_erae_done() == ERROR){
            return ERROR;
        }
        return SUCCESS;
    }else{
        return ERROR;
    }
}








 
ErrorStatus flash_prog_Nwords(uint32_t addr,uint32_t data[],uint32_t len)
{
    uint32_t index = 0x00U;
    while(len != 0U)
    {
        if(flash_prog_word(addr,data[index]) == ERROR){
            return ERROR;
        }
        len --;
        addr += 4U;
        index ++;
        wdt_clear();
    }
    return SUCCESS;
}






 
bool is_flash_idle(void)
{
    if((((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x0cU))))) & 0x01U) != 0x00U){
        return TRUE;
    }else{
        return FALSE;
    }
}





 
ErrorStatus wait_flash_prog_erae_done(void)
{
    uint32_t timeout = 30000U;    
    while(timeout != 0x00U){
        timeout --;
        if(is_flash_idle()){
            return SUCCESS;
        }
    }
    return ERROR;
}







 
ErrorStatus flash_word_get(uint32_t addr,uint32_t *red_dat)
{
    if(is_flash_idle()){
        *red_dat = (*(uint32_t *)(addr & (~0x3U)));
        return SUCCESS;
    }else{
        *red_dat = 0x00U;
        return ERROR;
    }
}








 
ErrorStatus flash_Nwords_get(uint32_t addr,uint32_t *red_dat,uint32_t len)
{
    uint32_t read_addr = addr;
    uint32_t* write_pt = red_dat;
    uint32_t read_temp;
    
    if(addr + 4 * len > (((uint32_t)0x00000000) + 0x17FFFU) + 1){
        return ERROR;
    }
    while(len != 0){
        if(flash_word_get(read_addr,&read_temp) == ERROR){
            return ERROR;
        }
        read_addr += 4;
        *write_pt = read_temp;
        write_pt++;
        len--;
    }
    return SUCCESS;
}






 
void flash_protect(uint8_t protect_page)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x204U))))) = 0xab23dc54U;
    if(protect_page > 48U){
        protect_page = 48U;
    }
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x208U))))) = protect_page;
     
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x10000) + 0x104U))))) |= ((uint32_t)(0x01UL<<((uint8_t)(3))));
    __NVIC_EnableIRQ(SYS_IRQn);
}







 
ErrorStatus eeprom_sector_erase(uint8_t sector_num,bool is_wait_done)
{
    uint32_t *addr;
    if(sector_num >= 32U){
        return ERROR;
    }
    if(is_eeprom_idle()){
        addr = (uint32_t *)(((uint32_t)0x40000000) + (0x40U * sector_num));
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x00U))))) = 0xcd78U;
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x04U))))) = 0x3cU;
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x08U))))) = 0x55U;
        if(addr != ((void *)0)){
            *addr = 0x00U;
        }
        if(is_wait_done){
            if(wait_eeprom_prog_erae_done() == ERROR){
                return ERROR;
            }
        }
        return SUCCESS;
    }else{
        return ERROR;
    }
}







 
ErrorStatus eeprom_Nsectors_erase(uint8_t sector_num,uint8_t len)
{
    while(len != 0U){
        if(eeprom_sector_erase(sector_num,TRUE) == ERROR){
            return ERROR;
        }
        len --;
        sector_num ++;
        wdt_clear();
    }
    return SUCCESS;
}






 
ErrorStatus eeprom_mass_erase(bool is_wait_done)
{
    uint32_t *addr;
    if(is_eeprom_idle()){
        addr = (uint32_t *)((uint32_t)0x40000000);
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x00U))))) = 0xcd78U;
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x04U))))) = 0x3cU;
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x08U))))) = 0xaaU;
        *addr = 0x00U;
        if(is_wait_done){
            if(wait_eeprom_prog_erae_done() == ERROR){
                return ERROR;
            }
        }
        return SUCCESS;
    }else{
        return ERROR;
    }
}







 
ErrorStatus eeprom_prog_word(uint32_t addr,uint32_t data)
{
    if(addr >= (((uint32_t)0x40000000) + 0x7FFU)){
        return ERROR;
    }
    if(is_eeprom_idle()){
        addr &= ~(0x3U);
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x00U))))) = 0xcd78U;
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x04U))))) = 0x3cU;
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x08U))))) = 0x33U;
        *(uint32_t *)addr = data;
        if(wait_eeprom_prog_erae_done() == FALSE){
            return ERROR;
        }
        return SUCCESS;
    }else{
        return ERROR;
    }
    
}








 
ErrorStatus eeprom_prog_Nwords(uint32_t addr,uint32_t data[],uint32_t len)
{
    uint32_t index = 0U;
    while(len != 0U)
    {
        if(eeprom_prog_word(addr,data[index]) == ERROR){
            return ERROR;
        }
        len --;
        addr += 4U;
        index ++;
        wdt_clear();
    }
    return SUCCESS;
}







 
ErrorStatus eeprom_word_get(uint32_t addr,uint32_t *red_dat)
{
    if(is_eeprom_idle()){
        *red_dat = (*(uint32_t *)(addr & (~0x3U)));
        return SUCCESS;
    }else{
        *red_dat = 0x00U;
        return ERROR;
    }
}








 
ErrorStatus eeprom_Nwords_get(uint32_t addr,uint32_t *red_dat,uint32_t len)
{
    uint32_t read_addr = addr;
    uint32_t* write_pt = red_dat;
    uint32_t read_temp;
    
    if((addr + 4 * len > (((uint32_t)0x40000000) + 0x7FFU) + 1) || (addr < ((uint32_t)0x40000000))){
        return ERROR;
    }
    while(len != 0){
        if(eeprom_word_get(read_addr,&read_temp) == ERROR){
            return ERROR;
        }
        read_addr += 4;
        *write_pt = read_temp;
        write_pt++;
        len--;
    }
    return SUCCESS;
}






 
bool is_eeprom_idle(void)
{
    if((((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x10U))))) & 0x01U) == 0x00U){
        return FALSE;
    }else{
        return TRUE;
    }
}






 
ErrorStatus wait_eeprom_prog_erae_done(void)
{
    uint32_t timeout = 0xFFFFFFFFU;
    while(timeout != 0x00U){
        timeout --;
        if(is_eeprom_idle()){
            return SUCCESS;
        }
    }
    return ERROR;
}






 
void eeprom_protect(uint8_t protect_page)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x204U))))) = 0xab23dc54U;
    if(protect_page > 36U){
        protect_page = 36U;
    }
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x00000) + 0x20cU))))) = protect_page;
     
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x10000) + 0x104U))))) |= ((uint32_t)(0x01UL<<((uint8_t)(4))));
    __NVIC_EnableIRQ(SYS_IRQn);
}


