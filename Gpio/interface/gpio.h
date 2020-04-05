///@file gpio.h
/******************************************************************
* @Title : general purpose input output(GPIO)
* @Filename : gpio.h
* @Author : Omar Ehab
* @Origin Date : 03/05/2020
* @Version : 1.0.0
* @Compiler : Keil
* @Target : Tm4c123gh6pm
* @Notes : this file contains prototypes for gpio module functions
********************************************************************/



#include "gpioMap.h"



//***************************************
//Prototypes of Gpio module 
//***************************************
extern void Gpio_Init(const GpioConfiguration* const cnfg_table,
		uint8_t cnfgTable_size);

extern void Gpio_Dir_set(GpioPorts port, GpioPins pin,
		GpioPinDirection_t direction);
extern GpioPinDirection_t Gpio_Dir_get(GpioPorts port, GpioPins pin);

extern void Gpio_PinWrite(GpioPorts port, GpioPins pin, GpioPinState_t state);
extern void Gpio_PinToggle(GpioPorts port, GpioPins pin);
extern int32_t Gpio_PinRead(GpioPorts port, GpioPins pin);

//extern void  Gpio_IntEnable (GpioPorts port);
//extern void  Gpio_IntDisable(GpioPorts port);
//extern void  Gpio_IntClear(GpioPorts port,GpioPins pin);
//extern void  Gpio_IntSense(GpioPorts port,GpioPins pin,GpioInterruptSense sense);
//extern void  Gpio_INTEdgeCnt(GpioPorts port,GpioPins pin,GpioInterruptLevel edge);
//extern void  Gpio_INTMask(GpioPorts port,GpioPins pin,GpioInterruptMask mask);
//extern GpioInterruptStatus Gpio_INTRIS(GpioPorts port,GpioPins pin);
//extern GpioInterruptStatus Gpio_INTMIS(GpioPorts port,GpioPins pin);

//***************************************
