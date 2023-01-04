#include "uart.h"
#include "serial.h"
#include "display.h"

unsigned char buzzer;
unsigned char uart_cmd,dandu_disp,para_cmd;
unsigned long mark_door;
unsigned char mark2,mark3;
unsigned char menu,page_xuanze;
unsigned int speed_scale,baimi_pulse;//subi
unsigned char system_bright,scale_factor;//liangdu
unsigned char system_video;//tv1-4
unsigned char i_temp[CMD_MAX],i_put = 0,i_get = 0,i_len = 0;
unsigned char status_para_change;
unsigned int meter_status[4];
unsigned int meter_para_A2,meter_para_A3,meter_para_A4,meter_para_A5,meter_para_A13,meter_para_A14,meter_para_A15,meter_para_K;
#if MODULE_FRONT_B40
unsigned int front_status[4];
unsigned int front_para_A25,front_para_A40,front_para_A26;
#endif
#if MODULE_REAR_B40
unsigned int rear_status[4];
unsigned int rear_para_A25,rear_para_A40,rear_para_A26;
#endif
#if MODULE_TOP_B40
unsigned int top_status[4];
unsigned int top_para_A25,top_para_A40,top_para_A26;
#endif
#if MODULE_FRONT_B50
unsigned int front_status[2],front_para[7];
unsigned int front_out_status[6];
#endif
#if MODULE_REAR_B50
unsigned int rear_status[2],rear_para[7];
unsigned int rear_out_status[6];
#endif
#if MODULE_TOP_B50
unsigned int top_status[2],top_para[7];
unsigned int top_out_status[6];
#endif
SYS_TIME system_time;
SYS_MEILAGE system_meilage;
SYS_ALARM system_alarm;
SYS_AIR system_air;
SYS_PAGE system_page;
SYS_BLINK1 system_b_password;
SYS_BLINK system_b_odo_char;
SYS_BLINK2 system_b_set;

unsigned char air1_factor,air2_factor,speed_alarm,air_alarm,oil_alarm,fuel_alarm,vedio_enable[5],yugua_time;//设置增加
unsigned char wiper_sec;
//-----------------------------------------------------------------------------------
unsigned char li_battery_level,system_status;
unsigned int xudianchi_voltage,system_code,xushi_trip,motor_zhuansu,tms_fault_code;
int total_voltage,total_current;

unsigned int dongli_input_voltage;
int dongli_input_current;
unsigned char siji_status,onoff_status,bus_life,bus_mode,bus_yuliu[6],youmen_taban,zhidong_taban,bus_version[7],dianchi_soc;

int motor_temp[2];
unsigned int motor_zhuanju;
int motor_zhju,motor_con_cur;
//unsigned char motor_version[7],dynamo_version[7];

int dcdc_output_voltage,dcdc_output_current,dcdc_input_voltage,dcdc_temp;
int qiben1,qiben2,qiben3,qiben4;
 
unsigned char qiben5,dcdc_fault,dcac_fault;
int dcac_w_current,dcac_v_current,dcac_u_current,dcac_temp;

unsigned int riso_zheng,riso_fu;
unsigned char riso_life,riso_fault,riso_loudian;

unsigned char tiaoshi_canshu[8];

int chongdian_current,fangdian_current,mono_max_temp,mono_min_temp;
unsigned int battery_riso_zheng,battery_riso_fu,mono_max_voltage,mono_min_voltage,mono_pingjun_voltage;
unsigned char battery_status[5];

unsigned char vin_status,battery_fault_suliang,mono_binglian_shuliang,mono_tanzhen_shuliang;
int chongdian_temp[4];
unsigned int eding_rongliang,eding_voltage,mono_chuanlian_shuliang;

int mono_min_temp;
unsigned char mono_max_t_xiang,mono_max_t_jie,mono_min_t_xiang,mono_min_t_jie,mono_max_v_xiang,mono_max_v_jie;
unsigned char mono_min_v_xiang,mono_min_v_jie,battery_leixing,battery_lengque,battery_yuliu[4];

unsigned int dianchi_bianhao[10],dianchi_mono_voltage[10];
int dianchi_mono_temp[10];
unsigned char dianchi_xianghao[10];

int air_set_temp,air_wai_temp,air_nei_temp,air_current;
unsigned char air_status,air_life,air_fuhe;

unsigned char miehuoqi_xiang,miehuoqi_yujing,miehuoqi_fault,miehuoqi_qingqiu,yanwu_status[5],yanwu_life;

unsigned char dianchi_fenxian,runhua1;

unsigned char yzt_status;//云智通状态


//int peidianhe_cur,peidianhe_temp;
//unsigned int peidianhe_vol;
//unsigned char peidianhe_status;


unsigned char youbeng_life[2],youbeng_status[2],youbeng[3],guzhangdaima,diduan_vol,yingjianbanben,ruanjianbanben;
unsigned int youbeng_zhuansu[2],youbeng_cur[2],gaoduan_vol;
int youbeng_temp[2],dianji_temp;

unsigned char meter_input,meter_output;
unsigned int dianhao;

unsigned char surface_data[6][8];
long shunshi_gonglv,shengyu_gonglv;
unsigned char elec_control_code;
void _main_data1(void);
void _main_data2(void);
void _main_data3(void);

unsigned int ByteToWord(unsigned char lowbyte,unsigned char highbyte)
{
	unsigned int temp;
	temp = highbyte;
	temp = (temp << 8) & 0xff00;
	temp |= lowbyte;
	return temp;
}
unsigned long ByteToDword(unsigned char lowbyte,unsigned char byte1,unsigned char byte2,unsigned char highbyte)
{
	unsigned long temp,tep;
	tep = byte1;
	tep = (tep << 8) & 0x0000ff00;
	tep |= lowbyte;

	temp = highbyte;
	temp = (temp << 8) & 0x0000ff00;
	temp |= byte2;
	temp = (temp << 16) & 0xffff0000;
	return (temp | tep);
}
void Rec_para_page(void)
{
	switch(rev_buf[2])
	{
		case PAGE_PASSWORD:
			system_b_password.blink = rev_buf[3];
			system_b_password.para[rev_buf[3]] = rev_buf[4];
			para_cmd = PAGE_PASSWORD;
			break;
		case PAGE_PARA:
			system_b_set.blink = rev_buf[3];
			system_b_set.para[rev_buf[3]] = rev_buf[4];
			if(rev_buf[3] == 6)
				buzzer = rev_buf[4];
			para_cmd = PAGE_PARA;
			break;
		case PAGE_SET:
			system_b_odo_char.blink = rev_buf[3];
			system_b_odo_char.para[rev_buf[3]] = rev_buf[4];
			para_cmd = PAGE_SET;
			break;
		default:
			para_cmd = 0;
			break;
	}
	uart_cmd = UART1_PARA_PAGE;
}
void Rec_meter_page(void)
{
	#if METER_C50
	unsigned char temp;
	if(rev_buf[2] == 1)
	{
		meter_status[0] = rev_buf[4];
		meter_status[0] <<= 7;
		meter_status[0] &= 0x7f80;
		meter_status[0] |= rev_buf[3];
		if(rev_buf[5] & 0x01)
			meter_status[0] |= 0x8000;
		
		meter_status[1] = rev_buf[7];
		meter_status[1] <<= 8;
		temp = (rev_buf[6] << 3) & 0xf8;
		temp |= ((rev_buf[5] >> 1) & 0x07);
		meter_status[1] |= temp;
		
		meter_status[2] = rev_buf[8];
		meter_status[3] = rev_buf[9];
	}
	else if(rev_buf[2] == 2)
	{
		meter_para_A2 = ByteToWord(rev_buf[3],rev_buf[4]);
		meter_para_A3 = ByteToWord(rev_buf[5],rev_buf[6]);
		meter_para_A4 = ByteToWord(rev_buf[7],rev_buf[8]);
	}
	else if(rev_buf[2] == 3)
	{
		meter_para_A5 = ByteToWord(rev_buf[3],rev_buf[4]);
		meter_para_A13 = ByteToWord(rev_buf[5],rev_buf[6]);
		meter_para_A14 = ByteToWord(rev_buf[7],rev_buf[8]);
		meter_para_A15 = ByteToWord(rev_buf[9],rev_buf[10]);
	}
	#elif METER_C61
	if(rev_buf[2] == 1)
	{
		meter_status[0] = ByteToWord(rev_buf[3],rev_buf[4]);
		meter_status[1] = rev_buf[6];
		meter_status[1] <<= 8;
		meter_status[1] &= 0x0700;
		meter_status[1] |= rev_buf[5];
		
		//meter_status[2] = rev_buf[8];
		meter_status[3] = rev_buf[7];
	}
	else if(rev_buf[2] == 2)
	{
		meter_para_A2 = ByteToWord(rev_buf[3],rev_buf[4]);
		meter_para_A3 = ByteToWord(rev_buf[5],rev_buf[6]);
		meter_para_A4 = ByteToWord(rev_buf[7],rev_buf[8]);
		meter_para_A5 = ByteToWord(rev_buf[9],rev_buf[10]);
	}
	else if(rev_buf[2] == 3)
	{
		meter_para_A13 = ByteToWord(rev_buf[3],rev_buf[4]);
		meter_para_A14 = ByteToWord(rev_buf[5],rev_buf[6]);
	}
	#elif METER_C52
	if(rev_buf[2] == 1)
	{
		meter_status[0] = ByteToWord(rev_buf[3],rev_buf[4]);
		meter_status[1] = ByteToWord(rev_buf[5],rev_buf[6]);
		meter_status[2] = ByteToWord(rev_buf[7],rev_buf[8]);
	}
	else if(rev_buf[2] == 2)
	{
		meter_para_A2 = ByteToWord(rev_buf[3],rev_buf[4]);
		meter_para_A3 = ByteToWord(rev_buf[5],rev_buf[6]);
		meter_para_A4 = ByteToWord(rev_buf[7],rev_buf[8]);
		meter_para_K = rev_buf[9];//逻辑版本
	}
	else if(rev_buf[2] == 3)
	{
		meter_para_A5 = ByteToWord(rev_buf[3],rev_buf[4]);
		meter_para_A13 = ByteToWord(rev_buf[5],rev_buf[6]);
		meter_para_A14 = ByteToWord(rev_buf[7],rev_buf[8]);
		meter_para_A15 = ByteToWord(rev_buf[9],rev_buf[10]);
	}
	#endif
	status_para_change = rev_buf[2];
	uart_cmd = UART1_METER_PAGE;
}
void Rec_front_page(void)
{
	#if MODULE_FRONT_B50
	unsigned char i;
	#endif
	status_para_change = rev_buf[2];
	#if MODULE_FRONT_B40
	if(rev_buf[2] == 1)
	{
		front_status[0] = ByteToWord(rev_buf[3],rev_buf[4]);
		
		front_status[1] = ByteToWord(rev_buf[5],rev_buf[6]);
		
		front_status[2] = ByteToWord(rev_buf[7],rev_buf[8]);
		
		front_status[3] = rev_buf[9];//a17=0,a41=1
	}
	else if(rev_buf[2] == 2)
	{
		front_para_A25 = ByteToWord(rev_buf[3],rev_buf[4]);

		front_para_A40 = ByteToWord(rev_buf[5],rev_buf[6]);

		front_para_A26 = ByteToWord(rev_buf[7],rev_buf[8]);
	}
	#endif
	#if MODULE_FRONT_B50
	switch(rev_buf[2])
	{
		case 1:
			front_status[0] = ByteToWord(rev_buf[3],rev_buf[4]);
			front_status[1] = ByteToWord(rev_buf[5],rev_buf[6]);
			break;
		case 2:
			for(i=0;i<4;i++)
				front_para[i] = ByteToWord(rev_buf[3 + 2*i],rev_buf[4 + 2*i]);
			break;
		case 3:
			for(i=0;i<3;i++)
				front_para[i + 4] = ByteToWord(rev_buf[3 + 2*i],rev_buf[4 + 2*i]);
			break;
		default:
			break;
	}
	#endif
	uart_cmd = UART1_FRONT_PAGE;
}
void Rec_rear_page(void)
{
	#if MODULE_REAR_B50
	unsigned char i;
	#endif
	status_para_change = rev_buf[2];
	#if MODULE_REAR_B40
	if(rev_buf[2] == 1)
	{
		rear_status[0] = ByteToWord(rev_buf[3],rev_buf[4]);
		
		rear_status[1] = ByteToWord(rev_buf[5],rev_buf[6]);
		
		rear_status[2] = ByteToWord(rev_buf[7],rev_buf[8]);
		
		rear_status[3] = rev_buf[9];//a17=0,a41=1
	}
	else if(rev_buf[2] == 2)
	{
		rear_para_A25 = ByteToWord(rev_buf[3],rev_buf[4]);

		rear_para_A40 = ByteToWord(rev_buf[5],rev_buf[6]);

		rear_para_A26 = ByteToWord(rev_buf[7],rev_buf[8]);
	}
	#endif
	#if MODULE_REAR_B50
	switch(rev_buf[2])
	{
		case 1:
			rear_status[0] = ByteToWord(rev_buf[3],rev_buf[4]);
			rear_status[1] = ByteToWord(rev_buf[5],rev_buf[6]);
			break;
		case 2:
			for(i=0;i<4;i++)
				rear_para[i] = ByteToWord(rev_buf[3 + 2*i],rev_buf[4 + 2*i]);
			break;
		case 3:
			for(i=0;i<3;i++)
				rear_para[i + 4] = ByteToWord(rev_buf[3 + 2*i],rev_buf[4 + 2*i]);
			break;
		default:
			break;
	}
	#endif
	uart_cmd = UART1_REAR_PAGE;
}
void Rec_top_page(void)
{
	#if MODULE_TOP_B50
	unsigned char i;
	#endif
	status_para_change = rev_buf[2];
	#if MODULE_TOP_B40
	if(rev_buf[2] == 1)
	{
		top_status[0] = ByteToWord(rev_buf[3],rev_buf[4]);
		
		top_status[1] = ByteToWord(rev_buf[5],rev_buf[6]);
		
		top_status[2] = ByteToWord(rev_buf[7],rev_buf[8]);
		
		top_status[3] = rev_buf[9];//a17=0,a41=1
	}
	else if(rev_buf[2] == 2)
	{
		top_para_A25 = ByteToWord(rev_buf[3],rev_buf[4]);

		top_para_A40 = ByteToWord(rev_buf[5],rev_buf[6]);

		top_para_A26 = ByteToWord(rev_buf[7],rev_buf[8]);
	}
	#endif
	#if MODULE_TOP_B50
	switch(rev_buf[2])
	{
		case 1:
			top_status[0] = ByteToWord(rev_buf[3],rev_buf[4]);
			top_status[1] = ByteToWord(rev_buf[5],rev_buf[6]);
			break;
		case 2:
			for(i=0;i<4;i++)
				top_para[i] = ByteToWord(rev_buf[3 + 2*i],rev_buf[4 + 2*i]);
			break;
		case 3:
			for(i=0;i<3;i++)
				top_para[i + 4] = ByteToWord(rev_buf[3 + 2*i],rev_buf[4 + 2*i]);
			break;
		default:
			break;
	}
	#endif
	uart_cmd = UART1_TOP_PAGE;
}
void Rec_front_out_page(void)
{
	#if MODULE_FRONT_B50
	unsigned char i;
	switch(rev_buf[2])
	{
		case 1:
			for(i=0;i<4;i++)
				front_out_status[i] = ByteToWord(rev_buf[3 + 2*i],rev_buf[4 + 2*i]);
			break;
		case 2:
			for(i=0;i<2;i++)
				front_out_status[i + 4] = ByteToWord(rev_buf[3 + 2*i],rev_buf[4 + 2*i]);
			front_out_status[5] &= 0x0fff;
			break;
		default:
			break;
	}
	#endif
	uart_cmd = UART1_FRONT_OUT_PAGE;
}
void Rec_rear_out_page(void)
{
	#if MODULE_REAR_B50
	unsigned char i;
	switch(rev_buf[2])
	{
		case 1:
			for(i=0;i<4;i++)
				rear_out_status[i] = ByteToWord(rev_buf[3 + 2*i],rev_buf[4 + 2*i]);
			break;
		case 2:
			for(i=0;i<2;i++)
				rear_out_status[i + 4] = ByteToWord(rev_buf[3 + 2*i],rev_buf[4 + 2*i]);
			rear_out_status[5] &= 0x0fff;
			break;
		default:
			break;
	}
	#endif
	uart_cmd = UART1_REAR_OUT_PAGE;
}
void Rec_top_out_page(void)
{
	#if MODULE_TOP_B50
	unsigned char i;
	switch(rev_buf[2])
	{
		case 1:
			for(i=0;i<4;i++)
				top_out_status[i] = ByteToWord(rev_buf[3 + 2*i],rev_buf[4 + 2*i]);
			break;
		case 2:
			for(i=0;i<2;i++)
				top_out_status[i + 4] = ByteToWord(rev_buf[3 + 2*i],rev_buf[4 + 2*i]);
			top_out_status[5] &= 0x0fff;
			break;
		default:
			break;
	}
	#endif
	uart_cmd = UART1_TOP_OUT_PAGE;
}
void Rec_main_page(void)
{
	unsigned char i;
	static unsigned char last_soc = 0,last_air1 = 0,last_air2 = 0,last_odo[7] = {0},last_mark2 = 0,last_mark3 = 0;
	static unsigned char last_year = 0,last_month = 0,last_day = 0,last_hour = 0,last_minute = 0;
	static unsigned long last_mark_door = 0xfffffff8;
	switch(rev_buf[2])
	{
		case 1:
			mark_door = ByteToDword(rev_buf[6],rev_buf[5],rev_buf[4],rev_buf[3]);
			mark2 = rev_buf[7];
			mark3 = rev_buf[8];
			if((last_mark_door != mark_door)||(last_mark2 != mark2)||(last_mark3 != mark3))
			{
				dandu_disp = MAIN_MARK;
				last_mark_door = mark_door;
				last_mark2 = mark2;
				last_mark3 = mark3;
			}
			
			break;
		case 2:
			for(i=0;i<7;i++)
				system_meilage.odo[6 - i] = rev_buf[3 + i];
			if((last_odo[0]!= system_meilage.odo[0]) || (last_odo[1]!= system_meilage.odo[1]) || (last_odo[2]!= system_meilage.odo[2]) ||\
				(last_odo[3]!= system_meilage.odo[3]) || (last_odo[4]!= system_meilage.odo[4]) || (last_odo[5]!= system_meilage.odo[5]) ||\
				(last_odo[6]!= system_meilage.odo[6]))
			{
				dandu_disp = MAIN_MILE;
				if((system_meilage.odo[0] == 0) && (system_meilage.odo[1] == 0) && (system_meilage.odo[2] == 0) && (system_meilage.odo[3] == 0) &&\
				(system_meilage.odo[4] == 0) && (system_meilage.odo[5] == 0) && (system_meilage.odo[6] == 0))
				{
					for(i=0;i<7;i++)
						system_meilage.odo[i] = last_odo[i];
				}
				else
				{
					for(i=0;i<7;i++)
						last_odo[i] = system_meilage.odo[i];
				}
			}
			break;
		case 3:
			system_time.year = rev_buf[3];
			system_time.month = rev_buf[4];
			system_time.day = rev_buf[5];
			system_time.hour = rev_buf[6];
			system_time.minute = rev_buf[7];
			system_air.air1 = rev_buf[8];
			if(system_air.air1 > 100)
				system_air.air1 = 100;
			system_air.air2 = rev_buf[9];
			if(system_air.air2 > 100)
				system_air.air2 = 100;
			system_air.soc = rev_buf[10];
			if(system_air.soc > 100)
				system_air.soc = 100;
			if((last_year != system_time.year) || (last_month != system_time.month) || (last_day != system_time.day) ||\
				(last_hour != system_time.hour) || (last_minute != system_time.minute))
			{
				DISP_TIME = 1;
				last_year = system_time.year;
				last_month = system_time.month;
				last_day = system_time.day;
				last_hour = system_time.hour;
				last_minute = system_time.minute;
			}
			if((system_air.air1!= last_air1) || (last_air2 != system_air.air2))
			{
				DISP_AIR = 1;
				last_air1 = system_air.air1;
				last_air2 = system_air.air2;
			}
			if(last_soc != system_air.soc)
			{
				DISP_SOC = 1;
				last_soc = system_air.soc;
			}
			dandu_disp = MAIN_TIME;
			break;
		case 4:
			_main_data1();
			dandu_disp = MAIN_DATA;
			break;
		case 5:
			_main_data2();
			dandu_disp = MAIN_DATA;
			break;
		case 6:
			_main_data3();
			dandu_disp = MAIN_DATA;
			break;
/*		case 8:
			vedio_enable[0] = (rev_buf[3]>>0)&0x01;
			vedio_enable[1] = (rev_buf[3]>>1)&0x01;
			vedio_enable[2] = (rev_buf[3]>>2)&0x01;
			vedio_enable[3] = (rev_buf[3]>>3)&0x01;
			air_factor = rev_buf[4];
			speed_alarm = rev_buf[5];
			air_alarm = rev_buf[6];
			oil_alarm = rev_buf[7];
			fuel_alarm  = rev_buf[8];
			break;*/
		default:
			break;
	}
	uart_cmd = UART1_MAIN_PAGE;
}
void _main_data1(void)
{
	unsigned char i;
	total_voltage = ByteToWord(rev_buf[3],rev_buf[4]) - 1000;//电池总电压
	total_current = ByteToWord(rev_buf[5],rev_buf[6]) - 1000;//电池总电流
	for(i=0;i<2;i++)
		motor_temp[i] = rev_buf[7 + i] - 40;//驱动电机和驱动电机控制器温度
	mono_max_voltage = ByteToWord(rev_buf[9],rev_buf[10]);//单体最高电压
	if(mono_max_voltage < 10000)
		mono_max_voltage = 0;
	else
		mono_max_voltage -= 10000;
}
void _main_data2(void)
{

	mono_min_voltage = ByteToWord(rev_buf[3],rev_buf[4]);//单体最低电压
	if(mono_min_voltage < 10000)
		mono_min_voltage = 0;
	else
		mono_min_voltage -= 10000;
	
	mono_max_temp = rev_buf[5] - 40;//单体最高温度

	system_code = ByteToWord(rev_buf[6],rev_buf[7]);//系统代码
	mono_min_temp = rev_buf[8] - 40;
	dianhao = ByteToWord(rev_buf[9],rev_buf[10]);
}
void _main_data3(void)
{
	shunshi_gonglv = ByteToWord(rev_buf[3],rev_buf[4]) - 3000;
	xushi_trip = rev_buf[5]* 5;
	shengyu_gonglv = ByteToWord(rev_buf[6],rev_buf[7]) - 3000;
	//tms_fault_code = rev_buf[8];
}
void Rec_surface1_page(void)
{
	unsigned char i;
	switch(rev_buf[2])
	{
		case 1:
			dongli_input_voltage = ByteToWord(rev_buf[3],rev_buf[4]) - 1000;
			dongli_input_current = ByteToWord(rev_buf[5],rev_buf[6]) - 1000;
			siji_status = rev_buf[7];
			onoff_status = rev_buf[8];
			bus_life = rev_buf[9];
			break;
		case 2:
			bus_mode = rev_buf[3];
			system_status = rev_buf[4];
			for(i=0;i<6;i++)
				bus_yuliu[i] = rev_buf[5 + i];
			break;
		case 3:
			youmen_taban = rev_buf[3];
			zhidong_taban = rev_buf[4];
			break;
		case 4:
			for(i=0;i<7;i++)
				bus_version[i] = rev_buf[4 + i];
			break;
		default:
			break;
	}
	uart_cmd = UART1_SURFACE1_PAGE;
}
void Rec_surface2_page(void)
{
	unsigned char i;
	switch(rev_buf[2])
	{
		case 1:
			for(i=0;i<2;i++)
				motor_temp[i] = rev_buf[3 + i] - 40;
			elec_control_code = rev_buf[5];
			motor_zhuanju = ByteToWord(rev_buf[7],rev_buf[8]);
			motor_zhju = motor_zhuanju - 32000;
			motor_con_cur = ByteToWord(rev_buf[9],rev_buf[10])-1000;
			break;
		case 2:
			for(i=0;i<7;i++)
				//motor_version[i] = rev_buf[4 + i];
				surface_data[0][i] = rev_buf[4 + i];
			break;
		/*case 3:
			for(i=0;i<7;i++)
				//dynamo_version[i] = rev_buf[4 + i];
				surface_data[1][i] = rev_buf[4 + i];
			break;*/
		default:
			break;
	}
	uart_cmd = UART1_SURFACE2_PAGE;
}
void Rec_surface3_page(void)
{
	switch(rev_buf[2])
	{
		case 1:
			dcdc_output_voltage = ByteToWord(rev_buf[3],rev_buf[4]) - 1000;
			dcdc_output_current = ByteToWord(rev_buf[5],rev_buf[6]) - 1000;
			dcdc_input_voltage = ByteToWord(rev_buf[7],rev_buf[8]) - 1000;
			dcdc_temp = rev_buf[9] - 40;
			dcdc_fault = rev_buf[10];
			break;
		case 2:
			surface_data[0][0]= rev_buf[3];
			surface_data[0][1] = rev_buf[4];
			surface_data[0][2]= rev_buf[5];
			surface_data[0][3] = rev_buf[6];
			break;
		case 3:
			riso_zheng = ByteToWord(rev_buf[3],rev_buf[4]);
			riso_fu = ByteToWord(rev_buf[5],rev_buf[6]);
			riso_fault = rev_buf[7];
			riso_life = rev_buf[8];
			riso_loudian = rev_buf[9];
			break;
		default:
			break;
	}
	uart_cmd = UART1_SURFACE3_PAGE;
}
void Rec_surface4_page(void)
{
	unsigned char i;
	switch(rev_buf[2])
	{
		case 1:
			for(i=0;i<8;i++)
				tiaoshi_canshu[i] = rev_buf[3 + i];
			break;

		case 2:
			yzt_status = rev_buf[3];
			break;
		default:
			break;
	}
	uart_cmd = UART1_SURFACE4_PAGE;
}
void Rec_surface5_page(void)
{     
	  //static unsigned char last_soc = 0;

	  switch(rev_buf[2])
	{
		case 1:
			total_voltage = ByteToWord(rev_buf[3],rev_buf[4]) - 1000;
			chongdian_current = ByteToWord(rev_buf[5],rev_buf[6]) - 1000;
			fangdian_current = ByteToWord(rev_buf[7],rev_buf[8]) - 1000;
			total_current = ByteToWord(rev_buf[9],rev_buf[10]) - 1000;
			break;
		case 2:
			battery_riso_zheng = ByteToWord(rev_buf[3],rev_buf[4]);
			battery_riso_fu = ByteToWord(rev_buf[5],rev_buf[6]);
			mono_max_voltage = ByteToWord(rev_buf[7],rev_buf[8]);
			if(mono_max_voltage < 10000)
				mono_max_voltage = 0;
			else
				mono_max_voltage -= 10000;
			mono_min_voltage = ByteToWord(rev_buf[9],rev_buf[10]);
			if(mono_min_voltage < 10000)
				mono_min_voltage = 0;
			else
				mono_min_voltage -= 10000;
			break;
		case 3:
			mono_pingjun_voltage = ByteToWord(rev_buf[3],rev_buf[4]);
			if(mono_pingjun_voltage < 10000)
				mono_pingjun_voltage = 0;
			else
				mono_pingjun_voltage -= 10000; 
			
			dianchi_soc = rev_buf[5] * 0.4;

			//mono_max_temp = rev_buf[5] - 40;
			//mono_min_temp = rev_buf[6] - 40;
			break;
		default:
			break;
	}
	uart_cmd = UART1_SURFACE5_PAGE;
}
void Rec_surface6_page(void)
{
	unsigned char i;
	switch(rev_buf[2])
	{
		case 1:
			vin_status = rev_buf[3];
			for(i=0;i<4;i++)
				chongdian_temp[i] = rev_buf[4 + i] - 40;
			battery_fault_suliang = rev_buf[8];
			break;
		case 2:
			eding_rongliang = ByteToWord(rev_buf[3],rev_buf[4]);
			eding_voltage = ByteToWord(rev_buf[5],rev_buf[6]);
			mono_chuanlian_shuliang = ByteToWord(rev_buf[7],rev_buf[8]);
			mono_binglian_shuliang = rev_buf[9];
			mono_tanzhen_shuliang = rev_buf[10];
			break;
		default:
			break;
	}
	uart_cmd = UART1_SURFACE6_PAGE;
}
void Rec_surface7_page(void)
{
	unsigned char i;
	switch(rev_buf[2])
	{
		case 1:
			mono_max_temp = rev_buf[3] - 40;
			mono_max_t_xiang = rev_buf[4];
			mono_max_t_jie = rev_buf[5];
			mono_min_temp = rev_buf[6] - 40;
			mono_min_t_xiang = rev_buf[7];
			mono_min_t_jie = rev_buf[8];
			battery_leixing = rev_buf[9];
			battery_lengque = rev_buf[10];
			break;
		case 2:
			mono_max_voltage = ByteToWord(rev_buf[3],rev_buf[4]);
			if(mono_max_voltage < 10000)
				mono_max_voltage = 0;
			else
				mono_max_voltage -= 10000;
			mono_min_voltage = ByteToWord(rev_buf[5],rev_buf[6]);
			if(mono_min_voltage < 10000)
				mono_min_voltage = 0;
			else
				mono_min_voltage -= 10000;
			break;
		case 3:
			mono_max_v_xiang = rev_buf[3];
			mono_max_v_jie = rev_buf[4];
			mono_min_v_xiang = rev_buf[5];
			mono_min_v_jie = rev_buf[6];
			for(i=0;i<4;i++)
				battery_yuliu[i] = rev_buf[7 + i];
			break;
		default:
			break;
	}
	uart_cmd = UART1_SURFACE7_PAGE;
}
void Rec_surface8_page(void)
{
	unsigned char i;
	dianchi_fenxian = rev_buf[2];
	switch(rev_buf[2])
	{
		case 1:
			dianchi_bianhao[0] = ByteToWord(rev_buf[3],rev_buf[9]);
			dianchi_bianhao[1] = ByteToWord(rev_buf[6],rev_buf[10]);
			dianchi_mono_voltage[0] = ByteToWord(rev_buf[4],rev_buf[5]);
			if(dianchi_mono_voltage[0] < 10000)
				dianchi_mono_voltage[0] = 0;
			else
				dianchi_mono_voltage[0] -= 10000;
			dianchi_mono_voltage[1] = ByteToWord(rev_buf[7],rev_buf[8]);
			if(dianchi_mono_voltage[1] < 10000)
				dianchi_mono_voltage[1] = 0;
			else
				dianchi_mono_voltage[1] -= 10000;
			break;
		case 2:
			dianchi_bianhao[2] = ByteToWord(rev_buf[3],rev_buf[9]);
			dianchi_bianhao[3] = ByteToWord(rev_buf[6],rev_buf[10]);
			dianchi_mono_voltage[2] = ByteToWord(rev_buf[4],rev_buf[5]);
			if(dianchi_mono_voltage[2] < 10000)
				dianchi_mono_voltage[2] = 0;
			else
				dianchi_mono_voltage[2] -= 10000;
			dianchi_mono_voltage[3] = ByteToWord(rev_buf[7],rev_buf[8]);
			if(dianchi_mono_voltage[3] < 10000)
				dianchi_mono_voltage[3] = 0;
			else
				dianchi_mono_voltage[3] -= 10000;
			break;
		case 3:
			dianchi_bianhao[4] = ByteToWord(rev_buf[3],rev_buf[9]);
			dianchi_bianhao[5] = ByteToWord(rev_buf[6],rev_buf[10]);
			dianchi_mono_voltage[4] = ByteToWord(rev_buf[4],rev_buf[5]);
			if(dianchi_mono_voltage[4] < 10000)
				dianchi_mono_voltage[4] = 0;
			else
				dianchi_mono_voltage[4] -= 10000;
			dianchi_mono_voltage[5] = ByteToWord(rev_buf[7],rev_buf[8]);
			if(dianchi_mono_voltage[5] < 10000)
				dianchi_mono_voltage[5] = 0;
			else
				dianchi_mono_voltage[5] -= 10000;
			break;
		case 4:
			dianchi_bianhao[6] = ByteToWord(rev_buf[3],rev_buf[9]);
			dianchi_bianhao[7] = ByteToWord(rev_buf[6],rev_buf[10]);
			dianchi_mono_voltage[6] = ByteToWord(rev_buf[4],rev_buf[5]);
			if(dianchi_mono_voltage[6] < 10000)
				dianchi_mono_voltage[6] = 0;
			else
				dianchi_mono_voltage[6] -= 10000;
			dianchi_mono_voltage[7] = ByteToWord(rev_buf[7],rev_buf[8]);
			if(dianchi_mono_voltage[7] < 10000)
				dianchi_mono_voltage[7] = 0;
			else
				dianchi_mono_voltage[7] -= 10000;
			break;
		case 5:
			dianchi_bianhao[8] = ByteToWord(rev_buf[3],rev_buf[9]);
			dianchi_bianhao[9] = ByteToWord(rev_buf[6],rev_buf[10]);
			dianchi_mono_voltage[8] = ByteToWord(rev_buf[4],rev_buf[5]);
			if(dianchi_mono_voltage[8] < 10000)
				dianchi_mono_voltage[8] = 0;
			else
				dianchi_mono_voltage[8] -= 10000;
			dianchi_mono_voltage[9] = ByteToWord(rev_buf[7],rev_buf[8]);
			if(dianchi_mono_voltage[9] < 10000)
				dianchi_mono_voltage[9] = 0;
			else
				dianchi_mono_voltage[9] -= 10000;
			break;
		case 6:
			for(i=0;i<4;i++)
			{
				dianchi_xianghao[i] = rev_buf[3 + 2*i];
				dianchi_mono_temp[i] = rev_buf[4 + 2*i] - 40;
			}
			break;
		case 7:
			for(i=0;i<4;i++)
			{
				dianchi_xianghao[4 + i] = rev_buf[3 + 2*i];
				dianchi_mono_temp[4 + i] = rev_buf[4 + 2*i] - 40;
			}
			break;
		case 8:
			for(i=0;i<2;i++)
			{
				dianchi_xianghao[8 + i] = rev_buf[3 + 2*i];
				dianchi_mono_temp[8 + i] = rev_buf[4 + 2*i] - 40;
			}
			break;
		default:
			break;
	}
	uart_cmd = UART1_SURFACE8_PAGE;
}
void Rec_surface9_page(void)
{
	switch(rev_buf[2])
	{
		case 1:
			air_fuhe = rev_buf[3]*0.4;
			air_life = rev_buf[10];
			air_set_temp = rev_buf[4] - 40;
			air_wai_temp = rev_buf[5] - 40;
			air_nei_temp = rev_buf[6] - 40;
			air_current = ByteToWord(rev_buf[7],rev_buf[8]) - 10000;
			air_status = rev_buf[9];
			break;
		default:
			break;
	}
	uart_cmd = UART1_SURFACE9_PAGE;
}
void Rec_surface10_page(void)
{
	unsigned char i;
	switch(rev_buf[2])
	{
		case 1:
			for(i=0;i<5;i++)
				battery_status[i] = rev_buf[3 + i];
			break;
		default:
			break;
	}
	uart_cmd = UART1_SURFACE10_PAGE;
}
void Rec_surface11_page(void)
{
	unsigned char i;
	switch(rev_buf[2])
	{
		case 1:
			for(i=0;i<8;i++)
				surface_data[0][i]= rev_buf[3 + i];
			break;
		case 2:
			for(i=0;i<4;i++)
				surface_data[1][i]= rev_buf[3 + i];
			break;
		case 3:
			for(i=0;i<6;i++)
				surface_data[2][i]= rev_buf[3 + i];
			break;
		default:
			break;
	}
	uart_cmd = UART1_SURFACE11_PAGE;
}
void Rec_surface12_page(void)
{
	qiben1 = (ByteToWord(rev_buf[3],rev_buf[4])/10) - 1000;
	qiben2 = (ByteToWord(rev_buf[5],rev_buf[6])/10 )- 1000;
	qiben3 = (ByteToWord(rev_buf[7],rev_buf[8])/10) - 1000;
	qiben4 = rev_buf[9] - 40;
	qiben5 = rev_buf[10];
	
	uart_cmd = UART1_SURFACE12_PAGE;
}
void Rec_surface13_page(void)
{
	unsigned char i;
	switch(rev_buf[2])
	{
		case 1:
			for(i=0;i<8;i++)
				surface_data[0][i]= rev_buf[3 + i];
			break;
	//	case 2:
	//		for(i=0;i<8;i++)
	//			surface_data[1][i]= rev_buf[3 + i];
	//		break;
		default:
			break;
	}
	uart_cmd = UART1_SURFACE13_PAGE;
}
void Rec_surface14_page(void)
{
	/*unsigned char i;
	switch(rev_buf[2])
	{
		case 1:
			for(i=0;i<6;i++)
				surface_data[0][i]= rev_buf[3 + i];
			break;
		default:
			break;
	}*/
	uart_cmd = UART1_SURFACE14_PAGE;
}
void Rec_surface15_page(void)
{   
	unsigned char i;
	switch(rev_buf[2])
	{
		case 1:
			system_air.soc = rev_buf[3];
			if(system_air.soc > 100)
				system_air.soc = 100;
			total_voltage = ByteToWord(rev_buf[4],rev_buf[5]) - 1000;
			total_current = ByteToWord(rev_buf[6],rev_buf[7]) - 1000;
			mono_max_temp = rev_buf[8] - 40;//单体最高温度
			mono_max_voltage = ByteToWord(rev_buf[9],rev_buf[10]);//单体最高电压
			if(mono_max_voltage < 10000)
				mono_max_voltage = 0;
			else
				mono_max_voltage -= 10000;
			break;
		case 2:
			mono_min_voltage = ByteToWord(rev_buf[3],rev_buf[4]);//单体最低电压
			if(mono_min_voltage < 10000)
				mono_min_voltage = 0;
			else
				mono_min_voltage -= 10000;
			mono_min_temp = rev_buf[5] - 40;//单体最低温度
			riso_zheng = ByteToWord(rev_buf[6],rev_buf[7]);
			riso_fu = ByteToWord(rev_buf[8],rev_buf[9]);
			surface_data[0][0]= rev_buf[10];
			break;
		case 3:
			for(i=0;i<4;i++)
				chongdian_temp[i] = rev_buf[3 + i] - 40;//充电座温度
			break;
		default:
			break;
	}
	uart_cmd = UART1_SURFACE15_PAGE;
}
void Rec_surface16_page(void)
{
	switch(rev_buf[2])
	{
		case 1:
			youbeng_life[0]= rev_buf[3];
			youbeng_zhuansu[0] = ByteToWord(rev_buf[5],rev_buf[4]);
			youbeng_cur[0] = ByteToWord(rev_buf[7],rev_buf[6])*0.1;
			youbeng_temp[0] = rev_buf[8] - 40;
			youbeng_status[0] = rev_buf[9];
			dianji_temp = rev_buf[10] - 40;
			break;
		case 2:
			youbeng[0] = rev_buf[3];
			diduan_vol = rev_buf[4]*0.2;
			gaoduan_vol = ByteToWord(rev_buf[6],rev_buf[5])*0.1;
			youbeng[1] = rev_buf[7];
			youbeng[2] = rev_buf[8];
			yingjianbanben = rev_buf[9];
			ruanjianbanben = rev_buf[10];
			break;
		default:
			break;
	}
	uart_cmd = UART1_SURFACE16_PAGE;
}

void Rec_surface17_page(void)
{
	switch(rev_buf[2])
	{
		case 1:
			youbeng_life[1]= rev_buf[3];
			youbeng_zhuansu[1] = ByteToWord(rev_buf[5],rev_buf[4]);
			youbeng_cur[1] = ByteToWord(rev_buf[7],rev_buf[6])*0.1;
			youbeng_temp[1] = rev_buf[8] - 40;
			youbeng_status[1] = rev_buf[9];
			guzhangdaima = rev_buf[10];
			break;
		default:
			break;
	}
	uart_cmd = UART1_SURFACE17_PAGE;
}
void Rec_surface18_page(void)
{
	unsigned char i;
	if(rev_buf[2]< 11)
	{
		for(i=0;i<8;i++)
			surface_data[rev_buf[2]-1][i] = rev_buf[3+i];
	}
	uart_cmd = UART1_SURFACE18_PAGE;
}
void Rec_surface19_page(void)
{
	//unsigned char i;
	switch(rev_buf[2])
	{
		case 1:
			meter_input = rev_buf[3];
			meter_output = rev_buf[4];
			break;
		default:
			break;
	}
	uart_cmd = UART1_SURFACE19_PAGE;
}
void Rec_surface20_page(void)
{
/*	unsigned char i;
	switch(rev_buf[2])
	{
		case 1:
			for(i=0;i<3;i++)
				surface_data[0][i] = rev_buf[3+i];
			break;
		default:
			break;
	}*/
	uart_cmd = UART1_SURFACE20_PAGE;

}

void Rec_surface21_page(void)
{

    uart_cmd = UART1_SURFACE21_PAGE;
	
}


void uart1_rev_data(void)
{
	static unsigned int last_trip = 0;
	static unsigned char last_menu = 0,reflash_page = 1;
	switch(rev_buf[1])
	{
		case UART1_MAIN_PAGE:
			Rec_main_page();
			reflash_page = 1;
			break;
		case UART1_MENU_PAGE:
			if((rev_buf[2]!=0xf1)&&(rev_buf[2]!=0xf2))
				{
					menu = rev_buf[2];
					reflash_page = 0;
					if(last_menu != menu)
					{
						uart_cmd = UART1_MENU_PAGE;
						reflash_page = 1;
						last_menu = menu;
					}
				}
			else if(rev_buf[2]==0xf1)
			{
				vedio_enable[0] = (rev_buf[3]>>0)&0x01;
				vedio_enable[1] = (rev_buf[3]>>1)&0x01;
				vedio_enable[2] = (rev_buf[3]>>2)&0x01;
				vedio_enable[3] = (rev_buf[3]>>3)&0x01;
				vedio_enable[4] = (rev_buf[3]>>4)&0x01;
				//vedio_enable[5] = (rev_buf[3]>>5)&0x01;
				//vedio_enable[6] = (rev_buf[3]>>6)&0x01;
				//vedio_enable[7] = (rev_buf[3]>>7)&0x01;
				air1_factor = rev_buf[4];
				air2_factor = rev_buf[5];
				speed_alarm = rev_buf[6];
				air_alarm = rev_buf[7];
				oil_alarm = rev_buf[8];
				fuel_alarm  = rev_buf[9];
				reflash_page = 0;
			}
			else if(rev_buf[2]==0xf2)
			{
				yugua_time = rev_buf[3];
				reflash_page = 0;
			}
			break;
		case UART1_PARA_PAGE:
			Rec_para_page();
			reflash_page = 1;
			break;
		case UART1_VIDEO_PAGE:
			system_video = rev_buf[2];
			reflash_page = 1;
			uart_cmd = UART1_VIDEO_PAGE;
			break;
		case UART1_METER_PAGE:
			Rec_meter_page();
			reflash_page = 1;
			break;
		case UART1_FRONT_PAGE:
			Rec_front_page();
			reflash_page = 1;
			break;
		case UART1_REAR_PAGE:
			Rec_rear_page();
			reflash_page = 1;
			break;
		case UART1_TOP_PAGE:
			Rec_top_page();
			reflash_page = 1;
			break;
		case UART1_FRONT_OUT_PAGE:
			Rec_front_out_page();
			reflash_page = 1;
			break;
		case UART1_REAR_OUT_PAGE:
			Rec_rear_out_page();
			reflash_page = 1;
			break;
		case UART1_TOP_OUT_PAGE:
			Rec_top_out_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE1_PAGE:
			Rec_surface1_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE2_PAGE:
			Rec_surface2_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE3_PAGE:
			Rec_surface3_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE4_PAGE:
			Rec_surface4_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE5_PAGE:
			Rec_surface5_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE6_PAGE:
			Rec_surface6_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE7_PAGE:
			Rec_surface7_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE8_PAGE:
			Rec_surface8_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE9_PAGE:
			Rec_surface9_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE10_PAGE:
			Rec_surface10_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE11_PAGE:
			Rec_surface11_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE12_PAGE:
			Rec_surface12_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE13_PAGE:
			Rec_surface13_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE14_PAGE:
			Rec_surface14_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE15_PAGE:
			Rec_surface15_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE16_PAGE:
			Rec_surface16_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE17_PAGE:
			Rec_surface17_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE18_PAGE:
			Rec_surface18_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE19_PAGE:
			Rec_surface19_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE20_PAGE:
			Rec_surface20_page();
			reflash_page = 1;
			break;
		case UART1_SURFACE21_PAGE:
			Rec_surface21_page();
			reflash_page = 1;
			break;
		case UART1_GENERAL_DATA:
			if(rev_buf[2] == 1)
			{
				system_alarm.index = rev_buf[3];
				system_alarm.number = ByteToWord(rev_buf[5],rev_buf[6]);
				system_meilage.trip = ByteToWord(rev_buf[7],rev_buf[8]);
				if(last_trip != system_meilage.trip)
				{
					DISP_MILE = 1;
					last_trip = system_meilage.trip;
				}
				reflash_page = 1;
				uart_cmd = GD_ALARM;
			}
			else if(rev_buf[2] == 2)
			{
				system_page.current_page = rev_buf[3];
				page_xuanze = rev_buf[4];
				if((system_page.current_page == UART1_PARA_PAGE) && (page_xuanze == PAGE_PARA))
				{
					system_bright = rev_buf[5];
					buzzer = rev_buf[6];
				}
				else if((system_page.current_page == UART1_PARA_PAGE) && (page_xuanze == PAGE_SET))
				{
					speed_scale = ByteToWord(rev_buf[5],rev_buf[6]);
					baimi_pulse = ByteToWord(rev_buf[7],rev_buf[8]);
					scale_factor = rev_buf[9];
				}
				else if(system_page.current_page != UART1_PARA_PAGE)
				{
					page_xuanze = 0;
					para_cmd = 0;
				}
				reflash_page = 1;
				uart_cmd = GD_PAGE_CHANGE;
			}
			break;
		default:
			break;
	}
	if(reflash_page)
		putdata(uart_cmd);
}
unsigned char addring(unsigned char i)
{
	return ((i + 1) == CMD_MAX) ? 0 : (i + 1);
}
unsigned char getdata(void)
{
	unsigned char pos;
	if(i_len)
	{
		pos = i_get;
		i_get = addring(i_get);
		i_len--;
		return i_temp[pos];
	}
	else
	{
		return 0;
	}
}
void putdata(unsigned char typedata)
{
	if(i_len < CMD_MAX)
	{
		i_temp[i_put] = typedata;
		i_put = addring(i_put);
		i_len++;
	}
	else
	{
		i_put = 0;
		i_get = 0;
		i_len = 0;
	}
}
