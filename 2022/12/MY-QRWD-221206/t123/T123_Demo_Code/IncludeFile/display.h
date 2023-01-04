#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#define ICVBS0			1
#define ICVBS1			2
#define ICVBS2			3
#define ICVBS3			4

#define SET_HOUR		0
#define SET_MINUTE		1
#define SET_YEAR		2
#define SET_MONTH		3
#define SET_DAY			4
#define SET_LIGHT		5
#define SET_BUZZER		6

typedef struct{
		unsigned char bit7:1;
		unsigned char bit6:1;
    		unsigned char bit5:1;
		unsigned char bit4:1;
    		unsigned char bit3:1;
		unsigned char bit2:1;
		unsigned char bit1:1;
		unsigned char bit0:1;	 		
}BIT_DATA;

typedef union{
	unsigned char byte;
	BIT_DATA ibit;
}TW_DATA;


extern TW_DATA  FLAG[5];
extern struct tw_icon code * buzzer_map[2];

#define	CLEAR_PAGE		FLAG[0].ibit.bit0
#define	LIGHT_EN		FLAG[0].ibit.bit1
#define	ENTER_ACC		FLAG[0].ibit.bit2
#define	ENTER_LOGO		FLAG[0].ibit.bit3
#define 	DISP_TIME		FLAG[0].ibit.bit4
#define	DISP_SOC		FLAG[0].ibit.bit5
#define	DISP_AIR		FLAG[0].ibit.bit6
#define	DISP_MILE		FLAG[0].ibit.bit7


extern void protocl_event(unsigned char cmd_type);
extern void display_meter_status(void);
extern void display_moudle_output_status(unsigned char x,unsigned int Lstatus,unsigned int Hstatus);
extern void display_moudle_input_status(unsigned int status,unsigned int vestigital);
extern void display_mark(void);
extern void display_air(void);
extern void display_soc(void);
extern void diplay_main_data(void);
extern void display_surface1(void);
extern void display_surface2(void);
extern void display_surface3(void);
extern void display_surface4(void);
extern void display_surface5(void);
extern void display_surface6(void);
extern void display_surface7(void);
extern void display_surface8s(void);
extern void display_surface8(void);
extern void display_surface9(void);
extern void display_surface10(void);
extern void display_surface11(void);
extern void display_surface12(void);
extern void display_surface13(void);
extern void display_surface14(void);
extern void display_surface15(void);
extern void display_surface16(void);
extern void display_surface17(void);
extern void display_surface18(void);
extern void display_surface19(void);
extern void display_surface20(void);
extern void display_surface21(void);
extern void display_system_time(void);
extern void display_set_time(void);
extern void display_unmark(void);
extern void display_init(void);
extern void display_mileage(void);
extern void display_fault_message(void);
#endif
