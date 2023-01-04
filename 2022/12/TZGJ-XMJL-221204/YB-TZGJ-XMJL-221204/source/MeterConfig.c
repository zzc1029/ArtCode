/*
 * MeterConfig.c
 *
 *  Created on: 2021-9-8
 *      Author: ART
 */

#include "system_init.h"




volatile TYPE_WORD   bcm_sw1_f;      //front bcm switch  15 switch from hc165
volatile TYPE_BYTE   bcm_sw2_f;      //front bcm switch   Pin-A17 A41
volatile uint16_t    bcm_frq_f;      //front bcm input frequence
volatile uint16_t    bcm_senor1_f;   //front bcm senor pin A25
volatile uint16_t    bcm_senor2_f;   //front bcm senor pin A40
volatile TYPE_WORD   bcm_out_st_f;   //front bcm output states ON & OFF
volatile TYPE_DWORD  bcm_fb_st_f;    //front bcm feedback states

volatile TYPE_WORD   bcm_sw1_r;      //rear bcm switch   15 switch from hc165
volatile TYPE_BYTE   bcm_sw2_r;      //rear bcm switch    Pin-A17 A41
volatile uint16_t    bcm_frq_r;      //rear bcm input frequence
volatile uint16_t    bcm_senor1_r;   //rear bcm senor pin A25
volatile uint16_t    bcm_senor2_r;   //rear bcm senor pin A40
volatile TYPE_WORD   bcm_out_st_r;   //rear bcm output states ON & OFF
volatile TYPE_DWORD  bcm_fb_st_r;    //rear bcm feedback states

volatile TYPE_WORD   bcm_sw1_t;      //top bcm switch    15 switch from hc165
volatile TYPE_BYTE   bcm_sw2_t;      //top bcm switch     Pin-A17 A41
volatile uint16_t    bcm_frq_t;      //top bcm input frequence
volatile uint16_t    bcm_senor1_t;   //top bcm senor pin A25
volatile uint16_t    bcm_senor2_t;   //top bcm senor pin A40
volatile TYPE_WORD   bcm_out_st_t;   //top bcm output states ON & OFF
volatile TYPE_DWORD  bcm_fb_st_t;    //top bcm feedback states
TYPE_BYTE   ctrl_cmd[8];

volatile uint8_t pcan_off_line;
volatile uint8_t fbcm_off_line;
volatile uint8_t rbcm_off_line;
volatile uint8_t tbcm_off_line;

TYPE_BYTE led[11];

// 文字报警
TYPE_QQWORD  tip_code1,tip_code2,tip_code3,tip_code4;

TYPE_BYTE power_state;

TYPE_WORD F_Set_PWM,R_Set_PWM,T_Set_PWM;



void PortInit(void)
{
	//仪表电源控制引脚 PB9
	GPIOInit_Output_Config(GPIOD_SFR,GPIO_PIN_MASK_3);
	GPIO_Set_Output_Data_Bits(GPIOD_SFR,GPIO_PIN_MASK_3,SET);
	
	//蜂鸣器控制端口  不适用PWM控制
	GPIOInit_Output_Config(GPIOA_SFR,GPIO_PIN_MASK_7);	
	GPIO_Set_Output_Data_Bits(GPIOA_SFR,GPIO_PIN_MASK_7, Bit_RESET);

	//24V给开关供电
	GPIOInit_Output_Config(GPIOE_SFR,GPIO_PIN_MASK_3);
	GPIO_Set_Output_Data_Bits(GPIOE_SFR,GPIO_PIN_MASK_3, SET);

	//
	GPIOInit_Output_Config(GPIOD_SFR,GPIO_PIN_MASK_2);
	
	//背光初始化IO模式
	//GPIOInit_Output_Config(GPIOB_SFR,GPIO_PIN_MASK_10);
    //B4励磁电路上拉使用
	GPIOInit_Output_Config(GPIOE_SFR,GPIO_PIN_MASK_4);
	//GPIO_Set_Output_Data_Bits(GPIOE_SFR,GPIO_PIN_MASK_3, SET);	
	//led
    //GPIO_Write_Mode_Bits(GPIOF_SFR,GPIO_PIN_MASK_4,GPIO_MODE_OUT);
	//GPIO_Set_Output_Data_Bits(GPIOF_SFR,GPIO_PIN_MASK_4, Bit_RESET);

}


#define POWER_ST_INIT	   (0 == power_state.byte)
#define POWER_ST_ON			power_state.bit.b0
#define POWER_ST_OFF		power_state.bit.b1
#define POWER_ST_STOP		power_state.byte = 0


void power_task(void)
{		
	static uint8_t power_off_delay;

	//switch_task();
	if(POWER_ST_INIT)
	{
	    POWER_KEEP(SET);
		if(POWER_DETECT)			//DB Wake Up
		{
			POWER_ST_ON = ON;
			POWER_ST_OFF = OFF;
		}
		else
		{
			POWER_ST_ON = OFF;
			POWER_ST_OFF = ON;	
		}
	}
	else if(POWER_ST_ON)
	{
		POWER_KEEP(SET);
		if(!POWER_DETECT)
		{
			POWER_ST_ON = OFF;
			POWER_ST_OFF = ON;
			power_off_delay = 119;		//15s
			//SaveVehodo();
			EEODOFLAG = 1;
		}
	}
	else if(POWER_ST_OFF)
	{
		power_off_delay--;
		//if(power_off_delay == 9)			
		//{
        //   SaveODO(SPEED_0);
		//}
		if(POWER_DETECT)
		{
			POWER_ST_ON = ON;
			POWER_ST_OFF = OFF;
		}
		//应该需要存储一下里程以及参数数据
		if(0 == power_off_delay)		//DB Sleep
		{
			POWER_ST_STOP;
			POWER_KEEP(RESET);
		}
	}
}

void CopyReceData(uint8_t *Des,volatile uint8_t *Souc,uint8_t n)
{
   uint8_t i;
   for(i = 0;i < n;i++)
   	Des[i] = Souc[i];
}



void InitSwitch()
{
    port_mask.qword = 0xFFFFFFFFFFFFFFFF;
#if (( defined LevelSet_A20_IN ) && ( LevelSet_A20_IN == HighEnable )) //A20定义为低边开关
    Mask_GND = 0;
#endif
#if (( defined LevelSet_C17_IN ) && ( LevelSet_C17_IN == HighEnable ))
    Mask_C17 = 0;
#endif
#if (( defined LevelSet_E02_IN ) && ( LevelSet_E02_IN == HighEnable ))
    Mask_E2 = 0;
#endif

#if (( defined LevelSet_A12_IN ) && ( LevelSet_A12_IN == HighEnable ))
    Mask_A12 = 0;
#endif

    Mask_A20 = 0;

#if (( defined LevelSet_D06_IN ) && ( LevelSet_D06_IN == HighEnable ))
    Mask_D6 = 0;
#endif
#if (( defined LevelSet_D14_IN ) && ( LevelSet_D14_IN == HighEnable ))
    Mask_D14 = 0;
#endif
#if (( defined LevelSet_D05_IN ) && ( LevelSet_D05_IN == HighEnable ))
    Mask_D5 = 0;
#endif
#if (( defined LevelSet_D13_IN ) && ( LevelSet_D13_IN == HighEnable ))
    Mask_D13 = 0;
#endif
#if (( defined LevelSet_D04_IN ) && ( LevelSet_D04_IN == HighEnable ))
    Mask_D4 = 0;
#endif
#if (( defined LevelSet_D12_IN ) && ( LevelSet_D12_IN == HighEnable ))
    Mask_D12 = 0;
#endif
#if (( defined LevelSet_D03_IN ) && ( LevelSet_D03_IN == HighEnable ))
    Mask_D3 = 0;
#endif
#if (( defined LevelSet_D11_IN ) && ( LevelSet_D11_IN == HighEnable ))
    Mask_D11 = 0;
#endif
#if (( defined LevelSet_B02_IN ) && ( LevelSet_B02_IN == HighEnable ))
    Mask_B2 = 0;
#endif
#if (( defined LevelSet_B08_IN ) && ( LevelSet_B08_IN == HighEnable ))
    Mask_B8 = 0;
#endif
#if (( defined LevelSet_B01_IN ) && ( LevelSet_B01_IN == HighEnable ))
    Mask_B1 = 0;
#endif
#if (( defined LevelSet_B07_IN ) && ( LevelSet_B07_IN == HighEnable ))
    Mask_B7 = 0;
#endif
#if (( defined LevelSet_D08_IN ) && ( LevelSet_D08_IN == HighEnable ))
    Mask_D8 = 0;
#endif
#if (( defined LevelSet_D16_IN ) && ( LevelSet_D16_IN == HighEnable ))
    Mask_D16 = 0;
#endif
#if (( defined LevelSet_D07_IN ) && ( LevelSet_D07_IN == HighEnable ))
    Mask_D7 = 0;
#endif
#if (( defined LevelSet_D15_IN ) && ( LevelSet_D15_IN == HighEnable ))
    Mask_D15 = 0;
#endif
#if (( defined LevelSet_B06_IN ) && ( LevelSet_B06_IN == HighEnable ))
    Mask_B6 = 0;
#endif
#if (( defined LevelSet_B12_IN ) && ( LevelSet_B12_IN == HighEnable ))
    Mask_B12 = 0;
#endif
#if (( defined LevelSet_B05_IN ) && ( LevelSet_B05_IN == HighEnable ))
    Mask_B5 = 0;
#endif
#if (( defined LevelSet_B11_IN ) && ( LevelSet_B11_IN == HighEnable ))
    Mask_B11 = 0;
#endif
#if (( defined LevelSet_B04_IN ) && ( LevelSet_B04_IN == HighEnable ))
    Mask_B4 = 0;
#endif
#if (( defined LevelSet_B10_IN ) && ( LevelSet_B10_IN == HighEnable ))
    Mask_B10 = 0;
#endif
#if (( defined LevelSet_B03_IN ) && ( LevelSet_B03_IN == HighEnable ))
    Mask_B3 = 0;
#endif
#if (( defined LevelSet_B09_IN ) && ( LevelSet_B09_IN == HighEnable ))
    Mask_B9 = 0;
#endif

#if (( defined LevelSet_D02_IN ) && ( LevelSet_D02_IN == HighEnable ))
    Mask_D2 = 0;
#endif
#if (( defined LevelSet_D10_IN ) && ( LevelSet_D10_IN == HighEnable ))
    Mask_D10 = 0;
#endif

#if (( defined LevelSet_D01_IN ) && ( LevelSet_D01_IN == HighEnable ))
    Mask_D1 = 0;
#endif
#if (( defined LevelSet_D09_IN ) && ( LevelSet_D09_IN == HighEnable ))
    Mask_D9 = 0;
#endif

#if (( defined LevelSet_C10_IN ) && ( LevelSet_C10_IN == HighEnable ))
    Mask_C10 = 0;
#endif
#if (( defined LevelSet_C11_IN ) && ( LevelSet_C11_IN == HighEnable ))
    Mask_C11 = 0;
#endif

#if (( defined LevelSet_A10_IN ) && ( LevelSet_A10_IN == HighEnable ))
    Mask_A10 = 0;
#endif
#if (( defined LevelSet_A09_IN ) && ( LevelSet_A09_IN == HighEnable ))
    Mask_A9 = 0;
#endif

#if (( defined LevelSet_A08_IN ) && ( LevelSet_A08_IN == HighEnable ))
    Mask_A8 = 0;
#endif
#if (( defined LevelSet_A07_IN ) && ( LevelSet_A07_IN == HighEnable ))
    Mask_A7 = 0;
#endif
#if (( defined LevelSet_A19_IN ) && ( LevelSet_A19_IN == HighEnable ))
    Mask_A19 = 0;
#endif



#if (( defined LevelSet_C12_IN ) && ( LevelSet_C12_IN == HighEnable ))
    Mask_C12 = 0;
#endif
#if (( defined LevelSet_C13_IN ) && ( LevelSet_C13_IN == HighEnable ))
    Mask_C13 = 0;
#endif
#if (( defined LevelSet_C14_IN ) && ( LevelSet_C14_IN == HighEnable ))
    Mask_C14 = 0;
#endif
#if (( defined LevelSet_C15_IN ) && ( LevelSet_C15_IN == HighEnable ))
    Mask_C15 = 0;
#endif
#if (( defined LevelSet_C16_IN ) && ( LevelSet_C16_IN == HighEnable ))
    Mask_C16 = 0;
#endif


}



TYPE_32BIT fmode_mask;


//fmode_mask 将安位和采集值异或，0采集值不变，1采集值取反
void InitFMode()
{
    fmode_mask.U32 = 0;
#if (( defined LevelSet_F_A32_IN ) && ( LevelSet_F_A32_IN == HighEnable ))
    Mask_F_P32_IN = 1;
#endif
#if (( defined LevelSet_F_A18_IN ) && ( LevelSet_F_A18_IN == HighEnable ))
    Mask_F_P18_IN = 1;
#endif
#if (( defined LevelSet_F_A33_IN ) && ( LevelSet_F_A33_IN == HighEnable ))
    Mask_F_P33_IN = 1;
#endif
#if (( defined LevelSet_F_A19_IN ) && ( LevelSet_F_A19_IN == HighEnable ))
    Mask_F_P19_IN = 1;
#endif
#if (( defined LevelSet_F_A34_IN ) && ( LevelSet_F_A34_IN == HighEnable ))
    Mask_F_P34_IN = 1;
#endif
#if (( defined LevelSet_F_A20_IN ) && ( LevelSet_F_A20_IN == HighEnable ))
    Mask_F_P20_IN = 1;
#endif
#if (( defined LevelSet_F_A35_IN ) && ( LevelSet_F_A35_IN == HighEnable ))
    Mask_F_P35_IN = 1;
#endif
#if (( defined LevelSet_F_A21_IN ) && ( LevelSet_F_A21_IN == HighEnable ))
    Mask_F_P21_IN = 1;
#endif
#if (( defined LevelSet_F_A36_IN ) && ( LevelSet_F_A36_IN == HighEnable ))
    Mask_F_P36_IN = 1;
#endif
#if (( defined LevelSet_F_A22_IN ) && ( LevelSet_F_A22_IN == HighEnable ))
    Mask_F_P22_IN = 1;
#endif
#if (( defined LevelSet_F_A37_IN ) && ( LevelSet_F_A37_IN == HighEnable ))
    Mask_F_P37_IN = 1;
#endif
#if (( defined LevelSet_F_A23_IN ) && ( LevelSet_F_A23_IN == HighEnable ))
    Mask_F_P23_IN = 1;
#endif
#if (( defined LevelSet_F_A38_IN ) && ( LevelSet_F_A38_IN == HighEnable ))
    Mask_F_P38_IN = 1;
#endif
#if (( defined LevelSet_F_A24_IN ) && ( LevelSet_F_A24_IN == HighEnable ))
    Mask_F_P24_IN = 1;
#endif
#if (( defined LevelSet_F_A39_IN ) && ( LevelSet_F_A39_IN == HighEnable ))
    Mask_F_P39_IN = 1;
#endif

#if (( defined LevelSet_F_A17_IN ) && ( LevelSet_F_A17_IN == HighEnable ))
    Mask_F_P17_IN = 0;
#endif

#if (( defined LevelSet_F_A17_IN ) && ( LevelSet_F_A17_IN == LowEnable ))
    Mask_F_P17_IN = 1;
#endif

#if (( defined LevelSet_F_A41_IN ) && ( LevelSet_F_A41_IN == HighEnable ))
    Mask_F_P41_IN = 1;
#endif

}

TYPE_32BIT rmode_mask;

void InitRMode()
{
    rmode_mask.U32 = 0;
#if (( defined LevelSet_R_A32_IN ) && ( LevelSet_R_A32_IN == HighEnable ))
    Mask_R_P32_IN = 1;
#endif
#if (( defined LevelSet_R_A18_IN ) && ( LevelSet_R_A18_IN == HighEnable ))
    Mask_R_P18_IN = 1;
#endif
#if (( defined LevelSet_R_A33_IN ) && ( LevelSet_R_A33_IN == HighEnable ))
    Mask_R_P33_IN = 1;
#endif
#if (( defined LevelSet_R_A19_IN ) && ( LevelSet_R_A19_IN == HighEnable ))
    Mask_R_P19_IN = 1;
#endif
#if (( defined LevelSet_R_A34_IN ) && ( LevelSet_R_A34_IN == HighEnable ))
    Mask_R_P34_IN = 1;
#endif
#if (( defined LevelSet_R_A20_IN ) && ( LevelSet_R_A20_IN == HighEnable ))
    Mask_R_P20_IN = 1;
#endif
#if (( defined LevelSet_R_A35_IN ) && ( LevelSet_R_A35_IN == HighEnable ))
    Mask_R_P35_IN = 1;
#endif
#if (( defined LevelSet_R_A21_IN ) && ( LevelSet_R_A21_IN == HighEnable ))
    Mask_R_P21_IN = 1;
#endif
#if (( defined LevelSet_R_A36_IN ) && ( LevelSet_R_A36_IN == HighEnable ))
    Mask_R_P36_IN = 1;
#endif
#if (( defined LevelSet_R_A22_IN ) && ( LevelSet_R_A22_IN == HighEnable ))
    Mask_R_P22_IN = 1;
#endif
#if (( defined LevelSet_R_A37_IN ) && ( LevelSet_R_A37_IN == HighEnable ))
    Mask_R_P37_IN = 1;
#endif
#if (( defined LevelSet_R_A23_IN ) && ( LevelSet_R_A23_IN == HighEnable ))
    Mask_R_P23_IN = 1;
#endif
#if (( defined LevelSet_R_A38_IN ) && ( LevelSet_R_A38_IN == HighEnable ))
    Mask_R_P38_IN = 1;
#endif
#if (( defined LevelSet_R_A24_IN ) && ( LevelSet_R_A24_IN == HighEnable ))
    Mask_R_P24_IN = 1;
#endif
#if (( defined LevelSet_R_A39_IN ) && ( LevelSet_R_A39_IN == HighEnable ))
    Mask_R_P39_IN = 1;
#endif

#if (( defined LevelSet_R_A17_IN ) && ( LevelSet_R_A17_IN == HighEnable ))
    Mask_R_P17_IN = 0;
#endif

#if (( defined LevelSet_R_A17_IN ) && ( LevelSet_R_A17_IN == LowEnable ))
    Mask_R_P17_IN = 1;
#endif

#if (( defined LevelSet_R_A41_IN ) && ( LevelSet_R_A41_IN == HighEnable ))
    Mask_R_P41_IN = 1;
#endif

}

TYPE_32BIT tmode_mask;

void InitTMode()
{
    tmode_mask.U32 = 0;

#if (( defined LevelSet_T_A32_IN ) && ( LevelSet_T_A32_IN == HighEnable ))
    Mask_T_P32_IN = 1;
#endif
#if (( defined LevelSet_T_A18_IN ) && ( LevelSet_T_A18_IN == HighEnable ))
    Mask_T_P18_IN = 1;
#endif
#if (( defined LevelSet_T_A33_IN ) && ( LevelSet_T_A33_IN == HighEnable ))
    Mask_T_P33_IN = 1;
#endif
#if (( defined LevelSet_T_A19_IN ) && ( LevelSet_T_A19_IN == HighEnable ))
    Mask_T_P19_IN = 1;
#endif
#if (( defined LevelSet_T_A34_IN ) && ( LevelSet_T_A34_IN == HighEnable ))
    Mask_T_P34_IN = 1;
#endif
#if (( defined LevelSet_T_A20_IN ) && ( LevelSet_T_A20_IN == HighEnable ))
    Mask_T_P20_IN = 1;
#endif
#if (( defined LevelSet_T_A35_IN ) && ( LevelSet_T_A35_IN == HighEnable ))
    Mask_T_P35_IN = 1;
#endif
#if (( defined LevelSet_T_A21_IN ) && ( LevelSet_T_A21_IN == HighEnable ))
    Mask_T_P21_IN = 1;
#endif
#if (( defined LevelSet_T_A36_IN ) && ( LevelSet_T_A36_IN == HighEnable ))
    Mask_T_P36_IN = 1;
#endif
#if (( defined LevelSet_T_A22_IN ) && ( LevelSet_T_A22_IN == HighEnable ))
    Mask_T_P22_IN = 1;
#endif
#if (( defined LevelSet_T_A37_IN ) && ( LevelSet_T_A37_IN == HighEnable ))
    Mask_T_P37_IN = 1;
#endif
#if (( defined LevelSet_T_A23_IN ) && ( LevelSet_T_A23_IN == HighEnable ))
    Mask_T_P23_IN = 1;
#endif
#if (( defined LevelSet_T_A38_IN ) && ( LevelSet_T_A38_IN == HighEnable ))
    Mask_T_P38_IN = 1;
#endif
#if (( defined LevelSet_T_A24_IN ) && ( LevelSet_T_A24_IN == HighEnable ))
    Mask_T_P24_IN = 1;
#endif
#if (( defined LevelSet_T_A39_IN ) && ( LevelSet_T_A39_IN == HighEnable ))
    Mask_T_P39_IN = 1;
#endif

#if (( defined LevelSet_T_A17_IN ) && ( LevelSet_T_A17_IN == HighEnable ))
    Mask_T_P17_IN = 0;
#endif

#if (( defined LevelSet_T_A17_IN ) && ( LevelSet_T_A17_IN == LowEnable ))
    Mask_T_P17_IN = 1;
#endif

#if (( defined LevelSet_T_A41_IN ) && ( LevelSet_T_A41_IN == HighEnable ))
    Mask_T_P41_IN = 1;
#endif

}

void initPWM_F(void)
{
    F_Set_PWM.word = 0x0000;
#if (( defined PWM_F_P01 ) && ( PWM_F_P01 == PWMEable))
    F_Set_PWM.bit.b0 = 1;
#endif
#if (( defined PWM_F_P09 ) && ( PWM_F_P09 == PWMEable))
    F_Set_PWM.bit.b1 = 1;
#endif
#if (( defined PWM_F_P02 ) && ( PWM_F_P02 == PWMEable))
    F_Set_PWM.bit.b2 = 1;
#endif
#if (( defined PWM_F_P10 ) && ( PWM_F_P10 == PWMEable))
    F_Set_PWM.bit.b3 = 1;
#endif
#if (( defined PWM_F_P03 ) && ( PWM_F_P03 == PWMEable))
    F_Set_PWM.bit.b4 = 1;
#endif
#if (( defined PWM_F_P11 ) && ( PWM_F_P11 == PWMEable))
    F_Set_PWM.bit.b5 = 1;
#endif
#if (( defined PWM_F_P04 ) && ( PWM_F_P04 == PWMEable))
    F_Set_PWM.bit.b6 = 1;
#endif
#if (( defined PWM_F_P12 ) && ( PWM_F_P12 == PWMEable))
    F_Set_PWM.bit.b7 = 1;
#endif
#if (( defined PWM_F_P05 ) && ( PWM_F_P05 == PWMEable))
    F_Set_PWM.bit.b8 = 1;
#endif
#if (( defined PWM_F_P13 ) && ( PWM_F_P13 == PWMEable))
    F_Set_PWM.bit.b9 = 1;
#endif
#if (( defined PWM_F_P06 ) && ( PWM_F_P06 == PWMEable))
    F_Set_PWM.bit.b10 = 1;
#endif
#if (( defined PWM_F_P14 ) && ( PWM_F_P14 == PWMEable))
    F_Set_PWM.bit.b11 = 1;
#endif
#if (( defined PWM_F_P07 ) && ( PWM_F_P07 == PWMEable))
    F_Set_PWM.bit.b12 = 1;
#endif
#if (( defined PWM_F_P42 ) && ( PWM_F_P42 == PWMEable))
    F_Set_PWM.bit.b13 = 1;
#endif
#if (( defined PWM_F_P08 ) && ( PWM_F_P08 == PWMEable))
    F_Set_PWM.bit.b14 = 1;
#endif

}

void initPWM_R(void)
{
    R_Set_PWM.word = 0x0000;
#if (( defined PWM_R_P01 ) && ( PWM_R_P01 == PWMEable))
    R_Set_PWM.bit.b0 = 1;
#endif
#if (( defined PWM_R_P09 ) && ( PWM_R_P09 == PWMEable))
    R_Set_PWM.bit.b1 = 1;
#endif
#if (( defined PWM_R_P02 ) && ( PWM_R_P02 == PWMEable))
    R_Set_PWM.bit.b2 = 1;
#endif
#if (( defined PWM_R_P10 ) && ( PWM_R_P10 == PWMEable))
    R_Set_PWM.bit.b3 = 1;
#endif
#if (( defined PWM_R_P03 ) && ( PWM_R_P03 == PWMEable))
    R_Set_PWM.bit.b4 = 1;
#endif
#if (( defined PWM_R_P11 ) && ( PWM_R_P11 == PWMEable))
    R_Set_PWM.bit.b5 = 1;
#endif
#if (( defined PWM_R_P04 ) && ( PWM_R_P04 == PWMEable))
    R_Set_PWM.bit.b6 = 1;
#endif
#if (( defined PWM_R_P12 ) && ( PWM_R_P12 == PWMEable))
    R_Set_PWM.bit.b7 = 1;
#endif
#if (( defined PWM_R_P05 ) && ( PWM_R_P05 == PWMEable))
    R_Set_PWM.bit.b8 = 1;
#endif
#if (( defined PWM_R_P13 ) && ( PWM_R_P13 == PWMEable))
    R_Set_PWM.bit.b9 = 1;
#endif
#if (( defined PWM_R_P06 ) && ( PWM_R_P06 == PWMEable))
    R_Set_PWM.bit.b10 = 1;
#endif
#if (( defined PWM_R_P14 ) && ( PWM_R_P14 == PWMEable))
    R_Set_PWM.bit.b11 = 1;
#endif
#if (( defined PWM_R_P07 ) && ( PWM_R_P07 == PWMEable))
    R_Set_PWM.bit.b12 = 1;
#endif
#if (( defined PWM_R_P42 ) && ( PWM_R_P42 == PWMEable))
    R_Set_PWM.bit.b13 = 1;
#endif
#if (( defined PWM_R_P08 ) && ( PWM_R_P08 == PWMEable))
    R_Set_PWM.bit.b14 = 1;
#endif

}


void initPWM_T(void)
{
    T_Set_PWM.word = 0x0000;
#if (( defined PWM_T_P01 ) && ( PWM_T_P01 == PWMEable))
    T_Set_PWM.bit.b0 = 1;
#endif
#if (( defined PWM_T_P09 ) && ( PWM_T_P09 == PWMEable))
    T_Set_PWM.bit.b1 = 1;
#endif
#if (( defined PWM_T_P02 ) && ( PWM_T_P02 == PWMEable))
    T_Set_PWM.bit.b2 = 1;
#endif
#if (( defined PWM_T_P10 ) && ( PWM_T_P10 == PWMEable))
    T_Set_PWM.bit.b3 = 1;
#endif
#if (( defined PWM_T_P03 ) && ( PWM_T_P03 == PWMEable))
    T_Set_PWM.bit.b4 = 1;
#endif
#if (( defined PWM_T_P11 ) && ( PWM_T_P11 == PWMEable))
    T_Set_PWM.bit.b5 = 1;
#endif
#if (( defined PWM_T_P04 ) && ( PWM_T_P04 == PWMEable))
    T_Set_PWM.bit.b6 = 1;
#endif
#if (( defined PWM_T_P12 ) && ( PWM_T_P12 == PWMEable))
    T_Set_PWM.bit.b7 = 1;
#endif
#if (( defined PWM_T_P05 ) && ( PWM_T_P05 == PWMEable))
    T_Set_PWM.bit.b8 = 1;
#endif
#if (( defined PWM_T_P13 ) && ( PWM_T_P13 == PWMEable))
    T_Set_PWM.bit.b9 = 1;
#endif
#if (( defined PWM_T_P06 ) && ( PWM_T_P06 == PWMEable))
    T_Set_PWM.bit.b10 = 1;
#endif
#if (( defined PWM_T_P14 ) && ( PWM_T_P14 == PWMEable))
    T_Set_PWM.bit.b11 = 1;
#endif
#if (( defined PWM_T_P07 ) && ( PWM_T_P07 == PWMEable))
    T_Set_PWM.bit.b12 = 1;
#endif
#if (( defined PWM_T_P42 ) && ( PWM_T_P42 == PWMEable))
    T_Set_PWM.bit.b13 = 1;
#endif
#if (( defined PWM_T_P08 ) && ( PWM_T_P08 == PWMEable))
    T_Set_PWM.bit.b14 = 1;
#endif

}

void All_Pwm(void)
{
  F_Set_PWM.word = 0x7fff;
  R_Set_PWM.word = 0x7fff;
  T_Set_PWM.word = 0x7fff;
}
void InitPWM(void)
{
    #if MODLE_ALL_PWM
      All_Pwm();
	#else 
	initPWM_F();
	initPWM_R();
	initPWM_T();
	#endif
}



void Send_PWM_Bcm(void)
{
    uint8_t i,data[8];

    data[0] = F_Set_PWM.byte[0];
	data[1] = F_Set_PWM.byte[1];
    data[2] = R_Set_PWM.byte[0];
	data[3] = R_Set_PWM.byte[1];
    data[4] = T_Set_PWM.byte[0];
	data[5] = T_Set_PWM.byte[1];
    data[6] = UNUSED;
	data[7] = UNUSED;
    BCan_Standard_Tx_Bytes(0x6E4,data,8);
} 

//雨刮配置
void RainConfig(void)
{
    CTL_WIPER_HI = SYSTEM_POW && WIPER_HI_SW;      //快档
    if(CTL_WIPER_HI == ON)
        CTL_WIPER_LO = OFF;
    else
        CTL_WIPER_LO = SYSTEM_POW && WIPER_LO_SW;  //慢档
    CTL_WIPER_MI = SYSTEM_POW && WIPER_MI_SW;      //喷水开关
    CTL_WIPER_INT = SYSTEM_POW && WIPER_INT_SW;     //间歇档

    if(CTL_WIPER_MI ==ON)
    {
        CTL_WIPER_HI = OFF;
        CTL_WIPER_LO = OFF;
        CTL_WIPER_INT = OFF;
    }
    CTL_KEY_ON  = KEY_ON;
    CTL_KEY_ACC = KEY_ACC;
}

void MeterAndBCMPortInit(void)
{
	InitSwitch();
	InitFMode();
	InitRMode();
	InitTMode();
	
	//模块PWM初始化
	InitPWM();
}





