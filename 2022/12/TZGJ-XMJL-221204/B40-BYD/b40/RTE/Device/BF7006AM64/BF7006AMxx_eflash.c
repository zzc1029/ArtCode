/*!
    \file  BF7006AMxx_flash.c
    \brief flash driver
*/

/*
    Copyright (C) 2017 Byd

    2017-12-27, V1.0.0, firmware for BF7006AMxx
    2019-11-22, V1.0.2, firmware for BF7006AMxx
    2021-03-03, V1.0.3, remove EEPROM_NVR operation for operation on EEPROM nvr is not recommanded
*/

#include "BF7006AMxx_eflash.h"

/*!
    \brief      ECC error correction enable
    \param[in]  none
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus ecc_enable(void)
{
    EFLASH_ECC_CTRL = 0x01U;
    if(EFLASH_ECC_CTRL != 0x01U){
        return ERROR;
    }
    return SUCCESS;
}

/*!
    \brief      ECC error correction disable
    \param[in]  none
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus ecc_disable(void)
{
    EFLASH_ECC_CTRL = 0x00U;
    if(EFLASH_ECC_CTRL != 0x00U){
        return ERROR;
    }
    return SUCCESS;
}

/*!
    \brief      flash sector erase
    \param[in]  sector_num: erase sector(0~FLASH_SECTOR_MAX_NUM-1)
    \param[in]  is_wait_done: wait to erase done or no
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus flash_sector_erase(uint8_t sector_num,bool is_wait_done)
{
    uint32_t *addr;
    if(sector_num >= FLASH_SECTOR_MAX_NUM){
        return ERROR;
    }
    if(is_flash_idle()){
        addr = (uint32_t *)((uint32_t)sector_num << 10U);
        EFLASH_SEL = FLASH_SEL;
        if(is_wait_done){
            EFLASH_MODE = FLASH_HALT_ENABLE;
        }else{
            EFLASH_MODE = FLASH_HALT_DISABLE;
        }
        EFLASH_EBCFG = FLASH_SECTOR_ERASE;
        if(addr != NULL){
            *addr = 0x00U;
        }
        if(is_wait_done){
            if(wait_flash_prog_erae_done() == ERROR){
                return ERROR;
            }
        }
        return SUCCESS;
    }else{
        return ERROR;
    }
}

/*!
    \brief      flash n sectors erase
    \param[in]  sector_num: erase sector(0~FLASH_SECTOR_MAX_NUM)
    \param[in]  len: erase sectro number
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus flash_Nsectors_erase(uint8_t sector_num,uint8_t len)
{
    while(len != 0U){
        if(flash_sector_erase(sector_num,TRUE) == ERROR){
            return ERROR;
        }
        len --;
        sector_num ++;
        wdt_clear();
    }
    return SUCCESS;
}


/*!
    \brief      flash mass erase
    \param[in]  is_wait_done: wait to erase done or no
    \param[out] none
    \retval     ERROR or SUCCESS
    note: when cpu run code in SRAM can mass erase flash
*/
ErrorStatus flash_mass_erase(bool is_wait_done)
{
    if(is_flash_idle()){
        EFLASH_SEL = FLASH_SEL;
        if(is_wait_done){
            EFLASH_MODE = FLASH_HALT_ENABLE;
        }else{
            EFLASH_MODE = FLASH_HALT_DISABLE;
        }
        EFLASH_EBCFG = FLASH_MASS_ERASE;
        if(is_wait_done){
            if(wait_flash_prog_erae_done() == ERROR){
                return ERROR;
            }
        }
        return SUCCESS;
    }else{
        return ERROR;
    }
}

/*!
    \brief      flash word prog
    \param[in]  addr: program address
    \param[in]  data: program data
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus flash_prog_word(uint32_t addr,uint32_t data)
{
    if(addr > FLASH_MAX_ADDR){
        return ERROR;
    }
    if(is_flash_idle()){
        addr &= ~0x3U;
        EFLASH_SEL = FLASH_SEL;
        EFLASH_MODE = FLASH_HALT_ENABLE;
        EFLASH_EBCFG = FLASH_PROG;
        *(uint32_t *)addr = data;
        if(wait_flash_prog_erae_done() == ERROR){
            return ERROR;
        }
        return SUCCESS;
    }else{
        return ERROR;
    }
}

/*!
    \brief      flash words prog
    \param[in]  addr: first program address
    \param[in]  data: program data
    \param[in]  len: progrma words lenth
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus flash_prog_Nwords(uint32_t addr,uint32_t data[],uint32_t len)
{
    uint32_t index = 0x00U;
    while(len != 0U)
    {
        if(flash_prog_word(addr,data[index]) == ERROR){
            return ERROR;
        }
        len --;
        addr += 4U;
        index ++;
        wdt_clear();
    }
    return SUCCESS;
}

/*!
    \brief      is flash idle
    \param[in]  none
    \param[out] none
    \retval     true:flash idle,false:flash busy
*/
bool is_flash_idle(void)
{
    if((FLASH_STATE & FLASH_STATE_IDLE) != 0x00U){
        return TRUE;
    }else{
        return FALSE;
    }
}
/*!
    \brief      wait flash prog/erase done
    \param[in]  none
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus wait_flash_prog_erae_done(void)
{
    uint32_t timeout = 30000U;    
    while(timeout != 0x00U){
        timeout --;
        if(is_flash_idle()){
            return SUCCESS;
        }
    }
    return ERROR;
}

/*!
    \brief      flash word get
    \param[in]  addr: address to get data
    \param[in]  red data: point to red data
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus flash_word_get(uint32_t addr,uint32_t *red_dat)
{
    if(is_flash_idle()){
        *red_dat = (*(uint32_t *)(addr & (~0x3U)));
        return SUCCESS;
    }else{
        *red_dat = 0x00U;
        return ERROR;
    }
}

/*!
    \brief      flash words get
    \param[in]  addr: address to get data
    \param[in]  red_dat: point to red data
    \param[in]  len: data length
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus flash_Nwords_get(uint32_t addr,uint32_t *red_dat,uint32_t len)
{
    uint32_t read_addr = addr;
    uint32_t* write_pt = red_dat;
    uint32_t read_temp;
    // judge if target addr out of FLASH addr
    if(addr + 4 * len > FLASH_MAX_ADDR + 1){
        return ERROR;
    }
    while(len != 0){
        if(flash_word_get(read_addr,&read_temp) == ERROR){
            return ERROR;
        }
        read_addr += 4;
        *write_pt = read_temp;
        write_pt++;
        len--;
    }
    return SUCCESS;
}

/*!
    \brief      flash protect set
    \param[in]  protect_page: size of protect(0~protect_page*FLASH_LOCK_UNIT Bytes)
    \param[out] none
    \retval     none
*/
void flash_protect(uint8_t protect_page)
{
    EFLASH_UNLOCK = EFLASH_UNLOCK_KEY;
    if(protect_page > FLASH_LOCK_MAX_PAGE){
        protect_page = FLASH_LOCK_MAX_PAGE;
    }
    FLASH_LOCK_SIZE = protect_page;
    /* enable flash protect range illegal access interrupt */
    SYS_INTEN |= SYS_INTEN_FPOT;
    NVIC_EnableIRQ(SYS_IRQn);
}

/*!
    \brief      eeprom sector erase
    \param[in]  sector_num: erase sector(0~EEPROM_SECTOR_MAX_NUM-1)
    \param[in]  is_wait_done: wait to erase done or no
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus eeprom_sector_erase(uint8_t sector_num,bool is_wait_done)
{
    uint32_t *addr;
    if(sector_num >= EEPROM_SECTOR_MAX_NUM){
        return ERROR;
    }
    if(is_eeprom_idle()){
        addr = (uint32_t *)(EEPROM_BASE + (EEPROM_SECTOR_SIZE * sector_num));
        EFLASH_SEL = EEPROM_SEL;
        EFLASH_MODE = EEPROM_PROG_ERASE_MODE;
        EFLASH_EBCFG = EEPROM_SECTOR_ERASE;
        if(addr != NULL){
            *addr = 0x00U;
        }
        if(is_wait_done){
            if(wait_eeprom_prog_erae_done() == ERROR){
                return ERROR;
            }
        }
        return SUCCESS;
    }else{
        return ERROR;
    }
}

/*!
    \brief      eeprom n sectors erase
    \param[in]  sector_num: erase sector(0~EEPROM_SECTOR_MAX_NUM)
    \param[in]  len: erase sectro number
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus eeprom_Nsectors_erase(uint8_t sector_num,uint8_t len)
{
    while(len != 0U){
        if(eeprom_sector_erase(sector_num,TRUE) == ERROR){
            return ERROR;
        }
        len --;
        sector_num ++;
        wdt_clear();
    }
    return SUCCESS;
}

/*!
    \brief      eeprom mass erase
    \param[in]  is_wait_done: wait to erase done or no
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus eeprom_mass_erase(bool is_wait_done)
{
    uint32_t *addr;
    if(is_eeprom_idle()){
        addr = (uint32_t *)EEPROM_BASE;
        EFLASH_SEL = EEPROM_SEL;
        EFLASH_MODE = EEPROM_PROG_ERASE_MODE;
        EFLASH_EBCFG = EEPROM_MASS_ERASE;
        *addr = 0x00U;
        if(is_wait_done){
            if(wait_eeprom_prog_erae_done() == ERROR){
                return ERROR;
            }
        }
        return SUCCESS;
    }else{
        return ERROR;
    }
}

/*!
    \brief      eeprom word prog
    \param[in]  addr: program address
    \param[in]    data: program data
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus eeprom_prog_word(uint32_t addr,uint32_t data)
{
    if(addr >= EEPROM_MAX_ADDR){
        return ERROR;
    }
    if(is_eeprom_idle()){
        addr &= ~(0x3U);
        EFLASH_SEL = EEPROM_SEL;
        EFLASH_MODE = EEPROM_PROG_ERASE_MODE;
        EFLASH_EBCFG = EEPROM_PROG;
        *(uint32_t *)addr = data;
        if(wait_eeprom_prog_erae_done() == FALSE){
            return ERROR;
        }
        return SUCCESS;
    }else{
        return ERROR;
    }
    
}

/*!
    \brief      eeprom words prog
    \param[in]  addr: first program address
    \param[in]  data: program data
    \param[in]  len: progrma words lenth
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus eeprom_prog_Nwords(uint32_t addr,uint32_t data[],uint32_t len)
{
    uint32_t index = 0U;
    while(len != 0U)
    {
        if(eeprom_prog_word(addr,data[index]) == ERROR){
            return ERROR;
        }
        len --;
        addr += 4U;
        index ++;
        wdt_clear();
    }
    return SUCCESS;
}

/*!
    \brief      eeprom word get
    \param[in]  addr: address to get data
    \param[in]  addr: point to red data
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus eeprom_word_get(uint32_t addr,uint32_t *red_dat)
{
    if(is_eeprom_idle()){
        *red_dat = (*(uint32_t *)(addr & (~0x3U)));
        return SUCCESS;
    }else{
        *red_dat = 0x00U;
        return ERROR;
    }
}

/*!
    \brief      eeprom words get
    \param[in]  addr: address to get data
    \param[in]  red_dat: point to red data
    \param[in]  len: data length
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus eeprom_Nwords_get(uint32_t addr,uint32_t *red_dat,uint32_t len)
{
    uint32_t read_addr = addr;
    uint32_t* write_pt = red_dat;
    uint32_t read_temp;
    // judge if target addr out of FLASH addr
    if((addr + 4 * len > EEPROM_MAX_ADDR + 1) || (addr < EEPROM_BASE)){
        return ERROR;
    }
    while(len != 0){
        if(eeprom_word_get(read_addr,&read_temp) == ERROR){
            return ERROR;
        }
        read_addr += 4;
        *write_pt = read_temp;
        write_pt++;
        len--;
    }
    return SUCCESS;
}

/*!
    \brief      is eeprom idle
    \param[in]  none
    \param[out] none
    \retval     true:eeprom idle,false:eeprom busy
*/
bool is_eeprom_idle(void)
{
    if((EEPROM_STATE & EEPROM_STATE_IDLE) == 0x00U){
        return FALSE;
    }else{
        return TRUE;
    }
}

/*!
    \brief      wait eeprom prog/erase done
    \param[in]  none
    \param[out] none
    \retval     ERROR or SUCCESS
*/
ErrorStatus wait_eeprom_prog_erae_done(void)
{
    uint32_t timeout = 0xFFFFFFFFU;
    while(timeout != 0x00U){
        timeout --;
        if(is_eeprom_idle()){
            return SUCCESS;
        }
    }
    return ERROR;
}

/*!
    \brief      eeprom protect set
    \param[in]  lock_page: size of protect(EEPROM_BASE~EEPROM_BASE+protect_page*EEPROM_LOCK_UNIT Bytes)
    \param[out] none
    \retval     none
*/
void eeprom_protect(uint8_t protect_page)
{
    EFLASH_UNLOCK = EFLASH_UNLOCK_KEY;
    if(protect_page > EEPROM_LOCK_MAX_PAGE){
        protect_page = EEPROM_LOCK_MAX_PAGE;
    }
    EEPROM_LOCK_SIZE = protect_page;
    /* enable eeprom protect range illegal access interrupt */
    SYS_INTEN |= SYS_INTEN_EPOT;
    NVIC_EnableIRQ(SYS_IRQn);
}


