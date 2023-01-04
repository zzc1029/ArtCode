/**
  ******************************************************************************
  * �ļ���  kf32a_basic_usart.c
  * ��  ��  ChipON_AE/FAE_Group
  * ��  ��  V2.62
  * ��  ��  2019-11-16
  * ��  ��  ���ļ��ṩ��USARTģ��(USART)��صĹ��ܺ�����������
  *          + USARTģ��(USART)��ʼ������
  *          + USARTģ��(USART)�������ú���
  *          + USARTģ��(USART)7816��ʼ�������ú���
  *          + USARTģ��(USART)�жϹ�����
  *
  *********************************************************************
  */

#include "kf32a_basic_usart.h"
#include "kf32a_basic_rst.h"
#include "kf32a_basic_pclk.h"

/* USART˽�ж��� ----------------------------------------------------*/
/* USARTx_CTLR�Ĵ����������� */
#define USART_CTLR_INIT_MASK            (USART_CTLR_SYNC \
                                       | USART_CTLR_CSRS \
                                       | USART_CTLR_TXEN \
                                       | USART_CTLR_RXEN \
                                       | USART_CTLR_DT9EN \
                                       | USART_CTLR_STPW \
                                       | USART_CTLR_PARM \
                                       | USART_CTLR_RTSEN \
                                       | USART_CTLR_CTSEN)

/* USARTx_U7816R_�Ĵ����������� */
#define USART_U7816R_INIT_MASK          (USART_U7816R_ERSW \
                                       | USART_U7816R_PSEL \
                                       | USART_U7816R_TXRE \
                                       | USART_U7816R_RXRE \
                                       | USART_U7816R_CLKOUT \
                                       | USART_U7816R_CLKDIV \
                                       | USART_U7816R_EGT)

/* USARTx_BRGR_�Ĵ����������� */
#define USART_BRGR_INIT_MASK            (USART_BRGR_BRGM \
                                       | USART_BRGR_BRGF1 \
                                       | USART_BRGR_BRGF2)


/**
  *   ##### USARTģ��(USART)��ʼ������ #####
  */
/**
  * ����  USART���踴λ
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  �ޡ�
  */
void
USART_Reset (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
#ifdef  KF32A_Periph_usart0
    if (USARTx == USART0_SFR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_USART0RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_USART0RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_USART0CLKEN, TRUE);
    }
#endif
#ifdef  KF32A_Periph_usart1
    if (USARTx == USART1_SFR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_USART1RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_USART1RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_USART1CLKEN, TRUE);
    }
#endif
#ifdef  KF32A_Periph_usart2
    if (USARTx == USART2_SFR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_USART2RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_USART2RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_USART2CLKEN, TRUE);
    }
#endif
#ifdef  KF32A_Periph_usart3
    if (USARTx == USART3_SFR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_USART3RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_USART3RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_USART3CLKEN, TRUE);
    }
#endif
#ifdef  KF32A_Periph_usart4
    if (USARTx == USART4_SFR)
    {
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_USART4RST, TRUE);
        RST_CTL1_Peripheral_Reset_Enable(RST_CTL1_USART4RST, FALSE);
        PCLK_CTL1_Peripheral_Clock_Enable(PCLK_CTL1_USART4CLKEN, TRUE);
    }
#endif
#ifdef  KF32A_Periph_usart5
   if (USARTx == USART5_SFR)
    {
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_USART5RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_USART5RST, FALSE);
        PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_USART5CLKEN, TRUE);
    }
#endif
#ifdef  KF32A_Periph_usart6
   if (USARTx == USART6_SFR)
    {
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_USART6RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_USART6RST, FALSE);
        PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_USART6CLKEN, TRUE);
    }
#endif
#ifdef  KF32A_Periph_usart7
    if (USARTx == USART7_SFR)
    {
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_USART7RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_USART7RST, FALSE);
        PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_USART7CLKEN, TRUE);
    }
#endif
}

/**
  * ����  ����USART�����ʼ����
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       USARTInitStruct: USART������Ϣ�ṹ��ָ�롣
  * ����  ��
  */
void
USART_Configuration (USART_SFRmap* USARTx, USART_InitTypeDef* usartInitStruct)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_USART_MODE(usartInitStruct->m_Mode));
    CHECK_RESTRICTION(CHECK_USART_CLOCKSOURCE(usartInitStruct->m_HalfDuplexClkSource));
    CHECK_RESTRICTION(CHECK_USART_DIRECTION(usartInitStruct->m_TransferDir));
    CHECK_RESTRICTION(CHECK_USART_WORD_LENGTH(usartInitStruct->m_WordLength));
    CHECK_RESTRICTION(CHECK_USART_STOPBITS(usartInitStruct->m_StopBits));//
    CHECK_RESTRICTION(CHECK_USART_Bit9_MODE(usartInitStruct->m_Bit9SEL));
    CHECK_RESTRICTION(CHECK_USART_PARITY(usartInitStruct->m_Parity));
    CHECK_RESTRICTION(CHECK_USART_ABRDEN(usartInitStruct->m_BRAutoDetect));
    CHECK_RESTRICTION(CHECK_USART_HARDWARE_FLOW_CONTROL(usartInitStruct->m_HardwareFlowControl));
    CHECK_RESTRICTION(CHECK_USART_RECEIVE_DIR(usartInitStruct->m_ReceiveOrder));
    CHECK_RESTRICTION(CHECK_USART_TRANSMIT_DIR(usartInitStruct->m_TransmitOrder));
    CHECK_RESTRICTION(CHECK_USART_CLK(usartInitStruct->m_BaudRateBRCKS));
    CHECK_RESTRICTION(CHECK_USART_BAUDRATE_DECIMAL(usartInitStruct->m_BaudRateNumerator));
    CHECK_RESTRICTION(CHECK_USART_BAUDRATE_DECIMAL(usartInitStruct->m_BaudRateDenominator));

    /*------------------- USART_CTLR�Ĵ�������  -----------------*/
    /* ���ݽṹ���Աm_Mode������SYNCλ�� */
    /* ���ݽṹ���Աm_HalfDuplexClkSource������CSRSλ�� */
    /* ���ݽṹ���Աm_TransferDir������TXEN/RXENλ�� */
    /* ���ݽṹ���Աm_WordLength������DT9ENλ�� */
    /* ���ݽṹ���Աm_StopBits������STPWλ�� */
    /* ���ݽṹ���Աm_Bit9SEL������TX9SELλ�� */
    /* ���ݽṹ���Աm_Parity������PARMλ�� */
    /* ���ݽṹ���Աm_HardwareFlowControl������RTSEN/CTSENλ�� */
    tmpreg = ((usartInitStruct->m_Mode)     \
            | (usartInitStruct->m_HalfDuplexClkSource)  \
            | (usartInitStruct->m_TransferDir)  \
            | (usartInitStruct->m_WordLength)  \
            | (usartInitStruct->m_Bit9SEL)   \
            | (usartInitStruct->m_StopBits)   \
            | (usartInitStruct->m_ReceiveOrder)   \
            | (usartInitStruct->m_TransmitOrder)   \
            | (usartInitStruct->m_Parity)     \
            | (usartInitStruct->m_BRAutoDetect)     \
            | (usartInitStruct->m_HardwareFlowControl)     \
            | (usartInitStruct->m_BaudRateBRCKS));

    USARTx->CTLR = SFR_Config (USARTx->CTLR, ~USART_CTLR_INIT_MASK, tmpreg);

    /*------------------- USART_BRGR�Ĵ�������  -----------------*/
    /* ���ݽṹ���Աm_BaudRateInteger������BRGMλ�� */
    /* ���ݽṹ���Աm_BaudRateNumerator������BRGF1λ�� */
    /* ���ݽṹ���Աm_BaudRateDenominator������BRGF2λ�� */
    tmpreg = ((uint32_t)usartInitStruct->m_BaudRateInteger << USART_BRGR_BRGM0_POS)  \
            | ((uint32_t)usartInitStruct->m_BaudRateNumerator << USART_BRGR_BRGF1_0_POS)   \
            | ((uint32_t)usartInitStruct->m_BaudRateDenominator << USART_BRGR_BRGF2_0_POS);
    USARTx->BRGR = SFR_Config (USARTx->BRGR, ~USART_BRGR_INIT_MASK, tmpreg);
}

/**
  * ����  7816�������á�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       USARTInitStruct: USART_U7816������Ϣ
  * ����  ��
  */
void
USART_U7816R_Configuration (USART_SFRmap* USARTx, U7816R_InitTypeDef* usartInitStruct)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_U7816R_ERRORSIGNAL(usartInitStruct->m_ErrorSignal));
    CHECK_RESTRICTION(CHECK_U7816R_PASSAGEWAY_SELECT(usartInitStruct->m_PassagewaySelect));
    CHECK_RESTRICTION(CHECK_U7816R_TRANSMIT_REPEAT(usartInitStruct->m_TransmitRepeat));
    CHECK_RESTRICTION(CHECK_U7816R_RECEIVE_REPEAT(usartInitStruct->m_ReceiveRepeat));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(usartInitStruct->m_Clkout));

    /*---------------------------- USARTx_U7816R�Ĵ�������  -----------------*/
    /* ���ݽṹ���Աm_ErrorSignal������ERSWλ�� */
    /* ���ݽṹ���Աm_PassagewaySelect������PSELλ�� */
    /* ���ݽṹ���Աm_TransmitRepeat������TXREλ�� */
    /* ���ݽṹ���Աm_ReceiveRepeat������RXREλ�� */
    /* ���ݽṹ���Աm_Clkout������CLKOUTλ�� */
    /* ���ݽṹ���Աm_ClkDiv������CLKDIVλ�� */
    /* ���ݽṹ���Աm_Egt������EGTλ�� */

    tmpreg = ((usartInitStruct->m_ErrorSignal)      \
            | (usartInitStruct->m_PassagewaySelect) \
            | (usartInitStruct->m_TransmitRepeat)   \
            | (usartInitStruct->m_ReceiveRepeat)    \
            | ((uint32_t)usartInitStruct->m_Clkout << USART_U7816R_CLKOUT_POS) \
            | ((uint32_t)usartInitStruct->m_Egt << USART_U7816R_EGT0_POS)      \
            | ((uint32_t)usartInitStruct->m_ClkDiv << USART_U7816R_CLKDIV0_POS));
    USARTx->U7816R = SFR_Config (USARTx->U7816R, ~USART_U7816R_INIT_MASK, tmpreg);
}

/**
  * ����  ��ʼ��USART������Ϣ�ṹ�塣
  * ����  usartInitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void
USART_Struct_Init(USART_InitTypeDef* usartInitStruct)
{
    /* ��ʼ�� USARTģʽ */
    usartInitStruct->m_Mode = USART_MODE_FULLDUPLEXASY;

    /* ��ʼ�� USARTʱ��Դѡ�� */
    usartInitStruct->m_HalfDuplexClkSource = USART_SLAVE_CLOCKSOURCE_EXTER;

    /* ��ʼ�� USART���䷽�� */
    usartInitStruct->m_TransferDir = USART_DIRECTION_TRANSMIT;

    /* ��ʼ�� USART�ֳ� */
    usartInitStruct->m_WordLength = USART_WORDLENGTH_8B;

    /* ��ʼ�� USARTֹͣλ */
    usartInitStruct->m_StopBits = USART_STOPBITS_1;

    /* ��ʼ�� USART�������ݵ�9λ���� */
    usartInitStruct->m_Bit9SEL = USART_BIT9_PAR;

    /* ��ʼ�� USART��żУ��λ */
    usartInitStruct->m_Parity = USART_PARITY_ODD;

    /* ��ʼ�� USART���մ��� */
    usartInitStruct->m_ReceiveOrder = USART_RECEIVE_LSB;

    /* ��ʼ��USART���ʹ��� */
    usartInitStruct->m_TransmitOrder = USART_TRANSMIT_LSB;

    /* ��ʼ�� USART�Զ������ʼ��ʹ��λ */
    usartInitStruct->m_BRAutoDetect = USART_ABRDEN_OFF;

    /* ��ʼ�� USARTӲ�������� */
    usartInitStruct->m_HardwareFlowControl = USART_HARDWAREFLOWCONTROL_NONE;

    /* ��ʼ�� USART�����ʷ�����ʱ��ѡ�� */
    usartInitStruct->m_BaudRateBRCKS = USART_CLK_SCLK;

    /* ��ʼ�� USART�������������� */
    usartInitStruct->m_BaudRateInteger = 1;

    /* ��ʼ�� USART������С�����Ӳ��� */
    usartInitStruct->m_BaudRateNumerator = 0;

    /* ��ʼ�� USART������С����ĸ���� */
    usartInitStruct->m_BaudRateDenominator = 1;
}

/**
  * ����  ��ʼ��USART_7816������Ϣ�ṹ�塣
  * ����  usartInitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void
USART_U7816R_Struct_Init(U7816R_InitTypeDef* usartInitStruct)
{
    /* ��ʼ�� USART������ */
    usartInitStruct->m_ErrorSignal = USART_U7816R_ERRORSIGNAL_2ETU;

    /* ��ʼ�� USART����ͨ�� */
    usartInitStruct->m_PassagewaySelect = USART_U7816R_PASSAGEWAY_TX0;

    /* ��ʼ�� USART��żУ�����ʱ�ط��͵������� */
    usartInitStruct->m_TransmitRepeat = USART_U7816R_TRANSMIT_REPEAT_0S;

    /* ��ʼ�� USART��żУ�����ʱ�ؽ��յ������� */
    usartInitStruct->m_ReceiveRepeat = USART_U7816R_RECEIVE_REPEAT_0S;

    /* ��ʼ�� USB�˵�����ʹ�� */
    usartInitStruct->m_Clkout = FALSE;

    /* ��ʼ�� 7816����ʱ�Ӻ��������ʱ�ӿ��� */
    usartInitStruct->m_ClkDiv = 0;

    /* ��ʼ�� ����ʱ�����EGT */
    usartInitStruct->m_Egt = 0;
}
/**
  *   ##### USARTģ��(USART)��ʼ������������� #####
  */


/**
  *   ##### USARTģ��(USART)�������ú��� #####
  */
/**
  * ����  ����USARTʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USARTʹ��ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Cmd (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_CTLR�Ĵ���USARTENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART */
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_USARTEN_POS);
    }
    else
    {
        /* ��ֹUSART */
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_USARTEN_POS);
    }
}

/**
  * ����  ����USART�����ʷ�����ʱ��ѡ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       CLK: ʱ��ѡ��ȡֵ��ΧΪ��
  *              USART_CLK_SCLK  :��ʱ��
  *              USART_CLK_HFCLK :��Ƶ����ʱ��
  *              USART_CLK_LFCLK :��Ƶ����ʱ��
  * ����  �ޡ�
  */
void
USART_BaudRate_Clock_Config(USART_SFRmap* USARTx, uint32_t CLK)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_USART_CLK(CLK));

    /*---------------- ����USART_CTLR�Ĵ���BRCKSλ ----------------*/
    USARTx->CTLR = SFR_Config (USARTx->CTLR, ~USART_CTLR_BRCKS, CLK);
}

/**
  * ����  ����USART��˫��ͬ��ʱ�Ӽ���ѡ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART��˫��ͬ��ʱ�Ӽ��ԣ�ȡֵΪ��
  *                   USART_CPOL_HIGH:������ʱ���½���ͬ����
  *                   USART_CPOL_LOW :������ʱ��������ͬ����
  * ����  �ޡ�
  */
void
USART_HalfDuplex_ClockPolarity_Config(USART_SFRmap* USARTx, uint32_t NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_USART_CPOL(NewState));

    /*---------------- ����USART_CTLR�Ĵ���SCKPSλ ----------------*/
    if (NewState != USART_CPOL_LOW)
    {
        /* ������ʱ���½���ͬ�� */
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_SCKPS_POS);
    }
    else
    {
        /* ������ʱ��������ͬ��*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_SCKPS_POS);
    }
}

/**
  * ����  ����USART���ʹ���ѡ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART���ʹ���ȡֵΪ��
  *                   USART_TRANSMIT_MSB:�ȷ���MSB��
  *                   USART_TRANSMIT_LSB:�ȷ���LSB��
  * ����  �ޡ�
  */
void
USART_Transmit_Order_Config (USART_SFRmap* USARTx, uint32_t NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_USART_TRANSMIT_DIR(NewState));

    /*---------------- ����USART_CTLR�Ĵ���TCONVλ ----------------*/
    if (NewState != USART_TRANSMIT_LSB)
    {
        /* �ȷ���MSB */
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_TCONV_POS);
    }
    else
    {
        /* �ȷ���LSB */
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_TCONV_POS);
    }
}

/**
  * ����  ����USART���մ���ѡ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART���մ���ȡֵΪ��
  *                   USART_RECEIVE_MSB:�Ƚ���MSB��
  *                   USART_RECEIVE_LSB:�Ƚ���LSB��
  * ����  �ޡ�
  */
void
USART_Receive_Order_Config (USART_SFRmap* USARTx, uint32_t NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_USART_RECEIVE_DIR(NewState));

    /*---------------- ����USART_CTLR�Ĵ���RCONVλ ----------------*/
    if (NewState != USART_RECEIVE_LSB)
    {
        /* �Ƚ���MSB */
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_RCONV_POS);
    }
    else
    {
        /* �Ƚ���LSB */
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_RCONV_POS);
    }
}

/**
  * ����  ���ú�����Ƹߵ�ƽ������ԡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: ������Ƹߵ�ƽ������ԣ�ȡֵΪ
  *                   TRUE: ���ͺͽ��շ����ƽ��
  *                   FALSE: ���ͺͽ��������ƽ��
  * ����  �ޡ�
  */
void
USART_Infrare_Detector_Voltage_Config(USART_SFRmap* USARTx,
                    FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_CTLR�Ĵ���DINVλ ----------------*/
    if (NewState != FALSE)
    {
        /* ���ͺͽ��շ����ƽ*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_DINV_POS);
    }
    else
    {
        /* ���ͺͽ��������ƽ*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_DINV_POS);
    }
}

/**
  * ����  ����USART����ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART����ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_WeakUP_Enable(USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_CTLR�Ĵ���WUENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART���� */
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_WUEN_POS);
    }
    else
    {
        /* ��ֹUSART���� */
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_WUEN_POS);
    }
}

/**
  * ����  ����USARTʱ��Դѡ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       ClockSource: USARTʱ��Դѡ��ȡֵΪTRUE �� FALSE��
  *                      USART_MASTER_CLOCKSOURCE_INTER: ��ģʽ(��BRG�ڲ�����ʱ��)��
  *                      USART_SLAVE_CLOCKSOURCE_EXTER: ��ģʽ(ʱ��Դ�����ⲿ)��
  * ����  �ޡ�
  */
void
USART_Clock_Source_Config(USART_SFRmap* USARTx, uint32_t ClockSource)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_USART_CLOCKSOURCE(ClockSource));

    /*---------------- ����USART_CTLR�Ĵ���CSRSλ ----------------*/
    if (ClockSource != USART_SLAVE_CLOCKSOURCE_EXTER)
    {
        /* ��ģʽ(��BRG�ڲ�����ʱ��*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_CSRS_POS);
    }
    else
    {
        /* ��ģʽ(ʱ��Դ�����ⲿ*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_CSRS_POS);
    }
}

/**
  * ����  ����USART��ַ���ʹ��λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART��ַ���ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Address_Detection_Enable(USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_CTLR�Ĵ���ADRENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ�ܵ�ַ��⣬����ַλΪ1ʱ����װ��BUF*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_ADREN_POS);
    }
    else
    {
        /* ��ֹ��ַ��⣬���������ֽڲ��ҵ�9λ����Ϊ��żУ��λ*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_ADREN_POS);
    }
}

/**
  * ����  ����USART�Զ������ʼ��ʹ��λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART�Զ������ʼ��ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Auto_BaudRate_Detection_Enable(USART_SFRmap* USARTx,
                    FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_CTLR�Ĵ���ABRDENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ���Զ�������ģʽ(����Զ������ʺ���0)*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_ABRDEN_POS);
    }
    else
    {
        /* ��ֹ�Զ�������ģʽ*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_ABRDEN_POS);
    }
}
/**
  * ����  ��ȡUSART�Զ������ʼ��ʹ��λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART�Զ������ʼ��ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  1: ʹ���Զ�������ģʽ(����Զ������ʺ�����)
  *       0: ��ֹ�Զ�������ģʽ
  */
FlagStatus USART_Get_Auto_BaudRate_Detection_Flag(USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ��ȡUSART_CTLR�Ĵ���ABRDENλ ----------------*/
    if (USARTx->CTLR & USART_CTLR_ABRDEN)
    {
        return SET;
    }
    else
    {
    	/* �Զ�����������Զ����� */
    	return RESET;
    }
}
/**
  * ����  ����USART���ͼ���ַ�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART���ͼ���ַ�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Send_Blank_Enable(USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_CTLR�Ĵ���SENDBλ ----------------*/
    if (NewState != FALSE)
    {
        /* ���ͼ���ַ�ʹ��(��ɺ��������0)*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_SENDB_POS);
    }
    else
    {
        /* δʹ�ܷ��ͼ���ַ�*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_SENDB_POS);
    }
}

/**
  * ����  ����USART����ͨ��ģʽѡ��λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewMode: USARTģʽѡ��ȡֵΪ��
  *                  USART_MODE_HALFDUPLEXSYN:��˫��ͬ��ģʽ��
  *                  USART_MODE_FULLDUPLEXASY:ȫ˫���첽ģʽ��
  * ����  �ޡ�
  */
void
USART_SYN_Choice_Config(USART_SFRmap* USARTx, uint32_t NewMode)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_USART_MODE(NewMode));

    /*---------------- ����USART_CTLR�Ĵ���SYNCλ ----------------*/
    if (NewMode != USART_MODE_FULLDUPLEXASY)
    {
        /* ��˫��ͬ��ģʽ*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_SYNC_POS);
    }
    else
    {
        /*ȫ˫���첽ģʽ*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_SYNC_POS);
    }
}

/**
  * ����  ����USART����ʹ��λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART����ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Transmit_Data_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_CTLR�Ĵ���TXENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ�ܷ���*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_TXEN_POS);
    }
    else
    {
        /* ��ֹ����*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_TXEN_POS);
    }
}

/**
  * ����  ����USART����ʹ��λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART����ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Receive_Data_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_CTLR�Ĵ���RXENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ�ܽ���*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_RXEN_POS);
    }
    else
    {
        /* ��ֹ����*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_RXEN_POS);
    }
}

/**
  * ����  ����USARTֹͣλ����ѡ��λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewLength: ȡֵΪUSART_STOPBITS_2 �� USART_STOPBITS_1��
  *                    USART_STOPBITS_2 :ֹͣλ����Ϊ2bits��
  *                    USART_STOPBITS_1 :ֹͣλ����Ϊ1bit��
  * ����  �ޡ�
  */
void
USART_STOP_Word_Config(USART_SFRmap* USARTx, uint32_t NewLength)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_USART_STOPBITS(NewLength));

    /*---------------- ����USART_CTLR�Ĵ���STPWλ ----------------*/
    if (NewLength != USART_STOPBITS_1)
    {
        /* ֹͣλ����Ϊ2bits*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_STPW_POS);
    }
    else
    {
        /* ֹͣλ����Ϊ1bit*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_STPW_POS);
    }
}

/**
  * ����  ����USART�������ݵ�9λ����ѡ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: ȡֵΪUSART_BIT9_RS485 �� USART_BIT9_PAR��
  *                   USART_BIT9_RS485 :RS-485ģʽ��
  *                   USART_BIT9_PAR   :ѡ����żУ�顣
  * ����  �ޡ�
  */
void
USART_Transmit_9Word_Select_Config (USART_SFRmap* USARTx, uint32_t NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_USART_Bit9_MODE(NewState));

    /*---------------- ����USART_CTLR�Ĵ���TX9SELλ ----------------*/
    if (NewState != USART_BIT9_PAR)
    {
        /* RS-485ģʽ*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_TX9SEL_POS);
    }
    else
    {
        /* ѡ����żУ��*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_TX9SEL_POS);
    }
}

/**
  * ����  ����USART��żУ��ѡ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: ȡֵΪUSART_PARITY_EVEN ��USART_PARITY_ODD��
  *                   USART_PARITY_EVEN :żУ�飬
  *                   USART_PARITY_ODD  :��У�顣
  * ����  �ޡ�
  */
void
USART_Parity_Select_Config(USART_SFRmap* USARTx, uint32_t NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_USART_PARITY(NewState));

    /*---------------- ����USART_CTLR�Ĵ���PARMλ ----------------*/
    if (NewState != USART_PARITY_ODD)
    {
        /* żУ��*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_PARM_POS);
    }
    else
    {
        /* ��У��*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_PARM_POS);
    }
}

/**
  * ����  ����USART��9λ����ʹ��λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART��9λ����ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_9Data_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_CTLR�Ĵ���DT9ENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ�ܵ�9λ���ݷ��ͺͽ���*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_DT9EN_POS);
    }
    else
    {
        /* δʹ�ܵ�9λ���ݷ��ͺͽ���*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_DT9EN_POS);
    }
}

/**
  * ����  ����USART CTSʹ��λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART CTSʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_CTS_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_CTLR�Ĵ���CTSENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��CTS����*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_CTSEN_POS);
    }
    else
    {
        /* ����CTS����*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_CTSEN_POS);
    }
}

/**
  * ����  ����USART RTSʹ��λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART RTSʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_RTS_Enable(USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_CTLR�Ĵ���RTSENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��RTS����*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_RTSEN_POS);
    }
    else
    {
        /* ����RTS����*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_RTSEN_POS);
    }
}

/**
  * ����  ����USART �������ʹ��λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART �������ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Infrare_Detector_Enable(USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_CTLR�Ĵ���IRDAENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��IrDA����*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_IRDAEN_POS);
    }
    else
    {
        /* ����IrDA����*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_IRDAEN_POS);
    }
}
/**
  * ����  ����USART RESHDλ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART ����ģʽʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_RESHD_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_CTLR�Ĵ���RESHDλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ�ܵ���ģʽ*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_RESHD_POS);
    }
    else
    {
        /* ��ֹ����ģʽ*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_RESHD_POS);
    }
}
/**
  * ����  ����USART ����ģʽʹ��λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART ����ģʽʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Singlet_Line_Mode_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_CTLR�Ĵ���SLMENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ�ܵ���ģʽ*/
        SFR_SET_BIT_ASM(USARTx->CTLR, USART_CTLR_SLMEN_POS);
    }
    else
    {
        /* ��ֹ����ģʽ*/
        SFR_CLR_BIT_ASM(USARTx->CTLR, USART_CTLR_SLMEN_POS);
    }
}

/**
  * ����  ����USART USARTDIV���������֡�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       DIV: ȡֵ��ΧΪ0~65535��
  * ����  �ޡ�
  */
void
USART_BaudRate_Integer_Config(USART_SFRmap* USARTx, uint16_t DIV)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_BRGR�Ĵ���BRGMλ ----------------*/
    tmpreg = DIV << USART_BRGR_BRGM0_POS;
    USARTx->BRGR = SFR_Config (USARTx->BRGR, ~USART_BRGR_BRGM, tmpreg);
}

/**
  * ����  ����USART С�������ʷ��ӡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       DIV: ȡֵ��ΧΪ0~15��
  * ����  �ޡ�
  */
void
USART_BaudRate_Decimal1_Config(USART_SFRmap* USARTx, uint32_t DIV)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_USART_BAUDRATE_DECIMAL(DIV));

    /*---------------- ����USART_BRGR�Ĵ���BRGF1λ ----------------*/
    tmpreg = DIV << USART_BRGR_BRGF1_0_POS ;
    USARTx->BRGR = SFR_Config (USARTx->BRGR, ~USART_BRGR_BRGF1, tmpreg);
}

/**
  * ����  ����USART С�������ʷ�ĸ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       DIV: ȡֵ��ΧΪ0~15��
  * ����  �ޡ�
  */
void
USART_BaudRate_Decimal2_Config(USART_SFRmap* USARTx, uint32_t DIV)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_USART_BAUDRATE_DECIMAL(DIV));

    /*---------------- ����USART_BRGR�Ĵ���BRGF2λ ----------------*/
    tmpreg = DIV << USART_BRGR_BRGF2_0_POS ;
    USARTx->BRGR = SFR_Config (USARTx->BRGR, ~USART_BRGR_BRGF2, tmpreg);
}

/**
  * ����  USART�������ݡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       Data: д�����ݼĴ�����ֵ��ȡֵΪ0~255��
  */
void
USART_SendData(USART_SFRmap* USARTx, uint8_t Data)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_TBUFR�Ĵ��� ----------------*/
    USARTx->TBUFR = Data;
}

/**
  * ����  USART�����ֽ�,���ȴ��������ͻ������ա�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       Data: д�����ݼĴ�����ֵ��ȡֵΪ0~255��
  */
void
USART_TransmitData(USART_SFRmap* USARTx, uint8_t Data)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    /*---------------- 	�ȴ�������Ϊ��	----------------*/
     while(!(USARTx->STR & USART_STR_TXEIF));
    /*---------------- ����USART_TBUFR�Ĵ��� ----------------*/
    USARTx->TBUFR = Data;
}

/**
  * ����  USART�������ݡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  32λ�������ݵ�8λ���ݡ�
  */
uint32_t
USART_ReceiveData(USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_RBUFR�Ĵ��� ----------------*/
    return USARTx->RBUFR;
}

/**
  * ����  ���� USARTx��ַƥ�书������λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       address: USARTx��ַƥ�书�ܣ�ȡֵ��ΧΪ0~255��
  * ����  �ޡ�
  */
void
USART_Address_Match_Config(USART_SFRmap* USARTx, uint8_t DIV)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_ADM�Ĵ���ADMλ ----------------*/
    tmpreg = DIV << USART_ADM_ADM0_POS;
    USARTx->ADM = SFR_Config (USARTx->ADM, ~USART_ADM_ADM, tmpreg);
}

/**
  * ����  ����USARTȫ˫��ģʽʱ���Ϳ���֡ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *      NewState:  TRUE: ʹ�ܷ��������Ϳ���֡
  *      			FALSE: ��ֹ���������Ϳ���֡��
  * ����  �ޡ�
  */
void
USART_Send_Idle_Frame_Enable(USART_SFRmap* USARTx, FunctionalState NewState)
{
	uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    tmpreg = NewState << USART_CTLR_TIDLEEN_POS;
    USARTx->CTLR = SFR_Config(USARTx->CTLR, ~USART_CTLR_TIDLEEN, tmpreg);
}

/**
  * ����  ����USART���տ���֡�жϱ�־����ģʽ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *      NewState:  TRUE: ����֡�жϱ�־�� RDRIF �޹�
  *      			FALSE: ����֡�жϱ�־�� RDRIF �йء�
  * ����  �ޡ�
  */
void
USART_Receive_Idle_Frame_Config(USART_SFRmap* USARTx, FunctionalState NewState)
{
	uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    tmpreg = NewState << USART_CTLR_RIDLES_POS;
    USARTx->CTLR = SFR_Config(USARTx->CTLR, ~USART_CTLR_RIDLES, tmpreg);
}

/**
  *   ##### USARTģ��(USART)�������ú������� #####
  */


/**
  *   ##### USARTģ��(USART)7816��ʼ�������ú��� #####
  */
/**
  * ����  ����USART 7816ģʽʹ�ܿ��ơ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART 7816ģʽʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_7816_Cmd(USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_U7816R�Ĵ���7816ENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��7816ģʽ*/
        SFR_SET_BIT_ASM(USARTx->U7816R, USART_U7816R_7816EN_POS);
    }
    else
    {
        /* ����7816ģʽ*/
        SFR_CLR_BIT_ASM(USARTx->U7816R, USART_U7816R_7816EN_POS);
    }
}

/**
  * ����  ����USART 7816ʱ�����ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART 7816ʱ�����ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_7816_CLKOUT_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_U7816R�Ĵ���CLKOUTλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��ʱ�����*/
        SFR_SET_BIT_ASM(USARTx->U7816R, USART_U7816R_CLKOUT_POS);
    }
    else
    {
        /* ��ֹʱ�����*/
        SFR_CLR_BIT_ASM(USARTx->U7816R, USART_U7816R_CLKOUT_POS);
    }
}

/**
  * ����  ����USART 7816 error signal���ѡ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       signal: ���ѡ��ȡֵ��ΧΪ��
  *                 USART_U7816R_ERRORSIGNAL_2ETU   : 2etu
  *                 USART_U7816R_ERRORSIGNAL_1P5ETU : 1.5etu
  *                 USART_U7816R_ERRORSIGNAL_1ETU   : 1etu
  * ����  �ޡ�
  */
void
USART_7816_Error_Signal_Config (USART_SFRmap* USARTx, uint32_t ERRORSIGNAL)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_U7816R_ERRORSIGNAL(ERRORSIGNAL));

    /*---------------- ����USART_U7816R�Ĵ���ERSWλ ----------------*/
    USARTx->U7816R = SFR_Config (USARTx->U7816R, ~USART_U7816R_ERSW, ERRORSIGNAL);
}

/**
  * ����  ����USART ����ͨ��ѡ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: ȡֵΪUSART_U7816R_PASSAGEWAY_TX1  �� USART_U7816R_PASSAGEWAY_TX0��
  *                   USART_U7816R_PASSAGEWAY_TX1 :ѡ��ͨ��1(TX1)��
  *                   USART_U7816R_PASSAGEWAY_TX0 :ѡ��ͨ��0(TX0)
  * ����  �ޡ�
  */
void
USART_Passageway_Select_Config(USART_SFRmap* USARTx, uint32_t NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_U7816R_PASSAGEWAY_SELECT(NewState));

    /*---------------- ����USART_U7816R�Ĵ���PSELλ ----------------*/
    if (NewState != USART_U7816R_PASSAGEWAY_TX0)
    {
        /* ѡ��ͨ��1(TX1)*/
        SFR_SET_BIT_ASM(USARTx->U7816R, USART_U7816R_PSEL_POS);
    }
    else
        {
        /* ѡ��ͨ��0(TX0)*/
        SFR_CLR_BIT_ASM(USARTx->U7816R, USART_U7816R_PSEL_POS);
    }
}

/**
  * ����  ����USART ���ƽ��յ�����֮���Ƿ����BGT��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: ȡֵΪTRUE �� FALSE��
  *                   TRUE:����BGT�����Ϊ22etu��
  *                   FALSE:������BGT
  * ����  �ޡ�
  */
void
USART_BGT_Config(USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_U7816R�Ĵ���BGTλ ----------------*/
    if (NewState != FALSE)
    {
        /* ����BGT�����Ϊ22etu*/
        SFR_SET_BIT_ASM(USARTx->U7816R, USART_U7816R_BGTEN_POS);
    }
    else
    {
        /* ������BGT*/
        SFR_CLR_BIT_ASM(USARTx->U7816R, USART_U7816R_BGTEN_POS);
    }
}
/**
  * ����  ����USART �ط�ʹ�ܿ��ơ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: ȡֵΪTRUE �� FALSE��
  *                   TRUE:�յ�У������źź��ط����ﵽ������������жϣ�
  *                   FALSE:�յ�У������źź�ֱ�ӽ����ж�
  * ����  �ޡ�
  */
void
USART_Transmit_Repeat_Enable(USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_U7816R�Ĵ���TREPENλ ----------------*/
    if (NewState != FALSE)
    {
        /* �յ�У������źź��ط����ﵽ������������ж�*/
        SFR_SET_BIT_ASM(USARTx->U7816R, USART_U7816R_TREPEN_POS);
    }
    else
    {
        /* �յ�У������źź�ֱ�ӽ����ж�*/
        SFR_CLR_BIT_ASM(USARTx->U7816R, USART_U7816R_TREPEN_POS);
    }
}

/**
  * ����  ����USART ����ʹ�ܿ��ơ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: ȡֵΪTRUE �� FALSE��
  *               TRUE:��żУ�������������ݣ��ﵽ������������жϣ�
  *               FALSE:��żУ������ֱ�ӽ����ж�
  * ����  �ޡ�
  */
void
USART_Receive_Repeat_Enable(USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_U7816R�Ĵ���RREPENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ��żУ�������������ݣ��ﵽ������������ж�*/
        SFR_SET_BIT_ASM(USARTx->U7816R, USART_U7816R_RREPEN_POS);
    }
    else
    {
        /* ��żУ������ֱ�ӽ����ж�*/
        SFR_CLR_BIT_ASM(USARTx->U7816R, USART_U7816R_RREPEN_POS);
    }
}

/**
  * ����  ����USART ��żУ�����ʱ�ط��͵���������
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       SELECT: ������ѡ��ȡֵ��ΧΪ��
  *                 USART_U7816R_TRANSMIT_REPEAT_0S: ������մ���Ϊ0
  *                 USART_U7816R_TRANSMIT_REPEAT_1S: ������մ���Ϊ1
  *                 USART_U7816R_TRANSMIT_REPEAT_2S: ������մ���Ϊ2
  *                 USART_U7816R_TRANSMIT_REPEAT_3S: ������մ���Ϊ3
  * ����  �ޡ�
  */
void
USART_Transmit_Repeat_Times_Config(USART_SFRmap* USARTx, uint32_t SELECT)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_U7816R_TRANSMIT_REPEAT(SELECT));

    /*---------------- ����USART_U7816R�Ĵ���TXREλ ----------------*/
    USARTx->U7816R = SFR_Config (USARTx->U7816R, ~USART_U7816R_TXRE, SELECT);
}

/**
  * ����  ����USART ��żУ�����ʱ�ؽ��յ���������
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       SELECT: ������ѡ��ȡֵ��ΧΪ��
  *                 USART_U7816R_RECEIVE_REPEAT_0S: ������մ���Ϊ0
  *                 USART_U7816R_RECEIVE_REPEAT_1S: ������մ���Ϊ1
  *                 USART_U7816R_RECEIVE_REPEAT_2S: ������մ���Ϊ2
  *                 USART_U7816R_RECEIVE_REPEAT_3S: ������մ���Ϊ3
  * ����  �ޡ�
  */
void
USART_Receive_Repeat_Times_Config(USART_SFRmap* USARTx, uint32_t SELECT)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_U7816R_RECEIVE_REPEAT(SELECT));

    /*---------------- ����USART_U7816R�Ĵ���RXREλ ----------------*/
    USARTx->U7816R = SFR_Config (USARTx->U7816R, ~USART_U7816R_RXRE, SELECT);
}

/**
  * ����  ����USART 7816����ʱ�Ӻ��������ʱ�ӿ��ơ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       CLKDIV: ȡֵ��ΧΪ0~255��
  * ����  �ޡ�
  */
void
USART_7816_CLKDIV_Config (USART_SFRmap* USARTx, uint8_t DIV)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_U7816R�Ĵ���λCLKDIV ----------------*/
    tmpreg = DIV << USART_U7816R_CLKDIV0_POS;
    USARTx->U7816R = SFR_Config (USARTx->U7816R, ~USART_U7816R_CLKDIV, tmpreg);
}

/**
  * ����  ����USART 7816����ʱ�����EGT(extra guard time)����λetu����
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       EGT: ȡֵ��ΧΪ0~255��
  * ����  �ޡ�
  */
void
USART_7816_EGT_Config(USART_SFRmap* USARTx, uint8_t EGT)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_U7816R�Ĵ���λEGT ----------------*/
    tmpreg = EGT << USART_U7816R_EGT0_POS;
    USARTx->U7816R = SFR_Config (USARTx->U7816R, ~USART_U7816R_EGT, tmpreg);
}

/**
  * ����  ����USART 7816�ط�ģʽѡ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: FALSE:ֻҪ���յ�����֡�������ط�
  *       			TRUE: �ط����������ô�����ֹͣ�ط�
  * ����  �ޡ�
  */
void
USART_7816_Resend_Mode_Select(USART_SFRmap* USARTx, FunctionalState NewState)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_U7816R�Ĵ���λTREPMS ----------------*/
    tmpreg = NewState << USART_U7816R_TREPMS_POS;
    USARTx->U7816R = SFR_Config (USARTx->U7816R, ~USART_U7816R_TREPMS, tmpreg);
}

/**
  *   ##### USARTģ��(USART)7816��ʼ�������ú���������� #####
  */


/**
  *   ##### USARTģ��(USART)�жϹ����� #####
  */
/**
  * ����  ����USART��������ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART��������ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Receive_Overflow_INT_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���OVFEIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART��������ж� */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_OVFEIE_POS);
    }
    else
    {
        /* ��ֹUSART��������ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_OVFEIE_POS);
    }
}

/**
  * ����  ����USART��żУ������ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART��żУ������ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Parity_ERROR_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���PAREIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART��żУ������ж�λ */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_PAREIE_POS);
    }
    else
    {
        /* ��ֹUSART��żУ������ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_PAREIE_POS);
    }
}

/**
  * ����  ����USART֡�����ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART֡�����ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Frame_ERROE_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���FREIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART֡�����ж�λ */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_FREIE_POS);
    }
    else
    {
        /* ��ֹUSART֡�����ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_FREIE_POS);
    }
}

/**
  * ����  ����USART�����λ�ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART�����λ�ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Blank_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���BRIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART�����λ�ж�λ */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_BRIE_POS);
    }
    else
    {
        /* ��ֹUSART�����λ�ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_BRIE_POS);
    }
}

/**
  * ����  ����USART�Զ������ʳ�ʱ�ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART�Զ������ʳ�ʱ�ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Auto_BaudRate_TimeOver_INT_Enable (USART_SFRmap* USARTx,
                    FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���BRIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART�Զ������ʳ�ʱ�ж�λ */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_ABTOIE_POS);
    }
    else
    {
        /* ��ֹUSART�Զ������ʳ�ʱ�ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_ABTOIE_POS);
    }
}

/**
  * ����  ����USART�Զ������ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART�Զ������ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_WeakUP_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���WUIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART�Զ������ж�λ */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_WUIE_POS);
    }
    else
    {
        /* ��ֹUSART�Զ������ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_WUIE_POS);
    }
}

/**
  * ����  ����USART7816���ʹ����ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART7816���ʹ����ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Transmit_ERROR_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���TEIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART7816���ʹ����ж�λ */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_TEIE_POS);
    }
    else
    {
        /* ��ֹUSART7816���ʹ����ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_TEIE_POS);
    }
}

/**
  * ����  ����USART7816���մ����ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART7816���մ����ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Receive_ERROR_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���REIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART7816���մ����ж�λ */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_REIE_POS);
    }
    else
    {
        /* ��ֹUSART7816���մ����ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_REIE_POS);
    }
}

/**
  * ����  ����USART CTS�ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART CTS�ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_CTS_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���CTSIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART CTS�ж�λ */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_CTSIE_POS);
    }
    else
    {
        /* ��ֹUSART CTS�ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_CTSIE_POS);
    }
}

/**
  * ����  ����USART RDR�ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART RDR�ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_RDR_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���RDRIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART RDR�ж�λ */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_RDRIE_POS);
    }
    else
    {
        /* ��ֹUSART RDR�ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_RDRIE_POS);
    }
}

/**
  * ����  ����USART TFE�ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART TFE�ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_TFE_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���TFEIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART TFE�ж�λ */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_TFEIE_POS);
    }
    else
    {
        /* ��ֹUSART TFE�ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_TFEIE_POS);
    }
}

/**
  * ����  ����USART TXE�ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART TXE�ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_TXE_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���TXEIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART TXE�ж�λ */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_TXEIE_POS);
    }
    else
    {
        /* ��ֹUSART TXE�ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_TXEIE_POS);
    }
}

/**
  * ����  ����USART ��������DMA�ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART ��������DMA�ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Receive_DMA_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���URCDEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART ��������DMA�ж�λ */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_URCDE_POS);
    }
    else
    {
        /* ��ֹUSART ��������DMA�ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_URCDE_POS);
    }
}

/**
  * ����  ����USART ��������DMA�ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART ��������DMA�ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_Transmit_DMA_INT_Enable (USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���UTXDEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART ��������DMA�ж�λ */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_UTXDE_POS);
    }
    else
    {
        /* ��ֹUSART ��������DMA�ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_UTXDE_POS);
    }
}

/**
  * ����  ����USART IDLEIF �ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART �ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_IDLE_INT_Enable(USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���IDLEIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART IDLEIE�ж�λ */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_IDLEIE_POS);
    }
    else
    {
        /* ��ֹUSART IDLEIE�ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_IDLEIE_POS);
    }
}

/**
  * ����  ����USART UADMIF �ж�ʹ�ܡ�
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  *       NewState: USART �ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
USART_UADM_INT_Enable(USART_SFRmap* USARTx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����USART_IER�Ĵ���UADMIEλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��USART UADMIE�ж�λ */
        SFR_SET_BIT_ASM(USARTx->IER, USART_IER_UADMIE_POS);
    }
    else
    {
        /* ��ֹUSART UADMIE�ж� */
        SFR_CLR_BIT_ASM(USARTx->IER, USART_IER_UADMIE_POS);
    }
}

/**
  * ����  ��ȡUSART��������жϱ�־״̬ ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  1: USART���������
  *       0: USARTû�н��������
  */
FlagStatus
USART_Get_Receive_Overflow_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ��ȡUSART_STR�Ĵ���OVFEIFλ ----------------*/
    if (USARTx->STR & USART_STR_OVFEIF)
    {
        /* USART������� */
        return SET;
    }
    else
    {
        /* USARTû�н������ */
        return RESET;
    }
}

/**
  * ����  ��ȡUSART��żУ������жϱ�־״̬ ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  1: USART��żУ�����
  *       0: USARTû�н��������
  */
FlagStatus
USART_Get_Parity_ERROR_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ��ȡUSART_STR�Ĵ���PAREIFλ ----------------*/
    if (USARTx->STR & USART_STR_PAREIF)
    {
        /* USART��żУ����� */
        return SET;
    }
    else
    {
        /* USART��żУ��δ�������� */
        return RESET;
    }
}

/**
  * ����  ��ȡUSART֡�����жϱ�־״̬ ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  1: USART��������ʱ����֡����
  *       0: USART��������ʱδ����֡����
  */
FlagStatus
USART_Get_Frame_ERROR_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ��ȡUSART_STR�Ĵ���FREIFλ ----------------*/
    if (USARTx->STR & USART_STR_FREIF)
    {
        /* USART��������ʱ������֡���� */
        return SET;
    }
    else
    {
        /* USART��������ʱδ����֡���� */
        return RESET;
    }
}

/**
  * ����  ��ȡUSART������жϱ�־״̬ ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  1: USART���յ�����ַ���
  *       0: USARTδ���ܵ�����ַ���
  */
FlagStatus
USART_Get_Blank_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ��ȡUSART_STR�Ĵ���BRIFλ ----------------*/
    if (USARTx->STR & USART_STR_BRIF)
    {
        /* USART���յ�����ַ� */
        return SET;
    }
    else
    {
        /* USARTδ���ܵ�����ַ� */
        return RESET;
    }
}

/**
  * ����  ��ȡUSART�Զ������ʳ�ʱ�жϱ�־״̬ ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  1: USART�Զ������ʳ�ʱ��
  *       0: USART�Զ�������δ��ʱ��
  */
FlagStatus
USART_Get_Auto_Baudrate_TimeOver_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ��ȡUSART_STR�Ĵ���ABTOIFλ ----------------*/
    if (USARTx->STR & USART_STR_ABTOIF)
    {
        /* USART�Զ������ʳ�ʱ */
        return SET;
    }
    else
    {
        /* USART�Զ�������δ��ʱ */
        return RESET;
    }
}

/**
  * ����  ��ȡUSART�Զ������жϱ�־״̬ ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  1: USART�������Զ������¼���
  *       0: USARTδ�����Զ������¼���
  */
FlagStatus
USART_Get_WeakUP_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ��ȡUSART_STR�Ĵ���WUIFλ ----------------*/
    if (USARTx->STR & USART_STR_WUIF)
    {
        /* USART�������Զ������¼�*/
        return SET;
    }
    else
    {
        /* USARTδ�����Զ������¼� */
        return RESET;
    }
}

/**
  * ����  ��ȡUSART 7816���ʹ����жϱ�־״̬ ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  1: USART������7816���ʹ����жϣ�
  *       0: USARTδ����7816���ʹ����жϡ�
  */
FlagStatus
USART_Get_7816Transmit_ERROR_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ��ȡUSART_STR�Ĵ���TEIFλ ----------------*/
    if (USARTx->STR & USART_STR_TEIF)
    {
        /* USART ������7816���ʹ����ж�*/
        return SET;
    }
    else
    {
        /* USART δ����7816���ʹ����ж� */
        return RESET;
    }
}

/**
  * ����  ��ȡUSART 7816���մ����жϱ�־״̬ ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  1: USART������7816���մ����жϣ�
  *       0: USARTδ����7816���մ����жϡ�
  */
FlagStatus
USART_Get_7816Receive_ERROR_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ��ȡUSART_STR�Ĵ���REIF λ ----------------*/
    if (USARTx->STR & USART_STR_REIF)
    {
        /* USART ������7816���մ����ж�*/
        return SET;
    }
    else
    {
        /* USART δ����7816���մ����ж� */
        return RESET;
    }
}

/**
  * ����  ��ȡUSART CTS�жϱ�־״̬ ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  1: USART���յ���ЧCTS�źţ�
  *       0: USARTδ���յ���ЧCTS�źš�
  */
FlagStatus
USART_Get_CTS_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ��ȡUSART_STR�Ĵ���CTSIFλ ----------------*/
    if (USARTx->STR & USART_STR_CTSIF)
    {
        /* USART ���յ���ЧCTS�ź�*/
        return SET;
    }
    else
    {
        /* USART δ���յ���ЧCTS�ź� */
        return RESET;
    }
}

/**
  * ����  ��ȡUSART ���ݾ����жϱ�־״̬ ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  1: USART����BUF�������ݿɶ���
  *       0: USART����BUF�������ݿɶ���
  */
FlagStatus
USART_Get_Receive_BUFR_Ready_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ��ȡUSART_STR�Ĵ���RDRIFλ ----------------*/
    if (USARTx->STR & USART_STR_RDRIF)
    {
        /* USART ����BUF�������ݿɶ�*/
        return SET;
    }
    else
    {
        /* USART ����BUF�������ݿɶ� */
        return RESET;
    }
}

/**
  * ����  ��ȡUSART ����ʹ��λ״̬ ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����      1: USART���ڵȴ��½��أ�
  *       0: USART����������������
  */
FlagStatus
USART_Get_WUEN_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ��ȡUSART_CTLR�Ĵ���WUENλ ----------------*/
    if (USARTx->CTLR & USART_CTLR_WUEN)
    {
        /* �ȴ��½���*/
        return SET;
    }
    else
    {
    	/*��������*/
        return RESET;
    }
}
/**
  * ����  ��ȡUSART ����BUFΪ���жϱ�־״̬ ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  1: USART����BUFΪ�գ�
  *       0: USART����BUF��Ϊ�ա�
  */
FlagStatus
USART_Get_Transmit_BUFR_Empty_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ��ȡUSART_STR�Ĵ���TFEIFλ ----------------*/
    if (USARTx->STR & USART_STR_TFEIF)
    {
        /* USART ����BUFΪ��*/
        return SET;
    }
    else
    {
        /* USART ����BUF��Ϊ�� */
        return RESET;
    }
}

/**
  * ����  ��ȡUSART ������Ϊ���жϱ�־״̬ ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  1: USART������Ϊ�գ�
  *       0: USART��������Ϊ�ա�
  */
FlagStatus
USART_Get_Transmitter_Empty_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ��ȡUSART_STR�Ĵ���TXEIFλ ----------------*/
    if (USARTx->STR & USART_STR_TXEIF)
    {
        /* USART ������Ϊ��*/
        return SET;
    }
    else
    {
        /* USART ��������Ϊ�� */
        return RESET;
    }
}

/**
  * ����  ��ȡUSART���տ���֡�жϱ�־ ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����    1: ���������յ�����֡
  *       0: ������û�н��յ�����֡��
  */
FlagStatus
USART_Get_Receive_Frame_Idel_Flag(USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ��ȡUSART_STR�Ĵ���TXEIFλ ----------------*/
    if (USARTx->STR & USART_STR_IDLFIF)
    {
        /* USART ������Ϊ��*/
        return SET;
    }
    else
    {
        /* USART ��������Ϊ�� */
        return RESET;
    }
}

/**
  * ����  ����USART��������жϱ�־��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  �ޡ�
  */
void
USART_Clear_Receive_Overflow_INT_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_STR�Ĵ���OVFEICλ ----------------*/
    SFR_SET_BIT_ASM(USARTx->STR, USART_STR_OVFEIC_POS);
    while(USARTx->STR & USART_STR_OVFEIF);
    SFR_CLR_BIT_ASM(USARTx->STR, USART_STR_OVFEIC_POS);
}

/**
  * ����  ����USART��żУ�����λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  �ޡ�
  */
void
USART_Clear_Parity_ERROR_INT_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_STR�Ĵ���PAREICλ ----------------*/
    SFR_SET_BIT_ASM(USARTx->STR, USART_STR_PAREIC_POS);
    while(USARTx->STR & USART_STR_PAREIF);
    SFR_CLR_BIT_ASM(USARTx->STR, USART_STR_PAREIC_POS);
}

/**
  * ����  ����USART֡����λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  �ޡ�
  */
void
USART_Clear_Frame_ERROR_INT_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_STR�Ĵ���FREICλ ----------------*/
    SFR_SET_BIT_ASM(USARTx->STR, USART_STR_FREIC_POS);
    while(USARTx->STR & USART_STR_FREIF);
    SFR_CLR_BIT_ASM(USARTx->STR, USART_STR_FREIC_POS);
}

/**
  * ����  ����USART�����λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  �ޡ�
  */
void
USART_Clear_Blank_INT_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_STR�Ĵ���BRICλ ----------------*/
    SFR_SET_BIT_ASM(USARTx->STR, USART_STR_BRIC_POS);
    while(USARTx->STR & USART_STR_BRIF);
    SFR_CLR_BIT_ASM(USARTx->STR, USART_STR_BRIC_POS);
}

/**
  * ����  ����USART�Զ������ʳ�ʱλ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  �ޡ�
  */
void
USART_Clear_Auto_BaudRate_TimeOver_INT_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_STR�Ĵ���ABTOICλ ----------------*/
    SFR_SET_BIT_ASM(USARTx->STR, USART_STR_ABTOIC_POS);
    while(USARTx->STR & USART_STR_ABTOIF);
    SFR_CLR_BIT_ASM(USARTx->STR, USART_STR_ABTOIC_POS);
}

/**
  * ����  ����USART�Զ������ж�λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  �ޡ�
  */
void
USART_Clear_WeakUP_INT_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_STR�Ĵ���WUICλ ----------------*/
    SFR_SET_BIT_ASM(USARTx->STR, USART_STR_WUIC_POS);
    while(USARTx->STR & USART_STR_WUIF);
    SFR_CLR_BIT_ASM(USARTx->STR, USART_STR_WUIC_POS);
}

/**
  * ����  ����USART���ʹ����ж�λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  �ޡ�
  */
void
USART_Clear_Transmit_ERROR_INT_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_STR�Ĵ���TEICλ ----------------*/
    SFR_SET_BIT_ASM(USARTx->STR, USART_STR_TEIC_POS);
    while(USARTx->STR & USART_STR_TEIF);
    SFR_CLR_BIT_ASM(USARTx->STR, USART_STR_TEIC_POS);
}

/**
  * ����  ����USART���մ����ж�λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  �ޡ�
  */
void
USART_Clear_Receive_ERROR_INT_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_STR�Ĵ���REICλ ----------------*/
    SFR_SET_BIT_ASM(USARTx->STR, USART_STR_REIC_POS);
    while(USARTx->STR & USART_STR_REIF);
    SFR_CLR_BIT_ASM(USARTx->STR, USART_STR_REIC_POS);
}

/**
  * ����  ����USART CTS�ж�λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  �ޡ�
  */
void
USART_Clear_CTS_INT_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_STR�Ĵ���REICλ ----------------*/
    SFR_SET_BIT_ASM(USARTx->STR, USART_STR_CTSIC_POS);
    while(USARTx->STR & USART_STR_CTSIF);
    SFR_CLR_BIT_ASM(USARTx->STR, USART_STR_CTSIC_POS);
}

/**
  * ����  ����USART UADM�ж�λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  �ޡ�
  */
void
USART_Clear_UADM_INT_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_STR�Ĵ���UADMλ ----------------*/
    SFR_SET_BIT_ASM(USARTx->STR, USART_STR_UADMIC_POS);
    while(USARTx->STR & USART_STR_UADMIF);
    SFR_CLR_BIT_ASM(USARTx->STR, USART_STR_UADMIC_POS);
}

/**
  * ����  ����USART IDLE�ж�λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  �ޡ�
  */
void
USART_Clear_IDLE_INT_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_STR�Ĵ���IDLEλ ----------------*/
    SFR_SET_BIT_ASM(USARTx->STR, USART_STR_IDLEIC_POS);
    while(USARTx->STR & USART_STR_IDLFIF);
    SFR_CLR_BIT_ASM(USARTx->STR, USART_STR_IDLEIC_POS);
}

/**
  * ����  ����USART ����BUF�ж�λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  �ޡ�
  */
void
USART_Clear_Receive_BUFR_INT_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_STR�Ĵ���RCFRλ ----------------*/
    SFR_SET_BIT_ASM(USARTx->STR, USART_STR_RCFR_POS);
    while(USARTx->STR & USART_STR_RDRIF);
    SFR_CLR_BIT_ASM(USARTx->STR, USART_STR_RCFR_POS);
}

/**
  * ����  ����USART ����BUF�ж�λ��
  * ����  USARTx: ָ��USART�ڴ�ṹ��ָ�룬ȡֵΪUSART0_SFR~USART8_SFR��
  * ����  �ޡ�
  */
void
USART_Clear_Transmit_BUFR_INT_Flag (USART_SFRmap* USARTx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_USART_ALL_PERIPH(USARTx));

    /*---------------- ����USART_STR�Ĵ���TXFRλ ----------------*/
    SFR_SET_BIT_ASM(USARTx->STR, USART_STR_TXFR_POS);
    while(!((USARTx->STR & USART_STR_TFEIF)>>USART_STR_TFEIF_POS));
    SFR_CLR_BIT_ASM(USARTx->STR, USART_STR_TXFR_POS);
}
/**
  *   ##### USARTģ��(USART)�жϹ������������ #####
  */

