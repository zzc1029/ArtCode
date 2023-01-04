;/*****************************************************************************
; * @file:    startup_MPS_CM0.s
; * @purpose: CMSIS Cortex-M0 Core Device Startup File 
; *           for the ARM 'Microcontroller Prototyping System' 
; * @version: V1.0
; * @date:    19. Aug. 2009
; *------- <<< Use Configuration Wizard in Context Menu >>> ------------------
; *
; * Copyright (C) 2008-2009 ARM Limited. All rights reserved.
; * ARM Limited (ARM) is supplying this software for use with Cortex-M0 
; * processor based microcontrollers.  This file can be freely distributed 
; * within development tools that are supporting such ARM based processors. 
; *
; * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
; * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
; * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
; * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
; * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
; *
; *****************************************************************************/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000400

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB

            
					
; Vector Table Mapped to Address 0 at Reset

                AREA    RESETORGIN, DATA, READONLY
                EXPORT  __Vectorsfirst

__Vectorsfirst  DCD     __initial_sp                        ; Top of Stack
                DCD     Reset_Handler                       ; Reset Handler
; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors

__Vectors       DCD     __initial_sp                        ; Top of Stack
                DCD     Reset_Handler                       ; Reset Handler
                DCD     NMI_Handler                         ; NMI Handler
                DCD     HardFault_Handler                   ; Hard Fault Handler
                DCD     0                                   ; Reserved
                DCD     0                                   ; Reserved
                DCD     0                                   ; Reserved
                DCD     0                                   ; Reserved
                DCD     0                                   ; Reserved
                DCD     0                                   ; Reserved
                DCD     0                                   ; Reserved
                DCD     SVC_Handler                         ; SVCall Handler
                DCD     0                                   ; Reserved
                DCD     0                                   ; Reserved
                DCD     PendSV_Handler                      ; PendSV Handler
                DCD     SysTick_Handler                     ; SysTick Handler

                ; External Interrupts
                DCD     0                                   ; 0:  Reserved
                DCD     SYS_IRQHandler                      ; 1:  Flash+EEPROM ECC RC_CHK_ONE ADJ_EER   
                DCD     0                                   ; 2:  Reserved
                DCD     0                                   ; 3:  Reserved
                DCD     LVDT_IRQHandler                     ; 4:  LVDT Interrupt
                DCD     PWM_CH0_IRQHandler                  ; 5:  PWM channel 0
                DCD     PWM_CH1_IRQHandler                  ; 6:  PWM channel 1
                DCD     PWM_CH2_IRQHandler                  ; 7:  PWM channel 2
                DCD     PWM_CH3_IRQHandler                  ; 8:  PWM channel 3
                DCD     PWM_CH4_IRQHandler                  ; 9:  PWM channel 4
                DCD     PWM_CH5_IRQHandler                  ; 10: PWM channel 5
                DCD     PWM_TOF_IRQHandler                  ; 11: PWM overflow
                DCD     0                                   ; 12: Reserved
                DCD     0                                   ; 13: Reserved
                DCD     0                                   ; 14: Reserved
                DCD     0                                   ; 15: Reserved
                DCD     SCI0_ERR_IRQHandler                 ; 16: SCI0 ERR
                DCD     SCI0_RX_IRQHandler                  ; 17: SCI0 RX
                DCD     SCI0_TX_IRQHandler                  ; 18: SCI0 TX
                DCD     SCI1_ERR_IRQHandler                 ; 19: SCI0 ERR
                DCD     SCI1_RX_IRQHandler                  ; 20: SCI0 RX
                DCD     SCI1_TX_IRQHandler                  ; 21: SCI0 TX
                DCD     GPIO_IRQHandler                     ; 22: GPIO INT
                DCD     ADC_IRQHandler                      ; 23: ADC
                DCD     0                                   ; 24: Reserved
                DCD     RTC_IRQHandler                      ; 25: RTC
                DCD     CAN_WAKE_IRQHandler                 ; 26: CAN WAKE UP
                DCD     CAN_ERR_IRQHandler                  ; 27: CAN ERR
                DCD     CAN_RX_IRQHandler                   ; 28: CAN RX
                DCD     CAN_TX_IRQHandler                   ; 29: CAN TX
                DCD     TIMER0_IRQHandler                   ; 30: Timer0
                DCD     TIMER1_IRQHandler                   ; 31: Timer1


                AREA    |.text|, CODE, READONLY

; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                    EXPORT          SYS_IRQHandler                      [WEAK]
                    EXPORT          LVDT_IRQHandler                     [WEAK]
                    EXPORT          PWM_CH0_IRQHandler                  [WEAK]
                    EXPORT          PWM_CH1_IRQHandler                  [WEAK]
                    EXPORT          PWM_CH2_IRQHandler                  [WEAK]
                    EXPORT          PWM_CH3_IRQHandler                  [WEAK]
                    EXPORT          PWM_CH4_IRQHandler                  [WEAK]
                    EXPORT          PWM_CH5_IRQHandler                  [WEAK]
                    EXPORT          PWM_TOF_IRQHandler                  [WEAK]
                    EXPORT          SCI0_ERR_IRQHandler                 [WEAK]
                    EXPORT          SCI0_RX_IRQHandler                  [WEAK]
                    EXPORT          SCI0_TX_IRQHandler                  [WEAK]
                    EXPORT          SCI1_ERR_IRQHandler                 [WEAK]
                    EXPORT          SCI1_RX_IRQHandler                  [WEAK]
                    EXPORT          SCI1_TX_IRQHandler                  [WEAK]
                    EXPORT          GPIO_IRQHandler                     [WEAK]
                    EXPORT          ADC_IRQHandler                      [WEAK]
                    EXPORT          RTC_IRQHandler                      [WEAK]
                    EXPORT          CAN_WAKE_IRQHandler                 [WEAK]
                    EXPORT          CAN_ERR_IRQHandler                  [WEAK]
                    EXPORT          CAN_RX_IRQHandler                   [WEAK]
                    EXPORT          CAN_TX_IRQHandler                   [WEAK]
                    EXPORT          TIMER0_IRQHandler                   [WEAK]
                    EXPORT          TIMER1_IRQHandler                   [WEAK]


SYS_IRQHandler  
LVDT_IRQHandler
PWM_CH0_IRQHandler
PWM_CH1_IRQHandler
PWM_CH2_IRQHandler
PWM_CH3_IRQHandler
PWM_CH4_IRQHandler
PWM_CH5_IRQHandler
PWM_TOF_IRQHandler
SCI0_ERR_IRQHandler
SCI0_RX_IRQHandler
SCI0_TX_IRQHandler
SCI1_ERR_IRQHandler
SCI1_RX_IRQHandler
SCI1_TX_IRQHandler
GPIO_IRQHandler
ADC_IRQHandler
RTC_IRQHandler
CAN_WAKE_IRQHandler
CAN_ERR_IRQHandler
CAN_RX_IRQHandler
CAN_TX_IRQHandler
TIMER0_IRQHandler
TIMER1_IRQHandler
   

                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB
                
                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit
                
                ELSE
                
                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap
__user_initial_stackheap

                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR

                ALIGN

                ENDIF


                END