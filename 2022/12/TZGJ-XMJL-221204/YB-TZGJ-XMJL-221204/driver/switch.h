/*
 * switch.h
 *
 *  Created on: 2021-8-7
 *      Author: ART
 */

#ifndef _SWITCH_H_
#define _SWITCH_H_




/*Define 74HC165 Pins	*/
#define HC165_PL(state)	  GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_8, state)	//asynchronous parallel load input (active LOW)
#define HC165_CP(state)	  GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_9, state)

//设为输入
#define HC165_Q7		  GPIO_Read_Input_Data_Bit(GPIOC_SFR,GPIO_PIN_MASK_7)		//serial output from the last stage


extern TYPE_WORD port_a;
extern TYPE_WORD port_c;
extern TYPE_WORD port_d;
extern TYPE_WORD port_b;

/*	Port_A */	
#define PTA10  port_a.bit.b0
#define PTA9   port_a.bit.b1
#define PTA8   port_a.bit.b2
#define PTA7   port_a.bit.b3
#define PTA19  port_a.bit.b4
#define PTA12  port_a.bit.b5
#define PTA20  port_a.bit.b6
#define PTE2   port_a.bit.b7



/*	Port_B */	
#define PTB1		port_b.bit.b0
#define PTB2		port_b.bit.b1
#define PTB3		port_b.bit.b2
#define PTB4		port_b.bit.b3
#define PTB5		port_b.bit.b4
#define PTB6		port_b.bit.b5
#define PTB7		port_b.bit.b6
#define PTB8		port_b.bit.b7
#define PTB9		port_b.bit.b8
#define PTB10		port_b.bit.b9
#define PTB11		port_b.bit.b10
#define PTB12		port_b.bit.b11

/*  Port_C  */
#define PTC10  port_c.bit.b0
#define PTC11  port_c.bit.b1
#define PTC12  port_c.bit.b2
#define PTC13  port_c.bit.b3
#define PTC14  port_c.bit.b4
#define PTC15  port_c.bit.b5
#define PTC16  port_c.bit.b6
#define PTC17  port_c.bit.b7
#define PTC18  port_c.bit.b8


//#define PTE2		port_c.bit.b4

/*	Port_D	*/	
#define PTD1		port_d.bit.b0
#define PTD2		port_d.bit.b1
#define PTD3		port_d.bit.b2
#define PTD4		port_d.bit.b3
#define PTD5		port_d.bit.b4
#define PTD6		port_d.bit.b5
#define PTD7		port_d.bit.b6
#define PTD8		port_d.bit.b7
#define PTD9		port_d.bit.b8
#define PTD10		port_d.bit.b9
#define PTD11		port_d.bit.b10
#define PTD12		port_d.bit.b11
#define PTD13		port_d.bit.b12
#define PTD14		port_d.bit.b13
#define PTD15		port_d.bit.b14
#define PTD16		port_d.bit.b15

enum
{
    BYTE1 = 0,
    BYTE2,
    BYTE3,
    BYTE4,
    BYTE5,
    BYTE6,
    BYTE7,
    BYTE8
}; //2 对应CAN报文的字节 BYTE0起始或者BYTE1起始



extern TYPE_QWORD port_mask;
extern TYPE_BYTE sw_input[6];

void HC165PortInit(void);
void switch_task(void);




#endif

