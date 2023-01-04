/*
 * Rtc.h
 *
 *  Created on: 2021-9-23
 *      Author: ART
 */

#ifndef RTC_H_
#define RTC_H_

void RtcInit(void);
void get_date(void);
void set_date(void);

void config_rtc(void);
uint8_t is_leap_year(void);
extern const uint8_t days_in_mo[13];

#endif /* RTC_H_ */
