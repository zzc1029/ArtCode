# 1 "../driver/keyfif.c"
# 1 "D:\\ARTStanHome\\Desktop\\TZGJ-XMJL-221205\\kf32\\Release//"
# 1 "<command-line>"
# 1 "../driver/keyfif.c"







# 1 "../driver/keyfifo.h" 1
# 12 "../driver/keyfifo.h"
typedef enum _MESSAGE
{
  MSG_NONE = 0x00

} MESSAGE;



typedef enum _MSG_FIFO_INDEX
{
 MSG_FIFO_KEY = 0,
 MSG_FIFO_DISP ,
 MSG_FIFO_SYS,
 MSG_FIFO_COUNT

} MSG_FIFO_INDEX;


typedef struct _MESSAGE_FIFO
{
  unsigned char IndexHead;
  unsigned char Count;
  unsigned char Buf[8];

} MESSAGE_FIFO;


extern MESSAGE_FIFO MsgFifos[MSG_FIFO_COUNT];
extern void message_init(void);


extern void message_send(unsigned char MsgFifoIndex, unsigned char event);

extern unsigned char message_get(unsigned char MsgFifoIndex);
# 9 "../driver/keyfif.c" 2

MESSAGE_FIFO MsgFifos[MSG_FIFO_COUNT];

void message_init(void)
{
 unsigned char i, j;

 for(i = 0; i < MSG_FIFO_COUNT; i++)
 {
  MsgFifos[i].IndexHead = 0;
  MsgFifos[i].Count = 0;
  for(j = 0; j < 8; j++)
  {
   MsgFifos[i].Buf[j] = 0;
  }
 }
}

void message_send(unsigned char MsgFifoIndex, unsigned char event)
{
 MESSAGE_FIFO* pMsgFifo = &MsgFifos[MsgFifoIndex];

 if(pMsgFifo->Count >= 8)
 {

 }
 pMsgFifo->Buf[(pMsgFifo->IndexHead + (pMsgFifo->Count++)) % 8] = event;
}

unsigned char message_get(unsigned char MsgFifoIndex)
{
 unsigned char event = MSG_NONE;
 MESSAGE_FIFO* pMsgFifo = &MsgFifos[MsgFifoIndex];

 if(pMsgFifo->Count)
 {
  event = pMsgFifo->Buf[pMsgFifo->IndexHead];
  pMsgFifo->IndexHead = (pMsgFifo->IndexHead + 1) % 8;
  pMsgFifo->Count--;
 }

 return event;
}
