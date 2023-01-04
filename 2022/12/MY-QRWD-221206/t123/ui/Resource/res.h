#ifndef __RES_H__
#define __RES_H__

enum PAGE_ID_DEF {
	ID_PAGE_START = 1,
	ID_PAGE_LOGO,
	ID_PAGE_MAIN_INTERNAL,
	ID_PAGE_MAIN_MENUS,
	ID_PAGE_METER_MOUDLE,
	ID_PAGE_FRONT_MOUDLE,
	ID_PAGE_REAR_MOUDLE,
	ID_PAGE_TOP_MOUDLE,
	ID_PAGE_PARAMETER,
	ID_PAGE_HELP_MESSAGE,
	ID_PAGE_VIDEO,
	ID_PAGE_SURFACE1,
	ID_PAGE_SURFACE2,
	ID_PAGE_SURFACE3,
	ID_PAGE_SURFACE4,
	ID_PAGE_SURFACE5,
	ID_PAGE_SURFACE6,
	ID_PAGE_SURFACE7,
	ID_PAGE_SURFACE8,
	ID_PAGE_SURFACE9,
	ID_PAGE_SURFACE10,
	ID_PAGE_SURFACE11,
	ID_PAGE_SURFACE12,
	ID_PAGE_SURFACE13,
	ID_PAGE_SURFACE14,
	ID_PAGE_SURFACE15,
	ID_PAGE_SURFACE16,
	ID_PAGE_SURFACE17,
	ID_PAGE_SURFACE18,
	ID_PAGE_SURFACE19,
	ID_PAGE_SURFACE20,
	ID_PAGE_SURFACE21,
	TOTAL_PAGE_NUM
};

#define ID_MAIN_START 5033
//[TD Struct]
// color_addr : 0x000000
// index_addr : 0x0BD390
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_LOGO 5037
//[TD Struct]
// color_addr : 0x000320
// index_addr : 0x0BD458
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_PARAMETER 5034
//[TD Struct]
// color_addr : 0x02F1C0
// index_addr : 0x0EC190
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_HELP_MESSAGE 5038
//[TD Struct]
// color_addr : 0x02F4E0
// index_addr : 0x0EC258
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE6 5035
//[TD Struct]
// color_addr : 0x05E380
// index_addr : 0x11AF90
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE7 5039
//[TD Struct]
// color_addr : 0x05E6A0
// index_addr : 0x11B058
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE14 5036
//[TD Struct]
// color_addr : 0x08D540
// index_addr : 0x149D90
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE15 5040
//[TD Struct]
// color_addr : 0x08D860
// index_addr : 0x149E58
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_LOGO 5041
//[TD Struct]
// color_addr : 0x178B90
// index_addr : 0x235F20
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_MAIN_INTERNAL 5045
//[TD Struct]
// color_addr : 0x178EB0
// index_addr : 0x235FE8
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_HELP_MESSAGE 5042
//[TD Struct]
// color_addr : 0x1A7D50
// index_addr : 0x264D20
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_VIDEO 5046
//[TD Struct]
// color_addr : 0x1A8070
// index_addr : 0x264DE8
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE7 5043
//[TD Struct]
// color_addr : 0x1D6F10
// index_addr : 0x293B20
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE8 5047
//[TD Struct]
// color_addr : 0x1D7230
// index_addr : 0x293BE8
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE15 5044
//[TD Struct]
// color_addr : 0x2060D0
// index_addr : 0x2C2920
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE16 5048
//[TD Struct]
// color_addr : 0x2063F0
// index_addr : 0x2C29E8
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_MAIN_INTERNAL 5049
//[TD Struct]
// color_addr : 0x2F1720
// index_addr : 0x3AEAB0
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_MAIN_MENUS 5053
//[TD Struct]
// color_addr : 0x2F1A40
// index_addr : 0x3AEB78
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_VIDEO 5050
//[TD Struct]
// color_addr : 0x3208E0
// index_addr : 0x3DD8B0
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE1 5054
//[TD Struct]
// color_addr : 0x320C00
// index_addr : 0x3DD978
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE8 5051
//[TD Struct]
// color_addr : 0x34FAA0
// index_addr : 0x40C6B0
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE9 5055
//[TD Struct]
// color_addr : 0x34FDC0
// index_addr : 0x40C778
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE16 5052
//[TD Struct]
// color_addr : 0x37EC60
// index_addr : 0x43B4B0
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE17 5056
//[TD Struct]
// color_addr : 0x37EF80
// index_addr : 0x43B578
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_MAIN_MENUS 5057
//[TD Struct]
// color_addr : 0x46A2B0
// index_addr : 0x527640
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_METER_MOUDLE 5061
//[TD Struct]
// color_addr : 0x46A5D0
// index_addr : 0x527708
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE1 5058
//[TD Struct]
// color_addr : 0x499470
// index_addr : 0x556440
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE2 5062
//[TD Struct]
// color_addr : 0x499790
// index_addr : 0x556508
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE9 5059
//[TD Struct]
// color_addr : 0x4C8630
// index_addr : 0x585240
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE10 5063
//[TD Struct]
// color_addr : 0x4C8950
// index_addr : 0x585308
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE17 5060
//[TD Struct]
// color_addr : 0x4F77F0
// index_addr : 0x5B4040
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE18 5064
//[TD Struct]
// color_addr : 0x4F7B10
// index_addr : 0x5B4108
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_METER_MOUDLE 5065
//[TD Struct]
// color_addr : 0x5E2E40
// index_addr : 0x6A01D0
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_FRONT_MOUDLE 5069
//[TD Struct]
// color_addr : 0x5E3160
// index_addr : 0x6A0298
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE2 5066
//[TD Struct]
// color_addr : 0x612000
// index_addr : 0x6CEFD0
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE3 5070
//[TD Struct]
// color_addr : 0x612320
// index_addr : 0x6CF098
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE10 5067
//[TD Struct]
// color_addr : 0x6411C0
// index_addr : 0x6FDDD0
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE11 5071
//[TD Struct]
// color_addr : 0x6414E0
// index_addr : 0x6FDE98
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE18 5068
//[TD Struct]
// color_addr : 0x670380
// index_addr : 0x72CBD0
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE19 5072
//[TD Struct]
// color_addr : 0x6706A0
// index_addr : 0x72CC98
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_FRONT_MOUDLE 5073
//[TD Struct]
// color_addr : 0x75B9D0
// index_addr : 0x818D60
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_REAR_MOUDLE 5077
//[TD Struct]
// color_addr : 0x75BCF0
// index_addr : 0x818E28
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE3 5074
//[TD Struct]
// color_addr : 0x78AB90
// index_addr : 0x847B60
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE4 5078
//[TD Struct]
// color_addr : 0x78AEB0
// index_addr : 0x847C28
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE11 5075
//[TD Struct]
// color_addr : 0x7B9D50
// index_addr : 0x876960
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE12 5079
//[TD Struct]
// color_addr : 0x7BA070
// index_addr : 0x876A28
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE19 5076
//[TD Struct]
// color_addr : 0x7E8F10
// index_addr : 0x8A5760
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE20 5080
//[TD Struct]
// color_addr : 0x7E9230
// index_addr : 0x8A5828
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_REAR_MOUDLE 5081
//[TD Struct]
// color_addr : 0x8D4560
// index_addr : 0x9918F0
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TOP_MOUDLE 5085
//[TD Struct]
// color_addr : 0x8D4880
// index_addr : 0x9919B8
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE4 5082
//[TD Struct]
// color_addr : 0x903720
// index_addr : 0x9C06F0
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE5 5086
//[TD Struct]
// color_addr : 0x903A40
// index_addr : 0x9C07B8
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE12 5083
//[TD Struct]
// color_addr : 0x9328E0
// index_addr : 0x9EF4F0
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE13 5087
//[TD Struct]
// color_addr : 0x932C00
// index_addr : 0x9EF5B8
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_TD_R_SURFACE20 5084
//[TD Struct]
// color_addr : 0x961AA0
// index_addr : 0xA1E2F0
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_MAIN_SURFACE21 5088
//[TD Struct]
// color_addr : 0x961DC0
// index_addr : 0xA1E3B8
// line_jump  : 1600
// width      : 800
// height     : 480
#define ID_ICON_SPACE_W16_H24_1BP 5447
//[ICON Struct]
// base_addr  : 0xA4D0F0
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 1
// count      : 1
#define ID_ICON_BLACK 35
//[ICON Struct]
// base_addr  : 0xA4D120
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 1
// count      : 6
#define ID_ICON_SOC_0 36
//[ICON Struct]
// base_addr  : 0xA4D240
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 1
// count      : 1
#define ID_ICON_SOC_1 37
//[ICON Struct]
// base_addr  : 0xA4D270
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 1
// count      : 1
#define ID_ICON_SOC_2 38
//[ICON Struct]
// base_addr  : 0xA4D2A0
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 1
// count      : 1
#define ID_ICON_SOC_3 39
//[ICON Struct]
// base_addr  : 0xA4D2D0
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 1
// count      : 1
#define ID_ICON_SOC_4 40
//[ICON Struct]
// base_addr  : 0xA4D300
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 1
// count      : 1
#define ID_ICON_SOC_5 41
//[ICON Struct]
// base_addr  : 0xA4D330
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 1
// count      : 1
#define ID_ICON_SOC_6 42
//[ICON Struct]
// base_addr  : 0xA4D360
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 1
// count      : 1
#define ID_ICON_SOC_7 43
//[ICON Struct]
// base_addr  : 0xA4D390
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 1
// count      : 1
#define ID_ICON_AV 278
//[ICON Struct]
// base_addr  : 0xA4D3C0
// font_w     : 16
// font_h     : 24
// width      : 2
// height     : 1
// bp         : 2
// count      : 2
#define ID_ICON_FONT_CLOSE 279
//[ICON Struct]
// base_addr  : 0xA4D480
// font_w     : 16
// font_h     : 24
// width      : 2
// height     : 1
// bp         : 2
// count      : 2
#define ID_ICON_FONT_OPEN 280
//[ICON Struct]
// base_addr  : 0xA4D540
// font_w     : 16
// font_h     : 24
// width      : 2
// height     : 1
// bp         : 2
// count      : 2
#define ID_ICON_NUMBER_0 281
//[ICON Struct]
// base_addr  : 0xA4D600
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_1 282
//[ICON Struct]
// base_addr  : 0xA4D660
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_2 283
//[ICON Struct]
// base_addr  : 0xA4D6C0
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_3 284
//[ICON Struct]
// base_addr  : 0xA4D720
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_4 285
//[ICON Struct]
// base_addr  : 0xA4D780
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_5 286
//[ICON Struct]
// base_addr  : 0xA4D7E0
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_6 287
//[ICON Struct]
// base_addr  : 0xA4D840
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_7 288
//[ICON Struct]
// base_addr  : 0xA4D8A0
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_8 289
//[ICON Struct]
// base_addr  : 0xA4D900
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_9 290
//[ICON Struct]
// base_addr  : 0xA4D960
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_10 291
//[ICON Struct]
// base_addr  : 0xA4D9C0
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_A 292
//[ICON Struct]
// base_addr  : 0xA4DA20
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_POINT_0 298
//[ICON Struct]
// base_addr  : 0xA4DA80
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_POINT_1 299
//[ICON Struct]
// base_addr  : 0xA4DAE0
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_POINT_2 300
//[ICON Struct]
// base_addr  : 0xA4DB40
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_POINT_3 301
//[ICON Struct]
// base_addr  : 0xA4DBA0
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_POINT_4 302
//[ICON Struct]
// base_addr  : 0xA4DC00
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_POINT_5 303
//[ICON Struct]
// base_addr  : 0xA4DC60
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_POINT_6 304
//[ICON Struct]
// base_addr  : 0xA4DCC0
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_POINT_7 305
//[ICON Struct]
// base_addr  : 0xA4DD20
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_POINT_8 306
//[ICON Struct]
// base_addr  : 0xA4DD80
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_NUMBER_POINT_9 307
//[ICON Struct]
// base_addr  : 0xA4DDE0
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_X 311
//[ICON Struct]
// base_addr  : 0xA4DE40
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_FAULT_ALARM_0 617
//[ICON Struct]
// base_addr  : 0xA4DEA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_1 618
//[ICON Struct]
// base_addr  : 0xA4EF20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_2 619
//[ICON Struct]
// base_addr  : 0xA4FFA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_3 620
//[ICON Struct]
// base_addr  : 0xA51020
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_4 621
//[ICON Struct]
// base_addr  : 0xA520A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_5 622
//[ICON Struct]
// base_addr  : 0xA53120
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_6 623
//[ICON Struct]
// base_addr  : 0xA541A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_7 624
//[ICON Struct]
// base_addr  : 0xA55220
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_8 625
//[ICON Struct]
// base_addr  : 0xA562A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_9 626
//[ICON Struct]
// base_addr  : 0xA57320
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_10 627
//[ICON Struct]
// base_addr  : 0xA583A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_11 628
//[ICON Struct]
// base_addr  : 0xA59420
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_12 629
//[ICON Struct]
// base_addr  : 0xA5A4A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_13 630
//[ICON Struct]
// base_addr  : 0xA5B520
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_14 631
//[ICON Struct]
// base_addr  : 0xA5C5A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_15 632
//[ICON Struct]
// base_addr  : 0xA5D620
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_16 633
//[ICON Struct]
// base_addr  : 0xA5E6A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_17 634
//[ICON Struct]
// base_addr  : 0xA5F720
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_18 635
//[ICON Struct]
// base_addr  : 0xA607A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_19 636
//[ICON Struct]
// base_addr  : 0xA61820
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_20 637
//[ICON Struct]
// base_addr  : 0xA628A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_21 638
//[ICON Struct]
// base_addr  : 0xA63920
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_22 639
//[ICON Struct]
// base_addr  : 0xA649A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_23 640
//[ICON Struct]
// base_addr  : 0xA65A20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_24 641
//[ICON Struct]
// base_addr  : 0xA66AA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_25 642
//[ICON Struct]
// base_addr  : 0xA67B20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_26 643
//[ICON Struct]
// base_addr  : 0xA68BA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_27 644
//[ICON Struct]
// base_addr  : 0xA69C20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_28 645
//[ICON Struct]
// base_addr  : 0xA6ACA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_29 646
//[ICON Struct]
// base_addr  : 0xA6BD20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_30 647
//[ICON Struct]
// base_addr  : 0xA6CDA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_31 648
//[ICON Struct]
// base_addr  : 0xA6DE20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_32 649
//[ICON Struct]
// base_addr  : 0xA6EEA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_33 650
//[ICON Struct]
// base_addr  : 0xA6FF20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_34 651
//[ICON Struct]
// base_addr  : 0xA70FA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_35 652
//[ICON Struct]
// base_addr  : 0xA72020
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_36 653
//[ICON Struct]
// base_addr  : 0xA730A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_37 654
//[ICON Struct]
// base_addr  : 0xA74120
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_38 655
//[ICON Struct]
// base_addr  : 0xA751A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_39 656
//[ICON Struct]
// base_addr  : 0xA76220
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_40 657
//[ICON Struct]
// base_addr  : 0xA772A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_41 658
//[ICON Struct]
// base_addr  : 0xA78320
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_42 659
//[ICON Struct]
// base_addr  : 0xA793A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_43 660
//[ICON Struct]
// base_addr  : 0xA7A420
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_44 661
//[ICON Struct]
// base_addr  : 0xA7B4A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_45 662
//[ICON Struct]
// base_addr  : 0xA7C520
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_46 663
//[ICON Struct]
// base_addr  : 0xA7D5A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_47 664
//[ICON Struct]
// base_addr  : 0xA7E620
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_48 665
//[ICON Struct]
// base_addr  : 0xA7F6A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_49 666
//[ICON Struct]
// base_addr  : 0xA80720
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_50 667
//[ICON Struct]
// base_addr  : 0xA817A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_51 668
//[ICON Struct]
// base_addr  : 0xA82820
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_52 669
//[ICON Struct]
// base_addr  : 0xA838A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_53 670
//[ICON Struct]
// base_addr  : 0xA84920
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_54 671
//[ICON Struct]
// base_addr  : 0xA859A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_55 672
//[ICON Struct]
// base_addr  : 0xA86A20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_56 673
//[ICON Struct]
// base_addr  : 0xA87AA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_57 674
//[ICON Struct]
// base_addr  : 0xA88B20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_58 675
//[ICON Struct]
// base_addr  : 0xA89BA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_59 676
//[ICON Struct]
// base_addr  : 0xA8AC20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_60 677
//[ICON Struct]
// base_addr  : 0xA8BCA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_61 678
//[ICON Struct]
// base_addr  : 0xA8CD20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_62 679
//[ICON Struct]
// base_addr  : 0xA8DDA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_63 680
//[ICON Struct]
// base_addr  : 0xA8EE20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_64 681
//[ICON Struct]
// base_addr  : 0xA8FEA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_65 682
//[ICON Struct]
// base_addr  : 0xA90F20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_66 683
//[ICON Struct]
// base_addr  : 0xA91FA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_67 684
//[ICON Struct]
// base_addr  : 0xA93020
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_68 685
//[ICON Struct]
// base_addr  : 0xA940A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_69 686
//[ICON Struct]
// base_addr  : 0xA95120
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_70 687
//[ICON Struct]
// base_addr  : 0xA961A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_71 688
//[ICON Struct]
// base_addr  : 0xA97220
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_72 689
//[ICON Struct]
// base_addr  : 0xA982A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_73 690
//[ICON Struct]
// base_addr  : 0xA99320
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_74 691
//[ICON Struct]
// base_addr  : 0xA9A3A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_75 692
//[ICON Struct]
// base_addr  : 0xA9B420
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_76 693
//[ICON Struct]
// base_addr  : 0xA9C4A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_77 694
//[ICON Struct]
// base_addr  : 0xA9D520
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_78 695
//[ICON Struct]
// base_addr  : 0xA9E5A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_79 696
//[ICON Struct]
// base_addr  : 0xA9F620
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_80 697
//[ICON Struct]
// base_addr  : 0xAA06A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_81 698
//[ICON Struct]
// base_addr  : 0xAA1720
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_82 699
//[ICON Struct]
// base_addr  : 0xAA27A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_83 700
//[ICON Struct]
// base_addr  : 0xAA3820
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_84 701
//[ICON Struct]
// base_addr  : 0xAA48A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_85 702
//[ICON Struct]
// base_addr  : 0xAA5920
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_86 703
//[ICON Struct]
// base_addr  : 0xAA69A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_87 704
//[ICON Struct]
// base_addr  : 0xAA7A20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_88 705
//[ICON Struct]
// base_addr  : 0xAA8AA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_89 706
//[ICON Struct]
// base_addr  : 0xAA9B20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_90 707
//[ICON Struct]
// base_addr  : 0xAAABA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_91 708
//[ICON Struct]
// base_addr  : 0xAABC20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_92 709
//[ICON Struct]
// base_addr  : 0xAACCA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_93 710
//[ICON Struct]
// base_addr  : 0xAADD20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_94 711
//[ICON Struct]
// base_addr  : 0xAAEDA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_95 712
//[ICON Struct]
// base_addr  : 0xAAFE20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_96 713
//[ICON Struct]
// base_addr  : 0xAB0EA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_97 714
//[ICON Struct]
// base_addr  : 0xAB1F20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_98 715
//[ICON Struct]
// base_addr  : 0xAB2FA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_99 716
//[ICON Struct]
// base_addr  : 0xAB4020
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_100 717
//[ICON Struct]
// base_addr  : 0xAB50A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_101 718
//[ICON Struct]
// base_addr  : 0xAB6120
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_102 719
//[ICON Struct]
// base_addr  : 0xAB71A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_103 720
//[ICON Struct]
// base_addr  : 0xAB8220
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_104 721
//[ICON Struct]
// base_addr  : 0xAB92A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_105 722
//[ICON Struct]
// base_addr  : 0xABA320
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_106 723
//[ICON Struct]
// base_addr  : 0xABB3A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_107 724
//[ICON Struct]
// base_addr  : 0xABC420
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_108 725
//[ICON Struct]
// base_addr  : 0xABD4A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_109 726
//[ICON Struct]
// base_addr  : 0xABE520
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_110 727
//[ICON Struct]
// base_addr  : 0xABF5A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_111 728
//[ICON Struct]
// base_addr  : 0xAC0620
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_112 729
//[ICON Struct]
// base_addr  : 0xAC16A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_113 730
//[ICON Struct]
// base_addr  : 0xAC2720
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_114 731
//[ICON Struct]
// base_addr  : 0xAC37A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_115 732
//[ICON Struct]
// base_addr  : 0xAC4820
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_116 733
//[ICON Struct]
// base_addr  : 0xAC58A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_117 734
//[ICON Struct]
// base_addr  : 0xAC6920
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_118 735
//[ICON Struct]
// base_addr  : 0xAC79A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_119 736
//[ICON Struct]
// base_addr  : 0xAC8A20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_120 737
//[ICON Struct]
// base_addr  : 0xAC9AA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_121 738
//[ICON Struct]
// base_addr  : 0xACAB20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_122 739
//[ICON Struct]
// base_addr  : 0xACBBA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_123 740
//[ICON Struct]
// base_addr  : 0xACCC20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_124 741
//[ICON Struct]
// base_addr  : 0xACDCA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_125 742
//[ICON Struct]
// base_addr  : 0xACED20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_126 743
//[ICON Struct]
// base_addr  : 0xACFDA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_127 744
//[ICON Struct]
// base_addr  : 0xAD0E20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_128 745
//[ICON Struct]
// base_addr  : 0xAD1EA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_129 746
//[ICON Struct]
// base_addr  : 0xAD2F20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_130 747
//[ICON Struct]
// base_addr  : 0xAD3FA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_131 748
//[ICON Struct]
// base_addr  : 0xAD5020
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_132 749
//[ICON Struct]
// base_addr  : 0xAD60A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_133 750
//[ICON Struct]
// base_addr  : 0xAD7120
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_134 751
//[ICON Struct]
// base_addr  : 0xAD81A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_135 752
//[ICON Struct]
// base_addr  : 0xAD9220
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_136 753
//[ICON Struct]
// base_addr  : 0xADA2A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_137 754
//[ICON Struct]
// base_addr  : 0xADB320
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_138 755
//[ICON Struct]
// base_addr  : 0xADC3A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_139 756
//[ICON Struct]
// base_addr  : 0xADD420
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_140 757
//[ICON Struct]
// base_addr  : 0xADE4A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_141 758
//[ICON Struct]
// base_addr  : 0xADF520
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_142 759
//[ICON Struct]
// base_addr  : 0xAE05A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_143 760
//[ICON Struct]
// base_addr  : 0xAE1620
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_144 761
//[ICON Struct]
// base_addr  : 0xAE26A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_145 762
//[ICON Struct]
// base_addr  : 0xAE3720
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_146 763
//[ICON Struct]
// base_addr  : 0xAE47A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_147 764
//[ICON Struct]
// base_addr  : 0xAE5820
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_148 765
//[ICON Struct]
// base_addr  : 0xAE68A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_149 766
//[ICON Struct]
// base_addr  : 0xAE7920
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_150 767
//[ICON Struct]
// base_addr  : 0xAE89A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_151 768
//[ICON Struct]
// base_addr  : 0xAE9A20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_152 769
//[ICON Struct]
// base_addr  : 0xAEAAA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_153 770
//[ICON Struct]
// base_addr  : 0xAEBB20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_154 771
//[ICON Struct]
// base_addr  : 0xAECBA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_155 772
//[ICON Struct]
// base_addr  : 0xAEDC20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_156 773
//[ICON Struct]
// base_addr  : 0xAEECA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_157 774
//[ICON Struct]
// base_addr  : 0xAEFD20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_158 775
//[ICON Struct]
// base_addr  : 0xAF0DA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_159 776
//[ICON Struct]
// base_addr  : 0xAF1E20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_160 777
//[ICON Struct]
// base_addr  : 0xAF2EA0
// font_w     : 16
// font_h     : 24
// width      : 18
// height     : 2
// bp         : 2
// count      : 36
#define ID_ICON_FAULT_ALARM_161 778
//[ICON Struct]
// base_addr  : 0xAF3C20
// font_w     : 16
// font_h     : 24
// width      : 18
// height     : 2
// bp         : 2
// count      : 36
#define ID_ICON_FAULT_ALARM_162 779
//[ICON Struct]
// base_addr  : 0xAF49A0
// font_w     : 16
// font_h     : 24
// width      : 18
// height     : 2
// bp         : 2
// count      : 36
#define ID_ICON_FAULT_ALARM_163 780
//[ICON Struct]
// base_addr  : 0xAF5720
// font_w     : 16
// font_h     : 24
// width      : 18
// height     : 2
// bp         : 2
// count      : 36
#define ID_ICON_FAULT_ALARM_164 781
//[ICON Struct]
// base_addr  : 0xAF64A0
// font_w     : 16
// font_h     : 24
// width      : 18
// height     : 2
// bp         : 2
// count      : 36
#define ID_ICON_FAULT_ALARM_165 782
//[ICON Struct]
// base_addr  : 0xAF7220
// font_w     : 16
// font_h     : 24
// width      : 18
// height     : 2
// bp         : 2
// count      : 36
#define ID_ICON_FAULT_ALARM_166 783
//[ICON Struct]
// base_addr  : 0xAF7FA0
// font_w     : 16
// font_h     : 24
// width      : 18
// height     : 2
// bp         : 2
// count      : 36
#define ID_ICON_FAULT_ALARM_167 784
//[ICON Struct]
// base_addr  : 0xAF8D20
// font_w     : 16
// font_h     : 24
// width      : 18
// height     : 2
// bp         : 2
// count      : 36
#define ID_ICON_FAULT_ALARM_168 785
//[ICON Struct]
// base_addr  : 0xAF9AA0
// font_w     : 16
// font_h     : 24
// width      : 18
// height     : 2
// bp         : 2
// count      : 36
#define ID_ICON_FAULT_ALARM_169 786
//[ICON Struct]
// base_addr  : 0xAFA820
// font_w     : 16
// font_h     : 24
// width      : 20
// height     : 2
// bp         : 2
// count      : 40
#define ID_ICON_FAULT_ALARM_170 787
//[ICON Struct]
// base_addr  : 0xAFB720
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_171 809
//[ICON Struct]
// base_addr  : 0xAFC7A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_172 810
//[ICON Struct]
// base_addr  : 0xAFD820
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_173 811
//[ICON Struct]
// base_addr  : 0xAFE8A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_174 812
//[ICON Struct]
// base_addr  : 0xAFF920
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_175 813
//[ICON Struct]
// base_addr  : 0xB009A0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_176 814
//[ICON Struct]
// base_addr  : 0xB01A20
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_177 815
//[ICON Struct]
// base_addr  : 0xB02AA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_FAULT_ALARM_178 822
//[ICON Struct]
// base_addr  : 0xB03B20
// font_w     : 16
// font_h     : 24
// width      : 14
// height     : 2
// bp         : 2
// count      : 28
#define ID_ICON_FAULT_ALARM_179 823
//[ICON Struct]
// base_addr  : 0xB045A0
// font_w     : 16
// font_h     : 24
// width      : 16
// height     : 2
// bp         : 2
// count      : 32
#define ID_ICON_FAULT_ALARM_180 824
//[ICON Struct]
// base_addr  : 0xB051A0
// font_w     : 16
// font_h     : 24
// width      : 14
// height     : 2
// bp         : 2
// count      : 28
#define ID_ICON_FAULT_ALARM_181 825
//[ICON Struct]
// base_addr  : 0xB05C20
// font_w     : 16
// font_h     : 24
// width      : 14
// height     : 2
// bp         : 2
// count      : 28
#define ID_ICON_FAULT_ALARM_182 826
//[ICON Struct]
// base_addr  : 0xB066A0
// font_w     : 16
// font_h     : 24
// width      : 14
// height     : 2
// bp         : 2
// count      : 28
#define ID_ICON_FAULT_ALARM_183 827
//[ICON Struct]
// base_addr  : 0xB07120
// font_w     : 16
// font_h     : 24
// width      : 14
// height     : 2
// bp         : 2
// count      : 28
#define ID_ICON_FAULT_ALARM_184 829
//[ICON Struct]
// base_addr  : 0xB07BA0
// font_w     : 16
// font_h     : 24
// width      : 22
// height     : 2
// bp         : 2
// count      : 44
#define ID_ICON_OFF 312
//[ICON Struct]
// base_addr  : 0xB08C20
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_ON 313
//[ICON Struct]
// base_addr  : 0xB08D40
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_YUUNXING 522
//[ICON Struct]
// base_addr  : 0xB08E60
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_D 594
//[ICON Struct]
// base_addr  : 0xB08F80
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_D1 595
//[ICON Struct]
// base_addr  : 0xB090A0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_D2 596
//[ICON Struct]
// base_addr  : 0xB091C0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_D3 597
//[ICON Struct]
// base_addr  : 0xB092E0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_D4 598
//[ICON Struct]
// base_addr  : 0xB09400
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_D5 599
//[ICON Struct]
// base_addr  : 0xB09520
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_D6 600
//[ICON Struct]
// base_addr  : 0xB09640
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_D7 601
//[ICON Struct]
// base_addr  : 0xB09760
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_D8 602
//[ICON Struct]
// base_addr  : 0xB09880
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_D9 603
//[ICON Struct]
// base_addr  : 0xB099A0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_D10 604
//[ICON Struct]
// base_addr  : 0xB09AC0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_D11 605
//[ICON Struct]
// base_addr  : 0xB09BE0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_D12 606
//[ICON Struct]
// base_addr  : 0xB09D00
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_N 610
//[ICON Struct]
// base_addr  : 0xB09E20
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_P 611
//[ICON Struct]
// base_addr  : 0xB09F40
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_R 612
//[ICON Struct]
// base_addr  : 0xB0A060
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S16_TINGJI 591
//[ICON Struct]
// base_addr  : 0xB0A180
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_WUXIAO 615
//[ICON Struct]
// base_addr  : 0xB0A2A0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_YOUXIAO 616
//[ICON Struct]
// base_addr  : 0xB0A3C0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_GZ 520
//[ICON Struct]
// base_addr  : 0xB0A4E0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_TINGJI 521
//[ICON Struct]
// base_addr  : 0xB0A600
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_WEITINGJI 525
//[ICON Struct]
// base_addr  : 0xB0A720
// font_w     : 16
// font_h     : 24
// width      : 4
// height     : 1
// bp         : 2
// count      : 4
#define ID_ICON_YITINGJI 526
//[ICON Struct]
// base_addr  : 0xB0A8A0
// font_w     : 16
// font_h     : 24
// width      : 4
// height     : 1
// bp         : 2
// count      : 4
#define ID_ICON_S1_CHADIAN 592
//[ICON Struct]
// base_addr  : 0xB0AA20
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_CHUNDIAN 593
//[ICON Struct]
// base_addr  : 0xB0AB40
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_HUNDONG 607
//[ICON Struct]
// base_addr  : 0xB0AC60
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_DIYA 523
//[ICON Struct]
// base_addr  : 0xB0AD80
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_GAOYA 524
//[ICON Struct]
// base_addr  : 0xB0AEA0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_KUAICHONG 608
//[ICON Struct]
// base_addr  : 0xB0AFC0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_MANCHONG 609
//[ICON Struct]
// base_addr  : 0xB0B0E0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S1_ZIJIAN 613
//[ICON Struct]
// base_addr  : 0xB0B200
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_ERJIGZ 527
//[ICON Struct]
// base_addr  : 0xB0B320
// font_w     : 16
// font_h     : 24
// width      : 6
// height     : 1
// bp         : 2
// count      : 6
#define ID_ICON_SANJIGZ 528
//[ICON Struct]
// base_addr  : 0xB0B560
// font_w     : 16
// font_h     : 24
// width      : 6
// height     : 1
// bp         : 2
// count      : 6
#define ID_ICON_YIJIGZ 529
//[ICON Struct]
// base_addr  : 0xB0B7A0
// font_w     : 16
// font_h     : 24
// width      : 6
// height     : 1
// bp         : 2
// count      : 6
#define ID_ICON_S20_G1_CAN 788
//[ICON Struct]
// base_addr  : 0xB0B9E0
// font_w     : 16
// font_h     : 24
// width      : 9
// height     : 1
// bp         : 2
// count      : 9
#define ID_ICON_S20_G1_CHUANGANQI 789
//[ICON Struct]
// base_addr  : 0xB0BD40
// font_w     : 16
// font_h     : 24
// width      : 9
// height     : 1
// bp         : 2
// count      : 9
#define ID_ICON_S20_G1_EBS 790
//[ICON Struct]
// base_addr  : 0xB0C0A0
// font_w     : 16
// font_h     : 24
// width      : 9
// height     : 1
// bp         : 2
// count      : 9
#define ID_ICON_S20_G1_FADIAN 791
//[ICON Struct]
// base_addr  : 0xB0C400
// font_w     : 16
// font_h     : 24
// width      : 9
// height     : 1
// bp         : 2
// count      : 9
#define ID_ICON_S20_G1_JINQI 792
//[ICON Struct]
// base_addr  : 0xB0C760
// font_w     : 16
// font_h     : 24
// width      : 9
// height     : 1
// bp         : 2
// count      : 9
#define ID_ICON_S20_G1_KAIGUAN 793
//[ICON Struct]
// base_addr  : 0xB0CAC0
// font_w     : 16
// font_h     : 24
// width      : 9
// height     : 1
// bp         : 2
// count      : 9
#define ID_ICON_S20_G1_MOKUAI 794
//[ICON Struct]
// base_addr  : 0xB0CE20
// font_w     : 16
// font_h     : 24
// width      : 9
// height     : 1
// bp         : 2
// count      : 9
#define ID_ICON_S20_G1_PAIQI 795
//[ICON Struct]
// base_addr  : 0xB0D180
// font_w     : 16
// font_h     : 24
// width      : 9
// height     : 1
// bp         : 2
// count      : 9
#define ID_ICON_S20_G1_ZHIDONG 796
//[ICON Struct]
// base_addr  : 0xB0D4E0
// font_w     : 16
// font_h     : 24
// width      : 9
// height     : 1
// bp         : 2
// count      : 9
#define ID_ICON_S3_DAIJI 575
//[ICON Struct]
// base_addr  : 0xB0D840
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S3_YUNXING 576
//[ICON Struct]
// base_addr  : 0xB0D960
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_S20_G2_CANDUANLU 797
//[ICON Struct]
// base_addr  : 0xB0DA80
// font_w     : 16
// font_h     : 24
// width      : 8
// height     : 1
// bp         : 2
// count      : 8
#define ID_ICON_S20_G2_CHUANGANQI 798
//[ICON Struct]
// base_addr  : 0xB0DD80
// font_w     : 16
// font_h     : 24
// width      : 8
// height     : 1
// bp         : 2
// count      : 8
#define ID_ICON_S20_G2_DI 799
//[ICON Struct]
// base_addr  : 0xB0E080
// font_w     : 16
// font_h     : 24
// width      : 8
// height     : 1
// bp         : 2
// count      : 8
#define ID_ICON_S20_G2_DIANYADI 800
//[ICON Struct]
// base_addr  : 0xB0E380
// font_w     : 16
// font_h     : 24
// width      : 8
// height     : 1
// bp         : 2
// count      : 8
#define ID_ICON_S20_G2_DIANYAGAO 801
//[ICON Struct]
// base_addr  : 0xB0E680
// font_w     : 16
// font_h     : 24
// width      : 8
// height     : 1
// bp         : 2
// count      : 8
#define ID_ICON_S20_G2_DIANYUAN 802
//[ICON Struct]
// base_addr  : 0xB0E980
// font_w     : 16
// font_h     : 24
// width      : 8
// height     : 1
// bp         : 2
// count      : 8
#define ID_ICON_S20_G2_DIUSHI 803
//[ICON Struct]
// base_addr  : 0xB0EC80
// font_w     : 16
// font_h     : 24
// width      : 8
// height     : 1
// bp         : 2
// count      : 8
#define ID_ICON_S20_G2_DUANLU 804
//[ICON Struct]
// base_addr  : 0xB0EF80
// font_w     : 16
// font_h     : 24
// width      : 8
// height     : 1
// bp         : 2
// count      : 8
#define ID_ICON_S20_G2_EBS 805
//[ICON Struct]
// base_addr  : 0xB0F280
// font_w     : 16
// font_h     : 24
// width      : 8
// height     : 1
// bp         : 2
// count      : 8
#define ID_ICON_S20_G2_FATI 806
//[ICON Struct]
// base_addr  : 0xB0F580
// font_w     : 16
// font_h     : 24
// width      : 8
// height     : 1
// bp         : 2
// count      : 8
#define ID_ICON_S20_G2_KAIGUAN 807
//[ICON Struct]
// base_addr  : 0xB0F880
// font_w     : 16
// font_h     : 24
// width      : 8
// height     : 1
// bp         : 2
// count      : 8
#define ID_ICON_S20_G2_THREE 808
//[ICON Struct]
// base_addr  : 0xB0FB80
// font_w     : 16
// font_h     : 24
// width      : 8
// height     : 1
// bp         : 2
// count      : 8
#define ID_ICON_GUZHANG 514
//[ICON Struct]
// base_addr  : 0xB0FE80
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_ZHENGCHANG 515
//[ICON Struct]
// base_addr  : 0xB0FFA0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_GUANBI 573
//[ICON Struct]
// base_addr  : 0xB100C0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_QIDONG 574
//[ICON Struct]
// base_addr  : 0xB101E0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_FAULT_NUMBER_0 534
//[ICON Struct]
// base_addr  : 0xB10300
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 2
// bp         : 2
// count      : 2
#define ID_ICON_FAULT_NUMBER_1 535
//[ICON Struct]
// base_addr  : 0xB103C0
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 2
// bp         : 2
// count      : 2
#define ID_ICON_FAULT_NUMBER_2 536
//[ICON Struct]
// base_addr  : 0xB10480
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 2
// bp         : 2
// count      : 2
#define ID_ICON_FAULT_NUMBER_3 537
//[ICON Struct]
// base_addr  : 0xB10540
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 2
// bp         : 2
// count      : 2
#define ID_ICON_FAULT_NUMBER_4 538
//[ICON Struct]
// base_addr  : 0xB10600
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 2
// bp         : 2
// count      : 2
#define ID_ICON_FAULT_NUMBER_5 539
//[ICON Struct]
// base_addr  : 0xB106C0
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 2
// bp         : 2
// count      : 2
#define ID_ICON_FAULT_NUMBER_6 540
//[ICON Struct]
// base_addr  : 0xB10780
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 2
// bp         : 2
// count      : 2
#define ID_ICON_FAULT_NUMBER_7 541
//[ICON Struct]
// base_addr  : 0xB10840
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 2
// bp         : 2
// count      : 2
#define ID_ICON_FAULT_NUMBER_8 542
//[ICON Struct]
// base_addr  : 0xB10900
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 2
// bp         : 2
// count      : 2
#define ID_ICON_FAULT_NUMBER_9 543
//[ICON Struct]
// base_addr  : 0xB109C0
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 2
// bp         : 2
// count      : 2
#define ID_ICON_S9_READY 828
//[ICON Struct]
// base_addr  : 0xB10A80
// font_w     : 16
// font_h     : 24
// width      : 4
// height     : 1
// bp         : 2
// count      : 4
#define ID_ICON_ALARM_POS_0 830
//[ICON Struct]
// base_addr  : 0xB10C00
// font_w     : 16
// font_h     : 24
// width      : 4
// height     : 2
// bp         : 2
// count      : 8
#define ID_ICON_ALARM_POS_1 831
//[ICON Struct]
// base_addr  : 0xB10F00
// font_w     : 16
// font_h     : 24
// width      : 4
// height     : 2
// bp         : 2
// count      : 8
#define ID_ICON_ALARM_POS_2 832
//[ICON Struct]
// base_addr  : 0xB11200
// font_w     : 16
// font_h     : 24
// width      : 6
// height     : 2
// bp         : 2
// count      : 12
#define ID_ICON_ALARM_POS_3 833
//[ICON Struct]
// base_addr  : 0xB11680
// font_w     : 16
// font_h     : 24
// width      : 6
// height     : 2
// bp         : 2
// count      : 12
#define ID_ICON_ALARM_POS_4 834
//[ICON Struct]
// base_addr  : 0xB11B00
// font_w     : 16
// font_h     : 24
// width      : 6
// height     : 2
// bp         : 2
// count      : 12
#define ID_ICON_ALARM_POS_5 835
//[ICON Struct]
// base_addr  : 0xB11F80
// font_w     : 16
// font_h     : 24
// width      : 6
// height     : 2
// bp         : 2
// count      : 12
#define ID_ICON_FAULT_ALARM_185 836
//[ICON Struct]
// base_addr  : 0xB12400
// font_w     : 16
// font_h     : 24
// width      : 19
// height     : 2
// bp         : 2
// count      : 38
#define ID_ICON_FAULT_ALARM_186 837
//[ICON Struct]
// base_addr  : 0xB13240
// font_w     : 16
// font_h     : 24
// width      : 19
// height     : 2
// bp         : 2
// count      : 38
#define ID_ICON_FAULT_ALARM_187 838
//[ICON Struct]
// base_addr  : 0xB14080
// font_w     : 16
// font_h     : 24
// width      : 19
// height     : 2
// bp         : 2
// count      : 38
#define ID_ICON_FAULT_ALARM_188 839
//[ICON Struct]
// base_addr  : 0xB14EC0
// font_w     : 16
// font_h     : 24
// width      : 19
// height     : 2
// bp         : 2
// count      : 38
#define ID_ICON_FAULT_ALARM_189 840
//[ICON Struct]
// base_addr  : 0xB15D00
// font_w     : 16
// font_h     : 24
// width      : 19
// height     : 2
// bp         : 2
// count      : 38
#define ID_ICON_FAULT_ALARM_190 841
//[ICON Struct]
// base_addr  : 0xB16B40
// font_w     : 16
// font_h     : 24
// width      : 19
// height     : 2
// bp         : 2
// count      : 38
#define ID_ICON_FAULT_ALARM_191 842
//[ICON Struct]
// base_addr  : 0xB17980
// font_w     : 16
// font_h     : 24
// width      : 19
// height     : 2
// bp         : 2
// count      : 38
#define ID_ICON_FAULT_ALARM_192 843
//[ICON Struct]
// base_addr  : 0xB187C0
// font_w     : 16
// font_h     : 24
// width      : 19
// height     : 2
// bp         : 2
// count      : 38
#define ID_ICON_FAULT_ALARM_193 844
//[ICON Struct]
// base_addr  : 0xB19600
// font_w     : 16
// font_h     : 24
// width      : 19
// height     : 2
// bp         : 2
// count      : 38
#define ID_ICON_FAULT_ALARM_194 845
//[ICON Struct]
// base_addr  : 0xB1A440
// font_w     : 16
// font_h     : 24
// width      : 20
// height     : 2
// bp         : 2
// count      : 40
#define ID_ICON_FAULT_ALARM_195 846
//[ICON Struct]
// base_addr  : 0xB1B340
// font_w     : 16
// font_h     : 24
// width      : 10
// height     : 2
// bp         : 2
// count      : 20
#define ID_ICON_FAULT_ALARM_196 847
//[ICON Struct]
// base_addr  : 0xB1BAC0
// font_w     : 16
// font_h     : 24
// width      : 10
// height     : 2
// bp         : 2
// count      : 20
#define ID_ICON_FAULT_ALARM_197 848
//[ICON Struct]
// base_addr  : 0xB1C240
// font_w     : 16
// font_h     : 24
// width      : 10
// height     : 2
// bp         : 2
// count      : 20
#define ID_ICON_FAULT_ALARM_198 849
//[ICON Struct]
// base_addr  : 0xB1C9C0
// font_w     : 16
// font_h     : 24
// width      : 14
// height     : 2
// bp         : 2
// count      : 28
#define ID_ICON_FAULT_ALARM_199 850
//[ICON Struct]
// base_addr  : 0xB1D440
// font_w     : 16
// font_h     : 24
// width      : 8
// height     : 2
// bp         : 2
// count      : 16
#define ID_ICON_BIHE 851
//[ICON Struct]
// base_addr  : 0xB1DA40
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_DUANKAI 852
//[ICON Struct]
// base_addr  : 0xB1DB60
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 1
// bp         : 2
// count      : 3
#define ID_ICON_ARROWS 202
//[ICON Struct]
// base_addr  : 0xB1DC80
// font_w     : 16
// font_h     : 24
// width      : 2
// height     : 1
// bp         : 4
// count      : 2
#define ID_ICON_FAULT_FLAG_RED 203
//[ICON Struct]
// base_addr  : 0xB1DE00
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_STATUS_GREEN 235
//[ICON Struct]
// base_addr  : 0xB1E280
// font_w     : 16
// font_h     : 24
// width      : 2
// height     : 1
// bp         : 4
// count      : 2
#define ID_ICON_STATUS_RED 236
//[ICON Struct]
// base_addr  : 0xB1E400
// font_w     : 16
// font_h     : 24
// width      : 2
// height     : 1
// bp         : 4
// count      : 2
#define ID_ICON_MARK_D 243
//[ICON Struct]
// base_addr  : 0xB1E580
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_D1 244
//[ICON Struct]
// base_addr  : 0xB1EA00
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_D2 245
//[ICON Struct]
// base_addr  : 0xB1EE80
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_D3 246
//[ICON Struct]
// base_addr  : 0xB1F300
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_D4 247
//[ICON Struct]
// base_addr  : 0xB1F780
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_D5 248
//[ICON Struct]
// base_addr  : 0xB1FC00
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_D6 249
//[ICON Struct]
// base_addr  : 0xB20080
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_D7 250
//[ICON Struct]
// base_addr  : 0xB20500
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_D8 251
//[ICON Struct]
// base_addr  : 0xB20980
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_D9 252
//[ICON Struct]
// base_addr  : 0xB20E00
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_D10 253
//[ICON Struct]
// base_addr  : 0xB21280
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_D11 254
//[ICON Struct]
// base_addr  : 0xB21700
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_D12 255
//[ICON Struct]
// base_addr  : 0xB21B80
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_N 256
//[ICON Struct]
// base_addr  : 0xB22000
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_R 257
//[ICON Struct]
// base_addr  : 0xB22480
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_BAI 258
//[ICON Struct]
// base_addr  : 0xB22900
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_HONG 259
//[ICON Struct]
// base_addr  : 0xB22D80
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_R_STOP 260
//[ICON Struct]
// base_addr  : 0xB23200
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_MARK_Y_STOP 261
//[ICON Struct]
// base_addr  : 0xB23680
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 2
// bp         : 4
// count      : 6
#define ID_ICON_DOOR_CLOSE_0 482
//[ICON Struct]
// base_addr  : 0xB23B00
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 3
// bp         : 4
// count      : 9
#define ID_ICON_DOOR_OPEN_0 485
//[ICON Struct]
// base_addr  : 0xB241C0
// font_w     : 16
// font_h     : 24
// width      : 3
// height     : 3
// bp         : 4
// count      : 9
#define ID_ICON_DOOR_CLOSE_1 483
//[ICON Struct]
// base_addr  : 0xB24880
// font_w     : 16
// font_h     : 24
// width      : 4
// height     : 5
// bp         : 4
// count      : 20
#define ID_ICON_DOOR_OPEN_1 486
//[ICON Struct]
// base_addr  : 0xB25780
// font_w     : 16
// font_h     : 24
// width      : 4
// height     : 5
// bp         : 4
// count      : 20
#define ID_ICON_DOOR_CLOSE_2 484
//[ICON Struct]
// base_addr  : 0xB26680
// font_w     : 16
// font_h     : 24
// width      : 4
// height     : 4
// bp         : 4
// count      : 16
#define ID_ICON_DOOR_OPEN_2 487
//[ICON Struct]
// base_addr  : 0xB27280
// font_w     : 16
// font_h     : 24
// width      : 4
// height     : 4
// bp         : 4
// count      : 16
#define ID_ICON_DUMMY_W16_H24_1BP 5451
//[ICON Struct]
// base_addr  : 0xB27E80
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 1
// count      : 1
#define ID_ICON_DUMMY_W16_H24_2BP 5452
//[ICON Struct]
// base_addr  : 0xB27EB0
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 2
// count      : 1
#define ID_ICON_DUMMY_W16_H24_4BP 5453
//[ICON Struct]
// base_addr  : 0xB27F10
// font_w     : 16
// font_h     : 24
// width      : 1
// height     : 1
// bp         : 4
// count      : 1
#define ID_OSD2_1_ORG 5098
//[OREG Struct]
// base_addr  : 0xB27FD0
// length     : 54
#define ID_OSD2_1_MENU 5096
//[MENU Struct]
// base_addr  : 0xB28006
// oram_addr  : 0x3BC5
// length     : 2160
// width      : 50
// height     : 20
#define ID_OSD2_1_LUT 5097
//[LUT Struct]
// lut_addr   : 0xB28876
// main_len   : 180
// sec_len    : 0
// re_2bp_len : 36
// re_bg_len  : 4
#define ID_OSD2_1_TILES 5099
//[Tile Struct]
// base_addr  : 0xB28B6E
// length     : 74
//#define ID_OSD2_1_TILES 5099
//[Tile Struct]
// base_addr  : 0xB28B6E
// length     : 74
#endif
