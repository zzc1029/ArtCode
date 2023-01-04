/*
 * eeprom.h
 *
 *  Created on: 2021-8-7
 *      Author: ART
 */

#ifndef _EEPROM_H
#define _EEPROM_H

#define DEFAULTDATA 0XFFFFFFFF



// 里程存储首地址  0X0007B400 - 0X0007F400  总的16k  用于存储总里程以及小计里程
#define EEPROMMILEADDR        0X0007B400

//里程存储最后地址
#define MILEENDADDR          (EEPROMPARAADR - 16) //(EEPROMPARAADR - 16)

// 仪表参数首地址 各种参数(气压系数、超速报警灯) 1K空间
#define EEPROMPARAADR         0X0007F400
//仪表参数最尾端地址
#define PARAENDADR            (EEPROMMILECHECKADDR - 64)

//参数数据长度
#define PARALEN               32

//里程参数check首地址   用于擦除里程过程中保护数据免得丢失里程数据
#define EEPROMMILECHECKADDR   0X0007F800
//参数check首地址       用于仪表各种参数保护数据避免丢失数据
#define EEPROMPARACHECKADDR   0X0007FC00

//参数联合体，用于参数设定，不包括单次以及总里程，防止擦除次数太多
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
		uint8_t  resv[9];
        uint8_t  checksum;
    } Data;
} EEPROMDataStru;

extern EEPROMDataStru  MeterPara;


//擦除1K FLASH空间
#define  ERASEPAGE(add)\
{\
	DisableIRQ();\
	FLASH_Wipe_Configuration_RAM (FLASH_WIPE_CODE_PAGE,add);\
	EnableIRQ();\
}	
// 读取对应地址上数据
uint32_t  ReadAdd(uint32_t address);
// 在一个地址上连续写入2个32位数据
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

//获取总里程数据
uint32_t ReadVehodo(void);
//保存总里程
uint32_t SaveVehodo(void);
//擦除总里程数据
void EraseMile(void);


uint32_t ReadMeterPara(void);
uint32_t SaveMeterPara(void);



//测试
uint32_t ReadBlockPara(uint32_t addr);

uint32_t WriteDlong(uint32_t address,uint32_t data1,uint32_t data2);

enum
{
  NORMAL = 0,
  SPEED_0
};

//save odo
void SaveODO(void);



// 可试试
void FLASH_PageWrite_fun(uint32_t address,uint32_t *p_FlashBuffer,uint8_t length);
// 写入  也试试
void FLASH_READCODE_fun(uint32_t address,uint32_t *p_FlashBuffer,uint32_t length);

#endif





