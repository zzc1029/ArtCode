/*!
    \file  BF7006AMxx_config.h
    \brief peripherals configuration for BF7006AMxx
*/

/*
    Copyright (C) 2017 Byd

    2021-02-28, V1.0.0, peripherals configuration for BF7006AMxx
*/

#ifndef BF7006AMxx_CONFIG_H
#define BF7006AMxx_CONFIG_H

#include "RTE_Components.h"
#include "BF7006AMxx.h"
#include "BF7006AMxx_sysctrl.h"

#ifdef BF7x06AMxx_SCI_DRIVER_PRESENT
    #include "BF7006AMxx_sci.h"
#endif

#ifdef BF7x06AMxx_CAN_DRIVER_PRESENT
    #include "BF7006AMxx_can.h"
#endif

#ifdef BF7x06AMxx_ADC_DRIVER_PRESENT
    #include "BF7006AMxx_adc.h"
#endif

#ifdef BF7x06AMxx_EFLASH_DRIVER_PRESENT
    #include "BF7006AMxx_eflash.h"
#endif

#ifdef BF7x06AMxx_WDT_DRIVER_PRESENT
    #include "BF7006AMxx_wdt.h"
#endif

#ifdef BF7x06AMxx_TIMER_DRIVER_PRESENT
    #include "BF7006AMxx_timer.h"
#endif

#ifdef BF7x06AMxx_RTC_DRIVER_PRESENT
    #include "BF7006AMxx_rtc.h"
#endif

#ifdef BF7x06AMxx_PWM_DRIVER_PRESENT
    #include "BF7006AMxx_pwm.h"
#endif

#ifdef BF7x06AMxx_GPIO_DRIVER_PRESENT
    #include "BF7006AMxx_gpio.h"
#endif

/* call this function to initialize all selected peripherals */
void peripherals_config(void);

/* call the following functions to configure single peripheral */
void adc_config(void);
void sci_config(void);
void can_config(void);
void timer_config(void);
void pwm_config(void);
void wdt_cfg(void);
void rtc_config(void);
void gpio_config(void);

#endif
