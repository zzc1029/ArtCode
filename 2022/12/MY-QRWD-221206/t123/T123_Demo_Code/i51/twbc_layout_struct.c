#include "sys.h"
#include "tw_widget_sys.h"
#include "res.h"
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
    ID_MAIN_TD_R_LOGO, 0, 0, 800, 480
};

struct tw_td code main_td_r_help_message = {
    ID_MAIN_TD_R_HELP_MESSAGE, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface7 = {
    ID_MAIN_TD_R_SURFACE7, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface15 = {
    ID_MAIN_TD_R_SURFACE15, 0, 0, 800, 480
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
    ID_MAIN_TD_R_MAIN_INTERNAL, 0, 0, 800, 480
};

struct tw_td code main_td_r_video = {
    ID_MAIN_TD_R_VIDEO, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface8 = {
    ID_MAIN_TD_R_SURFACE8, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface16 = {
    ID_MAIN_TD_R_SURFACE16, 0, 0, 800, 480
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
    ID_MAIN_TD_R_MAIN_MENUS, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface1 = {
    ID_MAIN_TD_R_SURFACE1, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface9 = {
    ID_MAIN_TD_R_SURFACE9, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface17 = {
    ID_MAIN_TD_R_SURFACE17, 0, 0, 800, 480
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
    ID_MAIN_TD_R_METER_MOUDLE, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface2 = {
    ID_MAIN_TD_R_SURFACE2, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface10 = {
    ID_MAIN_TD_R_SURFACE10, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface18 = {
    ID_MAIN_TD_R_SURFACE18, 0, 0, 800, 480
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
    ID_MAIN_TD_R_FRONT_MOUDLE, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface3 = {
    ID_MAIN_TD_R_SURFACE3, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface11 = {
    ID_MAIN_TD_R_SURFACE11, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface19 = {
    ID_MAIN_TD_R_SURFACE19, 0, 0, 800, 480
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
    ID_MAIN_TD_R_REAR_MOUDLE, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface4 = {
    ID_MAIN_TD_R_SURFACE4, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface12 = {
    ID_MAIN_TD_R_SURFACE12, 0, 0, 800, 480
};

struct tw_td code main_td_r_surface20 = {
    ID_MAIN_TD_R_SURFACE20, 0, 0, 800, 480
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
