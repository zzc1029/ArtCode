#include "../src/defs.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

/********************************************订单详细设置*******************************************************/
//<o>版本号后缀 
// <i> 版本号的数字部分
// <100001-999999>
#define ORDER_VERSION  100005

//<c1> PWM时长设置功能开关
// <i> 打开后，可以通过0x6FX报文设置个输出的PWM启动时长
//#define PWMTIME_SET_ENABLE
//</c>


//<c1> 电流值发送开关
// <i> 打开后，反馈电流会通过报文发送出去
#define CURRENT_SEND  
//</c>

#undef PLUSE
//<o>百米脉冲 
// <i> 百米脉冲 最大999
// <0000-9999>
#define PLUSE 1520


//<o>A25 传感器类型
// <i> 默认是电阻型
// <0=> 电压型
// <1000=> 电阻型
// <10000=> 10K上拉电阻型
#define SENSE_SER1_P25_SET  0

//<o>A40 传感器类型
// <i> 默认是电阻型
// <0=> 电压型
// <1000=> 电阻型
// <10000=> 10K上拉电阻型
#define SENSE_SER2_P40_SET  0

//<e>雨刮使能
// <i>雨刮使能
#define SUPPORT_WIPER 1

//<c1> 雨刮功能CAN控制开关
// <i> 打开后, 可以通过将0x06A4报文byte7.bit2设置为1来关闭雨刮功能,释放模块1的A1、A9脚
//#define WIPER_DISABLE_BY_CAN  
//</c>
//</e>

//<e>关仪表常输出设置
#define NORMAL_OUT 0
#if NORMAL_OUT > 0
	//<e>模块1（前模块）常输出使能
	//<s>模块1（前模块）常输出脚
	//<i>输入常输出端口，用空格键分开，例如A05 A07 A42
	#define NORMAL_MOD1 0
	#if NORMAL_MOD1 > 0
		#define NORMOL_OUTS_MOD1 ""
	#endif
	//</e>

	//<e>模块2（顶模块）常输出使能
	//<s>模块2（顶模块）常输出脚
	//<i>输入常输出端口，用空格键分开，例如A05 A07 A42
	#define NORMAL_MOD2 0
	#if NORMAL_MOD2 > 0
		#define NORMOL_OUTS_MOD2 ""
	#endif
	//</e>

	//<e>模块3（后模块）常输出使能
	//<s>模块3（后模块）常输出脚
	//<i>输入常输出端口，用空格键分开，例如A05 A07 A42
	#define NORMAL_MOD3 0
	#if NORMAL_MOD3 > 0
		#define NORMOL_OUTS_MOD3 ""
	#endif
	//</e>
	
	//<e>模块4（顶2模块）常输出使能
	//<s>模块4（顶2模块）常输出脚
	//<i>输入常输出端口，用空格键分开，例如A05 A07 A42
	#define NORMAL_MOD4 0
	#if NORMAL_MOD4 > 0
		#define NORMOL_OUTS_MOD4 ""
	#endif
	//</e>
#endif
//</e>

//<e>关仪表模块自动控制功能设置
#define SELF_CONTROL 0
#if SELF_CONTROL > 0

//<h> 开关状态接收设置
	//<c> 使能模块1开关状态接收
	//#define MOD1_SW_DATA
	//</c>
	//<c> 使能模块2开关状态接收
	//#define MOD2_SW_DATA
	//</c>
	//<c> 使能模块3开关状态接收
	//#define MOD3_SW_DATA
	//</c>
	//<c> 使能模块4开关状态接收
	//#define MOD4_SW_DATA
	//</c>
//</h>

//<h>关仪表模块自动控制脚设置
	//<e>模块1（前模块）自控输出使能
	//<s>模块1（前模块）自控输出脚
	//<i>输入端口，用空格键分开，例如A05 A07 A42
	#define LOGIC_MOD1 0
	#if LOGIC_MOD1 > 0
		#define LOGIC_OUTS_MOD1 "A05 A07 A42"
	#endif
	//</e>

	//<e>模块2（顶模块）自控输出使能
	//<s>模块2（顶模块）自控输出脚
	//<i>输入端口，用空格键分开，例如A05 A07 A42
	#define LOGIC_MOD2 0
	#if LOGIC_MOD2 > 0
		#define LOGIC_OUTS_MOD2 "A05 A07 A42"
	#endif
	//</e>

	//<e>模块3（后模块）自控输出使能
	//<s>模块3（后模块）自控输出脚
	//<i>输入端口，用空格键分开，例如A05 A07 A42
	#define LOGIC_MOD3 0
	#if LOGIC_MOD3 > 0
		#define LOGIC_OUTS_MOD3 "A05 A07 A42"
	#endif
	//</e>
	
	//<e>模块4（顶2模块）自控输出使能
	//<s>模块4（顶2模块）自控输出脚
	//<i>输入端口，用空格键分开，例如A05 A07 A42
	#define LOGIC_MOD4 0
	#if LOGIC_MOD4 > 0
		#define LOGIC_OUTS_MOD4 "A05 A07 A42"
	#endif
	//</e>
//</h>

//<h> 自控逻辑
//<i> 关仪表时自动控制逻辑选择
//<o> 门控逻辑开关
// <i> door control logic enable
// <0=> 逻辑1
// <1=> 逻辑2
// <2=> 逻辑3
// <4=> 逻辑4
// <5=> 220315最新逻辑
#define LOGIC_S  0

#if LOGIC_S == 0
#define LOGIC
#elif  LOGIC_S == 1
#define LOGIC1
#elif  LOGIC_S == 2
#define LOGIC2
#elif  LOGIC_S == 4
#define LOGIC4
#elif  LOGIC_S == 5
#define LOGIC5
#endif

//<c1> 模块3 A1打开时，关闭A8电流反馈，成都825台专用
// <i> 目前只有成都订单使用
//#define LOGIC3
//</c>
//</h>

#ifdef LOGIC5
	#define KEY_SOS_ENABLE
#endif
#endif
//</e>


//*** <<< end of configuration section >>>    ***


