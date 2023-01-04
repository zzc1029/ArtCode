/*
 * Bcan.h
 *
 *  Created on: 2021-9-19
 *      Author: ART
 */

#ifndef PCAN2_H_
#define PCAN2_H_

//volatile extern uint8_t PCan2Data[][8];


//PCAN2初始化端口以及缓存
void Pcan2Inint(void);
void InitPCan2Send(void);
//BCAN 发送数据
uint32_t PCan2_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);
uint32_t PCan2_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len);
//Bcan循环发送缓存
void PCan2SendTo(void);

//Bcan 接收函数
void Can3_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);

//flash      : ORIGIN =  0x00008000, LENGTH = 0x73400
#endif /* BCAN_H_ */

