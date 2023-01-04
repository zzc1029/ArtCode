/******************************************************************************

                  ��Ȩ���� (C), 2015 - 2020  ART. All Rights Reserved, ART

 ******************************************************************************
  �� �� ��   : T123AI.h
  �� �� ��   : ����
  ��    ��   : stan
  ��������   : 2016��2��15��
  ����޸�   :
  ��������   : T123AI.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2016��2��15��
    ��    ��   : stan
    �޸�����   : �����ļ�

******************************************************************************/

/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �ⲿ����˵��                                 *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �ⲿ����ԭ��˵��                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �ڲ�����ԭ��˵��                             *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ȫ�ֱ���                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ģ�鼶����                                   *
 *----------------------------------------------*/

/*----------------------------------------------*
 * ��������                                     *
 *----------------------------------------------*/

/*----------------------------------------------*
 * �궨��                                       *
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
	int ovfcount; //��������ʧ
	int errcount; //���ͳ������Դ���
	SendToT123Stru * buff;
	int max_len;
} SendToT123X;

extern SendToT123X SendBuff;
extern u8 SendToT123Loop;
extern u8 SendToT123Delay;

//����
extern uint32_t fifo_in(SendToT123X*fifo);
extern void fifo_init(SendToT123X* fifo,SendToT123Stru*buff,uint32_t len);
extern uint32_t fifo_out(SendToT123X *fifo);
extern void fifo_reset(SendToT123X*fifo);

///10ms-20ms����һ��
extern void SendToT123();

extern void InitSendToT123();

extern void fifo_set_free(SendToT123X*fifo);

#define Fifo_set_free() 		fifo_set_free(&SendBuff)
#define Transmit_Data_Sci1(x,y)   fifo_in(&SendBuff)

//��������:
//senddelay:����������ÿ�η���֮�����ʱ��������λ��SendToT123()��������ʱ����
//overdelay:��������֮�����ʱ��������λ��SendToT123()��������ʱ����
#define TransmitTo123Loop(senddelay,overdelay)     {SendToT123Loop = senddelay; SendToT123Delay = overdelay; fifo_in(&SendBuff); }
//#define Transmit_Data_Sci1(x,y)   Transmit_Data_To123(x,y)

#define SendToDP()   fifo_in(&SendBuff)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __T123AI_H__ */

