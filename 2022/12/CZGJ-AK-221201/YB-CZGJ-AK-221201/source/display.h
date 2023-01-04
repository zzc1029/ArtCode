/*
 * display.h
 *
 *  Created on: 2021-8-10
 *      Author: ART
 */

#ifndef _DISPLAY_H
#define _DISPLAY_H




extern 	volatile uint8_t can_water_low;
extern  volatile uint8_t Control_information_data7;
extern  volatile uint8_t ID_0CFF0B4A_data2,battery_1_data6,Control_information_data6;
extern  volatile uint8_t ID_18FF2A48_data5,ID_18FF2848_data7,veh_scr,_1CEBFF2F;
extern  volatile uint8_t _18FECA2F,_0CFE5A2F_data4,_0CFE5A2F_data1,ID_18FF2D47_data6,Control_information_data0;
extern  volatile uint8_t _18FF8001[8],_10FFC29E[8];
extern  volatile uint8_t batt_time,motor_tem,motor_flag,ID_18FF2D47_data5;
extern  volatile uint8_t _18FF8001[8],_18FF2D47[8],add[10],_18FF0152[8],_18FF3047[8],_18FF3147[8],_18FF3247[8];
extern  volatile uint8_t  Box_High_Temp,Temp_jicha,ID_18FF2948_data6,Battery_Total_Count,_18FF2948[8];
extern  volatile uint8_t  ID_18FF2E48_data0,ID_18FF2E48_data1,ID_18FF2E48_data2,ID_18FF2E48_data3;
extern  volatile uint8_t  ID_18ff0257_data[8],_0CFFEB4A[8];

extern  volatile uint8_t  elec_time,motor_state;
extern  volatile uint8_t  ID_18FF2848_data5,_18FF2848[8],b_postion;
extern  volatile uint16_t Battery_System_Volt,Battery_Charge_Curr;
extern  volatile uint8_t  _18FF2A48[8],Temp_Positive,ID_18FF2A48_data0,ID_18FF2A48_data1,ID_18FF2A48_data2;
extern  volatile uint16_t Remain_Energy;


extern  volatile uint16_t Battery_chong_Curr_1,Battery_fang_Curr_1;
extern  volatile uint16_t motor_torque,motor_dc_volt,motor_dc_curr,Battery_2_Remain_enery;

extern  volatile uint8_t  ID_18FF2C48_data5,battery_2_data6,battery_2_soc;
extern  volatile uint16_t battery_2_system_volt,battery_2_system_curr; 


extern  volatile uint16_t WaterTem;
extern  volatile uint16_t motor_pow[4];
extern  volatile uint8_t any_Remain_time,electric_shake;
extern  volatile TYPE_BYTE Ankai_Add_190703;


extern  volatile TYPE_BYTE Add_Comm,Low_Buzz;
extern  volatile uint8_t  fog_alarm[4];
extern  volatile uint8_t  ID_18FF2D48_data6,ID_18FF2D48_data5,ID_18FF2D48_data4;
extern  volatile uint16_t Battery_2_single_high_volt,Battery_2_single_low_volt; 
extern  volatile uint16_t insulate_value;
extern  volatile uint8_t  insulate_flag,Life;
extern  volatile uint8_t  Model_Temperure[16];
extern  volatile uint8_t _18FF2B49[8],_0CFF324A[8];
extern  volatile uint8_t Control_information_data7,Control_information_data6,Control_information_data5;
extern  volatile uint8_t Control_information_data0,Control_information_data1;
extern  volatile uint8_t _0CFF0B4A[8],ID_0CFF0B4A_data2,abs_fault,ChargingRelay,FaultAlarmAdd,dian_nuanfeng;


extern  volatile uint8_t _18FF5B52[8],_18FF0257[8],_18ff2b48[8];
extern  volatile TYPE_BYTE add_fog[8];

extern  volatile uint8_t  _18FFC13A[8],_18FF45F4[8],_10FFC09E[8],_10FFC19E[8],_0CFF114A[8];
extern  volatile uint8_t  errcodemix[6];
extern  volatile uint8_t _18FF064A[8],_18FF2C47[8],_18FF5A52[8],_0CFF0A4A[8],_18FF0258[8],_18F0010B[8],_18FDC40B[8];

extern  volatile uint8_t battery_1_soc,_18FF0498_data7;
extern  volatile uint16_t  Single_mile;


#if GUZHAGN_LOOP

void guzhangma_init(void);


//VCU故障码
extern volatile uint8_t VCU_MA[MAX_MA];
//VCU故障码
extern volatile uint8_t BMS_MA[MAX_MA];
//电机故障码
extern volatile uint8_t MOTOR_MA[MAX_MA];
//打气变频
extern volatile uint8_t DAQI_MA[MAX_MA];
//转向变频
extern volatile uint8_t TURN_MA[MAX_MA];
//小充电机
extern volatile uint8_t XIAOQONG_MA[MAX_MA];
//故障码索引参数
extern volatile uint8_t DIYA_MA[MAX_MA];

extern volatile uint8_t VCU_Index,BMS_Index,MOTOR_Index,DAQI_Index,TURN_Index,XIAOQONG_Index,DIYA_Index;
u8 JudgeMAInBuff(volatile u8 *p,volatile u8 data);

#endif













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
void AddAnkaiMenu(void);




#endif


