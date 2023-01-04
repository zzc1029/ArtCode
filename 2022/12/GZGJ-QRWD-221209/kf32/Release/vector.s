	.file	"vector.c"
	.stabs	"/cygdrive/d/zzc/project/pro_2022/pro_12/GZGJ-QRWD-221209/kf32/Release/",100,0,2,.Ltext0
	.stabs	"../system/vector.c",100,0,2,.Ltext0
	.text
.Ltext0:
	.stabs	"gcc2_compiled.",60,0,0,0
	.stabs	"int:t(0,1)=r(0,1);-2147483648;2147483647;",128,0,0,0
	.stabs	"char:t(0,2)=@s8;r(0,2);0;255;",128,0,0,0
	.stabs	"long int:t(0,3)=r(0,3);-2147483648;2147483647;",128,0,0,0
	.stabs	"unsigned int:t(0,4)=r(0,4);0;037777777777;",128,0,0,0
	.stabs	"long unsigned int:t(0,5)=r(0,5);0;037777777777;",128,0,0,0
	.stabs	"long long int:t(0,6)=@s64;r(0,6);01000000000000000000000;0777777777777777777777;",128,0,0,0
	.stabs	"long long unsigned int:t(0,7)=@s64;r(0,7);0;01777777777777777777777;",128,0,0,0
	.stabs	"short int:t(0,8)=@s16;r(0,8);-32768;32767;",128,0,0,0
	.stabs	"short unsigned int:t(0,9)=@s16;r(0,9);0;65535;",128,0,0,0
	.stabs	"signed char:t(0,10)=@s8;r(0,10);-128;127;",128,0,0,0
	.stabs	"unsigned char:t(0,11)=@s8;r(0,11);0;255;",128,0,0,0
	.stabs	"float:t(0,12)=r(0,1);4;0;",128,0,0,0
	.stabs	"double:t(0,13)=r(0,1);8;0;",128,0,0,0
	.stabs	"long double:t(0,14)=r(0,1);8;0;",128,0,0,0
	.stabs	"void:t(0,15)=(0,15)",128,0,0,0
	.stabs	"interruptVector:t(0,16)=(0,17)=s4Func:(0,18)=*(0,19)=f(0,15),0,32;;",128,0,149,0
	.stabs	"VectorEnter:t(0,20)=(0,21)=s512value:(0,22)=*(0,1),0,32;Reset_Enter:(0,16),32,32;NMI_Enter:(0,16),64,32;HardFault_Enter:(0,16),96,32;Rev4_Enter:(0,16),128,32;StackFault_Enter:(0,16),160,32;AriFault_Enter:(0,16),192,32;Intended_Rev:(0,16),224,32;interrupt:(0,23)=ar(0,24)=r(0,24);0;037777777777;;0;119;(0,16),256,3840;;",128,0,164,0
	.export	Stack_Mem
	.section .stack_mem$Stack_Mem
	.type	.stack_mem$Stack_Mem$scode_local_1, @function
	.stack_mem$Stack_Mem$scode_loacal_1:
	.align	2
	.type	Stack_Mem, @object
	.size	Stack_Mem, 512
Stack_Mem:
	.fill 512, 1
	.export	_startx
	.section .text$_startx
	.type	.text$_startx$scode_local_2, @function
	.text$_startx$scode_loacal_2:
	.align	2
	.type	_startx, @object
	.size	_startx, 512
_startx:
	.long	__initial_sp
	.long	startup
	.long	_NMI_exception
	.long	_HardFault_exception
	.long	_Soft4_exception
	.long	_StackFault_exception
	.long	_AriFault_exception
	.long	0
	.long	_Soft8_exception
	.long	_Soft9_exception
	.long	_Soft10_exception
	.long	_SVC_exception
	.long	_Soft12_exception
	.long	_Soft13_exception
	.long	_SoftSV_exception
	.long	_SysTick_exception
	.long	_WWDT_exception
	.long	_EINT16_exception
	.long	_EINT0_exception
	.long	_EINT1_exception
	.long	_EINT2_exception
	.long	_EINT3_exception
	.long	_EINT4_exception
	.long	_EINT9TO5_exception
	.long	_EINT15TO10_exception
	.long	_T1_exception
	.long	_T3_exception
	.long	_T5_exception
	.long	_T6_exception
	.long	_T7_T8_QEI_exception
	.long	_CAN2_exception
	.long	_CAN3_exception
	.long	_CAN4_exception
	.long	_T14_exception
	.long	_T15_exception
	.long	_CAN5_exception
	.long	_EXIC_exception
	.long	_ADC0_exception
	.long	_ADC1_exception
	.long	_CFGL_exception
	.long	_LCD_exception
	.long	_T0_exception
	.long	_DMA0_exception
	.long	_CMP_exception
	.long	_USART0_exception
	.long	_USART1_exception
	.long	_SPI0_exception
	.long	_SPI1_exception
	.long	_DMA1_exception
	.long	_EINT19TO17_exception
	.long	_CAN0_exception
	.long	_CAN1_exception
	.long	_T9_exception
	.long	_T10_exception
	.long	_EINT21TO20_exception
	.long	_EINT31TO22_exception
	.long	_OSC_CLK_exception
	.long	_I2C0_exception
	.long	_I2C1_exception
	.long	_I2C2_exception
	.long	_USB_exception
	.long	_T2_exception
	.long	_T4_exception
	.long	_CTOUCH_exception
	.long	_USART2_exception
	.long	_USART3_exception
	.long	_USART4_exception
	.long	_SPI2_exception
	.long	_SPI3_exception
	.long	_ADC2_exception
	.long	_T18_exception
	.long	_T19_exception
	.long	_T22_T23_exception
	.long	_WKP5TO0_exception
	.long	_T20_exception
	.long	_T21_exception
	.long	_I2C3_exception
	.long	_USART5_exception
	.long	_USART6_exception
	.long	_USART7_exception
	.long	_Soft80_exception
	.long	_Soft81_exception
	.long	_Soft82_exception
	.long	_Soft83_exception
	.long	_Soft84_exception
	.long	_Soft85_exception
	.long	_Soft86_exception
	.long	_Soft87_exception
	.long	_Soft88_exception
	.long	_Soft89_exception
	.long	_Soft90_exception
	.long	_Soft91_exception
	.long	_Soft92_exception
	.long	_Soft93_exception
	.long	_Soft94_exception
	.long	_Soft95_exception
	.long	_Soft96_exception
	.long	_Soft97_exception
	.long	_Soft98_exception
	.long	_Soft99_exception
	.long	_Soft100_exception
	.long	_Soft101_exception
	.long	_Soft102_exception
	.long	_Soft103_exception
	.long	_Soft104_exception
	.long	_Soft105_exception
	.long	_Soft106_exception
	.long	_Soft107_exception
	.long	_Soft108_exception
	.long	_Soft109_exception
	.long	_Soft110_exception
	.long	_Soft111_exception
	.long	_Soft112_exception
	.long	_Soft113_exception
	.long	_Soft114_exception
	.long	_Soft115_exception
	.long	_Soft116_exception
	.long	_Soft117_exception
	.long	_Soft118_exception
	.long	_Soft119_exception
	.long	_Soft120_exception
	.long	_Soft121_exception
	.long	_Soft122_exception
	.long	_Soft123_exception
	.long	_Soft124_exception
	.long	_Soft125_exception
	.long	_Soft126_exception
	.long	_Soft127_exception
	.export	_start
	.section .initvec$_start
	.type	.initvec$_start$scode_local_3, @function
	.initvec$_start$scode_loacal_3:
	.align	2
	.type	_start, @object
	.size	_start, 512
_start:
	.long	__initial_sp
	.long	startup
	.long	_NMI_exception
	.long	_HardFault_exception
	.long	_Soft4_exception
	.long	_StackFault_exception
	.long	_AriFault_exception
	.long	0
	.long	_Soft8_exception
	.long	_Soft9_exception
	.long	_Soft10_exception
	.long	_SVC_exception
	.long	_Soft12_exception
	.long	_Soft13_exception
	.long	_SoftSV_exception
	.long	_SysTick_exception
	.long	_WWDT_exception
	.long	_EINT16_exception
	.long	_EINT0_exception
	.long	_EINT1_exception
	.long	_EINT2_exception
	.long	_EINT3_exception
	.long	_EINT4_exception
	.long	_EINT9TO5_exception
	.long	_EINT15TO10_exception
	.long	_T1_exception
	.long	_T3_exception
	.long	_T5_exception
	.long	_T6_exception
	.long	_T7_T8_QEI_exception
	.long	_CAN2_exception
	.long	_CAN3_exception
	.long	_CAN4_exception
	.long	_T14_exception
	.long	_T15_exception
	.long	_CAN5_exception
	.long	_EXIC_exception
	.long	_ADC0_exception
	.long	_ADC1_exception
	.long	_CFGL_exception
	.long	_LCD_exception
	.long	_T0_exception
	.long	_DMA0_exception
	.long	_CMP_exception
	.long	_USART0_exception
	.long	_USART1_exception
	.long	_SPI0_exception
	.long	_SPI1_exception
	.long	_DMA1_exception
	.long	_EINT19TO17_exception
	.long	_CAN0_exception
	.long	_CAN1_exception
	.long	_T9_exception
	.long	_T10_exception
	.long	_EINT21TO20_exception
	.long	_EINT31TO22_exception
	.long	_OSC_CLK_exception
	.long	_I2C0_exception
	.long	_I2C1_exception
	.long	_I2C2_exception
	.long	_USB_exception
	.long	_T2_exception
	.long	_T4_exception
	.long	_CTOUCH_exception
	.long	_USART2_exception
	.long	_USART3_exception
	.long	_USART4_exception
	.long	_SPI2_exception
	.long	_SPI3_exception
	.long	_ADC2_exception
	.long	_T18_exception
	.long	_T19_exception
	.long	_T22_T23_exception
	.long	_WKP5TO0_exception
	.long	_T20_exception
	.long	_T21_exception
	.long	_I2C3_exception
	.long	_USART5_exception
	.long	_USART6_exception
	.long	_USART7_exception
	.long	_Soft80_exception
	.long	_Soft81_exception
	.long	_Soft82_exception
	.long	_Soft83_exception
	.long	_Soft84_exception
	.long	_Soft85_exception
	.long	_Soft86_exception
	.long	_Soft87_exception
	.long	_Soft88_exception
	.long	_Soft89_exception
	.long	_Soft90_exception
	.long	_Soft91_exception
	.long	_Soft92_exception
	.long	_Soft93_exception
	.long	_Soft94_exception
	.long	_Soft95_exception
	.long	_Soft96_exception
	.long	_Soft97_exception
	.long	_Soft98_exception
	.long	_Soft99_exception
	.long	_Soft100_exception
	.long	_Soft101_exception
	.long	_Soft102_exception
	.long	_Soft103_exception
	.long	_Soft104_exception
	.long	_Soft105_exception
	.long	_Soft106_exception
	.long	_Soft107_exception
	.long	_Soft108_exception
	.long	_Soft109_exception
	.long	_Soft110_exception
	.long	_Soft111_exception
	.long	_Soft112_exception
	.long	_Soft113_exception
	.long	_Soft114_exception
	.long	_Soft115_exception
	.long	_Soft116_exception
	.long	_Soft117_exception
	.long	_Soft118_exception
	.long	_Soft119_exception
	.long	_Soft120_exception
	.long	_Soft121_exception
	.long	_Soft122_exception
	.long	_Soft123_exception
	.long	_Soft124_exception
	.long	_Soft125_exception
	.long	_Soft126_exception
	.long	_Soft127_exception
	.stabs	"_start:G(0,25)=k(0,20)",32,0,298,0
	.stabs	"_startx:G(0,25)",32,0,431,0
	.stabs	"Stack_Mem:G(0,26)=ar(0,24);0;511;(0,11)",32,0,568,0
	.weak	_Soft127_exception
	.weak	_Soft126_exception
	.weak	_Soft125_exception
	.weak	_Soft124_exception
	.weak	_Soft123_exception
	.weak	_Soft122_exception
	.weak	_Soft121_exception
	.weak	_Soft120_exception
	.weak	_Soft119_exception
	.weak	_Soft118_exception
	.weak	_Soft117_exception
	.weak	_Soft116_exception
	.weak	_Soft115_exception
	.weak	_Soft114_exception
	.weak	_Soft113_exception
	.weak	_Soft112_exception
	.weak	_Soft111_exception
	.weak	_Soft110_exception
	.weak	_Soft109_exception
	.weak	_Soft108_exception
	.weak	_Soft107_exception
	.weak	_Soft106_exception
	.weak	_Soft105_exception
	.weak	_Soft104_exception
	.weak	_Soft103_exception
	.weak	_Soft102_exception
	.weak	_Soft101_exception
	.weak	_Soft100_exception
	.weak	_Soft99_exception
	.weak	_Soft98_exception
	.weak	_Soft97_exception
	.weak	_Soft96_exception
	.weak	_Soft95_exception
	.weak	_Soft94_exception
	.weak	_Soft93_exception
	.weak	_Soft92_exception
	.weak	_Soft91_exception
	.weak	_Soft90_exception
	.weak	_Soft89_exception
	.weak	_Soft88_exception
	.weak	_Soft87_exception
	.weak	_Soft86_exception
	.weak	_Soft85_exception
	.weak	_Soft84_exception
	.weak	_Soft83_exception
	.weak	_Soft82_exception
	.weak	_Soft81_exception
	.weak	_Soft80_exception
	.weak	_USART7_exception
	.weak	_USART6_exception
	.weak	_USART5_exception
	.weak	_I2C3_exception
	.weak	_T21_exception
	.weak	_T20_exception
	.weak	_WKP5TO0_exception
	.weak	_T22_T23_exception
	.weak	_T19_exception
	.weak	_T18_exception
	.weak	_ADC2_exception
	.weak	_SPI3_exception
	.weak	_SPI2_exception
	.weak	_USART4_exception
	.weak	_USART3_exception
	.weak	_USART2_exception
	.weak	_CTOUCH_exception
	.weak	_T4_exception
	.weak	_T2_exception
	.weak	_USB_exception
	.weak	_I2C2_exception
	.weak	_I2C1_exception
	.weak	_I2C0_exception
	.weak	_OSC_CLK_exception
	.weak	_EINT31TO22_exception
	.weak	_EINT21TO20_exception
	.weak	_T10_exception
	.weak	_T9_exception
	.weak	_CAN1_exception
	.weak	_CAN0_exception
	.weak	_EINT19TO17_exception
	.weak	_DMA1_exception
	.weak	_SPI1_exception
	.weak	_SPI0_exception
	.weak	_USART1_exception
	.weak	_USART0_exception
	.weak	_CMP_exception
	.weak	_DMA0_exception
	.weak	_T0_exception
	.weak	_LCD_exception
	.weak	_CFGL_exception
	.weak	_ADC1_exception
	.weak	_ADC0_exception
	.weak	_EXIC_exception
	.weak	_CAN5_exception
	.weak	_T15_exception
	.weak	_T14_exception
	.weak	_CAN4_exception
	.weak	_CAN3_exception
	.weak	_CAN2_exception
	.weak	_T7_T8_QEI_exception
	.weak	_T6_exception
	.weak	_T5_exception
	.weak	_T3_exception
	.weak	_T1_exception
	.weak	_EINT15TO10_exception
	.weak	_EINT9TO5_exception
	.weak	_EINT4_exception
	.weak	_EINT3_exception
	.weak	_EINT2_exception
	.weak	_EINT1_exception
	.weak	_EINT0_exception
	.weak	_EINT16_exception
	.weak	_WWDT_exception
	.weak	_SysTick_exception
	.weak	_SoftSV_exception
	.weak	_Soft13_exception
	.weak	_Soft12_exception
	.weak	_SVC_exception
	.weak	_Soft10_exception
	.weak	_Soft9_exception
	.weak	_Soft8_exception
	.weak	_AriFault_exception
	.weak	_StackFault_exception
	.weak	_Soft4_exception
	.weak	_HardFault_exception
	.weak	_NMI_exception
	.text
	.stabs	"",100,0,0,.Letext0
.Letext0: