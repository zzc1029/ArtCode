#include "includes.h"
#include "stdint.h"
#include "pt.h"
#include "ringfifo.h"
#include "canhl.h"

#define TX_TIMEOUT_MS 10

#define disable_can_rx_int()   NVIC_DisableIRQ(CAN_RX_IRQn)
#define enable_can_rx_int()   NVIC_EnableIRQ(CAN_RX_IRQn)

static can_frame_struct canrxisr;

static uint32_t tx_timeout;
static volatile uint32_t flag_can = 0;
static uint32_t flag_can_disable = 0;

static can_frame can_send_frames[16];   
#ifdef FIFO_TYPE1        
static RingFifo canfifo = {0, 0, 0, 0, 16 * sizeof(can_frame), (uint8_t *)(can_send_frames)}; 
#else
static uint8_t  pcan_send_frames[16];                                   
static RingFifo canfifo = {0, 0, 0, 0, 16 * sizeof(uint8_t), (uint8_t *)(pcan_send_frames)}; 
#endif
const RingFifo * pfifo = &canfifo;

static void TransLocal2CanFrame(can_frame_struct *msg, can_frame *can_msg)
{
    uint32_t i;
    can_msg->ext = msg->ff;
    can_msg->rtr = msg->ft;
    if (can_msg->ext)
        can_msg->id = msg->efid;
    else
        can_msg->id = msg->sfid;

    can_msg->len = msg->dlen;
    can_msg->len = can_msg->len > 8 ? 8 : can_msg->len;

    for (i = 0; i < can_msg->len; i++)
        can_msg->data[i] = msg->data[i];
}

static void TransCanFrame2Local(can_frame *can_msg, can_frame_struct *msg)
{
    uint32_t i;
    msg->ff = (CAN_FRAME_FORMAT)can_msg->ext;
    msg->ft = (CAN_FRAME_TYPE)can_msg->rtr;
    if (can_msg->ext)
        msg->efid = can_msg->id;
    else
        msg->sfid = can_msg->id;

    msg->dlen = can_msg->len;
    msg->dlen = msg->dlen > 8 ? 8 : msg->dlen;

    for (i = 0; i < msg->dlen; i++)
        msg->data[i] = can_msg->data[i];
}


void can_isr()
{
		can_receive_message(&canrxisr);
    flag_can = 1;
}

inline uint32_t can_frame_received()
{
		return flag_can;
}

uint32_t can_recv_frame(can_frame * canrx)
{
		if(flag_can)
		{
			disable_can_rx_int();
			TransLocal2CanFrame(&canrxisr, canrx);
			enable_can_rx_int();
			flag_can = 0;
			return 1;
		}
		return 0;
}
#ifdef FIFO_TYPE1
uint32_t can_send_frame(can_frame *msg)
{
		if(flag_can_disable)
			return 2;
		
	  if (fifo_get_free(pfifo) >= sizeof(can_frame*))
    {
        fifo_append_bytes((RingFifo* )pfifo, (uint8_t *)msg, sizeof(can_frame));
        return 0;
    }
    return 1;
}

uint32_t can_send_bytes(uint32_t id, uint8_t isext, uint8_t *data, uint8_t len)
{
    uint32_t i;
    can_frame msg;
    msg.ext = isext;
    msg.rtr = 0;

    msg.id = id;

    msg.len = len;
    msg.len = msg.len > 8 ? 8 : msg.len;

    for (i = 0; i < 8; i++)
        msg.data[i] = data[i];

    return can_send_frame(&msg);
}
#else
uint32_t can_send_frame(can_frame *msg)
{
		return can_send_bytes(msg->id,msg->ext,msg->data,msg->len);
}

uint32_t can_send_bytes(uint32_t id, uint8_t isext, uint8_t *data, uint8_t len)
{
		if(flag_can_disable)
			return 2;
		
		if (fifo_get_free(pfifo) >= 1)
    {
			uint32_t i;
			can_frame *msg = (can_send_frames + (pfifo->wr_index & (pfifo->max_len - 1)));
			
			msg->ext = isext;
			msg->rtr = 0;

			msg->id = id;

			msg->len = len;
			msg->len = msg->len > 8 ? 8 : msg->len;

			for (i = 0; i < 8; i++)
					msg->data[i] = data[i];

			canfifo.wr_index ++;
			return 0;
		}
    return 1;
}
#endif
void can_send_enable(uint32_t enable)
{
		if(enable)
			flag_can_disable = 0;
		else
			flag_can_disable = 1;
}

static uint32_t CAN_Transmit_Msg_Raw(can_frame_struct *msg)
{
		uint32_t re = can_transmit_message(msg);
    can_transmit_request();
    return re;
}

extern void can_config(void);

int protothread_canhl_loop(struct pt *pt)
{
  PT_BEGIN(pt);
	
	can_frame msg;
	static uint32_t retry = 0;
	static can_frame_struct tx;
	
	while(1)
	{
		#ifdef FIFO_TYPE1
		PT_WAIT_UNTIL(pt,fifo_get_count(pfifo)>=sizeof(can_frame));		
		fifo_get_bytes((RingFifo*)pfifo, (uint8_t *)&msg, sizeof(can_frame));		
		TransCanFrame2Local(&msg, &tx);
		#else		
		PT_WAIT_UNTIL(pt,fifo_have_data(pfifo));				
		TransCanFrame2Local((can_send_frames + (pfifo->rd_index & (pfifo->max_len - 1))), &tx);
		canfifo.rd_index ++;		
		#endif
		
		retry = 0;		
		while(retry ++ < MAX_SEND_RETRY)
		{
			CAN_Transmit_Msg_Raw(&tx);
			
			tx_timeout = systick_ms + TX_TIMEOUT_MS;			
			PT_WAIT_UNTIL(pt,((int)(systick_ms - tx_timeout) >= 0)||((can_interrupt_flag_get() & CAN_IF_TI) != 0x00U));
			
			if((can_interrupt_flag_get() & CAN_IF_TI) != 0x00U)
			{
				can_int_flag_clr (CAN_IF_TI);
				break;
			}
			can_int_flag_clr (CAN_IF_TI);
		}
	}
	PT_INFINITE_LOOP_END(pt);
}


static struct pt pt_can_send;

void canhl_loop()
{
	protothread_canhl_loop(&pt_can_send);
	if((can_status_get() & CAN_SR_BS) != 0x00U)
	{
			can_config();
	}
}



