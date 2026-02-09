/*
 * stm32f401xx_gpio_driver.h
 *
 *  Created on: Jan 27, 2026
 *      Author: ARJUN
 */


#ifndef STM32F401XX_GPIO_DRIVER_H_
#define STM32F401XX_GPIO_DRIVER_H_

#include "stm32f401xx.h"

/*Pin Number Definitions*/
#define GPIO_PIN_NO_00  			0
#define GPIO_PIN_NO_01				1
#define GPIO_PIN_NO_02				2
#define GPIO_PIN_NO_03				3
#define GPIO_PIN_NO_04				4
#define GPIO_PIN_NO_05				5
#define GPIO_PIN_NO_06				6
#define GPIO_PIN_NO_07				7
#define GPIO_PIN_NO_08				8
#define GPIO_PIN_NO_09				9
#define GPIO_PIN_NO_10				10
#define GPIO_PIN_NO_11  			11
#define GPIO_PIN_NO_12				12
#define GPIO_PIN_NO_13				13
#define GPIO_PIN_NO_14				14
#define GPIO_PIN_NO_15				15

#define ENABLE						1
#define DISABLE						0
/*GPIO Modes*/
#define GPIO_MODE_IN				0
#define GPIO_MODE_OUT				1
#define GPIO_MODE_ALTFN				2
#define GPIO_MODE_ANALOG 			3

/*GPIO Speed*/
#define GPIO_LOW_SPEED				0
#define GPIO_SPEED_MEDIUM			1
#define GPIO_SPEED_FAST				2
#define GPIO_SPEED_HIGH				3


/*GPIO PU/PD*/
#define GPIO_NO_PUPD				0
#define GPIO_PIN_PU					1
#define GPIO_PIN_PD					2
/*GPIO Output Type*/
#define GPIO_OP_TYPE_PP				0	//Push-pull
#define GPIO_OP_TYPE_OD				1	//Open-drain
/*GPIO ALt Functions*/
#define GPIO_AF_00					0
#define GPIO_AF_01					1
#define GPIO_AF_02					2
#define GPIO_AF_03					3
#define GPIO_AF_04					4
#define GPIO_AF_05					5
#define GPIO_AF_06					6
#define GPIO_AF_07					7
#define GPIO_AF_08					8
#define GPIO_AF_09					9
#define GPIO_AF_10					10
#define GPIO_AF_11					11
#define GPIO_AF_12					12
#define GPIO_AF_13					13
#define GPIO_AF_14					14
#define GPIO_AF_15					15

/**/
#define GPIO_SET_PIN				1
#define GPIO_CLR_PIN				0
/*configuration structure for GPIO Pin*/
typedef struct
{
	uint8_t GPIOPinNumber;
	uint8_t GPIOPinMode;
	uint8_t GPIOPinSpeed;
	uint8_t GPIOPinPuPdControl;
	uint8_t GPIOPinOPtype;
	uint8_t GPIOPinAltFunMode;
}GPIO_PinConfig_t;

typedef struct
{
	GPIO_RegDef_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);

void GPIO_WritToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value);
void GPIO_WritToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


#endif /* STM32F401XX_GPIO_DRIVER_H_ */
