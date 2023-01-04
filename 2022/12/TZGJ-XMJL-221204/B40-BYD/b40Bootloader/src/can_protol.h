#ifndef __CAN_PROTOL_H__
#define __CAN_PROTOL_H__

#include "includes.h"


#define APP_START_ADDR 0x8000
#define APP_MAX_LEN 0x10000
#define PASSWORD_ADDR 0x17C00
#define DefaultPassword 0x12345678

extern int protothread_can_recv (struct pt *pt);
	



#endif
