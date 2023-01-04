#ifndef __ORDER_CONFIF_H__
#define __ORDER_CONFIF_H__

#include "defs.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

#define NORMAL_QRWD  		100001   //常规的 电阻式传感器 B40 模块
#define NORMAL_VOL  		100002   //常规的 电压式传感器 B40 模块
#define NORMAL_RES 			100003   //常规的 电阻式传感器 阻值 1K B40 模块
#define NORMAL_RES_10K 	100004   //常规的 电阻式传感器 阻值 10K B40 模块
#define NORMAL_QRWD_vol 100005   //常规的 电压式传感器 B40 模块

/********************************************调试相关*******************************************************/
// <c1> 调试开关
// <i> 调试开关打开，打开调试硬编码为顶部模块
//#define DEBUG
// </c>

//短路重试计数复位（仪表6A4报文消失和ON档和ACC档丢失后和关闭功率输出一起复位）
// <c1> 关仪表重置短路重试次数使能
// <i> 关仪表时重置短路重试次数，勾选的话，重启仪表模块会重新打开，判断短路
//#define  PROTECTION_MAX_RETRY_COUNT_RESET   
// </c>

//<s>版本配置文件
// <i> 订单版本号6位年月日
#include "220801.h" 
//#include "config_experiment.h" 


//版本配置保存在../config目录下

//*** <<< end of configuration section >>>    ***

#endif

