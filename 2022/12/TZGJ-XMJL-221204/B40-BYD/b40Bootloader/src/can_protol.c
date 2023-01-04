#include "includes.h"
#include "can_protol.h"
#include "switch.h"
#include "canhl.h"
#include "BF7006AMxx_eflash.h"

#define RecvCmdID 0x530
#define SendCmdID 0x52E
#define RecvDataID 0x531
#define SendDataID 0x52F


typedef enum
{
	BLCMD_Erease = 1, 
	BLCMD_EreaseOK,	  
	BLCMD_ProgramEnd, 
	BLCMD_SetAddr,	  
	BLCMD_Null,		  
	BLCMD_GetInfo,	 
} BLCmd;


can_frame cantx;
can_frame candatatx;

can_frame canrx;

uint32_t startaddress = 0;

uint8_t CanRecvData[8];

void InitSendFrame()
{
	uint8_t i;
	cantx.ext = CAN_STANDARD_FRAME;
	cantx.rtr = CAN_DATA_FRAME;
	cantx.len = 8;
	cantx.id = SendCmdID;

	for (i = 0; i < 8; i++)
		cantx.data[i] = 0;

	candatatx.ext = CAN_STANDARD_FRAME;
	candatatx.rtr = CAN_DATA_FRAME;
	candatatx.len = 8;
	candatatx.id = SendDataID;

	for (i = 0; i < 8; i++)
		candatatx.data[i] = 0;
}

int protothread_can_recv(struct pt *pt)
{
	PT_BEGIN(pt);

	int i;

	while (1)
	{
		PT_WAIT_UNTIL(pt, can_frame_received());		
		
    can_recv_frame(&canrx);

		if (canrx.ext == 1)
		{
			continue;
		}

		for (i = 0; i < 8; i++)
			CanRecvData[i] = canrx.data[i];

		if (canrx.id == boot_funcid)
		{
			switch (CanRecvData[0])
			{
			case BLCMD_SetAddr:
				startaddress = CanRecvData[7] + (((uint32_t)CanRecvData[6]) << 8) + (((uint32_t)CanRecvData[5]) << 16) + (((uint32_t)CanRecvData[4]) << 24);
						
        for (i = 0; i < 8; i++)
					cantx.data[i] = CanRecvData[i];
				cantx.data[0] = BLCMD_SetAddr;
				can_send_frame(&cantx);			
				break;
			
			case BLCMD_GetInfo:				
				cantx.data[0] = 0x06;
				cantx.data[1] = boot_funcid>>8;
				cantx.data[2] = boot_funcid&0xFF;
				cantx.data[3] = 0x70; 
				cantx.data[4] = 0x01; 
				cantx.data[5] = 0x21;
				cantx.data[6] = 0x05;
				cantx.data[7] = 0x10;
				can_send_frame(&cantx);
				break;
			
			case BLCMD_Erease:				
				for (i = 0; i < 8; i++)
					cantx.data[i] = CanRecvData[i];
				can_send_frame(&cantx);
		
				PT_YIELD(pt);
			
				if (flash_Nsectors_erase((APP_START_ADDR >> 10), APP_MAX_LEN / FLASH_SECTOR_SIZE) == SUCCESS)
				{
						for (i = 0; i < 8; i++)
							cantx.data[i] = 0;
						cantx.data[0] = BLCMD_EreaseOK;
						can_send_frame(&cantx);
						break;
				}

				for (i = 0; i < 8; i++)
					cantx.data[i] = 0xFF;
				cantx.data[0] = BLCMD_EreaseOK;
				break;
				
			case BLCMD_ProgramEnd:
				for (i = 0; i < 8; i++)
						cantx.data[i] = CanRecvData[i];
				can_send_frame(&cantx);
				
				flash_prog_word(PASSWORD_ADDR, DefaultPassword);
				NVIC_SystemReset();
				break;
			}

			break;
		}
		else if (canrx.id == boot_dataid)
		{
			if ((startaddress < APP_START_ADDR) || (startaddress >= (APP_START_ADDR + APP_MAX_LEN)))
			{
					for (i = 0; i < 8; i++)
					{
						candatatx.data[i] = 0;
					}
					can_send_frame(&candatatx);
			}
			else
			{
					flash_prog_Nwords(startaddress, (uint32_t *)CanRecvData, 2);
				
					for (i = 0; i < 8; i++)
					{
						candatatx.data[i] = *((uint8_t *)startaddress);
						startaddress++;
					}
					can_send_frame(&candatatx);
			}

			break;
		}
		/* And we loop. */
	}
	PT_END(pt);
}
