///@file gpioMap.h
/******************************************************************
* @Title : general purpose input output Map
* @Filename : gpioMap.h
* @Author : Omar Ehab
* @Origin Date : 03/05/2020
* @Version : 1.0.0
* @Compiler : Keil
* @Target : Tm4c123gh6pm
* @Notes : this file contains Mapping of the GPIO moduleregisters of the Tm4c123gh6pm board
********************************************************************/
#include "gpio_config.h"


/**
 * The following are defines for the GPIO register offsets.
 */
#define GPIO_O_DATA             0x00000000  // GPIO Data
#define GPIO_O_DIR              0x00000400  // GPIO Direction
#define GPIO_O_IS               0x00000404  // GPIO Interrupt Sense
#define GPIO_O_IBE              0x00000408  // GPIO Interrupt Both Edges
#define GPIO_O_IEV              0x0000040C  // GPIO Interrupt Event
#define GPIO_O_IM               0x00000410  // GPIO Interrupt Mask
#define GPIO_O_RIS              0x00000414  // GPIO Raw Interrupt Status
#define GPIO_O_MIS              0x00000418  // GPIO Masked Interrupt Status
#define GPIO_O_ICR              0x0000041C  // GPIO Interrupt Clear
#define GPIO_O_AFSEL            0x00000420  // GPIO Alternate Function Select
#define GPIO_O_DR2R             0x00000500  // GPIO 2-mA Drive Select
#define GPIO_O_DR4R             0x00000504  // GPIO 4-mA Drive Select
#define GPIO_O_DR8R             0x00000508  // GPIO 8-mA Drive Select
#define GPIO_O_ODR              0x0000050C  // GPIO Open Drain Select
#define GPIO_O_PUR              0x00000510  // GPIO Pull-Up Select
#define GPIO_O_PDR              0x00000514  // GPIO Pull-Down Select
#define GPIO_O_SLR              0x00000518  // GPIO Slew Rate Control Select
#define GPIO_O_DEN              0x0000051C  // GPIO Digital Enable
#define GPIO_O_LOCK             0x00000520  // GPIO Lock
#define GPIO_O_CR               0x00000524  // GPIO Commit
#define GPIO_O_AMSEL            0x00000528  // GPIO Analog Mode Select
#define GPIO_O_PCTL             0x0000052C  // GPIO Port Control
#define GPIO_O_ADCCTL           0x00000530  // GPIO ADC Control
#define GPIO_O_DMACTL           0x00000534  // GPIO DMA Control
#define GPIO_O_SI               0x00000538  // GPIO Select Interrupt
#define GPIO_O_DR12R            0x0000053C  // GPIO 12-mA Drive Select
#define GPIO_O_WAKEPEN          0x00000540  // GPIO Wake Pin Enable
#define GPIO_O_WAKELVL          0x00000544  // GPIO Wake Level
#define GPIO_O_WAKESTAT         0x00000548  // GPIO Wake Status
#define GPIO_O_PP               0x00000FC0  // GPIO Peripheral Property
#define GPIO_O_PC               0x00000FC4  // GPIO Peripheral Configuration
//------------------------------------------------------------------------------------


/**
 * The following are gpio register base address
 */
#define PortA    0x40004000    //portA base address
#define PortB    0x40005000    //portB base address
#define PortC    0x40006000    //PortC base address
#define PortD    0x40007000    //portD base address
#define PortE    0x40024000    //PortE base address
#define PortF    0x40025000    //portF base address
//--------------------------------------------------




/**
 * The following are pointer array that maps to the data register of every Gpio port
 */
static volatile uint32_t * const GpioDataReg[NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_DATA)+(0x3fc)),   // Data register for port A
(uint32_t*)((PortB)+(GPIO_O_DATA)+(0x3fc)),   // Data register for port B
(uint32_t*)((PortC)+(GPIO_O_DATA)+(0x3fc)),   // Data register for port C
(uint32_t*)((PortD)+(GPIO_O_DATA)+(0x3fc)),   // Data register for port D
(uint32_t*)((PortE)+(GPIO_O_DATA)+(0x3fc)),   // Data register for port E
(uint32_t*)((PortF)+(GPIO_O_DATA)+(0x3fc)),   // Data register for port F
};

//------------------------------------------------------------------------------------



/**
 * The following are pointer array that maps to the data direction register of every Gpio port
 *
 */
static volatile uint32_t * const GpioDataDIR[NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_DIR)),   // Data direction register for port A
(uint32_t*)((PortB)+(GPIO_O_DIR)),   // Data direction register for port B
(uint32_t*)((PortC)+(GPIO_O_DIR)),   // Data direction register for port C
(uint32_t*)((PortD)+(GPIO_O_DIR)),   // Data direction register for port D
(uint32_t*)((PortE)+(GPIO_O_DIR)),   // Data direction register for port E
(uint32_t*)((PortF)+(GPIO_O_DIR)),   // Data direction register for port F
};
//------------------------------------------------------------------------------------


/**
 * The following are pointer array that maps to the interrupt sense register of every Gpio port
 */
static volatile uint32_t * const GpioISR[NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_IS)),   // Interrupt sense register for port A
(uint32_t*)((PortB)+(GPIO_O_IS)),   // Interrupt sense register for port B
(uint32_t*)((PortC)+(GPIO_O_IS)),   // Interrupt sense register for port C
(uint32_t*)((PortD)+(GPIO_O_IS)),   // Interrupt sense register for port D
(uint32_t*)((PortE)+(GPIO_O_IS)),   // Interrupt sense register for port E
(uint32_t*)((PortF)+(GPIO_O_IS)),   // Interrupt sense register for port F
};
//------------------------------------------------------------------------------------




/**
 * The following are pointer array that maps to the interrupt both edges register of every Gpio port
 */
static volatile uint32_t * const GpioIBE[NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_IBE)),   // Interrupt both edges register for port A
(uint32_t*)((PortB)+(GPIO_O_IBE)),   // Interrupt both edges register for port B
(uint32_t*)((PortC)+(GPIO_O_IBE)),   // Interrupt both edges register for port C
(uint32_t*)((PortD)+(GPIO_O_IBE)),   // Interrupt both edges register for port D
(uint32_t*)((PortE)+(GPIO_O_IBE)),   // Interrupt both edges register for port E
(uint32_t*)((PortF)+(GPIO_O_IBE)),   // Interrupt both edges register for port F
};
//------------------------------------------------------------------------------------


/**
 * The following are pointer array that maps to the interrupt event register of every Gpio port
 */
static volatile uint32_t * const GpioIEV [NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_IEV)),   // Interrupt event register for port A
(uint32_t*)((PortB)+(GPIO_O_IEV)),   // Interrupt event register for port B
(uint32_t*)((PortC)+(GPIO_O_IEV)),   // Interrupt event register for port C
(uint32_t*)((PortD)+(GPIO_O_IEV)),   // Interrupt event register for port D
(uint32_t*)((PortE)+(GPIO_O_IEV)),   // Interrupt event register for port E
(uint32_t*)((PortF)+(GPIO_O_IEV)),   // Interrupt event register for port F
};
//------------------------------------------------------------------------------------



/**
 * The following are pointer array that maps to the interrupt Mask register of every Gpio port
 */
static volatile uint32_t * const GpioIM [NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_IM)),   // Interrupt Mask register for port A
(uint32_t*)((PortB)+(GPIO_O_IM)),   // Interrupt Mask register for port B
(uint32_t*)((PortC)+(GPIO_O_IM)),   // Interrupt Mask register for port C
(uint32_t*)((PortD)+(GPIO_O_IM)),   // Interrupt Mask register for port D
(uint32_t*)((PortE)+(GPIO_O_IM)),   // Interrupt Mask register for port E
(uint32_t*)((PortF)+(GPIO_O_IM)),   // Interrupt Mask register for port F
};
//------------------------------------------------------------------------------------


/**
 * The following are pointer array that maps to the interrupt status register of every Gpio port
 */
static volatile uint32_t * const GpioRIS [NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_RIS)),   // Raw Interrupt Status register for port A
(uint32_t*)((PortB)+(GPIO_O_RIS)),   // Raw Interrupt Status register for port B
(uint32_t*)((PortC)+(GPIO_O_RIS)),   // Raw Interrupt Status register for port C
(uint32_t*)((PortD)+(GPIO_O_RIS)),   // Raw Interrupt Status register for port D
(uint32_t*)((PortE)+(GPIO_O_RIS)),   // Raw Interrupt Status register for port E
(uint32_t*)((PortF)+(GPIO_O_RIS)),   // Raw Interrupt Status register for port F
};
//------------------------------------------------------------------------------------


/**
 * The following are pointer array that maps to the Masked interrupt status register of every Gpio port
 */
static volatile uint32_t * const GpioMIS [NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_MIS)),   // Masked Interrupt Status register for port A
(uint32_t*)((PortB)+(GPIO_O_MIS)),   // Masked Interrupt Status register for port B
(uint32_t*)((PortC)+(GPIO_O_MIS)),   // Masked Interrupt Status register for port C
(uint32_t*)((PortD)+(GPIO_O_MIS)),   // Masked Interrupt Status register for port D
(uint32_t*)((PortE)+(GPIO_O_MIS)),   // Masked Interrupt Status register for port E
(uint32_t*)((PortF)+(GPIO_O_MIS)),   // Masked Interrupt Status register for port F
};
//------------------------------------------------------------------------------------


/**
 * The following are pointer array that maps to the interrupt clear register of every Gpio port
 */
static volatile uint32_t * const GpioICR [NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_ICR)),   // Interrupt Clear register for port A
(uint32_t*)((PortB)+(GPIO_O_ICR)),   // Interrupt Clear register for port B
(uint32_t*)((PortC)+(GPIO_O_ICR)),   // Interrupt Clear register for port C
(uint32_t*)((PortD)+(GPIO_O_ICR)),   // Interrupt Clear register for port D
(uint32_t*)((PortE)+(GPIO_O_ICR)),   // Interrupt Clear register for port E
(uint32_t*)((PortF)+(GPIO_O_ICR)),   // Interrupt Clear register for port F
};
//------------------------------------------------------------------------------------



/**
 * The following are pointer array that maps to the Alternate function select register of every Gpio port
 */
static volatile uint32_t * const GpioAFSEL [NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_AFSEL)),   // Alternate function select register for port A
(uint32_t*)((PortB)+(GPIO_O_AFSEL)),   // Alternate function select register for port B
(uint32_t*)((PortC)+(GPIO_O_AFSEL)),   // Alternate function select register for port C
(uint32_t*)((PortD)+(GPIO_O_AFSEL)),   // Alternate function select register for port D
(uint32_t*)((PortE)+(GPIO_O_AFSEL)),   // Alternate function select register for port E
(uint32_t*)((PortF)+(GPIO_O_AFSEL)),   // Alternate function select register for port F
};
//------------------------------------------------------------------------------------



/**
 * The following are pointer array that maps to the Pull up Resistor select register of every Gpio port
 */
static volatile uint32_t * const GpioPUR [NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_PUR)),   // Pull Up Resistor  select register for port A
(uint32_t*)((PortB)+(GPIO_O_PUR)),   // Pull Up Resistor  select register for port B
(uint32_t*)((PortC)+(GPIO_O_PUR)),   // Pull Up Resistor  select register for port C
(uint32_t*)((PortD)+(GPIO_O_PUR)),   // Pull Up Resistor  select register for port D
(uint32_t*)((PortE)+(GPIO_O_PUR)),   // Pull Up Resistor  select register for port E
(uint32_t*)((PortF)+(GPIO_O_PUR)),   // Pull Up Resistor  select register for port F
};
//------------------------------------------------------------------------------------



/**
 * The following are pointer array that maps to the Digital Enable register of every Gpio port
 */
static volatile uint32_t * const GpioDEN [NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_DEN)),   // Digital Enable  register for port A
(uint32_t*)((PortB)+(GPIO_O_DEN)),   // Digital Enable  register for port B
(uint32_t*)((PortC)+(GPIO_O_DEN)),   // Digital Enable  register for port C
(uint32_t*)((PortD)+(GPIO_O_DEN)),   // Digital Enable  register for port D
(uint32_t*)((PortE)+(GPIO_O_DEN)),   // Digital Enable  register for port E
(uint32_t*)((PortF)+(GPIO_O_DEN)),   // Digital Enable  register for port F
};
//------------------------------------------------------------------------------------



/**
 * The following are pointer array that maps to the GPIO Lock register of every Gpio port
 */
static volatile uint32_t * const GpioLock [NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_LOCK)),   // Lock register for port A
(uint32_t*)((PortB)+(GPIO_O_LOCK)),   // Lock register for port B
(uint32_t*)((PortC)+(GPIO_O_LOCK)),   // Lock register for port C
(uint32_t*)((PortD)+(GPIO_O_LOCK)),   // Lock register for port D
(uint32_t*)((PortE)+(GPIO_O_LOCK)),   // Lock register for port E
(uint32_t*)((PortF)+(GPIO_O_LOCK)),   // Lock register for port F
};
//------------------------------------------------------------------------------------


/**
 * The following are pointer array that maps to the GPIO Commit register of every Gpio port
 */
static volatile uint32_t * const GpioCR [NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_CR)),   // commit register for port A
(uint32_t*)((PortB)+(GPIO_O_CR)),   // commit register for port B
(uint32_t*)((PortC)+(GPIO_O_CR)),   // commit register for port C
(uint32_t*)((PortD)+(GPIO_O_CR)),   // commit register for port D
(uint32_t*)((PortE)+(GPIO_O_CR)),   // commit register for port E
(uint32_t*)((PortF)+(GPIO_O_CR)),   // commit register for port F
};
//------------------------------------------------------------------------------------



/**
 * The following are pointer array that maps to the Analog Mode select of every Gpio port
 */
static volatile uint32_t * const GpioAMSEL [NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_AMSEL)),   // Analog Mode Select register for port A
(uint32_t*)((PortB)+(GPIO_O_AMSEL)),   // Analog Mode Select register for port B
(uint32_t*)((PortC)+(GPIO_O_AMSEL)),   // Analog Mode Select register for port C
(uint32_t*)((PortD)+(GPIO_O_AMSEL)),   // Analog Mode Select register for port D
(uint32_t*)((PortE)+(GPIO_O_AMSEL)),   // Analog Mode Select register for port E
(uint32_t*)((PortF)+(GPIO_O_AMSEL)),   // Analog Mode Select register for port F
};
//------------------------------------------------------------------------------------



/**
 * The following are pointer array that maps to the Port control register of every Gpio port
 *
 */
static volatile uint32_t * const GpioPCTL [NumberOfPorts]={
(uint32_t*)((PortA)+(GPIO_O_PCTL)),   // Port Control register for port A
(uint32_t*)((PortB)+(GPIO_O_PCTL)),   // Port Control register for port B
(uint32_t*)((PortC)+(GPIO_O_PCTL)),   // Port Control register for port C
(uint32_t*)((PortD)+(GPIO_O_PCTL)),   // Port Control register for port D
(uint32_t*)((PortE)+(GPIO_O_PCTL)),   // Port Control register for port E
(uint32_t*)((PortF)+(GPIO_O_PCTL)),   // Port Control register for port F
};
//------------------------------------------------------------------------------------


/**
 * clock register for gpio
 */
#define RCGCGPIO  *((volatile uint32_t*)(0x400FE608))


