/*!
    \file  BF7006AMxx_pwm.c
    \brief pwm driver
*/

/*
    Copyright (C) 2017 Byd

    2017-12-27, V1.0.0, firmware for BF7006AMxx
    2019-11-22, V1.0.2, firmware for BF7006AMxx
    2021-03-03, V1.0.3, fixed problems which may cause by configuration order of pwm control reg and channel value reg
                        now configure mod reg first then sc reg
*/

#include "BF7006AMxx_pwm.h"

/*!
    \brief      pwm initialize 
    \param[in]  pwm_sc: pwm control register
    \param[in]  pwm_mod: pwm mod count 
    \param[out] none
    \retval     none
*/
void pwm_init(uint8_t pwm_sc,uint16_t pwm_mod)
{
    PWM_MOD = pwm_mod;
    PWM_SC = pwm_sc;
    if((pwm_sc & PWM_SC_TOIE) != 0U){
        NVIC_EnableIRQ(PWM_TOF_IRQN);
    }else{
        NVIC_DisableIRQ(PWM_TOF_IRQN);
    }
}

/*!
    \brief      pwm mod count set
    \param[in]  none
    \param[out] none
    \retval    none
*/
void pwm_mod_set(uint16_t mod_count)
{
    PWM_MOD = mod_count;
}

/*!
    \brief      pwm current count get
    \param[in]  none
    \param[out] none
    \retval     pwm current count
*/
uint16_t pwm_get_count(void)
{
    uint32_t rtal;
    rtal = PWM_CNT;
    return (uint16_t)rtal;
}

/*!
    \brief      pwm interrupt flag clear
    \param[in]  none
    \param[out] none
    \retval     none
*/
void pwm_tof_clr(void)
{
    PWM_SC &= ~PWM_SC_TOF;
}

/*!
    \brief      pwm channel 0 initialize 
    \param[in]  pwm_ch_sc: pwm channel 0 control register
    \param[in]  pwm_ch_cnt: pwm channel 0 count  
    \param[out] none
    \retval     none
*/
void pwm_ch0_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt)
{
    PWM_C0V = pwm_ch_cnt;
    PWM_C0SC = pwm_ch_sc;
    if((pwm_ch_sc & PWM_CnSC_IE) != 0U){
        NVIC_EnableIRQ(PWM_CH0_IRQn);
    }else{
        NVIC_DisableIRQ(PWM_CH0_IRQn);
    }
}

/*!
    \brief      pwm channel 0 count set
    \param[in]  none
    \param[out] none
    \retval     none
*/
void pwm_ch0_cnt_set(uint16_t count)
{
    PWM_C0V = count;
}

/*!
    \brief      pwm channel 0 current count get
    \param[in]  none
    \param[out] none
    \retval     pwm channel 0 current count
*/
uint16_t pwm_ch0_get_count(void)
{
    uint32_t rtal;
    rtal = PWM_C0V;
    return (uint16_t)rtal;
}

/*!
    \brief      pwm channel 0 interrupt flag clear
    \param[in]  none
    \param[out] none
    \retval     none
*/
void pwm_ch0_if_clr(void)
{
    PWM_C0SC &= ~PWM_CnSC_IF;
}

/*!
    \brief      pwm channel 1 initialize 
    \param[in]  pwm_ch_sc: pwm channel 1 control register
    \param[in]  pwm_ch_cnt: pwm channel 1 count  
    \param[out] none
    \retval     none
*/
void pwm_ch1_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt)
{
    PWM_C1V = pwm_ch_cnt;
    PWM_C1SC = pwm_ch_sc;
    if((pwm_ch_sc & PWM_CnSC_IE) != 0U){
        NVIC_EnableIRQ(PWM_CH1_IRQn);
    }else{
        NVIC_DisableIRQ(PWM_CH1_IRQn);
    }
}

/*!
    \brief      pwm channel 1 count set
    \param[in]  none
    \param[out] none
    \retval    none
*/
void pwm_ch1_cnt_set(uint16_t count)
{
    PWM_C1V = count;
}


/*!
    \brief      pwm channel 1 current count get
    \param[in]  none
    \param[out] none
    \retval     pwm channel 1 current count
*/
uint16_t pwm_ch1_get_count(void)
{
    uint32_t rtal;
    rtal = PWM_C1V;
    return (uint16_t)rtal;
}

/*!
    \brief      pwm channel 1 interrupt flag clear
    \param[in]  none
    \param[out] none
    \retval     none
*/
void pwm_ch1_if_clr(void)
{
    PWM_C1SC &= ~PWM_CnSC_IF;
}

/*!
    \brief      pwm channel 2 initialize 
    \param[in]  pwm_ch_sc: pwm channel 2 control register
    \param[in]  pwm_ch_cnt: pwm channel 2 count  
    \param[out] none
    \retval     none
*/
void pwm_ch2_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt)
{
    PWM_C2V = pwm_ch_cnt;
    PWM_C2SC = pwm_ch_sc;
    if((pwm_ch_sc & PWM_CnSC_IE) != 0U){
        NVIC_EnableIRQ(PWM_CH2_IRQn);
    }else{
        NVIC_DisableIRQ(PWM_CH2_IRQn);
    }
}

/*!
    \brief      pwm channel 2 count set
    \param[in]  none
    \param[out] none
    \retval    none
*/
void pwm_ch2_cnt_set(uint16_t count)
{
    PWM_C2V = count;
}

/*!
    \brief      pwm channel 2 current count get
    \param[in]  none
    \param[out] none
    \retval     pwm channel 2 current count
*/
uint16_t pwm_ch2_get_count(void)
{
    uint32_t rtal;
    rtal = PWM_C2V;
    return (uint16_t)rtal;
}

/*!
    \brief      pwm channel 2 interrupt flag clear
    \param[in]  none
    \param[out] none
    \retval     none
*/
void pwm_ch2_if_clr(void)
{
    PWM_C2SC &= ~PWM_CnSC_IF;
}

/*!
    \brief      pwm channel 3 initialize 
    \param[in]  pwm_ch_sc: pwm channel 3 control register
	\param[in]	pwm_ch_cnt: pwm channel 3 count  
    \param[out] none
    \retval     none
*/
void pwm_ch3_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt)
{
    PWM_C3V = pwm_ch_cnt;
    PWM_C3SC = pwm_ch_sc;
    if((pwm_ch_sc & PWM_CnSC_IE) != 0U){
        NVIC_EnableIRQ(PWM_CH3_IRQn);
    }else{
        NVIC_DisableIRQ(PWM_CH3_IRQn);
    }
}

/*!
    \brief      pwm channel 3 count set
    \param[in]  none
    \param[out] none
    \retval    none
*/
void pwm_ch3_cnt_set(uint16_t count)
{
    PWM_C3V = count;
}

/*!
    \brief      pwm channel 3 current count get
    \param[in]  none
    \param[out] none
    \retval     pwm channel 3 current count
*/
uint16_t pwm_ch3_get_count(void)
{
    uint32_t rtal;
    rtal = PWM_C3V;
    return (uint16_t)rtal;
}

/*!
    \brief      pwm channel 3 interrupt flag clear
    \param[in]  none
    \param[out] none
    \retval     none
*/
void pwm_ch3_if_clr(void)
{
    PWM_C3SC &= ~PWM_CnSC_IF;
}

/*!
    \brief      pwm channel 4 initialize 
    \param[in]  pwm_ch_sc: pwm channel 4 control register
    \param[in]  pwm_ch_cnt: pwm channel 4 count  
    \param[out] none
    \retval     none
*/
void pwm_ch4_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt)
{
    PWM_C4V = pwm_ch_cnt;
    PWM_C4SC = pwm_ch_sc;
    if((pwm_ch_sc & PWM_CnSC_IE) != 0U){
        NVIC_EnableIRQ(PWM_CH4_IRQn);
    }else{
        NVIC_DisableIRQ(PWM_CH4_IRQn);
    }
}

/*!
    \brief      pwm channel 4 count set
    \param[in]  none
    \param[out] none
    \retval    none
*/
void pwm_ch4_cnt_set(uint16_t count)
{
    PWM_C4V = count;
}

/*!
    \brief      pwm channel 4 current count get
    \param[in]  none
    \param[out] none
    \retval     pwm channel 4 current count
*/
uint16_t pwm_ch4_get_count(void)
{
    uint32_t rtal;
    rtal = PWM_C4V;
    return (uint16_t)rtal;
}

/*!
    \brief      pwm channel 4 interrupt flag clear
    \param[in]  none
    \param[out] none
    \retval     none
*/
void pwm_ch4_if_clr(void)
{
    PWM_C4SC &= ~PWM_CnSC_IF;
}

/*!
    \brief      pwm channel 5 initialize 
    \param[in]  pwm_ch_sc: pwm channel 5 control register
    \param[in]  pwm_ch_cnt: pwm channel 5 count  
    \param[out] none
    \retval     none
*/
void pwm_ch5_init(uint8_t pwm_ch_sc,uint16_t pwm_ch_cnt)
{
    PWM_C5V = pwm_ch_cnt;
    PWM_C5SC = pwm_ch_sc;
    if((pwm_ch_sc & PWM_CnSC_IE) != 0U){
        NVIC_EnableIRQ(PWM_CH5_IRQn);
    }else{
        NVIC_DisableIRQ(PWM_CH5_IRQn);
    }
}

/*!
    \brief      pwm channel 5 count set
    \param[in]  none
    \param[out] none
    \retval    none
*/
void pwm_ch5_cnt_set(uint16_t count)
{
    PWM_C5V = count;
}

/*!
    \brief      pwm channel 5 current count get
    \param[in]  none
    \param[out] none
    \retval     pwm channel 5 current count
*/
uint16_t pwm_ch5_get_count(void)
{
    uint32_t rtal;
    rtal = PWM_C5V;
    return (uint16_t)rtal;
}

/*!
    \brief      pwm channel 5 interrupt flag clear
    \param[in]  none
    \param[out] none
    \retval     none
*/
void pwm_ch5_if_clr(void)
{
    PWM_C5SC &= ~PWM_CnSC_IF;
}
