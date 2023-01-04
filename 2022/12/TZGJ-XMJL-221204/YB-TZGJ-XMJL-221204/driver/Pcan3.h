/*
 * Bcan.h
 *
 *  Created on: 2021-9-19
 *      Author: ART
 */

#ifndef PCAN3_H_
#define PCAN3_H_



//volatile extern  uint8_t PCan3Data[][];
//BCAN��ʼ���˿��Լ�����
void Pcan3Inint(void);
void InitPCan3Send(void);
//BCAN ��������
uint32_t PCan3_Expend_Tx_Bytes(uint32_t id,uint8_t * buffer,uint8_t len);
uint32_t PCan3_Standard_Tx_Bytes(uint16_t id,uint8_t * buffer,uint8_t len);
//Bcanѭ�����ͻ���
void PCan3SendTo(void);

//Bcan ���պ���
void Can4_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);

//flash      : ORIGIN =  0x00008000, LENGTH = 0x73400
#endif /* BCAN_H_ */

