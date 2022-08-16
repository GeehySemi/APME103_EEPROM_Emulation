/*!
 * @file        main.c
 *
 * @brief       Main program body
 *
 * @version     V1.0.0
 *
 * @date        2021-07-26
 *
 */

#include "main.h"
#include "eeprom.h"

#define BUF_SIZE               10
uint16_t buf_write[BUF_SIZE] = {0x2000, 0x2001, 0x2002, 0x2003, 0x2004, 0x2005, 0x2006, 0x2007, 0x2008, 0x2009};
uint16_t buf_read[BUF_SIZE];

/**
  * @brief  compare whether the valus of buffer 1 and buffer 2 are equal.
  * @param  buffer1: buffer 1 address.
            buffer2: buffer 2 address.
  * @retval 0: equal.
  *         1: unequal.
  */
uint32_t buffer_compare(uint16_t* buffer1, uint16_t* buffer2, uint32_t len)
{
  uint32_t i;
  
  for(i = 0; i < len; i++)
  {
    if(buffer1[i] != buffer2[i])
    {
      return 1;
    }
  }

  return 0;
}

/*!
 * @brief       Main program   
 *
 * @param       None
 *
 * @retval      None
 *
 */
int main(void)
{
    uint16_t i, address;
	
    APM_MINI_LEDInit(LED2);
    APM_MINI_LEDInit(LED3);
    APM_MINI_LEDOff(LED2);
    APM_MINI_LEDOff(LED3);

    FMC_Unlock();
    
    /* flash eeprom init */
    flash_ee_init();
  
    /* write data to eeprom */  
    for(i = 0; i < BUF_SIZE; i++)
    {
        address = i;
   
        flash_ee_data_write(address, buf_write[i]);
    }
  
    /* read data from eeprom */  
    for(i = 0; i < BUF_SIZE; i++)
    {
       address = i;
    
       flash_ee_data_read(address, &buf_read[i]);
    }
  
    /* compare data */
    if(buffer_compare(buf_write, buf_read, BUF_SIZE) == 0) 
    {
        APM_MINI_LEDOn(LED2);
    }
    else
    { 
        APM_MINI_LEDOff(LED2);
    }  

    while (1)
    {

    }
}
