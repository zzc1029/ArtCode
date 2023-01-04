#ifndef __CANHL_H__
#define __CANHL_H__

#include "stdint.h"

typedef struct {
	uint32_t id;
	uint8_t rtr; // 1=> remote frame
	uint8_t ext; // 1=> ext frame
	uint8_t len;
	uint8_t res;
	uint8_t data[8];
} can_frame;

#define MAX_SEND_RETRY  3

extern inline uint32_t can_frame_received(void);
extern void can_send_enable(uint32_t enable);

extern void can_isr(void);

extern uint32_t can_recv_frame(can_frame * msg);
extern uint32_t can_send_frame(can_frame * msg);
extern uint32_t can_send_bytes(uint32_t id, uint8_t isext, uint8_t * data, uint8_t len);



#endif
