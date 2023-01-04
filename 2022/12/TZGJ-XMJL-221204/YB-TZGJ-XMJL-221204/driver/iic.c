/*
 * iic.c
 *
 *  Created on: 2021-8-10
 *      Author: ART
 PF0 :IICSCL     I2C2_SCL   AF8
 PB15:IICSDA     I2C2_SDA
 */



 
#include "system_init.h"
#include "Iic.h"


#define   MS  10
 
void delay_(volatile unsigned int ms)
{
   while(ms--)
   	;
}
void iic_init(void)
{
  SDA_output();
  SCL_output();

  SDA(SET);
  SCL(SET);
}
 
 void start(void)
 {
   SDA(SET);
   delay_(MS);
   SCL(SET);
   delay_(MS);
   SDA(RESET);
   delay_(MS);
 }

void stop(void)
{
  SDA(RESET);
  delay_(MS);
  SCL(SET);
  delay_(MS);
  SDA(SET);
  delay_(MS);
}
 
 void respons(void)
 {
   volatile unsigned int i;
   SCL(SET);
   SDA_input();
   delay_(MS);
   while((READ_SDA == 1) && (i < 255))
	 i++;
   SCL(RESET);
   delay_(MS);
   SDA_output();
 }

 void write_byte(unsigned char date)
 {
   unsigned char i ,temp;
   temp = date;
   for(i = 0;i < 8;i++)
   {
	  SCL(RESET);
	  delay_(MS);
	  if((temp&0x80) == 0x80)
	    SDA(SET);
	  else
	    SDA(RESET);	
	  temp = temp<<1;
	  delay_(MS);
	  SCL(SET);
	  delay_(MS);
   }
   SCL(RESET);
   delay_(MS);
   SDA(SET);
   delay_(MS);
 }


 unsigned char read_byte(void)
 {
   unsigned char i,k;
   SCL(RESET);
   SDA_output();
   delay_(MS);
   SDA(SET);
   delay_(MS);
   SDA_input();
   delay_(MS);
   for(i = 0;i < 8; i++)
   {
	 SCL(SET);
	 delay_(MS);
	 k = (k<<1)|READ_SDA;
	 SCL(RESET);
	 delay_(MS);
   }
   SDA_output();
   return k;
 }


 void write_add(unsigned char address,unsigned char date)
 {
   start();
   write_byte(ISL1208_ADDR);
   respons();
   write_byte(address);
   respons();
   write_byte(date);
   respons(); 
   stop();
 }


 unsigned char read_add(unsigned char address)
 {
   unsigned char date;
   start();
   write_byte(ISL1208_ADDR);
   respons();
   write_byte(address);
   respons(); 
   start();
   write_byte(ISL1208_ADDR |0x01);
   respons();  
   date = read_byte();
   stop();
   return date;
 }










