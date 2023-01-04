#include "BF7006AMxx_config.h"
#include "BF7006AMxx_eflash.h"
#include "pt.h"
#include "config.h"
#include "eeprom.h"
#include "pluse.h"

//参数保存区
//总eeprom 2K；页大小64，word（4字节对齐）读写
//可以在flash中运行 区的擦除程序，


//param 分为两个区域，一个是总里程等滚动存储，一个是参数偶尔存储，
// 参数存储区

//偶尔存储的使用 两个块，轮换存储应该每问题
//滚动存储的需要多个块的驱动

#define PARAM_ADDR1 EEPROM_BASE
#define PARAM_ADDR2 (EEPROM_BASE+EEPROM_SECTOR_SIZE)

typedef struct
{
    uint16_t pluse;
    uint8_t recv;
    uint8_t sum;
} Param;

Param param;

#define PPARAM  (&param)
#define PBUF  ((uint32_t *)PPARAM)
#define PLEN  ((sizeof(Param)+3)>>2)

static void reset_param()
{
    int i;
    param.recv = 0xAA;
    param.pluse = PLUSE;
}

int save_param_pt (struct pt *pt)
{
    static int i;
    static int addr_temp;
    PT_BEGIN (pt);

    param.sum = sumx (PPARAM, sizeof (Param));

    eeprom_sector_erase (GET_SECTOR (PARAM_ADDR1), false);
    PT_WAIT_UNTIL (pt, (is_eeprom_idle()));

    addr_temp = PARAM_ADDR1;
    for (i = 0; i < PLEN; i++)
    {
        eeprom_prog_word_nowait (addr_temp, PBUF[i]);
        PT_WAIT_UNTIL (pt, (is_eeprom_idle()));
        addr_temp += 4;
    }

    eeprom_sector_erase (GET_SECTOR (PARAM_ADDR2), false);
    PT_WAIT_UNTIL (pt, (is_eeprom_idle()));

    addr_temp = PARAM_ADDR2;
    for (i = 0; i < PLEN; i++)
    {
        eeprom_prog_word_nowait (addr_temp, PBUF[i]);
        PT_WAIT_UNTIL (pt, (is_eeprom_idle()));
        addr_temp += 4;
    }

    PT_END (pt);
}

void save_param()
{
    param.sum = sumx (PPARAM, sizeof (Param));
    eeprom_sector_erase (GET_SECTOR (PARAM_ADDR1), true);
    eeprom_prog_Nwords (PARAM_ADDR1, PBUF, PLEN);
    eeprom_sector_erase (GET_SECTOR (PARAM_ADDR2), true);
    eeprom_prog_Nwords (PARAM_ADDR2, PBUF, PLEN);
}

#include "string.h"

void init_param()
{
    Param  p2;
    eeprom_Nwords_get (PARAM_ADDR1, (uint32_t *)&param, PLEN);
    eeprom_Nwords_get (PARAM_ADDR2, (uint32_t *)&p2, PLEN);

    switch (check ((void *)&param, PLEN) | (check ((void *)&p2, PLEN) << 1))
    {
        case 0:
            reset_param();
            save_param();
            break;
        case 1:
            eeprom_sector_erase (GET_SECTOR (PARAM_ADDR2), true);
            eeprom_prog_Nwords (PARAM_ADDR2, PBUF, PLEN);
            break;
        case 2:
            memcpy ((void *)&param, (void *)&p2, sizeof (Param));
            eeprom_sector_erase (GET_SECTOR (PARAM_ADDR1), true);
            eeprom_prog_Nwords (PARAM_ADDR1, PBUF, PLEN);
            break;
        default:
            break;
    }
}

