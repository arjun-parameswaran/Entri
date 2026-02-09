/*
 * led_control_using_commands_uart.c
 *
 * Created: 05-01-2026 11:36:00
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define LED_ON "LED ON"
#define LED_OFF "LED OFF"

void uart_init()
{
	/*setting the baud rate value 9600 ~ 130*/
	UBRR0H = 0;
	UBRR0L = 103;
	/*configuring the data size to 8 bit mode*/
	UCSR0C |= ((1 << UCSZ01) | (1 << UCSZ00));
	/*configuring 1 stop bit - 1 by default*/
	UCSR0C &= ~(1 << USBS0); // 0 - one stop bit
	/*parity select - no parity by default*/
	UCSR0C &= ~((1 << UPM01) | (1 << UPM00)); //00 - no parity
	/*enabling  receiver*/
	UCSR0B |= (1 << RXEN0);
}

int main(void)
{	uint8_t i = 0;
	uart_init();
	
	while (1)
	{
		
	}
}

 