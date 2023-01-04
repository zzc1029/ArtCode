/******************************************************************************

                  版权所有 (C), 2015 - 2020  ART. All Rights Reserved, ART

 ******************************************************************************
  文 件 名   : T123AI.h
  版 本 号   : 初稿
  作    者   : stan
  生成日期   : 2016年2月15日
  最近修改   :
  功能描述   : T123AI.c 的头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2016年2月15日
    作    者   : stan
    修改内容   : 创建文件

******************************************************************************/

/*----------------------------------------------*
 * 包含头文件                                   *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 外部变量说明                                 *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 外部函数原型说明                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 内部函数原型说明                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 全局变量                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 模块级变量                                   *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 常量定义                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * 宏定义                                       *
 *----------------------------------------------*/

#ifndef __T123AI_H__
#define __T123AI_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


extern uint16_t t123Ans;

typedef struct xSendToT123Stru
{
	u8 sended;
	u8 loop;
	u8 delay;
	u8 data[12];
	
}SendToT123Stru;


enum {
	Sended,
	Ready,
	Check1,	
	Check2,
	//Check3,
//	Check4,
//	Check5,
	SendErr,
	SendNop
};

typedef struct SendToT123Xx
{
	int wr_index;
	int rd_index;
	int ovfcount; //包满，丢失
	int errcount; //发送超过重试次数
	SendToT123Stru * buff;
	int max_len;
} SendToT123X;

extern SendToT123X SendBuff;
extern u8 SendToT123Loop;
extern u8 SendToT123Delay;

//函数
extern uint32_t fifo_in(SendToT123X*fifo);
extern void fifo_init(SendToT123X* fifo,SendToT123Stru*buff,uint32_t len);
extern uint32_t fifo_out(SendToT123X *fifo);
extern void fifo_reset(SendToT123X*fifo);

///10ms-20ms调用一次
extern void SendToT123();

extern void InitSendToT123();

extern void fifo_set_free(SendToT123X*fifo);

#define Fifo_set_free() 		fifo_set_free(&SendBuff)
#define Transmit_Data_Sci1(x,y)   fifo_in(&SendBuff)

//参数定义:
//senddelay:发送流程中每次发送之间的延时次数，单位是SendToT123()函数调用时间间隔
//overdelay:发送流程之后的延时次数，单位是SendToT123()函数调用时间间隔
#define TransmitTo123Loop(senddelay,overdelay)     {SendToT123Loop = senddelay; SendToT123Delay = overdelay; fifo_in(&SendBuff); }
//#define Transmit_Data_Sci1(x,y)   Transmit_Data_To123(x,y)

#define SendToDP()   fifo_in(&SendBuff)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __T123AI_H__ */

