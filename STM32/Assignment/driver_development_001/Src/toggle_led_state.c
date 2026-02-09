/*
 * main.c
 *
 *  Created on: Feb 7, 2026
 *      Author: ARJUN
 */


#include "stm32f401xx.h"
#include "stm32f401xx_gpio_driver.h"


int main(void)
{
	 GPIO_Handle_t GpioLed;
	 GpioLed.pGPIOx = GPIOA;
	 GpioLed.GPIO_PinConfig.GPIOPinNumber = GPIO_PIN_NO_05;
	 GpioLed.GPIO_PinConfig.GPIOPinMode = GPIO_MODE_OUT;
	 GpioLed.GPIO_PinConfig.GPIOPinSpeed = GPIO_SPEED_FAST;
	 GpioLed.GPIO_PinConfig.GPIOPinOPtype = GPIO_OP_TYPE_PP;
	 GpioLed.GPIO_PinConfig.GPIOPinPuPdControl = GPIO_NO_PUPD;

	 GPIO_Handle_t GpioButton;
	 GpioButton.pGPIOx = GPIOC;
	 GpioButton.GPIO_PinConfig.GPIOPinNumber = GPIO_PIN_NO_13;
	 GpioButton.GPIO_PinConfig.GPIOPinMode = GPIO_MODE_IN;
	 GpioButton.GPIO_PinConfig.GPIOPinPuPdControl = GPIO_PIN_PU;



	 /*External LED1 and LED2 Configuration*/
	 GPIO_Handle_t GpioExtLed1;
	 GpioExtLed1.pGPIOx = GPIOA;
	 GpioExtLed1.GPIO_PinConfig.GPIOPinNumber = GPIO_PIN_NO_06;
	 GpioExtLed1.GPIO_PinConfig.GPIOPinMode = GPIO_MODE_OUT;
	 GpioExtLed1.GPIO_PinConfig.GPIOPinSpeed = GPIO_SPEED_FAST;
	 GpioExtLed1.GPIO_PinConfig.GPIOPinOPtype =  GPIO_OP_TYPE_PP;
	 GpioExtLed1.GPIO_PinConfig.GPIOPinPuPdControl = GPIO_NO_PUPD;

	 GPIO_Handle_t GpioExtLed2;
	 GpioExtLed2.pGPIOx = GPIOA;
	 GpioExtLed2.GPIO_PinConfig.GPIOPinNumber = GPIO_PIN_NO_07;
	 GpioExtLed2.GPIO_PinConfig.GPIOPinMode = GPIO_MODE_OUT;
	 GpioExtLed2.GPIO_PinConfig.GPIOPinSpeed = GPIO_SPEED_FAST;
	 GpioExtLed2.GPIO_PinConfig.GPIOPinOPtype =  GPIO_OP_TYPE_PP;
	 GpioExtLed2.GPIO_PinConfig.GPIOPinPuPdControl = GPIO_NO_PUPD;

	 /*Peripheral Clock enable*/
	 GPIO_PeriClockControl(GPIOA, ENABLE);
	 GPIO_PeriClockControl(GPIOC, ENABLE);
	 /*GPIO Initialization*/
	 GPIO_Init(&GpioButton);
	 GPIO_Init(&GpioLed);
	 GPIO_Init(&GpioExtLed1);
	 GPIO_Init(&GpioExtLed2);

	 /*Variable Declarations*/
	 uint8_t prev_state = 1;
	 uint8_t altLedFlag = 0;
	 uint32_t delay = 0;

	/*Main Loop*/
	while(1)
	{
		uint8_t curr_state = GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13);
		/*checking the switch press based on the change in state*/
		if (prev_state == 1 && curr_state == 0)
		{
			 GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_05);
		}
		prev_state = curr_state;

		/*creating non-blocking delay using IF with a value reaching the given limit*/
		if (delay++ > 250000)
		{
			altLedFlag = !altLedFlag;
			delay = 0;
		}
		/*switching between the led's on the flag */
		if (altLedFlag)
		{
			GPIO_WritToOutputPin(GPIOA, GPIO_PIN_NO_06, GPIO_SET_PIN);
			GPIO_WritToOutputPin(GPIOA, GPIO_PIN_NO_07, GPIO_CLR_PIN);
		}
		else
		{
			GPIO_WritToOutputPin(GPIOA, GPIO_PIN_NO_06, GPIO_CLR_PIN);
			GPIO_WritToOutputPin(GPIOA, GPIO_PIN_NO_07, GPIO_SET_PIN);
		}
	}

}
