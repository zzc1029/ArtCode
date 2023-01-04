#ifndef __SAVE_H__
#define __SAVE_H__

#include "BF7006AMxx_config.h"
#include "BF7006AMxx_eflash.h"
#include "pt.h"
#include "config.h"


typedef struct
{
    uint32_t odo;
    uint16_t trip;
    uint8_t magic;
    uint8_t sum;
} TSB;
extern void init_odo (void);
extern int save_odo_pt (struct pt *pt);


typedef struct
{
    uint16_t pluse;
    uint8_t magic;
    uint8_t sum;
} Param;

extern Param param;

extern void init_param (void);
extern void save_param (void);
extern int save_param_pt (struct pt *pt);

#endif


