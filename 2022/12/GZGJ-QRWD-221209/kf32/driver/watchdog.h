/*
 * watchdog.h
 *
 *  Created on: 2021-8-4
 *      Author: ART
 */

#ifndef _WATCHDOG_H_
#define _WATCHDOG_H_



#define WWDT_Threshold      0x1F      //�����趨ֵ��ȡֵ��Χ 0~0x3F��
void WWDT_Config_TH(uint32_t Threshold);
void WWDT_Clear(void);




















#endif



