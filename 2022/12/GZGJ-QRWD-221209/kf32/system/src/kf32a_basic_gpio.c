/**
  ******************************************************************************
  * �ļ���  kf32a_basic_gpio.c
  * ��  ��  ChipON_AE/FAE_Group
  * ��  ��  V2.62
  * ��  ��  2019-11-16
  * ��  ��  ���ļ��ṩ��ͨ����������˿�(GPIO)���蹦�ܺ�����������
  *          + ͨ����������˿�(GPIO)��ʼ�������ú���
  *          + ͨ����������˿�(GPIO)��д����
  *          + ͨ����������˿�(GPIO)��ӳ�����ú���
  *
  *********************************************************************
  */

#include "kf32a_basic_gpio.h"
#include "kf32a_basic_rst.h"
#include "kf32a_basic_pclk.h"

/**
  *   ##### ͨ����������˿�(GPIO)��ʼ�������ú��� #####
  */
/**
  * ����  ��λGPIO���裬ʹ������ʱ�ӡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  * ����  �ޡ�
  */
void
GPIO_Reset (GPIO_SFRmap* GPIOx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));

    if (GPIOx == GPIOA_SFR)
    {
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOARST, TRUE);
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOARST, FALSE);
        PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOACLKEN, TRUE);
    }
    else if (GPIOx == GPIOB_SFR)
    {
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOBRST, TRUE);
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOBRST, FALSE);
        PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOBCLKEN, TRUE);
    }
    else if (GPIOx == GPIOC_SFR)
    {
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOCRST, TRUE);
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOCRST, FALSE);
        PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOCCLKEN, TRUE);
    }
    else if (GPIOx == GPIOD_SFR)
    {
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIODRST, TRUE);
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIODRST, FALSE);
        PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIODCLKEN, TRUE);
    }
    else if (GPIOx == GPIOE_SFR)
    {
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOERST, TRUE);
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOERST, FALSE);
        PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOECLKEN, TRUE);
    }
    else if (GPIOx == GPIOF_SFR)
    {
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOFRST, TRUE);
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOFRST, FALSE);
        PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOFCLKEN, TRUE);
    }
    else if (GPIOx == GPIOG_SFR)
    {
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOGRST, TRUE);
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOGRST, FALSE);
        PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOGCLKEN, TRUE);
    }
    else if (GPIOx == GPIOH_SFR)
    {
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOHRST, TRUE);
        RST_CTL0_Peripheral_Reset_Enable(RST_CTL0_GPIOHRST, FALSE);
        PCLK_CTL0_Peripheral_Clock_Enable(PCLK_CTL0_GPIOHCLKEN, TRUE);
    }
    else
    {
        ;
    }
}

/**
  * ����  ͨ����������˿�(GPIO)��ʼ�����á�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       gpioInitStruct: GPIO������Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void
GPIO_Configuration (GPIO_SFRmap* GPIOx, GPIO_InitTypeDef* gpioInitStruct)
{
    uint32_t pinpos = 0x00;
    uint32_t pos = 0x00;
    uint32_t currentpin = 0x00;
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(gpioInitStruct->m_Pin));
    CHECK_RESTRICTION(CHECK_GPIO_MODE(gpioInitStruct->m_Mode));
    CHECK_RESTRICTION(CHECK_GPIO_SPEED(gpioInitStruct->m_Speed));
    CHECK_RESTRICTION(CHECK_GPIO_PU(gpioInitStruct->m_PullUp));
    CHECK_RESTRICTION(CHECK_GPIO_PD(gpioInitStruct->m_PullDown));

    /* ����һ��������Ϣ */
    for (pinpos = 0x00; pinpos < 0x10; pinpos++)
    {
        pos = ((uint32_t)0x01) << pinpos;
        /* ��ȡ����λ����Ϣ */
        currentpin = (gpioInitStruct->m_Pin) & pos;

        if (currentpin == pos)
        {
            /*----------- ����GPIOx_PMOD�Ĵ��� -----------*/
            /* ���ݽṹ���Աm_Mode������PXPMDyλ�� */
            tmpreg = (((uint32_t)gpioInitStruct->m_Mode) << (pinpos * 2));
            GPIOx->PMOD = SFR_Config (GPIOx->PMOD,
                                  ~(GPIO_PMOD_PXPMD0 << (pinpos * 2)),
                                  tmpreg);

            if ((gpioInitStruct->m_Mode == GPIO_MODE_OUT)
                || (gpioInitStruct->m_Mode == GPIO_MODE_RMP))
            {
                /* GPIO��©���Ʋ���У�� */
                CHECK_RESTRICTION(CHECK_GPIO_POD(gpioInitStruct->m_OpenDrain));

                /*----------- ����GPIOx_PODR�Ĵ��� -----------*/
                /* ���ݽṹ���Աm_OpenDrain������PXPODRλ�� */
                tmpreg = (((uint32_t)gpioInitStruct->m_OpenDrain) << (pinpos));
                GPIOx->PODR = SFR_Config (GPIOx->PODR,
                                      ~(GPIO_PODR_PXPODR0 << pinpos),
                                      tmpreg);
            }
            else
            {
                ;
            }

            /*----------- ����GPIOx_OMOD�Ĵ��� -----------*/
            /* ���ݽṹ���Աm_Speed������PXOMDλ�� */
            tmpreg = ((uint32_t)gpioInitStruct->m_Speed) << (pinpos * 2);
            GPIOx->OMOD = SFR_Config (GPIOx->OMOD,
                                  ~(GPIO_OMOD_PXOMD0 << (pinpos * 2)),
                                  tmpreg);

            /*----------- ����GPIOx_PUR�Ĵ��� -----------*/
            /* ���ݽṹ���Աm_PullUp������PXPURλ�� */
            tmpreg = (((uint32_t)gpioInitStruct->m_PullUp) << (pinpos));
            GPIOx->PUR = SFR_Config (GPIOx->PUR,
                                  ~(GPIO_PUR_PXPUR0 << pinpos),
                                  tmpreg);

            /*----------- ����GPIOx_PDR�Ĵ��� -----------*/
            /* ���ݽṹ���Աm_PullDown������PXPDRλ�� */
            tmpreg = (((uint32_t)gpioInitStruct->m_PullDown) << (pinpos));
            GPIOx->PDR = SFR_Config (GPIOx->PDR,
                                  ~(GPIO_PDR_PXPDR0 << pinpos),
                                  tmpreg);
        }
        else
        {
            ;
        }
    }
}

/**
  * ����  ��ʼ��GPIO������Ϣ�ṹ�塣
  * ����  gpioInitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void
GPIO_Struct_Init (GPIO_InitTypeDef* gpioInitStruct)
{
    /* ��ʼ�� GPIO�˿����� */
    gpioInitStruct->m_Pin  = GPIO_PIN_MASK_All;

    /* ��ʼ�� GPIO���ģʽ */
    gpioInitStruct->m_Mode = GPIO_MODE_AN;

    /* ��ʼ�� GPIO����ٶ� */
    gpioInitStruct->m_Speed = GPIO_LOW_SPEED;

    /* ��ʼ�� GPIO��©���� */
    gpioInitStruct->m_OpenDrain = GPIO_POD_PP;

    /* ��ʼ�� GPIO�������� */
    gpioInitStruct->m_PullUp = GPIO_NOPULL;

    /* ��ʼ�� GPIO�������� */
    gpioInitStruct->m_PullDown = GPIO_NOPULL;
}

/**
  * ����  ����GPIO�˿�������
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  *       NewState: GPIO�˿�����״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
GPIO_Pin_Lock_Config (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPin, FunctionalState NewState)
{
    uint32_t tmpreg = 0x5C5A0000;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /* ����ԭʼ����״̬ */
    tmpreg |= GPIOx->LOCK;

    /* ��������/����״̬ */
    if (NewState != FALSE)
    {
        /* ���� */
        tmpreg |= (uint32_t)GpioPin;
    }
    else
    {
        /* ���� */
        tmpreg &= ~((uint32_t)GpioPin);
    }

    /*----------- ����GPIOx_LOCK�Ĵ��� -----------*/
    GPIOx->LOCK = tmpreg;
}

/**
  * ����  ����GPIO�˿�����ʹ�ܡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  *       NewState: GPIO�˿�����ʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
GPIO_Pull_Up_Enable (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPin, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*----------- ����GPIOx_PUR�Ĵ��� -----------*/
    if (NewState != FALSE)
    {
        /* ʹ���������� */
        GPIOx->PUR |= (uint32_t)GpioPin;
    }
    else
    {
        /* ��ֹ�������� */
        GPIOx->PUR &= ~((uint32_t)GpioPin);
    }
}

/**
  * ����  ����GPIO�˿�����ʹ��ȡ����
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  * ����  �ޡ�
  */
void
GPIO_Toggle_Pull_Up_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

    /*----------- ����GPIOx_PUR�Ĵ��� -----------*/
    GPIOx->PUR ^= (uint32_t)GpioPin;
}

/**
  * ����  ����GPIO�˿�����ʹ�ܡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  *       NewState: GPIO�˿�����ʹ��״̬��ȡֵ��ΧΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
GPIO_Pull_Down_Enable (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPin, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*----------- ����GPIOx_PDR�Ĵ��� -----------*/
    if (NewState != FALSE)
    {
        /* ʹ���������� */
        GPIOx->PDR |= (uint32_t)GpioPin;
    }
    else
    {
        /* ��ֹ�������� */
        GPIOx->PDR &= ~((uint32_t)GpioPin);
    }
}

/**
  * ����  ����GPIO�˿�����ʹ��ȡ����
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  * ����  �ޡ�
  */
void
GPIO_Toggle_Pull_Down_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

    /*----------- ����GPIOx_PUR�Ĵ��� -----------*/
    GPIOx->PDR ^= (uint32_t)GpioPin;
}

/**
  * ����  ����GPIO�˿ڿ�©������ơ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  *       NewState: GPIO��©�������״̬��ȡֵΪ��
  *                   GPIO_POD_PP: �������
  *                   GPIO_POD_OD: ��©���
  * ����  �ޡ�
  */
void
GPIO_Open_Drain_Enable (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPin, GPIOPOD_TypeDef NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
    CHECK_RESTRICTION(CHECK_GPIO_POD(NewState));

    /*----------- ����GPIOx_PODR�Ĵ��� -----------*/
    if (NewState != GPIO_POD_PP)
    {
        /* ��©��� */
        GPIOx->PODR |= (uint32_t)GpioPin;
    }
    else
    {
        /* ������� */
        GPIOx->PODR &= ~((uint32_t)GpioPin);
    }
}

/**
  * ����  ����GPIO�˿ڿ�©�������ȡ����
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  * ����  �ޡ�
  */
void
GPIO_Toggle_Open_Drain_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

    /*----------- ����GPIOx_PODR�Ĵ��� -----------*/
    GPIOx->PODR ^= (uint32_t)GpioPin;
}

/**
  * ����  ����GPIO���ģʽ���ơ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  *       NewState: GPIO���ģʽ����״̬��ȡֵΪ��
  *                   GPIO_MODE_IN: ͨ��IO������ģʽ
  *                   GPIO_MODE_OUT: ͨ��IO�����ģʽ
  *                   GPIO_MODE_RMP: ��ӳ��IO�ڹ���ģʽ
  *                   GPIO_MODE_AN: ģ��ģʽ
  * ����  �ޡ�
  */
void
GPIO_Write_Mode_Bits (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPin, GPIOMode_TypeDef NewState)
{
    uint32_t pinpos = 0;
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
    CHECK_RESTRICTION(CHECK_GPIO_MODE(NewState));

    /*----------- ��ȡGPIOx_PMOD�Ĵ��� -----------*/
    tmpreg = GPIOx->PMOD;
    while (GpioPin)
    {
        if (GpioPin & (uint16_t)0x1)
        {
            /* ��¼������Ϣ */
            tmpreg &= ~(GPIO_PMOD_PXPMD0 << pinpos);
            tmpreg |= (uint32_t)NewState << pinpos;
        }
        else
        {
            ;
        }
        GpioPin >>= 1;
        pinpos += 2;
    }

    /*----------- ����GPIOx_PMOD�Ĵ��� -----------*/
    GPIOx->PMOD = tmpreg;
}

/**
  * ����  ����GPIO�˿�����ٶȿ��ơ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  *       NewState: GPIO�˿�����ٶȿ���״̬��ȡֵΪ��
  *                   GPIO_LOW_SPEED: 10MHZ
  *                   GPIO_HIGH_SPEED: 50MHZ
  * ����  �ޡ�
  */
void
GPIO_Speed_Config (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPin, GPIOSpeed_TypeDef NewState)
{
    uint32_t pinpos = 0;
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
    CHECK_RESTRICTION(CHECK_GPIO_SPEED(NewState));

    /*----------- ��ȡGPIOx_OMOD�Ĵ��� -----------*/
    tmpreg = GPIOx->OMOD;
    while (GpioPin)
    {
        if (GpioPin & (uint16_t)0x1)
        {
            /* ��¼������Ϣ */
            tmpreg &= ~(GPIO_OMOD_PXOMD0 << pinpos);
            tmpreg |= (uint32_t)NewState << pinpos;
        }
        else
        {
            ;
        }
        GpioPin >>= 1;
        pinpos += 2;
    }

    /*----------- ����GPIOx_PMOD�Ĵ��� -----------*/
    GPIOx->OMOD = tmpreg;
}

/**
  * ����  ����GPIO�˿�����ٶȿ���ȡ����
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  * ����  �ޡ�
  */
void
GPIO_Toggle_Speed_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
    uint32_t pinpos = 0;
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

    /*----------- ��ȡGPIOx_OMOD�Ĵ��� -----------*/
    tmpreg = GPIOx->OMOD;
    while (GpioPin)
    {
        if (GpioPin & (uint16_t)0x1)
        {
            /* ȡ��������¼������Ϣ */
            tmpreg ^= GPIO_OMOD_PXOMD0 << pinpos;
        }
        else
        {
            ;
        }
        GpioPin >>= 1;
        pinpos += 2;
    }

    /*----------- ����GPIOx_PMOD�Ĵ��� -----------*/
    GPIOx->OMOD = tmpreg;
}
/**
  *   ##### ͨ����������˿�(GPIO)��ʼ�������ú���������� #####
  */


/**
  *   ##### ͨ����������˿�(GPIO)��д���� #####
  */
/**
  * ����  ��ȡGPIO�˿�ָ�����ŵ��������ݡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: ָ���˿����ţ�ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�һ����
  * ����  ָ�����ŵ���Ϣ��1���߼��ߵ�ƽ��0���߼��͵�ƽ��
  */
BitAction
GPIO_Read_Input_Data_Bit (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

    /*---------------- ��ȡGPIOx_PIR�Ĵ���PXPIRyλ ----------------*/
    tmpreg = (uint32_t)GpioPin;
    if ((GPIOx->PIR & tmpreg) != Bit_RESET)
    {
        /* �߼��ߵ�ƽ */
        return Bit_SET;
    }
    else
    {
        /* �߼��͵�ƽ */
        return Bit_RESET;
    }
}

/**
  * ����  ��ȡGPIO�˿��������ݡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  * ����  �������ݣ�16λ��Ч���ݡ�
  */
uint16_t
GPIO_Read_Input_Data (GPIO_SFRmap* GPIOx)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));

    /*---------------- ��ȡGPIOx_PIR�Ĵ��� ----------------*/
    tmpreg = GPIOx->PIR;

    return (uint16_t)tmpreg;
}

/**
  * ����  ��ȡGPIO�˿�ָ�����ŵ�������ݡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: ָ���˿����ţ�ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�һ����
  * ����  ָ�����ŵ���Ϣ��1���߼��ߵ�ƽ��0���߼��͵�ƽ��
  */
BitAction
GPIO_Read_Output_Data_Bit (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));

    /*---------------- ��ȡGPIOx_POR�Ĵ���PXPORyλ ----------------*/
    tmpreg = (uint32_t)GpioPin;
    if ((GPIOx->POR & tmpreg) != Bit_RESET)
    {
        /* �߼��ߵ�ƽ */
        return Bit_SET;
    }
    else
    {
        /* �߼��͵�ƽ */
        return Bit_RESET;
    }
}

/**
  * ����  ��ȡGPIO�˿�������ݡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  * ����  ������ݣ�16λ��Ч���ݡ�
  */
uint16_t
GPIO_Read_Output_Data (GPIO_SFRmap* GPIOx)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));

    /*---------------- ��ȡGPIOx_POR�Ĵ��� ----------------*/
    tmpreg = GPIOx->POR;

    return (uint16_t)tmpreg;
}

/**
  * ����  ����GPIO�˿�ָ�����ŵ�������ݡ�
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  *       BitsValue: ���ŵ�����ֵ��ȡֵΪ��
  *                    Bit_RESET: �߼��͵�ƽ
  *                    Bit_SET: �߼��ߵ�ƽ
  * ����  �ޡ�
  */
void
GPIO_Set_Output_Data_Bits (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPin, BitAction BitsValue)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_MASK(GpioPin));
    CHECK_RESTRICTION(CHECK_GPIO_BIT_ACTION(BitsValue));

    /*----------- ����GPIOx_POR�Ĵ��� -----------*/
    if (BitsValue != Bit_RESET)
    {
        /* �߼��ߵ�ƽ */
        GPIOx->POR |= (uint32_t)GpioPin;
    }
    else
    {
        /* �߼��͵�ƽ */
        GPIOx->POR &= ~((uint32_t)GpioPin);
    }
}

/**
  * ����  ����GPIO�˿�ָ�����ŵ��������ȡ����
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPin: �˿��������룬ȡֵΪGPIO_PIN_MASK_0~GPIO_PIN_MASK_15�е�
  *                һ��������ϡ�
  * ����  �ޡ�
  */
void
GPIO_Toggle_Output_Data_Config (GPIO_SFRmap* GPIOx, uint16_t GpioPin)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));

    /*----------- ����GPIOx_POR�Ĵ��� -----------*/
    GPIOx->POR ^= (uint32_t)GpioPin;
}
/**
  *   ##### ͨ����������˿�(GPIO)��д����������� #####
  */


/**
  *   ##### ͨ����������˿�(GPIO)��ӳ�����ú��� #####
  */
/**
  * ����  ����GPIO�˿�������ӳ�䡣
  * ����  GPIOx: ָ��GPIO�ڴ�ṹ��ָ�룬ȡֵΪGPIOA_SFR~GPIOH_SFR��
  *       GpioPinNum: ָ���˿����ţ�ȡֵΪGPIO_Pin_Num_0~GPIO_Pin_Num_15�е�һ����
  *       PinRemap: ������ӳ��ѡ��ȡֵΪ��
  *                   GPIO_RMP_AF0_SYSTEM: SYSTEM
  *                   GPIO_RMP_AF1_T0: T0
  *                   GPIO_RMP_AF1_T1: T1
  *                   GPIO_RMP_AF1_T2: T2
  *                   GPIO_RMP_AF1_T3: T3
  *                   GPIO_RMP_AF1_T4: T4
  *                   GPIO_RMP_AF2_T5: T5
  *                   GPIO_RMP_AF2_T6: T6
  *                   GPIO_RMP_AF2_T9: T9
  *                   GPIO_RMP_AF2_T10: T10
  *                   GPIO_RMP_AF3_T9: T9
  *                   GPIO_RMP_AF3_T20: T20
  *                   GPIO_RMP_AF3_T21: T21
  *                   GPIO_RMP_AF3_T23: T23
  *                   GPIO_RMP_AF3_QEI1: QEI1
  *                   GPIO_RMP_AF4_T: T9
  *                   GPIO_RMP_AF4_T14: T14
  *                   GPIO_RMP_AF4_T15: T15
  *                   GPIO_RMP_AF4_T18: T18
  *                   GPIO_RMP_AF4_T19: T19
  *                   GPIO_RMP_AF4_T22: T22
  *                   GPIO_RMP_AF4_QEI0: QEI0
  *                   GPIO_RMP_AF5_USART0: USART0
  *                   GPIO_RMP_AF5_USART1: USART1
  *                   GPIO_RMP_AF5_USART2: USART2
  *                   GPIO_RMP_AF6_USART3: USART3
  *                   GPIO_RMP_AF6_USART4: USART4
  *                   GPIO_RMP_AF6_USART5: USART5
  *                   GPIO_RMP_AF6_USART6: USART6
  *                   GPIO_RMP_AF6_USART7: USART7
  *                   GPIO_RMP_AF7_SPI0: SPI0
  *                   GPIO_RMP_AF7_SPI1: SPI1
  *                   GPIO_RMP_AF7_SPI2: SPI2
  *                   GPIO_RMP_AF7_SPI3: SPI3
  *                   GPIO_RMP_AF8_I2C0: I2C0
  *                   GPIO_RMP_AF8_I2C1: I2C1
  *                   GPIO_RMP_AF8_I2C2: I2C2
  *                   GPIO_RMP_AF8_I2C3: I2C3
  *                   GPIO_RMP_AF9_CAN0: CAN0
  *                   GPIO_RMP_AF9_CAN1: CAN1
  *                   GPIO_RMP_AF9_CAN2: CAN2
  *                   GPIO_RMP_AF9_CAN3: CAN3
  *                   GPIO_RMP_AF9_CAN4: CAN4
  *                   GPIO_RMP_AF9_CAN5: CAN5
  *                   GPIO_RMP_AF9_FLT: FLT
  *                   GPIO_RMP_AF10_CCP: CCP
  *                   GPIO_RMP_AF10_SPI: SPI
  *                   GPIO_RMP_AF10_I2C: I2C
  *                   GPIO_RMP_AF11_USART: USART
  *                   GPIO_RMP_AF11_CCP: CCP
  *                   GPIO_RMP_AF11_SPI: SPI
  *                   GPIO_RMP_AF11_I2C: I2C
  *                   GPIO_RMP_AF12_LED: LED
  *                   GPIO_RMP_AF12_CFGL: CFGL
  *                   GPIO_RMP_AF13_EXIC: EXIC
  *                   GPIO_RMP_AF14_LED: LED
  *                   GPIO_RMP_AF15_TESTPAD: TESTPAD
  *
  * ����  �ޡ�
  */
void
GPIO_Pin_RMP_Config (GPIO_SFRmap* GPIOx,
                    uint16_t GpioPinNum, uint8_t PinRemap)
{
    uint32_t tmpreg = 0x00;
    uint32_t tmpreg1 = 0x00;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_GPIO_ALL_PERIPH(GPIOx));
    CHECK_RESTRICTION(CHECK_GPIO_PIN_NUM(GpioPinNum));
    CHECK_RESTRICTION(CHECK_GPIO_RMP(PinRemap));

    /* ��ȡԭʼGPIO_RMPH/L���� */
    tmpreg1 = GPIOx->RMP[GpioPinNum >> 0x03];

    /* �޸Ķ�Ӧ����ֵ */
    tmpreg = ((uint32_t)PinRemap << (((uint32_t)GpioPinNum & 0x07) * 4));
    tmpreg1 &= ~((uint32_t)0xF << (((uint32_t)GpioPinNum & 0x07) * 4));
    tmpreg1 = tmpreg1 | tmpreg;

    /* ����GPIO_RMPH/L���� */
    GPIOx->RMP[GpioPinNum >> 0x03] = tmpreg1;
}
/**
  *   ##### ͨ����������˿�(GPIO)��ӳ�����ú���������� #####
  */
