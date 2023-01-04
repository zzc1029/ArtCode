# 1 "../driver/canfifo.c"
# 1 "D:\\ARTStanHome\\Desktop\\TZGJ-XMJL-221205\\kf32\\Release//"
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
  CANSENDED = 0,
  CANDELAYING,
  CANSUCCEED
};
# 8 "../driver/canfifo.c" 2
