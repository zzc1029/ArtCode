/**
  ******************************************************************************
  * �ļ���  kf32a_basic_can.h
  * ��  ��  ChipON_AE/FAE_Group
  * ��  ��  V2.62
  * ��  ��  2019-11-16
  * ��  ��  ���ļ��ṩ�˿���������������(CAN)��ع��ܺ�����������غ궨�塣
  *********************************************************************
  */

#ifndef _KF32A_BASIC_CAN_H_
#define _KF32A_BASIC_CAN_H_

#include "KF32A_BASIC.h"



/**
  * ����  ����������������(CAN)������Ϣ�ṹ��
  */
typedef struct
{
    FunctionalState m_Enable;       /* CANʹ��ѡ��
                                       ȡֵΪTRUE��FALSE��*/
    uint32_t m_Mode;                /* CAN����ģʽ��
                                       ȡֵ�ꡰCAN����ģʽ���е�һ���� */
    uint32_t m_WorkSource;          /* CAN����ʱ�ӣ�
                                       ȡֵ�ꡰCAN����ʱ�ӡ��е�һ���� */
    uint8_t m_BaudRate;             /* CAN������Ԥ��ֵ��
                                       ȡֵΪ0~0x3F�� */
    uint8_t m_SyncJumpWidth;        /* CANͬ����ת��ȣ�
                                       ȡֵΪ0~0x3�� */
    uint8_t m_TimeSeg1;             /* CANʱ���1��
                                       ȡֵΪ0~0xF�� */
    uint8_t m_TimeSeg2;             /* CANʱ���2��
                                       ȡֵΪ0~0x7�� */
    uint32_t m_BusSample;           /* CAN���߲���������
                                       ȡֵ�ꡰCAN���߲����������е�һ���� */
    uint32_t m_Acceptance;          /* CAN���մ��룬
                                       ȡֵΪ32λ���ݡ� */
    uint32_t m_AcceptanceMask;      /* CAN�������룬
                                       ȡֵΪ32λ���ݡ� */
}CAN_InitTypeDef;

/**
  * ����  CAN���ߴ�����Ϣ�ṹ��
  */
typedef struct
{
    uint8_t m_ErrorCode;            /* ������룬
                                       ȡֵ�ꡰCAN������롱�е�һ���� */
    uint8_t m_ErrorDirection;       /* ���䷽��
                                       ȡֵ�ꡰCAN�����䷽���е�һ���� */
    uint8_t m_ErrorSegment;         /* �������ĶΣ�
                                       ȡֵ�ꡰCAN�������ĶΡ��е�һ���� */
    uint8_t m_ArbitrationLost;      /* �ٲö�ʧλ�ã�
                                       ȡֵΪ�ꡰCAN�ٲö�ʧλ�á��е�һ�� */
}CAN_ErrorTypeDef;

/**
  * ����  CAN������Ϣ�ṹ��
  */
typedef struct
{
    uint32_t m_FrameFormat;         /* ֡��ʽѡ��
                                       ȡֵ�ꡰCAN֡��ʽ���е�һ���� */
    uint32_t m_RemoteTransmit;      /* Զ�̷�������
                                       ȡֵ�ꡰCANԶ�̷��������е�һ���� */
    uint32_t m_DataLength;          /* ���ݳ��ȣ�
                                       ȡֵΪ4λ���ݡ� */
    uint32_t m_StandardID;          /* ��׼֡ID��
                                       ȡֵΪ0~0x7FF�� */
    uint32_t m_ExtendedID;          /* ��չ֡ID��
                                       ȡֵΪ0~0x1FFFFFFF�� */
    uint8_t m_Data[16];              /* ��������
                                       ȡֵΪ16�ֽ����ݡ� */
}CAN_MessageTypeDef;


/**
  * CAN�ڴ�ָ��
  */
//#define CHECK_CAN_ALL_PERIPH(PERIPH)   (((PERIPH) == CAN0_SFR)  \
//                                      || ((PERIPH) == CAN1_SFR) \
//                                      || ((PERIPH) == CAN2_SFR) \
//                                      || ((PERIPH) == CAN3_SFR) \
//									    || ((PERIPH) == CAN4_SFR) \
//								        || ((PERIPH) == CAN5_SFR))
#define CHECK_CAN_ALL_PERIPH(PERIPH)   (((PERIPH) ==  ((CAN_SFRmap *)(uint32_t)0x40001100)) \
                                      || ((PERIPH) == ((CAN_SFRmap *)(uint32_t)0x40001180)) \
                                      || ((PERIPH) == ((CAN_SFRmap *)(uint32_t)0x40001900)) \
                                      || ((PERIPH) == ((CAN_SFRmap *)(uint32_t)0x40001980)) \
									  || ((PERIPH) == ((CAN_SFRmap *)(uint32_t)0x40002880)) \
								      || ((PERIPH) == ((CAN_SFRmap *)(uint32_t)0x40002900)))
/**
  * CAN�����¼�״̬����
  */
#define CAN_BUS_OFF_STATUS              ((uint32_t)CAN_CTLR_BOFF)
#define CAN_ERROR_STATUS                ((uint32_t)CAN_CTLR_CERROR)
#define CAN_TX_STATUS                   ((uint32_t)CAN_CTLR_TXSTA)
#define CAN_RX_STATUS                   ((uint32_t)CAN_CTLR_RXSTA)
#define CAN_TX_COMPLETE_OFF_STATUS      ((uint32_t)CAN_CTLR_TCSTA)
#define CAN_TX_BUFFER_STATUS            ((uint32_t)CAN_CTLR_TXBSTA)
#define CAN_DATA_OVERFLOW_STATUS        ((uint32_t)CAN_CTLR_DOSTA)
#define CAN_RX_BLANK_STATUS             ((uint32_t)CAN_CTLR_RXBSTA)
#define CHECK_CAN_STATUS(TYPE)          (((TYPE) == CAN_BUS_OFF_STATUS) \
                                      || ((TYPE) == CAN_ERROR_STATUS) \
                                      || ((TYPE) == CAN_TX_STATUS) \
                                      || ((TYPE) == CAN_RX_STATUS) \
                                      || ((TYPE) == CAN_TX_COMPLETE_OFF_STATUS) \
                                      || ((TYPE) == CAN_TX_BUFFER_STATUS) \
                                      || ((TYPE) == CAN_DATA_OVERFLOW_STATUS) \
                                      || ((TYPE) == CAN_RX_BLANK_STATUS))

/**
  * CAN����ʱ��
  */
#define CAN_SOURCE_SCLK_DIV_2           ((uint32_t)0<<CAN_CTLR_CANCKS0_POS)
#define CAN_SOURCE_HFCLK_DIV_2          ((uint32_t)1<<CAN_CTLR_CANCKS0_POS)
#define CAN_SOURCE_LFCLK_DIV_2          ((uint32_t)2<<CAN_CTLR_CANCKS0_POS)
#define CAN_SOURCE_INTLF_DIV_2          ((uint32_t)3<<CAN_CTLR_CANCKS0_POS)
#define CHECK_CAN_SOURCE(SEL)           (((SEL) == CAN_SOURCE_SCLK_DIV_2) \
                                      || ((SEL) == CAN_SOURCE_HFCLK_DIV_2) \
                                      || ((SEL) == CAN_SOURCE_LFCLK_DIV_2))
#define CHECK_CAN_LOWPOWER_SOURCE(SEL)  ((SEL) == CAN_SOURCE_INTLF_DIV_2)

/**
  * CAN����ģʽ
  */
#define CAN_MODE_NORMAL                 ((uint32_t)0<<CAN_CTLR_SILENT_POS)
#define CAN_MODE_SILENT                 ((uint32_t)1<<CAN_CTLR_SILENT_POS)
#define CAN_MODE_LOOPBACK               ((uint32_t)2<<CAN_CTLR_SILENT_POS)
#define CAN_MODE_SILENT_LOOPBACK        ((uint32_t)3<<CAN_CTLR_SILENT_POS)
#define CHECK_CAN_WORK_MODE(SEL)        (((SEL) == CAN_MODE_NORMAL) \
                                      || ((SEL) == CAN_MODE_SILENT) \
                                      || ((SEL) == CAN_MODE_LOOPBACK) \
                                      || ((SEL) == CAN_MODE_SILENT_LOOPBACK))

/**
  * CAN���߲�������
  */
#define CAN_BUS_SAMPLE_1_TIME           ((uint32_t)0<<CAN_BRGR_SAM_POS)
#define CAN_BUS_SAMPLE_3_TIMES          ((uint32_t)1<<CAN_BRGR_SAM_POS)
#define CHECK_CAN_BUS_SAMPLE(TIMES)     (((TIMES) == CAN_BUS_SAMPLE_1_TIME) \
                                      || ((TIMES) == CAN_BUS_SAMPLE_3_TIMES))

/**
  * CANʱ�����֤
  */
#define CHECK_CAN_TIME_SEGMENT1(DATA)   (((uint32_t)(DATA)>>4) == 0)
#define CHECK_CAN_TIME_SEGMENT2(DATA)   (((uint32_t)(DATA)>>3) == 0)

/**
  * CANͬ����ת
  */
#define CHECK_CAN_SYNC_JMP_WIDTH(DATA)  (((uint32_t)(DATA)>>2) == 0)

/**
  * CAN������Ԥ��ֵ
  */
#define CHECK_CAN_BAUDRATE_PRESET(DATA) (((uint32_t)(DATA)>>6) == 0)

/**
  * CAN�������
  */
#define CAN_BIT_ERROR                   ((uint32_t)0)
#define CAN_FORMAT_ERROR                ((uint32_t)1)
#define CAN_PADDING_ERROR               ((uint32_t)2)
#define CAN_OTHER_ERROR                 ((uint32_t)3)

/**
  * CAN�����䷽��
  */
#define CAN_ERROR_AT_TX                 ((uint32_t)0)
#define CAN_ERROR_AT_RX                 ((uint32_t)1)
#define CHECK_CAN_ERROR_DIR(ERROR)      (((ERROR) == CAN_ERROR_AT_TX) \
                                      || ((ERROR) == CAN_ERROR_AT_RX))

/**
  * CAN�������Ķ�
  */
#define CAN_SEG_FRAME_HEAD              ((uint32_t)0x3)
#define CAN_SEG_ID28_TO_ID21            ((uint32_t)0x2)
#define CAN_SEG_ID20_TO_ID18            ((uint32_t)0x6)
#define CAN_SEG_SRR                     ((uint32_t)0x4)
#define CAN_SEG_IDE                     ((uint32_t)0x5)
#define CAN_SEG_ID17_TO_ID13            ((uint32_t)0x7)
#define CAN_SEG_ID12_TO_ID5             ((uint32_t)0xF)
#define CAN_SEG_ID4_TO_ID0              ((uint32_t)0xE)
#define CAN_SEG_RTR                     ((uint32_t)0xC)
#define CAN_SEG_DATA_LENGTH             ((uint32_t)0xB)
#define CAN_SEG_DATA_POOL               ((uint32_t)0xA)
#define CAN_SEG_CRC_SEQUENCE            ((uint32_t)0x8)
#define CAN_SEG_CRC_DELIMITER           ((uint32_t)0x18)
#define CAN_SEG_ANSWER                  ((uint32_t)0x19)
#define CAN_SEG_ANSWER_DELIMITER        ((uint32_t)0x1B)
#define CAN_SEG_FRAME_END               ((uint32_t)0x1A)
#define CAN_SEG_INTERFRAME              ((uint32_t)0x12)
#define CAN_SEG_ACTIVE_ERROR            ((uint32_t)0x11)
#define CAN_SEG_NEGATIVE_ERROR          ((uint32_t)0x16)
#define CAN_SEG_CONTROL                 ((uint32_t)0x13)
#define CAN_SEG_OVERLOAD_DELIMITER      ((uint32_t)0x17)
#define CAN_SEG_OVERFLOW_FLAG           ((uint32_t)0x1C)

/**
  * CAN�ٲö�ʧλ��
  */
#define CAN_ARBITRATION_LOST_ID28       ((uint32_t)0x0)
#define CAN_ARBITRATION_LOST_ID27       ((uint32_t)0x1)
#define CAN_ARBITRATION_LOST_ID26       ((uint32_t)0x2)
#define CAN_ARBITRATION_LOST_ID25       ((uint32_t)0x3)
#define CAN_ARBITRATION_LOST_ID24       ((uint32_t)0x4)
#define CAN_ARBITRATION_LOST_ID23       ((uint32_t)0x5)
#define CAN_ARBITRATION_LOST_ID22       ((uint32_t)0x6)
#define CAN_ARBITRATION_LOST_ID21       ((uint32_t)0x7)
#define CAN_ARBITRATION_LOST_ID20       ((uint32_t)0x8)
#define CAN_ARBITRATION_LOST_ID19       ((uint32_t)0x9)
#define CAN_ARBITRATION_LOST_ID18       ((uint32_t)0xA)
#define CAN_ARBITRATION_LOST_SRR        ((uint32_t)0xB)
#define CAN_ARBITRATION_LOST_IDE        ((uint32_t)0xC)
#define CAN_ARBITRATION_LOST_ID17       ((uint32_t)0xD)
#define CAN_ARBITRATION_LOST_ID16       ((uint32_t)0xE)
#define CAN_ARBITRATION_LOST_ID15       ((uint32_t)0xF)
#define CAN_ARBITRATION_LOST_ID14       ((uint32_t)0x10)
#define CAN_ARBITRATION_LOST_ID13       ((uint32_t)0x11)
#define CAN_ARBITRATION_LOST_ID12       ((uint32_t)0x12)
#define CAN_ARBITRATION_LOST_ID11       ((uint32_t)0x13)
#define CAN_ARBITRATION_LOST_ID10       ((uint32_t)0x14)
#define CAN_ARBITRATION_LOST_ID9        ((uint32_t)0x15)
#define CAN_ARBITRATION_LOST_ID8        ((uint32_t)0x16)
#define CAN_ARBITRATION_LOST_ID7        ((uint32_t)0x17)
#define CAN_ARBITRATION_LOST_ID6        ((uint32_t)0x18)
#define CAN_ARBITRATION_LOST_ID5        ((uint32_t)0x19)
#define CAN_ARBITRATION_LOST_ID4        ((uint32_t)0x1A)
#define CAN_ARBITRATION_LOST_ID3        ((uint32_t)0x1B)
#define CAN_ARBITRATION_LOST_ID2        ((uint32_t)0x1C)
#define CAN_ARBITRATION_LOST_ID1        ((uint32_t)0x1D)
#define CAN_ARBITRATION_LOST_ID0        ((uint32_t)0x1E)
#define CAN_ARBITRATION_LOST_RTR        ((uint32_t)0x1F)

/**
  * CAN֡��ʽ
  */
#define CAN_FRAME_FORMAT_SFF            ((uint32_t)0)
#define CAN_FRAME_FORMAT_EFF            ((uint32_t)1)
#define CHECK_CAN_FRAME_FORMAT(FORMAT)  (((FORMAT) == CAN_FRAME_FORMAT_SFF) \
                                      || ((FORMAT) == CAN_FRAME_FORMAT_EFF))

/**
  * CANԶ�̷�������
  */
#define CAN_DATA_FRAME                  ((uint32_t)0)
#define CAN_REMOTE_FRAME                ((uint32_t)1)
#define CHECK_CAN_REMOTE_REQUEST(SEL)   (((SEL) == CAN_DATA_FRAME) \
                                      || ((SEL) == CAN_REMOTE_FRAME))

/**
  * CAN���ݳ���
  */
#define CHECK_CAN_DATA_LENGTH(Length)   (((uint32_t)(Length)>>4) == 0)

/**
  * CANʶ����
  */
#define CHECK_CAN_SFF_ID(ID)            (((uint32_t)(ID)>>11) == 0)
#define CHECK_CAN_EFF_ID(ID)            (((uint32_t)(ID)>>29) == 0)

/**
  * CAN�ж��¼�
  */
#define CAN_INT_RECEIVE                 ((uint32_t)1<<0)
#define CAN_INT_TRANSMIT                ((uint32_t)1<<1)
#define CAN_INT_ERROR_ALARM             ((uint32_t)1<<2)
#define CAN_INT_DATA_OVERFLOW           ((uint32_t)1<<3)
#define CAN_INT_WAKE_UP                 ((uint32_t)1<<4)
#define CAN_INT_ERROR_NEGATIVE          ((uint32_t)1<<5)
#define CAN_INT_ARBITRATION_LOST        ((uint32_t)1<<6)
#define CAN_INT_BUS_ERROR               ((uint32_t)1<<7)
#define CHECK_CAN_INT_ONE_EVENT(INT)    (((INT) == CAN_INT_RECEIVE) \
                                      || ((INT) == CAN_INT_TRANSMIT) \
                                      || ((INT) == CAN_INT_ERROR_ALARM) \
                                      || ((INT) == CAN_INT_DATA_OVERFLOW) \
                                      || ((INT) == CAN_INT_WAKE_UP) \
                                      || ((INT) == CAN_INT_ERROR_NEGATIVE) \
                                      || ((INT) == CAN_INT_ARBITRATION_LOST) \
                                      || ((INT) == CAN_INT_BUS_ERROR))
#define CHECK_CAN_INT_EVENT(INT)        (((INT) & (~(CAN_INT_RECEIVE \
                                                    | CAN_INT_TRANSMIT \
                                                    | CAN_INT_ERROR_ALARM \
                                                    | CAN_INT_DATA_OVERFLOW \
                                                    | CAN_INT_WAKE_UP \
                                                    | CAN_INT_ERROR_NEGATIVE \
                                                    | CAN_INT_ARBITRATION_LOST \
                                                    | CAN_INT_BUS_ERROR))) == 0)

/**
  * CAN���յ�ַƫ��
  */
#define CHECK_CAN_RECEIVE_OFFSET(ADDR)  (((ADDR) == 0x00) \
                                      || ((ADDR) == 0x10) \
                                      || ((ADDR) == 0x20) \
                                      || ((ADDR) == 0x30) \
                                      || ((ADDR) == 0x40) \
                                      || ((ADDR) == 0x50) \
                                      || ((ADDR) == 0x60) \
                                      || ((ADDR) == 0x70) \
                                      || ((ADDR) == 0x80) \
                                      || ((ADDR) == 0x90) \
                                      || ((ADDR) == 0xA0) \
                                      || ((ADDR) == 0xB0) \
                                      || ((ADDR) == 0xC0) \
                                      || ((ADDR) == 0xD0) \
                                      || ((ADDR) == 0xE0) \
                                      || ((ADDR) == 0xF0))


#ifdef KF32A_Periph_can
/* ����������������(CAN)��ʼ����������**************************************/
void CAN_Reset(CAN_SFRmap* CANx);
void CAN_Configuration(CAN_SFRmap* CANx, CAN_InitTypeDef* canInitStruct);
void CAN_Struct_Init (CAN_InitTypeDef* canInitStruct);
/* ����������������(CAN)�������ú�������************************************/
uint32_t CAN_Get_Receive_Message_Counter (CAN_SFRmap* CANx);
FlagStatus CAN_Get_Transmit_Status (CAN_SFRmap* CANx, uint32_t Type);
void CAN_Cmd (CAN_SFRmap* CANx, FunctionalState NewState);
void CAN_Clock_Source_Config (CAN_SFRmap* CANx, uint32_t ClockSource);
void CAN_Sleep_Mode_Enable (CAN_SFRmap* CANx, FunctionalState NewState);
void CAN_Reset_Mode_Enable (CAN_SFRmap* CANx, FunctionalState NewState);
void CAN_Work_Mode_Config (CAN_SFRmap* CANx, uint32_t ModeType);
void CAN_Bus_Sample_Times_Config (CAN_SFRmap* CANx, uint32_t Times);
void CAN_Time_Segment_Config (CAN_SFRmap* CANx,
                    uint32_t TimeSeg1, uint32_t TimeSeg2);
void CAN_Sync_Jump_Width_Config (CAN_SFRmap* CANx, uint32_t JumpWidth);
void CAN_Baud_Rate_Preset_Config (CAN_SFRmap* CANx, uint32_t BaudRate);
void CAN_Get_Error_Code (CAN_SFRmap* CANx, CAN_ErrorTypeDef* canErrorStruct);
uint8_t CAN_Get_Error_Warning_Limit (CAN_SFRmap* CANx);
uint8_t CAN_Get_Error_Counter (CAN_SFRmap* CANx, uint32_t Direction);
void CAN_Error_Warning_Limit_Config (CAN_SFRmap* CANx, uint8_t ErrorLimit);
void CAN_Error_Counter_Config (CAN_SFRmap* CANx,
                    uint32_t Direction, uint8_t ErrorCounter);
void CAN_Acceptance_Config (CAN_SFRmap* CANx, uint32_t Acceptance);
uint32_t CAN_Get_Acceptance (CAN_SFRmap* CANx);
void CAN_Acceptance_Mask_Config (CAN_SFRmap* CANx, uint32_t Acceptance);
uint32_t CAN_Get_Acceptance_Mask (CAN_SFRmap* CANx);
/* ����������������(CAN)���ͽ��պ�������************************************/
void CAN_Transmit_Message_Configuration (CAN_SFRmap* CANx,
                    CAN_MessageTypeDef* canInitStruct);
void CAN_Receive_Message_Configuration (CAN_SFRmap* CANx,
                    uint32_t ReceiveOffset, CAN_MessageTypeDef* canInitStruct);
void CAN_Message_Struct_Init (CAN_MessageTypeDef* canInitStruct);
void CAN_Clear_Buffer_Overflow_Flag (CAN_SFRmap* CANx);
void CAN_Release_Receive_Buffer (CAN_SFRmap* CANx, uint32_t ReleaseCount);
void CAN_Transmit_Single  (CAN_SFRmap* CANx);
void CAN_Transmit_Repeat (CAN_SFRmap* CANx);
void CAN_Frame_Format_Config (CAN_SFRmap* CANx, uint32_t FrameFormat);
void CAN_Remote_Request_Config (CAN_SFRmap* CANx, uint32_t RemoteRequest);
void CAN_Data_Length_Config (CAN_SFRmap* CANx, uint32_t Length);
void CAN_Identification_Code_Config (CAN_SFRmap* CANx,
                    uint32_t FrameFormat, uint32_t IDCode);
/* ����������������(CAN)�жϹ���������************************************/
FlagStatus CAN_Get_INT_Flag (CAN_SFRmap* CANx, uint32_t InterruptType);
void CAN_Clear_INT_Flag (CAN_SFRmap* CANx, uint32_t InterruptType);
void CAN_Set_INT_Enable (CAN_SFRmap* CANx,
                    uint32_t InterruptType, FunctionalState NewState);
#endif //KF32A_Periph_can
#endif /* _KF32A_BASIC_CAN_H */
