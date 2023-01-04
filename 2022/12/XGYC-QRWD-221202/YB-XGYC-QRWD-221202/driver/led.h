/*
 * led.h
 *
 *  Created on: 2021-11-30
 *      Author: ART
 */

#ifndef LED_H_
#define LED_H_

extern TYPE_WORD ledlogic;

void Ledinit(void);

#define LEFT_WL       ledlogic.bit.b0
#define LBEAM_WL      ledlogic.bit.b1
#define HBEAM_WL      ledlogic.bit.b2
#define FFOG_WL       ledlogic.bit.b3
#define RFOG_WL       ledlogic.bit.b4
#define PARK_WL       ledlogic.bit.b5
#define AIR_LOW_WL    ledlogic.bit.b6
#define FDOOR_WL      ledlogic.bit.b7
#define MDOOR_WL      ledlogic.bit.b8
#define POWER_WL      ledlogic.bit.b9
#define RIGHT_SW      ledlogic.bit.b10

void led_out(void);


#endif /* LED_H_ */
