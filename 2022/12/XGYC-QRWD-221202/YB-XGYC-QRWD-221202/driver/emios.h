/*
 * emios.h
 *
 *  Created on: 2021-12-2
 *      Author: ART
 */

#ifndef EMIOS_H_
#define EMIOS_H_

//void buzz_init(void);

// pwm…Ë÷√
void PwmInit(void);
void SetBackGround(uint8_t level);
void BACKGROUND_OFF(void);

//C3–≈∫≈
void C3_Sign_OUT(uint16_t speed,uint16_t hundred_meter);


void CaptureModeInit(void);
void GetCaptureHZ(void);


#endif /* EMIOS_H_ */
