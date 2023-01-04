/*
 * Bcan.h
 *
 *  Created on: 2021-9-19
 *      Author: ART
 */

#ifndef BCAN_H_
#define BCAN_H_

volatile extern uint8_t BCanData[][8];


//BCAN��ʼ���˿��Լ�����
void BcanInint(void);
void InitBCanSend(void);
//BCAN ��������
uint32_t BCan_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);
uint32_t BCan_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len);
//Bcanѭ�����ͻ���
void BCanSendTo(void);

//Bcan ���պ���
void Can3_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);

//flash      : ORIGIN =  0x00008000, LENGTH = 0x73400
#endif /* BCAN_H_ */

