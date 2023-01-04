/**
  ******************************************************************************
  *
  * �ļ���  Usart.h
  * ��  ��  ChipON_AE/FAE_Group
  * ��  ��  2019-10-19
  * ��  ��  ���ļ��ṩ�˴�������������ú���
  *
  ******************************************************************************/

#ifndef _USART_H_
#define _USART_H_

extern void USART_Async_config(USART_SFRmap *USARTx);//�����첽ȫ˫������
extern void USART_Sync_config(USART_SFRmap* USARTx);//���ڰ�˫��ͬ������
extern void USART_ReceiveInt_config(USART_SFRmap *USARTx,InterruptIndex Peripheral);//���ڽ����ж�ʹ��
extern void USART_Send(USART_SFRmap* USARTx, uint8_t* Databuf, uint32_t length);//���ڷ��ͺ���
void Usart_line_feed(USART_SFRmap *USARTx);


void UartInitToT123(void);
void TransmitDataTo123(uint8_t *pBuf, uint32_t cnt);
void Uart2Send(uint8_t *pBuf, uint32_t cnt);
#endif /* USART_H_ */
