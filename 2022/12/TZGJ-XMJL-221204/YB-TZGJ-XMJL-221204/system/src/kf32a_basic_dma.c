/**
  ******************************************************************************
  * �ļ���  kf32a_basic_dma.c
  * ��  ��  ChipON_AE/FAE_Group
  * ��  ��  V2.62
  * ��  ��  2019-11-16
  * ��  ��  ���ļ��ṩ��DMAģ��(DMA)��صĹ��ܺ�����������
  *          + DMAģ��(DMA)��ʼ������
  *          + DMAģ��(DMA)�������ú���
  *          + DMAģ��(DMA)�жϹ�����
  *
  *********************************************************************
  */

#include "kf32a_basic_dma.h"
#include "kf32a_basic_rst.h"
#include "kf32a_basic_pclk.h"


/* ��ʱ��˽�ж��� ----------------------------------------------------*/
/* DMA_CTLRy�Ĵ�����ʼ������ */
#define DMA_CTLR_INIT_MASK              (DMA_CTLR_NUMODT \
                                       | DMA_CTLR_CPL \
                                       | DMA_CTLR_PDS \
                                       | DMA_CTLR_MDS \
                                       | DMA_CTLR_PINC \
                                       | DMA_CTLR_MINC \
                                       | DMA_CTLR_LPM \
                                       | DMA_CTLR_DDIR \
                                       | DMA_CTLR_BLKM)

/**
  *   ##### DMAģ��(DMA)��ʼ������ #####
  */
/**
  * ����  ��λDMA���裬ʹ������ʱ�ӡ�
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  * ����  �ޡ�
  */
void
DMA_Reset (DMA_SFRmap* DMAx)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
#ifdef KF32A_Periph_dma0
    if (DMAx == DMA0_SFR)
    {
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_DMA0RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_DMA0RST, FALSE);
        PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_DMA0CLKEN, TRUE);
    }
#endif
#ifdef KF32A_Periph_dma1
    if (DMAx == DMA1_SFR)
    {
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_DMA1RST, TRUE);
        RST_CTL2_Peripheral_Reset_Enable(RST_CTL2_DMA1RST, FALSE);
        PCLK_CTL2_Peripheral_Clock_Enable(PCLK_CTL2_DMA1CLKEN, TRUE);
    }
#endif
}

/**
  * ����  DMAģ��(DMA)��ʼ�����á�
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       dmaInitStruct: DMAģ��������Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void
DMA_Configuration (DMA_SFRmap* DMAx,
                    DMA_InitTypeDef* dmaInitStruct)
{
    uint32_t tmpreg = 0;
    uint32_t tmpchannel = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(dmaInitStruct->m_Channel));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL_PRIORITY(dmaInitStruct->m_Priority));
    CHECK_RESTRICTION(CHECK_DMA_DIRECTION(dmaInitStruct->m_Direction));
    CHECK_RESTRICTION(CHECK_DMA_DATA_WIDTH(dmaInitStruct->m_PeripheralDataSize));
    CHECK_RESTRICTION(CHECK_DMA_DATA_WIDTH(dmaInitStruct->m_MemoryDataSize));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(dmaInitStruct->m_PeripheralInc));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(dmaInitStruct->m_MemoryInc));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(dmaInitStruct->m_LoopMode));
    CHECK_RESTRICTION(CHECK_DMA_TRANSFER_MODE(dmaInitStruct->m_BlockMode));

    tmpchannel = dmaInitStruct->m_Channel;

    /*---------------- ����DMAx_CTLRy�Ĵ��� ----------------*/
    /* ���ݽṹ���Աm_Number������NUMODTλ�� */
    /* ���ݽṹ���Աm_Priority������CPLλ�� */
    /* ���ݽṹ���Աm_PeripheralDataSize������PDSλ�� */
    /* ���ݽṹ���Աm_MemoryDataSize������MDSλ�� */
    /* ���ݽṹ���Աm_PeripheralInc������PINCλ�� */
    /* ���ݽṹ���Աm_MemoryInc������MINCλ�� */
    /* ���ݽṹ���Աm_LoopMode������LPMλ�� */
    /* ���ݽṹ���Աm_Direction������DDIRλ�� */
    /* ���ݽṹ���Աm_BlockMode������BLKMλ�� */
    tmpreg = ((uint32_t)dmaInitStruct->m_Number << DMA_CTLR_NUMODT0_POS) \
           | ((uint32_t)dmaInitStruct->m_Priority) \
           | ((uint32_t)dmaInitStruct->m_PeripheralDataSize << DMA_CTLR_PDS0_POS) \
           | ((uint32_t)dmaInitStruct->m_MemoryDataSize << DMA_CTLR_MDS0_POS) \
           | (dmaInitStruct->m_PeripheralInc << DMA_CTLR_PINC_POS) \
           | (dmaInitStruct->m_MemoryInc << DMA_CTLR_MINC_POS) \
           | (dmaInitStruct->m_LoopMode << DMA_CTLR_LPM_POS) \
           | ((uint32_t)dmaInitStruct->m_Direction) \
           | (dmaInitStruct->m_BlockMode);
    DMAx->CTLR[tmpchannel] = SFR_Config (DMAx->CTLR[tmpchannel],
                          ~DMA_CTLR_INIT_MASK,
                          tmpreg);

    /*--------- ����DMAx_PADDRy�����ַ�Ĵ��� ---------*/
    DMAx->PADDR[tmpchannel] = dmaInitStruct->m_PeriphAddr;

    /*--------- ����DMAx_MADDRy�����ַ�Ĵ��� ---------*/
    DMAx->MADDR[tmpchannel] = dmaInitStruct->m_MemoryAddr;
}

/**
  * ����  ��ʼ��DMA������Ϣ�ṹ�塣
  * ����  dmaInitStruct: ָ�����ʼ���Ľṹ��ָ�롣
  * ����  �ޡ�
  */
void
DMA_Struct_Init (DMA_InitTypeDef* dmaInitStruct)
{
    /* ��ʼ�� DMAͨ��ѡ�� */
    dmaInitStruct->m_Channel = DMA_CHANNEL_1;
    /* ��ʼ�� DMAͨ�����ȼ� */
    dmaInitStruct->m_Priority = DMA_CHANNEL_LOWER;
    /* ��ʼ�� DMA���䷽�� */
    dmaInitStruct->m_Direction = DMA_PERIPHERAL_TO_MEMORY;
    /* ��ʼ�� ��������λ�� */
    dmaInitStruct->m_PeripheralDataSize = DMA_DATA_WIDTH_8_BITS;
    /* ��ʼ�� �洢������λ�� */
    dmaInitStruct->m_MemoryDataSize = DMA_DATA_WIDTH_8_BITS;
    /* ��ʼ�� �������ݸ��� */
    dmaInitStruct->m_Number = 0;
    /* ��ʼ�� �����ַ����ģʽʹ�� */
    dmaInitStruct->m_PeripheralInc = FALSE;
    /* ��ʼ�� �洢����ַ����ģʽʹ�� */
    dmaInitStruct->m_MemoryInc = FALSE;
    /* ��ʼ�� ѭ��ģʽʹ�� */
    dmaInitStruct->m_LoopMode = FALSE;
    /* ��ʼ�� ���ݿ鴫��ģʽ */
    dmaInitStruct->m_BlockMode = DMA_TRANSFER_BYTE;
    /* ��ʼ�� ������ʼ��ַ */
    dmaInitStruct->m_PeriphAddr = 0;
    /* ��ʼ�� �ڴ���ʼ��ַ */
    dmaInitStruct->m_MemoryAddr = 0;
}
/**
  *   ##### DMAģ��(DMA)��ʼ������������� #####
  */


/**
  *   ##### DMAģ��(DMA)�������ú��� #####
  */
/**
  * ����  ����DMA�������������
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       Number: ��Ҫ��������ݸ�����ȡֵ��ΧΪ0~65535��
  * ����  �ޡ�
  */
void
DMA_Transfer_Number_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint16_t Number)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));

    /*---------------- ����DMA_CTLR�Ĵ���NUMODTλ ----------------*/
    tmpreg = (uint32_t)Number << DMA_CTLR_NUMODT0_POS;
    DMAx->CTLR[Channel] = SFR_Config (DMAx->CTLR[Channel],
                                ~DMA_CTLR_NUMODT,
                                tmpreg);
}

/**
  * ����  ���ô洢�����洢������ʹ�ܡ�
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       NewState: �洢�����洢������ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
DMA_Memory_To_Memory_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����DMA_CTLR�Ĵ���M2Mλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ�ܴ洢�����洢������ */
        SFR_SET_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_M2M_POS);
    }
    else
    {
        /* δʹ�ܴ洢�����洢������ */
        SFR_CLR_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_M2M_POS);
    }
}

/**
  * ����  ����DMAͨ�����ȼ���
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       Priority: ͨ�����ȼ���ȡֵΪ��
  *                   DMA_CHANNEL_LOWER: �����ȼ�
  *                   DMA_CHANNEL_MEDIUM: �����ȼ�
  *                   DMA_CHANNEL_HIGHER: �����ȼ�
  *                   DMA_CHANNEL_TOP: ������ȼ�
  * ����  �ޡ�
  */
void
DMA_Channel_Priority_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Priority)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL_PRIORITY(Priority));

    /*---------------- ����DMA_CTLR�Ĵ���CPLλ ----------------*/
    tmpreg = (uint32_t)Priority << DMA_CTLR_CPL0_POS;
    DMAx->CTLR[Channel] = SFR_Config (DMAx->CTLR[Channel],
                                ~DMA_CTLR_CPL,
                                tmpreg);
}

/**
  * ����  ����DMA��������λ��
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       Width: ��������λ��ȡֵΪ��
  *                DMA_DATA_WIDTH_8_BITS: ����Ϊ8λ��
  *                DMA_DATA_WIDTH_16_BITS: ����Ϊ16λ��
  *                DMA_DATA_WIDTH_32_BITS: ����Ϊ32λ��
  * ����  �ޡ�
  */
void
DMA_Peripheral_Data_Width_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Width)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_DMA_DATA_WIDTH(Width));

    /*---------------- ����DMA_CTLR�Ĵ���PDSλ ----------------*/
    tmpreg = Width << DMA_CTLR_PDS0_POS;
    DMAx->CTLR[Channel] = SFR_Config (DMAx->CTLR[Channel],
                                ~DMA_CTLR_PDS,
                                tmpreg);
}

/**
  * ����  ����DMA�洢������λ��
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       Width: �洢������λ��ȡֵΪ��
  *                DMA_DATA_WIDTH_8_BITS: ����Ϊ8λ��
  *                DMA_DATA_WIDTH_16_BITS: ����Ϊ16λ��
  *                DMA_DATA_WIDTH_32_BITS: ����Ϊ32λ��
  * ����  �ޡ�
  */
void
DMA_Memory_Data_Width_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Width)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_DMA_DATA_WIDTH(Width));

    /*---------------- ����DMA_CTLR�Ĵ���MDSλ ----------------*/
    tmpreg = Width << DMA_CTLR_MDS0_POS;
    DMAx->CTLR[Channel] = SFR_Config (DMAx->CTLR[Channel],
                                ~DMA_CTLR_MDS,
                                tmpreg);
}

/**
  * ����  ���������ַ����ģʽʹ�ܡ�
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       NewState: �����ַ����ģʽʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
DMA_Peripheral_addr_increase_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����DMA_CTLR�Ĵ���PINCλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ�������ַ����ģʽ */
        SFR_SET_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_PINC_POS);
    }
    else
    {
        /* δʹ�������ַ����ģʽ */
        SFR_CLR_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_PINC_POS);
    }
}

/**
  * ����  ���ô洢����ַ����ģʽʹ�ܡ�
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       NewState: �洢����ַ����ģʽʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
DMA_Memory_addr_increase_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����DMA_CTLR�Ĵ���MINCλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ�ܴ洢����ַ����ģʽ */
        SFR_SET_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_MINC_POS);
    }
    else
    {
        /* δʹ�ܴ洢����ַ����ģʽ */
        SFR_CLR_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_MINC_POS);
    }
}

/**
  * ����  ����ѭ��ģʽʹ�ܡ�
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       NewState: ѭ��ģʽʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
DMA_Loop_Mode_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����DMA_CTLR�Ĵ���LPMλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��ѭ��ģʽ */
        SFR_SET_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_LPM_POS);
    }
    else
    {
        /* δʹ��ѭ��ģʽ */
        SFR_CLR_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_LPM_POS);
    }
}

/**
  * ����  �������ݷ�����ơ�
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       Direction: ���ݷ������״̬��ȡֵΪ��
  *                    DMA_PERIPHERAL_TO_MEMORY: ���ݴ������ַ��ȡ������洢����ַ
  *                    DMA_MEMORY_TO_PERIPHERAL: ���ݴӴ洢����ַ��ȡ�����������ַ
  * ����  �ޡ�
  */
void
DMA_Transfer_Direction_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Direction)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_DMA_DIRECTION(Direction));

    /*---------------- ����DMA_CTLR�Ĵ���DDIRλ ----------------*/
    if (Direction != DMA_PERIPHERAL_TO_MEMORY)
    {
        /* ���ݴӴ洢����ַ��ȡ�����������ַ */
        SFR_SET_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_DDIR_POS);
    }
    else
    {
        /* ���ݴ������ַ��ȡ������洢����ַ */
        SFR_CLR_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_DDIR_POS);
    }
}

/**
  * ����  �������ݿ鴫��ģʽ��
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       BlockMode: ���ݿ鴫��ģʽ��ȡֵΪ��
  *                    DMA_TRANSFER_BYTE: ���ݰ����ֽڴ���
  *                    DMA_TRANSFER_BLOCK: ���ݰ��տ鴫��
  * ����  �ޡ�
  */
void
DMA_Transfer_Mode_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t BlockMode)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_DMA_TRANSFER_MODE(BlockMode));

    /*---------------- ����DMA_CTLR�Ĵ���BLKMλ ----------------*/
    if (BlockMode != DMA_TRANSFER_BYTE)
    {
        /* ���ݰ��տ鴫�� */
        SFR_SET_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_BLKM_POS);
    }
    else
    {
        /* ���ݰ����ֽڴ��� */
        SFR_CLR_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_BLKM_POS);
    }
}

/**
  * ����  ����DMAͨ�����δ���ģʽʹ�ܡ�
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       NewState: DMAͨ��Channelʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
DMA_Oneshot_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����DMA_CTLR�Ĵ���DMAENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��DMA���δ��� */
        SFR_SET_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_ONESHOT_POS);
    }
    else
    {
        /* δʹ��DMA���δ��� */
        SFR_CLR_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_ONESHOT_POS);
    }
}
/**
  * ����  ����DMAͨ��Channelʹ�ܡ�
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       NewState: DMAͨ��Channelʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
DMA_Channel_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����DMA_CTLR�Ĵ���DMAENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��DMAͨ��Channel */
        SFR_SET_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_DMAEN_POS);
    }
    else
    {
        /* δʹ��DMAͨ��Channel */
        SFR_CLR_BIT_ASM(DMAx->CTLR[Channel], DMA_CTLR_DMAEN_POS);
    }
}

/**
  * ����  ����DMAͨ������ʼ�����ַ��
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       Address: DMAͨ������ʼ�����ַ��ȡֵΪ32λ��Ч��ֵ��
  * ����  �ޡ�
  */
void
DMA_Peripheral_Start_Address_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Address)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));

    /*---------------- ����DMA_PADDR�Ĵ���PADDRλ ----------------*/
    DMAx->PADDR[Channel] = Address;
}

/**
  * ����  ����DMAͨ������ʼ�洢����ַ��
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       Address: DMAͨ������ʼ�洢����ַ��ȡֵΪ32λ��Ч��ֵ��
  * ����  �ޡ�
  */
void
DMA_Memory_Start_Address_Config (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t Address)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));

    /*---------------- ����DMA_MADDR�Ĵ���MADDRλ ----------------*/
    DMAx->MADDR[Channel] = Address;
}

/**
  * ����  ��ȡDMAͨ���ĵ�ǰ�����ַ��
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  * ����  DMAͨ���ĵ�ǰ�����ַ��ȡֵΪ32λ��Ч��ֵ��
  */
uint32_t
DMA_Get_Peripheral_Current_Address (DMA_SFRmap* DMAx, uint32_t Channel)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));

    /*---------------- ��ȡDMA_CPAR�Ĵ���CPARλ ----------------*/
    tmpreg = DMAx->CPAR[Channel];
    return tmpreg;
}

/**
  * ����  ��ȡDMAͨ���ĵ�ǰ�洢����ַ��
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  * ����  DMAͨ���ĵ�ǰ�洢����ַ��ȡֵΪ32λ��Ч��ֵ��
  */
uint32_t
DMA_Get_Memory_Current_Address (DMA_SFRmap* DMAx, uint32_t Channel)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));

    /*---------------- ��ȡDMA_CMAR�Ĵ���CMARλ ----------------*/
    tmpreg = DMAx->CMAR[Channel];
    return tmpreg;
}

/**
  * ����  ��ȡDMAͨ���ĵ�ǰʣ����������
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  * ����  DMAͨ���ĵ�ǰʣ����������ȡֵΪ16λ��Ч��ֵ��
  */
uint16_t
DMA_Get_Transfer_Number_Remain (DMA_SFRmap* DMAx, uint32_t Channel)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));

    /*---------------- ��ȡDMA_NCT�Ĵ���NCTλ ----------------*/
    tmpreg = DMAx->NCT[Channel] & DMA_NCT_NCT;
    tmpreg >>= DMA_NCT_NCT16_POS;

    return (uint16_t)tmpreg;
}
/**
  *   ##### DMAģ��(DMA)�������ú���������� #####
  */


/**
  *   ##### DMAģ��(DMA)�жϹ����� #####
  */
/**
  * ����  ��ȡDMAͨ�������жϱ�־��
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       InterruptType: DMAͨ���ж����ͣ�ȡֵ��ΧΪ:
  *                        DMA_INT_FINISH_TRANSFER: ��ɴ����ж�
  *                        DMA_INT_HALF_TRANSFER: �봫���ж�
  *                        DMA_INT_ERROR_TRANSFER: �������ж�
  * ����  1:���䷢������0:�����޴���
  */
FlagStatus
DMA_Get_INT_Flag (DMA_SFRmap* DMAx, uint32_t Channel, uint32_t InterruptType)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_DMA_INT_ONE_TYPE(InterruptType));

    /* �����жϱ�־���� */
    tmpreg = InterruptType << (Channel * 3);
    /*---------------- ��ȡDMA_LIFR�Ĵ����жϱ�־λ ----------------*/
    if (DMAx->LIFR & tmpreg)
    {
        /* ���䷢������ */
        return SET;
    }
    else
    {
        /* �����޴��� */
        return RESET;
    }
}

/**
  * ����  ����DMAͨ�������жϱ�־��
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       InterruptType: DMAͨ���ж����ͣ�ȡֵ��ΧΪ�����ṩ��һ���������:
  *                        DMA_INT_FINISH_TRANSFER: ��ɴ����ж�
  *                        DMA_INT_HALF_TRANSFER: �봫���ж�
  *                        DMA_INT_ERROR_TRANSFER: �������ж�
  * ����  �ޡ�
  */
void
DMA_Clear_INT_Flag (DMA_SFRmap* DMAx,
                    uint32_t Channel, uint32_t InterruptType)
{
    uint32_t tmpmask = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_DMA_INT_TYPE(InterruptType));

    /*---------------- ����DMA_LIFR�Ĵ����жϱ�־λ ----------------*/
    tmpmask = InterruptType << (Channel * 3);
    DMAx->LIFR &= ~tmpmask;
}

/**
  * ����  ����DMAͨ�������ж�ʹ�ܡ�
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       InterruptType: DMAͨ���ж����ͣ�ȡֵ��ΧΪ�����ṩ��һ���������:
  *                        DMA_INT_FINISH_TRANSFER: ��ɴ����ж�
  *                        DMA_INT_HALF_TRANSFER: �봫���ж�
  *                        DMA_INT_ERROR_TRANSFER: �������ж�
  *       NewState: DMAͨ���������ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
DMA_Set_INT_Enable (DMA_SFRmap* DMAx, uint32_t Channel,
                    uint32_t InterruptType, FunctionalState NewState)
{
    uint32_t tmpmask = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_DMA_INT_TYPE(InterruptType));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����DMA_LIER�Ĵ����ж�ʹ��λ ----------------*/
    tmpmask = InterruptType << (Channel * 3);
    if (NewState != FALSE)
    {
        DMAx->LIER |= tmpmask;
    }
    else
    {
        DMAx->LIER &= ~tmpmask;
    }
}

/**
  * ����  ��ȡDMAͨ���������жϱ�־��
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  * ����  1:���䷢������0:�����޴���
  */
FlagStatus
DMA_Get_Error_Transfer_INT_Flag (DMA_SFRmap* DMAx, uint32_t Channel)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));

    tmpreg = DMA_LIFR_ETIF1 << (Channel * 3);
    /*---------------- ��ȡDMA_LIFR�Ĵ���ETIFyλ ----------------*/
    if (DMAx->LIFR & tmpreg)
    {
        /* ���䷢������ */
        return SET;
    }
    else
    {
        /* �����޴��� */
        return RESET;
    }
}

/**
  * ����  ��ȡDMAͨ���봫���жϱ�־��
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  * ����  1:���������һ�룬0:����δ���һ�롣
  */
FlagStatus
DMA_Get_Half_Transfer_INT_Flag (DMA_SFRmap* DMAx, uint32_t Channel)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));

    tmpreg = DMA_LIFR_HTIF1 << (Channel * 3);
    /*---------------- ��ȡDMA_LIFR�Ĵ���HTIFyλ ----------------*/
    if (DMAx->LIFR & tmpreg)
    {
        /* ���������һ�� */
        return SET;
    }
    else
    {
        /* ����δ���һ�� */
        return RESET;
    }
}

/**
  * ����  ��ȡDMAͨ����ɴ����жϱ�־��
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  * ����  1:��������ɣ�0:����δ��ɡ�
  */
FlagStatus
DMA_Get_Finish_Transfer_INT_Flag (DMA_SFRmap* DMAx, uint32_t Channel)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));

    tmpreg = DMA_LIFR_FTIF1 << (Channel * 3);
    /*---------------- ��ȡDMA_LIFR�Ĵ���FTIFyλ ----------------*/
    if (DMAx->LIFR & tmpreg)
    {
        /* ��������� */
        return SET;
    }
    else
    {
        /* ����δ��� */
        return RESET;
    }
}

/**
  * ����  ����DMAͨ���������ж�ʹ�ܡ�
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       NewState: DMAͨ���������ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
DMA_Error_Transfer_INT_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{
    uint32_t tmpmask = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����DMA_LIER�Ĵ���ETIEyλ ----------------*/
    tmpmask = DMA_LIER_ETIE1 << (Channel * 3);
    if (NewState != FALSE)
    {
        DMAx->LIER |= tmpmask;
    }
    else
    {
        DMAx->LIER &= ~tmpmask;
    }
}

/**
  * ����  ����DMAͨ���봫���ж�ʹ�ܡ�
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       NewState: DMAͨ���봫���ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
DMA_Half_Transfer_INT_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{
    uint32_t tmpmask = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����DMA_LIER�Ĵ���HTIEyλ ----------------*/
    tmpmask = DMA_LIER_HTIE1 << (Channel * 3);
    if (NewState != FALSE)
    {
        DMAx->LIER |= tmpmask;
    }
    else
    {
        DMAx->LIER &= ~tmpmask;
    }
}

/**
  * ����  ����DMAͨ����ɴ����ж�ʹ�ܡ�
  * ����  DMAx: ָ��DMA�ڴ�ṹ��ָ�룬ȡֵΪDMA0_SFR��DMA1_SFR��
  *       Channel: DMAͨ��ѡ��ȡֵ��ΧΪ:
  *                  DMA_CHANNEL_1: ͨ��1
  *                  DMA_CHANNEL_2: ͨ��2
  *                  DMA_CHANNEL_3: ͨ��3
  *                  DMA_CHANNEL_4: ͨ��4
  *                  DMA_CHANNEL_5: ͨ��5
  *                  DMA_CHANNEL_6: ͨ��6
  *                  DMA_CHANNEL_7: ͨ��7
  *       NewState: DMAͨ����ɴ����ж�ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void
DMA_Finish_Transfer_INT_Enable (DMA_SFRmap* DMAx,
                    uint32_t Channel, FunctionalState NewState)
{
    uint32_t tmpmask = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_DMA_ALL_PERIPH(DMAx));
    CHECK_RESTRICTION(CHECK_DMA_CHANNEL(Channel));
    CHECK_RESTRICTION(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����DMA_LIER�Ĵ���FTIEyλ ----------------*/
    tmpmask = DMA_LIER_FTIE1 << (Channel * 3);
    if (NewState != FALSE)
    {
        DMAx->LIER |= tmpmask;
    }
    else
    {
        DMAx->LIER &= ~tmpmask;
    }
}
/**
  *   ##### DMAģ��(DMA)�жϹ������������ #####
  */
