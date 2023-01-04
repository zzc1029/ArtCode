/*
 * Dcan.h
 *
 *  Created on: 2021-9-19
 *      Author: ART
 */

#ifndef DCAN_H_
#define DCAN_H_


extern volatile uint8_t DCanData[][8];


//DCAN��ʼ���˿��Լ�����
void DcanInint(void);
void InitDCanSend(void);
//DCAN ��������
uint32_t DCan_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);
uint32_t DCan_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len);
//Dcanѭ�����ͻ���
void DCanSendTo(void);



// DCAN���պ���
void Can2_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);









#endif /* DCAN_H_ */
