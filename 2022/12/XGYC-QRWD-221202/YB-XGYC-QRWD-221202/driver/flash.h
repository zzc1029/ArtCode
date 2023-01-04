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
  * 文件名  flash.h
  * 作  者   ChipON_AE/FAE_Group
  * 版  本  V2.1
  * 日  期  2019-11-16
  * 描  述  该文件提供了flash功能的相关读写函数功能定义
  *
  *********************************************************************
*/
#ifndef FLASH_H_
#define FLASH_H_
#include "system_init.h"

#define Flash_OK                 1
#define Flash_FAIL               0

	//  *                   FLASH_WIPE_CODE_PAGE: 程序区页擦
	//  *                   FLASH_WIPE_CFG_PAGE: 用户配置区页擦
	//  *                   FLASH_WIPE_CODE_ALL: 程序区片擦
//用于擦除数据 1K
//FLASH_Wipe_Configuration_RAM (uint32_t WipeMode,uint32_t WipeAddr);

void FLASH_HALFPAGE_WRITECODE_fun(uint32_t address,uint32_t *p_FlashBuffer,uint32_t length);
void FLASH_PageWrite_fun(uint32_t address,uint32_t *p_FlashBuffer,uint8_t length);
void FLASH_WriteCODE_ONE(uint32_t address,uint32_t *p_FlashBuffer);
void FLASH_READCODE_fun(uint32_t address,uint32_t *p_FlashBuffer,uint32_t length);


void FLASH_WriteCFG_ONE(uint32_t address,uint32_t *p_FlashBuffer);
void FLASH_HALFPAGE_WRITECFG_fun(uint32_t address,uint32_t *p_FlashBuffer,uint32_t length);
void FLASH_PageWrite_CFG_fun(uint32_t address,uint32_t *p_FlashBuffer,uint8_t length);


//地址必须为被8整除
void FLASH_WriteByte(uint32_t address,uint8_t p_FlashBuffer);     //写byte
void FLASH_WriteHalfWord(uint32_t address,uint16_t p_FlashBuffer);//写HalWord
void FLASH_WriteWord(uint32_t address,uint64_t p_FlashBuffer);    //写word
void FLASH_WriteNByte(uint32_t address,uint8_t *p_FlashBuffer,uint32_t leng);//写多Byte

uint32_t FLASH_ReadByte(uint32_t address,uint8_t *p_FlashBuffer);  //读byte
uint32_t FLASH_ReadHalWord(uint32_t address,uint16_t *p_FlashBuffer);//读HalWord
uint32_t FLASH_ReadWord(uint32_t address,uint32_t *p_FlashBuffer);//读Word
void FLASH_ReadNByte(uint32_t address,uint8_t *p_FlashBuffer,uint32_t leng);//读多Byte

//读取8个字节，尝试  
uint64_t FLASH_ReadDWord(uint32_t address,uint64_t *p_FlashBuffer);


#endif /* FLASH_H_ */









#endif


