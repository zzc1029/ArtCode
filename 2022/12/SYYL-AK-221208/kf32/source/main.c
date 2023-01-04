
#include "system_init.h"
#include "flash.h"


/*
需要设定中断偏移,不确定是在boot还是APP加入
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
    //用到端口初始化
	PortInit();
    //初始化串口1与T123通讯
	UartInitToT123();
	//初始化定时器1,2，用于任务轮训以及电机处理
	TimerInit();

	//按键初始化
	KeyIoInit();
	//t123 FIFO初始化
	InitSendToT123();
	//显示任务初始化
	InitDisplayHelper();

	//74hc165初始化
	HC165PortInit();
	//74HC595初始化
	LedPortInit();
	//ADC数据
	AdcInit();
	//背光PWM初始化
	PwmInit();
	//频率捕捉初始化
	CaptureModeInit();
    //输出功率芯片IO口以及ADC初始化
	OutPowerInit();
	//电机端口、数据初始化
	InitMotor();
	
	CanInit();
    //初始化CAN1发送缓存
	InitCan1Send();

	//BCAN初始化 C3,C4
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

	//仪表以及BCM端口高低配置
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
	//系统时钟120M,外设高频时钟16M
	SystemInit();

	McuSystemInit();
	reset_motor();
	
    //watchdog定义如下：
	//配置设定WWDG的可操作区下限值
    #if WATCHDOGEN
	WWDT_Config_TH(WWDT_Threshold);  //窗口设定值0x1F
    #endif
    
    //配置时钟
	config_rtc();
  	ZD24C0xReadVehodo();
	DelayKong(300, 300);
	ZD24C0xReadMeterPara();
	DelayKong(300, 300);
    // 读取里程数据
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
        if(((SysTickPer1ms & 0x1F) == 0x10) && (time != SysTickPer1ms)) //32ms执行一次
        {
            time = SysTickPer1ms;
            SendToT123();
        }
		//C5,C6can发送报文
		Can1SendFifo();
		#if C16C17CAN
		DCanSendTo();
		#endif
		//内CAN
		BCanSendTo();
		//C7&C8can
		PCanSendTo();

		
       #if WATCHDOGEN
		WWDT_Clear();
       #endif
	}
}









/**
  * 描述   报告校验发生错误的文件和行
  * 输入   file: 指向文件名称的指针
  *      line： 校验错误的行
  * 返回  无。
  */
void check_failed(uint8_t* file, uint32_t line)
{
	  /* 用户可以添加自己的代码实现报告文件名和行号,
	             例如: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	  while(1)
	  {
		  ;
	  }
}



