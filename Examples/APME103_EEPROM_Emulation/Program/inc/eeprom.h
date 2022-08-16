/**
  **************************************************************************
  * @file     eeprom.h
  * @version  v1.0.0
  * @date     2022-08-15
  * @brief    flash eeprom libray header file
  **************************************************************************

  *
  **************************************************************************
  */

/*!< define to prevent recursive inclusion -------------------------------------*/
#ifndef __EEPROM_H
#define __EEPROM_H

#ifdef __cplusplus
extern "C" {
#endif

/* includes ------------------------------------------------------------------*/
#include "main.h"

/*
  +-----------------------------------------------------+
  |                        EEPROM                       |
  +--------------------------+--------------------------+
  |          PAGE 0          |          PAGE 1          |
  +--------+--------+--------+--------+--------+--------+
  |        |        |        |        |        |        |
  | sector | sector | sector | sector | sector | sector |
  |   0    |  ...   |   N    | N + 1  |  ...   |  N + N |
  |        |        |        |        |        |        |
  +--------+--------+--------+--------+--------+--------+
*/

/*!< user defined */ 
#define EE_SECTOR_NUM            ((uint32_t)1)                                 /*!< sector number, support multiple sectors to from 1 page */
#define EE_SECTOR_SIZE           ((uint32_t)(1024 * 2))                        /*!< sector size */

/*!< user do not need to care */ 
#define EE_FLASH_SIZE            ((*(uint16_t *)0x1FFFF7E0) & 0xFFFF)	                   /*!< APM32 flash size information */ 

#define EE_PAGE_SIZE             ((uint32_t)(EE_SECTOR_NUM * EE_SECTOR_SIZE))  /*!< page size */

#define EE_BASE_ADDRESS          ((uint32_t)(0x08000000 + 1024 * EE_FLASH_SIZE - EE_PAGE_SIZE * 2)) /*!< eeprom base address */    
#define EE_PAGE0_ADDRESS         ((uint32_t)(EE_BASE_ADDRESS))                 /*!< eeprom page 0 base address */
#define EE_PAGE1_ADDRESS         ((uint32_t)(EE_PAGE0_ADDRESS + EE_PAGE_SIZE)) /*!< eeprom page 1 base address */

#define EE_PARA_MAX_NUMBER       ((uint16_t)(EE_PAGE_SIZE / 4 - 1))            /*!< maximum number of variables that can be stored */ 

FMC_STATUS_T flash_ee_init       (void);
uint16_t          flash_ee_data_read  (uint16_t address, uint16_t* pdata);
FMC_STATUS_T flash_ee_data_write (uint16_t address, uint16_t data);

#ifdef __cplusplus
}
#endif

#endif






