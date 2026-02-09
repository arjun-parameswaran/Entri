/*
 * reading_the_chip_id_using_spi.c
 * Description: To read the chip id and display it in the serial monitor of Arduino.
 * Created: 06-01-2026 20:39:08
 * Author : ARJUN
 */
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

#define SLAVE PB2

void spi_init()
{
	/*GPIO configuration in master mode*/
	DDRB |= ((1 << DDB3) | (1 << DDB5) | (1 << DDB2)); // MOSI, SCK & SS - OUTPUT
	DDRB &= ~(1 << DDB4); //MISO - INPUT
	/*Enabling SPI, Selecting MASTER, Selecting 1 MHz Clock Frequency*/
	SPCR |= ((1 << SPE) |( 1 << MSTR) | (1 << SPR0));
	SPCR &= ~((1 << SPR1) |( 1 << CPHA) | (1 << CPOL));
}

int main(void)
{
	spi_init();
	uart_init();
	uint8_t chip_id;

	/**/
    while (1) 
    {
		PORTB &= ~(1 << SLAVE); //Selecting Slave - Making Active Low
		/*sending register address*/
		SPDR = 0XD0 | 0X80;
		while(!(SPSR & (1 << SPIF))); //waiting for transferring.
		(void)SPDR; // for cleaning reading the garbage value received.
		
		SPDR = 0X00; //reading the actual data we need.
		while(!(SPSR & (1 << SPIF))); //waiting for data transfer.
		chip_id = SPDR;
		PORTB |= (1 << SLAVE); //De-selecting slave
		
		uartTx_string("Chip ID : ");
		uart_Txhex(chip_id);
		//uartTx_number(chip_id);
		
    }
}

