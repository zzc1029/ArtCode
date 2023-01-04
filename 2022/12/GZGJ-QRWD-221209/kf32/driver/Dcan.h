/*
 * Dcan.h
 *
 *  Created on: 2021-9-19
 *      Author: ART
 */

#ifndef DCAN_H_
#define DCAN_H_


extern volatile uint8_t DCanData[][8];


//DCAN初始化端口以及缓存
void DcanInint(void);
void InitDCanSend(void);
//DCAN 发送数据
uint32_t DCan_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);
uint32_t DCan_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len);
//Dcan循环发送缓存
void DCanSendTo(void);



// DCAN接收函数
void Can2_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);









#endif /* DCAN_H_ */
