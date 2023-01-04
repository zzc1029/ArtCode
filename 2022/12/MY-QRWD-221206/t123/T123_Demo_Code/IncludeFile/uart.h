#ifndef __UART_H__
#define __UART_H__
#include "disp_config.h"

#define CMD_MAX				0x08

//数据类型
enum
{
	UART1_MAIN_PAGE = 1,
	UART1_MENU_PAGE,
	UART1_LOGO_PAGE,
	UART1_PARA_PAGE,
	UART1_HELP_PAGE,
	UART1_VIDEO_PAGE,
	UART1_METER_PAGE,
	UART1_FRONT_PAGE,
	UART1_REAR_PAGE,
	UART1_TOP_PAGE,
	UART1_FRONT_OUT_PAGE,
	UART1_REAR_OUT_PAGE,
	UART1_TOP_OUT_PAGE,

	UART1_SURFACE1_PAGE = 0x20,
	UART1_SURFACE2_PAGE,
	UART1_SURFACE3_PAGE,
	UART1_SURFACE4_PAGE,
	UART1_SURFACE5_PAGE,
	UART1_SURFACE6_PAGE,
	UART1_SURFACE7_PAGE,
	UART1_SURFACE8_PAGE,
	UART1_SURFACE9_PAGE,
	UART1_SURFACE10_PAGE,
	UART1_SURFACE11_PAGE,
	UART1_SURFACE12_PAGE,
	UART1_SURFACE13_PAGE,
	UART1_SURFACE14_PAGE,
	UART1_SURFACE15_PAGE,
	UART1_SURFACE16_PAGE,
	UART1_SURFACE17_PAGE,
	UART1_SURFACE18_PAGE,
	UART1_SURFACE19_PAGE,
	UART1_SURFACE20_PAGE,
	UART1_SURFACE21_PAGE,
	
};
enum
{
	PAGE_PASSWORD = 1,
	PAGE_PARA,
	PAGE_SET
};
enum
{
	MAIN_MARK = 0x90,
	MAIN_MILE,
	MAIN_TIME,
	MAIN_DATA,
};
enum
{
	UART1_GENERAL_DATA =	0x80,
	GD_ALARM,
	GD_PAGE_CHANGE
};

typedef struct {
	unsigned char year;
	unsigned char month;
	unsigned char day;
	unsigned char hour;
	unsigned char minute;
}SYS_TIME;
extern SYS_TIME system_time;

typedef struct {
	unsigned char odo[7];
	unsigned short trip;
}SYS_MEILAGE;
extern SYS_MEILAGE system_meilage;

typedef struct {
	unsigned int number;
	unsigned char index;
	unsigned int last_number;
	unsigned char last_index;
}SYS_ALARM;
extern SYS_ALARM system_alarm;

typedef struct {
	unsigned char air1;
	unsigned char air2;
	unsigned char soc;
	unsigned char last_air1;
	unsigned char last_air2;
	unsigned char last_soc;
}SYS_AIR;
extern SYS_AIR system_air;

typedef struct {
	unsigned char last_page;
	unsigned char current_page;
}SYS_PAGE;
extern SYS_PAGE system_page;

typedef struct {
	unsigned char blink;
	unsigned char para[44];
}SYS_BLINK;
typedef struct {
	unsigned char blink;
	unsigned char para[4];
}SYS_BLINK1;
typedef struct {
	unsigned char blink;
	unsigned char para[11];
}SYS_BLINK2;
extern SYS_BLINK1 system_b_password;
extern SYS_BLINK system_b_odo_char;
extern SYS_BLINK2 system_b_set;

extern unsigned char buzzer,mark2,mark3;
extern unsigned char uart_cmd,dandu_disp,para_cmd;
extern unsigned long mark_door;
extern unsigned char menu,page_xuanze;
extern unsigned int speed_scale,baimi_pulse;
extern unsigned char system_bright,scale_factor;//liangdu
extern unsigned char system_video;//tv1-4
extern unsigned char status_para_change;
extern unsigned int meter_status[4];
extern unsigned int meter_para_A2,meter_para_A3,meter_para_A4,meter_para_A5,meter_para_A13,meter_para_A14,meter_para_A15,meter_para_K;
extern unsigned char i_temp[CMD_MAX],i_put,i_get,i_len;
#if MODULE_FRONT_B40
extern unsigned int front_status[4];
extern unsigned int front_para_A25,front_para_A40,front_para_A26;
#endif
#if MODULE_REAR_B40
extern unsigned int rear_status[4];
extern unsigned int rear_para_A25,rear_para_A40,rear_para_A26;
#endif
#if MODULE_TOP_B40
extern unsigned int top_status[4];
extern unsigned int top_para_A25,top_para_A40,top_para_A26;
#endif
#if MODULE_FRONT_B50
extern unsigned int front_status[2],front_para[7];
extern unsigned int front_out_status[6];
#endif
#if MODULE_REAR_B50
extern unsigned int rear_status[2],rear_para[7];
extern unsigned int rear_out_status[6];
#endif
#if MODULE_TOP_B50
extern unsigned int top_status[2],top_para[7];
extern unsigned int top_out_status[6];
#endif
extern unsigned char air1_factor,air2_factor,speed_alarm,air_alarm,oil_alarm,fuel_alarm,vedio_enable[5],yugua_time;//设置增加
extern unsigned char wiper_sec;
//---------------------------------------------------------------------------------------------------
extern unsigned char li_battery_level,system_status;
extern unsigned int xudianchi_voltage,system_code,xushi_trip,motor_zhuansu,tms_fault_code;
extern int total_voltage,total_current;

extern unsigned int dongli_input_voltage;
extern int dongli_input_current;
extern unsigned char siji_status,onoff_status,bus_life,bus_mode,bus_yuliu[6],youmen_taban,zhidong_taban,bus_version[7],dianchi_soc;

extern int motor_temp[2];
extern unsigned int motor_zhuanju;
extern int motor_zhju,motor_con_cur;
//extern unsigned char motor_version[7],dynamo_version[7];
extern int qiben1,qiben2,qiben3;
extern int qiben4;

extern int dcdc_output_voltage,dcdc_output_current,dcdc_input_voltage,dcdc_temp;
extern unsigned char qiben5, dcdc_fault,dcac_fault;
extern int dcac_w_current,dcac_v_current,dcac_u_current,dcac_temp;

extern unsigned int riso_zheng,riso_fu;
extern unsigned char riso_life,riso_fault,riso_loudian;

extern unsigned char tiaoshi_canshu[8];

extern int chongdian_current,fangdian_current,mono_max_temp,mono_min_temp;
extern unsigned int battery_riso_zheng,battery_riso_fu,mono_max_voltage,mono_min_voltage,mono_pingjun_voltage;
extern unsigned char battery_status[5];

extern unsigned char vin_status,battery_fault_suliang,mono_binglian_shuliang,mono_tanzhen_shuliang;
extern int chongdian_temp[4];
extern unsigned int eding_rongliang,eding_voltage,mono_chuanlian_shuliang;

extern int mono_min_temp;
extern unsigned char mono_max_t_xiang,mono_max_t_jie,mono_min_t_xiang,mono_min_t_jie,mono_max_v_xiang,mono_max_v_jie;
extern unsigned char mono_min_v_xiang,mono_min_v_jie,battery_leixing,battery_lengque,battery_yuliu[4];

extern unsigned int dianchi_bianhao[10],dianchi_mono_voltage[10];
extern int dianchi_mono_temp[10];
extern unsigned char dianchi_xianghao[10];

extern int air_set_temp,air_wai_temp,air_nei_temp,air_current;
extern unsigned char air_status,air_life,air_fuhe;

extern unsigned char miehuoqi_xiang,miehuoqi_yujing,miehuoqi_fault,miehuoqi_qingqiu,yanwu_status[5],yanwu_life;
extern unsigned char dianchi_fenxian,runhua1;

extern unsigned char yzt_status;
extern unsigned char elec_control_code;
//extern int peidianhe_cur,peidianhe_temp;
//extern unsigned char peidianhe_status;
//extern unsigned int peidianhe_vol;



extern unsigned char youbeng_life[2],youbeng_status[2],youbeng[3],guzhangdaima,diduan_vol,yingjianbanben,ruanjianbanben;
extern unsigned int youbeng_zhuansu[2],youbeng_cur[2],gaoduan_vol;
extern int youbeng_temp[2],dianji_temp;
extern unsigned char meter_input,meter_output;
extern unsigned int dianhao;
extern unsigned char surface_data[6][8];
extern long shunshi_gonglv,shengyu_gonglv;


extern void uart1_rev_data(void);
extern unsigned char addring(unsigned char i);
extern unsigned char getdata(void);
extern void putdata(unsigned char typedata);
extern unsigned int ByteToWord(unsigned char lowbyte,unsigned char highbyte);
extern unsigned long ByteToDword(unsigned char lowbyte,unsigned char byte1,unsigned char byte2,unsigned char highbyte);
#endif