/**
  ******************************************************************************
  *
  * 文件名  Usart.h
  * 作  者  ChipON_AE/FAE_Group
  * 日  期  2019-10-19
  * 描  述  该文件提供了串口例程相关配置函数
  *
  ******************************************************************************/

#ifndef _USART_H_
#define _USART_H_

extern void USART_Async_config(USART_SFRmap *USARTx);//串口异步全双工配置
extern void USART_Sync_config(USART_SFRmap* USARTx);//串口半双工同步配置
extern void USART_ReceiveInt_config(USART_SFRmap *USARTx,InterruptIndex Peripheral);//串口接收中断使能
extern void USART_Send(USART_SFRmap* USARTx, uint8_t* Databuf, uint32_t length);//串口发送函数
void Usart_line_feed(USART_SFRmap *USARTx);


void UartInitToT123(void);
void TransmitDataTo123(uint8_t *pBuf, uint32_t cnt);
void Uart2Send(uint8_t *pBuf, uint32_t cnt);
#endif /* USART_H_ */
