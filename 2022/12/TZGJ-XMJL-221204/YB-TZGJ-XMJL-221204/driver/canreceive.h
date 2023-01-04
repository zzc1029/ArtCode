/*
 * canreceive.h
 *  计划写入CAN接收函数，直接在中断中调用
 *  Created on: 2021-8-6
 *      Author: ART
 */

#ifndef _CANRECEIVE_H
#define _CANRECEIVE_H

extern volatile uint8_t CanData[][8];
extern uint8_t timeout[];
void CopyData(volatile uint8_t *Des,volatile uint8_t *Souc,uint8_t n);

void ClearCanDataManage(void);

extern u32 Pcan1GetIDFromIndex(u16 index);

void ClearData(volatile u8* data,u8 ns);
uint16_t Pcan1GetIndexFromID(uint32_t id);

#define  GetIndexFromID Pcan1GetIndexFromID
#define  ID             Pcan1GetIndexFromID

u32 GetID(CAN_MessageTypeDef CAN_MessageStructrue);

void GeCantData(CAN_MessageTypeDef CAN_MessageStructrue,volatile u8 *data);

void Can2_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);

#endif
