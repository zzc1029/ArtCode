/**
 *  @file   i51_i2c_gpio.c
 *  @brief  terawins I2C control function
 *  $Id: i51_i2c_gpio.c,v 1.5 2013/04/03 08:27:22 onejoe Exp $
 *  $Author: onejoe $
 *  $Revision: 1.5 $
 *
 *  Copyright (c) 2012 Terawins Inc. All rights reserved.
 * 
 *  @date   2012/11/29  onejoe 	New file.
 *
 */

/*#############################################################################################################

==============================================================

timing diagram
                  .read data  .write data                                         nACK
    __         ______  ______  ______  ______  ______  ______  ______  ______  __________                ___
      \       /  MSB \/      \/      \/      \/      \/      \/      \/      \/ \ ACK /   ......        /
SDA    \_____/\______/\______/\______/\______/\______/\______/\______/\______/   \___/           ______/

   |<-start->|<---------------------------write/read byte------------------------------->|<------->|<-stop->|
...1..2..3...1..2..3.........................................................4..5..67..............12..3
    ______       __      __      __      __      __      __      __      __      __                   ______
          \     /  \    /  \    /  \    /  \    /  \    /  \    /  \    /  \    /  \      ......     /
SCL        \___/  1 \__/  2 \__/  3 \__/  4 \__/  5 \__/  6 \__/  7 \__/  8 \__/ ACK\____        ___/

===============================================================

communication format

|<-D1~D8->|ACK|

0. ack
read data, send ack.
sA: slave ACK
mA: master ACK 

1. write 

|S|<Slave Address(7)>|<w(0)>|<sA>|wDATA1|<sA>|...|P|    

2. read

|S|<Slave Address(7)>|<r(1)>|<sA>|rDATA1|<mA>|...|~mA|P|

3.complex

3.1 read->write

|S|<Slave Address(7)>|<r(1)>|<sA>|rDATA1|<mA>|...|~mA|S|<Slave Address(7)>|<w(0)>|<sA>|wDATA1|<sA>|...|P|

3.2 write->read

|S|<Slave Address(7)>|<w(0)>|<sA>|wDATA1|<sA>|...|S|<Slave Address(7)>|<r(1)>|<sA>|rDATA1|<mA>|...|~mA|P|

4. ilegal

|S|P|    	

===============================================================
terawins function

write reg
|S|<-Slave Address(7)->|w(0)|<sA>|<-Reg Address->|<sA>|<-Reg wVal->|<sA>|<-Reg+1 wVal->|<sA>|...|P|

read reg
|S|<Slave Address(7)>|w(0)|<sA>|<-Reg Address->|<sA>|S|<Slave Address(7)>|r(1)|<sA>|<-Reg rVal->|<mA>|<-Reg+1 rVal->|<mA>|...|~mA|P|

#############################################################################################################*/
#include <reg51.h>

#include "sys.h"
#include "reg_tw.h"
#include "i51_i2c_gpio.h"

/*
 * Synopsis     void io_iIC_start();
 * Description  iicͨӍ��ʼ��ʽ.
 * Parameters   none
 * Return       none
 */
void io_iIC_start(){

#ifdef _iIC_SPEED
	unsigned char c;
#endif
				//for restart
	_wrSDA_H;	//1  prevent create stop condition, SDA first 
	_wrSCL_H;

	_Delay(c);
	_wrSDA_L;	//2
	_Delay(c);
	_wrSCL_L;	//3
	_Delay(c);
	return;		
}

/*
 * Synopsis     void io_iIC_stop();
 * Description  iicͨӍ�Y����ʽ.
 * Parameters   none
 * Return       none
 */
void io_iIC_stop(){

#ifdef _iIC_SPEED
	unsigned char c;
#endif

	_wrSDA_L;	//1 
	_wrSCL_L;

	_wrSCL_H;	//2
	_Delay(c);
	_wrSDA_H;	//3
	_Delay(c);
	return;		
}

/*
 * Synopsis     unsigned char io_iIC_RdByte(unsigned char ack);
 * Description  iic�xȡ 1 byte.
 * Parameters   ack     - �؂�����Ӎ̖
 * Return       none
 */
unsigned char io_iIC_RdByte(unsigned char ack){

#ifdef _iIC_SPEED
	unsigned char c;
#endif
	unsigned char rdData,i;
	
	rdData=0; //init rdData
	i=0;

//	_wrSCL_L; //1
	_wrSDA_H; //release bus
	_Delay(c);
	
	while(1){
		_wrSCL_H;	//2		
		rdData|=_rdSDA;//3
		_Delay(c);
		_wrSCL_L;	//1
		_Delay(c);
		
		if(i>=7){
			break;
		}else{
			rdData<<=1;
			i++;	
		}							   	
	}
//	_wrSCL_L;	//4
//	_Delay(c);

   	if(ack)
		_wrSDA_H;
	else
		_wrSDA_L;

	_wrSCL_H;	//5
	_Delay(c);

	for(i=0;i<_MAX_WAIT;i++){ //wait slave
		if(_SCL_H)
			break;
		_wrSCL_H;	
	}

	_wrSCL_L;	//7
	_Delay(c);
	return rdData;			
}

/*
 * Synopsis     unsigned char io_iIC_wrByte(unsigned char wrData);
 * Description  iic����1 byte.
 * Parameters   wrData      - ���딵ֵ
 * Return       ���ն˽���Ӎ̖
 */
unsigned char io_iIC_wrByte(unsigned char wrData){
#ifdef _iIC_SPEED
	unsigned char c;
#endif

	unsigned char i,ack;
	unsigned char mask=0x80;
	
//	_wrSCL_L;

	for(i=0;i<8;i++){
		_wrSCL_L;	//1

		if(mask&wrData)//write data
			_wrSDA_H;
		else
			_wrSDA_L;

		wrData<<=1;					
		
		_Delay(c);
		_wrSCL_H;	//2
	   	_Delay(c);
			
	}
	_wrSCL_L;		//4
	_Delay(c);
	_wrSCL_H;		//5
	_Delay(c);
	
	for(i=0;i<_MAX_WAIT;i++){ //wait slave
		if(_SCL_H)
			break;
		_wrSCL_H;	
	}

	ack = _rdSDA;	//6
	_wrSCL_L;		//7

//	if(ack)
//		dbg(0, ("can't write!\n"));

	return ack;//return ack			
}

//write arrData[cNum] to slave, addr = cDevAddr

/*
 * Synopsis     unsigned char io_iIC_wrQueue( unsigned char cDevAddr, 
 *                                            unsigned char *arrData, 
 *                                            unsigned char cNum);
 * Description  iic�B�m����.
 * Parameters   cDevAddr		    - ��ͨӍ����λ�� 
 *              arrData		        - �������Y�����ָ��
 *              cNum		        - �Y���L��
 * Return       1/0                 - ���� �ɹ�/ʧ��
 */
unsigned char io_iIC_wrQueue(unsigned char cDevAddr, unsigned char *arrData, unsigned char cNum){
	unsigned char i;

	io_iIC_start();

	if(io_iIC_wrByte(cDevAddr<<1)){
		return 0;
	}

	for(i=0;i<cNum;i++){
		if(!io_iIC_wrByte(*arrData++)){
			return 0;
		}
	}

	io_iIC_stop();
	
	return 1;	
}

//read slave addr = cDevAddr ,storage to arrData[cNum]

/*
 * Synopsis     unsigned char io_iIC_rdQueue( unsigned char cDevAddr, 
 *                                            unsigned char *arrData, 
 *                                            unsigned char cNum);
 * Description  iic�B�m�xȡ.
 * Parameters   cDevAddr		    - ��ͨӍ����λ��
 *              arrData		        - �Y�����ָ��
 *              cNum		        - ���xȡ�Y���L��
 * Return       1/0                 - �xȡ �ɹ�/ʧ��
 */
unsigned char io_iIC_rdQueue(unsigned char cDevAddr, unsigned char *arrData, unsigned char cNum){
	unsigned char i;

	io_iIC_start();

	if(io_iIC_wrByte( (cDevAddr<<1)|0x01 )){
		return 0;
	}
		

	for(i=0;i<cNum-1;i++){
		*arrData++ = io_iIC_RdByte(_ACK);
	}

	*arrData = io_iIC_RdByte(_nACK);

	io_iIC_stop();	
	return 1;
}

/*
 * Synopsis     unsigned char io_iIC_wrReg( unsigned char cDevAddr, 
 *                                          unsigned char cReg, 
 *                                          unsigned char *arrData, 
 *                                          unsigned char cNum);
 * Description  ����T123������(֧Ԯburst).
 * Parameters   cDevAddr		    - ��ͨӍ����λ�� 
 *              cReg		        - ��������̖
 *              arrData		        - �������Y�����ָ��
 *              cNum		        - �Y���L��
 * Return       1/0                 - ���� �ɹ�/ʧ��
 */
unsigned char io_iIC_wrReg(unsigned char cDevAddr, unsigned char cReg, 
						   unsigned char *arrData, unsigned char cNum){
	unsigned char i;

	io_iIC_start();
	
	if(io_iIC_wrByte(cDevAddr)){
		printf_tw("1\n");
		return 0;
	}

	if(io_iIC_wrByte(cReg)){
		printf_tw("2\n");
		return 0;
	}

	for(i=0;i<cNum;i++){
		if(io_iIC_wrByte(arrData[i])){
			printf_tw("3+%bu\n",i);
			return 0;	
		}
			
	}

	io_iIC_stop();	

	return 1;
}

/*
 * Synopsis     unsigned char io_iIC_rdReg( unsigned char cDevAddr, 
 *                                          unsigned char cReg, 
 *                                          unsigned char *arrData, 
 *                                          unsigned char cNum);
 * Description  �xȡT123������(֧Ԯburst).
 * Parameters   cDevAddr		    - ��ͨӍ����λ�� 
 *              cReg		        - ��������̖
 *              arrData		        - �Y�����ָ��
 *              cNum		        - �xȡ�Y���L��
 * Return       1/0                 - �xȡ �ɹ�/ʧ��
 */
unsigned char io_iIC_rdReg(unsigned char cDevAddr, unsigned char cReg, 
						   unsigned char *arrData, unsigned char cNum){
#ifdef _iIC_SPEED
	unsigned char c;
#endif
	unsigned char i;

	io_iIC_start();
	
	if(io_iIC_wrByte(cDevAddr)){
		return 0;	
	}

	if(io_iIC_wrByte(cReg)){
		return 0;	
	}

	_Delay(c);
	io_iIC_start();

	if(io_iIC_wrByte( cDevAddr|0x01 )){
		return 0;	
	}
	
	if(cNum<=0)
		return 0;

	if(cNum > 1){	
		for(i=0;i<cNum-1;i++){
			arrData[i] = io_iIC_RdByte(_ACK);
		}
	}

	arrData[cNum-1] = io_iIC_RdByte(_nACK);

	io_iIC_stop();
	
	return 1;	
}

