/*
 * typedef.h
 *
 *  Created on: 2021-11-29
 *      Author: ART
 */

#ifndef TYPEDEF_H_
#define TYPEDEF_H_

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef int s16;

typedef struct
{
	unsigned char b0:1;
	unsigned char b1:1;
	unsigned char b2:1;
	unsigned char b3:1;
	unsigned char b4:1;
	unsigned char b5:1;
	unsigned char b6:1;
	unsigned char b7:1;
} BYTE_FIELD;

typedef struct
{
	unsigned char bits0:2;
	unsigned char bits1:2;
	unsigned char bits2:2;
	unsigned char bits3:2;
} Bits_FIELD;


typedef union
{
	unsigned char byte;
	BYTE_FIELD	bit;
	Bits_FIELD  bits;
} TYPE_BYTE;




typedef struct
{
	unsigned short b0:1;
	unsigned short b1:1;
	unsigned short b2:1;
	unsigned short b3:1;
	unsigned short b4:1;
	unsigned short b5:1;
	unsigned short b6:1;
	unsigned short b7:1;
	unsigned short b8:1;
	unsigned short b9:1;
	unsigned short b10:1;
	unsigned short b11:1;
	unsigned short b12:1;
	unsigned short b13:1;
	unsigned short b14:1;
	unsigned short b15:1;
} WORD_FIELD;

typedef union
{
	unsigned short word;
	unsigned char byte[2];
	WORD_FIELD bit;
} TYPE_WORD;

typedef struct
{
	unsigned int b31:1;
	unsigned int b30:1;
	unsigned int b29:1;
	unsigned int b28:1;
	unsigned int b27:1;
	unsigned int b26:1;
	unsigned int b25:1;
	unsigned int b24:1;
	unsigned int b23:1;
	unsigned int b22:1;
	unsigned int b21:1;
	unsigned int b20:1;
	unsigned int b19:1;
	unsigned int b18:1;
	unsigned int b17:1;
	unsigned int b16:1;
	unsigned int b15:1;
	unsigned int b14:1;
	unsigned int b13:1;
	unsigned int b12:1;
	unsigned int b11:1;
	unsigned int b10:1;
	unsigned int b9:1;
	unsigned int b8:1;
	unsigned int b7:1;
	unsigned int b6:1;
	unsigned int b5:1;
	unsigned int b4:1;
	unsigned int b3:1;
	unsigned int b2:1;
	unsigned int b1:1;
	unsigned int b0:1;
} DWORD_FIELD;

typedef struct
{
	unsigned short b0:2;
	unsigned short b1:2;
	unsigned short b2:2;
	unsigned short b3:2;
	unsigned short b4:2;
	unsigned short b5:2;
	unsigned short b6:2;
	unsigned short b7:2;
	unsigned short b8:2;
	unsigned short b9:2;
	unsigned short b10:2;
	unsigned short b11:2;
	unsigned short b12:2;
	unsigned short b13:2;
	unsigned short b14:2;
	unsigned short b15:2;
} DWORD_FIELD_2bit;


typedef union
{
	unsigned int dword;
	unsigned char byte[4];
	DWORD_FIELD	bit;
	DWORD_FIELD_2bit BIT;
} TYPE_DWORD;



typedef struct
{
	unsigned long long b63:1;
	unsigned long long b62:1;
	unsigned long long b61:1;
	unsigned long long b60:1;
	unsigned long long b59:1;
	unsigned long long b58:1;
	unsigned long long b57:1;
	unsigned long long b56:1;
	unsigned long long b55:1;
	unsigned long long b54:1;
	unsigned long long b53:1;
	unsigned long long b52:1;
	unsigned long long b51:1;
	unsigned long long b50:1;
	unsigned long long b49:1;
	unsigned long long b48:1;
	unsigned long long b47:1;
	unsigned long long b46:1;
	unsigned long long b45:1;
	unsigned long long b44:1;
	unsigned long long b43:1;
	unsigned long long b42:1;
	unsigned long long b41:1;
	unsigned long long b40:1;
	unsigned long long b39:1;
	unsigned long long b38:1;
	unsigned long long b37:1;
	unsigned long long b36:1;
	unsigned long long b35:1;
	unsigned long long b34:1;
	unsigned long long b33:1;
	unsigned long long b32:1;
	unsigned long long b31:1;
	unsigned long long b30:1;
	unsigned long long b29:1;
	unsigned long long b28:1;
	unsigned long long b27:1;
	unsigned long long b26:1;
	unsigned long long b25:1;
	unsigned long long b24:1;
	unsigned long long b23:1;
	unsigned long long b22:1;
	unsigned long long b21:1;
	unsigned long long b20:1;
	unsigned long long b19:1;
	unsigned long long b18:1;
	unsigned long long b17:1;
	unsigned long long b16:1;
	unsigned long long b15:1;
	unsigned long long b14:1;
	unsigned long long b13:1;
	unsigned long long b12:1;
	unsigned long long b11:1;
	unsigned long long b10:1;
	unsigned long long b9:1;
	unsigned long long b8:1;
	unsigned long long b7:1;
	unsigned long long b6:1;
	unsigned long long b5:1;
	unsigned long long b4:1;
	unsigned long long b3:1;
	unsigned long long b2:1;
	unsigned long long b1:1;
	unsigned long long b0:1;
} QWORD_FIELD;

typedef union
{
	unsigned long long qword;
	TYPE_BYTE byte[8];
	QWORD_FIELD	bit;
} TYPE_QWORD;


typedef struct
{
	unsigned long long b0:1;
	unsigned long long b1:1;
	unsigned long long b2:1;
	unsigned long long b3:1;
	unsigned long long b4:1;
	unsigned long long b5:1;
	unsigned long long b6:1;
	unsigned long long b7:1;
	unsigned long long b8:1;
	unsigned long long b9:1;
	unsigned long long b10:1;
	unsigned long long b11:1;
	unsigned long long b12:1;
	unsigned long long b13:1;
	unsigned long long b14:1;
	unsigned long long b15:1;
	unsigned long long b16:1;
	unsigned long long b17:1;
	unsigned long long b18:1;
	unsigned long long b19:1;
	unsigned long long b20:1;
	unsigned long long b21:1;
	unsigned long long b22:1;
	unsigned long long b23:1;
	unsigned long long b24:1;
	unsigned long long b25:1;
	unsigned long long b26:1;
	unsigned long long b27:1;
	unsigned long long b28:1;
	unsigned long long b29:1;
	unsigned long long b30:1;
	unsigned long long b31:1;
	unsigned long long b32:1;
	unsigned long long b33:1;
	unsigned long long b34:1;
	unsigned long long b35:1;
	unsigned long long b36:1;
	unsigned long long b37:1;
	unsigned long long b38:1;
	unsigned long long b39:1;
	unsigned long long b40:1;
	unsigned long long b41:1;
	unsigned long long b42:1;
	unsigned long long b43:1;
	unsigned long long b44:1;
	unsigned long long b45:1;
	unsigned long long b46:1;
	unsigned long long b47:1;
	unsigned long long b48:1;
	unsigned long long b49:1;
	unsigned long long b50:1;
	unsigned long long b51:1;
	unsigned long long b52:1;
	unsigned long long b53:1;
	unsigned long long b54:1;
	unsigned long long b55:1;
	unsigned long long b56:1;
	unsigned long long b57:1;
	unsigned long long b58:1;
	unsigned long long b59:1;
	unsigned long long b60:1;
	unsigned long long b61:1;
	unsigned long long b62:1;
	unsigned long long b63:1;

} QQWORD_FIELD;

typedef union
{
	unsigned long long qword;
	unsigned char byte[8];
	QQWORD_FIELD	bit;
} TYPE_QQWORD;


typedef struct
{
   uint16_t MeterA2;
   uint16_t MeterA3;
   uint16_t MeterA4;
   uint16_t MeterA13;
   uint16_t MeterA14;
   uint16_t MeterA15;
   uint16_t MeterA5;
}Meter;



typedef struct
{
    uint8_t secs;
    uint8_t mins;
    uint8_t hours;
    uint8_t day;
    uint8_t month;
    uint8_t year;
    uint8_t week;
}rtc_t;

#define GetByteLSB0(data) ((unsigned char)((data) >> 0))
#define GetByteLSB1(data) ((unsigned char)((data) >> 8))

#define GetU32LEData(l,ml,mh,h) ((((uint32_t)h)<<24)+(((uint32_t)mh)<<16)+(((uint32_t)ml)<<8)+l)

#define GetU16BE(x,y)  ((((uint16_t)x[y])<<8)+x[y+1])
#define GetU16LE(x,y)  ((((uint16_t)x[y+1])<<8)+x[y])

#define GetU16BEData(xl,xh)  ((((uint16_t)xl)<<8)+xh)
#define GetU16LEData(xl,xh)  ((((uint16_t)xh)<<8)+xl)

#define GetU16Low(x)	(((x)>>0)&0xFF)
#define GetU16High(x) 	(((x)>>8)&0xFF)

#define TestBitTrue(byte,bit)    (((byte) & (1<<(bit))) > 0)
#define TestBitFalse(byte,bit)    (((byte) & (1<<(bit))) == 0)


#define GetBits(byte,offset,bits)    (((byte)>>(offset)) & ((1<<(bits))-1))

//byte 被比较的数据所在的变量，offset 被比较的数据的起始位，bits被比较的数据位长度，comp 比较的值
#define TestBits(byte,offset,bits,comp)    (((byte) & (((1<<(bits))-1) << (offset))) == ((comp)<<(offset)))

#define BCD_TO_BIN(val) (((val)&0x0F) + ((val)>>4)*10)
#define BIN_TO_BCD(val) ((((val)/10)<<4) + (val)%10)


#define   TonyTestBits(id,pos,offset,bits,comp)       TestBits(CanData[ID(id)][pos],offset,bits,comp)
#define   TonyTestBitTrue(id,pos,bit)                 TestBitTrue(CanData[ID(id)][pos],bit)




#endif /* TYPEDEF_H_ */
