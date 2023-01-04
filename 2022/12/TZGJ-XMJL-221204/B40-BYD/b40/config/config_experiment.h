#ifndef __TEST_H__
#define __TEST_H__

#include "defs.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

#define NORMAL_QRWD  		100001   //常规的 电阻式传感器 B40 模块
#define NORMAL_VOL  		100002   //常规的 电压式传感器 B40 模块
#define NORMAL_RES 			100003   //常规的 电阻式传感器 阻值 1K B40 模块
#define NORMAL_RES_10K 	100004   //常规的 电阻式传感器 阻值 10K B40 模块


/********************************************调试相关*******************************************************/
//调试开关
// <c1> Enable Debug 
// <i> Enable Debug 
//#define DEBUG //打开调试硬编码为顶部模块
// </c>


//可选的配置
// <c1> Eanble Output Max Retry Count Reset
// <i> then max retry count is reset when key_on is invalid
//#define  PROTECTION_MAX_RETRY_COUNT_RESET   //短路重试计数复位（仪表6A4报文消失和ON档和ACC档丢失后和关闭功率输出一起复位）
// </c>


//#define CURRENT_SEND  //电流采样值输出，万达干燥器使用,不要在这里设置

//  <o>Pluse 
//  <i>  Pluse per 100m 百米脉冲
#define PLUSE 4800

// 雨刮使能
//雨刮逻辑：
//增加
//喷水端口仪表控制使能位：0x06A4 报文 Byte6 bit6 高有效  //高的话 喷水端口受仪表6A4控制，模块不写死端口，专门用于雨刮喷水不受控的订单
//稳刹PWM使能位：0x06A4 报文 Byte7 bit1 高有效
//稳刹使能位，0x06A4 报文 Byte7 bit0 高有效
//稳刹启动延迟时间：0x06A4 报文 Byte7 bit4-7 单位20ms，低于20ms自动调整到20ms
// <c1> SUPPORT_WIPER 
// <i> wiper function enable
#define SUPPORT_WIPER 1//雨刮控制功能开关
// </c>

//雨刮能通过报文关闭
//雨刮功能失能位：0x06A4 报文 Byte7 bit2 高有效  //高的话 无雨刮  待实现
// <c1> WIPER_DISABLE_BY_CAN
// <i> If selected, you can turn off the wiper function by sending 0x06A4 messages with data[7].bit2 = 1.
//#define WIPER_DISABLE_BY_CAN  
// </c>



// <c1> PWMTIME_SET_ENABLE
// <i> Enable can set pwm param 
//#define PWMTIME_SET_ENABLE
// </c>


//#define ORDER_VERSION NORMAL_VOL          //电压式传感器
//#define ORDER_VERSION NORMAL_RES          //电阻式传感器 1K上拉
//#define ORDER_VERSION NORMAL_RES_10K      //电阻式传感器 10K上拉
//#define ORDER_VERSION NORMAL_QRWD  				//万达带干燥器的 订单 电压式
#define ORDER_VERSION 220102    //CD-ZZ-220102 订单 220415 一样
//#define ORDER_VERSION 220308    //LA-ZZ-220308 订单
//#define ORDER_VERSION 220315    //220315 订单
//#define ORDER_VERSION == 211101  //肥东公交测试,强制打开模块3的A01的PWM启动


#if ORDER_VERSION == 211101

#define SENSE_SER1_P25_SET  TYPE_VOL
#define SENSE_SER2_P40_SET  TYPE_VOL

#endif

#if ORDER_VERSION == 220315

#define LOGIC5
#define LOGIC_OUTS_MOD3 "A05 A07 A42"
#define MOD1_SW_DATA

#define KEY_SOS_ENABLE

#define SENSE_SER1_P25_SET  TYPE_VOL
#define SENSE_SER2_P40_SET  TYPE_RES

#endif

#if ORDER_VERSION == 220308

#define LOGIC_OUTS_MOD3 "A08"

#define SENSE_SER1_P25_SET  TYPE_RES
#define SENSE_SER2_P40_SET  TYPE_RES

#define LOGIC4

#endif

#if ORDER_VERSION == 220102

#define MOD4_CD   //针对4模块订单程序

#define NORMOL_OUTS_MOD2 "A05"   				

/***********************************************自动协议相关**********************************************************/
//#define LOGIC  //门自控的功能，ACC和ON无效时，逻辑函数处理；XMJL的程序
//#define LOGIC1  //门自控功能，成都程序
#define LOGIC2  //门自控功能，成都程序
#define LOGIC3

#define LOGIC_OUTS_MOD2 "A02 A03"  //门自控的功能，ACC和ON无效时，内部输出

#define SENSE_SER1_P25_SET  TYPE_VOL
#define SENSE_SER2_P40_SET  TYPE_RES

#ifdef LOGIC1
#define MOD1_SW_DATA
#endif

#endif
#if ORDER_VERSION == NORMAL_QRWD
	//特别的地方在于需要发送电流
	#define CURRENT_SEND
	
	#define SENSE_SER1_P25_SET  TYPE_VOL
	#define SENSE_SER2_P40_SET  TYPE_VOL
	
	#undef PLUSE
	#define PLUSE 1520
	
#endif

#if ORDER_VERSION == NORMAL_VOL
 
	#define SENSE_SER1_P25_SET  TYPE_VOL
	#define SENSE_SER2_P40_SET  TYPE_VOL
	
#endif

#if  ORDER_VERSION == NORMAL_RES

	#define SENSE_SER1_P25_SET  TYPE_RES
	#define SENSE_SER2_P40_SET  TYPE_RES
	
#endif

#if  ORDER_VERSION == NORMAL_RES_10K

	#define SENSE_SER1_P25_SET  TYPE_RES_10K
	#define SENSE_SER2_P40_SET  TYPE_RES_10K
	
#endif

//*** <<< end of configuration section >>>    ***

#endif

