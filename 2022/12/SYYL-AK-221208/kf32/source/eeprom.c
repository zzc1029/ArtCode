/*
 * eeprom.c
 *
 *  Created on: 2021-8-7
 *      Author: ART
 */
#include "system_init.h"
#include "flash.h"

//���ڲ������� 1K
//FLASH_Wipe_Configuration_RAM (uint32_t WipeMode,uint32_t WipeAddr);
//����д��4�ֽ�
//void FLASH_WriteWord(uint32_t address,uint32_t p_FlashBuffer);    //дword
//����4���ֽ�����
//uint32_t FLASH_ReadWord(uint32_t address,uint32_t *p_FlashBuffer);//��Word

uint8_t     Air_Alarm,Speed_Alarm,Oil_Alarm,Ranyou_Alarm,Air_Coef,Air2_Coef,Coef,Oil_Alarm_2012;
uint8_t     Rain_Delay_Time,Fuel_Coef;
uint8_t     backlight_level,Bus_Type;
uint16_t    odometer_const,odometer_const_2012,Pulse,Pulse_const_2012;

uint8_t     Set_Air_Alarm,Set_Speed_Alarm,Set_Oil_Alarm,Set_Ranyou_Alarm,Set_Air_Coef,Set_Air2_Coef,Set_Coef;
uint8_t     Set_Rain_Delay_Time,Set_Fuel_Coef;
uint8_t     Set_backlight_level,Set_Bus_Type;
uint16_t    Set_odometer_const,Set_odometer_const_2012,Set_Pulse;
uint8_t     Set_buzz,Coef_2012;


//1 д�������
#define WTIRE_VEHODO(ADD,DATA)   FLASH_WriteWord(ADD,DATA)

//��̱�����ʼ��ַ
uint32_t  mileaddress = EEPROMMILEADDR;

void EraseMile(void);



//д������32λ����
uint32_t WriteDlong(uint32_t address,uint32_t data1,uint32_t data2)
{
    uint64_t  temp ;
	temp = data1 + ((uint64_t)data2 << 32);
	FLASH_WriteWord(address,temp);
	address = address + 8;
    return address;
}

// ��ȡһ��
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

// д�����������
uint32_t SaveVehodo(void)
{
    //д����̵���β�˵�ַ����
    if(mileaddress >= MILEENDADDR)
    {
        //����������
	    ERASEPAGE(EEPROMMILECHECKADDR);
        //FLASH_WriteWord(EEPROMMILECHECKADDR,Veh_odo); 
		WriteDlong(EEPROMMILECHECKADDR,Veh_odo,Veh_trip);
		EraseMile();//����16K�ռ�
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

//������̿ռ�
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

// ��ȡ���������
uint32_t ReadVehodo(void)
{
   //��ȡ����FLASH����������ݣ����������ֱ�Ӳ���
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
	     //д���������
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
     //�����ݣ�����16K�ռ����ݣ�д������̣��ٲ�����������
     EraseMile();//����16K�ռ�
     //Veh_odo = miles;
	 //Veh_trip = (miles >> 32)&0xffff; 
	 mileaddress = EEPROMMILEADDR;
	 //д���������
	 mileaddress = SaveVehodo();
	 //����������
	 ERASEPAGE(EEPROMMILECHECKADDR);
   }
}


/****************����Ϊ����̴��������Ǳ��������*************************************/


//10 A010 00 FF 05 EA 06 98 08 00 00 64 4F 37 69 0F 69 69 00 78
EEPROMDataStru  MeterPara;
//��̱�����ʼ��ַ
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


//��ȡһ����ַ��ʼ��ʼ��
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

//д���Ǳ��������
uint32_t SaveMeterPara(void)
{
   SaveDataToMeter();
   if(paraddress >=  PARAENDADR)
   {
	 //����������
	 ERASEPAGE(EEPROMPARACHECKADDR);
	 //��ַ�̶��ڱ�������
	 paraddress = EEPROMPARACHECKADDR;
	 //�����ݱ����ڱ�������
     DownPara(paraddress);
	 //��������������
	 ERASEPAGE(EEPROMPARAADR);//����1K�ռ�
	 //��ַ�̶������洢��
	 paraddress = EEPROMPARAADR;
	 //д����Ҫ�洢��
	 DownPara(paraddress);
	 //����������
	 ERASEPAGE(EEPROMPARACHECKADDR);	 
   }
   else
   {
      DownPara(paraddress);
   }
   return paraddress;
}

//EEPROM������ӳ��ȫ�ֱ���
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

//����У����
uint8_t CaluSum(void)
{
   uint8_t i,Sum = 0;
   //����Ҫд���У����  ����У���ֹ���ݳ���  20210907
   for(i = 0; i < 31;i++)
 	  Sum += MeterPara.data8[i] + 1; 
   return Sum;
}

//��ȡУ���룬����У������
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
/******δ����У�飬��������**********/
// ��ȡ�Ǳ��������
uint32_t ReadMeterPara(void)
{
   uint32_t i = 0;
   markaddress = 0;
   //��ȡ����FLASH���Ǳ��������
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
		        if(odoadd == EEPROMPARAADR)//ȷ����һ�ֽ�û����ֱ�Ӳ���д��
					break;
				else
				{   
	               for(markaddress = (odoadd - 32);markaddress >= EEPROMPARAADR;markaddress = markaddress - 32)
	               {
	                  ReadBlockPara(markaddress);
					  if(ReadCheckSum() == 1)
					  	break;   
				   }

	               //�ж�ֱ����һ����ַ���ݴ洢��������
				   if(markaddress == EEPROMPARAADR)
				   {
				     ERASEPAGE(EEPROMPARAADR);//����1K�ռ�
				   	 odoadd = EEPROMPARAADR;
				   }
				}
			#endif
           #if (PARACHECKEN == UNUSED)
              break;//δ����checksum֮ǰ
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
	     //д���������
	     paraddress = SaveMeterPara();		 
	  }
	  else
	  {
	      // δ����У��֮ǰ����
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
	             //������д���쳣�ˣ�Ҳ���ǵ�һ���ַ����
	             paraddress = odoadd;
				 paraddress = SaveMeterPara();	
			  }
		  #endif
	  }
   }
   else
   {
     //�����ݣ�����1K���ݿռ�
     ERASEPAGE(EEPROMPARAADR);//����1K�ռ�
     ReadBlockPara(EEPROMPARACHECKADDR);
     //Veh_odo = miles;
	 paraddress = EEPROMPARAADR;
	 //д���Ǳ��������
	 paraddress = SaveMeterPara();
	 //����������
	 ERASEPAGE(EEPROMPARACHECKADDR);
   }
   GiveParaToData();
}























