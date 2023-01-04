	.file	"keyfif.c"
	.stabs	"G:\\\\workspace32\\\\YB-GZST-QRWD-221203\\\\Release/",100,0,2,.Ltext0
	.stabs	"../driver/keyfif.c",100,0,2,.Ltext0
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
	.stabs	"../driver/keyfifo.h",130,0,0,0
	.stabs	"_MESSAGE:T(1,1)=eMSG_NONE:0,;",128,0,0,0
	.stabs	"MESSAGE:t(1,2)=(1,1)",128,0,16,0
	.stabs	"_MSG_FIFO_INDEX:T(1,3)=eMSG_FIFO_KEY:0,MSG_FIFO_DISP:1,MSG_FIFO_SYS:2,MSG_FIFO_COUNT:3,;",128,0,0,0
	.stabs	"MSG_FIFO_INDEX:t(1,4)=(1,3)",128,0,27,0
	.stabs	"_MESSAGE_FIFO:T(1,5)=s10IndexHead:(0,11),0,8;Count:(0,11),8,8;Buf:(1,6)=ar(1,7)=r(1,7);0;037777777777;;0;7;(0,11),16,64;;",128,0,0,0
	.stabs	"MESSAGE_FIFO:t(1,8)=(1,5)",128,0,36,0
	.stabn	162,0,0,0
	.section .text$message_init
	.type	.text$message_init$scode_local_1, @function
	.text$message_init$scode_loacal_1:
	.align	1
	.stabs	"message_init:F(0,15)",36,0,12,message_init
	.export	message_init
	.type	message_init, @function
message_init:
	.stabd	46,0,0
	.stabs	"../driver/keyfif.c",132,0,0,.Ltext1
.Ltext1:
	.stabn	68,0,13,.LM0-.LFBB1
.LM0:
.LFBB1:
	.stabn	68,0,18,.LM1-.LFBB1
.LM1:
	LD	r5,#MsgFifos
	MOV	r4,#0
	ST.b	[r5],r4
	.stabn	68,0,19,.LM2-.LFBB1
.LM2:
	ST.b	[r5+#1],r4
	.stabn	68,0,22,.LM3-.LFBB1
.LM3:
	ST.b	[r5+#2],r4
	ST.b	[r5+#3],r4
	ST.b	[r5+#4],r4
	ST.b	[r5+#5],r4
	ST.b	[r5+#6],r4
	ST.b	[r5+#7],r4
	ST.b	[r5+#8],r4
	ST.b	[r5+#9],r4
	.stabn	68,0,18,.LM4-.LFBB1
.LM4:
	ST.b	[r5+#10],r4
	.stabn	68,0,19,.LM5-.LFBB1
.LM5:
	ST.b	[r5+#11],r4
	.stabn	68,0,22,.LM6-.LFBB1
.LM6:
	ST.b	[r5+#12],r4
	ST.b	[r5+#13],r4
	ST.b	[r5+#14],r4
	ST.b	[r5+#15],r4
	ST.b	[r5+#16],r4
	ST.b	[r5+#17],r4
	ST.b	[r5+#18],r4
	ST.b	[r5+#19],r4
	.stabn	68,0,18,.LM7-.LFBB1
.LM7:
	ST.b	[r5+#20],r4
	.stabn	68,0,19,.LM8-.LFBB1
.LM8:
	ST.b	[r5+#21],r4
	.stabn	68,0,22,.LM9-.LFBB1
.LM9:
	ST.b	[r5+#22],r4
	ST.b	[r5+#23],r4
	ST.b	[r5+#24],r4
	ST.b	[r5+#25],r4
	ST.b	[r5+#26],r4
	ST.b	[r5+#27],r4
	ST.b	[r5+#28],r4
	ST.b	[r5+#29],r4
	.stabn	68,0,25,.LM10-.LFBB1
.LM10:
	JMP	lr
	.size	message_init, .-message_init
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
	.section .text$message_send
	.type	.text$message_send$scode_local_2, @function
	.text$message_send$scode_loacal_2:
	.align	1
	.stabs	"message_send:F(0,15)",36,0,27,message_send
	.stabs	"MsgFifoIndex:P(0,11)",64,0,27,0
	.stabs	"event:P(0,11)",64,0,27,1
	.export	message_send
	.type	message_send, @function
message_send:
	.stabd	46,0,0
	.stabs	"../driver/keyfif.c",132,0,0,.Ltext2
.Ltext2:
	.stabn	68,0,28,.LM11-.LFBB2
.LM11:
.LFBB2:
	ZXT.b	r0,r0
	.stabn	68,0,29,.LM12-.LFBB2
.LM12:
	MOV	r5,#10
	MULS	r0,r0,r5 ;
	NOP
	LD	r3,#MsgFifos
	ADD	r5,r0,r3
	.stabn	68,0,35,.LM13-.LFBB2
.LM13:
	LD.b	r4,[r5+#1]
	LD.b	r3,[r0+r3]
	ADD	r3,r3,r4
	MOV	r2,#7
	ANL	r3,r3,r2
	ADD	r3,r5,r3
	ST.b	[r3+#2],r1
	ADD	r4,r4,#1
	ST.b	[r5+#1],r4
	.stabn	68,0,36,.LM14-.LFBB2
.LM14:
	JMP	lr
	.size	message_send, .-message_send
	.stabs	"pMsgFifo:r(0,16)=*(1,8)",64,0,29,5
	.stabn	192,0,0,.LFBB2-.LFBB2
	.stabn	224,0,0,.Lscope2-.LFBB2
.Lscope2:
	.stabs	"",36,0,0,.Lscope2-.LFBB2
	.stabd	78,0,0
	.section .text$message_get
	.type	.text$message_get$scode_local_3, @function
	.text$message_get$scode_loacal_3:
	.align	1
	.stabs	"message_get:F(0,11)",36,0,38,message_get
	.stabs	"MsgFifoIndex:P(0,11)",64,0,38,0
	.export	message_get
	.type	message_get, @function
message_get:
	.stabd	46,0,0
	.stabs	"../driver/keyfif.c",132,0,0,.Ltext3
.Ltext3:
	.stabn	68,0,39,.LM15-.LFBB3
.LM15:
.LFBB3:
	PUSH	r6
	ZXT.b	r0,r0
	.stabn	68,0,41,.LM16-.LFBB3
.LM16:
	MOV	r5,#10
	MULS	r3,r0,r5 ;
	NOP
	LD	r4,#MsgFifos
	ADD	r5,r3,r4
	.stabn	68,0,43,.LM17-.LFBB3
.LM17:
	LD.b	r2,[r5+#1]
	.stabn	68,0,40,.LM18-.LFBB3
.LM18:
	MOV	r0,#0
	.stabn	68,0,43,.LM19-.LFBB3
.LM19:
	CMP	r2,r0
	JZ	.L4
	.stabn	68,0,45,.LM20-.LFBB3
.LM20:
	LD.b	r1,[r3+r4]
	ADD	r0,r5,r1
	LD.b	r0,[r0+#2]
	.stabn	68,0,46,.LM21-.LFBB3
.LM21:
	ADD	r1,r1,#1
	MOV	r6,#7
	ANL	r1,r1,r6
	ST.b	[r3+r4],r1
	.stabn	68,0,47,.LM22-.LFBB3
.LM22:
	SUB	r2,r2,#1
	ST.b	[r5+#1],r2
.L4:
	.stabn	68,0,51,.LM23-.LFBB3
.LM23:
	POP	r6
	JMP	lr
	.size	message_get, .-message_get
	.stabs	"event:r(0,11)",64,0,40,0
	.stabs	"pMsgFifo:r(0,16)",64,0,41,5
	.stabn	192,0,0,.LFBB3-.LFBB3
	.stabn	224,0,0,.Lscope3-.LFBB3
.Lscope3:
	.stabs	"",36,0,0,.Lscope3-.LFBB3
	.stabd	78,0,0
	.export	MsgFifos
	.section .bss$comm$MsgFifos
	.type	.bss$comm$MsgFifos$scode_local_4, @function
	.bss$comm$MsgFifos$scode_loacal_4:
	.type	MsgFifos, @object
	.size	MsgFifos, 30
MsgFifos:
	.fill 30, 1
	.stabs	"MsgFifos:G(0,17)=ar(1,7);0;2;(1,8)",32,0,10,0
	.text
	.stabs	"",100,0,0,.Letext0
.Letext0:
