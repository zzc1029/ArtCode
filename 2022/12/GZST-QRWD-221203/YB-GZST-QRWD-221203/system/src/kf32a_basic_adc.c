/**
  ******************************************************************************
  * �ļ���  kf32a_basic_adc.c
  * ��  ��  ChipON_AE/FAE_Group
  * ��  ��  V2.62
  * ��  ��  2019-11-16
  * ��  ��  ���ļ��ṩ��ģ��ת��ģ��(ADC)���蹦�ܺ�����������
  *          + ģ��ת��ģ��(ADC)��ʼ������
  *          + ģ��ת��ģ��(ADC)ģ�⿴�Ź���ʼ������
  *          + ģ��ת��ģ��(ADC)���ƹ������ú���
  *          + ģ��ת��ģ��(ADC)����ͨ���������ú���
  *          + ģ��ת��ģ��(ADC)�����ȼ�ͨ���������ú���
  *          + ģ��ת��ģ��(ADC)�жϹ�����
  *
  *********************************************************************
  */

#include "kf32a_basic_adc.h"
#include "kf32a_basic_rst.h"
#include "kf32a_basic_pclk.h"


/* ģ��ת��ģ��(ADC)˽�ж��� -------------------------------------------------*/

/* ADCx_CTL0�Ĵ�����ʼ���������� */
#define ADC_CTL0_INIT_MASK             (ADC_CTL0_CLKS \
                                       | ADC_CTL0_ADCCLKS \
                                       | ADC_CTL0_SCANEN \
                                       | ADC_CTL0_CONT \
                                       | ADC_CTL0_LR)

/* ADCx_CTL0�Ĵ���ģ�⿴�Ź��������� */
#define ADC_CTL0_AWDMODE_MASK           (ADC_CTL0_WDSCH \
                                       | ADC_CTL0_HPWDEN \
                                       | ADC_CTL0_WDEN)

/* ADCx_CTL1�Ĵ�����ʼ���������� */
#define ADC_CTL1_INIT_MASK              (ADC_CTL1_EXTEN \
                                       | ADC_CTL1_HPEXTEN \
                                       | ADC_CTL1_NCH \
                                       | ADC_CTL1_HCH \
                                       | ADC_CTL1_REF)

/* ADC0_DELAY�Ĵ�����ʼ���������� */
#define ADC0_DELAY_INIT_MASK            (ADC0_DELAY_FDELAY \
                                       | ADC0_DELAY_SDELAY)


/**
  *   ##### ģ��ת��ģ��(ADC)��ʼ������ #####
  */
/**
  * ����  ��λADC���裬ʹ������ʱ�ӡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  * ����  �ޡ�
  */
void
ADC_Reset (ADC_SFRmap* ADCx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));

#ifdef KF32A_Periph_adc0
    if (ADCx == ADC0_SFR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_ADC0RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_ADC0RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_ADC0CLKEN, TRUE);
    }
#endif
#ifdef KF32A_Periph_adc1
    if (ADCx == ADC1_SFR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_ADC1RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_ADC1RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_ADC1CLKEN, TRUE);
    }
#endif
#ifdef KF32A_Periph_adc2
    if (ADCx == ADC2_SFR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_ADC2RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_ADC2RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_ADC2CLKEN, TRUE);
    }
#endif
}

/**
  * ����  ģ��ת��ģ��(ADC)��ʼ�����á�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       adcInitStruct: ADCģ��������Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void
ADC_Configuration (ADC_SFRmap* ADCx, ADC_InitTypeDef* adcInitStruct)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_CLK(adcInitStruct->m_Clock));
    CHECK_RESTRICTION(CHECK_ADC_CLK_DIV(adcInitStruct->m_ClockDiv));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(adcInitStruct->m_ScanMode));
    CHECK_RESTRICTION(CHECK_ADC_CONV_MODE(adcInitStruct->m_ContinuousMode));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(adcInitStruct->m_ExternalTrig_EN));
    CHECK_RESTRICTION(CHECK_ADC_EXT_TRIG(adcInitStruct->m_ExternalTrig));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(adcInitStruct->m_HPExternalTrig_EN));
    CHECK_RESTRICTION(CHECK_ADC_HPEXT_TRIG(adcInitStruct->m_HPExternalTrig));
    CHECK_RESTRICTION(CHECK_ADC_DATA_ALIGN(adcInitStruct->m_DataAlign));
    CHECK_RESTRICTION(CHECK_ADC_REF(adcInitStruct->m_VoltageRef));
    CHECK_RESTRICTION(CHECK_ADC_REGULAR_LENGTH(adcInitStruct->m_NumOfConv));
    CHECK_RESTRICTION(CHECK_ADC_HIGH_PRIORITY_LENGTH(adcInitStruct->m_NumOfHPConv));

    /*---------------- ����ADC_CTL0�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_Clock������CLKSλ�� */
    /* ���ݽṹ���Աm_ClockDiv������ADCCLKSλ�� */
    /* ���ݽṹ���Աm_ScanMode������SCANENλ�� */
    /* ���ݽṹ���Աm_ContinuousMode������CONTλ�� */
    /* ���ݽṹ���Աm_DataAlign������LRλ�� */
    tmpreg = (uint32_t)(adcInitStruct->m_Clock | \
                        adcInitStruct->m_ClockDiv | \
                        ((uint32_t)adcInitStruct->m_ScanMode << 17) | \
                        adcInitStruct->m_ContinuousMode | \
                        adcInitStruct->m_DataAlign
                        );
    ADCx->CTL0 = SFR_Config (ADCx->CTL0, ~ADC_CTL0_INIT_MASK, tmpreg);

    /*---------------- ����ADC_CTL1�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_ExternalTrig_EN������EXTENλ�� */
    /* ���ݽṹ���Աm_HPExternalTrig_EN������HPEXTENλ�� */
    /* ���ݽṹ���Աm_ExternalTrig������NCHλ�� */
    /* ���ݽṹ���Աm_HPExternalTrig������HCHλ�� */
    /* ���ݽṹ���Աm_VoltageRef������REFλ�� */
    tmpreg = (uint32_t)(((uint32_t)adcInitStruct->m_ExternalTrig_EN << 11) | \
                         ((uint32_t)adcInitStruct->m_HPExternalTrig_EN << 27) | \
                         adcInitStruct->m_ExternalTrig | \
                         adcInitStruct->m_HPExternalTrig | \
                         adcInitStruct->m_VoltageRef);
    ADCx->CTL1 = SFR_Config (ADCx->CTL1, ~ADC_CTL1_INIT_MASK, tmpreg);

    /*---------------- ����ADC_SCANSQ3�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_NumOfConv������SLENλ�� */
    tmpreg = (adcInitStruct->m_NumOfConv - 1) << 28;
    ADCx->SCANSQ3 = SFR_Config (ADCx->SCANSQ3,
                                  ~ADC_SCANSQ3_SLEN,
                                  tmpreg);

    /*---------------- ����ADC_HSCANSQ�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_NumOfHPConv������HSLENλ�� */
    tmpreg = (adcInitStruct->m_NumOfHPConv - 1) << 28;
    ADCx->HSCANSQ = SFR_Config (ADCx->HSCANSQ,
                                  ~ADC_HSCANSQ_HSLEN,
                                  tmpreg);
}

/**
  * ����  ��ʼ��ADC������Ϣ�ṹ�塣
  * ����  adcInitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void
ADC_Struct_Init (ADC_InitTypeDef* adcInitStruct)
{
    /* ��ʼ�� ADCʱ��Դѡ�� */
    adcInitStruct->m_Clock = ADC_SCLK;

    /* ��ʼ�� ADCʱ�ӷ�Ƶ */
    adcInitStruct->m_ClockDiv = ADC_CLK_DIV_2;

    /* ��ʼ�� ADCɨ��ģʽʹ�� */
    adcInitStruct->m_ScanMode = FALSE;

    /* ��ʼ�� ADC����ת��ģʽ */
    adcInitStruct->m_ContinuousMode = ADC_SINGLE_MODE;

    /* ��ʼ�� ADCת����������ʽ */
    adcInitStruct->m_DataAlign = ADC_DATAALIGN_LEFT;

    /* ��ʼ�� ADC����ͨ���ⲿ����ת��ģʽʹ�� */
    adcInitStruct->m_ExternalTrig_EN = FALSE;

    /* ��ʼ�� ADC����ͨ���ⲿ�����¼� */
    adcInitStruct->m_ExternalTrig = ADC_EXTERNALTRIG_CCP1_CH1;

    /* ��ʼ�� ADC�����ȼ�ͨ���ⲿ����ת��ģʽʹ�� */
    adcInitStruct->m_HPExternalTrig_EN = FALSE;

    /* ��ʼ�� �����ȼ�ͨ���ⲿ�����¼� */
    adcInitStruct->m_HPExternalTrig = ADC_HPEXTERNALTRIG_CCP1_CH1;

    /* ��ʼ�� ADC�ο���ѹѡ�� */
    adcInitStruct->m_VoltageRef = ADC_REF_AVDD;

    /* ��ʼ�� ADC����ͨ��ɨ�賤�� */
    adcInitStruct->m_NumOfConv = 1;

    /* ��ʼ�� ADC�����ȼ�ͨ��ɨ�賤�� */
    adcInitStruct->m_NumOfHPConv = 1;
}

/**
  * ����  ADC0_DELAY��ʼ�����á�
  * ����  adc0Delay: ADC0��������ģʽ��Ϣ�ṹ�塣
  * ����  �ޡ�
  */
void
ADC_Delay_Configuration (ADC0_DELAY_InitTypeDef* adc0Delay)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_FDELAY_MODE(adc0Delay->m_FastDelay));
    CHECK_RESTRICTION(CHECK_ADC_SDELAY_MODE(adc0Delay->m_SlowDelay));

    /*---------------- ����ADC0_DELAY�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_SlowDelay������SDELAYλ�� */
    /* ���ݽṹ���Աm_FastDelay������FDELAYλ�� */
    tmpreg = (((uint32_t)(adc0Delay->m_SlowDelay - 1) << 16) | \
              ((uint32_t)(adc0Delay->m_FastDelay - 1)));
#ifdef KF32A_Periph_adc0
    ADC0_DELAY = SFR_Config (ADC0_DELAY,
                               ~ADC0_DELAY_INIT_MASK,
                               tmpreg);
#endif
}

/**
  * ����  ��ʼ��ADC0��������ģʽ��Ϣ�ṹ�塣
  * ����  adc0Delay: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void
ADC_Delay_Struct_Init (ADC0_DELAY_InitTypeDef* adc0Delay)
{
    /* ��ʼ�� ADC���ٽ���ģʽ��ʱʱ�� */
    adc0Delay->m_FastDelay = 0x06;

    /* ��ʼ�� ADC���ٽ���ģʽ��ʱʱ�� */
    adc0Delay->m_SlowDelay = 0x0D;
}

/**
  * ����  ����ADC����ʹ�ܡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       NewState: ADC����ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        /* ʹ��A/Dת��ģ�� */
        SFR_SET_BIT_ASM(ADCx->CTL0, ADC_CTL0_EN_POS);
    }
    else
    {
        /* A/Dת�����ر��Ҳ����Ĺ������� */
        SFR_CLR_BIT_ASM(ADCx->CTL0, ADC_CTL0_EN_POS);
    }
}
/**
  *   ##### ģ��ת��ģ��(ADC)��ʼ������������� #####
  */


/**
  *   ##### ģ��ת��ģ��(ADC)ģ�⿴�Ź���ʼ������ #####
  */
/**
  * ����  ADCģ�⿴�Ź���ʼ�����á�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       adcAnalogWatchdog: ADCģ�⿴�Ź���Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void
ADC_Analog_Watchdog_Configuration (ADC_SFRmap* ADCx,
                    ADC_WD_InitTypeDef * adcAnalogWatchdog)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_WDSCH(adcAnalogWatchdog->m_WDSingleCH));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(adcAnalogWatchdog->m_HPChannelWDEN));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(adcAnalogWatchdog->m_ChannelWDEN));
    CHECK_RESTRICTION(CHECK_ADC_WDCHANNEL(adcAnalogWatchdog->m_WDChannel));
    CHECK_RESTRICTION(CHECK_ADC_THRESHOLD(adcAnalogWatchdog->m_Threshold_H));
    CHECK_RESTRICTION(CHECK_ADC_THRESHOLD(adcAnalogWatchdog->m_Threshold_L));

    /*---------------- ����ADC_CTL0�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_WDSingleCH������WDSCHλ�� */
    /* ���ݽṹ���Աm_HPChannelWDEN������HPWDENλ�� */
    /* ���ݽṹ���Աm_ChannelWDEN������WDENλ�� */
    tmpreg = (uint32_t)(adcAnalogWatchdog->m_WDSingleCH | \
                  ((uint32_t)adcAnalogWatchdog->m_HPChannelWDEN << 30) | \
                  ((uint32_t)adcAnalogWatchdog->m_ChannelWDEN << 29));
    ADCx->CTL0 = SFR_Config (ADCx->CTL0,
                               ~ADC_CTL0_AWDMODE_MASK,
                               tmpreg);

    /*---------------- ����ADC_SCANSQ3�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_WDChannel������WDCHλ�� */
    tmpreg = adcAnalogWatchdog->m_WDChannel;
    ADCx->SCANSQ3 = SFR_Config (ADCx->SCANSQ3,
                               ~ADC_SCANSQ3_WDCH,
                               tmpreg);

    /*---------------- ����ADC_WDH�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_Threshold_H������WDHλ�� */
    tmpreg = adcAnalogWatchdog->m_Threshold_H;
    ADCx->WDH = SFR_Config (ADCx->WDH,
                              ~ADC_WDH_WDH,
                              tmpreg);

    /*---------------- ����ADC_WDL�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_Threshold_L������WDLλ�� */
    tmpreg = adcAnalogWatchdog->m_Threshold_L;
    ADCx->WDL = SFR_Config (ADCx->WDL,
                              ~ADC_WDL_WDL,
                              tmpreg);
}

/**
  * ����  ��ʼ��ADCģ�⿴�Ź���Ϣ�ṹ�塣
  * ����  adcAnalogWatchdog: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void
ADC_Analog_Watchdog_Struct_Init (ADC_WD_InitTypeDef* adcAnalogWatchdog)
{
    /* ��ʼ�� ADCģ�⿴�Ź���ͨ��ʹ�� */
    adcAnalogWatchdog->m_WDSingleCH = ADC_WD_ALL_CH;

    /* ��ʼ�� ADC�����ȼ�ͨ���Ͽ��Ź�ʹ�� */
    adcAnalogWatchdog->m_HPChannelWDEN = FALSE;

    /* ��ʼ�� ADC����ͨ���Ͽ��Ź�ʹ�� */
    adcAnalogWatchdog->m_ChannelWDEN = FALSE;

    /* ��ʼ�� ADCģ�⿴�Ź�ͨ��ѡ�� */
    adcAnalogWatchdog->m_WDChannel = ADC_WDCH_0;

    /* ��ʼ�� ADCģ�⿴�Ź�����ֵ */
    adcAnalogWatchdog->m_Threshold_H = 0x0;

    /* ��ʼ�� ADCģ�⿴�Ź�����ֵ */
    adcAnalogWatchdog->m_Threshold_L = 0x0;
}
/**
  *   ##### ģ��ת��ģ��(ADC)ģ�⿴�Ź���ʼ������������� #####
  */


/**
  *   ##### ģ��ת��ģ��(ADC)���ƹ������ú��� #####
  */
/**
  * ����  ����ɨ��ģʽ��ģ�⿴�Ź���һͨ��ʹ�ܡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       NewState: ģ�⿴�Ź���һͨ��ʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_Watchdog_Single_Channel_Enable (ADC_SFRmap* ADCx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����ADC_CTL0�Ĵ���WDSCHλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ�ܵ�һͨ�� */
        SFR_SET_BIT_ASM(ADCx->CTL0, ADC_CTL0_WDSCH_POS);
    }
    else
    {
        /* ʹ������ͨ�� */
        SFR_CLR_BIT_ASM(ADCx->CTL0, ADC_CTL0_WDSCH_POS);
    }
}

/**
  * ����  ����ɨ��ģʽʹ�ܡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       NewState: ɨ��ģʽʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_Scan_Mode_Enable (ADC_SFRmap* ADCx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����ADC_CTL0�Ĵ���SCANENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��ɨ��ģʽ */
        SFR_SET_BIT_ASM(ADCx->CTL0, ADC_CTL0_SCANEN_POS);
    }
    else
    {
        /* ��ֹɨ��ģʽ */
        SFR_CLR_BIT_ASM(ADCx->CTL0, ADC_CTL0_SCANEN_POS);
    }
}

/**
  * ����  ���ñȽ������˷�����ο���ѹ����֮һУ׼��
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       NewState: У׼����״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_Bosssel_Comparator_Calibration (ADC_SFRmap* ADCx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����ADC_CTL0�Ĵ���BOSSSELCOMPλ ----------------*/
    if (NewState != FALSE)
    {
        /* У׼���Ƚ�������˵�ѹ��׼ȷ */
        SFR_SET_BIT_ASM(ADCx->CTL0, ADC_CTL0_BOSSSELCOMP_POS);
    }
    else
    {
        /* ��У׼ */
        SFR_CLR_BIT_ASM(ADCx->CTL0, ADC_CTL0_BOSSSELCOMP_POS);
    }
}

/**
  * ����  ���òο���ѹ����֮һ�˷ŵ�ѹУ׼��
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       NewState: У׼����״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_Bosssel_Calibration (ADC_SFRmap* ADCx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����ADC_CTL0�Ĵ���BOSSSELλ ----------------*/
    if (NewState != FALSE)
    {
        /* У׼���˷������ѹ��׼ȷ */
        SFR_SET_BIT_ASM(ADCx->CTL0, ADC_CTL0_BOSSSEL_POS);
    }
    else
    {
        /* ��У׼ */
        SFR_CLR_BIT_ASM(ADCx->CTL0, ADC_CTL0_BOSSSEL_POS);
    }
}

/**
  * ����  ����ƫ�õ���У׼��
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       NewState: У׼����״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_Trim_Current_Intensity_Bias (ADC_SFRmap* ADCx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����ADC_CTL0�Ĵ���TRIMIBIASλ ----------------*/
    if (NewState != FALSE)
    {
        /* У׼��ƫ�õ������ */
        SFR_SET_BIT_ASM(ADCx->CTL0, ADC_CTL0_TRIMIBIAS_POS);
    }
    else
    {
        /* ��У׼ */
        SFR_CLR_BIT_ASM(ADCx->CTL0, ADC_CTL0_TRIMIBIAS_POS);
    }
}

/**
  * ����  ����ADCģ�ⲿ��ʱ�ӷ�Ƶ��ѡ��
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       ClockSelect: ADCģ�ⲿ��ʱ�ӷ�Ƶ�ȣ�ȡֵ��ΧΪ:
  *                      ADC_CLK_DIV_1: T
  *                      ADC_CLK_DIV_2: 1/2T
  *                      ADC_CLK_DIV_4: 1/4T
  *                      ADC_CLK_DIV_8: 1/8T
  *                      ADC_CLK_DIV_16: 1/16T
  *                      ADC_CLK_DIV_32: 1/32T
  *                      ADC_CLK_500KHZ: 500KHz
  * ����  �ޡ�
  */
void
ADC_Analog_Clock_Config (ADC_SFRmap* ADCx, uint32_t ClockSelect)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_CLK_DIV(ClockSelect));

    /*------------- ����ADCx_CTL0�Ĵ���ADCCLKSλ -------------*/
    ADCx->CTL0 = SFR_Config (ADCx->CTL0,
                               ~ADC_CTL0_ADCCLKS,
                               ClockSelect);
}

/**
  * ����  ����A/Dת����������ʽ��
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       DataAlign: ADCת����������ʽ��ȡֵ��ΧΪ��
  *                    ADC_DATAALIGN_LEFT: ת������洢ʱ�����
  *                    ADC_DATAALIGN_RIGHT: ת������洢ʱ�Ҷ���
  * ����  �ޡ�
  */
void
ADC_Data_Align_Config (ADC_SFRmap* ADCx, uint32_t DataAlign)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_DATA_ALIGN(DataAlign));

    /*------------- ����ADCx_CTL0�Ĵ���LRλ -------------*/
    ADCx->CTL0 = SFR_Config (ADCx->CTL0,
                               ~ADC_CTL0_LR,
                               DataAlign);
}

/**
  * ����  ����A/D����ʱ��Դ��
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       ClockSource: ADC����ʱ��Դ��ȡֵ��ΧΪ��
  *                      ADC_SCLK: ѡ��SCLK��ΪA/D����ģ�鹤��ʱ��
  *                      ADC_HFCLK: ѡ��HFCLK��ΪA/D����ģ�鹤��ʱ��
  *                      ADC_LFCLK: ѡ��LFCLK��ΪA/D����ģ�鹤��ʱ��
  * ����  �ޡ�
  */
void
ADC_Clock_Source_Config (ADC_SFRmap* ADCx, uint32_t ClockSource)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_CLK(ClockSource));

    /*------------- ����ADCx_CTL0�Ĵ���CLKSλ -------------*/
    ADCx->CTL0 = SFR_Config (ADCx->CTL0,
                               ~ADC_CTL0_CLKS,
                               ClockSource);
}

/**
  * ����  ����ֱ�Ӵ洢������ģʽʹ�ܡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       NewState: ֱ�Ӵ洢������ģʽʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_Regular_Channel_DMA_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        /* ʹ��DMAģʽ */
        SFR_SET_BIT_ASM(ADCx->CTL0, ADC_CTL0_NDMAEN_POS);
    }
    else
    {
        /* ��ʹ��DMAģʽ */
        SFR_CLR_BIT_ASM(ADCx->CTL0, ADC_CTL0_NDMAEN_POS);
    }
}

/**
  * ����  ����ֱ�Ӵ洢������ģʽʹ�ܡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *          HPChannel: �����ȼ�ͨ��ѡ��ȡֵΪ��
  *                        ADC_HPCH0: �����ȼ�ͨ��0
  *                        ADC_HPCH1: �����ȼ�ͨ��1
  *                        ADC_HPCH2: �����ȼ�ͨ��2
  *                        ADC_HPCH3: �����ȼ�ͨ��3
  *       NewState: ֱ�Ӵ洢������ģʽʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_High_Priority_Channel_DMA_Cmd (ADC_SFRmap* ADCx,
					uint32_t HPChannel,FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_HPCH(HPChannel));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));


    if (NewState != FALSE)
    {
    	ADCx->CTL0 |= HPChannel;
    }
    else
    {
    	ADCx->CTL0 &= ~HPChannel;
    }
}
/**
  * ����  ����˫ADCģʽѡ��
  * ����  WorkMode: ˫ADCģʽ��ȡֵ��ΧΪ��
  *                   ADC_SINGLE: ����ģʽ
  *                   ADC_REGULAR_HPRIORITY: ��ϳ���ͨ��ͬ��+�����ȼ�ͨ��ͬ��ģʽ
  *                   ADC_REGULAR_ALTERNATELY: ��ϳ���ͨ��ͬ��+���津��ģʽ
  *                   ADC_HPRIORITY_FAST_ALTERNATELY: ��ϸ����ȼ�ͨ��ͬ��+���ٽ���ģʽ
  *                   ADC_HPRIORITY_SYNC: �����ȼ�ͬ��ģʽ
  *                   ADC_REGULAR_SYNC: ����ͨ��ͬ��ģʽ
  *                   ADC_FAST_ALTERNATELY_SYNC: ���ٽ���ͬ��
  *                   ADC_SLOW_ALTERNATELY_SYNC: ���ٽ���ͬ��
  *                   ADC_ALTERNATELY_TRIGGER: ���津��ģʽ
  * ����  �ޡ�
  */
void
ADC_Double_Mode_Config (uint32_t WorkMode)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_DOUBLE_MODE(WorkMode));

#ifdef KF32A_Periph_adc0
    /*------------- ����ADC0_CTL1�Ĵ���DOUMODλ -------------*/
    ADC0_CTL1 = SFR_Config (ADC0_CTL1,
                               ~ADC_CTL1_DOUMOD,
                               WorkMode);
#endif
}

/**
  * ����  ����ADC�ο���ѹѡ��
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       RefVoltage: ˫ADCģʽ��ȡֵ��ΧΪ��
  *                     ADC_REF_INTERNAL: �ڲ��ο���ѹ��ΪADת����ѹ
  *                     ADC_REF_VREF: Vref+��ΪADת����ѹ
  *                     ADC_REF_AVDD: AVDD��ΪADת����ѹ
  * ����  �ޡ�
  */
void
ADC_Reference_Voltage_Config (ADC_SFRmap* ADCx, uint32_t RefVoltage)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_REF(RefVoltage));

    /*------------- ����ADCx_CTL1�Ĵ���REFλ -------------*/
    ADCx->CTL1 = SFR_Config (ADCx->CTL1,
                               ~ADC_CTL1_REF,
                               RefVoltage);
}

/**
  * ����  ����ADCģ�⿴�Ź�ͨ��ѡ��
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       Channel: ADCģ�⿴�Ź�ͨ����ȡֵ��ΧΪADC_WDCH_0~ADC_WDCH_25��
  * ����  �ޡ�
  */
void
ADC_Analog_Watchdog_Channel_Config (ADC_SFRmap* ADCx, uint32_t Channel)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_WDCHANNEL(Channel));

    /*------------- ����ADCx_CTL1�Ĵ���WDCHλ -------------*/
    ADCx->SCANSQ3 = SFR_Config (ADCx->SCANSQ3,
                               ~ADC_SCANSQ3_WDCH,
                               Channel);
}
/**
  *   ##### ģ��ת��ģ��(ADC)���ƹ������ú���������� #####
  */


/**
  *   ##### ģ��ת��ģ��(ADC)����ͨ���������ú��� #####
  */
/**
  * ����  ���ó���ͨ���Ͽ��Ź�ʹ�ܡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       NewState: ����ͨ���Ͽ��Ź�ʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_Regular_Channel_Watchdog_Enable (ADC_SFRmap* ADCx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����ADC_CTL0�Ĵ���WDENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ�ܳ���ͨ����ģ�⿴�Ź� */
        SFR_SET_BIT_ASM(ADCx->CTL0, ADC_CTL0_WDEN_POS);
    }
    else
    {
        /* ��ֹ����ͨ����ģ�⿴�Ź� */
        SFR_CLR_BIT_ASM(ADCx->CTL0, ADC_CTL0_WDEN_POS);
    }
}

/**
  * ����  ���ó���ͨ���ⲿ����ת��ģʽʹ�ܡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       NewState: ����ͨ���ⲿ����ת��ģʽʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_External_Trig_Conv_Enable (ADC_SFRmap* ADCx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����ADC_CTL1�Ĵ���EXTENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ���ⲿ�¼�����ת�� */
        SFR_SET_BIT_ASM(ADCx->CTL1, ADC_CTL1_EXTEN_POS);
    }
    else
    {
        /* ��ֹ�ⲿ�¼�����ת�� */
        SFR_CLR_BIT_ASM(ADCx->CTL1, ADC_CTL1_EXTEN_POS);
    }
}

/**
  * ����  ���ó���ͨ���ⲿ�����¼���
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       ExternalTrigEvent: ����ͨ���ⲿ�����¼�ѡ��ȡֵΪ��
  *                            ADC_EXTERNALTRIG_CCP1_CH1: CCP1 ͨ�� 1
  *                            ADC_EXTERNALTRIG_CCP1_CH2: CCP1 ͨ�� 2
  *                            ADC_EXTERNALTRIG_CCP1_CH3: CCP1 ͨ�� 3
  *                            ADC_EXTERNALTRIG_CCP1_CH4: CCP1 ͨ�� 4
  *                            ADC_EXTERNALTRIG_CCP2_CH1: CCP2 ͨ�� 1
  *                            ADC_EXTERNALTRIG_CCP2_CH2: CCP2 ͨ�� 2
  *                            ADC_EXTERNALTRIG_CCP2_CH3: CCP2 ͨ�� 3
  *                            ADC_EXTERNALTRIG_CCP2_CH4: CCP2 ͨ�� 4
  *                            ADC_EXTERNALTRIG_CCP3_CH1: CCP3 ͨ�� 1
  *                            ADC_EXTERNALTRIG_CCP3_CH2: CCP3 ͨ�� 2
  *                            ADC_EXTERNALTRIG_CCP3_CH3: CCP3 ͨ�� 3
  *                            ADC_EXTERNALTRIG_CCP3_CH4: CCP3 ͨ�� 4
  *                            ADC_EXTERNALTRIG_CCP4_CH1: CCP4 ͨ�� 1
  *                            ADC_EXTERNALTRIG_CCP4_CH2: CCP4 ͨ�� 2
  *                            ADC_EXTERNALTRIG_CCP4_CH3: CCP4 ͨ�� 3
  *                            ADC_EXTERNALTRIG_CCP4_CH4: CCP4 ͨ�� 4
  *                            ADC_EXTERNALTRIG_CCP18_CH1: CCP18 ͨ�� 1
  *                            ADC_EXTERNALTRIG_CCP18_CH2: CCP18 ͨ�� 2
  *                            ADC_EXTERNALTRIG_CCP18_CH3: CCP18 ͨ�� 3
  *                            ADC_EXTERNALTRIG_CCP18_CH4: CCP18 ͨ�� 4
  *                            ADC_EXTERNALTRIG_CCP19_CH1: CCP19 ͨ�� 1
  *                            ADC_EXTERNALTRIG_CCP19_CH2: CCP19 ͨ�� 2
  *                            ADC_EXTERNALTRIG_CCP19_CH3: CCP19 ͨ�� 3
  *                            ADC_EXTERNALTRIG_CCP19_CH4: CCP19 ͨ�� 4
  *                            ADC_EXTERNALTRIG_CCP20_CH1: CCP20 ͨ�� 1
  *                            ADC_EXTERNALTRIG_CCP20_CH2: CCP20 ͨ�� 2
  *                            ADC_EXTERNALTRIG_CCP20_CH3: CCP20 ͨ�� 3
  *                            ADC_EXTERNALTRIG_CCP20_CH4: CCP20 ͨ�� 4
  *                            ADC_EXTERNALTRIG_CCP21_CH1: CCP21 ͨ�� 1
  *                            ADC_EXTERNALTRIG_CCP21_CH2: CCP21 ͨ�� 2
  *                            ADC_EXTERNALTRIG_CCP21_CH3: CCP21 ͨ�� 3
  *                            ADC_EXTERNALTRIG_CCP21_CH4: CCP21 ͨ�� 4
  *                            ADC_EXTERNALTRIG_CCP5_CH1: CCP5 ͨ�� 1
  *                            ADC_EXTERNALTRIG_CCP5_CH2: CCP5 ͨ�� 2
  *                            ADC_EXTERNALTRIG_CCP5_CH3: CCP5 ͨ�� 3
  *                            ADC_EXTERNALTRIG_CCP5_CH4: CCP5 ͨ�� 4
  *                            ADC_EXTERNALTRIG_CCP22_CH1: CCP22 ͨ�� 1
  *                            ADC_EXTERNALTRIG_CCP22_CH2: CCP22 ͨ�� 2
  *                            ADC_EXTERNALTRIG_CCP22_CH3: CCP22 ͨ�� 3
  *                            ADC_EXTERNALTRIG_CCP22_CH4: CCP22 ͨ�� 4
  *                            ADC_EXTERNALTRIG_T1TRGO: T1TRGO
  *                            ADC_EXTERNALTRIG_T2TRGO: T2TRGO
  *                            ADC_EXTERNALTRIG_T3TRGO: T3TRGO
  *                            ADC_EXTERNALTRIG_T4TRGO: T4TRGO
  *                            ADC_EXTERNALTRIG_T18TRGO: T18TRGO
  *                            ADC_EXTERNALTRIG_T19TRGO: T19TRGO
  *                            ADC_EXTERNALTRIG_T20TRGO: T20TRGO
  *                            ADC_EXTERNALTRIG_T21TRGO: T21TRGO
  *                            ADC_EXTERNALTRIG_T5TRGO: T5TRGO
  *                            ADC_EXTERNALTRIG_T9TRGO: T9TRGO
  *                            ADC_EXTERNALTRIG_T14TRGO: T14TRGO
  *                            ADC_EXTERNALTRIG_T15TRGO: T15TRGO
  *                            ADC_EXTERNALTRIG_T5_OVERFLOW
  *                            ADC_EXTERNALTRIG_T6_OVERFLOW
  *                            ADC_EXTERNALTRIG_T9_OVERFLOW
  *                            ADC_EXTERNALTRIG_T10_OVERFLOW
  *                            ADC_EXTERNALTRIG_CCP9_CH1
  *                            ADC_EXTERNALTRIG_CCP9_CH2
  *                            ADC_EXTERNALTRIG_CCP9_CH3
  *                            ADC_EXTERNALTRIG_CCP9_CH4
  *                            ADC_EXTERNALTRIG_EINT7: EINT7
  *                            ADC_EXTERNALTRIG_EINT15: EINT15
  *                            ADC_EXTERNALTRIG_CCP0_CH1
  *                            ADC_EXTERNALTRIG_CCP0_CH2
  *                            ADC_EXTERNALTRIG_CCP0_CH3
  *                            ADC_EXTERNALTRIG_CCP0_CH4
  *                            ADC_EXTERNALTRIG_CCP23_CH1
  *                            ADC_EXTERNALTRIG_CCP23_CH2
  *                            ADC_EXTERNALTRIG_CCP23_CH3
  *                            ADC_EXTERNALTRIG_CCP23_CH4
  * ����  �ޡ�
  */
void
ADC_External_Trig_Conv_Config (ADC_SFRmap* ADCx,
                    uint32_t ExternalTrigEvent)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_EXT_TRIG(ExternalTrigEvent));

    /*------------- ����ADCx_CTL1�Ĵ���NCHλ -------------*/
    ADCx->CTL1 = SFR_Config (ADCx->CTL1,
                               ~ADC_CTL1_NCH,
                               ExternalTrigEvent);
}

/**
  * ����  ���ó���ͨ��ɨ�����С�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       Channel: ADCͨ��ѡ��ȡֵ��ΧΪ:
  *                  ADC_CHANNEL_0: ͨ��0---- ADC_CHANNEL_63: ͨ��63
  *       Rank: ����ͨ��ɨ��AD�����ת��λ�ã�ȡֵΪ1~16��
  * ����  �ޡ�
  */
void
ADC_Regular_Channel_Config (ADC_SFRmap* ADCx, uint32_t Channel, uint32_t Rank)
{
    uint32_t tmpreg = 0;
    uint32_t tmpmask = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_ADC_REGULAR_RANK(Rank));

    /* ���õ�1��ת��~��5��ת�� */
    if (Rank < 6)
    {
        /*------------- ����ADCx_SCANSQ0�Ĵ���SSQxλ -------------*/
        tmpreg = (uint32_t)Channel << (6 * (Rank - 1));
        tmpmask = ADC_SCANSQ0_SSQ0 << (6 * (Rank - 1));
        ADCx->SCANSQ0 = SFR_Config (ADCx->SCANSQ0,
                              ~tmpmask,
                              tmpreg);
    }
    /* ���õ�6��ת��~��10��ת�� */
    else if (Rank < 11)
    {
        /*------------- ����ADCx_SCANSQ1�Ĵ���SSQxλ -------------*/
        tmpreg = (uint32_t)Channel << (6 * (Rank - 6));
        tmpmask = ADC_SCANSQ1_SSQ5 << (6 * (Rank - 6));
        ADCx->SCANSQ1 = SFR_Config (ADCx->SCANSQ1,
                              ~tmpmask,
                              tmpreg);
    }
    /* ���õ�11��ת��~��15��ת�� */
    else if (Rank < 16)
    {
        /*------------- ����ADCx_SCANSQ2�Ĵ���SSQxλ -------------*/
        tmpreg = (uint32_t)Channel << (6 * (Rank - 11));
        tmpmask = ADC_SCANSQ2_SSQ10 << (6 * (Rank - 11));
        ADCx->SCANSQ2 = SFR_Config (ADCx->SCANSQ2,
                              ~tmpmask,
                              tmpreg);
    }
    /* ���õ�16��ת�� */
    else
    {
        /*------------- ����ADCx_SCANSQ3�Ĵ���SSQxλ -------------*/
        tmpreg = (uint32_t)Channel << (6 * (Rank - 16));
        tmpmask = ADC_SCANSQ3_SSQ15 << (6 * (Rank - 16));
        ADCx->SCANSQ3 = SFR_Config (ADCx->SCANSQ3,
                              ~tmpmask,
                              tmpreg);
    }
}

/**
  * ����  ���ó���ͨ��ɨ�賤�ȡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       Length: ����ͨ��ɨ�賤�ȣ�ȡֵΪ1~16��
  * ����  �ޡ�
  */
void
ADC_Regular_Sequencer_Length_Config (ADC_SFRmap* ADCx, uint32_t Length)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_REGULAR_LENGTH(Length));

    /*---------------- ����ADC_SCANSQ3�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_NumOfConv������SLENλ�� */
    tmpreg = (Length - 1) << ADC_SCANSQ3_SLEN_0_POS;
    ADCx->SCANSQ3 = SFR_Config (ADCx->SCANSQ3,
                          ~ADC_SCANSQ3_SLEN,
                          tmpreg);
}

/**
  * ����  ���ó������ȼ�ͨ���� Tx_CCRy ����ʹ�ܡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       HPExternalTrigEvent: �������ȼ�ͨ���ⲿ�����¼�ѡ��ȡֵΪ��
  *                              ADC_EXTERNALTRIG_T10_CCR0: �������ȼ�ͨ���� T10_CCR0 ����ʹ��
  *                              ADC_EXTERNALTRIG_T9_CCR1:  �������ȼ�ͨ���� T9_CCR1 ����ʹ��
  *                              ADC_EXTERNALTRIG_T9_CCR0:  �������ȼ�ͨ���� T9_CCR0 ����ʹ��
  *                              ADC_EXTERNALTRIG_T6_CCR0:  �������ȼ�ͨ���� T6_CCR0 ����ʹ��
  *                              ADC_EXTERNALTRIG_T5_CCR1:  �������ȼ�ͨ���� T5_CCR1 ����ʹ��
  *                              ADC_EXTERNALTRIG_T5_CCR0:  �������ȼ�ͨ���� T5_CCR0 ����ʹ��
  *       NewState: ADC�ж�ʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_Regular_Channel_TxCCRy_Trig_Enable (ADC_SFRmap* ADCx,
							 uint32_t ExternalTrigEvent, FunctionalState NewState)
{
    uint32_t tmpreg = 0;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));
    CHECK_RESTRICTION(CHECK_RegularChannel_TxCCRy_Trig(ExternalTrigEvent));

    /* ��ȡ�������� */
    tmpreg = ExternalTrigEvent;
    tmpreg = (uint32_t)0x01 << tmpreg;

    if (NewState != FALSE)
    {
        /* ʹ�ܴ��� */
        ADCx->STATE |= tmpreg;
    }
    else
    {
        /* ��ֹ���� */
        ADCx->STATE &= (~tmpreg);
    }
}

/**
  * ����  �������A/D����ͨ��ת����
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  * ����  �ޡ�
  */
void
ADC_Software_Start_Conv(ADC_SFRmap* ADCx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));

    /*---------------- ����ADC_CTL1�Ĵ���STARTλ ----------------*/
    SFR_SET_BIT_ASM(ADCx->CTL1, ADC_CTL1_START_POS);
}

/**
  * ����  ��������ת��ʹ�ܡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       NewState: ����ת��ʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_Continuous_Mode_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        /* ����ת��ģʽ */
        SFR_SET_BIT_ASM(ADCx->CTL0, ADC_CTL0_CONT_POS);
    }
    else
    {
        /* ����ת��ģʽ */
        SFR_CLR_BIT_ASM(ADCx->CTL0, ADC_CTL0_CONT_POS);
    }
}

/**
  * ����  ���ü��ģʽͨ��������
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       Number: ���ģʽͨ��������ȡֵ��ΧΪ1~8��
  * ����  �ޡ�
  */
void
ADC_Disc_Mode_Channel_Count_Config (ADC_SFRmap* ADCx, uint8_t Number)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_REGULAR_DISC_NUMBER(Number));

    /*---------------- ����ADC_CTL0�Ĵ���DSNUMλ ----------------*/
    tmpreg = (uint32_t)(Number - 1) << ADC_CTL0_DSNUM0_POS;
    ADCx->CTL0 = SFR_Config (ADCx->CTL0,
                               ~ADC_CTL0_DSNUM,
                               tmpreg);
}

/**
  * ����  ���ó���ͨ���ϵļ��ģʽʹ�ܡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       NewState: ����ͨ���ϵļ��ģʽʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_Disc_Mode_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        /* ʹ�ܳ���ͨ���ϵļ��ģʽ */
        SFR_SET_BIT_ASM(ADCx->CTL0, ADC_CTL0_DSEN_POS);
    }
    else
    {
        /* ��ֹ����ͨ���ϵļ��ģʽ */
        SFR_CLR_BIT_ASM(ADCx->CTL0, ADC_CTL0_DSEN_POS);
    }
}

/**
  * ����  ��ȡ����ͨ��ת��������ݡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  * ����  ����ͨ��ת��������ݣ�16λ��Ч���ݡ�
  */
uint16_t
ADC_Get_Conversion_Value (ADC_SFRmap* ADCx)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));

    /*---------------- ����ADC_DATA�Ĵ���DATAλ ----------------*/
    tmpreg = ADCx->DATA;

    return (uint16_t) tmpreg;
}
/**
  *   ##### ģ��ת��ģ��(ADC)����ͨ���������ú���������� #####
  */


/**
  *   ##### ģ��ת��ģ��(ADC)�����ȼ�ͨ���������ú��� #####
  */
/**
  * ����  ���ø����ȼ�ͨ���Ͽ��Ź�ʹ�ܡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       NewState: �����ȼ�ͨ���Ͽ��Ź�ʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_High_Priority_Watchdog_Enable (ADC_SFRmap* ADCx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����ADC_CTL0�Ĵ���HPWDENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ�ܸ����ȼ�ͨ����ģ�⿴�Ź� */
        SFR_SET_BIT_ASM(ADCx->CTL0, ADC_CTL0_HPWDEN_POS);
    }
    else
    {
        /* ��ֹ�����ȼ�ͨ����ģ�⿴�Ź� */
        SFR_CLR_BIT_ASM(ADCx->CTL0, ADC_CTL0_HPWDEN_POS);
    }
}

/**
  * ����  ���ø����ȼ�ͨ���ⲿ����ת��ģʽʹ�ܡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       NewState: �����ȼ�ͨ���ⲿ����ת��ģʽʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_HPExternal_Trig_Conv_Enable (ADC_SFRmap* ADCx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����ADC_CTL1�Ĵ���HPEXTENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ���ⲿ�¼�����ת�� */
        SFR_SET_BIT_ASM(ADCx->CTL1, ADC_CTL1_HPEXTEN_POS);
    }
    else
    {
        /* ��ֹ�ⲿ�¼�����ת�� */
        SFR_CLR_BIT_ASM(ADCx->CTL1, ADC_CTL1_HPEXTEN_POS);
    }
}

/**
  * ����  ���ø����ȼ�ͨ��ɨ�����С�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       Channel: ADCͨ��ѡ��ȡֵ��ΧΪ:
  *                  ADC_CHANNEL_0: ͨ��0--- ADC_CHANNEL_63: ͨ��63
  *       Rank: �����ȼ�ͨ��ɨ��AD�����ת��λ�ã�ȡֵΪ1~4��
  * ����  �ޡ�
  */
void
ADC_High_Priority_Channel_Config (ADC_SFRmap* ADCx,
                    uint32_t Channel, uint32_t Rank)
{
    uint32_t tmpreg = 0;
    uint32_t tmpmask = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_HP_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_ADC_HP_RANK(Rank));

    /* ���õ�1��ת��~��4��ת�� */

    /*------------- ����ADCx_HSCANSQ�Ĵ���HSSQxλ -------------*/
    tmpreg = (uint32_t)Channel << (6 * (Rank - 1));
    tmpmask = ADC_HSCANSQ_SSQ1 << (6 * (Rank - 1));
    ADCx->HSCANSQ = SFR_Config (ADCx->HSCANSQ,
                          ~tmpmask,
                          tmpreg);
}

/**
  * ����  ���ø����ȼ�ͨ��ɨ�賤�ȡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       Length: �����ȼ�ͨ��ɨ�賤�ȣ�ȡֵ��ΧΪ1~4��
  * ����  �ޡ�
  */
void
ADC_High_Priority_Sequencer_Length_Config (ADC_SFRmap* ADCx, uint32_t Length)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_HIGH_PRIORITY_LENGTH(Length));

    /*------------- ����ADCx_HSCANSQ�Ĵ���HSLENλ -------------*/
    tmpreg = (Length - 1) << ADC_HSCANSQ_HSLEN_0_POS;
    ADCx->HSCANSQ = SFR_Config (ADCx->HSCANSQ,
                               ~ADC_HSCANSQ_HSLEN,
                               tmpreg);
}

/**
  * ����  ���ø����ȼ�ͨ��ת���������ƫ�ơ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       HPDoffChannel: �����ȼ�ͨ��ѡ��ȡֵΪ��
  *                        ADC_HPDOFF_0: �����ȼ�ͨ��0
  *                        ADC_HPDOFF_1: �����ȼ�ͨ��1
  *                        ADC_HPDOFF_2: �����ȼ�ͨ��2
  *                        ADC_HPDOFF_3: �����ȼ�ͨ��3
  *       Offset: ת���������ƫ�ƣ�ȡֵΪ12λ��Ч���ݡ�
  * ����  �ޡ�
  */
void
ADC_Set_HPChannel_Conv_Value_Offset (ADC_SFRmap* ADCx,
                    uint32_t HPDoffChannel, uint32_t Offset)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_HPDOFF_OFFSET(HPDoffChannel));
    CHECK_RESTRICTION(CHECK_ADC_OFFSET(Offset));

    /*------------- ����ADCx_HPDOFFy�Ĵ���HPDOFFλ -------------*/
    /* ��ȡADCx_HPDOFFy��ַ */
    tmpreg = (uint32_t)ADCx;
    tmpreg += HPDoffChannel;

    /* ����ADCx_HPDOFFy */
    *(volatile uint32_t *) tmpreg = Offset;
}

/**
  * ����  ���ø����ȼ�ͨ���ⲿ�����¼���
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       HPExternalTrigEvent: �����ȼ�ͨ���ⲿ�����¼�ѡ��ȡֵΪ��
  *                              ADC_HPEXTERNALTRIG_CCP1_CH1: CCP1 ͨ�� 1
  *                              ADC_HPEXTERNALTRIG_CCP1_CH2: CCP1 ͨ�� 2
  *                              ADC_HPEXTERNALTRIG_CCP1_CH3: CCP1 ͨ�� 3
  *                              ADC_HPEXTERNALTRIG_CCP1_CH4: CCP1 ͨ�� 4
  *                              ADC_HPEXTERNALTRIG_CCP2_CH1: CCP2 ͨ�� 1
  *                              ADC_HPEXTERNALTRIG_CCP2_CH2: CCP2 ͨ�� 2
  *                              ADC_HPEXTERNALTRIG_CCP2_CH3: CCP2 ͨ�� 3
  *                              ADC_HPEXTERNALTRIG_CCP2_CH4: CCP2 ͨ�� 4
  *                              ADC_HPEXTERNALTRIG_CCP3_CH1: CCP3 ͨ�� 1
  *                              ADC_HPEXTERNALTRIG_CCP3_CH2: CCP3 ͨ�� 2
  *                              ADC_HPEXTERNALTRIG_CCP3_CH3: CCP3 ͨ�� 3
  *                              ADC_HPEXTERNALTRIG_CCP3_CH4: CCP3 ͨ�� 4
  *                              ADC_HPEXTERNALTRIG_CCP4_CH1: CCP4 ͨ�� 1
  *                              ADC_HPEXTERNALTRIG_CCP4_CH2: CCP4 ͨ�� 2
  *                              ADC_HPEXTERNALTRIG_CCP4_CH3: CCP4 ͨ�� 3
  *                              ADC_HPEXTERNALTRIG_CCP4_CH4: CCP4 ͨ�� 4
  *                              ADC_HPEXTERNALTRIG_CCP18_CH1: CCP18 ͨ�� 1
  *                              ADC_HPEXTERNALTRIG_CCP18_CH2: CCP18 ͨ�� 2
  *                              ADC_HPEXTERNALTRIG_CCP18_CH3: CCP18 ͨ�� 3
  *                              ADC_HPEXTERNALTRIG_CCP18_CH4: CCP18 ͨ�� 4
  *                              ADC_HPEXTERNALTRIG_CCP19_CH1: CCP19 ͨ�� 1
  *                              ADC_HPEXTERNALTRIG_CCP19_CH2: CCP19 ͨ�� 2
  *                              ADC_HPEXTERNALTRIG_CCP19_CH3: CCP19 ͨ�� 3
  *                              ADC_HPEXTERNALTRIG_CCP19_CH4: CCP19 ͨ�� 4
  *                              ADC_HPEXTERNALTRIG_CCP20_CH1: CCP20 ͨ�� 1
  *                              ADC_HPEXTERNALTRIG_CCP20_CH2: CCP20 ͨ�� 2
  *                              ADC_HPEXTERNALTRIG_CCP20_CH3: CCP20 ͨ�� 3
  *                              ADC_HPEXTERNALTRIG_CCP20_CH4: CCP20 ͨ�� 4
  *                              ADC_HPEXTERNALTRIG_CCP21_CH1: CCP21 ͨ�� 1
  *                              ADC_HPEXTERNALTRIG_CCP21_CH2: CCP21 ͨ�� 2
  *                              ADC_HPEXTERNALTRIG_CCP21_CH3: CCP21 ͨ�� 3
  *                              ADC_HPEXTERNALTRIG_CCP21_CH4: CCP21 ͨ�� 4
  *                              ADC_HPEXTERNALTRIG_CCP5_CH1: CCP5 ͨ�� 1
  *                              ADC_HPEXTERNALTRIG_CCP5_CH2: CCP5 ͨ�� 2
  *                              ADC_HPEXTERNALTRIG_CCP5_CH3: CCP5 ͨ�� 3
  *                              ADC_HPEXTERNALTRIG_CCP5_CH4: CCP5 ͨ�� 4
  *                              ADC_HPEXTERNALTRIG_CCP22_CH1: CCP22 ͨ�� 1
  *                              ADC_HPEXTERNALTRIG_CCP22_CH2: CCP22 ͨ�� 2
  *                              ADC_HPEXTERNALTRIG_CCP22_CH3: CCP22 ͨ�� 3
  *                              ADC_HPEXTERNALTRIG_CCP22_CH4: CCP22 ͨ�� 4
  *                              ADC_HPEXTERNALTRIG_T1TRGO: T1TRGO
  *                              ADC_HPEXTERNALTRIG_T2TRGO: T2TRGO
  *                              ADC_HPEXTERNALTRIG_T3TRGO: T3TRGO
  *                              ADC_HPEXTERNALTRIG_T4TRGO: T4TRGO
  *                              ADC_HPEXTERNALTRIG_T18TRGO: T18TRGO
  *                              ADC_HPEXTERNALTRIG_T19TRGO: T19TRGO
  *                              ADC_HPEXTERNALTRIG_T20TRGO: T20TRGO
  *                              ADC_HPEXTERNALTRIG_T21TRGO: T21TRGO
  *                              ADC_HPEXTERNALTRIG_T5TRGO: T5TRGO
  *                              ADC_HPEXTERNALTRIG_T9TRGO: T9TRGO
  *                              ADC_HPEXTERNALTRIG_T14TRGO: T14TRGO
  *                              ADC_HPEXTERNALTRIG_T15TRGO: T15TRGO
  *                              ADC_HPEXTERNALTRIG_T5_OVERFLOW: T5���
  *                              ADC_HPEXTERNALTRIG_T6_OVERFLOW: T6���
  *                              ADC_HPEXTERNALTRIG_T9_OVERFLOW: T9���
  *                              ADC_HPEXTERNALTRIG_T10_OVERFLOW: T10���
  *                              ADC_HPEXTERNALTRIG_CCP9_CH1: CCP9ͨ��1
  *                              ADC_HPEXTERNALTRIG_CCP9_CH2: CCP9ͨ��2
  *                              ADC_HPEXTERNALTRIG_CCP9_CH3: CCP9ͨ��3
  *                              ADC_HPEXTERNALTRIG_CCP9_CH4: CCP9ͨ��4
  *                              ADC_HPEXTERNALTRIG_EINT7: EINT7
  *                              ADC_HPEXTERNALTRIG_EINT15: EINT15
  *                              ADC_HPEXTERNALTRIG_CCP0_CH1_CMP: CCP0_CH1
  *                              ADC_HPEXTERNALTRIG_CCP0_CH2_CMP: CCP0_CH2
  *                              ADC_HPEXTERNALTRIG_CCP0_CH3: CCP0_CH3
  *                              ADC_HPEXTERNALTRIG_CCP0_CH4: CCP0_CH4
  *                              ADC_HPEXTERNALTRIG_CCP23_CH1: CCP23ͨ��1
  *                              ADC_HPEXTERNALTRIG_CCP23_CH2: CCP23ͨ��2
  *                              ADC_HPEXTERNALTRIG_CCP23_CH3: CCP23ͨ��3
  *                              ADC_HPEXTERNALTRIG_CCP23_CH4: CCP23ͨ��4
  * ����  �ޡ�
  */
void
ADC_HPExternal_Trig_Conv_Config (ADC_SFRmap* ADCx,
                    uint32_t HPExternalTrigEvent)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_HPEXT_TRIG(HPExternalTrigEvent));

    /*------------- ����ADCx_CTL1�Ĵ���HCHλ -------------*/
    ADCx->CTL1 = SFR_Config (ADCx->CTL1,
                               ~ADC_CTL1_HCH,
                               HPExternalTrigEvent);
}

/**
  * ����  �������A/D�����ȼ�ͨ��ת����
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  * ����  �ޡ�
  */
void
ADC_Software_HPStart_Conv (ADC_SFRmap* ADCx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));

    /*---------------- ����ADC_CTL1�Ĵ���HPSTARTλ ----------------*/
    SFR_SET_BIT_ASM(ADCx->CTL1, ADC_CTL1_HPSTART_POS);
}

/**
  * ����  �����Զ������ȼ�ͨ����ת��ʹ�ܡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       NewState: �Զ������ȼ�ͨ����ת��ʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_HPAuto_Conv_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        /* ʹ���Զ��ĸ����ȼ�ͨ��ת�� */
        SFR_SET_BIT_ASM(ADCx->CTL0, ADC_CTL0_HPAUTO_POS);
    }
    else
    {
        /* ��ֹ�Զ��ĸ����ȼ�ͨ��ת�� */
        SFR_CLR_BIT_ASM(ADCx->CTL0, ADC_CTL0_HPAUTO_POS);
    }
}

/**
  * ����  ���ø����ȼ�ͨ���ϵļ��ģʽʹ�ܡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       NewState: �����ȼ�ͨ���ϵļ��ģʽʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_HPDisc_Mode_Cmd (ADC_SFRmap* ADCx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        /* ʹ�ܸ����ȼ�ͨ���ϵļ��ģʽ */
        SFR_SET_BIT_ASM(ADCx->CTL0, ADC_CTL0_HPDSEN_POS);
    }
    else
    {
        /* ��ֹ�����ȼ�ͨ���ϵļ��ģʽ */
        SFR_CLR_BIT_ASM(ADCx->CTL0, ADC_CTL0_HPDSEN_POS);
    }
}

/**
  * ����  ��ȡ�����ȼ�ͨ��ת��������ݡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       HPDataChannel: �����ȼ�ͨ��ѡ��ȡֵΪ��
  *                        ADC_HPDATA_0: �����ȼ�ͨ��0
  *                        ADC_HPDATA_1: �����ȼ�ͨ��1
  *                        ADC_HPDATA_2: �����ȼ�ͨ��2
  *                        ADC_HPDATA_3: �����ȼ�ͨ��3
  * ����  �����ȼ�ͨ��ת��������ݣ�16λ��Ч���ݡ�
  */
uint16_t
ADC_Get_HPConversion_Data (ADC_SFRmap* ADCx, uint8_t HPDataChannel)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_HPDATA_OFFSET(HPDataChannel));

    /*------------- ��ȡADCx_HPDATAy�Ĵ���HPDATAλ -------------*/
    /* ��ȡADCx_HPDATAy��ַ */
    tmpreg = (uint32_t)ADCx;
    tmpreg += HPDataChannel;

    /* ��ȡADCx_HPDATAy��ֵ */
    tmpreg = *(volatile uint32_t *)  tmpreg;
    return (uint16_t) tmpreg;
}
/**
  *   ##### ģ��ת��ģ��(ADC)�����ȼ�ͨ���������ú���������� #####
  */


/**
  *   ##### ģ��ת��ģ��(ADC)�жϹ����� #####
  */
/**
  * ����  ����ADC�ж�ʹ�ܡ�
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       InterruptType: ADC�ж����ͣ�ȡֵΪ��
  *                        ADC_INT_EOC: ADCһ��ת�������ж�
  *                        ADC_INT_AWD: ADCģ�⿴�Ź��ж�
  *                        ADC_INT_HPEND: ADC�����ȼ�ͨ��ת�������ж�
  *                        ADC_INT_END: ADC����ͨ��ת�������ж�
  *       NewState: ADC�ж�ʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
ADC_Set_INT_Enable (ADC_SFRmap* ADCx,
                    uint32_t InterruptType, FunctionalState NewState)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));
    CHECK_RESTRICTION(CHECK_ADC_INT(InterruptType));

    /* ��ȡ�ж��������� */
    tmpreg = (InterruptType & 0x0F);
    tmpreg = (uint32_t)0x01 << tmpreg;

    if (NewState != FALSE)
    {
        /* ʹ���ж� */
        ADCx->STATE |= tmpreg;
    }
    else
    {
        /* ��ֹ�ж� */
        ADCx->STATE &= (~tmpreg);
    }
}

/**
  * ����  ��ȡADC�жϱ�־��
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       InterruptType: ADC�ж����ͣ�ȡֵΪ��
  *                        ADC_INT_EOC: ADCһ��ת�������ж�
  *                        ADC_INT_AWD: ADCģ�⿴�Ź��ж�
  *                        ADC_INT_HPEND: ADC�����ȼ�ͨ��ת�������ж�
  *                        ADC_INT_END: ADC����ͨ��ת�������ж�
  * ����  �жϱ�־��1���������жϣ�0��δ�����жϡ�
  */
FlagStatus
ADC_Get_INT_Flag (ADC_SFRmap* ADCx, uint32_t InterruptType)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_INT(InterruptType));

    /*------------- ��ȡADCx_STATE�Ĵ�����Ӧ�жϱ�־λ -------------*/
    tmpreg = ((InterruptType >> 8)&0x0F);
    tmpreg = (uint32_t)0x01 << tmpreg;
    if ((ADCx->STATE & tmpreg) != RESET)
    {
        /* ADC�������ж� */
        return SET;
    }
    else
    {
        /* ADCδ�����ж� */
        return RESET;
    }
}

/**
  * ����  ���ADC�жϱ�־��
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       InterruptType: ADC�ж����ͣ�ȡֵΪ��
  *                        ADC_INT_EOC: ADCһ��ת�������ж�
  *                        ADC_INT_AWD: ADCģ�⿴�Ź��ж�
  *                        ADC_INT_HPEND: ADC�����ȼ�ͨ��ת�������ж�
  *                        ADC_INT_END: ADC����ͨ��ת�������ж�
  * ����  �ޡ�
  */
void
ADC_Clear_INT_Flag (ADC_SFRmap* ADCx, uint32_t InterruptType)
{
    uint32_t tmpreg = 0;
    uint32_t tmpreg1 = 0;
    uint32_t tmpreg2 = 0;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_INT(InterruptType));

    /*------------- ����ADCx_STATE�Ĵ�����Ӧ�жϱ�־����λ -------------*/
    tmpreg = InterruptType >> 16;
    tmpreg = (uint32_t)0x01 << tmpreg;

    /* �����жϱ�־����λ */
    ADCx->STATE |= tmpreg;

    tmpreg1 = (InterruptType >> 8)&0x0f;
    tmpreg2 = (ADCx->STATE) & ((uint32_t)(0x01 << tmpreg1));
    while(tmpreg2>>tmpreg1);
    /* �����жϱ�־����λ */
    ADCx->STATE &= ~tmpreg;
}

/**
  * ����  ��ȡADC�ж���Ӧ״̬��
  * ����  ADCx: ָ��ADC�ڴ�ṹ��ָ�룬ȡֵΪADC0_SFR~ADC2_SFR��
  *       InterruptType: ADC�ж����ͣ�ȡֵΪ��
  *                        ADC_INT_EOC: ADCһ��ת�������ж�
  *                        ADC_INT_AWD: ADCģ�⿴�Ź��ж�
  *                        ADC_INT_HPEND: ADC�����ȼ�ͨ��ת�������ж�
  *                        ADC_INT_END: ADC����ͨ��ת�������ж�
  * ����  �ж���Ӧ״̬��1����������Ӧ�жϣ�0��δ�����жϻ�δʹ�ܡ�
  */
INTStatus
ADC_Get_INT_Status (ADC_SFRmap* ADCx, uint32_t InterruptType)
{
    uint32_t tmpmask = 0;
    uint32_t enablestatus = 0;
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ADC_ALL_PERIPH(ADCx));
    CHECK_RESTRICTION(CHECK_ADC_INT(InterruptType));

    /*------------- ��ȡADCx_STATE�Ĵ��� -------------*/
    tmpreg = ADCx->STATE;

    /* ��ȡ�ж�ʹ��״̬ */
    enablestatus = (tmpreg & ((uint32_t)0x01 << InterruptType)) ;

    /* ��ȡ�жϱ�־״̬ */
    tmpmask = tmpreg & ((uint32_t)0x01 << ((InterruptType >> 8)));

    /* ����ж�ʹ�ܺͱ�־ */
    if ((tmpmask != (uint32_t)RESET) && enablestatus)
    {
        /* ��������Ӧ�ж� */
        return SET;
    }
    else
    {
        /* δ�����жϻ�δʹ�� */
        return RESET;
    }
}
/**
  *   ##### ģ��ת��ģ��(ADC)�жϹ������������ #####
  */
