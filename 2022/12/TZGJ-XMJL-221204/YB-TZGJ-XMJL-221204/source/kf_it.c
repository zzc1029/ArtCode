/****************************************************************************************
 *
 * �ļ��� kf_it.c
 * ��  ��	ChipON_AE/FAE_Group
 * ��  ��	V2.1
 * ��  ��	2019-11-16
 * ��  ��  ���ļ��ṩ���ж���ڵ�ַ,��CAN1�жϴ���RAM����
 *
 ****************************************************************************************/
#include"system_init.h"


void __attribute__((interrupt))_CAN2_exception (void)
{
	uint8_t i;
	uint32_t id;
	static uint8_t Receice_addr = 0x00;//����RAMƫ�Ƶ�ַ
	static uint8_t bus_off_count = 0;
	CAN_MessageTypeDef CAN_MessageStructrue;//���ձ��Ľṹ��
	/* ��CAN�жϱ�־ */
	INT_Clear_Interrupt_Flag(INT_CAN2);

	/* �ж��Ƿ�ΪCAN���ձ�־ */
	if(CAN_Get_INT_Flag(CAN2_SFR,CAN_INT_RECEIVE) != RESET)
	{
		/* ����RAM���� */
		CAN_Receive_Message_Configuration(CAN2_SFR,Receice_addr,&CAN_MessageStructrue);
		/* RAM��ַ���� */
		Receice_addr += 0x10;
		/* �ͷ�һ�μ����� */
		CAN_Release_Receive_Buffer(CAN2_SFR,1);
        bus_off_count = 0;
		if(CAN_MessageStructrue.m_RemoteTransmit != CAN_DATA_FRAME)//Զ��֡  m_FrameFormat  ���պ����Ѿ�ruturn����������
		{
			//�û�����
		}
		else  //����֡
		{
			Can2_Rx_Isr(CAN_MessageStructrue);
			/* ��ȡ���� */
			/* ��ӡ���� */
		}
	}
}


void __attribute__((interrupt))_CAN0_exception (void)
{
	uint8_t i;
	uint32_t id;
	static uint8_t Receice_addr=0x00;//����RAMƫ�Ƶ�ַ
	static uint8_t bus_off_count;
	CAN_MessageTypeDef CAN_MessageStructrue;//���ձ��Ľṹ��
	/* ��CAN�жϱ�־ */
	INT_Clear_Interrupt_Flag(INT_CAN0);


	/* �ж��Ƿ�ΪCAN���ձ�־ */
	if(CAN_Get_INT_Flag(CAN0_SFR,CAN_INT_RECEIVE) != RESET)
	{
		/* ����RAM���� */
		CAN_Receive_Message_Configuration(CAN0_SFR,Receice_addr,&CAN_MessageStructrue);
		/* RAM��ַ���� */
		Receice_addr+=0x10;
		/* �ͷ�һ�μ����� */
		CAN_Release_Receive_Buffer(CAN0_SFR,1);
        bus_off_count = 0;
		if(CAN_MessageStructrue.m_RemoteTransmit != CAN_DATA_FRAME)//Զ��֡  m_FrameFormat  ���պ����Ѿ�ruturn����������
		{
			//�û�����
		}
		else  //����֡
		{
			Can0_Rx_Isr(CAN_MessageStructrue);
			/* ��ȡ���� */
		}
	}
}


void __attribute__((interrupt))_CAN3_exception (void)
{
	uint8_t i;
	uint32_t id;
	static uint8_t Receice_addr=0x00;//����RAMƫ�Ƶ�ַ
	static uint8_t bus_off_count = 0;
	CAN_MessageTypeDef CAN_MessageStructrue;//���ձ��Ľṹ��
	/* ��CAN�жϱ�־ */
	INT_Clear_Interrupt_Flag(INT_CAN3);

	/* �ж��Ƿ�ΪCAN���ձ�־ */
	if(CAN_Get_INT_Flag(CAN3_SFR,CAN_INT_RECEIVE) != RESET)
	{
		/* ����RAM���� */
		CAN_Receive_Message_Configuration(CAN3_SFR,Receice_addr,&CAN_MessageStructrue);
		/* RAM��ַ���� */
		Receice_addr+=0x10;
		/* �ͷ�һ�μ����� */
		CAN_Release_Receive_Buffer(CAN3_SFR,1);
        bus_off_count = 0;
		if(CAN_MessageStructrue.m_RemoteTransmit != CAN_DATA_FRAME)//Զ��֡  m_FrameFormat  ���պ����Ѿ�ruturn����������
		{
			//�û�����
		}
		else  //����֡
		{
			Can3_Rx_Isr(CAN_MessageStructrue);
			/* ��ȡ���� */
			/* ��ӡ���� */
		}
	}
}


void __attribute__((interrupt))_CAN1_exception (void)
{
	uint8_t i;
	uint32_t id;
	static uint8_t Receice_addr=0x00;//����RAMƫ�Ƶ�ַ
	static uint8_t bus_off_count = 0;
	CAN_MessageTypeDef CAN_MessageStructrue;//���ձ��Ľṹ��
	/* ��CAN�жϱ�־ */
	INT_Clear_Interrupt_Flag(INT_CAN1);

	/* �ж��Ƿ�ΪCAN���ձ�־ */
	if(CAN_Get_INT_Flag(CAN1_SFR,CAN_INT_RECEIVE) != RESET)
	{
		/* ����RAM���� */
		CAN_Receive_Message_Configuration(CAN1_SFR,Receice_addr,&CAN_MessageStructrue);
		/* RAM��ַ���� */
		Receice_addr+=0x10;
		/* �ͷ�һ�μ����� */
		CAN_Release_Receive_Buffer(CAN1_SFR,1);
        bus_off_count = 0;
		if(CAN_MessageStructrue.m_RemoteTransmit != CAN_DATA_FRAME)//Զ��֡  m_FrameFormat  ���պ����Ѿ�ruturn����������
		{
			//�û�����
		}
		else  //����֡
		{
			Can1_Rx_Isr(CAN_MessageStructrue);
			/* ��ȡ���� */
			/* ��ӡ���� */
		}
	}
}

void __attribute__((interrupt))_CAN4_exception (void)
{
	uint8_t i;
	uint32_t id;
	static uint8_t Receice_addr=0x00;//����RAMƫ�Ƶ�ַ
	static uint8_t bus_off_count = 0;
	CAN_MessageTypeDef CAN_MessageStructrue;//���ձ��Ľṹ��
	/* ��CAN�жϱ�־ */
	INT_Clear_Interrupt_Flag(INT_CAN4);

	/* �ж��Ƿ�ΪCAN���ͱ�־ */
	//if(CAN_Get_INT_Flag(CAN4_SFR,CAN_INT_TRANSMIT) != RESET)
	//{
	//	CAN_Clear_INT_Flag(CAN4_SFR,CAN_INT_TRANSMIT);
	//}

	if(CAN_Get_INT_Flag(CAN4_SFR,CAN_INT_BUS_ERROR) != RESET)
	{
		CAN_Clear_INT_Flag(CAN4_SFR,CAN_INT_BUS_ERROR);
		
		//bus_off_count++;
		//if(bus_off_count > 20)
		//{
          CAN_Reset(CAN4_SFR);
		  Pcan3Inint();
		//  bus_off_count = 0;
		//}
		//else
		//{
		//	CAN_Reset_Mode_Enable(CAN4_SFR, FALSE);   
		//}			
	}


	/* �ж��Ƿ�ΪCAN���ձ�־ */
	if(CAN_Get_INT_Flag(CAN4_SFR,CAN_INT_RECEIVE) != RESET)
	{
		/* ����RAM���� */
		CAN_Receive_Message_Configuration(CAN4_SFR,Receice_addr,&CAN_MessageStructrue);
		/* RAM��ַ���� */
		Receice_addr+=0x10;
		/* �ͷ�һ�μ����� */
		CAN_Release_Receive_Buffer(CAN4_SFR,1);

		if(CAN_MessageStructrue.m_RemoteTransmit != CAN_DATA_FRAME)//Զ��֡  m_FrameFormat  ���պ����Ѿ�ruturn����������
		{
			//�û�����
		}
		else  //����֡
		{
			Can4_Rx_Isr(CAN_MessageStructrue);
			/* ��ȡ���� */
			/* ��ӡ���� */
		}
	}
}


//*****************************************************************************************
//                              T0�жϺ���  ���񼶱�
//*****************************************************************************************
void __attribute__((interrupt))_T0_exception (void)
{
    static unsigned char flag = 0;
	GPTIM_Clear_Updata_INT_Flag(T0_SFR);							 //�����ʱ���־λ
	GPTIM_Clear_Overflow_INT_Flag(T0_SFR);						     //��T0����жϱ�־λ
	sch_update();
    if(rs485style.len > 0)
	{
	   if(rs485style.timeout < 19)
	      rs485style.timeout++;
	}
}

//*****************************************************************************************
//                              T1�жϺ���  ���������
//*****************************************************************************************
void __attribute__((interrupt))_T2_exception (void)
{
	GPTIM_Clear_Updata_INT_Flag(T2_SFR);							 //�����ʱ���־λ
	GPTIM_Clear_Overflow_INT_Flag(T2_SFR);						     //��T0����жϱ�־λ
	SysTickPer1ms++;

    if(Pcan2Delay > 0)
	   Pcan2Delay--;
	
    if(Pcan3Delay > 0)
	   Pcan3Delay--;

    if(Pcan1Delay > 0)
	   Pcan1Delay--;

	if(DcanDelay > 0)
	   DcanDelay--;

	if(BcanDelay > 0)
	   BcanDelay--;
}


//                             EINT0�жϺ���
//*****************************************************************************************
//ԭPC0��
/*void __attribute__((interrupt)) _EINT0_exception (void)
{
	 if(INT_Get_External_Flag(INT_EXTERNAL_INTERRUPT_0) != RESET)
	 {
			INT_External_Clear_Flag(INT_EXTERNAL_INTERRUPT_0);
			A5Count++;
	 }

}*/
//��PD14��
void __attribute__((interrupt)) _EINT15TO10_exception (void)
{
	 if(INT_Get_External_Flag(INT_EXTERNAL_INTERRUPT_14) != RESET)
	 {
			INT_External_Clear_Flag(INT_EXTERNAL_INTERRUPT_14);
			A5Count++;
	 }

}



//                             EINT1�жϺ���
//*****************************************************************************************
void __attribute__((interrupt)) _EINT1_exception (void)
{
	 if(INT_Get_External_Flag(INT_EXTERNAL_INTERRUPT_1) != RESET)
	 {
			INT_External_Clear_Flag(INT_EXTERNAL_INTERRUPT_1);
			A15Count++;
	 }

}


