


#include "stm32f401xx_gpio_driver.h"



/*********************************************************************
 * @function  				- GPIO_PeriClockControl
 *
 * @brief   	       	  	- This function enables or disables peripheral clock for the given GPIO port
 *
 * @parameters[in]        	- pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 * @parameters[in]          - EnorDi: ENABLE or DISABLE macros
 *
 * @return      	      	- none
 *
 * @Note            	  	- none
 */


void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if (pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
	}
	else
	{
		if (pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
	}
}

/*********************************************************************
 * @function  				- GPIO_ReadFromInputPin
 *
 * @brief   	       	  	- This function is used to read the value in GPIO pin.
 *
 * @parameters[in]        	- pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 * @parameters[in]          - PinNumber
 * @return      	      	- uint7_t value (returns the value inside that pin.
 *
 * @Note            	  	- refer macros for
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;
	/*Enabling the Peripheral Clock*/
	GPIO_PeriClockControl(pGPIOHandle -> pGPIOx, ENABLE);
	//1. GPIO Mode
	if (pGPIOHandle -> GPIO_PinConfig.GPIOPinMode <= GPIO_MODE_ANALOG)
	{
		temp = (pGPIOHandle -> GPIO_PinConfig.GPIOPinMode << (2 * pGPIOHandle -> GPIO_PinConfig.GPIOPinNumber));
		pGPIOHandle -> pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle -> GPIO_PinConfig.GPIOPinNumber));	//Clearing the bits
		pGPIOHandle -> pGPIOx->MODER |= temp;
		temp = 0;
	}
	else
	{
		//Interrupt Mode - Code to be written
	}
	//2 Speed
	temp = (pGPIOHandle -> GPIO_PinConfig.GPIOPinSpeed << (2 * pGPIOHandle -> GPIO_PinConfig.GPIOPinNumber));
	pGPIOHandle -> pGPIOx->OSPEEDR &= ~(0x3 << (2 * pGPIOHandle -> GPIO_PinConfig.GPIOPinNumber));	//Clearing the bits
	pGPIOHandle -> pGPIOx->OSPEEDR |= temp;
	temp = 0;
	//3 PUPD
	temp = (pGPIOHandle -> GPIO_PinConfig.GPIOPinPuPdControl << (2 * pGPIOHandle -> GPIO_PinConfig.GPIOPinNumber));
	pGPIOHandle -> pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle -> GPIO_PinConfig.GPIOPinNumber));	//Clearing the bits
	pGPIOHandle -> pGPIOx->PUPDR |= temp;
	temp = 0;
	//3.

	temp = (pGPIOHandle -> GPIO_PinConfig.GPIOPinOPtype << (pGPIOHandle -> GPIO_PinConfig.GPIOPinNumber));
	pGPIOHandle -> pGPIOx->OTYPER &= ~(0x1 << (pGPIOHandle -> GPIO_PinConfig.GPIOPinNumber));	//Clearing the bits
	pGPIOHandle -> pGPIOx->OTYPER |= temp;
	temp = 0;

	if(pGPIOHandle -> GPIO_PinConfig.GPIOPinMode == GPIO_MODE_ALTFN)
	{
		uint8_t index, value;

		index = (pGPIOHandle -> GPIO_PinConfig.GPIOPinNumber) / 8;													// 0 or 1 - selecting which index
		value = (pGPIOHandle -> GPIO_PinConfig.GPIOPinNumber) % 8;													// bringing down the value if going beyond 7
		pGPIOHandle -> pGPIOx -> AFR[index] &= ~((0xF) << (4 * value));												// Clearing the bits before setting the mode
		pGPIOHandle -> pGPIOx -> AFR[index] |= (pGPIOHandle->GPIO_PinConfig.GPIOPinAltFunMode << (4 * value));		// Setting the mode

	}
}
/*********************************************************************
 * @function  				- GPIO_ReadFromInputPin
 *
 * @brief   	       	  	- This function is used to read the value in GPIO pin.
 *
 * @parameters[in]        	- pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 * @parameters[in]          - PinNumber
 * @return      	      	- uint7_t value (returns the value inside that pin.
 *
 * @Note            	  	- refer macros for
 */

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{


}
/*********************************************************************
 * @function  				- GPIO_ReadFromInputPin
 *
 * @brief   	       	  	- This function is used to read the value in GPIO pin.
 *
 * @parameters[in]        	- pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 * @parameters[in]          - PinNumber
 * @return      	      	- uint7_t value (returns the value inside that pin.
 *
 * @Note            	  	- refer macros for
 */


uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t) (((pGPIOx->IDR) >> PinNumber) & 0x00000001);
	return value;
}
/*********************************************************************
 * @function  				- GPIO_ReadFromInputPin
 *
 * @brief   	       	  	- This function is used to read the value in GPIO pin.
 *
 * @parameters[in]        	- pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 * @parameters[in]          - PinNumber
 * @return      	      	- uint7_t value (returns the value inside that pin.
 *
 * @Note            	  	- refer macros for
 */


uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t) (pGPIOx->IDR);
	return value;
}
/*********************************************************************
 * @function  				- GPIO_ReadFromInputPin
 *
 * @brief   	       	  	- This function is used to read the value in GPIO pin.
 *
 * @parameters[in]        	- pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 * @parameters[in]          - PinNumber
 * @return      	      	- uint7_t value (returns the value inside that pin.
 *
 * @Note            	  	- refer macros for
 */

void GPIO_WritToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value)
{
	if(value == GPIO_SET_PIN)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}
	else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}
/*********************************************************************
 * @function  				- GPIO_ReadFromInputPin
 *
 * @brief   	       	  	- This function is used to read the value in GPIO pin.
 *
 * @parameters[in]        	- pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 * @parameters[in]          - PinNumber
 * @return      	      	- uint7_t value (returns the value inside that pin.
 *
 * @Note            	  	- refer macros for
 */


void GPIO_WritToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value)
{
	pGPIOx->ODR = value;
}
/*********************************************************************
 * @function  				- GPIO_ReadFromInputPin
 *
 * @brief   	       	  	- This function is used to read the value in GPIO pin.
 *
 * @parameters[in]        	- pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 * @parameters[in]          - PinNumber
 * @return      	      	- uint7_t value (returns the value inside that pin.
 *
 * @Note            	  	- refer macros for
 */

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx -> ODR ^= (1 << PinNumber);
}
