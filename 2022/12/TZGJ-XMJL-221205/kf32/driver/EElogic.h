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

		uint8_t  coef;         //���ٵ���ϵ��

		uint8_t  speed_alarm;  //����
        uint8_t  air_alarm;    //��ѹ
		uint8_t  oil_alarm;    //����ѹ��
	    uint8_t  ranyou_alarm; //ȼ�ͱ���
	    uint8_t  air_coef;     //��ѹ����ϵ��
	    uint8_t  air2_coef;
	    BYTE_FIELD  video;
	    uint8_t  fuel_coef;    //ȼ�ϱ���ϵ��
		uint8_t rain_time;     //�����ʱ
	//	uint8_t  coef_2012;    //���ٵ���ϵ��
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
  //CAN ����
  EECANSETBYTE,
  //CAN ���ú������������ȥ
  EECANSETBACK,
}EEstep;


//24c0xһҳ�׵�ַ
#define  ZD24C0xPAGEADD(n)                  16*n
//�����ҳ��ַ
#define  MAINMILEPAGE                       ZD24C0xPAGEADD(mainmilepage)   
//�������ҳ��ַ
#define  BACKUPMILEPAGE                     ZD24C0xPAGEADD(backupmilepage)  

//������ҳ��ַ
#define  MAINPARAPAGEL                      ZD24C0xPAGEADD(mainparal) 
#define  MAINPARAPAGEH                      ZD24C0xPAGEADD(mainparah) 
//���ݲ���ҳ��ַ
#define  BACKUPPARAPAGEL                    ZD24C0xPAGEADD(backupparal) 
#define  BACKUPPARAPAGEH                    ZD24C0xPAGEADD(backupparah) 

#define  EEONEPAGEMAXBYTE                   16

void ZD24C0xReadVehodo(void);

void ZD24C0xReadMeterPara(void);

void WriteEE(void);

void ReadAllZD24c0x(void);

/*
EE(ZD24C08)�滮:1000000������

��ַ0: ODO	L
��ַ1: ODO	H
��ַ2: ODO	HH
��ַ3: ODO	HHH
��ַ4: trip  L
��ַ5: trip  H 
��ַ6: CHECKSUM




//����̱���:
��ַ 8: ODO  L
��ַ 9: ODO  H
��ַ10: ODO  HH
��ַ11: ODO  HHH
��ַ12: trip  L
��ַ13: trip  H 
��ַ14: CHECKSUM


//para:
��ַ 16: switch
��ַ 17: backlight
��ַ 18: pulse	l
��ַ 19: pulse	h
��ַ 20: subi	l
��ַ 21: subi	h
��ַ 22: coef 
��ַ 23: speed_alarm 
��ַ 24: air_alarm 
��ַ 25: oil_alarm 
��ַ 26: ranyou_alarm 
��ַ 27: air_coef 
��ַ 28: air2_coef 
��ַ 29: video 
��ַ 30: fuel_coef 
��ַ 31: rain_time
��ַ 32: resv[]  start
.
.
.
��ַ 46: resv[]  end
��ַ 47: checksum

//para(����):
��ַ 48: switch
��ַ 49: backlight
��ַ 50: pulse	l
��ַ 51: pulse	h
��ַ 52: subi	l
��ַ 53: subi	h
��ַ 54: coef 
��ַ 55: speed_alarm 
��ַ 56: air_alarm 
��ַ 57: oil_alarm 
��ַ 58: ranyou_alarm 
��ַ 59: air_coef 
��ַ 60: air2_coef 
��ַ 61: video 
��ַ 62: fuel_coef 
��ַ 63: rain_time
��ַ 64: resv[]  start
.
.
.
��ַ 78: resv[]  end
��ַ 79: checksum

*/





#endif /* EELOGIC_H_ */
