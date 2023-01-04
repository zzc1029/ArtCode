/**
  ******************************************************************************
  * 文件名 canhl.h
  * 作  者  ChipON_AE/FAE_Group
  * 日  期  2019-10-19
  * 描  述  该文件提供了CAN例程使用的变量与函数
  ******************************************************************************/

#ifndef _CANH_H_
#define _CANH_H_

#define 	xCAN_ACR    (uint32_t)0x00000000;  //验收代码
#define 	xCAN_MSK 	(uint32_t)0xffffffff;  //验收屏蔽


//波特率
typedef enum
{
    //CAN_BAUDRATE_125K = 0,   //!<baudrate 125K
    CAN_BAUDRATE_125K = 1,   //!<baudrate 250K
    CAN_BAUDRATE_250K = 2,   //!<baudrate 500K
    CAN_BAUDRATE_500K   = 3    //!<baudrate 1M
} CAN_BaudRateT;

//CAN发送函数返回值
typedef enum
{
    CAN_ERROR_NOERROR = 0,			 //!<return no error
    CAN_ERROR_BUFFERFULL=1,
    CAN_WAIT_SEND
} CAN_ErrorT;

//全局变量声明

//函数声明
//void xGPIO_CAN();
//void xINT_CAN(CAN_SFRmap* CANx);
void xInit_CAN(CAN_SFRmap* CANx,uint8_t Bdrt,uint32_t MODE);
void CanInit(void);
//发送标准数据帧
uint32_t Can_Standard_Tx_Bytes( uint16_t id,uint8_t * buffer,uint8_t len);
//发送扩展数据帧
uint32_t Can_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);




CAN_ErrorT CAN_Transmit_DATA(CAN_SFRmap* CANx,   //CAN通道
						uint32_t  TargetID,		 //ID
						uint8_t*  data ,   	     //数据指针
						uint8_t   lenth,   		 //长度
						uint32_t  MsgType, 		 //帧类型        CAN_DATA_FRAME数据帧                     CAN_REMOTE_FRAME远程帧
						uint32_t  RmtFrm   		 //帧格式        CAN_FRAME_FORMAT_SFF标准帧     CAN_FRAME_FORMAT_EFF扩展帧
						);
void Can1SendFifo(void);
void InitCan1Send(void);

#endif /* _CANHL_H_ */
