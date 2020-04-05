///@file gpio_config.h
/******************************************************************
* @Title : general purpose input output(GPIO)
* @Filename : gpio.h
* @Author : Omar Ehab
* @Origin Date : 03/05/2020
* @Version : 1.0.0
* @Compiler : Keil
* @Target : Tm4c123gh6pm
* @Notes : this file contains definition and enums of values that is used for Gpio module configuration
********************************************************************/




#include <stdint.h>
#include <stdlib.h>


#define NumberOfPorts  8  
#define NumberOfPins   8



//*******************************************************************************************
//                                        GPIO Configurations
//*******************************************************************************************


/**
 * Defining all GPIO PORTS that exists on the Board
 */
typedef enum {
	PortA, Portb, Portc, Portd, Porte, Portf
} GpioPorts;


/**
 * Defining every pin that exist in every GPIO port
 */
typedef enum {
	pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7
} GpioPins;



/**
 * Defining The possible Logical states of any GPIO pin
 */
typedef enum {
	gpio_low,  /**< set GPIO pin to low state (0)*/
	gpio_high  /**< set GPIO pin to high state(1)*/
} GpioPinState_t;


/**
 *Defining Possible directions of a GPIO pin
 */
typedef enum {
	gpio_input,    /**<set GPIO pin as input pin (0)*/
	gpio_output    /**<set GPIO pin as output pin (1)*/
} GpioPinDirection_t;



//setting pull up resistor of a gpio pin
/**
 * Configuring GPIO pin to have a pull u resistor
 */
typedef enum {
	gpio_pullupdisable,    /**<disable pull up resistor for that GPIO*/
	gpio_pullupenable      /**<enable pull  up resistor for that GPIO*/
} GpioPullupResistors;


/**
 * Configure GPIO pin to detec digital signals logic
 */
typedef enum {
	gpio_digitalDisable,   /**<digital function is disabled on this GPIO (can't detect any digital Logic)*/
	gpio_digitalEnable     /**<digital function is enabled  on this GPIO (can detect digital Logic)*/
} GpioDigitalEnable;



/**
 * Configure GPIO pin to detect analog signal by working in Analog mode
 */
typedef enum {
	gpio_analogDisable,    /**<analog mode disabled (GPIO can't detect analog signals)*/
	gpio_analogEnable      /**<analog mode enabled  (GPIO can detect analog signals)*/
} GpioAnalogMide;
//******************************************************************************************




//*********************************************************************************
//                                  GPIO Interrupts
//********************************************************************************

/**
 *Defining Interrupt status of a GPIO pin
 */
typedef enum {
	gpio_noInterrupt,          /**<No interrupt is active corresponding to that GPIO pin*/
	gpio_triggeredInterrupt    /**<An interrupt is active corresponding to that GPIO pin*/
} GpioInterruptStatus;


/**
 * Defining Type of signal to fire an interrupt on a GPIO pin
 */
typedef enum {
	gpio_edgeSensetive,  /**<set GPIO to detect edge  of any signal on it's pin to generate an interrupt*/
	gpio_levelSensetive  /**<set GPIO to detect Level of any signal on it's pin to generate an interrupt*/
} GpioInterruptSense;



/**
 * Defining which signal edge to cause an interrupt if GPIO pin configured as an edge triggered
 */
typedef enum {
	gpio_fallingEdge,   /**< interrupt is triggred on falling edge of signal*/
	gpio_risingEdge,    /**<interrupt is triggered on rising edge of signal*/
	gpio_bothEdges      /**<Interrupt occur on any edge change*/
} GpioInterruptLevel;



/**
 * Defining Interrupt Mask
 */
typedef enum {
	gpio_maskInterrupt,   /**<mask the Activated interrupt*/
	gpio_trggerInterrupt /**<send the interrupt signal to the NVIC*/
} GpioInterruptMask;
//*******************************************************************************************





//*********************************************************************************
//                             Configuration Table structure
//*********************************************************************************

/**
 * This is the configuration table structure that will be used
 * to set the configuration parameter of every GPIO pin by defining
 * evey entry in this structure to a specific pin and pass this table to initializing function
 */
typedef struct {
	GpioPorts port;  /**<Choose the port that you want to configure it's pin*/
	GpioPins pin;   /**<Select  the pin that you want to set it's parameters*/
	GpioPinDirection_t direction; /**<set the direction of the pin as input or outpt*/
	GpioPullupResistors resistor; /**<configure if a pull up resistor is desired to be enabled on that pin*/
	GpioPinState_t state; /**<Set the initial digital state of the pin (High,Low)*/
} GpioConfiguration;
//****************************************************************************************




//************************************************************
//prototype function ta return pointer to configuration table
//************************************************************
const GpioConfiguration* config_get(void);
//***********************************************************
