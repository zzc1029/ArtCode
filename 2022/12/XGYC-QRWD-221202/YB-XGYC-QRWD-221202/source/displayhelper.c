/*
 * displayhelper.c
 *
 *  Created on: 2021-11-30
 *      Author: ART
 */

#include "system_init.h"
#include "keyfifo.h"


 //视频手动标志，0自动，1手动
 //当 视频 键按下是置1，所有 视频自动切换信号没有后 清0
 static uint32_t VedioManual = 0;
 u8  initflag = 1;
 static uint8_t choose_menu = 0;
 static u8 timedata[5];

 static u8 NoEncryptSetVar[8] = {0};
 const uint16_t password = 1127;
 static u16 set_password;



 
 DisMenuStruct disp[MAXDISMENU];
 u32 MenuNum = 0;


 
 u8 SetOption = 0;
 u8 ClearBufferDisable = 0;
 
 typedef struct
 {
	 unsigned char bs0: 4;
	 unsigned char bs1: 4;
 } BYTE_4BITFIELD;
 
 typedef union
 {
	 unsigned char byte;
	 BYTE_4BITFIELD  bit;
 } BYTE_4Bit_Union;
 
 
 static BYTE_4Bit_Union PageInfo[8] = {0};
 
 
 void SendKeyToGPU(u8 key)
 {
	 uint8_t i;
	 for(i = 1; i < 12; i++)
	 {
		 Send_To_DP_Data[i] = 0;
	 }
 
	 Send_To_DP_Data[0] = 0x80;
	 Send_To_DP_Data[1] = 0x03;
	 Send_To_DP_Data[2] = 0x02;
 
	 Send_To_DP_Data[3] = key;
 
	 SendToDP();
 
 }
 
 
 void ChangeToSubPageCache(uint8_t menu, uint8_t subpage)
 {
	 uint8_t i;
	 for(i = 1; i < 12; i++)
	 {
		 Send_To_DP_Data[i] = 0;
	 }
 
	 Send_To_DP_Data[0] = 0x80;
	 Send_To_DP_Data[1] = 0x03;
	 Send_To_DP_Data[2] = 0x01;
 
	 switch(menu)
	 {
		 case SET_MODE:
			 if(SET_VIDEO_AV1 && SET_VIDEO_AV2 && SET_VIDEO_AV3 && SET_VIDEO_AV4)
			 {
				 PageInfo[0].bit.bs0 = subpage | 0x04 ;
			 }
			 else
			 {
				 PageInfo[0].bit.bs0 = subpage ;
			 }
			 break;
		 case DIS_VEDIO:
			 PageInfo[0].bit.bs1 = subpage;
			 break;
		 case DIS_SYSTEM_SET_MENU:
			 PageInfo[1].bit.bs0 = subpage;
			 break;
		 case DIS_BMS_MENU:
			 PageInfo[1].bit.bs1 = subpage;
			 break;
		 case DIS_ART_INFORMATION:
			 PageInfo[2].bit.bs0 = subpage;
			 break;
		 case DIS_MAIN:
			 PageInfo[2].bit.bs1 = subpage;
			 break;
		 case DIS_FUZU_MENU:
			 PageInfo[3].bit.bs0 = subpage;
			 break;
		 case SET_JMP_PAGE:
			 choose_menu = subpage;
			 PageInfo[7].byte = subpage;
			 break;
	 }
 
	 PageInfo[6].byte = dis_mod;
 
	 for(i = 0; i < 8; i++)
	 {
		 Send_To_DP_Data[i + 3] = PageInfo[i].byte;
	 }
 
 
 }
 
 
 void ChangeToSubPage(uint8_t menu, uint8_t subpage)
 {
	 ChangeToSubPageCache(menu, subpage);
	 SendToDP();
	 if(SET_JMP_PAGE == menu)
	 {
		 SendKeyToGPU(CMD_JMP_PAGE);
	 }
 }
 
 
 
 
 void PushDataToGPU()
 {
	 uint8_t i;
 
	 Send_To_DP_Data[0] = 0x80;
	 Send_To_DP_Data[1] = 0x03;
	 Send_To_DP_Data[2] = 0x01;
 
	 for(i = 0; i < 8; i++)
	 {
		 Send_To_DP_Data[i + 3] = PageInfo[i].byte;
	 }
 
	 SendToDP();
 }
 





 
 //处理ON档档位关闭显示手刹图标功能
 static u32 MainMesg(u8 key, u8 initpw)
 {
	 u8 changeflag = 0xFF;
	 static u8 lastflag = 0xFF,lop= 0;
 
	 if((initpw))
	 {
		 SendKeyToGPU(CMD_DIS_PAGE);
		 //SendKeyToGPU(CMD_DIS_MAIN);
		 lastflag = 0xFF;
	 }
 
	 if(ONFlag)
	 {
	     switch(lop)
	     {
            case 0:
				  SendPAGE_MAIN04(1);
				  break;
			case 4:
				  SendPAGE_MAIN05(1);
				  break;
		    case 8:
				  SendPAGE_MAIN06(1);
				  break;
		 }
		 lop++;
		 if(lop > 10)
		 	lop = 0;
	 }
 
	 switch(key)
	 {
		 case IN_KEY1_SP:
			 return DIS_CHOOSE_MENU;
		 case IN_KEY3_CP:
			 if(MILE_COME_FROM == MODULE_MILE)
			 {
				 clr_trip();
			 }
			 else
			 {
				 clear_mile = 1;
				 Veh_trip = 0;
				 //SaveVehodo();
				 EEODOFLAG = 1;
			 }
			 break;
	    case IN_KEY4_CP:
			 //SYSCTL_System_Reset_Enable(TRUE);
			 break;
	 }
	 return DIS_MAIN_MENU;
 }



 static u32 MenuMesg(u8 key, u8 initpw)
 {
	 u8 sendflag = 0;
	 static u8 InitNoEncryptSetFlag = 0;
	 if(initpw)
	 {
		 SendKeyToGPU(CMD_DIS_MENU);
	 }
	 switch(key)
	 {
		 case IN_KEY4_SP:
			 return choose_menu;
		 case IN_KEY2_SP:
			 choose_menu++;
			 if(choose_menu >= DIS_USED_END)
			 {
				 choose_menu = DIS_MAIN_MENU;
			 }
 
			 SendKeyToGPU(CMD_INC_MENU);
			 break;
		 case IN_KEY3_SP:
			 if(choose_menu == DIS_MAIN_MENU)
			 {
				 choose_menu = DIS_USED_END;
			 }
 
			 choose_menu--;
			 SendKeyToGPU(CMD_DEC_MENU);
			 break;
	 }
 
	 return DIS_CHOOSE_MENU;
 
 }


enum
{
    TONY_METER = 0,
#if  (Has_Fmode == ON)
    FMode,
#endif
#if (Has_Rmode == ON)
    RMode,
#endif
#if (Has_Tmode == ON)
    TMode,
#endif
    ARTNum
};


void art_fmod_1(u8 initpw)
{
    TYPE_DWORD    front_power_state;

    SendStart();

    front_power_state.BIT.b0  = (F_OPEN1_A1)  ? F_OUT1_A1 : 3;
    front_power_state.BIT.b1  = (F_OPEN3_A2)  ? F_OUT3_A2 : 3;
    front_power_state.BIT.b2  = (F_OPEN5_A3)  ? F_OUT5_A3 : 3;
    front_power_state.BIT.b3  = (F_OPEN7_A4)  ? F_OUT7_A4 : 3;

    front_power_state.BIT.b4  = (F_OPEN9_A5)  ? F_OUT9_A5  : 3;
    front_power_state.BIT.b5  = (F_OPEN11_A6) ? F_OUT11_A6 : 3;
    front_power_state.BIT.b6  = (F_OPEN13_A7) ? F_OUT13_A7 : 3;
    front_power_state.BIT.b7  = (F_OPEN15_A8) ? F_OUT15_A8 : 3;

    front_power_state.BIT.b8  = (F_OPEN2_A9)  ? F_OUT2_A9 : 3;
    front_power_state.BIT.b9  = (F_OPEN4_A10) ? F_OUT4_A10 : 3;
    front_power_state.BIT.b10 = (F_OPEN6_A11) ? F_OUT6_A11 : 3;
    front_power_state.BIT.b11 = (F_OPEN8_A12) ? F_OUT8_A12 : 3;

    front_power_state.BIT.b12 = (F_OPEN10_A13) ? F_OUT10_A13 : 3;
    front_power_state.BIT.b13 = (F_OPEN12_A14) ? F_OUT12_A14 : 3;
    front_power_state.BIT.b14 = (F_OPEN14_A42) ? F_OUT14_A42 : 3;

    Send_To_DP_Data[0] = 0x08;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x01;
    Send_To_DP_Data[3] = front_power_state.byte[0];
    Send_To_DP_Data[4] = front_power_state.byte[1];
    Send_To_DP_Data[5] = front_power_state.byte[2];
    Send_To_DP_Data[6] = front_power_state.byte[3];
    Send_To_DP_Data[7] = bcm_sw1_f.byte[0];
    Send_To_DP_Data[8] = bcm_sw1_f.byte[1];
    Send_To_DP_Data[9] = bcm_sw2_f.byte;
    SendEnd();
}

void art_fmod_2(u8 initpw)
{
	u16 temp;
    SendStart();

    Send_To_DP_Data[0] = 0x08;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x02;
	temp = bcm_senor1_f * Air_Coef*0.1;
    Send_To_DP_Data[3] = temp;
    Send_To_DP_Data[4] = temp >> 8;
	temp = bcm_senor2_f * Air_Coef*0.1;
    Send_To_DP_Data[5] = temp;
    Send_To_DP_Data[6] = temp >> 8;
    Send_To_DP_Data[7] = bcm_frq_f;
    Send_To_DP_Data[8] = bcm_frq_f >> 8;

    SendEnd();
}

#define  ART_FMODE

SendGroup_Init(ART_FMODE)
{
    art_fmod_1,
    art_fmod_2
};
SendGroup_CodeGen(ART_FMODE);

void art_rmod_1(u8 initpw)
{
    TYPE_DWORD    middle_power_state;

    SendStart();

    middle_power_state.BIT.b0  = (R_OPEN1_A1)  ? R_OUT1_A1 : 3;
    middle_power_state.BIT.b1  = (R_OPEN3_A2)  ? R_OUT3_A2 : 3;
    middle_power_state.BIT.b2  = (R_OPEN5_A3)  ? R_OUT5_A3 : 3;
    middle_power_state.BIT.b3  = (R_OPEN7_A4)  ? R_OUT7_A4 : 3;

    middle_power_state.BIT.b4  = (R_OPEN9_A5)  ? R_OUT9_A5  : 3;
    middle_power_state.BIT.b5  = (R_OPEN11_A6) ? R_OUT11_A6 : 3;
    middle_power_state.BIT.b6  = (R_OPEN13_A7) ? R_OUT13_A7 : 3;
    middle_power_state.BIT.b7  = (R_OPEN15_A8) ? R_OUT15_A8 : 3;

    middle_power_state.BIT.b8  = (R_OPEN2_A9)  ? R_OUT2_A9 : 3;
    middle_power_state.BIT.b9  = (R_OPEN4_A10) ? R_OUT4_A10 : 3;
    middle_power_state.BIT.b10 = (R_OPEN6_A11) ? R_OUT6_A11 : 3;
    middle_power_state.BIT.b11 = (R_OPEN8_A12) ? R_OUT8_A12 : 3;

    middle_power_state.BIT.b12 = (R_OPEN10_A13) ? R_OUT10_A13 : 3;
    middle_power_state.BIT.b13 = (R_OPEN12_A14) ? R_OUT12_A14 : 3;
    middle_power_state.BIT.b14 = (R_OPEN14_A42) ? R_OUT14_A42 : 3;

    Send_To_DP_Data[0] = 0x09;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x01;
    Send_To_DP_Data[3] = middle_power_state.byte[0];
    Send_To_DP_Data[4] = middle_power_state.byte[1];
    Send_To_DP_Data[5] = middle_power_state.byte[2];
    Send_To_DP_Data[6] = middle_power_state.byte[3];
    Send_To_DP_Data[7] = bcm_sw1_r.byte[0];
    Send_To_DP_Data[8] = bcm_sw1_r.byte[1];
    Send_To_DP_Data[9] = bcm_sw2_r.byte;
    SendEnd();
}

extern u8 Frist_Temp_1;
void art_rmod_2(u8 initpw)
{
    SendStart();

    Send_To_DP_Data[0] = 0x09;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x02;

    Send_To_DP_Data[3] = bcm_senor1_r;
    Send_To_DP_Data[4] = bcm_senor1_r >> 8;
    Send_To_DP_Data[5] = bcm_senor2_r;
    Send_To_DP_Data[6] = bcm_senor2_r >> 8;
    Send_To_DP_Data[7] = bcm_frq_r;
    Send_To_DP_Data[8] = bcm_frq_r >> 8;
    Send_To_DP_Data[9] = Temp_Vbat;

    SendEnd();
}

#define  ART_RMODE

SendGroup_Init(ART_RMODE)
{
    art_rmod_1,
    art_rmod_2
};
SendGroup_CodeGen(ART_RMODE);


void art_tmod_1(u8 initpw)
{
    TYPE_DWORD    top_power_state;

    SendStart();

    top_power_state.BIT.b0  = (T_OPEN1_A1 == 1)  ? T_OUT1_A1 : 3;
    top_power_state.BIT.b1  = (T_OPEN3_A2 == 1)  ? T_OUT3_A2 : 3;
    top_power_state.BIT.b2  = (T_OPEN5_A3 == 1)  ? T_OUT5_A3 : 3;
    top_power_state.BIT.b3  = (T_OPEN7_A4 == 1)  ? T_OUT7_A4 : 3;

    top_power_state.BIT.b4  = (T_OPEN9_A5 == 1)  ? T_OUT9_A5 : 3;
    top_power_state.BIT.b5  = (T_OPEN11_A6 == 1) ? T_OUT11_A6 : 3;
    top_power_state.BIT.b6  = (T_OPEN13_A7 == 1) ? T_OUT13_A7 : 3;
    top_power_state.BIT.b7  = (T_OPEN15_A8 == 1) ? T_OUT15_A8 : 3;
    top_power_state.BIT.b8  = (T_OPEN2_A9 == 1)  ? T_OUT2_A9 : 3;
    top_power_state.BIT.b9  = (T_OPEN4_A10 == 1) ? T_OUT4_A10 : 3;
    top_power_state.BIT.b10 = (T_OPEN6_A11 == 1) ? T_OUT6_A11 : 3;
    top_power_state.BIT.b11 = (T_OPEN8_A12 == 1) ? T_OUT8_A12 : 3;

    top_power_state.BIT.b12 = (T_OPEN10_A13 == 1) ? T_OUT10_A13 : 3;
    top_power_state.BIT.b13 = (T_OPEN12_A14 == 1) ? T_OUT12_A14 : 3;
    top_power_state.BIT.b14 = (T_OPEN14_A42 == 1) ? T_OUT14_A42 : 3;

    Send_To_DP_Data[0] = 0x0A;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x01;

    Send_To_DP_Data[3] = top_power_state.byte[0];
    Send_To_DP_Data[4] = top_power_state.byte[1];
    Send_To_DP_Data[5] = top_power_state.byte[2];
    Send_To_DP_Data[6] = top_power_state.byte[3];
    Send_To_DP_Data[7] = bcm_sw1_t.byte[0];
    Send_To_DP_Data[8] = bcm_sw1_t.byte[1];
    Send_To_DP_Data[9] = bcm_sw2_t.byte;

    SendEnd();
}

void art_tmod_2(u8 initpw)
{
    SendStart();

    Send_To_DP_Data[0] = 0x0A;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x02;

    Send_To_DP_Data[3] = bcm_senor1_t;
    Send_To_DP_Data[4] = bcm_senor1_t >> 8;
    Send_To_DP_Data[5] = bcm_senor2_t;
    Send_To_DP_Data[6] = bcm_senor2_t >> 8;
    Send_To_DP_Data[7] = bcm_frq_t;
    Send_To_DP_Data[8] = bcm_frq_t >> 8;

    SendEnd();
}

#define  ART_TMODE

SendGroup_Init(ART_TMODE)
{
    art_tmod_1,
    art_tmod_2
};
SendGroup_CodeGen(ART_TMODE);


#define METER_A01            METER_OPEN_E3  		
#define METER_A04            METER_OPEN_E6  		
#define METER_A02            METER_OPEN_E7  		
#define METER_A03            METER_OPEN_E8  		
#define METER_A05            METER_OPEN_WAKE_UP   //24V唤醒信号输出(AMP20接口的A16)
		
#define METER_A01_FeedBack   METER_OUT_E3       
#define METER_A03_FeedBack   METER_OUT_E8       
#define METER_A04_FeedBack   METER_OUT_E7       
#define METER_A02_FeedBack   METER_OUT_E6       
		
#define METER_A05_FeedBack   METER_OUT_WAKE_UP  


void Art_Meter_1(u8 initpw)
{
    static TYPE_BYTE temp = {0};

    SendStart();
    /****************更改BY CODE3 20170919****************************/

    Send_To_DP_Data[0] = 0x07;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x01;

    //增加C52仪表接口处理
    temp.byte = 0;
    temp.bit.b0 = PTA7;
    temp.bit.b1 = PTA8;
    temp.bit.b2 = PTA9;
    temp.bit.b3 = PTA10;
    temp.bit.b4 = PTA12;
    temp.bit.b5 = PTA19;
    temp.bit.b6 = PTA20;
    temp.bit.b7 = PTB1;

    Send_To_DP_Data[3] = temp.byte;

    temp.byte = 0;
    temp.bit.b0 = PTB2;
    temp.bit.b1 = PTB3;
    temp.bit.b2 = PTB4;
    temp.bit.b3 = PTB5;
    temp.bit.b4 = PTB6;
    temp.bit.b5 = PTB7;
    temp.bit.b6 = PTB8;
    temp.bit.b7 = PTB9;

    Send_To_DP_Data[4] = temp.byte;

    temp.byte = 0;
    temp.bit.b0 = PTB10;
    temp.bit.b1 = PTB11;
    temp.bit.b2 = PTB12;
    temp.bit.b3 = PTC10;
    temp.bit.b4 = PTC11;
    temp.bit.b5 = PTC12;
    temp.bit.b6 = PTC13;
    temp.bit.b7 = PTC14;

    Send_To_DP_Data[5] = temp.byte;

    temp.byte = 0;
    temp.bit.b0 = PTC15;
    temp.bit.b1 = PTC16;
    temp.bit.b2 = PTC17;
    temp.bit.b3 = PTC18;
    temp.bit.b4 = PTD1;
    temp.bit.b5 = PTD2;
    temp.bit.b6 = PTD3;
    temp.bit.b7 = PTD4;

    Send_To_DP_Data[6] = temp.byte;

    temp.byte = 0;
    temp.bit.b0 = PTD5;
    temp.bit.b1 = PTD6;
    temp.bit.b2 = PTD7;
    temp.bit.b3 = PTD8;
    temp.bit.b4 = PTD9;
    temp.bit.b5 = PTD10;
    temp.bit.b6 = PTD11;
    temp.bit.b7 = PTD12;

    Send_To_DP_Data[7] = temp.byte;

    temp.byte = 0;
    temp.bit.b0 = PTD13;
    temp.bit.b1 = PTD14;
    temp.bit.b2 = PTD15;
    temp.bit.b3 = PTD16;
    temp.bit.b4 = PTE2;
    temp.bit.b5 = 0;

    temp.bits.bits3 = METER_A05 ? ((METER_A05_FeedBack == 2) ? 2 : 0) : 3; //A16
	Send_To_DP_Data[8] = temp.byte;

    temp.byte = 0;
    //3关闭 0正常 2 短路
    temp.bits.bits0 = METER_A01 ? ((METER_A01_FeedBack == 2) ? 2 : 0) : 3;
    temp.bits.bits1 = METER_A04 ? ((METER_A04_FeedBack == 2) ? 2 : 0) : 3;
    temp.bits.bits2 = METER_A02 ? ((METER_A02_FeedBack == 2) ? 2 : 0) : 3;
    temp.bits.bits3 = METER_A03 ? ((METER_A03_FeedBack == 2) ? 2 : 0) : 3;

    Send_To_DP_Data[9] = temp.byte; //E3 ~ E8
    SendEnd();
}

void Art_Meter_2(u8 initpw)
{
    SendStart();
    Send_To_DP_Data[0] = 0x07;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x02;

    Send_To_DP_Data[3] = meter.MeterA5;
    Send_To_DP_Data[4] = meter.MeterA5 >> 8;  //A5
    Send_To_DP_Data[5] = meter.MeterA15;
    Send_To_DP_Data[6] = meter.MeterA15 >> 8;  //A15
    Send_To_DP_Data[7] = meter.MeterA2;
    Send_To_DP_Data[8] = meter.MeterA2 >> 8; //A2
    Send_To_DP_Data[9] = UNUSED;//meter.port_c19;
    Send_To_DP_Data[10] = UNUSED;//meter.port_c19 >> 8; //C3

    SendEnd();
}

void Art_Meter_3(u8 initpw)
{
    SendStart();

    Send_To_DP_Data[0] = 0x07;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x03;


    Send_To_DP_Data[3] = meter.MeterA3;
    Send_To_DP_Data[4] = meter.MeterA3 >> 8;//A3
    Send_To_DP_Data[5] = meter.MeterA4;
    Send_To_DP_Data[6] = meter.MeterA4 >> 8;//A4
    Send_To_DP_Data[7] = meter.MeterA13;
    Send_To_DP_Data[8] = meter.MeterA13 >> 8;//A13
    Send_To_DP_Data[9] = meter.MeterA14;
    Send_To_DP_Data[10] = meter.MeterA14 >> 8;//A14


    SendEnd();
}

void Art_Meter_4(u8 initpw)
{
    TYPE_BYTE temp;

    SendStart();

    Send_To_DP_Data[0] = 0x07;
    Send_To_DP_Data[1] = 0x01;
    Send_To_DP_Data[2] = 0x04;

	Send_To_DP_Data[3] = SOFT_VERSION;
	#if 0
    //0关闭 1正常 2 短路
    temp.bits.bits0 = METER_A05 ? ((METER_A05_FeedBack == 2) ? 2 : 1) : 0;
    temp.bits.bits1 = METER_A01 ? ((METER_A01_FeedBack == 2) ? 2 : 1) : 0;
    temp.bits.bits2 = METER_A03 ? ((METER_A03_FeedBack == 2) ? 2 : 1) : 0;
    temp.bits.bits3 = METER_A04 ? ((METER_A04_FeedBack == 2) ? 2 : 1) : 0;

    Send_To_DP_Data[3] = temp.byte;

    temp.bits.bits0 = METER_A02 ? ((METER_A02_FeedBack == 2) ? 2 : 1) : 0;
    temp.bits.bits2 = 0;

    Send_To_DP_Data[4] = temp.byte;
	#endif

    SendEnd();
}


#if 0
void Art_Meter_4(u8 initpw)
{
    SendStart();

    Send_To_DP_Data[0] = 0x01;
    Send_To_DP_Data[1] = 0x07;
    Send_To_DP_Data[2] = 0x04;

    Send_To_DP_Data[3] = meter.port_ap13;
    Send_To_DP_Data[4] = meter.port_ap13 >> 8;
    Send_To_DP_Data[5] = meter.port_ap14;
    Send_To_DP_Data[6] = meter.port_ap14 >> 8;
    Send_To_DP_Data[7] = meter.port_ap14;

    SendEnd();
}

#endif
#define  ART_METER
SendGroup_Init(ART_METER)
{
    Art_Meter_1,
    Art_Meter_2,
    Art_Meter_3,
    Art_Meter_4,
};
SendGroup_CodeGen(ART_METER);



u32 ArtMesg(u8 key, u8 initpw)
{
    static u8 flag = 0;
    u8 changescreenflag = 0;

    if(initpw)
    {
        changescreenflag = 1;
        SendKeyToGPU(CMD_DIS_PAGE);
    }

    switch(key)
    {
        case IN_KEY2_SP:
            flag++;
            flag = (flag >= ARTNum) ? TONY_METER : flag;
            changescreenflag = 1;
            break;
        case IN_KEY3_SP:
            flag = (flag == TONY_METER) ? ARTNum : flag;
            flag--;
            changescreenflag = 1;
            break;
    }
    if(changescreenflag)
    {
        switch(flag)
        {
            case TONY_METER:
                ChangeToSubPage(DIS_ART_INFORMATION, PAGE_METER);
                break;

#if (Has_Fmode == ON)
            case FMode:
                ChangeToSubPage(DIS_ART_INFORMATION, PAGE_FMODE);
                break;
#endif

#if (Has_Rmode == ON)
            case RMode:
                ChangeToSubPage(DIS_ART_INFORMATION, PAGE_RMODE);
                break;
#endif

#if (Has_Tmode == ON)
            case TMode:
                ChangeToSubPage(DIS_ART_INFORMATION, PAGE_TMODE);
                break;

#endif
        }
    }

    switch(flag)
    {
        case TONY_METER:
            SendGroup(ART_METER, changescreenflag);
            break;

#if (Has_Fmode == ON)
        case FMode:
            SendGroup(ART_FMODE, changescreenflag);
            break;
#endif

#if (Has_Rmode == ON)
        case RMode:
            SendGroup(ART_RMODE, changescreenflag);
            break;
#endif

#if (Has_Tmode == ON)
        case TMode:
            SendGroup(ART_TMODE, changescreenflag);
            break;
#endif
    }

    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }
    return DIS_ART_INFORMATION;
}




void u32tostr(u32 dataxxx, u8 *out, u8 optionx, u8 CharNum)
{
    utostrbcd();
}


#define ChTimeStart         0
#define ChTimeLen           (ChangeTimeEnable*5)
 
#define ChBLStart           (ChTimeStart + ChTimeLen)
#define ChBLLen             (ChangeBLEnable*1)
 
#define ChBuzzStart         (ChBLStart + ChBLLen)
#define ChBuzzLen           (ChangeBuzzEnable*1)
 


 void NoEncryptSetToGPU()
 {
	 u8 initpw = 1;
 
	 SendStart();
 
	 Send_To_DP_Data[0] = 4;
	 Send_To_DP_Data[1] = 2;
	 Send_To_DP_Data[2] = 1;
	 DP_DATA1 = NoEncryptSetVar[0];
	 DP_DATA2 = NoEncryptSetVar[1];
	 DP_DATA3 = NoEncryptSetVar[2];
	 DP_DATA4 = NoEncryptSetVar[3];
	 DP_DATA5 = NoEncryptSetVar[4];
	 DP_DATA6 = NoEncryptSetVar[5];
	 DP_DATA7 = NoEncryptSetVar[6];
	 DP_DATA8 = NoEncryptSetVar[7];
 
	 SendEnd();
 }


 void UpdateNoEncryptSetVar()
 {
	 NoEncryptSetVar[1] = rtc.year;
	 NoEncryptSetVar[2] = rtc.month;
	 NoEncryptSetVar[3] = rtc.day;
	 NoEncryptSetVar[4] = rtc.hours;
	 NoEncryptSetVar[5] = rtc.mins;
	 NoEncryptSetVar[6] = (BUZZ_NORMAL_WORK > 0) /*| ((language > 0) << 1)*/;
	 NoEncryptSetVar[7] = backlight_level;
 }
 
 void InitNoEncryptSetVar()
 {
	 NoEncryptSetVar[0] = 0;
	 UpdateNoEncryptSetVar();
 }

void SaveTime()
{
    rtc.hours =  timedata[0];
    rtc.mins  =  timedata[1];
    rtc.year  =  timedata[2];
    rtc.month =  timedata[3];
    rtc.day   =  timedata[4];
    rtc.secs  =  timedata[5];
    set_date();
}

 
#if(ChangeTimeEnable == ON)
 u8 ChangeTime(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 state = 0;
	 rtc_t rtcx;
	 u8 color;
	 u8 i;
	 static u16 data[6];
	 u32 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
		 for(i = 0; i < 5; i++)
		 {
			 data[i] = timedata[i];
		 }
 
		 sendflag = 1;
		 index = 0;
		 state = 0;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP:
			 data[index] ++;
			 switch(index)
			 {
				 case 0:
					 data[0] = data[0] > 23 ? 0 : data[0];
					 break;
				 case 1:
					 data[1] = data[1] > 59 ? 0 : data[1];
					 break;
				 case 2:
					 data[2] = data[2] > 99 ? 0 : data[2];
					 break;
				 case 3:
					 data[3] = data[3] > 12 ? 1 : data[3];
					 break;
				 case 4:
					 data[4] = (data[4] > (((data[3] == 2) && is_leap_year()) ? 29 : days_in_mo[data[3]])) ? 1 : data[4];
					 break;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY3_SP:
			 switch(index)
			 {
				 case 0:
					 data[0] =	data[0] <= 0 ? 24 : data[0];;
					 break;
				 case 1:
					 data[1] =	data[1] <= 0 ? 60 : data[1];
					 break;
				 case 2:
					 data[2] = data[2] <= 0 ? 100 : data[2];
					 break;
				 case 3:
					 data[3] =	data[3] <= 1 ? 13 : data[3];
					 break;
				 case 4:
					 data[4] = data[4] <= 1 ? ((((data[3] == 2) && is_leap_year()) ? 28 : days_in_mo[data[3]]) + 1) : data[4];
					 break;
			 }
			 data[index] --;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP:
			 index ++;
			 if(index > 4)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
 
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
 
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
 
	 }
	 if((sendflag == 1))
	 {
		 for(i = 0; i < 5; i++)
		 {
			 timedata[i] = data[i];
		 }
		 NoEncryptSetVar[0] = index + ChTimeStart;
		 NoEncryptSetVar[1] = data[2];
		 NoEncryptSetVar[2] = data[3];
		 NoEncryptSetVar[3] = data[4];
		 NoEncryptSetVar[4] = data[0];
		 NoEncryptSetVar[5] = data[1];
		 NoEncryptSetToGPU();
		 sendflag = 0;
	 }
 
	 return 0;
 
 }
#endif
#if(ChangeBLEnable == ON)
 static u8 ChangeBackLight(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP:
			 backlight_level ++;
			 backlight_level = backlight_level >= 9 ? 0 : backlight_level;
			 sendflag = 1;
			 break;
		 case IN_KEY3_SP:
			 backlight_level = backlight_level <= 0 ? 9 : backlight_level;
			 backlight_level --;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP:
			 index ++;
			 if(index > 0)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 NoEncryptSetVar[0] = index + ChBLStart;
		 NoEncryptSetVar[7] = backlight_level;
		 NoEncryptSetToGPU();
 
		 sendflag = 0;
	 }
 
	 return 0;
 }
#endif
 
 
#define BUZZ_BYTE() ((BUZZ_NORMAL_WORK > 0))
 
 
#if(ChangeBuzzEnable == ON)
 static u8 ChangeBuzz(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP:
		 case IN_KEY3_SP:
			 BUZZ_NORMAL_WORK ^= 1;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP:
			 index ++;
			 if(index > 0)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 NoEncryptSetVar[0] = index + ChBuzzStart;
		 NoEncryptSetVar[6] = BUZZ_BYTE();
		 NoEncryptSetToGPU();
		 sendflag = 0;
	 }
 
	 return 0;
 }
#endif
 


 
 enum
 {
#if(ChangeTimeEnable == ON)
	 TimeIndex,
#endif
#if(ChangeBLEnable == ON)
	 BLIndex,
#endif
#if(ChangeBuzzEnable == ON)
	 BuzzIndex,
#endif
	 NoEncryptSystemSetLast
 };
 
 void ReInitSystemPage()
 {
	 timedata[0] = rtc.hours;
	 timedata[1] = rtc.mins;
	 timedata[2] = rtc.year;
	 timedata[3] = rtc.month;
	 timedata[4] = rtc.day;
	 timedata[5] = rtc.secs;
	 Set_backlight_level = backlight_level;
	 set_buzz = BUZZ_NORMAL_WORK;
	// set_language = language;
 }

 void SaveChangeNoEncrypt()
 {
	 if((Set_backlight_level != backlight_level) || (set_buzz != BUZZ_NORMAL_WORK))
	 {
 
		 Set_backlight_level = backlight_level;
		 set_buzz = BUZZ_NORMAL_WORK;
        // SaveMeterPara();
        EEPARAFLAG = 1;
		 //背光打开
		 SetBackGround(backlight_level);
 
	 }
 }


 u32 NoEncryptSystemSet(u8 key, u8 initpw)	//不保密设定
 {
	 static u32 flag = 0;
	 static u8 initflag = 0;
	 static u8 LastNoEncryptSystemSetPage = NoEncryptSystemSetLast;
	 static u8 reinitflag = 0;
 
	 if(initpw)
	 {
		 //display_time_bar_soc(1); //补发一下时间同步修改显示
		 // 	 ClearBufferDisable = 1;
		 // 	   ChangeToSetPage(NoEncryptSetPage);
		 // 	   ClearBufferDisable = 0;
		 SendKeyToGPU(CMD_DIS_PAGE);
		 ReInitSystemPage();
		 

		 NoEncryptSetVar[6] = BUZZ_BYTE();
		 LastNoEncryptSystemSetPage = flag;
		 flag = 0;
		 reinitflag = 1;
	 }
 
	 if((LastNoEncryptSystemSetPage == flag) && reinitflag)
	 {
		 initflag = 1;
		 reinitflag = 0;
	 }
 
	 switch(flag)
	 {
#if(ChangeTimeEnable == ON)
		 case TimeIndex:
			 flag += ChangeTime(key, initflag);
			 initflag = 0;
			 break;
#endif
#if(ChangeBLEnable == ON)
		 case BLIndex:
			 flag += ChangeBackLight(key, initflag);
			 initflag = 0;
			 break;
#endif
#if(ChangeBuzzEnable == ON)
		 case BuzzIndex:
			 flag += ChangeBuzz(key, initflag);
			 initflag = 0;
			 break;
#endif
 

 
	 }
 
	 flag = (flag >= NoEncryptSystemSetLast ? 0 : flag);
 
	 if(key == IN_KEY4_SP)
	 {
		 SaveTime();
		 SaveChangeNoEncrypt();

		 
		 return DIS_CHOOSE_MENU;
	 }
 
	 return DIS_FACTORY_SET_MENU;
 }


static BYTE_4Bit_Union ESSetData[24];

#ifndef ChangeLiChengEnable
    #define ChangeLiChengEnable ON
#endif

#ifndef ChangeSubiEnable
    #define ChangeSubiEnable ON
#endif

#ifndef ChangePulseEnable
    #define ChangePulseEnable ON
#endif

#ifndef ChangeCoefEnable
    #define ChangeCoefEnable     ON
#endif

#ifndef ChangeAirCoefEnable
    #define ChangeAirCoefEnable     ON
#endif


#ifndef ChangeSpeedAlarmEnable
    #define ChangeSpeedAlarmEnable     ON
#endif

#ifndef ChangeAirAlarmEnable
    #define ChangeAirAlarmEnable     ON
#endif


#ifndef ChangeTimeEnable
    #define ChangeTimeEnable ON
#endif

#ifndef ChangeBLEnable
    #define ChangeBLEnable ON
#endif

#ifndef ChangeBuzzEnable
    #define ChangeBuzzEnable ON
#endif


#ifndef ChangeFuelCoefEnable
    #define ChangeFuelCoefEnable ON
#endif



#define ChLiChengStart      0
#define ChLiChengLen        (ChangeLiChengEnable*7)

#define ChSubiStart         (ChLiChengStart + ChLiChengLen)
#define ChSubiLen           (ChangeSubiEnable*4)

#define ChPulseStart        (ChSubiStart + ChSubiLen)
#define ChPulseLen          (ChangePulseEnable*4)

#define ChCoefStart         (ChPulseStart+ChPulseLen)
#define ChCoefLen           (ChangeCoefEnable*3)

#define ChAirCoefStart      (ChCoefStart+ChCoefLen)  //1 气压比例系数
#define ChAirCoefLen        (ChangeAirCoefEnable*3)

#define ChHSValueStart      (ChAirCoefStart+ChAirCoefLen)
#define ChHSValueLen        (ChangeSpeedAlarmEnable*3)


#define ChAirAlarmStart    (ChHSValueStart+ChHSValueLen)//3 气压报警值
#define ChAirAlarmLen      (ChangeAirAlarmEnable*3)

#define ChOilAlarmStart    (ChAirAlarmStart+ChAirAlarmLen)//3 机油压力报警系数
#define ChOilAlarmLen      (ChangeOilAlarmEnable*3)

#define ChFuelCoefStart     (ChOilAlarmStart+ChOilAlarmLen)//3 
#define ChFuelCoefLen       (ChangeFuelCoefEnable*3)

#define ChRanYouStart       (ChFuelCoefStart+ChFuelCoefLen)//3 燃油报警值
#define ChRanYouLen         (ChangeRanyouEnable*3)

#define ChVideoAv1Start     (ChRanYouStart+ChRanYouLen)//3 视频1
#define ChVideoAv1Len       (ChangeVideoAv1Enable)

#define ChVideoAv2Start     (ChVideoAv1Start+ChVideoAv1Len)//3 视频2
#define ChVideoAv2Len       (ChangeVideoAv2Enable)

#define ChVideoAv3Start     (ChVideoAv2Start+ChVideoAv2Len)//3 视频2
#define ChVideoAv3Len       (ChangeVideoAv3Enable)

#define ChVideoAv4Start     (ChVideoAv3Start+ChVideoAv3Len)//3 视频2
#define ChVideoAv4Len       (ChangeVideoAv4Enable)


void SendESSetDataToGPU()
{
    u8 i;
    Send_To_DP_Data[0] = 4;
    Send_To_DP_Data[1] = 3;
    Send_To_DP_Data[2] = 1;

    for(i = 0; i < 8; i++)
    {
        Send_To_DP_Data[i + 3] = ESSetData[i].byte;
    }

    SendToDP();

    Send_To_DP_Data[0] = 4;
    Send_To_DP_Data[1] = 3;
    Send_To_DP_Data[2] = 2;

    for(i = 0; i < 8; i++)
    {
        Send_To_DP_Data[i + 3] = ESSetData[i + 8].byte;
    }

    SendToDP();

    Send_To_DP_Data[0] = 4;
    Send_To_DP_Data[1] = 3;
    Send_To_DP_Data[2] = 3;

    for(i = 0; i < 8; i++)
    {
        Send_To_DP_Data[i + 3] = ESSetData[i + 16].byte;
    }

    SendToDP();
}


 
#if (ChangeLiChengEnable == ON)
 static u8 ChangeLicheng(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
 
		 u32tostr(Set_Veh_odo, setbcd, 1, 7);
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP:
			 setbcd[index] ++;
			 setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
			 sendflag = 1;
			 break;
		 case IN_KEY3_SP:
			 setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
			 setbcd[index] --;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP:
			 index ++;
			 if(index > 6)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
 
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
 
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 Set_Veh_odo = 0;
		 for(i = 0; i < 7; i++)
		 {
			 Set_Veh_odo*= 10;
			 Set_Veh_odo += setbcd[i];
			 ESSetData[i + 1].byte = setbcd[i];
		 }
		 ESSetData[0].byte = index + ChLiChengStart;
 
		 SendESSetDataToGPU();
		 sendflag = 0;
	 }
 
	 return 0;
 }
 
 
 
#endif
#if(ChangeSubiEnable == ON)
 static u8 ChangeSubi(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
 
		 u32tostr(Set_odometer_const, setbcd, 1, 4);
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP:
			 setbcd[index] ++;
			 setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
			 sendflag = 1;
			 break;
		 case IN_KEY3_SP:
			 setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
			 setbcd[index] --;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP:
			 index ++;
			 if(index > 3)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 Set_odometer_const = 0;
		 for(i = 0; i < 4; i++)
		 {
			 Set_odometer_const *= 10;
			 Set_odometer_const += setbcd[i];
		 }
 
		 ESSetData[0].byte = index + ChSubiStart;
		 ESSetData[8].bit.bs0 = setbcd[0];
		 ESSetData[8].bit.bs1 = setbcd[1];
		 ESSetData[9].bit.bs0 = setbcd[2];
		 ESSetData[9].bit.bs1 = setbcd[3];
 
		 SendESSetDataToGPU();
 
		 sendflag = 0;
	 }
 
	 return 0;
 }
#endif
#if(ChangePulseEnable == ON)
 static u8 ChangePulse(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
 
		 u32tostr(Set_Pulse, setbcd, 1, 4);
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP:
			 setbcd[index] ++;
			 setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
			 sendflag = 1;
			 break;
		 case IN_KEY3_SP:
			 setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
			 setbcd[index] --;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP:
			 index ++;
			 if(index > 3)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 Set_Pulse = 0;
		 for(i = 0; i < 4; i++)
		 {
			 Set_Pulse *= 10;
			 Set_Pulse += setbcd[i];
		 }
 
		 ESSetData[0].byte = index + ChPulseStart;
		 ESSetData[10].bit.bs0 = setbcd[0];
		 ESSetData[10].bit.bs1 = setbcd[1];
		 ESSetData[11].bit.bs0 = setbcd[2];
		 ESSetData[11].bit.bs1 = setbcd[3];
 
		 SendESSetDataToGPU();
 
		 sendflag = 0;
	 }
 
	 return 0;
 }
#endif
 
#if(ChangeCoefEnable == ON)
 static u8 ChangeCoef(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
 
		 u32tostr(Set_Coef, setbcd, 1, 3);
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP: //up
			 setbcd[index] ++;
			 setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
			 sendflag = 1;
			 break;
		 case IN_KEY3_SP://down
			 setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
			 setbcd[index] --;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP://funtion
			 index ++;
			 if(index > 2)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 Set_Coef = 0;
		 for(i = 0; i < 3; i++)
		 {
			 Set_Coef *= 10;
			 Set_Coef += setbcd[i];
		 }
 
		 ESSetData[0].byte = index + ChCoefStart;
		 ESSetData[12].bit.bs0 = setbcd[0];
		 ESSetData[12].bit.bs1 = setbcd[1];
		 ESSetData[13].bit.bs0 = setbcd[2];
 
		 SendESSetDataToGPU();
 
 
		 sendflag = 0;
	 }
	 return 0;
 }
 
#endif
 
#if(ChangeAirCoefEnable == ON)
 static u8 ChangeAirCoef(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
 
		 u32tostr(Set_Air_Coef, setbcd, 1, 3);
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP: //up
			 setbcd[index] ++;
			 setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
			 sendflag = 1;
			 break;
		 case IN_KEY3_SP://down
			 setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
			 setbcd[index] --;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP://funtion
			 index ++;
			 if(index > 2)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 Set_Air_Coef = 0;
		 for(i = 0; i < 3; i++)
		 {
			 Set_Air_Coef *= 10;
			 Set_Air_Coef += setbcd[i];
		 }
 
 
		 ESSetData[0].byte = index + ChAirCoefStart;
		 ESSetData[13].bit.bs1 = setbcd[0];
		 ESSetData[14].bit.bs0 = setbcd[1];
		 ESSetData[14].bit.bs1 = setbcd[2];
 
		 SendESSetDataToGPU();
 
		 sendflag = 0;
	 }
	 return 0;
 }
 
#endif
 
 
#if(ChangeSpeedAlarmEnable == ON)
 static u8 ChangeHSValue(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
		 u32tostr(Set_Speed_Alarm, setbcd, 1, 3);
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP: //up
			 setbcd[index] ++;
			 setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
			 sendflag = 1;
			 break;
		 case IN_KEY3_SP://down
			 setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
			 setbcd[index] --;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP://funtion
			 index ++;
			 if(index > 2)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 Set_Speed_Alarm = 0;
		 for(i = 0; i < 3; i++)
		 {
			 Set_Speed_Alarm *= 10;
			 Set_Speed_Alarm += setbcd[i];
		 }
 
		 ESSetData[0].byte = index + ChHSValueStart;
		 ESSetData[15].bit.bs0 = setbcd[0];
		 ESSetData[15].bit.bs1 = setbcd[1];
		 ESSetData[16].bit.bs0 = setbcd[2];
 
		 SendESSetDataToGPU();
 
		 sendflag = 0;
	 }
	 return 0;
 }
 
#endif
 
 
#if(ChangeAirAlarmEnable == ON)
 static u8 ChangeAirAlarm(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
 
		 u32tostr(Set_Air_Alarm, setbcd, 1, 3);
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP: //up
			 setbcd[index] ++;
			 setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
			 sendflag = 1;
			 break;
		 case IN_KEY3_SP://down
			 setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
			 setbcd[index] --;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP://funtion
			 index ++;
			 if(index > 2)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 Set_Air_Alarm = 0;
		 for(i = 0; i < 3; i++)
		 {
			 Set_Air_Alarm *= 10;
			 Set_Air_Alarm += setbcd[i];
		 }
 
		 ESSetData[0].byte = index + ChAirAlarmStart;
		 ESSetData[16].bit.bs1 = setbcd[0];
		 ESSetData[17].bit.bs0 = setbcd[1];
		 ESSetData[17].bit.bs1 = setbcd[2];
 
		 SendESSetDataToGPU();
 
 
		 sendflag = 0;
	 }
	 return 0;
 }
 
#endif
 
 
#if(ChangeOilAlarmEnable == ON)
 static u8 ChangeOilAlarm(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
 
		 u32tostr(Set_Oil_Alarm, setbcd, 1, 3);
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP: //up
			 setbcd[index] ++;
			 setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
			 sendflag = 1;
			 break;
		 case IN_KEY3_SP://down
			 setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
			 setbcd[index] --;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP://funtion
			 index ++;
			 if(index > 2)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 Set_Oil_Alarm= 0;
		 for(i = 0; i < 3; i++)
		 {
			 Set_Oil_Alarm *= 10;
			 Set_Oil_Alarm += setbcd[i];
		 }
		 ESSetData[0].byte = index + ChOilAlarmStart;
		 ESSetData[18].bit.bs0 = setbcd[0];
		 ESSetData[18].bit.bs1 = setbcd[1];
		 ESSetData[19].bit.bs0 = setbcd[2];
 
		 SendESSetDataToGPU();
 
		 sendflag = 0;
	 }
	 return 0;
 }
 
#endif
 
#if(ChangeFuelCoefEnable == ON)//油量系数
 static u8 ChangeFuelCoef(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
 
		 u32tostr(Set_Fuel_Coef, setbcd, 1, 3);
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP: //up
			 setbcd[index] ++;
			 setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
			 sendflag = 1;
			 break;
		 case IN_KEY3_SP://down
			 setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
			 setbcd[index] --;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP://funtion
			 index ++;
			 if(index >= ChFuelCoefLen)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 Set_Fuel_Coef = 0;
		 for(i = 0; i < 3; i++)
		 {
			 Set_Fuel_Coef *= 10;
			 Set_Fuel_Coef += setbcd[i];
		 }
		 ESSetData[0].byte = index + ChFuelCoefStart;
		 ESSetData[21].bit.bs0 = setbcd[0];
		 ESSetData[21].bit.bs1 = setbcd[1];
		 ESSetData[22].bit.bs0 = setbcd[2];
 
		 SendESSetDataToGPU();
		 sendflag = 0;
	 }
	 return 0;
 }
 
#endif
 
 
#if(ChangeRanyouEnable == ON)   //油量报警
 static u8 ChangeRanYou(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
 
		 u32tostr(Set_Ranyou_Alarm, setbcd, 1, 3);
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP: //up
			 setbcd[index] ++;
			 setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
			 sendflag = 1;
			 break;
		 case IN_KEY3_SP://down
			 setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
			 setbcd[index] --;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP://funtion
			 index ++;
			 if(index > 2)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 Set_Ranyou_Alarm = 0;
		 for(i = 0; i < 3; i++)
		 {
			 Set_Ranyou_Alarm *= 10;
			 Set_Ranyou_Alarm += setbcd[i];
		 }
 
		 ESSetData[0].byte = index + ChRanYouStart;
		 ESSetData[19].bit.bs1 = setbcd[0];
		 ESSetData[20].bit.bs0 = setbcd[1];
		 ESSetData[20].bit.bs1 = setbcd[2];
		 SendESSetDataToGPU();
		 sendflag = 0;
 
	 }
	 return 0;
 }
 
#endif
 
#if(ChangeVideoAv1Enable == ON)
 static u8 ChangeVideoAv1(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP:
		 case IN_KEY3_SP:
			 SET_VIDEO_AV1 ^= 1;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP:
			 index ++;
			 if(index > 0)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 ESSetData[0].byte = index + ChVideoAv1Start;
		 ESSetData[22].byte &= (~(1 << 4));
		 ESSetData[22].byte |= SET_VIDEO_AV1 << 4;
		 SendESSetDataToGPU();
		 sendflag = 0;
	 }
 
	 return 0;
 }
#endif
 
#if(ChangeVideoAv2Enable == ON)
 static u8 ChangeVideoAv2(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP:
		 case IN_KEY3_SP:
			 SET_VIDEO_AV2 ^= 1;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP:
			 index ++;
			 if(index > 0)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 ESSetData[0].byte = index + ChVideoAv2Start;
		 ESSetData[22].byte &= (~(1 << 5));
		 ESSetData[22].byte |= SET_VIDEO_AV2 << 5;
		 SendESSetDataToGPU();
		 sendflag = 0;
	 }
 
	 return 0;
 }
#endif
 
#if(ChangeVideoAv3Enable == ON)
 static u8 ChangeVideoAv3(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP:
		 case IN_KEY3_SP:
			 SET_VIDEO_AV3 ^= 1;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP:
			 index ++;
			 if(index > 0)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 ESSetData[0].byte = index + ChVideoAv3Start;
		 ESSetData[22].byte &= (~(1 << 6));
		 ESSetData[22].byte |= SET_VIDEO_AV3 << 6;
		 SendESSetDataToGPU();
		 sendflag = 0;
	 }
 
	 return 0;
 }
#endif
#if(ChangeVideoAv4Enable == ON)
 static u8 ChangeVideoAv4(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP:
		 case IN_KEY3_SP:
			 SET_VIDEO_AV4 ^= 1;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP:
			 index ++;
			 if(index > 0)
			 {
				 index = 0;
				 initflag = 1;
				 return 1;
			 }
			 sendflag = 1;
			 break;
		 case IN_KEY1_CP:
			 index = 0;
			 initflag = 1;
			 return 1;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
			 }
			 return 0;
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 ESSetData[0].byte = index + ChVideoAv4Start;
		 ESSetData[22].byte &= (~(1 << 7));
		 ESSetData[22].byte |= SET_VIDEO_AV4 << 7;
		 SendESSetDataToGPU();
		 sendflag = 0;
	 }
 
	 return 0;
 }
#endif
 
 
 
 
 static s16 CheckPassword(u8 key, u8 initpw)
 {
	 static u8 index = 0;
	 static u8 initflag = 1;
	 static u8 setbcd[10] = {0};
	 u8 i;
 
	 u8 sendflag = 0;
 
	 if(initpw)
	 {
		 initflag = 1;
	 }
 
	 if(initflag)
	 {
		 initflag = 0;
		 set_password = 0;
		 u32tostr(set_password, setbcd, 1, 4);
		 index = 0;
		 sendflag = 1;
	 }
 
	 switch(key)
	 {
		 case IN_KEY2_SP:
			 setbcd[index] ++;
			 setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
			 sendflag = 1;
			 break;
		 case IN_KEY3_SP:
			 setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];
			 setbcd[index] --;
			 sendflag = 1;
			 break;
		 case IN_KEY1_SP:
			 index ++;
			 index = (index > 3 ? 0 : index);
			 sendflag = 1;
			 break;
		 case IN_KEY4_SP:
			 {
				 initflag = 1;
 
				 for(i = 1; i < 12; i++)
				 {
					 Send_To_DP_Data[i] = 0;
				 }
 
				 Send_To_DP_Data[0] = 4;
				 Send_To_DP_Data[1] = 1;
				 Send_To_DP_Data[2] = 1;
				 Send_To_DP_Data[3] = 0;
				 Send_To_DP_Data[4] = 0;
				 Send_To_DP_Data[5] = 0;
				 Send_To_DP_Data[6] = 0;
				 Send_To_DP_Data[7] = 0;
 
				 SendToDP();
 
				 if(set_password == password)
				 {
					 return 1;
				 }
				 else
				 {
					 return -1;
				 }
			 }
		 default:
			 break;
	 }
 
	 if(sendflag == 1)
	 {
		 set_password = 0;
		 for(i = 0; i < 4; i++)
		 {
			 set_password *= 10;
			 set_password += setbcd[i];
		 }
 
		 for(i = 1; i < 12; i++)
		 {
			 Send_To_DP_Data[i] = 0;
		 }
 
		 Send_To_DP_Data[0] = 4;
		 Send_To_DP_Data[1] = 1;
		 Send_To_DP_Data[2] = 1;
		 Send_To_DP_Data[3] = index;
		 Send_To_DP_Data[4] = setbcd[0];
		 Send_To_DP_Data[5] = setbcd[1];
		 Send_To_DP_Data[6] = setbcd[2];
		 Send_To_DP_Data[7] = setbcd[3];
 
		 SendToDP();
		 sendflag = 0;
	 }
 
	 return 0;
 }
 
 enum
 {
#if(ChangeLiChengEnable== ON)
	 LiChengIndex,
#endif
#if(ChangeSubiEnable == ON)
	 SubiIndex,
#endif
#if(ChangePulseEnable == ON)
	 PulseIndex,
#endif
#if(ChangeCoefEnable == ON)
	 CoefIndex,
#endif
#if(ChangeAirCoefEnable == ON)
	 AirCoefIndex,
#endif
#if(ChangeSpeedAlarmEnable == ON)
	 HSValueIndex,
#endif
#if(ChangeAirAlarmEnable == ON)
	 AirAlarmIndex,
#endif
#if(ChangeOilAlarmEnable == ON)
	 OilAlarmIndex,
#endif
#if(ChangeFuelCoefEnable == ON)
	 FuelCoefIndex,
#endif
 
#if(ChangeRanyouEnable == ON)
	 RanYouIndex,
#endif
 
#if(ChangeVideoAv1Enable == ON)
	 VideoAv1Index,
#endif
#if(ChangeVideoAv2Enable == ON)
	 VideoAv2Index,
#endif
#if(ChangeVideoAv3Enable == ON)
	 VideoAv3Index,
#endif
#if(ChangeVideoAv4Enable == ON)
	 VideoAv4Index,
#endif
 
	 EncryptSystemSetLast
 };

 
 
 
 void SaveChangeEncrypt()
 {
	 uint32_t address = 0x800000;
	 u8 i = 0, k;
	 if((Set_odometer_const != odometer_const) || (Veh_odo != Set_Veh_odo) || (Set_Pulse != Pulse) || (Set_Coef != Coef) || \
		(Set_Air2_Coef != Air2_Coef)||	 (Set_Air_Coef != Air_Coef) || (Set_Fuel_Coef != Fuel_Coef) || (Set_Speed_Alarm != Speed_Alarm) || (Set_Air_Alarm != Air_Alarm) || \
			 (Set_Oil_Alarm != Oil_Alarm) || (Set_Ranyou_Alarm != Ranyou_Alarm) || (SET_VIDEO_AV1 != VIDEO_AV_GRAR) || \
			 (SET_VIDEO_AV2 != VIDEO_AV_MID) || (SET_VIDEO_AV3 != VIDEO_AV_FRO) || (SET_VIDEO_AV4 != VIDEO_AV_ELSE))
	 {
	     if(Veh_odo != Set_Veh_odo)
	     {
            Veh_odo = Set_Veh_odo;
			//SaveVehodo();
			EEODOFLAG = 1;
		 }

	
		 odometer_const = Set_odometer_const;
		 Pulse = Set_Pulse;
		 Coef = Set_Coef;
		 Speed_Alarm = Set_Speed_Alarm;
		 Air_Coef = Set_Air_Coef;
		 Air2_Coef = Set_Air2_Coef;
		 Air_Alarm = Set_Air_Alarm;
		 Oil_Alarm = Set_Oil_Alarm;
		 Fuel_Coef = Set_Fuel_Coef;
		 Ranyou_Alarm = Set_Ranyou_Alarm;
		 VIDEO_AV_GRAR = SET_VIDEO_AV1;
		 VIDEO_AV_FRO  = SET_VIDEO_AV2;
		 VIDEO_AV_MID  = SET_VIDEO_AV3;
		 VIDEO_AV_ELSE = SET_VIDEO_AV4;

					 
		 //SaveMeterPara();
		 EEPARAFLAG = 1;
	 }
 
 
 }

 
 void display_total_miles(u8 initw);
 u32 EncryptSystemSet(u8 key, u8 initpw)  //保密设定
 {
	 static u32 flag = 0;
	 static u32 flag1 = 0;
 
	 static u8 initflag = 0;
	 static u8 LastEncryptSystemSetPage = EncryptSystemSetLast;
	 static u8 reinitflag = 0;
 
 
	 if(initpw)
	 {
		 SendKeyToGPU(CMD_DIS_PAGE);
		 flag = 0;
 
		 LastEncryptSystemSetPage = flag1;
		 flag1 = 0;
		 reinitflag = 1;
	 }
 
	 if((LastEncryptSystemSetPage == flag1) && reinitflag)
	 {
		 initflag = 1;
		 reinitflag = 0;
	 }
 
	 switch(flag)
	 {
		 case 0:
			 {
				 int32_t f = CheckPassword(key, initpw);
				 if(f == 1)
				 {
					 u8 setbcd[8];
					 flag = 1;
					 //display_total_miles(1); //刷新下总里程显示
					 Set_Veh_odo = Veh_odo;
					 Set_odometer_const = odometer_const;
					 Set_Pulse = Pulse;
					 Set_Coef = Coef;
					 Set_Speed_Alarm = Speed_Alarm;
					 Set_Air_Coef = Air_Coef;
					 //Set_Air2_Coef = Air2_Coef;
					 Set_Air_Alarm = Air_Alarm;
					 Set_Oil_Alarm = Oil_Alarm;
					 Set_Fuel_Coef = Fuel_Coef;
					 Set_Ranyou_Alarm = Ranyou_Alarm;
					 SET_VIDEO_AV1 = VIDEO_AV_GRAR;
					 SET_VIDEO_AV2 = VIDEO_AV_FRO;
					 SET_VIDEO_AV3 = VIDEO_AV_MID;
					 SET_VIDEO_AV4 = VIDEO_AV_ELSE;
 
 
					 ESSetData[0].byte = 0;
					 u32tostr(Set_Veh_odo, setbcd, 1, 7);
					 ESSetData[1].byte = setbcd[0];
					 ESSetData[2].byte = setbcd[1];
					 ESSetData[3].byte = setbcd[2];
					 ESSetData[4].byte = setbcd[3];
					 ESSetData[5].byte = setbcd[4];
					 ESSetData[6].byte = setbcd[5];
					 ESSetData[7].byte = setbcd[6];
 
					 u32tostr(Set_odometer_const, setbcd, 1, 4);
					 ESSetData[8].bit.bs0 = setbcd[0];
					 ESSetData[8].bit.bs1 = setbcd[1];
					 ESSetData[9].bit.bs0 = setbcd[2];
					 ESSetData[9].bit.bs1 = setbcd[3];
 
					 u32tostr(Set_Pulse, setbcd, 1, 4);
					 ESSetData[10].bit.bs0 = setbcd[0];
					 ESSetData[10].bit.bs1 = setbcd[1];
					 ESSetData[11].bit.bs0 = setbcd[2];
					 ESSetData[11].bit.bs1 = setbcd[3];
 
					 u32tostr(Set_Coef, setbcd, 1, 3);
					 ESSetData[12].bit.bs0 = setbcd[0];
					 ESSetData[12].bit.bs1 = setbcd[1];
					 ESSetData[13].bit.bs0 = setbcd[2];
 
					 u32tostr(Set_Air_Coef, setbcd, 1, 3);
					 ESSetData[13].bit.bs1 = setbcd[0];
					 ESSetData[14].bit.bs0 = setbcd[1];
					 ESSetData[14].bit.bs1 = setbcd[2];
 
					 u32tostr(Set_Speed_Alarm, setbcd, 1, 3);
					 ESSetData[15].bit.bs0 = setbcd[0];
					 ESSetData[15].bit.bs1 = setbcd[1];
					 ESSetData[16].bit.bs0 = setbcd[2];
 
					 u32tostr(Set_Air_Alarm, setbcd, 1, 3);
					 ESSetData[16].bit.bs1 = setbcd[0];
					 ESSetData[17].bit.bs0 = setbcd[1];
					 ESSetData[17].bit.bs1 = setbcd[2];
 
					 u32tostr(Set_Oil_Alarm, setbcd, 1, 3);
					 ESSetData[18].bit.bs0 = setbcd[0];
					 ESSetData[18].bit.bs1 = setbcd[1];
					 ESSetData[19].bit.bs0 = setbcd[2];
 
					 u32tostr(Set_Ranyou_Alarm, setbcd, 1, 3);
					 ESSetData[19].bit.bs1 = setbcd[0];
					 ESSetData[20].bit.bs0 = setbcd[1];
					 ESSetData[20].bit.bs1 = setbcd[2];
 
					 u32tostr(Set_Fuel_Coef, setbcd, 1, 3);
					 ESSetData[21].bit.bs0 = setbcd[0];
					 ESSetData[21].bit.bs1 = setbcd[1];
					 ESSetData[22].bit.bs0 = setbcd[2];
 
					 ESSetData[22].byte |= (u8)SET_VIDEO_AV1 << 4;
					 ESSetData[22].byte |= (u8)SET_VIDEO_AV2 << 5;
					 ESSetData[22].byte |= (u8)SET_VIDEO_AV3 << 6;
					 ESSetData[22].byte |= (u8)SET_VIDEO_AV4 << 7;
 
 
					 SendESSetDataToGPU();
					 ChangeToSubPage(DIS_SYSTEM_SET_MENU, PAGE_ARTSET_MILESET);
				 }
				 else if(f == -1)
				 {
					 ChangeToSubPage(DIS_SYSTEM_SET_MENU, PAGE_ARTSET_PASSWORD);
					 return DIS_CHOOSE_MENU;
				 }
			 }
			 break;
		 case 1:
			 switch(flag1)
			 {
#if(ChangeLiChengEnable == ON)
				 case LiChengIndex:
					 flag1 += ChangeLicheng(key, initflag);
					 initflag = 0;
					 break;
#endif
#if(ChangeSubiEnable == ON)
				 case SubiIndex:
					 flag1 += ChangeSubi(key, initflag);
					 initflag = 0;
					 break;
#endif
#if(ChangePulseEnable == ON)
				 case PulseIndex:
					 flag1 += ChangePulse(key, initflag);
					 initflag = 0;
					 break;
#endif
#if(ChangeCoefEnable == ON)
				 case CoefIndex:
					 flag1 += ChangeCoef(key, initflag);
					 initflag = 0;
					 break;
#endif
 
#if(ChangeAirCoefEnable == ON)
				 case AirCoefIndex:
					 flag1 += ChangeAirCoef(key, initflag);
					 initflag = 0;
					 break;
#endif
 
#if(ChangeSpeedAlarmEnable == ON)
				 case HSValueIndex:
					 flag1 += ChangeHSValue(key, initflag);
					 initflag = 0;
					 break;
#endif
#if(ChangeAirAlarmEnable == ON)
				 case AirAlarmIndex:
					 flag1 += ChangeAirAlarm(key, initflag);
					 initflag = 0;
					 break;
#endif
#if(ChangeOilAlarmEnable == ON)
				 case OilAlarmIndex:
					 flag1 += ChangeOilAlarm(key, initflag);
					 initflag = 0;
					 break;
#endif
#if(ChangeFuelCoefEnable == ON)
				 case FuelCoefIndex:
					 flag1 += ChangeFuelCoef(key, initflag);
					 initflag = 0;
					 break;
#endif
#if(ChangeRanyouEnable == ON)
				 case RanYouIndex:
					 flag1 += ChangeRanYou(key, initflag);
					 initflag = 0;
					 break;
#endif
#if(ChangeVideoAv1Enable == ON)
				 case VideoAv1Index:
					 flag1 += ChangeVideoAv1(key, initflag);
					 initflag = 0;
					 break;
#endif
#if(ChangeVideoAv2Enable == ON)
				 case VideoAv2Index:
					 flag1 += ChangeVideoAv2(key, initflag);
					 initflag = 0;
					 break;
#endif
#if(ChangeVideoAv3Enable == ON)
				 case VideoAv3Index:
					 flag1 += ChangeVideoAv3(key, initflag);
					 initflag = 0;
					 break;
#endif
#if(ChangeVideoAv4Enable == ON)
				 case VideoAv4Index:
					 flag1 += ChangeVideoAv4(key, initflag);
					 initflag = 0;
					 break;
#endif
 
			 }
 
			 flag1 = (flag1 >= EncryptSystemSetLast ? 0 : flag1);
			 if(key == IN_KEY4_SP)
			 {
				 SaveChangeEncrypt();
				 ChangeToSubPage(DIS_SYSTEM_SET_MENU, PAGE_ARTSET_PASSWORD);
				 flag = 0;
				 return DIS_CHOOSE_MENU;
			 }
			 break;
 
	 }
 
	 return DIS_SYSTEM_SET_MENU;
 }



 
 static inline u8 getVideo()
 {
	 if(TV1_REVERSE_SW)
	 {
		 return 1;
	 }
	 if(TV2_REAR_DOOR_SW)
	 {
		 return 2;
	 }
	 if(TV3_FRONT_DOOR_SW)
	 {
		 return 3;
	 }
	 if(TV4_MIDDLE_DOOR_SW)
	 {
		 return 4;
	 }
	 return 0;
 }
 
 u8 VedioCheck(u8 key)
 {
	 static u8 video_status = 0;
	 static u8 video = 0;
	 static u8 video_bak = 0xFF;
 
	 if(KEY_ON == 0)
	 {
		 if(video > 0)
		 {
			 video_bak = 0xFF;
			 video = 0;
			 goto ChangVideo;
		 }
		 else
		 {
			 return key;
		 }
	 }
 
	 video_status = getVideo();
	 if(video_status !=  video_bak)
	 {
		 video_bak = video_status;
		 video = video_status;
		 goto ChangVideo;
	 }
 
	 if(key == IN_KEY4_CP)
	 {
		 if(video < 4)
		 {
			 video ++;
		 }
		 else
		 {
			 video = 0;
		 }
		 goto ChangVideo;
	 }
 
	 if(video > 0)
	 {
		 return IN_KEY_NONE;
	 }
	 else
	 {
		 return key;
	 }
 
 ChangVideo:
 
	 video = video > 4 ? 4 : video;
	 ChangeToSubPage(DIS_VEDIO, video);
	 return IN_KEY_NONE;
 }




 void ReInitDisplay(void)
 {
	 u8 i;
	 VedioManual = 0;
	 initflag = 1;
	 choose_menu = 0;
 
	 dis_mod = DIS_MAIN_MENU;
 }


 
 void display_task(void) //100ms
 {
	 u8 i, key;
	 static u8 vedio_time;
	 static u8 lastmode = DIS_MAIN_MENU;
 
 
	 key = message_get(MSG_FIFO_KEY);
     // 按键处理视频信号
	 key = VedioCheck(key);
 
 
	 for(i = 0; i < MAXDISMENU; i++)
	 {
		 if((disp[i].operate != 0) && (disp[i].id == dis_mod))
		 {
			 lastmode = dis_mod;
			 dis_mod = (*disp[i].operate)(key, initflag);
			 initflag = 0;
			 if(dis_mod != lastmode)
			 {
				 initflag = 1;
			 }
			 break;
		 }
	 }
 
	 if(i == MAXDISMENU)
	 {
		 dis_mod = DIS_CHOOSE_MENU;
	 }
 
 
	 if(ReInitDisplayFlag)
	 {
		 ReInitDisplayFlag = 0;
		 ReInitDisplay();
		 i = 0;
		 lastmode = DIS_MAIN_MENU;
	 }
 
 }
 
 void InitDispStru(void)
 {
	 u8 i = 0;
	 for(i = 0; i < MAXDISMENU; i++)
	 {
		 disp[i].operate = 0;
	 }
 }
 void AddMenu(u32(*operate)(u8 key, u8 initpw), u32 id)
 {
	 DisMenuStruct *p;
	 if(MenuNum >= MAXDISMENU)
	 {
		 return ;
	 }
	 p = &disp[MenuNum++];
	 p->id = id;
	 p->operate = operate;
 }
 
 void InitDisplayHelper(void)
 {
	 SendKeyToGPU(CMD_DIS_MAIN);
	 InitNoEncryptSetVar();
 
	 InitDispStru();
	 //AddMenu(EMGMesg, 		   DIS_EMG_MENU);
	 //AddMenu(ACCMesg, 		   DIS_ACC_MENU);
	 AddMenu(MainMesg,			   DIS_MAIN_MENU);
	 //AddMenu(HelpMesg,			 DIS_HELP_MENU);
 
	 AddMenu(NoEncryptSystemSet,   DIS_FACTORY_SET_MENU);
	 AddMenu(EncryptSystemSet,	   DIS_SYSTEM_SET_MENU);
	 AddMenu(ArtMesg,			   DIS_ART_INFORMATION);
 
	 AddMenu(MenuMesg,			   DIS_CHOOSE_MENU);
 }


















#if 0
 void display_time_bar_soc(u8 initpw)
 {
	 static uint8_t pre_min = 0xFF;
	 uint8_t i;
	 u8 soc_temp;
	 static uint8_t pre_veh_bar1 = 0, pre_veh_bar2 = 0, bar_step1 = 0, bar_step2 = 0, pre_soc;
 
	 for(i = 1; i < 12; i++)
	 {
		 Send_To_DP_Data[i] = 0;
	 }
 
	 if(veh_bar1 >= pre_veh_bar1)
	 {
		 bar_step1 = veh_bar1 - pre_veh_bar1;
	 }
	 else
	 {
		 bar_step1 = pre_veh_bar1 - veh_bar1;
	 }
	 if(veh_bar2 >= pre_veh_bar2)
	 {
		 bar_step2 = veh_bar2 - pre_veh_bar2;
	 }
	 else
	 {
		 bar_step2 = pre_veh_bar2 - veh_bar2;
	 }
 
	 soc_temp = veh_soc;
	 if(soc_temp >= 100)
	 {
		 soc_temp = 100;
	 }
 
	 if((pre_min != rtc.mins) || (bar_step1 > 3) || (bar_step2 > 3) || (pre_soc != soc_temp) || (initpw > 0))
	 {
		 //SET_TIME = 1;
		 pre_min = rtc.mins;
		 Send_To_DP_Data[1] = PAGE_MAIN;
		 Send_To_DP_Data[2] = 3;
		 Send_To_DP_Data[3] = tmp_buff[5];
		 Send_To_DP_Data[4] = tmp_buff[4];
		 Send_To_DP_Data[5] = tmp_buff[3];
		 Send_To_DP_Data[6] = tmp_buff[2];
		 Send_To_DP_Data[7] = tmp_buff[1];//0x15
 
		 pre_veh_bar1 = veh_bar1;
		 pre_veh_bar2 = veh_bar2;
		 pre_soc = soc_temp;
 
		 Send_To_DP_Data[8] = veh_bar1;
		 Send_To_DP_Data[9] = veh_bar2;
		 Send_To_DP_Data[10] = pre_soc;
 
		 SendToDP();
	 }
 
 }
#endif

 void Send_Time_ToDis(u8 initpw)
 {
	 SendStart();
 
	 Send_To_DP_Data[0] = 0x80;
	 Send_To_DP_Data[1] = 01;
	 Send_To_DP_Data[2] = 2;
 
	 DP_DATA1 = rtc.year;
	 DP_DATA2 = rtc.month;
	 DP_DATA3 = rtc.day;
	 DP_DATA4 = rtc.hours;
	 DP_DATA5 = rtc.mins;
	 DP_DATA6 = rtc.secs;
	 DP_DATA7 = Veh_trip;
	 DP_DATA8 = Veh_trip >> 8;
 
	 SendEnd();
 }
 
 
 void Send_Symbol_ToDis(u8 initpw)
 {
	 SendStart();
 
	 Send_To_DP_Data[0] = 0x80;
	 Send_To_DP_Data[1] = 1;
	 Send_To_DP_Data[2] = 3;
 
	 DP_DATA1 = led[0].byte;
	 DP_DATA2 = led[1].byte;
	 DP_DATA3 = led[2].byte;
	 DP_DATA4 = led[3].byte;
	 DP_DATA5 = led[4].byte;
	 DP_DATA6 = led[5].byte;
	 DP_DATA7 = led[6].byte;
	 DP_DATA8 = led[7].byte;
 
	 SendEnd();
 }
 
 void Send_Guide_ToDis1(u8 initpw)
 {
	 SendStart();
 
	 Send_To_DP_Data[0] = 0x80;
	 Send_To_DP_Data[1] = 2;
	 Send_To_DP_Data[2] = 1;
 
	 DP_DATA1 = veh_speed_display;
	 DP_DATA2 = veh_speed_display >> 8;
	 DP_DATA3 = eng_speed;
	 DP_DATA4 = eng_speed >> 8;
	 DP_DATA5 = veh_bar1;
	 DP_DATA6 = veh_bar2;
	 DP_DATA7 = (Vbat >> 1);
 	 DP_DATA8 = veh_soc;
	 SendEnd();
 }
 
 void Send_Guide_ToDis2(u8 initpw)
 {
 	 u16 u16_data;
	 static u8 soc_count = 0;
	 SendStart();
 
	 Send_To_DP_Data[0] = 0x80;
	 Send_To_DP_Data[1] = 2;
	 Send_To_DP_Data[2] = 2;

 	 soc_count++;
	 if((soc_count >= 100) || (soc_count < veh_soc))
	 	soc_count = veh_soc;
	 DP_DATA1 = CanData[ID(0x0C04A1A7)][6];
     DP_DATA2 = CanData[ID(0x0C04A1A7)][7];
	 DP_DATA3 = 0;
	 DP_DATA4 = soc_count;
	 DP_DATA5 = 0;
     DP_DATA6 = 0;
     DP_DATA7 = 0;
     DP_DATA8 = 0;

	 SendEnd();
 }
 
 void Constant_display_Task()
 {
	 static u8 count = 0;
	 static u8 temp = 0;
	 static u8 count2 = 100;
 
	 Send_Symbol_ToDis(1);
	 PushDataToGPU();
 
	 if(count >= 5)
	 {
		 Send_Time_ToDis(1);
		 Send_Guide_ToDis1(1);
		 Send_Guide_ToDis2(1);
		 count = 0;
	 }
 
	 if(dis_mod != DIS_FACTORY_SET_MENU)
	 {
		 UpdateNoEncryptSetVar();
 
		 if(temp != NoEncryptSetVar[5])
		 {
			 if(count2 == 0)
			 {
				 count2 = 10;
			 }
			 temp = NoEncryptSetVar[5];
		 }
 
		 if(count2)
		 {
			 count2--;
			 NoEncryptSetToGPU();
		 }
	 }
 
	 count++;
 }


 
 
 void roll_alarm_Task(void)  //200ms
 {
	 if((KEY_ON && (ONFlag)) || KEY_CHARGE)
	 {
		 uint8_t i;
		 uint16_t alarm_count = 0xFF;
		 static  uint16_t x = 0;
		 u64 data[4];
		 u64 temp;
 
		 for(i = 1; i < 12; i++)
		 {
			 Send_To_DP_Data[i] = 0;
		 }
 
		 Send_To_DP_Data[0] = 0x80;
		 Send_To_DP_Data[1] = PAGE_MAIN;
		 Send_To_DP_Data[2] = 0x01;
 
		 data[0] = tip_code1.qword;
		 data[1] = tip_code2.qword;
		 data[2] = tip_code3.qword;
		 data[3] = tip_code4.qword;
 
		 for(i = 0; i < (sizeof(data) / sizeof(data[0])); i++)
		 {
			 if(data[i] != 0)
			 {
				 break;
			 }
		 }
 
		 if(i == (sizeof(data) / sizeof(data[0])))
		 {
			 goto end;
		 }
 
		 for(; x < (sizeof(data) * 8); x++)
		 {
 
			 if(((data[x >> 6] >> (x & (0x3F))) & 0x01) == 0x01)
			 {
				 alarm_count = x;
				 x++;
				 break;
			 }
 
		 }
 
 end:
		 DP_DATA1 = (u8)(alarm_count + 1);
		 DP_DATA2 = 0;
 
		 {
			 u16 errcode = GetWenziWarnCode(DP_DATA1);
			 DP_DATA3 = GetU16Low(errcode);
			 DP_DATA4 = GetU16High(errcode);
		 }
 
		 DP_DATA5 = Veh_odo;
		 DP_DATA6 = Veh_odo >> 8;
		 DP_DATA7 = Veh_odo >> 16;
		 DP_DATA8 = Veh_odo >> 24;
 
		 SendToDP();
 
		 if(alarm_count == 0xFF)
		 {
			 x = 0;
		 }
	 }
 }





