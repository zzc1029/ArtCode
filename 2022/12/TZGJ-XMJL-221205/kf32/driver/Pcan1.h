/*
 * Dcan.h
 *
 *  Created on: 2021-9-19
 *      Author: ART
 */

#ifndef PCAN1_H_
#define PCAN1_H_


//extern volatile uint8_t DCanData[][8];


//DCAN��ʼ���˿��Լ�����
void Pcan1Inint(void);
void InitPCan1Send(void);
//DCAN ��������
uint32_t PCan1_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);
uint32_t PCan1_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len);
//Dcanѭ�����ͻ���
void PCan1SendTo(void);



// DCAN���պ���
void Can2_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);









#endif /* DCAN_H_ */
