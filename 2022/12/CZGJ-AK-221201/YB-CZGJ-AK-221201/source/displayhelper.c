/*
 * displayhelper.c
 *
 *  Created on: 2021-7-27
 *      Author: ART
 */

#include "system_init.h"
#include "keyfifo.h"
#include "display.h"

void Main_Send(u8 initpw);
void display_total_miles(u8 initpw);
void SaveChangeEncrypt(void);

//视频手动标志，0自动，1手动
//当 视频 键按下是置1，所有 视频自动切换信号没有后 清0
static int32_t VedioManual = 0;
//只有两个标志位都有效时，视频自动切换才能运行。

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

#define ChLiChengStart      0
#define ChLiChengLen        (ChangeLiChengEnable*7)

#define ChSubiStart         (ChLiChengStart + ChLiChengLen)
#define ChSubiLen           (ChangeSubiEnable*4)

#define ChPulseStart        (ChSubiStart + ChSubiLen)
#define ChPulseLen          (ChangePulseEnable*4)

#define ChCoefStart         (ChPulseStart+ChPulseLen)
#define ChCoefLen           (ChangeCoefEnable*3)

#define ChAir1CoefStart      (ChCoefStart+ChCoefLen)  //1 气压比例系数
#define ChAir1CoefLen        (ChangeAir1CoefEnable*3)

#define ChAir2CoefStart      (ChAir1CoefStart+ChAir1CoefLen)  //1 气压比例系数
#define ChAir2CoefLen        (ChangeAir2CoefEnable*3)

#define ChSpeedAlarmStart  (ChAir2CoefStart+ChAir2CoefLen)//1 超速报警系数
#define ChSpeedAlarmLen     (ChangeSpeedAlarmEnable*3)

#define ChAirAlarmStart    (ChSpeedAlarmStart+ChSpeedAlarmLen)//3 气压报警值
#define ChAirAlarmLen      (ChangeAirAlarmEnable*3)

#define ChOilAlarmStart    (ChAirAlarmStart+ChAirAlarmLen)//3 机油压力报警系数
#define ChOilAlarmLen      (ChangeOilAlarmEnable*3)

#define ChRanYouStart       (ChOilAlarmStart+ChOilAlarmLen)//3 燃油报警值
#define ChRanYouLen         (ChangeRanyouEnable*3)

#define ChVideoAv1Start     (ChRanYouStart+ChRanYouLen)//3 视频1
#define ChVideoAv1Len       (ChangeVideoAv1Enable)

#define ChVideoAv2Start     (ChVideoAv1Start+ChVideoAv1Len)//3 视频2
#define ChVideoAv2Len       (ChangeVideoAv2Enable)

#define ChVideoAv3Start     (ChVideoAv2Start+ChVideoAv2Len)//3 视频2
#define ChVideoAv3Len       (ChangeVideoAv3Enable)

#define ChVideoAv4Start     (ChVideoAv3Start+ChVideoAv3Len)//3 视频2
#define ChVideoAv4Len       (ChangeVideoAv4Enable)

#define ChRainStart         (ChVideoAv4Start + ChVideoAv4Len)//3 雨刮时间设置
#define ChRainLen           (ChangeRainEnable)

#define ChRainTimeStart     (ChRainStart+ChRainLen)
#define ChRainTimeLen       (ChangeRainTimeEnable*3)


#define ChFuelCoefStart     (ChRainTimeStart+ChRainTimeLen)//3 视频2
#define ChFuelCoefLen       (ChangeFuelCoefEnable*3)


#define ChTimeStart         0
#define ChTimeLen           (ChangeTimeEnable*5)

#define ChBLStart           (ChTimeStart + ChTimeLen)
#define ChBLLen             (ChangeBLEnable*1)

#define ChBuzzStart         (ChBLStart + ChBLLen)
#define ChBuzzLen           (ChangeBuzzEnable*1)


const uint8_t days_in_mo[13] = 
{0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

u8  initflag = 1;

uint8_t dis_mod = DIS_NOP_MENU;

uint8_t SetOption = 0;
u8 ClearBufferDisable = 0;

void ChangeToPage(uint8_t menu)
{
    uint8_t i;
    for(i = 1; i < 12; i++)
        communicate_T123_data[i] = 0;

    communicate_T123_data[1] = 0x80;
    communicate_T123_data[2] = 0x02;
    communicate_T123_data[3] = menu;

    if(menu == PAGE_ARTSET)
    {
        communicate_T123_data[4] = SetOption;
        switch(SetOption)
        {
            case PassWordPage:
                break;
            case NoEncryptSetPage:
                communicate_T123_data[5] = backlight_level;
                communicate_T123_data[6] = !BUZZ_NORMAL_WORK;
                break;
            case EncryptSetPage:
                communicate_T123_data[5] = odometer_const;
                communicate_T123_data[6] = ((odometer_const%10000) >> 8);

                communicate_T123_data[7] = GetU16Low(Pulse);
                communicate_T123_data[8] = GetU16High(Pulse);

				communicate_T123_data[9] = Coef;
                break;
			case KehuEncryptSetPage:
                communicate_T123_data[5] = odometer_const;
                communicate_T123_data[6] = ((odometer_const%10000) >> 8);

                communicate_T123_data[7] = GetU16Low(Pulse);
                communicate_T123_data[8] = GetU16High(Pulse);

                communicate_T123_data[9] = Coef;
                break;			
            default:
                communicate_T123_data[4] = 0;
                break;
        }

    }
    if(ClearBufferDisable == 0)
        Fifo_set_free();
    TransmitTo123Loop(8,10);
	//	CAN_T123();
}










static u32 MainMesg(u8 key,u8 initpw)
{
    static uint8_t vedio_menu = 0,loop = 0;
    if((initpw))
    {
    	ChangeToPage(PAGE_MAIN);
    }
    Main_Send(initpw);
	if(KEY_ON)
	{
	    switch(key)
	    {
	        case IN_KEY2_SP:
				 break;

	        case IN_KEY3_SP:
				 break;

	        case IN_KEY4_SP:
				loop++;
			 break;
		    case IN_KEY6_CP:
				if(loop == 3)
				{
					MPC5602_CALL_T123 ^= 1;
				}
				else if(loop == 2)
				{
					 BUZZ_NORMAL_WORK ^= 1;
					 //SaveMeterPara();
					 EEPARAFLAG = 1;
				}
				loop = 0;

			 break;

	        case IN_KEY1_SP:
	        	return DIS_CHOOSE_MENU;
	        case IN_KEY5_CP:
				 Veh_trip = 0;
				 clear_mile = 1;
				 //SaveVehodo();
				  EEODOFLAG = 1;
	            break;
	        case IN_KEY6_SP:
				VedioManual = 1; //手动切换到视屏界面
				return DIS_VEDIO; //切换到视频界面
	    }
	}
	
	if(!KEY_ON)
	{
		/*if(KEY_CHARGE||KEY_POWER)
		{
		    #if ANKAI_ADD_SCREEC_FOR_PARK
			  return DIS_POWER_MENU;
			#else
			  return DIS_NOP_MENU;
			#endif
		}
		else*/
		return DIS_NOP_MENU;
	}
	else if(YOUMEN_ENABLE && KEY_ON)
		return DIS_YOUMEN_MENU;
	else if(EP_ENABLE && KEY_ON)
		return DIS_EP_MENU;
	else
        return DIS_MAIN_MENU;
}


static u32 MenuMesg(u8 key,u8 initpw)
{
	static uint8_t choose_menu = 0,Para_time = 0;
	u8 sendflag = 0,i;
	TYPE_BYTE temp_u8;
	if(initpw)
	{
		ChangeToPage(PAGE_MENU);
		sendflag = 1;
	}
	switch(key)
	{
		case IN_KEY1_SP:
			return DIS_MAIN_MENU;
		case IN_KEY4_SP:
			return choose_menu;
		case IN_KEY2_SP:
			if(choose_menu == DIS_ART_INFORMATION)
				choose_menu = DIS_MAIN_MENU;
			else
				choose_menu++;
			sendflag = 1;
			break;
		case IN_KEY3_SP:
			if(choose_menu == DIS_MAIN_MENU)
				choose_menu = DIS_ART_INFORMATION;
			else
				choose_menu--;
			sendflag = 1;
			break;
	}

	if(sendflag)
	{
		for(i = 1; i < 12; i++)
			communicate_T123_data[i] = 0;

		communicate_T123_data[1] = PAGE_MENU;
		communicate_T123_data[2] = choose_menu;  // 切换界面
		Transmit_Data_Sci1(communicate_T123_data,12);
	}
    else
    {
	   Para_time++;
	   if(Para_time == 4)
	   {
		//Para_time = 0;
		for(i = 1; i < 12; i++)
			communicate_T123_data[i] = 0;

		communicate_T123_data[1] = PAGE_MENU;
		communicate_T123_data[2] = 0XF1;  // 切换界面
		temp_u8.byte = 0;
		temp_u8.bit.b0 = !SET_VIDEO_AV1;
		temp_u8.bit.b1 = !SET_VIDEO_AV2;
		temp_u8.bit.b2 = !SET_VIDEO_AV3;
		temp_u8.bit.b3 = !SET_VIDEO_AV4;
		temp_u8.bit.b4 = !SET_RAIN;

		communicate_T123_data[3] = temp_u8.byte;
		communicate_T123_data[4] = Set_Air_Coef;
		communicate_T123_data[5] = Set_Air2_Coef;
		communicate_T123_data[6] = Set_Speed_Alarm;
		communicate_T123_data[7] = Set_Air_Alarm;
		communicate_T123_data[8] = Set_Oil_Alarm;
		communicate_T123_data[9] = Set_Ranyou_Alarm;//油量报警
		communicate_T123_data[10] = Set_Fuel_Coef;//瞬时电耗参数
		Transmit_Data_Sci1(communicate_T123_data,12);
	   }
	   else if(Para_time == 8)
	   {
		Para_time = 0;
		for(i = 1; i < 12; i++)
			communicate_T123_data[i] = 0;

		communicate_T123_data[1] = PAGE_MENU;
		communicate_T123_data[2] = 0XF2;  // 切换界面


		communicate_T123_data[3] = Set_Rain_Delay_Time;

		Transmit_Data_Sci1(communicate_T123_data,12);

	  }     
	}
	return DIS_CHOOSE_MENU;

}


static u32 HelpMesg(u8 key,u8 initpw)
{
    if(initpw)
    {
        ChangeToPage(PAGE_ARTHELP);
    }
    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }
    return DIS_HELP_MENU;
}


static u8 timedata[5];

/*************************************************************************
* Function Name    : is_leep_year
* Description		  : this function determines whether the year is a leap year
* Parameters		 : year: is the year to check for leap year
* Return Value	 :1: if year is a leap year
				  0: if year is not a leap year	
**************************************************************************/
uint8_t is_leap_year(void)
{	
	
	if(!((rtc.year+2000) % 4) && ((rtc.year+2000) % 100) || !((rtc.year+2000) % 400))
		return 1;
	else
		return 0;
		
}

#if(ChangeTimeEnable == ON)
u8 ChangeTime(u8 key,u8 initpw)
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
        initflag = 1;

    if(initflag)
    {
        initflag = 0;
        for(i=0; i<5; i++)
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
                    data[4] = (data[4] > (((data[3] == 2) && is_leap_year())?29:days_in_mo[data[3]])) ? 1 : data[4];
                    break;
            }
            sendflag = 1;
            break;
        case IN_KEY3_SP:
            switch(index)
            {
                case 0:
                    data[0] =  data[0] <= 0 ? 24 : data[0];;
                    break;
                case 1:
                    data[1] =  data[1] <= 0 ? 60 : data[1];
                    break;
                case 2:
                    data[2] = data[2] <= 0 ? 100 : data[2];
                    break;
                case 3:
                    data[3] =  data[3] <= 1 ? 13 : data[3];
                    break;
                case 4:
                    data[4] = data[4] <= 1 ? ((((data[3] == 2) && is_leap_year())?28:days_in_mo[data[3]])+1):data[4];
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
        for(i=0; i<5; i++)
        {
            timedata[i] = data[i];
        }

        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = NoEncryptSetPage;
        communicate_T123_data[3] = index + ChTimeStart;
        communicate_T123_data[4] = BIN_TO_BCD(data[index]);

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }

    return 0;

}
#endif
#if(ChangeBLEnable == ON)
static u8 ChangeBackLight(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

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
        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = NoEncryptSetPage;

        communicate_T123_data[3] = ChBLStart;
        communicate_T123_data[4] = backlight_level;

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }

    return 0;
}
#endif
#if(ChangeBuzzEnable == ON)
static u8 ChangeBuzz(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

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
        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = NoEncryptSetPage;
        communicate_T123_data[3] = ChBuzzStart;
        communicate_T123_data[4] = !BUZZ_NORMAL_WORK;

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }

    return 0;
}
#endif

void ReInitSystemPage()
{
    timedata[0] = rtc.hours;
    timedata[1] = rtc.mins;
    timedata[2] = rtc.year;
    timedata[3] = rtc.month;
    timedata[4] = rtc.day;
    timedata[5] = rtc.secs;
    Set_backlight_level = backlight_level;
    Set_buzz = BUZZ_NORMAL_WORK;

}

void SaveTime(void)
{
    rtc.hours =  timedata[0] ;
    rtc.mins  =  timedata[1] ;
    rtc.year  =  timedata[2] ;
    rtc.month =  timedata[3] ;
    rtc.day   =  timedata[4] ;
    rtc.secs  =  timedata[5] ;
    set_date();
}

void SaveChangeNoEncrypt()
{
    if((Set_backlight_level != backlight_level)||(Set_buzz != BUZZ_NORMAL_WORK))
    {

        Set_backlight_level = backlight_level;
        Set_buzz = BUZZ_NORMAL_WORK;

       // SaveMeterPara();
       EEPARAFLAG = 1;
    }
}




u32 NoEncryptSystemSet(u8 key,u8 initpw) //不保密设定
{
    static u32 flag =0;
    static u8 initflag = 0;
    static u8 LastNoEncryptSystemSetPage = NoEncryptSystemSetLast;
    static u8 reinitflag = 0;

    if(initpw)
    {
     //   display_time_bar_soc(1); //补发一下时间同步修改显示
        ClearBufferDisable = 1;
        ChangeToSetPage(NoEncryptSetPage);
        ClearBufferDisable = 0;
        ReInitSystemPage();
        LastNoEncryptSystemSetPage = flag;
        flag = 0;
        reinitflag = 1;
    }

    if((LastNoEncryptSystemSetPage == flag)&&reinitflag)
    {
        initflag = 1;
        reinitflag = 0;
    }

    switch(flag)
    {
#if(ChangeTimeEnable == ON)
        case TimeIndex:
            flag += ChangeTime(key,initflag);
            initflag = 0;
            break;
#endif
#if(ChangeBLEnable == ON)
        case BLIndex:
            flag += ChangeBackLight(key,initflag);
            initflag = 0;
            break;
#endif
#if(ChangeBuzzEnable == ON)
        case BuzzIndex:
            flag += ChangeBuzz(key,initflag);
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


const uint16_t password = 2046;
const uint16_t kehu_password = 1127;
u8 kehu_mi = 0;
u16 set_password;

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

#if(ChangeAir1CoefEnable == ON)
    Air1CoefIndex,
#endif
#if(ChangeAir2CoefEnable == ON)
    Air2CoefIndex,
#endif

#if(ChangeSpeedAlarmEnable == ON)
    AirSpeedAlarmIndex,
#endif
#if(ChangeAirAlarmEnable == ON)
    AirAlarmIndex,
#endif
#if(ChangeOilAlarmEnable == ON)
    OilAlarmIndex,
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
#if(ChangeRainEnable == ON)
    RainIndex,
#endif
#if(ChangeRainTimeEnable == ON)
	RainTimeIndex,
#endif

#if(ChangeFuelCoefEnable == ON)
	FuelCoefIndex,
#endif

    EncryptSystemSetLast
};

void u32tostr(u32 dataxxx,u8 * out,u8 optionx,u8 CharNum)
{
    utostrbcd();
}



#if (ChangeLiChengEnable == ON)
static u8 ChangeLicheng(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

    if(initflag)
    {
        initflag = 0;

        u32tostr(Set_Veh_odo,setbcd,1,7);
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
        for(i=0; i<7; i++)
        {
            Set_Veh_odo *= 10;
            Set_Veh_odo += setbcd[i];
        }

        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = EncryptSetPage;
        communicate_T123_data[3] = index + ChLiChengStart;
        communicate_T123_data[4] = setbcd[index];

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }

    return 0;
}

#endif

#if(ChangeSubiEnable == ON)
static u8 ChangeSubi(u8 key,u8 initpw)
{
	static u8 index = 0;
	static u8 initflag = 1;
	static u8 setbcd[10] = {0};
	static u16 set_odometer_last;
	u8 i;

	u8 sendflag = 0;

	if(initpw)
		initflag = 1;

	if(initflag)
	{
		initflag = 0;
		set_odometer_last = Set_odometer_const;
		u32tostr(Set_odometer_const,setbcd,1,4);
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
		for(i=0; i<4; i++)
		{
			Set_odometer_const *= 10;
			Set_odometer_const += setbcd[i];
		}
		if(!kehu_mi)
		{
			odometer_const_2012 = Set_odometer_const;
		}
		if(kehu_mi)
		{
			//if((Set_odometer_const > (1.2*odometer_const_2012))||(Set_odometer_const < (0.8*odometer_const_2012)))
			if((Set_odometer_const > (1.2*SUBI))||(Set_odometer_const < (0.8*SUBI)))
			{
				Set_odometer_const = set_odometer_last;			
				MIMA_FLAG = 1;
			}
			else
				MIMA_FLAG = 0;
		}
		for(i = 1; i < 12; i++)
			communicate_T123_data[i] = 0;

		communicate_T123_data[1] = PAGE_ARTSET;
		communicate_T123_data[2] = EncryptSetPage+kehu_mi;
		communicate_T123_data[3] = index+ChSubiStart;
		communicate_T123_data[4] = setbcd[index];
		Transmit_Data_Sci1(communicate_T123_data,12);
		sendflag = 0;
	}

	return 0;
}

#endif

#if(ChangePulseEnable == ON)
static u8 ChangePulse(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
	static u16 set_Pulse_last;
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

    if(initflag)
    {
        initflag = 0;
		set_Pulse_last = Set_Pulse;
        u32tostr(Set_Pulse,setbcd,1,4);
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
        for(i=0; i<4; i++)
        {
            Set_Pulse *= 10;
            Set_Pulse += setbcd[i];
        }
		if(!kehu_mi)
		{
			Pulse_const_2012 = Set_Pulse;
		}
		if(kehu_mi)
		{
			//if((Set_Pulse > (1.2*Pulse_const_2012))||(Set_Pulse < (0.8*Pulse_const_2012)))
			if((Set_Pulse > (1.2*PULSE))||(Set_Pulse < (0.8*PULSE)))
			{
				Set_Pulse = set_Pulse_last;			
				MIMA_FLAG = 1;
			}
			else
				MIMA_FLAG = 0;
		}
        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = EncryptSetPage+kehu_mi;
        communicate_T123_data[3] = index+ ChPulseStart;
        communicate_T123_data[4] = setbcd[index];


        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }

    return 0;
}
#endif


#if(ChangeCoefEnable == ON)
static u8 ChangeCoef(u8 key,u8 initpw)
{
	static u8 index = 0;
	static u8 initflag = 1;
	static u8 setbcd[10] = {0};
	
	static u8 set_coef_last = 0;
	u8 i;

	u8 sendflag = 0;

	if(initpw)
		initflag = 1;

	if(initflag)
	{
		initflag = 0;
		set_coef_last = Set_Coef;
		u32tostr(Set_Coef,setbcd,1,3);
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
		for(i=0; i<3; i++)
		{
			Set_Coef *= 10;
			Set_Coef += setbcd[i];
		}
		
		if(!kehu_mi)
		{
			Coef_2012 = Set_Coef;
		}
		if(kehu_mi)
		{
			//if((Set_Coef > (1.2*Coef_2012))||(Set_Coef < (0.8*Coef_2012)))
			if((Set_Coef > (1.2*COEF))||(Set_Coef < (0.8*COEF)))
			{
				Set_Coef = set_coef_last;			
				MIMA_FLAG = 1;
			}
			else
				MIMA_FLAG = 0;
		}
		
		for(i = 1; i < 12; i++)
			communicate_T123_data[i] = 0;

		communicate_T123_data[1] = PAGE_ARTSET;
		communicate_T123_data[2] = EncryptSetPage+kehu_mi;
		communicate_T123_data[3] = index+ ChCoefStart;
		communicate_T123_data[4] = setbcd[index];
		Transmit_Data_Sci1(communicate_T123_data,12);
		sendflag = 0;
	}
	return 0;
}


#endif

#if(ChangeAir1CoefEnable == ON)
static u8 ChangeAir1Coef(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

    if(initflag)
    {
        initflag = 0;

        u32tostr(Set_Air_Coef,setbcd,1,3);
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
        for(i=0; i<3; i++)
        {
            Set_Air_Coef *= 10;
            Set_Air_Coef += setbcd[i];
        }

        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = EncryptSetPage+kehu_mi;
        communicate_T123_data[3] = index+ ChAir1CoefStart;
        communicate_T123_data[4] = setbcd[index];

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }
    return 0;
}

#endif

#if(ChangeAir2CoefEnable == ON)
static u8 ChangeAir2Coef(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

    if(initflag)
    {
        initflag = 0;

        u32tostr(Set_Air2_Coef,setbcd,1,3);
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
        Set_Air2_Coef = 0;
        for(i=0; i<3; i++)
        {
            Set_Air2_Coef *= 10;
            Set_Air2_Coef += setbcd[i];
        }

        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = EncryptSetPage+kehu_mi;
        communicate_T123_data[3] = index+ ChAir2CoefStart;
        communicate_T123_data[4] = setbcd[index];

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }
    return 0;
}

#endif

#if(ChangeSpeedAlarmEnable == ON)
static u8 ChangeSpeedAlarm(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

    if(initflag)
    {
        initflag = 0;

        u32tostr(Set_Speed_Alarm,setbcd,1,3);
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
        Set_Speed_Alarm= 0;
        for(i=0; i<3; i++)
        {
            Set_Speed_Alarm *= 10;
            Set_Speed_Alarm += setbcd[i];
        }

        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = EncryptSetPage+kehu_mi;
        communicate_T123_data[3] = index+ ChSpeedAlarmStart;
        communicate_T123_data[4] = setbcd[index];

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }
    return 0;
}

#endif

#if(ChangeAirAlarmEnable == ON)
static u8 ChangeAirAlarm(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

    if(initflag)
    {
        initflag = 0;

        u32tostr(Set_Air_Alarm,setbcd,1,3);
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
        for(i=0; i<3; i++)
        {
            Set_Air_Alarm *= 10;
            Set_Air_Alarm += setbcd[i];
        }

        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = EncryptSetPage+kehu_mi;
        communicate_T123_data[3] = index+ ChAirAlarmStart;
        communicate_T123_data[4] = setbcd[index];

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }
    return 0;
}

#endif

#if(ChangeOilAlarmEnable == ON)
static u8 ChangeOilAlarm(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;
	static u8 set_oilalarm_last = 0;
    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

    if(initflag)
    {
        initflag = 0;
		set_oilalarm_last = Set_Oil_Alarm;
        u32tostr(Set_Oil_Alarm,setbcd,1,3);
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
        Set_Oil_Alarm = 0;
        for(i=0; i<3; i++)
        {
            Set_Oil_Alarm *= 10;
            Set_Oil_Alarm += setbcd[i];
        }
		if(!kehu_mi)
		{
			Oil_Alarm_2012 = Set_Oil_Alarm;
		}
		if(kehu_mi)
		{
			//if((Set_Oil_Alarm > (1.2*Oil_Alarm_2012))||(Set_Oil_Alarm < (0.8*Oil_Alarm_2012)))
			if((Set_Oil_Alarm > (1.2*OIL_ALARM))||(Set_Oil_Alarm < (0.8*OIL_ALARM)))
			{
				Set_Oil_Alarm = set_oilalarm_last;			
				MIMA_FLAG = 1;
			}
			else
				MIMA_FLAG = 0;
		}
        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = EncryptSetPage+kehu_mi;
        communicate_T123_data[3] = index+ ChOilAlarmStart;
        communicate_T123_data[4] = setbcd[index];

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }
    return 0;
}

#endif


#if(ChangeRanyouEnable == ON)
static u8 ChangeRanYou(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

    if(initflag)
    {
        initflag = 0;

        u32tostr(Set_Ranyou_Alarm,setbcd,1,3);
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
        for(i=0; i<3; i++)
        {
            Set_Ranyou_Alarm *= 10;
            Set_Ranyou_Alarm += setbcd[i];
        }

        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = EncryptSetPage+kehu_mi;
        communicate_T123_data[3] = index+ ChRanYouStart;
        communicate_T123_data[4] = setbcd[index];

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }
    return 0;
}

#endif

#if(ChangeVideoAv1Enable == ON)
static u8 ChangeVideoAv1(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

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
        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = EncryptSetPage+kehu_mi;
        communicate_T123_data[3] = ChVideoAv1Start;
        communicate_T123_data[4] = !SET_VIDEO_AV1;

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }

    return 0;
}
#endif

#if(ChangeVideoAv2Enable == ON)
static u8 ChangeVideoAv2(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

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
        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = EncryptSetPage+kehu_mi;
        communicate_T123_data[3] = ChVideoAv2Start;
        communicate_T123_data[4] = !SET_VIDEO_AV2;

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }

    return 0;
}
#endif


#if(ChangeVideoAv3Enable == ON)
static u8 ChangeVideoAv3(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

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
        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = EncryptSetPage+kehu_mi;
        communicate_T123_data[3] = ChVideoAv3Start;
        communicate_T123_data[4] = !SET_VIDEO_AV3;

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }

    return 0;
}
#endif


#if(ChangeVideoAv4Enable == ON)
static u8 ChangeVideoAv4(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

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
        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = EncryptSetPage+kehu_mi;
        communicate_T123_data[3] = ChVideoAv4Start;
        communicate_T123_data[4] = !SET_VIDEO_AV4;

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }

    return 0;
}
#endif

#if(ChangeRainEnable == ON)
static u8 ChangeRain(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

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
            SET_RAIN^= 1;
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
        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = EncryptSetPage+kehu_mi;
        communicate_T123_data[3] = ChRainStart;
        communicate_T123_data[4] = !SET_RAIN;

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }

    return 0;
}
#endif

#if(ChangeRainTimeEnable == ON)
static u8 ChangeRainTime(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;
    u16 temp;
    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

    if(initflag)
    {
        initflag = 0;

        u32tostr(Set_Rain_Delay_Time,setbcd,1,3);
        index = 0;
        sendflag = 1;
		if(!SET_RAIN)
		{
			index = 0;
			initflag = 1;
			return 1;
		}
    }

    switch(key)
    {
        case IN_KEY6_SP:
			    index = 0;
                initflag = 1;
                return 1;
        case IN_KEY2_SP: //up

		    if(index == 0)
		    {
				setbcd[index] ++;
                setbcd[index] = setbcd[index] >= 3 ? 0 : setbcd[index];
			}
			else if(index == 1)
			{
				setbcd[index] +=2;
				setbcd[index] = setbcd[index] >= 10 ? 0 : setbcd[index];
			}

            sendflag = 1;
            break;
        case IN_KEY3_SP://down
            if(index == 0)
            {
               setbcd[index] = setbcd[index] <= 0 ? 3 : setbcd[index]; 		   
               setbcd[index] --;
			}
			else
			{
              setbcd[index] = setbcd[index] <= 0 ? 10 : setbcd[index];			  
			  setbcd[index] -=2;
			}
            sendflag = 1;
            break;
        case IN_KEY1_SP://funtion
            index ++;
            if(index >= (ChRainTimeLen - 1))
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
        Set_Rain_Delay_Time = 0;
        for(i=0; i<3; i++)
        {
            temp *= 10;
            temp += setbcd[i];
        }
        if(temp > 255)
			Set_Rain_Delay_Time = 240;
		else 
		   Set_Rain_Delay_Time = temp;
        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = EncryptSetPage+kehu_mi;
        communicate_T123_data[3] = index+ ChRainTimeStart;
        communicate_T123_data[4] = setbcd[index];

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }
    return 0;
}

#endif

static signed int CheckPassword(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

    if(initflag)
    {
        initflag = 0;
        set_password = 0;
        u32tostr(set_password,setbcd,1,4);
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
            if(set_password == password)
            {
                return 1;
            }
			else if(set_password == kehu_password)
			{
                return 2;
            }
            else
                return -1;
        }
        default:
            break;
    }

    if(sendflag == 1)
    {
        set_password = 0;
        for(i=0; i<4; i++)
        {
            set_password *= 10;
            set_password += setbcd[i];
        }

        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = PassWordPage;
        communicate_T123_data[3] = index;
        communicate_T123_data[4] = setbcd[index];

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }

    return 0;
}


#if(ChangeFuelCoefEnable == ON)
static u8 ChangeFuelCoef(u8 key,u8 initpw)
{
    static u8 index = 0;
    static u8 initflag = 1;
    static u8 setbcd[10] = {0};
    u8 i;

    u8 sendflag = 0;

    if(initpw)
        initflag = 1;

    if(initflag)
    {
        initflag = 0;

        u32tostr(Set_Fuel_Coef,setbcd,1,3);
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
        for(i=0; i<3; i++)
        {
            Set_Fuel_Coef *= 10;
            Set_Fuel_Coef += setbcd[i];
        }

        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_ARTSET;
        communicate_T123_data[2] = EncryptSetPage+kehu_mi;
        communicate_T123_data[3] = index+ ChFuelCoefStart;
        communicate_T123_data[4] = setbcd[index];

        Transmit_Data_Sci1(communicate_T123_data,12);
        sendflag = 0;
    }
    return 0;
}

#endif


u32 EncryptSystemSet(u8 key,u8 initpw) //保密设定
{
    static u32 flag =0;
    static u32 flag1 =0;

    static u8 initflag = 0;
    static u8 LastEncryptSystemSetPage = EncryptSystemSetLast;
    static u8 reinitflag = 0,sendflagxx = 1,xx;

	static u32 set_odo_org = 0;

    if(initpw)
    {
        ChangeToSetPage(PassWordPage);
        flag = 0;

        LastEncryptSystemSetPage = flag1;
        flag1 = 0;

        reinitflag = 1;
    }

    if((LastEncryptSystemSetPage == flag1)&&reinitflag)
    {
        initflag = 1;
        reinitflag = 0;
    }

    switch(flag)
    {
        case 0:
        {
            signed int f = CheckPassword(key,initpw);
			if(f == -1)
            {
                return DIS_CHOOSE_MENU;
            }

			if(f > 0)
			{			
	            if(f == 1)//2026
	            {
					flag1 = 0;
					kehu_mi = 0;
	                display_total_miles(1); //刷新下总里程显示
	                ClearBufferDisable = 1;
	                ChangeToSetPage(EncryptSetPage);
	                ClearBufferDisable = 0;                
	            }
				else if(f == 2)  //1127
	            {
					flag1 = 1;
					kehu_mi = 1;
	                ClearBufferDisable = 1;
	                ChangeToSetPage(KehuEncryptSetPage);
	                ClearBufferDisable = 0;
	            }
				
	            flag = 1;
	            Set_Veh_odo = Veh_odo;
				set_odo_org = Set_Veh_odo;
	            Set_odometer_const = odometer_const;
	            Set_Pulse = Pulse;
	            Set_Coef = Coef;

	            Set_Air_Coef = Air_Coef;
	            Set_Air2_Coef = Air2_Coef;
	            Set_Speed_Alarm = Speed_Alarm;
	            Set_Air_Alarm = Air_Alarm;
	            Set_Oil_Alarm = Oil_Alarm;
	            Set_Ranyou_Alarm = Ranyou_Alarm;
	            SET_VIDEO_AV1 = VIDEO_AV_GRAR;
	            SET_VIDEO_AV2 = VIDEO_AV_MID;
	            SET_VIDEO_AV3 = VIDEO_AV_FRO;
	            SET_VIDEO_AV4 = VIDEO_AV_ELSE;
	            Set_Fuel_Coef = Fuel_Coef;
				SET_RAIN = RAIN_STATE;
				Set_Rain_Delay_Time = Rain_Delay_Time;
			}
        }
        break;
        case 1:
            switch(flag1)
            {

#if(ChangeLiChengEnable == ON)
                case LiChengIndex:
                    flag1 += ChangeLicheng(key,initflag);
                    initflag = 0;
                    break;
#endif

#if(ChangeSubiEnable == ON)
                case SubiIndex:
                    flag1 += ChangeSubi(key,initflag);
                    initflag = 0;
                    break;
#endif
#if(ChangePulseEnable == ON)
                case PulseIndex:
                    flag1 += ChangePulse(key,initflag);
                    initflag = 0;
                    break;
#endif
#if(ChangeCoefEnable == ON)
                case CoefIndex:
                    flag1+=ChangeCoef(key,initflag);
                    initflag = 0;
                    break;
#endif

#if(ChangeAir1CoefEnable == ON)
                case Air1CoefIndex:
                    flag1+=ChangeAir1Coef(key,initflag);
                    initflag = 0;
                    break;
#endif

#if(ChangeAir2CoefEnable == ON)
                case Air2CoefIndex:
                    flag1+=ChangeAir2Coef(key,initflag);
                    initflag = 0;
                    break;
#endif

#if(ChangeSpeedAlarmEnable == ON)
                case AirSpeedAlarmIndex:
                    flag1+=ChangeSpeedAlarm(key,initflag);
                    initflag = 0;
                    break;
#endif
#if(ChangeAirAlarmEnable == ON)
                case AirAlarmIndex:
                    flag1+=ChangeAirAlarm(key,initflag);
                    initflag = 0;
                    break;
#endif
#if(ChangeOilAlarmEnable == ON)
                case OilAlarmIndex:
                    flag1+=ChangeOilAlarm(key,initflag);
                    initflag = 0;
                    break;
#endif
#if(ChangeRanyouEnable == ON)
                case RanYouIndex:
                    flag1+=ChangeRanYou(key,initflag);
                    initflag = 0;
                    break;
#endif
#if(ChangeVideoAv1Enable == ON)
                case VideoAv1Index:
                    flag1+=ChangeVideoAv1(key,initflag);
                    initflag = 0;
                    break;
#endif
#if(ChangeVideoAv2Enable == ON)
                case VideoAv2Index:
                    flag1+=ChangeVideoAv2(key,initflag);
                    initflag = 0;
                    break;
#endif
#if(ChangeVideoAv3Enable == ON)
                case VideoAv3Index:
                    flag1+=ChangeVideoAv3(key,initflag);
                    initflag = 0;
                    break;
#endif
#if(ChangeVideoAv4Enable == ON)
                case VideoAv4Index:
                    flag1+=ChangeVideoAv4(key,initflag);
                    initflag = 0;
                    break;
#endif
#if(ChangeRainEnable == ON)
                case RainIndex:
                    flag1+=ChangeRain(key,initflag);
                    initflag = 0;
                    break;
#endif

#if(ChangeRainTimeEnable == ON)
		   case RainTimeIndex:
			   flag1+=ChangeRainTime(key,initflag);
			   initflag = 0;
				break;
#endif

#if(ChangeFuelCoefEnable == ON)
				case FuelCoefIndex:
					flag1+=ChangeFuelCoef(key,initflag);
					initflag = 0;
					break;
#endif

            }

           
			if(kehu_mi == 1)
				 flag1 = (flag1 >= EncryptSystemSetLast ? 1 : flag1);
			else
				 flag1 = (flag1 >= EncryptSystemSetLast ? 0 : flag1);
			if(sendflagxx == 10)
			{
				sendflagxx = 0;
				for(xx = 0; xx < 12; xx++)
					communicate_T123_data[xx] = 0;
			
				communicate_T123_data[1] = PAGE_ARTSET;		
				communicate_T123_data[2] = EncryptSetPage +1 ;
				communicate_T123_data[3] = 0xFE;
				communicate_T123_data[4] = MIMA_FLAG;
				communicate_T123_data[5] = kehu_mi;
				communicate_T123_data[6] = odometer_const_2012;
				communicate_T123_data[7] = odometer_const_2012 >> 8;
				
				communicate_T123_data[8] = Set_odometer_const;
				communicate_T123_data[9] = Set_odometer_const >> 8;
				
				Transmit_Data_Sci1(communicate_T123_data,12);
			}
			sendflagxx ++;
            if(key == IN_KEY4_SP)
            {
            	if(set_odo_org == Set_Veh_odo)
            	{
            		Set_Veh_odo = set_odo_org;
				}
                SaveChangeEncrypt();
                flag = 0;
				kehu_mi = 0;
				MIMA_FLAG = 0;
                return DIS_CHOOSE_MENU;
            }
            break;

    }

    return DIS_SYSTEM_SET_MENU;
}


void SaveChangeEncrypt(void)
{
    u8 i = 0,k;
    if((Set_odometer_const != odometer_const) ||(Veh_odo != Set_Veh_odo)||(Set_Pulse!=Pulse)||(Set_Coef!=Coef)||\
       (Set_Air_Coef != Air_Coef)||(Set_Fuel_Coef != Fuel_Coef)||(Set_Speed_Alarm!= Speed_Alarm)||(Set_Air_Alarm!= Air_Alarm)||\
       (Set_Oil_Alarm!= Oil_Alarm)||(Set_Ranyou_Alarm != Ranyou_Alarm)||(SET_VIDEO_AV1 != VIDEO_AV_GRAR)||(Set_Air2_Coef != Air2_Coef)||\
       (SET_VIDEO_AV2 != VIDEO_AV_MID)||(SET_VIDEO_AV3 != VIDEO_AV_FRO)||(SET_VIDEO_AV4 != VIDEO_AV_ELSE)||(SET_RAIN!= RAIN_STATE)||\
       (Set_Rain_Delay_Time != Rain_Delay_Time))
    {
        //if(Veh_odo != Set_Veh_odo)
		//	Veh_trip = 0;
		Rain_Delay_Time = Set_Rain_Delay_Time;
        odometer_const = Set_odometer_const;
        Veh_odo = Set_Veh_odo;
        Pulse = Set_Pulse;
        Coef =  Set_Coef;
        Air2_Coef = Set_Air2_Coef;
        Air_Coef = Set_Air_Coef;
        Fuel_Coef = Set_Fuel_Coef;
        Speed_Alarm = Set_Speed_Alarm;
        Air_Alarm = Set_Air_Alarm;
        Oil_Alarm = Set_Oil_Alarm;
        Ranyou_Alarm = Set_Ranyou_Alarm;
        VIDEO_AV_GRAR = SET_VIDEO_AV1;
        VIDEO_AV_MID  = SET_VIDEO_AV2;
        VIDEO_AV_FRO  = SET_VIDEO_AV3;
        VIDEO_AV_ELSE = SET_VIDEO_AV4;
		RAIN_STATE = SET_RAIN;

        //SaveMeterPara();
        EEPARAFLAG = 1;
    }


}


void SaveODO(void)
{
	if(odo != Veh_odo)
	{
		//SaveVehodo();
		EEODOFLAG = 1;
		odo = Veh_odo;
	}
}







u32 MenuDIS_SELFTEST_MENU(u8 key,u8 initpw)
{
    if(initpw)
    {
        ChangeToPage(PAGE_MAIN);
        SELF_TEST = 1;
    }

    SELF_TEST = 1;

    return DIS_MAIN_MENU;
}

void SendPOWER01(u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x27;
    communicate_T123_data[2] = 0x01;

	communicate_T123_data[3] = Veh_odo/1000000;
	communicate_T123_data[4] = (Veh_odo%1000000)/100000;
	communicate_T123_data[5] = (Veh_odo%100000)/10000;
	communicate_T123_data[6] = (Veh_odo%10000)/1000;
	communicate_T123_data[7] = (Veh_odo%1000)/100;
	communicate_T123_data[8] = (Veh_odo%100)/10;
	communicate_T123_data[9] =  Veh_odo%10;
	SendEnd();
}



void SendPOWER02(u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_0x27;
    communicate_T123_data[2] = 0x02;

    communicate_T123_data[3] = tmp_buff[2];
    communicate_T123_data[4] = tmp_buff[1];//0x15
    communicate_T123_data[5] = veh_soc;
	communicate_T123_data[6] = Veh_trip;
	communicate_T123_data[7] = Veh_trip >> 8;
	communicate_T123_data[8] = Vbat;
	communicate_T123_data[9] = Vbat >> 8;
	
	communicate_T123_data[10] = (SYMBOL_POSITION15|(SYMBOL_POSITION14 << 1));
	SendEnd();
}
void SendPOWER03(u8 initpw)
{
    u16 vol = Battery_System_Volt / 10;
    u16 cur = Battery_Charge_Curr / 10;
	
	SendStart();

    communicate_T123_data[1] = PAGE_0x27;
    communicate_T123_data[2] = 0x03;

    communicate_T123_data[3]   = GetU16Low(vol);
    communicate_T123_data[4]   = GetU16High(vol);
    communicate_T123_data[5]   = GetU16Low(cur);
    communicate_T123_data[6]   = GetU16High(cur);
	SendEnd();
}

static u32 MenuDIS_POWER_MENU(u8 key,u8 initpw)  //松正
{
    static u8 loop = 0;
    if(initpw)
    {
        ChangeToPage(PAGE_0x27);
		SendPOWER01(1);
		SendPOWER02(1);
		SendPOWER03(1);
    }

	switch(loop)
	{
       case 0:
	   	   SendPOWER01(initpw);
		   loop = 1;
	   break;
       case 1:
	   	   SendPOWER02(initpw);
			   loop = 2;
	   break;	
	   case 2:
	   	   SendPOWER03(initpw);
		   loop = 0;
	   break;
	   
	}
	if((!(KEY_CHARGE || KEY_POWER))||KEY_ON||((Ankai_Add_190703.bit.b5 == 1) && PAGE_ON_FLAG))
		return DIS_NOP_MENU;
	else
		return DIS_POWER_MENU;
}





// 相当于display上电后第一个要执行的函数，用于
// 符号片以及背光自检
//一般执行到该函数要么是KEY_ON  要么是KEYPOWER KEYCHARGE等界面
static u32 NopMesg(u8 key,u8 initpw)
{
   static u8 lop = 0,ledtime = 0,flag = 0,waittime = 0;
   
   switch(lop)
   {
      case 0:
	  	    if(KEY_ON)
	  	    {
				lop = 1;
				OPENSYSTEMCHECK = 1;
				ONFlag = 1;
				ledtime = 40;
	  	    }
			else if(KEY_CHARGE||KEY_POWER)//单独充电界面
			{
				ChangeToPage(PAGE_ACC);
				lop = 2;
				waittime = 35;
			}
	  	    break;
	  case 1:
	  	    if(ledtime == 5)
	  	    {
	  	       OPENSYSTEMCHECK = 0;
               ChangeToPage(PAGE_ACC);
               ledtime--;
			}
			else
			{
               if(ledtime > 0)
			   	 ledtime--;
			   else
			   {
                  lop = 3;
				  //return DIS_MAIN_MENU;
			   }
			}
	  	    break;
	  case 2:
	  		if(KEY_ON)
				lop = 0;
			else if(KEY_CHARGE||KEY_POWER)
			{
				if(waittime > 0)
					waittime--;
				else
					return DIS_POWER_MENU;
			}
			else
				ChangeToPage(PAGE_ACC);
	  	    break;
	  case 3:
	  	  	 PAGE_ON_FLAG = 1;//表示已经切换过ON档,此标志位用于后面从POWER切换PARK页面
	  	     if(KEY_ON)
	  	     {
	  	        flag = 0;
				PARK_BUZZZ_FLAG = 0;//此标志位用于从ON切换PARK页面蜂鸣器可响，防止在启动时蜂鸣器误响
			 	return DIS_MAIN_MENU;
	  	     }
			 else if((KEY_CHARGE || KEY_POWER) && (Ankai_Add_190703.bit.b5 != 1))
			 {
			    flag = 0;
				PARK_BUZZZ_FLAG = 0;
			 	return DIS_POWER_MENU;
			 }
			 else if((KEY_CHARGE || KEY_POWER || KEY_ACC) && (Ankai_Add_190703.bit.b5 == 1))
			 {
			    flag = 0;
				PARK_BUZZZ_FLAG = 1;
			 	return DIS_PARK_MENU;
			 }
			 else 
			 {
			   if(flag == 0)
			   {
			     flag = 1;
				 PAGE_ON_FLAG = 0;
				 PARK_BUZZZ_FLAG = 0;
	  	         ChangeToPage(PAGE_ACC);
			   }
			 }
	  	   break;
	  default:
	  	    break;
   }
   
   return DIS_NOP_MENU;
}

enum
{
    meter_nor = 0,
    meter_add,
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



void module_information(uint8_t module)
{
    uint8_t i;
	u16 temp;
    static uint8_t front_module_time = 0,rear_module_time = 0,top_module_time = 0;
    static TYPE_DWORD    pre_bcm_fb_st_f,pre_bcm_fb_st_r,pre_bcm_fb_st_t;     //front bcm feedback states

    static TYPE_WORD     pre_bcm_out_st_f,pre_bcm_out_st_r,pre_bcm_out_st_t;

    static TYPE_WORD     pre_bcm_sw1_f,pre_bcm_sw1_r,pre_bcm_sw1_t;

    static TYPE_BYTE     pre_bcm_sw2_f,pre_bcm_sw2_r,pre_bcm_sw2_t;

    static TYPE_DWORD    front_power_state,middle_power_state,top_power_state;

    if(module == FRONT_MODULE)
    {
        if((FRONT_MAKE_SURE_SEND_INFORMATION == 0) || (pre_bcm_fb_st_f.dword != bcm_fb_st_f.dword)||\
           (pre_bcm_out_st_f.word != bcm_out_st_f.word)||\
           (pre_bcm_sw1_f.word != bcm_sw1_f.word) || (pre_bcm_sw2_f.byte != bcm_sw2_f.byte))
        {

            front_power_state.BIT.b0  = (F_OPEN1_A1 )  ? F_OUT1_A1 : 3;
            front_power_state.BIT.b1  = (F_OPEN3_A2 )  ? F_OUT3_A2 : 3;
            front_power_state.BIT.b2  = (F_OPEN5_A3 )  ? F_OUT5_A3 : 3;
            front_power_state.BIT.b3  = (F_OPEN7_A4 )  ? F_OUT7_A4 : 3;

            front_power_state.BIT.b4  = (F_OPEN9_A5)  ? F_OUT9_A5  : 3;
            front_power_state.BIT.b5  = (F_OPEN11_A6) ? F_OUT11_A6 : 3;
            front_power_state.BIT.b6  = (F_OPEN13_A7) ? F_OUT13_A7 : 3;
            front_power_state.BIT.b7  = (F_OPEN15_A8) ? F_OUT15_A8 : 3;

            front_power_state.BIT.b8  = (F_OPEN2_A9)  ? F_OUT2_A9 : 3;
            front_power_state.BIT.b9  = (F_OPEN4_A10) ? F_OUT4_A10 : 3;
            front_power_state.BIT.b10 = (F_OPEN6_A11) ? F_OUT6_A11 : 3;
            front_power_state.BIT.b11 = (F_OPEN8_A12 ) ? F_OUT8_A12 : 3;

            front_power_state.BIT.b12 = (F_OPEN10_A13) ? F_OUT10_A13 : 3;
            front_power_state.BIT.b13 = (F_OPEN12_A14) ? F_OUT12_A14 : 3;
            front_power_state.BIT.b14 = (F_OPEN14_A42 ) ? F_OUT14_A42 : 3;
			//front_power_state.BIT.b15 = 3;

            FRONT_MAKE_SURE_SEND_INFORMATION = 1;

            pre_bcm_fb_st_f.dword = bcm_fb_st_f.dword;
            pre_bcm_out_st_f.word = bcm_out_st_f.word;
            pre_bcm_sw1_f.word    = bcm_sw1_f.word;
            pre_bcm_sw2_f.byte    = bcm_sw2_f.byte;

            for(i = 1; i < 12; i++)
                communicate_T123_data[i] = 0;

            communicate_T123_data[1] = PAGE_FMODE;
            communicate_T123_data[2] = 0x01;
            communicate_T123_data[3] = front_power_state.byte[0];
            communicate_T123_data[4] = front_power_state.byte[1];
            communicate_T123_data[5] = front_power_state.byte[2];
            communicate_T123_data[6] = front_power_state.byte[3];
            communicate_T123_data[7] = bcm_sw1_f.byte[0];
            communicate_T123_data[8] = bcm_sw1_f.byte[1];
            communicate_T123_data[9] = bcm_sw2_f.byte;

            Transmit_Data_Sci1(communicate_T123_data,12);
        }
        front_module_time++;
        if(front_module_time >= 10)
        {
            front_module_time = 0;
            for(i = 1; i < 12; i++)
                communicate_T123_data[i] = 0;

            communicate_T123_data[1] = PAGE_FMODE;
            communicate_T123_data[2] = 0x02;
			
			//temp = bcm_senor1_f*0.01*Air_Coef;
            communicate_T123_data[3] = bcm_senor1_f;
            communicate_T123_data[4] = bcm_senor1_f >> 8;
			
			//temp = bcm_senor2_f*0.01*Air2_Coef;
            communicate_T123_data[5] = bcm_senor2_f;
            communicate_T123_data[6] = bcm_senor2_f >> 8;
            communicate_T123_data[7] = bcm_frq_f;
            communicate_T123_data[8] = bcm_frq_f >> 8;

            Transmit_Data_Sci1(communicate_T123_data,12);
        }
    }
    else if(module == REAR_MODULE)
    {
        if((REAR_MAKE_SURE_SEND_INFORMATION == 0) || (pre_bcm_fb_st_r.dword != bcm_fb_st_r.dword)||\
           (pre_bcm_out_st_r.word != bcm_out_st_r.word)||\
           (pre_bcm_sw1_r.word != bcm_sw1_r.word) || (pre_bcm_sw2_r.byte != bcm_sw2_r.byte))
        {
            REAR_MAKE_SURE_SEND_INFORMATION = 1;
            middle_power_state.BIT.b0  = (R_OPEN1_A1 == 1)  ? R_OUT1_A1 : 3;
            middle_power_state.BIT.b1  = (R_OPEN3_A2 == 1)  ? R_OUT3_A2 : 3;
            middle_power_state.BIT.b2  = (R_OPEN5_A3 == 1)  ? R_OUT5_A3 : 3;
            middle_power_state.BIT.b3  = (R_OPEN7_A4 == 1)  ? R_OUT7_A4 : 3;

            middle_power_state.BIT.b4  = (R_OPEN9_A5 == 1)  ? R_OUT9_A5  : 3;
            middle_power_state.BIT.b5  = (R_OPEN11_A6 == 1) ? R_OUT11_A6 : 3;
            middle_power_state.BIT.b6  = (R_OPEN13_A7 == 1) ? R_OUT13_A7 : 3;
            middle_power_state.BIT.b7  = (R_OPEN15_A8 == 1) ? R_OUT15_A8 : 3;

            middle_power_state.BIT.b8  = (R_OPEN2_A9 == 1)  ? R_OUT2_A9 : 3;
            middle_power_state.BIT.b9  = (R_OPEN4_A10 == 1) ? R_OUT4_A10 : 3;
            middle_power_state.BIT.b10 = (R_OPEN6_A11 == 1) ? R_OUT6_A11 : 3;
            middle_power_state.BIT.b11 = (R_OPEN8_A12 == 1) ? R_OUT8_A12 : 3;

            middle_power_state.BIT.b12 = (R_OPEN10_A13 == 1) ? R_OUT10_A13 : 3;
            middle_power_state.BIT.b13 = (R_OPEN12_A14 == 1) ? R_OUT12_A14 : 3;
            middle_power_state.BIT.b14 = (R_OPEN14_A42 == 1) ? R_OUT14_A42 : 3;

            pre_bcm_fb_st_r.dword = bcm_fb_st_r.dword;
            pre_bcm_out_st_r.word = bcm_out_st_r.word;
            pre_bcm_sw1_r.word    = bcm_sw1_r.word;
            pre_bcm_sw2_r.byte    = bcm_sw2_r.byte;

            for(i = 1; i < 12; i++)
                communicate_T123_data[i] = 0;

            communicate_T123_data[1] = PAGE_RMODE;
            communicate_T123_data[2] = 0x01;
            communicate_T123_data[3] = middle_power_state.byte[0];
            communicate_T123_data[4] = middle_power_state.byte[1];
            communicate_T123_data[5] = middle_power_state.byte[2];
            communicate_T123_data[6] = middle_power_state.byte[3];
            communicate_T123_data[7] = bcm_sw1_r.byte[0];
            communicate_T123_data[8] = bcm_sw1_r.byte[1];
            communicate_T123_data[9] = bcm_sw2_r.byte;

            Transmit_Data_Sci1(communicate_T123_data,12);
        }
        rear_module_time++;
        if(rear_module_time >= 10)
        {
            rear_module_time = 0;
            for(i = 1; i < 12; i++)
                communicate_T123_data[i] = 0;

            communicate_T123_data[1] = PAGE_RMODE;
            communicate_T123_data[2] = 0x02;
            communicate_T123_data[3] = bcm_senor1_r;
            communicate_T123_data[4] = bcm_senor1_r >> 8;
            communicate_T123_data[5] = bcm_senor2_r;
            communicate_T123_data[6] = bcm_senor2_r >> 8;
            communicate_T123_data[7] = bcm_frq_r;
            communicate_T123_data[8] = bcm_frq_r >> 8;
            Transmit_Data_Sci1(communicate_T123_data,12);
        }
    }
    else if(module == TOP_MODULE)
    {
        if((TOP_MAKE_SURE_SEND_INFORMATION == 0) || (pre_bcm_fb_st_t.dword != bcm_fb_st_t.dword)||\
           (pre_bcm_out_st_t.word != bcm_out_st_t.word)||\
           (pre_bcm_sw1_t.word != bcm_sw1_t.word) || (pre_bcm_sw2_t.byte != bcm_sw2_t.byte))
        {
            TOP_MAKE_SURE_SEND_INFORMATION = 1;
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

            pre_bcm_fb_st_t.dword = bcm_fb_st_t.dword;
            pre_bcm_out_st_t.word = bcm_out_st_t.word;
            pre_bcm_sw1_t.word    = bcm_sw1_t.word;
            pre_bcm_sw2_t.byte    = bcm_sw2_t.byte;

            for(i = 1; i < 12; i++)
                communicate_T123_data[i] = 0;

            communicate_T123_data[1] = PAGE_TMODE;
            communicate_T123_data[2] = 0x01;
            communicate_T123_data[3] = top_power_state.byte[0];
            communicate_T123_data[4] = top_power_state.byte[1];
            communicate_T123_data[5] = top_power_state.byte[2];
            communicate_T123_data[6] = top_power_state.byte[3];
            communicate_T123_data[7] = bcm_sw1_t.byte[0];
            communicate_T123_data[8] = bcm_sw1_t.byte[1];
            communicate_T123_data[9] = bcm_sw2_t.byte;

            Transmit_Data_Sci1(communicate_T123_data,12);
        }
        top_module_time++;
        if(top_module_time >= 10)
        {
            top_module_time = 0;
            for(i = 1; i < 12; i++)
                communicate_T123_data[i] = 0;

            communicate_T123_data[1] = PAGE_TMODE;
            communicate_T123_data[2] = 0x02;
            communicate_T123_data[3] = bcm_senor1_t;
            communicate_T123_data[4] = bcm_senor1_t >> 8;
            communicate_T123_data[5] = bcm_senor2_t;
            communicate_T123_data[6] = bcm_senor2_t >> 8;
            communicate_T123_data[7] = bcm_frq_t;
            communicate_T123_data[8] = bcm_frq_t >> 8;

            Transmit_Data_Sci1(communicate_T123_data,12);
        }
    }
}


void meter_information(void)
{
    uint8_t i;
    static uint8_t meter_time = 0,meterx= 0;
    TYPE_BYTE b2_add;
    meterx++;
    if((meterx&0x03)==0x01)
    {
        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_METER;
        communicate_T123_data[2] = 0x01;
        b2_add.bit.b7 = PTB1;
		b2_add.bit.b6 = PTA19;
		b2_add.bit.b5 = PTA18;
		b2_add.bit.b4 = PTA17;
		b2_add.bit.b3 = PTA10;
		b2_add.bit.b2 = PTA9;
		b2_add.bit.b1 = PTA8;
		b2_add.bit.b0 = PTA7;
        communicate_T123_data[3] = b2_add.byte;

        b2_add.bit.b7 = PTB9;
		b2_add.bit.b6 = PTB8;
		b2_add.bit.b5 = PTB7;
		b2_add.bit.b4 = PTB6;
		b2_add.bit.b3 = PTB5;
		b2_add.bit.b2 = PTB4;
		b2_add.bit.b1 = PTB3;
		b2_add.bit.b0 = PTB2;
        communicate_T123_data[4] = b2_add.byte;

        b2_add.bit.b7 = PTC14;
		b2_add.bit.b6 = PTC13;
		b2_add.bit.b5 = PTC12;
		b2_add.bit.b4 = PTC11;
		b2_add.bit.b3 = PTC10;
		b2_add.bit.b2 = PTB12;
		b2_add.bit.b1 = PTB11;
		b2_add.bit.b0 = PTB10;
        communicate_T123_data[5] = b2_add.byte;

        b2_add.bit.b7 = PTD4;//PTC18
		b2_add.bit.b6 = PTD3;
		b2_add.bit.b5 = PTD2;
		b2_add.bit.b4 = PTD1;
		b2_add.bit.b3 = 0;
		b2_add.bit.b2 = PTC17;	
		b2_add.bit.b1 = PTC16;
		b2_add.bit.b0 = PTC15;	
        communicate_T123_data[6] = b2_add.byte;

        b2_add.bit.b7 = PTD12;
		b2_add.bit.b6 = PTD11;
		b2_add.bit.b5 = PTD10;
		b2_add.bit.b4 = PTD9;
		b2_add.bit.b3 = PTD8;
		b2_add.bit.b2 = PTD7;
		b2_add.bit.b1 = PTD6;
		b2_add.bit.b0 = PTD5;	
        communicate_T123_data[7] = b2_add.byte;

        b2_add.bit.b7 = UNUSED;
		b2_add.bit.b6 = UNUSED;
		b2_add.bit.b5 = UNUSED;
		b2_add.bit.b4 = UNUSED;
		b2_add.bit.b3 = UNUSED;
		b2_add.bit.b2 = UNUSED;
		b2_add.bit.b1 = UNUSED;
		b2_add.bit.b0 = PTD13;	
        communicate_T123_data[8] = b2_add.byte;



        Transmit_Data_Sci1(communicate_T123_data,12);


        METRE_MAKE_SURE_SEND_INFORMATION = 1;
    }
    meter_time++;
    if(meter_time == 5)
    {
        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_METER;
        communicate_T123_data[2] = 0x02;

        communicate_T123_data[3] = meter.MeterA2;
        communicate_T123_data[4] = meter.MeterA2 >> 8;
        communicate_T123_data[5] = meter.MeterA3;
        communicate_T123_data[6] = meter.MeterA3 >> 8;
        communicate_T123_data[7] = meter.MeterA4;
        communicate_T123_data[8] = meter.MeterA4 >> 8;
		communicate_T123_data[9] = SOFT_VERSION;
        Transmit_Data_Sci1(communicate_T123_data,12);
    }
    if(meter_time == 10)
    {
        meter_time = 0;
        for(i = 1; i < 12; i++)
            communicate_T123_data[i] = 0;

        communicate_T123_data[1] = PAGE_METER;
        communicate_T123_data[2] = 0x03;
 
        communicate_T123_data[3] = meter.MeterA5;
        communicate_T123_data[4] = meter.MeterA5 >> 8;
        communicate_T123_data[5] = meter.MeterA13;
        communicate_T123_data[6] = meter.MeterA13 >> 8;
        communicate_T123_data[7] = meter.MeterA14;
        communicate_T123_data[8] = meter.MeterA14 >> 8;
        communicate_T123_data[9] = meter.MeterA15;
        communicate_T123_data[10] = meter.MeterA15 >> 8;

        Transmit_Data_Sci1(communicate_T123_data,12);
    }
}



void Meter_Add_Menu(u8 initpw)
{
    static TYPE_2BIT_BYTE outpower_state;
    SendStart(); 

    communicate_T123_data[1] = PAGE_METER_ADD;
    communicate_T123_data[2] = 0x01;
	
	outpower_state.byte = 0;

    outpower_state.bits.bits3  = (METER_OPEN_WAKE_UP == 1)?METER_OUT_WAKE_UP:3;
    outpower_state.bit.b4 = UNUSED;
    outpower_state.bit.b3 = PTE2;
    outpower_state.bit.b2 = PTD16;
    outpower_state.bit.b1 = PTD15;
    outpower_state.bit.b0 = PTD14;
	
    communicate_T123_data[3] = outpower_state.byte;

    outpower_state.byte = 0;


    outpower_state.bits.bits3  = (METER_OPEN_E8 == 1)  ? METER_OUT_E8 : 3;
    outpower_state.bits.bits2  = (METER_OPEN_E7 == 1)  ? METER_OUT_E7 : 3;
    outpower_state.bits.bits1  = (METER_OPEN_E6 == 1)  ? METER_OUT_E6 : 3;
    outpower_state.bits.bits0  = (METER_OPEN_E3 == 1)  ? METER_OUT_E3 : 3;


    communicate_T123_data[4] = outpower_state.byte ;

	communicate_T123_data[5] = Temp_Vbat;
	communicate_T123_data[6] = Temp_Ranyou;
    SendEnd();
}


u32 ArtMesg(u8 key,u8 initpw)
{
    static u8 flag = 0;
    u8 changescreenflag = 0;

    if(initpw)
    {
        changescreenflag = 1;
    }

    switch(key)
    {
        case IN_KEY2_SP:
            flag++;
            flag = flag>=ARTNum ? meter_nor : flag;
            changescreenflag = 1;
            break;
        case IN_KEY3_SP:
            flag = flag==meter_nor ? ARTNum : flag;
            flag--;
            changescreenflag = 1;
            break;
    }
    if(changescreenflag)
    {
        switch(flag)
        {
            case meter_nor:
                ChangeToPage(PAGE_METER);
                break;
            case meter_add:
                ChangeToPage(PAGE_METER_ADD);
                break;
#if (Has_Fmode == ON)
            case FMode:
                ChangeToPage(PAGE_FMODE);
                break;
#endif

#if (Has_Rmode == ON)
            case RMode:
                ChangeToPage(PAGE_RMODE);
                break;
#endif

#if (Has_Tmode == ON)
            case TMode:
                ChangeToPage(PAGE_TMODE);
                break;

#endif
        }
    }

    switch(flag)
    {
        case meter_nor:
            meter_information();
            break;
        case meter_add:
            Meter_Add_Menu(0);
            break;

#if (Has_Fmode == ON)
        case FMode:
            module_information(FRONT_MODULE);
            break;
#endif

#if (Has_Rmode == ON)
        case RMode:
            module_information(REAR_MODULE);
            break;
#endif

#if (Has_Tmode == ON)
        case TMode:
            module_information(TOP_MODULE);
            break;
#endif
    }

    if(key == IN_KEY1_SP)
    {
        return DIS_CHOOSE_MENU;
    }
    return DIS_ART_INFORMATION;
}



const u8 TV[5] = {TV2,TV1,TV3,TV4,TVNo};
static u8 checkin;

static void vedio_menu_information(uint8_t vedio)
{
    uint8_t i;
    for(i = 1; i < 12; i++)
        communicate_T123_data[i] = 0;

    communicate_T123_data[1] = PAGE_ARTAV;
    communicate_T123_data[2] = vedio;

    Transmit_Data_Sci1(communicate_T123_data,12);
}

static u32 VedioMesg(u8 key,u8 initpw)
{
    static u8 vedio_menu = TV1;

    if(initpw)
    {
        if(ONFlag)
        {
            ChangeToPage(PAGE_ARTAV);
            if(VedioManual >0)
            {
                //手动切换，从TV1开始
                VedioManual = 0;
                vedio_menu = TV1;
                vedio_menu_information(vedio_menu);
            }
            else
            {
                //自动切换，从切换源开始
                vedio_menu = checkin;
                vedio_menu_information(checkin);
            }
        }
    }

    if(key == IN_KEY1_SP)
    {
        return DIS_MAIN_MENU;
    }

    if(key == IN_KEY6_SP)
    {
        vedio_menu++;
        if(vedio_menu > TV4)
        {

            return DIS_MAIN_MENU;
        }
        else
        {
            vedio_menu_information(vedio_menu);
        }
    }
    return DIS_VEDIO;
}



void VedioCheck(void)
{
    u8 i;
    static u8 dis_mod_bak = DIS_MAIN_MENU;  //备份切换前界面

    u8 TVSW[5];
    static u8 count = 0;
#if TV_360
    if(count > 170)
    {
        INITDIS = 0;
    }
    else
    {
        INITDIS = 1;
        count++;
    }

    if(!KEY_ON)
    {
        INITDIS = 0;
        count = 0;
    }
#endif
    TVSW[0] = TV1_REVERSE_SW     ;
    TVSW[1] = TV2_REAR_DOOR_SW   ;
    TVSW[2] = TV3_FRONT_DOOR_SW  ;
    TVSW[3] = TV4_MIDDLE_DOOR_SW ;

    TVSW[4] = (!(TVSW[0]||TVSW[1]||TVSW[2]||TVSW[3]));

    for(i=0; i<5; i++)
    {
        if((TVSW[i]>0))
        {
            if((checkin != TV[i])) //保证只触发一次
            {
                checkin = TV[i];

                VedioManual = 0;  //自动切换到视屏界面标志

                if(checkin == TVNo)
                {
                    dis_mod = dis_mod_bak;
                    initflag = 1;
                }
                else
                {
                    if(dis_mod == DIS_VEDIO)
                        dis_mod_bak = DIS_MAIN_MENU;
                    else
                        dis_mod_bak = dis_mod;

                    dis_mod = DIS_VEDIO;
                    initflag = 1;
                }
            }
            break;
        }
    }

}


u16 GetWenziWarnCode(u16 alarm_count)
{
    u8 temp = 0;
    u8 index = 0,taiya_lin;

    if((alarm_count>= 150) && (alarm_count<=167))
    {
        index = (alarm_count-150)/3;
        if(errcodemix[index] != 0xFF)
        {
            temp = errcodemix[index];
            errcodemix[index] = 0xFF;
            return temp;
        }
    }
	else if((alarm_count > 0xdc) && (alarm_count < 0xe0))
	{
		if(errcodemix[6] != 0xFF)
        {
            temp = errcodemix[6];
            errcodemix[6] = 0xFF;
            return temp;
        }
	}
	else if((alarm_count > 0xc8) && (alarm_count < 0xcF))
	{
		return ID_18FF2A48_data5; 

	}
    return 0;
}


void roll_alarm(void)
{
    uint8_t i;
    uint8_t alarm_count = 0xFF;
    static  uint16_t x = 0;
	u16 code = 0;
    u64 data[4];
	u64 temp;

    for(i = 1; i < 12; i++)
        communicate_T123_data[i] = 0;

    communicate_T123_data[1] = 0x80;
    communicate_T123_data[2] = 0x01;


		
    data[0] = tip_code1.qword;
    data[1] = tip_code2.qword;
    data[2] = tip_code3.qword;
    data[3] = tip_code4.qword;


    for(i = 0; i< (sizeof(data)/sizeof(data[0])); i++)
    {
        if(data[i] != 0)
            break;
    }

    if(i==(sizeof(data)/sizeof(data[0])))
    {
        goto end;
    }

    for(; x<(sizeof(data)*8); x++)
    {

        if(((data[x>>6]>>(x&(0x3F)))&0x01) == 0x01)
        {
            alarm_count = x;
            x++;
            break;
        }

    }

end:

    communicate_T123_data[3] = (u8)alarm_count;
	
	code = GetWenziWarnCode(alarm_count);
	communicate_T123_data[5] = GetU16Low(code);
	communicate_T123_data[6] = GetU16High(code);

    communicate_T123_data[7] = Veh_trip;
    communicate_T123_data[8] = Veh_trip >> 8;

    Transmit_Data_Sci1(communicate_T123_data,12);

    if(alarm_count == 0xFF)
    {
        x = 0;
    }

}


void roll_alarm_Task(void) //200ms
{
    if((KEY_ON&&(ONFlag)) || KEY_CHARGE|| KEY_POWER)
    {
        roll_alarm();
    }
}


u32 MenuDIS_EP_MENU(u8 key,u8 initpw)
{
    if(initpw)
    {
        ChangeToPage(PAGE_0x2B);
    }
    if(!EP_ENABLE)
	  return DIS_MAIN_MENU;
	else
      return DIS_EP_MENU;
}

u32 MenuDIS_YOUMEN_MENU(u8 key,u8 initpw)
{
    if(initpw)
    {
        ChangeToPage(PAGE_0x2A);
    }
    if(!YOUMEN_ENABLE)
	  return DIS_MAIN_MENU;
	else
      return DIS_YOUMEN_MENU;
}


u32 MenuDIS_PARK_MENU(u8 key,u8 initpw)
{
   static uint8_t falg = 0xff;
   if(initpw)
   {
     ChangeToPage(PAGE_0x28); 
   }
   
   /*if(falg != Ankai_Add_190703.bit.b5)
   {
     falg = Ankai_Add_190703.bit.b5;
	 if(falg)
	 	ChangeToPage(PAGE_0x28); 
	 else
	 	ChangeToPage(PAGE_0x29); 
   }*/
   

   

	if(KEY_ON||(Ankai_Add_190703.bit.b5 == 0))
		return DIS_NOP_MENU;
	else
		return DIS_PARK_MENU;

}





typedef struct
{
    u32 (*operate)(u8 key, u8 initpw);
    uint16_t id;
    uint16_t rever;
} DisMenuStruct;

DisMenuStruct disp[MAXDISMENU];



void display_task(void) //100ms
{
    u8 i,key;
    u32 lastmode;

	VedioCheck();

    if(KEY_ON)
      key = message_get(MSG_FIFO_KEY);

    for(i=0; i<MAXDISMENU; i++)
    {
        if((disp[i].operate != 0) && (disp[i].id == dis_mod))
        {
            lastmode = dis_mod;
            dis_mod = (*disp[i].operate)(key,initflag);
            initflag = 0;
            if(dis_mod != lastmode)
                initflag = 1;
            break;
        }
    }
    if(!KEY_ON && ((dis_mod >= DIS_HELP_MENU) && ((dis_mod <= DIS_CHOOSE_MENU))))
    {
       if(HANDANOSCREENFORNOPOWER == 0)
       {
          dis_mod = DIS_MAIN_MENU;
		  HANDANOSCREENFORNOPOWER = 1;
	   }
	}
	else if(KEY_ON)
		 HANDANOSCREENFORNOPOWER = 0;
	
    if(i == MAXDISMENU)
        dis_mod = DIS_CHOOSE_MENU;

}

void InitDispStru()
{
    u8 i = 0;
    for(i=0; i<MAXDISMENU; i++)
    {
        disp[i].operate = 0;
    }
}


u32 MenuNum = 0;
void AddMenu(u32 (*operate)(u8 key, u8 initpw),u32 id)
{
    DisMenuStruct * p;
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
//	InitDispVar();
    InitDispStru();

    AddMenu(MainMesg,              DIS_MAIN_MENU);
    AddMenu(MenuMesg,              DIS_CHOOSE_MENU);
    AddMenu(HelpMesg,              DIS_HELP_MENU);
    AddMenu(NoEncryptSystemSet,    DIS_FACTORY_SET_MENU);
	AddMenu(EncryptSystemSet,	   DIS_SYSTEM_SET_MENU);

    AddMenu(MenuDIS_SELFTEST_MENU, DIS_SELFTEST_MENU);
    AddMenu(ArtMesg,               DIS_ART_INFORMATION);
    AddMenu(VedioMesg,             DIS_VEDIO);

	//上电默认执行
    AddMenu(NopMesg,               DIS_NOP_MENU);
	//EP误操作
    AddMenu(MenuDIS_EP_MENU,       DIS_EP_MENU);
	//油门提醒
    AddMenu(MenuDIS_YOUMEN_MENU,   DIS_YOUMEN_MENU);
	#if ANKAI_ADD_SCREEC_FOR_PARK
	AddMenu(MenuDIS_PARK_MENU,     DIS_PARK_MENU);
	#endif
	//充电/总电源开关页面
	AddMenu(MenuDIS_POWER_MENU,     DIS_POWER_MENU);
	//协议
	AddAnkaiMenu();
}

uint8_t symbol_one = 0;

void SendPAGE_MAIN04(u8 initpw);
void SendPAGE_MAIN05(u8 initpw);
void SendPAGE_MAIN06(u8 initpw);

void HightLightSymbl(void)
{
   uint8_t i = 0;
   for(i = 0;i < 4;i++)
   	DisplaySymbol[i].byte = 0xff;
   SYMBOL_POSITION21 = 0;
}
static void Display_Symbol_Information(u8 initpw)
{
    SendStart();
    if(symbol_one < 5)
    {
        HightLightSymbl();
        initpw = 0;
        symbol_one++;
    }

    communicate_T123_data[1] = PAGE_MAIN;
    communicate_T123_data[2] = 1;

	for(i = 0;i < 8;i++)
       communicate_T123_data[3 + i] = DisplaySymbol[i].byte;


    SendEnd();

}

uint8_t tmp_buff[7];

void display_time_bar_soc(u8 initpw)
{
    SendStart();
    communicate_T123_data[1] = PAGE_MAIN;
    communicate_T123_data[2] = 3;
    communicate_T123_data[3] = tmp_buff[5];
    communicate_T123_data[4] = tmp_buff[4];
    communicate_T123_data[5] = tmp_buff[3];
    communicate_T123_data[6] = tmp_buff[2];
    communicate_T123_data[7] = tmp_buff[1];//0x15


    communicate_T123_data[8] = veh_bar1;
    communicate_T123_data[9] = veh_bar2;
    communicate_T123_data[10] = veh_soc;

    SendEnd();
}

void display_total_miles(u8 initpw)
{
    SendStart();

    communicate_T123_data[1] = PAGE_MAIN;
    communicate_T123_data[2] = 2;

    if(Veh_odo >= 10000000)
        Veh_odo = 0;
    communicate_T123_data[3] = Veh_odo/1000000;
    communicate_T123_data[4] = (Veh_odo%1000000)/100000;
    communicate_T123_data[5] = (Veh_odo%100000)/10000;
    communicate_T123_data[6] = (Veh_odo%10000)/1000;
    communicate_T123_data[7] = (Veh_odo%1000)/100;
    communicate_T123_data[8] = (Veh_odo%100)/10;
    communicate_T123_data[9] =  Veh_odo%10;

    SendEnd();
    //SendEndPlus(20);
}

void Main_Data(u8 initpw)
{
    static u8 loop = 0;
	switch(loop)
	{
      case 0:
	  	    SendPAGE_MAIN04(initpw);
	  	    break;
      case 1:
	        SendPAGE_MAIN05(initpw);
	        break;		
	  case 2:
	        SendPAGE_MAIN06(initpw);
	        break;		
	}
    loop++;
	if(loop > 2)
		loop = 0;
}



//主界面显示数据
void Main_Send(u8 initpw)
{
    static u8 lop = 0;
	
    Display_Symbol_Information(initpw);
	switch(lop)
	{
       case 1:
		display_time_bar_soc(initpw);
	   	     break;
	   case 2: 	
		Main_Data(initpw);
	   	     break;
	   case 3:	
		display_total_miles(initpw);
	   	     break;
	   default:
	   	     break;
	}
	lop++;
	if(lop > 3)
		lop = 1;
}


void SendPAGE_MAIN04(u8 initpw)
{
    u16 vol = Battery_System_Volt / 10;
    u16 cur = Battery_Charge_Curr / 10;

    //PeriodSendStart(4,10);
	SendStart();

    communicate_T123_data[1] = PAGE_MAIN;
    communicate_T123_data[2] = 0x04;

    communicate_T123_data[3]   = GetU16Low(vol);
    communicate_T123_data[4]   = GetU16High(vol);
    communicate_T123_data[5]   = GetU16Low(cur);
    communicate_T123_data[6]   = GetU16High(cur);
    communicate_T123_data[7]   = GetU16Low(Battery_High_Volt);
    communicate_T123_data[8]   = GetU16High(Battery_High_Volt);
    communicate_T123_data[9]   = GetU16Low(Battery_Low_Volt);
    communicate_T123_data[10]  = GetU16High(Battery_Low_Volt);
	SendEnd();

    //PeriodSendEnd();
}

void SendPAGE_MAIN05(u8 initpw)
{
    u16 temp;
	SendStart();

    communicate_T123_data[1] = PAGE_MAIN;
    communicate_T123_data[2] = 0x05;

    communicate_T123_data[3]   = GetU16Low(Drive_mile);  
    communicate_T123_data[4]   = GetU16High(Drive_mile);
    communicate_T123_data[5]   = fuel_percent;

	SendEnd();

}


void SendPAGE_MAIN06(u8 initpw)
{
    u8 temp;
    //PeriodSendStart(4,5);
	SendStart();

    communicate_T123_data[1] = PAGE_MAIN;
    communicate_T123_data[2] = 0x06;
	temp = (_0CFF0D4A[4]*0.8);
	if(temp > 100)
	{
		communicate_T123_data[3]  = temp - 100;
		communicate_T123_data[4]  = 0;
	}
	else
	{
		communicate_T123_data[3]  = 0;
		communicate_T123_data[4]  = 100 - temp;
	}
    communicate_T123_data[5]   = _0CFF0C4A[4];
    communicate_T123_data[6]   = _0CFF0C4A[5];  

    communicate_T123_data[7]   = Aver_Dianhao;
	if(eng_speed > 50)
 		communicate_T123_data[8]   = 1;
	else
		communicate_T123_data[8]   = 0;
	communicate_T123_data[9]   = (_0CFF0D4A[4]*0.8); //功率百分比


   SendEnd();
}





