/**
  ******************************************************************************
  * �ļ��� canhl.h
  * ��  ��  ChipON_AE/FAE_Group
  * ��  ��  2019-10-19
  * ��  ��  ���ļ��ṩ��CAN����ʹ�õı����뺯��
  ******************************************************************************/

#ifndef _CANH_H_
#define _CANH_H_

#define 	xCAN_ACR    (uint32_t)0x00000000;  //���մ���
#define 	xCAN_MSK 	(uint32_t)0xffffffff;  //��������


//������
typedef enum
{
    //CAN_BAUDRATE_125K = 0,   //!<baudrate 125K
    CAN_BAUDRATE_125K = 1,   //!<baudrate 250K
    CAN_BAUDRATE_250K = 2,   //!<baudrate 500K
    CAN_BAUDRATE_500K   = 3    //!<baudrate 1M
} CAN_BaudRateT;

//CAN���ͺ�������ֵ
typedef enum
{
    CAN_ERROR_NOERROR = 0,			 //!<return no error
    CAN_ERROR_BUFFERFULL=1,
    CAN_WAIT_SEND
} CAN_ErrorT;

//ȫ�ֱ�������

//��������
//void xGPIO_CAN();
//void xINT_CAN(CAN_SFRmap* CANx);
void xInit_CAN(CAN_SFRmap* CANx,uint8_t Bdrt,uint32_t MODE);
void CanInit(void);
//���ͱ�׼����֡
uint32_t Can_Standard_Tx_Bytes( uint16_t id,uint8_t * buffer,uint8_t len);
//������չ����֡
uint32_t Can_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);




CAN_ErrorT CAN_Transmit_DATA(CAN_SFRmap* CANx,   //CANͨ��
						uint32_t  TargetID,		 //ID
						uint8_t*  data ,   	     //����ָ��
						uint8_t   lenth,   		 //����
						uint32_t  MsgType, 		 //֡����        CAN_DATA_FRAME����֡                     CAN_REMOTE_FRAMEԶ��֡
						uint32_t  RmtFrm   		 //֡��ʽ        CAN_FRAME_FORMAT_SFF��׼֡     CAN_FRAME_FORMAT_EFF��չ֡
						);
void Can1SendFifo(void);
void InitCan1Send(void);

#endif /* _CANHL_H_ */
