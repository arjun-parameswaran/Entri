/*
 * stm32f401xx.h
 *
 *  Created on: Jan 19, 2026
 *      Author: ARJUN
 */

#ifndef INC_STM32F401XX_H_ //first creation
#define INC_STM32F401XX_H_

#include <stddef.h>
#include <stdint.h>


/*macro for volatile keyword*/
#define __vo volatile

/*------------------------------------Memory Base Address--------------------------------------*/

#define FLASH_BASEADDR 		0x08000000U
#define ROM_BASEADDR   		0x1FFF0000U
#define SRAM_BASEADDR		0x20000000U

/*------------------------------Peripheral Bus Base Addresses-----------------------------------*/

#define PERIPH_BASEADDR			0x40000000U
#define APB1_PERIPH_BASEADDR	PERIPH_BASEADDR
#define APB2_PERIPH_BASEADDR	0x40010000U
#define AHB1_PERIPH_BASEADDR	0x40020000U
#define AHB2_PERIPH_BASEADDR	0x50000000U

/*------------------------------AHB1 Peripheral Base Address-----------------------------------*/

/*GPIO Peripherals A,B, C, D, E and H*/
#define GPIOA_BASEADDR		(AHB1_PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR		(AHB1_PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR		(AHB1_PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR 		(AHB1_PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR		(AHB1_PERIPH_BASEADDR + 0x0C00)
#define GPIOH_BASEADDR		(AHB1_PERIPH_BASEADDR + 0X1000)

/* Note: GPIOH is usually at + 0x1C00, so that one was likely correct! */
/*Other Peripherals*/
#define CRC_BASEADDR		(AHB1_PERIPH_BASEADDR + 0x3000)
#define RCC_BASEADDR		(AHB1_PERIPH_BASEADDR + 0x3800)
#define FLASH_IF_BASEADDR	(AHB1_PERIPH_BASEADDR + 0x3C00)
#define DMA1_BASEADDR		(AHB1_PERIPH_BASEADDR + 0x6000)
#define DMA2_BASEADDR		(AHB1_PERIPH_BASEADDR + 0x6400)

/*----------------------------APB1 PERIPHERAL Base Address-------------------------------------*/

/*TIMERS*/
#define TIM2_BASEADDR		(APB1_PERIPH_BASEADDR + 0x0000)
#define TIM3_BASEADDR		(APB1_PERIPH_BASEADDR + 0x0400)
#define TIM4_BASEADDR		(APB1_PERIPH_BASEADDR + 0x0800)
#define TIM5_BASEADDR		(APB1_PERIPH_BASEADDR + 0x0C00)

/*SPI*/
#define SPI2_BASEADDR		(APB1_PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR		(APB1_PERIPH_BASEADDR + 0x3C00)

/*USART*/
#define USART2_BASEADDR		(APB1_PERIPH_BASEADDR + 0x4400)

/*I2C*/
#define I2C1_BASEADDR 		(APB1_PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR 		(APB1_PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR 		(APB1_PERIPH_BASEADDR + 0x5C00)

/*-------------------------APB2 PHERIPHERAL BASE ADDRESS--------------------------------------*/

/*TIMER*/
#define TIM1_BASEADDR		(APB2_PERIPH_BASEADDR + 0x0000)
#define TIM9_BASEADDR		(APB2_PERIPH_BASEADDR + 0x4000)
#define TIM10_BASEADDR		(APB2_PERIPH_BASEADDR + 0x4400)
#define TIM11_BASEADDR		(APB2_PERIPH_BASEADDR + 0x4800)

/*SPI*/
#define SPI1_BASEADDR		(APB2_PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR		(APB2_PERIPH_BASEADDR + 0x3400)


/*USART*/
#define USART1_BASEADDR		(APB2_PERIPH_BASEADDR + 0x1400)
#define USART6_BASEADDR		(APB2_PERIPH_BASEADDR + 0x1000)

/* System Configuration */
#define SYSCFG_BASEADDR     (APB2_PERIPH_BASEADDR + 0x3800)
#define EXTI_BASEADDR       (APB2_PERIPH_BASEADDR + 0x3C00)


/* --------------------Peripheral register definition structure for GPIO ---------------------*/

typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];

} GPIO_RegDef_t;



#define GPIOA		((GPIO_RegDef_t *) (GPIOA_BASEADDR))
#define GPIOB		((GPIO_RegDef_t *) (GPIOB_BASEADDR))
#define GPIOC		((GPIO_RegDef_t *) (GPIOC_BASEADDR))
#define GPIOD		((GPIO_RegDef_t *) (GPIOD_BASEADDR))
#define GPIOE		((GPIO_RegDef_t *) (GPIOE_BASEADDR))
#define GPIOH		((GPIO_RegDef_t *) (GPIOH_BASEADDR))

/* -------------------------Peripheral register definition structure for I2C-----------------*/

typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t OAR1;
	__vo uint32_t OAR2;
	__vo uint32_t DR;
	__vo uint32_t SR1;
	__vo uint32_t SR2;
	__vo uint32_t CCR;
	__vo uint32_t TRISE;
	__vo uint32_t FLTR;
} I2C_RegDef_t;

#define I2C1		((I2C_RegDef_t *) (I2C1_BASEADDR))
#define I2C2		((I2C_RegDef_t *) (I2C2_BASEADDR))
#define I2C3		((I2C_RegDef_t *) (I2C3_BASEADDR))

/*------------------------ Peripheral register definition structure for SPI------------------ */

typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t CRCPR;
	__vo uint32_t RXCRCR;
	__vo uint32_t TXCRCR;
	__vo uint32_t I2SCFGR;
	__vo uint32_t I2SPR;
} SPI_RefDef_t;

#define SPI1		((SPI_RegDef_t *) (SPI1_BASEADDR))
#define SPI2		((SPI_RegDef_t *) (SPI2_BASEADDR))
#define SPI3		((SPI_RegDef_t *) (SPI3_BASEADDR))
#define SPI4		((SPI_RegDef_t *) (SPI4_BASEADDR))

/*-----------------Peripheral register definition structure for UART------------------------- */

typedef struct
{
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t BRR;
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t CR3;
	__vo uint32_t GTPR;

} USART_RegDef_t;

/*Pointer to the USART Register structures*/
#define USART1		((USART_RegDef_t *) (USART1_BASEADDR))
#define USART2		((USART_RegDef_t *) (USART2_BASEADDR))
#define USART6		((USART_RegDef_t *) (USART6_BASEADDR))

/*--------------------------Peripheral register definition structure for RCC------------------*/

typedef struct
{
    __vo uint32_t CR;           /* Offset: 0x00 - Clock control register */
    __vo uint32_t PLLCFGR;      /* Offset: 0x04 - PLL configuration register */
    __vo uint32_t CFGR;         /* Offset: 0x08 - Clock configuration register */
    __vo uint32_t CIR;          /* Offset: 0x0C - Clock interrupt register */
    __vo uint32_t AHB1RSTR;     /* Offset: 0x10 - AHB1 peripheral reset register */
    __vo uint32_t AHB2RSTR;     /* Offset: 0x14 - AHB2 peripheral reset register */
    uint32_t RESERVED0[2];      /* Offset: 0x18, 0x1C - Reserved */
    __vo uint32_t APB1RSTR;     /* Offset: 0x20 - APB1 peripheral reset register */
    __vo uint32_t APB2RSTR;     /* Offset: 0x24 - APB2 peripheral reset register */
    uint32_t RESERVED[2];       /* Offset: 0x28, 0x2C - Reserved */
    __vo uint32_t AHB1ENR;      /* Offset: 0x30 - AHB1 peripheral clock enable register */
    __vo uint32_t AHB2ENR;      /* Offset: 0x34 - AHB2 peripheral clock enable register */
    uint32_t RESERVED2[2];      /* Offset: 0x38, 0x3C - Reserved */
    __vo uint32_t APB1ENR;      /* Offset: 0x40 - APB1 peripheral clock enable register */
    __vo uint32_t APB2ENR;      /* Offset: 0x44 - APB2 peripheral clock enable register */
    uint32_t RESERVED3[2];      /* Offset: 0x48, 0x4C - Reserved */
    __vo uint32_t AHB1LPENR;    /* Offset: 0x50 - AHB1 peripheral clock enable in low power */
    __vo uint32_t AHB2LPENR;    /* Offset: 0x54 - AHB2 peripheral clock enable in low power */
    uint32_t RESERVED4[2];      /* Offset: 0x58, 0x5C - Reserved */
    __vo uint32_t APB1LPENR;    /* Offset: 0x60 - APB1 peripheral clock enable in low power */
    __vo uint32_t APB2LPENR;    /* Offset: 0x64 - APB2 peripheral clock enable in low power */
    uint32_t RESERVED5[2];      /* Offset: 0x68, 0x6C - Reserved */
    __vo uint32_t BDCR;         /* Offset: 0x70 - Backup domain control register */
    __vo uint32_t CSR;          /* Offset: 0x74 - Clock control & status register */
    uint32_t RESERVED6[2];      /* Offset: 0x78, 0x7C - Reserved */
    __vo uint32_t SSCGR;        /* Offset: 0x80 - Spread spectrum clock generation register */
    __vo uint32_t PLLI2SCFGR;   /* Offset: 0x84 - PLLI2S configuration register */
    /* Note: F401 does not have PLLSAICFGR or DCKCFGR like the F429/446 */
} RCC_RegDef_t;

#define RCC		((RCC_RegDef_t *) (RCC_BASEADDR))


/* GPIO Clock Enable */
#define GPIOA_PCLK_EN()   (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()   (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()   (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()   (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()   (RCC->AHB1ENR |= (1 << 4))
#define GPIOH_PCLK_EN()   (RCC->AHB1ENR |= (1 << 7))

/* GPIO Clock Disable */
#define GPIOA_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOH_PCLK_DI()   (RCC->AHB1ENR &= ~(1 << 7))


/*SPI Enable functions*/
#define SPI1_PCLK_EN()			RCC->APB2ENR |= (1 << 12)
#define SPI2_PCLK_EN()			RCC->APB1ENR |= (1 << 14)
#define SPI3_PCLK_EN()			RCC->APB1ENR |= (1 << 15)
#define SPI4_PCLK_EN()			RCC->APB2ENR |= (1 << 13)
/*SPI Disable Function*/
#define SPI1_PCLK_DI()			RCC->APB2ENR &= ~(1 << 12)
#define SPI2_PCLK_DI()			RCC->APB1ENR &= ~(1 << 14)
#define SPI3_PCLK_DI()			RCC->APB1ENR &= ~(1 << 15)
#define SPI4_PCLK_DI()			RCC->APB2ENR &= ~(1 << 13)

/*I2C Enable Functions*/
#define I2C1_PCLK_EN()			RCC->APB1ENR |= (1 << 21)
#define I2C2_PCLK_EN()			RCC->APB1ENR |= (1 << 22)
#define I2C3_PCLK_EN()			RCC->APB1ENR |= (1 << 23)
/*I2C Disable Functions*/
#define I2C1_PCLK_DI()			RCC->APB1ENR &= ~(1 << 21)
#define I2C2_PCLK_DI()			RCC->APB1ENR &= ~(1 << 22)
#define I2C3_PCLK_DI()			RCC->APB1ENR &= ~(1 << 23)

/*USART ENABLE FUNCTION*/
#define USART1_PCLK_EN()		RCC->APB2ENR |= (1 << 4)
#define USART2_PCLK_EN()		RCC->APB1ENR |= (1 << 17)
#define USART6_PCLK_EN()		RCC->APB2ENR |= (1 << 5)
/*USART DISABLE FUNCTION*/
#define USART1_PCLK_DI()		RCC->APB2ENR &= ~(1 << 4)
#define USART2_PCLK_DI()		RCC->APB1ENR &= ~(1 << 17)
#define USART6_PCLK_DI()		RCC->APB2ENR &= ~(1 << 5)


#endif /* INC_STM32F401XX_H_ */
