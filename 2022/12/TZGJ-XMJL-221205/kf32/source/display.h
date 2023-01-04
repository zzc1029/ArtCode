/*
 * display.h
 *
 *  Created on: 2021-11-30
 *      Author: ART
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_


#define  normal 0x80
#define  FRONT_MODULE  0X01
#define  REAR_MODULE   0X02
#define  TOP_MODULE    0x03

#define RUNHUA  1


enum
{  	
  	DIS_MAIN_MENU = 0X00,
    DIS_ART_INFORMATION,
    DIS_VCU_MENU,
    DIS_BAT_MENU,
    DIS_BMS_MENU,
    DIS_TMS_MENU,
    DIS_AIR_MENU,
    DIS_FAULT_MENU,
    DIS_EPB_MENU,
	#if RUNHUA
    DIS_RUNHUA_MENU,
    #endif
    DIS_PEIDIANHE_MENU,
    DIS_TAIYA_MENU,
    DIS_MIEHUO_MENU,
    DIS_FACTORY_SET_MENU,
    DIS_SYSTEM_SET_MENU,
    DIS_USED_END, //使用结束标志

    DIS_VEDIO,
    DIS_MAIN,

    DIS_HELP_MENU = 0x80,

    DIS_CHOOSE_MENU

};

enum{
	MODE_ACC,
	MODE_NORMAL,
	MODE_OTHER
};

enum{	
  SET_KEY = 0x80,
  SET_MODE,
  SET_JMP_PAGE
};

enum
{
	PassWordPage = 1, //输入密码界面
	NoEncryptSetPage,  //非保密界面
	EncryptSetPage   //保密设置界面
};


enum{
	PAGE_METER,
	PAGE_FMODE,
	PAGE_RMODE,
	PAGE_TMODE
};

enum{
	PAGE_ARTSET_PASSWORD,
	PAGE_KeHuSET_MILESET,
	PAGE_ARTSET_MILESET
};

enum {
	CMD_DEC_MENU = 1, //增加菜单
	CMD_INC_MENU,     //较小菜单
	CMD_DIS_MENU,     //显示菜单
	CMD_DIS_PAGE,     //显示页面
	CMD_DIS_MAIN,      //显示主页面
	CMD_JMP_PAGE      //显示主页面	
};


enum
{
	PAGE_MAIN = 0x01,
	PAGE_MENU,
	PAGE_ARTAV,
	PAGE_ARTHELP,
	
	PAGE_0X20 = 0x20,
    PAGE_0X21,//21
    PAGE_0X22,//22
    PAGE_0X23,//23
    PAGE_0X24,//24
    PAGE_0X25, //
    PAGE_0X26,//26
    PAGE_0X27,//27
    PAGE_0X28,//28
    PAGE_0X29,//29
    PAGE_0X2A,//2A
    PAGE_0X2B,//2B
    PAGE_0X2C, //2C
	PAGE_0X2D,
	PAGE_0X2E,
	PAGE_0X2F,
	PAGE_0X30,
};

enum
{
    MAIN,
    CHARGE,
    PSTART,
    PSTOP,
    ACCT,
    EP,
    MAINMax,
};


enum
{
  METER,
  FRONTMODULE,
  REARMODULE
};

enum
{
  FAULT0,
  FAULT1,
  FAULT2,
  FAULT3
};

enum
{
  BC0,
  BC1
};

enum BusType
{
  PUBLIC,
  TOURING 
};


void SendPAGE_MAIN04(u8 initpw);
void SendPAGE_MAIN05(u8 initpw);
void SendPAGE_MAIN06(u8 initpw);


typedef struct
{
  u8 box;
  u8 type;
  u8 alarm_level;
  u8 fault_status;
  u8 zifa;
  u8 faultcode;
  u8 changjia;
}MIEHUO;

#define MAX_MIEHUO   15
extern volatile MIEHUO Meihuo[MAX_MIEHUO];
extern volatile uint8_t meihuo_life;
extern volatile uint16_t Get_ID_Off;

extern volatile u8 ReInitDisplayFlag;
extern uint8_t dis_mod;
extern volatile u8 avtest;
extern volatile u8 DCanSendDisablel;
extern u8 Send_To_DP_Data[12];
extern u8 errcodemix[7];
extern u8 p_status[];
extern u8 p_cur[];
extern u8 p_temp[];
extern u8 switch24;

//安徽阿瑞特探测器设置报文
void InitDisplay();



#endif /* DISPLAY_H_ */
