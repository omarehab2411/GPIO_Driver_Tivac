///@file gpio_config.c
/******************************************************************
* @Title : general purpose input output configuration
* @Filename : gpio_config.c
* @Author : Omar Ehab
* @Origin Date : 03/05/2020
* @Version : 1.0.0
* @Compiler : Keil
* @Target : Tm4c123gh6pm
* @Notes : this file contains Gpio configuration table structure that the user of the gpio module should
* configure before using any gpio functions
********************************************************************/


#include "gpio_config.h"


/**
 *The following is the Gpio configuration table it is simply an
 *array of Gpioconfiguration structure where every entry in this array is a structure
 *that will configure a GPIO pin according to the entered parameters in the structure
 */
const GpioConfiguration cnfgTable[] = {
/*                                                                                                    */
/*                                                                                                    */
/* Port    Pin    Direction      Resistor                State                                        */
{ Portf, pin3, gpio_output, gpio_pullupdisable, gpio_high },

{ Portf, pin1, gpio_output, gpio_pullupdisable, gpio_high },

{ Portf, pin2, gpio_output, gpio_pullupdisable, gpio_high }, };



//**************************************************************************
//function that will return a pointer to first element in configuration table
//***************************************************************************

const GpioConfiguration* config_get(void) {
	return (const GpioConfiguration*) cnfgTable;
}
//***************************************************************************
