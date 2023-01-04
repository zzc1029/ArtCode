# 1 "../system/startup.c"
# 1 "G:\\workspace32\\YB-GZST-QRWD-221203\\Release//"
# 1 "<command-line>"
# 1 "../system/startup.c"





extern unsigned int __text_end__;
extern unsigned int __bss_start__;
extern unsigned int __bss_end__;
extern unsigned int __data_start__;
extern unsigned int __vec_start__;







extern int main();

void startup()
{
 unsigned int *s,*begin,*end;





 (*((volatile unsigned int *)(0x40000000)))=0;
 (*((volatile unsigned int *)(0x402000BC))) = (unsigned int)&__vec_start__;

 s = (unsigned int*)&__text_end__;
 begin = (unsigned int*)&__data_start__;
 end = (unsigned int*)&__bss_start__;
 while(begin < end)
  *begin++ = *s++;
# 48 "../system/startup.c"
 begin = (unsigned int*)&__bss_start__;
 end = (unsigned int*)&__bss_end__;
 while(begin < end)
  *begin++ = 0;


 main();
}
