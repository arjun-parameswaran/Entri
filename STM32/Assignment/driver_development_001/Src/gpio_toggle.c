/*
 * gpio_toggle.c
 *
 *  Created on: Feb 4, 2026
 *      Author: ARJUN
 */


#include "stm32f401xx.h"
#include "stm32f401xx_gpio_driver.h"


#if 0

int main(void)
{
    GPIO_Handle_t GpioLed;

    GpioLed.pGPIOx = GPIOA;
    GpioLed.GPIO_PinConfig.GPIOPinNumber = GPIO_PIN_NO_05;
    GpioLed.GPIO_PinConfig.GPIOPinMode = GPIO_MODE_OUT;
    GpioLed.GPIO_PinConfig.GPIOPinSpeed = GPIO_SPEED_FAST;
    GpioLed.GPIO_PinConfig.GPIOPinOPtype = GPIO_OP_TYPE_PP;
    GpioLed.GPIO_PinConfig.GPIOPinPuPdControl = GPIO_NO_PUPD;

    GPIO_PeriClockControl(GPIOA, ENABLE);
    GPIO_Init(&GpioLed);

    uint32_t delay = 0;

    while(1)
    {
    	if (delay++ >= 5000000)
    	{
    		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_05);
    		delay = 0;
    	}


    }
}



#endif

