/*
 * Emios.h
 *
 *  Created on: 2021-9-9
 *      Author: ART
 */

#ifndef _EMIOS_H
#define _EMIOS_H



#include "system_init.h"





#define BACKGROUND(state) GPTIM_Cmd(CCP1_SFR,state);

// pwm����
void PwmInit(void);
void SetBackGround(uint8_t level);

//��ȡƵ��
void CaptureModeInit(void);
void GetCaptureHZ(void);

void BACKGROUND_OFF(void);


//C3�źŵ���
void C3_Sign_OUT(uint16_t speed,uint16_t hundred_meter);



#endif

