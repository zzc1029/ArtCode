#include "../src/defs.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

/********************************************������ϸ����*******************************************************/
//<o>�汾�ź�׺ 
// <i> �汾�ŵ����ֲ���
// <100001-999999>
#define ORDER_VERSION  100005

//<c1> PWMʱ�����ù��ܿ���
// <i> �򿪺󣬿���ͨ��0x6FX�������ø������PWM����ʱ��
//#define PWMTIME_SET_ENABLE
//</c>


//<c1> ����ֵ���Ϳ���
// <i> �򿪺󣬷���������ͨ�����ķ��ͳ�ȥ
#define CURRENT_SEND  
//</c>

#undef PLUSE
//<o>�������� 
// <i> �������� ���999
// <0000-9999>
#define PLUSE 1520


//<o>A25 ����������
// <i> Ĭ���ǵ�����
// <0=> ��ѹ��
// <1000=> ������
// <10000=> 10K����������
#define SENSE_SER1_P25_SET  0

//<o>A40 ����������
// <i> Ĭ���ǵ�����
// <0=> ��ѹ��
// <1000=> ������
// <10000=> 10K����������
#define SENSE_SER2_P40_SET  0

//<e>���ʹ��
// <i>���ʹ��
#define SUPPORT_WIPER 1

//<c1> ��ι���CAN���ƿ���
// <i> �򿪺�, ����ͨ����0x06A4����byte7.bit2����Ϊ1���ر���ι���,�ͷ�ģ��1��A1��A9��
//#define WIPER_DISABLE_BY_CAN  
//</c>
//</e>

//<e>���Ǳ��������
#define NORMAL_OUT 0
#if NORMAL_OUT > 0
	//<e>ģ��1��ǰģ�飩�����ʹ��
	//<s>ģ��1��ǰģ�飩�������
	//<i>���볣����˿ڣ��ÿո���ֿ�������A05 A07 A42
	#define NORMAL_MOD1 0
	#if NORMAL_MOD1 > 0
		#define NORMOL_OUTS_MOD1 ""
	#endif
	//</e>

	//<e>ģ��2����ģ�飩�����ʹ��
	//<s>ģ��2����ģ�飩�������
	//<i>���볣����˿ڣ��ÿո���ֿ�������A05 A07 A42
	#define NORMAL_MOD2 0
	#if NORMAL_MOD2 > 0
		#define NORMOL_OUTS_MOD2 ""
	#endif
	//</e>

	//<e>ģ��3����ģ�飩�����ʹ��
	//<s>ģ��3����ģ�飩�������
	//<i>���볣����˿ڣ��ÿո���ֿ�������A05 A07 A42
	#define NORMAL_MOD3 0
	#if NORMAL_MOD3 > 0
		#define NORMOL_OUTS_MOD3 ""
	#endif
	//</e>
	
	//<e>ģ��4����2ģ�飩�����ʹ��
	//<s>ģ��4����2ģ�飩�������
	//<i>���볣����˿ڣ��ÿո���ֿ�������A05 A07 A42
	#define NORMAL_MOD4 0
	#if NORMAL_MOD4 > 0
		#define NORMOL_OUTS_MOD4 ""
	#endif
	//</e>
#endif
//</e>

//<e>���Ǳ�ģ���Զ����ƹ�������
#define SELF_CONTROL 0
#if SELF_CONTROL > 0

//<h> ����״̬��������
	//<c> ʹ��ģ��1����״̬����
	//#define MOD1_SW_DATA
	//</c>
	//<c> ʹ��ģ��2����״̬����
	//#define MOD2_SW_DATA
	//</c>
	//<c> ʹ��ģ��3����״̬����
	//#define MOD3_SW_DATA
	//</c>
	//<c> ʹ��ģ��4����״̬����
	//#define MOD4_SW_DATA
	//</c>
//</h>

//<h>���Ǳ�ģ���Զ����ƽ�����
	//<e>ģ��1��ǰģ�飩�Կ����ʹ��
	//<s>ģ��1��ǰģ�飩�Կ������
	//<i>����˿ڣ��ÿո���ֿ�������A05 A07 A42
	#define LOGIC_MOD1 0
	#if LOGIC_MOD1 > 0
		#define LOGIC_OUTS_MOD1 "A05 A07 A42"
	#endif
	//</e>

	//<e>ģ��2����ģ�飩�Կ����ʹ��
	//<s>ģ��2����ģ�飩�Կ������
	//<i>����˿ڣ��ÿո���ֿ�������A05 A07 A42
	#define LOGIC_MOD2 0
	#if LOGIC_MOD2 > 0
		#define LOGIC_OUTS_MOD2 "A05 A07 A42"
	#endif
	//</e>

	//<e>ģ��3����ģ�飩�Կ����ʹ��
	//<s>ģ��3����ģ�飩�Կ������
	//<i>����˿ڣ��ÿո���ֿ�������A05 A07 A42
	#define LOGIC_MOD3 0
	#if LOGIC_MOD3 > 0
		#define LOGIC_OUTS_MOD3 "A05 A07 A42"
	#endif
	//</e>
	
	//<e>ģ��4����2ģ�飩�Կ����ʹ��
	//<s>ģ��4����2ģ�飩�Կ������
	//<i>����˿ڣ��ÿո���ֿ�������A05 A07 A42
	#define LOGIC_MOD4 0
	#if LOGIC_MOD4 > 0
		#define LOGIC_OUTS_MOD4 "A05 A07 A42"
	#endif
	//</e>
//</h>

//<h> �Կ��߼�
//<i> ���Ǳ�ʱ�Զ������߼�ѡ��
//<o> �ſ��߼�����
// <i> door control logic enable
// <0=> �߼�1
// <1=> �߼�2
// <2=> �߼�3
// <4=> �߼�4
// <5=> 220315�����߼�
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

//<c1> ģ��3 A1��ʱ���ر�A8�����������ɶ�825̨ר��
// <i> Ŀǰֻ�гɶ�����ʹ��
//#define LOGIC3
//</c>
//</h>

#ifdef LOGIC5
	#define KEY_SOS_ENABLE
#endif
#endif
//</e>


//*** <<< end of configuration section >>>    ***


