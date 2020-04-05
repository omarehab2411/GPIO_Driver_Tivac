#include "gpio.h"
int main() {

	//init 
	Gpio_Init(config_get(), 3);
	while (1) {
		Gpio_PinWrite(Portf, 1, gpio_low);
		Gpio_PinWrite(Portf, 2, gpio_low);

	}

}
