/**
  ******************************************************************************
  * �ļ���  kf32a_basic_rst.c
  * ��  ��  ChipON_AE/FAE_Group
  * ��  ��  V2.62
  * ��  ��  2019-11-16
  * ��  ��  ���ļ��ṩ�˸�λģ��(RST)���蹦�ܺ�����������
  *          + ��λģ��(RST)�������ú���
  *
  *********************************************************************
  */

#include "kf32a_basic_rst.h"


/**
  *   ##### ��λģ��(RST)�������ú��� #####
  */
/**
  * ����  ����RST_CTL0���Ƶ����踴λ״̬��
  * ����  RST_CTL0_bit: ָ�����踴λ����λ�����룬ȡֵΪ��
  *                       RST_CTL0_GPIOARST: GPIOA��λ
  *                       RST_CTL0_GPIOBRST: GPIOB��λ
  *                       RST_CTL0_GPIOCRST: GPIOC��λ
  *                       RST_CTL0_GPIODRST: GPIOD��λ
  *                       RST_CTL0_GPIOERST: GPIOE��λ
  *                       RST_CTL0_GPIOFRST: GPIOF��λ
  *                       RST_CTL0_GPIOGRST: GPIOG��λ
  *                       RST_CTL0_GPIOHRST: GPIOH��λ
  *                       RST_CTL0_GPIOIRST: GPIOI��λ
  *       NewState: ���踴λ״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
RST_CTL0_Peripheral_Reset_Enable (uint32_t RST_CTL0_bit,
                    FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_RST_CTL0_RESET_PERIPH(RST_CTL0_bit));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        RST_CTL0 |= RST_CTL0_bit;
    }
    else
    {
        RST_CTL0 &= ~RST_CTL0_bit;
    }
}

/**
  * ����  ����RST_CTL1���Ƶ����踴λ״̬��
  * ����  RST_CTL1_bit: ָ�����踴λ����λ�����룬ȡֵΪ��
  *                       RST_CTL1_QEI1RST: QEI1��λ
  *                       RST_CTL1_T1RST: T1��λ
  *                       RST_CTL1_T2RST: T2��λ
  *                       RST_CTL1_T3RST: T3��λ
  *                       RST_CTL1_T4RST: T4��λ
  *                       RST_CTL1_T5T6RST: T5T6��λ
  *                       RST_CTL1_T9T10RST: T9T10��λ
  *                       RST_CTL1_QEI0RST: QEI0��λ
  *                       RST_CTL1_ADC0RST: ADC0��λ
  *                       RST_CTL1_ADC1RST: ADC1��λ
  *                       RST_CTL1_ADC2RST: ADC2��λ
  *                       RST_CTL1_DAC0RST: DAC0��λ
  *                       RST_CTL1_DAC1RST: DAC1��λ
  *                       RST_CTL1_CMPRST: CMP��λ
  *                       RST_CTL1_T0RST: T0��λ
  *                       RST_CTL1_CTOUCHRST: CTOUCH��λ
  *                       RST_CTL1_USART0RST: USART0��λ
  *                       RST_CTL1_USART1RST: USART1��λ
  *                       RST_CTL1_USART2RST: USART2��λ
  *                       RST_CTL1_USART3RST: USART3��λ
  *                       RST_CTL1_USART4RST: USART4��λ
  *                       RST_CTL1_SPI0RST: SPI0��λ
  *                       RST_CTL1_SPI1RST: SPI1��λ
  *                       RST_CTL1_I2C0RST: I2C0��λ
  *                       RST_CTL1_I2C1RST: I2C1��λ
  *                       RST_CTL1_I2C2RST: I2C2��λ
  *                       RST_CTL1_LCDRST: LCD��λ
  *                       RST_CTL1_USBRST: USB��λ
  *       NewState: ���踴λ״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
RST_CTL1_Peripheral_Reset_Enable (uint32_t RST_CTL1_bit,
                    FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_RST_CTL1_RESET_PERIPH(RST_CTL1_bit));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        RST_CTL1 |= RST_CTL1_bit;
    }
    else
    {
        RST_CTL1 &= ~RST_CTL1_bit;
    }
}

/**
  * ����  ����RST_CTL2���Ƶ����踴λ״̬��
  * ����  RST_CTL2_bit: ָ�����踴λ����λ�����룬ȡֵΪ��
  *                       RST_CTL2_CAN0RST: CAN0��λ
  *                       RST_CTL2_CAN1RST: CAN1��λ
  *                       RST_CTL2_WWDTRST: WWDT��λ
  *                       RST_CTL2_DMA0RST: DMA0��λ
  *                       RST_CTL2_DMA1RST: DMA1��λ
  *                       RST_CTL2_T14RST: T14��λ
  *                       RST_CTL2_T15RST: T15��λ
  *                       RST_CTL2_CAN2RST: CAN2��λ
  *                       RST_CTL2_CAN3RST: CAN3��λ
  *                       RST_CTL2_T18RST: T18��λ
  *                       RST_CTL2_T19RST: T19��λ
  *                       RST_CTL2_T20RST: T20��λ
  *                       RST_CTL2_T21RST: T21��λ
  *                       RST_CTL2_T22RST: T22��λ
  *                       RST_CTL2_T23RST: T23��λ
  *                       RST_CTL2_USART5RST: USART5��λ
  *                       RST_CTL2_USART6RST: USART6��λ
  *                       RST_CTL2_USART7RST: USART7��λ
  *       NewState: ���踴λ״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
RST_CTL2_Peripheral_Reset_Enable (uint32_t RST_CTL2_bit,
                    FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_RST_CTL2_RESET_PERIPH(RST_CTL2_bit));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        RST_CTL2 |= RST_CTL2_bit;
    }
    else
    {
        RST_CTL2 &= ~RST_CTL2_bit;
    }
}

/**
  * ����  ����RST_CTL3���Ƶ����踴λ״̬��
  * ����  RST_CTL3_bit: ָ�����踴λ����λ�����룬ȡֵΪ��
  *                       RST_CTL3_SPI2RST: SPI2��λ
  *                       RST_CTL3_SPI3RST: SPI3��λ
  *                       RST_CTL3_I2C3RST: I2C3��λ
  *                       RST_CTL3_CRCRST: CRC��λ
  *                       RST_CTL3_AESRST: AES��λ
  *                       RST_CTL3_LEDRST: LED��λ
  *                       RST_CTL3_EXICRST: EXIC��λ
  *                       RST_CTL3_CAN4RST: CAN4��λ
  *                       RST_CTL3_CAN5RST: CAN5��λ
  *                       RST_CTL3_CFGLRST: CFGL��λ
  *                       RST_CTL3_OPRST: OP��λ
  *       NewState: ���踴λ״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
RST_CTL3_Peripheral_Reset_Enable (uint32_t RST_CTL3_bit,
                    FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_RST_CTL3_RESET_PERIPH(RST_CTL3_bit));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    if (NewState != FALSE)
    {
        RST_CTL3 |= RST_CTL3_bit;
    }
    else
    {
        RST_CTL3 &= ~RST_CTL3_bit;
    }
}
/**
  *   ##### ��λģ��(RST)�������ú���������� #####
  */
