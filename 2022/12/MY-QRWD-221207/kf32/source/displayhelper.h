/*
 * displayhelper.h
 *
 *  Created on: 2021-7-27
 *      Author: ART
 */

#ifndef __DISPLAYHELPER_H__
#define __DISPLAYHELPER_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */


//�˴�����display�ļ�����Ӳ˵�����
#define DISPLAYTASKNUM 8

#define  FRONT_MODULE  0X01
#define  REAR_MODULE   0X02
#define  TOP_MODULE    0x03

enum
{
    TVNo = 0,
    TV1 = 1,
    TV2,
    TV3,
    TV4
};


#define utostrbcd()                         \
                                            \
{                                           \
        u8 tempx[10] = {0};                 \
        u8 i,j,k,option=11;/*�ո�*/         \
                                            \
        if(optionx)                         \
            option = 0;/*0*/                \
                                            \
        for(i=0; dataxxx>0; dataxxx/=10)    \
        {                                   \
            tempx[i++] = dataxxx%10;        \
        }                                   \
        if(i == 0)                          \
        {                                   \
            tempx[i++] = 0;                 \
        }                                   \
                                            \
        if(CharNum >= i)                    \
        {                                   \
            k = CharNum-i;                  \
            for(j=0; j<CharNum; j++)        \
            {                               \
                if(j<k)                     \
                    out[j] = option;        \
                else                        \
                    out[j] = tempx[--i];    \
            }                               \
        }                                   \
        else                                \
        {                                   \
            for(j=0;j<CharNum;j++)          \
                    out[j] = 11;            \
            out[1] = 10;                    \
                                            \
        }                                   \
}

#define ChangeToSetPage(page)  {SetOption = page;ChangeToPage(PAGE_ARTSET);SetOption = 0;}

enum
{
	DIS_MAIN_MENU = 0x00,
	DIS_HELP_MENU,
	DIS_FACTORY_SET_MENU,   //ϵͳ����
	DIS_SYSTEM_SET_MENU,    //�Ǳ����
	DIS_SELFTEST_MENU,      //�Լ�˵�

	//#if(DISPLAYTASKNUM > 8)
   // DIS_PAGE9_MENU,
    //#endif
	//#if(DISPLAYTASKNUM > 0)
   // DIS_PAGE1_MENU,
    //#endif
	#if(DISPLAYTASKNUM > 1)
    DIS_PAGE2_MENU,
    #endif
	#if(DISPLAYTASKNUM > 2)
    DIS_PAGE3_MENU,
    #endif
	#if(DISPLAYTASKNUM > 3)
    DIS_PAGE4_MENU,
    #endif
	#if(DISPLAYTASKNUM > 4)
    DIS_PAGE5_MENU,
    #endif
	#if(DISPLAYTASKNUM > 5)
    DIS_PAGE6_MENU,
    #endif
	#if(DISPLAYTASKNUM > 6)
    DIS_PAGE7_MENU,
    #endif
	#if(DISPLAYTASKNUM > 7)
    DIS_PAGE8_MENU,
    #endif

	#if(DISPLAYTASKNUM > 9)
    DIS_PAGEA_MENU,  
    #endif
	#if(DISPLAYTASKNUM > 10)
    DIS_PAGEB_MENU,  
    #endif
	DIS_ART_INFORMATION,
    //�˵�ҳ��
	DIS_CHOOSE_MENU,	
	//����ͷ
    DIS_VEDIO,
	//������
	DIS_CHARGE_MENU,
	//��Դ����
	DIS_POWER_MENU,
	//�ȴ�����  ����SYSTEM�����������,������ON���Լ�ƹ�
	DIS_NOP_MENU,
};

enum
{
	PAGE_MAIN = 0x01,
	PAGE_MENU,
	PAGE_ACC,
	PAGE_ARTSET,
	PAGE_ARTHELP,
	PAGE_ARTAV,
	PAGE_METER,
	PAGE_FMODE,
	PAGE_RMODE,
	PAGE_TMODE,
	PAGE_0x20 = 0x20,
	PAGE_0x21,
	PAGE_0x22,
	PAGE_0x23,
	PAGE_0x24,
	PAGE_0x25,
	PAGE_0x26,
	PAGE_0x27,
	PAGE_0x28,
	PAGE_0x29,
	PAGE_0x2A,
	PAGE_0x2B,
	PAGE_0x2C,
	PAGE_0x2D,
	PAGE_0x2E,
	PAGE_0x2F,
	PAGE_0x30,
	PAGE_0x31,
	PAGE_METER_ADD = 0x32,
};
enum
{
	PassWordPage = 1, //�����������
	NoEncryptSetPage,  //�Ǳ��ܽ���
	EncryptSetPage,   //�������ý���
	KehuEncryptSetPage   //�ͻ��������ý��� 
};


void SaveODO(void);

void InitDisplayHelper();
void display_task(void);


void roll_alarm_Task(void); //200ms
void ChangeToPage(uint8_t menu);
void AddMenu(u32 (*operate)(u8 key, u8 initpw),u32 id);





















#endif
