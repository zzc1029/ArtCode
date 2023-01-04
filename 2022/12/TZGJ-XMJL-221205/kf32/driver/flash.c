/*
 * flash.c
 *
 *  Created on: 2021-8-7
 *      Author: ART
 */
//flash����
#include "system_init.h"


/**
  ********************************************************************
  * �ļ���  flash.c
  * ��  ��   ChipON_AE/FAE_Group
  * ��  ��  V2.1
  * ��  ��  2019-11-16
  * ��  ��  ���ļ��ṩ��flashӦ�ö�д������
  *
  *********************************************************************
*/
#include"flash.h"

FLASH_ProgramTypeDef flash_write;


/**
  * ����  flash ������д����˫�ֽ����ݣ�д������32λ���ݣ���
  * ����  address�� ָ��flash  ��������ַ
  *  p_FlashBuffer: д�����ݵ�ָ��
  *
  * ����  �ޡ�
  * дflashע��˵����ҳ�����ָ����ַ���ڵ�һҳ128��˫�ֵ�ַ�����ݶ�������
  */
void FLASH_WriteCODE_ONE(uint32_t address,uint32_t *p_FlashBuffer)
{

	//	//--------------------------------------------------------------------------------------------
	//	FLASH_Wipe_Configuration_RAM(FLASH_WIPE_CODE_PAGE,address);//������ҳ��

		flash_write.m_Mode=FLASH_PROGRAM_WORD;//FLASH_PROGRAM_HALF_PAGE //FLASH_PROGRAM_WORD
		flash_write.m_Zone=FLASH_PROGRAM_CODE;//FLASH_PROGRAM_CFG  FLASH_PROGRAM_CODE
		flash_write.m_Addr=address;
		flash_write.m_WriteSize=1;//��ҳ��̲���Ϊ0�����д1��+1��ʵ��д����2��˫�� ���ֱ����Ӱ��
		flash_write.m_Data=p_FlashBuffer;
		FLASH_Program_Configuration_RAM(&flash_write);
}

/*
*
* ��������������ҳ��̣�����ҳ��С�ڰ�ҳ����д�����ݵ�FLASH����������1~63����ַΪҳ���׵�ַ ��ʮ�������½�β000 400 800 C00
* 			�����ַ����ҳ���׵�ַ������ȷ������ҳ���Ϊ0xFFFF����ǰ�������ҳ��д��ʹ������ֵ��0xFFFF������д����쳣��
* ���������address ��д��ַ
*          p_FlashBuffer ��д��ַ������ָ��
*          length        ��д���ݳ���ȡֵ��1~63
*  ��һ��д64λ��˫�ֽڣ��������63ʱ��ʵ�����д�루63+1��*2=128��32λ�����ݣ���û�в������ݣ�ϵͳ�����������һ��д��flash��
* ����          ����
* дflashע��˵����ҳ�����ָ����ַ���ڵ���һҳ128��˫�ֵ�ַ�����ݶ���������
*/
void FLASH_HALFPAGE_WRITECODE_fun(uint32_t address,uint32_t *p_FlashBuffer,uint32_t length)
{

	//	FLASH_Wipe_Configuration_RAM(FLASH_WIPE_CODE_PAGE,address);//������ҳ��

		flash_write.m_Mode=FLASH_PROGRAM_HALF_PAGE;//FLASH_PROGRAM_HALF_PAGE //FLASH_PROGRAM_WORD
		flash_write.m_Zone=FLASH_PROGRAM_CODE;//FLASH_PROGRAM_CFG  FLASH_PROGRAM_CODE
		flash_write.m_Addr=address;
		flash_write.m_WriteSize=length;//��ҳ��̲���Ϊ0�����д1��+1��ʵ��д����2��˫�� ���ֱ����Ӱ��
		flash_write.m_Data=p_FlashBuffer;
		FLASH_Program_Configuration_RAM(&flash_write);
}

/*
*
* ��������������ҳд�����ݵ�FLASH����������ֻ��Ϊ128 ����ַ����Ϊҳ���׵�ַ ��ʮ�������½�β000 400 800 C00
* 			�����ַ����ҳ���׵�ַ������ȷ����������Ϊ0xFFFF����ǰ�����������д��ʹ����ҳֵ��0xFFFF������д����쳣��
* ���������address ��д��ַ
*          p_FlashBuffer ��д��ַ������ָ��
*          length        ��д���ݳ���(��������ֻ��Ϊ128)
* ����          ����
* дflashע��˵����ҳ�����ָ����ַ���ڵ�һҳ128��˫�ֵ�ַ�����ݶ�����������ҳ���ֻ��64��˫�ֽ���д������ҳд��Ҫ�������ΰ�ҳд��
*/
void FLASH_PageWrite_fun(uint32_t address,uint32_t *p_FlashBuffer,uint8_t length)
{
	volatile uint8_t i;
	static uint32_t Flash_Buff1[128];
	static uint32_t Flash_Buff2[128];

	//	//--------------------------------------------------------------------------------------------
		FLASH_Wipe_Configuration_RAM(FLASH_WIPE_CODE_PAGE,address);//������ҳ��

		//--------------------------------------------------------------------------------------------
		for (i = 0; i < length; i++)
		{
			Flash_Buff1[i] =*p_FlashBuffer;
			p_FlashBuffer ++;
		}

		flash_write.m_Mode=FLASH_PROGRAM_HALF_PAGE;//FLASH_PROGRAM_HALF_PAGE //FLASH_PROGRAM_WORD
		flash_write.m_Zone=FLASH_PROGRAM_CODE;//FLASH_PROGRAM_CFG  FLASH_PROGRAM_CODE
		flash_write.m_Addr=address;
		flash_write.m_WriteSize=63;//��ҳ��̲���Ϊ0�����д1��+1��ʵ��д����2��˫�� ���ֱ����Ӱ��
		flash_write.m_Data=Flash_Buff1;
		FLASH_Program_Configuration_RAM(&flash_write);


		for (i = 0; i < length; i++)
		{
			Flash_Buff2[i] = *p_FlashBuffer;
			p_FlashBuffer ++;
		}

		flash_write.m_Mode=FLASH_PROGRAM_HALF_PAGE;//FLASH_PROGRAM_HALF_PAGE //FLASH_PROGRAM_WORD
		flash_write.m_Zone=FLASH_PROGRAM_CODE;//FLASH_PROGRAM_CFG  FLASH_PROGRAM_CODE
		flash_write.m_Addr=address+0x200;
		flash_write.m_WriteSize=63;//��ҳ��̲���Ϊ0�����д1��+1��ʵ��д����2��˫�� ���ֱ����Ӱ��
		flash_write.m_Data=Flash_Buff2;
		FLASH_Program_Configuration_RAM(&flash_write);


}


/**
  * ����  flash �����������ֽ�����
  * ����  address�� ָ��flash��ַ
  *  p_FlashBuffer: д�����ݵ�ָ��
  *
  * ����  �ޡ�
  */
void FLASH_READCODE_fun(uint32_t address,uint32_t *p_FlashBuffer,uint32_t length)
{

	volatile uint32_t read_num;

	for(read_num=0;read_num<length;read_num++)
	{
		*p_FlashBuffer=Read_Flash_or_CFR_RAM(address,FLASH_PROGRAM_CODE);
		p_FlashBuffer++;
		address=address+0x0004;
	}
}






/*******************************************��Ϣ�û�����д����*********************************************/
/**
  * ����  flash ��Ϣ�û���д����˫�ֽ����ݣ�д������32λ���ݣ���
  * ����  address�� ָ��flash�û�����ַ��0x1C00~0X1FF8����ַʮ�������½�β0x1C00 0x1C08  0x1E00 0x1E08
  * p_FlashBuffer: д�����ݵ�ָ��
  *
  * ����  �ޡ�
  * дflashע��˵����ҳ�����ָ����ַ���ڵ�һҳ128��˫�ֵ�ַ�����ݶ�������
  */
void FLASH_WriteCFG_ONE(uint32_t address,uint32_t *p_FlashBuffer)
{

	//	//--------------------------------------------------------------------------------------------
	//	FLASH_Wipe_Configuration_RAM(FLASH_WIPE_CFG_PAGE,address);//������ҳ��

		flash_write.m_Mode=FLASH_PROGRAM_WORD;//FLASH_PROGRAM_HALF_PAGE //FLASH_PROGRAM_WORD
		flash_write.m_Zone=FLASH_PROGRAM_CFG;//FLASH_PROGRAM_CFG  FLASH_PROGRAM_CODE
		flash_write.m_Addr=address;
		flash_write.m_WriteSize=1;//��ҳ��̲���Ϊ0�����д1��+1��ʵ��д����2��˫�� ���ֱ����Ӱ��
		flash_write.m_Data=p_FlashBuffer;
		FLASH_Program_Configuration_RAM(&flash_write);
}

/*
* �������û�����ҳ��̣�����ҳ��С�ڰ�ҳ����д�����ݵ�FLASH����������1~63����ַΪҳ���׵�ַ ��ʮ�������½�β000 400 800 C00
* 			�����ַ����ҳ���׵�ַ������ȷ������ҳ���Ϊ0xFFFF����ǰ�������ҳ��д��ʹ������ֵ��0xFFFF������д����쳣��
* ���������address ָ���û�����ַ��0x1C00~0X1FF8��
*          p_FlashBuffer ��д��ַ������ָ��
*          length        ��д���ݳ���ȡֵ��1~63
*  ��һ��д64λ��˫�ֽڣ��������63ʱ��ʵ�����д�루63+1��*2=128��32λ�����ݣ���û�в������ݣ�ϵͳ�����������һ��д��flash��
* ����          ����
* дflashע��˵����ҳ�����ָ����ַ���ڵ���һҳ128��˫�ֵ�ַ�����ݶ���������
*/
void FLASH_HALFPAGE_WRITECFG_fun(uint32_t address,uint32_t *p_FlashBuffer,uint32_t length)
{

	//	FLASH_Wipe_Configuration_RAM(FLASH_WIPE_CFG_PAGE,address);//������ҳ��

		flash_write.m_Mode=FLASH_PROGRAM_HALF_PAGE;//FLASH_PROGRAM_HALF_PAGE //FLASH_PROGRAM_WORD
		flash_write.m_Zone=FLASH_PROGRAM_CFG;//FLASH_PROGRAM_CFG  FLASH_PROGRAM_CODE
		flash_write.m_Addr=address;
		flash_write.m_WriteSize=length;//��ҳ��̲���Ϊ0�����д1��+1��ʵ��д����2��˫�� ���ֱ����Ӱ��
		flash_write.m_Data=p_FlashBuffer;
		FLASH_Program_Configuration_RAM(&flash_write);
}


/*
*
* �������û�����ҳд�����ݵ�FLASH����������ֻ��Ϊ128 ����ַ����Ϊҳ���׵�ַ ��ʮ�������½�β000 400 800 C00
* 			�����ַ����ҳ���׵�ַ������ȷ����������Ϊ0xFFFF����ǰ�����������д��ʹ����ҳֵ��0xFFFF������д����쳣��
* ���������address ��д��ַ��Ŀǰ���ŵ�ֻ�����һ��PAGE ����׵�ַֻ�ܴ�0x1C00��ʼ
*          p_FlashBuffer ��д��ַ������ָ��
*          length        ��д���ݳ���(��������ֻ��Ϊ128)
* ����          ����
* дflashע��˵����ҳ�����ָ����ַ���ڵ�һҳ128��˫�ֵ�ַ�����ݶ�����������ҳ���ֻ��64��˫�ֽ���д������ҳд��Ҫ�������ΰ�ҳд��
*/
void FLASH_PageWrite_CFG_fun(uint32_t address,uint32_t *p_FlashBuffer,uint8_t length)
{
	volatile uint8_t i;
	static uint32_t Flash_Buff1[128];
	static uint32_t Flash_Buff2[128];

	//	//--------------------------------------------------------------------------------------------
	//	FLASH_Wipe_Configuration_RAM(FLASH_WIPE_CFG_PAGE,address);//��Ϣ�û���ҳ��

		//--------------------------------------------------------------------------------------------
		for (i = 0; i < length; i++)
		{
			Flash_Buff1[i] =*p_FlashBuffer;
			p_FlashBuffer ++;
		}

		flash_write.m_Mode=FLASH_PROGRAM_HALF_PAGE;//FLASH_PROGRAM_HALF_PAGE //FLASH_PROGRAM_WORD
		flash_write.m_Zone=FLASH_PROGRAM_CFG;//FLASH_PROGRAM_CFG  FLASH_PROGRAM_CODE
		flash_write.m_Addr=address;
		flash_write.m_WriteSize=63;//��ҳ��̲���Ϊ0�����д1��+1��ʵ��д����2��˫�� ���ֱ����Ӱ��
		flash_write.m_Data=Flash_Buff1;
		FLASH_Program_Configuration_RAM(&flash_write);


		for (i = 0; i < length; i++)
		{
			Flash_Buff2[i] = *p_FlashBuffer;
			p_FlashBuffer ++;
		}

		flash_write.m_Mode=FLASH_PROGRAM_HALF_PAGE;//FLASH_PROGRAM_HALF_PAGE //FLASH_PROGRAM_WORD
		flash_write.m_Zone=FLASH_PROGRAM_CFG;//FLASH_PROGRAM_CFG  FLASH_PROGRAM_CODE
		flash_write.m_Addr=address+0x200;
		flash_write.m_WriteSize=63;//��ҳ��̲���Ϊ0�����д1��+1��ʵ��д����2��˫�� ���ֱ����Ӱ��
		flash_write.m_Data=Flash_Buff2;
		FLASH_Program_Configuration_RAM(&flash_write);

}


/**
  * ����  flash ������д���ֽ�����
  * ����  address�� ָ��flash��ַ
  *  p_FlashBuffer: д�����ݵ�ָ��
  *
  * ����  �ޡ�
  * ע��д��ǰҪ�Ȳ�����ַ���ڵ�ҳ
  */
void FLASH_WriteByte(uint32_t address,uint8_t p_FlashBuffer)
{
	    uint32_t num32[2];
	    uint32_t *flash_write_num;
	    num32[0]=p_FlashBuffer;
	    num32[1]=0;
		flash_write_num=num32;
		//--------------------------------------------------------------------------------------------

	    flash_write.m_Mode=FLASH_PROGRAM_WORD;//FLASH_PROGRAM_HALF_PAGE //FLASH_PROGRAM_WORD
		flash_write.m_Zone=FLASH_PROGRAM_CODE;//FLASH_PROGRAM_CFG  FLASH_PROGRAM_CODE
		flash_write.m_Addr=address;
		flash_write.m_WriteSize=1;//��ҳ��̲���Ϊ0�����д1��+1��ʵ��д����2��˫�� ���ֱ����Ӱ��
		flash_write.m_Data=flash_write_num;
		FLASH_Program_Configuration_RAM(&flash_write);
}

/**
  * ����  flash ������д��������
  * ����  address�� ָ��flash��ַ
  *  p_FlashBuffer: д�����ݵ�ָ��
  *
  * ����  �ޡ�
  * ע��д��ǰҪ�Ȳ�����ַ���ڵ�ҳ
  */
void FLASH_WriteHalfWord(uint32_t address,uint16_t p_FlashBuffer)
{
	    uint32_t num32[2];
	    uint32_t *flash_write_num;
	    num32[0]=p_FlashBuffer;
	    num32[1]=0;
		flash_write_num=num32;
		//--------------------------------------------------------------------------------------------

	    flash_write.m_Mode=FLASH_PROGRAM_WORD;//FLASH_PROGRAM_HALF_PAGE //FLASH_PROGRAM_WORD
		flash_write.m_Zone=FLASH_PROGRAM_CODE;//FLASH_PROGRAM_CFG  FLASH_PROGRAM_CODE
		flash_write.m_Addr=address;
		flash_write.m_WriteSize=1;//��ҳ��̲���Ϊ0�����д1��+1��ʵ��д����2��˫�� ���ֱ����Ӱ��
		flash_write.m_Data=flash_write_num;
		FLASH_Program_Configuration_RAM(&flash_write);
}

/**
  * ����  flash ������д��������
  * ����  address�� ָ��flash��ַ
  *  p_FlashBuffer: д�����ݵ�ָ��
  *
  * ����  �ޡ�
  * ע��д��ǰҪ�Ȳ�����ַ���ڵ�ҳ
  */
void FLASH_WriteWord(uint32_t address,uint64_t p_FlashBuffer)
{
	    uint32_t num32[2];
	    uint32_t *flash_write_num;
	    num32[0]=p_FlashBuffer;
	    num32[1]=p_FlashBuffer >> 32;
		flash_write_num=num32;
		//--------------------------------------------------------------------------------------------

	    flash_write.m_Mode=FLASH_PROGRAM_WORD;//FLASH_PROGRAM_HALF_PAGE //FLASH_PROGRAM_WORD
		flash_write.m_Zone=FLASH_PROGRAM_CODE;//FLASH_PROGRAM_CFG  FLASH_PROGRAM_CODE
		flash_write.m_Addr=address;
		flash_write.m_WriteSize=1;//��ҳ��̲���Ϊ0�����д1��+1��ʵ��д����2��˫�� ���ֱ����Ӱ��
		flash_write.m_Data=flash_write_num;
		FLASH_Program_Configuration_RAM(&flash_write);
}





/**
  * ����  flash ������д����ֽ�����
  * ����  address�� ָ��flash��ַ
  *  p_FlashBuffer: д�����ݵ�ָ��
  *    leng�����ݵĳ���
  * ����  �ޡ�
  * ע��д��ǰҪ�Ȳ�����ַ���ڵ�ҳ
  */
void FLASH_WriteNByte(uint32_t address,uint8_t *p_FlashBuffer,uint32_t leng)//��ַ����Ϊ��8����
{
	uint32_t i;
	for(i=0;i<leng;i++)//һҳ1024byte������һ��д64bit=8byte��128�������
	{
		FLASH_WriteByte(address,*p_FlashBuffer);//
		p_FlashBuffer++;
		address+=8;
	}
}

/**
  * ����  flash �����������ֽ�����
  * ����  address�� ָ��flash��ַ
  *  p_FlashBuffer: �������ݵ�ָ��
  *
  * ����  read_buf:�������ֽ�����
  *
  */
uint32_t FLASH_ReadByte(uint32_t address,uint8_t *p_FlashBuffer) //��������
{
	uint32_t read_buf;
	read_buf=Read_Flash_or_CFR_RAM(address,FLASH_PROGRAM_CODE);
	*p_FlashBuffer=read_buf;

	return read_buf;
}

/**
  * ����  flash ����������������
  * ����  address�� ָ��flash��ַ
  *  p_FlashBuffer: �������ݵ�ָ��
  *
  * ����  read_buf:������������
  *
  */
uint32_t FLASH_ReadHalWord(uint32_t address,uint16_t *p_FlashBuffer)
{
	uint32_t read_buf;
	read_buf=Read_Flash_or_CFR_RAM(address,FLASH_PROGRAM_CODE);
	*p_FlashBuffer=read_buf;

	return read_buf;
}

/**
  * ����  flash ����������������
  * ����  address�� ָ��flash��ַ
  *  p_FlashBuffer: �������ݵ�ָ��
  *
  * ����  read_buf:������������
  *
  */
uint32_t FLASH_ReadWord(uint32_t address,uint32_t *p_FlashBuffer)
{
	uint32_t read_buf;
	read_buf=Read_Flash_or_CFR_RAM(address,FLASH_PROGRAM_CODE);
	*p_FlashBuffer=read_buf;

	return read_buf;
}

uint64_t FLASH_ReadDWord(uint32_t address,uint64_t *p_FlashBuffer)
{
	uint64_t read_buf;
	read_buf=Read_Flash_or_CFR_RAM(address,FLASH_PROGRAM_CODE);
	*p_FlashBuffer=read_buf;

	return read_buf;
}


/**
  * ����  flash ��������ζ����ֽ�����
  * ����  address�� ָ��flash��ַ
  *  p_FlashBuffer: �������ݵ�ָ��
  *   leng��ָ�����ݳ���
  * ����  ��
  *
  */
void FLASH_ReadNByte(uint32_t address,uint8_t *p_FlashBuffer,uint32_t leng)//��ַ����Ϊ��8����
{
	uint32_t i=0;
	uint32_t read_buf;
	for(i=0;i<leng;i++)//һҳ1024byte������һ��д64bit=8byte��128�������
	{
		read_buf=Read_Flash_or_CFR_RAM(address,FLASH_PROGRAM_CODE);
		*p_FlashBuffer=read_buf;
		p_FlashBuffer++;
		address+=8;
	}
}





























