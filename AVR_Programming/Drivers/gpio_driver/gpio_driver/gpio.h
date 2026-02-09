/*
 * gpio.h
 *
 * Created: 03-02-2026 16:03:02
 *  Author: ARJUN
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#define  GPIO_HIGH		1
#define GPIO_LOW		0

#define GPIO_INPUT		1
#define GPIO_OUTPUT		0

#define  GPIO_PULLUP_ENABLE		1
#define  GPIO_PULLUP_DISABLE	0
/*GPIO PIN NUMBERS*/
#define GPIO_PIN_0		0
#define GPIO_PIN_1		1
#define GPIO_PIN_2		2
#define GPIO_PIN_3		3
#define GPIO_PIN_4		4
#define GPIO_PIN_5		5
#define GPIO_PIN_6		6
#define GPIO_PIN_7		7

#define GPIOA		((GPIO_RegDef_t *)(0x25))
#define GPIOB		((GPIO_RegDef_t *)(0x23))
#define GPIOC		((GPIO_RegDef_t *)(0x29))

typedef struct  
{
	volatile uint8_t pin;
	volatile uint8_t data;
	volatile uint8_t ddr;
}GPIO_RegDef_t;

void GPIO_r

#endif /* GPIO_H_ */