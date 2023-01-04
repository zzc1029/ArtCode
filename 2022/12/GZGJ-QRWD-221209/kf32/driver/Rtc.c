/*
 * Rtc.c
 *
 *  Created on: 2021-9-23
 *      Author: ART
 */

 
#include "system_init.h"
#include "Iic.h"



void RtcInit(void)
{
    iic_init();
//	I2C_GPIO_init();
//	I2C_init_Slave(I2C2_SFR,ISL1208_ADDR);
}

void get_date(void)
{
	//uint8_t tmp_buff[7];

	tmp_buff[0] = read_add(0);
	tmp_buff[1] = read_add(1);
	tmp_buff[2] = read_add(2);
	tmp_buff[3] = read_add(3);
	tmp_buff[4] = read_add(4);
	tmp_buff[5] = read_add(5);
	
    tmp_buff[0] &= 0x7f;   /* seconds */
    tmp_buff[1] &= 0x7f;   /* minutes */
    tmp_buff[2] &= 0x3f;   /* hours */
    tmp_buff[3] &= 0x3f;   /* day-of-month */
    tmp_buff[4] &= 0x1f;   /* month */
    tmp_buff[5] &= 0xff;   /* year */

	rtc.secs   = BCD_TO_BIN(tmp_buff[0]);
    rtc.mins   = BCD_TO_BIN(tmp_buff[1]);
    rtc.hours  = BCD_TO_BIN(tmp_buff[2]);
    rtc.day    = BCD_TO_BIN(tmp_buff[3]);
    rtc.month  = BCD_TO_BIN(tmp_buff[4]);
    rtc.year   = BCD_TO_BIN(tmp_buff[5]);
}

void set_date(void)
{
	uint8_t tmp_buff[7];
	
    tmp_buff[0] = BIN_TO_BCD(rtc.secs);	 	/* seconds */
    tmp_buff[1] = BIN_TO_BCD(rtc.mins);		/* minutes */
    tmp_buff[2] = BIN_TO_BCD(rtc.hours)|0x80;	//set 0x80 ,just for 24 hours mode ;
    tmp_buff[3] = BIN_TO_BCD(rtc.day);		/* day-of-month */
    tmp_buff[4] = BIN_TO_BCD(rtc.month);	/* month */
    tmp_buff[5] = BIN_TO_BCD(rtc.year);		 /* year */

	write_add(0x00,tmp_buff[0]);
	write_add(0x01,tmp_buff[1]);
	write_add(0x02,tmp_buff[2]);
	write_add(0x03,tmp_buff[3]);
	write_add(0x04,tmp_buff[4]);
	write_add(0x05,tmp_buff[5]);
	write_add(0x06,tmp_buff[6]);
//	I2C_Buffer_write(0x00,tmp_buff,6);
}


/*************************************************************************
* Function Name    : config_rtc
* Description		  : this function initializes the RTC module
* Parameters		 : None
* Return Value	 :None
**************************************************************************/
void config_rtc(void)
{
	uint8_t cmd[4] = {0x90,0xc0,0x81,0x00};
	get_date();
	if(rtc.day == 0)
	{
        write_add(0x07,cmd[0]);
		write_add(0x08,cmd[1]);
		write_add(0x0C,cmd[2]);
		write_add(0x00,cmd[3]);

		
		rtc.secs = 6;
		rtc.mins = 46;
		rtc.hours = 15;
		rtc.day = 27;
		rtc.month = 9;
		rtc.year = 21;
		set_date();
	}
}










