/*
 * eeprom.c
 *
 *  Created on: 2021-8-7
 *      Author: ART
 */
#include "system_init.h"
#include "flash.h"

//用于擦除数据 1K
//FLASH_Wipe_Configuration_RAM (uint32_t WipeMode,uint32_t WipeAddr);
//用于写入4字节
//void FLASH_WriteWord(uint32_t address,uint32_t p_FlashBuffer);    //写word
//读出4个字节数据
//uint32_t FLASH_ReadWord(uint32_t address,uint32_t *p_FlashBuffer);//读Word

uint8_t     Air_Alarm,Speed_Alarm,Oil_Alarm,Ranyou_Alarm,Air_Coef,Air2_Coef,Coef,Oil_Alarm_2012;
uint8_t     Rain_Delay_Time,Fuel_Coef;
uint8_t     backlight_level,Bus_Type;
uint16_t    odometer_const,odometer_const_2012,Pulse,Pulse_const_2012;

uint8_t     Set_Air_Alarm,Set_Speed_Alarm,Set_Oil_Alarm,Set_Ranyou_Alarm,Set_Air_Coef,Set_Air2_Coef,Set_Coef;
uint8_t     Set_Rain_Delay_Time,Set_Fuel_Coef;
uint8_t     Set_backlight_level,Set_Bus_Type;
uint16_t    Set_odometer_const,Set_odometer_const_2012,Set_Pulse;
uint8_t     Set_buzz,Coef_2012;


//1 写入总里程
#define WTIRE_VEHODO(ADD,DATA)   FLASH_WriteWord(ADD,DATA)

//里程保存起始地址
uint32_t  mileaddress = EEPROMMILEADDR;

void EraseMile(void);



//写入两个32位数据
uint32_t WriteDlong(uint32_t address,uint32_t data1,uint32_t data2)
{
    uint64_t  temp ;
	temp = data1 + ((uint64_t)data2 << 32);
	FLASH_WriteWord(address,temp);
	address = address + 8;
    return address;
}

// 读取一个
uint32_t  ReadAdd(uint32_t address)
{
	uint32_t returndata = 0,data = 0;
	returndata = FLASH_ReadWord(address,&data);
	return returndata;
}

void GetMile(uint32_t address)
{
    uint32_t data[2];
	FLASH_READCODE_fun(address,data,2);
    Veh_odo = data[0];
	Veh_trip = data[1];
}

// 写入总里程数据
uint32_t SaveVehodo(void)
{
    //写入里程到最尾端地址数据
    if(mileaddress >= MILEENDADDR)
    {
        //擦除备用区
	    ERASEPAGE(EEPROMMILECHECKADDR);
        //FLASH_WriteWord(EEPROMMILECHECKADDR,Veh_odo); 
		WriteDlong(EEPROMMILECHECKADDR,Veh_odo,Veh_trip);
		EraseMile();//擦除16K空间
	    mileaddress = EEPROMMILEADDR;
		//FLASH_WriteWord(mileaddress,Veh_odo); 
		WriteDlong(mileaddress,Veh_odo,Veh_trip);
		mileaddress = mileaddress + 8;
		ERASEPAGE(EEPROMMILECHECKADDR);
	}
	else
	{
       //FLASH_WriteWord(mileaddress,Veh_odo);
	   WriteDlong(mileaddress,Veh_odo,Veh_trip);
	   mileaddress = mileaddress + 8;
	}
	return mileaddress;
}

//擦除里程空间
void EraseMile(void)
{
   uint32_t odoadd = EEPROMMILEADDR,i = 0,delay = 5000;
   for(i = 0;i < 16;i++)
   {
       delay = 5000;
       ERASEPAGE(odoadd);
	   odoadd = odoadd + 0x400;
	   while(delay > 0)
	   	delay--;
   }
}

uint32_t odoadd = EEPROMMILEADDR;
uint64_t miles = 0;

// 读取总里程数据
uint32_t ReadVehodo(void)
{
   //读取备份FLASH中总里程数据，如果有数据直接擦除
   miles = ReadAdd(EEPROMMILECHECKADDR);
   if(miles == DEFAULTDATA)
   {    
      for(odoadd = EEPROMMILEADDR; odoadd < MILEENDADDR;)
      {
         miles = 0;
         miles = ReadAdd(odoadd);
	     if(miles == DEFAULTDATA)
	     {
           break;
	     }
	     else
	       odoadd = odoadd + 8;
      }   
	  if(odoadd == EEPROMMILEADDR)
	  {
         Veh_odo = 0;
		 Veh_trip = 0;
		 mileaddress = odoadd;
	     //写入里程数据
	     mileaddress = SaveVehodo();		 
	  }
	  else
	  {
		  //miles = ReadAdd(odoadd - 8);
		  GetMile(odoadd - 8);
          //Veh_odo = miles;
		  //Veh_trip = (miles >> 32)&0xffff; 
		  mileaddress = odoadd ;
	  }
	//  Veh_odo = miles;
	//  mileaddress = odoadd;
   }
   else
   {
     //有数据，擦除16K空间数据，写入总里程，再擦除备份区域
     EraseMile();//擦除16K空间
     //Veh_odo = miles;
	 //Veh_trip = (miles >> 32)&0xffff; 
	 mileaddress = EEPROMMILEADDR;
	 //写入里程数据
	 mileaddress = SaveVehodo();
	 //擦除备用区
	 ERASEPAGE(EEPROMMILECHECKADDR);
   }
}


/****************以上为总里程处理，下面仪表参数处理*************************************/


//10 A010 00 FF 05 EA 06 98 08 00 00 64 4F 37 69 0F 69 69 00 78
EEPROMDataStru  MeterPara;
//里程保存起始地址
uint32_t  paraddress = EEPROMPARAADR;

const EEPROMDataStru /*__attribute__((section(".user")))*/ConstInit =
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
//	.Data.checksum     = 
};


//读取一个地址开始起始的
uint32_t ReadBlockPara(uint32_t addr)
{
   uint8_t i;
   FLASH_READCODE_fun(addr,MeterPara.data32,8);
   addr+=32;
   return addr;
}
uint8_t CaluSum(void);

void SaveDataToMeter(void)
{
	#if 0
	MeterPara.Data.Switch.b0 = VIDEO_AV_GRAR; 
	MeterPara.Data.Switch.b1 = VIDEO_AV_MID; 
	MeterPara.Data.Switch.b2 = VIDEO_AV_FRO; 
	MeterPara.Data.Switch.b3 = VIDEO_AV_ELSE;
	#else
	MeterPara.Data.video.b0 = VIDEO_AV_GRAR; 
	MeterPara.Data.video.b1 = VIDEO_AV_MID; 
	MeterPara.Data.video.b2 = VIDEO_AV_FRO; 
	MeterPara.Data.video.b3 = VIDEO_AV_ELSE;
	#endif
	MeterPara.Data.Switch.b4 = RAIN_STATE;
	MeterPara.Data.Switch.b5 = BUZZ_NORMAL_WORK;
	MeterPara.Data.Switch.b6 = Bus_Type;
	
	MeterPara.Data.air_alarm	= Air_Alarm; 
	MeterPara.Data.speed_alarm	= Speed_Alarm; 
	MeterPara.Data.oil_alarm	= Oil_Alarm;
	MeterPara.Data.ranyou_alarm = Ranyou_Alarm; 
	MeterPara.Data.air_coef 	= Air_Coef; 
	MeterPara.Data.air2_coef	= Air2_Coef;
	MeterPara.Data.fuel_coef	= Fuel_Coef; 
	MeterPara.Data.rain_time	= Rain_Delay_Time;;
	MeterPara.Data.coef         = Coef;
	MeterPara.Data.pulse		= Pulse;
	MeterPara.Data.backlight	= backlight_level;
	MeterPara.Data.subi         = odometer_const;
    //MeterPara.Data.trip         = Veh_trip;
	//#if (PARACHECKEN == USED)
	MeterPara.Data.checksum = CaluSum();
	//#endif
}

uint32_t DownPara(uint32_t address)
{
	uint8_t i;
	for(i = 0;i <8;)
    {
       WriteDlong(paraddress,MeterPara.data32[i],MeterPara.data32[i + 1]);
	   i += 2;
	   paraddress+=8;
    }	
	return paraddress;
}

//写入仪表参数数据
uint32_t SaveMeterPara(void)
{
   SaveDataToMeter();
   if(paraddress >=  PARAENDADR)
   {
	 //擦除备用区
	 ERASEPAGE(EEPROMPARACHECKADDR);
	 //地址固定在备份区域
	 paraddress = EEPROMPARACHECKADDR;
	 //把数据备份在备份区域
     DownPara(paraddress);
	 //擦除主数据区域
	 ERASEPAGE(EEPROMPARAADR);//擦除1K空间
	 //地址固定在主存储区
	 paraddress = EEPROMPARAADR;
	 //写入主要存储区
	 DownPara(paraddress);
	 //擦除备用区
	 ERASEPAGE(EEPROMPARACHECKADDR);	 
   }
   else
   {
      DownPara(paraddress);
   }
   return paraddress;
}

//EEPROM中数据映射全局变量
void GiveParaToData(void)
{
	#if 0
   	VIDEO_AV_GRAR    = MeterPara.Data.Switch.b0; 
	VIDEO_AV_MID     = MeterPara.Data.Switch.b1; 
	VIDEO_AV_FRO     = MeterPara.Data.Switch.b2; 
	VIDEO_AV_ELSE    = MeterPara.Data.Switch.b3;
	#else
	VIDEO_AV_GRAR    = MeterPara.Data.video.b0; 
	VIDEO_AV_MID     = MeterPara.Data.video.b1; 
	VIDEO_AV_FRO     = MeterPara.Data.video.b2; 
	VIDEO_AV_ELSE    = MeterPara.Data.video.b3;
	#endif
	
	RAIN_STATE       = MeterPara.Data.Switch.b4;
    BUZZ_NORMAL_WORK = MeterPara.Data.Switch.b5;
    Bus_Type         = MeterPara.Data.Switch.b6;

	Air_Alarm        = MeterPara.Data.air_alarm; 
    Speed_Alarm      = MeterPara.Data.speed_alarm; 
	Oil_Alarm        = MeterPara.Data.oil_alarm;
	Ranyou_Alarm     = MeterPara.Data.ranyou_alarm; 
	Air_Coef         = MeterPara.Data.air_coef; 
    Air2_Coef        = MeterPara.Data.air2_coef;
	Fuel_Coef        = MeterPara.Data.fuel_coef; 
	Rain_Delay_Time  = MeterPara.Data.rain_time;
    Coef             = MeterPara.Data.coef;
    Pulse            = MeterPara.Data.pulse;
    backlight_level  = MeterPara.Data.backlight;	
	odometer_const   = MeterPara.Data.subi;
	
    //Veh_trip         = MeterPara.Data.trip;
}

//计算校验码
uint8_t CaluSum(void)
{
   uint8_t i,Sum = 0;
   //计算要写入的校验码  加入校验防止数据出错  20210907
   for(i = 0; i < 31;i++)
 	  Sum += MeterPara.data8[i] + 1; 
   return Sum;
}

//读取校验码，由于校验数据
uint8_t ReadCheckSum(void)
{
   uint8_t i,Sum = 0;
   for(i = 0; i < 31;i++)
   	 Sum += MeterPara.data8[i]; 
   if(Sum == MeterPara.Data.checksum)
   	return 1;
   else
   	return 0;
}

uint32_t markaddress = 0;
/******未加入校验，后续补上**********/
// 读取仪表参数数据
uint32_t ReadMeterPara(void)
{
   uint32_t i = 0;
   markaddress = 0;
   //读取备份FLASH中仪表参数数据
   miles = ReadAdd(EEPROMPARACHECKADDR);
   if(miles == DEFAULTDATA)
   {    
      for(odoadd = EEPROMPARAADR; odoadd < PARAENDADR;)
      {
         miles = 0;
         miles = ReadAdd(odoadd);
	     if(miles == DEFAULTDATA)
	     {
	        #if (PARACHECKEN == USED)
		        if(odoadd == EEPROMPARAADR)//确定第一字节没数据直接擦除写入
					break;
				else
				{   
	               for(markaddress = (odoadd - 32);markaddress >= EEPROMPARAADR;markaddress = markaddress - 32)
	               {
	                  ReadBlockPara(markaddress);
					  if(ReadCheckSum() == 1)
					  	break;   
				   }

	               //判断直到第一个地址数据存储都有问题
				   if(markaddress == EEPROMPARAADR)
				   {
				     ERASEPAGE(EEPROMPARAADR);//擦除1K空间
				   	 odoadd = EEPROMPARAADR;
				   }
				}
			#endif
           #if (PARACHECKEN == UNUSED)
              break;//未加入checksum之前
           #endif
	     }
	     else
	       odoadd = odoadd + PARALEN;
      }   
	  
	  if(odoadd == EEPROMPARAADR)
	  {
		 paraddress = odoadd;
		 for(i = 0;i < 8;i++)
		 	MeterPara.data32[i] = ConstInit.data32[i];
		 GiveParaToData();
	     //写入里程数据
	     paraddress = SaveMeterPara();		 
	  }
	  else
	  {
	      // 未加入校验之前数据
	      #if (PARACHECKEN == UNUSED)
		  	   ReadBlockPara(odoadd - PARALEN);
			   paraddress = odoadd;
		  #endif
		  #if (PARACHECKEN == USED)
		      if(markaddress == (odoadd - 32))
		      {
			    ReadBlockPara(odoadd - PARALEN);
			    paraddress = odoadd;
		      }
			  else
			  {
	             //有数据写入异常了，也不是第一组地址数据
	             paraddress = odoadd;
				 paraddress = SaveMeterPara();	
			  }
		  #endif
	  }
   }
   else
   {
     //有数据，擦除1K数据空间
     ERASEPAGE(EEPROMPARAADR);//擦除1K空间
     ReadBlockPara(EEPROMPARACHECKADDR);
     //Veh_odo = miles;
	 paraddress = EEPROMPARAADR;
	 //写入仪表参数数据
	 paraddress = SaveMeterPara();
	 //擦除备用区
	 ERASEPAGE(EEPROMPARACHECKADDR);
   }
   GiveParaToData();
}























