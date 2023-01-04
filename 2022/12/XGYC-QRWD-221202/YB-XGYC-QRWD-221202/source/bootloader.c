/**
	******************************************************************************
	* @file    FW_upgrade/src/command.c
	* @author  MCD Application Team
	* @version V1.0.0
	* @date    28-October-2011
	* @brief   This file provides all the IAP command functions.
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

/* Includes ------------------------------------------------------------------*/
#include "system_init.h"



/** @addtogroup STM32F4-Discovery_FW_Upgrade
	* @{
	*/

uint8_t BootCanDisable = 0;


volatile BLStauts blstatus = BL_Nop;

static  CAN_SFRmap * can_handle = NULL;

static CAN_MessageTypeDef sendframecmd;  //接收报文结构体

static void InitSendFrame()
{
	uint8_t i;
	sendframecmd.m_FrameFormat = CAN_FRAME_FORMAT_SFF;
	sendframecmd.m_RemoteTransmit = CAN_DATA_FRAME;
	sendframecmd.m_DataLength = 8;
	sendframecmd.m_StandardID = SendCmdID;

	for (i = 0; i < 8; i++)
		sendframecmd.m_Data[i] = 0;

}

void BootloaderLoop()
{
	uint8_t i;
	switch (blstatus)
	{
	case BL_Nop: //空转等待命令
		break;
	case BL_GetInfo:
		sendframecmd.m_Data[0] = 0x07;
		sendframecmd.m_Data[1] = 0x05; //模块地址高
		sendframecmd.m_Data[2] = 0x26; //模块地址低

		sendframecmd.m_Data[3] = 0x71; //设备类型  //0x70 表示byd 0x71 表示kf32a
		sendframecmd.m_Data[4] = 0x01; //版本号 1-99
		sendframecmd.m_Data[5] = 0x21;
		sendframecmd.m_Data[6] = 0x12;
		sendframecmd.m_Data[7] = 0x01;
		BCan_Standard_Tx_Bytes(0x52e,sendframecmd.m_Data,8);
	//	CAN_Transmit_Msg(can_handle, &sendframecmd);
		blstatus = BL_Nop;
		break;
	}
}

void BootloaderHandleRxMsg(CAN_MessageTypeDef * RxMessage)
{
	uint8_t i;
	if (RxMessage->m_FrameFormat == CAN_FRAME_FORMAT_SFF)
	{
		if (RxMessage->m_StandardID == RecvCmdID)
		{
			switch (RxMessage->m_Data[0])
			{
			case BLCMD_ToBootStatus:
				FLASH_Wipe_Configuration_RAM(FLASH_WIPE_CODE_PAGE,APPLICATION_ADDRESS);//程序区页擦
				SYSCTL_System_Reset_Enable(TRUE);
				break;
			case BLCMD_GetInfo:
				blstatus = BL_GetInfo;
				break;
			}
		}
		else if((RxMessage->m_StandardID >= 0x520) && (RxMessage->m_StandardID <= 0x525))
		{
			if(RxMessage->m_Data[0] == 3)
				BootCanDisable = 0;
			else
				BootCanDisable = 1;
		}
	}
}

void BootloaderInit(CAN_SFRmap * can)
{
	can_handle = can;
	InitSendFrame();
}

/*******************(C)COPYRIGHT 2011 STMicroelectronics *****END OF FILE******/
