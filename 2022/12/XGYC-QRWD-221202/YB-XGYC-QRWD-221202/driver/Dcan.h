/*
 * Pcan1.h
 *
 *  Created on: 2021-9-19
 *      Author: ART
 */

#ifndef DCAN_H_
#define DCAN_H_

extern  volatile uint8_t PCanData[][8];


//PCAN 初始化
void DcanInint(void);
void InitDCanSend(void);
//BCAN 发送数据
uint32_t DCan_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);
uint32_t DCan_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len);


// PCAN循环buff
void DCanSendTo(void);

// PCAN 接收函数
void Can1_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);


#endif /* PCAN1_H_ */
