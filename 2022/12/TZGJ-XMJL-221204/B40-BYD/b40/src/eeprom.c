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
//偶尔存储的使用 两个块，轮换存储应该每问题
//滚动存储的需要多个块的驱动

uint32_t EepromFlag = 0;

ErrorStatus eeprom_prog_word_nowait (uint32_t addr, uint32_t data)
{
    if (addr >= EEPROM_MAX_ADDR)
    {
        return ERROR;
    }
    if (is_eeprom_idle())
    {
        addr &= ~ (0x3U);
        EFLASH_SEL = EEPROM_SEL;
        EFLASH_MODE = EEPROM_PROG_ERASE_MODE;
        EFLASH_EBCFG = EEPROM_PROG;
        * (uint32_t *)addr = data;
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}

uint8_t check (void *buf, uint8_t len)
{
    int i;
    uint8_t sum;
    if (len > 2)
    {
        sum = 0;
        if (((uint8_t *)buf)[len - 2] != 0xFF)
        {
            for (i = (len - 2); i >= 0 ; i--)
            {
                sum += ((uint8_t *)buf)[i];
            }

            if (sum == ((uint8_t *)buf)[len - 1])
            {
                return 1;
            }
        }
    }
    return 0;
}

uint8_t sumx (void *buf, uint8_t len)
{
    int i;
    uint8_t sum = 0;
    for (i = (len - 2); i >= 0 ; i--)
    {
        sum += ((uint8_t *)buf)[i];
    }
    return sum;
}

