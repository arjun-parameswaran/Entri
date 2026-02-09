/*
 * reading_temperature_from_BMP280_sensor.c
 *
 * Created: 08-01-2026 20:08:08
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

#define SLAVE PB2 // CSB Pin (Arduino D10)

void spi_init() {
	// MOSI (PB3), SCK (PB5), SS (PB2) as Output
	DDRB |= (1 << DDB3) | (1 << DDB5) | (1 << DDB2);
	// MISO (PB4) as Input
	DDRB &= ~(1 << DDB4);
	
	// SPI Enable, Master, F_osc/128 (125kHz)
	// Mode 3: CPOL=1 (Clock high when idle), CPHA=1 (Sample on trailing edge)
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << CPOL) | (1 << CPHA) | (1 << SPR1) | (1 << SPR0);
}

uint8_t spi_transfer(uint8_t data) {
	SPDR = data;
	while(!(SPSR & (1 << SPIF)));
	return SPDR;
}

void bmp280_soft_reset() {
	PORTB &= ~(1 << SLAVE);
	spi_transfer(0xE0 & 0x7F); // Reset Register
	spi_transfer(0xB6);        // Reset command
	PORTB |= (1 << SLAVE);
	_delay_ms(100);
}

int main(void) {
	spi_init();
	UART_Init();
	
	_delay_ms(100);
	UART_TxString("\r\n--- BMP280 Mode 3 Forced ---\r\n");

	// Check ID
	PORTB &= ~(1 << SLAVE);
	spi_transfer(0xD0 | 0x80);
	uint8_t chip_id = spi_transfer(0x00);
	PORTB |= (1 << SLAVE);

	UART_TxString("Chip ID: ");
	UART_TxNumber(chip_id);
	UART_TxString("\r\n");

	bmp280_soft_reset();

	uint8_t msb, lsb, xlsb, status;
	uint32_t raw_temp;

	while (1) {
		// 1. Trigger Forced Measurement (0x25)
		// 0x25 = Temp x1, Pressure x1, Forced Mode
		PORTB &= ~(1 << SLAVE);
		spi_transfer(0xF4 & 0x7F);
		spi_transfer(0x25);
		PORTB |= (1 << SLAVE);

		// 2. Poll Status until 'measuring' bit (bit 3) is 0
		do {
			PORTB &= ~(1 << SLAVE);
			spi_transfer(0xF3 | 0x80);
			status = spi_transfer(0x00);
			PORTB |= (1 << SLAVE);
			_delay_ms(10);
			
		} while (status & 0x08);

		//Read Temp Data
		PORTB &= ~(1 << SLAVE);
	
		spi_transfer(0xFA | 0x80);
		msb  = spi_transfer(0x00);
		lsb  = spi_transfer(0x00);
		xlsb = spi_transfer(0x00);
		PORTB |= (1 << SLAVE);

		//Assemble 20-bit
		raw_temp = ((uint32_t)msb << 12) | ((uint32_t)lsb << 4) | (xlsb >> 4);

		UART_TxString("Status: ");
		UART_TxNumber(status);
		UART_TxString(" | Raw Temp: ");
		UART_TxNumber(raw_temp);
		UART_TxString("\r\n");

		_delay_ms(1000); // Wait 1 second before next forced trigger
	}
}