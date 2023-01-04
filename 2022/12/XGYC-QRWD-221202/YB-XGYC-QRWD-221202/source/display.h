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

//FUNC_MENU(DIS_VCU_MENU, {});


#define FUNC_MENU(menu,op)           \
    u32 Menu##menu(u8 key, u8 initpw)   \
    {                                   \
        if (initpw)                     \
        {                               \
            SendKeyToGPU(CMD_DIS_PAGE); \
        }                               \
        op;                             \
        if (key == IN_KEY1_SP)          \
        {                               \
            return DIS_CHOOSE_MENU;     \
        }                               \
        return menu;                    \
    }


#define FUNC_ITEM(menu)  Menu##menu,menu

enum
{  	
	DIS_MAIN_MENU = 0X00,
    DIS_ART_INFORMATION,
    DIS_VCU_MENU,  
    DIS_MCU_MENU,
    DIS_BMS_MENU,
    DIS_BATCELL_MENU,
    DIS_FUZU_MENU, 
    DIS_PARAM_MENU,   
    DIS_TMS_MENU,
    DIS_MIEHUO_MENU,
    //DIS_ZHONGKONGPING_MENU,  
    DIS_AP_MENU,
    //DIS_ECAS_MENU,
    DIS_RUNHUA_MENU,
    DIS_TAIYA_MENU,
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
#if (Has_Fmode == ON) 
	PAGE_FMODE,
#endif
#if (Has_Rmode == ON) 
	PAGE_RMODE,
#endif
#if (Has_Tmode == ON) 
	PAGE_TMODE
#endif

};

enum{
	PAGE_ARTSET_PASSWORD,
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
	//PAGE_ARTHELP,
	
	PAGE_0X20 = 0x20,
	PAGE_0X21,
	PAGE_0X22,
	PAGE_0X23,
	PAGE_0X24,
	PAGE_0X25,
	PAGE_0X26,
	PAGE_0X27,
	PAGE_0X28,
	PAGE_0X29,
	PAGE_0X2A,
	PAGE_0X2B,
	PAGE_0X2C,
	PAGE_0X2D,
	PAGE_0X2E,
	PAGE_0X2F,
	PAGE_0X30,
	PAGE_0X31,
	PAGE_0X32,
	PAGE_0X33,
	PAGE_0X34,
	PAGE_0X35,
};

enum
{
    MAIN,
    CHARGE,
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



extern volatile u8 ReInitDisplayFlag;
extern uint8_t dis_mod;
extern volatile u8 avtest;
extern volatile u8 DCanSendDisablel;
extern u8 Send_To_DP_Data[12];



extern volatile u8 DCDC1[8],DriverOperateStatus,OnOffStatus;
extern volatile u8 _0C04A1A7_DATA[8],_0C06A1A7_DATA[8],_0C09A1A7_DATA[8],_181AD0F3_DATA[8],_181BD0F3_DATA[8];
extern volatile u8 _181CD0F3_DATA[8],_181DD0F3_DATA[8],_181ED0F3_DATA[8]; 
extern volatile u8 _0C0CA7F2_DATA[8],_0C0AA7F0_DATA[8],_0C08A7F4_DATA[8],_180AA7A3_DATA[8];
extern volatile u8 _180BA7A3_DATA[8],_180CA7A3_DATA[8],_0C01A70A_DATA[8],_0C02A70A_DATA[8],_0C03A70A_DATA[8];
extern volatile u8 _0C04A70A_DATA[8],_1818D0F3_DATA[8],_1819D0F3_DATA[8],_18EFA1A5_DATA[8]; 
extern volatile u8 _180028F3_DATA[8],_180128F3_DATA[8],_180228F3_DATA[8],_180328F3_DATA[8],_180428F3_DATA[8];
extern volatile u8 _180528F3_DATA[8],_180028F4_DATA[8],_180128F4_DATA[8];
extern volatile u8 _180228F4_DATA[8],_180328F4_DATA[8],_0CFFF3A7_DATA[8],_0CFEEC21_DATA[8];
extern volatile u8 EngineWaterTemp,EngineLoad,EngineTatgetAccelerator,EngineActualAccelerator,VCU_Life,EngineInputAirTemp,FuelConsumption_Instant;
extern volatile u16 EngineSpeed,scr,oil_prss,shunshigonglv,FuelConsumption_100KM_Subtotal,FuelConsumption_100KM_Acctotal,shengyugonglv,Motor_Current;
extern volatile u32 OilAccumulation;
extern volatile u8 VCUSofeVersion[8],ECUSofeVersion[8],EECUSofeVersion[8],SystemMode,SystemStatus,xuedimoshi,qianyinli;
extern volatile u16 can_err_time,SystemCode;
extern volatile u8 DrivingRange,baigongli[2],AlarmFlag[4],E_MotorError[4],BmsMonoData[5][8],DebugData[8];


extern volatile TYPE_BYTE AIR[8],YUN_TONG[8],fuzhu[8],add1[8],add2[8],add3[8];
extern volatile u8 ECASFault[40];




typedef struct{
	unsigned int ivoltage;//电机电压
	unsigned int icurrent;//电机电流
	unsigned int itorque;//电机转矩
	
	unsigned int ispeed;//电机转速
	unsigned char itemp;//电机温度
	unsigned char etemp;//发电机温度
	//unsigned int imubiaochuanju;
	unsigned char iversion[8];
}bus_motor;
extern volatile bus_motor MOTOR;


typedef struct{
	unsigned char itemp;//控制器温度
	unsigned char etemp;//发电机控制器温度
	unsigned char iversion[8];//版本
	unsigned int ifault_code;//故障代码
	unsigned char ifault_level;//故障等级
	unsigned char ibus_model;//整车模式
	unsigned char ilife;//控制器life
	unsigned char K_control;//能量主接触器等
	unsigned char iready;//ready信号等
	unsigned char igear;//档位
	unsigned char iswitching;//爬坡等开关
	unsigned char icharge;//充电确认
}bus_control;
extern volatile bus_control CONTROL;


typedef struct{
	unsigned char ispeed_up;//加速踏板
	unsigned char ibraking;//制动踏板
}footboard;
extern volatile footboard STEP;

typedef struct{
	u16 voltage_out;
	u16 current;
	u16 voltage_input;
	u8 temp;
	u8 faultcode;
}dcdc;
extern volatile dcdc DC_DC;


typedef struct{
	unsigned int ivoltage;//电池总电压
	unsigned int icadc;//充放电电流
	unsigned char isoc;//soc
	unsigned char istatus[3];//状态标志
	unsigned int imax_charge;//最大允许充电电流
	unsigned int imax_discharge;//最大允许放电电流
	unsigned char isystem_fault;//锂电池故障等级
	unsigned int iaverage_voltage;//平均电压值
	unsigned char imono_max_temp;//单体最高温度
	unsigned int itotal_anode_riso;//总正绝缘电阻值
	unsigned int itotal_cathode_riso;//总负绝缘电阻值
	unsigned int imono_max_voltage;//单体最大电压
	unsigned int imono_min_voltage;//单体最小电压
	unsigned char VIN;
	unsigned char status_flag4;
	unsigned char ChargeOutletTemp1;
	unsigned char ChargeOutletTemp2;
	unsigned char ChargeOutletTemp3;
	unsigned char ChargeOutletTemp4;
	unsigned char error_total;
	unsigned char status_flag5;
	unsigned int  rated_capacity;
	unsigned int  rated_voltage;
	unsigned int  battery_series_num;
	unsigned char battery_parallel_num;
	unsigned char temp_sensor_num;
	unsigned char imono_max_temp_2;
	unsigned char maxtemp_pos_x;
	unsigned char maxtemp_pos_y;
	unsigned char imono_min_temp;
	unsigned char mintemp_pos_x;
	unsigned char mintemp_pos_y;
	unsigned char battery_typeinfo;
	unsigned char battery_cooling_methods;

	unsigned char maxvol_pos_x;
	unsigned char maxvol_pos_y;
	unsigned char minvol_pos_x;
	unsigned char minvol_pos_y;
	
	
}battery;
extern volatile battery BMS;

typedef struct{
	unsigned int inumber[10];//单体电压编号
	unsigned int ivoltage[10];//单体电压
	unsigned char isampl_number[10];//单体采样点编号
	unsigned char itemp[10];//单体采样点温度
}mono_battery;
extern volatile mono_battery BMS_MONO;

typedef struct{
	unsigned char box[10];
	unsigned char type[10];
	unsigned char alarm_level[10];
	unsigned char fault_status[10];
	unsigned char zifa_status[10];
	unsigned char fault_code[10];
	unsigned char rolling_count[10];
}miehuo;
extern volatile miehuo MIEHUO;

void InitDisplay();


#endif /* DISPLAY_H_ */
