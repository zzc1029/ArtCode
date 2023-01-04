

#ifndef _AEBS_H
#define _AEBS_H
//extern u8 add1[8],add2[8],add3[8],add4[8],add5[8],chedao;
#if 0
extern TYPE_BYTE Symbol_Data6,Symbol_Data7,AEBS_FLAG;

#define Symbol_Data6_1  Symbol_Data6.bit.b7
#define Symbol_Data6_2  Symbol_Data6.bit.b6
#define Symbol_Data6_3  Symbol_Data6.bit.b5
#define Symbol_Data6_4  Symbol_Data6.bit.b4
#define Symbol_Data6_5  Symbol_Data6.bit.b3
#define Symbol_Data6_6  Symbol_Data6.bit.b2
#define Symbol_Data6_7  Symbol_Data6.bit.b1
#define Symbol_Data6_8  Symbol_Data6.bit.b0

#define Symbol_Data7_1  Symbol_Data7.bit.b7
#define Symbol_Data7_2  Symbol_Data7.bit.b6
#define Symbol_Data7_3  Symbol_Data7.bit.b5
#define Symbol_Data7_4  Symbol_Data7.bit.b4
#define Symbol_Data7_5  Symbol_Data7.bit.b3
#define Symbol_Data7_6  Symbol_Data7.bit.b2
#define Symbol_Data7_7  Symbol_Data7.bit.b1
#define Symbol_Data7_8  Symbol_Data7.bit.b0

#define AEBS_PEDE_STA   AEBS_FLAG.bit.b0



/**************************       EBS      *********************/

#define ADD_E_BREAK1       ((add1[0]&0XC0)==0X40)
#define ADD_E_BREAK2       ((add2[1]&0X03)==0X01)
#define ESC_BREAK          (ADD_E_BREAK1||ADD_E_BREAK2)//刹车开关  点亮制动灯

#define EBS_SW_R             ((add1[5]&0X0C) == 0X04)
#define EBS_SW_Y             ((add1[5]&0X30) == 0X10)
#define ABS_SW_Y             (((add1[5]&0X30) == 0X10) && ((add1[5]&0X03) == 0X00))
#define ASR_SW_Y             ((add1[2]&0X0C) == 0X04)
#define ASR_SW_BLINK         ((add1[0]&0X03) == 0X01) ||((add1[0]&0X0C) == 0X04)


#define ESC_NORMAL           (((add3[0]&0X03)==0X01) && ((add3[0]&0X0C)==0X04))
#define ESC_FAULT            (((add3[0]&0X03)==0X01) && ((add3[0]&0X0C)==0X00))


#define ZUO_LDW         ((chedao&0X40)  == 0X40)
#define YOU_LDW         ((chedao &0X80)  == 0X80)

//*********************************************************************/

//#define BREAK_ALL           (BREAK_SW||ELEC_BREAK||ESC_BREAK)


/**************************       AEBS      *********************/

#define FCW_FAULT				((((add5[0])&0x0F) ==0x05)||(((add5[0])&0x0F)  == 0x06)||(((add5[0])&0x0F) ==0x07))

#define AEBS_FAULT				(((add5[0]&0x0F) == 0x0E)||((add5[0]&0x0F) == 0x0F))
#define AEBS_CLOSE				((add5[0]&0x0F) == 0x02)

#define PCW_NORMAL				((add4[1]&0xF0) == 0x00)
#define PCW_LV				     ((add4[1]&0xF0) == 0x10)
#define PCW_YELLOW				((add4[1]&0xF0) == 0x20)
#define PCW_RED				    ((add4[1]&0xF0) == 0x30)


#define AEBS_SW				    F_SW_P36
#define ESC_SW				    F_SW_P22
#define AEBS_PEDE_SW		    F_SW_P37



void Aebs_Symbol(void);
void J1939_Can_Aebs(void); 


#endif

#endif







