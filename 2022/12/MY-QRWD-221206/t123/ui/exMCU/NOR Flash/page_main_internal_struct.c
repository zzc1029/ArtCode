#include "sys.h"
#include "tw_ex_sys.h"
#include "res_full.h"
#include "page_main_internal.h"

struct tw_td code main_main_internal = {
  0x178EB0+RES_OFFSET,
  0x235FE8+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};
struct tw_menu code	page_main_internal_osd2_1_menu = {
  0xB28006+RES_OFFSET,
  &page_main_internal_osd2_1_tile,
  &page_main_internal_osd2_1_lut,
  &page_main_internal_osd2_1_org,
  0,
  0,
  0,
  50,
  20,
  15301,
  16,
  24,
};

struct tw_icon code page_main_internal_black = {
  0xA4D120+RES_OFFSET,
  32,
  0,
  0,
  3,
  2,
  1,
};

struct tw_icon code page_main_internal_soc_0 = {
  0xA4D240+RES_OFFSET,
  34,
  0,
  0,
  1,
  1,
  7,
};

struct tw_icon code page_main_internal_soc_1 = {
  0xA4D270+RES_OFFSET,
  35,
  0,
  0,
  1,
  1,
  8,
};

struct tw_icon code page_main_internal_soc_2 = {
  0xA4D2A0+RES_OFFSET,
  36,
  0,
  0,
  1,
  1,
  9,
};

struct tw_icon code page_main_internal_soc_3 = {
  0xA4D2D0+RES_OFFSET,
  37,
  0,
  0,
  1,
  1,
  10,
};

struct tw_icon code page_main_internal_soc_4 = {
  0xA4D300+RES_OFFSET,
  38,
  0,
  0,
  1,
  1,
  11,
};

struct tw_icon code page_main_internal_soc_5 = {
  0xA4D330+RES_OFFSET,
  39,
  0,
  0,
  1,
  1,
  12,
};

struct tw_icon code page_main_internal_soc_6 = {
  0xA4D360+RES_OFFSET,
  40,
  0,
  0,
  1,
  1,
  13,
};

struct tw_icon code page_main_internal_soc_7 = {
  0xA4D390+RES_OFFSET,
  8,
  0,
  0,
  1,
  1,
  14,
};

struct tw_icon code page_main_internal_av = {
  0xA4D3C0+RES_OFFSET,
  0,
  0,
  0,
  2,
  1,
  16,
};

struct tw_icon code page_main_internal_font_close = {
  0xA4D480+RES_OFFSET,
  1,
  0,
  0,
  2,
  1,
  18,
};

struct tw_icon code page_main_internal_font_open = {
  0xA4D540+RES_OFFSET,
  2,
  0,
  0,
  2,
  1,
  20,
};

struct tw_icon code page_main_internal_number_0 = {
  0xA4D600+RES_OFFSET,
  3,
  0,
  0,
  1,
  1,
  22,
};

struct tw_icon code page_main_internal_number_1 = {
  0xA4D660+RES_OFFSET,
  3,
  0,
  0,
  1,
  1,
  23,
};

struct tw_icon code page_main_internal_number_2 = {
  0xA4D6C0+RES_OFFSET,
  3,
  0,
  0,
  1,
  1,
  24,
};

struct tw_icon code page_main_internal_number_3 = {
  0xA4D720+RES_OFFSET,
  3,
  0,
  0,
  1,
  1,
  25,
};

struct tw_icon code page_main_internal_number_4 = {
  0xA4D780+RES_OFFSET,
  3,
  0,
  0,
  1,
  1,
  26,
};

struct tw_icon code page_main_internal_number_5 = {
  0xA4D7E0+RES_OFFSET,
  3,
  0,
  0,
  1,
  1,
  27,
};

struct tw_icon code page_main_internal_number_6 = {
  0xA4D840+RES_OFFSET,
  3,
  0,
  0,
  1,
  1,
  28,
};

struct tw_icon code page_main_internal_number_7 = {
  0xA4D8A0+RES_OFFSET,
  3,
  0,
  0,
  1,
  1,
  29,
};

struct tw_icon code page_main_internal_number_8 = {
  0xA4D900+RES_OFFSET,
  3,
  0,
  0,
  1,
  1,
  30,
};

struct tw_icon code page_main_internal_number_9 = {
  0xA4D960+RES_OFFSET,
  3,
  0,
  0,
  1,
  1,
  31,
};

struct tw_icon code page_main_internal_number_10 = {
  0xA4D9C0+RES_OFFSET,
  4,
  0,
  0,
  1,
  1,
  32,
};

struct tw_icon code page_main_internal_number_a = {
  0xA4DA20+RES_OFFSET,
  3,
  0,
  0,
  1,
  1,
  33,
};

struct tw_icon code page_main_internal_number_point_0 = {
  0xA4DA80+RES_OFFSET,
  4,
  0,
  0,
  1,
  1,
  34,
};

struct tw_icon code page_main_internal_number_point_1 = {
  0xA4DAE0+RES_OFFSET,
  4,
  0,
  0,
  1,
  1,
  35,
};

struct tw_icon code page_main_internal_number_point_2 = {
  0xA4DB40+RES_OFFSET,
  4,
  0,
  0,
  1,
  1,
  36,
};

struct tw_icon code page_main_internal_number_point_3 = {
  0xA4DBA0+RES_OFFSET,
  4,
  0,
  0,
  1,
  1,
  37,
};

struct tw_icon code page_main_internal_number_point_4 = {
  0xA4DC00+RES_OFFSET,
  4,
  0,
  0,
  1,
  1,
  38,
};

struct tw_icon code page_main_internal_number_point_5 = {
  0xA4DC60+RES_OFFSET,
  4,
  0,
  0,
  1,
  1,
  39,
};

struct tw_icon code page_main_internal_number_point_6 = {
  0xA4DCC0+RES_OFFSET,
  4,
  0,
  0,
  1,
  1,
  40,
};

struct tw_icon code page_main_internal_number_point_7 = {
  0xA4DD20+RES_OFFSET,
  4,
  0,
  0,
  1,
  1,
  41,
};

struct tw_icon code page_main_internal_number_point_8 = {
  0xA4DD80+RES_OFFSET,
  4,
  0,
  0,
  1,
  1,
  42,
};

struct tw_icon code page_main_internal_number_point_9 = {
  0xA4DDE0+RES_OFFSET,
  4,
  0,
  0,
  1,
  1,
  43,
};

struct tw_icon code page_main_internal_x = {
  0xA4DE40+RES_OFFSET,
  5,
  0,
  0,
  1,
  1,
  44,
};

unsigned long code page_main_internal_fault_alarm_0_tbl[] = {
  0xA4DEA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_0_tiles = {
  page_main_internal_fault_alarm_0_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_0 = {
  &page_main_internal_fault_alarm_0_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_1_tbl[] = {
  0xA4EF20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_1_tiles = {
  page_main_internal_fault_alarm_1_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_1 = {
  &page_main_internal_fault_alarm_1_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_2_tbl[] = {
  0xA4FFA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_2_tiles = {
  page_main_internal_fault_alarm_2_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_2 = {
  &page_main_internal_fault_alarm_2_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_3_tbl[] = {
  0xA51020+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_3_tiles = {
  page_main_internal_fault_alarm_3_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_3 = {
  &page_main_internal_fault_alarm_3_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_4_tbl[] = {
  0xA520A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_4_tiles = {
  page_main_internal_fault_alarm_4_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_4 = {
  &page_main_internal_fault_alarm_4_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_5_tbl[] = {
  0xA53120+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_5_tiles = {
  page_main_internal_fault_alarm_5_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_5 = {
  &page_main_internal_fault_alarm_5_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_6_tbl[] = {
  0xA541A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_6_tiles = {
  page_main_internal_fault_alarm_6_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_6 = {
  &page_main_internal_fault_alarm_6_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_7_tbl[] = {
  0xA55220+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_7_tiles = {
  page_main_internal_fault_alarm_7_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_7 = {
  &page_main_internal_fault_alarm_7_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_8_tbl[] = {
  0xA562A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_8_tiles = {
  page_main_internal_fault_alarm_8_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_8 = {
  &page_main_internal_fault_alarm_8_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_9_tbl[] = {
  0xA57320+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_9_tiles = {
  page_main_internal_fault_alarm_9_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_9 = {
  &page_main_internal_fault_alarm_9_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_10_tbl[] = {
  0xA583A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_10_tiles = {
  page_main_internal_fault_alarm_10_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_10 = {
  &page_main_internal_fault_alarm_10_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_11_tbl[] = {
  0xA59420+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_11_tiles = {
  page_main_internal_fault_alarm_11_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_11 = {
  &page_main_internal_fault_alarm_11_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_12_tbl[] = {
  0xA5A4A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_12_tiles = {
  page_main_internal_fault_alarm_12_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_12 = {
  &page_main_internal_fault_alarm_12_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_13_tbl[] = {
  0xA5B520+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_13_tiles = {
  page_main_internal_fault_alarm_13_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_13 = {
  &page_main_internal_fault_alarm_13_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_14_tbl[] = {
  0xA5C5A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_14_tiles = {
  page_main_internal_fault_alarm_14_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_14 = {
  &page_main_internal_fault_alarm_14_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_15_tbl[] = {
  0xA5D620+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_15_tiles = {
  page_main_internal_fault_alarm_15_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_15 = {
  &page_main_internal_fault_alarm_15_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_16_tbl[] = {
  0xA5E6A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_16_tiles = {
  page_main_internal_fault_alarm_16_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_16 = {
  &page_main_internal_fault_alarm_16_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_17_tbl[] = {
  0xA5F720+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_17_tiles = {
  page_main_internal_fault_alarm_17_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_17 = {
  &page_main_internal_fault_alarm_17_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_18_tbl[] = {
  0xA607A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_18_tiles = {
  page_main_internal_fault_alarm_18_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_18 = {
  &page_main_internal_fault_alarm_18_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_19_tbl[] = {
  0xA61820+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_19_tiles = {
  page_main_internal_fault_alarm_19_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_19 = {
  &page_main_internal_fault_alarm_19_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_20_tbl[] = {
  0xA628A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_20_tiles = {
  page_main_internal_fault_alarm_20_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_20 = {
  &page_main_internal_fault_alarm_20_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_21_tbl[] = {
  0xA63920+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_21_tiles = {
  page_main_internal_fault_alarm_21_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_21 = {
  &page_main_internal_fault_alarm_21_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_22_tbl[] = {
  0xA649A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_22_tiles = {
  page_main_internal_fault_alarm_22_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_22 = {
  &page_main_internal_fault_alarm_22_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_23_tbl[] = {
  0xA65A20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_23_tiles = {
  page_main_internal_fault_alarm_23_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_23 = {
  &page_main_internal_fault_alarm_23_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_24_tbl[] = {
  0xA66AA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_24_tiles = {
  page_main_internal_fault_alarm_24_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_24 = {
  &page_main_internal_fault_alarm_24_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_25_tbl[] = {
  0xA67B20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_25_tiles = {
  page_main_internal_fault_alarm_25_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_25 = {
  &page_main_internal_fault_alarm_25_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_26_tbl[] = {
  0xA68BA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_26_tiles = {
  page_main_internal_fault_alarm_26_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_26 = {
  &page_main_internal_fault_alarm_26_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_27_tbl[] = {
  0xA69C20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_27_tiles = {
  page_main_internal_fault_alarm_27_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_27 = {
  &page_main_internal_fault_alarm_27_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_28_tbl[] = {
  0xA6ACA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_28_tiles = {
  page_main_internal_fault_alarm_28_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_28 = {
  &page_main_internal_fault_alarm_28_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_29_tbl[] = {
  0xA6BD20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_29_tiles = {
  page_main_internal_fault_alarm_29_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_29 = {
  &page_main_internal_fault_alarm_29_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_30_tbl[] = {
  0xA6CDA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_30_tiles = {
  page_main_internal_fault_alarm_30_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_30 = {
  &page_main_internal_fault_alarm_30_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_31_tbl[] = {
  0xA6DE20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_31_tiles = {
  page_main_internal_fault_alarm_31_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_31 = {
  &page_main_internal_fault_alarm_31_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_32_tbl[] = {
  0xA6EEA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_32_tiles = {
  page_main_internal_fault_alarm_32_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_32 = {
  &page_main_internal_fault_alarm_32_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_33_tbl[] = {
  0xA6FF20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_33_tiles = {
  page_main_internal_fault_alarm_33_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_33 = {
  &page_main_internal_fault_alarm_33_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_34_tbl[] = {
  0xA70FA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_34_tiles = {
  page_main_internal_fault_alarm_34_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_34 = {
  &page_main_internal_fault_alarm_34_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_35_tbl[] = {
  0xA72020+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_35_tiles = {
  page_main_internal_fault_alarm_35_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_35 = {
  &page_main_internal_fault_alarm_35_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_36_tbl[] = {
  0xA730A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_36_tiles = {
  page_main_internal_fault_alarm_36_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_36 = {
  &page_main_internal_fault_alarm_36_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_37_tbl[] = {
  0xA74120+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_37_tiles = {
  page_main_internal_fault_alarm_37_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_37 = {
  &page_main_internal_fault_alarm_37_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_38_tbl[] = {
  0xA751A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_38_tiles = {
  page_main_internal_fault_alarm_38_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_38 = {
  &page_main_internal_fault_alarm_38_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_39_tbl[] = {
  0xA76220+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_39_tiles = {
  page_main_internal_fault_alarm_39_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_39 = {
  &page_main_internal_fault_alarm_39_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_40_tbl[] = {
  0xA772A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_40_tiles = {
  page_main_internal_fault_alarm_40_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_40 = {
  &page_main_internal_fault_alarm_40_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_41_tbl[] = {
  0xA78320+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_41_tiles = {
  page_main_internal_fault_alarm_41_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_41 = {
  &page_main_internal_fault_alarm_41_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_42_tbl[] = {
  0xA793A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_42_tiles = {
  page_main_internal_fault_alarm_42_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_42 = {
  &page_main_internal_fault_alarm_42_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_43_tbl[] = {
  0xA7A420+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_43_tiles = {
  page_main_internal_fault_alarm_43_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_43 = {
  &page_main_internal_fault_alarm_43_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_44_tbl[] = {
  0xA7B4A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_44_tiles = {
  page_main_internal_fault_alarm_44_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_44 = {
  &page_main_internal_fault_alarm_44_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_45_tbl[] = {
  0xA7C520+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_45_tiles = {
  page_main_internal_fault_alarm_45_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_45 = {
  &page_main_internal_fault_alarm_45_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_46_tbl[] = {
  0xA7D5A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_46_tiles = {
  page_main_internal_fault_alarm_46_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_46 = {
  &page_main_internal_fault_alarm_46_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_47_tbl[] = {
  0xA7E620+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_47_tiles = {
  page_main_internal_fault_alarm_47_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_47 = {
  &page_main_internal_fault_alarm_47_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_48_tbl[] = {
  0xA7F6A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_48_tiles = {
  page_main_internal_fault_alarm_48_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_48 = {
  &page_main_internal_fault_alarm_48_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_49_tbl[] = {
  0xA80720+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_49_tiles = {
  page_main_internal_fault_alarm_49_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_49 = {
  &page_main_internal_fault_alarm_49_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_50_tbl[] = {
  0xA817A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_50_tiles = {
  page_main_internal_fault_alarm_50_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_50 = {
  &page_main_internal_fault_alarm_50_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_51_tbl[] = {
  0xA82820+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_51_tiles = {
  page_main_internal_fault_alarm_51_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_51 = {
  &page_main_internal_fault_alarm_51_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_52_tbl[] = {
  0xA838A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_52_tiles = {
  page_main_internal_fault_alarm_52_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_52 = {
  &page_main_internal_fault_alarm_52_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_53_tbl[] = {
  0xA84920+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_53_tiles = {
  page_main_internal_fault_alarm_53_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_53 = {
  &page_main_internal_fault_alarm_53_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_54_tbl[] = {
  0xA859A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_54_tiles = {
  page_main_internal_fault_alarm_54_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_54 = {
  &page_main_internal_fault_alarm_54_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_55_tbl[] = {
  0xA86A20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_55_tiles = {
  page_main_internal_fault_alarm_55_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_55 = {
  &page_main_internal_fault_alarm_55_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_56_tbl[] = {
  0xA87AA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_56_tiles = {
  page_main_internal_fault_alarm_56_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_56 = {
  &page_main_internal_fault_alarm_56_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_57_tbl[] = {
  0xA88B20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_57_tiles = {
  page_main_internal_fault_alarm_57_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_57 = {
  &page_main_internal_fault_alarm_57_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_58_tbl[] = {
  0xA89BA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_58_tiles = {
  page_main_internal_fault_alarm_58_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_58 = {
  &page_main_internal_fault_alarm_58_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_59_tbl[] = {
  0xA8AC20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_59_tiles = {
  page_main_internal_fault_alarm_59_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_59 = {
  &page_main_internal_fault_alarm_59_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_60_tbl[] = {
  0xA8BCA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_60_tiles = {
  page_main_internal_fault_alarm_60_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_60 = {
  &page_main_internal_fault_alarm_60_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_61_tbl[] = {
  0xA8CD20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_61_tiles = {
  page_main_internal_fault_alarm_61_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_61 = {
  &page_main_internal_fault_alarm_61_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_62_tbl[] = {
  0xA8DDA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_62_tiles = {
  page_main_internal_fault_alarm_62_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_62 = {
  &page_main_internal_fault_alarm_62_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_63_tbl[] = {
  0xA8EE20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_63_tiles = {
  page_main_internal_fault_alarm_63_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_63 = {
  &page_main_internal_fault_alarm_63_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_64_tbl[] = {
  0xA8FEA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_64_tiles = {
  page_main_internal_fault_alarm_64_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_64 = {
  &page_main_internal_fault_alarm_64_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_65_tbl[] = {
  0xA90F20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_65_tiles = {
  page_main_internal_fault_alarm_65_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_65 = {
  &page_main_internal_fault_alarm_65_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_66_tbl[] = {
  0xA91FA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_66_tiles = {
  page_main_internal_fault_alarm_66_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_66 = {
  &page_main_internal_fault_alarm_66_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_67_tbl[] = {
  0xA93020+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_67_tiles = {
  page_main_internal_fault_alarm_67_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_67 = {
  &page_main_internal_fault_alarm_67_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_68_tbl[] = {
  0xA940A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_68_tiles = {
  page_main_internal_fault_alarm_68_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_68 = {
  &page_main_internal_fault_alarm_68_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_69_tbl[] = {
  0xA95120+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_69_tiles = {
  page_main_internal_fault_alarm_69_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_69 = {
  &page_main_internal_fault_alarm_69_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_70_tbl[] = {
  0xA961A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_70_tiles = {
  page_main_internal_fault_alarm_70_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_70 = {
  &page_main_internal_fault_alarm_70_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_71_tbl[] = {
  0xA97220+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_71_tiles = {
  page_main_internal_fault_alarm_71_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_71 = {
  &page_main_internal_fault_alarm_71_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_72_tbl[] = {
  0xA982A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_72_tiles = {
  page_main_internal_fault_alarm_72_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_72 = {
  &page_main_internal_fault_alarm_72_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_73_tbl[] = {
  0xA99320+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_73_tiles = {
  page_main_internal_fault_alarm_73_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_73 = {
  &page_main_internal_fault_alarm_73_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_74_tbl[] = {
  0xA9A3A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_74_tiles = {
  page_main_internal_fault_alarm_74_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_74 = {
  &page_main_internal_fault_alarm_74_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_75_tbl[] = {
  0xA9B420+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_75_tiles = {
  page_main_internal_fault_alarm_75_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_75 = {
  &page_main_internal_fault_alarm_75_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_76_tbl[] = {
  0xA9C4A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_76_tiles = {
  page_main_internal_fault_alarm_76_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_76 = {
  &page_main_internal_fault_alarm_76_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_77_tbl[] = {
  0xA9D520+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_77_tiles = {
  page_main_internal_fault_alarm_77_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_77 = {
  &page_main_internal_fault_alarm_77_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_78_tbl[] = {
  0xA9E5A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_78_tiles = {
  page_main_internal_fault_alarm_78_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_78 = {
  &page_main_internal_fault_alarm_78_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_79_tbl[] = {
  0xA9F620+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_79_tiles = {
  page_main_internal_fault_alarm_79_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_79 = {
  &page_main_internal_fault_alarm_79_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_80_tbl[] = {
  0xAA06A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_80_tiles = {
  page_main_internal_fault_alarm_80_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_80 = {
  &page_main_internal_fault_alarm_80_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_81_tbl[] = {
  0xAA1720+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_81_tiles = {
  page_main_internal_fault_alarm_81_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_81 = {
  &page_main_internal_fault_alarm_81_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_82_tbl[] = {
  0xAA27A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_82_tiles = {
  page_main_internal_fault_alarm_82_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_82 = {
  &page_main_internal_fault_alarm_82_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_83_tbl[] = {
  0xAA3820+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_83_tiles = {
  page_main_internal_fault_alarm_83_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_83 = {
  &page_main_internal_fault_alarm_83_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_84_tbl[] = {
  0xAA48A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_84_tiles = {
  page_main_internal_fault_alarm_84_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_84 = {
  &page_main_internal_fault_alarm_84_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_85_tbl[] = {
  0xAA5920+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_85_tiles = {
  page_main_internal_fault_alarm_85_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_85 = {
  &page_main_internal_fault_alarm_85_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_86_tbl[] = {
  0xAA69A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_86_tiles = {
  page_main_internal_fault_alarm_86_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_86 = {
  &page_main_internal_fault_alarm_86_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_87_tbl[] = {
  0xAA7A20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_87_tiles = {
  page_main_internal_fault_alarm_87_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_87 = {
  &page_main_internal_fault_alarm_87_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_88_tbl[] = {
  0xAA8AA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_88_tiles = {
  page_main_internal_fault_alarm_88_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_88 = {
  &page_main_internal_fault_alarm_88_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_89_tbl[] = {
  0xAA9B20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_89_tiles = {
  page_main_internal_fault_alarm_89_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_89 = {
  &page_main_internal_fault_alarm_89_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_90_tbl[] = {
  0xAAABA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_90_tiles = {
  page_main_internal_fault_alarm_90_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_90 = {
  &page_main_internal_fault_alarm_90_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_91_tbl[] = {
  0xAABC20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_91_tiles = {
  page_main_internal_fault_alarm_91_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_91 = {
  &page_main_internal_fault_alarm_91_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_92_tbl[] = {
  0xAACCA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_92_tiles = {
  page_main_internal_fault_alarm_92_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_92 = {
  &page_main_internal_fault_alarm_92_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_93_tbl[] = {
  0xAADD20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_93_tiles = {
  page_main_internal_fault_alarm_93_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_93 = {
  &page_main_internal_fault_alarm_93_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_94_tbl[] = {
  0xAAEDA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_94_tiles = {
  page_main_internal_fault_alarm_94_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_94 = {
  &page_main_internal_fault_alarm_94_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_95_tbl[] = {
  0xAAFE20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_95_tiles = {
  page_main_internal_fault_alarm_95_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_95 = {
  &page_main_internal_fault_alarm_95_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_96_tbl[] = {
  0xAB0EA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_96_tiles = {
  page_main_internal_fault_alarm_96_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_96 = {
  &page_main_internal_fault_alarm_96_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_97_tbl[] = {
  0xAB1F20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_97_tiles = {
  page_main_internal_fault_alarm_97_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_97 = {
  &page_main_internal_fault_alarm_97_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_98_tbl[] = {
  0xAB2FA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_98_tiles = {
  page_main_internal_fault_alarm_98_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_98 = {
  &page_main_internal_fault_alarm_98_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_99_tbl[] = {
  0xAB4020+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_99_tiles = {
  page_main_internal_fault_alarm_99_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_99 = {
  &page_main_internal_fault_alarm_99_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_100_tbl[] = {
  0xAB50A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_100_tiles = {
  page_main_internal_fault_alarm_100_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_100 = {
  &page_main_internal_fault_alarm_100_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_101_tbl[] = {
  0xAB6120+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_101_tiles = {
  page_main_internal_fault_alarm_101_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_101 = {
  &page_main_internal_fault_alarm_101_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_102_tbl[] = {
  0xAB71A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_102_tiles = {
  page_main_internal_fault_alarm_102_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_102 = {
  &page_main_internal_fault_alarm_102_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_103_tbl[] = {
  0xAB8220+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_103_tiles = {
  page_main_internal_fault_alarm_103_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_103 = {
  &page_main_internal_fault_alarm_103_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_104_tbl[] = {
  0xAB92A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_104_tiles = {
  page_main_internal_fault_alarm_104_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_104 = {
  &page_main_internal_fault_alarm_104_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_105_tbl[] = {
  0xABA320+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_105_tiles = {
  page_main_internal_fault_alarm_105_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_105 = {
  &page_main_internal_fault_alarm_105_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_106_tbl[] = {
  0xABB3A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_106_tiles = {
  page_main_internal_fault_alarm_106_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_106 = {
  &page_main_internal_fault_alarm_106_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_107_tbl[] = {
  0xABC420+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_107_tiles = {
  page_main_internal_fault_alarm_107_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_107 = {
  &page_main_internal_fault_alarm_107_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_108_tbl[] = {
  0xABD4A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_108_tiles = {
  page_main_internal_fault_alarm_108_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_108 = {
  &page_main_internal_fault_alarm_108_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_109_tbl[] = {
  0xABE520+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_109_tiles = {
  page_main_internal_fault_alarm_109_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_109 = {
  &page_main_internal_fault_alarm_109_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_110_tbl[] = {
  0xABF5A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_110_tiles = {
  page_main_internal_fault_alarm_110_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_110 = {
  &page_main_internal_fault_alarm_110_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_111_tbl[] = {
  0xAC0620+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_111_tiles = {
  page_main_internal_fault_alarm_111_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_111 = {
  &page_main_internal_fault_alarm_111_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_112_tbl[] = {
  0xAC16A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_112_tiles = {
  page_main_internal_fault_alarm_112_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_112 = {
  &page_main_internal_fault_alarm_112_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_113_tbl[] = {
  0xAC2720+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_113_tiles = {
  page_main_internal_fault_alarm_113_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_113 = {
  &page_main_internal_fault_alarm_113_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_114_tbl[] = {
  0xAC37A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_114_tiles = {
  page_main_internal_fault_alarm_114_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_114 = {
  &page_main_internal_fault_alarm_114_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_115_tbl[] = {
  0xAC4820+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_115_tiles = {
  page_main_internal_fault_alarm_115_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_115 = {
  &page_main_internal_fault_alarm_115_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_116_tbl[] = {
  0xAC58A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_116_tiles = {
  page_main_internal_fault_alarm_116_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_116 = {
  &page_main_internal_fault_alarm_116_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_117_tbl[] = {
  0xAC6920+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_117_tiles = {
  page_main_internal_fault_alarm_117_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_117 = {
  &page_main_internal_fault_alarm_117_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_118_tbl[] = {
  0xAC79A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_118_tiles = {
  page_main_internal_fault_alarm_118_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_118 = {
  &page_main_internal_fault_alarm_118_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_119_tbl[] = {
  0xAC8A20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_119_tiles = {
  page_main_internal_fault_alarm_119_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_119 = {
  &page_main_internal_fault_alarm_119_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_120_tbl[] = {
  0xAC9AA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_120_tiles = {
  page_main_internal_fault_alarm_120_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_120 = {
  &page_main_internal_fault_alarm_120_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_121_tbl[] = {
  0xACAB20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_121_tiles = {
  page_main_internal_fault_alarm_121_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_121 = {
  &page_main_internal_fault_alarm_121_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_122_tbl[] = {
  0xACBBA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_122_tiles = {
  page_main_internal_fault_alarm_122_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_122 = {
  &page_main_internal_fault_alarm_122_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_123_tbl[] = {
  0xACCC20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_123_tiles = {
  page_main_internal_fault_alarm_123_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_123 = {
  &page_main_internal_fault_alarm_123_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_124_tbl[] = {
  0xACDCA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_124_tiles = {
  page_main_internal_fault_alarm_124_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_124 = {
  &page_main_internal_fault_alarm_124_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_125_tbl[] = {
  0xACED20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_125_tiles = {
  page_main_internal_fault_alarm_125_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_125 = {
  &page_main_internal_fault_alarm_125_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_126_tbl[] = {
  0xACFDA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_126_tiles = {
  page_main_internal_fault_alarm_126_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_126 = {
  &page_main_internal_fault_alarm_126_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_127_tbl[] = {
  0xAD0E20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_127_tiles = {
  page_main_internal_fault_alarm_127_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_127 = {
  &page_main_internal_fault_alarm_127_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_128_tbl[] = {
  0xAD1EA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_128_tiles = {
  page_main_internal_fault_alarm_128_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_128 = {
  &page_main_internal_fault_alarm_128_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_129_tbl[] = {
  0xAD2F20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_129_tiles = {
  page_main_internal_fault_alarm_129_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_129 = {
  &page_main_internal_fault_alarm_129_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_130_tbl[] = {
  0xAD3FA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_130_tiles = {
  page_main_internal_fault_alarm_130_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_130 = {
  &page_main_internal_fault_alarm_130_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_131_tbl[] = {
  0xAD5020+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_131_tiles = {
  page_main_internal_fault_alarm_131_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_131 = {
  &page_main_internal_fault_alarm_131_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_132_tbl[] = {
  0xAD60A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_132_tiles = {
  page_main_internal_fault_alarm_132_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_132 = {
  &page_main_internal_fault_alarm_132_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_133_tbl[] = {
  0xAD7120+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_133_tiles = {
  page_main_internal_fault_alarm_133_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_133 = {
  &page_main_internal_fault_alarm_133_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_134_tbl[] = {
  0xAD81A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_134_tiles = {
  page_main_internal_fault_alarm_134_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_134 = {
  &page_main_internal_fault_alarm_134_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_135_tbl[] = {
  0xAD9220+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_135_tiles = {
  page_main_internal_fault_alarm_135_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_135 = {
  &page_main_internal_fault_alarm_135_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_136_tbl[] = {
  0xADA2A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_136_tiles = {
  page_main_internal_fault_alarm_136_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_136 = {
  &page_main_internal_fault_alarm_136_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_137_tbl[] = {
  0xADB320+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_137_tiles = {
  page_main_internal_fault_alarm_137_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_137 = {
  &page_main_internal_fault_alarm_137_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_138_tbl[] = {
  0xADC3A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_138_tiles = {
  page_main_internal_fault_alarm_138_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_138 = {
  &page_main_internal_fault_alarm_138_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_139_tbl[] = {
  0xADD420+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_139_tiles = {
  page_main_internal_fault_alarm_139_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_139 = {
  &page_main_internal_fault_alarm_139_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_140_tbl[] = {
  0xADE4A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_140_tiles = {
  page_main_internal_fault_alarm_140_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_140 = {
  &page_main_internal_fault_alarm_140_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_141_tbl[] = {
  0xADF520+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_141_tiles = {
  page_main_internal_fault_alarm_141_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_141 = {
  &page_main_internal_fault_alarm_141_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_142_tbl[] = {
  0xAE05A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_142_tiles = {
  page_main_internal_fault_alarm_142_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_142 = {
  &page_main_internal_fault_alarm_142_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_143_tbl[] = {
  0xAE1620+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_143_tiles = {
  page_main_internal_fault_alarm_143_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_143 = {
  &page_main_internal_fault_alarm_143_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_144_tbl[] = {
  0xAE26A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_144_tiles = {
  page_main_internal_fault_alarm_144_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_144 = {
  &page_main_internal_fault_alarm_144_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_145_tbl[] = {
  0xAE3720+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_145_tiles = {
  page_main_internal_fault_alarm_145_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_145 = {
  &page_main_internal_fault_alarm_145_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_146_tbl[] = {
  0xAE47A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_146_tiles = {
  page_main_internal_fault_alarm_146_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_146 = {
  &page_main_internal_fault_alarm_146_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_147_tbl[] = {
  0xAE5820+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_147_tiles = {
  page_main_internal_fault_alarm_147_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_147 = {
  &page_main_internal_fault_alarm_147_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_148_tbl[] = {
  0xAE68A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_148_tiles = {
  page_main_internal_fault_alarm_148_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_148 = {
  &page_main_internal_fault_alarm_148_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_149_tbl[] = {
  0xAE7920+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_149_tiles = {
  page_main_internal_fault_alarm_149_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_149 = {
  &page_main_internal_fault_alarm_149_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_150_tbl[] = {
  0xAE89A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_150_tiles = {
  page_main_internal_fault_alarm_150_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_150 = {
  &page_main_internal_fault_alarm_150_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_151_tbl[] = {
  0xAE9A20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_151_tiles = {
  page_main_internal_fault_alarm_151_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_151 = {
  &page_main_internal_fault_alarm_151_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_152_tbl[] = {
  0xAEAAA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_152_tiles = {
  page_main_internal_fault_alarm_152_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_152 = {
  &page_main_internal_fault_alarm_152_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_153_tbl[] = {
  0xAEBB20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_153_tiles = {
  page_main_internal_fault_alarm_153_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_153 = {
  &page_main_internal_fault_alarm_153_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_154_tbl[] = {
  0xAECBA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_154_tiles = {
  page_main_internal_fault_alarm_154_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_154 = {
  &page_main_internal_fault_alarm_154_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_155_tbl[] = {
  0xAEDC20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_155_tiles = {
  page_main_internal_fault_alarm_155_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_155 = {
  &page_main_internal_fault_alarm_155_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_156_tbl[] = {
  0xAEECA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_156_tiles = {
  page_main_internal_fault_alarm_156_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_156 = {
  &page_main_internal_fault_alarm_156_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_157_tbl[] = {
  0xAEFD20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_157_tiles = {
  page_main_internal_fault_alarm_157_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_157 = {
  &page_main_internal_fault_alarm_157_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_158_tbl[] = {
  0xAF0DA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_158_tiles = {
  page_main_internal_fault_alarm_158_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_158 = {
  &page_main_internal_fault_alarm_158_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_159_tbl[] = {
  0xAF1E20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_159_tiles = {
  page_main_internal_fault_alarm_159_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_159 = {
  &page_main_internal_fault_alarm_159_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_160_tbl[] = {
  0xAF2EA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*36,
};

struct tw_tiles code page_main_internal_fault_alarm_160_tiles = {
  page_main_internal_fault_alarm_160_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_160 = {
  &page_main_internal_fault_alarm_160_tiles,
  6,
  0,
  0,
  18,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_161_tbl[] = {
  0xAF3C20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*36,
};

struct tw_tiles code page_main_internal_fault_alarm_161_tiles = {
  page_main_internal_fault_alarm_161_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_161 = {
  &page_main_internal_fault_alarm_161_tiles,
  6,
  0,
  0,
  18,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_162_tbl[] = {
  0xAF49A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*36,
};

struct tw_tiles code page_main_internal_fault_alarm_162_tiles = {
  page_main_internal_fault_alarm_162_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_162 = {
  &page_main_internal_fault_alarm_162_tiles,
  6,
  0,
  0,
  18,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_163_tbl[] = {
  0xAF5720+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*36,
};

struct tw_tiles code page_main_internal_fault_alarm_163_tiles = {
  page_main_internal_fault_alarm_163_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_163 = {
  &page_main_internal_fault_alarm_163_tiles,
  6,
  0,
  0,
  18,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_164_tbl[] = {
  0xAF64A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*36,
};

struct tw_tiles code page_main_internal_fault_alarm_164_tiles = {
  page_main_internal_fault_alarm_164_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_164 = {
  &page_main_internal_fault_alarm_164_tiles,
  6,
  0,
  0,
  18,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_165_tbl[] = {
  0xAF7220+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*36,
};

struct tw_tiles code page_main_internal_fault_alarm_165_tiles = {
  page_main_internal_fault_alarm_165_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_165 = {
  &page_main_internal_fault_alarm_165_tiles,
  6,
  0,
  0,
  18,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_166_tbl[] = {
  0xAF7FA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*36,
};

struct tw_tiles code page_main_internal_fault_alarm_166_tiles = {
  page_main_internal_fault_alarm_166_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_166 = {
  &page_main_internal_fault_alarm_166_tiles,
  6,
  0,
  0,
  18,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_167_tbl[] = {
  0xAF8D20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*36,
};

struct tw_tiles code page_main_internal_fault_alarm_167_tiles = {
  page_main_internal_fault_alarm_167_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_167 = {
  &page_main_internal_fault_alarm_167_tiles,
  6,
  0,
  0,
  18,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_168_tbl[] = {
  0xAF9AA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*36,
};

struct tw_tiles code page_main_internal_fault_alarm_168_tiles = {
  page_main_internal_fault_alarm_168_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_168 = {
  &page_main_internal_fault_alarm_168_tiles,
  6,
  0,
  0,
  18,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_169_tbl[] = {
  0xAFA820+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*40,
};

struct tw_tiles code page_main_internal_fault_alarm_169_tiles = {
  page_main_internal_fault_alarm_169_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_169 = {
  &page_main_internal_fault_alarm_169_tiles,
  6,
  0,
  0,
  20,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_170_tbl[] = {
  0xAFB720+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_170_tiles = {
  page_main_internal_fault_alarm_170_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_170 = {
  &page_main_internal_fault_alarm_170_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_171_tbl[] = {
  0xAFC7A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_171_tiles = {
  page_main_internal_fault_alarm_171_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_171 = {
  &page_main_internal_fault_alarm_171_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_172_tbl[] = {
  0xAFD820+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_172_tiles = {
  page_main_internal_fault_alarm_172_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_172 = {
  &page_main_internal_fault_alarm_172_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_173_tbl[] = {
  0xAFE8A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_173_tiles = {
  page_main_internal_fault_alarm_173_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_173 = {
  &page_main_internal_fault_alarm_173_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_174_tbl[] = {
  0xAFF920+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_174_tiles = {
  page_main_internal_fault_alarm_174_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_174 = {
  &page_main_internal_fault_alarm_174_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_175_tbl[] = {
  0xB009A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_175_tiles = {
  page_main_internal_fault_alarm_175_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_175 = {
  &page_main_internal_fault_alarm_175_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_176_tbl[] = {
  0xB01A20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_176_tiles = {
  page_main_internal_fault_alarm_176_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_176 = {
  &page_main_internal_fault_alarm_176_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_177_tbl[] = {
  0xB02AA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_177_tiles = {
  page_main_internal_fault_alarm_177_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_177 = {
  &page_main_internal_fault_alarm_177_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_178_tbl[] = {
  0xB03B20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*28,
};

struct tw_tiles code page_main_internal_fault_alarm_178_tiles = {
  page_main_internal_fault_alarm_178_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_178 = {
  &page_main_internal_fault_alarm_178_tiles,
  6,
  0,
  0,
  14,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_179_tbl[] = {
  0xB045A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*32,
};

struct tw_tiles code page_main_internal_fault_alarm_179_tiles = {
  page_main_internal_fault_alarm_179_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_179 = {
  &page_main_internal_fault_alarm_179_tiles,
  6,
  0,
  0,
  16,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_180_tbl[] = {
  0xB051A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*28,
};

struct tw_tiles code page_main_internal_fault_alarm_180_tiles = {
  page_main_internal_fault_alarm_180_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_180 = {
  &page_main_internal_fault_alarm_180_tiles,
  6,
  0,
  0,
  14,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_181_tbl[] = {
  0xB05C20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*28,
};

struct tw_tiles code page_main_internal_fault_alarm_181_tiles = {
  page_main_internal_fault_alarm_181_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_181 = {
  &page_main_internal_fault_alarm_181_tiles,
  6,
  0,
  0,
  14,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_182_tbl[] = {
  0xB066A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*28,
};

struct tw_tiles code page_main_internal_fault_alarm_182_tiles = {
  page_main_internal_fault_alarm_182_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_182 = {
  &page_main_internal_fault_alarm_182_tiles,
  6,
  0,
  0,
  14,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_183_tbl[] = {
  0xB07120+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*28,
};

struct tw_tiles code page_main_internal_fault_alarm_183_tiles = {
  page_main_internal_fault_alarm_183_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_183 = {
  &page_main_internal_fault_alarm_183_tiles,
  6,
  0,
  0,
  14,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_184_tbl[] = {
  0xB07BA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*44,
};

struct tw_tiles code page_main_internal_fault_alarm_184_tiles = {
  page_main_internal_fault_alarm_184_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_184 = {
  &page_main_internal_fault_alarm_184_tiles,
  6,
  0,
  0,
  22,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_off_tbl[] = {
  0xB08C20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_off_tiles = {
  page_main_internal_off_tbl,
  1,
};

struct tw_gicon code page_main_internal_off = {
  &page_main_internal_off_tiles,
  7,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_on_tbl[] = {
  0xB08D40+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_on_tiles = {
  page_main_internal_on_tbl,
  1,
};

struct tw_gicon code page_main_internal_on = {
  &page_main_internal_on_tiles,
  7,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_yuunxing_tbl[] = {
  0xB08E60+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_yuunxing_tiles = {
  page_main_internal_yuunxing_tbl,
  1,
};

struct tw_gicon code page_main_internal_yuunxing = {
  &page_main_internal_yuunxing_tiles,
  4,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_d_tbl[] = {
  0xB08F80+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_d_tiles = {
  page_main_internal_s1_d_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_d = {
  &page_main_internal_s1_d_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_d1_tbl[] = {
  0xB090A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_d1_tiles = {
  page_main_internal_s1_d1_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_d1 = {
  &page_main_internal_s1_d1_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_d2_tbl[] = {
  0xB091C0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_d2_tiles = {
  page_main_internal_s1_d2_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_d2 = {
  &page_main_internal_s1_d2_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_d3_tbl[] = {
  0xB092E0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_d3_tiles = {
  page_main_internal_s1_d3_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_d3 = {
  &page_main_internal_s1_d3_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_d4_tbl[] = {
  0xB09400+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_d4_tiles = {
  page_main_internal_s1_d4_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_d4 = {
  &page_main_internal_s1_d4_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_d5_tbl[] = {
  0xB09520+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_d5_tiles = {
  page_main_internal_s1_d5_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_d5 = {
  &page_main_internal_s1_d5_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_d6_tbl[] = {
  0xB09640+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_d6_tiles = {
  page_main_internal_s1_d6_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_d6 = {
  &page_main_internal_s1_d6_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_d7_tbl[] = {
  0xB09760+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_d7_tiles = {
  page_main_internal_s1_d7_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_d7 = {
  &page_main_internal_s1_d7_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_d8_tbl[] = {
  0xB09880+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_d8_tiles = {
  page_main_internal_s1_d8_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_d8 = {
  &page_main_internal_s1_d8_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_d9_tbl[] = {
  0xB099A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_d9_tiles = {
  page_main_internal_s1_d9_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_d9 = {
  &page_main_internal_s1_d9_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_d10_tbl[] = {
  0xB09AC0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_d10_tiles = {
  page_main_internal_s1_d10_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_d10 = {
  &page_main_internal_s1_d10_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_d11_tbl[] = {
  0xB09BE0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_d11_tiles = {
  page_main_internal_s1_d11_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_d11 = {
  &page_main_internal_s1_d11_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_d12_tbl[] = {
  0xB09D00+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_d12_tiles = {
  page_main_internal_s1_d12_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_d12 = {
  &page_main_internal_s1_d12_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_n_tbl[] = {
  0xB09E20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_n_tiles = {
  page_main_internal_s1_n_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_n = {
  &page_main_internal_s1_n_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_p_tbl[] = {
  0xB09F40+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_p_tiles = {
  page_main_internal_s1_p_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_p = {
  &page_main_internal_s1_p_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s1_r_tbl[] = {
  0xB0A060+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_r_tiles = {
  page_main_internal_s1_r_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_r = {
  &page_main_internal_s1_r_tiles,
  8,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

unsigned long code page_main_internal_s16_tingji_tbl[] = {
  0xB0A180+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s16_tingji_tiles = {
  page_main_internal_s16_tingji_tbl,
  1,
};

struct tw_gicon code page_main_internal_s16_tingji = {
  &page_main_internal_s16_tingji_tiles,
  4,
  0,
  0,
  3,
  1,
  89,
  0X0f30,
};

struct tw_icon code page_main_internal_wuxiao = {
  0xB0A2A0+RES_OFFSET,
  8,
  0,
  0,
  3,
  1,
  92,
};

struct tw_icon code page_main_internal_youxiao = {
  0xB0A3C0+RES_OFFSET,
  8,
  0,
  0,
  3,
  1,
  95,
};

unsigned long code page_main_internal_gz_tbl[] = {
  0xB0A4E0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_gz_tiles = {
  page_main_internal_gz_tbl,
  1,
};

struct tw_gicon code page_main_internal_gz = {
  &page_main_internal_gz_tiles,
  4,
  0,
  0,
  3,
  1,
  98,
  0X10e0,
};

unsigned long code page_main_internal_tingji_tbl[] = {
  0xB0A600+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_tingji_tiles = {
  page_main_internal_tingji_tbl,
  1,
};

struct tw_gicon code page_main_internal_tingji = {
  &page_main_internal_tingji_tiles,
  4,
  0,
  0,
  3,
  1,
  98,
  0X10e0,
};

unsigned long code page_main_internal_weitingji_tbl[] = {
  0xB0A720+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*4,
};

struct tw_tiles code page_main_internal_weitingji_tiles = {
  page_main_internal_weitingji_tbl,
  1,
};

struct tw_gicon code page_main_internal_weitingji = {
  &page_main_internal_weitingji_tiles,
  8,
  0,
  0,
  4,
  1,
  98,
  0X10e0,
};

unsigned long code page_main_internal_yitingji_tbl[] = {
  0xB0A8A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*4,
};

struct tw_tiles code page_main_internal_yitingji_tiles = {
  page_main_internal_yitingji_tbl,
  1,
};

struct tw_gicon code page_main_internal_yitingji = {
  &page_main_internal_yitingji_tiles,
  8,
  0,
  0,
  4,
  1,
  98,
  0X10e0,
};

unsigned long code page_main_internal_s1_chadian_tbl[] = {
  0xB0AA20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_chadian_tiles = {
  page_main_internal_s1_chadian_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_chadian = {
  &page_main_internal_s1_chadian_tiles,
  8,
  0,
  0,
  3,
  1,
  98,
  0X10e0,
};

unsigned long code page_main_internal_s1_chundian_tbl[] = {
  0xB0AB40+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_chundian_tiles = {
  page_main_internal_s1_chundian_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_chundian = {
  &page_main_internal_s1_chundian_tiles,
  8,
  0,
  0,
  3,
  1,
  98,
  0X10e0,
};

unsigned long code page_main_internal_s1_hundong_tbl[] = {
  0xB0AC60+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_hundong_tiles = {
  page_main_internal_s1_hundong_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_hundong = {
  &page_main_internal_s1_hundong_tiles,
  8,
  0,
  0,
  3,
  1,
  98,
  0X10e0,
};

unsigned long code page_main_internal_diya_tbl[] = {
  0xB0AD80+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_diya_tiles = {
  page_main_internal_diya_tbl,
  1,
};

struct tw_gicon code page_main_internal_diya = {
  &page_main_internal_diya_tiles,
  8,
  0,
  0,
  3,
  1,
  102,
  0X11a0,
};

unsigned long code page_main_internal_gaoya_tbl[] = {
  0xB0AEA0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_gaoya_tiles = {
  page_main_internal_gaoya_tbl,
  1,
};

struct tw_gicon code page_main_internal_gaoya = {
  &page_main_internal_gaoya_tiles,
  8,
  0,
  0,
  3,
  1,
  102,
  0X11a0,
};

unsigned long code page_main_internal_s1_kuaichong_tbl[] = {
  0xB0AFC0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_kuaichong_tiles = {
  page_main_internal_s1_kuaichong_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_kuaichong = {
  &page_main_internal_s1_kuaichong_tiles,
  8,
  0,
  0,
  3,
  1,
  102,
  0X11a0,
};

unsigned long code page_main_internal_s1_manchong_tbl[] = {
  0xB0B0E0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_manchong_tiles = {
  page_main_internal_s1_manchong_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_manchong = {
  &page_main_internal_s1_manchong_tiles,
  8,
  0,
  0,
  3,
  1,
  102,
  0X11a0,
};

unsigned long code page_main_internal_s1_zijian_tbl[] = {
  0xB0B200+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s1_zijian_tiles = {
  page_main_internal_s1_zijian_tbl,
  1,
};

struct tw_gicon code page_main_internal_s1_zijian = {
  &page_main_internal_s1_zijian_tiles,
  8,
  0,
  0,
  3,
  1,
  102,
  0X11a0,
};

unsigned long code page_main_internal_erjigz_tbl[] = {
  0xB0B320+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*6,
};

struct tw_tiles code page_main_internal_erjigz_tiles = {
  page_main_internal_erjigz_tbl,
  1,
};

struct tw_gicon code page_main_internal_erjigz = {
  &page_main_internal_erjigz_tiles,
  4,
  0,
  0,
  6,
  1,
  105,
  0X1230,
};

unsigned long code page_main_internal_sanjigz_tbl[] = {
  0xB0B560+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*6,
};

struct tw_tiles code page_main_internal_sanjigz_tiles = {
  page_main_internal_sanjigz_tbl,
  1,
};

struct tw_gicon code page_main_internal_sanjigz = {
  &page_main_internal_sanjigz_tiles,
  4,
  0,
  0,
  6,
  1,
  105,
  0X1230,
};

unsigned long code page_main_internal_yijigz_tbl[] = {
  0xB0B7A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*6,
};

struct tw_tiles code page_main_internal_yijigz_tiles = {
  page_main_internal_yijigz_tbl,
  1,
};

struct tw_gicon code page_main_internal_yijigz = {
  &page_main_internal_yijigz_tiles,
  4,
  0,
  0,
  6,
  1,
  105,
  0X1230,
};

unsigned long code page_main_internal_s20_g1_can_tbl[] = {
  0xB0B9E0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*9,
};

struct tw_tiles code page_main_internal_s20_g1_can_tiles = {
  page_main_internal_s20_g1_can_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g1_can = {
  &page_main_internal_s20_g1_can_tiles,
  3,
  0,
  0,
  9,
  1,
  105,
  0X1230,
};

unsigned long code page_main_internal_s20_g1_chuanganqi_tbl[] = {
  0xB0BD40+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*9,
};

struct tw_tiles code page_main_internal_s20_g1_chuanganqi_tiles = {
  page_main_internal_s20_g1_chuanganqi_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g1_chuanganqi = {
  &page_main_internal_s20_g1_chuanganqi_tiles,
  3,
  0,
  0,
  9,
  1,
  105,
  0X1230,
};

unsigned long code page_main_internal_s20_g1_ebs_tbl[] = {
  0xB0C0A0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*9,
};

struct tw_tiles code page_main_internal_s20_g1_ebs_tiles = {
  page_main_internal_s20_g1_ebs_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g1_ebs = {
  &page_main_internal_s20_g1_ebs_tiles,
  3,
  0,
  0,
  9,
  1,
  105,
  0X1230,
};

unsigned long code page_main_internal_s20_g1_fadian_tbl[] = {
  0xB0C400+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*9,
};

struct tw_tiles code page_main_internal_s20_g1_fadian_tiles = {
  page_main_internal_s20_g1_fadian_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g1_fadian = {
  &page_main_internal_s20_g1_fadian_tiles,
  3,
  0,
  0,
  9,
  1,
  105,
  0X1230,
};

unsigned long code page_main_internal_s20_g1_jinqi_tbl[] = {
  0xB0C760+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*9,
};

struct tw_tiles code page_main_internal_s20_g1_jinqi_tiles = {
  page_main_internal_s20_g1_jinqi_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g1_jinqi = {
  &page_main_internal_s20_g1_jinqi_tiles,
  3,
  0,
  0,
  9,
  1,
  105,
  0X1230,
};

unsigned long code page_main_internal_s20_g1_kaiguan_tbl[] = {
  0xB0CAC0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*9,
};

struct tw_tiles code page_main_internal_s20_g1_kaiguan_tiles = {
  page_main_internal_s20_g1_kaiguan_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g1_kaiguan = {
  &page_main_internal_s20_g1_kaiguan_tiles,
  3,
  0,
  0,
  9,
  1,
  105,
  0X1230,
};

unsigned long code page_main_internal_s20_g1_mokuai_tbl[] = {
  0xB0CE20+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*9,
};

struct tw_tiles code page_main_internal_s20_g1_mokuai_tiles = {
  page_main_internal_s20_g1_mokuai_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g1_mokuai = {
  &page_main_internal_s20_g1_mokuai_tiles,
  3,
  0,
  0,
  9,
  1,
  105,
  0X1230,
};

unsigned long code page_main_internal_s20_g1_paiqi_tbl[] = {
  0xB0D180+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*9,
};

struct tw_tiles code page_main_internal_s20_g1_paiqi_tiles = {
  page_main_internal_s20_g1_paiqi_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g1_paiqi = {
  &page_main_internal_s20_g1_paiqi_tiles,
  3,
  0,
  0,
  9,
  1,
  105,
  0X1230,
};

unsigned long code page_main_internal_s20_g1_zhidong_tbl[] = {
  0xB0D4E0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*9,
};

struct tw_tiles code page_main_internal_s20_g1_zhidong_tiles = {
  page_main_internal_s20_g1_zhidong_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g1_zhidong = {
  &page_main_internal_s20_g1_zhidong_tiles,
  3,
  0,
  0,
  9,
  1,
  105,
  0X1230,
};

unsigned long code page_main_internal_s3_daiji_tbl[] = {
  0xB0D840+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s3_daiji_tiles = {
  page_main_internal_s3_daiji_tbl,
  1,
};

struct tw_gicon code page_main_internal_s3_daiji = {
  &page_main_internal_s3_daiji_tiles,
  4,
  0,
  0,
  3,
  1,
  114,
  0X13e0,
};

unsigned long code page_main_internal_s3_yunxing_tbl[] = {
  0xB0D960+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_s3_yunxing_tiles = {
  page_main_internal_s3_yunxing_tbl,
  1,
};

struct tw_gicon code page_main_internal_s3_yunxing = {
  &page_main_internal_s3_yunxing_tiles,
  4,
  0,
  0,
  3,
  1,
  114,
  0X13e0,
};

unsigned long code page_main_internal_s20_g2_canduanlu_tbl[] = {
  0xB0DA80+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*8,
};

struct tw_tiles code page_main_internal_s20_g2_canduanlu_tiles = {
  page_main_internal_s20_g2_canduanlu_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g2_canduanlu = {
  &page_main_internal_s20_g2_canduanlu_tiles,
  3,
  0,
  0,
  8,
  1,
  114,
  0X13e0,
};

unsigned long code page_main_internal_s20_g2_chuanganqi_tbl[] = {
  0xB0DD80+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*8,
};

struct tw_tiles code page_main_internal_s20_g2_chuanganqi_tiles = {
  page_main_internal_s20_g2_chuanganqi_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g2_chuanganqi = {
  &page_main_internal_s20_g2_chuanganqi_tiles,
  3,
  0,
  0,
  8,
  1,
  114,
  0X13e0,
};

unsigned long code page_main_internal_s20_g2_di_tbl[] = {
  0xB0E080+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*8,
};

struct tw_tiles code page_main_internal_s20_g2_di_tiles = {
  page_main_internal_s20_g2_di_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g2_di = {
  &page_main_internal_s20_g2_di_tiles,
  3,
  0,
  0,
  8,
  1,
  114,
  0X13e0,
};

unsigned long code page_main_internal_s20_g2_dianyadi_tbl[] = {
  0xB0E380+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*8,
};

struct tw_tiles code page_main_internal_s20_g2_dianyadi_tiles = {
  page_main_internal_s20_g2_dianyadi_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g2_dianyadi = {
  &page_main_internal_s20_g2_dianyadi_tiles,
  3,
  0,
  0,
  8,
  1,
  114,
  0X13e0,
};

unsigned long code page_main_internal_s20_g2_dianyagao_tbl[] = {
  0xB0E680+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*8,
};

struct tw_tiles code page_main_internal_s20_g2_dianyagao_tiles = {
  page_main_internal_s20_g2_dianyagao_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g2_dianyagao = {
  &page_main_internal_s20_g2_dianyagao_tiles,
  3,
  0,
  0,
  8,
  1,
  114,
  0X13e0,
};

unsigned long code page_main_internal_s20_g2_dianyuan_tbl[] = {
  0xB0E980+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*8,
};

struct tw_tiles code page_main_internal_s20_g2_dianyuan_tiles = {
  page_main_internal_s20_g2_dianyuan_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g2_dianyuan = {
  &page_main_internal_s20_g2_dianyuan_tiles,
  3,
  0,
  0,
  8,
  1,
  114,
  0X13e0,
};

unsigned long code page_main_internal_s20_g2_diushi_tbl[] = {
  0xB0EC80+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*8,
};

struct tw_tiles code page_main_internal_s20_g2_diushi_tiles = {
  page_main_internal_s20_g2_diushi_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g2_diushi = {
  &page_main_internal_s20_g2_diushi_tiles,
  3,
  0,
  0,
  8,
  1,
  114,
  0X13e0,
};

unsigned long code page_main_internal_s20_g2_duanlu_tbl[] = {
  0xB0EF80+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*8,
};

struct tw_tiles code page_main_internal_s20_g2_duanlu_tiles = {
  page_main_internal_s20_g2_duanlu_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g2_duanlu = {
  &page_main_internal_s20_g2_duanlu_tiles,
  3,
  0,
  0,
  8,
  1,
  114,
  0X13e0,
};

unsigned long code page_main_internal_s20_g2_ebs_tbl[] = {
  0xB0F280+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*8,
};

struct tw_tiles code page_main_internal_s20_g2_ebs_tiles = {
  page_main_internal_s20_g2_ebs_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g2_ebs = {
  &page_main_internal_s20_g2_ebs_tiles,
  3,
  0,
  0,
  8,
  1,
  114,
  0X13e0,
};

unsigned long code page_main_internal_s20_g2_fati_tbl[] = {
  0xB0F580+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*8,
};

struct tw_tiles code page_main_internal_s20_g2_fati_tiles = {
  page_main_internal_s20_g2_fati_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g2_fati = {
  &page_main_internal_s20_g2_fati_tiles,
  3,
  0,
  0,
  8,
  1,
  114,
  0X13e0,
};

unsigned long code page_main_internal_s20_g2_kaiguan_tbl[] = {
  0xB0F880+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*8,
};

struct tw_tiles code page_main_internal_s20_g2_kaiguan_tiles = {
  page_main_internal_s20_g2_kaiguan_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g2_kaiguan = {
  &page_main_internal_s20_g2_kaiguan_tiles,
  3,
  0,
  0,
  8,
  1,
  114,
  0X13e0,
};

unsigned long code page_main_internal_s20_g2_three_tbl[] = {
  0xB0FB80+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*8,
};

struct tw_tiles code page_main_internal_s20_g2_three_tiles = {
  page_main_internal_s20_g2_three_tbl,
  1,
};

struct tw_gicon code page_main_internal_s20_g2_three = {
  &page_main_internal_s20_g2_three_tiles,
  3,
  0,
  0,
  8,
  1,
  114,
  0X13e0,
};

struct tw_icon code page_main_internal_guzhang = {
  0xB0FE80+RES_OFFSET,
  4,
  0,
  0,
  3,
  1,
  122,
};

struct tw_icon code page_main_internal_zhengchang = {
  0xB0FFA0+RES_OFFSET,
  4,
  0,
  0,
  3,
  1,
  125,
};

struct tw_icon code page_main_internal_guanbi = {
  0xB100C0+RES_OFFSET,
  8,
  0,
  0,
  3,
  1,
  128,
};

struct tw_icon code page_main_internal_qidong = {
  0xB101E0+RES_OFFSET,
  8,
  0,
  0,
  3,
  1,
  131,
};

struct tw_icon code page_main_internal_fault_number_0 = {
  0xB10300+RES_OFFSET,
  8,
  0,
  0,
  1,
  2,
  134,
};

struct tw_icon code page_main_internal_fault_number_1 = {
  0xB103C0+RES_OFFSET,
  8,
  0,
  0,
  1,
  2,
  136,
};

struct tw_icon code page_main_internal_fault_number_2 = {
  0xB10480+RES_OFFSET,
  8,
  0,
  0,
  1,
  2,
  138,
};

struct tw_icon code page_main_internal_fault_number_3 = {
  0xB10540+RES_OFFSET,
  8,
  0,
  0,
  1,
  2,
  140,
};

struct tw_icon code page_main_internal_fault_number_4 = {
  0xB10600+RES_OFFSET,
  8,
  0,
  0,
  1,
  2,
  142,
};

struct tw_icon code page_main_internal_fault_number_5 = {
  0xB106C0+RES_OFFSET,
  8,
  0,
  0,
  1,
  2,
  144,
};

struct tw_icon code page_main_internal_fault_number_6 = {
  0xB10780+RES_OFFSET,
  8,
  0,
  0,
  1,
  2,
  146,
};

struct tw_icon code page_main_internal_fault_number_7 = {
  0xB10840+RES_OFFSET,
  8,
  0,
  0,
  1,
  2,
  148,
};

struct tw_icon code page_main_internal_fault_number_8 = {
  0xB10900+RES_OFFSET,
  8,
  0,
  0,
  1,
  2,
  150,
};

struct tw_icon code page_main_internal_fault_number_9 = {
  0xB109C0+RES_OFFSET,
  8,
  0,
  0,
  1,
  2,
  152,
};

struct tw_icon code page_main_internal_s9_ready = {
  0xB10A80+RES_OFFSET,
  3,
  0,
  0,
  4,
  1,
  154,
};

unsigned long code page_main_internal_alarm_pos_0_tbl[] = {
  0xB10C00+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*8,
};

struct tw_tiles code page_main_internal_alarm_pos_0_tiles = {
  page_main_internal_alarm_pos_0_tbl,
  1,
};

struct tw_gicon code page_main_internal_alarm_pos_0 = {
  &page_main_internal_alarm_pos_0_tiles,
  8,
  0,
  0,
  4,
  2,
  158,
  0X1c20,
};

unsigned long code page_main_internal_alarm_pos_1_tbl[] = {
  0xB10F00+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*8,
};

struct tw_tiles code page_main_internal_alarm_pos_1_tiles = {
  page_main_internal_alarm_pos_1_tbl,
  1,
};

struct tw_gicon code page_main_internal_alarm_pos_1 = {
  &page_main_internal_alarm_pos_1_tiles,
  8,
  0,
  0,
  4,
  2,
  158,
  0X1c20,
};

unsigned long code page_main_internal_alarm_pos_2_tbl[] = {
  0xB11200+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*12,
};

struct tw_tiles code page_main_internal_alarm_pos_2_tiles = {
  page_main_internal_alarm_pos_2_tbl,
  1,
};

struct tw_gicon code page_main_internal_alarm_pos_2 = {
  &page_main_internal_alarm_pos_2_tiles,
  8,
  0,
  0,
  6,
  2,
  158,
  0X1c20,
};

unsigned long code page_main_internal_alarm_pos_3_tbl[] = {
  0xB11680+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*12,
};

struct tw_tiles code page_main_internal_alarm_pos_3_tiles = {
  page_main_internal_alarm_pos_3_tbl,
  1,
};

struct tw_gicon code page_main_internal_alarm_pos_3 = {
  &page_main_internal_alarm_pos_3_tiles,
  8,
  0,
  0,
  6,
  2,
  158,
  0X1c20,
};

unsigned long code page_main_internal_alarm_pos_4_tbl[] = {
  0xB11B00+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*12,
};

struct tw_tiles code page_main_internal_alarm_pos_4_tiles = {
  page_main_internal_alarm_pos_4_tbl,
  1,
};

struct tw_gicon code page_main_internal_alarm_pos_4 = {
  &page_main_internal_alarm_pos_4_tiles,
  8,
  0,
  0,
  6,
  2,
  158,
  0X1c20,
};

unsigned long code page_main_internal_alarm_pos_5_tbl[] = {
  0xB11F80+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*12,
};

struct tw_tiles code page_main_internal_alarm_pos_5_tiles = {
  page_main_internal_alarm_pos_5_tbl,
  1,
};

struct tw_gicon code page_main_internal_alarm_pos_5 = {
  &page_main_internal_alarm_pos_5_tiles,
  8,
  0,
  0,
  6,
  2,
  158,
  0X1c20,
};

unsigned long code page_main_internal_fault_alarm_185_tbl[] = {
  0xB12400+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*38,
};

struct tw_tiles code page_main_internal_fault_alarm_185_tiles = {
  page_main_internal_fault_alarm_185_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_185 = {
  &page_main_internal_fault_alarm_185_tiles,
  8,
  0,
  0,
  19,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_186_tbl[] = {
  0xB13240+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*38,
};

struct tw_tiles code page_main_internal_fault_alarm_186_tiles = {
  page_main_internal_fault_alarm_186_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_186 = {
  &page_main_internal_fault_alarm_186_tiles,
  8,
  0,
  0,
  19,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_187_tbl[] = {
  0xB14080+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*38,
};

struct tw_tiles code page_main_internal_fault_alarm_187_tiles = {
  page_main_internal_fault_alarm_187_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_187 = {
  &page_main_internal_fault_alarm_187_tiles,
  8,
  0,
  0,
  19,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_188_tbl[] = {
  0xB14EC0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*38,
};

struct tw_tiles code page_main_internal_fault_alarm_188_tiles = {
  page_main_internal_fault_alarm_188_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_188 = {
  &page_main_internal_fault_alarm_188_tiles,
  8,
  0,
  0,
  19,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_189_tbl[] = {
  0xB15D00+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*38,
};

struct tw_tiles code page_main_internal_fault_alarm_189_tiles = {
  page_main_internal_fault_alarm_189_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_189 = {
  &page_main_internal_fault_alarm_189_tiles,
  8,
  0,
  0,
  19,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_190_tbl[] = {
  0xB16B40+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*38,
};

struct tw_tiles code page_main_internal_fault_alarm_190_tiles = {
  page_main_internal_fault_alarm_190_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_190 = {
  &page_main_internal_fault_alarm_190_tiles,
  8,
  0,
  0,
  19,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_191_tbl[] = {
  0xB17980+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*38,
};

struct tw_tiles code page_main_internal_fault_alarm_191_tiles = {
  page_main_internal_fault_alarm_191_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_191 = {
  &page_main_internal_fault_alarm_191_tiles,
  8,
  0,
  0,
  19,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_192_tbl[] = {
  0xB187C0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*38,
};

struct tw_tiles code page_main_internal_fault_alarm_192_tiles = {
  page_main_internal_fault_alarm_192_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_192 = {
  &page_main_internal_fault_alarm_192_tiles,
  8,
  0,
  0,
  19,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_193_tbl[] = {
  0xB19600+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*38,
};

struct tw_tiles code page_main_internal_fault_alarm_193_tiles = {
  page_main_internal_fault_alarm_193_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_193 = {
  &page_main_internal_fault_alarm_193_tiles,
  8,
  0,
  0,
  19,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_194_tbl[] = {
  0xB1A440+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*40,
};

struct tw_tiles code page_main_internal_fault_alarm_194_tiles = {
  page_main_internal_fault_alarm_194_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_194 = {
  &page_main_internal_fault_alarm_194_tiles,
  8,
  0,
  0,
  20,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_195_tbl[] = {
  0xB1B340+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*20,
};

struct tw_tiles code page_main_internal_fault_alarm_195_tiles = {
  page_main_internal_fault_alarm_195_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_195 = {
  &page_main_internal_fault_alarm_195_tiles,
  8,
  0,
  0,
  10,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_196_tbl[] = {
  0xB1BAC0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*20,
};

struct tw_tiles code page_main_internal_fault_alarm_196_tiles = {
  page_main_internal_fault_alarm_196_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_196 = {
  &page_main_internal_fault_alarm_196_tiles,
  8,
  0,
  0,
  10,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_197_tbl[] = {
  0xB1C240+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*20,
};

struct tw_tiles code page_main_internal_fault_alarm_197_tiles = {
  page_main_internal_fault_alarm_197_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_197 = {
  &page_main_internal_fault_alarm_197_tiles,
  8,
  0,
  0,
  10,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_198_tbl[] = {
  0xB1C9C0+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*28,
};

struct tw_tiles code page_main_internal_fault_alarm_198_tiles = {
  page_main_internal_fault_alarm_198_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_198 = {
  &page_main_internal_fault_alarm_198_tiles,
  8,
  0,
  0,
  14,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_fault_alarm_199_tbl[] = {
  0xB1D440+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*16,
};

struct tw_tiles code page_main_internal_fault_alarm_199_tiles = {
  page_main_internal_fault_alarm_199_tbl,
  1,
};

struct tw_gicon code page_main_internal_fault_alarm_199 = {
  &page_main_internal_fault_alarm_199_tiles,
  8,
  0,
  0,
  8,
  2,
  45,
  0X06f0,
};

unsigned long code page_main_internal_bihe_tbl[] = {
  0xB1DA40+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_bihe_tiles = {
  page_main_internal_bihe_tbl,
  1,
};

struct tw_gicon code page_main_internal_bihe = {
  &page_main_internal_bihe_tiles,
  4,
  0,
  0,
  3,
  1,
  170,
  0X1e60,
};

unsigned long code page_main_internal_duankai_tbl[] = {
  0xB1DB60+RES_OFFSET, _OSD2_1_MENU_2BP_SIZE*3,
};

struct tw_tiles code page_main_internal_duankai_tiles = {
  page_main_internal_duankai_tbl,
  1,
};

struct tw_gicon code page_main_internal_duankai = {
  &page_main_internal_duankai_tiles,
  4,
  0,
  0,
  3,
  1,
  170,
  0X1e60,
};

struct tw_icon code page_main_internal_arrows = {
  0xB1DC80+RES_OFFSET,
  1,
  0,
  0,
  2,
  1,
  174,
};

struct tw_icon code page_main_internal_fault_flag_red = {
  0xB1DE00+RES_OFFSET,
  2,
  0,
  0,
  3,
  2,
  176,
};

struct tw_icon code page_main_internal_status_green = {
  0xB1E280+RES_OFFSET,
  3,
  0,
  0,
  2,
  1,
  182,
};

struct tw_icon code page_main_internal_status_red = {
  0xB1E400+RES_OFFSET,
  4,
  0,
  0,
  2,
  1,
  184,
};

unsigned long code page_main_internal_mark_d_tbl[] = {
  0xB1E580+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_d_tiles = {
  page_main_internal_mark_d_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_d = {
  &page_main_internal_mark_d_tiles,
  3,
  0,
  0,
  3,
  2,
  186,
  0X23a0,
};

unsigned long code page_main_internal_mark_d1_tbl[] = {
  0xB1EA00+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_d1_tiles = {
  page_main_internal_mark_d1_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_d1 = {
  &page_main_internal_mark_d1_tiles,
  3,
  0,
  0,
  3,
  2,
  186,
  0X23a0,
};

unsigned long code page_main_internal_mark_d2_tbl[] = {
  0xB1EE80+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_d2_tiles = {
  page_main_internal_mark_d2_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_d2 = {
  &page_main_internal_mark_d2_tiles,
  3,
  0,
  0,
  3,
  2,
  186,
  0X23a0,
};

unsigned long code page_main_internal_mark_d3_tbl[] = {
  0xB1F300+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_d3_tiles = {
  page_main_internal_mark_d3_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_d3 = {
  &page_main_internal_mark_d3_tiles,
  3,
  0,
  0,
  3,
  2,
  186,
  0X23a0,
};

unsigned long code page_main_internal_mark_d4_tbl[] = {
  0xB1F780+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_d4_tiles = {
  page_main_internal_mark_d4_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_d4 = {
  &page_main_internal_mark_d4_tiles,
  3,
  0,
  0,
  3,
  2,
  186,
  0X23a0,
};

unsigned long code page_main_internal_mark_d5_tbl[] = {
  0xB1FC00+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_d5_tiles = {
  page_main_internal_mark_d5_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_d5 = {
  &page_main_internal_mark_d5_tiles,
  3,
  0,
  0,
  3,
  2,
  186,
  0X23a0,
};

unsigned long code page_main_internal_mark_d6_tbl[] = {
  0xB20080+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_d6_tiles = {
  page_main_internal_mark_d6_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_d6 = {
  &page_main_internal_mark_d6_tiles,
  3,
  0,
  0,
  3,
  2,
  186,
  0X23a0,
};

unsigned long code page_main_internal_mark_d7_tbl[] = {
  0xB20500+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_d7_tiles = {
  page_main_internal_mark_d7_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_d7 = {
  &page_main_internal_mark_d7_tiles,
  3,
  0,
  0,
  3,
  2,
  186,
  0X23a0,
};

unsigned long code page_main_internal_mark_d8_tbl[] = {
  0xB20980+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_d8_tiles = {
  page_main_internal_mark_d8_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_d8 = {
  &page_main_internal_mark_d8_tiles,
  3,
  0,
  0,
  3,
  2,
  186,
  0X23a0,
};

unsigned long code page_main_internal_mark_d9_tbl[] = {
  0xB20E00+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_d9_tiles = {
  page_main_internal_mark_d9_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_d9 = {
  &page_main_internal_mark_d9_tiles,
  3,
  0,
  0,
  3,
  2,
  186,
  0X23a0,
};

unsigned long code page_main_internal_mark_d10_tbl[] = {
  0xB21280+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_d10_tiles = {
  page_main_internal_mark_d10_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_d10 = {
  &page_main_internal_mark_d10_tiles,
  3,
  0,
  0,
  3,
  2,
  186,
  0X23a0,
};

unsigned long code page_main_internal_mark_d11_tbl[] = {
  0xB21700+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_d11_tiles = {
  page_main_internal_mark_d11_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_d11 = {
  &page_main_internal_mark_d11_tiles,
  3,
  0,
  0,
  3,
  2,
  186,
  0X23a0,
};

unsigned long code page_main_internal_mark_d12_tbl[] = {
  0xB21B80+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_d12_tiles = {
  page_main_internal_mark_d12_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_d12 = {
  &page_main_internal_mark_d12_tiles,
  3,
  0,
  0,
  3,
  2,
  186,
  0X23a0,
};

unsigned long code page_main_internal_mark_n_tbl[] = {
  0xB22000+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_n_tiles = {
  page_main_internal_mark_n_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_n = {
  &page_main_internal_mark_n_tiles,
  5,
  0,
  0,
  3,
  2,
  186,
  0X23a0,
};

unsigned long code page_main_internal_mark_r_tbl[] = {
  0xB22480+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_r_tiles = {
  page_main_internal_mark_r_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_r = {
  &page_main_internal_mark_r_tiles,
  4,
  0,
  0,
  3,
  2,
  186,
  0X23a0,
};

unsigned long code page_main_internal_mark_bai_tbl[] = {
  0xB22900+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_bai_tiles = {
  page_main_internal_mark_bai_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_bai = {
  &page_main_internal_mark_bai_tiles,
  5,
  0,
  0,
  3,
  2,
  192,
  0X25e0,
};

unsigned long code page_main_internal_mark_hong_tbl[] = {
  0xB22D80+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_hong_tiles = {
  page_main_internal_mark_hong_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_hong = {
  &page_main_internal_mark_hong_tiles,
  4,
  0,
  0,
  3,
  2,
  192,
  0X25e0,
};

unsigned long code page_main_internal_mark_r_stop_tbl[] = {
  0xB23200+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_r_stop_tiles = {
  page_main_internal_mark_r_stop_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_r_stop = {
  &page_main_internal_mark_r_stop_tiles,
  4,
  0,
  0,
  3,
  2,
  198,
  0X2820,
};

unsigned long code page_main_internal_mark_y_stop_tbl[] = {
  0xB23680+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*6,
};

struct tw_tiles code page_main_internal_mark_y_stop_tiles = {
  page_main_internal_mark_y_stop_tbl,
  1,
};

struct tw_gicon code page_main_internal_mark_y_stop = {
  &page_main_internal_mark_y_stop_tiles,
  6,
  0,
  0,
  3,
  2,
  198,
  0X2820,
};

unsigned long code page_main_internal_door_close_0_tbl[] = {
  0xB23B00+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*9,
};

struct tw_tiles code page_main_internal_door_close_0_tiles = {
  page_main_internal_door_close_0_tbl,
  1,
};

struct tw_gicon code page_main_internal_door_close_0 = {
  &page_main_internal_door_close_0_tiles,
  7,
  0,
  0,
  3,
  3,
  204,
  0X2a60,
};

unsigned long code page_main_internal_door_open_0_tbl[] = {
  0xB241C0+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*9,
};

struct tw_tiles code page_main_internal_door_open_0_tiles = {
  page_main_internal_door_open_0_tbl,
  1,
};

struct tw_gicon code page_main_internal_door_open_0 = {
  &page_main_internal_door_open_0_tiles,
  8,
  0,
  0,
  3,
  3,
  204,
  0X2a60,
};

unsigned long code page_main_internal_door_close_1_tbl[] = {
  0xB24880+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*20,
};

struct tw_tiles code page_main_internal_door_close_1_tiles = {
  page_main_internal_door_close_1_tbl,
  1,
};

struct tw_gicon code page_main_internal_door_close_1 = {
  &page_main_internal_door_close_1_tiles,
  7,
  0,
  0,
  4,
  5,
  213,
  0X2dc0,
};

unsigned long code page_main_internal_door_open_1_tbl[] = {
  0xB25780+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*20,
};

struct tw_tiles code page_main_internal_door_open_1_tiles = {
  page_main_internal_door_open_1_tbl,
  1,
};

struct tw_gicon code page_main_internal_door_open_1 = {
  &page_main_internal_door_open_1_tiles,
  8,
  0,
  0,
  4,
  5,
  213,
  0X2dc0,
};

unsigned long code page_main_internal_door_close_2_tbl[] = {
  0xB26680+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*16,
};

struct tw_tiles code page_main_internal_door_close_2_tiles = {
  page_main_internal_door_close_2_tbl,
  1,
};

struct tw_gicon code page_main_internal_door_close_2 = {
  &page_main_internal_door_close_2_tiles,
  7,
  0,
  0,
  4,
  4,
  233,
  0X3540,
};

unsigned long code page_main_internal_door_open_2_tbl[] = {
  0xB27280+RES_OFFSET, _OSD2_1_MENU_4BP_SIZE*16,
};

struct tw_tiles code page_main_internal_door_open_2_tiles = {
  page_main_internal_door_open_2_tbl,
  1,
};

struct tw_gicon code page_main_internal_door_open_2 = {
  &page_main_internal_door_open_2_tiles,
  8,
  0,
  0,
  4,
  4,
  233,
  0X3540,
};

struct tw_luts code page_main_internal_osd2_1_lut = {
  0xB28876+RES_OFFSET,
  180,//main len
  0,//sec len
  36,//2bp len
  4//bg len
};

struct tw_regs code page_main_internal_osd2_1_org = {
  0xB27FD0+RES_OFFSET,
  54
};

unsigned long code osd2_1_tile_tbl[] = {
  0xA4D0F0+RES_OFFSET,  _OSD2_1_MENU_1BP_SIZE*1,
  0xA4D120+RES_OFFSET,  _OSD2_1_MENU_1BP_SIZE*6,
  0xA4D240+RES_OFFSET,  _OSD2_1_MENU_1BP_SIZE*1,
  0xA4D270+RES_OFFSET,  _OSD2_1_MENU_1BP_SIZE*1,
  0xA4D2A0+RES_OFFSET,  _OSD2_1_MENU_1BP_SIZE*1,
  0xA4D2D0+RES_OFFSET,  _OSD2_1_MENU_1BP_SIZE*1,
  0xA4D300+RES_OFFSET,  _OSD2_1_MENU_1BP_SIZE*1,
  0xA4D330+RES_OFFSET,  _OSD2_1_MENU_1BP_SIZE*1,
  0xA4D360+RES_OFFSET,  _OSD2_1_MENU_1BP_SIZE*1,
  0xA4D390+RES_OFFSET,  _OSD2_1_MENU_1BP_SIZE*1,
  0xB27E80+RES_OFFSET,  _OSD2_1_MENU_1BP_SIZE*1,
  0xA4D3C0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*2,
  0xA4D480+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*2,
  0xA4D540+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*2,
  0xA4D600+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4D660+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4D6C0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4D720+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4D780+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4D7E0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4D840+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4D8A0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4D900+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4D960+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4D9C0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4DA20+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4DA80+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4DAE0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4DB40+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4DBA0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4DC00+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4DC60+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4DCC0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4DD20+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4DD80+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4DDE0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4DE40+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xA4DEA0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*44,
  0xB08C20+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*3,
  0xB0A2A0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*3,
  0xB0A3C0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*3,
  0xB0A4E0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*3,
  0xB0AD80+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*3,
  0xB0B320+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*6,
  0xB0D840+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*3,
  0xB0FE80+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*3,
  0xB0FFA0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*3,
  0xB100C0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*3,
  0xB101E0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*3,
  0xB10300+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*2,
  0xB103C0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*2,
  0xB10480+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*2,
  0xB10540+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*2,
  0xB10600+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*2,
  0xB106C0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*2,
  0xB10780+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*2,
  0xB10840+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*2,
  0xB10900+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*2,
  0xB109C0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*2,
  0xB10A80+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*4,
  0xB10C00+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*8,
  0xB1DA40+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*3,
  0xB27EB0+RES_OFFSET,  _OSD2_1_MENU_2BP_SIZE*1,
  0xB1DC80+RES_OFFSET,  _OSD2_1_MENU_4BP_SIZE*2,
  0xB1DE00+RES_OFFSET,  _OSD2_1_MENU_4BP_SIZE*6,
  0xB1E280+RES_OFFSET,  _OSD2_1_MENU_4BP_SIZE*2,
  0xB1E400+RES_OFFSET,  _OSD2_1_MENU_4BP_SIZE*2,
  0xB1E580+RES_OFFSET,  _OSD2_1_MENU_4BP_SIZE*6,
  0xB22900+RES_OFFSET,  _OSD2_1_MENU_4BP_SIZE*6,
  0xB23200+RES_OFFSET,  _OSD2_1_MENU_4BP_SIZE*6,
  0xB23B00+RES_OFFSET,  _OSD2_1_MENU_4BP_SIZE*9,
  0xB24880+RES_OFFSET,  _OSD2_1_MENU_4BP_SIZE*20,
  0xB26680+RES_OFFSET,  _OSD2_1_MENU_4BP_SIZE*16,
  0xB27F10+RES_OFFSET,  _OSD2_1_MENU_4BP_SIZE*1,
};

struct tw_tiles code page_main_internal_osd2_1_tile = {
  osd2_1_tile_tbl,
  74//length
};

