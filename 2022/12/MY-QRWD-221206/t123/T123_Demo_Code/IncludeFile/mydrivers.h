#ifndef __MYDRIVERS_H__
#define __MYDRIVERS_H__

enum
{
	FULLSPACE = 0,
	FULLZERO,
};
enum
{
	FONT_SMALL = 0,
	FONT_MEDIUM,
	FONT_BIG,
};

extern struct tw_icon *code number_map[22];
extern struct tw_icon *code number_medium_map[12];
extern struct tw_icon *code number_big_map[12];


extern void displayu8(unsigned char x,unsigned char y,unsigned char value,unsigned char left,unsigned char right,unsigned char color,unsigned char space,unsigned char size);
extern void displays8(unsigned char x,unsigned char y,signed char value,unsigned char left,unsigned char right,unsigned char color,unsigned char space,unsigned char size);
extern void displayu16(unsigned char x,unsigned char y,unsigned int value,unsigned char left,unsigned char right,unsigned char color,unsigned char space,unsigned char size);
extern void displays16(unsigned char x,unsigned char y,signed int value,unsigned char left,unsigned char right,unsigned char color,unsigned char space,unsigned char size);
extern void displayu32(unsigned char x,unsigned char y,unsigned long value,unsigned char left,unsigned char right,unsigned char color,unsigned char space,unsigned char size);
extern void displays32(unsigned char x,unsigned char y,signed long value,unsigned char left,unsigned char right,unsigned char color,unsigned char space,unsigned char size);
extern void display_char_8bit(unsigned char x,unsigned char y,unsigned char color,unsigned char value);
extern void display_icon(struct tw_icon picon, unsigned char color, unsigned char x, unsigned char y);
extern void display_uncolor_icon(struct tw_icon picon,unsigned char x, unsigned char y);
extern void clear_icon(struct tw_icon picon,unsigned char x,unsigned char y);
extern void display_gicon(struct tw_gicon gpicon,unsigned char color,unsigned char x,unsigned char y);
extern void display_uncolor_gicon(struct tw_gicon gpicon,unsigned char x,unsigned char y);
extern void display_spr(struct tw_spr spr,unsigned int x,unsigned int y);
extern void clear_gicon(struct tw_gicon gpicon,unsigned char x,unsigned char y);
extern void clear_area_block(unsigned char x,unsigned char y,unsigned char width,unsigned char height);
extern void clear_unmark_area(void);
extern void clear_mark_area(void);
extern void clear_unalarm_area(void);
extern void clear_alarm_area(void);
extern void clear_time_area(void);
extern void clear_set_area(void);
extern void clear_mima_area(void);
extern unsigned char check_page(unsigned char page);
extern void page_switch(void);
extern void display_icon_blink(struct tw_icon picon,unsigned char x,unsigned char y,unsigned char color,unsigned char blinking);
extern void display_icon_uncolor_blink(struct tw_icon picon,unsigned char x,unsigned char y,unsigned char blinking);
extern void display_gicon_uncolor_blink(struct tw_gicon pgicon,unsigned char x,unsigned char y,unsigned char blinking);
void tw_icon_draw_blink(struct tw_icon* picon,unsigned char blinking);
void tw_gicon_draw_blink(struct tw_gicon* pgicon,unsigned char blinking);



#endif
