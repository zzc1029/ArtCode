# 1 "../driver/canfifo.c"
# 1 "/cygdrive/d/zzc/project/pro_2022/pro_12/MY-QRWD-221207/kf32/Release//"
# 1 "<command-line>"
# 1 "../driver/canfifo.c"






# 1 "../driver/canfifo.h" 1
# 26 "../driver/canfifo.h"
typedef struct
{

  unsigned char sended;

  unsigned int ID;

  unsigned char type;
  unsigned char data[8];
  unsigned char len;
}SendCanFifo;


typedef struct
{
 int wr_index;
 int rd_index;
 int ovfcount;
 int errcount;
 SendCanFifo * buff;
 int max_len;
} SendToCan;


enum
{
  SENDED = 0,
  DELAYING,
  SUCCEED
};
# 8 "../driver/canfifo.c" 2
