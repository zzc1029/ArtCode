# 1 "RTE\\SEGGER\\SEGGER_RTT.c"










































































 

# 1 "RTE\\SEGGER\\SEGGER_RTT.h"























































 




# 1 "RTE\\SEGGER\\SEGGER_RTT_Conf.h"























































 














 



























































 
































 
# 251 "RTE\\SEGGER\\SEGGER_RTT_Conf.h"




 
# 306 "RTE\\SEGGER\\SEGGER_RTT_Conf.h"




 
# 320 "RTE\\SEGGER\\SEGGER_RTT_Conf.h"




 
# 334 "RTE\\SEGGER\\SEGGER_RTT_Conf.h"




 
# 347 "RTE\\SEGGER\\SEGGER_RTT_Conf.h"

# 367 "RTE\\SEGGER\\SEGGER_RTT_Conf.h"




 
# 393 "RTE\\SEGGER\\SEGGER_RTT_Conf.h"




 
# 408 "RTE\\SEGGER\\SEGGER_RTT_Conf.h"





 
# 425 "RTE\\SEGGER\\SEGGER_RTT_Conf.h"




 









 
# 62 "RTE\\SEGGER\\SEGGER_RTT.h"






 
# 125 "RTE\\SEGGER\\SEGGER_RTT.h"
    
    
    
# 146 "RTE\\SEGGER\\SEGGER_RTT.h"
  
  
  
# 158 "RTE\\SEGGER\\SEGGER_RTT.h"










# 175 "RTE\\SEGGER\\SEGGER_RTT.h"





# 192 "RTE\\SEGGER\\SEGGER_RTT.h"

# 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
 
 
 




 
 



 






   














  


 








# 54 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


  



    typedef unsigned int size_t;    
# 70 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"






    



    typedef unsigned short wchar_t;  
# 91 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"

typedef struct div_t { int quot, rem; } div_t;
    
typedef struct ldiv_t { long int quot, rem; } ldiv_t;
    

typedef struct lldiv_t { long long quot, rem; } lldiv_t;
    


# 112 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   



 

   




 
# 131 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"
   


 
extern __declspec(__nothrow) int __aeabi_MB_CUR_MAX(void);

   




 

   




 




extern __declspec(__nothrow) double atof(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int atoi(const char *  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) long int atol(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) long long atoll(const char *  ) __attribute__((__nonnull__(1)));
   



 


extern __declspec(__nothrow) double strtod(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

















 

extern __declspec(__nothrow) float strtof(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) long double strtold(const char * __restrict  , char ** __restrict  ) __attribute__((__nonnull__(1)));
   

 

extern __declspec(__nothrow) long int strtol(const char * __restrict  ,
                        char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   



























 
extern __declspec(__nothrow) unsigned long int strtoul(const char * __restrict  ,
                                       char ** __restrict  , int  ) __attribute__((__nonnull__(1)));
   


























 

 
extern __declspec(__nothrow) long long strtoll(const char * __restrict  ,
                                  char ** __restrict  , int  )
                          __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) unsigned long long strtoull(const char * __restrict  ,
                                            char ** __restrict  , int  )
                                   __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) int rand(void);
   







 
extern __declspec(__nothrow) void srand(unsigned int  );
   






 

struct _rand_state { int __x[57]; };
extern __declspec(__nothrow) int _rand_r(struct _rand_state *);
extern __declspec(__nothrow) void _srand_r(struct _rand_state *, unsigned int);
struct _ANSI_rand_state { int __x[1]; };
extern __declspec(__nothrow) int _ANSI_rand_r(struct _ANSI_rand_state *);
extern __declspec(__nothrow) void _ANSI_srand_r(struct _ANSI_rand_state *, unsigned int);
   


 

extern __declspec(__nothrow) void *calloc(size_t  , size_t  );
   



 
extern __declspec(__nothrow) void free(void *  );
   





 
extern __declspec(__nothrow) void *malloc(size_t  );
   



 
extern __declspec(__nothrow) void *realloc(void *  , size_t  );
   













 

extern __declspec(__nothrow) int posix_memalign(void **  , size_t  , size_t  );
   









 

typedef int (*__heapprt)(void *, char const *, ...);
extern __declspec(__nothrow) void __heapstats(int (*  )(void *  ,
                                           char const *  , ...),
                        void *  ) __attribute__((__nonnull__(1)));
   










 
extern __declspec(__nothrow) int __heapvalid(int (*  )(void *  ,
                                           char const *  , ...),
                       void *  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) __declspec(__noreturn) void abort(void);
   







 

extern __declspec(__nothrow) int atexit(void (*  )(void)) __attribute__((__nonnull__(1)));
   




 
# 436 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


extern __declspec(__nothrow) __declspec(__noreturn) void exit(int  );
   












 

extern __declspec(__nothrow) __declspec(__noreturn) void _Exit(int  );
   







      

extern __declspec(__nothrow) char *getenv(const char *  ) __attribute__((__nonnull__(1)));
   









 

extern __declspec(__nothrow) int  system(const char *  );
   









 

extern  void *bsearch(const void *  , const void *  ,
              size_t  , size_t  ,
              int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,2,5)));
   












 
# 524 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"


extern  void qsort(void *  , size_t  , size_t  ,
           int (*  )(const void *, const void *)) __attribute__((__nonnull__(1,4)));
   









 

# 553 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"

extern __declspec(__nothrow) __attribute__((const)) int abs(int  );
   



 

extern __declspec(__nothrow) __attribute__((const)) div_t div(int  , int  );
   









 
extern __declspec(__nothrow) __attribute__((const)) long int labs(long int  );
   



 




extern __declspec(__nothrow) __attribute__((const)) ldiv_t ldiv(long int  , long int  );
   











 







extern __declspec(__nothrow) __attribute__((const)) long long llabs(long long  );
   



 




extern __declspec(__nothrow) __attribute__((const)) lldiv_t lldiv(long long  , long long  );
   











 
# 634 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"




 
typedef struct __sdiv32by16 { int quot, rem; } __sdiv32by16;
typedef struct __udiv32by16 { unsigned int quot, rem; } __udiv32by16;
    
typedef struct __sdiv64by32 { int rem, quot; } __sdiv64by32;

__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv32by16 __rt_sdiv32by16(
     int  ,
     short int  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __udiv32by16 __rt_udiv32by16(
     unsigned int  ,
     unsigned short  );
   

 
__value_in_regs extern __declspec(__nothrow) __attribute__((const)) __sdiv64by32 __rt_sdiv64by32(
     int  , unsigned int  ,
     int  );
   

 




 
extern __declspec(__nothrow) unsigned int __fp_status(unsigned int  , unsigned int  );
   







 























 
extern __declspec(__nothrow) int mblen(const char *  , size_t  );
   












 
extern __declspec(__nothrow) int mbtowc(wchar_t * __restrict  ,
                   const char * __restrict  , size_t  );
   















 
extern __declspec(__nothrow) int wctomb(char *  , wchar_t  );
   













 





 
extern __declspec(__nothrow) size_t mbstowcs(wchar_t * __restrict  ,
                      const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 
extern __declspec(__nothrow) size_t wcstombs(char * __restrict  ,
                      const wchar_t * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   














 

extern __declspec(__nothrow) void __use_realtime_heap(void);
extern __declspec(__nothrow) void __use_realtime_division(void);
extern __declspec(__nothrow) void __use_two_region_memory(void);
extern __declspec(__nothrow) void __use_no_heap(void);
extern __declspec(__nothrow) void __use_no_heap_region(void);

extern __declspec(__nothrow) char const *__C_library_version_string(void);
extern __declspec(__nothrow) int __C_library_version_number(void);











# 892 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdlib.h"





 
# 195 "RTE\\SEGGER\\SEGGER_RTT.h"
# 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"
 
 
 





 










# 27 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"








 

 
 
# 57 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"
    typedef struct __va_list { void *__ap; } va_list;

   






 


   










 


   















 




   

 


   




 



   





 








      
     typedef  va_list __gnuc_va_list;






# 147 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\stdarg.h"

 

# 196 "RTE\\SEGGER\\SEGGER_RTT.h"






 








# 218 "RTE\\SEGGER\\SEGGER_RTT.h"






 





typedef struct {
  const     char*    sName;         
            char*    pBuffer;       
            unsigned SizeOfBuffer;  
            unsigned WrOff;         
  volatile  unsigned RdOff;         
            unsigned Flags;         
} SEGGER_RTT_BUFFER_UP;





typedef struct {
  const     char*    sName;         
            char*    pBuffer;       
            unsigned SizeOfBuffer;  
  volatile  unsigned WrOff;         
            unsigned RdOff;         
            unsigned Flags;         
} SEGGER_RTT_BUFFER_DOWN;






typedef struct {
  char                    acID[16];                                 
  int                     MaxNumUpBuffers;                          
  int                     MaxNumDownBuffers;                        
  SEGGER_RTT_BUFFER_UP    aUp[(1)];       
  SEGGER_RTT_BUFFER_DOWN  aDown[(1)];   



} SEGGER_RTT_CB;






 
extern SEGGER_RTT_CB _SEGGER_RTT;






 



int          SEGGER_RTT_AllocDownBuffer         (const char* sName, void* pBuffer, unsigned BufferSize, unsigned Flags);
int          SEGGER_RTT_AllocUpBuffer           (const char* sName, void* pBuffer, unsigned BufferSize, unsigned Flags);
int          SEGGER_RTT_ConfigUpBuffer          (unsigned BufferIndex, const char* sName, void* pBuffer, unsigned BufferSize, unsigned Flags);
int          SEGGER_RTT_ConfigDownBuffer        (unsigned BufferIndex, const char* sName, void* pBuffer, unsigned BufferSize, unsigned Flags);
int          SEGGER_RTT_GetKey                  (void);
unsigned     SEGGER_RTT_HasData                 (unsigned BufferIndex);
int          SEGGER_RTT_HasKey                  (void);
unsigned     SEGGER_RTT_HasDataUp               (unsigned BufferIndex);
void         SEGGER_RTT_Init                    (void);
unsigned     SEGGER_RTT_Read                    (unsigned BufferIndex,       void* pBuffer, unsigned BufferSize);
unsigned     SEGGER_RTT_ReadNoLock              (unsigned BufferIndex,       void* pData,   unsigned BufferSize);
int          SEGGER_RTT_SetNameDownBuffer       (unsigned BufferIndex, const char* sName);
int          SEGGER_RTT_SetNameUpBuffer         (unsigned BufferIndex, const char* sName);
int          SEGGER_RTT_SetFlagsDownBuffer      (unsigned BufferIndex, unsigned Flags);
int          SEGGER_RTT_SetFlagsUpBuffer        (unsigned BufferIndex, unsigned Flags);
int          SEGGER_RTT_WaitKey                 (void);
unsigned     SEGGER_RTT_Write                   (unsigned BufferIndex, const void* pBuffer, unsigned NumBytes);
unsigned     SEGGER_RTT_WriteNoLock             (unsigned BufferIndex, const void* pBuffer, unsigned NumBytes);
unsigned     SEGGER_RTT_WriteSkipNoLock         (unsigned BufferIndex, const void* pBuffer, unsigned NumBytes);
unsigned     SEGGER_RTT_ASM_WriteSkipNoLock     (unsigned BufferIndex, const void* pBuffer, unsigned NumBytes);
unsigned     SEGGER_RTT_WriteString             (unsigned BufferIndex, const char* s);
void         SEGGER_RTT_WriteWithOverwriteNoLock(unsigned BufferIndex, const void* pBuffer, unsigned NumBytes);
unsigned     SEGGER_RTT_PutChar                 (unsigned BufferIndex, char c);
unsigned     SEGGER_RTT_PutCharSkip             (unsigned BufferIndex, char c);
unsigned     SEGGER_RTT_PutCharSkipNoLock       (unsigned BufferIndex, char c);
unsigned     SEGGER_RTT_GetAvailWriteSpace      (unsigned BufferIndex);
unsigned     SEGGER_RTT_GetBytesInBuffer        (unsigned BufferIndex);














 
unsigned     SEGGER_RTT_ReadUpBuffer            (unsigned BufferIndex, void* pBuffer, unsigned BufferSize);
unsigned     SEGGER_RTT_ReadUpBufferNoLock      (unsigned BufferIndex, void* pData, unsigned BufferSize);
unsigned     SEGGER_RTT_WriteDownBuffer         (unsigned BufferIndex, const void* pBuffer, unsigned NumBytes);
unsigned     SEGGER_RTT_WriteDownBufferNoLock   (unsigned BufferIndex, const void* pBuffer, unsigned NumBytes);








 
int     SEGGER_RTT_SetTerminal        (unsigned char TerminalId);
int     SEGGER_RTT_TerminalOut        (unsigned char TerminalId, const char* s);
int     SEGGER_RTT_TerminalPrintf     (unsigned TerminalId, const char * sFormat, ...);






 
int SEGGER_RTT_printf(unsigned BufferIndex, const char * sFormat, ...);
int SEGGER_RTT_vprintf(unsigned BufferIndex, const char * sFormat, va_list * pParamList);












 
















# 389 "RTE\\SEGGER\\SEGGER_RTT.h"

# 398 "RTE\\SEGGER\\SEGGER_RTT.h"

# 407 "RTE\\SEGGER\\SEGGER_RTT.h"

# 416 "RTE\\SEGGER\\SEGGER_RTT.h"




 
# 78 "RTE\\SEGGER\\SEGGER_RTT.c"

# 1 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
 
 
 
 




 








 












# 38 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"


  



    typedef unsigned int size_t;    
# 54 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"




extern __declspec(__nothrow) void *memcpy(void * __restrict  ,
                    const void * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) void *memmove(void *  ,
                    const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   







 
extern __declspec(__nothrow) char *strcpy(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncpy(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 

extern __declspec(__nothrow) char *strcat(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncat(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 






 

extern __declspec(__nothrow) int memcmp(const void *  , const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strcmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int strncmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcasecmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strncasecmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcoll(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   







 

extern __declspec(__nothrow) size_t strxfrm(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   













 


# 193 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) void *memchr(const void *  , int  , size_t  ) __attribute__((__nonnull__(1)));

   





 

# 209 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   




 

extern __declspec(__nothrow) size_t strcspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 

# 232 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strpbrk(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   




 

# 247 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strrchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   





 

extern __declspec(__nothrow) size_t strspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   



 

# 270 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strstr(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   





 

extern __declspec(__nothrow) char *strtok(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) char *_strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

extern __declspec(__nothrow) char *strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

   

































 

extern __declspec(__nothrow) void *memset(void *  , int  , size_t  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) char *strerror(int  );
   





 
extern __declspec(__nothrow) size_t strlen(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) size_t strlcpy(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   
















 

extern __declspec(__nothrow) size_t strlcat(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






















 

extern __declspec(__nothrow) void _membitcpybl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpybb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
    














































 







# 502 "C:\\Keil_v5\\ARM\\ARMCC\\Bin\\..\\include\\string.h"



 

# 80 "RTE\\SEGGER\\SEGGER_RTT.c"






 

# 108 "RTE\\SEGGER\\SEGGER_RTT.c"























































# 170 "RTE\\SEGGER\\SEGGER_RTT.c"




















 




# 210 "RTE\\SEGGER\\SEGGER_RTT.c"

# 225 "RTE\\SEGGER\\SEGGER_RTT.c"































 

static unsigned char _aTerminalId[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };






 




SEGGER_RTT_CB _SEGGER_RTT;
static char _acUpBuffer [((256))];
static char _acDownBuffer[((16))];

static unsigned char _ActiveTerminal;






 









 
# 301 "RTE\\SEGGER\\SEGGER_RTT.c"

static void _DoInit(void) {
  volatile SEGGER_RTT_CB* p;   
  
  
  
  p                     = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0));  
  p->MaxNumUpBuffers    = (1);
  p->MaxNumDownBuffers  = (1);
  
  
  
  p->aUp[0].sName         = "Terminal";
  p->aUp[0].pBuffer       = _acUpBuffer;
  p->aUp[0].SizeOfBuffer  = (256);
  p->aUp[0].RdOff         = 0u;
  p->aUp[0].WrOff         = 0u;
  p->aUp[0].Flags         = 0;
  
  
  
  p->aDown[0].sName         = "Terminal";
  p->aDown[0].pBuffer       = _acDownBuffer;
  p->aDown[0].SizeOfBuffer  = (16);
  p->aDown[0].RdOff         = 0u;
  p->aDown[0].WrOff         = 0u;
  p->aDown[0].Flags         = 0;
  
  
  
  
  
  strcpy(((char*)&p->acID[7]), ("RTT"));
  ;                       
  strcpy(((char*)&p->acID[0]), ("SEGGER"));
  ;                       
  p->acID[6] = ' ';
  ;                       
}



















 
static unsigned _WriteBlocking(SEGGER_RTT_BUFFER_UP* pRing, const char* pBuffer, unsigned NumBytes) {
  unsigned NumBytesToWrite;
  unsigned NumBytesWritten;
  unsigned RdOff;
  unsigned WrOff;
  volatile char* pDst;
  
  
  
  NumBytesWritten = 0u;
  WrOff = pRing->WrOff;
  do {
    RdOff = pRing->RdOff;                         
    if (RdOff > WrOff) {
      NumBytesToWrite = RdOff - WrOff - 1u;
    } else {
      NumBytesToWrite = pRing->SizeOfBuffer - (WrOff - RdOff + 1u);
    }
    NumBytesToWrite = (((NumBytesToWrite) < ((pRing->SizeOfBuffer - WrOff))) ? (NumBytesToWrite) : ((pRing->SizeOfBuffer - WrOff)));      
    NumBytesToWrite = (((NumBytesToWrite) < (NumBytes)) ? (NumBytesToWrite) : (NumBytes));
    pDst = (pRing->pBuffer + WrOff) + (0);
# 389 "RTE\\SEGGER\\SEGGER_RTT.c"
    memcpy(((void*)pDst), (pBuffer), (NumBytesToWrite));
    NumBytesWritten += NumBytesToWrite;
    pBuffer         += NumBytesToWrite;
    NumBytes        -= NumBytesToWrite;
    WrOff           += NumBytesToWrite;

    if (WrOff == pRing->SizeOfBuffer) {
      WrOff = 0u;
    }
    ;                     
    pRing->WrOff = WrOff;
  } while (NumBytes);
  return NumBytesWritten;
}


















 
static void _WriteNoCheck(SEGGER_RTT_BUFFER_UP* pRing, const char* pData, unsigned NumBytes) {
  unsigned NumBytesAtOnce;
  unsigned WrOff;
  unsigned Rem;
  volatile char* pDst;

  WrOff = pRing->WrOff;
  Rem = pRing->SizeOfBuffer - WrOff;
  if (Rem > NumBytes) {
    
    
    
    pDst = (pRing->pBuffer + WrOff) + (0);
# 443 "RTE\\SEGGER\\SEGGER_RTT.c"
    memcpy(((void*)pDst), (pData), (NumBytes));
    ;                     
    pRing->WrOff = WrOff + NumBytes;

  } else {
    
    
    
# 465 "RTE\\SEGGER\\SEGGER_RTT.c"
    NumBytesAtOnce = Rem;
    pDst = (pRing->pBuffer + WrOff) + (0);
    memcpy(((void*)pDst), (pData), (NumBytesAtOnce));
    NumBytesAtOnce = NumBytes - Rem;
    pDst = pRing->pBuffer + (0);
    memcpy(((void*)pDst), (pData + Rem), (NumBytesAtOnce));
    ;                     
    pRing->WrOff = NumBytesAtOnce;

  }
}













 
static void _PostTerminalSwitch(SEGGER_RTT_BUFFER_UP* pRing, unsigned char TerminalId) {
  unsigned char ac[2];

  ac[0] = 0xFFu;
  ac[1] = _aTerminalId[TerminalId];  
  _WriteBlocking(pRing, (const char*)ac, 2u);
}














 
static unsigned _GetAvailWriteSpace(SEGGER_RTT_BUFFER_UP* pRing) {
  unsigned RdOff;
  unsigned WrOff;
  unsigned r;
  
  
  
  
  RdOff = pRing->RdOff;
  WrOff = pRing->WrOff;
  if (RdOff <= WrOff) {
    r = pRing->SizeOfBuffer - 1u - WrOff + RdOff;
  } else {
    r = RdOff - WrOff - 1u;
  }
  return r;
}






 






















 
unsigned SEGGER_RTT_ReadUpBufferNoLock(unsigned BufferIndex, void* pData, unsigned BufferSize) {
  unsigned                NumBytesRem;
  unsigned                NumBytesRead;
  unsigned                RdOff;
  unsigned                WrOff;
  unsigned char*          pBuffer;
  SEGGER_RTT_BUFFER_UP*   pRing;
  volatile char*          pSrc;

  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  pRing = (SEGGER_RTT_BUFFER_UP*)((char*)&_SEGGER_RTT.aUp[BufferIndex] + (0));  
  pBuffer = (unsigned char*)pData;
  RdOff = pRing->RdOff;
  WrOff = pRing->WrOff;
  NumBytesRead = 0u;
  
  
  
  if (RdOff > WrOff) {
    NumBytesRem = pRing->SizeOfBuffer - RdOff;
    NumBytesRem = (((NumBytesRem) < (BufferSize)) ? (NumBytesRem) : (BufferSize));
    pSrc = (pRing->pBuffer + RdOff) + (0);
# 589 "RTE\\SEGGER\\SEGGER_RTT.c"
    memcpy((pBuffer), ((void*)pSrc), (NumBytesRem));
    NumBytesRead += NumBytesRem;
    pBuffer      += NumBytesRem;
    BufferSize   -= NumBytesRem;
    RdOff        += NumBytesRem;

    
    
    
    if (RdOff == pRing->SizeOfBuffer) {
      RdOff = 0u;
    }
  }
  
  
  
  NumBytesRem = WrOff - RdOff;
  NumBytesRem = (((NumBytesRem) < (BufferSize)) ? (NumBytesRem) : (BufferSize));
  if (NumBytesRem > 0u) {
    pSrc = (pRing->pBuffer + RdOff) + (0);
# 617 "RTE\\SEGGER\\SEGGER_RTT.c"
    memcpy((pBuffer), ((void*)pSrc), (NumBytesRem));
    NumBytesRead += NumBytesRem;
    pBuffer      += NumBytesRem;
    BufferSize   -= NumBytesRem;
    RdOff        += NumBytesRem;

  }
  
  
  
  if (NumBytesRead) {
    pRing->RdOff = RdOff;
  }
  
  return NumBytesRead;
}

















 
unsigned SEGGER_RTT_ReadNoLock(unsigned BufferIndex, void* pData, unsigned BufferSize) {
  unsigned                NumBytesRem;
  unsigned                NumBytesRead;
  unsigned                RdOff;
  unsigned                WrOff;
  unsigned char*          pBuffer;
  SEGGER_RTT_BUFFER_DOWN* pRing;
  volatile char*          pSrc;
  
  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  pRing = (SEGGER_RTT_BUFFER_DOWN*)((char*)&_SEGGER_RTT.aDown[BufferIndex] + (0));  
  pBuffer = (unsigned char*)pData;
  RdOff = pRing->RdOff;
  WrOff = pRing->WrOff;
  NumBytesRead = 0u;
  
  
  
  if (RdOff > WrOff) {
    NumBytesRem = pRing->SizeOfBuffer - RdOff;
    NumBytesRem = (((NumBytesRem) < (BufferSize)) ? (NumBytesRem) : (BufferSize));
    pSrc = (pRing->pBuffer + RdOff) + (0);
# 681 "RTE\\SEGGER\\SEGGER_RTT.c"
    memcpy((pBuffer), ((void*)pSrc), (NumBytesRem));
    NumBytesRead += NumBytesRem;
    pBuffer      += NumBytesRem;
    BufferSize   -= NumBytesRem;
    RdOff        += NumBytesRem;

    
    
    
    if (RdOff == pRing->SizeOfBuffer) {
      RdOff = 0u;
    }
  }
  
  
  
  NumBytesRem = WrOff - RdOff;
  NumBytesRem = (((NumBytesRem) < (BufferSize)) ? (NumBytesRem) : (BufferSize));
  if (NumBytesRem > 0u) {
    pSrc = (pRing->pBuffer + RdOff) + (0);
# 709 "RTE\\SEGGER\\SEGGER_RTT.c"
    memcpy((pBuffer), ((void*)pSrc), (NumBytesRem));
    NumBytesRead += NumBytesRem;
    pBuffer      += NumBytesRem;
    BufferSize   -= NumBytesRem;
    RdOff        += NumBytesRem;

  }
  if (NumBytesRead) {
    pRing->RdOff = RdOff;
  }
  
  return NumBytesRead;
}

























 
unsigned SEGGER_RTT_ReadUpBuffer(unsigned BufferIndex, void* pBuffer, unsigned BufferSize) {
  unsigned NumBytesRead;

  { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;
  
  
  
  NumBytesRead = SEGGER_RTT_ReadUpBufferNoLock(BufferIndex, pBuffer, BufferSize);
  
  
  
  _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
  
  return NumBytesRead;
}
















 
unsigned SEGGER_RTT_Read(unsigned BufferIndex, void* pBuffer, unsigned BufferSize) {
  unsigned NumBytesRead;

  { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;
  
  
  
  NumBytesRead = SEGGER_RTT_ReadNoLock(BufferIndex, pBuffer, BufferSize);
  
  
  
  _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
  
  return NumBytesRead;
}























 
void SEGGER_RTT_WriteWithOverwriteNoLock(unsigned BufferIndex, const void* pBuffer, unsigned NumBytes) {
  const char*           pData;
  SEGGER_RTT_BUFFER_UP* pRing;
  unsigned              Avail;
  volatile char*        pDst;
  
  
  
  pData = (const char *)pBuffer;
  pRing = (SEGGER_RTT_BUFFER_UP*)((char*)&_SEGGER_RTT.aUp[BufferIndex] + (0));  
  
  
  
  if (pRing->WrOff == pRing->RdOff) {
    Avail = pRing->SizeOfBuffer - 1u;
  } else if ( pRing->WrOff < pRing->RdOff) {
    Avail = pRing->RdOff - pRing->WrOff - 1u;
  } else {
    Avail = pRing->RdOff - pRing->WrOff - 1u + pRing->SizeOfBuffer;
  }
  if (NumBytes > Avail) {
    pRing->RdOff += (NumBytes - Avail);
    while (pRing->RdOff >= pRing->SizeOfBuffer) {
      pRing->RdOff -= pRing->SizeOfBuffer;
    }
  }
  
  
  
  Avail = pRing->SizeOfBuffer - pRing->WrOff;
  do {
    if (Avail > NumBytes) {
      
      
      
      pDst = (pRing->pBuffer + pRing->WrOff) + (0);
# 863 "RTE\\SEGGER\\SEGGER_RTT.c"
      memcpy(((void*)pDst), (pData), (NumBytes));
      ;                     
      pRing->WrOff += NumBytes;

      break;
    } else {
      
      
      
      pDst = (pRing->pBuffer + pRing->WrOff) + (0);
# 881 "RTE\\SEGGER\\SEGGER_RTT.c"
      memcpy(((void*)pDst), (pData), (Avail));
      pData += Avail;
      ;                     
      pRing->WrOff = 0;
      NumBytes -= Avail;

      Avail = (pRing->SizeOfBuffer - 1);
    }
  } while (NumBytes);
}



























 

unsigned SEGGER_RTT_WriteSkipNoLock(unsigned BufferIndex, const void* pBuffer, unsigned NumBytes) {
  const char*           pData;
  SEGGER_RTT_BUFFER_UP* pRing;
  unsigned              Avail;
  unsigned              RdOff;
  unsigned              WrOff;
  unsigned              Rem;
  volatile char*        pDst;
  
  
  
  
  
  
  
  
  
  
  pData = (const char *)pBuffer;
  pRing = (SEGGER_RTT_BUFFER_UP*)((char*)&_SEGGER_RTT.aUp[BufferIndex] + (0));  
  RdOff = pRing->RdOff;
  WrOff = pRing->WrOff;
  if (RdOff <= WrOff) {                                 
    Avail = pRing->SizeOfBuffer - WrOff - 1u;           
    if (Avail >= NumBytes) {                            
CopyStraight:
      pDst = (pRing->pBuffer + WrOff) + (0);
      memcpy((void*)pDst, pData, NumBytes);
      ;                     
      pRing->WrOff = WrOff + NumBytes;
      return 1;
    }
    Avail += RdOff;                                     
    if (Avail >= NumBytes) {                            
      Rem = pRing->SizeOfBuffer - WrOff;                
      pDst = (pRing->pBuffer + WrOff) + (0);
      memcpy((void*)pDst, pData, Rem);                  
      NumBytes -= Rem;
      
      
      
      
      
      
      if (NumBytes) {
        pDst = pRing->pBuffer + (0);
        memcpy((void*)pDst, pData + Rem, NumBytes);
      }
      ;                     
      pRing->WrOff = NumBytes;
      return 1;
    }
  } else {                                             
    Avail = RdOff - WrOff - 1u;
    if (Avail >= NumBytes) {                           
      goto CopyStraight;
    }
  }
  return 0;     
}





























 
unsigned SEGGER_RTT_WriteDownBufferNoLock(unsigned BufferIndex, const void* pBuffer, unsigned NumBytes) {
  unsigned                Status;
  unsigned                Avail;
  const char*             pData;
  SEGGER_RTT_BUFFER_UP*   pRing;
  
  
  
  
  pData = (const char *)pBuffer;
  pRing = (SEGGER_RTT_BUFFER_UP*)((char*)&_SEGGER_RTT.aDown[BufferIndex] + (0));  
  
  
  
  switch (pRing->Flags) {
  case (0):
    
    
    
    
    Avail = _GetAvailWriteSpace(pRing);
    if (Avail < NumBytes) {
      Status = 0u;
    } else {
      Status = NumBytes;
      _WriteNoCheck(pRing, pData, NumBytes);
    }
    break;
  case (1):
    
    
    
    Avail = _GetAvailWriteSpace(pRing);
    Status = Avail < NumBytes ? Avail : NumBytes;
    _WriteNoCheck(pRing, pData, Status);
    break;
  case (2):
    
    
    
    Status = _WriteBlocking(pRing, pData, NumBytes);
    break;
  default:
    Status = 0u;
    break;
  }
  
  
  
  return Status;
}























 
unsigned SEGGER_RTT_WriteNoLock(unsigned BufferIndex, const void* pBuffer, unsigned NumBytes) {
  unsigned              Status;
  unsigned              Avail;
  const char*           pData;
  SEGGER_RTT_BUFFER_UP* pRing;
  
  
  
  pData = (const char *)pBuffer;
  pRing = (SEGGER_RTT_BUFFER_UP*)((char*)&_SEGGER_RTT.aUp[BufferIndex] + (0));  
  
  
  
  switch (pRing->Flags) {
  case (0):
    
    
    
    
    Avail = _GetAvailWriteSpace(pRing);
    if (Avail < NumBytes) {
      Status = 0u;
    } else {
      Status = NumBytes;
      _WriteNoCheck(pRing, pData, NumBytes);
    }
    break;
  case (1):
    
    
    
    Avail = _GetAvailWriteSpace(pRing);
    Status = Avail < NumBytes ? Avail : NumBytes;
    _WriteNoCheck(pRing, pData, Status);
    break;
  case (2):
    
    
    
    Status = _WriteBlocking(pRing, pData, NumBytes);
    break;
  default:
    Status = 0u;
    break;
  }
  
  
  
  return Status;
}

























 
unsigned SEGGER_RTT_WriteDownBuffer(unsigned BufferIndex, const void* pBuffer, unsigned NumBytes) {
  unsigned Status;

  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;
  Status = SEGGER_RTT_WriteDownBufferNoLock(BufferIndex, pBuffer, NumBytes);  
  _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
  return Status;
}



















 
unsigned SEGGER_RTT_Write(unsigned BufferIndex, const void* pBuffer, unsigned NumBytes) {
  unsigned Status;

  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;
  Status = SEGGER_RTT_WriteNoLock(BufferIndex, pBuffer, NumBytes);  
  _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
  return Status;
}




















 
unsigned SEGGER_RTT_WriteString(unsigned BufferIndex, const char* s) {
  unsigned Len;

  Len = strlen((s));
  return SEGGER_RTT_Write(BufferIndex, s, Len);
}






















 

unsigned SEGGER_RTT_PutCharSkipNoLock(unsigned BufferIndex, char c) {
  SEGGER_RTT_BUFFER_UP* pRing;
  unsigned              WrOff;
  unsigned              Status;
  volatile char*        pDst;
  
  
  
  pRing = (SEGGER_RTT_BUFFER_UP*)((char*)&_SEGGER_RTT.aUp[BufferIndex] + (0));  
  
  
  
  WrOff = pRing->WrOff + 1;
  if (WrOff == pRing->SizeOfBuffer) {
    WrOff = 0;
  }
  
  
  
  if (WrOff != pRing->RdOff) {
    pDst = (pRing->pBuffer + pRing->WrOff) + (0);
    *pDst = c;
    ;                     
    pRing->WrOff = WrOff;
    Status = 1;
  } else {
    Status = 0;
  }
  
  return Status;
}

















 

unsigned SEGGER_RTT_PutCharSkip(unsigned BufferIndex, char c) {
  SEGGER_RTT_BUFFER_UP* pRing;
  unsigned              WrOff;
  unsigned              Status;
  volatile char*        pDst;
  
  
  
  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;
  
  
  
  pRing = (SEGGER_RTT_BUFFER_UP*)((char*)&_SEGGER_RTT.aUp[BufferIndex] + (0));  
  
  
  
  WrOff = pRing->WrOff + 1;
  if (WrOff == pRing->SizeOfBuffer) {
    WrOff = 0;
  }
  
  
  
  if (WrOff != pRing->RdOff) {
    pDst  = (pRing->pBuffer + pRing->WrOff) + (0);
    *pDst = c;
    ;                     
    pRing->WrOff = WrOff;
    Status = 1;
  } else {
    Status = 0;
  }
  
  
  
  _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
  
  return Status;
}

 















 

unsigned SEGGER_RTT_PutChar(unsigned BufferIndex, char c) {
  SEGGER_RTT_BUFFER_UP* pRing;
  unsigned              WrOff;
  unsigned              Status;
  volatile char*        pDst;
  
  
  
  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;
  
  
  
  pRing = (SEGGER_RTT_BUFFER_UP*)((char*)&_SEGGER_RTT.aUp[BufferIndex] + (0));  
  
  
  
  WrOff = pRing->WrOff + 1;
  if (WrOff == pRing->SizeOfBuffer) {
    WrOff = 0;
  }
  
  
  
  if (pRing->Flags == (2)) {
    while (WrOff == pRing->RdOff) {
      ;
    }
  }
  
  
  
  if (WrOff != pRing->RdOff) {
    pDst  = (pRing->pBuffer + pRing->WrOff) + (0);
    *pDst = c;
    ;                     
    pRing->WrOff = WrOff;
    Status = 1;
  } else {
    Status = 0;
  }
  
  
  
  _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
  return Status;
}















 
int SEGGER_RTT_GetKey(void) {
  char c;
  int r;

  r = (int)SEGGER_RTT_Read(0u, &c, 1u);
  if (r == 1) {
    r = (int)(unsigned char)c;
  } else {
    r = -1;
  }
  return r;
}















 
int SEGGER_RTT_WaitKey(void) {
  int r;

  do {
    r = SEGGER_RTT_GetKey();
  } while (r < 0);
  return r;
}














 
int SEGGER_RTT_HasKey(void) {
  SEGGER_RTT_BUFFER_DOWN* pRing;
  unsigned RdOff;
  int r;

  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  pRing = (SEGGER_RTT_BUFFER_DOWN*)((char*)&_SEGGER_RTT.aDown[0] + (0));  
  RdOff = pRing->RdOff;
  if (RdOff != pRing->WrOff) {
    r = 1;
  } else {
    r = 0;
  }
  return r;
}












 
unsigned SEGGER_RTT_HasData(unsigned BufferIndex) {
  SEGGER_RTT_BUFFER_DOWN* pRing;
  unsigned                v;

  pRing = (SEGGER_RTT_BUFFER_DOWN*)((char*)&_SEGGER_RTT.aDown[BufferIndex] + (0));  
  v = pRing->WrOff;
  return v - pRing->RdOff;
}












 
unsigned SEGGER_RTT_HasDataUp(unsigned BufferIndex) {
  SEGGER_RTT_BUFFER_UP* pRing;
  unsigned                v;

  pRing = (SEGGER_RTT_BUFFER_UP*)((char*)&_SEGGER_RTT.aUp[BufferIndex] + (0));  
  v = pRing->RdOff;
  return pRing->WrOff - v;
}



















 
int SEGGER_RTT_AllocDownBuffer(const char* sName, void* pBuffer, unsigned BufferSize, unsigned Flags) {
  int BufferIndex;
  volatile SEGGER_RTT_CB* pRTTCB;

  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;
  pRTTCB = (volatile SEGGER_RTT_CB*)((unsigned char*)&_SEGGER_RTT + (0));  
  BufferIndex = 0;
  do {
    if (pRTTCB->aDown[BufferIndex].pBuffer == 0) {
      break;
    }
    BufferIndex++;
  } while (BufferIndex < pRTTCB->MaxNumDownBuffers);
  if (BufferIndex < pRTTCB->MaxNumDownBuffers) {
    pRTTCB->aDown[BufferIndex].sName        = sName;
    pRTTCB->aDown[BufferIndex].pBuffer      = (char*)pBuffer;
    pRTTCB->aDown[BufferIndex].SizeOfBuffer = BufferSize;
    pRTTCB->aDown[BufferIndex].RdOff        = 0u;
    pRTTCB->aDown[BufferIndex].WrOff        = 0u;
    pRTTCB->aDown[BufferIndex].Flags        = Flags;
    ;                     
  } else {
    BufferIndex = -1;
  }
  _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
  return BufferIndex;
}



















 
int SEGGER_RTT_AllocUpBuffer(const char* sName, void* pBuffer, unsigned BufferSize, unsigned Flags) {
  int BufferIndex;
  volatile SEGGER_RTT_CB* pRTTCB;

  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;
  pRTTCB = (volatile SEGGER_RTT_CB*)((unsigned char*)&_SEGGER_RTT + (0));  
  BufferIndex = 0;
  do {
    if (pRTTCB->aUp[BufferIndex].pBuffer == 0) {
      break;
    }
    BufferIndex++;
  } while (BufferIndex < pRTTCB->MaxNumUpBuffers);
  if (BufferIndex < pRTTCB->MaxNumUpBuffers) {
    pRTTCB->aUp[BufferIndex].sName        = sName;
    pRTTCB->aUp[BufferIndex].pBuffer      = (char*)pBuffer;
    pRTTCB->aUp[BufferIndex].SizeOfBuffer = BufferSize;
    pRTTCB->aUp[BufferIndex].RdOff        = 0u;
    pRTTCB->aUp[BufferIndex].WrOff        = 0u;
    pRTTCB->aUp[BufferIndex].Flags        = Flags;
    ;                     
  } else {
    BufferIndex = -1;
  }
  _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
  return BufferIndex;
}

























 
int SEGGER_RTT_ConfigUpBuffer(unsigned BufferIndex, const char* sName, void* pBuffer, unsigned BufferSize, unsigned Flags) {
  int r;
  volatile SEGGER_RTT_CB* pRTTCB;

  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  pRTTCB = (volatile SEGGER_RTT_CB*)((unsigned char*)&_SEGGER_RTT + (0));  
  if (BufferIndex < (unsigned)pRTTCB->MaxNumUpBuffers) {
    { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;
    if (BufferIndex > 0u) {
      pRTTCB->aUp[BufferIndex].sName        = sName;
      pRTTCB->aUp[BufferIndex].pBuffer      = (char*)pBuffer;
      pRTTCB->aUp[BufferIndex].SizeOfBuffer = BufferSize;
      pRTTCB->aUp[BufferIndex].RdOff        = 0u;
      pRTTCB->aUp[BufferIndex].WrOff        = 0u;
    }
    pRTTCB->aUp[BufferIndex].Flags          = Flags;
    _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
    r =  0;
  } else {
    r = -1;
  }
  return r;
}

























 
int SEGGER_RTT_ConfigDownBuffer(unsigned BufferIndex, const char* sName, void* pBuffer, unsigned BufferSize, unsigned Flags) {
  int r;
  volatile SEGGER_RTT_CB* pRTTCB;

  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  pRTTCB = (volatile SEGGER_RTT_CB*)((unsigned char*)&_SEGGER_RTT + (0));  
  if (BufferIndex < (unsigned)pRTTCB->MaxNumDownBuffers) {
    { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;
    if (BufferIndex > 0u) {
      pRTTCB->aDown[BufferIndex].sName        = sName;
      pRTTCB->aDown[BufferIndex].pBuffer      = (char*)pBuffer;
      pRTTCB->aDown[BufferIndex].SizeOfBuffer = BufferSize;
      pRTTCB->aDown[BufferIndex].RdOff        = 0u;
      pRTTCB->aDown[BufferIndex].WrOff        = 0u;
    }
    pRTTCB->aDown[BufferIndex].Flags          = Flags;
    ;                     
    _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
    r =  0;
  } else {
    r = -1;
  }
  return r;
}
















 
int SEGGER_RTT_SetNameUpBuffer(unsigned BufferIndex, const char* sName) {
  int r;
  volatile SEGGER_RTT_CB* pRTTCB;

  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  pRTTCB = (volatile SEGGER_RTT_CB*)((unsigned char*)&_SEGGER_RTT + (0));  
  if (BufferIndex < (unsigned)pRTTCB->MaxNumUpBuffers) {
    { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;
    pRTTCB->aUp[BufferIndex].sName = sName;
    _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
    r =  0;
  } else {
    r = -1;
  }
  return r;
}
















 
int SEGGER_RTT_SetNameDownBuffer(unsigned BufferIndex, const char* sName) {
  int r;
  volatile SEGGER_RTT_CB* pRTTCB;

  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  pRTTCB = (volatile SEGGER_RTT_CB*)((unsigned char*)&_SEGGER_RTT + (0));  
  if (BufferIndex < (unsigned)pRTTCB->MaxNumDownBuffers) {
    { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;
    pRTTCB->aDown[BufferIndex].sName = sName;
    _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
    r =  0;
  } else {
    r = -1;
  }
  return r;
}
















 
int SEGGER_RTT_SetFlagsUpBuffer(unsigned BufferIndex, unsigned Flags) {
  int r;
  volatile SEGGER_RTT_CB* pRTTCB;

  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  pRTTCB = (volatile SEGGER_RTT_CB*)((unsigned char*)&_SEGGER_RTT + (0));  
  if (BufferIndex < (unsigned)pRTTCB->MaxNumUpBuffers) {
    { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;
    pRTTCB->aUp[BufferIndex].Flags = Flags;
    _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
    r =  0;
  } else {
    r = -1;
  }
  return r;
}
















 
int SEGGER_RTT_SetFlagsDownBuffer(unsigned BufferIndex, unsigned Flags) {
  int r;
  volatile SEGGER_RTT_CB* pRTTCB;

  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  pRTTCB = (volatile SEGGER_RTT_CB*)((unsigned char*)&_SEGGER_RTT + (0));  
  if (BufferIndex < (unsigned)pRTTCB->MaxNumDownBuffers) {
    { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;
    pRTTCB->aDown[BufferIndex].Flags = Flags;
    _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
    r =  0;
  } else {
    r = -1;
  }
  return r;
}









 
void SEGGER_RTT_Init (void) {
  _DoInit();
}

















 
int SEGGER_RTT_SetTerminal (unsigned char TerminalId) {
  unsigned char         ac[2];
  SEGGER_RTT_BUFFER_UP* pRing;
  unsigned Avail;
  int r;

  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  r = 0;
  ac[0] = 0xFFu;
  if (TerminalId < sizeof(_aTerminalId)) { 
    ac[1] = _aTerminalId[TerminalId];
    pRing = (SEGGER_RTT_BUFFER_UP*)((char*)&_SEGGER_RTT.aUp[0] + (0));  
    { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;                     
    if ((pRing->Flags & (3)) == (2)) {
      _ActiveTerminal = TerminalId;
      _WriteBlocking(pRing, (const char*)ac, 2u);
    } else {                                                                            
      Avail = _GetAvailWriteSpace(pRing);
      if (Avail >= 2) {
        _ActiveTerminal = TerminalId;    
        _WriteNoCheck(pRing, (const char*)ac, 2u);
      } else {
        r = -1;
      }
    }
    _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
  } else {
    r = -1;
  }
  return r;
}

















 
int SEGGER_RTT_TerminalOut (unsigned char TerminalId, const char* s) {
  int                   Status;
  unsigned              FragLen;
  unsigned              Avail;
  SEGGER_RTT_BUFFER_UP* pRing;
  
  { volatile SEGGER_RTT_CB* pRTTCBInit; pRTTCBInit = (volatile SEGGER_RTT_CB*)((char*)&_SEGGER_RTT + (0)); do { if (pRTTCBInit->acID[0] == '\0') { _DoInit(); } } while (0); };
  
  
  
  if (TerminalId < (char)sizeof(_aTerminalId)) { 
    
    
    
    pRing = (SEGGER_RTT_BUFFER_UP*)((char*)&_SEGGER_RTT.aUp[0] + (0));  
    
    
    
    
    FragLen = strlen((s));
    
    
    
    { unsigned int _SEGGER_RTT__LockState; register unsigned char _SEGGER_RTT__PRIMASK __asm( "primask"); _SEGGER_RTT__LockState = _SEGGER_RTT__PRIMASK; _SEGGER_RTT__PRIMASK = 1u; __schedule_barrier();;
    Avail = _GetAvailWriteSpace(pRing);
    switch (pRing->Flags & (3)) {
    case (0):
      
      
      
      
      if (Avail < (FragLen + 4u)) {
        Status = 0;
      } else {
        _PostTerminalSwitch(pRing, TerminalId);
        Status = (int)_WriteBlocking(pRing, s, FragLen);
        _PostTerminalSwitch(pRing, _ActiveTerminal);
      }
      break;
    case (1):
      
      
      
      
      
      if (Avail < 4u) {
        Status = -1;
      } else {
        _PostTerminalSwitch(pRing, TerminalId);
        Status = (int)_WriteBlocking(pRing, s, (FragLen < (Avail - 4u)) ? FragLen : (Avail - 4u));
        _PostTerminalSwitch(pRing, _ActiveTerminal);
      }
      break;
    case (2):
      
      
      
      _PostTerminalSwitch(pRing, TerminalId);
      Status = (int)_WriteBlocking(pRing, s, FragLen);
      _PostTerminalSwitch(pRing, _ActiveTerminal);
      break;
    default:
      Status = -1;
      break;
    }
    
    
    
    _SEGGER_RTT__PRIMASK = _SEGGER_RTT__LockState; __schedule_barrier(); };
  } else {
    Status = -1;
  }
  return Status;
}













 
unsigned SEGGER_RTT_GetAvailWriteSpace (unsigned BufferIndex) {
  SEGGER_RTT_BUFFER_UP* pRing;

  pRing = (SEGGER_RTT_BUFFER_UP*)((char*)&_SEGGER_RTT.aUp[BufferIndex] + (0));  
  return _GetAvailWriteSpace(pRing);
}














 
unsigned SEGGER_RTT_GetBytesInBuffer(unsigned BufferIndex) {
  unsigned RdOff;
  unsigned WrOff;
  unsigned r;
  volatile SEGGER_RTT_CB* pRTTCB;
  
  
  
  
  pRTTCB = (volatile SEGGER_RTT_CB*)((unsigned char*)&_SEGGER_RTT + (0));  
  RdOff = pRTTCB->aUp[BufferIndex].RdOff;
  WrOff = pRTTCB->aUp[BufferIndex].WrOff;
  if (RdOff <= WrOff) {
    r = WrOff - RdOff;
  } else {
    r = pRTTCB->aUp[BufferIndex].SizeOfBuffer - (WrOff - RdOff);
  }
  return r;
}






























 
int SEGGER_RTT_TerminalPrintf(unsigned TerminalId, const char * sFormat, ...) {
  int r;
  va_list ParamList;
  
  if(TerminalId > (char)sizeof(_aTerminalId)){
    return -1;
  }
  SEGGER_RTT_SetTerminal(TerminalId);

  __va_start(ParamList, sFormat);
  r = SEGGER_RTT_vprintf(0, sFormat, &ParamList);
  __va_end(ParamList);
  return r;
}

 
