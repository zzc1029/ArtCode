/*
 * display.h
 *
 *  Created on: 2021-8-10
 *      Author: ART
 */

#ifndef _DISPLAY_H
#define _DISPLAY_H




extern volatile u8 DCDC1[8],RUNHUA[8],PEIDIAN[8],shuileng1[8],shuileng2[8],DriverOperateStatus,OnOffStatus;
//extern volatile u8 jizhong_alarm[10],jizhong_life[10],jizhong_grade[10],jizhong_code[10],jizhong_box[10]={0};
extern volatile u8 _0C04A1A7_DATA[8],_0C07A1A7_DATA[8],_0C09A1A7_DATA[8],_181AD0F3_DATA[8],_181BD0F3_DATA[8];
extern volatile u8 _181CD0F3_DATA[8],_181DD0F3_DATA[8],_181ED0F3_DATA[8]; 
extern volatile u8 _0C0CA7F2_DATA[8],_0C0AA7F0_DATA[8],_0C01F4A7_DATA[8],_0C08A7F4_DATA[8],_180AA7A3_DATA[8];
extern volatile u8 _180BA7A3_DATA[8],_180CA7A3_DATA[8],_0C01A70A_DATA[8],_0C02A70A_DATA[8],_0C03A70A_DATA[8];
extern volatile u8 _0C04A70A_DATA[8],_1818D0F3_DATA[8],_1819D0F3_DATA[8],_18EFA1A5_DATA[8],_1819A100_DATA[8]; 
extern volatile u8 _180028F3_DATA[8],_180128F3_DATA[8],_180228F3_DATA[8],_180328F3_DATA[8],_180428F3_DATA[8];
extern volatile u8 _180528F3_DATA[8],_180028F4_DATA[8],_180128F4_DATA[8];
extern volatile u8 _180228F4_DATA[8],_180328F4_DATA[8],_0CFFF3A7_DATA[8],_0CFEEC21_DATA[8],_18EBA1A5_DATA[8];
extern volatile u8 EngineWaterTemp,EngineLoad,EngineTatgetAccelerator,EngineActualAccelerator,VCU_Life,EngineInputAirTemp,FuelConsumption_Instant;
extern volatile u16 EngineSpeed,scr,oil_prss,shunshigonglv,FuelConsumption_100KM_Subtotal,FuelConsumption_100KM_Acctotal,shengyugonglv,Motor_Current;
extern volatile u32 OilAccumulation;
extern volatile u8 VCUSofeVersion[8],ECUSofeVersion[8],EECUSofeVersion[8],SystemMode,SystemStatus,xuedimoshi,qianyinli,InsulationMonitorErrorLevel,InsulationMonitorLife,InsulationMonitorAlarm;
extern volatile u16 InsulationMonitorRes_Positive,InsulationMonitorRes_Negative,can_err_time,Bat_Soc,SystemCode;
extern volatile u8 DrivingRange,baigongli[2],AlarmFlag[4],E_MotorError[4],BmsMonoData[5][8],veh_scr,fire_alarm_status[4],fire_alarm_system_status,fire_alarm_life,DebugData[8];


extern volatile TYPE_BYTE AIR[8],YUN_TONG[8],fuzhu[8],add1[8],add2[8],add3[8];




typedef struct{
	unsigned int ivoltage;//�����ѹ
	unsigned int icurrent;//�������
	unsigned int itorque;//���ת��
	
	unsigned int ispeed;//���ת��
	unsigned char itemp;//����¶�
	unsigned char etemp;//������¶�
	//unsigned int imubiaochuanju;
	unsigned char iversion[8];
}bus_motor;
extern volatile bus_motor MOTOR;


typedef struct{
	unsigned char itemp;//�������¶�
	unsigned char etemp;//������������¶�
	unsigned char iversion[8];//�汾
	unsigned int ifault_code;//���ϴ���
	unsigned char ifault_level;//���ϵȼ�
	unsigned char ibus_model;//����ģʽ
	unsigned char ilife;//������life
	unsigned char K_control;//�������Ӵ�����
	unsigned char iready;//ready�źŵ�
	unsigned char igear;//��λ
	unsigned char iswitching;//���µȿ���
	unsigned char icharge;//���ȷ��
}bus_control;
extern volatile bus_control CONTROL;


typedef struct{
	unsigned char ispeed_up;//����̤��
	unsigned char ibraking;//�ƶ�̤��
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
	u16 current_w;
	u16 current_v;
	u16 current_u;
	u8 temp;
	u8 faultcode;
}dcac;
extern volatile dcac DC_AC;



typedef struct{
	unsigned char num;
	unsigned char alarmlevel;
	unsigned char faultcode;
	unsigned char timecalibration;
}extinguisher; //�����
extern volatile extinguisher Extinguisher;

typedef struct{
	unsigned int ivoltage;//����ܵ�ѹ
	unsigned int icadc;//��ŵ����
	unsigned char isoc;//soc
	unsigned char istatus[3];//״̬��־
	unsigned int imax_charge;//������������
	unsigned int imax_discharge;//�������ŵ����
	unsigned char isystem_fault;//﮵�ع��ϵȼ�
	unsigned int iaverage_voltage;//ƽ����ѹֵ
	unsigned char imono_max_temp;//��������¶�
	unsigned int itotal_anode_riso;//������Ե����ֵ
	unsigned int itotal_cathode_riso;//�ܸ���Ե����ֵ
	unsigned int imono_max_voltage;//��������ѹ
	unsigned int imono_min_voltage;//������С��ѹ
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
	unsigned int inumber[10];//�����ѹ���
	unsigned int ivoltage[10];//�����ѹ
	unsigned char isampl_number[10];//�����������
	unsigned char itemp[10];//����������¶�
}mono_battery;
extern volatile mono_battery BMS_MONO;

typedef struct{
	u8 box[10];
	u8 type[10];
	u8 status[10];
	u8 fault_code[10];
	u8 rollcounter;
}bat_fire;
extern volatile bat_fire BAT_FIRE;

typedef struct{
	u8 baojing_count[5];
	u8 alarm_num[5];
	u16 press[6];
	u8 temperature[6];
	u8 fault_1[6];
	u8 fault_2[6];
}tire;
extern volatile tire TIRE;



#define SendStart()                                                                         \
    u8 i;                                                                                   \
    static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};       \
    for(i = 1; i < 12; i++)                                                                 \
        communicate_T123_data[i] = 0;

#define SendEnd()                                                           \
    do{                                                                     \
        u8 change = 0;                                                      \
        for(i=3; i<11; i++)                                                \
        {                                                                  \
            if(data1save[i] != communicate_T123_data[i])                   \
            {                                                              \
                data1save[i] = communicate_T123_data[i];                   \
                change ++;                                                 \
            }                                                              \
        }                                                                  \
        if((change>0) ||(initpw))                                          \
        {                                                                  \
            Transmit_Data_Sci1(communicate_T123_data,12);                  \
        }                                                                   \
    }while(0)

#define PeriodSendStart(init,TimeOut100ms)                              \
			u8 i;																\
			static u8 time = init;													\
			time ++;															\
			if((time>(TimeOut100ms))||initpw)									\
				time = 0;														\
			if(time == 0)														\
			{																	\
				for(i = 1; i < 12; i++) 										\
					communicate_T123_data[i] = 0;
		
		
#define PeriodSendEnd()                                                 \
				Transmit_Data_Sci1(communicate_T123_data,12);					\
			}


#define SendEndPlus(timeout100ms)                                               \
    do {                                                                    \
        static u8 timeoutxxxxxxx;               \
        u8 change = 0;                                                      \
        timeoutxxxxxxx ++;                                                  \
                                                                            \
        for(i=3; i<11; i++)                                                 \
        {                                                                   \
            if(data1save[i] != communicate_T123_data[i])                    \
            {                                                               \
                data1save[i] = communicate_T123_data[i];                    \
                change ++;                                                  \
            }                                                               \
        }                                                                   \
        if(timeoutxxxxxxx >= (timeout100ms))                                \
        {                                                                   \
            timeoutxxxxxxx = 0;                                             \
            Transmit_Data_Sci1(communicate_T123_data,12);                   \
        }                                                                   \
        else                                                                \
        {                                                                   \
            if((change>0) ||(initpw))                                       \
            {                                                               \
                Transmit_Data_Sci1(communicate_T123_data,12);               \
                timeoutxxxxxxx = communicate_T123_data[2];                  \
            }                                                               \
        }                                                                   \
    } while(0)


void CAN_T123(void);
void AddWanDaMenu(void);




#endif


