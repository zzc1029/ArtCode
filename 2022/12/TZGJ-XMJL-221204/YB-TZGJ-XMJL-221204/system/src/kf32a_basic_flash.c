/**
  ******************************************************************************
  * �ļ���  kf32a_basic_flash.c
  * ��  ��  ChipON_AE/FAE_Group
  * ��  ��  V2.62
  * ��  ��  2019-11-16
  * ��  ��  ���ļ��ṩ��FLASH����洢��(FLASH)��صĹ��ܺ�����������
  *          + FLASH����洢��(FLASH)�������ú���
  *          + FLASH����洢��(FLASH)��̹��ܺ���
  *
  *ע�⣺ʹ��Ƭ�����ܺ�FLASH����գ�ԭ�г���ʧ���޷�����FLASH
  *ע�⣺ʹ��ҳ�����ܺ���ȷ���Ƿ�����˺��ڵ��ú�����FLASH�����Ѳ��������޷�����FLASH
  *********************************************************************
  */

#include "kf32a_basic_flash.h"


/* ��ʱ��˽�ж��� ----------------------------------------------------*/
/* FLASH_ISPCON0���ƼĴ���д������16λֵ */
#define FLASH_ISPCON0_HIGH              ((uint32_t)0x50AF0000)
#define FLASH_ISPCON0_HIGH_MSK          ((uint32_t)0xFFFF0000)

/* FLASH_ISPCON1���ƼĴ���д������16λֵ */
#define FLASH_ISPCON1_HIGH              ((uint32_t)0xA05F0000)
#define FLASH_ISPCON1_HIGH_MSK          ((uint32_t)0xFFFF0000)

/* FLASH_ISPTRG���ƼĴ���д������16λֵ */
#define FLASH_ISPTRG_HIGH               ((uint32_t)0x50AF0000)
#define FLASH_ISPTRG_HIGH_MSK           ((uint32_t)0xFFFF0000)

/* FLASH_NVMUNLOCK�Ĵ����������� */
#define FLASH_NVMUNLOCK_KEY1            ((uint32_t)0x87654321)
#define FLASH_NVMUNLOCK_KEY2            ((uint32_t)0x05040302)

/* FLASH_PROUNLOCK�Ĵ����������� */
#define FLASH_PROUNLOCK_KEY1            ((uint32_t)0x789ABCDE)
#define FLASH_PROUNLOCK_KEY2            ((uint32_t)0x16151413)

/* FLASH_CFGUNLOCK�Ĵ����������� */
#define FLASH_CFGUNLOCK_KEY1            ((uint32_t)0x879A43DE)
#define FLASH_CFGUNLOCK_KEY2            ((uint32_t)0x27262524)


/**
  *   ##### FLASH����洢��(FLASH)�������ú��� #####
  */

void __attribute__((section(".indata")))
CHECK_RESTRICTION_RAM(int expr)
{
	while(!expr)
		;
}

/* д���⹦�ܼĴ���RAM */
static inline uint32_t   __attribute__((section(".indata")))
SFR_Config_RAM (uint32_t SfrMem, uint32_t SfrMask, uint32_t WriteVal)
{
    return ((SfrMem & SfrMask) | (WriteVal));
}

/**
  * ����  ��FLASH����������״̬��
  * ����  �ޡ�
  * ����  ����״̬��1������״̬��0������״̬��
  */
LockStatus __attribute__((section(".indata")))
FLASH_Get_NonVolatile_Memory_Unlock_Status_RAM (void)
{
    if (FLASH_ISPCON0 & FLASH_ISPCON0_NVMLOCK)
    {
        /* ����״̬ */
        return UNLOCK;
    }
    else
    {
        /* ����״̬ */
        return LOCK;
    }
}

/**
  * ����  ����FLASH����������״̬λ��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Clear_NonVolatile_Memory_Unlock_Status_RAM (void)
{
    uint32_t tmpreg = 0;

    /*---------------- ����FLASH_ISPCON0�Ĵ���NVMLOCKλ ----------------*/
    tmpreg = FLASH_ISPCON0_HIGH | FLASH_ISPCON0_NVMLOCK;
    FLASH_ISPCON0 = SFR_Config_RAM (FLASH_ISPCON0,
                        ~(FLASH_ISPCON0_HIGH_MSK | FLASH_ISPCON0_NVMLOCK),
                        tmpreg);
}
/**
  * ����  ����FLASH����������״̬λ��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void
FLASH_Clear_NonVolatile_Memory_Unlock_Status (void)
{
    uint32_t tmpreg = 0;

    /*---------------- ����FLASH_ISPCON0�Ĵ���NVMLOCKλ ----------------*/
    tmpreg = FLASH_ISPCON0_HIGH | FLASH_ISPCON0_NVMLOCK;
    FLASH_ISPCON0 = SFR_Config (FLASH_ISPCON0,
                        ~(FLASH_ISPCON0_HIGH_MSK | FLASH_ISPCON0_NVMLOCK),
                        tmpreg);
}
/**
  * ����  ��λFLASH����������״̬λ������ISP�Ĵ�����
  * ����  �ޡ�
  * ����  �ޡ�
  */
void  __attribute__((section(".indata")))
FLASH_Unlock_ISP_RAM   (void)
{
    /* д��KEY1 �� KEY2 */
    FLASH_NVMUNLOCK = FLASH_NVMUNLOCK_KEY1;
    FLASH_NVMUNLOCK = FLASH_NVMUNLOCK_KEY2;
}

/**
  * ����  ��λFLASH����������״̬λ������ISP�Ĵ�����
  * ����  �ޡ�
  * ����  �ޡ�
  */
void
FLASH_Unlock_ISP   (void)
{
    /* д��KEY1 �� KEY2 */
    FLASH_NVMUNLOCK = FLASH_NVMUNLOCK_KEY1;
    FLASH_NVMUNLOCK = FLASH_NVMUNLOCK_KEY2;
}
/**
  * ����  ��FLASH����״̬��
  * ����  �ޡ�
  * ����  ����״̬��1������״̬��0������״̬��
  */
LockStatus __attribute__((section(".indata")))
FLASH_Get_Flash_Unlock_Status_RAM (void)
{
    if (FLASH_ISPCON0 & FLASH_ISPCON0_FLASHLOCK)
    {
        /* ����״̬ */
        return UNLOCK;
    }
    else
    {
        /* ����״̬ */
        return LOCK;
    }
}

/**
  * ����  ����FLASH����״̬λ��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Clear_Flash_Unlock_Status_RAM (void)
{
    uint32_t tmpreg = 0;

    /*---------------- ����FLASH_ISPCON0�Ĵ���FLASHLOCKλ ----------------*/
    tmpreg = FLASH_ISPCON0_HIGH | FLASH_ISPCON0_FLASHLOCK;
    FLASH_ISPCON0 = SFR_Config_RAM (FLASH_ISPCON0,
                        ~(FLASH_ISPCON0_HIGH_MSK | FLASH_ISPCON0_FLASHLOCK),
                        tmpreg);
}
/**
  * ����  ����FLASH����״̬λ��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void
FLASH_Clear_Flash_Unlock_Status (void)
{
    uint32_t tmpreg = 0;

    /*---------------- ����FLASH_ISPCON0�Ĵ���FLASHLOCKλ ----------------*/
    tmpreg = FLASH_ISPCON0_HIGH | FLASH_ISPCON0_FLASHLOCK;
    FLASH_ISPCON0 = SFR_Config (FLASH_ISPCON0,
                        ~(FLASH_ISPCON0_HIGH_MSK | FLASH_ISPCON0_FLASHLOCK),
                        tmpreg);
}
/**
  * ����  ��λFLASH����״̬λ������FLASH��������
  * ����  �ޡ�
  * ����  �ޡ�
  */
void  __attribute__((section(".indata")))
FLASH_Unlock_Code_RAM (void)
{
    /* д��KEY1 �� KEY2 */
    FLASH_PROUNLOCK = FLASH_PROUNLOCK_KEY1;
    FLASH_PROUNLOCK = FLASH_PROUNLOCK_KEY2;
}

/**
  * ����  ��λFLASH����״̬λ������FLASH��������
  * ����  �ޡ�
  * ����  �ޡ�
  */
void
FLASH_Unlock_Code (void)
{
    /* д��KEY1 �� KEY2 */
    FLASH_PROUNLOCK = FLASH_PROUNLOCK_KEY1;
    FLASH_PROUNLOCK = FLASH_PROUNLOCK_KEY2;
}
/**
  * ����  ��FLASH����������״̬��
  * ����  �ޡ�
  * ����  ����״̬��1������״̬��0������״̬��
  */
LockStatus __attribute__((section(".indata")))
FLASH_Get_Config_Unlock_Status_RAM (void)
{
    if (FLASH_ISPCON0 & FLASH_ISPCON0_CFGLOCK)
    {
        /* ����״̬ */
        return UNLOCK;
    }
    else
    {
        /* ����״̬ */
        return LOCK;
    }
}

/**
  * ����  ����FLASH����������״̬λ��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Clear_Config_Unlock_Status_RAM (void)
{
    uint32_t tmpreg = 0;

    /*---------------- ����FLASH_ISPCON0�Ĵ���CFGLOCKλ ----------------*/
    tmpreg = FLASH_ISPCON0_HIGH | FLASH_ISPCON0_CFGLOCK;
    FLASH_ISPCON0 = SFR_Config_RAM (FLASH_ISPCON0,
                        ~(FLASH_ISPCON0_HIGH_MSK | FLASH_ISPCON0_CFGLOCK),
                        tmpreg);
}
/**
  * ����  ����FLASH����������״̬λ��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void
FLASH_Clear_Config_Unlock_Status (void)
{
    uint32_t tmpreg = 0;

    /*---------------- ����FLASH_ISPCON0�Ĵ���CFGLOCKλ ----------------*/
    tmpreg = FLASH_ISPCON0_HIGH | FLASH_ISPCON0_CFGLOCK;
    FLASH_ISPCON0 = SFR_Config (FLASH_ISPCON0,
                        ~(FLASH_ISPCON0_HIGH_MSK | FLASH_ISPCON0_CFGLOCK),
                        tmpreg);
}
/**
  * ����  ��λFLASH����������״̬λ���û���������
  * ����  �ޡ�
  * ����  �ޡ�
  */
void  __attribute__((section(".indata")))
FLASH_Unlock_User_Config_RAM (void)
{
    /* д��KEY1 �� KEY2 */
    FLASH_CFGUNLOCK = FLASH_CFGUNLOCK_KEY1;
    FLASH_CFGUNLOCK = FLASH_CFGUNLOCK_KEY2;
}

/**
  * ����  ��λFLASH����������״̬λ���û���������
  * ����  �ޡ�
  * ����  �ޡ�
  */
void
FLASH_Unlock_User_Config(void)
{
    /* д��KEY1 �� KEY2 */
    FLASH_CFGUNLOCK = FLASH_CFGUNLOCK_KEY1;
    FLASH_CFGUNLOCK = FLASH_CFGUNLOCK_KEY2;
}
/**
  * ����  ����FLASHд����ʹ�ܡ�
  * ����  NewState: FLASHд����ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void  __attribute__((section(".indata")))
FLASH_Data_Write_Enable_RAM (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����FLASH_ISPCON0�Ĵ���DWENλ ----------------*/
    if (NewState != FALSE)
    {
        /* FLASHд������Ա�д������ */
        __asm volatile("SET [%0], #%1"::"r"(&(FLASH_ISPCON0)),"i"(FLASH_ISPCON0_DWEN_POS));
    }
    else
    {
        /* FLASHд�����ֹ��д������ */
        __asm volatile("CLR [%0], #%1"::"r"(&(FLASH_ISPCON0)),"i"(FLASH_ISPCON0_DWEN_POS));
    }
}

/**
  * ����  ����FLASH��Ϣ��ѡ��
  * ����  ZoneSelect: FLASH��Ϣ��ѡ��ȡֵΪ��
  *                     FLASH_NVM_CODE_ZONE: FLASH������
  *                     FLASH_NVM_INFORMATION_ZONE: FLASH_NVM_CODE_ZONE
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Zone_Config_RAM (uint32_t ZoneSelect)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_NVM_ZONE(ZoneSelect));

    /*---------------- ����FLASH_ISPCON0�Ĵ���IFENλ ----------------*/
    if (ZoneSelect != FLASH_NVM_CODE_ZONE)
    {
        /* NVM�����洢��ѡ��FLASH��Ϣ�� */
        __asm volatile("SET [%0], #%1"::"r"(&(FLASH_ISPCON0)),"i"(FLASH_ISPCON0_IFEN_POS));
    }
    else
    {
        /* NVM�����洢��ѡ��FLASH������ */
        __asm volatile("CLR [%0], #%1"::"r"(&(FLASH_ISPCON0)),"i"(FLASH_ISPCON0_IFEN_POS));
    }
}
/**
  * ����  ����FLASH��Ϣ��ѡ��
  * ����  ZoneSelect: FLASH��Ϣ��ѡ��ȡֵΪ��
  *                     FLASH_NVM_CODE_ZONE: FLASH������
  *                     FLASH_NVM_INFORMATION_ZONE: FLASH_NVM_CODE_ZONE
  * ����  �ޡ�
  */
void
FLASH_Zone_Config(uint32_t ZoneSelect)
{
    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FLASH_NVM_ZONE(ZoneSelect));

    /*---------------- ����FLASH_ISPCON0�Ĵ���IFENλ ----------------*/
    if (ZoneSelect != FLASH_NVM_CODE_ZONE)
    {
        /* NVM�����洢��ѡ��FLASH��Ϣ�� */
        SFR_SET_BIT_ASM(FLASH_ISPCON0, FLASH_ISPCON0_IFEN_POS);
    }
    else
    {
        /* NVM�����洢��ѡ��FLASH������ */
        SFR_CLR_BIT_ASM(FLASH_ISPCON0, FLASH_ISPCON0_IFEN_POS);
    }
}
/**
  * ����  ����FLASHģʽ��
  * ����  ModeSelect: FLASH��Ϣ��ѡ��ȡֵΪ��
  *                     FLASH_MODE_NORMAL: ��Ϊ����ģʽ
  *                     FLASH_MODE_STANDBY1: STANDBY1 ����Stanbyģʽ
  *                     FLASH_MODE_STANDBY2: STANDBY2 ��������ģʽ
  *                     FLASH_MODE_STANDBY1_STANDBY2: ������Stanbyģʽ
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Standby_Mode_Config_RAM (uint32_t ModeSelect)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_MODE(ModeSelect));

    /*---------------- ����FLASH_ISPCON0�Ĵ���CFGLOCKλ ----------------*/
    tmpreg = FLASH_ISPCON0_HIGH | ModeSelect;
    FLASH_ISPCON0 = SFR_Config_RAM (FLASH_ISPCON0,
                        ~(FLASH_ISPCON0_HIGH_MSK | FLASH_ISPCON0_STANDBY1),
                        tmpreg);
}



/**
  * ����  ����FLASH��ģʽ��
  * ����  ReadMode: FLASH��ģʽѡ��ȡֵΪ��
  *                   FLASH_READ_MODE_NORMAL: ����ģʽ
  *                   FLASH_READ_MODE_RECALL: RECALLģʽ
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Read_Mode_Config_RAM (uint32_t ReadMode)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_READ_MODE(ReadMode));

    /*---------------- ����FLASH_ISPCON1�Ĵ���RECALLENλ ----------------*/
    if (ReadMode != FLASH_IP1)
    {
        /* FLASH��������Ϊ����ģʽ */
        __asm volatile("SET [%0], #%1"::"r"(&(FLASH_ISPCON1)),"i"(FLASH_ISPCON1_RECALLEN_POS));
    }
    else
    {
        /* FLASH��������ΪRECALLģʽ */
        __asm volatile("CLR [%0], #%1"::"r"(&(FLASH_ISPCON1)),"i"(FLASH_ISPCON1_RECALLEN_POS));
    }
}

/**
  * ����  ����FLASHУ׼��Ϣ����ʹ�ܡ�
  * ����  NewState: FLASHУ׼��Ϣ����ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Calibration_Updata_Enable_RAM (FunctionalState NewState)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����FLASH_ISPCON1�Ĵ���CONFENλ ----------------*/
    tmpreg = FLASH_ISPCON1_HIGH \
           | (NewState << FLASH_ISPCON1_CONFEN_POS);
    FLASH_ISPCON1 = SFR_Config_RAM (FLASH_ISPCON1,
                        ~(FLASH_ISPCON1_HIGH_MSK | FLASH_ISPCON1_CONFEN),
                        tmpreg);
}

/**
  * ����  ����FLASHоƬ��Ϣ����д����״̬��
  * ����  NewState: FLASHоƬ��Ϣ����д����״̬��ȡֵΪ��
  *                   LOCK: ����״̬
  *                   UNLOCK: ����״̬
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Information_Zone_Wipe_Unlock_Config_RAM (LockStatus NewState)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_LOCK_STATUS(NewState));

    /*---------------- ����FLASH_ISPCON1�Ĵ���CONFENλ ----------------*/
    tmpreg = FLASH_ISPCON1_HIGH \
           | (NewState << FLASH_ISPCON1_CHIPONEN_POS);
    FLASH_ISPCON1 = SFR_Config_RAM (FLASH_ISPCON1,
                        ~(FLASH_ISPCON1_HIGH_MSK | FLASH_ISPCON1_CHIPONEN),
                        tmpreg);
}

/**
  * ����  ����FLASH��ҳ���ģʽ����Ҫд���������
  * ����  WriteSize: ��Ҫд���������ȡֵ6λ��ֵ��
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Half_Page_Write_Size_Config_RAM (uint32_t WriteSize)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_WRITE_SIZE(WriteSize));

    /*---------------- ����FLASH_ISPCMD�Ĵ���WSIZEλ ----------------*/
    tmpreg = WriteSize << FLASH_ISPCMD_WSIZE0_POS;
    FLASH_ISPCMD = SFR_Config_RAM (FLASH_ISPCMD,
                        ~FLASH_ISPCMD_WSIZE,
                        tmpreg);
}

/**
  * ����  ����FLASH����ѡ��
  * ����  CmdSelect: FLASH����ѡ��ȡֵΪ��
  *                    FLASH_PROGRAM_CMD_WORD: ���ֱ��
  *                    FLASH_PROGRAM_CMD_ALL_CODE: Ƭ��
  *                    FLASH_PROGRAM_CMD_PAGE: ҳ��
  *                    FLASH_PROGRAM_CMD_HALF_PAGE: ��ҳ���
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Program_Cmd_Config_RAM (uint32_t CmdSelect)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_PROGRAM_CMD(CmdSelect));

    /*---------------- ����FLASH_ISPCMD�Ĵ���CMDλ ----------------*/
    FLASH_ISPCMD = SFR_Config_RAM (FLASH_ISPCMD,
                        ~FLASH_ISPCMD_CMD,
                        CmdSelect);
}

/**
  * ����  ִ�е�ǰFLASH_ISPCMD�Ĵ����趨�������FLASH_Program_Cmd_Config����
  *       ���õ����
  * ����  �ޡ�
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Executive_Cmd_RAM(void)
{
    uint32_t tmpreg = 0;

    /*---------------- ����FLASH_ISPTRG�Ĵ���ISPGOλ ----------------*/
    tmpreg = FLASH_ISPTRG_HIGH | FLASH_ISPTRG_ISPGO;
    FLASH_ISPTRG = SFR_Config_RAM (FLASH_ISPTRG,
                        ~(FLASH_ISPTRG_HIGH_MSK | FLASH_ISPTRG_ISPGO),
                        tmpreg);
}
/**
  * ����  ִ�е�ǰFLASH_ISPCMD�Ĵ����趨�������FLASH_Program_Cmd_Config����
  *       ���õ����
  * ����  �ޡ�
  * ����  �ޡ�
  */
void
FLASH_Executive_Cmd(void)
{
    uint32_t tmpreg = 0;

    /*---------------- ����FLASH_ISPTRG�Ĵ���ISPGOλ ----------------*/
    tmpreg = FLASH_ISPTRG_HIGH | FLASH_ISPTRG_ISPGO;
    FLASH_ISPTRG = SFR_Config_RAM (FLASH_ISPTRG,
                        ~(FLASH_ISPTRG_HIGH_MSK | FLASH_ISPTRG_ISPGO),
                        tmpreg);
}
/**
  * ����  ����FLASH����ʧ�Դ洢��ECCʹ�ܡ�
  * ����  NewState: FLASH����ʧ�Դ洢��ECCʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_NonVolatile_Memory_ECC_Enable_RAM (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����FLASH_CFG�Ĵ���ECCREADENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ��ECCУ�� */
        __asm volatile("SET [%0], #%1"::"r"(&(FLASH_CFG)),"i"(FLASH_CFG_ECCREADEN_POS));
    }
    else
    {
        /* ��ʹ��ECCУ�� */
        __asm volatile("CLR [%0], #%1"::"r"(&(FLASH_CFG)),"i"(FLASH_CFG_ECCREADEN_POS));
    }
}

/**
  * ����  ����FLASH����Ԥȡʹ�ܡ�
  * ����  NewState: FLASH����Ԥȡʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Linear_Prefetch_Enable_RAM (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����FLASH_CFG�Ĵ���PREFETCHENλ ----------------*/
    if (NewState != FALSE)
    {
        /* ʹ������Ԥȡ */
        __asm volatile("SET [%0], #%1"::"r"(&(FLASH_CFG)),"i"(FLASH_CFG_PREFETCHEN_POS));
    }
    else
    {
        /* ��ʹ������Ԥȡ */
    	__asm volatile("CLR [%0], #%1"::"r"(&(FLASH_CFG)),"i"(FLASH_CFG_PREFETCHEN_POS));
    }
}

/**
  * ����  ����FLASH�������ڡ�
  * ����  PeriodNum: FLASH����ϵͳ���ڸ�����ȡֵΪ1~16��
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Period_Number_Config_RAM (uint32_t PeriodNum)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_PERIOD(PeriodNum));

    /*---------------- ����FLASH_CFG�Ĵ���TCFGλ ----------------*/
    tmpreg = (PeriodNum - 1) << FLASH_CFG_TCFG0_POS;
    FLASH_CFG = SFR_Config_RAM (FLASH_CFG,
                        ~FLASH_CFG_TCFG,
                        tmpreg);
}

/**
  * ����  ����FLASH��̺��в��ڼ�ĵ�ַ��
  * ����  ProgramAddr: FLASH��̵�ַ��ȡֵΪ0x0~0xFFFFF��Ӳ�����Ե�2λ��
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Program_Addr_Config_RAM (uint32_t ProgramAddr)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_ADDR_20BITS(ProgramAddr));

    /*---------------- ����FLASH_ISPADDR�Ĵ���SADDRλ ----------------*/
    tmpreg = ProgramAddr << FLASH_ISPADDR_SADDR0_POS;
    FLASH_ISPADDR = SFR_Config_RAM (FLASH_ISPADDR,
                        ~FLASH_ISPADDR_SADDR,
                        tmpreg);
}

/**
  * ����  ��FLASH���״̬��   RAM
  * ����  �ޡ�
  * ����  ���״̬��1��FLASH�����ڱ��״̬��0��FLASH���ڱ��״̬��
  */
FlagStatus  __attribute__((section(".indata")))
FLASH_Get_Program_Status_RAM (void)
{
    if (FLASH_STATE & FLASH_STATE_TBUSY)
    {
        /* ���״̬ */
        return SET;
    }
    else
    {
        /* ���ڱ��״̬ */
        return RESET;
    }
}
/**
  * ����  ��FLASH���״̬��   RAM
  * ����  �ޡ�
  * ����  ���״̬��1��FLASH�����ڱ��״̬��0��FLASH���ڱ��״̬��
  */
FlagStatus
FLASH_Get_Program_Status (void)
{
    if (FLASH_STATE & FLASH_STATE_TBUSY)
    {
        /* ���״̬ */
        return SET;
    }
    else
    {
        /* ���ڱ��״̬ */
        return RESET;
    }
}



/**
  * ����  ��FLASH��д״̬��
  * ����  �ޡ�
  * ����  ���״̬��1��ISP����ִ�в�������д���0��ISP���ڿ���״̬��
  */
FlagStatus   __attribute__((section(".indata")))
FLASH_Get_Wipe_Status_RAM (void)
{
    if (FLASH_STATE & FLASH_STATE_TBIT)
    {
        /* ����ִ�в�������д���� */
        return SET;
    }
    else
    {
        /* ���ڿ���״̬ */
        return RESET;
    }
}

/**
  * ����  ��FLASH��д״̬��
  * ����  �ޡ�
  * ����  ���״̬��1��ISP����ִ�в�������д���0��ISP���ڿ���״̬��
  */
FlagStatus
FLASH_Get_Wipe_Status (void)
{
    if (FLASH_STATE & FLASH_STATE_TBIT)
    {
        /* ����ִ�в�������д���� */
        return SET;
    }
    else
    {
        /* ���ڿ���״̬ */
        return RESET;
    }
}
/**
  * ����  ��FLASH�������״̬��
  * ����  �ޡ�
  * ����  ���״̬��1��������ɣ�0��δ������߼����С�
  */
FlagStatus __attribute__((section(".indata")))
FLASH_Get_Compute_Complete_Status_RAM (void)
{
    if (FLASH_STATE & FLASH_STATE_SIGDONE)
    {
        /* ������� */
        return SET;
    }
    else
    {
        /* δ������߼����� */
        return RESET;
    }
}

/**
  * ����  ����FLASH�������״̬��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Clear_Compute_Complete_Status_RAM (void)
{
    /* д 1 ���� */
    while((FLASH_STATE & FLASH_STATE_SIGDONE)>>FLASH_STATE_SIGDONE_POS)
    {
    	__asm volatile("SET [%0], #%1"::"r"(&(FLASH_STATE)),"i"(FLASH_STATE_SIGDONE_POS));
    }
}

#if _CLOSE_SERVICE_

/**
  * ����  ��FLASH CFG��̴����־��
  * ����  �ޡ�
  * ����  ��̴����־��1��CFG��������̴���0��������
  */
FlagStatus  __attribute__((section(".indata")))
FLASH_Get_CFG_Error_Flag_RAM (void)
{
    if (FLASH_STATE & FLASH_STATE_CFGERROR)
    {
        /* CFG��������̴��� */
        return SET;
    }
    else
    {
        /* ���� */
        return RESET;
    }
}

/**
  * ����  ����FLASH CFG��̴����־��
  * ����  �ޡ�
  * ����  �ޡ�
  */
void  __attribute__((section(".indata")))
FLASH_Clear_CFG_Error_Flag_RAM (void)
{
    /* д 1 ���� */

    while((FLASH_STATE & FLASH_STATE_CFGERROR)>>FLASH_STATE_CFGERROR_POS)
    {
    	__asm volatile("SET [%0], #%1"::"r"(&(FLASH_STATE)),"i"(FLASH_STATE_CFGERROR_POS));
    }
}
#endif /* _CLOSE_SERVICE_ */

/**
  * ����  ����FLASH CheckSum��β��ַ��
  * ����  StartAddr: FLASH CheckSum���׵�ַ����ַ����Ϊ0x0~0xFFFFF��Ӳ�����Ե�4λ��
  *       StopAddr: FLASH CheckSum��β��ַ����ַ����Ϊ0x0~0xFFFFF��Ӳ�����Ե�4λ��
  * ����  �ޡ�
  */
void  __attribute__((section(".indata")))
FLASH_CheckSum_Addr_Config_RAM(uint32_t StartAddr, uint32_t StopAddr)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_ADDR_20BITS(StartAddr));
    CHECK_RESTRICTION_RAM(CHECK_FLASH_ADDR_20BITS(StopAddr));

    FLASH_CSSTART = StartAddr;
    FLASH_CSSTOP = StopAddr;
}

/**
  * ����  ����FLASH����SIG����ʹ�ܡ�
  * ����  NewState: FLASH����SIG����ʹ��״̬��ȡֵΪTRUE �� FALSE��
  * ����  �ޡ�
  */
void  __attribute__((section(".indata")))
FLASH_Start_SIG_Compute_Enable_RAM (FunctionalState NewState)
{
    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FUNCTIONAL_STATE(NewState));

    /*---------------- ����FLASH_CSSTOP�Ĵ���SIGGOλ ----------------*/
    if (NewState != FALSE)
    {
        /* ����SIG���� */
        __asm volatile("SET [%0], #%1"::"r"(&(FLASH_CSSTOP)),"i"(FLASH_CSSTOP_SIGGO_POS));
    }
    else
    {
        /* ������SIG���� */
        __asm volatile("CLR [%0], #%1"::"r"(&(FLASH_CSSTOP)),"i"(FLASH_CSSTOP_SIGGO_POS));
    }
}

/**
  * ����  ��ȡFLASH CheckSum�Ľ����
  * ����  CheckSumStruct: FLASH CheckSum��Ϣ�ṹ��ָ�룬
  *                       ָ�����ָ���д�ĵ�ַ�ռ䡣
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Get_CheckSum_Result_RAM (FLASH_CheckSumResult* CheckSumStruct)
{
    uint32_t tmpreg = 0;

    /*---------------- ����FLASH_CSRESx�Ĵ���CKSPRESλ ----------------*/
    tmpreg = FLASH_CSRES0;
    CheckSumStruct->m_ResultWord[0] = tmpreg;

    tmpreg = FLASH_CSRES1;
    CheckSumStruct->m_ResultWord[1] = tmpreg;

    tmpreg = FLASH_CSRES2;
    CheckSumStruct->m_ResultWord[2] = tmpreg;

    tmpreg = FLASH_CSRES3;
    CheckSumStruct->m_ResultWord[3] = tmpreg;
}
/**
  *   ##### FLASH����洢��(FLASH)�������ú���������� #####
  */


/**
  *   ##### FLASH����洢��(FLASH)��̹��ܺ��� #####
  */
/**
  * ����  FLASH�����������ã��û���Ҫȷ��FLASH��д����״̬��
  * ����  WipeMode: FLASH ����ģʽ��ȡֵΪ��
  *                   FLASH_WIPE_CODE_PAGE: ������ҳ��
  *                   FLASH_WIPE_CFG_PAGE: �û�������ҳ��
  *                   FLASH_WIPE_CODE_ALL: ������Ƭ��
  *       WipeAddr: ������ַ��ȡֵΪ0x0~0xFFFFF��Ӳ�����Ե�10λ��
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Wipe_Configuration_RAM (uint32_t WipeMode,uint32_t WipeAddr)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION_RAM(CHECK_FLASH_WIPE_MODE(WipeMode));
    CHECK_RESTRICTION_RAM(CHECK_FLASH_ADDR_20BITS(WipeAddr));



    /* ����ISP���ܼĴ��� */
    FLASH_Unlock_ISP_RAM();

	/* ����FLASH������ */
	FLASH_Unlock_Code_RAM();

	/* ����FLASH�û������� */
	FLASH_Unlock_User_Config_RAM();


    /* ���ô�������PAGE */
    if (WipeMode != FLASH_WIPE_CODE_ALL)
    {
        /* ҳ�� */
        FLASH_ISPADDR = WipeAddr;


        if (FLASH_WIPE_CFG_PAGE == WipeMode)
        {

            /* ʹ����Ϣ��ӳ�� */
            /*---------------- ����FLASH_ISPCON0�Ĵ���IFENλ ----------------*/
            __asm volatile("SET [%0], #%1"::"r"(&(FLASH_ISPCON0)),"i"(FLASH_ISPCON0_IFEN_POS));
        }
        else
        {
            ;
        }
    }
    else
    {
        /* Ƭ�� */
    }
    /* ���ò���ģʽ */
    if (WipeMode != FLASH_WIPE_CODE_ALL)
    {
        /* ҳ�� */
        tmpreg = FLASH_PROGRAM_CMD_PAGE;
    }
    else
    {
        /* Ƭ�� */
        tmpreg = FLASH_PROGRAM_CMD_ALL_CODE;
    }
    /*---------------- ����FLASH_ISPCMD�Ĵ���CMDλ ----------------*/
    FLASH_ISPCMD = SFR_Config_RAM (FLASH_ISPCMD,
                        ~FLASH_ISPCMD_CMD,
                        tmpreg);



    /* �������� */
    FLASH_Executive_Cmd_RAM();

    while(FLASH_Get_Wipe_Status_RAM());//�ȴ�д�����

   	FLASH_Zone_Config_RAM (FLASH_NVM_CODE_ZONE);//�ص�������

    //����
	FLASH_Clear_NonVolatile_Memory_Unlock_Status_RAM ();//����FLASH����������״̬λ��
	FLASH_Clear_Flash_Unlock_Status_RAM ();//����FLASH����״̬λ��
	FLASH_Clear_Config_Unlock_Status_RAM ();//����FLASH����������״̬λ��


}

/**
  * ����  FLASH�����������ã��û���Ҫȷ��FLASH��д����״̬��
  * ����  WipeMode: FLASH ����ģʽ��ȡֵΪ��
  *                   FLASH_WIPE_CODE_PAGE: ������ҳ��
  *                   FLASH_WIPE_CFG_PAGE: �û�������ҳ��
  *                   FLASH_WIPE_CODE_ALL: ������Ƭ��
  *       WipeAddr: ������ַ��ȡֵΪ0x0~0xFFFFF��Ӳ�����Ե�10λ��
  * ����  �ޡ�
  */
void
FLASH_Wipe_Configuration (uint32_t WipeMode,uint32_t WipeAddr)
{
    uint32_t tmpreg = 0;

    /* ����У�� */
    CHECK_RESTRICTION(CHECK_FLASH_WIPE_MODE(WipeMode));
    CHECK_RESTRICTION(CHECK_FLASH_ADDR_20BITS(WipeAddr));



    /* ����ISP���ܼĴ��� */
    FLASH_Unlock_ISP();

	/* ����FLASH������ */
	FLASH_Unlock_Code();

	/* ����FLASH�û������� */
	FLASH_Unlock_User_Config();


    /* ���ô�������PAGE */
    if (WipeMode != FLASH_WIPE_CODE_ALL)
    {
        /* ҳ�� */
        FLASH_ISPADDR = WipeAddr;


        if (FLASH_WIPE_CFG_PAGE == WipeMode)
        {

            /* ʹ����Ϣ��ӳ�� */
            /*---------------- ����FLASH_ISPCON0�Ĵ���IFENλ ----------------*/
            SFR_SET_BIT_ASM(FLASH_ISPCON0, FLASH_ISPCON0_IFEN_POS);
        }
        else
        {
            ;
        }
    }
    else
    {
        /* Ƭ�� */
    }
    /* ���ò���ģʽ */
    if (WipeMode != FLASH_WIPE_CODE_ALL)
    {
        /* ҳ�� */
        tmpreg = FLASH_PROGRAM_CMD_PAGE;
    }
    else
    {
        /* Ƭ�� */
        tmpreg = FLASH_PROGRAM_CMD_ALL_CODE;
    }
    /*---------------- ����FLASH_ISPCMD�Ĵ���CMDλ ----------------*/
    FLASH_ISPCMD = SFR_Config (FLASH_ISPCMD,
                        ~FLASH_ISPCMD_CMD,
                        tmpreg);



    /* �������� */
    FLASH_Executive_Cmd();

    while(FLASH_Get_Wipe_Status());//�ȴ�д�����

   	FLASH_Zone_Config_RAM (FLASH_NVM_CODE_ZONE);//�ص�������

    //����
	FLASH_Clear_NonVolatile_Memory_Unlock_Status ();//����FLASH����������״̬λ��
	FLASH_Clear_Flash_Unlock_Status ();//����FLASH����״̬λ��
	FLASH_Clear_Config_Unlock_Status ();//����FLASH����������״̬λ��


}


/**
  * ����  FLASH��̲������ã��û���Ҫȷ��FLASH��д����״̬��   RAM
  * ����  flashProgramStruct: FLASH�����Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void __attribute__((section(".indata")))
FLASH_Program_Configuration_RAM (FLASH_ProgramTypeDef * flashProgramStruct)
{
	uint32_t tmpreg = 0;
	uint32_t tmpaddr = 0;
	uint32_t * tmpptr = NULL;

    /* ����У�� */

	CHECK_RESTRICTION_RAM(CHECK_FLASH_PROGRAM_MODE(flashProgramStruct->m_Mode));
	CHECK_RESTRICTION_RAM(CHECK_FLASH_PROGRAM_ZONE(flashProgramStruct->m_Zone));
	CHECK_RESTRICTION_RAM(CHECK_FLASH_ADDR_20BITS(flashProgramStruct->m_Addr));
	CHECK_RESTRICTION_RAM(CHECK_FLASH_WRITE_SIZE(flashProgramStruct->m_WriteSize));

    /* �����Ĵ��� */




    FLASH_Unlock_ISP_RAM();
    FLASH_Unlock_User_Config_RAM();
    FLASH_Unlock_Code_RAM();




    /*---------------- ����FLASH_ISPCON0�Ĵ���DWENλ ----------------*/
    __asm volatile("SET [%0], #%1"::"r"(&(FLASH_ISPCON0)),"i"(FLASH_ISPCON0_DWEN_POS));

    if (flashProgramStruct->m_Zone != FLASH_PROGRAM_CODE)
    {
        /*---------------- ����FLASH_ISPCON0�Ĵ���IFENλ ----------------*/
        __asm volatile("SET [%0], #%1"::"r"(&(FLASH_ISPCON0)),"i"(FLASH_ISPCON0_IFEN_POS));

    }
    else
    {
    }

    /* ʹ����ʱ�������������������޸Ľṹ������ */
	  tmpaddr = flashProgramStruct->m_Addr;
	  tmpptr =  flashProgramStruct->m_Data;

    /* ���ñ��ģʽ */
    if (flashProgramStruct->m_Mode != FLASH_PROGRAM_WORD)
    {
        /* ��ҳ��� */
        /*----------- ����FLASH_ISPCMD�Ĵ���CMD/WSIZEλ -----------*/
        tmpreg = flashProgramStruct->m_Mode \
               | (flashProgramStruct->m_WriteSize << FLASH_ISPCMD_WSIZE0_POS);
        FLASH_ISPCMD = SFR_Config_RAM(FLASH_ISPCMD,
                            ~(FLASH_ISPCMD_CMD | FLASH_ISPCMD_WSIZE),
                            tmpreg);
        FLASH_Executive_Cmd_RAM();
		unsigned char j;
		for(j=0;j<=0x3f;j++)//0x3f���ֵ
		{
			__asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));
			tmpaddr=tmpaddr+4;
			tmpptr++;
			__asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));
			tmpaddr=tmpaddr+4;
			tmpptr++;
			while(FLASH_Get_Program_Status_RAM());
		}
    }
    else
    {
        /* ���ֱ�� */
        /*------------- ����FLASH_ISPCMD�Ĵ���CMDλ --------------*/
        FLASH_ISPCMD = SFR_Config_RAM (FLASH_ISPCMD,
                            ~FLASH_ISPCMD_CMD,
                            flashProgramStruct->m_Mode);
        /* ���ֱ�̣��ȼ������ݣ��󴥷����� */
        /* ����64λ���� */

    	__asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));
    	tmpaddr=tmpaddr+4;
    	tmpptr++;
    	__asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));

        /* �������� */

        FLASH_Executive_Cmd_RAM();

    }

    while(FLASH_Get_Wipe_Status_RAM());//�ȴ�д�����

    /*---------------- ����FLASH_ISPCON0�Ĵ���DWENλ ----------------*/


   	FLASH_Zone_Config_RAM (FLASH_NVM_CODE_ZONE);//�ص�������

   	FLASH_Data_Write_Enable_RAM (FALSE);
    //����
	FLASH_Clear_NonVolatile_Memory_Unlock_Status_RAM ();//����FLASH����������״̬λ��
	FLASH_Clear_Flash_Unlock_Status_RAM ();//����FLASH����״̬λ��
	FLASH_Clear_Config_Unlock_Status_RAM ();//����FLASH����������״̬λ��

}
/**
  * ����  FLASH��̲������ã��û���Ҫȷ��FLASH��д����״̬��   RAM
  * ����  flashProgramStruct: FLASH�����Ϣ�ṹ��ָ�롣
  * ����  �ޡ�
  */
void
FLASH_Program_Configuration (FLASH_ProgramTypeDef * flashProgramStruct)
{
	uint32_t tmpreg = 0;
	uint32_t tmpaddr = 0;
	uint32_t * tmpptr = NULL;

    /* ����У�� */

	CHECK_RESTRICTION(CHECK_FLASH_PROGRAM_MODE(flashProgramStruct->m_Mode));
	CHECK_RESTRICTION(CHECK_FLASH_PROGRAM_ZONE(flashProgramStruct->m_Zone));
	CHECK_RESTRICTION(CHECK_FLASH_ADDR_20BITS(flashProgramStruct->m_Addr));
	CHECK_RESTRICTION(CHECK_FLASH_WRITE_SIZE(flashProgramStruct->m_WriteSize));

    /* �����Ĵ��� */




    FLASH_Unlock_ISP();
    FLASH_Unlock_User_Config();
    FLASH_Unlock_Code();




    /*---------------- ����FLASH_ISPCON0�Ĵ���DWENλ ----------------*/
    SFR_SET_BIT_ASM(FLASH_ISPCON0, FLASH_ISPCON0_DWEN_POS);

    if (flashProgramStruct->m_Zone != FLASH_PROGRAM_CODE)
    {
        /*---------------- ����FLASH_ISPCON0�Ĵ���IFENλ ----------------*/
        SFR_SET_BIT_ASM(FLASH_ISPCON0, FLASH_ISPCON0_IFEN_POS);

    }
    else
    {
    }

    /* ʹ����ʱ�������������������޸Ľṹ������ */
	  tmpaddr = flashProgramStruct->m_Addr;
	  tmpptr =  flashProgramStruct->m_Data;

    /* ���ñ��ģʽ */
    if (flashProgramStruct->m_Mode != FLASH_PROGRAM_WORD)
    {
        /* ��ҳ��� */
        /*----------- ����FLASH_ISPCMD�Ĵ���CMD/WSIZEλ -----------*/
        tmpreg = flashProgramStruct->m_Mode \
               | (flashProgramStruct->m_WriteSize << FLASH_ISPCMD_WSIZE0_POS);
        FLASH_ISPCMD = SFR_Config(FLASH_ISPCMD,
                            ~(FLASH_ISPCMD_CMD | FLASH_ISPCMD_WSIZE),
                            tmpreg);
        FLASH_Executive_Cmd();
		unsigned char j;
		for(j=0;j<=0x3f;j++)//0x3f���ֵ
		{
			__asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));
			tmpaddr=tmpaddr+4;
			tmpptr++;
			__asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));
			tmpaddr=tmpaddr+4;
			tmpptr++;
			while(FLASH_Get_Program_Status());
		}
    }
    else
    {
        /* ���ֱ�� */
        /*------------- ����FLASH_ISPCMD�Ĵ���CMDλ --------------*/
        FLASH_ISPCMD = SFR_Config (FLASH_ISPCMD,
                            ~FLASH_ISPCMD_CMD,
                            flashProgramStruct->m_Mode);
        /* ���ֱ�̣��ȼ������ݣ��󴥷����� */
        /* ����64λ���� */

    	__asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));
    	tmpaddr=tmpaddr+4;
    	tmpptr++;
    	__asm volatile("ST.w [%0], %1"::"r"(tmpaddr),"r"(*tmpptr));

        /* �������� */

        FLASH_Executive_Cmd();

    }

    while(FLASH_Get_Wipe_Status());//�ȴ�д�����

    /*---------------- ����FLASH_ISPCON0�Ĵ���DWENλ ----------------*/


   	FLASH_Zone_Config (FLASH_NVM_CODE_ZONE);//�ص�������

   	FLASH_Data_Write_Enable_RAM (FALSE);
    //����
	FLASH_Clear_NonVolatile_Memory_Unlock_Status ();//����FLASH����������״̬λ��
	FLASH_Clear_Flash_Unlock_Status ();//����FLASH����״̬λ��
	FLASH_Clear_Config_Unlock_Status ();//����FLASH����������״̬λ��

}
/**
  *   ##### FLASH����洢��(FLASH)��̹��ܺ���������� #####
  */

/**
  * ����  ��ȡflash�ĳ�����������Ϣ��(RAM)
  * ����:address(��ȡ��ַ��,ZoneSelect����ȡ����ѡ��
  * ����  ����ָ���ַ��32λ����
  */
uint32_t read_data;
uint32_t __attribute__((section(".indata")))
Read_Flash_or_CFR_RAM (uint32_t address,uint32_t ZoneSelect)
{
	uint32_t *read_adr;
	CHECK_RESTRICTION_RAM(CHECK_FLASH_PROGRAM_ZONE(ZoneSelect));
	//����
	FLASH_Unlock_ISP_RAM();
	FLASH_Unlock_User_Config_RAM();
	FLASH_Unlock_Code_RAM();
	if(ZoneSelect!=FLASH_PROGRAM_CFG)
	{
		read_adr = (uint32_t *)address;
		read_data = *read_adr;
	}
	else
	{
		FLASH_Zone_Config_RAM (FLASH_NVM_INFORMATION_ZONE);//�е���Ϣ��
		read_adr = (uint32_t *)address;
		read_data = *read_adr;
		FLASH_Zone_Config_RAM (FLASH_NVM_CODE_ZONE);//�ص�������
	}
	 //����
	FLASH_Clear_NonVolatile_Memory_Unlock_Status ();//����FLASH����������״̬λ��
	FLASH_Clear_Flash_Unlock_Status ();//����FLASH����״̬λ��
	FLASH_Clear_Config_Unlock_Status ();//����FLASH����������״̬λ��
	return read_data;

}

/**
  * ����  ��ȡflash�ĳ�����������Ϣ��
  * ����:address(��ȡ��ַ��,ZoneSelect����ȡ����ѡ��
  * ����  ����ָ���ַ��32λ����
  */
uint32_t Read_Flash_or_CFR (uint32_t address,uint32_t ZoneSelect)
{
	uint32_t *read_adr;
	CHECK_RESTRICTION(CHECK_FLASH_PROGRAM_ZONE(ZoneSelect));
	//����
	FLASH_Unlock_ISP_RAM();
	FLASH_Unlock_User_Config_RAM();
	FLASH_Unlock_Code_RAM();
	if(ZoneSelect!=FLASH_PROGRAM_CFG)
	{
		read_adr = (uint32_t *)address;
		read_data = *read_adr;
	}
	else
	{
		FLASH_Zone_Config_RAM (FLASH_NVM_INFORMATION_ZONE);//�е���Ϣ��
		read_adr = (uint32_t *)address;
		read_data = *read_adr;
		FLASH_Zone_Config_RAM (FLASH_NVM_CODE_ZONE);//�ص�������
	}
	 //����
	FLASH_Clear_NonVolatile_Memory_Unlock_Status ();//����FLASH����������״̬λ��
	FLASH_Clear_Flash_Unlock_Status ();//����FLASH����״̬λ��
	FLASH_Clear_Config_Unlock_Status ();//����FLASH����������״̬λ��
	return read_data;

}

/**
  * ����  ��ȡоƬΨһID
  * ����:��
  * ����  ��Ӧ��ΨһID
  */
uint32_t  Read_Soft_Device_ID1(void)
{
	uint32_t Soft_Device_ID1;
	Soft_Device_ID1 = Read_Flash_or_CFR(0x444,FLASH_PROGRAM_CFG);
	return Soft_Device_ID1;
}
uint32_t  Read_Soft_Device_ID2(void)
{
	uint32_t Soft_Device_ID2;
	Soft_Device_ID2 = Read_Flash_or_CFR(0x448,FLASH_PROGRAM_CFG);
	return Soft_Device_ID2;
}
uint32_t  Read_Soft_Device_ID3(void)
{
	uint32_t Soft_Device_ID3;
	Soft_Device_ID3 = Read_Flash_or_CFR(0x44C,FLASH_PROGRAM_CFG);
	return Soft_Device_ID3;
}
uint32_t  Read_Soft_Device_ID4(void)
{
	uint32_t Soft_Device_ID4;
	Soft_Device_ID4 = Read_Flash_or_CFR(0x450,FLASH_PROGRAM_CFG);
	return Soft_Device_ID4;
}
