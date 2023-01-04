/*
 * Bcan.h
 *
 *  Created on: 2021-9-19
 *      Author: ART
 */

#ifndef PCAN3_H_
#define PCAN3_H_



//volatile extern  uint8_t PCan3Data[][];
//BCAN初始化端口以及缓存
void Pcan3Inint(void);
void InitPCan3Send(void);
//BCAN 发送数据
uint32_t PCan3_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);
uint32_t PCan3_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len);
//Bcan循环发送缓存
void PCan3SendTo(void);

//Bcan 接收函数
void Can4_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);

//flash      : ORIGIN =  0x00008000, LENGTH = 0x73400
#endif /* BCAN_H_ */

