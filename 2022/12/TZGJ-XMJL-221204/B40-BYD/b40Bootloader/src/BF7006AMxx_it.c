/*!
    \file  BF7006AMxx_it.c
    \brief interrupt service routines
*/

#include "RTE_Components.h"
#include "BF7006AMxx.h"
#include "BF7006AMxx_sysctrl.h"

#ifdef BF7x06AMxx_ADC_DRIVER_PRESENT
    #include "BF7006AMxx_adc.h"
#endif
#ifdef BF7x06AMxx_CAN_DRIVER_PRESENT
    #include "BF7006AMxx_can.h"
#endif
#ifdef BF7x06AMxx_EFLASH_DRIVER_PRESENT
    #include "BF7006AMxx_eflash.h"
#endif
#ifdef BF7x06AMxx_GPIO_DRIVER_PRESENT
    #include "BF7006AMxx_gpio.h"
#endif
#ifdef BF7x06AMxx_LIN_DRIVER_PRESENT
    #include "BF7006AMxx_lin.h"
#endif
#ifdef BF7x06AMxx_PWM_DRIVER_PRESENT
    #include "BF7006AMxx_pwm.h"
#endif
#ifdef BF7x06AMxx_RTC_DRIVER_PRESENT
    #include "BF7006AMxx_rtc.h"
#endif
#ifdef BF7x06AMxx_SCI_DRIVER_PRESENT
    #include "BF7006AMxx_sci.h"
#endif
#ifdef BF7x06AMxx_TIMER_DRIVER_PRESENT
    #include "BF7006AMxx_timer.h"
#endif
#ifdef BF7x06AMxx_WDT_DRIVER_PRESENT
    #include "BF7006AMxx_wdt.h"
#endif


#ifdef BF7x06AMxx_GPIO_DRIVER_PRESENT
/*!
    \brief      this function handles NMI exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void NMI_Handler (void)
{
    clr_nmi_interrupt_flag();
}
#endif

/*!
    \brief      this function handles HardFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void HardFault_Handler (void)
{
    /* if Hard Fault exception occurs, go to infinite loop */
    while (1)
    {
    }
}

/*!
    \brief      this function handles SVC exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SVC_Handler (void)
{

}

/*!
    \brief      this function handles PendSV exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PendSV_Handler (void)
{

}

/*!
    \brief      this function handles SysTick exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SysTick_Handler (void)
{
}

/*!
    \brief      system interrupt handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SYS_IRQHandler (void)
{
    uint32_t state = SYS_INTFLG;
    /* eeprom protect range illegal access */
    if ((state & SYS_INTFLG_EPOT) != 0x00U)
    {
    }
    /* flash protect range illegal access */
    if ((state & SYS_INTFLG_FPOT) != 0x00U)
    {
    }
    /* xtal initialize fail state */
    if ((state & SYS_INTFLG_XTALINIT) != 0x00U)
    {
        xtal_timeout = 1;
    }
    /* xtal invalid check state */
    if ((state & SYS_INTFLG_XTALCHK) != 0x00U)
    {
        if ((SYS_XTAL_CHK & SYS_XTAL_CHK_RSTEN) == 0x00U)
        {
            SYS_XTAL_CTRL &= ~SYS_XTAL_CTRL_EN;
        }
    }
    SYS_INTFLG = state;
}

/*!
    \brief      this function handles lvdt exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void LVDT_IRQHandler (void)
{
    uint8_t int_flag;
    int_flag = lvdt_int_flag_get();
    lvdt_int_flag_clr (int_flag);
}

#ifdef BF7x06AMxx_SCI_DRIVER_PRESENT
/*!
    \brief      sci0 error handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SCI0_ERR_IRQHandler (void)
{
    (void)sci_err_int_flag_get (SCI0);
}

/*!
    \brief      sci0 tx handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SCI0_TX_IRQHandler (void)
{
    #ifdef LIN_SCI0
    uint8_t state;
    state = sci_tx_int_flag_get (SCI0);
    if ((state & SCI_IF_TX_EMPTY) != 0x00U)
    {
        if (LIN0_Tx_Callback != NULL)
        {
            LIN0_Tx_Callback();
        }
    }
    #else
    (void)sci_tx_int_flag_get (SCI0);
    #endif
}

/*!
    \brief      sci0 rx handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SCI0_RX_IRQHandler (void)
{
    uint8_t rx_int_state;
    rx_int_state = sci_rx_int_flag_get (SCI0);
    #ifdef LIN_SCI0
    if (LIN0_Rx_Callback != NULL)
    {
        if ((rx_int_state & SCI_IF_RX_EDGE) != 0x00U)
        {
            sci_rx_edge_int_flag_clr (SCI0);
        }
        LIN0_Rx_Callback (rx_int_state);
    }
    else
    {
        if ((rx_int_state & SCI_IF_BREAK_CHECK) != 0x00U)
        {
            sci_break_int_flag_clr (SCI0);
            lin_break_check_disable (SCI0);
        }
        else if ((rx_int_state & SCI_IF_RX_FULL) != 0x00U)
        {
            (void)sci_data_get (SCI0);
        }
        else if ((rx_int_state & SCI_IF_RX_EDGE) != 0x00U)
        {
            sci_rx_edge_int_flag_clr (SCI0);
        }
        else
        {
            (void)sci_data_get (SCI0);
        }
    }
    #else
    if ((rx_int_state & SCI_IF_BREAK_CHECK) != 0x00U)
    {
        sci_break_int_flag_clr (SCI0);
        #ifdef BF7x06AMxx_LIN_DRIVER_PRESENT
        lin_break_check_disable (SCI0);
        #endif
    }
    else if ((rx_int_state & SCI_IF_RX_FULL) != 0x00U)
    {
        (void)sci_data_get (SCI0);
    }
    else if ((rx_int_state & SCI_IF_RX_EDGE) != 0x00U)
    {
        sci_rx_edge_int_flag_clr (SCI0);
    }
    else
    {
        (void)sci_data_get (SCI0);
    }
    #endif
}

/*!
    \brief      sci1 error handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SCI1_ERR_IRQHandler (void)
{
    (void)sci_err_int_flag_get (SCI1);
}

/*!
    \brief      sci1 tx handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SCI1_TX_IRQHandler (void)
{
    #ifdef LIN_SCI1
    uint8_t state;
    state = sci_tx_int_flag_get (SCI1);
    if ((state & SCI_IF_TX_EMPTY) != 0x00U)
    {
        if (LIN1_Tx_Callback != NULL)
        {
            LIN1_Tx_Callback();
        }
    }
    #else
    (void)sci_tx_int_flag_get (SCI1);
    #endif
}

/*!
    \brief      sci1 rx handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SCI1_RX_IRQHandler (void)
{
    uint8_t rx_int_state;
    rx_int_state = sci_rx_int_flag_get (SCI1);
    #ifdef LIN_SCI1
    if (LIN1_Rx_Callback != NULL)
    {
        if ((rx_int_state & SCI_IF_RX_EDGE) != 0x00U)
        {
            sci_rx_edge_int_flag_clr (SCI1);
        }
        LIN1_Rx_Callback (rx_int_state);
    }
    else
    {
        if ((rx_int_state & SCI_IF_BREAK_CHECK) != 0x00U)
        {
            sci_break_int_flag_clr (SCI1);
            lin_break_check_disable (SCI1);
        }
        else if ((rx_int_state & SCI_IF_RX_FULL) != 0x00U)
        {
            (void)sci_data_get (SCI1);
        }
        else if ((rx_int_state & SCI_IF_RX_EDGE) != 0x00U)
        {
            sci_rx_edge_int_flag_clr (SCI1);
        }
        else
        {
            (void)sci_data_get (SCI1);
        }
    }
    #else
    if ((rx_int_state & SCI_IF_BREAK_CHECK) != 0x00U)
    {
        sci_break_int_flag_clr (SCI1);
        #ifdef BF7x06AMxx_LIN_DRIVER_PRESENT
        lin_break_check_disable (SCI1);
        #endif
    }
    else if ((rx_int_state & SCI_IF_RX_FULL) != 0x00U)
    {
        (void)sci_data_get (SCI1);
    }
    else if ((rx_int_state & SCI_IF_RX_EDGE) != 0x00U)
    {
        sci_rx_edge_int_flag_clr (SCI1);
    }
    else
    {
        (void)sci_data_get (SCI1);
    }
    #endif
}
#endif

#ifdef BF7x06AMxx_TIMER_DRIVER_PRESENT
/*!
    \brief      timer0 handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void TIMER0_IRQHandler (void)
{
    //1KHz, for sys tick
    extern uint32_t systick_ms;
    systick_ms ++;
    timer_intflag_clr (TIMER0);
}

/*!
    \brief      timer1 handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void TIMER1_IRQHandler (void)
{
    //10KHz, for soft pwm, 100us

//    extern uint32_t pwmtime; //5day
//    pwmtime ++;
    timer_intflag_clr (TIMER1);
}
#endif

#ifdef BF7x06AMxx_PWM_DRIVER_PRESENT
/*!
    \brief      pwm over flow handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PWM_TOF_IRQHandler (void)
{
    pwm_tof_clr();
}

/*!
    \brief      pwm channel 0 handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PWM_CH0_IRQHandler (void)
{
    pwm_ch0_if_clr();
}

/*!
    \brief      pwm channel 1 handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PWM_CH1_IRQHandler (void)
{
    pwm_ch1_if_clr();
}

/*!
    \brief      pwm channel 2 handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PWM_CH2_IRQHandler (void)
{
    pwm_ch2_if_clr();
}

/*!
    \brief      pwm channel 3 handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PWM_CH3_IRQHandler (void)
{
    pwm_ch3_if_clr();
}

/*!
    \brief      pwm channel 4 handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PWM_CH4_IRQHandler (void)
{
    pwm_ch4_if_clr();
}

/*!
    \brief      pwm channel 5 handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PWM_CH5_IRQHandler (void)
{
    pwm_ch5_if_clr();
}
#endif

#ifdef BF7x06AMxx_RTC_DRIVER_PRESENT
/*!
    \brief      rtc handler
    \param[in]  none
    \param[out] none
    \retval     none
*/

void RTC_IRQHandler (void)
{
    extern uint16_t pluse_100ms;
    extern uint16_t pluse_count;
    extern  uint8_t pluse_flag;
    rtc_int_flag_clr();
    pluse_100ms = pluse_count;
    pluse_count = 0;
    pluse_flag ++;
}
#endif

#ifdef BF7x06AMxx_CAN_DRIVER_PRESENT
/*!
    \brief      can wake up handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void CAN_WAKE_IRQHandler (void)
{
    (void)can_interrupt_flag_get();
    can_int_flag_clr (CAN_IF_WUPI);
}

/*!
    \brief      can error handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void CAN_ERR_IRQHandler (void)
{
    uint8_t state;
    state = can_interrupt_flag_get();
    (void)can_read_frame_error_code();
    if ((state & CAN_IF_BEI) != 0x00U)          /* bus error */
    {
        can_int_flag_clr (CAN_IF_BEI);
    }
    if ((state & CAN_IF_ALI) != 0x00U)          /* arbitration lost */
    {
        (void)can_read_arbitration_lost_code();
        can_int_flag_clr (CAN_IF_ALI);
    }
    if ((state & CAN_IF_EPI) != 0x00U)          /* error passive */
    {
        can_int_flag_clr (CAN_IF_EPI);
    }
    if ((state & CAN_IF_DOI) != 0x00U)          /* data overflow */
    {
        can_int_flag_clr (CAN_IF_DOI);
    }
    if ((state & CAN_IF_EI) != 0x00U)           /* error interrupt or bus state change */
    {
        if ((can_status_get() & CAN_SR_BS) == CAN_BUS_OFF)  //can bus off
        {					
        }
        can_int_flag_clr (CAN_IF_EI);
    }
}


/*!
    \brief      can rx handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void CAN_RX_IRQHandler (void)
{
		extern void can_isr();
    (void)can_interrupt_flag_get();
		can_isr();
    can_int_flag_clr (CAN_IF_RI);
}

/*!
    \brief      can tx handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void CAN_TX_IRQHandler (void)
{
    (void)can_interrupt_flag_get();
    can_int_flag_clr (CAN_IF_TI);
}
#endif

#ifdef BF7x06AMxx_GPIO_DRIVER_PRESENT
/*!
    \brief      gpioA/B/D interrupt handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void GPIO_IRQHandler (void)
{
    extern uint16_t pluse_count;
    uint8_t stateD = get_gpio_port_interrupt_state ((uint32_t)GPIOD);

    // count pluse
    //pluse_count ++;

    clr_gpio_interrupt_state ((uint32_t)GPIOD, stateD);
}
#endif

#ifdef BF7x06AMxx_ADC_DRIVER_PRESENT
/*!
    \brief      ADC interrupt handler
    \param[in]  none
    \param[out] none
    \retval     none
*/
void ADC_IRQHandler (void)
{
    uint16_t temp = adc_data_get();
}
#endif

