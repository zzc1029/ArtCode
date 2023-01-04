/*
 * EElogic.c
 *
 *  Created on: 2022-5-11
 *      Author: ART
 */

#include "system_init.h"
#include "ZD240Cx.h"
#include "EElogic.h"


EEDataStru eeodo;
EEParaStru eepara;
EECan      CanSetEEByte;

TYPE_BYTE  EEflag;


#define GetU32LE(x,y)  GetU32LEData(x[y],x[y + 1],x[y + 2],x[y + 3])

#define Shiftright(data,n)  ((data >> n)&0xff)

#define GetU32L0BYTE(data)  (Shiftright(data,0)  & 0xff)
#define GetU32L1BYTE(data)  (Shiftright(data,8)  & 0xff)
#define GetU32L2BYTE(data)  (Shiftright(data,16) & 0xff)
#define GetU32L3BYTE(data)  (Shiftright(data,24) & 0xff)

u8 EEOdoDataPlus(u8 *data,u8 len)
{
  u8 i,sum = 0;
  for(i = 0;i < (len - 1);i++)
  	sum += data[i];
  return (sum + ODONUM);
}

u8 EEDataPlus(u8 *data,u8 len)
{
  u8 i,sum = 0;
  for(i = 0;i < (len - 1);i++)
  	sum += data[i];
  return (sum + PARANUM);
}


void WriteMainOdo(void)
{
 // DisableIRQ();   
  ZD24c0xWritePage(BACKUPMILEPAGE,eeodo.data8);   
  //DelayKong(500,500);//����д����ʱʾ�����鿴ԼΪ30ms����������д��
  //DelayKong(400,400);//����д����ʱʾ�����鿴ԼΪ20ms����������д��
  //DelayKong(300,300);//����д����ʱʾ�����鿴ԼΪ10ms����������д��
  //DelayKong(200,200);//����д����ʱʾ�����鿴ԼΪ5ms����������д��
  DelayKong(400,400);//��ʱԼ10ms����������д��
  ZD24c0xWritePage(MAINMILEPAGE,eeodo.data8);
  DelayKong(400,400);//��ʱԼ10ms����������д��
 // EnableIRQ();
}



void ZD24C0xReadVehodo(void)
{
   u32 miles;
   ZD24c0xReadPage(MAINMILEPAGE,eeodo.data8);
   miles = GetU32LE(eeodo.data8,0);
   if(miles == DEFAULTDATA)
   {
      Veh_odo = 0;
	  Veh_trip = 0;
	  eeodo.Data.odo = Veh_odo;
	  eeodo.Data.trip = Veh_trip;
	  eeodo.Data.checksum =  EEOdoDataPlus(eeodo.data8,sizeof(eeodo.data8));
	  DelayKong(400,400);//��ʱԼ10ms����������д��
	  WriteMainOdo();
	  DelayKong(400,400);//��ʱԼ10ms����������д��
   }
   else
   {
      //checksum pass
      if(eeodo.Data.checksum == EEOdoDataPlus(eeodo.data8,sizeof(eeodo.data8)))
      {
         Veh_odo  = GetU32LE(eeodo.data8,0);
		 Veh_trip = GetU16LE(eeodo.data8,4);
	  }
	  else
	  {
        ZD24c0xReadPage(BACKUPMILEPAGE,eeodo.data8);
		DelayKong(400,400);//��ʱԼ10ms����������д��
		if(eeodo.Data.checksum == EEOdoDataPlus(eeodo.data8,sizeof(eeodo.data8)))
		{
           Veh_odo  = GetU32LE(eeodo.data8,0) + 1;  // + 1????
		   Veh_trip = GetU16LE(eeodo.data8,4);
		   eeodo.Data.odo = Veh_odo;
	       eeodo.Data.trip = Veh_trip;
		   ZD24c0xWritePage(MAINMILEPAGE,eeodo.data8);
		}
		else
		{
			Veh_odo = SETODO;
			Veh_trip = SETTRIP;
			eeodo.Data.odo = Veh_odo;
	        eeodo.Data.trip = Veh_trip;
			eeodo.Data.checksum =  EEOdoDataPlus(eeodo.data8,sizeof(eeodo.data8));
			DelayKong(400,400);//��ʱԼ10ms����������д��
			WriteMainOdo();
		}
	  }
   }
   //if(Veh_odo < Veh_trip)
   //	Veh_trip = 0;
}


 EEParaStru EEConstInit =
{
	.Data.Switch.b0 = 1,
	.Data.Switch.b1 = 1,
	.Data.Switch.b2 = 1,
	.Data.Switch.b3 = 1,
	.Data.Switch.b4 = 1,
	.Data.Switch.b5 = 1,
	.Data.Switch.b6 = 1,
	.Data.Switch.b7 = 1,
	.Data.backlight = 5,
	.Data.pulse =PULSE,
	.Data.subi = SUBI,
	.Data.trip = 0,
	.Data.coef = COEF,

	.Data.video.b0 = VIDEO_GEAR,
	.Data.video.b1 = VIDEO_MID_DOOR,
	.Data.video.b2 = VIDEO_FRO_DOOR,
	.Data.video.b3 = VIDEO_ELSE,

	.Data.air_alarm = AIR_ALARM,
	.Data.speed_alarm = SPEED_ALARM,
	.Data.oil_alarm   = OIL_ALARM,
	.Data.ranyou_alarm = RANYOU_ALARM,
	.Data.air_coef     = AIR1_COEF,
	.Data.air2_coef    = AIR2_COEF,
	.Data.fuel_coef    = FUEL_COEF,
	.Data.rain_time    = RAIN_TIME,
//	.Data.coef_2012    = COEF,
//	.Data.subi_2012    = SUBI,
//	.Data.checksum     =  EEDataPlus(eeodo.data8,,sizeof(eeodo.data8)),
};

//EEPROM������ӳ��ȫ�ֱ���

void EEGiveParaToData(void)
{
   	VIDEO_AV_GRAR    = eepara.Data.Switch.b0; 
	VIDEO_AV_MID     = eepara.Data.Switch.b1; 
	VIDEO_AV_FRO     = eepara.Data.Switch.b2; 
	VIDEO_AV_ELSE    = eepara.Data.Switch.b3;
	RAIN_STATE       = eepara.Data.Switch.b4;
    BUZZ_NORMAL_WORK = eepara.Data.Switch.b5;
    Bus_Type         = eepara.Data.Switch.b6;
	//LANGUAGE_STATUS  = eepara.Data.Switch.b7;

	Air_Alarm        = eepara.Data.air_alarm; 
    Speed_Alarm      = eepara.Data.speed_alarm; 
	Oil_Alarm        = eepara.Data.oil_alarm;
	Ranyou_Alarm     = eepara.Data.ranyou_alarm; 
	Air_Coef         = eepara.Data.air_coef; 
    Air2_Coef        = eepara.Data.air2_coef;
	Fuel_Coef        = eepara.Data.fuel_coef; 
	Rain_Delay_Time  = eepara.Data.rain_time;
    Coef             = eepara.Data.coef;
    Pulse            = eepara.Data.pulse;
    backlight_level  = eepara.Data.backlight;	
	odometer_const   = eepara.Data.subi;
	//-------------------

    //Veh_trip         = MeterPara.Data.trip;
}

void EESaveDataToMeter(void)
{
	eepara.Data.Switch.b0 = VIDEO_AV_GRAR; 
	eepara.Data.Switch.b1 = VIDEO_AV_MID; 
	eepara.Data.Switch.b2 = VIDEO_AV_FRO; 
	eepara.Data.Switch.b3 = VIDEO_AV_ELSE;
	eepara.Data.Switch.b4 = RAIN_STATE;
	eepara.Data.Switch.b5 = BUZZ_NORMAL_WORK;
	eepara.Data.Switch.b6 = Bus_Type;
	//eepara.Data.Switch.b7 = LANGUAGE_STATUS;

	
	eepara.Data.air_alarm	= Air_Alarm; 
	eepara.Data.speed_alarm	= Speed_Alarm; 
	eepara.Data.oil_alarm	= Oil_Alarm;
	eepara.Data.ranyou_alarm = Ranyou_Alarm; 
	eepara.Data.air_coef 	= Air_Coef; 
	eepara.Data.air2_coef	= Air2_Coef;
	eepara.Data.fuel_coef	= Fuel_Coef; 
	eepara.Data.rain_time	= Rain_Delay_Time;;
	eepara.Data.coef         = Coef;
	eepara.Data.pulse		= Pulse;
	eepara.Data.backlight	= backlight_level;
	eepara.Data.subi         = odometer_const;
    //MeterPara.Data.trip         = Veh_trip;
	//#if (PARACHECKEN == USED)
	eepara.Data.checksum = EEDataPlus(eepara.data8,sizeof(eepara.data8));
	//#endif
}


void ZD24C0xReadMeterPara(void)
{
   u8 i;
   ZD24c0xReadPages(MAINPARAPAGEL,eepara.data8,2);
   if(eepara.Data.backlight == 0xff)
   {
      CopyData(eepara.data8,EEConstInit.data8,sizeof(EEConstInit));
	  eepara.Data.checksum = EEDataPlus(eepara.data8,sizeof(eepara.data8));
	  EEGiveParaToData();
	  ZD24c0xWritePage(BACKUPPARAPAGEL,eepara.data8);
	  DelayKong(300,300);
	  ZD24c0xWritePage(BACKUPPARAPAGEH,eepara.data8 + 16);
	  DelayKong(300,300);
	  ZD24c0xWritePage(MAINPARAPAGEL,eepara.data8);
	  DelayKong(300,300);
	  ZD24c0xWritePage(MAINPARAPAGEH,eepara.data8 + 16);
	  DelayKong(300,300);
   }
   else
   {
      if(eepara.Data.checksum == EEDataPlus(eepara.data8,sizeof(eepara.data8)))
      {
		  EEGiveParaToData();
	  }
	  else
	  {
        ZD24c0xReadPages(BACKUPPARAPAGEL,eepara.data8,2);
		if(eepara.Data.checksum == EEDataPlus(eepara.data8,sizeof(eepara.data8)))
		{
           EEGiveParaToData();
		   ZD24c0xWritePage(MAINPARAPAGEL,eepara.data8);
	       DelayKong(300,300);
	       ZD24c0xWritePage(MAINPARAPAGEH,eepara.data8 + 16);
		}
		else
		{
			CopyData(eepara.data8,EEConstInit.data8,sizeof(EEConstInit));
			eepara.Data.checksum = EEDataPlus(eepara.data8,sizeof(eepara.data8));
			EEGiveParaToData();
			ZD24c0xWritePage(BACKUPPARAPAGEL,eepara.data8);
			DelayKong(300,300);
			ZD24c0xWritePage(BACKUPPARAPAGEH,eepara.data8 + 16);
			DelayKong(300,300);
			ZD24c0xWritePage(MAINPARAPAGEL,eepara.data8);
			DelayKong(300,300);
			ZD24c0xWritePage(MAINPARAPAGEH,eepara.data8 + 16);
			DelayKong(300,300);
		}
	  }
   }
}

EEstep step = EENOP;
u8 checksum;

void WriteEE(void)
{
  u8 errorback[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
  switch(step)
  {
    case EENOP:
		     if(EEODOFLAG)
		     {
		       eeodo.Data.odo = Veh_odo;
			   eeodo.Data.trip = Veh_trip;
			   eeodo.Data.checksum = EEOdoDataPlus(eeodo.data8,sizeof(eeodo.data8));
			   step = EEBACKUPODO;
		     }
			 else if(EEPARAFLAG)
			 {
			    EESaveDataToMeter();
			 	step = EEBACKPARAL;
			 }
			 else if(EECANFLAG)
			 {
			    checksum = EEDataPlus(CanSetEEByte.data8,sizeof(CanSetEEByte.data8));
                if((CanSetEEByte.Data.addr < 0x400) && (CanSetEEByte.Data.checksum ==  checksum))
                {
                   if(CanSetEEByte.Data.cmd == EEWRITECMD)
                   {
                      ZD24c0xWriteByte(CanSetEEByte.Data.addr,CanSetEEByte.Data.setdata);
					  step = EECANSETBACK;
                   }
				   else if(CanSetEEByte.Data.cmd == EEREADCMD)
				   {
					  CanSetEEByte.Data.resv[0] = ZD24c0xReadByte(CanSetEEByte.Data.addr);
					  step = EECANSETBACK;
				   }
				   else
				   {
					  EECANFLAG = 0;
					  errorback[0] = 0xfe;//д���ȡ�������
					  CanSetEEByte.Data.checksum = EEDataPlus(CanSetEEByte.data8,sizeof(CanSetEEByte.data8));
					  //Can0_Tx_Standard_Bytes(0x540,errorback,8);
					  BCan_Standard_Tx_Bytes(0x540,errorback,8);
				   }
				}
				else
				{
					EECANFLAG = 0;
					if((CanSetEEByte.Data.addr > 0x400))
					   errorback[0] = 0xfd;//д���ַ��������ַ
					else
					   errorback[0] = 0xfc;//0x540�������У�鲻ͨ��
					CanSetEEByte.Data.checksum = EEDataPlus(CanSetEEByte.data8,sizeof(CanSetEEByte.data8));   
					//Can0_Tx_Standard_Bytes(0x540,errorback,8);
					BCan_Standard_Tx_Bytes(0x540,errorback,8);
				}
			 }
			 
		 break;
	case EEBACKUPODO:
		 ZD24c0xWritePage(BACKUPMILEPAGE,eeodo.data8);
		 step = EEMAINODO;
		 break;
	case EEMAINODO:
		 ZD24c0xWritePage(MAINMILEPAGE,eeodo.data8);
		 if(EEODOFLAG)
		 	EEODOFLAG = 0;
		 step = EENOP;
		 break;
	case EEBACKPARAL:
		 ZD24c0xWritePage(BACKUPPARAPAGEL,eepara.data8);
		 step = EEBACKPARAH;
		 break;
	case EEBACKPARAH:
		 ZD24c0xWritePage(BACKUPPARAPAGEH,eepara.data8 + 16);
		 step = EEMAINPARAL;
		 break;
	case EEMAINPARAL:
		 ZD24c0xWritePage(MAINPARAPAGEL,eepara.data8);
		 step = EEMAINPARAH;
		 break;
	case EEMAINPARAH:
		 ZD24c0xWritePage(MAINPARAPAGEH,eepara.data8 + 16);
		 if(EEPARAFLAG)
		 	EEPARAFLAG = 0;
		 step = EENOP;
		 break;	
	//case EECANSETBYTE:
	//	 ZD24c0xWriteByte(CanSetEEByte.Data.addr,CanSetEEByte.Data.setdata);
	//	 step = EECANSETBACK;
	//	 break;
	case EECANSETBACK:
		 if(CanSetEEByte.Data.cmd == EEWRITECMD)
		 {
		   CanSetEEByte.Data.resv[0] = ZD24c0xReadByte(CanSetEEByte.Data.addr);
		   if(CanSetEEByte.Data.resv[0] == CanSetEEByte.Data.setdata)
		   {
		     CanSetEEByte.Data.resv[0] = 0;
			 CanSetEEByte.Data.checksum = EEDataPlus(CanSetEEByte.data8,sizeof(CanSetEEByte.data8));
             //Can0_Tx_Standard_Bytes(0x540,CanSetEEByte.data8,8);
			 BCan_Standard_Tx_Bytes(0x540,CanSetEEByte.data8,8);
		   }
		   else
		   {
		      errorback[0]= 0xfb;//д��������õ�ַ��ȡ��һ��
		      CanSetEEByte.Data.checksum = EEDataPlus(CanSetEEByte.data8,sizeof(CanSetEEByte.data8));
              //Can0_Tx_Standard_Bytes(0x540,errorback,8);
			  BCan_Standard_Tx_Bytes(0x540,errorback,8);
		   }
		 }
		 else if(CanSetEEByte.Data.cmd == EEREADCMD)
		 {
            CanSetEEByte.Data.resv[1] = ZD24c0xReadByte(CanSetEEByte.Data.addr);
			if(CanSetEEByte.Data.resv[1] == CanSetEEByte.Data.resv[0])
			{
			    CanSetEEByte.Data.setdata = CanSetEEByte.Data.resv[0];
				CanSetEEByte.Data.resv[0] = 0;
				CanSetEEByte.Data.resv[1] = 0;
				CanSetEEByte.Data.checksum = EEDataPlus(CanSetEEByte.data8,sizeof(CanSetEEByte.data8));
				//Can0_Tx_Standard_Bytes(0x540,CanSetEEByte.data8,8);
				BCan_Standard_Tx_Bytes(0x540,CanSetEEByte.data8,8);
			}
			else
			{
		       errorback[0]= 0xfa;//�����������ζ�ȡ���ݲ�һ��
		       CanSetEEByte.Data.checksum = EEDataPlus(CanSetEEByte.data8,sizeof(CanSetEEByte.data8));
               //Can0_Tx_Standard_Bytes(0x540,errorback,8); 
			   BCan_Standard_Tx_Bytes(0x540,errorback,8); 
			}
		 }		 
		 EECANFLAG = 0;
		 step = EENOP;
		 break;
  }
  
}


u8 eeall[1024];
void ReadAllZD24c0x(void)
{
  ZD24c0xReadAllPages(0,eeall);
}






