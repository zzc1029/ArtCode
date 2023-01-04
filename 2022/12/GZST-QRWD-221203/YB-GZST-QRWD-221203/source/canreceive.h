/*
 * canreceive.h
 *  计划写入CAN接收函数，直接在中断中调用
 *  Created on: 2021-8-6
 *      Author: ART
 */

#ifndef _CANRECEIVE_H
#define _CANRECEIVE_H

extern volatile uint8_t CanData[][8];
extern volatile uint8_t timeout[];
void CopyData(volatile uint8_t *Des,volatile uint8_t *Souc,uint8_t n);

void ClearCanDataManage(void);

u16 ID(u32 id);

void ClearData(volatile u8* data,u8 ns);
uint16_t GetIndexFromID(uint32_t id);

u32 GetID(CAN_MessageTypeDef CAN_MessageStructrue);

void GeCantData(CAN_MessageTypeDef CAN_MessageStructrue,volatile u8 *data);

void Can0_Rx_Isr(CAN_MessageTypeDef CAN_MessageStructrue);

#endif
