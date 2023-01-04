/*
 * RS485.h
 *
 *  Created on: 2022-11-15
 *      Author: ART
 */

#ifndef RS485_H_
#define RS485_H_

#define RS485MAXLEN       1<<6

#define RS485TIMEOUT         9     //  数据接收最大100ms为最大时间  timeout 

typedef struct _Rs485Style
{
  uint8_t data[RS485MAXLEN];
  uint8_t disdata[RS485MAXLEN];
  uint8_t len; 
  uint8_t uartReceiveFlag;
  uint8_t timeout;
}RS485Style;

extern RS485Style  rs485style;



#define RS485Send   UartSend

void ConfigRS485(USART_SFRmap *USARTx);

void UartSend(uint8_t *pBuf, uint32_t cnt);
int ReadRS485(void);

#endif /* RS485_H_ */
