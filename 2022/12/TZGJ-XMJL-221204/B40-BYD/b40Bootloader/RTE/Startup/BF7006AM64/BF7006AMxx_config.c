/*!
    \file  BF7006AMxx_config.h
    \brief peripherals configuration for BF7006AMxx
*/

/*
    Copyright (C) 2017 Byd

    2021-02-28, V1.0.0, peripherals configuration for BF7006AMxx
*/

#include "BF7006AMxx_config.h"

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

#ifdef BF7x06AMxx_SCI_DRIVER_PRESENT
void sci_config(void)
{
//  <e>SCI
#define SCI_CONFIG_EN 0
#if SCI_CONFIG_EN == 1
//    <e>SCI0
#define SCI0_EN 0
#if SCI0_EN == 1
    sci_parameter_struct sci0_parameter_init = 
    {
//      <o>Baudrate
//        <4800=>4800
//        <9600=>9600
//        <19200=>19200
//        <38400=>38400
//        <57600=>57600
//        <115200=>115200
//      <i>SCI baudrate config
        .baud_rate = 9600,

//      <o>Work mode
//        <0x80=>Cycle mode
//        <0x20=>Single mode
//        <0x00=>Normal mode
//      <i>SCI work mode select
        .work_mode = 0,

//      <o>Stop bit
//        <0x0=>1 bit
//        <0x40=>2 bits
//      <i>SCI stop bit width
        .stop_bit_width = 0,

//      <o>Data bit
//        <0x0=>8 bits
//        <0x10=>9 bits
//      <i>SCI data bit width select
        .data_bit_width = 0,

//      <q0.1>Parity enable
//      <i>SCI parity enable
        .parity_en = 0,

//      <o>Parity select
//        <0x1=>Odd
//        <0x0=>Even
//      <i>SCI parity type select
        .parity_sel = 1,

//      <o>Break tx size
//        <0x4=>13 bits
//        <0x0=>10 bits
//      <i>SCI stop bit width select
        .break_tx_size = 0x4,

//      <q0.1>Break check enable
//      <i>SCI break check enable
        .break_check_en = 0x0,

//      <q0.5>Baud rate auto match enable
//      <i>SCI baud rate auto match
        .rate_automatch_en = 0x00,

//      <q0.3>Tx enable
//      <i>SCI tx enable
        .tx_en = 0x0,

//      <q0.2>Rx enable
//      <i>SCI rx enable
        .rx_en = 0x0,

//      <o>Idle select
//        <0x0=>Start bit
//        <0x4=>Stop bit
//      <i>SCI idle select
        .idle_sel = 0x4,

//      <o>Wake up select
//        <0x8=>Addrrece
//        <0x0=>Idle
//      <i>SCI wake up select
        .wake_sel = 0x8,

//      <q0.4>Tx data inversion enable
//      <i>SCI tx data inversion enable
        .tx_inversion_en = 0x00,

//      <q0.3>Rwu idle select set
//      <i>SCI rwu idle select set
        .rwu_idlesel = 0x0,

//      <h>SCI Interrupt Enable
//        <q0.15>Break check 
//        <q0.14>Rx edge
//        <q0.7>Tx empty
//        <q0.6>Tx comp
//        <q0.5>Rx full
//        <q0.4>Idle
//        <q0.3>Rx overflow
//        <q0.2>Noise err
//        <q0.1>Frame err
//        <q0.0>Parity err
//      </h>
        .int_enable = 0x0000,

//      <h>SCI NVIC Enable
//        <q0.2>Rx
//        <q0.1>Tx
//        <q0.0>Err
//      </h>
//    </e>
        .nvic_enable = 0x0
    };

    (void)sci_init(SCI0,sci0_parameter_init);       //sci0 init
#endif

//    <e0>SCI1
#define SCI1_EN 0
#if SCI1_EN == 1

//      <o>Port select
//        <0x0=>PF0  PF1
//        <0x1=>PE2  PE3
//        <0x2=>PE6  PE7
//      <i>SCI1 output port select
    sci1_port_sel(0x1);

    sci_parameter_struct sci1_parameter_init = 
    {
//      <o>Baudrate
//        <4800=>4800
//        <9600=>9600
//        <19200=>19200
//        <38400=>38400
//        <57600=>57600
//        <115200=>115200
//      <i>SCI baudrate config
        .baud_rate = 9600,

//      <o>Work mode
//        <0x80=>Cycle mode
//        <0x20=>Single mode
//        <0x00=>Normal mode
//      <i>SCI work mode select
        .work_mode = 0,

//      <o>Stop bit
//        <0x0=>1 bit
//        <0x40=>2 bits
//      <i>SCI stop bit width
        .stop_bit_width = 0,

//      <o>Data bit
//        <0x0=>8 bits
//        <0x10=>9 bits
//      <i>SCI data bit width select
        .data_bit_width = 0,

//      <q0.1>Parity enable
//      <i>SCI parity enable
        .parity_en = 0,

//      <o>Parity select
//        <0x1=>Odd
//        <0x0=>Even
//      <i>SCI parity type select
        .parity_sel = 1,

//      <o>Break tx size
//        <0x4=>13 bits
//        <0x0=>10 bits
//      <i>SCI stop bit width select
        .break_tx_size = 0x4,

//      <q0.1>Break check enable
//      <i>SCI break check enable
        .break_check_en = 0x0,

//      <q0.5>Baud rate auto match enable
//      <i>SCI baud rate auto match
        .rate_automatch_en = 0x00,

//      <q0.3>Tx enable
//      <i>SCI tx enable
        .tx_en = 0x0,

//      <q0.2>Rx enable
//      <i>SCI rx enable
        .rx_en = 0x0,

//      <o>Idle select
//        <0x0=>Start bit
//        <0x4=>Stop bit
//      <i>SCI idle select
        .idle_sel = 0x4,

//      <o>Wake up select
//        <0x8=>Addrrece
//        <0x0=>Idle
//      <i>SCI wake up select
        .wake_sel = 0x8,

//      <q0.4>Tx data inversion enable
//      <i>SCI tx data inversion enable
        .tx_inversion_en = 0x00,

//      <q0.3>Rwu idle select
//      <i>SCI rwu idle select
        .rwu_idlesel = 0x0,

//      <h>SCI Interrupt Enable
//        <q0.15>Break check 
//        <q0.14>Rx edge
//        <q0.7>Tx empty
//        <q0.6>Tx comp
//        <q0.5>Rx full
//        <q0.4>Idle
//        <q0.3>Rx overflow
//        <q0.2>Noise err
//        <q0.1>Frame err
//        <q0.0>Parity err
//      </h>
        .int_enable = 0x0000,

//      <h>SCI NVIC Enable
//        <q0.2>Rx
//        <q0.1>Tx
//        <q0.0>Err
//      </h>
//    </e>
//  </e>
        .nvic_enable = 0x0
    };
    (void)sci_init(SCI1,sci1_parameter_init);       //sci1 init
#endif
#endif
}
#endif

#ifdef BF7x06AMxx_CAN_DRIVER_PRESENT
void can_config(void)
{
//  <e>CAN
#define CAN_CONFIG_EN 1
#if CAN_CONFIG_EN == 1
//    <o>CAN source clock select
//      <0x0=>XTAL
//      <0x1=>PLL
    can_clock_sel(0x0);

    can_parameter_struct can_parameter_init = 
    {
//    <o>Work mode select
//      <0x0=>Normal
//      <0x1=>Listen only
//      <0x2=>Self test
//      <0x3=>Self receive
//    <i>CAN work mode select
        .working_mode = (can_work_mode_enum)0,

//    <o>Synchronlzation jump width
//      <0x0=>0
//      <0x40=>1
//      <0x80=>2
//      <0xC0=>3
//    <i>Synchronlzation jump width
        .resync_jump_width = 0xC0,

//    <o>CAN module clock select
//      <0x0=>32MHz
//      <0x1=>16MHz
//      <0x2=>8MHz
//    <i>CAN module clock select
        .can_clk = (can_clk_enum)2,

//    <o>CAN baud rate
//      <0x0=>50K
//      <0x1=>100K
//      <0x2=>125K
//      <0x3=>200K
//      <0x4=>250K
//      <0x5=>400K
//      <0x6=>500K
//      <0x7=>800K
//      <0x8=>1M
//    <i>CAN baud rate config
        .can_baud = (can_baud_enum)0x2,

//    <o>Sampling times
//      <0x0=>1 time
//      <0x80=>3 time
//     <i>Sampling times
        .sampling_times = 0x80,

//    <o>Error alarm count <0x0-0xFF:0x1><#/0x1>
//    <i>Error alarm count (8 bits)
        .error_alarm_count = 100,

//    <h>Interrupt Enable
//      <q0.7>Bus error interrupt enable
//      <q0.6>Arbitration lost interrupt enable
//      <q0.5>Error passive interrupt enable
//      <q0.4>Wake up interrupt enable
//      <q0.3>Data overflow interrupt enable
//      <q0.2>Error interrupt enable
//      <q0.1>Tx interrupt enable
//      <q0.0>Rx interrupt enable
//    </h>
        .int_enable = 0x01,

//    <h>NVIC Enable
//      <q0.3>Wake up nvic interrupt enable
//      <q0.2>Error nvic interrupt enable
//      <q0.1>Rx nvic interrupt enable
//      <q0.0>Tx nvic interrupt enable
//    </h>
        .nvic_int_enable = 0x0F
    };
//    <h>CAN filter config
    can_filter_parameter_struct can_filter_parameter = 
    {
//      <o>Filter mode
//        <0x0=>Double filter
//        <0x1=>Single filter
//      <i>CAN filter mode select
        .filter_mode = (CAN_FILTER_MODE)0x1,

//      <o>Frame format
//        <0x0=>Standard frame
//        <0x1=>Extended frame
//      <i>CAN filter frame format 
        .filter_frame = (CAN_FRAME_FORMAT)0x0,

//      <o>Frame type
//        <0x0=>Data frame
//        <0x1=>Remote frame
//      <i>Frame type
        .filter_RTR = (CAN_FRAME_TYPE)0x0,

//      <o>RTR mask
//        <0x0=>Disable
//        <0x1=>Enable
//      <i>RTR mask
        .filter_mask_RTR = (FunctionalState)0,

//      <h>Single filter config
//        <o>id <0x0-0x1FFFFFFF:0x1><#/0x1>
//        <i> Standard frame : lower 11 bits valid
//        <i> Extended frame : lower 29 bits valid
        .filter_single_id = 0xFFFF,
        
//        <o>data 0 <0x0-0xFF:0x1><#/0x1>
//        <i> Standard frame : lower 8 bits valid
//        <i> Extended frame : invalid
        .filter_data0 = 0xff,
        
//        <o>data 1 <0x0-0xFF:0x1><#/0x1>
//        <i> Standard frame : lower 8 bits valid
//        <i> Extended frame : invalid
        .filter_data1 = 0xff,
        
//        <o>id mask <0x0-0x7FF:0x1><#/0x1>
//        <i> Standard frame : lower 11 bits valid
//        <i> Extended frame : lower 29 bits valid
        .filter_mask_single_id  = 0xffff,
        
//        <o>data 0 mask <0x0-0xFF:0x1><#/0x1>
//        <i> Standard frame : lower 8 bits valid
//        <i> Extended frame : invalid
        .filter_mask_data0      = 0xff,
        
//        <o>data 1 mask <0x0-0xFF:0x1><#/0x1>
//        <i> Standard frame : lower 8 bits valid
//        <i> Extended frame : invalid
        .filter_mask_data1      = 0xff,
//      </h>

//      <h>Double filter config
//        <o>id 0 <0x0-0x1FFFFFFF:0x1><#/0x1>
//        <i> Standard frame: Bit 10 ~ 0 valid
//        <i> Extended frame: Bit 28 ~ 13 valid
        .filter_double_id0      = 0xFFFFU,
        
//        <o>id 1 <0x0-0xFFFFFFFF:0x1><#/0x1>
//        <i> Standard frame: Bit 10 ~ 0 valid
//        <i> Extended frame: Bit 28 ~ 13 valid
        .filter_double_id1      = 0xFFFFU,
        
//        <o>std frame data 0 <0x0-0xFF:0x1><#/0x1>
//        <i> Standard frame: lower 8 bits valid
//        <i> Extended frame: invalid
        .filter_data0_std       = 0xff,
        
//        <o>id 0 mask<0x0-0xFFFF:0x1><#/0x1>
//        <i> Standard frame: lower 11 bits valid
//        <i> Extended frame: lower 16 bits valid
        .filter_mask_double_id0 = 0xffff,
        
        
//        <o>id 1 mask<0x0-0xFFFF:0x1><#/0x1>
//        <i> Standard frame: lower 11 bits valid
//        <i> Extended frame: lower 16 bits valid
        .filter_mask_double_id1 = 0xffff,
        
//        <o>std frame data 0 mask<0x0-0xFF:0x1><#/0x1>
//        <i> Standard frame: lower 8 bits valid
//        <i> Extended frame: invalid
        .filter_mask_data0_std  = 0xff
//      </h>
//    </h>
//  </e>
    };

    (void)can_init(can_parameter_init,can_filter_parameter);
		
//		extern void Can_Send_Strand_Buff_X (uint16_t id, uint8_t *buf, uint8_t len);
//		uint8_t data[8] = {1};
//		Can_Send_Strand_Buff_X(0x123,data,8);
		
#endif
}
#endif

#ifdef BF7x06AMxx_ADC_DRIVER_PRESENT
void adc_config(void)
{
//  <e> ADC
#define ADC_CONFIG_EN 1
#if ADC_CONFIG_EN == 1
    adc_parameter_struct adc_init_para = 
    {
//    <o>Clock divide parameter
//      <0x0=> SysClk / 1
//      <0x10=>SysClk / 2
//      <0x70=>SysClk / 3
//      <0x20=>SysClk / 4
//      <0x30=>SysClk / 6
//      <0x40=>SysClk / 8
//      <0x50=>SysClk / 10
//      <0x60=>SysClk / 12
//    <i>ADC clock divide parameter
        .adc_clk = 0x00,

//    <o>Data width
//      <0x0=>8 bits
//      <0x1=>12 bits
//    <i>adc data width
        .data_width = 0x1,

//    <o>Sample clock number<0x0-0x3FF:0x1><#/0x1>
        .sample_clk_num = 100,

//    <h>Channel enable
//      <q0.23>CH 23  //cs7-1  null
//      <q0.22>CH 22  //ad_r1
//      <q0.21>CH 21  //cs14
//      <q0.20>CH 20  //cs9

//      <q0.19>CH 19  //cs4
//      <q0.18>CH 18
//      <q0.17>CH 17
//      <q0.16>CH 16

//      <q0.15>CH 15  //ad_r2
//      <q0.14>CH 14  //cs13
//      <q0.13>CH 13  //cs11
//      <q0.12>CH 12  //cs8

//      <q0.11>CH 11  //cs5
//      <q0.10>CH 10  //cs2
//      <q0.9>CH 9
//      <q0.8>CH 8

//      <q0.7>CH 7   //cs15
//      <q0.6>CH 6   //cs12
//      <q0.5>CH 5   //cs10
//      <q0.4>CH 4   //cs7

//      <q0.3>CH 3   //cs6
//      <q0.2>CH 2   //cs3
//      <q0.1>CH 1   //cs1
//      <q0.0>CH 0
//    </h>
        .channel_en = 0x78FCFEU, 

//    <q0.0>Continuous convert enable
//    <i>Continuous convert enable
        .adco_en = (FunctionalState)0,

//    <q0.0>Interrupt enable
//    <i>Interrupt enable
        .int_en = (FunctionalState)0,

//    <o>Trigger Mode
//      <0x0=>software trigger
//      <0x1=>hardware trigger
//    <i>adc trigger mode select
        .trigger.trigger_mode = 0x0,

//    <o>Trigger source
//      <0x1=>NMI
//      <0x2=>PWM
//      <0x3=>RTC
//    <i>adc hardware trigger source
        .trigger.trigger_source = 0x3,

//    <o>PWM trigger delay<0x0-0xFFFF:0x1><#/0x1>
        .trigger.pwm_trigger_delay = 100,

//    <h>Compare config
//      <q0.0>Compare enable
//      <i>Compare enable
        .compare.compare_en = (FunctionalState)0x0,

//      <o>Compare condition
//        <0x0=>less
//        <0x1=>larger
//        <0x2=>between
//      <i>ADC compare condition select
        .compare.compare_condition = 2,

//      <o>Lower limit<0x0-0xFFF:0x1><#/0x1>
        .compare.lower_limit_val = 100,
        
//      <o>Higher limit<0x0-0xFFF:0x1><#/0x1>
        .compare.higher_limit_val = 3500
//    </h>
//  </e>
    };

    adc_init(adc_init_para);
#endif
}
#endif

#ifdef BF7x06AMxx_PWM_DRIVER_PRESENT
void pwm_config(void)
{
//  <e>PWM
#define PWM_CONFIG_EN 0
#if PWM_CONFIG_EN == 1
//    <e0>Channel 0
#define PWM_CH0_EN 0
#if PWM_CH0_EN == 1
//      <q0.6>Interrupt enable
//      <i>Channel interrupt enable

//      <o0.2..5>Mode select
//        <0x1=>Input Capture Mode  --  Rising Edge
//        <0x2=>Input Capture Mode  --  Falling Edge
//        <0x3=>Input Capture Mode  --  Rising / Falling Edge
//        <0x5=>Output Compare Mode  --  Toggle
//        <0x6=>Output Compare Mode  --  Clear
//        <0x7=>Output Compare Mode  --  Set
//        <0xA=>Edge / Center Aligned Mode  --  High-true pulse
//        <0x9=>Edge / Center Aligned Mode  --  Low-true pulse
//      <i>Channel mode select

//      <o1>Channel value<0x0-0xFFFF:0x1><#/0x1>
//    </e>
    pwm_ch0_init(0x28,0x0);
#endif

//    <e0>Channel 1
#define PWM_CH1_EN 0
#if PWM_CH1_EN == 1
//      <q0.6>Interrupt enable
//      <i>Channel interrupt enable

//      <o0.2..5>Mode select
//        <0x1=>Input Capture Mode  --  Rising Edge
//        <0x2=>Input Capture Mode  --  Falling Edge
//        <0x3=>Input Capture Mode  --  Rising / Falling Edge
//        <0x5=>Output Compare Mode  --  Toggle
//        <0x6=>Output Compare Mode  --  Clear
//        <0x7=>Output Compare Mode  --  Set
//        <0xA=>Edge / Center Aligned Mode  --  High-true pulse
//        <0x9=>Edge / Center Aligned Mode  --  Low-true pulse
//      <i>Channel mode select

//      <o1>Channel value<0x0-0xFFFF:0x1><#/0x1>
//    </e>
    pwm_ch1_init(0x28,0x0);
#endif

//    <e0>Channel 2
#define PWM_CH2_EN 0
#if PWM_CH2_EN == 1
//      <q0.6>Interrupt enable
//      <i>Channel interrupt enable

//      <o0.2..5>Mode select
//        <0x1=>Input Capture Mode  --  Rising Edge
//        <0x2=>Input Capture Mode  --  Falling Edge
//        <0x3=>Input Capture Mode  --  Rising / Falling Edge
//        <0x5=>Output Compare Mode  --  Toggle
//        <0x6=>Output Compare Mode  --  Clear
//        <0x7=>Output Compare Mode  --  Set
//        <0xA=>Edge / Center Aligned Mode  --  High-true pulse
//        <0x9=>Edge / Center Aligned Mode  --  Low-true pulse
//      <i>Channel mode select

//      <o1>Channel value<0x0-0xFFFF:0x1><#/0x1>
//    </e>
    pwm_ch2_init(0x28,0x0);
#endif

//    <e0>Channel 3
#define PWM_CH3_EN 0
#if PWM_CH3_EN == 1
//      <q0.6>Interrupt enable
//      <i>Channel interrupt enable

//      <o0.2..5>Mode select
//        <0x1=>Input Capture Mode  --  Rising Edge
//        <0x2=>Input Capture Mode  --  Falling Edge
//        <0x3=>Input Capture Mode  --  Rising / Falling Edge
//        <0x5=>Output Compare Mode  --  Toggle
//        <0x6=>Output Compare Mode  --  Clear
//        <0x7=>Output Compare Mode  --  Set
//        <0xA=>Edge / Center Aligned Mode  --  High-true pulse
//        <0x9=>Edge / Center Aligned Mode  --  Low-true pulse
//      <i>Channel mode select

//      <o1>Channel value<0x0-0xFFFF:0x1><#/0x1>
//    </e>
    pwm_ch3_init(0x28,0x0);
#endif

//    <e0>Channel 4
#define PWM_CH4_EN 0
#if PWM_CH4_EN == 1
//      <q0.6>Interrupt enable
//      <i>Channel interrupt enable

//      <o0.2..5>Mode select
//        <0x1=>Input Capture Mode  --  Rising Edge
//        <0x2=>Input Capture Mode  --  Falling Edge
//        <0x3=>Input Capture Mode  --  Rising / Falling Edge
//        <0x5=>Output Compare Mode  --  Toggle
//        <0x6=>Output Compare Mode  --  Clear
//        <0x7=>Output Compare Mode  --  Set
//        <0xA=>Edge / Center Aligned Mode  --  High-true pulse
//        <0x9=>Edge / Center Aligned Mode  --  Low-true pulse
//      <i>Channel mode select

//      <o1>Channel value<0x0-0xFFFF:0x1><#/0x1>
//    </e>
    pwm_ch4_init(0x28,0x0);
#endif

//    <e0>Channel 5
#define PWM_CH5_EN 0
#if PWM_CH5_EN == 1
//      <q0.6>Interrupt enable
//      <i>Channel interrupt enable

//      <o0.2..5>Mode select
//        <0x1=>Input Capture Mode  --  Rising Edge
//        <0x2=>Input Capture Mode  --  Falling Edge
//        <0x3=>Input Capture Mode  --  Rising / Falling Edge
//        <0x5=>Output Compare Mode  --  Toggle
//        <0x6=>Output Compare Mode  --  Clear
//        <0x7=>Output Compare Mode  --  Set
//        <0xA=>Edge / Center Aligned Mode  --  High-true pulse
//        <0x9=>Edge / Center Aligned Mode  --  Low-true pulse
//      <i>Channel mode select

//      <o1>Channel value<0x0-0xFFFF:0x1><#/0x1>
//    </e>
    pwm_ch5_init(0x28,0x0);
#endif
//    <h> PWM counter
//      <o0.3..4>Clock select
//        <0x0=>Off
//        <0x1=>System Clock
//        <0x2=>System Clock
//        <0x3=>External input clock
//      <i>PWM clock select

//      <o0.0..2>Clock divide parameter
//        <0x0=> / 1
//        <0x1=> / 2
//        <0x2=> / 4
//        <0x3=> / 8
//        <0x4=> / 16
//        <0x5=> / 32
//        <0x6=> / 64
//        <0x7=> / 128
//      <i>PWM clock divide parameter

//      <o0.5>Count direction
//        <0x0=>Up Counting
//        <0x1=>Up-Down Counting
//      <i>PWM count direction select

//      <q0.6>Interrupt enable
//      <i>PWM overflow interrupt enable

//      <o1>Modulo<0x0-0xFFFF:0x1><#/0x1>
//    </h>
//  </e>
    pwm_init(0x09,0x4000);
#endif
}
#endif

#ifdef BF7x06AMxx_WDT_DRIVER_PRESENT
void wdt_cfg(void)
{
//  <e>WDT
#define WDT_CONFIG_EN 1
#if WDT_CONFIG_EN == 1
//    <o0.8>Clock select
//      <0x0=>1KHz internal clock
//      <0x1=>32KHz internal clock
//    <i>WDT clock select

//    <q0.15>Window mode enable
//    <i>WDT window mode enable

//    <q0.7>WDT enable
//    <i>WDT enable

//    <q0.5>Update enable
//    <i>WDT update enable

//    <q0.1>Enable in sleep mode
//    <i>WDT enable in sleep mode

//    <q0.0>Enable in deep sleep mode
//    <i>WDT enable in deep sleep mode
    wdt_config(0x020);//0b0000 0001 0010 0000

//    <o>Overflow count<0x0-0xFFFF:0x1><#/0x1>
    wdt_overflow_count(0x0);
//    <o>Window mode overflow count<0x0-0xFFFF:0x1><#/0x1>
    wdt_overflow_count_win(0x0);
//  </e>
#endif
}
#endif

#ifdef BF7x06AMxx_TIMER_DRIVER_PRESENT
void timer_config(void)
{
//  <e>Timer
#define TIMER_CONFIG_EN 1
#if TIMER_CONFIG_EN == 1
//    <e0>Timer 0
#define TIMER0_EN 1
#if TIMER0_EN == 1
//      <o0.2>Clock select
//        <0x0=>System clock
//        <0x1=>RC32KHz
//      <i>TIMER clock select

//      <o0.3..4>Clock divide
//        <0x0=>System clock / 1
//        <0x1=>System clock / 2
//        <0x2=>System clock / 4
//        <0x3=>System clock / 8
//      <i>TIMER clock divide parameter (only when using system clock)

//      <o0.1>Auto reload mode select
//        <0x0=>Manual reload
//        <0x1=>Auto reload
//      <i>Timer auto reload mode select

//      <q0.5>Interrupt enable
//      <i>TIMER interrupt enable

//      <q0.0>Enable
//      <i>TIMER enable

//      <o1>Modulo<0x0-0xFFFF:0x1><#/0x1>
//    </e>
    timer_init(TIMER0,0x7B,4000); // 0111 1010  32MHz/8/4000 = 1000Hz --> 1ms
#endif

//    <e>Timer 1
#define TIMER1_EN 1
#if TIMER1_EN == 1
//      <o0.2>Clock select
//        <0x0=>System clock
//        <0x1=>RC32KHz
//      <i>TIMER clock select

//      <o0.3..4>Clock divide
//        <0x0=>System clock / 1
//        <0x1=>System clock / 2
//        <0x2=>System clock / 4
//        <0x3=>System clock / 8
//      <i>TIMER clock divide parameter (only when using system clock)

//      <o0.1>Auto reload mode select
//        <0x0=>Manual reload
//        <0x1=>Auto reload
//      <i>Timer auto reload mode select

//      <q0.5>Interrupt enable
//      <i>TIMER interrupt enable

//      <q0.0>Enable
//      <i>TIMER enable

//      <o1>Modulo<0x0-0xFFFF:0x1><#/0x1>
//    </e>
//  </e>
    timer_init(TIMER1,0x7A,400); // 0111 1011  32MHz/8/400 = 10KHz  //start
#endif
#endif
}
#endif

#ifdef BF7x06AMxx_RTC_DRIVER_PRESENT
void rtc_config(void)
{
//  <e>RTC
#define RTC_CONFIG_EN 1
#if RTC_CONFIG_EN == 1
//    <o0.5..6>Clock select
//      <0x0=>1KHz
//      <0x1=>XTAL / 32
//      <0x2=>Internal 32KHz clock
//      <0x3=>Internal 32KHz clock
//    <i>RTC clock select

//    <q0.4>Interrupt enable
//    <i>TIMER interrupt enable

//    <q0.9>Enable
//    <i>TIMER enable

//    <o1>Modulo<0x0-0xFFFFFFFF:0x1><#/0x1>
//    <i>RTC mod should not be set less than 3
//  </e>
	rtc_init(0x230,25000); //0000_0010_0011_0000 10Hz = 8M/32/25000;
#endif
}
#endif

#ifdef BF7x06AMxx_GPIO_DRIVER_PRESENT
void gpio_config(void)
{
#define ONE_BIT(x) (0x1 << x)

//  <e> GPIO
#define GPIO_CONFIG_EN 1
#if GPIO_CONFIG_EN == 1
//    <e0>NMI
#define NMI_EN 0
#if NMI_EN == 1
//      <o0>Trigger Mode
//        <0x00=>Falling edge
//        <0x20=>Rising edge
//        <0x21=>High level
//        <0x01=>Low level
//      <i>Configure NMI triggermode
//    </e>
    nmi_init(0x20,ENABLE);
#endif

//    <e0>PA
#define PA_EN 1
#if PA_EN == 1
//      <e16.7>PIN 7
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PA_7_INOUT_MODE 2

//        <q16.7>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PA_7_TRIGGER_MODE 2
//      </e>

//      <e14.6>PIN 6
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PA_6_INOUT_MODE 2

//        <q14.6>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PA_6_TRIGGER_MODE 2
//      </e>

//      <e12.5>PIN 5
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PA_5_INOUT_MODE 2

//        <q12.5>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PA_5_TRIGGER_MODE 2
//      </e>

//      <e10.4>PIN 4
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PA_4_INOUT_MODE 2

//        <q10.4>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PA_4_TRIGGER_MODE 2
//      </e>

//      <e8.3>PIN 3
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PA_3_INOUT_MODE 2

//        <q8.3>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PA_3_TRIGGER_MODE 2
//      </e>

//      <e6.2>PIN 2
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PA_2_INOUT_MODE 2

//        <q6.2>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PA_2_TRIGGER_MODE 2
//      </e>

//      <e4.1>PIN 1
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PA_1_INOUT_MODE 2

//        <q4.1>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PA_1_TRIGGER_MODE 2
//      </e>

//      <e2.0>PIN 0
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PA_0_INOUT_MODE 2

//        <q2.0>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PA_0_TRIGGER_MODE 2
//      </e>
//    </e>
#define PA_PIN 0x01
#define PA_IE 0x00

// init PA group
#if PA_PIN & ONE_BIT(7)         //PIN7
    gpio_init(GPIOA,(GPIO_MODE)PA_7_INOUT_MODE,GPIO_PIN_7);
#endif
#if PA_PIN & ONE_BIT(6)         //PIN6
    gpio_init(GPIOA,(GPIO_MODE)PA_6_INOUT_MODE,GPIO_PIN_6);
#endif
#if PA_PIN & ONE_BIT(5)         //PIN5
    gpio_init(GPIOA,(GPIO_MODE)PA_5_INOUT_MODE,GPIO_PIN_5);
#endif
#if PA_PIN & ONE_BIT(4)         //PIN4
    gpio_init(GPIOA,(GPIO_MODE)PA_4_INOUT_MODE,GPIO_PIN_4);
#endif
#if PA_PIN & ONE_BIT(3)         //PIN3
    gpio_init(GPIOA,(GPIO_MODE)PA_3_INOUT_MODE,GPIO_PIN_3);
#endif
#if PA_PIN & ONE_BIT(2)         //PIN2
    gpio_init(GPIOA,(GPIO_MODE)PA_2_INOUT_MODE,GPIO_PIN_2);
#endif
#if PA_PIN & ONE_BIT(1)         //PIN1
    gpio_init(GPIOA,(GPIO_MODE)PA_1_INOUT_MODE,GPIO_PIN_1);
#endif
#if PA_PIN & ONE_BIT(0)         //PIN0
    gpio_init(GPIOA,(GPIO_MODE)PA_0_INOUT_MODE,GPIO_PIN_0);
#endif

// Interrupt enable
#if PA_IE & ONE_BIT(7)         //PIN7
    gpio_trigge_mode(GPIOA,(GPIO_TRG_MODE)PA_7_TRIGGER_MODE,GPIO_PIN_7);
    gpio_interrupt_set(GPIOA,GPIO_PIN_7,ENABLE);
#endif
#if PA_IE & ONE_BIT(6)         //PIN6
    gpio_trigge_mode(GPIOA,(GPIO_TRG_MODE)PA_6_TRIGGER_MODE,GPIO_PIN_6);
    gpio_interrupt_set(GPIOA,GPIO_PIN_6,ENABLE);
#endif
#if PA_IE & ONE_BIT(5)         //PIN5
    gpio_trigge_mode(GPIOA,(GPIO_TRG_MODE)PA_5_TRIGGER_MODE,GPIO_PIN_5);
    gpio_interrupt_set(GPIOA,GPIO_PIN_5,ENABLE);
#endif
#if PA_IE & ONE_BIT(4)         //PIN4
    gpio_trigge_mode(GPIOA,(GPIO_TRG_MODE)PA_4_TRIGGER_MODE,GPIO_PIN_4);
    gpio_interrupt_set(GPIOA,GPIO_PIN_4,ENABLE);
#endif
#if PA_IE & ONE_BIT(3)         //PIN3
    gpio_trigge_mode(GPIOA,(GPIO_TRG_MODE)PA_3_TRIGGER_MODE,GPIO_PIN_3);
    gpio_interrupt_set(GPIOA,GPIO_PIN_3,ENABLE);
#endif
#if PA_IE & ONE_BIT(2)         //PIN2
    gpio_trigge_mode(GPIOA,(GPIO_TRG_MODE)PA_2_TRIGGER_MODE,GPIO_PIN_2);
    gpio_interrupt_set(GPIOA,GPIO_PIN_2,ENABLE);
#endif
#if PA_IE & ONE_BIT(1)         //PIN1
    gpio_trigge_mode(GPIOA,(GPIO_TRG_MODE)PA_1_TRIGGER_MODE,GPIO_PIN_1);
    gpio_interrupt_set(GPIOA,GPIO_PIN_1,ENABLE);
#endif
#if PA_IE & ONE_BIT(0)         //PIN0
    gpio_trigge_mode(GPIOA,(GPIO_TRG_MODE)PA_0_TRIGGER_MODE,GPIO_PIN_0);
    gpio_interrupt_set(GPIOA,GPIO_PIN_0,ENABLE);
#endif
#endif  // #if PA_EN == 1


//    <e0>PB
#define PB_EN 1
#if PB_EN == 1
//      <e16.7>PIN 7
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PB_7_INOUT_MODE 2

//        <q16.7>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PB_7_TRIGGER_MODE 2
//      </e>

//      <e14.6>PIN 6
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PB_6_INOUT_MODE 2

//        <q14.6>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PB_6_TRIGGER_MODE 2
//      </e>

//      <e12.5>PIN 5
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PB_5_INOUT_MODE 2

//        <q12.5>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PB_5_TRIGGER_MODE 2
//      </e>

//      <e10.4>PIN 4
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PB_4_INOUT_MODE 2

//        <q10.4>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PB_4_TRIGGER_MODE 2
//      </e>

//      <e8.3>PIN 3
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PB_3_INOUT_MODE 0

//        <q8.3>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PB_3_TRIGGER_MODE 0
//      </e>

//      <e6.2>PIN 2
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PB_2_INOUT_MODE 2

//        <q6.2>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PB_2_TRIGGER_MODE 2
//      </e>

//      <e4.1>PIN 1
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PB_1_INOUT_MODE 2

//        <q4.1>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PB_1_TRIGGER_MODE 2
//      </e>

//      <e2.0>PIN 0
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PB_0_INOUT_MODE 2

//        <q2.0>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PB_0_TRIGGER_MODE 2
//      </e>
//    </e>
#define PB_PIN 0x03
#define PB_IE 0x00

// init PB group
#if PB_PIN & ONE_BIT(7)         //PIN7
    gpio_init(GPIOB,(GPIO_MODE)PB_7_INOUT_MODE,GPIO_PIN_7);
#endif
#if PB_PIN & ONE_BIT(6)         //PIN6
    gpio_init(GPIOB,(GPIO_MODE)PB_6_INOUT_MODE,GPIO_PIN_6);
#endif
#if PB_PIN & ONE_BIT(5)         //PIN5
    gpio_init(GPIOB,(GPIO_MODE)PB_5_INOUT_MODE,GPIO_PIN_5);
#endif
#if PB_PIN & ONE_BIT(4)         //PIN4
    gpio_init(GPIOB,(GPIO_MODE)PB_4_INOUT_MODE,GPIO_PIN_4);
#endif
#if PB_PIN & ONE_BIT(3)         //PIN3
    gpio_init(GPIOB,(GPIO_MODE)PB_3_INOUT_MODE,GPIO_PIN_3);
#endif
#if PB_PIN & ONE_BIT(2)         //PIN2
    gpio_init(GPIOB,(GPIO_MODE)PB_2_INOUT_MODE,GPIO_PIN_2);
#endif
#if PB_PIN & ONE_BIT(1)         //PIN1
    gpio_init(GPIOB,(GPIO_MODE)PB_1_INOUT_MODE,GPIO_PIN_1);
#endif
#if PB_PIN & ONE_BIT(0)         //PIN0
    gpio_init(GPIOB,(GPIO_MODE)PB_0_INOUT_MODE,GPIO_PIN_0);
#endif

// Interrupt enable
#if PB_IE & ONE_BIT(7)         //PIN7
    gpio_trigge_mode(GPIOB,(GPIO_TRG_MODE)PB_7_TRIGGER_MODE,GPIO_PIN_7);
    gpio_interrupt_set(GPIOB,GPIO_PIN_7,ENABLE);
#endif
#if PB_IE & ONE_BIT(6)         //PIN6
    gpio_trigge_mode(GPIOB,(GPIO_TRG_MODE)PB_6_TRIGGER_MODE,GPIO_PIN_6);
    gpio_interrupt_set(GPIOB,GPIO_PIN_6,ENABLE);
#endif
#if PB_IE & ONE_BIT(5)         //PIN5
    gpio_trigge_mode(GPIOB,(GPIO_TRG_MODE)PB_5_TRIGGER_MODE,GPIO_PIN_5);
    gpio_interrupt_set(GPIOB,GPIO_PIN_5,ENABLE);
#endif
#if PB_IE & ONE_BIT(4)         //PIN4
    gpio_trigge_mode(GPIOB,(GPIO_TRG_MODE)PB_4_TRIGGER_MODE,GPIO_PIN_4);
    gpio_interrupt_set(GPIOB,GPIO_PIN_4,ENABLE);
#endif
#if PB_IE & ONE_BIT(3)         //PIN3
    gpio_trigge_mode(GPIOB,(GPIO_TRG_MODE)PB_3_TRIGGER_MODE,GPIO_PIN_3);
    gpio_interrupt_set(GPIOB,GPIO_PIN_3,ENABLE);
#endif
#if PB_IE & ONE_BIT(2)         //PIN2
    gpio_trigge_mode(GPIOB,(GPIO_TRG_MODE)PB_2_TRIGGER_MODE,GPIO_PIN_2);
    gpio_interrupt_set(GPIOB,GPIO_PIN_2,ENABLE);
#endif
#if PB_IE & ONE_BIT(1)         //PIN1
    gpio_trigge_mode(GPIOB,(GPIO_TRG_MODE)PB_1_TRIGGER_MODE,GPIO_PIN_1);
    gpio_interrupt_set(GPIOB,GPIO_PIN_1,ENABLE);
#endif
#if PB_IE & ONE_BIT(0)         //PIN0
    gpio_trigge_mode(GPIOB,(GPIO_TRG_MODE)PB_0_TRIGGER_MODE,GPIO_PIN_0);
    gpio_interrupt_set(GPIOB,GPIO_PIN_0,ENABLE);
#endif
#endif  // #if PB_EN == 1


//    <e0>PC
#define PC_EN 1
#if PC_EN == 1
//      <e8.7>PIN 7
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PC_7_INOUT_MODE 2

//      <e7.6>PIN 6
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PC_6_INOUT_MODE 2

//      <e6.5>PIN 5
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PC_5_INOUT_MODE 2

//      <e5.4>PIN 4
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PC_4_INOUT_MODE 2

//      <e4.3>PIN 3
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PC_3_INOUT_MODE 2

//      <e3.2>PIN 2
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PC_2_INOUT_MODE 2


//      <e2.1>PIN 1
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PC_1_INOUT_MODE 2

//      <e1.0>PIN 0
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
//    </e>
#define PC_0_INOUT_MODE 2

#define PC_PIN 0x07

// init PC group
#if PC_PIN & ONE_BIT(7)         //PIN7
    gpio_init(GPIOC,(GPIO_MODE)PC_7_INOUT_MODE,GPIO_PIN_7);
#endif
#if PC_PIN & ONE_BIT(6)         //PIN6
    gpio_init(GPIOC,(GPIO_MODE)PC_6_INOUT_MODE,GPIO_PIN_6);
#endif
#if PC_PIN & ONE_BIT(5)         //PIN5
    gpio_init(GPIOC,(GPIO_MODE)PC_5_INOUT_MODE,GPIO_PIN_5);
#endif
#if PC_PIN & ONE_BIT(4)         //PIN4
    gpio_init(GPIOC,(GPIO_MODE)PC_4_INOUT_MODE,GPIO_PIN_4);
#endif
#if PC_PIN & ONE_BIT(3)         //PIN3
    gpio_init(GPIOC,(GPIO_MODE)PC_3_INOUT_MODE,GPIO_PIN_3);
#endif
#if PC_PIN & ONE_BIT(2)         //PIN2
    gpio_init(GPIOC,(GPIO_MODE)PC_2_INOUT_MODE,GPIO_PIN_2);
#endif
#if PC_PIN & ONE_BIT(1)         //PIN1
    gpio_init(GPIOC,(GPIO_MODE)PC_1_INOUT_MODE,GPIO_PIN_1);
#endif
#if PC_PIN & ONE_BIT(0)         //PIN0
    gpio_init(GPIOC,(GPIO_MODE)PC_0_INOUT_MODE,GPIO_PIN_0);
#endif
#endif  // #if PC_EN == 1


//    <e0>PD
#define PD_EN 1
#if PD_EN == 1
//      <e16.7>PIN 7
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PD_7_INOUT_MODE 2

//        <q16.7>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PD_7_TRIGGER_MODE 2
//      </e>

//      <e14.6>PIN 6
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PD_6_INOUT_MODE 2

//        <q14.6>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PD_6_TRIGGER_MODE 2
//      </e>

//      <e12.5>PIN 5
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PD_5_INOUT_MODE 2

//        <q12.5>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PD_5_TRIGGER_MODE 2
//      </e>

//      <e10.4>PIN 4
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PD_4_INOUT_MODE 2

//        <q10.4>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PD_4_TRIGGER_MODE 2
//      </e>

//      <e8.3>PIN 3
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PD_3_INOUT_MODE 2

//        <q8.3>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PD_3_TRIGGER_MODE 2
//      </e>

//      <e6.2>PIN 2
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PD_2_INOUT_MODE 2

//        <q6.2>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PD_2_TRIGGER_MODE 2
//      </e>

//      <e4.1>PIN 1
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PD_1_INOUT_MODE 2

//        <q4.1>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PD_1_TRIGGER_MODE 2
//      </e>

//      <e2.0>PIN 0
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
#define PD_0_INOUT_MODE 1

//        <q2.0>Interrup enable
//        <o>Trigger mode
//          <0x0=>High level
//          <0x1=>Low level
//          <0x2=>Rising edge
//          <0x3=>Falling edge
//        <i>Configure GPIO trigger mode
#define PD_0_TRIGGER_MODE 2
//      </e>
//    </e>
#define PD_PIN 0xFD
#define PD_IE 0x01

// init PD group
#if PD_PIN & ONE_BIT(7)         //PIN7
    gpio_init(GPIOD,(GPIO_MODE)PD_7_INOUT_MODE,GPIO_PIN_7);
#endif
#if PD_PIN & ONE_BIT(6)         //PIN6
    gpio_init(GPIOD,(GPIO_MODE)PD_6_INOUT_MODE,GPIO_PIN_6);
#endif
#if PD_PIN & ONE_BIT(5)         //PIN5
    gpio_init(GPIOD,(GPIO_MODE)PD_5_INOUT_MODE,GPIO_PIN_5);
#endif
#if PD_PIN & ONE_BIT(4)         //PIN4
    gpio_init(GPIOD,(GPIO_MODE)PD_4_INOUT_MODE,GPIO_PIN_4);
#endif
#if PD_PIN & ONE_BIT(3)         //PIN3
    gpio_init(GPIOD,(GPIO_MODE)PD_3_INOUT_MODE,GPIO_PIN_3);
#endif
#if PD_PIN & ONE_BIT(2)         //PIN2
    gpio_init(GPIOD,(GPIO_MODE)PD_2_INOUT_MODE,GPIO_PIN_2);
#endif
#if PD_PIN & ONE_BIT(1)         //PIN1
    gpio_init(GPIOD,(GPIO_MODE)PD_1_INOUT_MODE,GPIO_PIN_1);
#endif
#if PD_PIN & ONE_BIT(0)         //PIN0
    gpio_init(GPIOD,(GPIO_MODE)PD_0_INOUT_MODE,GPIO_PIN_0);
#endif

// Interrupt enable
#if PD_IE & ONE_BIT(7)         //PIN7
    gpio_trigge_mode(GPIOD,(GPIO_TRG_MODE)PD_7_TRIGGER_MODE,GPIO_PIN_7);
    gpio_interrupt_set(GPIOD,GPIO_PIN_7,ENABLE);
#endif
#if PD_IE & ONE_BIT(6)         //PIN6
    gpio_trigge_mode(GPIOD,(GPIO_TRG_MODE)PD_6_TRIGGER_MODE,GPIO_PIN_6);
    gpio_interrupt_set(GPIOD,GPIO_PIN_6,ENABLE);
#endif
#if PD_IE & ONE_BIT(5)         //PIN5
    gpio_trigge_mode(GPIOD,(GPIO_TRG_MODE)PD_5_TRIGGER_MODE,GPIO_PIN_5);
    gpio_interrupt_set(GPIOD,GPIO_PIN_5,ENABLE);
#endif
#if PD_IE & ONE_BIT(4)         //PIN4
    gpio_trigge_mode(GPIOD,(GPIO_TRG_MODE)PD_4_TRIGGER_MODE,GPIO_PIN_4);
    gpio_interrupt_set(GPIOD,GPIO_PIN_4,ENABLE);
#endif
#if PD_IE & ONE_BIT(3)         //PIN3
    gpio_trigge_mode(GPIOD,(GPIO_TRG_MODE)PD_3_TRIGGER_MODE,GPIO_PIN_3);
    gpio_interrupt_set(GPIOD,GPIO_PIN_3,ENABLE);
#endif
#if PD_IE & ONE_BIT(2)         //PIN2
    gpio_trigge_mode(GPIOD,(GPIO_TRG_MODE)PD_2_TRIGGER_MODE,GPIO_PIN_2);
    gpio_interrupt_set(GPIOD,GPIO_PIN_2,ENABLE);
#endif
#if PD_IE & ONE_BIT(1)         //PIN1
    gpio_trigge_mode(GPIOD,(GPIO_TRG_MODE)PD_1_TRIGGER_MODE,GPIO_PIN_1);
    gpio_interrupt_set(GPIOD,GPIO_PIN_1,ENABLE);
#endif
#if PD_IE & ONE_BIT(0)         //PIN0
    gpio_trigge_mode(GPIOD,(GPIO_TRG_MODE)PD_0_TRIGGER_MODE,GPIO_PIN_0);
    gpio_interrupt_set(GPIOD,GPIO_PIN_0,ENABLE);
#endif
#endif  // #if PD_EN == 1


//    <e0>PE
#define PE_EN 1
#if PE_EN == 1
//      <e8.7>PIN 7
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PE_7_INOUT_MODE 2

//      <e7.6>PIN 6
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PE_6_INOUT_MODE 2

//      <e6.5>PIN 5
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PE_5_INOUT_MODE 1

//      <e5.4>PIN 4
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PE_4_INOUT_MODE 1

//      <e4.3>PIN 3
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PE_3_INOUT_MODE 1

//      <e3.2>PIN 2
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PE_2_INOUT_MODE 2


//      <e2.1>PIN 1
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PE_1_INOUT_MODE 2

//      <e1.0>PIN 0
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
//    </e>
#define PE_0_INOUT_MODE 2

#define PE_PIN 0x3D

// init PE group
#if PE_PIN & ONE_BIT(7)         //PIN7
    gpio_init(GPIOE,(GPIO_MODE)PE_7_INOUT_MODE,GPIO_PIN_7);
#endif
#if PE_PIN & ONE_BIT(6)         //PIN6
    gpio_init(GPIOE,(GPIO_MODE)PE_6_INOUT_MODE,GPIO_PIN_6);
#endif
#if PE_PIN & ONE_BIT(5)         //PIN5
    gpio_init(GPIOE,(GPIO_MODE)PE_5_INOUT_MODE,GPIO_PIN_5);
#endif
#if PE_PIN & ONE_BIT(4)         //PIN4
    gpio_init(GPIOE,(GPIO_MODE)PE_4_INOUT_MODE,GPIO_PIN_4);
#endif
#if PE_PIN & ONE_BIT(3)         //PIN3
    gpio_init(GPIOE,(GPIO_MODE)PE_3_INOUT_MODE,GPIO_PIN_3);
#endif
#if PE_PIN & ONE_BIT(2)         //PIN2
    gpio_init(GPIOE,(GPIO_MODE)PE_2_INOUT_MODE,GPIO_PIN_2);
#endif
#if PE_PIN & ONE_BIT(1)         //PIN1
    gpio_init(GPIOE,(GPIO_MODE)PE_1_INOUT_MODE,GPIO_PIN_1);
#endif
#if PE_PIN & ONE_BIT(0)         //PIN0
    gpio_init(GPIOE,(GPIO_MODE)PE_0_INOUT_MODE,GPIO_PIN_0);
#endif
#endif  // #if PE_EN == 1


//    <e0>PF
#define PF_EN 1
#if PF_EN == 1
//      <e8.7>PIN 7
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PF_7_INOUT_MODE 2

//      <e7.6>PIN 6
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PF_6_INOUT_MODE 2

//      <e6.5>PIN 5
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PF_5_INOUT_MODE 2

//      <e5.4>PIN 4
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PF_4_INOUT_MODE 2

//      <e4.3>PIN 3
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PF_3_INOUT_MODE 2

//      <e3.2>PIN 2
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PF_2_INOUT_MODE 2


//      <e2.1>PIN 1
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PF_1_INOUT_MODE 2

//      <e1.0>PIN 0
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
//    </e>
#define PF_0_INOUT_MODE 2

#define PF_PIN 0xD4

// init PF group
#if PF_PIN & ONE_BIT(7)         //PIN7
    gpio_init(GPIOF,(GPIO_MODE)PF_7_INOUT_MODE,GPIO_PIN_7);
#endif
#if PF_PIN & ONE_BIT(6)         //PIN6
    gpio_init(GPIOF,(GPIO_MODE)PF_6_INOUT_MODE,GPIO_PIN_6);
#endif
#if PF_PIN & ONE_BIT(5)         //PIN5
    gpio_init(GPIOF,(GPIO_MODE)PF_5_INOUT_MODE,GPIO_PIN_5);
#endif
#if PF_PIN & ONE_BIT(4)         //PIN4
    gpio_init(GPIOF,(GPIO_MODE)PF_4_INOUT_MODE,GPIO_PIN_4);
#endif
#if PF_PIN & ONE_BIT(3)         //PIN3
    gpio_init(GPIOF,(GPIO_MODE)PF_3_INOUT_MODE,GPIO_PIN_3);
#endif
#if PF_PIN & ONE_BIT(2)         //PIN2
    gpio_init(GPIOF,(GPIO_MODE)PF_2_INOUT_MODE,GPIO_PIN_2);
#endif
#if PF_PIN & ONE_BIT(1)         //PIN1
    gpio_init(GPIOF,(GPIO_MODE)PF_1_INOUT_MODE,GPIO_PIN_1);
#endif
#if PF_PIN & ONE_BIT(0)         //PIN0
    gpio_init(GPIOF,(GPIO_MODE)PF_0_INOUT_MODE,GPIO_PIN_0);
#endif
#endif  // #if PF_EN == 1


//    <e0>PG
#define PG_EN 1
#if PG_EN == 1
//      <e8.7>PIN 7
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PG_7_INOUT_MODE 2

//      <e7.6>PIN 6
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PG_6_INOUT_MODE 2

//      <e6.5>PIN 5
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PG_5_INOUT_MODE 2

//      <e5.4>PIN 4
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PG_4_INOUT_MODE 2

//      <e4.3>PIN 3
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PG_3_INOUT_MODE 2

//      <e3.2>PIN 2
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PG_2_INOUT_MODE 2


//      <e2.1>PIN 1
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
#define PG_1_INOUT_MODE 2

//      <e1.0>PIN 0
//        <o>Mode
//          <0x0=>Floating
//          <0x1=>Pull up
//          <0x2=>Out
//        <i>Configure GPIO inout mode
//      </e>
//    </e>
//  </e>
#define PG_0_INOUT_MODE 2

#define PG_PIN 0x38

// init PG group
#if PG_PIN & ONE_BIT(7)         //PIN7
    gpio_init(GPIOG,(GPIO_MODE)PG_7_INOUT_MODE,GPIO_PIN_7);
#endif
#if PG_PIN & ONE_BIT(6)         //PIN6
    gpio_init(GPIOG,(GPIO_MODE)PG_6_INOUT_MODE,GPIO_PIN_6);
#endif
#if PG_PIN & ONE_BIT(5)         //PIN5
    gpio_init(GPIOG,(GPIO_MODE)PG_5_INOUT_MODE,GPIO_PIN_5);
#endif
#if PG_PIN & ONE_BIT(4)         //PIN4
    gpio_init(GPIOG,(GPIO_MODE)PG_4_INOUT_MODE,GPIO_PIN_4);
#endif
#if PG_PIN & ONE_BIT(3)         //PIN3
    gpio_init(GPIOG,(GPIO_MODE)PG_3_INOUT_MODE,GPIO_PIN_3);
#endif
#if PG_PIN & ONE_BIT(2)         //PIN2
    gpio_init(GPIOG,(GPIO_MODE)PG_2_INOUT_MODE,GPIO_PIN_2);
#endif
#if PG_PIN & ONE_BIT(1)         //PIN1
    gpio_init(GPIOG,(GPIO_MODE)PG_1_INOUT_MODE,GPIO_PIN_1);
#endif
#if PG_PIN & ONE_BIT(0)         //PIN0
    gpio_init(GPIOG,(GPIO_MODE)PG_0_INOUT_MODE,GPIO_PIN_0);
#endif
#endif  // #if PG_EN == 1
#endif
}
#endif

void peripherals_config(void)
{
#ifdef BF7x06AMxx_WDT_DRIVER_PRESENT
    wdt_cfg();
#endif

#ifdef BF7x06AMxx_SCI_DRIVER_PRESENT
    sci_config();
#endif

#ifdef BF7x06AMxx_CAN_DRIVER_PRESENT
    can_config();
#endif

#ifdef BF7x06AMxx_ADC_DRIVER_PRESENT
    adc_config();
#endif

#ifdef BF7x06AMxx_TIMER_DRIVER_PRESENT
    timer_config();
#endif

#ifdef BF7x06AMxx_RTC_DRIVER_PRESENT
    rtc_config();
#endif

#ifdef BF7x06AMxx_PWM_DRIVER_PRESENT
    pwm_config();
#endif

#ifdef BF7x06AMxx_GPIO_DRIVER_PRESENT
    gpio_config();
#endif
}

//------------- <<< end of configuration section >>> ---------------------------
