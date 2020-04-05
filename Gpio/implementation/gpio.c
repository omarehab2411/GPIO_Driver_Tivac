///@file gpio.c

/******************************************************************
* @Title : general purpose input output(GPIO)
* @Filename : gpio.c
* @Author : Omar Ehab
* @Origin Date : 03/05/2020
* @Version : 1.0.0
* @Compiler : Keil
* @Target : Tm4c123gh6pm
* @Notes : this file contains definition of Gpio module functions
*
* MIT License
*Copyright (c) [2020] [Omar Ehab abdelaziz]
*Permission is hereby granted, free of charge, to any person obtaining a copy
*of this software and associated documentation files (the "Software"), to deal
*in the Software without restriction, including without limitation the rights
*to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*copies of the Software, and to permit persons to whom the Software is
*furnished to do so, subject to the following conditions:
*
*The above copyright notice and this permission notice shall be included in all
*copies or substantial portions of the Software.
*THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*SOFTWARE
*******************************************************************/

#include "gpio.h"


//*******************************************************
//                 Function: Gpio_Init()
//********************************************************

/**
 *\b Description:
 *This function is used to initiaize GPIO pins based on the configuration
 *parameters entered for every GPIO pin in the GPIO configuration table array that resides inside
 *gpio_config.h module the function loop through the configuration table and configure GPIO pins based on the defined configuration selected in the configuration table
 *
 *\b PRE-CONDITION:Configure the parameters of the GPIO pin in the configuration table in gpio_config.h module \br
 *\b POST-CONDITION:All GPIO pins listed in the configuration table structure will be initialzied
 *
 *@param[in]     cnfg_table is a constant pointer to a configuration table structure defined in gpio_conig.h module
 *               this pointer is used to refrence every defined configuration of every gpio pin inside the configuration structure table
 *
 *@param[in]     cnfgTable_size is a uint8 varibale that hold the size of the configuration table array so the function could loop
 *              through every index of the table to initialize the coressponding defined GPIO pin
 *
 *@return       void
 *@see          Gpio_PinWrite
 *@see          Gpio_PinRead
 *@see          Gpio_PinToggle
 *@see          Gpio_Dir_set
 *@see          Gpio_Dir_get
 */
void Gpio_Init(const GpioConfiguration* const cnfg_table,
		uint8_t cnfgTable_size) {
	for (uint8_t i = 0; i < cnfgTable_size; i++) {
		//enable clock to the specific port
		RCGCGPIO = (1 << cnfg_table[i].port);

		//set direction of the pin 
		if (cnfg_table[i].direction == gpio_output)
			//pin is output pin
			*GpioDataDIR[cnfg_table[i].port] |= (1 << cnfg_table[i].pin);
		else
			//pin is input
			*GpioDataDIR[cnfg_table[i].port] &= ~(1 << cnfg_table[i].pin);

		//digital enable for the pin in this port 
		*GpioDEN[cnfg_table[i].port] |= (1 << cnfg_table[i].pin);

		//check if pull up resistor is enabled
		if (cnfg_table[i].resistor == gpio_pullupenable)
			*GpioPUR[cnfg_table[i].port] |= (1 << cnfg_table[i].pin);
		else
			*GpioPUR[cnfg_table[i].port] &= ~(1 << cnfg_table[i].pin);

		//set state of the pin
		if (cnfg_table[i].state == gpio_high)
			//set pin high
			*GpioDataReg[cnfg_table[i].port] |= (1 << cnfg_table[i].pin);
		else
			*GpioDataReg[cnfg_table[i].port] |= (1 << cnfg_table[i].pin);
	}

}

//******************************************************
//                  Function:Gpio_Dir_set()
//******************************************************

/**
 *\b Description: This function is used to set the direction of a GPIO pin.
 *
 *
 *
 *
 *
 *
 *PRE-CONDITION:a call to Gpio_init function must have been made so the pin is actually initialized
 *POST-CONDITION:the specified pin will change it's direction state to input or output pin according to configuration made
 *
 *@param[in]    Port is an enum variable that takes the name of the port that contain the pin we want to modify.
 *@param[in]    pin is an enum variable that takes the pin number that we want to modify it's direction state.
 *@param[in]   direction is an enum varibale that takes the direction state we want to set (input,output).
 *
 *
 *
 *@return       void
 *@see          Gpio_init
 */

void Gpio_Dir_set(GpioPorts port, GpioPins pin, GpioPinDirection_t direction) {
	if (direction == gpio_input)
		*GpioDataDIR[port] |= (1 << pin);
	else
		*GpioDataDIR[port] &= ~(1 << pin);
}




//******************************************
//            Function:Gpio_Dir_get()
//*******************************************

/**
 *\b Description: This function is used to get the direction of a certain pin.
 *
 *
 *
 *
 *PRE-CONDITION:a call to Gpio_init function must have been made so the pin is actually initialized
 *POST-CONDITION:the direction state of the pin is returned from the function
 *
 *@param[in]     Port is an enum variable that takes the port name that we want to check one of it's pins direction
 *
 *
 *@param[in]     pin is an enum variable that takes the pin number that we want to check it's direction state
 *
 *
 *@return       a GpioPinDirection_t enum varibale is returned which specifies the direction state of the pin
 *@see          Gpio_init
 */

GpioPinDirection_t Gpio_Dir_get(GpioPorts port, GpioPins pin) {
	if (*GpioDataDIR[port] & (1 << pin))
		return gpio_output;
	else
		return gpio_input;

}


//*****************************************
//Function to set state of a pin in a port
//*****************************************

/**
 *\b Description:This functoin is used to output a signal on the GPIO pin this signal could be logical high or low signal output
 *
 *
 *
 *
 *PRE-CONDITION:a call to Gpio_init function must have been made so the pin is actually initialized
 *POST-CONDITION:the configured GPIO pin will now output a signal based on the configured output value
 *
 *@param[in]  port is an enum variable that takes the port name that we want to output a signal on one of it's pins
 *@param[in]  pin is an enum varibale that takes the pin number that we want to output a signal to
 *@param[in]  stae is an enum variable that takes the state of the signal that we want to output on the pin this signal could be high or low signal
 *
 *
 *@return    void
 *@see        Gpio_init
 */
void Gpio_PinWrite(GpioPorts port, GpioPins pin, GpioPinState_t state) {
	if (state == gpio_high)
		*GpioDataReg[port] |= (1 << pin);
	else
		*GpioDataReg[port] &= ~(1 << pin);
}





//*****************************************
//function to read a pin in a port
//*****************************************

/**
 *\b Description:This functoin is used to read the current signal value going into or form a GPIO pin
 *
 *
 *
 *
 *PRE-CONDITION:a call to Gpio_init function must have been made so the pin is actually initialized
 *POST-CONDITION:the current signal value of a Gpio pin will be returned
 *
 *@param[in]  port is an enum variable that takes the port name
 *@param[in]  pin is an enum varibale that takes the pin number that we want to read it's signal value
 *
 *
 *@return     the signal value corresponding to that pin is returned in an integer form (1,0)
 *@see        Gpio_init
 */

int32_t Gpio_PinRead(GpioPorts port, GpioPins pin) {
	return ((*GpioDataReg[port]) & (1 << pin));

}


//*****************************************
//function to toggle a pin in a port
//****************************************

void Gpio_PinToggle(GpioPorts port, GpioPins pin) {
	*GpioDataReg[port] ^= (1 << pin);

}
//*****************************************
