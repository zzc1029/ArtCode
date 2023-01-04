/**
  ******************************************************************************
  * �ļ���  kf32a_basic_can.c
  * ��  ��  ChipON_AE/FAE_Group
  * ��  ��  V2.62
  * ��  ��  2019-11-16
  * ��  ��  ���ļ��ṩ�˿���������������(CAN)��صĹ��ܺ�����������
  *          + ����������������(CAN)��ʼ������
  *          + ����������������(CAN)�������ú���
  *          + ����������������(CAN)���ͽ��պ���
  *          + ����������������(CAN)�жϹ�����
  *
  *********************************************************************
  */

#include "kf32a_basic_can.h"
#include "kf32a_basic_rst.h"
#include "kf32a_basic_pclk.h"

#ifdef KF32A_Periph_can
/* ��ʱ��˽�ж��� ----------------------------------------------------*/
/* CANx_CTLR�Ĵ�����ʼ������ */
#define CAN_CTLR_INIT_MASK              (CAN_CTLR_CANEN \
                                       | CAN_CTLR_CANCKS \
                                       | CAN_CTLR_LBACK \
                                       | CAN_CTLR_SILENT \
                                       | CAN_CTLR_RSMOD)

/* CANx_BRGR�Ĵ�����ʼ������ */
#define CAN_BRGR_INIT_MASK              (CAN_BRGR_CANBRP \
                                       | CAN_BRGR_SJW \
                                       | CAN_BRGR_TSEG1 \
                                       | CAN_BRGR_TSEG2 \
                                       | CAN_BRGR_SAM)

/* CANx_INFR�Ĵ�����ʼ������ */
#define CAN_INFR_INIT_MASK              (CAN_INFR_IDE \
                                       | CAN_INFR_RTR \
                                       | CAN_INFR_DLC)

/* CANx_TX0R�Ĵ���SFF��ʽ��ʼ������ */
#define CAN_TX0R_SFF_MASK               (CAN_TX0R_SFF_ID \
                                       | 0xFFFF)

/* CANx_TX0R�Ĵ���EFF��ʽ��ʼ������ */
#define CAN_TX0R_EFF_MASK               (CAN_TX0R_EFF_ID)

/* CANx_TX2R�Ĵ���SFF��ʽ��ʼ������ */
#define CAN_TX2R_SFF_MASK               (0xFFFF0000)

/* CAN���յ�ַ */
#define CAN0_RECEIVE_ADDR               ((uint32_t)0x1FFEF800)
#define CAN1_RECEIVE_ADDR               ((uint32_t)0x1FFEF900)
#define CAN2_RECEIVE_ADDR               ((uint32_t)0x1FFEFA00)
#define CAN3_RECEIVE_ADDR               ((uint32_t)0x1FFEFB00)
#define CAN4_RECEIVE_ADDR               ((uint32_t)0x1FFEFC00)
#define CAN5_RECEIVE_ADDR               ((uint32_t)0x1FFEFD00)

/**
  *   ##### ����������������(CAN)��ʼ������ #####
  */
/**
  * ����  ��λCAN���裬ʹ������ʱ�ӡ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  * ����  �ޡ�
  */
void
CAN_Reset(CAN_SFRmap* CANx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
#ifdef KF32A_Periph_can0
    if (CANx == CAN0_SFR)
    {
    	PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_CAN0CLKEN, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_CAN0RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_CAN0RST, FALSE);
    }
#endif
#ifdef KF32A_Periph_can1
    if(CANx == CAN1_SFR)
    {
    	PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_CAN1CLKEN, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_CAN1RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_CAN1RST, FALSE);
    }
#endif
#ifdef KF32A_Periph_can2
    if(CANx == CAN2_SFR)
    {
    	PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_CAN2CLKEN, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_CAN2RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_CAN2RST, FALSE);
    }
#endif
#ifdef KF32A_Periph_can3
    if(CANx == CAN3_SFR)
    {
    	PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_CAN3CLKEN, TRUE);  
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_CAN3RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_CAN3RST, FALSE);
    }
#endif
#ifdef KF32A_Periph_can4
    if(CANx == CAN4_SFR)
    {
    	PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_CAN4CLKEN, TRUE);
        RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CAN4RST, TRUE);
        RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CAN4RST, FALSE);
    }
#endif
#ifdef KF32A_Periph_can5
    if(CANx == CAN5_SFR)
    {
    	PCLK_CTL3_Peripheral_Clock_Enable(PCLK_CTL3_CAN5CLKEN, TRUE);
        RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CAN5RST, TRUE);
        RST_CTL3_Peripheral_Reset_Enable(RST_CTL3_CAN5RST, FALSE);
    }
#endif
}

/**
  * ����  ����������������(CAN)��ʼ�����ú���������������һ��λģʽRSMOD��
  *       ���ں�������ʱ����RSMOD��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       canInitStruct: CAN������Ϣ�ṹ�塣
  * ����  �ޡ�
  */
void
CAN_Configuration(CAN_SFRmap* CANx, CAN_InitTypeDef* canInitStruct)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(canInitStruct->m_Enable));
    CHECK_RESTRICTION(CHECK_CAN_WORK_MODE(canInitStruct->m_Mode));
    CHECK_RESTRICTION(CHECK_CAN_SOURCE(canInitStruct->m_WorkSource));
    CHECK_RESTRICTION(CHECK_CAN_BAUDRATE_PRESET(canInitStruct->m_BaudRate));
    CHECK_RESTRICTION(CHECK_CAN_SYNC_JMP_WIDTH(canInitStruct->m_SyncJumpWidth));
    CHECK_RESTRICTION(CHECK_CAN_TIME_SEGMENT1(canInitStruct->m_TimeSeg1));
    CHECK_RESTRICTION(CHECK_CAN_TIME_SEGMENT2(canInitStruct->m_TimeSeg2));
    CHECK_RESTRICTION(CHECK_CAN_BUS_SAMPLE(canInitStruct->m_BusSample));

    /*---------------- ����CANx_CTLR�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_Enable������CANENλ�� */
    /* ���ݽṹ���Աm_Mode������LBACK��SILENTλ�� */
    /* ���ݽṹ���Աm_WorkSource������CANCKSλ�� */
    /* ����RSMOD�����븴λģʽ */
    tmpreg = ((uint32_t)canInitStruct->m_Enable << CAN_CTLR_CANEN_POS) \
           | canInitStruct->m_Mode \
           | canInitStruct->m_WorkSource \
           | CAN_CTLR_RSMOD;
    CANx->CTLR = SFR_Config (CANx->CTLR, ~CAN_CTLR_INIT_MASK, tmpreg);

    /*---------------- ����CANx_BRGR�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_BaudRate������CANBRPλ�� */
    /* ���ݽṹ���Աm_SyncJumpWidth������SJWλ�� */
    /* ���ݽṹ���Աm_TimeSeg1������TSEG1λ�� */
    /* ���ݽṹ���Աm_TimeSeg2������TSEG2λ�� */
    /* ���ݽṹ���Աm_BusSample������SAMλ�� */
    tmpreg = ((uint32_t)canInitStruct->m_BaudRate << CAN_BRGR_CANBRP0_POS) \
           | ((uint32_t)canInitStruct->m_SyncJumpWidth << CAN_BRGR_SJW0_POS) \
           | ((uint32_t)canInitStruct->m_TimeSeg1 << CAN_BRGR_TSEG1_0_POS) \
           | ((uint32_t)canInitStruct->m_TimeSeg2 << CAN_BRGR_TSEG2_0_POS) \
           | (canInitStruct->m_BusSample);
    CANx->BRGR = SFR_Config (CANx->BRGR, ~CAN_BRGR_INIT_MASK, tmpreg);

    /*---------------- ����CANx_ACRR�Ĵ��� ----------------*/
    CANx->ACRR = canInitStruct->m_Acceptance;

    /*---------------- ����CANx_MSKR�Ĵ��� ----------------*/
    CANx->MSKR = canInitStruct->m_AcceptanceMask;

    /* �˳���λģʽ */
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_RSMOD_POS);
}

/**
  * ����  ��ʼ��CAN������Ϣ�ṹ�塣
  * ����  canInitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void
CAN_Struct_Init (CAN_InitTypeDef* canInitStruct)
{
    /* ��ʼ�� CANʹ��ѡ�� */
    canInitStruct->m_Enable = FALSE;

    /* ��ʼ�� CAN����ģʽ */
    canInitStruct->m_Mode = CAN_MODE_NORMAL;

    /* ��ʼ�� CAN����ʱ�� */
    canInitStruct->m_WorkSource = CAN_SOURCE_SCLK_DIV_2;

    /* ��ʼ�� CAN������Ԥ��ֵ */
    canInitStruct->m_BaudRate = 0;

    /* ��ʼ�� CANͬ����ת��� */
    canInitStruct->m_SyncJumpWidth = 0;

    /* ��ʼ�� CANʱ���1 */
    canInitStruct->m_TimeSeg1 = 0;

    /* ��ʼ�� CANʱ���2 */
    canInitStruct->m_TimeSeg2 = 0;

    /* ��ʼ�� CAN���߲������� */
    canInitStruct->m_BusSample = CAN_BUS_SAMPLE_1_TIME;

    /* ��ʼ�� CAN���մ��� */
    canInitStruct->m_Acceptance = 0;

    /* ��ʼ�� CAN�������� */
    canInitStruct->m_AcceptanceMask = 0;
}
/**
  *   ##### ����������������(CAN)��ʼ������������� #####
  */


/**
  *   ##### ����������������(CAN)�������ú��� #####
  */
/**
  * ����  ��ȡCAN RX��Ϣ��������
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  * ����  RX��Ϣ����������ЧֵΪ5λ��
  */
uint32_t
CAN_Get_Receive_Message_Counter (CAN_SFRmap* CANx)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*---------------- ��ȡCANx_CTLR�Ĵ���CANRMCλ ----------------*/
    tmpreg = CANx->CTLR;
    tmpreg &= CAN_CTLR_CANRMC;
    tmpreg >>= CAN_CTLR_CANRMC0_POS;

    return tmpreg;
}

/**
  * ����  ��ȡCAN�����¼�״̬���͡�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       Type: CAN�����¼�״̬���ͣ�ȡֵΪ:
  *               CAN_BUS_OFF_STATUS: ���߹ر�״̬
  *               CAN_ERROR_STATUS: ����״̬
  *               CAN_TX_STATUS: ����״̬
  *               CAN_RX_STATUS: ����״̬
  *               CAN_TX_COMPLETE_OFF_STATUS: �������״̬
  *               CAN_TX_BUFFER_STATUS: ���ͻ�����״̬
  *               CAN_DATA_OVERFLOW_STATUS: ������״̬
  *               CAN_RX_BLANK_STATUS: ���ݿ�״̬
  * ����  1: ���߹ر�/����/���ڷ���/���ڽ���/�������/CPU���Է��ʷ��ͻ�����/
  *          RAM��δ��������/RAM����δ����Ϣ��
  *       0: ���߿���/�޴�/���Ϳ���/���տ���/����δ���/CPU���ܷ��ʷ��ͻ�����/
  *          RAM��δ������δ��/RAM����δ����Ϣ��
  */
FlagStatus
CAN_Get_Transmit_Status (CAN_SFRmap* CANx, uint32_t Type)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_STATUS(Type));

    /*---------------- ��ȡCANx_CTLR�Ĵ�����Ӧλ ----------------*/
    tmpreg = CANx->CTLR;

    if (tmpreg & Type)
    {
        /* ״̬λΪ1 */
        return SET;
    }
    else
    {
        /* ״̬λΪ0 */
        return RESET;
    }
}

/**
  * ����  ����CANʹ�ܡ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       NewState: CANʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
CAN_Cmd (CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����CANx_CTLR�Ĵ���CANENλ ----------------*/
    if (NewState != FALSE)
    {
        /* CANʹ�� */
        SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_CANEN_POS);
    }
    else
    {
        /* CAN��ֹ */
        SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_CANEN_POS);
    }
}

/**
  * ����  ����CAN����ʱ��ѡ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       ClockSource: CAN����ʱ�ӣ�ȡֵΪ:
  *                      CAN_SOURCE_SCLK_DIV_2: ѡ��SCLK��ʱ��/2��ΪCAN����ʱ��
  *                      CAN_SOURCE_HFCLK_DIV_2: ѡ��HFCLKʱ��/2��ΪCAN����ʱ��
  *                      CAN_SOURCE_LFCLK_DIV_2: ѡ��LFCLKʱ��/2��ΪCAN����ʱ��
  * ����  �ޡ�
  */
void
CAN_Clock_Source_Config (CAN_SFRmap* CANx, uint32_t ClockSource)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_SOURCE(ClockSource));

    /*---------------- ����CANx_CTLR�Ĵ���CANCKSλ ----------------*/
    CANx->CTLR = SFR_Config (CANx->CTLR, ~CAN_CTLR_CANCKS, ClockSource);
}

/**
  * ����  ����CAN˯��ģʽʹ�ܡ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       NewState: CAN˯��ģʽʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
CAN_Sleep_Mode_Enable (CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����CANx_CTLR�Ĵ���SLEEPλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��˯��ģʽ */
        SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_SLEEP_POS);
    }
    else
    {
        /* ��ֹ˯��ģʽ */
        SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_SLEEP_POS);
    }
}

/**
  * ����  ����CAN��λģʽʹ�ܡ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       NewState: CAN��λģʽʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
CAN_Reset_Mode_Enable (CAN_SFRmap* CANx, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����CANx_CTLR�Ĵ���RSMODλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ�ܸ�λģʽ */
        SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_RSMOD_POS);
    }
    else
    {
        /* ��ֹ��λģʽ */
        SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_RSMOD_POS);
    }
}

/**
  * ����  ����CAN����ģʽ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       ModeType: CAN����ģʽ��ȡֵΪ:
  *                   CAN_MODE_NORMAL: ��ֹ�����ͻػ�ģʽ
  *                   CAN_MODE_SILENT: ʹ�ܰ���ģʽ
  *                   CAN_MODE_LOOPBACK: ʹ�ܻػ�ģʽ
  *                   CAN_MODE_SILENT_LOOPBACK: ʹ�ܰ����ͻػ�ģʽ
  * ����  �ޡ�
  */
void
CAN_Work_Mode_Config (CAN_SFRmap* CANx, uint32_t ModeType)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_WORK_MODE(ModeType));

    /*------------ ����CANx_CTLR�Ĵ���SILENT��LBACKλ ------------*/
    CANx->CTLR = SFR_Config (CANx->CTLR,
                        ~(CAN_CTLR_SILENT | CAN_CTLR_LBACK),
                        ModeType);
}

/**
  * ����  ����CAN���߲���������
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       Times: ���߲���������ȡֵΪ:
  *                CAN_BUS_SAMPLE_1_TIME: ���߲���1��
  *                CAN_BUS_SAMPLE_3_TIMES: ���߲���3��
  * ����  �ޡ�
  */
void
CAN_Bus_Sample_Times_Config (CAN_SFRmap* CANx, uint32_t Times)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_BUS_SAMPLE(Times));

    /*---------------- ����CANx_BRGR�Ĵ���SAMλ ----------------*/
    if (Times != CAN_BUS_SAMPLE_1_TIME)
    {
        /* ���߲���3�� */
        SFR_SET_BIT_ASM(CANx->BRGR, CAN_BRGR_SAM_POS);
    }
    else
    {
        /* ���߲���1�� */
        SFR_CLR_BIT_ASM(CANx->BRGR, CAN_BRGR_SAM_POS);
    }
}

/**
  * ����  ����CAN����ʱ��Ρ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       TimeSeg1: CANʱ���1��ȡֵΪ4λ��Ч��ֵ��
  *       TimeSeg2: CANʱ���2��ȡֵΪ3λ��Ч��ֵ��
  * ����  �ޡ�
  */
void
CAN_Time_Segment_Config (CAN_SFRmap* CANx,
                    uint32_t TimeSeg1, uint32_t TimeSeg2)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_TIME_SEGMENT1(TimeSeg1));
    CHECK_RESTRICTION(CHECK_CAN_TIME_SEGMENT2(TimeSeg2));

    /*------------- ����CANx_BRGR�Ĵ���TSEG1/TSEG2λ -------------*/
    tmpreg = (TimeSeg1 << CAN_BRGR_TSEG1_0_POS) \
           | (TimeSeg2 << CAN_BRGR_TSEG2_0_POS);
    CANx->BRGR = SFR_Config (CANx->BRGR,
                        ~(CAN_BRGR_TSEG1 | CAN_BRGR_TSEG2),
                        tmpreg);
}

/**
  * ����  ����CANͬ����ת��ȡ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       JumpWidth: ͬ����ת��ȣ�ȡֵΪ2λ��Ч��ֵ��
  * ����  �ޡ�
  */
void
CAN_Sync_Jump_Width_Config (CAN_SFRmap* CANx, uint32_t JumpWidth)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_SYNC_JMP_WIDTH(JumpWidth));

    /*------------- ����CANx_BRGR�Ĵ���SJWλ -------------*/
    tmpreg = JumpWidth << CAN_BRGR_SJW0_POS;
    CANx->BRGR = SFR_Config (CANx->BRGR, ~CAN_BRGR_SJW, tmpreg);
}

/**
  * ����  ����CANͬ����ת��ȡ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       BaudRate: ������Ԥ��ֵ��ȡֵΪ6λ��Ч��ֵ��
  * ����  �ޡ�
  */
void
CAN_Baud_Rate_Preset_Config (CAN_SFRmap* CANx, uint32_t BaudRate)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_BAUDRATE_PRESET(BaudRate));

    /*------------- ����CANx_BRGR�Ĵ���CANBRPλ -------------*/
    tmpreg = BaudRate << CAN_BRGR_CANBRP0_POS;
    CANx->BRGR = SFR_Config (CANx->BRGR, ~CAN_BRGR_CANBRP, tmpreg);
}

/**
  * ����  ��ȡCAN���ߴ�����Ϣ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       canErrorStruct: CAN���ߴ�����Ϣ�ṹ�壬��¼������Ϣ��
  * ����  �ޡ�
  */
void
CAN_Get_Error_Code (CAN_SFRmap* CANx, CAN_ErrorTypeDef* canErrorStruct)
{
    uint32_t tmpreg = 0;
    uint32_t tmpreg1 = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(canErrorStruct != (CAN_ErrorTypeDef*)0);

    /*---------------- ��ȡCANx_RCR�Ĵ��� ----------------*/
    tmpreg = CANx->RCR;

    /*---------------- ��ȡCANx_RCR�Ĵ���CANERRCλ ----------------*/
    tmpreg1 = tmpreg & CAN_RCR_CANERRC;
    tmpreg1 >>= CAN_RCR_CANERRC0_POS;
    canErrorStruct->m_ErrorCode = tmpreg1;

    /*---------------- ��ȡCANx_RCR�Ĵ���CANDIRλ ----------------*/
    tmpreg1 = tmpreg & CAN_RCR_CANDIR;
    tmpreg1 >>= CAN_RCR_CANDIR_POS;
    canErrorStruct->m_ErrorDirection = tmpreg1;

    /*---------------- ��ȡCANx_RCR�Ĵ���CANSEGλ ----------------*/
    tmpreg1 = tmpreg & CAN_RCR_CANSEG;
    tmpreg1 >>= CAN_RCR_CANSEG0_POS;
    canErrorStruct->m_ErrorSegment = tmpreg1;

    /*---------------- ��ȡCANx_RCR�Ĵ���CANALCλ ----------------*/
    tmpreg1 = tmpreg & CAN_RCR_CANALC;
    tmpreg1 >>= CAN_RCR_CANALC0_POS;
    canErrorStruct->m_ArbitrationLost = tmpreg1;
}

/**
  * ����  ��ȡCAN���󱨾����ơ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  * ����  ���󱨾����ƣ�ȡֵΪ8λ��ֵ��
  */
uint8_t
CAN_Get_Error_Warning_Limit (CAN_SFRmap* CANx)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*---------------- ��ȡCANx_EROR�Ĵ���CANEWLλ ----------------*/
    tmpreg = CANx->EROR;

    return (uint8_t)tmpreg;
}

/**
  * ����  ��ȡCAN����/���մ����������
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       Direction: CAN�����䷽��ȡֵΪ��
  *                    CAN_ERROR_AT_TX: ���ʹ��������
  *                    CAN_ERROR_AT_RX: ���մ��������
  * ����  �����������ȡֵΪ8λ��ֵ��
  */
uint8_t
CAN_Get_Error_Counter (CAN_SFRmap* CANx, uint32_t Direction)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_ERROR_DIR(Direction));

    /*----------- ��ȡCANx_EROR�Ĵ��� -----------*/
    tmpreg = CANx->EROR;

    if (Direction != CAN_ERROR_AT_TX)
    {
        /*----------- ��ȡCANRXEλ -----------*/
        tmpreg &= CAN_EROR_CANRXE;
        tmpreg >>= CAN_EROR_CANRXE0_POS;
    }
    else
    {
        /*----------- ��ȡCANTXEλ -----------*/
        tmpreg &= CAN_EROR_CANTXE;
        tmpreg >>= CAN_EROR_CANTXE0_POS;
    }

    return (uint8_t)tmpreg;
}

/**
  * ����  ����CAN���󱨾����ơ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       ErrorLimit: ���󱨾����ƣ�ȡֵΪ8λ��Ч��ֵ��
  * ����  �ޡ�
  */
void
CAN_Error_Warning_Limit_Config (CAN_SFRmap* CANx, uint8_t ErrorLimit)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ����CANx_EROR�Ĵ���CANEWLλ -------------*/
    tmpreg = ErrorLimit << CAN_EROR_CANEWL0_POS;
    CANx->EROR = SFR_Config (CANx->EROR, ~CAN_EROR_CANEWL, tmpreg);
}

/**
  * ����  ����CAN����/���մ����������
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       Direction: CAN�����䷽��ȡֵΪ��
  *                    CAN_ERROR_AT_TX: ���ʹ��������
  *                    CAN_ERROR_AT_RX: ���մ��������
  *       ErrorCounter: ���������ȡֵΪ8λ��Ч��ֵ��
  * ����  �ޡ�
  */
void
CAN_Error_Counter_Config (CAN_SFRmap* CANx,
                    uint32_t Direction, uint8_t ErrorCounter)
{
    uint32_t tmpreg = 0;
    uint32_t tmpmask = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_ERROR_DIR(Direction));

    if (Direction != CAN_ERROR_AT_TX)
    {
        /*----------- ��ȡCANRXEλ -----------*/
        tmpreg = ErrorCounter << CAN_EROR_CANRXE0_POS;
        tmpmask = CAN_EROR_CANRXE;
    }
    else
    {
        /*----------- ��ȡCANTXEλ -----------*/
        tmpreg = ErrorCounter << CAN_EROR_CANTXE0_POS;
        tmpmask = CAN_EROR_CANTXE;
    }

    /*------------- ����CANx_EROR�Ĵ��� -------------*/
    CANx->EROR = SFR_Config (CANx->EROR, ~tmpmask, tmpreg);
}

/**
  * ����  ����CAN���մ��롣
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       Acceptance: ���մ��룬ȡֵΪ32λ��Ч��ֵ��
  * ����  �ޡ�
  */
void
CAN_Acceptance_Config (CAN_SFRmap* CANx, uint32_t Acceptance)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ����CANx_ACRR�Ĵ���ACRλ -------------*/
    CANx->ACRR = Acceptance;
}

/**
  * ����  ��ȡCAN���մ��롣
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  * ����  ���մ��룬ȡֵΪ32λ��Ч��ֵ��
  */
uint32_t
CAN_Get_Acceptance (CAN_SFRmap* CANx)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ��ȡCANx_ACRR�Ĵ���ACRλ -------------*/
    tmpreg = CANx->ACRR;

    return tmpreg;
}

/**
  * ����  ����CAN�������Ρ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       Acceptance: �������Σ�ȡֵΪ32λ��Ч��ֵ��
  * ����  �ޡ�
  */
void
CAN_Acceptance_Mask_Config (CAN_SFRmap* CANx, uint32_t Acceptance)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ����CANx_MSKR�Ĵ���MSKλ -------------*/
    CANx->MSKR = Acceptance;
}

/**
  * ����  ��ȡCAN�������Ρ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  * ����  �������Σ�ȡֵΪ32λ��Ч��ֵ��
  */
uint32_t
CAN_Get_Acceptance_Mask (CAN_SFRmap* CANx)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*------------- ��ȡCANx_MSKR�Ĵ���MSKλ -------------*/
    tmpreg = CANx->MSKR;

    return tmpreg;
}
/**
  *   ##### ����������������(CAN)�������ú���������� #####
  */


/**
  *   ##### ����������������(CAN)���ͽ��պ��� #####
  */
/**
  * ����  CANģ��(CAN)���ͻ������á�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       canInitStruct: CANģ��������Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void
CAN_Transmit_Message_Configuration (CAN_SFRmap* CANx,
                    CAN_MessageTypeDef* canInitStruct)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_FRAME_FORMAT(canInitStruct->m_FrameFormat));
    CHECK_RESTRICTION(CHECK_CAN_REMOTE_REQUEST(canInitStruct->m_RemoteTransmit));
    CHECK_RESTRICTION(CHECK_CAN_DATA_LENGTH(canInitStruct->m_DataLength));
    CHECK_RESTRICTION(CHECK_CAN_SFF_ID(canInitStruct->m_StandardID));
    CHECK_RESTRICTION(CHECK_CAN_EFF_ID(canInitStruct->m_ExtendedID));

    /*---------------- ����CANx_INFR�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_FrameFormat������IDEλ�� */
    /* ���ݽṹ���Աm_RemoteTransmit������RTRλ�� */
    /* ���ݽṹ���Աm_DataLength������DLCλ�� */
    tmpreg = (canInitStruct->m_FrameFormat << CAN_INFR_IDE_POS) \
           | (canInitStruct->m_RemoteTransmit << CAN_INFR_RTR_POS) \
           | (canInitStruct->m_DataLength << CAN_INFR_DLC0_POS);
    CANx->INFR = SFR_Config (CANx->INFR, ~CAN_INFR_INIT_MASK, tmpreg);

    /*----------- ����CANx_TX0R/CANx_TX1R/CANx_TX2R�Ĵ��� -----------*/
    /* ���ݽṹ���Աm_FrameFormat��ѡ��֡��ʽ */
    /* ���ݽṹ���Աm_StandardID������IDxλ�� */
    /* ���ݽṹ���Աm_ExtendedID������IDxλ�� */
    /* ���ݽṹ���Աm_Data������CANTXDTxλ�� */
    if (canInitStruct->m_FrameFormat != CAN_FRAME_FORMAT_EFF)
    {
        /*----------- ����CANx_TX0R�Ĵ��� -----------*/
        tmpreg = (canInitStruct->m_StandardID << CAN_TX0R_ID18_POS) \
               | ((uint32_t)canInitStruct->m_Data[0] << CAN_TX0R_CANTX0_8_POS) \
               | ((uint32_t)canInitStruct->m_Data[1] << CAN_TX0R_CANTX0_0_POS);
        CANx->TX0R = SFR_Config (CANx->TX0R, ~CAN_TX0R_SFF_MASK, tmpreg);

        /*----------- ����CANx_TX1R�Ĵ��� -----------*/
        tmpreg = ((uint32_t)canInitStruct->m_Data[2] << CAN_TX1R_CANTX1_24_POS) \
               | ((uint32_t)canInitStruct->m_Data[3] << CAN_TX1R_CANTX1_16_POS) \
               | ((uint32_t)canInitStruct->m_Data[4] << CAN_TX1R_CANTX1_8_POS) \
               | ((uint32_t)canInitStruct->m_Data[5] << CAN_TX1R_CANTX1_0_POS);
        CANx->TX1R = tmpreg;

        /*----------- ����CANx_TX2R�Ĵ��� -----------*/
        tmpreg = ((uint32_t)canInitStruct->m_Data[6] << CAN_TX2R_CANTX2_24_POS) \
               | ((uint32_t)canInitStruct->m_Data[7] << CAN_TX2R_CANTX2_16_POS);
        CANx->TX2R = SFR_Config (CANx->TX2R, ~CAN_TX2R_SFF_MASK, tmpreg);
    }
    else
    {
        /*----------- ����CANx_TX0R�Ĵ��� -----------*/
        tmpreg = canInitStruct->m_ExtendedID << CAN_TX0R_ID0_POS;
        CANx->TX0R = SFR_Config (CANx->TX0R, ~CAN_TX0R_EFF_MASK, tmpreg);

        /*----------- ����CANx_TX1R�Ĵ��� -----------*/
        tmpreg = ((uint32_t)canInitStruct->m_Data[0] << CAN_TX1R_CANTX1_24_POS) \
               | ((uint32_t)canInitStruct->m_Data[1] << CAN_TX1R_CANTX1_16_POS) \
               | ((uint32_t)canInitStruct->m_Data[2] << CAN_TX1R_CANTX1_8_POS) \
               | ((uint32_t)canInitStruct->m_Data[3] << CAN_TX1R_CANTX1_0_POS);
        CANx->TX1R = tmpreg;

        /*----------- ����CANx_TX2R�Ĵ��� -----------*/
        tmpreg = ((uint32_t)canInitStruct->m_Data[4] << CAN_TX2R_CANTX2_24_POS) \
               | ((uint32_t)canInitStruct->m_Data[5] << CAN_TX2R_CANTX2_16_POS) \
               | ((uint32_t)canInitStruct->m_Data[6] << CAN_TX2R_CANTX2_8_POS) \
               | ((uint32_t)canInitStruct->m_Data[7] << CAN_TX2R_CANTX2_0_POS);
        CANx->TX2R = tmpreg;
    }
}

/**
  * ����  ��ȡCANģ��(CAN)���ջ����һ��֡��Ϣ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       ReceiveOffset: RAM�洢�ռ���ʼ��ַ��ȡֵΪ8λ��Ч����4�ֽڶ��롣
  *       canInitStruct: CANģ��������Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void
CAN_Receive_Message_Configuration (CAN_SFRmap* CANx,
                    uint32_t ReceiveOffset, CAN_MessageTypeDef* canInitStruct)
{
    uint32_t tmpreg = 0;
    uint32_t tmpreg1 = 0;
    uint32_t tmpaddr = 0;
    uint8_t dataoffset[] = {1,0,7,6,5,4,11,10};
    uint32_t i = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_RECEIVE_OFFSET(ReceiveOffset));

    /* ��ȡRXDATA0���洢�����һ������ */
    tmpreg = (uint32_t)CANx;
    switch (tmpreg)
    {
#ifdef  KF32A_Periph_can0
		case CAN0_ADDR:
			tmpaddr = CAN0_RECEIVE_ADDR;
			break;
#endif
#ifdef  KF32A_Periph_can1
		case CAN1_ADDR:
			tmpaddr = CAN1_RECEIVE_ADDR;
			break;
#endif
#ifdef  KF32A_Periph_can2
		case CAN2_ADDR:
			tmpaddr = CAN2_RECEIVE_ADDR;
			break;
#endif
#ifdef  KF32A_Periph_can3
		case CAN3_ADDR:
			tmpaddr = CAN3_RECEIVE_ADDR;
			break;
#endif
#ifdef  KF32A_Periph_can4
		case CAN4_ADDR:
			tmpaddr = CAN4_RECEIVE_ADDR;
			break;
#endif
#ifdef  KF32A_Periph_can5
		case CAN5_ADDR:
			tmpaddr = CAN5_RECEIVE_ADDR;
			break;
#endif
		default:
			break;
    }
    tmpaddr += ReceiveOffset;
    tmpreg = *(volatile uint32_t *)tmpaddr;

    /* CAN֡��ʽ */
    tmpreg1 = (tmpreg & CAN_INFR_IDE) >> CAN_INFR_IDE_POS;
    canInitStruct->m_FrameFormat = tmpreg1;

    /* CANԶ�̷������� */
    tmpreg1 = (tmpreg & CAN_INFR_RTR) >> CAN_INFR_RTR_POS;
    canInitStruct->m_RemoteTransmit = tmpreg1;

    /* �ж����������ֽڵĽ��� */
    if (tmpreg1 != CAN_DATA_FRAME)//Զ��֡
    {
        return;
    }
    else//����֡
    {
        ;
    }

    /* ���ݳ��� */
    tmpreg1 = (tmpreg & CAN_INFR_DLC) >> CAN_INFR_DLC0_POS;
    canInitStruct->m_DataLength = tmpreg1;

    if (canInitStruct->m_FrameFormat != CAN_FRAME_FORMAT_EFF)
    {
        /* ��׼��ʽSFF */
        /* ��ȡRXDATA1���洢����ڶ������� */
        tmpaddr += 4;
        tmpreg = *(volatile uint32_t *)tmpaddr;

        /* ��׼֡ID */
        tmpreg1 = (tmpreg & CAN_TX0R_SFF_ID) >> CAN_TX0R_ID18_POS;
        canInitStruct->m_StandardID = tmpreg1;

        /* ��ȡ�����������ݳ���Ϊm_DataLength�����Ϊ8�ֽ� */
        for (i = 0; i < canInitStruct->m_DataLength; i++)
        {
            canInitStruct->m_Data[i] =
                    *(volatile uint8_t *)(tmpaddr + dataoffset[i]);
        }
    }
    else
    {
        /* ��չ֡��ʽEFF */
        /* ��ȡRXDATA1���洢����ڶ������� */
        tmpaddr += 4;
        tmpreg = *(volatile uint32_t *)tmpaddr;

        /* ��չ֡ID */
        tmpreg1 = (tmpreg & CAN_TX0R_EFF_ID) >> CAN_TX0R_ID0_POS;
        canInitStruct->m_ExtendedID = tmpreg1;

        /* ��ȡ�����������ݳ���Ϊm_DataLength�����Ϊ8�ֽ� */
        tmpaddr += 4;
        if (canInitStruct->m_DataLength < 4)
        {
            /* ��ȡRXDATA2 */
            for (i = 0; i < canInitStruct->m_DataLength; i++)
            {
                canInitStruct->m_Data[i] =
                        *(volatile uint8_t *)(tmpaddr + 3 - i);
            }
        }
        else
        {
            /* ��ȡRXDATA2 */
            for (i = 0; i < 4; i++)
            {
                canInitStruct->m_Data[i] =
                        *(volatile uint8_t *)(tmpaddr + 3 - i);
            }

            /* ��ȡRXDATA3 */
            tmpaddr += 4;
            for (i = 4; i < canInitStruct->m_DataLength; i++)
            {
                canInitStruct->m_Data[i] =
                        *(volatile uint8_t *)(tmpaddr + 7 - i);
            }
        }
    }
}

/**
  * ����  ��ʼ��CAN������Ϣ�ṹ�塣
  * ����  canInitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void
CAN_Message_Struct_Init (CAN_MessageTypeDef* canInitStruct)
{
    uint32_t i = 0;

    /* ��ʼ�� ֡��ʽѡ�� */
    canInitStruct->m_FrameFormat = CAN_FRAME_FORMAT_SFF;

    /* ��ʼ�� Զ�̷������� */
    canInitStruct->m_RemoteTransmit = CAN_DATA_FRAME;

    /* ��ʼ�� ���ݳ��� */
    canInitStruct->m_DataLength = 0;

    /* ��ʼ�� ��׼֡ID */
    canInitStruct->m_StandardID = 0;

    /* ��ʼ�� ��չ֡ID */
    canInitStruct->m_ExtendedID = 0;

    /* ��ʼ�� ������ */
    for (i = 0; i < 8; i++)
    {
        canInitStruct->m_Data[i] = 0;
    }
}

/**
  * ����  ���CAN �������������־��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  * ����  �ޡ�
  */
void
CAN_Clear_Buffer_Overflow_Flag (CAN_SFRmap* CANx)
{

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*-------------------- ����CANx_CTLR�Ĵ���RELFλ --------------------*/
    SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_RELRX_POS);
    while(!((CANx->CTLR & CAN_CTLR_RXBSTA)>>CAN_CTLR_RXBSTA_POS));
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_RELRX_POS);

    SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_RELF_POS);
    while((CANx->CTLR & CAN_CTLR_DOSTA)>>CAN_CTLR_DOSTA_POS);
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_RELF_POS);
}

/**
  * ����  �ͷ�CAN ���ջ�������
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *    	ReleaseCount: �ͷŻ���������
  * ����  �ޡ�
  */
void
CAN_Release_Receive_Buffer (CAN_SFRmap* CANx, uint32_t ReleaseCount)
{
	uint32_t i,tmprmc;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*-------------------- ����CANx_CTLR�Ĵ���RELRXλ --------------------*/
    for(i=0;i<ReleaseCount;i++)
    {
        tmprmc = (CANx->CTLR&CAN_CTLR_CANRMC)>>CAN_CTLR_CANRMC0_POS;
        if(tmprmc == 0)
        {
        	return ;
        }
        else
        {
    		SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_RELRX_POS);
    		while(tmprmc - ((CANx->CTLR&CAN_CTLR_CANRMC)>>CAN_CTLR_CANRMC0_POS) != 1);
    		SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_RELRX_POS);
    	}
    }
}

/**
  * ����  ���η��ͣ���������������ٲö�ʧʱ��������ط������η��ͣ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  * ����  �ޡ�
  * ��ע������֮ǰ��ȷ�����߿����������ڿ���״̬
  */
void
CAN_Transmit_Single (CAN_SFRmap* CANx)
{
 volatile unsigned char i=80;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_TXR_POS);
	//asm("nop");
	//SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_TXR_POS);
    /*-------------------- ����CANx_CTLR�Ĵ���TXRλ --------------------*/
    CANx->CTLR = CANx->CTLR | 0x300;
    
    //while(!(CANx->CTLR & CAN_CTLR_TXSTA)>>CAN_CTLR_TXSTA_POS)
    //    while(i--);
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_ATX_POS);
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_TXR_POS);
}

/**
 * ����  ���ͣ����������ٲö�ʧ���ͽ���ʱ������ط����������ͣ���
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  * ����  �ޡ�
  * ��ע������֮ǰ��ȷ�����߿����������ڿ���״̬
  */
void
CAN_Transmit_Repeat (CAN_SFRmap* CANx)
{
	volatile unsigned int	temp;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));

    /*-------------------- ����CANx_CTLR�Ĵ���TXRλ --------------------*/
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_ATX_POS);
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_TXR_POS);
    SFR_SET_BIT_ASM(CANx->CTLR, CAN_CTLR_TXR_POS);
    while((CANx->CTLR & CAN_CTLR_TXSTA)>>CAN_CTLR_TXSTA_POS);
    SFR_CLR_BIT_ASM(CANx->CTLR, CAN_CTLR_TXR_POS);
}

/**
  * ����  ����CAN���ͻ�����֡��ʽ��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       FrameFormat: ֡��ʽ��ȡֵΪ:
  *                      CAN_FRAME_FORMAT_SFF: ��׼֡��ʽSFF
  *                      CAN_FRAME_FORMAT_EFF: ��չ֡��ʽEFF
  * ����  �ޡ�
  */
void
CAN_Frame_Format_Config (CAN_SFRmap* CANx, uint32_t FrameFormat)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_FRAME_FORMAT(FrameFormat));

    /*---------------- ����CANx_INFR�Ĵ���IDEλ ----------------*/
    if (FrameFormat != CAN_FRAME_FORMAT_SFF)
    {
        /* ��չ֡��ʽEFF */
        SFR_SET_BIT_ASM(CANx->INFR, CAN_INFR_IDE_POS);
    }
    else
    {
        /* ��׼֡��ʽSFF */
        SFR_CLR_BIT_ASM(CANx->INFR, CAN_INFR_IDE_POS);
    }
}

/**
  * ����  ����CAN���ͻ�����Զ�̷�������
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       RemoteRequest: Զ�̷�������ȡֵΪ:
  *                        CAN_DATA_FRAME: ����֡
  *                        CAN_REMOTE_FRAME: Զ��֡
  * ����  �ޡ�
  */
void
CAN_Remote_Request_Config (CAN_SFRmap* CANx, uint32_t RemoteRequest)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_REMOTE_REQUEST(RemoteRequest));

    /*---------------- ����CANx_INFR�Ĵ���RTRλ ----------------*/
    if (RemoteRequest != CAN_DATA_FRAME)
    {
        /* Զ��֡ */
        SFR_SET_BIT_ASM(CANx->INFR, CAN_INFR_RTR_POS);
    }
    else
    {
        /* ����֡ */
        SFR_CLR_BIT_ASM(CANx->INFR, CAN_INFR_RTR_POS);
    }
}

/**
  * ����  ����CAN���ͻ��������ݳ��ȣ�����8�����ݳ��ȴ����ǲ����õġ�
  *       �������8������8���ֽڼơ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       Length: CAN���ݳ��ȣ�ȡֵΪ4λ��Ч��ֵ���������8������8���ֽڼơ�
  * ����  �ޡ�
  */
void
CAN_Data_Length_Config (CAN_SFRmap* CANx, uint32_t Length)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_DATA_LENGTH(Length));

    /*------------- ����CANx_INFR�Ĵ���DLCλ -------------*/
    tmpreg = Length << CAN_INFR_DLC0_POS;
    CANx->EROR = SFR_Config (CANx->EROR, ~CAN_INFR_DLC, tmpreg);
}

/**
  * ����  ����CAN���ͻ�����ʶ���롣
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       Format: CAN֡��ʽ��ȡֵΪ:
                    CAN_FRAME_FORMAT_SFF: ��׼��ʽSFF
                    CAN_FRAME_FORMAT_EFF: ��չ��ʽEFF
  *       IDCode: CANʶ���룬��׼��ʽSFFΪ11λ����չ��ʽEFFλ29λ��
  * ����  �ޡ�
  */
void
CAN_Identification_Code_Config (CAN_SFRmap* CANx,
                    uint32_t FrameFormat, uint32_t IDCode)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_FRAME_FORMAT(FrameFormat));
    if (FrameFormat != CAN_FRAME_FORMAT_SFF)
    {
        CHECK_RESTRICTION(CHECK_CAN_EFF_ID(IDCode));
    }
    else
    {
        CHECK_RESTRICTION(CHECK_CAN_SFF_ID(IDCode));
    }

    /*------------- ����CANx_TX0R�Ĵ���IDxλ -------------*/
    if (FrameFormat != CAN_FRAME_FORMAT_SFF)
    {
        /* ��չ��ʽEFF */
        tmpreg = IDCode << CAN_TX0R_ID0_POS;
        CANx->TX0R = SFR_Config (CANx->TX0R, ~CAN_TX0R_EFF_ID, tmpreg);
    }
    else
    {
        /* ��׼��ʽSFF */
        tmpreg = IDCode << CAN_TX0R_ID18_POS;
        CANx->TX0R = SFR_Config (CANx->TX0R, ~CAN_TX0R_SFF_ID, tmpreg);
    }
}
/**
  *   ##### ����������������(CAN)���ͽ��պ���������� #####
  */


/**
  *   ##### ����������������(CAN)�жϹ����� #####
  */
/**
  * ����  ��ȡCAN�жϱ�־��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       InterruptType: CAN�ж����ͣ�ȡֵ��ΧΪ�����ṩ��һ��:
  *                        CAN_INT_RECEIVE: �����ж�
  *                        CAN_INT_TRANSMIT: �����ж�
  *                        CAN_INT_ERROR_ALARM: ���󱨾��ж�
  *                        CAN_INT_DATA_OVERFLOW: ��������ж�
  *                        CAN_INT_WAKE_UP: �����ж�
  *                        CAN_INT_ERROR_NEGATIVE: ���������ж�
  *                        CAN_INT_ARBITRATION_LOST: �ٲö�ʧ�ж�
  *                        CAN_INT_BUS_ERROR: ���ߴ����ж�
  * ����  1:�����жϣ�0:δ�����жϡ�
  */
FlagStatus
CAN_Get_INT_Flag (CAN_SFRmap* CANx, uint32_t InterruptType)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_INT_ONE_EVENT(InterruptType));

    /* �����жϱ�־���� */
    tmpreg = InterruptType << CAN_IFR_CANRXIF_POS;
    /*---------------- ��ȡCAN_IFR�Ĵ����жϱ�־λ ----------------*/
    if (CANx->IFR & tmpreg)
    {
        /* �����ж� */
        return SET;
    }
    else
    {
        /* δ�����ж� */
        return RESET;
    }
}

/**
  * ����  ����CAN�жϱ�־��
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       InterruptType: CAN�ж����ͣ�ȡֵ��ΧΪ�����ṩ��һ���������:
  *                        CAN_INT_RECEIVE: �����ж�
  *                        CAN_INT_TRANSMIT: �����ж�
  *                        CAN_INT_ERROR_ALARM: ���󱨾��ж�
  *                        CAN_INT_DATA_OVERFLOW: ��������ж�
  *                        CAN_INT_WAKE_UP: �����ж�
  *                        CAN_INT_ERROR_NEGATIVE: ���������ж�
  *                        CAN_INT_ARBITRATION_LOST: �ٲö�ʧ�ж�
  *                        CAN_INT_BUS_ERROR: ���ߴ����ж�
  * ����  �ޡ�
  */
void
CAN_Clear_INT_Flag (CAN_SFRmap* CANx, uint32_t InterruptType)
{
	uint32_t tmpreg = 0;
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_INT_EVENT(InterruptType));

    /*---------------- ����CAN_IER�Ĵ����жϱ�־λ ----------------*/
    tmpreg = InterruptType << CAN_IFR_CANRXIF_POS;
    CANx->IER |= InterruptType << CAN_IER_CANRXIC_POS;
    while((CANx->IFR & tmpreg)>0);
    CANx->IER &= ~(InterruptType << CAN_IER_CANRXIC_POS);
}

/**
  * ����  ����CAN�ж�ʹ�ܡ�
  * ����  CANx: ָ��CAN�ڴ�ṹ��ָ�룬ȡֵΪCAN0_SFR~CAN5_SFR��
  *       InterruptType: CAN�ж����ͣ�ȡֵ��ΧΪ�����ṩ��һ���������:
  *                        CAN_INT_RECEIVE: �����ж�
  *                        CAN_INT_TRANSMIT: �����ж�
  *                        CAN_INT_ERROR_ALARM: ���󱨾��ж�
  *                        CAN_INT_DATA_OVERFLOW: ��������ж�
  *                        CAN_INT_WAKE_UP: �����ж�
  *                        CAN_INT_ERROR_NEGATIVE: ���������ж�
  *                        CAN_INT_ARBITRATION_LOST: �ٲö�ʧ�ж�
  *                        CAN_INT_BUS_ERROR: ���ߴ����ж�
  *       NewState: DMAͨ���������ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
CAN_Set_INT_Enable (CAN_SFRmap* CANx,
                    uint32_t InterruptType, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_CAN_ALL_PERIPH(CANx));
    CHECK_RESTRICTION(CHECK_CAN_INT_EVENT(InterruptType));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����CAN_IER�Ĵ����ж�ʹ��λ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ���ж� */
        CANx->IER |= InterruptType << CAN_IER_CANRXIE_POS;
    }
    else
    {
        /* ��ֹ�ж� */
        CANx->IER &= ~(InterruptType << CAN_IER_CANRXIE_POS);
    }
}
/**
  *   ##### ����������������(CAN)�жϹ������������ #####
  */

#endif //KF32A_Periph_can

