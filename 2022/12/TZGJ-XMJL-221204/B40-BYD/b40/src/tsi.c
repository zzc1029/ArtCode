#include "BF7006AMxx_config.h"
#include "BF7006AMxx_eflash.h"
#include "pt.h"
#include "config.h"
#include "eeprom.h"
#include "pluse.h"
#include "includes.h"
#include "save.h"


//参数保存区
//总eeprom 2K；页大小64，word（4字节对齐）读写
//可以在flash中运行 区的擦除程序，


//param 分为两个区域，一个是总里程等滚动存储，一个是参数偶尔存储，
//参数存储区

//偶尔存储的使用 两个块，轮换存储应该每问题
//滚动存储的需要多个块的驱动


TSB tsb;


#define ODO_ADDR1 (EEPROM_BASE+EEPROM_SECTOR_SIZE*2)
#define ODO_ADDR2 (EEPROM_BASE+EEPROM_SECTOR_SIZE*3)

#define PODO  (&tsb)
#define OBUF  ((uint32_t *)PODO)
#define OLEN  ((sizeof(TSB)+3)>>2)
#define OLEN_8  (sizeof(TSB))


static void reset_odo()
{
    tsb.magic = 0x55;
    tsb.odo = 0;
    tsb.trip = 0;
    tsb.sum = sumx ((void *)&tsb, sizeof (TSB));
}

static void save_odo()
{
    tsb.odo = odo_100m;
    tsb.trip = trip_100m;
    tsb.magic = 0x55;

    tsb.sum = sumx ((void *)&tsb, sizeof (TSB));

    eeprom_sector_erase (GET_SECTOR (ODO_ADDR1), true);
    eeprom_prog_Nwords (ODO_ADDR1, OBUF, OLEN);
    eeprom_sector_erase (GET_SECTOR (ODO_ADDR2), true);
    eeprom_prog_Nwords (ODO_ADDR2, OBUF, OLEN);
}


int save_odo_pt (struct pt *pt)
{
    static int i;
    static uint32_t time;
    static int addr_temp;
    PT_BEGIN (pt);

    tsb.odo = odo_100m;
    tsb.trip = trip_100m;
    tsb.magic = 0x55;

    tsb.sum = sumx ((void *)&tsb, sizeof (TSB));

    eeprom_sector_erase (GET_SECTOR (ODO_ADDR1), false);
    PT_DELAY_MS (pt, 25);

    addr_temp = ODO_ADDR1;
    for (i = 0; i < OLEN; i++)
    {
        eeprom_prog_word_nowait (addr_temp, OBUF[i]);
        PT_DELAY_MS (pt, 1);
        addr_temp += 4;
    }

    eeprom_sector_erase (GET_SECTOR (ODO_ADDR2), false);
    PT_DELAY_MS (pt, 25);

    addr_temp = ODO_ADDR2;
    for (i = 0; i < OLEN; i++)
    {
        eeprom_prog_word_nowait (addr_temp, OBUF[i]);
        PT_DELAY_MS (pt, 1);
        addr_temp += 4;
    }

    PT_END (pt);
}

#include "string.h"

static void init_odo()
{
    TSB  p2;
    eeprom_Nwords_get (ODO_ADDR1, (uint32_t *)&tsb, OLEN);
    eeprom_Nwords_get (ODO_ADDR2, (uint32_t *)&p2, OLEN);

    switch (check ((void *)&tsb, OLEN_8) | (check ((void *)&p2, OLEN_8) << 1))
    {
        case 0:
            reset_odo();
            save_odo();
            break;
        case 1:
            eeprom_sector_erase (GET_SECTOR (ODO_ADDR2), true);
            eeprom_prog_Nwords (ODO_ADDR2, OBUF, OLEN);
            break;
        case 2:
            memcpy ((void *)&tsb, (void *)&p2, sizeof (TSB));
            eeprom_sector_erase (GET_SECTOR (ODO_ADDR1), true);
            eeprom_prog_Nwords (ODO_ADDR1, OBUF, OLEN);
            break;
        default:
            break;
    }

    odo_100m = tsb.odo;
    trip_100m = tsb.trip;
}

INIT_DEVICE_EXPORT(init_odo);

