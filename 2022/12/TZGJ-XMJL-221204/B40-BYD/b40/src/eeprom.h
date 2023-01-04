#ifndef __EEPROM_H__
#define __EEPROM_H__

#include "BF7006AMxx_config.h"
#include "BF7006AMxx_eflash.h"
#include "pt.h"
#include "config.h"
#include "save.h"

//参数保存区
//总eeprom 2K；页大小64，word（4字节对齐）读写
//可以在flash中运行 区的擦除程序，


//param 分为两个区域，一个是总里程等滚动存储，一个是参数偶尔存储，
//偶尔存储的使用 两个块，轮换存储应该每问题
//滚动存储的需要多个块的驱动

extern uint32_t EepromFlag;

#define GET_SECTOR(addr) ((addr-EEPROM_BASE)>>6)

extern uint8_t sumx (void *buf, uint8_t len);
extern uint8_t check (void *buf, uint8_t len);
extern ErrorStatus eeprom_prog_word_nowait (uint32_t addr, uint32_t data);


#endif

