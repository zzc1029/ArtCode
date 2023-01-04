#define OSD2_1_MENU_FONT_W  16L
#define OSD2_1_MENU_FONT_H  24L

#define OSD2_1_MENU_1BP_SIZE ((OSD2_1_MENU_FONT_W*OSD2_1_MENU_FONT_H)/8L) //bytes
#define OSD2_1_MENU_2BP_SIZE ((OSD2_1_MENU_FONT_W*OSD2_1_MENU_FONT_H)/4L) //bytes
#define OSD2_1_MENU_4BP_SIZE ((OSD2_1_MENU_FONT_W*OSD2_1_MENU_FONT_H)/2L) //bytes
#define OSD2_1_MENU_8BP_SIZE ((OSD2_1_MENU_FONT_W*OSD2_1_MENU_FONT_H)/1L) //bytes

#define OSD2_1_MENU_1BP_TOTAL (1+6+1+1+1+1+1+1+1+1+1L)
#define OSD2_1_MENU_2BP_TOTAL (2+2+2+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+44+36+36+36+36+36+36+36+36+36+40+44+44+44+44+44+44+44+44+28+32+28+28+28+28+44+3+3+3+3+3+3+3+3+3+3+3+3+3+3+3+3+3+3+3+3+3+3+3+3+4+4+3+3+3+3+3+3+3+3+6+6+6+9+9+9+9+9+9+9+9+9+3+3+8+8+8+8+8+8+8+8+8+8+8+8+3+3+3+3+2+2+2+2+2+2+2+2+2+2+4+8+8+12+12+12+12+38+38+38+38+38+38+38+38+38+40+20+20+20+28+16+3+3+1L)
#define OSD2_1_MENU_4BP_TOTAL (2+6+2+2+6+6+6+6+6+6+6+6+6+6+6+6+6+6+6+6+6+6+6+9+9+20+20+16+16+1L)

#define OSD2_1_MENU_TOTAL_LENGTH ((OSD2_1_MENU_1BP_SIZE*OSD2_1_MENU_1BP_TOTAL)+(OSD2_1_MENU_2BP_SIZE*OSD2_1_MENU_2BP_TOTAL)+(OSD2_1_MENU_4BP_TOTAL*OSD2_1_MENU_4BP_SIZE))
extern unsigned short code osd2_1_menu_menuTable[];

#define _ICON_SPACE_W16_H24_1BP_WIDTH  1
#define _ICON_SPACE_W16_H24_1BP_HEIGHT 1
extern unsigned char code _icon_space_w16_h24_1bp[];

#define _BLACK_WIDTH  3
#define _BLACK_HEIGHT 2
extern unsigned char code _black[];

#define _SOC_0_WIDTH  1
#define _SOC_0_HEIGHT 1
extern unsigned char code _soc_0[];

#define _SOC_1_WIDTH  1
#define _SOC_1_HEIGHT 1
extern unsigned char code _soc_1[];

#define _SOC_2_WIDTH  1
#define _SOC_2_HEIGHT 1
extern unsigned char code _soc_2[];

#define _SOC_3_WIDTH  1
#define _SOC_3_HEIGHT 1
extern unsigned char code _soc_3[];

#define _SOC_4_WIDTH  1
#define _SOC_4_HEIGHT 1
extern unsigned char code _soc_4[];

#define _SOC_5_WIDTH  1
#define _SOC_5_HEIGHT 1
extern unsigned char code _soc_5[];

#define _SOC_6_WIDTH  1
#define _SOC_6_HEIGHT 1
extern unsigned char code _soc_6[];

#define _SOC_7_WIDTH  1
#define _SOC_7_HEIGHT 1
extern unsigned char code _soc_7[];

#define _ICON_DUMMY_W16_H24_1BP_WIDTH  1
#define _ICON_DUMMY_W16_H24_1BP_HEIGHT 1
extern unsigned char code _icon_dummy_w16_h24_1bp[];

#define _AV_WIDTH  2
#define _AV_HEIGHT 1
extern unsigned char code _av[];

#define _FONT_CLOSE_WIDTH  2
#define _FONT_CLOSE_HEIGHT 1
extern unsigned char code _font_close[];

#define _FONT_OPEN_WIDTH  2
#define _FONT_OPEN_HEIGHT 1
extern unsigned char code _font_open[];

#define _NUMBER_0_WIDTH  1
#define _NUMBER_0_HEIGHT 1
extern unsigned char code _number_0[];

#define _NUMBER_1_WIDTH  1
#define _NUMBER_1_HEIGHT 1
extern unsigned char code _number_1[];

#define _NUMBER_2_WIDTH  1
#define _NUMBER_2_HEIGHT 1
extern unsigned char code _number_2[];

#define _NUMBER_3_WIDTH  1
#define _NUMBER_3_HEIGHT 1
extern unsigned char code _number_3[];

#define _NUMBER_4_WIDTH  1
#define _NUMBER_4_HEIGHT 1
extern unsigned char code _number_4[];

#define _NUMBER_5_WIDTH  1
#define _NUMBER_5_HEIGHT 1
extern unsigned char code _number_5[];

#define _NUMBER_6_WIDTH  1
#define _NUMBER_6_HEIGHT 1
extern unsigned char code _number_6[];

#define _NUMBER_7_WIDTH  1
#define _NUMBER_7_HEIGHT 1
extern unsigned char code _number_7[];

#define _NUMBER_8_WIDTH  1
#define _NUMBER_8_HEIGHT 1
extern unsigned char code _number_8[];

#define _NUMBER_9_WIDTH  1
#define _NUMBER_9_HEIGHT 1
extern unsigned char code _number_9[];

#define _NUMBER_10_WIDTH  1
#define _NUMBER_10_HEIGHT 1
extern unsigned char code _number_10[];

#define _NUMBER_A_WIDTH  1
#define _NUMBER_A_HEIGHT 1
extern unsigned char code _number_a[];

#define _NUMBER_POINT_0_WIDTH  1
#define _NUMBER_POINT_0_HEIGHT 1
extern unsigned char code _number_point_0[];

#define _NUMBER_POINT_1_WIDTH  1
#define _NUMBER_POINT_1_HEIGHT 1
extern unsigned char code _number_point_1[];

#define _NUMBER_POINT_2_WIDTH  1
#define _NUMBER_POINT_2_HEIGHT 1
extern unsigned char code _number_point_2[];

#define _NUMBER_POINT_3_WIDTH  1
#define _NUMBER_POINT_3_HEIGHT 1
extern unsigned char code _number_point_3[];

#define _NUMBER_POINT_4_WIDTH  1
#define _NUMBER_POINT_4_HEIGHT 1
extern unsigned char code _number_point_4[];

#define _NUMBER_POINT_5_WIDTH  1
#define _NUMBER_POINT_5_HEIGHT 1
extern unsigned char code _number_point_5[];

#define _NUMBER_POINT_6_WIDTH  1
#define _NUMBER_POINT_6_HEIGHT 1
extern unsigned char code _number_point_6[];

#define _NUMBER_POINT_7_WIDTH  1
#define _NUMBER_POINT_7_HEIGHT 1
extern unsigned char code _number_point_7[];

#define _NUMBER_POINT_8_WIDTH  1
#define _NUMBER_POINT_8_HEIGHT 1
extern unsigned char code _number_point_8[];

#define _NUMBER_POINT_9_WIDTH  1
#define _NUMBER_POINT_9_HEIGHT 1
extern unsigned char code _number_point_9[];

#define _X_WIDTH  1
#define _X_HEIGHT 1
extern unsigned char code _x[];

#define _FAULT_ALARM_0_WIDTH  22
#define _FAULT_ALARM_0_HEIGHT 2
extern unsigned char code _fault_alarm_0[];

#define _FAULT_ALARM_1_WIDTH  22
#define _FAULT_ALARM_1_HEIGHT 2
extern unsigned char code _fault_alarm_1[];

#define _FAULT_ALARM_2_WIDTH  22
#define _FAULT_ALARM_2_HEIGHT 2
extern unsigned char code _fault_alarm_2[];

#define _FAULT_ALARM_3_WIDTH  22
#define _FAULT_ALARM_3_HEIGHT 2
extern unsigned char code _fault_alarm_3[];

#define _FAULT_ALARM_4_WIDTH  22
#define _FAULT_ALARM_4_HEIGHT 2
extern unsigned char code _fault_alarm_4[];

#define _FAULT_ALARM_5_WIDTH  22
#define _FAULT_ALARM_5_HEIGHT 2
extern unsigned char code _fault_alarm_5[];

#define _FAULT_ALARM_6_WIDTH  22
#define _FAULT_ALARM_6_HEIGHT 2
extern unsigned char code _fault_alarm_6[];

#define _FAULT_ALARM_7_WIDTH  22
#define _FAULT_ALARM_7_HEIGHT 2
extern unsigned char code _fault_alarm_7[];

#define _FAULT_ALARM_8_WIDTH  22
#define _FAULT_ALARM_8_HEIGHT 2
extern unsigned char code _fault_alarm_8[];

#define _FAULT_ALARM_9_WIDTH  22
#define _FAULT_ALARM_9_HEIGHT 2
extern unsigned char code _fault_alarm_9[];

#define _FAULT_ALARM_10_WIDTH  22
#define _FAULT_ALARM_10_HEIGHT 2
extern unsigned char code _fault_alarm_10[];

#define _FAULT_ALARM_11_WIDTH  22
#define _FAULT_ALARM_11_HEIGHT 2
extern unsigned char code _fault_alarm_11[];

#define _FAULT_ALARM_12_WIDTH  22
#define _FAULT_ALARM_12_HEIGHT 2
extern unsigned char code _fault_alarm_12[];

#define _FAULT_ALARM_13_WIDTH  22
#define _FAULT_ALARM_13_HEIGHT 2
extern unsigned char code _fault_alarm_13[];

#define _FAULT_ALARM_14_WIDTH  22
#define _FAULT_ALARM_14_HEIGHT 2
extern unsigned char code _fault_alarm_14[];

#define _FAULT_ALARM_15_WIDTH  22
#define _FAULT_ALARM_15_HEIGHT 2
extern unsigned char code _fault_alarm_15[];

#define _FAULT_ALARM_16_WIDTH  22
#define _FAULT_ALARM_16_HEIGHT 2
extern unsigned char code _fault_alarm_16[];

#define _FAULT_ALARM_17_WIDTH  22
#define _FAULT_ALARM_17_HEIGHT 2
extern unsigned char code _fault_alarm_17[];

#define _FAULT_ALARM_18_WIDTH  22
#define _FAULT_ALARM_18_HEIGHT 2
extern unsigned char code _fault_alarm_18[];

#define _FAULT_ALARM_19_WIDTH  22
#define _FAULT_ALARM_19_HEIGHT 2
extern unsigned char code _fault_alarm_19[];

#define _FAULT_ALARM_20_WIDTH  22
#define _FAULT_ALARM_20_HEIGHT 2
extern unsigned char code _fault_alarm_20[];

#define _FAULT_ALARM_21_WIDTH  22
#define _FAULT_ALARM_21_HEIGHT 2
extern unsigned char code _fault_alarm_21[];

#define _FAULT_ALARM_22_WIDTH  22
#define _FAULT_ALARM_22_HEIGHT 2
extern unsigned char code _fault_alarm_22[];

#define _FAULT_ALARM_23_WIDTH  22
#define _FAULT_ALARM_23_HEIGHT 2
extern unsigned char code _fault_alarm_23[];

#define _FAULT_ALARM_24_WIDTH  22
#define _FAULT_ALARM_24_HEIGHT 2
extern unsigned char code _fault_alarm_24[];

#define _FAULT_ALARM_25_WIDTH  22
#define _FAULT_ALARM_25_HEIGHT 2
extern unsigned char code _fault_alarm_25[];

#define _FAULT_ALARM_26_WIDTH  22
#define _FAULT_ALARM_26_HEIGHT 2
extern unsigned char code _fault_alarm_26[];

#define _FAULT_ALARM_27_WIDTH  22
#define _FAULT_ALARM_27_HEIGHT 2
extern unsigned char code _fault_alarm_27[];

#define _FAULT_ALARM_28_WIDTH  22
#define _FAULT_ALARM_28_HEIGHT 2
extern unsigned char code _fault_alarm_28[];

#define _FAULT_ALARM_29_WIDTH  22
#define _FAULT_ALARM_29_HEIGHT 2
extern unsigned char code _fault_alarm_29[];

#define _FAULT_ALARM_30_WIDTH  22
#define _FAULT_ALARM_30_HEIGHT 2
extern unsigned char code _fault_alarm_30[];

#define _FAULT_ALARM_31_WIDTH  22
#define _FAULT_ALARM_31_HEIGHT 2
extern unsigned char code _fault_alarm_31[];

#define _FAULT_ALARM_32_WIDTH  22
#define _FAULT_ALARM_32_HEIGHT 2
extern unsigned char code _fault_alarm_32[];

#define _FAULT_ALARM_33_WIDTH  22
#define _FAULT_ALARM_33_HEIGHT 2
extern unsigned char code _fault_alarm_33[];

#define _FAULT_ALARM_34_WIDTH  22
#define _FAULT_ALARM_34_HEIGHT 2
extern unsigned char code _fault_alarm_34[];

#define _FAULT_ALARM_35_WIDTH  22
#define _FAULT_ALARM_35_HEIGHT 2
extern unsigned char code _fault_alarm_35[];

#define _FAULT_ALARM_36_WIDTH  22
#define _FAULT_ALARM_36_HEIGHT 2
extern unsigned char code _fault_alarm_36[];

#define _FAULT_ALARM_37_WIDTH  22
#define _FAULT_ALARM_37_HEIGHT 2
extern unsigned char code _fault_alarm_37[];

#define _FAULT_ALARM_38_WIDTH  22
#define _FAULT_ALARM_38_HEIGHT 2
extern unsigned char code _fault_alarm_38[];

#define _FAULT_ALARM_39_WIDTH  22
#define _FAULT_ALARM_39_HEIGHT 2
extern unsigned char code _fault_alarm_39[];

#define _FAULT_ALARM_40_WIDTH  22
#define _FAULT_ALARM_40_HEIGHT 2
extern unsigned char code _fault_alarm_40[];

#define _FAULT_ALARM_41_WIDTH  22
#define _FAULT_ALARM_41_HEIGHT 2
extern unsigned char code _fault_alarm_41[];

#define _FAULT_ALARM_42_WIDTH  22
#define _FAULT_ALARM_42_HEIGHT 2
extern unsigned char code _fault_alarm_42[];

#define _FAULT_ALARM_43_WIDTH  22
#define _FAULT_ALARM_43_HEIGHT 2
extern unsigned char code _fault_alarm_43[];

#define _FAULT_ALARM_44_WIDTH  22
#define _FAULT_ALARM_44_HEIGHT 2
extern unsigned char code _fault_alarm_44[];

#define _FAULT_ALARM_45_WIDTH  22
#define _FAULT_ALARM_45_HEIGHT 2
extern unsigned char code _fault_alarm_45[];

#define _FAULT_ALARM_46_WIDTH  22
#define _FAULT_ALARM_46_HEIGHT 2
extern unsigned char code _fault_alarm_46[];

#define _FAULT_ALARM_47_WIDTH  22
#define _FAULT_ALARM_47_HEIGHT 2
extern unsigned char code _fault_alarm_47[];

#define _FAULT_ALARM_48_WIDTH  22
#define _FAULT_ALARM_48_HEIGHT 2
extern unsigned char code _fault_alarm_48[];

#define _FAULT_ALARM_49_WIDTH  22
#define _FAULT_ALARM_49_HEIGHT 2
extern unsigned char code _fault_alarm_49[];

#define _FAULT_ALARM_50_WIDTH  22
#define _FAULT_ALARM_50_HEIGHT 2
extern unsigned char code _fault_alarm_50[];

#define _FAULT_ALARM_51_WIDTH  22
#define _FAULT_ALARM_51_HEIGHT 2
extern unsigned char code _fault_alarm_51[];

#define _FAULT_ALARM_52_WIDTH  22
#define _FAULT_ALARM_52_HEIGHT 2
extern unsigned char code _fault_alarm_52[];

#define _FAULT_ALARM_53_WIDTH  22
#define _FAULT_ALARM_53_HEIGHT 2
extern unsigned char code _fault_alarm_53[];

#define _FAULT_ALARM_54_WIDTH  22
#define _FAULT_ALARM_54_HEIGHT 2
extern unsigned char code _fault_alarm_54[];

#define _FAULT_ALARM_55_WIDTH  22
#define _FAULT_ALARM_55_HEIGHT 2
extern unsigned char code _fault_alarm_55[];

#define _FAULT_ALARM_56_WIDTH  22
#define _FAULT_ALARM_56_HEIGHT 2
extern unsigned char code _fault_alarm_56[];

#define _FAULT_ALARM_57_WIDTH  22
#define _FAULT_ALARM_57_HEIGHT 2
extern unsigned char code _fault_alarm_57[];

#define _FAULT_ALARM_58_WIDTH  22
#define _FAULT_ALARM_58_HEIGHT 2
extern unsigned char code _fault_alarm_58[];

#define _FAULT_ALARM_59_WIDTH  22
#define _FAULT_ALARM_59_HEIGHT 2
extern unsigned char code _fault_alarm_59[];

#define _FAULT_ALARM_60_WIDTH  22
#define _FAULT_ALARM_60_HEIGHT 2
extern unsigned char code _fault_alarm_60[];

#define _FAULT_ALARM_61_WIDTH  22
#define _FAULT_ALARM_61_HEIGHT 2
extern unsigned char code _fault_alarm_61[];

#define _FAULT_ALARM_62_WIDTH  22
#define _FAULT_ALARM_62_HEIGHT 2
extern unsigned char code _fault_alarm_62[];

#define _FAULT_ALARM_63_WIDTH  22
#define _FAULT_ALARM_63_HEIGHT 2
extern unsigned char code _fault_alarm_63[];

#define _FAULT_ALARM_64_WIDTH  22
#define _FAULT_ALARM_64_HEIGHT 2
extern unsigned char code _fault_alarm_64[];

#define _FAULT_ALARM_65_WIDTH  22
#define _FAULT_ALARM_65_HEIGHT 2
extern unsigned char code _fault_alarm_65[];

#define _FAULT_ALARM_66_WIDTH  22
#define _FAULT_ALARM_66_HEIGHT 2
extern unsigned char code _fault_alarm_66[];

#define _FAULT_ALARM_67_WIDTH  22
#define _FAULT_ALARM_67_HEIGHT 2
extern unsigned char code _fault_alarm_67[];

#define _FAULT_ALARM_68_WIDTH  22
#define _FAULT_ALARM_68_HEIGHT 2
extern unsigned char code _fault_alarm_68[];

#define _FAULT_ALARM_69_WIDTH  22
#define _FAULT_ALARM_69_HEIGHT 2
extern unsigned char code _fault_alarm_69[];

#define _FAULT_ALARM_70_WIDTH  22
#define _FAULT_ALARM_70_HEIGHT 2
extern unsigned char code _fault_alarm_70[];

#define _FAULT_ALARM_71_WIDTH  22
#define _FAULT_ALARM_71_HEIGHT 2
extern unsigned char code _fault_alarm_71[];

#define _FAULT_ALARM_72_WIDTH  22
#define _FAULT_ALARM_72_HEIGHT 2
extern unsigned char code _fault_alarm_72[];

#define _FAULT_ALARM_73_WIDTH  22
#define _FAULT_ALARM_73_HEIGHT 2
extern unsigned char code _fault_alarm_73[];

#define _FAULT_ALARM_74_WIDTH  22
#define _FAULT_ALARM_74_HEIGHT 2
extern unsigned char code _fault_alarm_74[];

#define _FAULT_ALARM_75_WIDTH  22
#define _FAULT_ALARM_75_HEIGHT 2
extern unsigned char code _fault_alarm_75[];

#define _FAULT_ALARM_76_WIDTH  22
#define _FAULT_ALARM_76_HEIGHT 2
extern unsigned char code _fault_alarm_76[];

#define _FAULT_ALARM_77_WIDTH  22
#define _FAULT_ALARM_77_HEIGHT 2
extern unsigned char code _fault_alarm_77[];

#define _FAULT_ALARM_78_WIDTH  22
#define _FAULT_ALARM_78_HEIGHT 2
extern unsigned char code _fault_alarm_78[];

#define _FAULT_ALARM_79_WIDTH  22
#define _FAULT_ALARM_79_HEIGHT 2
extern unsigned char code _fault_alarm_79[];

#define _FAULT_ALARM_80_WIDTH  22
#define _FAULT_ALARM_80_HEIGHT 2
extern unsigned char code _fault_alarm_80[];

#define _FAULT_ALARM_81_WIDTH  22
#define _FAULT_ALARM_81_HEIGHT 2
extern unsigned char code _fault_alarm_81[];

#define _FAULT_ALARM_82_WIDTH  22
#define _FAULT_ALARM_82_HEIGHT 2
extern unsigned char code _fault_alarm_82[];

#define _FAULT_ALARM_83_WIDTH  22
#define _FAULT_ALARM_83_HEIGHT 2
extern unsigned char code _fault_alarm_83[];

#define _FAULT_ALARM_84_WIDTH  22
#define _FAULT_ALARM_84_HEIGHT 2
extern unsigned char code _fault_alarm_84[];

#define _FAULT_ALARM_85_WIDTH  22
#define _FAULT_ALARM_85_HEIGHT 2
extern unsigned char code _fault_alarm_85[];

#define _FAULT_ALARM_86_WIDTH  22
#define _FAULT_ALARM_86_HEIGHT 2
extern unsigned char code _fault_alarm_86[];

#define _FAULT_ALARM_87_WIDTH  22
#define _FAULT_ALARM_87_HEIGHT 2
extern unsigned char code _fault_alarm_87[];

#define _FAULT_ALARM_88_WIDTH  22
#define _FAULT_ALARM_88_HEIGHT 2
extern unsigned char code _fault_alarm_88[];

#define _FAULT_ALARM_89_WIDTH  22
#define _FAULT_ALARM_89_HEIGHT 2
extern unsigned char code _fault_alarm_89[];

#define _FAULT_ALARM_90_WIDTH  22
#define _FAULT_ALARM_90_HEIGHT 2
extern unsigned char code _fault_alarm_90[];

#define _FAULT_ALARM_91_WIDTH  22
#define _FAULT_ALARM_91_HEIGHT 2
extern unsigned char code _fault_alarm_91[];

#define _FAULT_ALARM_92_WIDTH  22
#define _FAULT_ALARM_92_HEIGHT 2
extern unsigned char code _fault_alarm_92[];

#define _FAULT_ALARM_93_WIDTH  22
#define _FAULT_ALARM_93_HEIGHT 2
extern unsigned char code _fault_alarm_93[];

#define _FAULT_ALARM_94_WIDTH  22
#define _FAULT_ALARM_94_HEIGHT 2
extern unsigned char code _fault_alarm_94[];

#define _FAULT_ALARM_95_WIDTH  22
#define _FAULT_ALARM_95_HEIGHT 2
extern unsigned char code _fault_alarm_95[];

#define _FAULT_ALARM_96_WIDTH  22
#define _FAULT_ALARM_96_HEIGHT 2
extern unsigned char code _fault_alarm_96[];

#define _FAULT_ALARM_97_WIDTH  22
#define _FAULT_ALARM_97_HEIGHT 2
extern unsigned char code _fault_alarm_97[];

#define _FAULT_ALARM_98_WIDTH  22
#define _FAULT_ALARM_98_HEIGHT 2
extern unsigned char code _fault_alarm_98[];

#define _FAULT_ALARM_99_WIDTH  22
#define _FAULT_ALARM_99_HEIGHT 2
extern unsigned char code _fault_alarm_99[];

#define _FAULT_ALARM_100_WIDTH  22
#define _FAULT_ALARM_100_HEIGHT 2
extern unsigned char code _fault_alarm_100[];

#define _FAULT_ALARM_101_WIDTH  22
#define _FAULT_ALARM_101_HEIGHT 2
extern unsigned char code _fault_alarm_101[];

#define _FAULT_ALARM_102_WIDTH  22
#define _FAULT_ALARM_102_HEIGHT 2
extern unsigned char code _fault_alarm_102[];

#define _FAULT_ALARM_103_WIDTH  22
#define _FAULT_ALARM_103_HEIGHT 2
extern unsigned char code _fault_alarm_103[];

#define _FAULT_ALARM_104_WIDTH  22
#define _FAULT_ALARM_104_HEIGHT 2
extern unsigned char code _fault_alarm_104[];

#define _FAULT_ALARM_105_WIDTH  22
#define _FAULT_ALARM_105_HEIGHT 2
extern unsigned char code _fault_alarm_105[];

#define _FAULT_ALARM_106_WIDTH  22
#define _FAULT_ALARM_106_HEIGHT 2
extern unsigned char code _fault_alarm_106[];

#define _FAULT_ALARM_107_WIDTH  22
#define _FAULT_ALARM_107_HEIGHT 2
extern unsigned char code _fault_alarm_107[];

#define _FAULT_ALARM_108_WIDTH  22
#define _FAULT_ALARM_108_HEIGHT 2
extern unsigned char code _fault_alarm_108[];

#define _FAULT_ALARM_109_WIDTH  22
#define _FAULT_ALARM_109_HEIGHT 2
extern unsigned char code _fault_alarm_109[];

#define _FAULT_ALARM_110_WIDTH  22
#define _FAULT_ALARM_110_HEIGHT 2
extern unsigned char code _fault_alarm_110[];

#define _FAULT_ALARM_111_WIDTH  22
#define _FAULT_ALARM_111_HEIGHT 2
extern unsigned char code _fault_alarm_111[];

#define _FAULT_ALARM_112_WIDTH  22
#define _FAULT_ALARM_112_HEIGHT 2
extern unsigned char code _fault_alarm_112[];

#define _FAULT_ALARM_113_WIDTH  22
#define _FAULT_ALARM_113_HEIGHT 2
extern unsigned char code _fault_alarm_113[];

#define _FAULT_ALARM_114_WIDTH  22
#define _FAULT_ALARM_114_HEIGHT 2
extern unsigned char code _fault_alarm_114[];

#define _FAULT_ALARM_115_WIDTH  22
#define _FAULT_ALARM_115_HEIGHT 2
extern unsigned char code _fault_alarm_115[];

#define _FAULT_ALARM_116_WIDTH  22
#define _FAULT_ALARM_116_HEIGHT 2
extern unsigned char code _fault_alarm_116[];

#define _FAULT_ALARM_117_WIDTH  22
#define _FAULT_ALARM_117_HEIGHT 2
extern unsigned char code _fault_alarm_117[];

#define _FAULT_ALARM_118_WIDTH  22
#define _FAULT_ALARM_118_HEIGHT 2
extern unsigned char code _fault_alarm_118[];

#define _FAULT_ALARM_119_WIDTH  22
#define _FAULT_ALARM_119_HEIGHT 2
extern unsigned char code _fault_alarm_119[];

#define _FAULT_ALARM_120_WIDTH  22
#define _FAULT_ALARM_120_HEIGHT 2
extern unsigned char code _fault_alarm_120[];

#define _FAULT_ALARM_121_WIDTH  22
#define _FAULT_ALARM_121_HEIGHT 2
extern unsigned char code _fault_alarm_121[];

#define _FAULT_ALARM_122_WIDTH  22
#define _FAULT_ALARM_122_HEIGHT 2
extern unsigned char code _fault_alarm_122[];

#define _FAULT_ALARM_123_WIDTH  22
#define _FAULT_ALARM_123_HEIGHT 2
extern unsigned char code _fault_alarm_123[];

#define _FAULT_ALARM_124_WIDTH  22
#define _FAULT_ALARM_124_HEIGHT 2
extern unsigned char code _fault_alarm_124[];

#define _FAULT_ALARM_125_WIDTH  22
#define _FAULT_ALARM_125_HEIGHT 2
extern unsigned char code _fault_alarm_125[];

#define _FAULT_ALARM_126_WIDTH  22
#define _FAULT_ALARM_126_HEIGHT 2
extern unsigned char code _fault_alarm_126[];

#define _FAULT_ALARM_127_WIDTH  22
#define _FAULT_ALARM_127_HEIGHT 2
extern unsigned char code _fault_alarm_127[];

#define _FAULT_ALARM_128_WIDTH  22
#define _FAULT_ALARM_128_HEIGHT 2
extern unsigned char code _fault_alarm_128[];

#define _FAULT_ALARM_129_WIDTH  22
#define _FAULT_ALARM_129_HEIGHT 2
extern unsigned char code _fault_alarm_129[];

#define _FAULT_ALARM_130_WIDTH  22
#define _FAULT_ALARM_130_HEIGHT 2
extern unsigned char code _fault_alarm_130[];

#define _FAULT_ALARM_131_WIDTH  22
#define _FAULT_ALARM_131_HEIGHT 2
extern unsigned char code _fault_alarm_131[];

#define _FAULT_ALARM_132_WIDTH  22
#define _FAULT_ALARM_132_HEIGHT 2
extern unsigned char code _fault_alarm_132[];

#define _FAULT_ALARM_133_WIDTH  22
#define _FAULT_ALARM_133_HEIGHT 2
extern unsigned char code _fault_alarm_133[];

#define _FAULT_ALARM_134_WIDTH  22
#define _FAULT_ALARM_134_HEIGHT 2
extern unsigned char code _fault_alarm_134[];

#define _FAULT_ALARM_135_WIDTH  22
#define _FAULT_ALARM_135_HEIGHT 2
extern unsigned char code _fault_alarm_135[];

#define _FAULT_ALARM_136_WIDTH  22
#define _FAULT_ALARM_136_HEIGHT 2
extern unsigned char code _fault_alarm_136[];

#define _FAULT_ALARM_137_WIDTH  22
#define _FAULT_ALARM_137_HEIGHT 2
extern unsigned char code _fault_alarm_137[];

#define _FAULT_ALARM_138_WIDTH  22
#define _FAULT_ALARM_138_HEIGHT 2
extern unsigned char code _fault_alarm_138[];

#define _FAULT_ALARM_139_WIDTH  22
#define _FAULT_ALARM_139_HEIGHT 2
extern unsigned char code _fault_alarm_139[];

#define _FAULT_ALARM_140_WIDTH  22
#define _FAULT_ALARM_140_HEIGHT 2
extern unsigned char code _fault_alarm_140[];

#define _FAULT_ALARM_141_WIDTH  22
#define _FAULT_ALARM_141_HEIGHT 2
extern unsigned char code _fault_alarm_141[];

#define _FAULT_ALARM_142_WIDTH  22
#define _FAULT_ALARM_142_HEIGHT 2
extern unsigned char code _fault_alarm_142[];

#define _FAULT_ALARM_143_WIDTH  22
#define _FAULT_ALARM_143_HEIGHT 2
extern unsigned char code _fault_alarm_143[];

#define _FAULT_ALARM_144_WIDTH  22
#define _FAULT_ALARM_144_HEIGHT 2
extern unsigned char code _fault_alarm_144[];

#define _FAULT_ALARM_145_WIDTH  22
#define _FAULT_ALARM_145_HEIGHT 2
extern unsigned char code _fault_alarm_145[];

#define _FAULT_ALARM_146_WIDTH  22
#define _FAULT_ALARM_146_HEIGHT 2
extern unsigned char code _fault_alarm_146[];

#define _FAULT_ALARM_147_WIDTH  22
#define _FAULT_ALARM_147_HEIGHT 2
extern unsigned char code _fault_alarm_147[];

#define _FAULT_ALARM_148_WIDTH  22
#define _FAULT_ALARM_148_HEIGHT 2
extern unsigned char code _fault_alarm_148[];

#define _FAULT_ALARM_149_WIDTH  22
#define _FAULT_ALARM_149_HEIGHT 2
extern unsigned char code _fault_alarm_149[];

#define _FAULT_ALARM_150_WIDTH  22
#define _FAULT_ALARM_150_HEIGHT 2
extern unsigned char code _fault_alarm_150[];

#define _FAULT_ALARM_151_WIDTH  22
#define _FAULT_ALARM_151_HEIGHT 2
extern unsigned char code _fault_alarm_151[];

#define _FAULT_ALARM_152_WIDTH  22
#define _FAULT_ALARM_152_HEIGHT 2
extern unsigned char code _fault_alarm_152[];

#define _FAULT_ALARM_153_WIDTH  22
#define _FAULT_ALARM_153_HEIGHT 2
extern unsigned char code _fault_alarm_153[];

#define _FAULT_ALARM_154_WIDTH  22
#define _FAULT_ALARM_154_HEIGHT 2
extern unsigned char code _fault_alarm_154[];

#define _FAULT_ALARM_155_WIDTH  22
#define _FAULT_ALARM_155_HEIGHT 2
extern unsigned char code _fault_alarm_155[];

#define _FAULT_ALARM_156_WIDTH  22
#define _FAULT_ALARM_156_HEIGHT 2
extern unsigned char code _fault_alarm_156[];

#define _FAULT_ALARM_157_WIDTH  22
#define _FAULT_ALARM_157_HEIGHT 2
extern unsigned char code _fault_alarm_157[];

#define _FAULT_ALARM_158_WIDTH  22
#define _FAULT_ALARM_158_HEIGHT 2
extern unsigned char code _fault_alarm_158[];

#define _FAULT_ALARM_159_WIDTH  22
#define _FAULT_ALARM_159_HEIGHT 2
extern unsigned char code _fault_alarm_159[];

#define _FAULT_ALARM_160_WIDTH  18
#define _FAULT_ALARM_160_HEIGHT 2
extern unsigned char code _fault_alarm_160[];

#define _FAULT_ALARM_161_WIDTH  18
#define _FAULT_ALARM_161_HEIGHT 2
extern unsigned char code _fault_alarm_161[];

#define _FAULT_ALARM_162_WIDTH  18
#define _FAULT_ALARM_162_HEIGHT 2
extern unsigned char code _fault_alarm_162[];

#define _FAULT_ALARM_163_WIDTH  18
#define _FAULT_ALARM_163_HEIGHT 2
extern unsigned char code _fault_alarm_163[];

#define _FAULT_ALARM_164_WIDTH  18
#define _FAULT_ALARM_164_HEIGHT 2
extern unsigned char code _fault_alarm_164[];

#define _FAULT_ALARM_165_WIDTH  18
#define _FAULT_ALARM_165_HEIGHT 2
extern unsigned char code _fault_alarm_165[];

#define _FAULT_ALARM_166_WIDTH  18
#define _FAULT_ALARM_166_HEIGHT 2
extern unsigned char code _fault_alarm_166[];

#define _FAULT_ALARM_167_WIDTH  18
#define _FAULT_ALARM_167_HEIGHT 2
extern unsigned char code _fault_alarm_167[];

#define _FAULT_ALARM_168_WIDTH  18
#define _FAULT_ALARM_168_HEIGHT 2
extern unsigned char code _fault_alarm_168[];

#define _FAULT_ALARM_169_WIDTH  20
#define _FAULT_ALARM_169_HEIGHT 2
extern unsigned char code _fault_alarm_169[];

#define _FAULT_ALARM_170_WIDTH  22
#define _FAULT_ALARM_170_HEIGHT 2
extern unsigned char code _fault_alarm_170[];

#define _FAULT_ALARM_171_WIDTH  22
#define _FAULT_ALARM_171_HEIGHT 2
extern unsigned char code _fault_alarm_171[];

#define _FAULT_ALARM_172_WIDTH  22
#define _FAULT_ALARM_172_HEIGHT 2
extern unsigned char code _fault_alarm_172[];

#define _FAULT_ALARM_173_WIDTH  22
#define _FAULT_ALARM_173_HEIGHT 2
extern unsigned char code _fault_alarm_173[];

#define _FAULT_ALARM_174_WIDTH  22
#define _FAULT_ALARM_174_HEIGHT 2
extern unsigned char code _fault_alarm_174[];

#define _FAULT_ALARM_175_WIDTH  22
#define _FAULT_ALARM_175_HEIGHT 2
extern unsigned char code _fault_alarm_175[];

#define _FAULT_ALARM_176_WIDTH  22
#define _FAULT_ALARM_176_HEIGHT 2
extern unsigned char code _fault_alarm_176[];

#define _FAULT_ALARM_177_WIDTH  22
#define _FAULT_ALARM_177_HEIGHT 2
extern unsigned char code _fault_alarm_177[];

#define _FAULT_ALARM_178_WIDTH  14
#define _FAULT_ALARM_178_HEIGHT 2
extern unsigned char code _fault_alarm_178[];

#define _FAULT_ALARM_179_WIDTH  16
#define _FAULT_ALARM_179_HEIGHT 2
extern unsigned char code _fault_alarm_179[];

#define _FAULT_ALARM_180_WIDTH  14
#define _FAULT_ALARM_180_HEIGHT 2
extern unsigned char code _fault_alarm_180[];

#define _FAULT_ALARM_181_WIDTH  14
#define _FAULT_ALARM_181_HEIGHT 2
extern unsigned char code _fault_alarm_181[];

#define _FAULT_ALARM_182_WIDTH  14
#define _FAULT_ALARM_182_HEIGHT 2
extern unsigned char code _fault_alarm_182[];

#define _FAULT_ALARM_183_WIDTH  14
#define _FAULT_ALARM_183_HEIGHT 2
extern unsigned char code _fault_alarm_183[];

#define _FAULT_ALARM_184_WIDTH  22
#define _FAULT_ALARM_184_HEIGHT 2
extern unsigned char code _fault_alarm_184[];

#define _OFF_WIDTH  3
#define _OFF_HEIGHT 1
extern unsigned char code _off[];

#define _ON_WIDTH  3
#define _ON_HEIGHT 1
extern unsigned char code _on[];

#define _YUUNXING_WIDTH  3
#define _YUUNXING_HEIGHT 1
extern unsigned char code _yuunxing[];

#define _S1_D_WIDTH  3
#define _S1_D_HEIGHT 1
extern unsigned char code _s1_d[];

#define _S1_D1_WIDTH  3
#define _S1_D1_HEIGHT 1
extern unsigned char code _s1_d1[];

#define _S1_D2_WIDTH  3
#define _S1_D2_HEIGHT 1
extern unsigned char code _s1_d2[];

#define _S1_D3_WIDTH  3
#define _S1_D3_HEIGHT 1
extern unsigned char code _s1_d3[];

#define _S1_D4_WIDTH  3
#define _S1_D4_HEIGHT 1
extern unsigned char code _s1_d4[];

#define _S1_D5_WIDTH  3
#define _S1_D5_HEIGHT 1
extern unsigned char code _s1_d5[];

#define _S1_D6_WIDTH  3
#define _S1_D6_HEIGHT 1
extern unsigned char code _s1_d6[];

#define _S1_D7_WIDTH  3
#define _S1_D7_HEIGHT 1
extern unsigned char code _s1_d7[];

#define _S1_D8_WIDTH  3
#define _S1_D8_HEIGHT 1
extern unsigned char code _s1_d8[];

#define _S1_D9_WIDTH  3
#define _S1_D9_HEIGHT 1
extern unsigned char code _s1_d9[];

#define _S1_D10_WIDTH  3
#define _S1_D10_HEIGHT 1
extern unsigned char code _s1_d10[];

#define _S1_D11_WIDTH  3
#define _S1_D11_HEIGHT 1
extern unsigned char code _s1_d11[];

#define _S1_D12_WIDTH  3
#define _S1_D12_HEIGHT 1
extern unsigned char code _s1_d12[];

#define _S1_N_WIDTH  3
#define _S1_N_HEIGHT 1
extern unsigned char code _s1_n[];

#define _S1_P_WIDTH  3
#define _S1_P_HEIGHT 1
extern unsigned char code _s1_p[];

#define _S1_R_WIDTH  3
#define _S1_R_HEIGHT 1
extern unsigned char code _s1_r[];

#define _S16_TINGJI_WIDTH  3
#define _S16_TINGJI_HEIGHT 1
extern unsigned char code _s16_tingji[];

#define _WUXIAO_WIDTH  3
#define _WUXIAO_HEIGHT 1
extern unsigned char code _wuxiao[];

#define _YOUXIAO_WIDTH  3
#define _YOUXIAO_HEIGHT 1
extern unsigned char code _youxiao[];

#define _GZ_WIDTH  3
#define _GZ_HEIGHT 1
extern unsigned char code _gz[];

#define _TINGJI_WIDTH  3
#define _TINGJI_HEIGHT 1
extern unsigned char code _tingji[];

#define _WEITINGJI_WIDTH  4
#define _WEITINGJI_HEIGHT 1
extern unsigned char code _weitingji[];

#define _YITINGJI_WIDTH  4
#define _YITINGJI_HEIGHT 1
extern unsigned char code _yitingji[];

#define _S1_CHADIAN_WIDTH  3
#define _S1_CHADIAN_HEIGHT 1
extern unsigned char code _s1_chadian[];

#define _S1_CHUNDIAN_WIDTH  3
#define _S1_CHUNDIAN_HEIGHT 1
extern unsigned char code _s1_chundian[];

#define _S1_HUNDONG_WIDTH  3
#define _S1_HUNDONG_HEIGHT 1
extern unsigned char code _s1_hundong[];

#define _DIYA_WIDTH  3
#define _DIYA_HEIGHT 1
extern unsigned char code _diya[];

#define _GAOYA_WIDTH  3
#define _GAOYA_HEIGHT 1
extern unsigned char code _gaoya[];

#define _S1_KUAICHONG_WIDTH  3
#define _S1_KUAICHONG_HEIGHT 1
extern unsigned char code _s1_kuaichong[];

#define _S1_MANCHONG_WIDTH  3
#define _S1_MANCHONG_HEIGHT 1
extern unsigned char code _s1_manchong[];

#define _S1_ZIJIAN_WIDTH  3
#define _S1_ZIJIAN_HEIGHT 1
extern unsigned char code _s1_zijian[];

#define _ERJIGZ_WIDTH  6
#define _ERJIGZ_HEIGHT 1
extern unsigned char code _erjigz[];

#define _SANJIGZ_WIDTH  6
#define _SANJIGZ_HEIGHT 1
extern unsigned char code _sanjigz[];

#define _YIJIGZ_WIDTH  6
#define _YIJIGZ_HEIGHT 1
extern unsigned char code _yijigz[];

#define _S20_G1_CAN_WIDTH  9
#define _S20_G1_CAN_HEIGHT 1
extern unsigned char code _s20_g1_can[];

#define _S20_G1_CHUANGANQI_WIDTH  9
#define _S20_G1_CHUANGANQI_HEIGHT 1
extern unsigned char code _s20_g1_chuanganqi[];

#define _S20_G1_EBS_WIDTH  9
#define _S20_G1_EBS_HEIGHT 1
extern unsigned char code _s20_g1_ebs[];

#define _S20_G1_FADIAN_WIDTH  9
#define _S20_G1_FADIAN_HEIGHT 1
extern unsigned char code _s20_g1_fadian[];

#define _S20_G1_JINQI_WIDTH  9
#define _S20_G1_JINQI_HEIGHT 1
extern unsigned char code _s20_g1_jinqi[];

#define _S20_G1_KAIGUAN_WIDTH  9
#define _S20_G1_KAIGUAN_HEIGHT 1
extern unsigned char code _s20_g1_kaiguan[];

#define _S20_G1_MOKUAI_WIDTH  9
#define _S20_G1_MOKUAI_HEIGHT 1
extern unsigned char code _s20_g1_mokuai[];

#define _S20_G1_PAIQI_WIDTH  9
#define _S20_G1_PAIQI_HEIGHT 1
extern unsigned char code _s20_g1_paiqi[];

#define _S20_G1_ZHIDONG_WIDTH  9
#define _S20_G1_ZHIDONG_HEIGHT 1
extern unsigned char code _s20_g1_zhidong[];

#define _S3_DAIJI_WIDTH  3
#define _S3_DAIJI_HEIGHT 1
extern unsigned char code _s3_daiji[];

#define _S3_YUNXING_WIDTH  3
#define _S3_YUNXING_HEIGHT 1
extern unsigned char code _s3_yunxing[];

#define _S20_G2_CANDUANLU_WIDTH  8
#define _S20_G2_CANDUANLU_HEIGHT 1
extern unsigned char code _s20_g2_canduanlu[];

#define _S20_G2_CHUANGANQI_WIDTH  8
#define _S20_G2_CHUANGANQI_HEIGHT 1
extern unsigned char code _s20_g2_chuanganqi[];

#define _S20_G2_DI_WIDTH  8
#define _S20_G2_DI_HEIGHT 1
extern unsigned char code _s20_g2_di[];

#define _S20_G2_DIANYADI_WIDTH  8
#define _S20_G2_DIANYADI_HEIGHT 1
extern unsigned char code _s20_g2_dianyadi[];

#define _S20_G2_DIANYAGAO_WIDTH  8
#define _S20_G2_DIANYAGAO_HEIGHT 1
extern unsigned char code _s20_g2_dianyagao[];

#define _S20_G2_DIANYUAN_WIDTH  8
#define _S20_G2_DIANYUAN_HEIGHT 1
extern unsigned char code _s20_g2_dianyuan[];

#define _S20_G2_DIUSHI_WIDTH  8
#define _S20_G2_DIUSHI_HEIGHT 1
extern unsigned char code _s20_g2_diushi[];

#define _S20_G2_DUANLU_WIDTH  8
#define _S20_G2_DUANLU_HEIGHT 1
extern unsigned char code _s20_g2_duanlu[];

#define _S20_G2_EBS_WIDTH  8
#define _S20_G2_EBS_HEIGHT 1
extern unsigned char code _s20_g2_ebs[];

#define _S20_G2_FATI_WIDTH  8
#define _S20_G2_FATI_HEIGHT 1
extern unsigned char code _s20_g2_fati[];

#define _S20_G2_KAIGUAN_WIDTH  8
#define _S20_G2_KAIGUAN_HEIGHT 1
extern unsigned char code _s20_g2_kaiguan[];

#define _S20_G2_THREE_WIDTH  8
#define _S20_G2_THREE_HEIGHT 1
extern unsigned char code _s20_g2_three[];

#define _GUZHANG_WIDTH  3
#define _GUZHANG_HEIGHT 1
extern unsigned char code _guzhang[];

#define _ZHENGCHANG_WIDTH  3
#define _ZHENGCHANG_HEIGHT 1
extern unsigned char code _zhengchang[];

#define _GUANBI_WIDTH  3
#define _GUANBI_HEIGHT 1
extern unsigned char code _guanbi[];

#define _QIDONG_WIDTH  3
#define _QIDONG_HEIGHT 1
extern unsigned char code _qidong[];

#define _FAULT_NUMBER_0_WIDTH  1
#define _FAULT_NUMBER_0_HEIGHT 2
extern unsigned char code _fault_number_0[];

#define _FAULT_NUMBER_1_WIDTH  1
#define _FAULT_NUMBER_1_HEIGHT 2
extern unsigned char code _fault_number_1[];

#define _FAULT_NUMBER_2_WIDTH  1
#define _FAULT_NUMBER_2_HEIGHT 2
extern unsigned char code _fault_number_2[];

#define _FAULT_NUMBER_3_WIDTH  1
#define _FAULT_NUMBER_3_HEIGHT 2
extern unsigned char code _fault_number_3[];

#define _FAULT_NUMBER_4_WIDTH  1
#define _FAULT_NUMBER_4_HEIGHT 2
extern unsigned char code _fault_number_4[];

#define _FAULT_NUMBER_5_WIDTH  1
#define _FAULT_NUMBER_5_HEIGHT 2
extern unsigned char code _fault_number_5[];

#define _FAULT_NUMBER_6_WIDTH  1
#define _FAULT_NUMBER_6_HEIGHT 2
extern unsigned char code _fault_number_6[];

#define _FAULT_NUMBER_7_WIDTH  1
#define _FAULT_NUMBER_7_HEIGHT 2
extern unsigned char code _fault_number_7[];

#define _FAULT_NUMBER_8_WIDTH  1
#define _FAULT_NUMBER_8_HEIGHT 2
extern unsigned char code _fault_number_8[];

#define _FAULT_NUMBER_9_WIDTH  1
#define _FAULT_NUMBER_9_HEIGHT 2
extern unsigned char code _fault_number_9[];

#define _S9_READY_WIDTH  4
#define _S9_READY_HEIGHT 1
extern unsigned char code _s9_ready[];

#define _ALARM_POS_0_WIDTH  4
#define _ALARM_POS_0_HEIGHT 2
extern unsigned char code _alarm_pos_0[];

#define _ALARM_POS_1_WIDTH  4
#define _ALARM_POS_1_HEIGHT 2
extern unsigned char code _alarm_pos_1[];

#define _ALARM_POS_2_WIDTH  6
#define _ALARM_POS_2_HEIGHT 2
extern unsigned char code _alarm_pos_2[];

#define _ALARM_POS_3_WIDTH  6
#define _ALARM_POS_3_HEIGHT 2
extern unsigned char code _alarm_pos_3[];

#define _ALARM_POS_4_WIDTH  6
#define _ALARM_POS_4_HEIGHT 2
extern unsigned char code _alarm_pos_4[];

#define _ALARM_POS_5_WIDTH  6
#define _ALARM_POS_5_HEIGHT 2
extern unsigned char code _alarm_pos_5[];

#define _FAULT_ALARM_185_WIDTH  19
#define _FAULT_ALARM_185_HEIGHT 2
extern unsigned char code _fault_alarm_185[];

#define _FAULT_ALARM_186_WIDTH  19
#define _FAULT_ALARM_186_HEIGHT 2
extern unsigned char code _fault_alarm_186[];

#define _FAULT_ALARM_187_WIDTH  19
#define _FAULT_ALARM_187_HEIGHT 2
extern unsigned char code _fault_alarm_187[];

#define _FAULT_ALARM_188_WIDTH  19
#define _FAULT_ALARM_188_HEIGHT 2
extern unsigned char code _fault_alarm_188[];

#define _FAULT_ALARM_189_WIDTH  19
#define _FAULT_ALARM_189_HEIGHT 2
extern unsigned char code _fault_alarm_189[];

#define _FAULT_ALARM_190_WIDTH  19
#define _FAULT_ALARM_190_HEIGHT 2
extern unsigned char code _fault_alarm_190[];

#define _FAULT_ALARM_191_WIDTH  19
#define _FAULT_ALARM_191_HEIGHT 2
extern unsigned char code _fault_alarm_191[];

#define _FAULT_ALARM_192_WIDTH  19
#define _FAULT_ALARM_192_HEIGHT 2
extern unsigned char code _fault_alarm_192[];

#define _FAULT_ALARM_193_WIDTH  19
#define _FAULT_ALARM_193_HEIGHT 2
extern unsigned char code _fault_alarm_193[];

#define _FAULT_ALARM_194_WIDTH  20
#define _FAULT_ALARM_194_HEIGHT 2
extern unsigned char code _fault_alarm_194[];

#define _FAULT_ALARM_195_WIDTH  10
#define _FAULT_ALARM_195_HEIGHT 2
extern unsigned char code _fault_alarm_195[];

#define _FAULT_ALARM_196_WIDTH  10
#define _FAULT_ALARM_196_HEIGHT 2
extern unsigned char code _fault_alarm_196[];

#define _FAULT_ALARM_197_WIDTH  10
#define _FAULT_ALARM_197_HEIGHT 2
extern unsigned char code _fault_alarm_197[];

#define _FAULT_ALARM_198_WIDTH  14
#define _FAULT_ALARM_198_HEIGHT 2
extern unsigned char code _fault_alarm_198[];

#define _FAULT_ALARM_199_WIDTH  8
#define _FAULT_ALARM_199_HEIGHT 2
extern unsigned char code _fault_alarm_199[];

#define _BIHE_WIDTH  3
#define _BIHE_HEIGHT 1
extern unsigned char code _bihe[];

#define _DUANKAI_WIDTH  3
#define _DUANKAI_HEIGHT 1
extern unsigned char code _duankai[];

#define _ICON_DUMMY_W16_H24_2BP_WIDTH  1
#define _ICON_DUMMY_W16_H24_2BP_HEIGHT 1
extern unsigned char code _icon_dummy_w16_h24_2bp[];

#define _ARROWS_WIDTH  2
#define _ARROWS_HEIGHT 1
extern unsigned char code _arrows[];

#define _FAULT_FLAG_RED_WIDTH  3
#define _FAULT_FLAG_RED_HEIGHT 2
extern unsigned char code _fault_flag_red[];

#define _STATUS_GREEN_WIDTH  2
#define _STATUS_GREEN_HEIGHT 1
extern unsigned char code _status_green[];

#define _STATUS_RED_WIDTH  2
#define _STATUS_RED_HEIGHT 1
extern unsigned char code _status_red[];

#define _MARK_D_WIDTH  3
#define _MARK_D_HEIGHT 2
extern unsigned char code _mark_d[];

#define _MARK_D1_WIDTH  3
#define _MARK_D1_HEIGHT 2
extern unsigned char code _mark_d1[];

#define _MARK_D2_WIDTH  3
#define _MARK_D2_HEIGHT 2
extern unsigned char code _mark_d2[];

#define _MARK_D3_WIDTH  3
#define _MARK_D3_HEIGHT 2
extern unsigned char code _mark_d3[];

#define _MARK_D4_WIDTH  3
#define _MARK_D4_HEIGHT 2
extern unsigned char code _mark_d4[];

#define _MARK_D5_WIDTH  3
#define _MARK_D5_HEIGHT 2
extern unsigned char code _mark_d5[];

#define _MARK_D6_WIDTH  3
#define _MARK_D6_HEIGHT 2
extern unsigned char code _mark_d6[];

#define _MARK_D7_WIDTH  3
#define _MARK_D7_HEIGHT 2
extern unsigned char code _mark_d7[];

#define _MARK_D8_WIDTH  3
#define _MARK_D8_HEIGHT 2
extern unsigned char code _mark_d8[];

#define _MARK_D9_WIDTH  3
#define _MARK_D9_HEIGHT 2
extern unsigned char code _mark_d9[];

#define _MARK_D10_WIDTH  3
#define _MARK_D10_HEIGHT 2
extern unsigned char code _mark_d10[];

#define _MARK_D11_WIDTH  3
#define _MARK_D11_HEIGHT 2
extern unsigned char code _mark_d11[];

#define _MARK_D12_WIDTH  3
#define _MARK_D12_HEIGHT 2
extern unsigned char code _mark_d12[];

#define _MARK_N_WIDTH  3
#define _MARK_N_HEIGHT 2
extern unsigned char code _mark_n[];

#define _MARK_R_WIDTH  3
#define _MARK_R_HEIGHT 2
extern unsigned char code _mark_r[];

#define _MARK_BAI_WIDTH  3
#define _MARK_BAI_HEIGHT 2
extern unsigned char code _mark_bai[];

#define _MARK_HONG_WIDTH  3
#define _MARK_HONG_HEIGHT 2
extern unsigned char code _mark_hong[];

#define _MARK_R_STOP_WIDTH  3
#define _MARK_R_STOP_HEIGHT 2
extern unsigned char code _mark_r_stop[];

#define _MARK_Y_STOP_WIDTH  3
#define _MARK_Y_STOP_HEIGHT 2
extern unsigned char code _mark_y_stop[];

#define _DOOR_CLOSE_0_WIDTH  3
#define _DOOR_CLOSE_0_HEIGHT 3
extern unsigned char code _door_close_0[];

#define _DOOR_OPEN_0_WIDTH  3
#define _DOOR_OPEN_0_HEIGHT 3
extern unsigned char code _door_open_0[];

#define _DOOR_CLOSE_1_WIDTH  4
#define _DOOR_CLOSE_1_HEIGHT 5
extern unsigned char code _door_close_1[];

#define _DOOR_OPEN_1_WIDTH  4
#define _DOOR_OPEN_1_HEIGHT 5
extern unsigned char code _door_open_1[];

#define _DOOR_CLOSE_2_WIDTH  4
#define _DOOR_CLOSE_2_HEIGHT 4
extern unsigned char code _door_close_2[];

#define _DOOR_OPEN_2_WIDTH  4
#define _DOOR_OPEN_2_HEIGHT 4
extern unsigned char code _door_open_2[];

#define _ICON_DUMMY_W16_H24_4BP_WIDTH  1
#define _ICON_DUMMY_W16_H24_4BP_HEIGHT 1
extern unsigned char code _icon_dummy_w16_h24_4bp[];

