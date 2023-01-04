#ifndef __TEST_H__
#define __TEST_H__

#include "defs.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

#define NORMAL_QRWD  		100001   //����� ����ʽ������ B40 ģ��
#define NORMAL_VOL  		100002   //����� ��ѹʽ������ B40 ģ��
#define NORMAL_RES 			100003   //����� ����ʽ������ ��ֵ 1K B40 ģ��
#define NORMAL_RES_10K 	100004   //����� ����ʽ������ ��ֵ 10K B40 ģ��


/********************************************�������*******************************************************/
//���Կ���
// <c1> Enable Debug 
// <i> Enable Debug 
//#define DEBUG //�򿪵���Ӳ����Ϊ����ģ��
// </c>


//��ѡ������
// <c1> Eanble Output Max Retry Count Reset
// <i> then max retry count is reset when key_on is invalid
//#define  PROTECTION_MAX_RETRY_COUNT_RESET   //��·���Լ�����λ���Ǳ�6A4������ʧ��ON����ACC����ʧ��͹رչ������һ��λ��
// </c>


//#define CURRENT_SEND  //��������ֵ�������������ʹ��,��Ҫ����������

//  <o>Pluse 
//  <i>  Pluse per 100m ��������
#define PLUSE 4800

// ���ʹ��
//����߼���
//����
//��ˮ�˿��Ǳ����ʹ��λ��0x06A4 ���� Byte6 bit6 ����Ч  //�ߵĻ� ��ˮ�˿����Ǳ�6A4���ƣ�ģ�鲻д���˿ڣ�ר�����������ˮ���ܿصĶ���
//��ɲPWMʹ��λ��0x06A4 ���� Byte7 bit1 ����Ч
//��ɲʹ��λ��0x06A4 ���� Byte7 bit0 ����Ч
//��ɲ�����ӳ�ʱ�䣺0x06A4 ���� Byte7 bit4-7 ��λ20ms������20ms�Զ�������20ms
// <c1> SUPPORT_WIPER 
// <i> wiper function enable
#define SUPPORT_WIPER 1//��ο��ƹ��ܿ���
// </c>

//�����ͨ�����Ĺر�
//��ι���ʧ��λ��0x06A4 ���� Byte7 bit2 ����Ч  //�ߵĻ� �����  ��ʵ��
// <c1> WIPER_DISABLE_BY_CAN
// <i> If selected, you can turn off the wiper function by sending 0x06A4 messages with data[7].bit2 = 1.
//#define WIPER_DISABLE_BY_CAN  
// </c>



// <c1> PWMTIME_SET_ENABLE
// <i> Enable can set pwm param 
//#define PWMTIME_SET_ENABLE
// </c>


//#define ORDER_VERSION NORMAL_VOL          //��ѹʽ������
//#define ORDER_VERSION NORMAL_RES          //����ʽ������ 1K����
//#define ORDER_VERSION NORMAL_RES_10K      //����ʽ������ 10K����
//#define ORDER_VERSION NORMAL_QRWD  				//������������ ���� ��ѹʽ
#define ORDER_VERSION 220102    //CD-ZZ-220102 ���� 220415 һ��
//#define ORDER_VERSION 220308    //LA-ZZ-220308 ����
//#define ORDER_VERSION 220315    //220315 ����
//#define ORDER_VERSION == 211101  //�ʶ���������,ǿ�ƴ�ģ��3��A01��PWM����


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

#define MOD4_CD   //���4ģ�鶩������

#define NORMOL_OUTS_MOD2 "A05"   				

/***********************************************�Զ�Э�����**********************************************************/
//#define LOGIC  //���ԿصĹ��ܣ�ACC��ON��Чʱ���߼���������XMJL�ĳ���
//#define LOGIC1  //���Կع��ܣ��ɶ�����
#define LOGIC2  //���Կع��ܣ��ɶ�����
#define LOGIC3

#define LOGIC_OUTS_MOD2 "A02 A03"  //���ԿصĹ��ܣ�ACC��ON��Чʱ���ڲ����

#define SENSE_SER1_P25_SET  TYPE_VOL
#define SENSE_SER2_P40_SET  TYPE_RES

#ifdef LOGIC1
#define MOD1_SW_DATA
#endif

#endif
#if ORDER_VERSION == NORMAL_QRWD
	//�ر�ĵط�������Ҫ���͵���
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

