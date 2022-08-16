/*!
 * @file        readme.txt
 *
 * @brief       This file is routine instruction
 *
 * @version     V1.0.0
 *
 * @date        2021-07-26
 *
 */
 
 
&par Example Description 

This example shows how to program the flash address of APM32E103. 
After system reset, the Flash will be unlock. Then erase the specifies address and 
write a data in the address. In the end, lock the flash. If the data in the address 
is equal to the data to be written, LED2 will light, otherwise, LED3 will light.

&par Directory contents 

  - FMC/Program/src/apm32e10x_int.c     Interrupt handlers
  - FMC/Program/src/main.c                     Main program


&par Hardware and Software environment

  - This example runs on APM32E103_MINI Devices. 