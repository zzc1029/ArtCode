/**
  ******************************************************************************
  * @file    FW_upgrade/inc/command.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    28-October-2011
  * @brief   Header file for command.c
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _BOOTLOADEROVERCAN_H
#define _BOOTLOADEROVERCAN_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "system_init.h"
/* Includes ------------------------------------------------------------------*/

typedef enum
{
	BL_Nop,		   //等待命令
	BL_ToBoot,     //切换boot模式
	BL_GetInfo	   //获取版本信息
} BLStauts;

typedef enum
{
	BLCMD_ToBootStatus = 5,	//切换boot模式
	BLCMD_GetInfo,	  //查询版本号和其它信息
} BLCmd;


#define RecvCmdID 0x526
#define SendCmdID 0x52E
#define RecvDataID 0x52D
#define SendDataID 0x52F

#define BCAN  CAN3_SFR  //PE1-2   1C4
#define PCAN1 CAN0_SFR  //PA2-3   1C1
#define PCAN2 CAN1_SFR  //PA4-5   1C3
#define PCAN3 CAN2_SFR  //PA11-12 1C2

#define PAGE_SIZE 0x400

#define APPLICATION_ADDRESS 0x08000
#define APPLICATION_END_ADDRESS 0x80000

extern volatile BLStauts blstatus;


void BootloaderInit(CAN_SFRmap* can);
void BootloaderLoop(void);
void BootloaderHandleRxMsg(CAN_MessageTypeDef * RxMessage);

#ifdef __cplusplus
}
#endif

#endif /* _COMMAND_H */

/*******************(C)COPYRIGHT 2011 STMicroelectronics *****END OF FILE******/
