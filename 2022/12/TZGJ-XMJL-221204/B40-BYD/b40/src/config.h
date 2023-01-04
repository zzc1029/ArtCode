#ifndef __CONFIF_H__
#define __CONFIF_H__

#include "OrderConfig.h"

/********************************************调试相关*******************************************************/
//调试开关
//#define DEBUG //打开调试硬编码为顶部模块

#ifdef DEBUG
		//#define ADC_DEBUG
    //#define PLUSE_TEST
		//#define PLUSE_DEBUG
    //#define RAIN_TEST
    #define MAIN_TEST //主程序统计运行效率
		//#define TEMP_TEST
#endif


/********************************************硬件版本相关*******************************************************/
//B40 6.0版本  相比2.41版本增加下面的功能
//PTC7 传感器电源控制，高有效
//PTF4 控低开关 上拉电控制，高有效
//PTF3 唤醒输入，控低输入，高有效
//PTD1 电源维持，高有效
#define B40V60

//B40 6.0版本 采用6143D功率芯片,相对 B40V60 更换了 功率芯片
#define B40V60_BTS6143D


/********************************************4模块订单相关*******************************************************/
#if defined MOD4_HF  // 合肥四模块
	#define MOD4
	#define MOD4_BYTE_START  2
#elif defined MOD4_CD  // 成都四模块
	#define MOD4
	#define MOD4_BYTE_START  0
#endif

/********************************************功率输出相关*******************************************************/
#define OC_THRESHOLD2					180     //50085保护值
#define OC_THRESHOLD  				150  		//过载保护电流限值，单位0.1A
#define OC_TIME_THRESHOLD_MS  5000   	//过流时间限值，单位 ms

#define SC_TIME_THRESHOLD_MS  500   	//短路时间限值，单位 ms

/***********************************************雨刮相关**********************************************************/
//喷水电机输出脚位置受0x6A4报文data[6]&0x40控制
//==0x00：表示喷水电机输出脚固定为PA9，不能改变，兼容以前的仪表协议
//==0x40；表示仪表控制模式，可由仪表逻辑选择任意引脚作为雨刮喷水输出

#if SUPPORT_WIPER == 1
	#define WIPER_OUTS "A01 A09"  //雨刮输出口，高低档位
	#define WIPER_AT_RESET()  (ADD1_IN() == 0)   //查询雨刮位置，1处于复位位置
	
	#ifndef  WIPER_DISABLE_BY_CAN 
	#define WIPER_DISABLE 0
	#else
	#undef WIPER_DISABLE
	#endif
#endif

/***********************************************自动协议相关**********************************************************/
//#if (defined LOGIC_OUTS_MOD1) || (defined LOGIC_OUTS_MOD2) || (defined LOGIC_OUTS_MOD3) || ((defined MOD4) && (defined LOGIC_OUTS_MOD4))
//	#if (!defined LOGIC) && (!defined LOGIC1) && (!defined LOGIC2) && (!defined LOGIC4) && (!defined LOGIC5)
//		#error "mast defined LOGICX!"
//	#endif
//#endif

/***********************************************传感器相关**********************************************************/
//传感器类型选择，电阻：TYPE_RES；电压：TYPE_VOL，可以分开设定，
//B40 V6.0版本之后 电阻电压传感器无需修改硬件，但是两个传感器类型不同的话仍然要修改硬件
//后期可以根据模块修改



#endif

