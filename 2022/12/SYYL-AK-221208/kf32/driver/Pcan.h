/*
 * Pcan1.h
 *
 *  Created on: 2021-9-19
 *      Author: ART
 */

#ifndef PCAN1_H_
#define PCAN1_H_

extern  volatile uint8_t PCanData[][8];


//PCAN ��ʼ��
void PcanInint(void);
void InitPCanSend(void);
//BCAN ��������
uint32_t PCan_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);
uint32_t PCan_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len);


// PCANѭ��buff
void PCanSendTo(void);

// PCAN ���պ���
void Can1_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);


#endif /* PCAN1_H_ */
