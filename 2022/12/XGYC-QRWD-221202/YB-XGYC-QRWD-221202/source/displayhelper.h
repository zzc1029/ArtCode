/*
 * displayhelper.h
 *
 *  Created on: 2021-11-30
 *      Author: ART
 */

#ifndef DISPLAYHELPER_H_
#define DISPLAYHELPER_H_

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


typedef struct
{
	u32(*operate)(u8 key, u8 initpw);
	uint16_t id;
	uint16_t rever;
} DisMenuStruct;




#define _IN
#define _OUT

#define Main_Data

typedef void (*SendPackFunc)(u8 initpw);


#define DP_DATA1 Send_To_DP_Data[3]
#define DP_DATA2 Send_To_DP_Data[4]
#define DP_DATA3 Send_To_DP_Data[5]
#define DP_DATA4 Send_To_DP_Data[6]
#define DP_DATA5 Send_To_DP_Data[7]
#define DP_DATA6 Send_To_DP_Data[8]
#define DP_DATA7 Send_To_DP_Data[9]
#define DP_DATA8 Send_To_DP_Data[10]

//下面两个宏用于简化申明前必须在同一个文件中使用 SendGroup_Sendfuncs 声明函数数组如下
//SendGroup_Init(PAGE_MAIN)
//{
//	display_time_bar_soc,
//	Display_Symbol_Information,
//	display_total_miles
//};
//SendGroup_CodeGen(PAGE_MAIN);

#define SendGroup_Init(GROUP_NAME)		SendPackFunc GROUP_NAME##_Sendfuncs[] =
	
#define SendGroup_CodeGen(GROUP_NAME)											\
void GROUP_NAME##_Send(u8 initpw)												\
{																				\
	u8 i=0;																		\
    static u8 fan = 0;															\
    if(fan>= (sizeof(GROUP_NAME##_Sendfuncs)/sizeof(SendPackFunc)))				\
    	fan = 0;																\
																				\
    if(initpw)																	\
    {																			\
		for(i=0;i<(sizeof(GROUP_NAME##_Sendfuncs)/sizeof(SendPackFunc));i++)	\
			(*(GROUP_NAME##_Sendfuncs[i]))(initpw);								\
    }																			\
	else 																		\
    	(*(GROUP_NAME##_Sendfuncs[fan]))(0);									\
    																			\
    fan++;																		\
}																				\

#define  SendGroup(GROUP_NAME,initpw) 		GROUP_NAME##_Send(initpw)
#define  SendGroup_Extern(GROUP_NAME) 		extern void GROUP_NAME##_Send(u8 initpw);					


#define utostrbcd()                         \
                                            \
{                                           \
        u8 tempx[10] = {0};                 \
        u8 i,j,k,option=11;/*空格*/         \
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


#define SendStart()                                                    \
    u8 i;                                                              \
    u8 change = 0;                                                     \
    static u8 data1save[11]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};                                           \
    for(i = 1; i < 12; i++)                                            \
        Send_To_DP_Data[i] = 0;


#define SendEndPlus(timeout100ms)                                               \
    do {                                                                    \
        static u8 timeoutxxxxxxx;               \
        u8 change = 0;                                                      \
        timeoutxxxxxxx ++;                                                  \
                                                                            \
        for(i=3; i<11; i++)                                                 \
        {                                                                   \
            if(data1save[i] != Send_To_DP_Data[i])                    \
            {                                                               \
                data1save[i] = Send_To_DP_Data[i];                    \
                change ++;                                                  \
            }                                                               \
        }                                                                   \
        if(timeoutxxxxxxx >= (timeout100ms))                                \
        {                                                                   \
            timeoutxxxxxxx = 0;                                             \
            SendToDP();                   \
        }                                                                   \
        else                                                                \
        {                                                                   \
            if((change>0) ||(initpw))                                       \
            {                                                               \
                SendToDP();               \
                timeoutxxxxxxx = Send_To_DP_Data[2];                  \
            }                                                               \
        }                                                                   \
    } while(0)



#define SendEnd()                                                      \
                                                                       \
    for(i=3; i<11; i++)                                                \
    {                                                                  \
        if(data1save[i] != Send_To_DP_Data[i])                   \
        {                                                              \
            data1save[i] = Send_To_DP_Data[i];                   \
            change ++;                                                 \
        }                                                              \
    }                                                                  \
    if((change>0) ||(initpw))                                          \
    {    															   \
		SendToDP();													   \
    }																   


enum{
	TV1,
	TV2,
	TV3,
	TV4,
	TVNo,
};  

enum
{
  Meter_B50 = 0x00,
  front_in,
  front_out,  
  rear_in,
  rear_out,
  
  top_in,
  
  top_out
};



#define MAXDISMENU 25

extern u8 ClearBufferDisable;

#define SystemChangePage(page)  {ClearBufferDisable = 1;ChangeToPage(page);ClearBufferDisable = 0;}

extern void ChangeToSubPageCache(uint8_t menu, uint8_t subpage);
void ChangeToSubPage(uint8_t menu, uint8_t subpage);
void Constant_display_Task();


//函数
extern void ChangeToPage(u8 m);
extern void AddMenu(u32 (*operate)(u8 key, u8 initpw),u32 id);

extern void clr_trip(void);
extern void display_task();
void SendKeyToGPU(u8 key);

extern void u32tostr(u32 dataxxx,u8 * out,u8 optionx,u8 CharNum);

extern void roll_alarm_Task(void); //2000ms

extern void SetHightLightSymbl();
extern uint16_t GetWenziWarnCode(uint16_t count);

void InitDisplayHelper(void);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */



#endif /* DISPLAYHELPER_H_ */
