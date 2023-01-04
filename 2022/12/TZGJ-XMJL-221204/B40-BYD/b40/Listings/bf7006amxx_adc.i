# 1 "RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.c"



 





 

# 1 "RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.h"



 





 




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





# 16 "RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.h"

 
# 56 "RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.h"
 

 
 






 
# 75 "RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.h"

 




 
# 106 "RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.h"

 





 


 

 
 



 
# 132 "RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.h"

 



 




 




 
# 154 "RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.h"

 
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
# 13 "RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.c"
# 1 "C:\\Keil_v5\\ARM\\PACK\\BYD\\BYDMicro_DFP\\1.1.0\\Device\\Include\\BF7006AMxx\\BF7006AMxx_sci.h"



 






 




# 1 "C:\\Keil_v5\\ARM\\PACK\\BYD\\BYDMicro_DFP\\1.1.0\\Device\\Include\\BF7006AMxx\\BF7006AMxx.h"



 





 

# 17 "C:\\Keil_v5\\ARM\\PACK\\BYD\\BYDMicro_DFP\\1.1.0\\Device\\Include\\BF7006AMxx\\BF7006AMxx_sci.h"

 
# 28 "C:\\Keil_v5\\ARM\\PACK\\BYD\\BYDMicro_DFP\\1.1.0\\Device\\Include\\BF7006AMxx\\BF7006AMxx_sci.h"
 

 
 





 


 
# 49 "C:\\Keil_v5\\ARM\\PACK\\BYD\\BYDMicro_DFP\\1.1.0\\Device\\Include\\BF7006AMxx\\BF7006AMxx_sci.h"

 
# 59 "C:\\Keil_v5\\ARM\\PACK\\BYD\\BYDMicro_DFP\\1.1.0\\Device\\Include\\BF7006AMxx\\BF7006AMxx_sci.h"

 
# 69 "C:\\Keil_v5\\ARM\\PACK\\BYD\\BYDMicro_DFP\\1.1.0\\Device\\Include\\BF7006AMxx\\BF7006AMxx_sci.h"

 
# 78 "C:\\Keil_v5\\ARM\\PACK\\BYD\\BYDMicro_DFP\\1.1.0\\Device\\Include\\BF7006AMxx\\BF7006AMxx_sci.h"

 
# 88 "C:\\Keil_v5\\ARM\\PACK\\BYD\\BYDMicro_DFP\\1.1.0\\Device\\Include\\BF7006AMxx\\BF7006AMxx_sci.h"

 


 


 

 
 
# 105 "C:\\Keil_v5\\ARM\\PACK\\BYD\\BYDMicro_DFP\\1.1.0\\Device\\Include\\BF7006AMxx\\BF7006AMxx_sci.h"

 




 



 



 



 



 



 



 



 
# 150 "C:\\Keil_v5\\ARM\\PACK\\BYD\\BYDMicro_DFP\\1.1.0\\Device\\Include\\BF7006AMxx\\BF7006AMxx_sci.h"

 



 



 



 



 



 



     



     





     





 
# 198 "C:\\Keil_v5\\ARM\\PACK\\BYD\\BYDMicro_DFP\\1.1.0\\Device\\Include\\BF7006AMxx\\BF7006AMxx_sci.h"

 
                

 
typedef struct
{
    uint32_t    baud_rate;           
    uint8_t     work_mode;           
    uint8_t     stop_bit_width;      
    uint8_t     data_bit_width;      
    uint8_t     parity_en;           
    uint8_t     parity_sel;          
    uint8_t     break_tx_size;       
    uint8_t     break_check_en;      
    uint8_t     rate_automatch_en;   
    uint8_t     tx_en;               
    uint8_t     rx_en;               
    uint8_t     idle_sel;            
    uint8_t     wake_sel;            
    uint8_t     tx_inversion_en;     
    uint8_t     rwu_idlesel;         
    uint16_t    int_enable;          
    uint8_t     nvic_enable;         
}sci_parameter_struct;


 
 
ErrorStatus sci_init(uint32_t scix,sci_parameter_struct sci_parameter_init);
 
void sci_enable(uint32_t scix);
 
void sci_disable(uint32_t scix);
 
void sci_data_send(uint32_t scix,uint8_t dat);
 
uint8_t sci_data_get(uint32_t scix);

 
void sci_tx_enable(uint32_t scix);
 
void sci_tx_disable(uint32_t scix);
 
void sci_rx_enable(uint32_t scix);
 
void sci_rx_disable(uint32_t scix);

 
void sci_tx_out(uint32_t scix);
 
void sci_tx_in(uint32_t scix);
 
void sci_t8_set(uint32_t scix);
 
void sci_t8_reset(uint32_t scix);
 
FlagStatus sci_r8_get(uint32_t scix);
 
FlagStatus sci_rx_inv_get(uint32_t scix);

 
uint8_t sci_tx_int_flag_get(uint32_t scix);
 
uint8_t sci_rx_int_flag_get(uint32_t scix);
 
uint8_t sci_err_int_flag_get(uint32_t scix);
 
void sci_break_int_flag_clr(uint32_t scix);
 
void sci_rx_edge_int_flag_clr(uint32_t scix);

 
ErrorStatus sci_send_byte(uint32_t scix,uint8_t dat);
 
ErrorStatus sci_rece_byte(uint32_t scix,uint8_t *rece_dat);


# 14 "RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.c"
# 1 "RTE\\Device\\BF7006AM64\\BF7006AMxx_wdt.h"



 






 




# 17 "RTE\\Device\\BF7006AM64\\BF7006AMxx_wdt.h"

 




 

 
# 32 "RTE\\Device\\BF7006AM64\\BF7006AMxx_wdt.h"
 

 
 



 



 



 



 



 



 
 
void wdt_clear(void);
 
void wdt_updata(uint16_t wdt_cs);
 
void wdt_config(uint16_t wdt_cs);
 
void wdt_overflow_count(uint16_t wdt_cnt);
 
void wdt_overflow_count_win(uint16_t wdt_cnt);

# 15 "RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.c"
# 1 "RTE\\Device\\BF7006AM64\\BF7006AMxx_pwm.h"



 








 




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


# 16 "RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.c"
# 1 ".\\RTE\\CMSIS\\BF7006AM64\\stdio.h"
 
 
 





 






 







 




  
 








# 47 ".\\RTE\\CMSIS\\BF7006AM64\\stdio.h"


  



    typedef unsigned int size_t;    









 
 

 



    typedef struct __va_list __va_list;






   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

# 136 ".\\RTE\\CMSIS\\BF7006AM64\\stdio.h"


extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

# 166 ".\\RTE\\CMSIS\\BF7006AM64\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));


#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int __ARM_vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int __ARM_vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int __ARM_vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));
   








 

extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 




    extern __declspec(__nothrow) int (getchar)(void);

   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 




    extern __declspec(__nothrow) int (putchar)(int  );

   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 











# 1021 ".\\RTE\\CMSIS\\BF7006AM64\\stdio.h"



 

# 17 "RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.c"

static void adc_reg_config(void);
static void adc_clk_init(uint8_t adc_clk,uint32_t sys_clk);





















 



 
void adc_init(adc_parameter_struct adc_init_para)
{
     
    (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x00U)))) = 0x1fUL;
    if(adc_init_para.adco_en == ENABLE){    
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x00U)))) |= ((uint32_t)(0x01UL<<((uint8_t)(5))));
    }else{                                  
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x00U)))) &= ~((uint32_t)(0x01UL<<((uint8_t)(5))));
    }

    (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) = 0X00UL;

    (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x14U)))) = 0x00UL;
    if(adc_init_para.data_width == 0x01U){        
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x14U)))) |= ((uint32_t)(0x01UL<<((uint8_t)(2))));
    }else if(adc_init_para.data_width == 0x00U){   
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x14U)))) &= ~((uint32_t)(0x01UL<<((uint8_t)(2))));
    }else{
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x14U)))) |= ((uint32_t)(0x01UL<<((uint8_t)(2))));
    }

     
    adc_clk_init(adc_init_para.adc_clk,SystemCoreClock);

    (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x1cU)))) = adc_init_para.sample_clk_num;                 
    
     
    adc_reg_config();
    
     
    adc_trigger_config(adc_init_para.trigger);
    
     
    adc_compare_config(adc_init_para.compare);

     
    adc_channel_enable(adc_init_para.channel_en);
    
     
    adc_powerdown(DISABLE);
    
     
    adc_interrupt_set(adc_init_para.int_en);
    


}






 
void adc_interrupt_set(FunctionalState en)
{
    if(en == ENABLE){
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x00U)))) |= ((uint32_t)(0x01UL<<((uint8_t)(6))));
        __NVIC_EnableIRQ(ADC_IRQn);
    }else{
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x00U)))) &= ~((uint32_t)(0x01UL<<((uint8_t)(6))));
        __NVIC_DisableIRQ(ADC_IRQn);
    }
}






 
ErrorStatus wait_adc_convert(void)
{
    uint32_t timeout = 30000U;
    while(timeout != 0x00U){
        timeout --;
        if(((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x00U)))) & ((uint32_t)(0x01UL<<((uint8_t)(7))))) != 0x00U){
            return SUCCESS;
        }
    }
    return SUCCESS;
}






 
uint16_t adc_data_get(void)
{
    return (uint16_t)(*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x08U))));
}






 
void adc_start_convert(uint8_t ch)
{
    ch |= 0xe0U;
    (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x00U)))) |= 0x1fU;
    (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x00U)))) &= ch;
}







 
static void adc_clk_init(uint8_t adc_clk,uint32_t sys_clk)
{    










# 180 "RTE\\Device\\BF7006AM64\\BF7006AMxx_adc.c"

    uint8_t adc_ckc_ckv;
    uint8_t adc_ckc_wnum;
    uint8_t adc_ckc_sambg = 0x80U;
    uint8_t adc_ckc_samdel;
    if(sys_clk == 32000000UL){
        if(adc_clk == 0x00U){        
            adc_clk = 0x10U;
        }
        switch(adc_clk){
            case 0x10U:
                adc_ckc_ckv = ((uint8_t)0x01);
                adc_ckc_wnum = ((uint8_t)0x03 << 2);
                adc_ckc_samdel = ((uint8_t)0x03 << 4);
                break;
            case 0x70U:
                adc_ckc_ckv = ((uint8_t)0x01);
                adc_ckc_wnum = ((uint8_t)0x01 << 2);
                adc_ckc_samdel = ((uint8_t)0x03 << 4);
                break;
            case 0x20U:
                adc_ckc_ckv = ((uint8_t)0x02);
                adc_ckc_wnum = ((uint8_t)0x03 << 2);
                adc_ckc_samdel = ((uint8_t)0x02 << 4);
                break;
            case 0x30U:
            case 0x40U:    
            case 0x50U:
            case 0x60U:
                adc_ckc_ckv = ((uint8_t)0x02);
                adc_ckc_wnum = ((uint8_t)0x00 << 2);
                adc_ckc_samdel = ((uint8_t)0x01 << 4);
                break;
            default:
                adc_ckc_ckv = 0x00U;
                adc_ckc_wnum = 0x00U;
                adc_ckc_samdel = 0x00U;
                break;
        }
    }else if(sys_clk == 16000000UL){
        switch(adc_clk){
            case 0x00U:
                adc_ckc_ckv = ((uint8_t)0x00);
                adc_ckc_wnum = ((uint8_t)0x03 << 2);
                adc_ckc_samdel = ((uint8_t)0x03 << 4);
                break;
            case 0x10U:
                adc_ckc_ckv = ((uint8_t)0x01);
                adc_ckc_wnum = ((uint8_t)0x03 << 2);
                adc_ckc_samdel = ((uint8_t)0x02 << 4);
                break;
            case 0x70U:
                adc_ckc_ckv = ((uint8_t)0x01);
                adc_ckc_wnum = ((uint8_t)0x01 << 2);
                adc_ckc_samdel = ((uint8_t)0x02 << 4);
                break;
            case 0x20U:
            case 0x30U:
            case 0x40U:    
            case 0x50U:
            case 0x60U:
                adc_ckc_ckv = ((uint8_t)0x01);
                adc_ckc_wnum = ((uint8_t)0x00 << 2);
                adc_ckc_samdel = ((uint8_t)0x01 << 4);
                break;
            default:
                adc_ckc_ckv = 0x00U;
                adc_ckc_wnum = 0x00U;
                adc_ckc_samdel = 0x00U;
                break;
        }
    }else{
        if(adc_clk == 0x00U){
            adc_ckc_ckv = ((uint8_t)0x00);
            adc_ckc_wnum = ((uint8_t)0x03 << 2);
            adc_ckc_samdel = ((uint8_t)0x02 << 4);
        }else{
            adc_ckc_ckv = ((uint8_t)0x00);
            adc_ckc_wnum = ((uint8_t)0x00 << 2);
            adc_ckc_samdel = ((uint8_t)0x01 << 4);
        }
    }
    (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x14U)))) &= ~((uint32_t)((0xFFFFFFFFUL << ((uint8_t)(4))) & (0xFFFFFFFFUL >> (31U - ((uint8_t)(6))))));
    (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x14U)))) |= adc_clk;
    (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x78U)))) = (adc_ckc_sambg | adc_ckc_samdel | adc_ckc_wnum | adc_ckc_ckv);
}





 
static void adc_reg_config(void)
{
    (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x7cU)))) = 0X19U;
    (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x90U)))) = 0X00U;
    (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x94U)))) = 0x00U;

}






 
void adc_powerdown(FunctionalState en)
{
    if(en == ENABLE){
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x80U)))) = 0x01U;
    }else{
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x80U)))) = 0x00U;
    }
}






 
void adc_channel_enable(uint32_t ch)
{
    (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x18U)))) = 0x00U;
    (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x18U)))) |= ch;
}






 
void adc_channel_disable(uint32_t ch)
{
    (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x18U)))) &= ~ch;
}











 
void adc_compare_config(adc_compare_struct adc_compare)
{
    if(adc_compare.compare_en == ENABLE){
        if(adc_compare.compare_condition == 0x00U){
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) |= ((uint32_t)(0x01UL<<((uint8_t)(5))));
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) &= ~((uint32_t)(0x01UL<<((uint8_t)(3))));
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) &= ~((uint32_t)(0x01UL<<((uint8_t)(4))));
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x0cU)))) = adc_compare.higher_limit_val;
        }else if(adc_compare.compare_condition == 0x01U){
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) |= ((uint32_t)(0x01UL<<((uint8_t)(5))));
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) &= ~((uint32_t)(0x01UL<<((uint8_t)(3))));
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) |= ((uint32_t)(0x01UL<<((uint8_t)(4))));
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x0cU)))) = adc_compare.lower_limit_val;
        }else if(adc_compare.compare_condition == 0x02U){
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) |= ((uint32_t)(0x01UL<<((uint8_t)(5))));
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) |= ((uint32_t)(0x01UL<<((uint8_t)(3))));
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) |= ((uint32_t)(0x01UL<<((uint8_t)(4))));
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) &= ~((uint32_t)(0x01UL<<((uint8_t)(2))));
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x0cU)))) = adc_compare.lower_limit_val;
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x10U)))) = adc_compare.higher_limit_val;
        }else{
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) &= ~((uint32_t)(0x01UL<<((uint8_t)(5))));
            (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) &= ~((uint32_t)(0x01UL<<((uint8_t)(3))));
        }
    }
}








 
void adc_trigger_config(adc_trigger_struct adc_trigger)
{
     
    if(adc_trigger.trigger_mode == 0x00U){             
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) &= ~((uint32_t)(0x01UL<<((uint8_t)(6))));
    }else if(adc_trigger.trigger_mode == 0x01U){       
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) |= ((uint32_t)(0x01UL<<((uint8_t)(6))));
    }else{
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) &= ~((uint32_t)(0x01UL<<((uint8_t)(6))));
    }
    
     
    if(adc_trigger.trigger_source == 0x01U){       
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) |= ((uint32_t)(0x01UL<<((uint8_t)(1))));
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x8cU)))) = 0x00U;
    }else if(adc_trigger.trigger_source == 0x02U){ 
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) &= ~((uint32_t)(0x01UL<<((uint8_t)(1))));
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x8cU)))) = 0x01U;
        ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x60000) + 0x3CU))))) = adc_trigger.pwm_trigger_delay;
    }else if(adc_trigger.trigger_source == 0x03U){ 
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) &= ~((uint32_t)(0x01UL<<((uint8_t)(1))));
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x8cU)))) = 0x00U;
    }else{
        (*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x90000) + 0x04U)))) &= ~((uint32_t)(0x01UL<<((uint8_t)(6))));
    }
}
