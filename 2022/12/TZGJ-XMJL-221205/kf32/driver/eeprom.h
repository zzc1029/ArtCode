/*
 * eeprom.h
 *
 *  Created on: 2021-8-7
 *      Author: ART
 */

#ifndef _EEPROM_H
#define _EEPROM_H

#define DEFAULTDATA 0XFFFFFFFF



// ��̴洢�׵�ַ  0X0007B400 - 0X0007F400  �ܵ�16k  ���ڴ洢������Լ�С�����
#define EEPROMMILEADDR        0X0007B400

//��̴洢����ַ
#define MILEENDADDR          (EEPROMPARAADR - 16) //(EEPROMPARAADR - 16)

// �Ǳ�����׵�ַ ���ֲ���(��ѹϵ�������ٱ�����) 1K�ռ�
#define EEPROMPARAADR         0X0007F400
//�Ǳ������β�˵�ַ
#define PARAENDADR            (EEPROMMILECHECKADDR - 64)

//�������ݳ���
#define PARALEN               32

//��̲���check�׵�ַ   ���ڲ�����̹����б���������ö�ʧ�������
#define EEPROMMILECHECKADDR   0X0007F800
//����check�׵�ַ       �����Ǳ���ֲ����������ݱ��ⶪʧ����
#define EEPROMPARACHECKADDR   0X0007FC00

//���������壬���ڲ����趨�������������Լ�����̣���ֹ��������̫��
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
		uint8_t  resv[9];
        uint8_t  checksum;
    } Data;
} EEPROMDataStru;

extern EEPROMDataStru  MeterPara;


//����1K FLASH�ռ�
#define  ERASEPAGE(add)\
{\
	DisableIRQ();\
	FLASH_Wipe_Configuration_RAM (FLASH_WIPE_CODE_PAGE,add);\
	EnableIRQ();\
}	
// ��ȡ��Ӧ��ַ������
uint32_t  ReadAdd(uint32_t address);
// ��һ����ַ������д��2��32λ����
uint32_t WriteDlong(uint32_t address,uint32_t data1,uint32_t data2);

extern uint8_t     Air_Alarm,Speed_Alarm,Oil_Alarm,Ranyou_Alarm,Air_Coef,Air2_Coef,Coef;
extern uint8_t     Rain_Delay_Time,Fuel_Coef;
extern uint8_t     backlight_level,Bus_Type;
extern uint16_t    odometer_const,odometer_const_2012,Pulse;

extern uint8_t     Set_Air_Alarm,Set_Speed_Alarm,Set_Oil_Alarm,Set_Ranyou_Alarm,Set_Air_Coef,Set_Air2_Coef,Set_Coef;
extern uint8_t     Set_Rain_Delay_Time,Set_Fuel_Coef;
extern uint8_t     Set_backlight_level,Set_Bus_Type;
extern uint16_t    Set_odometer_const,Set_odometer_const_2012,Set_Pulse;
extern uint8_t     Set_buzz,Coef_2012,Oil_Alarm_2012;


#define ReadData64 FLASH_ReadDWord

//��ȡ���������
uint32_t ReadVehodo(void);
//���������
uint32_t SaveVehodo(void);
//�������������
void EraseMile(void);


uint32_t ReadMeterPara(void);
uint32_t SaveMeterPara(void);



//����
uint32_t ReadBlockPara(uint32_t addr);

uint32_t WriteDlong(uint32_t address,uint32_t data1,uint32_t data2);

enum
{
  NORMAL = 0,
  SPEED_0
};

//save odo
void SaveODO(void);



// ������
void FLASH_PageWrite_fun(uint32_t address,uint32_t *p_FlashBuffer,uint8_t length);
// д��  Ҳ����
void FLASH_READCODE_fun(uint32_t address,uint32_t *p_FlashBuffer,uint32_t length);

#endif





