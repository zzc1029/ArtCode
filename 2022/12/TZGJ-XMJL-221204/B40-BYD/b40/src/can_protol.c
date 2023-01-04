#include "includes.h"
#include "adc.h"
#include "power_out.h"
#include "pluse.h"
#include "switch.h"
#include "canhl.h"
#include "eeprom.h"

uint8_t flag_can;
uint8_t flag_can_enable = 1;

can_frame canrx;

uint8_t KEY_ON, KEY_ACC, KEY_SOS;

static struct pt ptx;
/**
 * The second protothread function. This is almost the same as the
 * first one.
 */
int protothread_can(struct pt *pt)
{
	PT_BEGIN(pt);

	uint8_t data[8];
	static uint32_t time;
	static uint8_t count = 0;

	/* We loop forever here. */
	while (1)
	{
		time = systick_ms + 100;
		{
			uint16_t speed = freq * 3600 / param.pluse;
			data[0] = in_sw[0];
			data[1] = in_sw[1];
			data[2] = in_sw[2];
			data[3] = freq;
			data[4] = freq >> 8;
			data[5] = speed;
			data[6] = speed >> 8;
			can_send_bytes(ID_TX_SW + MOD_ADDR, 0, data, 7);
		}

		count++;
		switch (count & 3)
		{
		case 0:
			data[0] = P25;
			data[1] = P25 >> 8;
			data[2] = P40;
			data[3] = P40 >> 8;
			// data[4] = P25_VOL;
			// data[5] = P25_VOL >> 8;
			// data[6] = P40_VOL;
			// data[7] = P40_VOL >> 8;
			can_send_bytes(ID_TX_AD + MOD_ADDR, 0, data, 8);
			break;
		case 1:
		{
			uint8_t i;
			uint8_t j;
			data[0] = 0;
			for (i = 0, j = 0; i < 8; i++, j++)
			{
				data[0] |= (PoutS[i].cmd) << i;
			}

			data[1] = 0;
			for (j = 0; i < POUT_COUNT; i++, j++)
			{
				data[1] |= (PoutS[i].cmd) << j;
			}
			data[1] |= OD_IN() << 7;

			data[2] = 0;
			for (i = 0, j = 0; i < 4; i++, j += 2)
			{
				data[2] |= (PoutS[i].diag) << j;
			}

			data[3] = 0;
			for (j = 0; i < 8; i++, j += 2)
			{
				data[3] |= (PoutS[i].diag) << j;
			}

			data[4] = 0;
			for (j = 0; i < 12; i++, j += 2)
			{
				data[4] |= (PoutS[i].diag) << j;
			}

			data[5] = 0;
			for (j = 0; i < POUT_COUNT; i++, j += 2)
			{
				data[5] |= (PoutS[i].diag) << j;
			}
			can_send_bytes(ID_TX_ST + MOD_ADDR, 0, data, 6);
		}
		break;
		case 2:
			data[0] = odo_100m;
			data[1] = odo_100m >> 8;
			data[2] = odo_100m >> 16;
			data[3] = odo_100m >> 24;
			data[4] = trip_100m;
			data[5] = trip_100m >> 8;
			data[6] = param.pluse;
			data[7] = param.pluse >> 8;
			can_send_bytes(ID_TX_MILE + MOD_ADDR, 0, data, 8);
			break;
#ifdef CURRENT_SEND
		case 3:
		{
			data[0] = PoutS[0].cur_100ma;
			data[1] = PoutS[1].cur_100ma;
			data[2] = PoutS[2].cur_100ma;
			data[3] = PoutS[3].cur_100ma;
			data[4] = PoutS[4].cur_100ma;
			data[5] = PoutS[5].cur_100ma;
			data[6] = PoutS[6].cur_100ma;
			data[7] = PoutS[7].cur_100ma;
			can_send_bytes(ID_TX_CURRENT + 2 * MOD_ADDR - 2, 0, data, 8);

			data[0] = PoutS[8].cur_100ma;
			data[1] = PoutS[9].cur_100ma;
			data[2] = PoutS[10].cur_100ma;
			data[3] = PoutS[11].cur_100ma;
			data[4] = PoutS[12].cur_100ma;
			data[5] = PoutS[13].cur_100ma;
			data[6] = PoutS[14].cur_100ma;
			can_send_bytes(ID_TX_CURRENT + 2 * MOD_ADDR - 1, 0, data, 7);
		}
		break;
#endif
		}

		wdt_clear();

		PT_WAIT_UNTIL(pt, ((int)(systick_ms - time) >= 0));
	}
	PT_INFINITE_LOOP_END(pt);
}

#define ORDER_VERSION_HELP(v) #v
#define VERSION(v) ORDER_VERSION_HELP(v)

#define ORDV_SIZE sizeof(ordv)
const static uint8_t date[] = __DATE__;			//当前编译日期（月、日、年）：此为字符串格式
const static uint8_t time[] = __TIME__;			//当前编译时间（时、分、秒）：此为字符串格式
const static uint8_t ordv[] = VERSION(ORDER_VERSION);

static const char *month[] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

static uint8_t SoftVer[8];

#define STRBIN2BCD(s, o, l) (((s[o] - '0') << 4) | (l))
#define STR2BCD(s, o) (((s[o] - '0') << 4) | (s[o + 1] - '0'))
#define BIN2BCD(b) (((b / 10) << 4) | (b % 10))

void InitSoftVer()
{
	int i;

	//	for(i = 0;((i<(sizeof(ordv)-1)) && (i<6));i+=2)
	//		SoftVer[i>>1] = STR2BCD(ordv, i);
	//
	//	if(i<sizeof(ordv))
	//		SoftVer[i>>1] = STRBIN2BCD(ordv, i, 0);
	//	i+=2;
	//
	//	for(;i<6;i+= 2)
	//		SoftVer[i>>1] = 0;

	SoftVer[0] = STR2BCD(ordv, 0);	//获取版本号转为BCD
	SoftVer[1] = STR2BCD(ordv, 2);
	SoftVer[2] = STR2BCD(ordv, 4);

	for (i = 0; i < 12; i++)
	{
		if ((date[0] == month[i][0]) && (date[1] == month[i][1]) && (date[2] == month[i][2]))
		{
			i++;
			SoftVer[3] = BIN2BCD(i);	 //获取月份并转为BCD，例如Oct转为10。
			break;
		}
	}
	SoftVer[4] = STR2BCD(date, 4); //获取日期并转为BCD，例如3转为03。
	SoftVer[5] = STR2BCD(time, 0); //获取小时并转为BCD，例如3转为03。
	SoftVer[6] = STR2BCD(time, 3); //获取分钟并转为BCD，例如59转为59。
	SoftVer[7] = STR2BCD(time, 6); //获取秒并转为BCD，例如59转为59。
}

INIT_APP_EXPORT(InitSoftVer);

int protothread_can_test(struct pt *pt)
{
	PT_BEGIN(pt);

	static uint32_t time;
	uint8_t data[8];

	/* We loop forever here. */
	while (1)
	{
		// 500ms
		data[0] = 6;
		data[1] = 5;
		data[2] = 0x23;
		data[3] = 0x11;
		data[4] = 0;
		data[5] = 0x19;
		data[6] = 0x05;
		data[7] = 0x14;
		can_send_bytes(0x52E, 0, data, 8);

		PT_DELAY_MS(pt, 500);
		/* And we loop. */
	}
	PT_INFINITE_LOOP_END(pt);
}

#include "string.h"
#include "rain.h"

#if 0
inline void dash_cmd_parse(uint16_t cmd, uint16_t cmd_ext)
{
	int i;

	KEY_ON = (cmd_ext & 0x10) > 0;
	KEY_ACC = (cmd_ext & 0x20) > 0;
	
#ifdef KEY_SOS_ENABLE
	KEY_SOS = (cmd_ext & 0x80) > 0;
#endif
	
#if SUPPORT_WIPER == 1
	if (MOD_ADDR == ADDR1_MOD)
		i = 2; //快档和慢档输出受雨刮逻辑控制，这边跳过
	else
#endif
		i = 0;

	for (; i < POUT_COUNT; i++)
	{
		if ((KEY_ON == 0) && (KEY_ACC == 0)
		#ifdef  KEY_SOS_ENABLE
			&& (KEY_SOS == 0)
		#endif
		)
		{
#ifdef PROTECTION_MAX_RETRY_COUNT_RESET
			PoutS[i].errcount = 0;
#endif

			switch (MOD_ADDR)
			{
			case ADDR1_MOD:
#ifdef LOGIC_OUTS_MOD1
				if (strstr(LOGIC_OUTS_MOD1, PoutS[i].name))
				{
					continue;
				}
#endif
#ifdef NORMOL_OUTS_MOD1
				if (strstr(NORMOL_OUTS_MOD1, PoutS[i].name))
				{
					PoutS[i].cmd = 1;
					continue;
				}
#endif
				break;
			case ADDR2_MOD:
#ifdef LOGIC_OUTS_MOD2
				if (strstr(LOGIC_OUTS_MOD2, PoutS[i].name))
				{
					continue;
				}
#endif
#ifdef NORMOL_OUTS_MOD2
				if (strstr(NORMOL_OUTS_MOD2, PoutS[i].name))
				{
					PoutS[i].cmd = 1;
					continue;
				}
#endif
				break;
			case ADDR3_MOD:
#ifdef LOGIC_OUTS_MOD3
				if (strstr(LOGIC_OUTS_MOD3, PoutS[i].name))
				{
					continue;
				}
#endif
#ifdef NORMOL_OUTS_MOD3
				if (strstr(NORMOL_OUTS_MOD3, PoutS[i].name))
				{
					PoutS[i].cmd = 1;
					continue;
				}
#endif
				break;
			case ADDR4_MOD:
#ifdef LOGIC_OUTS_MOD4
				if (strstr(LOGIC_OUTS_MOD4, PoutS[i].name))
				{
					continue;
				}
#endif
#ifdef NORMOL_OUTS_MOD4
				if (strstr(NORMOL_OUTS_MOD4, PoutS[i].name))
				{
					PoutS[i].cmd = 1;
					continue;
				}
#endif
				break;
			default:
				break;
			}
		}
		PoutS[i].cmd = ((cmd >> i) & 1) > 0;
	}
	
#if SUPPORT_WIPER == 1
	if (MOD_ADDR == ADDR1_MOD)
	{
		rain_cmd_parse(cmd_ext);
#ifdef RAIN_TEST
		extern uint8_t rain_test_delay;
		rain_test_delay = cmd_ext >> 8;
#endif
	}
#endif

	OD_OUT((cmd & 0x8000) > 0);
}
#endif

#if 1

#if SUPPORT_WIPER == 1
#ifndef WIPER_DISABLE
uint8_t WIPER_DISABLE = 0;
#endif
#endif

inline void dash_cmd_parse(uint16_t cmd, uint16_t cmd_ext)
{
	int i;

	KEY_ON = (cmd_ext & 0x10) > 0;
	KEY_ACC = (cmd_ext & 0x20) > 0;
	
#ifdef KEY_SOS_ENABLE
	KEY_SOS = (cmd_ext & 0x80) > 0;
#endif

#ifndef WIPER_DISABLE
  WIPER_DISABLE = (cmd_ext & 0x400) > 0;
#endif
	
#if SUPPORT_WIPER == 1
	if ((WIPER_DISABLE == 0) && (MOD_ADDR == ADDR1_MOD))
		i = 2; //快档和慢档输出受雨刮逻辑控制，这边跳过
	else
#endif
		i = 0;

	for (; i < POUT_COUNT; i++)
	{
		if ((KEY_ON == 0) && (KEY_ACC == 0)
		#ifdef  KEY_SOS_ENABLE
			&& (KEY_SOS == 0)
		#endif
		)
		{
#ifdef PROTECTION_MAX_RETRY_COUNT_RESET
			PoutS[i].errcount = 0;
#endif

			switch (MOD_ADDR)
			{
			case ADDR1_MOD:
#ifdef LOGIC_OUTS_MOD1
				if (strstr(LOGIC_OUTS_MOD1, PoutS[i].name))
				{
					continue;
				}
#endif
#ifdef NORMOL_OUTS_MOD1
				if (strstr(NORMOL_OUTS_MOD1, PoutS[i].name))
				{
					PoutS[i].cmd = 1;
					continue;
				}
#endif
				break;
			case ADDR2_MOD:
#ifdef LOGIC_OUTS_MOD2
				if (strstr(LOGIC_OUTS_MOD2, PoutS[i].name))
				{
					continue;
				}
#endif
#ifdef NORMOL_OUTS_MOD2
				if (strstr(NORMOL_OUTS_MOD2, PoutS[i].name))
				{
					PoutS[i].cmd = 1;
					continue;
				}
#endif
				break;
			case ADDR3_MOD:
#ifdef LOGIC_OUTS_MOD3
				if (strstr(LOGIC_OUTS_MOD3, PoutS[i].name))
				{
					continue;
				}
#endif
#ifdef NORMOL_OUTS_MOD3
				if (strstr(NORMOL_OUTS_MOD3, PoutS[i].name))
				{
					PoutS[i].cmd = 1;
					continue;
				}
#endif
				break;
			case ADDR4_MOD:
#ifdef LOGIC_OUTS_MOD4
				if (strstr(LOGIC_OUTS_MOD4, PoutS[i].name))
				{
					continue;
				}
#endif
#ifdef NORMOL_OUTS_MOD4
				if (strstr(NORMOL_OUTS_MOD4, PoutS[i].name))
				{
					PoutS[i].cmd = 1;
					continue;
				}
#endif
				break;
			default:
				break;
			}
		}
		PoutS[i].cmd = ((cmd >> i) & 1) > 0;
	}

#if SUPPORT_WIPER == 1
	if ((WIPER_DISABLE == 0) && (MOD_ADDR == ADDR1_MOD))
	{
		rain_cmd_parse(cmd_ext);
#ifdef RAIN_TEST
		extern uint8_t rain_test_delay;
		rain_test_delay = cmd_ext >> 8;
#endif
	}
#endif
	
	OD_OUT((cmd & 0x8000) > 0);
}

#endif

// typedef void (*CanFrameHandleFunc)(uint8_t data[8]);

// typedef struct _CanHandle{
//	uint32_t id;
//	uint8_t ext;
//	CanFrameHandleFunc  func;
// } CanHandle;

// CanHandle canhandles[10];

// for(i=0;i<10;i++)
//{
//	if(canhandles[i].func != 0)
//	{
//		if(frmae->id == canhandles[i].id)
//		{
//				canhandles[i].func(frame->data);
//		}
//	}
// }

#ifdef MOD1_SW_DATA
uint8_t sw_1[3];
#endif
#ifdef MOD2_SW_DATA
uint8_t sw_2[3];
#endif
#ifdef MOD3_SW_DATA
uint8_t sw_3[3];
#endif
#ifdef MOD4_SW_DATA
uint8_t sw_4[3];
#endif
int protothread_can_recv(struct pt *pt)
{
	PT_BEGIN(pt);
	static uint32_t timeout_6a4;
	static uint8_t data[8];
	static uint16_t cmd_ext;
	int i;

	timeout_6a4 = systick_ms + 4000;

	/* We loop forever here. */
	while (1)
	{
		PT_WAIT_UNTIL(pt, (can_frame_received() || ((int)(systick_ms - timeout_6a4) >= 0)));
		if (((int)(systick_ms - timeout_6a4) >= 0))
		{
			timeout_6a4 = systick_ms + 10000;
			cmd_ext = 0;
			dash_cmd_parse(0, cmd_ext);
		}

		if (can_frame_received())
		{
			can_recv_frame(&canrx);

			switch (canrx.id)
			{
#ifdef MOD1_SW_DATA
			case 0x681: // PWM
			{
				sw_1[0] = canrx.data[0];
				sw_1[1] = canrx.data[1];
				sw_1[2] = canrx.data[2];
			}
			break;
#endif
#ifdef MOD2_SW_DATA
			case 0x682: // PWM
			{
				sw_2[0] = canrx.data[0];
				sw_2[1] = canrx.data[1];
				sw_2[2] = canrx.data[2];
			}
			break;
#endif
#ifdef MOD3_SW_DATA
			case 0x683: // PWM
			{
				sw_3[0] = canrx.data[0];
				sw_3[1] = canrx.data[1];
				sw_3[2] = canrx.data[2];
			}
			break;
#endif
#ifdef MOD4_SW_DATA
			case 0x684: // PWM
			{
				sw_4[0] = canrx.data[0];
				sw_4[1] = canrx.data[1];
				sw_4[2] = canrx.data[2];
			}
			break;
#endif

			case ID_RX_DASH:
			{
				timeout_6a4 = systick_ms + 4000;
				cmd_ext = canrx.data[6] + (((uint16_t)canrx.data[7]) << 8);

				if (MOD_ADDR != ADDR4_MOD)
				{
					dash_cmd_parse(*((uint16_t *)(canrx.data + (MOD_ADDR << 1) - 2)), cmd_ext); // normal
				}
			}
			break;

#ifdef MOD4
			case ID_ADD_DASH:
			{
				if (MOD_ADDR == ADDR4_MOD)
				{
					dash_cmd_parse(*((uint16_t *)(canrx.data + MOD4_BYTE_START)), cmd_ext); // normal
				}
			}
			break;
#endif
			
#ifdef PWMTIME_SET_ENABLE
			case ID_PWMTIME_SET:  //0x6F0
			case ID_PWMTIME_SET+1:
				
			case ID_PWMTIME_SET+2:
			case ID_PWMTIME_SET+3:
				
			case ID_PWMTIME_SET+4:
			case ID_PWMTIME_SET+5:
				
#ifdef MOD4
			case ID_PWMTIME_SET+6:
			case ID_PWMTIME_SET+7:
#endif
				{
					uint8_t addr = canrx.id - ID_PWMTIME_SET;
					if ((addr >> 1) == MOD_ADDR_S0)
					{
						uint8_t index = (addr & 1) *8;
						
						for (i = 0; i < 8; i++)
						{								
								PoutS[index].pwmend = canrx.data[i];
							
								if((++index) >= POUT_COUNT)
										break;							 
						}
					}
				}
				break;
#endif
				
			case ID_RX_PWM: // PWM
			{
				uint8_t startbyte = (MOD_ADDR << 1) - 2;
				uint16_t *temp = (uint16_t *)(canrx.data + startbyte);

				for (i = 0; i < POUT_COUNT; i++)
				{
					if(PoutS[i].pwmfixed == 0)
					{
							PoutS[i].pwmable = (((*temp) >> i) & 1) > 0;
					}
				}
			}
			break;

			case ID_BOOTLOADER:
			case 0x520:
			case 0x521:
			case 0x522:
#ifdef MOD4
			case 0x523:
#endif
				if ((0x51F + MOD_ADDR) == canrx.id)
				{
					if (canrx.data[0] == 0x5)
					{
#define PASSWORD_ADDR 0x17C00
#include "BF7006AMxx_eflash.h"
						flash_sector_erase(PASSWORD_ADDR >> 10, true);
						NVIC_SystemReset();
					}
					else if (canrx.data[0] == 0x6)
					{
						data[0] = 7;
						data[1] = (((0x51f + MOD_ADDR) >> 8) & 0xff);
						data[2] = (0x51f + MOD_ADDR) & 0xff;
						data[3] = 0x70; //芯片型号
						data[4] = 0x01; //版本号
						data[5] = 0x21;
						data[6] = 0x05;
						data[7] = 0x10;

						can_send_bytes(0x052e, 0, data, 8);
					}
				}
				else
				{
					if (canrx.data[0] == 0x01)
					{
						cmd_ext = 0;
						dash_cmd_parse(0, cmd_ext);
						can_send_enable(0);
					}
					else if (canrx.data[0] == 0x03)
					{
						can_send_enable(1);
					}
				}
				break;
			case ID_FW_UPDATE:
			case ID_FW_UPDATE + 1:
			case ID_FW_UPDATE + 2:
#ifdef MOD4
			case ID_FW_UPDATE + 3:
#endif
				if ((ID_FW_UPDATE + MOD_ADDR) == canrx.id)
				{
					if (canrx.data[0] == 0xAE && canrx.data[1] == 0xEA)
					{
						NVIC_SystemReset();
					}
				}
				break;
			case ID_TX_TEST:
				switch (canrx.data[0])
				{
				case 0x56: /* 读取165，返回开关输入状态数据 */
					data[0] = in_sw[0];
					data[1] = in_sw[1];
					can_send_bytes(ID_TX_TEST, 0, data, 2);
					break;

				case 0x57: /* 打开、关闭指定输出 */
					PoutS[canrx.data[1]].cmd = canrx.data[2] > 0;
					break;

				case 0x58: /* 读取输出反馈值 */
					data[0] = PoutS[canrx.data[1]].cur_100ma;
					data[1] = PoutS[canrx.data[1]].cur_100ma >> 8;
					can_send_bytes(ID_TX_TEST, 0, data, 2);
					break;

				case 0x59: /* 两路电压输入信号读取*/
					data[0] = P25;
					data[1] = P25 >> 8;
					data[2] = P40;
					data[3] = P40 >> 8;
					can_send_bytes(ID_TX_TEST, 0, data, 4);
					break;

				case 0x60: /* 获取输入脉冲频率*/
					data[0] = freq;
					data[0] = freq >> 8;
					can_send_bytes(ID_TX_TEST, 0, data, 2);
					break;

				case 0x63: /* 检测ADD1& NK1两路输入 */
					data[0] = in_sw[2] & 3;
					can_send_bytes(ID_TX_TEST, 0, data, 2);
					break;
				default:
					break;
				}
			case ID_TX_TEST + 1:
			case ID_TX_TEST + 2:
			case ID_TX_TEST + 3:
#ifdef MOD4
			case ID_TX_TEST + 4:
#endif
				if ((ID_TX_TEST + MOD_ADDR) == canrx.id)
				{
					switch (canrx.data[0])
					{
					case 0x56: /*设置百米脉冲数*/
						param.pluse = (uint16_t)(canrx.data[2] << 8) | canrx.data[1];
						PT_WAIT_UNTIL(pt, (EepromFlag == 0));
						EepromFlag = 1;
						save_param();
						EepromFlag = 0;
						can_send_bytes(ID_TX_TEST + MOD_ADDR, 0, (uint8_t *)"\x56\x55", 2);
						break;
					case 0xA0: /*读取百米脉冲数*/
						data[0] = 0xA0;
						data[1] = param.pluse;
						data[2] = (param.pluse >> 8);
						can_send_bytes(ID_TX_TEST + MOD_ADDR, 0, data, 3);
						break;
					case 0x59: /*设置总里程数*/

						odo_100m = (uint32_t)canrx.data[4] << 24;
						odo_100m |= (uint32_t)canrx.data[3] << 16;
						odo_100m |= (uint32_t)canrx.data[2] << 8;
						odo_100m |= (uint32_t)canrx.data[1];

						PT_WAIT_UNTIL(pt, (EepromFlag == 0));
						EepromFlag = 1;
						PT_SPAWN(pt, &ptx, save_odo_pt(&ptx));
						EepromFlag = 0;

						can_send_bytes(ID_TX_TEST + MOD_ADDR, 0, (uint8_t *)"\x59\x55", 2);
						break;

					case 0xA1: /*读取总里程数*/
						data[0] = 0xA1;
						data[1] = (uint8_t)odo_100m;
						data[2] = (uint8_t)(odo_100m >> 8);
						data[3] = (uint8_t)(odo_100m >> 16);
						data[4] = (uint8_t)(odo_100m >> 24);
						can_send_bytes(ID_TX_TEST + MOD_ADDR, 0, data, 5);
						break;

					case 0x5C: /*设置单次里程*/

						trip_100m = (uint16_t)(canrx.data[2] << 8 | canrx.data[1]);

						PT_WAIT_UNTIL(pt, (EepromFlag == 0));
						EepromFlag = 1;
						PT_SPAWN(pt, &ptx, save_odo_pt(&ptx));
						EepromFlag = 0;
						can_send_bytes(ID_TX_TEST + MOD_ADDR, 0, (uint8_t *)"\x5C\x55", 2);
						break;
					case 0xA3: /*读取单次里程*/
						data[0] = 0xA3;
						data[1] = trip_100m;
						data[2] = (trip_100m >> 8);
						can_send_bytes(ID_TX_TEST + MOD_ADDR, 0, data, 3);
						break;

					case 0xFE: /*读取版本号*/
						can_send_bytes(ID_TX_TEST + MOD_ADDR, 0, SoftVer, 8);
						break;

					case 0xFF: /*读取反馈电流，分辨率0.1A*/
						data[0] = PoutS[0].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[0].cur_100ma;
						data[1] = PoutS[1].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[1].cur_100ma;
						data[2] = PoutS[2].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[2].cur_100ma;
						data[3] = PoutS[3].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[3].cur_100ma;
						data[4] = PoutS[4].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[4].cur_100ma;
						data[5] = PoutS[5].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[5].cur_100ma;
						data[6] = PoutS[6].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[6].cur_100ma;
						data[7] = PoutS[7].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[7].cur_100ma;
						can_send_bytes(ID_TX_CURRENT + 2 * MOD_ADDR - 2, 0, data, 8);

						data[0] = PoutS[8].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[8].cur_100ma;
						data[1] = PoutS[9].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[9].cur_100ma;
						data[2] = PoutS[10].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[10].cur_100ma;
						data[3] = PoutS[11].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[11].cur_100ma;
						data[4] = PoutS[12].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[12].cur_100ma;
						data[5] = PoutS[13].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[13].cur_100ma;
						data[6] = PoutS[14].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[14].cur_100ma;
						data[7] = 0; // PoutS[15].cur_100ma > 0xFF ? 0xFF : (uint8_t)PoutS[15].cur_100ma;
						can_send_bytes(ID_TX_CURRENT + 2 * MOD_ADDR - 1, 0, data, 8);
						break;
					}
				}
				break;

			default:
				break;
			}
		}
	}
	PT_INFINITE_LOOP_END(pt);
}

static struct pt ptcansend, ptcanrecv;

static void can_app_init()
{
	PT_INIT(&ptcansend);
	PT_INIT(&ptcanrecv);
}

INIT_COMPONENT_EXPORT(can_app_init);

void can_app()
{
	protothread_can(&ptcansend);
#ifndef TEMP_TEST
	protothread_can_recv(&ptcanrecv);
#endif
}
// INIT_APP_LOOP_EXPORT(can_app);

#ifndef MOD4
static void testmod_can_app()
{
	if (MOD_ADDR == ADDR4_MOD)
	{
		while (1)
		{
			protothread_can_test(&ptcansend);
			protothread_can_recv(&ptcanrecv);
		}
	}
}
INIT_APP_EXPORT(testmod_can_app);
#endif
