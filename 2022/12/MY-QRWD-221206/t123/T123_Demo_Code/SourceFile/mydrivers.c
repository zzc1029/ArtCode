#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"
#include "spiosd.h"
#include "osd2api.h"

#include "page_main_internal.h"
#include "uart.h"
#include "display.h"
#include "mydrivers.h"
#include "disp_config.h"

unsigned char code page_map[PAGE_TOTAL][2] =
{
	0x52,ID_PAGE_START,//logo
	0x01,ID_PAGE_MAIN_INTERNAL,
	0x02,ID_PAGE_MAIN_MENUS,
	0x03,ID_PAGE_LOGO,
	0x04,ID_PAGE_PARAMETER,
	0x05,ID_PAGE_HELP_MESSAGE,
	0x06,ID_PAGE_VIDEO,
	0x07,ID_PAGE_METER_MOUDLE,
	#if MODULE_FRONT_B40 || MODULE_FRONT_B50
	0x08,ID_PAGE_FRONT_MOUDLE,
	#endif
	#if MODULE_REAR_B40 || MODULE_REAR_B50
	0x09,ID_PAGE_REAR_MOUDLE,
	#endif
	#if MODULE_TOP_B40 || MODULE_TOP_B50
	0x0a,ID_PAGE_TOP_MOUDLE,
	#endif
	#if MODULE_FRONT_B50
	0x0b,ID_PAGE_FRONT_MOUDLE_OUT,
	#endif
	#if MODULE_REAR_B50
	0x0c,ID_PAGE_REAR_MOUDLE_OUT,
	#endif
	#if MODULE_TOP_B50
	0x0d,ID_PAGE_TOP_MOUDLE_OUT,
	#endif
	#if (PAGE_ADD > 0)
	0x20,ID_PAGE_SURFACE1,
	#endif
	#if (PAGE_ADD > 1)
	0x21,ID_PAGE_SURFACE2,
	#endif
	#if (PAGE_ADD > 2)
	0x22,ID_PAGE_SURFACE3,
	#endif
	#if (PAGE_ADD > 3)
	0x23,ID_PAGE_SURFACE4,
	#endif
	#if (PAGE_ADD > 4)
	0x24,ID_PAGE_SURFACE5,
	#endif
	#if (PAGE_ADD > 5)
	0x25,ID_PAGE_SURFACE6,
	#endif
	#if (PAGE_ADD > 6)
	0x26,ID_PAGE_SURFACE7,
	#endif
	#if (PAGE_ADD > 7)
	0x27,ID_PAGE_SURFACE8,
	#endif
	#if (PAGE_ADD > 8)
	0x28,ID_PAGE_SURFACE9,
	#endif
	#if (PAGE_ADD > 9)
	0x29,ID_PAGE_SURFACE10,
	#endif
	#if (PAGE_ADD > 10)
	0x2a,ID_PAGE_SURFACE11,
	#endif
	#if (PAGE_ADD > 11)
	0x2b,ID_PAGE_SURFACE12,
	#endif
	#if (PAGE_ADD > 12)
	0x2c,ID_PAGE_SURFACE13,
	#endif
	#if (PAGE_ADD > 13)
	0x2d,ID_PAGE_SURFACE14,
	#endif
	#if (PAGE_ADD > 14)
	0x2e,ID_PAGE_SURFACE15,
	#endif
	#if (PAGE_ADD > 15)
	0x2f,ID_PAGE_SURFACE16,
	#endif
	#if (PAGE_ADD > 16)
	0x30,ID_PAGE_SURFACE17,
	#endif
	#if (PAGE_ADD > 17)
	0x31,ID_PAGE_SURFACE18,
	#endif
	#if (PAGE_ADD > 18)
	0x32,ID_PAGE_SURFACE19,
	#endif
	#if (PAGE_ADD > 19)
	0x33,ID_PAGE_SURFACE20,
	#endif
	#if (PAGE_ADD > 20)
	0x34,ID_PAGE_SURFACE21,
	#endif
};

struct tw_icon *code number_map[22] = {
	&page_main_internal_number_0,
	&page_main_internal_number_1,
	&page_main_internal_number_2,
	&page_main_internal_number_3,
	&page_main_internal_number_4,
	&page_main_internal_number_5,
	&page_main_internal_number_6,
	&page_main_internal_number_7,
	&page_main_internal_number_8,
	&page_main_internal_number_9,
	&page_main_internal_number_10,//-
	&page_main_internal_soc_7,//空格
	&page_main_internal_number_point_0,
	&page_main_internal_number_point_1,
	&page_main_internal_number_point_2,
	&page_main_internal_number_point_3,
	&page_main_internal_number_point_4,
	&page_main_internal_number_point_5,
	&page_main_internal_number_point_6,
	&page_main_internal_number_point_7,
	&page_main_internal_number_point_8,
	&page_main_internal_number_point_9,
};

struct tw_icon *code number_medium_map[12] = {
	&page_main_internal_fault_number_0,
	&page_main_internal_fault_number_1,
	&page_main_internal_fault_number_2,
	&page_main_internal_fault_number_3,
	&page_main_internal_fault_number_4,
	&page_main_internal_fault_number_5,
	&page_main_internal_fault_number_6,
	&page_main_internal_fault_number_7,
	&page_main_internal_fault_number_8,
	&page_main_internal_fault_number_9,
	&page_main_internal_number_10,
	&page_main_internal_soc_7,

};

struct tw_icon *code number_big_map[12] = {
	&page_main_internal_fault_alarm_0,
	&page_main_internal_fault_alarm_1,
	&page_main_internal_fault_alarm_2,
	&page_main_internal_fault_alarm_3,
	&page_main_internal_fault_alarm_4,
	&page_main_internal_fault_alarm_5,
	&page_main_internal_fault_alarm_6,
	&page_main_internal_fault_alarm_7,
	&page_main_internal_fault_alarm_8,
	&page_main_internal_fault_alarm_9,
	&page_main_internal_number_10,
	&page_main_internal_soc_7,
};

#define		uintToBCD()\
{	\
	unsigned char tempx[10] = {0};\
	unsigned char i,j,k,space = 11;\
	\
	if(ispace)	\
		space = 0;\
	for(i=0;ivalue>0;ivalue/=10)\
		tempx[i++] = ivalue % 10;\
	if(i == 0)\
		tempx[i++] = 0;\
	if(icharnum >= i)\
	{\
		k = icharnum - i;\
		for(j=0;j<icharnum;j++)\
		{\
			if(j < k)\
				iout[j] = space;\
			else	\
				iout[j] = tempx[--i];\
		}\
	}\
	else\
	{\
		for(j=0;j<icharnum;j++)\
			iout[j] = 11;\
		iout[1] = 10;\
		iout[2] = 10;\
	}\
}
#define		sintToBCD()\
{	\
	unsigned char tempx[10] = {0};\
	unsigned char i,j,k,neg = 0,space = 11;\
	\
	if(ispace)	\
		space = 0;\
	if(ivalue < 0)\
	{\
		ivalue = 0 - ivalue;	\
		neg = 1;\
	}\
	for(i=0;ivalue>0;ivalue/=10)\
		tempx[i++] = ivalue % 10;\
	if(i == 0)\
		tempx[i++] = 0;\
	if(icharnum >= (i + 1))	\
	{\
		k = icharnum - i - 1;\
		for(j=0;j<icharnum;j++)\
		{\
			if(j < k)\
				iout[j] = space;\
			else if(j == k)\
			{\
				if(neg)\
					iout[j] = 10;\
				else	\
					iout[j] = space;\
			}\
			else	\
				iout[j] = tempx[--i];\
		}\
	}\
	else if(icharnum == i)\
	{\
		if(neg)\
		{\
			for(j=0;j<icharnum;j++)\
				iout[j] = 11;\
			iout[1] = 10;\
			iout[2] = 10;\
		}\
		else	\
		{\
			for(j=0;j<icharnum;j++)\
				iout[j] = tempx[--i];\
		}\
	}\
	else	\
	{\
		for(j=0;j<icharnum;j++)\
			iout[j] = 11;\
		iout[1] = 10;\
		iout[2] = 10;\
	}\
}
#define		DISPLAY()\
{\
	unsigned char i;\
	for(i=0; i<(left+right); i++)\
	{\
		if(size == FONT_SMALL)\
		{\
			if(out[i] == 11)\
				clear_area_block(x + i,y,1,1);\
			else\
				display_icon(*number_map[out[i]],color,x + i,y);\
		}\
		else if(size == FONT_MEDIUM)\
		{\
			if(out[i] == 11)\
			{\
				clear_area_block(x + i,y,1,2);\
			}\
			else\
				display_icon(*number_medium_map[out[i]],color,x + i,y);\
		}\
		else\
		{\
			if(out[i] == 11)\
			{\
				clear_area_block(x + i*2,y,2,2);\
			}\
			else\
			display_icon(*number_big_map[out[i]],color,x + i*2,y);\
		}\
	}\
}

void u8tobcd(unsigned char ivalue,unsigned char * iout,unsigned char ispace,unsigned char icharnum)
{
	uintToBCD();
}

void s8tobcd(signed char ivalue,unsigned char * iout,unsigned char ispace,unsigned char icharnum)
{
	sintToBCD();
}

void u16tobcd(unsigned int ivalue,unsigned char * iout,unsigned char ispace,unsigned char icharnum)
{
	uintToBCD();
}

void s16tobcd(signed int ivalue,unsigned char * iout,unsigned char ispace,unsigned char icharnum)
{
	sintToBCD();
}

void u32tobcd(unsigned long ivalue,unsigned char * iout,unsigned char ispace,unsigned char icharnum)
{
	uintToBCD();
}

void s32tobcd(signed long ivalue,unsigned char * iout,unsigned char ispace,unsigned char icharnum)
{
	sintToBCD();
}
/*
left:必须为非0数据，小数点左边个数
right:小数点右边个数，为0时显示为整数
space:为0时，不用显示的信息显示空格，为1时，显示0
size:字体大小目前只支持小型字体带小数点，大中型字体不能显示小数点
*/
void displayu8(unsigned char x,unsigned char y,unsigned char value,unsigned char left,unsigned char right,unsigned char color,unsigned char space,unsigned char size)
{
	unsigned char out[10],i;
	u8tobcd(value,out,space, left + right);
	if((out[1] != 10) && (out[2] != 10) && right)
	{
		if(out[left - 1] == 11)
		{
			out[left - 1] = 12;
			for(i=0;i<right;i++)
			{
				if(out[left + i] == 11)
					out[left + i] = 0;
			}
		}
		else
			out[left - 1] += 12;	
	}
	DISPLAY();
}

void displays8(unsigned char x,unsigned char y,signed char value,unsigned char left,unsigned char right,unsigned char color,unsigned char space,unsigned char size)
{
	unsigned char out[10],i;
	s8tobcd(value,out,space, left + right);
	if(right && !((out[1] == 10) && (out[2] == 10)))
	{
		if(out[left - 1] == 11)
		{
			out[left - 1] = 12;
			for(i=0;i<right;i++)
			{
				if(out[left + i] == 11)
					out[left + i] = 0;
			}
		}
		else
			out[left - 1] += 12;	
	}
	DISPLAY();
}

void displayu16(unsigned char x,unsigned char y,unsigned int value,unsigned char left,unsigned char right,unsigned char color,unsigned char space,unsigned char size)
{
	unsigned char out[10],i;
	u16tobcd(value,out,space, left + right);
	if((out[1] != 10) && (out[2] != 10) && right)
	{
		if(out[left - 1] == 11)
		{
			out[left - 1] = 12;
			for(i=0;i<right;i++)
			{
				if(out[left + i] == 11)
					out[left + i] = 0;
			}
		}
		else
			out[left - 1] += 12;	
	}
	DISPLAY();
}

void displays16(unsigned char x,unsigned char y,signed int value,unsigned char left,unsigned char right,unsigned char color,unsigned char space,unsigned char size)
{
	unsigned char out[10],i;
	s16tobcd(value,out,space, left + right);
	if(right && !((out[1] == 10) && (out[2] == 10)))
	{
		if(out[left - 1] == 11)
		{
			out[left - 1] = 12;
			for(i=0;i<right;i++)
			{
				if(out[left + i] == 11)
					out[left + i] = 0;
			}
		}
		else
			out[left - 1] += 12;	
	}
	DISPLAY();
}

void displayu32(unsigned char x,unsigned char y,unsigned long value,unsigned char left,unsigned char right,unsigned char color,unsigned char space,unsigned char size)
{
	unsigned char out[10],i;
	u32tobcd(value,out,space, left + right);
	if((out[1] != 10) && (out[2] != 10) && right)
	{
		if(out[left - 1] == 11)
		{
			out[left - 1] = 12;
			for(i=0;i<right;i++)
			{
				if(out[left + i] == 11)
					out[left + i] = 0;
			}
		}
		else
			out[left - 1] += 12;	
	}
	DISPLAY();
}

void displays32(unsigned char x,unsigned char y,signed long value,unsigned char left,unsigned char right,unsigned char color,unsigned char space,unsigned char size)
{
	unsigned char out[10],i;
	s32tobcd(value,out,space, left + right);
	if(right && !((out[1] == 10) && (out[2] == 10)))
	{
		if(out[left - 1] == 11)
		{
			out[left - 1] = 12;
			for(i=0;i<right;i++)
			{
				if(out[left + i] == 11)
					out[left + i] = 0;
			}
		}
		else
			out[left - 1] += 12;	
	}
	DISPLAY();
}
void display_char_8bit(unsigned char x,unsigned char y,unsigned char color,unsigned char value)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if(value & 0x80)
			display_icon(*number_map[1],color,x + i,y);
		else
			display_icon(*number_map[0],color,x + i,y);
		value <<= 1;
	}
}
void display_uncolor_icon(struct tw_icon picon,unsigned char x, unsigned char y)
{
	picon.x = x;
	picon.y = y;
	tw_icon_draw(&picon);
}
void display_icon(struct tw_icon picon, unsigned char color, unsigned char x, unsigned char y)
{
	picon.x = x;
	picon.y = y;
	picon.color = color;
	tw_icon_draw(&picon);
}
void clear_icon(struct tw_icon picon,unsigned char x,unsigned char y)
{
	picon.x = x;
	picon.y = y;
	tw_clear_icon(&picon);
}
void display_uncolor_gicon(struct tw_gicon gpicon,unsigned char x,unsigned char y)
{
	gpicon.x = x;
	gpicon.y = y;
	tw_gicon_draw(&gpicon);
}
void display_gicon(struct tw_gicon gpicon,unsigned char color,unsigned char x,unsigned char y)
{
	gpicon.x = x;
	gpicon.y = y;
	gpicon.color = color;
	tw_gicon_draw(&gpicon);
}
void display_spr(struct tw_spr spr,unsigned int x,unsigned int y)
{
	spr.x = x;
	spr.y = y;
	tw_spr_draw(&spr);
}
void clear_gicon(struct tw_gicon gpicon,unsigned char x,unsigned char y)
{
	gpicon.x = x;
	gpicon.y = y;
	tw_clear_gicon(&gpicon);
}
void clear_area_block(unsigned char x,unsigned char y,unsigned char width,unsigned char height)
{
	osd_clear_block(x,y,width,height,page_main_internal_osd2_1_menu.addr,page_main_internal_osd2_1_menu.width);
}
void clear_unmark_area(void)
{
	//clear_area_block(4,4,46,2);
	clear_area_block(0,4,50,14);
}
void clear_mark_area(void)
{
	clear_area_block(0,0,50,4);
	//clear_area_block(0,4,4,2);
}
void clear_unalarm_area(void)
{
	clear_area_block(0,0,50,18);
}
void clear_alarm_area(void)
{
	clear_area_block(0,18,50,2);
}
void clear_time_area(void)
{
	unsigned char i,j;
	for(i=0;i<4;i++)
		display_icon(page_main_internal_soc_7,iBLACK,15 + i,2);
	display_icon(page_main_internal_soc_7,iBLACK,21,2);
	for(i=0;i<6;i++)
		display_icon(page_main_internal_soc_7,iBLACK,15 + i,4);
	display_icon(page_main_internal_soc_7,iBLACK,23,4);
	display_icon(page_main_internal_soc_7,iBLACK,26,4);
	for(i=0;i<10;i++)
		display_icon(page_main_internal_soc_7,iBLACK,12 + i,6);
	for(i=0;i<8;i++)
		display_icon(page_main_internal_soc_7,iBLACK,11 + i,8);
	for(i=0;i<4;i++)
	{
		for(j=0;j<10;j++)
			display_icon(page_main_internal_soc_7,iBLACK,32 + j,2 + i);
	}
}
void clear_set_area(void)
{
	unsigned char i,j;
	//for(i=0;i<5;i++)
		//display_icon(page_main_internal_soc_7,iBLACK,14 + i,10);
	display_icon(page_main_internal_soc_7,iBLACK,19,12);
	display_icon(page_main_internal_soc_7,iBLACK,20,12);
	display_icon(page_main_internal_soc_7,iBLACK,19,13);
	display_icon(page_main_internal_soc_7,iBLACK,20,13);
	display_icon(page_main_internal_soc_7,iBLACK,19,14);
	display_icon(page_main_internal_soc_7,iBLACK,20,14);
	display_icon(page_main_internal_soc_7,iBLACK,19,16);
	display_icon(page_main_internal_soc_7,iBLACK,20,16);
	display_icon(page_main_internal_soc_7,iBLACK,19,17);
	display_icon(page_main_internal_soc_7,iBLACK,20,17);
	
	
	
	for(j=0;j<9;j++)
	{
		for(i=0;i<11;i++)
			display_icon(page_main_internal_soc_7,iBLACK,8 + i,9 + j);
	}
	for(j=0;j<9;j++)
	{
		for(i=0;i<10;i++)
			display_icon(page_main_internal_soc_7,iBLACK,30 + i,9 + j);
	}

	//for(i=0;i<9;i++)
		//display_icon(page_main_internal_soc_7,iBLACK,12 + i,16);
}
void clear_mima_area(void)
{
	unsigned char i;
	for(i=0;i<12;i++)
		display_icon(page_main_internal_soc_7,iBLACK,4 + i,7);
}
unsigned char check_page(unsigned char page)
{
	char i;
	for(i=0;i<PAGE_TOTAL;i++)
	{
		if(page_map[i][0] == page)
			return page_map[i][1];
	}
	return 0;
}
void page_switch(void)
{
	unsigned char temp_page;
	temp_page = check_page(system_page.current_page);
	if(temp_page != system_page.last_page)
	{
		put_quit_page_event(system_page.last_page);
		system_page.last_page = temp_page;
		if(!ENTER_LOGO)
			ENTER_ACC = 1;
		put_enter_page_event(temp_page);	
	}
}
void display_icon_blink(struct tw_icon picon,unsigned char x,unsigned char y,unsigned char color,unsigned char blinking)
{
	picon.x = x;
	picon.y = y;
	picon.color = color;
	tw_icon_draw_blink(&picon,blinking);
}
void display_icon_uncolor_blink(struct tw_icon picon,unsigned char x,unsigned char y,unsigned char blinking)
{
	picon.x = x;
	picon.y = y;
	tw_icon_draw_blink(&picon,blinking);
}
void display_gicon_uncolor_blink(struct tw_gicon pgicon,unsigned char x,unsigned char y,unsigned char blinking)
{
	pgicon.x = x;
	pgicon.y = y;
	tw_gicon_draw_blink(&pgicon,blinking);
}
void tw_icon_draw_blink(struct tw_icon* picon,unsigned char blinking)
{   
	_icon_draw(picon->index, picon->color, picon->x, picon->y, picon->width, picon->height, blinking);
}
void tw_gicon_draw_blink(struct tw_gicon* pgicon,unsigned char blinking)
{
	unsigned short icon_id = 0;
	unsigned char color = 0;
	unsigned short tmp_addr = 0;
	
    icon_id = check_gicon_id(pgicon->gicon_id);
    if(!icon_id)
        return;
    
    tmp_addr = pgicon->oram_addr;
    /* dynamic load ICON to OSDRAM */
    tw_load_icon(icon_id, &tmp_addr);

	color = check_color_config(pgicon->index, 0, pgicon->color);
	_icon_draw(pgicon->index, color, pgicon->x, pgicon->y, pgicon->width, pgicon->height, blinking);
}
