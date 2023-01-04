	.file	"keyfif.c"
	.stabs	"/cygdrive/d/zzc/project/pro_2021/pro_12/FYGJ-AK-211230/code/ART_BOOT/Debug/",100,0,2,.Ltext0
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
	.export	MsgFifos
	.section .bss$comm$MsgFifos
	.type	.bss$comm$MsgFifos$scode_local_1, @function
	.bss$comm$MsgFifos$scode_loacal_1:
	.type	MsgFifos, @object
	.size	MsgFifos, 30
MsgFifos:
	.fill 30, 1
	.section .text$message_init
	.type	.text$message_init$scode_local_2, @function
	.text$message_init$scode_loacal_2:
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
	SUB	sp,#4
	.stabn	68,0,16,.LM1-.LFBB1
.LM1:
	MOV	r5,#0
	ST.b	[sp],r5
	JMP	.L2
.L5:
	.stabn	68,0,18,.LM2-.LFBB1
.LM2:
	LD.b	r4,[sp]
	LD	r3,#MsgFifos
	MOV	r5,#10
	MULS	r5,r4,r5 ;
	NOP
	ADD	r4,r3,r5
	MOV	r5,#0
	ST.b	[r4],r5
	.stabn	68,0,19,.LM3-.LFBB1
.LM3:
	LD.b	r4,[sp]
	LD	r3,#MsgFifos
	MOV	r5,#10
	MULS	r5,r4,r5 ;
	NOP
	ADD	r5,r3,r5
	ADD	r4,r5,#1
	MOV	r5,#0
	ST.b	[r4],r5
	.stabn	68,0,20,.LM4-.LFBB1
.LM4:
	MOV	r5,#0
	ST.b	[sp+#1],r5
	JMP	.L3
.L4:
	.stabn	68,0,22,.LM5-.LFBB1
.LM5:
	LD.b	r4,[sp]
	LD.b	r3,[sp+#1]
	LD	r2,#MsgFifos
	MOV	r5,#10
	MULS	r5,r4,r5 ;
	NOP
	ADD	r5,r2,r5
	ADD	r5,r5,r3
	ADD	r4,r5,#2
	MOV	r5,#0
	ST.b	[r4],r5
	.stabn	68,0,20,.LM6-.LFBB1
.LM6:
	LD.b	r5,[sp+#1]
	ADD	r5,r5,#1
	ST.b	[sp+#1],r5
.L3:
	LD.b	r5,[sp+#1]
	CMP	r5,#7
	JLS	.L4
	.stabn	68,0,16,.LM7-.LFBB1
.LM7:
	LD.b	r5,[sp]
	ADD	r5,r5,#1
	ST.b	[sp],r5
.L2:
	LD.b	r5,[sp]
	CMP	r5,#2
	JLS	.L5
	.stabn	68,0,25,.LM8-.LFBB1
.LM8:
	ADD	sp,#4
	JMP	lr
	.size	message_init, .-message_init
	.stabs	"i:(0,11)",128,0,14,0
	.stabs	"j:(0,11)",128,0,14,1
	.stabn	192,0,0,.LFBB1-.LFBB1
	.stabn	224,0,0,.Lscope1-.LFBB1
.Lscope1:
	.stabs	"",36,0,0,.Lscope1-.LFBB1
	.stabd	78,0,0
	.section .text$message_send
	.type	.text$message_send$scode_local_3, @function
	.text$message_send$scode_loacal_3:
	.align	1
	.stabs	"message_send:F(0,15)",36,0,27,message_send
	.stabs	"MsgFifoIndex:p(0,11)",160,0,27,4
	.stabs	"event:p(0,11)",160,0,27,8
	.export	message_send
	.type	message_send, @function
message_send:
	.stabd	46,0,0
	.stabs	"../driver/keyfif.c",132,0,0,.Ltext2
.Ltext2:
	.stabn	68,0,28,.LM9-.LFBB2
.LM9:
.LFBB2:
	SUB	sp,#12
	MOV	r4,r0
	MOV	r5,r1
	ST.b	[sp+#4],r4
	ST.b	[sp+#8],r5
	.stabn	68,0,29,.LM10-.LFBB2
.LM10:
	LD.b	r4,[sp+#4]
	MOV	r5,#10
	MULS	r4,r4,r5 ;
	NOP
	LD	r5,#MsgFifos
	ADD	r5,r4,r5
	ST.w	[sp],r5
	.stabn	68,0,35,.LM11-.LFBB2
.LM11:
	LD.w	r5,[sp]
	LD.b	r5,[r5]
	MOV	r3,r5
	LD.w	r5,[sp]
	LD.b	r5,[r5+#1]
	MOV	r4,r5
	ADD	r3,r3,r4
	MOV	r4,#7
	ANL	r3,r3,r4
	LD.w	r4,[sp]
	ADD	r4,r4,r3
	LD.b	r3,[sp+#8]
	ST.b	[r4+#2],r3
	ADD	r5,r5,#1
	ZXT.b	r5,r5
	LD.w	r4,[sp]
	ST.b	[r4+#1],r5
	.stabn	68,0,36,.LM12-.LFBB2
.LM12:
	ADD	sp,#12
	JMP	lr
	.size	message_send, .-message_send
	.stabs	"pMsgFifo:(0,16)=*(1,8)",128,0,29,0
	.stabn	192,0,0,.LFBB2-.LFBB2
	.stabn	224,0,0,.Lscope2-.LFBB2
.Lscope2:
	.stabs	"",36,0,0,.Lscope2-.LFBB2
	.stabd	78,0,0
	.section .text$message_get
	.type	.text$message_get$scode_local_4, @function
	.text$message_get$scode_loacal_4:
	.align	1
	.stabs	"message_get:F(0,11)",36,0,38,message_get
	.stabs	"MsgFifoIndex:p(0,11)",160,0,38,8
	.export	message_get
	.type	message_get, @function
message_get:
	.stabd	46,0,0
	.stabs	"../driver/keyfif.c",132,0,0,.Ltext3
.Ltext3:
	.stabn	68,0,39,.LM13-.LFBB3
.LM13:
.LFBB3:
	SUB	sp,#12
	MOV	r5,r0
	ST.b	[sp+#8],r5
	.stabn	68,0,40,.LM14-.LFBB3
.LM14:
	MOV	r5,#0
	ST.b	[sp],r5
	.stabn	68,0,41,.LM15-.LFBB3
.LM15:
	LD.b	r4,[sp+#8]
	MOV	r5,#10
	MULS	r4,r4,r5 ;
	NOP
	LD	r5,#MsgFifos
	ADD	r5,r4,r5
	ST.w	[sp+#1],r5
	.stabn	68,0,43,.LM16-.LFBB3
.LM16:
	LD.w	r5,[sp+#1]
	LD.b	r5,[r5+#1]
	CMP	r5,#0
	JZ	.L8
	.stabn	68,0,45,.LM17-.LFBB3
.LM17:
	LD.w	r5,[sp+#1]
	LD.b	r5,[r5]
	LD.w	r4,[sp+#1]
	ADD	r5,r4,r5
	LD.b	r5,[r5+#2]
	ST.b	[sp],r5
	.stabn	68,0,46,.LM18-.LFBB3
.LM18:
	LD.w	r5,[sp+#1]
	LD.b	r5,[r5]
	ADD	r4,r5,#1
	LD	r5,#-2147483641
	ANL	r5,r4,r5
	CMP	r5,#0
	JPL	.L9
	SUB	r5,r5,#1
	MOV	r4,#7
	NOT	r4,r4
	ORL	r5,r5,r4
	ADD	r5,r5,#1
.L9:
	ZXT.b	r5,r5
	LD.w	r4,[sp+#1]
	ST.b	[r4],r5
	.stabn	68,0,47,.LM19-.LFBB3
.LM19:
	LD.w	r5,[sp+#1]
	LD.b	r5,[r5+#1]
	SUB	r5,r5,#1
	ZXT.b	r5,r5
	LD.w	r4,[sp+#1]
	ST.b	[r4+#1],r5
.L8:
	.stabn	68,0,50,.LM20-.LFBB3
.LM20:
	LD.b	r5,[sp]
	.stabn	68,0,51,.LM21-.LFBB3
.LM21:
	MOV	r0,r5
	ADD	sp,#12
	JMP	lr
	.size	message_get, .-message_get
	.stabs	"event:(0,11)",128,0,40,0
	.stabs	"pMsgFifo:(0,16)",128,0,41,4
	.stabn	192,0,0,.LFBB3-.LFBB3
	.stabn	224,0,0,.Lscope3-.LFBB3
.Lscope3:
	.stabs	"",36,0,0,.Lscope3-.LFBB3
	.stabd	78,0,0
	.stabs	"MsgFifos:G(0,17)=ar(1,7);0;2;(1,8)",32,0,10,0
	.text
	.stabs	"",100,0,0,.Letext0
.Letext0:
