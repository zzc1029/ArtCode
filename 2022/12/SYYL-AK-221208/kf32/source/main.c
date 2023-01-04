
#include "system_init.h"
#include "flash.h"


/*
��Ҫ�趨�ж�ƫ��,��ȷ������boot����APP����
SYSCTL_Vector_Offset_Config(APP_ADDRESS)
SYS_VECTOFF = APPLICATION_ADDRESS ; 

*/

//const unsigned int __attribute__((section(".password")))PassWord = 0x55555555;
void DelayKong(volatile uint32_t a, volatile uint32_t b)
{
	volatile uint32_t i;
	volatile uint32_t j;
	for(i=a;i>1;i--)
	{
		j=b;
        while(j--);
	}
}


void McuSystemInit(void)
{
    //�õ��˿ڳ�ʼ��
	PortInit();
    //��ʼ������1��T123ͨѶ
	UartInitToT123();
	//��ʼ����ʱ��1,2������������ѵ�Լ��������
	TimerInit();

	//������ʼ��
	KeyIoInit();
	//t123 FIFO��ʼ��
	InitSendToT123();
	//��ʾ�����ʼ��
	InitDisplayHelper();

	//74hc165��ʼ��
	HC165PortInit();
	//74HC595��ʼ��
	LedPortInit();
	//ADC����
	AdcInit();
	//����PWM��ʼ��
	PwmInit();
	//Ƶ�ʲ�׽��ʼ��
	CaptureModeInit();
    //�������оƬIO���Լ�ADC��ʼ��
	OutPowerInit();
	//����˿ڡ����ݳ�ʼ��
	InitMotor();
	
	CanInit();
    //��ʼ��CAN1���ͻ���
	InitCan1Send();

	//BCAN��ʼ�� C3,C4
	BcanInint();
    InitBCanSend();
	
	//PCAN C7,C8
	PcanInint();
	InitPCanSend();

	
    #if C16C17CAN
	//PCAN C16,C17
	DcanInint();
	InitDCanSend();
    #endif

	//�Ǳ��Լ�BCM�˿ڸߵ�����
    MeterAndBCMPortInit();
	//GPIO_Set_Output_Data_Bits(GPIOE_SFR,GPIO_PIN_MASK_0, SET);

	RtcInit();
	ZD24C0xDeceiveInit();
}



void TestCan(void)
{
    static uint8_t  data[8],life;
	TYPE_DWORD temp;
    temp.BIT.b0 = 2;
	
	data[0] = temp.dword;
	data[1] = temp.dword >> 8;
	data[2] = temp.dword >> 16;
	data[3] = temp.dword >> 24;
	
	data[4] = temp.byte[0];
	data[5] = temp.byte[1];
	
	data[6] = temp.byte[2];
	data[7] = temp.byte[3];



    Can0_Tx_Bytes(0x0cfe6cee,data,8);
    Can2_Tx_Bytes(0x12345678,data,8);
    //Can3_Tx_Bytes(0x621,data,8);
	
}


void main()
{
   // 
   // SYS_VECTOFF = 0x8000; 
    DisableIRQ();
	//ϵͳʱ��120M,�����Ƶʱ��16M
	SystemInit();

	McuSystemInit();
	reset_motor();
	
    //watchdog�������£�
	//�����趨WWDG�Ŀɲ���������ֵ
    #if WATCHDOGEN
	WWDT_Config_TH(WWDT_Threshold);  //�����趨ֵ0x1F
    #endif
    
    //����ʱ��
	config_rtc();
  	ZD24C0xReadVehodo();
	DelayKong(300, 300);
	ZD24C0xReadMeterPara();
	DelayKong(300, 300);
    // ��ȡ�������
	//ReadVehodo();
	//ReadMeterPara();
    EnableIRQ(); 
	sch_init();
    initdata();
	MPC5602_CALL_T123 = 0;
	(void)sch_add_task(power_task, 2, 9);
	(void)sch_add_task(Light, 2, 49);
	//(void)sch_add_task(TestCan, 2, 9);
	(void)sch_add_task(key_task, 1, 2);			         //20ms
	(void)sch_add_task(display_task, 1, 9);			     //20ms
    #if CALULATE_SPEED_ENABLE
	(void)sch_add_task(calulate_speed,99,9);
    #endif
    #if SENDSPEED_ENABLE
	(void)sch_add_task(Sendspeed,99,4);
    #endif
	//(void)sch_add_task(j1939_tx_50ms, 6, 9);			 //100ms
	(void)sch_add_task(Acquisition_Task,26,99);
	(void)sch_add_task(ReadAdcResult, 1, 1); 			 //20ms
	(void)sch_add_task(SystemLogic, 49, 9); 			 //20ms
	(void)sch_add_task(feedback_diag, 9, 49); 			 //20ms
	(void)sch_add_task(motor_task, 300, 4); 			 //20ms
	(void)sch_add_task(roll_alarm_Task, 500, 199);		 //2000ms
	(void)sch_add_task(BuzzLogic, 48, 1);		         //2000ms

	//(void)sch_add_task(CaultOdo, 199, 99);			     //20ms
	while(1)
	{
		if((KEY_ON || KEY_CHARGE|| KEY_POWER) && (T123OnFlag == 0))
		  {
			  T123OnFlag  = 1; 
			  CONTROL_T123_POWER();
		//	  (void)sch_add_task(display_task, 334, 9); 		  //20ms  
		  }
		BootloaderLoop();
		sch_dispatch_tasks();
        if(((SysTickPer1ms & 0x1F) == 0x10) && (time != SysTickPer1ms)) //32msִ��һ��
        {
            time = SysTickPer1ms;
            SendToT123();
        }
		//C5,C6can���ͱ���
		Can1SendFifo();
		#if C16C17CAN
		DCanSendTo();
		#endif
		//��CAN
		BCanSendTo();
		//C7&C8can
		PCanSendTo();

		
       #if WATCHDOGEN
		WWDT_Clear();
       #endif
	}
}









/**
  * ����   ����У�鷢��������ļ�����
  * ����   file: ָ���ļ����Ƶ�ָ��
  *      line�� У��������
  * ����  �ޡ�
  */
void check_failed(uint8_t* file, uint32_t line)
{
	  /* �û���������Լ��Ĵ���ʵ�ֱ����ļ������к�,
	             ����: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	  while(1)
	  {
		  ;
	  }
}



