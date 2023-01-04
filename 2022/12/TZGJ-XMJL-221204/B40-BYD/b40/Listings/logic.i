# 1 "src\\logic.c"
# 1 "src\\includes.h"



# 1 ".\\RTE\\Startup\\BF7006AM64\\BF7006AMxx_config.h"



 





 




# 1 ".\\RTE\\_b40\\RTE_Components.h"







 







 


 

 

 

 

 

 

 

 



# 16 ".\\RTE\\Startup\\BF7006AM64\\BF7006AMxx_config.h"
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





# 17 ".\\RTE\\Startup\\BF7006AM64\\BF7006AMxx_config.h"
# 1 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"



 







 




# 18 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"

 
# 47 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"

 
 






 




 




 
# 75 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"

 
# 87 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"

 
# 99 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"

 



 



 
 




 






 





 
# 146 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"

 
# 157 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_sysctrl.h"

 



 


 




 



 





 



 
 
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
# 18 ".\\RTE\\Startup\\BF7006AM64\\BF7006AMxx_config.h"





# 1 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"



 






 



# 16 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 
# 46 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 
# 60 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"
 

 

 
 





 
# 78 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 
# 88 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 
# 98 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 
# 108 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 






 
# 123 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 



 


 




 





 
# 150 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"
 

 
 



 



 



 
# 177 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 












 




 


 


 


 


 


 


 


 
typedef enum
{
	CAN_NOMARL = 0,
	CAN_MODE_LISTEN_ONLY,
	CAN_MODE_SELF_TEST,
	CAN_MODE_SELF_RECEIVE,
}can_work_mode_enum;

 
typedef enum
{
	CAN_BAUD_50K = 0,
	CAN_BAUD_100K,
	CAN_BAUD_125K,
	CAN_BAUD_200K,
	CAN_BAUD_250K,
	CAN_BAUD_400K,
	CAN_BAUD_500K,
	CAN_BAUD_800K,
	CAN_BAUD_1M
}can_baud_enum;

 
typedef enum
{
	CAN_CLK_32M,
	CAN_CLK_16M,
	CAN_CLK_8M
}can_clk_enum;


 
typedef enum
{
	CAN_DOUBLE_FILTER,		 
	CAN_SINGLE_FILTER,		 
}CAN_FILTER_MODE;

 
typedef enum
{
	CAN_STANDARD_FRAME,		 
	CAN_EXTENDED_FRAME,		 
}CAN_FRAME_FORMAT;

 
typedef enum
{
	CAN_DATA_FRAME,			 
	CAN_REMOTE_FRAME,		 
}CAN_FRAME_TYPE;

 
typedef enum
{
	CAN_ALC_ID_BIT0,
	CAN_ALC_ID_BIT1,
	CAN_ALC_ID_BIT2,
	CAN_ALC_ID_BIT3,
	CAN_ALC_ID_BIT4,
	CAN_ALC_ID_BIT5,
	CAN_ALC_ID_BIT6,
	CAN_ALC_ID_BIT7,
	CAN_ALC_ID_BIT8,
	CAN_ALC_ID_BIT9,
	CAN_ALC_ID_BIT10,
	CAN_ALC_SRTR,
	CAN_ALC_IDE,
	CAN_ALC_ID_BIT11,
	CAN_ALC_ID_BIT12,
	CAN_ALC_ID_BIT13,
	CAN_ALC_ID_BIT14,
	CAN_ALC_ID_BIT15,
	CAN_ALC_ID_BIT16,
	CAN_ALC_ID_BIT17,
	CAN_ALC_ID_BIT18,
	CAN_ALC_ID_BIT19,
	CAN_ALC_ID_BIT20,
	CAN_ALC_ID_BIT21,
	CAN_ALC_ID_BIT22,
	CAN_ALC_ID_BIT23,
	CAN_ALC_ID_BIT24,
	CAN_ALC_ID_BIT25,
	CAN_ALC_ID_BIT26,
	CAN_ALC_ID_BIT27,
	CAN_ALC_ID_BIT28,
	CAN_ALC_RTR,
}CAN_ALC_CODE_ENUM;

 
typedef struct
{
	can_work_mode_enum 	working_mode;			 
	uint8_t 			resync_jump_width;		 
	can_clk_enum 		can_clk;				 
	can_baud_enum		can_baud;				 
	uint8_t 			sampling_times;			 
	uint8_t 			error_alarm_count;		 
	uint8_t				int_enable;				 
	uint8_t 			nvic_int_enable;		 
}can_parameter_struct;

 
typedef struct
{
	CAN_FILTER_MODE		filter_mode;			 
	CAN_FRAME_FORMAT	filter_frame;			 
	CAN_FRAME_TYPE		filter_RTR;				 
	FunctionalState		filter_mask_RTR;		 
	 
	uint32_t 			filter_single_id;		 
	uint8_t				filter_data0;			 
	uint8_t 			filter_data1;			 
	uint32_t 			filter_mask_single_id;	 
	uint8_t				filter_mask_data0;		 
	uint8_t				filter_mask_data1;		 
	 
	uint32_t			filter_double_id0;		 
	uint32_t 			filter_double_id1;		 
	uint8_t				filter_data0_std;		 
	uint32_t			filter_mask_double_id0;	 
	uint32_t 			filter_mask_double_id1;	 
	uint8_t 			filter_mask_data0_std;	 

}can_filter_parameter_struct;

 
typedef struct
{
    uint32_t 			sfid;                  
    uint32_t 			efid;                  
    uint8_t 			data[8];               
    CAN_FRAME_FORMAT 	ff;                    
    CAN_FRAME_TYPE 		ft;                    
    uint8_t 			dlen;                  
}can_frame_struct;












 
 
ErrorStatus can_init(can_parameter_struct can_parameter_init,can_filter_parameter_struct can_filter_parameter);
 
ErrorStatus can_receive_message(can_frame_struct *receive_data);
 
ErrorStatus can_transmit_message(can_frame_struct *transmit_data);
 
void can_transmit_request(void);
 
ErrorStatus can_wait_trans(void);
 
uint8_t can_read_frame_error_code(void);
 
uint8_t can_read_arbitration_lost_code(void);
 
void can_transmit_abort(void);
 
void can_sleep_config(uint8_t wakeup_mode,uint8_t filter_en,FunctionalState state);
 
ErrorStatus can_sleep_request(void);
 
void can_wait_transmit_frame(can_frame_struct *transmit_data);
 
uint8_t can_get_fifo_num(void);
 
uint8_t can_get_txerrcnt(void);
 
uint8_t can_get_rxerrcnt(void);
 
void can_module_rst(void);
 
void can_clock_sel(uint8_t can_clock);
 
bool is_can_txbuf_empty(void);

 
 
void can_int_enable(uint8_t intstate);
 
void can_int_disable(uint8_t intstate);
 
uint8_t can_interrupt_flag_get(void);
 
void can_int_flag_clr(uint8_t int_flag);
 
uint8_t can_status_get(void);

# 25 ".\\RTE\\Startup\\BF7006AM64\\BF7006AMxx_config.h"


# 1 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.h"



 





 




# 16 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.h"

 
# 56 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.h"
 

 
 






 
# 75 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.h"

 




 
# 106 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.h"

 





 


 

 
 



 
# 132 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.h"

 



 




 




 
# 154 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.h"

 
typedef enum
{
    ADC_COMPARE_0,
    ADC_COMPARE_1
}adc_compare_n;

 
typedef struct
{
    uint8_t             trigger_mode;            
    uint8_t             trigger_source;          
    uint16_t            pwm_trigger_delay;       
}adc_trigger_struct;

 
typedef struct
{
    FunctionalState     compare_en;              
    uint8_t             compare_condition;       
    uint16_t            lower_limit_val;         
    uint16_t            higher_limit_val;        
}adc_compare_struct;

 
typedef struct
{
    uint8_t             adc_clk;                 
    uint16_t            sample_clk_num;          
    FunctionalState     adco_en;                 
    uint8_t             data_width;              
    uint32_t            channel_en;              
    FunctionalState     int_en;                  
    adc_trigger_struct  trigger;                 
    adc_compare_struct  compare;                 
    adc_compare_struct  compare_0;               
    adc_compare_struct  compare_1;               
}adc_parameter_struct;

 
 
void adc_init(adc_parameter_struct adc_init_para);
 
void adc_channel_enable(uint32_t ch);
 
void adc_channel_disable(uint32_t ch);
 
void adc_start_convert(uint8_t ch);
 
uint16_t adc_data_get(void);
 
ErrorStatus wait_adc_convert(void);
 
void adc_interrupt_set(FunctionalState en);
 
void adc_powerdown(FunctionalState en);
 
void adc_compare_config(adc_compare_struct adc_compare);
 
void adc_trigger_config(adc_trigger_struct adc_trigger);
# 29 ".\\RTE\\Startup\\BF7006AM64\\BF7006AMxx_config.h"


# 1 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_eflash.h"



 







 




# 18 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_eflash.h"
# 1 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_wdt.h"



 






 




# 17 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_wdt.h"

 




 

 
# 32 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_wdt.h"
 

 
 



 



 



 



 



 



 
 
void wdt_clear(void);
 
void wdt_updata(uint16_t wdt_cs);
 
void wdt_config(uint16_t wdt_cs);
 
void wdt_overflow_count(uint16_t wdt_cnt);
 
void wdt_overflow_count_win(uint16_t wdt_cnt);

# 19 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_eflash.h"
# 20 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_eflash.h"

 










 

 
 



 



 
 

 

 

 

 


 



     

 

 


 
 

 

 

 

 



     

 

 


 
 
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

# 33 ".\\RTE\\Startup\\BF7006AM64\\BF7006AMxx_config.h"


# 37 ".\\RTE\\Startup\\BF7006AM64\\BF7006AMxx_config.h"


# 1 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_timer.h"



 






 




# 17 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_timer.h"

 



 

 
# 32 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_timer.h"
 

 
 



 






 



 



 
 
void timer_init(uint32_t timerx,uint8_t timer_cfg,uint16_t timer_mod);
 
void timer_enable(uint32_t timerx);
 
void timer_disable(uint32_t timerx);
 
void timer_mod_set(uint32_t timerx,uint16_t count);
 
uint16_t timer_cnt_get(uint32_t timerx);

 
void timer_intflag_clr(uint32_t timerx);
 
FlagStatus timer_intflag_get(uint32_t timerx);

# 41 ".\\RTE\\Startup\\BF7006AM64\\BF7006AMxx_config.h"


# 1 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_rtc.h"



 






 




# 17 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_rtc.h"
# 18 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_rtc.h"

 



 

 





 

 
 



 	




 



 
 
void rtc_init(uint16_t rtc_sc,uint32_t rtc_mod);
 
void rtc_mod_set(uint16_t rtc_mod);
 
uint16_t rtc_cnt_get(void);
 
void rtc_enable(void);
 
void rtc_disable(void);
 
void rtc_int_enable(void);
 
void rtc_int_disable(void);
 
FlagStatus rtc_int_flag_get(void);
 
void rtc_int_flag_clr(void);
 
void rtc_clk_sel(uint8_t clk_sel);

# 45 ".\\RTE\\Startup\\BF7006AM64\\BF7006AMxx_config.h"


# 1 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_pwm.h"



 








 




# 19 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_pwm.h"

 
# 37 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_pwm.h"
 

 
 
# 48 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_pwm.h"

 
# 56 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_pwm.h"
 

 
 



 



 




 
# 81 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_pwm.h"

 



 


 


 
 
void pwm_init(uint8_t pwm_sc,uint16_t pwm_mod);
 
void pwm_mod_set(uint16_t mod_count);
 
uint16_t pwm_get_count(void);
 
void pwm_tof_clr(void);

 
void pwm_ch0_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt);
 
void pwm_ch0_cnt_set(uint16_t count);
 
uint16_t pwm_ch0_get_count(void);
 
void pwm_ch0_if_clr(void);

 
void pwm_ch1_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt);
 
void pwm_ch1_cnt_set(uint16_t count);
 
uint16_t pwm_ch1_get_count(void);
 
void pwm_ch1_if_clr(void);

 
void pwm_ch2_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt);
 
void pwm_ch2_cnt_set(uint16_t count);
 
uint16_t pwm_ch2_get_count(void);
 
void pwm_ch2_if_clr(void);

 
void pwm_ch3_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt);
 
void pwm_ch3_cnt_set(uint16_t count);
 
uint16_t pwm_ch3_get_count(void);
 
void pwm_ch3_if_clr(void);

 
void pwm_ch4_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt);
 
void pwm_ch4_cnt_set(uint16_t count);
 
uint16_t pwm_ch4_get_count(void);
 
void pwm_ch4_if_clr(void);

 
void pwm_ch5_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt);
 
void pwm_ch5_cnt_set(uint16_t count);
 
uint16_t pwm_ch5_get_count(void);
 
void pwm_ch5_if_clr(void);


# 49 ".\\RTE\\Startup\\BF7006AM64\\BF7006AMxx_config.h"


# 1 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"



 






 




# 17 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 29 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 

 
# 41 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 51 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 61 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 





 
# 77 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 87 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 97 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 107 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 117 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 125 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 136 ".\\RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
typedef enum
{
	GPIO_MODE_IN_FLOATING,											 
	GPIO_MODE_IPU,													 
	GPIO_MODE_OUT,													 
}GPIO_MODE;


 
typedef enum
{
	GPIO_TRG_HIGH,													 
	GPIO_TRG_LOW,													 
	GPIO_TRG_RISING,												 		
	GPIO_TRG_FALLING,												 	
}GPIO_TRG_MODE;

 





 
 
void gpio_init(uint32_t gpio_periph,GPIO_MODE mode,uint8_t pin);
 
void gpio_bit_set(uint32_t gpio_periph,uint8_t pin);
 
void gpio_bit_reset(uint32_t gpio_periph,uint8_t pin);
 
void gpio_bit_write(uint32_t gpio_periph,uint8_t pin,FlagStatus bit_value);
 
void gpio_port_write(uint32_t gpio_periph,uint8_t data);
 
FlagStatus gpio_bit_get(uint32_t gpio_periph,uint8_t pin);
 
uint8_t gpio_port_get(uint32_t gpio_periph);
 
void gpio_toggle(uint32_t gpio_periph,uint8_t pin);
 
ErrorStatus gpio_trigge_mode(uint32_t gpio_periph,GPIO_TRG_MODE trg_mode,uint8_t pin);
 
void gpio_interrupt_set(uint32_t gpio_periph,uint8_t pin,FunctionalState value);
 
uint8_t get_gpio_port_interrupt_state(uint32_t gpio_periph);
 
FlagStatus get_gpio_interrupt_state(uint32_t gpio_periph,uint8_t pin);
 
void clr_gpio_interrupt_state(uint32_t gpio_periph,uint8_t pin);
 
void nmi_init(uint8_t trigg_mode,FunctionalState state);
 
void clr_nmi_interrupt_flag(void);
# 53 ".\\RTE\\Startup\\BF7006AM64\\BF7006AMxx_config.h"


 
void peripherals_config(void);

 
void adc_config(void);
void sci_config(void);
void can_config(void);
void timer_config(void);
void pwm_config(void);
void wdt_cfg(void);
void rtc_config(void);
void gpio_config(void);

# 5 "src\\includes.h"
# 1 ".\\RTE\\SEGGER\\SEGGER_RTT.h"























































 




# 1 ".\\RTE\\SEGGER\\SEGGER_RTT_Conf.h"























































 














 



























































 
































 
# 251 ".\\RTE\\SEGGER\\SEGGER_RTT_Conf.h"




 
# 306 ".\\RTE\\SEGGER\\SEGGER_RTT_Conf.h"




 
# 320 ".\\RTE\\SEGGER\\SEGGER_RTT_Conf.h"




 
# 334 ".\\RTE\\SEGGER\\SEGGER_RTT_Conf.h"




 
# 347 ".\\RTE\\SEGGER\\SEGGER_RTT_Conf.h"

# 367 ".\\RTE\\SEGGER\\SEGGER_RTT_Conf.h"




 
# 393 ".\\RTE\\SEGGER\\SEGGER_RTT_Conf.h"




 
# 408 ".\\RTE\\SEGGER\\SEGGER_RTT_Conf.h"





 
# 425 ".\\RTE\\SEGGER\\SEGGER_RTT_Conf.h"




 









 
# 62 ".\\RTE\\SEGGER\\SEGGER_RTT.h"






 
# 125 ".\\RTE\\SEGGER\\SEGGER_RTT.h"
    
    
    
# 146 ".\\RTE\\SEGGER\\SEGGER_RTT.h"
  
  
  
# 158 ".\\RTE\\SEGGER\\SEGGER_RTT.h"










# 175 ".\\RTE\\SEGGER\\SEGGER_RTT.h"





# 192 ".\\RTE\\SEGGER\\SEGGER_RTT.h"

# 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
 
 
 




 
 



 






   














  


 








# 54 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


  



    typedef unsigned int size_t;    
# 70 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"






    



    typedef unsigned short wchar_t;  
# 91 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"

typedef struct div_t { int quot, rem; } div_t;
    
typedef struct ldiv_t { long int quot, rem; } ldiv_t;
    

typedef struct lldiv_t { long long quot, rem; } lldiv_t;
    


# 112 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   



 

   




 
# 131 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   


 
extern __declspec(__nothrow) int __aeabi_MB_CUR_MAX(void);

   




 

   




 




extern __declspec(__nothrow) double atof(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int atoi(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) long int atol(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) long long atoll(const char *  ) __attribute__((__nonnull__(1)));
   



 


extern __declspec(__nothrow) double strtod(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

















 

extern __declspec(__nothrow) float strtof(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) long double strtold(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

 

extern __declspec(__nothrow) long int strtol(const char * __restrict  ,
                        char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



























 
extern __declspec(__nothrow) unsigned long int strtoul(const char * __restrict  ,
                                       char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   


























 

 
extern __declspec(__nothrow) long long strtoll(const char * __restrict  ,
                                  char ** __restrict  , int  )
                          __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) unsigned long long strtoull(const char * __restrict  ,
                                            char ** __restrict  , int  )
                                   __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) int rand(void);
   







 
extern __declspec(__nothrow) void srand(unsigned int  );
   






 

struct _rand_state { int __x[57]; };
extern __declspec(__nothrow) int _rand_r(struct _rand_state *);
extern __declspec(__nothrow) void _srand_r(struct _rand_state *, unsigned int);
struct _ANSI_rand_state { int __x[1]; };
extern __declspec(__nothrow) int _ANSI_rand_r(struct _ANSI_rand_state *);
extern __declspec(__nothrow) void _ANSI_srand_r(struct _ANSI_rand_state *, unsigned int);
   


 

extern __declspec(__nothrow) void *calloc(size_t  , size_t  );
   



 
extern __declspec(__nothrow) void free(void *  );
   





 
extern __declspec(__nothrow) void *malloc(size_t  );
   



 
extern __declspec(__nothrow) void *realloc(void *  , size_t  );
   













 

extern __declspec(__nothrow) int posix_memalign(void **  , size_t  , size_t  );
   









 

typedef int (*__heapprt)(void *, char const *, ...);
extern __declspec(__nothrow) void __heapstats(int (*  )(void *  ,
                                           char const *  , ...),
                        void *  ) __attribute__((__nonnull__(1)));
   










 
extern __declspec(__nothrow) int __heapvalid(int (*  )(void *  ,
                                           char const *  , ...),
                       void *  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) __declspec(__noreturn) void abort(void);
   







 

extern __declspec(__nothrow) int atexit(void (*  )(void)) __attribute__((__nonnull__(1)));
   




 
# 436 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


extern __declspec(__nothrow) __declspec(__noreturn) void exit(int  );
   












 

extern __declspec(__nothrow) __declspec(__noreturn) void _Exit(int  );
   







      

extern __declspec(__nothrow) char *getenv(const char *  ) __attribute__((__nonnull__(1)));
   









 

extern __declspec(__nothrow) int  system(const char *  );
   









 

extern  void *bsearch(const void *  , const void *  ,
              size_t  , size_t  ,
              int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,2,5)));
   












 
# 524 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


extern  void qsort(void *  , size_t  , size_t  ,
           int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,4)));
   









 

# 553 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"

extern __declspec(__nothrow) __attribute__((const)) int abs(int  );
   



 

extern __declspec(__nothrow) __attribute__((const)) div_t div(int  , int  );
   









 
extern __declspec(__nothrow) __attribute__((const)) long int labs(long int  );
   



 




extern __declspec(__nothrow) __attribute__((const)) ldiv_t ldiv(long int  , long int  );
   











 







extern __declspec(__nothrow) __attribute__((const)) long long llabs(long long  );
   



 




extern __declspec(__nothrow) __attribute__((const)) lldiv_t lldiv(long long  , long long  );
   











 
# 634 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"




 
typedef struct __sdiv32by16 { int quot, rem; } __sdiv32by16;
typedef struct __udiv32by16 { unsigned int quot, rem; } __udiv32by16;
    
typedef struct __sdiv64by32 { int rem, quot; } __sdiv64by32;

__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv32by16 __rt_sdiv32by16(
     int  ,
     short int  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __udiv32by16 __rt_udiv32by16(
     unsigned int  ,
     unsigned short  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv64by32 __rt_sdiv64by32(
     int  , unsigned int  ,
     int  );
   

 




 
extern __declspec(__nothrow) unsigned int __fp_status(unsigned int  , unsigned int  );
   







 























 
extern __declspec(__nothrow) int mblen(const char *  , size_t  );
   












 
extern __declspec(__nothrow) int mbtowc(wchar_t * __restrict  ,
                   const char * __restrict  , size_t  );
   















 
extern __declspec(__nothrow) int wctomb(char *  , wchar_t  );
   













 





 
extern __declspec(__nothrow) size_t mbstowcs(wchar_t * __restrict  ,
                      const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 
extern __declspec(__nothrow) size_t wcstombs(char * __restrict  ,
                      const wchar_t * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 

extern __declspec(__nothrow) void __use_realtime_heap(void);
extern __declspec(__nothrow) void __use_realtime_division(void);
extern __declspec(__nothrow) void __use_two_region_memory(void);
extern __declspec(__nothrow) void __use_no_heap(void);
extern __declspec(__nothrow) void __use_no_heap_region(void);

extern __declspec(__nothrow) char const *__C_library_version_string(void);
extern __declspec(__nothrow) int __C_library_version_number(void);











# 892 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"





 
# 195 ".\\RTE\\SEGGER\\SEGGER_RTT.h"
# 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"
 
 
 





 










# 27 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"








 

 
 
# 57 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"
    typedef struct __va_list { void *__ap; } va_list;

   






 


   










 


   















 




   

 


   




 



   





 








      
     typedef  va_list __gnuc_va_list;






# 147 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"

 

# 196 ".\\RTE\\SEGGER\\SEGGER_RTT.h"






 








# 218 ".\\RTE\\SEGGER\\SEGGER_RTT.h"






 





typedef struct {
  const     char*    sName;         
            char*    pBuffer;       
            unsigned SizeOfBuffer;  
            unsigned WrOff;         
  volatile  unsigned RdOff;         
            unsigned Flags;         
} SEGGER_RTT_BUFFER_UP;





typedef struct {
  const     char*    sName;         
            char*    pBuffer;       
            unsigned SizeOfBuffer;  
  volatile  unsigned WrOff;         
            unsigned RdOff;         
            unsigned Flags;         
} SEGGER_RTT_BUFFER_DOWN;






typedef struct {
  char                    acID[16];                                 
  int                     MaxNumUpBuffers;                          
  int                     MaxNumDownBuffers;                        
  SEGGER_RTT_BUFFER_UP    aUp[(1)];       
  SEGGER_RTT_BUFFER_DOWN  aDown[(1)];   



} SEGGER_RTT_CB;






 
extern SEGGER_RTT_CB _SEGGER_RTT;






 



int          SEGGER_RTT_AllocDownBuffer         (const char* sName, void* pBuffer, unsigned BufferSize, unsigned Flags);
int          SEGGER_RTT_AllocUpBuffer           (const char* sName, void* pBuffer, unsigned BufferSize, unsigned Flags);
int          SEGGER_RTT_ConfigUpBuffer          (unsigned BufferIndex, const char* sName, void* pBuffer, unsigned BufferSize, unsigned Flags);
int          SEGGER_RTT_ConfigDownBuffer        (unsigned BufferIndex, const char* sName, void* pBuffer, unsigned BufferSize, unsigned Flags);
int          SEGGER_RTT_GetKey                  (void);
unsigned     SEGGER_RTT_HasData                 (unsigned BufferIndex);
int          SEGGER_RTT_HasKey                  (void);
unsigned     SEGGER_RTT_HasDataUp               (unsigned BufferIndex);
void         SEGGER_RTT_Init                    (void);
unsigned     SEGGER_RTT_Read                    (unsigned BufferIndex,       void* pBuffer, unsigned BufferSize);
unsigned     SEGGER_RTT_ReadNoLock              (unsigned BufferIndex,       void* pData,   unsigned BufferSize);
int          SEGGER_RTT_SetNameDownBuffer       (unsigned BufferIndex, const char* sName);
int          SEGGER_RTT_SetNameUpBuffer         (unsigned BufferIndex, const char* sName);
int          SEGGER_RTT_SetFlagsDownBuffer      (unsigned BufferIndex, unsigned Flags);
int          SEGGER_RTT_SetFlagsUpBuffer        (unsigned BufferIndex, unsigned Flags);
int          SEGGER_RTT_WaitKey                 (void);
unsigned     SEGGER_RTT_Write                   (unsigned BufferIndex, const void* pBuffer, unsigned NumBytes);
unsigned     SEGGER_RTT_WriteNoLock             (unsigned BufferIndex, const void* pBuffer, unsigned NumBytes);
unsigned     SEGGER_RTT_WriteSkipNoLock         (unsigned BufferIndex, const void* pBuffer, unsigned NumBytes);
unsigned     SEGGER_RTT_ASM_WriteSkipNoLock     (unsigned BufferIndex, const void* pBuffer, unsigned NumBytes);
unsigned     SEGGER_RTT_WriteString             (unsigned BufferIndex, const char* s);
void         SEGGER_RTT_WriteWithOverwriteNoLock(unsigned BufferIndex, const void* pBuffer, unsigned NumBytes);
unsigned     SEGGER_RTT_PutChar                 (unsigned BufferIndex, char c);
unsigned     SEGGER_RTT_PutCharSkip             (unsigned BufferIndex, char c);
unsigned     SEGGER_RTT_PutCharSkipNoLock       (unsigned BufferIndex, char c);
unsigned     SEGGER_RTT_GetAvailWriteSpace      (unsigned BufferIndex);
unsigned     SEGGER_RTT_GetBytesInBuffer        (unsigned BufferIndex);














 
unsigned     SEGGER_RTT_ReadUpBuffer            (unsigned BufferIndex, void* pBuffer, unsigned BufferSize);
unsigned     SEGGER_RTT_ReadUpBufferNoLock      (unsigned BufferIndex, void* pData, unsigned BufferSize);
unsigned     SEGGER_RTT_WriteDownBuffer         (unsigned BufferIndex, const void* pBuffer, unsigned NumBytes);
unsigned     SEGGER_RTT_WriteDownBufferNoLock   (unsigned BufferIndex, const void* pBuffer, unsigned NumBytes);








 
int     SEGGER_RTT_SetTerminal        (unsigned char TerminalId);
int     SEGGER_RTT_TerminalOut        (unsigned char TerminalId, const char* s);
int     SEGGER_RTT_TerminalPrintf     (unsigned TerminalId, const char * sFormat, ...);






 
int SEGGER_RTT_printf(unsigned BufferIndex, const char * sFormat, ...);
int SEGGER_RTT_vprintf(unsigned BufferIndex, const char * sFormat, va_list * pParamList);












 
















# 389 ".\\RTE\\SEGGER\\SEGGER_RTT.h"

# 398 ".\\RTE\\SEGGER\\SEGGER_RTT.h"

# 407 ".\\RTE\\SEGGER\\SEGGER_RTT.h"

# 416 ".\\RTE\\SEGGER\\SEGGER_RTT.h"




 
# 6 "src\\includes.h"
# 1 "src\\init_section.h"




typedef void (*init_fn_t)(void);


















extern const init_fn_t __stan_init_init_board_start; 
extern const init_fn_t __stan_init_init_app_end; 


extern __inline void auto_loop(void);
extern void auto_init(void);

# 7 "src\\includes.h"

# 1 ".\\src\\pt\\pt.h"

































 




 







 




# 1 ".\\src\\pt\\lc.h"

































 




 












 







 

# 118 ".\\src\\pt\\lc.h"





# 1 ".\\src\\pt\\lc-addrlabels.h"

































 




 
















 




 
typedef void *lc_t;



# 72 ".\\src\\pt\\lc-addrlabels.h"













 
# 125 ".\\src\\pt\\lc.h"






 
 
# 53 ".\\src\\pt\\pt.h"

struct pt
{
    lc_t lc;
};









 












 


 




 











 














 











 



 




 











 
# 156 ".\\src\\pt\\pt.h"











 


 




 
















 













 






 




 










 
















 






 




 












 


 




 










 
# 299 ".\\src\\pt\\pt.h"











 
# 319 ".\\src\\pt\\pt.h"

 



 
# 10 "src\\includes.h"







# 23 "src\\includes.h"

# 1 "src\\config.h"



# 1 "src\\OrderConfig.h"



# 1 "src\\defs.h"









# 5 "src\\OrderConfig.h"









 













# 1 ".\\config\\220801.h"

# 3 ".\\config\\220801.h"



 


















































	
	
	




	

	
	
	




	

	
	
	




	
	
	
	
	




	







	
	
	
	
	
	
	

	
	
	
	



	
	
	




	

	
	
	




	

	
	
	




	
	
	
	
	




	













# 173 ".\\config\\220801.h"

















# 29 "src\\OrderConfig.h"









# 5 "src\\config.h"

 



# 18 "src\\config.h"


 











 
# 40 "src\\config.h"

 






 







	
# 63 "src\\config.h"

 






 








# 25 "src\\includes.h"


extern volatile uint32_t systick_ms;
extern uint8_t mod_addr;
extern uint8_t mod_addr_s0;













		


















# 2 "src\\logic.c"
# 1 "src\\power_out.h"



# 5 "src\\power_out.h"

typedef enum
{
    PS_Off = 0,
    PS_Start,
    PS_On,
    PS_Err,
		PS_Idle
} PoutStatus;

typedef struct
{
    char name[8];
    uint32_t gpio_periph;
    uint32_t magic; 
	
    uint32_t time;
	
    uint32_t oc_time;
    uint16_t oct_threshold;
	
    uint32_t sc_time;
    uint16_t sct_threshold;

    uint16_t cur_100ma;
    uint16_t oc_threshold;
    uint16_t sc_threshold; 

    uint8_t pin;
    uint8_t adc_ch;

    uint8_t cmd;
    uint8_t diag;
    uint8_t rt_diag; 
    PoutStatus status;
    uint8_t errcount;

    uint8_t pwmable;   
    uint8_t pwmfixed;   
    uint8_t pwmstart;   
    uint8_t pwmend;  
    uint8_t pwmi;   	

} PoutControl;


enum{
	A1,
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
	A8,
};












	
extern PoutControl PoutS[15];
extern uint8_t rain_int_cmd;







# 3 "src\\logic.c"
# 1 "src\\can_protol.h"



# 5 "src\\can_protol.h"

extern uint8_t KEY_ON,KEY_ACC,KEY_SOS;



extern void testmod_can_app (void);

# 4 "src\\logic.c"
# 1 "src\\switch.h"



# 5 "src\\switch.h"

extern uint8_t in_sw[3];






extern void mod_addr_init (void);




# 5 "src\\logic.c"
# 1 "src\\logic.h"
# 2 "src\\logic.h"
# 3 "src\\logic.h"
# 4 "src\\logic.h"
# 5 "src\\logic.h"





# 17 "src\\logic.h"
extern uint8_t sw_3[3];





# 40 "src\\logic.h"

# 56 "src\\logic.h"

# 74 "src\\logic.h"

# 92 "src\\logic.h"

# 110 "src\\logic.h"

# 128 "src\\logic.h"




# 152 "src\\logic.h"
	
	
# 170 "src\\logic.h"
	
	
# 191 "src\\logic.h"
	
	


# 6 "src\\logic.c"


