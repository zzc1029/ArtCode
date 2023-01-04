/*
 * MeterConfig.h
 *
 *  Created on: 2021-9-8
 *  仪表配置信息等处理
 *      Author: ART
 */


#ifndef _METERCONFIG_H_
#define _METERCONFIG_H_


#define  Mask_A10	    port_mask.tb[0].bit.b0
#define  Mask_A09	    port_mask.tb[0].bit.b1  
#define  Mask_A08	    port_mask.tb[0].bit.b2  
#define  Mask_A07	    port_mask.tb[0].bit.b3  
#define  Mask_C20	    port_mask.tb[0].bit.b4  
#define  Mask_A19	    port_mask.tb[0].bit.b5
#define  Mask_A18	    port_mask.tb[0].bit.b6  
#define  Mask_A17	    port_mask.tb[0].bit.b7  

#define  Mask_D02	    port_mask.tb[1].bit.b0  
#define  Mask_D10	    port_mask.tb[1].bit.b1  
#define  Mask_D01	    port_mask.tb[1].bit.b2  
#define  Mask_D09	    port_mask.tb[1].bit.b3 
#define  Mask_C13	    port_mask.tb[1].bit.b4  
#define  Mask_C12	    port_mask.tb[1].bit.b5  
#define  Mask_C11	    port_mask.tb[1].bit.b6  
#define  Mask_C10	    port_mask.tb[1].bit.b7

#define  Mask_D06	    port_mask.tb[2].bit.b0 
#define  Mask_D14	    port_mask.tb[2].bit.b1 
#define  Mask_D05	    port_mask.tb[2].bit.b2  
#define  Mask_D13	    port_mask.tb[2].bit.b3  
#define  Mask_D04	    port_mask.tb[2].bit.b4  
#define  Mask_D12	    port_mask.tb[2].bit.b5  
#define  Mask_D03	    port_mask.tb[2].bit.b6  
#define  Mask_D11	    port_mask.tb[2].bit.b7 

#define  Mask_B02	    port_mask.tb[3].bit.b0 
#define  Mask_B08	    port_mask.tb[3].bit.b1  
#define  Mask_B01	    port_mask.tb[3].bit.b2  
#define  Mask_B07	    port_mask.tb[3].bit.b3  
#define  Mask_D08	    port_mask.tb[3].bit.b4  
#define  Mask_D16	    port_mask.tb[3].bit.b5  
#define  Mask_D07	    port_mask.tb[3].bit.b6  
#define  Mask_D15	    port_mask.tb[3].bit.b7  

#define  Mask_B06	    port_mask.tb[4].bit.b0 
#define  Mask_B12	    port_mask.tb[4].bit.b1  
#define  Mask_B05	    port_mask.tb[4].bit.b2  
#define  Mask_B11	    port_mask.tb[4].bit.b3  
#define  Mask_B04	    port_mask.tb[4].bit.b4  
#define  Mask_B10	    port_mask.tb[4].bit.b5  
#define  Mask_B03	    port_mask.tb[4].bit.b6  
#define  Mask_B09	    port_mask.tb[4].bit.b7


//符号片定义  BYTE0 BIT7 开始  BIT0结束
#define SYMBOL_POSITION00   	  DisplaySymbol[0].bit.b7    
#define SYMBOL_POSITION01         DisplaySymbol[0].bit.b6    
#define SYMBOL_POSITION02         DisplaySymbol[0].bit.b5    
#define SYMBOL_POSITION03         DisplaySymbol[0].bit.b4    
#define SYMBOL_POSITION04         DisplaySymbol[0].bit.b3    
#define SYMBOL_POSITION05         DisplaySymbol[0].bit.b2    
#define SYMBOL_POSITION06         DisplaySymbol[0].bit.b1    
#define SYMBOL_POSITION07         DisplaySymbol[0].bit.b0  

#define SYMBOL_POSITION08   	  DisplaySymbol[1].bit.b7    
#define SYMBOL_POSITION09         DisplaySymbol[1].bit.b6    
#define SYMBOL_POSITION10         DisplaySymbol[1].bit.b5    
#define SYMBOL_POSITION11         DisplaySymbol[1].bit.b4    
#define SYMBOL_POSITION12         DisplaySymbol[1].bit.b3    
#define SYMBOL_POSITION13         DisplaySymbol[1].bit.b2    
#define SYMBOL_POSITION14         DisplaySymbol[1].bit.b1    
#define SYMBOL_POSITION15         DisplaySymbol[1].bit.b0 

#define SYMBOL_POSITION16   	  DisplaySymbol[2].bit.b7    
#define SYMBOL_POSITION17         DisplaySymbol[2].bit.b6    
#define SYMBOL_POSITION18         DisplaySymbol[2].bit.b5    
#define SYMBOL_POSITION19         DisplaySymbol[2].bit.b4    
#define SYMBOL_POSITION20         DisplaySymbol[2].bit.b3    
#define SYMBOL_POSITION21         DisplaySymbol[2].bit.b2    
#define SYMBOL_POSITION22         DisplaySymbol[2].bit.b1    
#define SYMBOL_POSITION23         DisplaySymbol[2].bit.b0 

#define SYMBOL_POSITION24   	  DisplaySymbol[3].bit.b7    
#define SYMBOL_POSITION25         DisplaySymbol[3].bit.b6    
#define SYMBOL_POSITION26         DisplaySymbol[3].bit.b5    
#define SYMBOL_POSITION27         DisplaySymbol[3].bit.b4    
#define SYMBOL_POSITION28         DisplaySymbol[3].bit.b3    
#define SYMBOL_POSITION29         DisplaySymbol[3].bit.b2    
#define SYMBOL_POSITION30         DisplaySymbol[3].bit.b1    
#define SYMBOL_POSITION31         DisplaySymbol[3].bit.b0 

#define SYMBOL_POSITION32   	  DisplaySymbol[4].bit.b7    
#define SYMBOL_POSITION33         DisplaySymbol[4].bit.b6    
#define SYMBOL_POSITION34         DisplaySymbol[4].bit.b5    
#define SYMBOL_POSITION35         DisplaySymbol[4].bit.b4    
#define SYMBOL_POSITION36         DisplaySymbol[4].bit.b3    
#define SYMBOL_POSITION37         DisplaySymbol[4].bit.b2    
#define SYMBOL_POSITION38         DisplaySymbol[4].bit.b1    
#define SYMBOL_POSITION39         DisplaySymbol[4].bit.b0 

#define SYMBOL_POSITION40   	  DisplaySymbol[5].bit.b7    
#define SYMBOL_POSITION41         DisplaySymbol[5].bit.b6    
#define SYMBOL_POSITION42         DisplaySymbol[5].bit.b5    
#define SYMBOL_POSITION43         DisplaySymbol[5].bit.b4    
#define SYMBOL_POSITION44         DisplaySymbol[5].bit.b3    
#define SYMBOL_POSITION45         DisplaySymbol[5].bit.b2    
#define SYMBOL_POSITION46         DisplaySymbol[5].bit.b1    
#define SYMBOL_POSITION47         DisplaySymbol[5].bit.b0 

#define SYMBOL_POSITION48   	  DisplaySymbol[6].bit.b7    
#define SYMBOL_POSITION49         DisplaySymbol[6].bit.b6    
#define SYMBOL_POSITION50         DisplaySymbol[6].bit.b5    
#define SYMBOL_POSITION51         DisplaySymbol[6].bit.b4    
#define SYMBOL_POSITION52         DisplaySymbol[6].bit.b3    
#define SYMBOL_POSITION53         DisplaySymbol[6].bit.b2    
#define SYMBOL_POSITION54         DisplaySymbol[6].bit.b1    
#define SYMBOL_POSITION55         DisplaySymbol[6].bit.b0 

#define SYMBOL_POSITION56   	  DisplaySymbol[7].bit.b7    
#define SYMBOL_POSITION57         DisplaySymbol[7].bit.b6    
#define SYMBOL_POSITION58         DisplaySymbol[7].bit.b5    
#define SYMBOL_POSITION59         DisplaySymbol[7].bit.b4    
#define SYMBOL_POSITION60         DisplaySymbol[7].bit.b3    
#define SYMBOL_POSITION61         DisplaySymbol[7].bit.b2    
#define SYMBOL_POSITION62         DisplaySymbol[7].bit.b1    
#define SYMBOL_POSITION63         DisplaySymbol[7].bit.b0 

/*	send control command to BCM	*/
#define F_OUT_P1                      ctrl_cmd[0].bit.b0
#define F_OUT_P9                      ctrl_cmd[0].bit.b1
#define F_OUT_P2                      ctrl_cmd[0].bit.b2
#define F_OUT_P10                     ctrl_cmd[0].bit.b3
#define F_OUT_P3                      ctrl_cmd[0].bit.b4
#define F_OUT_P11                     ctrl_cmd[0].bit.b5
#define F_OUT_P4                      ctrl_cmd[0].bit.b6
#define F_OUT_P12                     ctrl_cmd[0].bit.b7
#define F_OUT_P5                      ctrl_cmd[1].bit.b0
#define F_OUT_P13                    ctrl_cmd[1].bit.b1
#define F_OUT_P6                     ctrl_cmd[1].bit.b2
#define F_OUT_P14                    ctrl_cmd[1].bit.b3
#define F_OUT_P7                     ctrl_cmd[1].bit.b4
#define F_OUT_P42                    ctrl_cmd[1].bit.b5
#define F_OUT_P8                     ctrl_cmd[1].bit.b6
#define F_OUT_P17                    ctrl_cmd[1].bit.b7  /////

#define R_OUT_P1                      ctrl_cmd[2].bit.b0
#define R_OUT_P9                      ctrl_cmd[2].bit.b1
#define R_OUT_P2                      ctrl_cmd[2].bit.b2
#define R_OUT_P10                     ctrl_cmd[2].bit.b3
#define R_OUT_P3                      ctrl_cmd[2].bit.b4
#define R_OUT_P11                     ctrl_cmd[2].bit.b5
#define R_OUT_P4                      ctrl_cmd[2].bit.b6
#define R_OUT_P12                     ctrl_cmd[2].bit.b7
#define R_OUT_P5                      ctrl_cmd[3].bit.b0
#define R_OUT_P13                    ctrl_cmd[3].bit.b1
#define R_OUT_P6                     ctrl_cmd[3].bit.b2
#define R_OUT_P14                    ctrl_cmd[3].bit.b3
#define R_OUT_P7                     ctrl_cmd[3].bit.b4
#define R_OUT_P42                    ctrl_cmd[3].bit.b5
#define R_OUT_P8                     ctrl_cmd[3].bit.b6
#define R_OUT_P17                    ctrl_cmd[3].bit.b7 /////

#define T_OUT_P1                      ctrl_cmd[4].bit.b0
#define T_OUT_P9                      ctrl_cmd[4].bit.b1
#define T_OUT_P2                      ctrl_cmd[4].bit.b2
#define T_OUT_P10                     ctrl_cmd[4].bit.b3
#define T_OUT_P3                      ctrl_cmd[4].bit.b4
#define T_OUT_P11                     ctrl_cmd[4].bit.b5
#define T_OUT_P4                      ctrl_cmd[4].bit.b6
#define T_OUT_P12                     ctrl_cmd[4].bit.b7
#define T_OUT_P5                      ctrl_cmd[5].bit.b0
#define T_OUT_P13                    ctrl_cmd[5].bit.b1
#define T_OUT_P6                     ctrl_cmd[5].bit.b2
#define T_OUT_P14                    ctrl_cmd[5].bit.b3
#define T_OUT_P7                     ctrl_cmd[5].bit.b4
#define T_OUT_P42                    ctrl_cmd[5].bit.b5
#define T_OUT_P8                     ctrl_cmd[5].bit.b6
#define T_OUT_P17                    ctrl_cmd[5].bit.b7  /////

/*wiper control command*/
#define CTL_WIPER_HI	               ctrl_cmd[6].bit.b0
#define	CTL_WIPER_LO                   ctrl_cmd[6].bit.b1
#define CTL_WIPER_MI	               ctrl_cmd[6].bit.b2
#define CTL_WIPER_INT                  ctrl_cmd[6].bit.b3
#define CTL_KEY_ON		               ctrl_cmd[6].bit.b4
#define CTL_KEY_ACC		               ctrl_cmd[6].bit.b5


/*front open state*/
#define F_OPEN1_A1       bcm_out_st_f.bit.b0
#define F_OPEN2_A9       bcm_out_st_f.bit.b1
#define F_OPEN3_A2       bcm_out_st_f.bit.b2
#define F_OPEN4_A10      bcm_out_st_f.bit.b3

#define F_OPEN5_A3       bcm_out_st_f.bit.b4
#define F_OPEN6_A11      bcm_out_st_f.bit.b5
#define F_OPEN7_A4       bcm_out_st_f.bit.b6
#define F_OPEN8_A12      bcm_out_st_f.bit.b7

#define F_OPEN9_A5       bcm_out_st_f.bit.b8
#define F_OPEN10_A13     bcm_out_st_f.bit.b9
#define F_OPEN11_A6      bcm_out_st_f.bit.b10
#define F_OPEN12_A14     bcm_out_st_f.bit.b11

#define F_OPEN13_A7      bcm_out_st_f.bit.b12
#define F_OPEN14_A42     bcm_out_st_f.bit.b13
#define F_OPEN15_A8      bcm_out_st_f.bit.b14

/* front out state*/
#define F_OUT1_A1     bcm_fb_st_f.BIT.b0
#define F_OUT2_A9     bcm_fb_st_f.BIT.b1
#define F_OUT3_A2     bcm_fb_st_f.BIT.b2
#define F_OUT4_A10    bcm_fb_st_f.BIT.b3

#define F_OUT5_A3     bcm_fb_st_f.BIT.b4
#define F_OUT6_A11    bcm_fb_st_f.BIT.b5
#define F_OUT7_A4     bcm_fb_st_f.BIT.b6
#define F_OUT8_A12    bcm_fb_st_f.BIT.b7

#define F_OUT9_A5     bcm_fb_st_f.BIT.b8
#define F_OUT10_A13   bcm_fb_st_f.BIT.b9
#define F_OUT11_A6    bcm_fb_st_f.BIT.b10
#define F_OUT12_A14   bcm_fb_st_f.BIT.b11

#define F_OUT13_A7    bcm_fb_st_f.BIT.b12
#define F_OUT14_A42   bcm_fb_st_f.BIT.b13
#define F_OUT15_A8    bcm_fb_st_f.BIT.b14


/*front open state*/
#define R_OPEN1_A1       bcm_out_st_r.bit.b0
#define R_OPEN2_A9       bcm_out_st_r.bit.b1
#define R_OPEN3_A2       bcm_out_st_r.bit.b2
#define R_OPEN4_A10      bcm_out_st_r.bit.b3

#define R_OPEN5_A3       bcm_out_st_r.bit.b4
#define R_OPEN6_A11      bcm_out_st_r.bit.b5
#define R_OPEN7_A4       bcm_out_st_r.bit.b6
#define R_OPEN8_A12      bcm_out_st_r.bit.b7

#define R_OPEN9_A5       bcm_out_st_r.bit.b8
#define R_OPEN10_A13     bcm_out_st_r.bit.b9
#define R_OPEN11_A6      bcm_out_st_r.bit.b10
#define R_OPEN12_A14     bcm_out_st_r.bit.b11

#define R_OPEN13_A7      bcm_out_st_r.bit.b12
#define R_OPEN14_A42     bcm_out_st_r.bit.b13
#define R_OPEN15_A8      bcm_out_st_r.bit.b14

/* rear out state*/
#define R_OUT1_A1     bcm_fb_st_r.BIT.b0
#define R_OUT2_A9     bcm_fb_st_r.BIT.b1
#define R_OUT3_A2     bcm_fb_st_r.BIT.b2
#define R_OUT4_A10    bcm_fb_st_r.BIT.b3

#define R_OUT5_A3     bcm_fb_st_r.BIT.b4
#define R_OUT6_A11    bcm_fb_st_r.BIT.b5
#define R_OUT7_A4     bcm_fb_st_r.BIT.b6
#define R_OUT8_A12    bcm_fb_st_r.BIT.b7

#define R_OUT9_A5     bcm_fb_st_r.BIT.b8
#define R_OUT10_A13   bcm_fb_st_r.BIT.b9
#define R_OUT11_A6    bcm_fb_st_r.BIT.b10
#define R_OUT12_A14   bcm_fb_st_r.BIT.b11

#define R_OUT13_A7    bcm_fb_st_r.BIT.b12
#define R_OUT14_A42   bcm_fb_st_r.BIT.b13
#define R_OUT15_A8    bcm_fb_st_r.BIT.b14


/*front open state*/
#define T_OPEN1_A1       bcm_out_st_t.bit.b0
#define T_OPEN2_A9       bcm_out_st_t.bit.b1
#define T_OPEN3_A2       bcm_out_st_t.bit.b2
#define T_OPEN4_A10      bcm_out_st_t.bit.b3

#define T_OPEN5_A3       bcm_out_st_t.bit.b4
#define T_OPEN6_A11      bcm_out_st_t.bit.b5
#define T_OPEN7_A4       bcm_out_st_t.bit.b6
#define T_OPEN8_A12      bcm_out_st_t.bit.b7

#define T_OPEN9_A5       bcm_out_st_t.bit.b8
#define T_OPEN10_A13     bcm_out_st_t.bit.b9
#define T_OPEN11_A6      bcm_out_st_t.bit.b10
#define T_OPEN12_A14     bcm_out_st_t.bit.b11

#define T_OPEN13_A7      bcm_out_st_t.bit.b12
#define T_OPEN14_A42     bcm_out_st_t.bit.b13
#define T_OPEN15_A8      bcm_out_st_t.bit.b14

/* top out state*/
#define T_OUT1_A1     bcm_fb_st_t.BIT.b0
#define T_OUT2_A9     bcm_fb_st_t.BIT.b1
#define T_OUT3_A2     bcm_fb_st_t.BIT.b2
#define T_OUT4_A10    bcm_fb_st_t.BIT.b3

#define T_OUT5_A3     bcm_fb_st_t.BIT.b4
#define T_OUT6_A11    bcm_fb_st_t.BIT.b5
#define T_OUT7_A4     bcm_fb_st_t.BIT.b6
#define T_OUT8_A12    bcm_fb_st_t.BIT.b7

#define T_OUT9_A5     bcm_fb_st_t.BIT.b8
#define T_OUT10_A13   bcm_fb_st_t.BIT.b9
#define T_OUT11_A6    bcm_fb_st_t.BIT.b10
#define T_OUT12_A14   bcm_fb_st_t.BIT.b11

#define T_OUT13_A7    bcm_fb_st_t.BIT.b12
#define T_OUT14_A42   bcm_fb_st_t.BIT.b13
#define T_OUT15_A8    bcm_fb_st_t.BIT.b14


/*	switch from front BCM*/
#define F_SW_P32			          bcm_sw1_f.bit.b0
#define F_SW_P18			          bcm_sw1_f.bit.b1
#define F_SW_P33			          bcm_sw1_f.bit.b2
#define F_SW_P19			          bcm_sw1_f.bit.b3
#define F_SW_P34			          bcm_sw1_f.bit.b4
#define F_SW_P20			          bcm_sw1_f.bit.b5
#define F_SW_P35			          bcm_sw1_f.bit.b6
#define F_SW_P21			          bcm_sw1_f.bit.b7
#define F_SW_P36			          bcm_sw1_f.bit.b8
#define F_SW_P22			          bcm_sw1_f.bit.b9
#define F_SW_P37			          bcm_sw1_f.bit.b10 
#define F_SW_P23			          bcm_sw1_f.bit.b11
#define F_SW_P38			          bcm_sw1_f.bit.b12
#define F_SW_P24			          bcm_sw1_f.bit.b13
#define F_SW_P39			          bcm_sw1_f.bit.b14				
#define F_SW_P17			          bcm_sw2_f.bit.b0
#define F_SW_P41			          bcm_sw2_f.bit.b1

/*	switch from rear BCM*/
#define R_SW_P32			          bcm_sw1_r.bit.b0
#define R_SW_P18			          bcm_sw1_r.bit.b1
#define R_SW_P33			          bcm_sw1_r.bit.b2
#define R_SW_P19			          bcm_sw1_r.bit.b3
#define R_SW_P34			          bcm_sw1_r.bit.b4
#define R_SW_P20			          bcm_sw1_r.bit.b5
#define R_SW_P35			          bcm_sw1_r.bit.b6
#define R_SW_P21			          bcm_sw1_r.bit.b7
#define R_SW_P36			          bcm_sw1_r.bit.b8
#define R_SW_P22			          bcm_sw1_r.bit.b9
#define R_SW_P37			          bcm_sw1_r.bit.b10
#define R_SW_P23			          bcm_sw1_r.bit.b11
#define R_SW_P38			          bcm_sw1_r.bit.b12 
#define R_SW_P24			          bcm_sw1_r.bit.b13
#define R_SW_P39			          bcm_sw1_r.bit.b14				
#define R_SW_P17			          bcm_sw2_r.bit.b0
#define R_SW_P41			          bcm_sw2_r.bit.b1

/*	switch from top BCM*/
#define T_SW_P32			           bcm_sw1_t.bit.b0
#define T_SW_P18			           bcm_sw1_t.bit.b1
#define T_SW_P33			           bcm_sw1_t.bit.b2
#define T_SW_P19			           bcm_sw1_t.bit.b3
#define T_SW_P34			           bcm_sw1_t.bit.b4
#define T_SW_P20			           bcm_sw1_t.bit.b5
#define T_SW_P35			           bcm_sw1_t.bit.b6
#define T_SW_P21			           bcm_sw1_t.bit.b7
#define T_SW_P36			           bcm_sw1_t.bit.b8
#define T_SW_P22			           bcm_sw1_t.bit.b9
#define T_SW_P37			           bcm_sw1_t.bit.b10
#define T_SW_P23			           bcm_sw1_t.bit.b11
#define T_SW_P38			           bcm_sw1_t.bit.b12
#define T_SW_P24			           bcm_sw1_t.bit.b13
#define T_SW_P39			           bcm_sw1_t.bit.b14				
#define T_SW_P17			           bcm_sw2_t.bit.b0
#define T_SW_P41			           bcm_sw2_t.bit.b1


extern uint8_t pcan_off_line;
extern uint8_t fbcm_off_line;
extern uint8_t rbcm_off_line;
extern uint8_t tbcm_off_line;

extern TYPE_QQWORD  tip_code1,tip_code2,tip_code3,tip_code4;


//文字报警宏定义开始

#define WIPER_HINT                     tip_code1.bit.b0
#define WIPER_1SEC					   tip_code1.bit.b1
#define WIPER_2SEC					   tip_code1.bit.b2
#define WIPER_3SEC					   tip_code1.bit.b3
#define WIPER_4SEC					   tip_code1.bit.b4
#define WIPER_5SEC					   tip_code1.bit.b5
#define WIPER_6SEC					   tip_code1.bit.b6
#define WIPER_7SEC					   tip_code1.bit.b7
#define WIPER_8SEC					   tip_code1.bit.b8
#define WIPER_9SEC					   tip_code1.bit.b9

#define TIP_FRONT_A1_SHORT			   tip_code1.bit.b10		//
#define TIP_FRONT_A2_SHORT			   tip_code1.bit.b11		//
#define TIP_FRONT_A3_SHORT			   tip_code1.bit.b12		//
#define TIP_FRONT_A4_SHORT			   tip_code1.bit.b13		//
#define TIP_FRONT_A5_SHORT			   tip_code1.bit.b14		//
#define TIP_FRONT_A6_SHORT			   tip_code1.bit.b15		//
#define TIP_FRONT_A7_SHORT			   tip_code1.bit.b16		//
#define TIP_FRONT_A8_SHORT			   tip_code1.bit.b17		//
#define TIP_FRONT_A9_SHORT			   tip_code1.bit.b18		//
#define TIP_FRONT_A10_SHORT			   tip_code1.bit.b19		//

#define TIP_FRONT_A11_SHORT			   tip_code1.bit.b20		//
#define TIP_FRONT_A12_SHORT			   tip_code1.bit.b21		//
#define TIP_FRONT_A13_SHORT			   tip_code1.bit.b22		//
#define TIP_FRONT_A14_SHORT			   tip_code1.bit.b23		//
#define TIP_FRONT_A42_SHORT			   tip_code1.bit.b24		//

#define TIP_REAR_A1_SHORT			   tip_code1.bit.b25		//
#define TIP_REAR_A2_SHORT			   tip_code1.bit.b26		//
#define TIP_REAR_A3_SHORT			   tip_code1.bit.b27		//
#define TIP_REAR_A4_SHORT			   tip_code1.bit.b28		//
#define TIP_REAR_A5_SHORT			   tip_code1.bit.b29		//
#define TIP_REAR_A6_SHORT			   tip_code1.bit.b30		//
#define TIP_REAR_A7_SHORT			   tip_code1.bit.b31		//
#define TIP_REAR_A8_SHORT			   tip_code1.bit.b32		//
#define TIP_REAR_A9_SHORT			   tip_code1.bit.b33		//
#define TIP_REAR_A10_SHORT			   tip_code1.bit.b34		//
#define TIP_REAR_A11_SHORT			   tip_code1.bit.b35		//
#define TIP_REAR_A12_SHORT			   tip_code1.bit.b36		//
#define TIP_REAR_A13_SHORT			   tip_code1.bit.b37		//
#define TIP_REAR_A14_SHORT			   tip_code1.bit.b38		//
#define TIP_REAR_A42_SHORT			   tip_code1.bit.b39		//

#define TIP_TOP_A1_SHORT			   tip_code1.bit.b40		//
#define TIP_TOP_A2_SHORT			   tip_code1.bit.b41		//
#define TIP_TOP_A3_SHORT			   tip_code1.bit.b42		//
#define TIP_TOP_A4_SHORT			   tip_code1.bit.b43		//
#define TIP_TOP_A5_SHORT			   tip_code1.bit.b44		//
#define TIP_TOP_A6_SHORT			   tip_code1.bit.b45		//
#define TIP_TOP_A7_SHORT			   tip_code1.bit.b46		//
#define TIP_TOP_A8_SHORT			   tip_code1.bit.b47		//
#define TIP_TOP_A9_SHORT			   tip_code1.bit.b48		//
#define TIP_TOP_A10_SHORT			   tip_code1.bit.b49		//
#define TIP_TOP_A11_SHORT			   tip_code1.bit.b50		//
#define TIP_TOP_A12_SHORT			   tip_code1.bit.b51		//
#define TIP_TOP_A13_SHORT			   tip_code1.bit.b52		//
#define TIP_TOP_A14_SHORT			   tip_code1.bit.b53		//
#define TIP_TOP_A42_SHORT			   tip_code1.bit.b54		//

#define TIP_0X37        		       	tip_code1.bit.b55		//仪表输出1短路，C5x为C19、C6x为D01
#define TIP_0X38        	           	tip_code1.bit.b56		//仪表输出2短路，C5x为C21、C6x为D02
#define TIP_0X39   					    tip_code1.bit.b57		//前部模块离线
#define TIP_0X3A     					tip_code1.bit.b58		//后部模块离线
#define TIP_0X3B    					tip_code1.bit.b59		//顶部模块离线

#define TIP_0X3C     					tip_code1.bit.b60       // PCAN离线
#define TIP_0X3D        				tip_code1.bit.b61       // 蓄电池电压低于16V
#define TIP_0X3E      tip_code1.bit.b62   
#define TIP_0X3F      tip_code1.bit.b63   

#define TIP_FBCM_OFF  tip_code2.bit.b0    
#define TIP_RBCM_OFF  tip_code2.bit.b1		
#define TIP_TBCM_OFF  tip_code2.bit.b2		
#define TIP_PCAN_OFF  tip_code2.bit.b3	

#define TIP_0X44  tip_code2.bit.b4		
#define TIP_0X45  tip_code2.bit.b5    
#define TIP_0X46  tip_code2.bit.b6    
#define TIP_0X47  tip_code2.bit.b7    
#define TIP_0X48  tip_code2.bit.b8		
#define TIP_0X49  tip_code2.bit.b9		
#define TIP_0X4A  tip_code2.bit.b10   
#define TIP_0X4B  tip_code2.bit.b11   
#define TIP_0X4C  tip_code2.bit.b12   
#define TIP_0X4D  tip_code2.bit.b13   
#define TIP_0X4E  tip_code2.bit.b14   
#define TIP_0X4F  tip_code2.bit.b15  
 
#define TIP_0X50  tip_code2.bit.b16   
#define TIP_0X51  tip_code2.bit.b17   
#define TIP_0X52  tip_code2.bit.b18   
#define TIP_0X53  tip_code2.bit.b19   
#define TIP_0X54  tip_code2.bit.b20   
#define TIP_0X55  tip_code2.bit.b21   
#define TIP_0X56  tip_code2.bit.b22   
#define TIP_0X57  tip_code2.bit.b23   
#define TIP_0X58  tip_code2.bit.b24   
#define TIP_0X59  tip_code2.bit.b25   
#define TIP_0X5A  tip_code2.bit.b26   
#define TIP_0X5B  tip_code2.bit.b27   
#define TIP_0X5C  tip_code2.bit.b28   
#define TIP_0X5D  tip_code2.bit.b29   
#define TIP_0X5E  tip_code2.bit.b30   
#define TIP_0X5F  tip_code2.bit.b31  
 
#define TIP_0X60  tip_code2.bit.b32   
#define TIP_0X61  tip_code2.bit.b33   
#define TIP_0X62  tip_code2.bit.b34   
#define TIP_0X63  tip_code2.bit.b35   
#define TIP_0X64  tip_code2.bit.b36   
#define TIP_0X65  tip_code2.bit.b37   
#define TIP_0X66  tip_code2.bit.b38   
#define TIP_0X67  tip_code2.bit.b39   
#define TIP_0X68  tip_code2.bit.b40   
#define TIP_0X69  tip_code2.bit.b41   
#define TIP_0X6A  tip_code2.bit.b42   
#define TIP_0X6B  tip_code2.bit.b43   
#define TIP_0X6C  tip_code2.bit.b44   
#define TIP_0X6D  tip_code2.bit.b45   
#define TIP_0X6E  tip_code2.bit.b46   
#define TIP_0X6F  tip_code2.bit.b47 
  
#define TIP_0X70  tip_code2.bit.b48   
#define TIP_0X71  tip_code2.bit.b49   
#define TIP_0X72  tip_code2.bit.b50   
#define TIP_0X73  tip_code2.bit.b51   
#define TIP_0X74  tip_code2.bit.b52   
#define TIP_0X75  tip_code2.bit.b53   
#define TIP_0X76  tip_code2.bit.b54   
#define TIP_0X77  tip_code2.bit.b55   
#define TIP_0X78  tip_code2.bit.b56   
#define TIP_0X79  tip_code2.bit.b57   
#define TIP_0X7A  tip_code2.bit.b58   
#define TIP_0X7B  tip_code2.bit.b59   
#define TIP_0X7C  tip_code2.bit.b60   
#define TIP_0X7D  tip_code2.bit.b61   
#define TIP_0X7E  tip_code2.bit.b62   
#define TIP_0X7F  tip_code2.bit.b63  
 
#define TIP_0X80  tip_code3.bit.b0    
#define TIP_0X81  tip_code3.bit.b1    
#define TIP_0X82  tip_code3.bit.b2		
#define TIP_0X83  tip_code3.bit.b3    
#define TIP_0X84  tip_code3.bit.b4		
#define TIP_0X85  tip_code3.bit.b5    
#define TIP_0X86  tip_code3.bit.b6    
#define TIP_0X87  tip_code3.bit.b7    
#define TIP_0X88  tip_code3.bit.b8		
#define TIP_0X89  tip_code3.bit.b9    
#define TIP_0X8A  tip_code3.bit.b10   
#define TIP_0X8B  tip_code3.bit.b11   
#define TIP_0X8C  tip_code3.bit.b12   
#define TIP_0X8D  tip_code3.bit.b13   
#define TIP_0X8E  tip_code3.bit.b14   
#define TIP_0X8F  tip_code3.bit.b15   

#define TIP_0X90  tip_code3.bit.b16   
#define TIP_0X91  tip_code3.bit.b17   
#define TIP_0X92  tip_code3.bit.b18   
#define TIP_0X93  tip_code3.bit.b19   
#define TIP_0X94  tip_code3.bit.b20   
#define TIP_0X95  tip_code3.bit.b21   
#define TIP_0X96  tip_code3.bit.b22   
#define TIP_0X97  tip_code3.bit.b23   
#define TIP_0X98  tip_code3.bit.b24   
#define TIP_0X99  tip_code3.bit.b25   
#define TIP_0X9A  tip_code3.bit.b26   
#define TIP_0X9B  tip_code3.bit.b27   
#define TIP_0X9C  tip_code3.bit.b28   
#define TIP_0X9D  tip_code3.bit.b29   
#define TIP_0X9E  tip_code3.bit.b30   
#define TIP_0X9F  tip_code3.bit.b31  
 
#define TIP_0XA0  tip_code3.bit.b32   
#define TIP_0XA1  tip_code3.bit.b33   
#define TIP_0XA2  tip_code3.bit.b34   
#define TIP_0XA3  tip_code3.bit.b35   
#define TIP_0XA4  tip_code3.bit.b36   
#define TIP_0XA5  tip_code3.bit.b37   
#define TIP_0XA6  tip_code3.bit.b38   
#define TIP_0XA7  tip_code3.bit.b39   
#define TIP_0XA8  tip_code3.bit.b40   
#define TIP_0XA9  tip_code3.bit.b41   
#define TIP_0XAA  tip_code3.bit.b42   
#define TIP_0XAB  tip_code3.bit.b43   
#define TIP_0XAC  tip_code3.bit.b44   
#define TIP_0XAD  tip_code3.bit.b45   
#define TIP_0XAE  tip_code3.bit.b46   
#define TIP_0XAF  tip_code3.bit.b47   

#define TIP_0XB0  tip_code3.bit.b48   
#define TIP_0XB1  tip_code3.bit.b49   
#define TIP_0XB2  tip_code3.bit.b50   
#define TIP_0XB3  tip_code3.bit.b51   
#define TIP_0XB4  tip_code3.bit.b52   
#define TIP_0XB5  tip_code3.bit.b53   
#define TIP_0XB6  tip_code3.bit.b54   
#define TIP_0XB7  tip_code3.bit.b55   
#define TIP_0XB8  tip_code3.bit.b56   
#define TIP_0XB9  tip_code3.bit.b57   
#define TIP_0XBA  tip_code3.bit.b58   
#define TIP_0XBB  tip_code3.bit.b59   
#define TIP_0XBC  tip_code3.bit.b60   
#define TIP_0XBD  tip_code3.bit.b61   
#define TIP_0XBE  tip_code3.bit.b62   
#define TIP_0XBF  tip_code3.bit.b63  
 
#define TIP_0XC0  tip_code4.bit.b0    
#define TIP_0XC1  tip_code4.bit.b1    
#define TIP_0XC2  tip_code4.bit.b2    
#define TIP_0XC3  tip_code4.bit.b3		
#define TIP_0XC4  tip_code4.bit.b4		
#define TIP_0XC5  tip_code4.bit.b5    
#define TIP_0XC6  tip_code4.bit.b6    
#define TIP_0XC7  tip_code4.bit.b7		
#define TIP_0XC8  tip_code4.bit.b8		
#define TIP_0XC9  tip_code4.bit.b9    
#define TIP_0XCA  tip_code4.bit.b10   
#define TIP_0XCB  tip_code4.bit.b11   
#define TIP_0XCC  tip_code4.bit.b12   
#define TIP_0XCD  tip_code4.bit.b13   
#define TIP_0XCE  tip_code4.bit.b14   
#define TIP_0XCF  tip_code4.bit.b15   

#define TIP_0XD0  tip_code4.bit.b16   
#define TIP_0XD1  tip_code4.bit.b17   
#define TIP_0XD2  tip_code4.bit.b18   
#define TIP_0XD3  tip_code4.bit.b19   
#define TIP_0XD4  tip_code4.bit.b20   
#define TIP_0XD5  tip_code4.bit.b21   
#define TIP_0XD6  tip_code4.bit.b22   
#define TIP_0XD7  tip_code4.bit.b23   
#define TIP_0XD8  tip_code4.bit.b24   
#define TIP_0XD9  tip_code4.bit.b25   
#define TIP_0XDA  tip_code4.bit.b26   
#define TIP_0XDB  tip_code4.bit.b27   
#define TIP_0XDC  tip_code4.bit.b28   
#define TIP_0XDD  tip_code4.bit.b29   
#define TIP_0XDE  tip_code4.bit.b30   
#define TIP_0XDF  tip_code4.bit.b31  
 
#define TIP_0XE0  tip_code4.bit.b32   
#define TIP_0XE1  tip_code4.bit.b33   
#define TIP_0XE2  tip_code4.bit.b34        
#define TIP_0XE3  tip_code4.bit.b35        
#define TIP_0XE4  tip_code4.bit.b36        
#define TIP_0XE5  tip_code4.bit.b37        
#define TIP_0XE6  tip_code4.bit.b38        
#define TIP_0XE7  tip_code4.bit.b39        
#define TIP_0XE8  tip_code4.bit.b40        
#define TIP_0XE9  tip_code4.bit.b41        
#define TIP_0XEA  tip_code4.bit.b42        
#define TIP_0XEB  tip_code4.bit.b43        
#define TIP_0XEC  tip_code4.bit.b44        
#define TIP_0XED  tip_code4.bit.b45        
#define TIP_0XEE  tip_code4.bit.b46        
#define TIP_0XEF  tip_code4.bit.b47 
       
#define TIP_0XF0  tip_code4.bit.b48        
#define TIP_0XF1  tip_code4.bit.b49        
#define TIP_0XF2  tip_code4.bit.b50        
#define TIP_0XF3  tip_code4.bit.b51        
#define TIP_0XF4  tip_code4.bit.b52        
#define TIP_0XF5  tip_code4.bit.b53        
#define TIP_0XF6  tip_code4.bit.b54        
#define TIP_0XF7  tip_code4.bit.b55        
#define TIP_0XF8  tip_code4.bit.b56        
#define TIP_0XF9  tip_code4.bit.b57        
#define TIP_0XFA  tip_code4.bit.b58        
#define TIP_0XFB  tip_code4.bit.b59        
#define TIP_0XFC  tip_code4.bit.b60        
#define TIP_0XFD  tip_code4.bit.b61        
#define TIP_0XFE  tip_code4.bit.b62    

//文字报警宏定义结束

extern TYPE_WORD   bcm_sw1_f;      //front bcm switch  15 switch from hc165
extern TYPE_BYTE   bcm_sw2_f;      //front bcm switch   Pin-A17 A41
extern uint16_t    bcm_frq_f;      //front bcm input frequence
extern uint16_t    bcm_senor1_f;   //front bcm senor pin A25
extern uint16_t    bcm_senor2_f;   //front bcm senor pin A40
extern TYPE_WORD   bcm_out_st_f;   //front bcm output states ON & OFF
extern TYPE_DWORD  bcm_fb_st_f;    //front bcm feedback states

extern TYPE_WORD   bcm_sw1_r;      //rear bcm switch   15 switch from hc165
extern TYPE_BYTE   bcm_sw2_r;      //rear bcm switch    Pin-A17 A41
extern uint16_t    bcm_frq_r;      //rear bcm input frequence
extern uint16_t    bcm_senor1_r;   //rear bcm senor pin A25
extern uint16_t    bcm_senor2_r;   //rear bcm senor pin A40
extern TYPE_WORD   bcm_out_st_r;   //rear bcm output states ON & OFF
extern TYPE_DWORD  bcm_fb_st_r;    //rear bcm feedback states

extern TYPE_WORD   bcm_sw1_t;      //top bcm switch    15 switch from hc165
extern TYPE_BYTE   bcm_sw2_t;      //top bcm switch     Pin-A17 A41
extern uint16_t    bcm_frq_t;      //top bcm input frequence
extern uint16_t    bcm_senor1_t;   //top bcm senor pin A25
extern uint16_t    bcm_senor2_t;   //top bcm senor pin A40
extern TYPE_WORD   bcm_out_st_t;   //top bcm output states ON & OFF
extern TYPE_DWORD  bcm_fb_st_t;    //top bcm feedback states
extern TYPE_BYTE   ctrl_cmd[8];

extern TYPE_WORD F_Set_PWM,R_Set_PWM,T_Set_PWM;


#define POWER_KEEP(state)   GPIO_Set_Output_Data_Bits(GPIOB_SFR,GPIO_PIN_MASK_9, state)	

typedef struct 
{
	unsigned char bs0:2;
	unsigned char bs1:2;
	unsigned char bs2:2;
	unsigned char bs3:2;
} BYTE_2BITFIELD;


typedef union 
{
	unsigned char byte;
	BYTE_FIELD	bit;
	BYTE_2BITFIELD bit2;
} TYPE_8BIT;


typedef union 
{
	unsigned int U32;	
	unsigned int U16[2];	
	TYPE_8BIT U8[4];
	DWORD_FIELD	bit;
	DWORD_FIELD_2bit bit2;
} TYPE_32BIT;

extern TYPE_32BIT fmode_mask,rmode_mask,tmode_mask;

/*	switch from front BCM*/

#define Mask_F_P32_IN			          fmode_mask.bit.b31
#define Mask_F_P18_IN			          fmode_mask.bit.b30
#define Mask_F_P33_IN			          fmode_mask.bit.b29
#define Mask_F_P19_IN			          fmode_mask.bit.b28
#define Mask_F_P34_IN			          fmode_mask.bit.b27
#define Mask_F_P20_IN			          fmode_mask.bit.b26
#define Mask_F_P35_IN			          fmode_mask.bit.b25
#define Mask_F_P21_IN			          fmode_mask.bit.b24

#define Mask_F_P36_IN			          fmode_mask.bit.b23
#define Mask_F_P22_IN			          fmode_mask.bit.b22
#define Mask_F_P37_IN			          fmode_mask.bit.b21
#define Mask_F_P23_IN			          fmode_mask.bit.b20
#define Mask_F_P38_IN			          fmode_mask.bit.b19 
#define Mask_F_P24_IN			          fmode_mask.bit.b18
#define Mask_F_P39_IN			          fmode_mask.bit.b17	

#define Mask_F_P17_IN			          fmode_mask.bit.b15
#define Mask_F_P41_IN			          fmode_mask.bit.b14



/*	switch from rear BCM*/
#define Mask_R_P32_IN			          rmode_mask.bit.b31
#define Mask_R_P18_IN			          rmode_mask.bit.b30
#define Mask_R_P33_IN			          rmode_mask.bit.b29
#define Mask_R_P19_IN			          rmode_mask.bit.b28
#define Mask_R_P34_IN			          rmode_mask.bit.b27
#define Mask_R_P20_IN			          rmode_mask.bit.b26
#define Mask_R_P35_IN			          rmode_mask.bit.b25
#define Mask_R_P21_IN			          rmode_mask.bit.b24

#define Mask_R_P36_IN			          rmode_mask.bit.b23
#define Mask_R_P22_IN			          rmode_mask.bit.b22
#define Mask_R_P37_IN			          rmode_mask.bit.b21
#define Mask_R_P23_IN			          rmode_mask.bit.b20
#define Mask_R_P38_IN			          rmode_mask.bit.b19 
#define Mask_R_P24_IN			          rmode_mask.bit.b18
#define Mask_R_P39_IN			          rmode_mask.bit.b17	

#define Mask_R_P17_IN			          rmode_mask.bit.b15
#define Mask_R_P41_IN			          rmode_mask.bit.b14



/*	switch from top BCM*/
#define Mask_T_P32_IN			          tmode_mask.bit.b31
#define Mask_T_P18_IN			          tmode_mask.bit.b30
#define Mask_T_P33_IN			          tmode_mask.bit.b29
#define Mask_T_P19_IN			          tmode_mask.bit.b28
#define Mask_T_P34_IN			          tmode_mask.bit.b27
#define Mask_T_P20_IN			          tmode_mask.bit.b26
#define Mask_T_P35_IN			          tmode_mask.bit.b25
#define Mask_T_P21_IN			          tode_mask.bit.b24

#define Mask_T_P36_IN			          tmode_mask.bit.b23
#define Mask_T_P22_IN			          tmode_mask.bit.b22
#define Mask_T_P37_IN			          tmode_mask.bit.b21
#define Mask_T_P23_IN			          tmode_mask.bit.b20
#define Mask_T_P38_IN			          tmode_mask.bit.b19 
#define Mask_T_P24_IN			          tmode_mask.bit.b18
#define Mask_T_P39_IN			          tmode_mask.bit.b17	

#define Mask_T_P17_IN			          tmode_mask.bit.b15
#define Mask_T_P41_IN			          tmode_mask.bit.b14




void power_task(void);

//仪表中使用端口初始化
void PortInit(void);
void MeterAndBCMPortInit(void);
void Send_PWM_Bcm(void);
//雨刮配置函数
void RainConfig(void);



#endif









