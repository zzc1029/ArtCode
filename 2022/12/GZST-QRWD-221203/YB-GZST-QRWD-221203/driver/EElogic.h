/*
 * EElogic.h
 *
 *  Created on: 2022-5-11
 *      Author: ART
 */

#ifndef EELOGIC_H_
#define EELOGIC_H_


typedef union
{
    BYTE_FIELD databit1[16];
    uint8_t data8[16];
    uint16_t data16[8];
    struct
    {
        uint32_t odo;
        uint16_t trip;
		uint8_t  resv[9];
        uint8_t  checksum;
    } Data;
} EEDataStru;


typedef union
{
  uint8_t data8[8];
  struct
  {
    uint8_t cmd;
	uint8_t  setdata;
    uint16_t addr;
	uint8_t  resv[3];
	uint8_t  checksum;
  }Data;
}EECan;

typedef union
{
    BYTE_FIELD databit1[32];
    uint8_t data8[32];
    uint16_t data16[16];
    uint32_t data32[8];
	uint64_t data64[4];
    struct
    {
        BYTE_FIELD Switch;
        uint8_t backlight;

        uint16_t pulse;

        uint16_t subi;
        uint16_t trip;

		uint8_t  coef;         //车速调整系数

		uint8_t  speed_alarm;  //超速
        uint8_t  air_alarm;    //气压
		uint8_t  oil_alarm;    //机油压力
	    uint8_t  ranyou_alarm; //燃油报警
	    uint8_t  air_coef;     //气压比例系数
	    uint8_t  air2_coef;
	    BYTE_FIELD  video;
	    uint8_t  fuel_coef;    //燃料比例系数
		uint8_t rain_time;     //雨刮延时
	//	uint8_t  coef_2012;    //车速调整系数
    //    uint16_t subi_2012;
		uint8_t  resv[13];
        uint8_t  checksum;
    } Data;
} EEParaStru;


extern 	void DelayKong(volatile uint32_t a, volatile uint32_t b);

extern  TYPE_BYTE  EEflag;
extern  EECan      CanSetEEByte;

#define EEODOFLAG  EEflag.bit.b0
#define EEPARAFLAG EEflag.bit.b1
#define EECANFLAG  EEflag.bit.b2


#define  EEWRITECMD    1
#define  EEREADCMD     2


#define  ZD24C0xDeceiveInit()              ZD_iic_init()
#define  ZD24c0xWriteByte(addr,data)       ZD_write_add(addr,data)
#define  ZD24c0xReadByte(addr)             ZD_read_add(addr)


#define  ZD24c0xWriteBytes(addr,data,len)   ZD_write_bytes(addr,data,len)
#define  ZD24c0xReadBytes(addr,data,len)    ZD_read_bytes(addr,data,len)

#define  ZD24c0xWritePage(addr,data)        ZD_write_bytes(addr,data,16)
#define  ZD24c0xReadPage(addr,data)         ZD_read_bytes(addr,data,16)

#define  ZD24c0xReadPages(addr,data,n)      ZD_read_bytes(addr,data,16*n)

#define  ZD24c0xReadAllPages(addr,data)     ZD_read_bytes(addr,data,1024)

enum
{
  mainmilepage = 16,
  backupmilepage,
  mainparal,
  mainparah,
  backupparal,
  backupparah,
};

typedef enum
{
  EENOP,
  EEMAINODO,
  EEBACKUPODO,
  EEMAINPARAL,
  EEMAINPARAH,
  EEBACKPARAL,
  EEBACKPARAH,
  //CAN 设置
  EECANSETBYTE,
  //CAN 设置后读出，反馈出去
  EECANSETBACK,
}EEstep;


//24c0x一页首地址
#define  ZD24C0xPAGEADD(n)                  16*n
//主里程页地址
#define  MAINMILEPAGE                       ZD24C0xPAGEADD(mainmilepage)   
//备份里程页地址
#define  BACKUPMILEPAGE                     ZD24C0xPAGEADD(backupmilepage)  

//主参数页地址
#define  MAINPARAPAGEL                      ZD24C0xPAGEADD(mainparal) 
#define  MAINPARAPAGEH                      ZD24C0xPAGEADD(mainparah) 
//备份参数页地址
#define  BACKUPPARAPAGEL                    ZD24C0xPAGEADD(backupparal) 
#define  BACKUPPARAPAGEH                    ZD24C0xPAGEADD(backupparah) 

#define  EEONEPAGEMAXBYTE                   16

void ZD24C0xReadVehodo(void);

void ZD24C0xReadMeterPara(void);

void WriteEE(void);

void ReadAllZD24c0x(void);

/*
EE(ZD24C08)规划:1000000次寿命

地址0: ODO	L
地址1: ODO	H
地址2: ODO	HH
地址3: ODO	HHH
地址4: trip  L
地址5: trip  H 
地址6: CHECKSUM




//总里程备份:
地址 8: ODO  L
地址 9: ODO  H
地址10: ODO  HH
地址11: ODO  HHH
地址12: trip  L
地址13: trip  H 
地址14: CHECKSUM


//para:
地址 16: switch
地址 17: backlight
地址 18: pulse	l
地址 19: pulse	h
地址 20: subi	l
地址 21: subi	h
地址 22: coef 
地址 23: speed_alarm 
地址 24: air_alarm 
地址 25: oil_alarm 
地址 26: ranyou_alarm 
地址 27: air_coef 
地址 28: air2_coef 
地址 29: video 
地址 30: fuel_coef 
地址 31: rain_time
地址 32: resv[]  start
.
.
.
地址 46: resv[]  end
地址 47: checksum

//para(备份):
地址 48: switch
地址 49: backlight
地址 50: pulse	l
地址 51: pulse	h
地址 52: subi	l
地址 53: subi	h
地址 54: coef 
地址 55: speed_alarm 
地址 56: air_alarm 
地址 57: oil_alarm 
地址 58: ranyou_alarm 
地址 59: air_coef 
地址 60: air2_coef 
地址 61: video 
地址 62: fuel_coef 
地址 63: rain_time
地址 64: resv[]  start
.
.
.
地址 78: resv[]  end
地址 79: checksum

*/





#endif /* EELOGIC_H_ */
