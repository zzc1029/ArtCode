#define OSD2_1_MENU_WIDTH  50
#define OSD2_1_MENU_HEIGHT 20
#define OSD2_1_MENU_MENU_START_ADDR 0x3BC5
#define OSD2_1_MENU_MENU_END_ADDR 0x3FFD
#define OSD2_1_MENU_SIZE ((OSD2_1_MENU_WIDTH*2+8)*OSD2_1_MENU_HEIGHT) //byte
extern unsigned char code osd2_1_menu[];
