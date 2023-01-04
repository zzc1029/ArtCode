/****************************************************************************************
  *
  * 文件名  main.c
  * 作  者  ChipON_AE/FAE_Group
  * 日  期  2019-11-16
  * 描  述  该文件提供了CAN的收发参考代码
  *
 ****************************************************************************************/
#include "stdio.h"
#include "system_init.h"
#include "bootloader.h"




u32 pretime = 0;



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

// PF2 CCP1CH3


void MeterConfig()
{
	TimerInit();
	//仪表特殊功能管脚
	PortInit();
	//GPIOInit_Output_Config(GPIOA_SFR,GPIO_PIN_MASK_7);
    //BCAN初始化
	BcanInit();
	InitBCanSend();
	//PCAN1
	Pcan1Inint();
    InitPCan1Send();
    //PCAN2
	Pcan2Inint();
	InitPCan2Send();
    //PCAN3
	Pcan3Inint();
	InitPCan3Send();

	DcanInint();
	InitDCanSend();

	HC165PortInit();
    Ledinit();
	KeyIoInit();
	AdcInit();
//	buzz_init();
	//输入捕捉
	CaptureModeInit();
	//输出功率芯片IO口以及ADC初始化
	OutPowerInit();
	//仪表以及BCM端口高低配置
    MeterAndBCMPortInit();

	RtcInit();
    InitSendToT123();
    PwmInit();
	ZD24C0xDeceiveInit();
}

void TestCan(void)
{
    static uint8_t  data[8],life;
    TYPE_DWORD temp;

	data[0] = rtc.secs;
	data[1] = rtc.mins;

	data[2] = meter.MeterA15;
	data[3] = meter.MeterA15 >> 8;

	data[4] = meter.MeterA14;
	data[5] = meter.MeterA14>>8;

	data[6] = output_s.byte;
	data[7] = life++;


    //TCan_Standard_Tx_Bytes(0x520,data,8);
	//BCan_Standard_Tx_Bytes(0x666,data,8);
   // BCan_Expend_Tx_Bytes(0x0cfe6cee,data,8);

	//PCan1_Standard_Tx_Bytes(0x321,data,8);
    //PCan1_Expend_Tx_Bytes(0x18FEE017,data,8);

	//PCan2_Standard_Tx_Bytes(0x123,data,8);
    //PCan2_Expend_Tx_Bytes(0x18FEE017,data,8);

	PCan3_Standard_Tx_Bytes(0x111,data,8);
    PCan3_Expend_Tx_Bytes(0x12345678,data,8);

    //DCan_Standard_Tx_Bytes(0x113,data,8);
    //DCan_Expend_Tx_Bytes(0x12345678,data,8);

    //PCan_Expend_Tx_Bytes(0x12345678,data,8);
    //DCan_Standard_Tx_Bytes(0x621,data,8);

}


/**
  * 描述   主函数
  * 输入   无
  * 返回   无
  */
void main()
{
    DisableIRQ();
	SystemInit();
	MeterConfig();
    config_rtc();
    #if WATCHDOGEN
	WWDT_Config_TH(WWDT_Threshold);  //窗口设定值0x1F
    #endif
	
    #if RS485
    ConfigRS485(USART0_SFR);
	#endif
	
    // 读取里程数据
    ZD24C0xReadVehodo();
	DelayKong(300, 300);
	ZD24C0xReadMeterPara();
	DelayKong(300, 300);
	//ReadVehodo();
	//ReadMeterPara();
	EnableIRQ();
	//open background
	//SetBackGround(backlight_level);
	InitDisplay();
	sch_init();
	(void)sch_add_task(power_task, 2, 9);
	(void)sch_add_task(ReadAdcResult, 1, 1); 			 //20ms
	(void)sch_add_task(key_task, 1, 2);			         //20ms
	(void)sch_add_task(TestCan, 6, 9);				     //100ms
	(void)sch_add_task(switch_task, 7, 9);				 //100ms
	(void)sch_add_task(SystemLogic, 8, 9);				 //100ms
	(void)sch_add_task(feedback_diag, 9, 49); 			 //20ms
	
	(void)sch_add_task(GetCaptureHZ, 10, 99); 			 //20ms
	
	(void)sch_add_task(Acquisition_Task,26,99);
	
    (void)sch_add_task(display_task, 700, 9);          //100ms 
	(void)sch_add_task(Constant_display_Task, 99, 9);
	(void)sch_add_task(roll_alarm_Task, 500, 249);		//2000ms
	(void)sch_add_task(roll_symbol, 501, 249);		//2000ms

     #if CALULATE_SPEED_ENABLE
	 (void)sch_add_task(calulate_speed,99,19);
     #endif
	 
     #if SENDSPEED_ENABLE
	 (void)sch_add_task(Sendspeed,99,4);
     #endif

	 
	 (void)sch_add_task(BuzzLogic, 48, 1);				  //2000ms
	 (void)sch_add_task (singleMile, 99, 9);
	while(1)
	{
		BootloaderLoop();
		sch_dispatch_tasks();

        if ((pretime != SysTickPer1ms)) //1ms执行一次
        {
            pretime = SysTickPer1ms;
            SendToT123();
        }
        #if RS485
        (void)ReadRS485();
		#endif

		BCanSendTo();
		PCan1SendTo();
		PCan2SendTo();
		PCan3SendTo();
		DCanSendTo();
		
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
		  fprintf(USART2_STREAM,"Wrong parameters value: file %s on line %d\r\n", file, line);
	  }
}

