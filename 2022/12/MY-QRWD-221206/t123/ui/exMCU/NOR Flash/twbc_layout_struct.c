#include "sys.h"
#include "tw_ex_sys.h"
#include "res_full.h"
#include "page_start.h"
#include "page_logo.h"
#include "page_main_internal.h"
#include "page_main_menus.h"
#include "page_meter_moudle.h"
#include "page_front_moudle.h"
#include "page_rear_moudle.h"
#include "page_top_moudle.h"
#include "page_parameter.h"
#include "page_help_message.h"
#include "page_video.h"
#include "page_surface1.h"
#include "page_surface2.h"
#include "page_surface3.h"
#include "page_surface4.h"
#include "page_surface5.h"
#include "page_surface6.h"
#include "page_surface7.h"
#include "page_surface8.h"
#include "page_surface9.h"
#include "page_surface10.h"
#include "page_surface11.h"
#include "page_surface12.h"
#include "page_surface13.h"
#include "page_surface14.h"
#include "page_surface15.h"
#include "page_surface16.h"
#include "page_surface17.h"
#include "page_surface18.h"
#include "page_surface19.h"
#include "page_surface20.h"
#include "page_surface21.h"
#include "twbc_layout_struct.h"

struct tw_layout_item code td_layout_0_item0 = {
 &main_start,  NULL, &td_layout_0_item2, NULL, &td_layout_0_item1,NULL};
struct tw_layout_item code td_layout_0_item1 = {
 &main_logo,  NULL, &td_layout_0_item3, &td_layout_0_item0, NULL,&td_layout_1_item0};
struct tw_layout_item code td_layout_0_item2 = {
 &main_parameter, &td_layout_0_item0, &td_layout_0_item4, NULL, &td_layout_0_item3,NULL};
struct tw_layout_item code td_layout_0_item3 = {
 &main_help_message, &td_layout_0_item1, &td_layout_0_item5, &td_layout_0_item2, NULL,&td_layout_1_item2};
struct tw_layout_item code td_layout_0_item4 = {
 &main_surface6, &td_layout_0_item2, &td_layout_0_item6, NULL, &td_layout_0_item5,NULL};
struct tw_layout_item code td_layout_0_item5 = {
 &main_surface7, &td_layout_0_item3, &td_layout_0_item7, &td_layout_0_item4, NULL,&td_layout_1_item4};
struct tw_layout_item code td_layout_0_item6 = {
 &main_surface14, &td_layout_0_item4, NULL, NULL, &td_layout_0_item7,NULL};
struct tw_layout_item code td_layout_0_item7 = {
 &main_surface15, &td_layout_0_item5, NULL, &td_layout_0_item6, NULL,&td_layout_1_item6};

struct tw_td code main_td_r_logo = {
  0x178B90+RES_OFFSET,
  0x235F20+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_help_message = {
  0x1A7D50+RES_OFFSET,
  0x264D20+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface7 = {
  0x1D6F10+RES_OFFSET,
  0x293B20+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface15 = {
  0x2060D0+RES_OFFSET,
  0x2C2920+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_layout_item code td_layout_1_item0 = {
 &main_td_r_logo,  NULL, &td_layout_1_item2, NULL, &td_layout_1_item1,&td_layout_0_item1};
struct tw_layout_item code td_layout_1_item1 = {
 &main_main_internal,  NULL, &td_layout_1_item3, &td_layout_1_item0, NULL,&td_layout_2_item0};
struct tw_layout_item code td_layout_1_item2 = {
 &main_td_r_help_message, &td_layout_1_item0, &td_layout_1_item4, NULL, &td_layout_1_item3,&td_layout_0_item3};
struct tw_layout_item code td_layout_1_item3 = {
 &main_video, &td_layout_1_item1, &td_layout_1_item5, &td_layout_1_item2, NULL,&td_layout_2_item2};
struct tw_layout_item code td_layout_1_item4 = {
 &main_td_r_surface7, &td_layout_1_item2, &td_layout_1_item6, NULL, &td_layout_1_item5,&td_layout_0_item5};
struct tw_layout_item code td_layout_1_item5 = {
 &main_surface8, &td_layout_1_item3, &td_layout_1_item7, &td_layout_1_item4, NULL,&td_layout_2_item4};
struct tw_layout_item code td_layout_1_item6 = {
 &main_td_r_surface15, &td_layout_1_item4, NULL, NULL, &td_layout_1_item7,&td_layout_0_item7};
struct tw_layout_item code td_layout_1_item7 = {
 &main_surface16, &td_layout_1_item5, NULL, &td_layout_1_item6, NULL,&td_layout_2_item6};

struct tw_td code main_td_r_main_internal = {
  0x2F1720+RES_OFFSET,
  0x3AEAB0+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_video = {
  0x3208E0+RES_OFFSET,
  0x3DD8B0+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface8 = {
  0x34FAA0+RES_OFFSET,
  0x40C6B0+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface16 = {
  0x37EC60+RES_OFFSET,
  0x43B4B0+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_layout_item code td_layout_2_item0 = {
 &main_td_r_main_internal,  NULL, &td_layout_2_item2, NULL, &td_layout_2_item1,&td_layout_1_item1};
struct tw_layout_item code td_layout_2_item1 = {
 &main_main_menus,  NULL, &td_layout_2_item3, &td_layout_2_item0, NULL,&td_layout_3_item0};
struct tw_layout_item code td_layout_2_item2 = {
 &main_td_r_video, &td_layout_2_item0, &td_layout_2_item4, NULL, &td_layout_2_item3,&td_layout_1_item3};
struct tw_layout_item code td_layout_2_item3 = {
 &main_surface1, &td_layout_2_item1, &td_layout_2_item5, &td_layout_2_item2, NULL,&td_layout_3_item2};
struct tw_layout_item code td_layout_2_item4 = {
 &main_td_r_surface8, &td_layout_2_item2, &td_layout_2_item6, NULL, &td_layout_2_item5,&td_layout_1_item5};
struct tw_layout_item code td_layout_2_item5 = {
 &main_surface9, &td_layout_2_item3, &td_layout_2_item7, &td_layout_2_item4, NULL,&td_layout_3_item4};
struct tw_layout_item code td_layout_2_item6 = {
 &main_td_r_surface16, &td_layout_2_item4, NULL, NULL, &td_layout_2_item7,&td_layout_1_item7};
struct tw_layout_item code td_layout_2_item7 = {
 &main_surface17, &td_layout_2_item5, NULL, &td_layout_2_item6, NULL,&td_layout_3_item6};

struct tw_td code main_td_r_main_menus = {
  0x46A2B0+RES_OFFSET,
  0x527640+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface1 = {
  0x499470+RES_OFFSET,
  0x556440+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface9 = {
  0x4C8630+RES_OFFSET,
  0x585240+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface17 = {
  0x4F77F0+RES_OFFSET,
  0x5B4040+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_layout_item code td_layout_3_item0 = {
 &main_td_r_main_menus,  NULL, &td_layout_3_item2, NULL, &td_layout_3_item1,&td_layout_2_item1};
struct tw_layout_item code td_layout_3_item1 = {
 &main_meter_moudle,  NULL, &td_layout_3_item3, &td_layout_3_item0, NULL,&td_layout_4_item0};
struct tw_layout_item code td_layout_3_item2 = {
 &main_td_r_surface1, &td_layout_3_item0, &td_layout_3_item4, NULL, &td_layout_3_item3,&td_layout_2_item3};
struct tw_layout_item code td_layout_3_item3 = {
 &main_surface2, &td_layout_3_item1, &td_layout_3_item5, &td_layout_3_item2, NULL,&td_layout_4_item2};
struct tw_layout_item code td_layout_3_item4 = {
 &main_td_r_surface9, &td_layout_3_item2, &td_layout_3_item6, NULL, &td_layout_3_item5,&td_layout_2_item5};
struct tw_layout_item code td_layout_3_item5 = {
 &main_surface10, &td_layout_3_item3, &td_layout_3_item7, &td_layout_3_item4, NULL,&td_layout_4_item4};
struct tw_layout_item code td_layout_3_item6 = {
 &main_td_r_surface17, &td_layout_3_item4, NULL, NULL, &td_layout_3_item7,&td_layout_2_item7};
struct tw_layout_item code td_layout_3_item7 = {
 &main_surface18, &td_layout_3_item5, NULL, &td_layout_3_item6, NULL,&td_layout_4_item6};

struct tw_td code main_td_r_meter_moudle = {
  0x5E2E40+RES_OFFSET,
  0x6A01D0+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface2 = {
  0x612000+RES_OFFSET,
  0x6CEFD0+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface10 = {
  0x6411C0+RES_OFFSET,
  0x6FDDD0+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface18 = {
  0x670380+RES_OFFSET,
  0x72CBD0+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_layout_item code td_layout_4_item0 = {
 &main_td_r_meter_moudle,  NULL, &td_layout_4_item2, NULL, &td_layout_4_item1,&td_layout_3_item1};
struct tw_layout_item code td_layout_4_item1 = {
 &main_front_moudle,  NULL, &td_layout_4_item3, &td_layout_4_item0, NULL,&td_layout_5_item0};
struct tw_layout_item code td_layout_4_item2 = {
 &main_td_r_surface2, &td_layout_4_item0, &td_layout_4_item4, NULL, &td_layout_4_item3,&td_layout_3_item3};
struct tw_layout_item code td_layout_4_item3 = {
 &main_surface3, &td_layout_4_item1, &td_layout_4_item5, &td_layout_4_item2, NULL,&td_layout_5_item2};
struct tw_layout_item code td_layout_4_item4 = {
 &main_td_r_surface10, &td_layout_4_item2, &td_layout_4_item6, NULL, &td_layout_4_item5,&td_layout_3_item5};
struct tw_layout_item code td_layout_4_item5 = {
 &main_surface11, &td_layout_4_item3, &td_layout_4_item7, &td_layout_4_item4, NULL,&td_layout_5_item4};
struct tw_layout_item code td_layout_4_item6 = {
 &main_td_r_surface18, &td_layout_4_item4, NULL, NULL, &td_layout_4_item7,&td_layout_3_item7};
struct tw_layout_item code td_layout_4_item7 = {
 &main_surface19, &td_layout_4_item5, NULL, &td_layout_4_item6, NULL,&td_layout_5_item6};

struct tw_td code main_td_r_front_moudle = {
  0x75B9D0+RES_OFFSET,
  0x818D60+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface3 = {
  0x78AB90+RES_OFFSET,
  0x847B60+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface11 = {
  0x7B9D50+RES_OFFSET,
  0x876960+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface19 = {
  0x7E8F10+RES_OFFSET,
  0x8A5760+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_layout_item code td_layout_5_item0 = {
 &main_td_r_front_moudle,  NULL, &td_layout_5_item2, NULL, &td_layout_5_item1,&td_layout_4_item1};
struct tw_layout_item code td_layout_5_item1 = {
 &main_rear_moudle,  NULL, &td_layout_5_item3, &td_layout_5_item0, NULL,&td_layout_6_item0};
struct tw_layout_item code td_layout_5_item2 = {
 &main_td_r_surface3, &td_layout_5_item0, &td_layout_5_item4, NULL, &td_layout_5_item3,&td_layout_4_item3};
struct tw_layout_item code td_layout_5_item3 = {
 &main_surface4, &td_layout_5_item1, &td_layout_5_item5, &td_layout_5_item2, NULL,&td_layout_6_item2};
struct tw_layout_item code td_layout_5_item4 = {
 &main_td_r_surface11, &td_layout_5_item2, &td_layout_5_item6, NULL, &td_layout_5_item5,&td_layout_4_item5};
struct tw_layout_item code td_layout_5_item5 = {
 &main_surface12, &td_layout_5_item3, &td_layout_5_item7, &td_layout_5_item4, NULL,&td_layout_6_item4};
struct tw_layout_item code td_layout_5_item6 = {
 &main_td_r_surface19, &td_layout_5_item4, NULL, NULL, &td_layout_5_item7,&td_layout_4_item7};
struct tw_layout_item code td_layout_5_item7 = {
 &main_surface20, &td_layout_5_item5, NULL, &td_layout_5_item6, NULL,&td_layout_6_item6};

struct tw_td code main_td_r_rear_moudle = {
  0x8D4560+RES_OFFSET,
  0x9918F0+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface4 = {
  0x903720+RES_OFFSET,
  0x9C06F0+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface12 = {
  0x9328E0+RES_OFFSET,
  0x9EF4F0+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_td code main_td_r_surface20 = {
  0x961AA0+RES_OFFSET,
  0xA1E2F0+RES_OFFSET,
  0,
  0,
  800,
  480,
  1600
};

struct tw_layout_item code td_layout_6_item0 = {
 &main_td_r_rear_moudle,  NULL, &td_layout_6_item2, NULL, &td_layout_6_item1,&td_layout_5_item1};
struct tw_layout_item code td_layout_6_item1 = {
 &main_top_moudle,  NULL, &td_layout_6_item3, &td_layout_6_item0, NULL,NULL};
struct tw_layout_item code td_layout_6_item2 = {
 &main_td_r_surface4, &td_layout_6_item0, &td_layout_6_item4, NULL, &td_layout_6_item3,&td_layout_5_item3};
struct tw_layout_item code td_layout_6_item3 = {
 &main_surface5, &td_layout_6_item1, &td_layout_6_item5, &td_layout_6_item2, NULL,NULL};
struct tw_layout_item code td_layout_6_item4 = {
 &main_td_r_surface12, &td_layout_6_item2, &td_layout_6_item6, NULL, &td_layout_6_item5,&td_layout_5_item5};
struct tw_layout_item code td_layout_6_item5 = {
 &main_surface13, &td_layout_6_item3, &td_layout_6_item7, &td_layout_6_item4, NULL,NULL};
struct tw_layout_item code td_layout_6_item6 = {
 &main_td_r_surface20, &td_layout_6_item4, NULL, NULL, &td_layout_6_item7,&td_layout_5_item7};
struct tw_layout_item code td_layout_6_item7 = {
 &main_surface21, &td_layout_6_item5, NULL, &td_layout_6_item6, NULL,NULL};

struct tw_layout_group code main_group0 = {
  2, 4, &td_layout_0_item0
};


struct tw_layout_group code main_group1 = {
  2, 4, &td_layout_1_item0
};


struct tw_layout_group code main_group2 = {
  2, 4, &td_layout_2_item0
};


struct tw_layout_group code main_group3 = {
  2, 4, &td_layout_3_item0
};


struct tw_layout_group code main_group4 = {
  2, 4, &td_layout_4_item0
};


struct tw_layout_group code main_group5 = {
  2, 4, &td_layout_5_item0
};


struct tw_layout_group code main_group6 = {
  2, 4, &td_layout_6_item0
};

struct tw_layout code main = {
  1, 7, &main_group0
};
