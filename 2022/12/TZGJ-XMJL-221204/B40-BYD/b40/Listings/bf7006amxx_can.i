# 1 "RTE\\Device\\BF7006AM64\\BF7006AMxx_can.c"



 






 

# 1 "RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"



 






 



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





# 16 "RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 
# 46 "RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 
# 60 "RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"
 

 

 
 





 
# 78 "RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 
# 88 "RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 
# 98 "RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 
# 108 "RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 






 
# 123 "RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 



 


 




 





 
# 150 "RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"
 

 
 



 



 



 
# 177 "RTE\\Device\\BF7006AM64\\BF7006AMxx_can.h"

 












 




 


 


 


 


 


 


 


 
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

# 14 "RTE\\Device\\BF7006AM64\\BF7006AMxx_can.c"
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
# 15 "RTE\\Device\\BF7006AM64\\BF7006AMxx_can.c"
# 1 "RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"



 






 




# 17 "RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 29 "RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 

 
# 41 "RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 51 "RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 61 "RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 





 
# 77 "RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 87 "RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 97 "RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 107 "RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 117 "RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 125 "RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
# 136 "RTE\\Device\\BF7006AM64\\BF7006AMxx_gpio.h"

 
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
# 16 "RTE\\Device\\BF7006AM64\\BF7006AMxx_can.c"






static ErrorStatus can_baud_set(can_clk_enum can_clk,uint8_t can_baud);
static ErrorStatus can_filter_init(can_filter_parameter_struct can_filter_parameter);



























 
ErrorStatus can_init(can_parameter_struct can_parameter_init,can_filter_parameter_struct can_filter_parameter)
{	
	can_module_rst();
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x10000) + 0x18U))))) = 4U;
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x78U))))) = 1U;
	 
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x00U))))) |= ((uint32_t)(0x01UL<<((uint8_t)(0))));
	
	 
	switch(can_parameter_init.working_mode){
		case CAN_MODE_LISTEN_ONLY:
			((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x00U))))) |= ((uint32_t)(0x01UL<<((uint8_t)(1))));
			break;
		case CAN_MODE_SELF_TEST:
			((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x00U))))) |= ((uint32_t)(0x01UL<<((uint8_t)(2))));
			break;
		case CAN_MODE_SELF_RECEIVE:
			((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x04U))))) |= ((uint32_t)(0x01UL<<((uint8_t)(4))));
			break;
		default:
			 
			break;
	}
	
	 
	(void)can_baud_set(can_parameter_init.can_clk,can_parameter_init.can_baud);
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x18U))))) |= can_parameter_init.resync_jump_width;
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x1CU))))) |= can_parameter_init.sampling_times;
	
	 
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x34U))))) = ((uint32_t)can_parameter_init.error_alarm_count & 0x000000FFUL);
	
	 
	(void)can_filter_init(can_filter_parameter);
	
	 
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x00U))))) &= ~((uint32_t)(0x01UL<<((uint8_t)(0))));
	
	can_int_enable(can_parameter_init.int_enable);
	if((can_parameter_init.nvic_int_enable & ((uint32_t)(0x01UL<<((uint8_t)(3))))) != 0U){
		__NVIC_EnableIRQ(CAN_WAKE_IRQn);
	}else{
		__NVIC_DisableIRQ(CAN_WAKE_IRQn);
	}
	if((can_parameter_init.nvic_int_enable & ((uint32_t)(0x01UL<<((uint8_t)(2))))) != 0U){
		__NVIC_EnableIRQ(CAN_ERR_IRQn);
	}else{
		__NVIC_DisableIRQ(CAN_ERR_IRQn);
	}
	if((can_parameter_init.nvic_int_enable & ((uint32_t)(0x01UL<<((uint8_t)(1))))) != 0U){
		__NVIC_EnableIRQ(CAN_RX_IRQn);
	}else{
		__NVIC_DisableIRQ(CAN_RX_IRQn);
	}
	if((can_parameter_init.nvic_int_enable & ((uint32_t)(0x01UL<<((uint8_t)(0))))) != 0U){
		__NVIC_EnableIRQ(CAN_TX_IRQn);
	}else{
		__NVIC_DisableIRQ(CAN_TX_IRQn);
	}
	return SUCCESS;
}












 
ErrorStatus can_receive_message(can_frame_struct *receive_data)
{
	uint8_t i;
	 
	if((((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x0CU))))) & ((uint32_t)(0x01UL<<((uint8_t)(0))))) != 0U){	
		uint32_t tmp[4];
		tmp[0] = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x44U)))));
		tmp[1] = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x48U)))));
		tmp[2] = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x4CU)))));
		tmp[3] = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x50U)))));

		 
		if((((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x40U))))) & ((uint32_t)(0x01UL<<((uint8_t)(7))))) != 0U){
			receive_data->ff = CAN_EXTENDED_FRAME;
			receive_data->efid = (uint32_t)((tmp[0] << 21U) | (tmp[1] << 13U) | (tmp[2] << 5U) | (tmp[3] >> 3U));
		}else{
			receive_data->ff = CAN_STANDARD_FRAME;
			receive_data->sfid = (uint32_t)((tmp[0] << 3U) | (tmp[1] >> 5U));
		}
		
		 
		if((((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x40U))))) & ((uint32_t)(0x01UL<<((uint8_t)(6))))) != 0U){
			receive_data->ft = CAN_REMOTE_FRAME;
		}else{
			receive_data->ft = CAN_DATA_FRAME;
		}
		
		 
		tmp[0] = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x40U)))));
		receive_data->dlen = (uint8_t)(tmp[0] & ((uint32_t)((0xFFFFFFFFUL << ((uint8_t)(0))) & (0xFFFFFFFFUL >> (31U - ((uint8_t)(3)))))));
		if(receive_data->dlen > 0x08U){
			receive_data->dlen = 0x08U;
		}
		
		 
		for(i=0U;i<receive_data->dlen;i++){
			tmp[0] = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x54U + ((i) << 2))))));
			receive_data->data[i] = (uint8_t)tmp[0];
		}
		 
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x04U))))) |= ((uint32_t)(0x01UL<<((uint8_t)(2))));
		return SUCCESS;
	}
	return ERROR;
}











 
ErrorStatus can_transmit_message(can_frame_struct *transmit_data)
{
	uint8_t tmp_frame;
	uint8_t tmp_id[4] = {0x00,0x00,0x00,0x00};
	if(transmit_data == ((void *)0)){
		return ERROR;
	}
	
	if((((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x08U))))) & (((uint32_t)(0x01UL<<((uint8_t)(2)))))) == (((uint32_t)(0x01UL<<((uint8_t)(2)))))){
		if(transmit_data->ff == CAN_STANDARD_FRAME){	
			tmp_id[0] = (uint8_t)(transmit_data->sfid >> 3);
			tmp_id[1] = (uint8_t)(transmit_data->sfid << 5);
		}else{	
			tmp_id[0] = (uint8_t)(transmit_data->efid >> 21);
			tmp_id[1] = (uint8_t)(transmit_data->efid >> 13);
			tmp_id[2] = (uint8_t)(transmit_data->efid >> 5);
			tmp_id[3] = (uint8_t)(transmit_data->efid << 3);
		}
		tmp_frame = (transmit_data->dlen & 0x0fU);
		if((transmit_data->ff) != CAN_STANDARD_FRAME){
			tmp_frame |= 0x80U;
		}
		if((transmit_data->ft) != CAN_DATA_FRAME){
			tmp_frame |= 0x40U;
		}
		 
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x40U))))) = tmp_frame;
		
		 
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x44U))))) = tmp_id[0];
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x48U))))) = tmp_id[1];
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x4CU))))) = tmp_id[2];
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x50U))))) = tmp_id[3];
		
		 
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x54U))))) = transmit_data->data[0];
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x58U))))) = transmit_data->data[1];
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x5CU))))) = transmit_data->data[2];
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x60U))))) = transmit_data->data[3];
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x64U))))) = transmit_data->data[4];
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x68U))))) = transmit_data->data[5];
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x6CU))))) = transmit_data->data[6];
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x70U))))) = transmit_data->data[7];
		
		return SUCCESS;
	}
	return ERROR;
}









 
static ErrorStatus can_baud_set(can_clk_enum can_clk,uint8_t can_baud)
{
 
	uint8_t perscaler;
	uint8_t seg1;
	uint8_t seg2;
	ErrorStatus rtal;
	switch(can_baud){
		case CAN_BAUD_50K:
			if(can_clk == CAN_CLK_8M){
				perscaler = 3U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_16M){
				perscaler = 7U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_32M){
				perscaler = 15U;
				rtal = SUCCESS;
			}else{
				perscaler = 0U;
				rtal = ERROR;
			}
			seg1 = 13U;
			seg2 = 4U;
			break;
		case CAN_BAUD_100K:
			if(can_clk == CAN_CLK_8M){
				perscaler = 1U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_16M){
				perscaler = 3U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_32M){
				perscaler = 7U;
				rtal = SUCCESS;
			}else{
				perscaler = 0U;
				rtal = ERROR;
			}
			seg1 = 13U;
			seg2 = 4U;
			break;
		case CAN_BAUD_125K:
			if(can_clk == CAN_CLK_8M){
				perscaler = 1U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_16M){
				perscaler = 3U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_32M){
				perscaler = 7U;
				rtal = SUCCESS;
			}else{
				perscaler = 0U;
				rtal = ERROR;
			}
			seg1 = 10U;
			seg2 = 3U;
			break;
		case CAN_BAUD_200K:
			if(can_clk == CAN_CLK_8M){
				perscaler = 0U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_16M){
				perscaler = 1U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_32M){
				perscaler = 3U;
				rtal = SUCCESS;
			}else{
				perscaler = 0U;
				rtal = ERROR;
			}
			seg1 = 13U;
			seg2 = 4U;
			break;
		case CAN_BAUD_250K:
			if(can_clk == CAN_CLK_8M){
				perscaler = 0U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_16M){
				perscaler = 1U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_32M){
				perscaler = 3U;
				rtal = SUCCESS;
			}else{
				perscaler = 0U;
				rtal = ERROR;
			}
			seg1 = 10U;
			seg2 = 3U;
			break;
		case CAN_BAUD_400K:
			if(can_clk == CAN_CLK_8M){
				perscaler = 0x00U;
				seg1 = 5U;
				seg2 = 2U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_16M){
				perscaler = 0x00U;
				seg1 = 13U;
				seg2 = 4U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_32M){
				perscaler = 0x01U;
				seg1 = 13U;
				seg2 = 4U;
				rtal = SUCCESS;
			}else{
				perscaler = 0U;
				seg1 = 0U;
				seg2 = 0U;
				rtal = ERROR;
			}
			break;
		case CAN_BAUD_500K:
			if(can_clk == CAN_CLK_8M){
				perscaler = 0x00U;
				seg1 = 4U;
				seg2 = 1U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_16M){
				perscaler = 0x00U;
				seg1 = 10U;
				seg2 = 3U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_32M){
				perscaler = 0x01U;
				seg1 = 10U;
				seg2 = 3U;
				rtal = SUCCESS;
			}else{
				perscaler = 0U;
				seg1 = 0U;
				seg2 = 0U;
				rtal = ERROR;
			}
			break;
		case CAN_BAUD_800K:
			if(can_clk == CAN_CLK_16M){
				perscaler = 0x00U;
				seg1 = 5U;
				seg2 = 2U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_32M){
				perscaler = 0x00U;
				seg1 = 13U;
				seg2 = 4U;
				rtal = SUCCESS;
			}else{
				perscaler = 0U;
				seg1 = 0U;
				seg2 = 0U;
				rtal = ERROR;
			}
			break;
		case CAN_BAUD_1M:
			if(can_clk == CAN_CLK_16M){
				perscaler = 0x00U;
				seg1 = 4U;
				seg2 = 1U;
				rtal = SUCCESS;
			}else if(can_clk == CAN_CLK_32M){
				perscaler = 0x00U;
				seg1 = 10U;
				seg2 = 3U;
				rtal = SUCCESS;
			}else{
				perscaler = 0U;
				seg1 = 0U;
				seg2 = 0U;
				rtal = ERROR;
			}
			break;
		default:
			perscaler = 0x00U;
			seg1 = 0U;
			seg2 = 0U;
			rtal = ERROR;
			break;
	}
	if(rtal == SUCCESS){
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x18U))))) = perscaler;
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x1CU))))) = ((seg2 << 4U) | seg1);
	}
	return rtal;
}







 

void can_transmit_request(void)
{
	can_int_flag_clr(((uint32_t)(0x01UL<<((uint8_t)(1)))));
	 
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x04U))))) |= ((uint32_t)(0x01UL<<((uint8_t)(0))));
}






 
ErrorStatus can_wait_trans(void)
{
	uint32_t timeout = 30000U;
	while(timeout != 0x00U){
		timeout --;
		if((can_interrupt_flag_get() & ((uint32_t)(0x01UL<<((uint8_t)(1))))) != 0x00U){
			can_int_flag_clr((uint8_t)(0x01UL << 1));
			return SUCCESS;
		}
	}
	can_int_flag_clr((uint8_t)(0x01UL << 1));
	return ERROR;
}




















 
static ErrorStatus can_filter_init(can_filter_parameter_struct can_filter_parameter)
{
	uint8_t tmp_id[4] = {0x00U,0x00U,0x00U,0x00U};
	uint8_t tmp_mask[4] = {0xffU,0xffU,0xffU,0xffU};
	can_filter_parameter_struct *can_filter;
	can_filter = &can_filter_parameter;
	if(can_filter->filter_mode == CAN_SINGLE_FILTER){	
		if(can_filter->filter_frame == CAN_STANDARD_FRAME){	
			tmp_id[0] = (uint8_t)(can_filter->filter_single_id >> 3);
			tmp_id[1] = (uint8_t)(can_filter->filter_single_id << 5);
			if((can_filter->filter_RTR) != CAN_DATA_FRAME){
				tmp_id[1] |= ((uint8_t)0x01 << 4);
			}else{
				tmp_id[1] &= ~((uint8_t)0x01 << 4);
			}
			tmp_id[2] = can_filter->filter_data0;
			tmp_id[3] = can_filter->filter_data1;
			tmp_mask[0] = (uint8_t)(can_filter->filter_mask_single_id >> 3);
			tmp_mask[1] = (uint8_t)((can_filter->filter_mask_single_id << 5) | 0x1FU);
			if((can_filter->filter_mask_RTR) != DISABLE){
				tmp_mask[1] &= ~((uint8_t)0x01 << 4);
			}else{
				tmp_mask[1] |= ((uint8_t)0x01 << 4);
			}
			tmp_mask[2] = can_filter->filter_mask_data0;
			tmp_mask[3] = can_filter->filter_mask_data1;
		}else{	
			tmp_id[0] = (uint8_t)(can_filter->filter_single_id >> 21);
			tmp_id[1] = (uint8_t)(can_filter->filter_single_id >> 13);
			tmp_id[2] = (uint8_t)(can_filter->filter_single_id >> 5);
			tmp_id[3] = (uint8_t)(can_filter->filter_single_id << 3); 
			if(can_filter->filter_RTR != CAN_DATA_FRAME){
				tmp_id[3] |= ((uint8_t)0x01 << 2);
			}else{
				tmp_id[3] &= ~((uint8_t)0x01 << 2);
			}
			tmp_mask[0] = (uint8_t)(can_filter->filter_mask_single_id >> 21);
			tmp_mask[1] = (uint8_t)(can_filter->filter_mask_single_id >> 13);
			tmp_mask[2] = (uint8_t)(can_filter->filter_mask_single_id >> 5);
			tmp_mask[3] = (uint8_t)(((uint8_t)(can_filter->filter_mask_single_id << 3)) | 0x07U);		
			if((can_filter->filter_mask_RTR) != DISABLE){
				tmp_mask[3] &= ~((uint8_t)0x01 << 2);
			}else{
				tmp_mask[3] |= ((uint8_t)0x01 << 2);
			}
		}
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x00U))))) |= ((uint32_t)(0x01UL<<((uint8_t)(3))));
	}else{	
		if(can_filter->filter_frame == CAN_STANDARD_FRAME){	
			tmp_id[0] = (uint8_t)(can_filter->filter_double_id0 >> 3);
			tmp_id[1] = (uint8_t)((can_filter->filter_double_id0 << 5) | 
						((can_filter->filter_data0_std >> 4) & 0x0fU));
			if(can_filter->filter_RTR != CAN_DATA_FRAME){
				tmp_id[1] |= (0x01U << 4);
			}else{
				tmp_id[1] &= ~(0x01U << 4);
			}
			tmp_id[2] = (uint8_t)(can_filter->filter_double_id1 >> 3);
			tmp_id[3] = (uint8_t)((can_filter->filter_double_id1 << 5) | 
						(can_filter->filter_data0_std & 0x0fU));
			if(can_filter->filter_RTR != CAN_DATA_FRAME){
				tmp_id[3] |= (0x01U << 4);
			}else{
				tmp_id[3] &= ~(0x01U << 4);
			}
			
			tmp_mask[0] = (uint8_t)(can_filter->filter_mask_double_id0 >> 3);
			tmp_mask[1] = (uint8_t)((can_filter->filter_mask_double_id0 << 5) | 
						  ((can_filter->filter_mask_data0_std >> 4) & 0x0fU));
			tmp_mask[2] = (uint8_t)(can_filter->filter_mask_double_id1 >> 3);
			tmp_mask[3] = (uint8_t)((can_filter->filter_mask_double_id1 << 5) | 
						  (can_filter->filter_mask_data0_std & 0x0fU));
			if((can_filter->filter_mask_RTR) != DISABLE){
				tmp_mask[1] &= ~((uint8_t)0x01 << 4);
			}else{
				tmp_mask[1] |= ((uint8_t)0x01 << 4);
			}
			if((can_filter->filter_mask_RTR) != DISABLE){
				tmp_mask[3] &= ~((uint8_t)0x01 << 4);
			}else{
				tmp_mask[3] |= ((uint8_t)0x01 << 4);
			}
		}else{	
			tmp_id[0] = (uint8_t)(can_filter->filter_double_id0 >> 21);
			tmp_id[1] = (uint8_t)(can_filter->filter_double_id0 >> 13);
			tmp_id[2] = (uint8_t)(can_filter->filter_double_id1 >> 21);
			tmp_id[3] = (uint8_t)(can_filter->filter_double_id1 >> 13);
			tmp_mask[0] = (uint8_t)(can_filter->filter_mask_double_id0 >> 8);
			tmp_mask[1] = (uint8_t)can_filter->filter_mask_double_id0;
			tmp_mask[2] = (uint8_t)(can_filter->filter_mask_double_id1 >> 8);
			tmp_mask[3] = (uint8_t)can_filter->filter_mask_double_id1;
		}
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x00U))))) &= ~((uint32_t)(0x01UL<<((uint8_t)(3))));
	}
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x40U))))) = tmp_id[0];
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x44U))))) = tmp_id[1];
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x48U))))) = tmp_id[2];
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x4CU))))) = tmp_id[3];
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x50U))))) = tmp_mask[0];
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x54U))))) = tmp_mask[1];
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x58U))))) = tmp_mask[2];
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x5CU))))) = tmp_mask[3];
	return SUCCESS;
}






 
uint8_t can_read_frame_error_code(void)
{
	uint32_t retal;
	retal = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x30U)))));
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x84U))))) = 0x01;
	return (uint8_t)retal;
}






 
uint8_t can_read_arbitration_lost_code(void)
{
	uint32_t retal;
	retal = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x2CU)))));
	return (uint8_t)retal;

}






 
void can_transmit_abort(void)
{
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x04U))))) |= (((uint32_t)(0x01UL<<((uint8_t)(1)))) | ((uint32_t)(0x01UL<<((uint8_t)(0)))));
}












 
void can_sleep_config(uint8_t wakeup_mode,uint8_t filter_en,FunctionalState state)
{
	if(state == ENABLE){
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x24U))))) |= ((uint32_t)(0x01UL<<((uint8_t)(0))));
	}else{
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x24U))))) &= ~((uint32_t)(0x01UL<<((uint8_t)(0))));
	}
	if(wakeup_mode != 0U){
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x24U))))) |= ((uint32_t)(0x01UL<<((uint8_t)(1))));
	}else{
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x24U))))) &= ~((uint32_t)(0x01UL<<((uint8_t)(1))));
	}
	if(filter_en != 0U){
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x88U))))) = 0x01U;
	}else{
		((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x88U))))) = 0x00U;
	}
}






 
ErrorStatus can_sleep_request(void)
{
	uint32_t timeout = 30000U;
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x04U))))) |= ((uint32_t)(0x01UL<<((uint8_t)(5))));
	while(timeout != 0x00U){
		timeout --;
		if(((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x20U))))) != 0x00U){
			return SUCCESS;
		}
	}
	return ERROR;
}






 
uint8_t can_get_fifo_num(void)
{
	uint32_t retal;
	retal = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x74U)))));
	return (uint8_t)retal;
}







 
void can_int_enable(uint8_t intstate)
{
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x10U))))) |= intstate;
}







 
void can_int_disable(uint8_t intstate)
{
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x10U))))) &= ~intstate;
}






 
uint8_t can_interrupt_flag_get(void)
{
	uint32_t retal;
	retal = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x0CU)))));
	return (uint8_t)retal;
}






 
void can_int_flag_clr(uint8_t int_flag)
{
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x80U))))) = int_flag;
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x10000) + 0x48U))))) = 0x01U;
}






 
uint8_t can_status_get(void)
{
	uint32_t retal;
	retal = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x08U)))));
	return (uint8_t)retal;
}












 
void can_wait_transmit_frame(can_frame_struct *transmit_data)
{
	(void)can_transmit_message(transmit_data);
	can_transmit_request();
	(void)can_wait_trans();
}






 
uint8_t can_get_txerrcnt(void)
{
	uint32_t retal;
	retal = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x3CU)))));
	return (uint8_t)retal;
}






 
uint8_t can_get_rxerrcnt(void)
{
	uint32_t retal;
	retal = ((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x38U)))));
	return (uint8_t)retal;
}






 
void can_module_rst(void)
{
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x10000) + 0x44U))))) = 0x00U;
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x10000) + 0x44U))))) = 0x01U;
}






 
void can_clock_sel(uint8_t can_clock)
{
	ErrorStatus rval;
	if(can_clock == 0U){
		if((((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x10000) + 0x04U))))) & ((uint32_t)(0x01UL<<((uint8_t)(3))))) == 0x00U){
			rval = xtal_init();
			if(rval == ERROR){
				can_clock = 1U;
			}
		}
	}
	((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x10000) + 0x40U))))) = can_clock;
}






 
bool is_can_txbuf_empty(void)
{
	bool rtal;
	if((((*((volatile uint32_t *)((uint32_t)((((uint32_t)0x50000000) + (uint32_t)0x50000) + 0x08U))))) & ((uint32_t)(0x01UL<<((uint8_t)(2))))) == ((uint32_t)(0x01UL<<((uint8_t)(2))))){
		rtal = TRUE;
	}else{
		rtal = FALSE;
	}
	return rtal;
}


