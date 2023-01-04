#include "system_init.h"

#if 0
//u8 add1[8],add2[8],add3[8],add4[8];
TYPE_BYTE Symbol_Data6,Symbol_Data7,AEBS_FLAG;

void Aebs_Symbol(void)  //100ms
{
	static u8 light1,red,yellow,timex = 60,time05s = 0,dis = 70;
	Symbol_Data6_1 = (EBS_SW_R ||((timeout[GetIndexFromID(0x18F0010B)]) >50))||(dis > 0);
	Symbol_Data6_2 = EBS_SW_Y||(dis > 0);
	if(ESC_FAULT||(dis > 0))
	 {
	   Symbol_Data6_3	  =  1;   //N/A
	   light1 = 1;
	 }
	 else if(ESC_NORMAL)
	 {
		Symbol_Data6_3 = (light1 > 5);
		if(light1++ == 10)
		   light1 = 1;
	 }
	 else
	 {
	   Symbol_Data6_3 = 0;
	   light1 = 1;
	 }
	 Symbol_Data6_4 = 0;
	 Symbol_Data6_5 = 0;
	 Symbol_Data6_6 = 0;
	 Symbol_Data6_7 = ZUO_LDW;
	 Symbol_Data6_8 = YOU_LDW;
     if(dis > 0 )
	 	dis--;
 #if 0
	Symbol_Data7_1 = AEBS_PEDE_STA;
	
	//PCW碰撞报警
	if(PCW_NORMAL)
	{	
		Symbol_Data7_2	=  0;
		Symbol_Data7_3	=  0;
		Symbol_Data7_4	=  0;
	}
	else if(PCW_RED)
	{
		Symbol_Data7_2	=  0;
		Symbol_Data7_3	=  0;
		Symbol_Data7_4	=  (red < 4);
	}
	else if(PCW_YELLOW)
	{
		Symbol_Data7_2	=  (yellow < 6);
		Symbol_Data7_3	=  0;
		Symbol_Data7_4	=  0;
	}
	else if(PCW_LV)
	{
		Symbol_Data7_2	=  0;
		Symbol_Data7_3	=  1;
		Symbol_Data7_4	=  0;
	}
	if(ITSR_MARK)
		Symbol_Data7_5	 =	1;	  //N/A
	else if(ITSR_BLINKER)
	{
		Symbol_Data7_5	 =	(time05s > 2);	  //N/A
	}
	else
		Symbol_Data7_5	 =	0;	  //N/A
	time05s ++;
  	if(time05s > 5)
		time05s = 0;
	Symbol_Data7_6	 =	(add[1] == 109);	  //N/A
	
	if(timex > 0)
	{	
		timex--;
		Symbol_Data6.byte = 0xff;
		Symbol_Data7.byte = 0xf0;
	}
    #endif

}
u8 send[8];
void J1939_Can_Aebs(void)  //100ms
{
	static TYPE_BYTE aebs_status2,aebs_status1,aebs_status;
	static u8 lizhi = 1,lizhi2 =1,fanglaoshi = 0,li = 0,life = 0,AEBS_INIT = 0,AEBS_STA = 0;
	static uint8_t add_air = 0,add_air1 = 0,check = 0,what_i_f;
	u32 temp;
/******************************* EBS 发送报文 ************************************************/
//(0X0CFE6CEE不在此处发送)

	if(add_air > 9)
    {
      add_air = 0;
      send[0] = 0;
      send[1] = 0;
      send[2] = veh_bar2*1.25;
      send[3] = veh_bar1*1.25;
      send[4] = 0;
      send[5] = 0;
      send[6] = 0;
      send[7] = 0;
	  PCan1_Expend_Tx_Bytes(0x18FEAE30,send,8);
	  PCan2_Expend_Tx_Bytes(0x18FEAE30,send,8);
	}
	else
		add_air++;
	

	if(LED_PARK_SW)
		what_i_f = 0X04;
	else
		what_i_f = 0x00;
	
	send[0] = what_i_f;
	send[1] = 0;
	send[2] = veh_speed_display/10;
	
	if(ADD_E_BREAK1)
		what_i_f = 0x10;
	else
		what_i_f = 0x00;
	send[3] = what_i_f;


	send[4] = 0xff;
	send[5] = 0xff;
	send[6] = 0xff;
	send[7] = 0xff;
	
	PCan1_Expend_Tx_Bytes(0x18FEF117,send,8);
	PCan2_Expend_Tx_Bytes(0x18FEF117,send,8);



/******************************* AEBS 发送报文 ************************************************/ 
#if 0
	EBC1_msg.prio = 3;
	EBC1_msg.PGN = 0x0BA0;
	EBC1_msg.sa = 0x27;
	EBC1_msg.len = 8;
	EBC1_msg.RTR = 0;

	if(!fanglaoshi)
	{
		aebs_status.byte = 0x01;
		fanglaoshi = 1;
	}
	if(AEBS_SW != li)
	{
		li = AEBS_SW;
		if(AEBS_SW)	
			aebs_status.bit.b0 = (!aebs_status.bit.b0);
	}

	EBC1_msg.buffer[0].byte = aebs_status.byte;
	EBC1_msg.buffer[1].byte = 0xff;
	EBC1_msg.buffer[2].byte = 0xff;
	EBC1_msg.buffer[3].byte = 0xff;
	EBC1_msg.buffer[4].byte = 0xff;
	EBC1_msg.buffer[5].byte = 0xff;
	EBC1_msg.buffer[6].byte = 0xff;
	{
		life++;
		if(life > 15) 
			life =0 ;
		check = EBC1_msg.buffer[0].byte +EBC1_msg.buffer[1].byte+EBC1_msg.buffer[2].byte +EBC1_msg.buffer[3].byte+EBC1_msg.buffer[4].byte +EBC1_msg.buffer[5].byte+EBC1_msg.buffer[6].byte;
		check = check + (life&0x0f) +0x0C+0X0B+0XA0+0X27;
		check = ((check>>4) + check)&0x0f;
	}
	EBC1_msg.buffer[7].byte = ((check<<4)&0XF0)+(life&0x0f);
	Can2_Tx_Expend(MB2, EBC1_msg);

	EBC1_msg.prio = 3;
	EBC1_msg.PGN = 0xFDCC;
	EBC1_msg.sa = 0x27;
	EBC1_msg.len = 8;
	EBC1_msg.RTR = 0;
	if(KEY_EMG)
		what_i_f = 0X10;
	else if(LEFT_LED_SW)
		what_i_f = 0X01;
	else if(RIGHT_LED_SW)
		what_i_f = 0x02;
	else 
		what_i_f = 0x00;
	EBC1_msg.buffer[0].byte = 0Xff;
	EBC1_msg.buffer[1].byte = what_i_f;
	EBC1_msg.buffer[2].byte = 0xff;
	EBC1_msg.buffer[3].byte = 0xff;
	EBC1_msg.buffer[4].byte = 0xff;
	EBC1_msg.buffer[5].byte = 0xff;
	EBC1_msg.buffer[6].byte = 0xff;
	EBC1_msg.buffer[7].byte = 0xff;
	Can2_Tx_Expend(MB3, EBC1_msg);
 
	EBC1_msg.prio = 6;
	EBC1_msg.PGN = 0xF007;
	EBC1_msg.sa = 0xE8;
	EBC1_msg.len = 8;
	EBC1_msg.RTR = 0;	
	if(lizhi)
	{
		aebs_status1.byte = 0x10;
		lizhi = 0;
	}	
	if(AEBS_PEDE_SW && lizhi2)
	{
		aebs_status1.bit.b4 = (!aebs_status1.bit.b4);
		if(aebs_status1.bit.b4)
			AEBS_PEDE_STA = 0;
		else
			AEBS_PEDE_STA = 1;
		lizhi2 = 0;
	}
	if(!AEBS_PEDE_SW)
		lizhi2 = 1;


	EBC1_msg.buffer[0].byte = 0xff;
	EBC1_msg.buffer[1].byte = aebs_status1.byte;
	EBC1_msg.buffer[2].byte = 0xff;
	EBC1_msg.buffer[3].byte = 0xff;
	EBC1_msg.buffer[4].byte = 0xff;
	EBC1_msg.buffer[5].byte = 0xff;
	EBC1_msg.buffer[6].byte = 0xff;
	EBC1_msg.buffer[7].byte = 0xff;

	Can2_Tx_Expend(MB4, EBC1_msg);
	
	EBC1_msg.prio = 6;
	EBC1_msg.PGN = 0xF001;
	EBC1_msg.sa = 0x17;
	EBC1_msg.len = 8;
	EBC1_msg.RTR = 0;
		
	EBC1_msg.buffer[0].byte = 0xff;
	EBC1_msg.buffer[1].byte = 0xff;
	if(!AEBS_INIT)
	{
		aebs_status2.byte = 0xf0;
		AEBS_INIT = 1;
	}
	if(ESC_SW != AEBS_STA)
	{
		AEBS_STA = ESC_SW;
		if(ESC_SW)	
			aebs_status2.bit.b2 = (!aebs_status2.bit.b2);
	}
	
	EBC1_msg.buffer[2].byte = aebs_status2.byte;
	EBC1_msg.buffer[3].byte = 0xff;
	EBC1_msg.buffer[4].byte = 0xff;
	EBC1_msg.buffer[5].byte = 0xff;
	EBC1_msg.buffer[6].byte = 0xff;
	EBC1_msg.buffer[7].byte = 0xff;
	Can2_Tx_Expend(MB5, EBC1_msg);



	if(add_air1 > 9)
    {
 		EBC1_msg.prio = 6;
		EBC1_msg.PGN = 0xfee6;
		EBC1_msg.sa = 0xee;
		EBC1_msg.len = 8;
		EBC1_msg.RTR = 0;
		EBC1_msg.buffer[0].byte = (4*rtc.secs);	  
		EBC1_msg.buffer[1].byte = rtc.mins;
		EBC1_msg.buffer[2].byte = rtc.hours;
		EBC1_msg.buffer[3].byte = rtc.month;
		EBC1_msg.buffer[4].byte = (4*rtc.day);
		EBC1_msg.buffer[5].byte = (15+rtc.year);//1985
		EBC1_msg.buffer[6].byte = 0xff;
		EBC1_msg.buffer[7].byte = 0xff;	
		Can2_Tx_Expend(MB6, EBC1_msg);

		temp = veh_odo*200;
		EBC1_msg.prio = 6;
		EBC1_msg.PGN = 0xfec1;
		EBC1_msg.sa = 0xee;
		EBC1_msg.len = 8;
		EBC1_msg.RTR = 0;
		EBC1_msg.buffer[0].byte = temp&0xFF;
		EBC1_msg.buffer[1].byte = (temp>>8)&0xFF;
		EBC1_msg.buffer[2].byte = (temp>>16)&0xFF;
		EBC1_msg.buffer[3].byte = (temp>>24)&0xFF;
		EBC1_msg.buffer[4].byte = 0xff;
		EBC1_msg.buffer[5].byte = 0xff;
		EBC1_msg.buffer[6].byte = 0xff;
		EBC1_msg.buffer[7].byte = 0xff;
		Can2_Tx_Expend(MB7, EBC1_msg);
	}
	else
		add_air1++;
 
#endif
}
#endif


