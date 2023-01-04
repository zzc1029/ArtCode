/*!
    \file  BF7006AMxx_sys.c
    \brief system control driver
*/

/*
    Copyright (C) 2017 Byd

    2017-12-27, V1.0.0, firmware for BF7006AMxx
	2019-11-22, V1.0.2, firmware for BF7006AMxx
    2021-03-03, V1.0.3, add variable SystemCoreClock update function in system_clk_sel(void)
*/

#include "BF7006AMxx_sysctrl.h"

volatile uint8_t xtal_timeout = 0;
/*!
    \brief      sci1 port select 
    \param[in]  port_sel: SCI1_PF0_PF1,SCI1_PE2_PE3,SCI1_PE6_PE7
    \param[out] none
    \retval     none
*/
void sci1_port_sel(uint8_t port_sel)
{
    SYS_PTSEL = port_sel;
}

/*!
    \brief      system clock select
    \param[in]  pll_source_sel: pll source clock select
                    SYS_PLL_SEL_RC1M: pll source clock select rc_1M
                    SYS_PLL_SEL_XTAL_16M: pll source clock select xtal/16
                    SYS_PLL_SEL_XTAL_12M: pll source clock select xtal/12
                    SYS_PLL_SEL_XTAL_8M: pll source clock select xtal/8
    \param[in]  clk_sel: clock select
                    SYS_CLK_PLL_32M: system clock select pll 32M hz
                    SYS_CLK_PLL_16M: system clock select pll 16M hz
                    SYS_CLK_PLL_8M: system clock select pll 8M hz
                    SYS_CLK_XTAL: system clock select xtal
    \param[out] none
    \retval     none
*/
void system_clk_sel(uint32_t pll_source_sel,uint32_t clk_sel,uint8_t xtal_freq)
{
    ErrorStatus rval;
    if((pll_source_sel == SYS_PLL_SEL_RC1M) && (clk_sel != SYS_CLK_XTAL)){
        SYS_PLL_SOURCE_SEL = pll_source_sel;
        SYS_CLK_SEL = clk_sel;
        if(clk_sel == SYS_CLK_32M){
            SystemCoreClock = (uint32_t)32000000;
        }else if(clk_sel == SYS_CLK_16M){
            SystemCoreClock = (uint32_t)16000000;
        }else if(clk_sel == SYS_CLK_8M){
            SystemCoreClock = (uint32_t)8000000;
        }
    }else{
        if(xtal_freq == 0x01U){
            SystemCoreClock = (uint32_t)16000000;
        }else if(xtal_freq == 0x02U){
            SystemCoreClock = (uint32_t)12000000;
        }else if(xtal_freq == 0x03U){
            SystemCoreClock = (uint32_t)8000000;
        }
        if((SYS_XTAL_CTRL & SYS_XTAL_CTRL_INIT) == 0U){
            rval = xtal_init();
            if(rval == ERROR){
                pll_source_sel = SYS_PLL_SEL_RC1M;
                if(xtal_freq == 0x01U){
                    clk_sel = SYS_CLK_16M;
                }else if(xtal_freq == 0x02U){
                    clk_sel = SYS_CLK_16M;
                    SystemCoreClock = (uint32_t)16000000;
                }else if(xtal_freq == 0x03U){
                    clk_sel = SYS_CLK_8M;
                }else{
                    clk_sel = SYS_CLK_32M;
                    SystemCoreClock = (uint32_t)32000000;
                }
            }
        }
        SYS_PLL_SOURCE_SEL = pll_source_sel;
        SYS_CLK_SEL = clk_sel;
    }
}

/*!
    \brief      xtal initiliaze
                if xtal initiliaze success,enable xtal invalid check
                if xtal initiliaze fail,return error to change clock select
    \param[in]  none
    \param[out] none
    \retval     ERROR:xtal initiliaze fail,SUCCESS:xtal initiliaze success
*/
ErrorStatus xtal_init(void)
{
    uint32_t timeout = 300000U;
    SYS_XTAL_CTRL |= SYS_XTAL_CTRL_EN;
    SYS_INTEN |= SYS_INTEN_XTALINIT;
    NVIC_EnableIRQ(SYS_IRQn);
    SYS_XTAL_INIT = 0x00U;
    SYS_XTAL_INIT &= ~SYS_XTAL_INIT_RSTEN;
    SYS_XTAL_INIT |= SYS_XTAL_INIT_EN;
    xtal_timeout = 0U;
    while(timeout != 0x00U){
        timeout --;
        if((SYS_XTAL_CTRL & SYS_XTAL_CTRL_INIT) != 0x00U){  //xtal initialize success then enable xtal invalid check
            SYS_XTAL_CHK = 0x00U;
            SYS_XTAL_CHK |= SYS_XTAL_CHK_EN;
            SYS_XTAL_CHK |= SYS_XTAL_CHK_RSTEN;
            SYS_INTEN |= SYS_INTEN_XTALCHK;
            SYS_XTAL_INIT |= SYS_XTAL_INIT_RSTEN;
            SYS_XTAL_INIT |= SYS_XTAL_INIT_EN;
            SYS_INTEN |= SYS_INTEN_XTALINIT;
            return SUCCESS;
        }
        if(xtal_timeout != 0x00U){
            SYS_XTAL_CTRL &= ~SYS_XTAL_CTRL_EN;             //xtal initialize error then disable xtal
            return ERROR;
        }
    }
    SYS_XTAL_CTRL &= ~SYS_XTAL_CTRL_EN;                     //xtal initialize error then disable xtal
    return ERROR;
}

/*!
    \brief      enable or disable xtal powerdown in sleepdeep mode
    \param[in]  pd_en:ENABLE or DISABLE
    \param[out] none
    \retval     none
*/
void xtal_sleepdeep_pd(FunctionalState pd_en)
{
    if(pd_en == ENABLE){
        SYS_XTAL_CTRL |= SYS_XTAL_CTRL_SLEEPPD;
    }else{
        SYS_XTAL_CTRL &= ~SYS_XTAL_CTRL_SLEEPPD;
    }
}

/*!
    \brief      enable or disable rc128k powerdown 
    \param[in]  pd_en:ENABLE or DISABLE
    \param[out] none
    \retval     none
*/
void rc128k_pd(FunctionalState pd_en)
{
    if(pd_en == ENABLE){
        SYS_CLK_PD |= SYS_CLK_PD_RC128K;
    }else{
        SYS_CLK_PD &= ~SYS_CLK_PD_RC128K;
    }
}

/*!
    \brief      clock out
    \param[in]  clk_source: CLK_OUT_XTAL_DIV_8,CLK_OUT_PLL_DIV_16,CLK_OUT_RC_32K,CLK_OUT_RC_250K
    \param[out] none
    \retval     none
*/
void clock_out(uint8_t clk_source)
{
    if(clk_source > 3U){
        return;
    }
    SYS_CLK_OUT &= 0x37U;
    SYS_CLK_OUT &= ~0x03U;
    SYS_CLK_OUT |= 0x04U;
    SYS_CLK_OUT |= clk_source;
}

/*!
    \brief      clock2 out
    \param[in]  clk2_source: CLK2_OUT_XTAL_DIV_16,CLK2_OUT_RC_250K
    \param[out] none
    \retval     none
*/
void clock2_out(uint8_t clk2_source)
{
    SYS_CLK_OUT &= 0x37U;
    if(clk2_source == CLK2_OUT_XTAL_DIV_16){
        SYS_CLK_OUT &= ~0x30U;
        SYS_CLK_OUT |= clk2_source;
    }else if(clk2_source == CLK2_OUT_RC_250K){
        SYS_CLK_OUT &= ~0x30U;
        SYS_CLK_OUT |= clk2_source;
    }else{
        SYS_CLK_OUT &= ~0x30U;
    }
}

/*!
    \brief      system interrupt vector address offset
    \param[in]  offset_addr: offset address
    \param[out] none
    \retval     none
*/
void system_intvector_offset(uint32_t offset_addr)
{
    SYS_VECTOR_OFFSET = offset_addr;
}

/*!
    \brief      system interrupt config
    \param[in]  int_state: 
                    lower power detect interrupt: SYS_INT_LVDT_ENABLE   or SYS_INT_LVDT_DISABLE
                    eeprom ECC error two bits or more interrupt: SYS_INT_ETER_ENABLE    or SYS_INT_ETER_DISABLE
                    eeprom ECC error one bit interrupt enable: SYS_INT_EOER_ENABLE      or SYS_INT_EOER_DISABLE
                    flash ECC error two bits or more interrupt: SYS_INT_FTER_ENABLE     or SYS_INT_FTER_DISABLE
                    flash ECC error one bit interrupt enable: SYS_INT_FOER_ENABLE       or SYS_INT_FOER_DISABLE
                    eeprom protect range illegal access interrupt: SYS_INT_EPOT_ENABLE  or SYS_INT_EPOT_DISABLE
                    flash protect range illegal access interrupt enable: SYS_INT_FPOT_ENABLE    or SYS_INT_FPOT_DISABLE
                    config bits error interrupt enable: SYS_INT_ADJ_ENABLE  or SYS_INT_ADJ_DISABLE
    \param[out] none
    \retval     none
*/
void system_int_cfg(uint8_t int_state,FunctionalState en_state)
{
    SYS_INTEN = int_state;
    if(en_state == ENABLE){
        NVIC_EnableIRQ(SYS_IRQn);
    }else{
        NVIC_DisableIRQ(SYS_IRQn);
    }
}

/*!
    \brief      system interrupt flag get
    \param[in]  none
    \param[out] none
    \retval     system interrupt flag
*/
uint16_t system_intflg_get(void)
{
    uint32_t retal;
    retal = SYS_INTFLG;
    return (uint16_t)retal;
}

/*!
    \brief      system interrupt flag clear
    \param[in]  int_flg: system interrupt flag
    \param[out] none
    \retval     none
*/
void system_intflg_clr(uint16_t int_flg)
{
    SYS_INTFLG = int_flg;
}

/*!
    \brief      lvdt initialize
    \param[in]  lvdt_en: lvdt enable
    \param[in]  lvdt_vol_gear: lvdt voltage gear
    \param[in]  int_en: lvdt interrupt enable
    \param[out] none
    \retval     none
*/
void lvdt_init(FunctionalState lvdt_en,uint8_t lvdt_vol_gear,FunctionalState int_en)
{
    if(lvdt_en == ENABLE){
        if(lvdt_vol_gear > 3U){
            return ;
        }
        lvdt_enable();
        SYS_LVDT_CRL &= ~0x03U;
        SYS_LVDT_CRL |= lvdt_vol_gear;
        if(int_en == ENABLE){
            SYS_LVDT_IE = 0x01U;
            NVIC_EnableIRQ(LVDT_IRQn);
        }else{
            SYS_LVDT_IE = 0x00U;
            NVIC_DisableIRQ(LVDT_IRQn);
        }
    }else{
        lvdt_disable();
    }
}

/*!
    \brief      lvdt enable
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lvdt_enable(void)
{
    SYS_CLK_PD &= ~SYS_CLK_PD_LVDT;
}

/*!
    \brief      lvdt disable
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lvdt_disable(void)
{
    SYS_CLK_PD |= SYS_CLK_PD_LVDT;
}

/*!
    \brief      lvdt interrput flag get
    \param[in]  none
    \param[out] none
    \retval     interrupt flag
*/
uint8_t lvdt_int_flag_get(void)
{
    uint32_t rtal;
    rtal = SYS_LVDT_IF;
    return (uint8_t)rtal;
}

/*!
    \brief      lvdt interrput flag clear
    \param[in]  int_flag: interrupt flag,boost flag or buck flag
    \param[in]  int_en: lvdt interrupt enable
    \param[out] none
    \retval     none
*/
void lvdt_int_flag_clr(uint8_t int_flag)
{
    SYS_LVDT_IF = int_flag;
}

/*!
    \brief      bor initialize 
    \param[in]  bor_en: enable or disable bor 
    \param[in]  filter_en: enable or disable bor filter 100us
    \param[out] none
    \retval     none
*/
void bor_init(FunctionalState bor_en,FunctionalState filter_en)
{
    if(bor_en == ENABLE){
        bor_enbale();
        if(filter_en == ENABLE){
            bor_filter_enbale();
        }else{
            bor_filter_disable();
        }
    }else{
        bor_disable();
    }
}

/*!
    \brief      bor enable
    \param[in]  none
    \param[out] none
    \retval     none
*/
void bor_enbale(void)
{
    SYS_CLK_PD &= ~SYS_CLK_PD_BOR;
}

/*!
    \brief      bor disable
    \param[in]  none
    \param[out] none
    \retval     none
*/
void bor_disable(void)
{
    SYS_CLK_PD |= SYS_CLK_PD_BOR;
}

/*!
    \brief      bor filter 100us enable
    \param[in]  none
    \param[out] none
    \retval     none
*/
void bor_filter_enbale(void)
{
    SYS_LVDT_CRL |= 0x04U;
}

/*!
    \brief      bor filter 100us disable
    \param[in]  none
    \param[out] none
    \retval     none
*/
void bor_filter_disable(void)
{
    SYS_LVDT_CRL &= ~0x04U;
}


/*!
    \brief      reset pin filter enable or disable
    \param[in]  filter_en: ENABLE or DISABLE
    \param[out] none
    \retval     none
*/
void reset_filter(FunctionalState filter_en)
{
    SYS_EXRST = 0x01U;
    if(filter_en == ENABLE){
        SYS_EXFLT = 0x01U;
    }else{
        SYS_EXFLT = 0x00U;
    }
}

/*!
    \brief      reset flag get
    \param[in]  none
    \param[out] none
    \retval     reset flag
*/
uint16_t rst_flag_get(void)
{
	uint32_t rtal;
	rtal = SYS_RSTSTAT;
	return (uint16_t)rtal;
}


/*!
    \brief      reset flag clear
    \param[in]  rst_flag: reset flag
    \param[out] none
    \retval     none
*/
void rst_flag_clr(uint16_t rst_flag)
{
    SYS_RSTSTAT = rst_flag;
}

