/*
 * flash.h
 *
 *  Created on: 2021-8-7
 *      Author: ART
 */

#ifndef _FLASH_H_
#define _FLASH_H_






/**
  ********************************************************************
  * �ļ���  flash.h
  * ��  ��   ChipON_AE/FAE_Group
  * ��  ��  V2.1
  * ��  ��  2019-11-16
  * ��  ��  ���ļ��ṩ��flash���ܵ���ض�д�������ܶ���
  *
  *********************************************************************
*/
#ifndef FLASH_H_
#define FLASH_H_
#include "system_init.h"

#define Flash_OK                 1
#define Flash_FAIL               0

	//  *                   FLASH_WIPE_CODE_PAGE: ������ҳ��
	//  *                   FLASH_WIPE_CFG_PAGE: �û�������ҳ��
	//  *                   FLASH_WIPE_CODE_ALL: ������Ƭ��
//���ڲ������� 1K
//FLASH_Wipe_Configuration_RAM (uint32_t WipeMode,uint32_t WipeAddr);

void FLASH_HALFPAGE_WRITECODE_fun(uint32_t address,uint32_t *p_FlashBuffer,uint32_t length);
void FLASH_PageWrite_fun(uint32_t address,uint32_t *p_FlashBuffer,uint8_t length);
void FLASH_WriteCODE_ONE(uint32_t address,uint32_t *p_FlashBuffer);
void FLASH_READCODE_fun(uint32_t address,uint32_t *p_FlashBuffer,uint32_t length);


void FLASH_WriteCFG_ONE(uint32_t address,uint32_t *p_FlashBuffer);
void FLASH_HALFPAGE_WRITECFG_fun(uint32_t address,uint32_t *p_FlashBuffer,uint32_t length);
void FLASH_PageWrite_CFG_fun(uint32_t address,uint32_t *p_FlashBuffer,uint8_t length);


//��ַ����Ϊ��8����
void FLASH_WriteByte(uint32_t address,uint8_t p_FlashBuffer);     //дbyte
void FLASH_WriteHalfWord(uint32_t address,uint16_t p_FlashBuffer);//дHalWord
void FLASH_WriteWord(uint32_t address,uint64_t p_FlashBuffer);    //дword
void FLASH_WriteNByte(uint32_t address,uint8_t *p_FlashBuffer,uint32_t leng);//д��Byte

uint32_t FLASH_ReadByte(uint32_t address,uint8_t *p_FlashBuffer);  //��byte
uint32_t FLASH_ReadHalWord(uint32_t address,uint16_t *p_FlashBuffer);//��HalWord
uint32_t FLASH_ReadWord(uint32_t address,uint32_t *p_FlashBuffer);//��Word
void FLASH_ReadNByte(uint32_t address,uint8_t *p_FlashBuffer,uint32_t leng);//����Byte

//��ȡ8���ֽڣ�����  
uint64_t FLASH_ReadDWord(uint32_t address,uint64_t *p_FlashBuffer);


#endif /* FLASH_H_ */









#endif


