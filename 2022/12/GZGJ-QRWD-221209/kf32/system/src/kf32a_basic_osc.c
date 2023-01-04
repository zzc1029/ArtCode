/**
  ******************************************************************************
  * �ļ���  kf32a_basic_osc.c
  * ��  ��  ChipON_AE/FAE_Group
  * ��  ��  V2.62
  * ��  ��  2019-11-16
  * ��  ��  ���ļ��ṩ������(OSC)���蹦�ܺ�����������
  *          + ����(OSC)�����ʼ������
  *          + ����(OSC)�������ú���
  *          + ����(OSC)�жϿ��ƺ���
  *
  *********************************************************************
  */

#include "kf32a_basic_osc.h"


/* ����(OSC)˽�ж��� ----------------------------------------------------*/
/* OSC_CTL0�Ĵ���SCK��ʼ���������� */
#define OSC_CTL0_SCLK_MASK               (OSC_CTL0_SCKS \
                                       | OSC_CTL0_SCKDIV)

/* OSC_CTL0�Ĵ���HFCK��ʼ���������� */
#define OSC_CTL0_HFCK_MASK             (OSC_CTL0_HFCKS \
                                       | OSC_CTL0_HFCKDIV)

/* OSC_CTL0�Ĵ���LFCK��ʼ���������� */
#define OSC_CTL0_LFCK_MASK             (OSC_CTL0_LFCKS \
                                       | OSC_CTL0_LFCKDIV)

/* OSC_CTL1�Ĵ���CK48M��ʼ���������� */
#define OSC_CTL1_CK48M_MASK             (OSC_CTL1_CK48MS \
                                       | OSC_CTL1_CK48DIV)


/**
  *   ##### ����(OSC)�����ʼ������ #####
  */
/**
  * ����  ��������(OSC)ϵͳ��ʱ��SCLK��
  * ����  oscInitStruct: ����(OSC)������Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void
OSC_SCLK_Configuration (OSC_InitTypeDef* oscInitStruct)
{
    uint32_t tmpreg = 0;
    uint32_t tmpreg1 = 0;
    uint32_t tmpmask = 0;
    uint32_t tmpmask1 = 0;
    uint32_t sfraddr = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SCLK_SOURCE(oscInitStruct->m_InputSource));
    CHECK_RESTRICTION(CHECK_SCLK_DIVISION(oscInitStruct->m_CLKDivision));

    /*------------------ ����OSC_CTL0�Ĵ��� -----------------*/
    /* ���ݲ���m_InputSource������SCKSλ�� */
    /* ���ݲ���m_CLKDivision������SCKDIVλ�� */
    tmpreg = oscInitStruct->m_InputSource << OSC_CTL0_SCKS0_POS \
           | oscInitStruct->m_CLKDivision << OSC_CTL0_SCKDIV0_POS;
    tmpmask = OSC_CTL0_SCLK_MASK;

    switch (oscInitStruct->m_InputSource)
    {
        case SCLK_SOURCE_PLL:
        {
            /* ���ݲ���m_PLLInputSource������PLLxCKSλ�� */
            tmpreg |= (oscInitStruct->m_PLLInputSource \
                                << OSC_CTL0_PLL0CKS_POS);
            tmpmask |= OSC_CTL0_PLL0CKS;
            /* PLL��ƵDIVSELλ��Ĵ�����ַ */
            sfraddr = (uint32_t)&PLL_CTL;
            /* PLL������ʱʱ������λ��ƫ�� */
            tmpreg1 = OSC_CTL2_PLLDLY0_POS;
        }
            break;
        case SCLK_SOURCE_EXTHF:
        {
            tmpreg1 = OSC_CTL2_EHFDLY0_POS;
            tmpmask1 = OSC_CTL2_EHFDLY;
        }
            break;
        case SCLK_SOURCE_EXTLF:
        {
            tmpreg1 = OSC_CTL2_ELFDLY0_POS;
            tmpmask1 = OSC_CTL2_ELFDLY;
        }
            break;
        default:
            break;
    }
    /* PLL����ʱ��Դѡ��λ */
    OSC_CTL0 = SFR_Config (OSC_CTL0, ~tmpmask, tmpreg);

    if (oscInitStruct->m_InputSource >= SCLK_SOURCE_PLL)
    {
        CHECK_RESTRICTION(CHECK_PLL_INPUT(oscInitStruct->m_PLLInputSource));
        CHECK_RESTRICTION(CHECK_PLL_START_DELAY(oscInitStruct->m_StartDelay));

        /* PLL������ʱʱ������ */
        /*------------------ ����OSC_CTL2�Ĵ��� -----------------*/
        /* ���ݲ���m_StartDelay������PLLxDLYλ�� */
        OSC_CTL2 = SFR_Config (OSC_CTL2,
                            ~(0xF << tmpreg1),
                            oscInitStruct->m_StartDelay << tmpreg1);
    }
    else if ((oscInitStruct->m_InputSource == SCLK_SOURCE_EXTHF)
         || (oscInitStruct->m_InputSource == SCLK_SOURCE_EXTLF))
    {
        /* �ⲿ������ʱʱ������ */
        CHECK_RESTRICTION(CHECK_EXT_START_DELAY(oscInitStruct->m_StartDelay));

        /*------------------ ����OSC_CTL2�Ĵ��� -----------------*/
        /* ���ݲ���m_StartDelay������EHFDLY/ELFDLYλ�� */
        OSC_CTL2 = SFR_Config (OSC_CTL2,
                            ~tmpmask1,
                            oscInitStruct->m_StartDelay << tmpreg1);
    }
    else
    {
        ;
    }
}

/**
  * ����  ��������(OSC)��Ƶ����ʱ��HFCLK��
  * ����  oscInitStruct: ����(OSC)������Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void
OSC_HFCK_Configuration (OSC_InitTypeDef* oscInitStruct)
{
    uint32_t tmpreg = 0;
    uint32_t tmpreg1 = 0;
    uint32_t tmpmask = 0;
    uint32_t tmpmask1 = 0;
    uint32_t sfraddr = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_HFCK_SOURCE(oscInitStruct->m_InputSource));
    CHECK_RESTRICTION(CHECK_HFCK_DIVISION(oscInitStruct->m_CLKDivision));

    switch (oscInitStruct->m_InputSource)
    {
        case HFCK_SOURCE_PLL:
        {
            /* ���ݲ���m_PLLInputSource������PLLxCKSλ�� */
            tmpreg = (oscInitStruct->m_PLLInputSource \
                                << OSC_CTL0_PLL0CKS_POS);
            tmpmask = OSC_CTL0_PLL0CKS;
            /* PLL��ƵDIVSELλ��Ĵ�����ַ */
            sfraddr = (uint32_t)&PLL_CTL;
            /* PLL������ʱʱ������λ��ƫ�� */
            tmpreg1 = OSC_CTL2_PLLDLY0_POS;
        }
            break;
        case HFCK_SOURCE_INTHF:
            break;
        case HFCK_SOURCE_EXTHF:
        {
            tmpreg1 = OSC_CTL2_ELFDLY0_POS;
            tmpmask1 = OSC_CTL2_ELFDLY;
        }
            break;
        default:
            break;
    }
    /* PLL����ʱ��Դѡ��λ */
    /*------------------ ����OSC_CTL0�Ĵ��� -----------------*/
    /* ���ݲ���m_InputSource������HFCKSλ�� */
    /* ���ݲ���m_CLKDivision������HFCKDIVλ�� */
    tmpreg |= oscInitStruct->m_InputSource << OSC_CTL0_HFCKS0_POS \
           | oscInitStruct->m_CLKDivision << OSC_CTL0_HFCKDIV0_POS;
    tmpmask |= OSC_CTL0_HFCK_MASK;

    OSC_CTL0 = SFR_Config (OSC_CTL0, ~tmpmask, tmpreg);

    if (oscInitStruct->m_InputSource >= HFCK_SOURCE_PLL)
    {
        CHECK_RESTRICTION(CHECK_PLL_INPUT(oscInitStruct->m_PLLInputSource));
        CHECK_RESTRICTION(CHECK_PLL_START_DELAY(oscInitStruct->m_StartDelay));
        /* PLL������ʱʱ������ */
        /*------------------ ����OSC_CTL2�Ĵ��� -----------------*/
        /* ���ݲ���m_StartDelay������PLLxDLYλ�� */
        OSC_CTL2 = SFR_Config (OSC_CTL2,
                            ~(0xF << tmpreg1),
                            oscInitStruct->m_StartDelay << tmpreg1);
    }
    else if (oscInitStruct->m_InputSource == HFCK_SOURCE_EXTHF)
    {
        /* �ⲿ������ʱʱ������ */
        CHECK_RESTRICTION(CHECK_EXT_START_DELAY(oscInitStruct->m_StartDelay));

        /*------------------ ����OSC_CTL2�Ĵ��� -----------------*/
        /* ���ݲ���m_StartDelay������EHFDLY/ELFDLYλ�� */
        OSC_CTL2 = SFR_Config (OSC_CTL2,
                            ~tmpmask1,
                            oscInitStruct->m_StartDelay << tmpreg1);
    }
    else
    {
        ;
    }
}

/**
  * ����  ��������(OSC)��Ƶ����ʱ��LFCLK��
  * ����  oscInitStruct: ����(OSC)������Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void
OSC_LFCK_Configuration (OSC_InitTypeDef* oscInitStruct)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_LFCK_INPUT(oscInitStruct->m_InputSource));
    CHECK_RESTRICTION(CHECK_LFCK_DIVISION(oscInitStruct->m_CLKDivision));

    /*------------------ ����OSC_CTL0�Ĵ��� -----------------*/
    /* ���ݲ���m_InputSource������LFCKSλ�� */
    /* ���ݲ���m_CLKDivision������LFCKDIVλ�� */
    tmpreg = oscInitStruct->m_InputSource << OSC_CTL0_LFCKS_POS \
           | oscInitStruct->m_CLKDivision << OSC_CTL0_LFCKDIV0_POS;
    OSC_CTL0 = SFR_Config (OSC_CTL0, ~OSC_CTL0_LFCK_MASK, tmpreg);

    if (oscInitStruct->m_InputSource == LFCK_INPUT_EXTLF)
    {
        /* �ⲿ������ʱʱ������ */
        CHECK_RESTRICTION(CHECK_EXT_START_DELAY(oscInitStruct->m_StartDelay));

        /*------------------ ����OSC_CTL2�Ĵ��� -----------------*/
        /* ���ݲ���m_StartDelay������ELFDLYλ�� */
        tmpreg = oscInitStruct->m_StartDelay << OSC_CTL2_ELFDLY0_POS;
        OSC_CTL2 = SFR_Config (OSC_CTL2, ~OSC_CTL2_ELFDLY, tmpreg);
    }
    else
    {
        ;
    }
}

/**
  * ����  ��������(OSC)48MHzʱ��CK48M��
  * ����  oscInitStruct: ����(OSC)������Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void
OSC_CK48M_Configuration (OSC_InitTypeDef* oscInitStruct)
{
    uint32_t tmpreg = 0;
    uint32_t tmpreg1 = 0;
    uint32_t tmpmask = 0;
    uint32_t tmpmask1 = 0;
    uint32_t sfraddr = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CK48M_SOURCE(oscInitStruct->m_InputSource));
    CHECK_RESTRICTION(CHECK_CK48M_DIVISION(oscInitStruct->m_CLKDivision));

    switch (oscInitStruct->m_InputSource)
    {
        case CK48M_SOURCE_PLL:
        {
            /* ���ݲ���m_PLLInputSource������PLLxCKSλ�� */
            tmpreg = (oscInitStruct->m_PLLInputSource \
                                << OSC_CTL0_PLL0CKS_POS);
            tmpmask = OSC_CTL0_PLL0CKS;
            /* PLL��ƵDIVSELλ��Ĵ�����ַ */
            sfraddr = (uint32_t)&PLL_CTL;
            /* PLL������ʱʱ������λ��ƫ�� */
            tmpreg1 = OSC_CTL2_PLLDLY0_POS;
        }
            break;
        case CK48M_SOURCE_INTHF:
            break;
        case CK48M_SOURCE_EXTHF:
        {
            tmpreg1 = OSC_CTL2_ELFDLY0_POS;
            tmpmask1 = OSC_CTL2_ELFDLY;
        }
            break;
        default:
            break;
    }

    if (oscInitStruct->m_InputSource >= CK48M_SOURCE_PLL)
    {
        CHECK_RESTRICTION(CHECK_PLL_INPUT(oscInitStruct->m_PLLInputSource));
        CHECK_RESTRICTION(CHECK_PLL_START_DELAY(oscInitStruct->m_StartDelay));

        /* PLL����ʱ��Դѡ��λ */
        /*------------------ ����OSC_CTL0�Ĵ��� -----------------*/
        /* ���ݲ���m_PLLInputSource������PLLxCKSλ�� */
        OSC_CTL0 = SFR_Config (OSC_CTL0, ~tmpmask, tmpreg);

        /* PLL������ʱʱ������ */
        /*------------------ ����OSC_CTL2�Ĵ��� -----------------*/
        /* ���ݲ���m_StartDelay������PLLxDLYλ�� */
        OSC_CTL2 = SFR_Config (OSC_CTL2,
                            ~(0xF << tmpreg1),
                            oscInitStruct->m_StartDelay << tmpreg1);
    }
    else if (oscInitStruct->m_InputSource == HFCK_SOURCE_EXTHF)
    {
        /* �ⲿ������ʱʱ������ */
        CHECK_RESTRICTION(CHECK_EXT_START_DELAY(oscInitStruct->m_StartDelay));

        /*------------------ ����OSC_CTL2�Ĵ��� -----------------*/
        /* ���ݲ���m_StartDelay������EHFDLY/ELFDLYλ�� */
        OSC_CTL2 = SFR_Config (OSC_CTL2,
                            ~tmpmask1,
                            oscInitStruct->m_StartDelay << tmpreg1);
    }
    else
    {
        ;
    }

    /* ��Դѡ��ͷ�Ƶϵ�� */
    /*------------------ ����OSC_CTL1�Ĵ��� -----------------*/
    /* ���ݲ���m_InputSource������CK48MSλ�� */
    /* ���ݲ���m_CLKDivision������CK48DIVλ�� */
    tmpreg = oscInitStruct->m_InputSource << OSC_CTL1_CK48MS0_POS \
           | oscInitStruct->m_CLKDivision << OSC_CTL1_CK48DIV0_POS;
    OSC_CTL1 = SFR_Config (OSC_CTL1, ~OSC_CTL1_CK48M_MASK, tmpreg);
}

/**
  * ����  ��ʼ������(OSC)������Ϣ�ṹ�塣
  * ����  oscInitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void
OSC_Struct_Init (OSC_InitTypeDef* oscInitStruct)
{
    /* ��Դѡ�� */
    oscInitStruct->m_InputSource = SCLK_SOURCE_INTHF;
    /* ʱ�ӷ�Ƶϵ�� */
    oscInitStruct->m_CLKDivision = SCLK_DIVISION_128;
    /* PLL����ʱ��Դѡ�� */
    oscInitStruct->m_PLLInputSource = PLL_INPUT_INTHF;
    /* PLL �� �ⲿ������ʱʱ������ */
    oscInitStruct->m_StartDelay = PLL_START_DELAY_64;
}
/**
  *   ##### ����(OSC)�����ʼ������������� #####
  */


/**
  *   ##### ����(OSC)�������ú��� #####
  */
/**
  * ����  ���õ�Ƶ����ʱ�ӷ�Ƶѡ��
  * ����  LFDivision: ��Ƶ����ʱ�ӷ�Ƶѡ��ȡֵ��ΧΪ��
  *                         LFCK_DIVISION_1: 1/1��Ƶ,
  *                         LFCK_DIVISION_2: 1/2��Ƶ,
  *                         LFCK_DIVISION_4: 1/4��Ƶ,
  *                         LFCK_DIVISION_8: 1/8��Ƶ,
  *                         LFCK_DIVISION_16: 1/16��Ƶ,
  *                         LFCK_DIVISION_32: 1/32��Ƶ,
  *                         LFCK_DIVISION_64: 1/64��Ƶ,
  *                         LFCK_DIVISION_128: 1/128��Ƶ,
  * ����  �ޡ�
  */
void
OSC_LFCK_Division_Config (uint32_t LFDivision)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_LFCK_DIVISION(LFDivision));

    /*---------------- ����OSC_CTL0�Ĵ���LFCKDIVλ ----------------*/
    tmpreg = LFDivision << OSC_CTL0_LFCKDIV0_POS;
    OSC_CTL0 = SFR_Config (OSC_CTL0, ~OSC_CTL0_LFCKDIV, tmpreg);
}

/**
  * ����  ���ø�Ƶ����ʱ�ӷ�Ƶѡ��
  * ����  HFDivision: ��Ƶ����ʱ�ӷ�Ƶѡ��ȡֵ��ΧΪ��
  *                         HFCK_DIVISION_1: 1/1��Ƶ,
  *                         HFCK_DIVISION_2: 1/2��Ƶ,
  *                         HFCK_DIVISION_4: 1/4��Ƶ,
  *                         HFCK_DIVISION_8: 1/8��Ƶ,
  *                         HFCK_DIVISION_16: 1/16��Ƶ,
  *                         HFCK_DIVISION_32: 1/32��Ƶ,
  *                         HFCK_DIVISION_64: 1/64��Ƶ,
  *                         HFCK_DIVISION_128: 1/128��Ƶ,
  *                         HFCK_DIVISION_256: 1/256��Ƶ,
  *                         HFCK_DIVISION_512: 1/512��Ƶ,
  * ����  �ޡ�
  */
void
OSC_HFCK_Division_Config (uint32_t HFDivision)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_HFCK_DIVISION(HFDivision));

    /*---------------- ����OSC_CTL0�Ĵ���HFCKDIVλ ----------------*/
    tmpreg = HFDivision << OSC_CTL0_HFCKDIV0_POS;
    OSC_CTL0 = SFR_Config (OSC_CTL0, ~OSC_CTL0_HFCKDIV, tmpreg);
}

/**
  * ����  ������ʱ��SCLK��Ƶѡ��
  * ����  SclkDivision: ��ʱ��SCLK��Ƶѡ��ȡֵ��ΧΪ��
  *                         SCLK_DIVISION_1: 1/1��Ƶ,
  *                         SCLK_DIVISION_2: 1/2��Ƶ,
  *                         SCLK_DIVISION_4: 1/4��Ƶ,
  *                         SCLK_DIVISION_8: 1/8��Ƶ,
  *                         SCLK_DIVISION_16: 1/16��Ƶ,
  *                         SCLK_DIVISION_32: 1/32��Ƶ,
  *                         SCLK_DIVISION_64: 1/64��Ƶ,
  *                         SCLK_DIVISION_128: 1/128��Ƶ,
  * ����  �ޡ�
  */
void
OSC_SCK_Division_Config (uint32_t SclkDivision)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SCLK_DIVISION(SclkDivision));

    /*---------------- ����OSC_CTL0�Ĵ���SCKDIVλ ----------------*/
    tmpreg = SclkDivision << OSC_CTL0_SCKDIV0_POS;
    OSC_CTL0 = SFR_Config (OSC_CTL0, ~OSC_CTL0_SCKDIV, tmpreg);
}


/**
  * ����  ����PLL����ʱ��Դѡ��
  * ����  NewState: PLL����ʱ��Դѡ��ȡֵ��ΧΪ��
  *                   PLL_INPUT_INTHF: ѡ��INTHF��ΪPLL����ʱ�ӣ�
  *                   PLL_INPUT_EXTHF: ѡ��EXTHF��ΪPLL����ʱ�ӡ�
  * ����  �ޡ�
  */
void
OSC_PLL_Input_Source_Config (uint32_t NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_PLL_INPUT(NewState));

    /*---------------- ����OSC_CTL0�Ĵ���PLL0CKSλ ----------------*/
    if (NewState != PLL_INPUT_INTHF)
    {
        /* ѡ��EXTHF��ΪPLL����ʱ�� */
        SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_PLL0CKS_POS);
    }
    else
    {
        /* ѡ��INTHF��ΪPLL����ʱ�� */
        SFR_CLR_BIT_ASM(OSC_CTL0, OSC_CTL0_PLL0CKS_POS);
    }
}

/**
  * ����  ���ø�Ƶ����ʱ��Դѡ��
  * ����  HFSource: ��Ƶ����ʱ��Դѡ��ȡֵ��ΧΪ��
  *                   HFCK_SOURCE_INTHF: ѡ��INTHF��ΪHFCLKʱ��,
  *                   HFCK_SOURCE_EXTHF: ѡ��EXTHF��ΪHFCLKʱ��,
  *                   HFCK_SOURCE_PLL: ѡ��PLL�����ΪHFCLKʱ��,
  *                   HFCK_SOURCE_PLL2: ѡ��PLL2�����ΪHFCLKʱ��,
  *                   HFCK_SOURCE_PLL1: ѡ��PLL1�����ΪHFCLKʱ��,
  * ����  �ޡ�
  */
void
OSC_HFCK_Source_Config (uint32_t HFSource)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_HFCK_SOURCE(HFSource));

    /*---------------- ����OSC_CTL0�Ĵ���HFCKSλ ----------------*/
    tmpreg = HFSource << OSC_CTL0_HFCKS0_POS;
    OSC_CTL0 = SFR_Config (OSC_CTL0, ~OSC_CTL0_HFCKS, tmpreg);
}

/**
  * ����  ���ø�Ƶ����ʱ������ʹ�ܡ�
  * ����  NewState: ��Ƶ����ʱ������ʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_HFCK_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL0�Ĵ���HFCKENλ ----------------*/
    if (NewState != FALSE)
    {
        /* HFCLKʱ���ź����� */
        SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_HFCKEN_POS);
    }
    else
    {
        /* HFCLKʱ���źŽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_CTL0, OSC_CTL0_HFCKEN_POS);
    }
}

/**
  * ����  ���õ�Ƶ����ʱ��Դѡ��
  * ����  NewState: ��Ƶ����ʱ��Դѡ��ȡֵ��ΧΪ��
  *                   LFCK_INPUT_INTLF: ѡ��INTLF��ΪLFCLKʱ�ӣ�
  *                   LFCK_INPUT_EXTLF: ѡ��EXTLF��ΪLFCLKʱ�ӡ�
  * ����  �ޡ�
  */
void
OSC_LFCK_Source_Config (uint32_t NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_LFCK_INPUT(NewState));

    /*---------------- ����OSC_CTL0�Ĵ���LFCKSλ ----------------*/
    if (NewState != LFCK_INPUT_INTLF)
    {
        /* ѡ��EXTLF��ΪLFCLKʱ�� */
        SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_LFCKS_POS);
    }
    else
    {
        /* ѡ��INTLF��ΪLFCLKʱ�� */
        SFR_CLR_BIT_ASM(OSC_CTL0, OSC_CTL0_LFCKS_POS);
    }
}

/**
  * ����  ���õ�Ƶ����ʱ������ʹ�ܡ�
  * ����  NewState: ��Ƶ����ʱ������ʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_LFCK_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL0�Ĵ���LFCKENλ ----------------*/
    if (NewState != FALSE)
    {
        /* LFCLKʱ���ź����� */
        SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_LFCKEN_POS);
    }
    else
    {
        /* LFCLKʱ���źŽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_CTL0, OSC_CTL0_LFCKEN_POS);
    }
}

/**
  * ����  ����SCLK��ʱ��ѡ��
  * ����  SclkSource: SCLK��ʱ��ѡ��ȡֵ��ΧΪ��
  *                     SCLK_SOURCE_INTHF: ѡ��INTHF��Ϊϵͳʱ��,
  *                     SCLK_SOURCE_INTLF: ѡ��INTLF��Ϊϵͳʱ��,
  *                     SCLK_SOURCE_EXTHF: ѡ��EXTHF��Ϊϵͳʱ��,
  *                     SCLK_SOURCE_EXTLF: ѡ��EXTLF��Ϊϵͳʱ��,
  *                     SCLK_SOURCE_PLL: ѡ��PLL�����Ϊϵͳʱ��,
  *                     SCLK_SOURCE_LP4M:  ѡ�� LP4M �����Ϊϵͳʱ��
  * ����  �ޡ�
  */
void
OSC_SCK_Source_Config (uint32_t SclkSource)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SCLK_SOURCE(SclkSource));

    /*---------------- ����OSC_CTL0�Ĵ���SCKSλ ----------------*/
    tmpreg = SclkSource << OSC_CTL0_SCKS0_POS;
    OSC_CTL0 = SFR_Config (OSC_CTL0, ~OSC_CTL0_SCKS, tmpreg);
}

/**
  * ����  ���ñ������Ĵ�����д����
  * ����  NewState: �������Ĵ�����д����״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_Backup_Write_Read_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL0�Ĵ���PMWRENλ ----------------*/
    if (NewState != FALSE)
    {
        /* �������ɶ�д */
        SFR_SET_BIT_ASM(OSC_CTL0, OSC_CTL0_PMWREN_POS);
    }
    else
    {
        /* ���������ɶ�д */
        SFR_CLR_BIT_ASM(OSC_CTL0, OSC_CTL0_PMWREN_POS);
    }
}

/**
  * ����  ����ϵͳʱ�����ʹ�ܡ�
  * ����  NewState: ϵͳʱ�����ʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_SCLK_Output_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL1�Ĵ���SCLKOEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ����SCLKʱ�Ӵ�IO�������CLKOUT�� */
        SFR_SET_BIT_ASM(OSC_CTL1, OSC_CTL1_SCLKOE_POS);
    }
    else
    {
        /* ��ֹSCLKʱ�Ӵ�IO�������CLKOUT�� */
        SFR_CLR_BIT_ASM(OSC_CTL1, OSC_CTL1_SCLKOE_POS);
    }
}
/**
  * ����  ���ô����� CLKOUT ���ʱ��ѡ��
  * ����  SclkSource: ���ʱ��ѡ��
  *                     CLKOUT_SCLK:  ѡ�� SCLK ��Ϊ���ʱ��
  *                     CLKOUT_EXTLF: ѡ�� EXTLF ��Ϊ���ʱ��
  *                     CLKOUT_EXTHF: ѡ�� EXTHF ��Ϊ���ʱ��
  *                     CLKOUT_INTLF: ѡ�� INTLF ��Ϊ���ʱ��
  *                     CLKOUT_INTHF: ѡ�� INTHF ��Ϊ���ʱ��
  *                     CLKOUT_PLL:   ѡ�� PLL ��Ϊ���ʱ��
  *                     CLKOUT_LP4M:  ѡ�� LP4M ��Ϊ���ʱ��
  * ����  �ޡ�
  */
void
OSC_SCLK_Output_Select (uint32_t SclkSource)
{
    uint32_t tmpreg = 0;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CLKOUT_SEL(SclkSource));

    /*---------------- ����OSC_CTL0�Ĵ���CLKOUTSλ ----------------*/
    tmpreg = SclkSource << OSC_CTL1_CLKOUTS0_POS;
    OSC_CTL1 = SFR_Config (OSC_CTL1, ~OSC_CTL1_CLKOUTS, tmpreg);
}
/**
  * ����  ����SCLK���ʱ�ӷ�Ƶѡ��
  * ����  OutputDivision: SCLK���ʱ�ӷ�Ƶѡ��λ��ȡֵ��ΧΪ��
  *                         SCLK_DIVISION_1: 1/1��Ƶ,
  *                         SCLK_DIVISION_2: 1/2��Ƶ,
  *                         SCLK_DIVISION_4: 1/4��Ƶ,
  *                         SCLK_DIVISION_8: 1/8��Ƶ,
  *                         SCLK_DIVISION_16: 1/16��Ƶ,
  *                         SCLK_DIVISION_32: 1/32��Ƶ,
  *                         SCLK_DIVISION_64: 1/64��Ƶ,
  *                         SCLK_DIVISION_128: 1/128��Ƶ,
  * ����  �ޡ�
  */
void
OSC_SCLK_Output_Division_Config (uint32_t OutputDivision)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_SCLK_DIVISION(OutputDivision));

    /*---------------- ����OSC_CTL1�Ĵ���SCLKOUTDIVλ ----------------*/
    tmpreg = OutputDivision << OSC_CTL1_SCLKOUTDIV0_POS;
    OSC_CTL1 = SFR_Config (OSC_CTL1, ~OSC_CTL1_SCLKOUTDIV, tmpreg);
}

/**
  * ����  ����ʱ�ӹ��ϼ��ʹ�ܡ�
  * ����  NewState: ʱ�ӹ��ϼ��ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_Clock_Failure_Check_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL1�Ĵ���FSCMλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʱ�ӹ��ϼ��ʹ�� */
        SFR_SET_BIT_ASM(OSC_CTL1, OSC_CTL1_FSCM_POS);
    }
    else
    {
        /* ʱ�ӹ��ϼ���ֹ */
        SFR_CLR_BIT_ASM(OSC_CTL1, OSC_CTL1_FSCM_POS);
    }
}

/**
  * ����  ����CK48Mʱ�ӷ�Ƶѡ��
  * ����  CK48MDivision: CK48Mʱ�ӷ�Ƶѡ��ȡֵ��ΧΪ��
  *                        CK48M_DIVISION_1: 1/1��Ƶ,
  *                        CK48M_DIVISION_2: 1/2��Ƶ,
  *                        CK48M_DIVISION_4: 1/4��Ƶ,
  * ����  �ޡ�
  */
void
OSC_CK48M_Division_Config (uint32_t CK48MDivision)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CK48M_DIVISION(CK48MDivision));

    /*---------------- ����OSC_CTL1�Ĵ���CK48DIVλ ----------------*/
    tmpreg = CK48MDivision << OSC_CTL1_CK48DIV0_POS;
    OSC_CTL1 = SFR_Config (OSC_CTL1, ~OSC_CTL1_CK48DIV, tmpreg);
}

/**
  * ����  ����48Mʱ������ʱ��Դѡ��
  * ����  CK48MSource: 48Mʱ������ʱ��Դѡ��ȡֵ��ΧΪ��
  *                      CK48M_SOURCE_INTHF: ѡ��INTHF��ΪCK48M����ʱ��,
  *                      CK48M_SOURCE_EXTHF: ѡ��EXTHF��ΪCK48M����ʱ��,
  *                      CK48M_SOURCE_PLL: ѡ��PLL�����ΪCK48M����ʱ��,
  * ����  �ޡ�
  */
void
OSC_CK48M_Source_Config (uint32_t CK48MSource)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CK48M_SOURCE(CK48MSource));

    /*---------------- ����OSC_CTL1�Ĵ���CK48MSλ ----------------*/
    tmpreg = CK48MSource << OSC_CTL1_CK48MS0_POS;
    OSC_CTL1 = SFR_Config (OSC_CTL1, ~OSC_CTL1_CK48MS, tmpreg);
}

/**
  * ����  ����48Mʱ������ʱ������ʹ�ܡ�
  * ����  NewState: 48Mʱ������ʱ������ʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_CK48M_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL1�Ĵ���CK48MENλ ----------------*/
    if (NewState != FALSE)
    {
        /* CK48Mʱ���ź�ʹ�� */
        SFR_SET_BIT_ASM(OSC_CTL1, OSC_CTL1_CK48MEN_POS);
    }
    else
    {
        /* CK48Mʱ���źŽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_CTL1, OSC_CTL1_CK48MEN_POS);
    }
}
/**
  * ����  ����PLL��Ƶѡ��
  * ����  PLLmultiple: PLL��Ƶ��ȡֵ��ΧΪ��
  *                PLLmultiple_M 0X04-0X3FFF��Χ(MҪ���ڵ���4, ��������200MHZ<��M*����ο�Ƶ��/N��<400MHZ)
  *                PLLmultiple_N 0X01-0XF��Χ,��������1MHZ<������ο�Ƶ��/N��<50MHZ
  *                PLLmultiple_NO ȡֵ��1/2/4/8ѡ����1����
  *
  *					�Ŵ���=PLLmultiple_M/��PLLmultiple_N*PLLmultiple_NO��
  * ����  �ޡ�
  */
void
OSC_PLL_Multiple_Value_Select (uint32_t PLLmultiple_M,uint32_t PLLmultiple_N,uint32_t PLLmultiple_NO)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_PLL_MULTIPLE_MValue(PLLmultiple_M));
    CHECK_RESTRICTION(CHECK_PLL_MULTIPLE_NValue(PLLmultiple_N));
    CHECK_RESTRICTION(CHECK_PLL_MULTIPLE_NOValue(PLLmultiple_NO));



    /*---------------- ����PLL_CTL�Ĵ���ODλNλMλ ----------------*/
    tmpreg = PLLmultiple_M << PLL_CTL_M0_POS;
    PLL_CTL = SFR_Config (PLL_CTL, ~PLL_CTL_M, tmpreg);

    tmpreg = PLLmultiple_N << PLL_CTL_N0_POS;
    PLL_CTL = SFR_Config (PLL_CTL, ~PLL_CTL_N, tmpreg);

    if(PLLmultiple_NO==8){PLLmultiple_NO=3;}
    else if(PLLmultiple_NO==4){PLLmultiple_NO=2;}
    else if(PLLmultiple_NO==2){PLLmultiple_NO=1;}
    else if(PLLmultiple_NO==1){PLLmultiple_NO=0;}
    tmpreg = PLLmultiple_NO << PLL_CTL_OD0_POS;
    PLL_CTL = SFR_Config (PLL_CTL, ~PLL_CTL_OD, tmpreg);


}
/**
  * ����  PLL��λ���ơ�
  * ���� :��
  * ���� ����
  */
void OSC_PLL_RST(void)
{
    /*---------------- ����PLL_CTL�Ĵ���PDRSTλ ----------------*/
    SFR_SET_BIT_ASM(PLL_CTL, PLL_CTL_PDRST_POS);
}
/**
  * ����  ����PLL�����ӳٿ��ơ�
  * ����  PLLDelay: PLL�����ӳٿ��ƣ�ȡֵ��ΧΪ��
  *                   PLL_START_DELAY_64: �ӳ�64��ʱ��
  *                   PLL_START_DELAY_128: �ӳ�128��ʱ��
  *                   PLL_START_DELAY_256: �ӳ�256��ʱ��
  *                   PLL_START_DELAY_512: �ӳ�512��ʱ��
  *                   PLL_START_DELAY_1024: �ӳ�1024��ʱ��
  *                   PLL_START_DELAY_2048: �ӳ�2048��ʱ��
  *                   PLL_START_DELAY_4096: �ӳ�4096��ʱ��
  *                   PLL_START_DELAY_8192: �ӳ�8192��ʱ��
  *                   PLL_START_DELAY_16384: �ӳ�16384��ʱ��
  *                   PLL_START_DELAY_32768: �ӳ�32768��ʱ��
  * ����  �ޡ�
  */
void
OSC_PLL_Start_Delay_Config (uint32_t PLLDelay)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_PLL_START_DELAY(PLLDelay));

    /*---------------- ����OSC_CTL2�Ĵ���PLLDLYλ ----------------*/
    tmpreg = PLLDelay << OSC_CTL2_PLLDLY0_POS;
    OSC_CTL2 = SFR_Config (OSC_CTL2, ~OSC_CTL2_PLLDLY, tmpreg);
}


/**
  * ����  �����ⲿ��Ƶ�����ӳٿ��ơ�
  * ����  ExternalDelay: �ⲿ��Ƶ�����ӳٿ��ƣ�ȡֵ��ΧΪ��
  *                        EXT_START_DELAY_0: �ӳ�0��ʱ��
  *                        EXT_START_DELAY_2: �ӳ�2��ʱ��
  *                        EXT_START_DELAY_4: �ӳ�4��ʱ��
  *                        EXT_START_DELAY_8: �ӳ�8��ʱ��
  *                        EXT_START_DELAY_16: �ӳ�16��ʱ��
  *                        EXT_START_DELAY_32: �ӳ�32��ʱ��
  *                        EXT_START_DELAY_64: �ӳ�64��ʱ��
  *                        EXT_START_DELAY_128: �ӳ�128��ʱ��
  *                        EXT_START_DELAY_256: �ӳ�256��ʱ��
  *                        EXT_START_DELAY_512: �ӳ�512��ʱ��
  * ����  �ޡ�
  */
void
OSC_EXTHF_Start_Delay_Config (uint32_t ExternalDelay)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_EXT_START_DELAY(ExternalDelay));

    /*---------------- ����OSC_CTL2�Ĵ���EHFDLYλ ----------------*/
    tmpreg = ExternalDelay << OSC_CTL2_EHFDLY0_POS;
    OSC_CTL2 = SFR_Config (OSC_CTL2, ~OSC_CTL2_EHFDLY, tmpreg);
}

/**
  * ����  �����ⲿ��Ƶ�����ӳٿ��ơ�
  * ����  ExternalDelay: �ⲿ��Ƶ�����ӳٿ��ƣ�ȡֵ��ΧΪ��
  *                        EXT_START_DELAY_0: �ӳ�0��ʱ��
  *                        EXT_START_DELAY_2: �ӳ�2��ʱ��
  *                        EXT_START_DELAY_4: �ӳ�4��ʱ��
  *                        EXT_START_DELAY_8: �ӳ�8��ʱ��
  *                        EXT_START_DELAY_16: �ӳ�16��ʱ��
  *                        EXT_START_DELAY_32: �ӳ�32��ʱ��
  *                        EXT_START_DELAY_64: �ӳ�64��ʱ��
  *                        EXT_START_DELAY_128: �ӳ�128��ʱ��
  *                        EXT_START_DELAY_256: �ӳ�256��ʱ��
  *                        EXT_START_DELAY_512: �ӳ�512��ʱ��
  * ����  �ޡ�
  */
void
OSC_EXTLF_Start_Delay_Config (uint32_t ExternalDelay)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_EXT_START_DELAY(ExternalDelay));

    /*---------------- ����OSC_CTL2�Ĵ���ELFDLYλ ----------------*/
    tmpreg = ExternalDelay << OSC_CTL2_ELFDLY0_POS;
    OSC_CTL2 = SFR_Config (OSC_CTL2, ~OSC_CTL2_ELFDLY, tmpreg);
}

/**
  * ����  ����PLL���ʹ�ܡ�
  * ����  NewState: PLL���ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_PLL_Software_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL2�Ĵ���PLLSWENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��PLL���� */
        SFR_SET_BIT_ASM(OSC_CTL2, OSC_CTL2_PLLSWEN_POS);
    }
    else
    {
        /* ��Ч */
        SFR_CLR_BIT_ASM(OSC_CTL2, OSC_CTL2_PLLSWEN_POS);
    }
}

/**
  * ����  �����ⲿ��Ƶ�������ʹ�ܡ�
  * ����  NewState: �ⲿ��Ƶ�������ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_EXTHF_Software_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL2�Ĵ���EXTHFSWENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ���ⲿ��Ƶ�������� */
        SFR_SET_BIT_ASM(OSC_CTL2, OSC_CTL2_EXTHFSWEN_POS);
    }
    else
    {
        /* ��Ч */
        SFR_CLR_BIT_ASM(OSC_CTL2, OSC_CTL2_EXTHFSWEN_POS);
    }
}

/**
  * ����  �����ⲿ��Ƶ�������ʹ�ܡ�
  * ����  NewState: �ⲿ��Ƶ�������ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_EXTLF_Software_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL2�Ĵ���EXTLFSWENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ���ⲿ��Ƶ�������� */
        SFR_SET_BIT_ASM(OSC_CTL2, OSC_CTL2_EXTLFSWEN_POS);
    }
    else
    {
        /* ��Ч */
        SFR_CLR_BIT_ASM(OSC_CTL2, OSC_CTL2_EXTLFSWEN_POS);
    }
}

/**
  * ����  �����ڲ���Ƶ�������ʹ�ܡ�
  * ����  NewState: �ڲ���Ƶ�������ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_INTHF_Software_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL2�Ĵ���INTHFSWENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ���ڲ���Ƶ�������� */
        SFR_SET_BIT_ASM(OSC_CTL2, OSC_CTL2_INTHFSWEN_POS);
    }
    else
    {
        /* ��Ч */
        SFR_CLR_BIT_ASM(OSC_CTL2, OSC_CTL2_INTHFSWEN_POS);
    }
}

/**
  * ����  �����ڲ���Ƶ�������ʹ�ܡ�
  * ����  NewState: �ڲ���Ƶ�������ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_INTLF_Software_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_CTL2�Ĵ���INTLFSWENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ���ڲ���Ƶ�������� */
        SFR_SET_BIT_ASM(OSC_CTL2, OSC_CTL2_INTLFSWEN_POS);
    }
    else
    {
        /* ��Ч */
        SFR_CLR_BIT_ASM(OSC_CTL2, OSC_CTL2_INTLFSWEN_POS);
    }
}

/**
  * ����  ��������Ư�ľ���ֵУ׼Ȩ��λ��
  * ����  Scale: ����Ư������ѡ��ȡֵΪ���к��һ��������ϣ�
  *                ZERO_DRIFT_SCALEDIV32: 1/32uA������
  *                ZERO_DRIFT_SCALEDIV16: 1/16uA������
  *                ZERO_DRIFT_SCALEDIV8: 1/8uA������
  *                ZERO_DRIFT_SCALEDIV4: 1/4uA������
  *                ZERO_DRIFT_SCALEDIV2: 1/2uA������
  *                ZERO_DRIFT_SCALE1X: 1uA������
  *                ZERO_DRIFT_SCALE2X: 2uA������
  *                ZERO_DRIFT_SCALE4X: 4uA������
  *                ZERO_DRIFT_SCALE8X: 8uA������
  *                ZERO_DRIFT_SCALE16X0: 16uA������
  *                ZERO_DRIFT_SCALE16X1: 16uA������
  *                ZERO_DRIFT_SCALE16X2: 16uA������
  *                ZERO_DRIFT_SCALE16X3: 16uA������
  *                ZERO_DRIFT_SCALE16X4: 16uA������
  *                ZERO_DRIFT_SCALE32X: 32uA������
  *       NewState: ����Ư������״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_Zero_Drift_Config (uint32_t Scale, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_ZERO_DRIFT(Scale));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_HFOSCCAL0�Ĵ��� ----------------*/
    if (NewState != FALSE)
    {
        /* ָ������������ */
        OSC_HFOSCCAL0 |= Scale;
    }
    else
    {
        /* ָ���������ر� */
        OSC_HFOSCCAL0 &= ~Scale;
    }
}

/**
  * ����  �����ڲ���Ƶ���������µ��ڡ�
  * ����  PositiveDrift: �ڲ���Ƶ���������µ��ڣ�ȡֵ��ΧΪ��0~31��
  * ����  �ޡ�
  */
void
OSC_Positive_Drift_Config (uint32_t PositiveDrift)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_POSITIVE_DRIFT(PositiveDrift));

    /*---------------- ����OSC_HFOSCCAL0�Ĵ���PTATλ ----------------*/
    tmpreg = PositiveDrift << OSC_HFOSCCAL0_PTAT0_POS;
    OSC_HFOSCCAL0 = SFR_Config (OSC_HFOSCCAL0, ~OSC_HFOSCCAL0_PTAT, tmpreg);
}

/**
  * ����  �����ڲ���Ƶ�����ĸ��µ��ڡ�
  * ����  NegativeDrift: �ڲ���Ƶ�����ĸ��µ��ڣ�ȡֵ��ΧΪ��0~31��
  * ����  �ޡ�
  */
void
OSC_Negative_Drift_Config (uint32_t PositiveDrift)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_NEGATIVE_DRIFT(PositiveDrift));

    /*---------------- ����OSC_HFOSCCAL0�Ĵ���CTATλ ----------------*/
    tmpreg = PositiveDrift << OSC_HFOSCCAL0_CTAT0_POS;
    OSC_HFOSCCAL0 = SFR_Config (OSC_HFOSCCAL0, ~OSC_HFOSCCAL0_CTAT, tmpreg);
}

/**
  * ����  ���õ�������ѡ��
  * ����  CurrentGain: ��������ѡ��ȡֵ��ΧΪ��0~3��
  * ����  �ޡ�
  */
void
OSC_Current_Gain_Config (uint32_t PositiveDrift)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CURRENT_GAIN(PositiveDrift));

    /*---------------- ����OSC_HFOSCCAL1�Ĵ���SELGAINλ ----------------*/
    tmpreg = PositiveDrift << OSC_HFOSCCAL1_SELGAIN0_POS;
    OSC_HFOSCCAL1 = SFR_Config (OSC_HFOSCCAL1, ~OSC_HFOSCCAL1_SELGAIN, tmpreg);
}

/**
  * ����  ���ø���ѡ��
  * ����  NewState: ����ѡ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_High_Speed_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_HFOSCCAL1�Ĵ���HSFSENλ ----------------*/
    if (NewState != FALSE)
    {
        /* �ж�ʹ�� */
        SFR_SET_BIT_ASM(OSC_HFOSCCAL1, OSC_HFOSCCAL1_HSFSEN_POS);
    }
    else
    {
        /* �жϽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_HFOSCCAL1, OSC_HFOSCCAL1_HSFSEN_POS);
    }
}

/**
  * ����  �����ⲿ��Ƶ��������ʹ�ܡ�
  * ����  NewState: �ⲿ��Ƶ��������ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_External_Input_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_HFOSCCAL1�Ĵ���HSXTALEXENλ ----------------*/
    if (NewState != FALSE)
    {
        /* �ж�ʹ�� */
        SFR_SET_BIT_ASM(OSC_HFOSCCAL1, OSC_HFOSCCAL1_HSXTALEXEN_POS);
    }
    else
    {
        /* �жϽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_HFOSCCAL1, OSC_HFOSCCAL1_HSXTALEXEN_POS);
    }
}

/**
  * ����  ���÷���������ڡ�
  * ����  NewState: ����������ڣ�ȡֵ��ΧΪ��
  *                   FREQUENCY_MORE_THAN_10M: Ƶ�ʴ���10MHz��
  *                   FREQUENCY_LESS_THAN_10M: Ƶ��С��10MHz��
  * ����  �ޡ�
  */
void
OSC_Feedback_Resistance_Config (uint32_t NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FEEDBACK_RESISTANCE(NewState));

    /*---------------- ����OSC_HFOSCCAL1�Ĵ���HLSWλ ----------------*/
    if (NewState != FREQUENCY_MORE_THAN_10M)
    {
        /* Ƶ��С��10MHz */
        SFR_SET_BIT_ASM(OSC_HFOSCCAL1, OSC_HFOSCCAL1_HLSW_POS);
    }
    else
    {
        /* Ƶ�ʴ���10MHz */
        SFR_CLR_BIT_ASM(OSC_HFOSCCAL1, OSC_HFOSCCAL1_HLSW_POS);
    }
}
/**
  * ����  ����PLL����Ư����Դ�����IO��ʹ�ܡ�
  * ����  NewState: PLL����Ư����Դ�����IO��ʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_PLL_Zero_Source_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����PLL_CTL0�Ĵ���TSZEROISλ ----------------*/
    if (NewState != FALSE)
    {
        /* ������Ư����Դ��IO��ͨ�� */
        SFR_SET_BIT_ASM(PLL_CTL, PLL_CTL_TSZEROIS_POS);
    }
    else
    {
        /* �ر�����Ư����Դ��IO��ͨ�� */
        SFR_CLR_BIT_ASM(PLL_CTL, PLL_CTL_TSZEROIS_POS);
    }
}

/**
  * ����  ����PLL�ڲ��ο���ѹ2V�����IO�ڵ�ʹ�ܡ�
  * ����  NewState: PLL�ڲ��ο���ѹ2V�����IO�ڵ�ʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_PLL_Vref2_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����PLL_CTL0�Ĵ���TSVREF2Vλ ----------------*/
    if (NewState != FALSE)
    {
        /* ���ڲ��ο���ѹ2V��IO��ͨ�� */
        SFR_SET_BIT_ASM(PLL_CTL, PLL_CTL_TSVREF2V_POS);
    }
    else
    {
        /* �ر��ڲ��ο���ѹ2V��IO��ͨ�� */
        SFR_CLR_BIT_ASM(PLL_CTL, PLL_CTL_TSVREF2V_POS);
    }
}

/**
  * ����  ����PLL�ڲ��͹���BG�ο�0.5V���ڲ�buffer��ʹ�ܡ�
  * ����  NewState: PLL�ڲ��͹���BG�ο�0.5V���ڲ�buffer��ʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_PLL_Vref0p5_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����PLL_CTL0�Ĵ���TSVREF0P5λ ----------------*/
    if (NewState != FALSE)
    {
        /* ���ڲ��͹���BG�ο�0.5V���ڲ�buffer��ͨ�� */
        SFR_SET_BIT_ASM(PLL_CTL, PLL_CTL_TSVREF0P5_POS);
    }
    else
    {
        /* �ر��ڲ��͹���BG�ο�0.5V���ڲ�buffer��ͨ�� */
        SFR_CLR_BIT_ASM(PLL_CTL, PLL_CTL_TSVREF0P5_POS);
    }
}

/**
  * ����  ����PLL��BG���ڲ�buffer��ͨ��ʹ�ܡ�
  * ����  NewState: PLL��BG���ڲ�buffer��ͨ��ʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_PLL_Vref1p2_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����PLL_CTL0�Ĵ���TSMRBGλ ----------------*/
    if (NewState != FALSE)
    {
        /* ����BG�ο�1.2V���ڲ�buffer��ͨ�� */
        SFR_SET_BIT_ASM(PLL_CTL, PLL_CTL_TSMRBG_POS);
    }
    else
    {
        /* �ر�BG�ο�1.2V���ڲ�buffer��ͨ�� */
        SFR_CLR_BIT_ASM(PLL_CTL, PLL_CTL_TSMRBG_POS);
    }
}

/**
  * ����  ����PLL�ڲ��͹���BG�ĵ���Դ20nA��IO�ڵ�ѡͨʹ�ܡ�
  * ����  NewState: PLL�ڲ��͹���BG�ĵ���Դ20nA��IO�ڵ�ѡͨʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_PLL_Low_Power_20nA_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����PLL_CTL0�Ĵ���TSLSRCISλ ----------------*/
    if (NewState != FALSE)
    {
        /* ���ڲ��͹���BG�ĵ���Դ20nA��IO�ڵ�ͨ�� */
        SFR_SET_BIT_ASM(PLL_CTL, PLL_CTL_TSLSRCIS_POS);
    }
    else
    {
        /* �ر��ڲ��͹���BG�ĵ���Դ20nA��IO�ڵ�ͨ�� */
        SFR_CLR_BIT_ASM(PLL_CTL, PLL_CTL_TSLSRCIS_POS);
    }
}

/**
  * ����  ����PLL�ڲ��͹��Ĳο���ѹ1.14V���ڲ�buffer��ѡͨʹ�ܡ�
  * ����  NewState: PLL�ڲ��͹��Ĳο���ѹ1.14V���ڲ�buffer��ѡͨʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_PLL_Vref1p14_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����PLL_CTL0�Ĵ���TSLPBGλ ----------------*/
    if (NewState != FALSE)
    {
        /* ���ڲ��͹��Ĳο���ѹ1.14V���ڲ�buffer��ͨ�� */
        SFR_SET_BIT_ASM(PLL_CTL, PLL_CTL_TSLPBG_POS);
    }
    else
    {
        /* �ر��ڲ��͹��Ĳο���ѹ1.14V���ڲ�buffer��ͨ�� */
        SFR_CLR_BIT_ASM(PLL_CTL, PLL_CTL_TSLPBG_POS);
    }
}

/**
  * ����  ����PLL�ڲ��͹���ƫ�õ�·�ĵ���Դ100nA��IO�ڵ�ѡͨʹ�ܡ�
  * ����  NewState: PLL�ڲ��͹���ƫ�õ�·�ĵ���Դ100nA��IO�ڵ�ѡͨʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_PLL_Low_Power_100nA_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����PLL_CTL0�Ĵ���TSLCDISλ ----------------*/
    if (NewState != FALSE)
    {
        /* ���ڲ��͹���ƫ�õ�·�ĵ���Դ100nA��IO�ڵ�ͨ�� */
        SFR_SET_BIT_ASM(PLL_CTL, PLL_CTL_TSLCDIS_POS);
    }
    else
    {
        /* �ر��ڲ��͹���ƫ�õ�·�ĵ���Դ100nA��IO�ڵ�ͨ�� */
        SFR_CLR_BIT_ASM(PLL_CTL, PLL_CTL_TSLCDIS_POS);
    }
}

/**
  * ����  ����PLL�ڲ���ƵLDO���ڲ�buffer��ѡͨʹ�ܡ�
  * ����  NewState: PLL�ڲ���ƵLDO���ڲ�buffer��ѡͨʹ��״̬��
  *                 ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_PLL_LDO_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����PLL_CTL0�Ĵ���TSHSILDO12λ ----------------*/
    if (NewState != FALSE)
    {
        /* ���ڲ���ƵLDO���ڲ�buffer��ͨ�� */
        SFR_SET_BIT_ASM(PLL_CTL, PLL_CTL_TSHSILDO12_POS);
    }
    else
    {
        /* �ر��ڲ���ƵLDO���ڲ�buffer��ͨ�� */
        SFR_CLR_BIT_ASM(PLL_CTL, PLL_CTL_TSHSILDO12_POS);
    }
}

/**
  * ����  ����PLL�ж�ʹ�ܡ�
  * ����  NewState: PLL�ж�ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_PLL_INT_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_INT�Ĵ���PLLIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* �ж�ʹ�� */
        SFR_SET_BIT_ASM(OSC_INT, OSC_INT_PLLIE_POS);
    }
    else
    {
        /* �жϽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_INT, OSC_INT_PLLIE_POS);
    }
}

/**
  * ����  �����ⲿ��Ƶ�ж�ʹ�ܡ�
  * ����  NewState: �ⲿ��Ƶ�ж�ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_EXTHF_INT_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_INT�Ĵ���EHFIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* �ж�ʹ�� */
        SFR_SET_BIT_ASM(OSC_INT, OSC_INT_EHFIE_POS);
    }
    else
    {
        /* �жϽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_INT, OSC_INT_EHFIE_POS);
    }
}

/**
  * ����  �����ⲿ��Ƶ�ж�ʹ�ܡ�
  * ����  NewState: �ⲿ��Ƶ�ж�ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_EXTLF_INT_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_INT�Ĵ���ELFIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* �ж�ʹ�� */
        SFR_SET_BIT_ASM(OSC_INT, OSC_INT_ELFIE_POS);
    }
    else
    {
        /* �жϽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_INT, OSC_INT_ELFIE_POS);
    }
}

/**
  * ����  �����ڲ���Ƶ�ж�ʹ�ܡ�
  * ����  NewState: �ڲ���Ƶ�ж�ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_INTHF_INT_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_INT�Ĵ���IHFIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* �ж�ʹ�� */
        SFR_SET_BIT_ASM(OSC_INT, OSC_INT_IHFIE_POS);
    }
    else
    {
        /* �жϽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_INT, OSC_INT_IHFIE_POS);
    }
}

/**
  * ����  �����ڲ���Ƶ�ж�ʹ�ܡ�
  * ����  NewState: �ڲ���Ƶ�ж�ʹ��״̬��ȡֵ��ΧΪ��TRUE �� FALSE��
  * ����  �ޡ�
  */
void
OSC_INTLF_INT_Enable (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����OSC_INT�Ĵ���ILFIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* �ж�ʹ�� */
        SFR_SET_BIT_ASM(OSC_INT, OSC_INT_ILFIE_POS);
    }
    else
    {
        /* �жϽ�ֹ */
        SFR_CLR_BIT_ASM(OSC_INT, OSC_INT_ILFIE_POS);
    }
}

/**
  * ����  ��ȡʱ�ӹ��ϱ�־��
  * ����  �ޡ�
  * ����  ʱ�ӹ���״̬��0��û��ʱ�ӹ��ϣ�1����⵽ʱ�ӹ��ϡ�
  */
FlagStatus
OSC_Get_Clock_Failure_INT_Flag (void)
{
    /*---------------- ����OSC_INT�Ĵ���CKFIFλ ----------------*/
    if (OSC_INT & OSC_INT_CKFIF)
    {
        /* ��⵽ʱ�ӹ��� */
        return SET;
    }
    else
    {
        /* û��ʱ�ӹ��� */
        return RESET;
    }
}

/**
  * ����  ��ȡPLL�жϱ�־��
  * ����  �ޡ�
  * ����  �ж�״̬��0��δ�����жϣ�1�������жϡ�
  */
FlagStatus
OSC_Get_PLL_INT_Flag (void)
{
    /*---------------- ����OSC_INT�Ĵ���PLLIFλ ----------------*/
    if (OSC_INT & OSC_INT_PLLIF)
    {
        /* PLL���� */
        return SET;
    }
    else
    {
        /* PLLδ���� */
        return RESET;
    }
}

/**
  * ����  ��ȡ�ⲿ��Ƶ�жϱ�־��
  * ����  �ޡ�
  * ����  �ж�״̬��0��δ�����жϣ�1�������жϡ�
  */
FlagStatus
OSC_Get_EXTHF_INT_Flag (void)
{
    /*---------------- ����OSC_INT�Ĵ���EHFIFλ ----------------*/
    if (OSC_INT & OSC_INT_EHFIF)
    {
        /* PLL���� */
        return SET;
    }
    else
    {
        /* PLLδ���� */
        return RESET;
    }
}

/**
  * ����  ��ȡ�ⲿ��Ƶ�жϱ�־��
  * ����  �ޡ�
  * ����  �ж�״̬��0��δ�����жϣ�1�������жϡ�
  */
FlagStatus
OSC_Get_EXTLF_INT_Flag (void)
{
    /*---------------- ����OSC_INT�Ĵ���ELFIFλ ----------------*/
    if (OSC_INT & OSC_INT_ELFIF)
    {
        /* PLL���� */
        return SET;
    }
    else
    {
        /* PLLδ���� */
        return RESET;
    }
}

/**
  * ����  ��ȡ�ڲ���Ƶ�жϱ�־��
  * ����  �ޡ�
  * ����  �ж�״̬��0��δ�����жϣ�1�������жϡ�
  */
FlagStatus
OSC_Get_INTHF_INT_Flag (void)
{
    /*---------------- ����OSC_INT�Ĵ���IHFIFλ ----------------*/
    if (OSC_INT & OSC_INT_IHFIF)
    {
        /* PLL���� */
        return SET;
    }
    else
    {
        /* PLLδ���� */
        return RESET;
    }
}

/**
  * ����  ��ȡ�ڲ���Ƶ�жϱ�־��
  * ����  �ޡ�
  * ����  �ж�״̬��0��δ�����жϣ�1�������жϡ�
  */
FlagStatus
OSC_Get_INTLF_INT_Flag (void)
{
    /*---------------- ����OSC_INT�Ĵ���ILFIFλ ----------------*/
    if (OSC_INT & OSC_INT_ILFIF)
    {
        /* PLL���� */
        return SET;
    }
    else
    {
        /* PLLδ���� */
        return RESET;
    }
}
/**
  * ����  ��ȡLP4M�жϱ�־��
  * ����  �ޡ�
  * ����  �ж�״̬��0��δ�����жϣ�1�������жϡ�
  */
FlagStatus
OSC_Get_LP4MIF_INT_Flag (void)
{
    /*---------------- ����OSC_INT�Ĵ���ILFIFλ ----------------*/
    if (OSC_INT & OSC_INT_LP4MIF)
    {
        /* PLL���� */
        return SET;
    }
    else
    {
        /* PLLδ���� */
        return RESET;
    }
}
/**
  *   ##### ����(OSC)�жϿ��ƺ���������� #####
  */

