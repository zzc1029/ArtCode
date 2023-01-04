# 1 "RTE\\Device\\BF7006AM64\\BF7006AMxx_pwm.c"



 








 

# 1 "RTE\\Device\\BF7006AM64\\BF7006AMxx_pwm.h"



 








 




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





# 19 "RTE\\Device\\BF7006AM64\\BF7006AMxx_pwm.h"

 
# 37 "RTE\\Device\\BF7006AM64\\BF7006AMxx_pwm.h"
 

 
 
# 48 "RTE\\Device\\BF7006AM64\\BF7006AMxx_pwm.h"

 
# 56 "RTE\\Device\\BF7006AM64\\BF7006AMxx_pwm.h"
 

 
 



 



 




 
# 81 "RTE\\Device\\BF7006AM64\\BF7006AMxx_pwm.h"

 



 


 


 
 
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


# 16 "RTE\\Device\\BF7006AM64\\BF7006AMxx_pwm.c"







 
void pwm_init(uint8_t pwm_sc,uint16_t pwm_mod)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x08U))))) = pwm_mod;
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x00U))))) = pwm_sc;
    if((pwm_sc & ((uint32_t)(0x01UL<<((uint8_t)(6))))) != 0U){
        __NVIC_EnableIRQ(PWM_TOF_IRQN);
    }else{
        __NVIC_DisableIRQ(PWM_TOF_IRQN);
    }
}






 
void pwm_mod_set(uint16_t mod_count)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x08U))))) = mod_count;
}






 
uint16_t pwm_get_count(void)
{
    uint32_t rtal;
    rtal = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x04U)))));
    return (uint16_t)rtal;
}






 
void pwm_tof_clr(void)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x00U))))) &= ~((uint32_t)(0x01UL<<((uint8_t)(7))));
}







 
void pwm_ch0_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x10U))))) = pwm_ch_cnt;
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x0cU))))) = pwm_ch_sc;
    if((pwm_ch_sc & ((uint32_t)(0x01UL<<((uint8_t)(6))))) != 0U){
        __NVIC_EnableIRQ(PWM_CH0_IRQn);
    }else{
        __NVIC_DisableIRQ(PWM_CH0_IRQn);
    }
}






 
void pwm_ch0_cnt_set(uint16_t count)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x10U))))) = count;
}






 
uint16_t pwm_ch0_get_count(void)
{
    uint32_t rtal;
    rtal = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x10U)))));
    return (uint16_t)rtal;
}






 
void pwm_ch0_if_clr(void)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x0cU))))) &= ~((uint32_t)(0x01UL<<((uint8_t)(7))));
}







 
void pwm_ch1_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x18U))))) = pwm_ch_cnt;
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x14U))))) = pwm_ch_sc;
    if((pwm_ch_sc & ((uint32_t)(0x01UL<<((uint8_t)(6))))) != 0U){
        __NVIC_EnableIRQ(PWM_CH1_IRQn);
    }else{
        __NVIC_DisableIRQ(PWM_CH1_IRQn);
    }
}






 
void pwm_ch1_cnt_set(uint16_t count)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x18U))))) = count;
}







 
uint16_t pwm_ch1_get_count(void)
{
    uint32_t rtal;
    rtal = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x18U)))));
    return (uint16_t)rtal;
}






 
void pwm_ch1_if_clr(void)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x14U))))) &= ~((uint32_t)(0x01UL<<((uint8_t)(7))));
}







 
void pwm_ch2_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x20U))))) = pwm_ch_cnt;
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x1cU))))) = pwm_ch_sc;
    if((pwm_ch_sc & ((uint32_t)(0x01UL<<((uint8_t)(6))))) != 0U){
        __NVIC_EnableIRQ(PWM_CH2_IRQn);
    }else{
        __NVIC_DisableIRQ(PWM_CH2_IRQn);
    }
}






 
void pwm_ch2_cnt_set(uint16_t count)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x20U))))) = count;
}






 
uint16_t pwm_ch2_get_count(void)
{
    uint32_t rtal;
    rtal = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x20U)))));
    return (uint16_t)rtal;
}






 
void pwm_ch2_if_clr(void)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x1cU))))) &= ~((uint32_t)(0x01UL<<((uint8_t)(7))));
}







 
void pwm_ch3_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x28U))))) = pwm_ch_cnt;
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x24U))))) = pwm_ch_sc;
    if((pwm_ch_sc & ((uint32_t)(0x01UL<<((uint8_t)(6))))) != 0U){
        __NVIC_EnableIRQ(PWM_CH3_IRQn);
    }else{
        __NVIC_DisableIRQ(PWM_CH3_IRQn);
    }
}






 
void pwm_ch3_cnt_set(uint16_t count)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x28U))))) = count;
}






 
uint16_t pwm_ch3_get_count(void)
{
    uint32_t rtal;
    rtal = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x28U)))));
    return (uint16_t)rtal;
}






 
void pwm_ch3_if_clr(void)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x24U))))) &= ~((uint32_t)(0x01UL<<((uint8_t)(7))));
}







 
void pwm_ch4_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x30U))))) = pwm_ch_cnt;
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x2cU))))) = pwm_ch_sc;
    if((pwm_ch_sc & ((uint32_t)(0x01UL<<((uint8_t)(6))))) != 0U){
        __NVIC_EnableIRQ(PWM_CH4_IRQn);
    }else{
        __NVIC_DisableIRQ(PWM_CH4_IRQn);
    }
}






 
void pwm_ch4_cnt_set(uint16_t count)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x30U))))) = count;
}






 
uint16_t pwm_ch4_get_count(void)
{
    uint32_t rtal;
    rtal = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x30U)))));
    return (uint16_t)rtal;
}






 
void pwm_ch4_if_clr(void)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x2cU))))) &= ~((uint32_t)(0x01UL<<((uint8_t)(7))));
}







 
void pwm_ch5_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x38U))))) = pwm_ch_cnt;
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x34U))))) = pwm_ch_sc;
    if((pwm_ch_sc & ((uint32_t)(0x01UL<<((uint8_t)(6))))) != 0U){
        __NVIC_EnableIRQ(PWM_CH5_IRQn);
    }else{
        __NVIC_DisableIRQ(PWM_CH5_IRQn);
    }
}






 
void pwm_ch5_cnt_set(uint16_t count)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x38U))))) = count;
}






 
uint16_t pwm_ch5_get_count(void)
{
    uint32_t rtal;
    rtal = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x38U)))));
    return (uint16_t)rtal;
}






 
void pwm_ch5_if_clr(void)
{
    ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x34U))))) &= ~((uint32_t)(0x01UL<<((uint8_t)(7))));
}
