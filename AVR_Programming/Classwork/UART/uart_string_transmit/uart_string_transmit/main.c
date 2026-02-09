/*
 * uart_string_transmit.c
 * Description: Transmitting a string using UART to serial moniter.
 * Created: 04-01-2026 18:46:01
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

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
	/*enabling  transmitter*/
	UCSR0B |= (1 << TXEN0);	
}
/*function to transmit string*/
void string_transmit(char *str)
{
	while(*str)
	{
		UDR0 = *str;
		while(!(UCSR0A & (1 << UDRE0))); //checking if sending is over/
		_delay_ms(200);
		str++;    //incrementing to next character
	}
}

int main(void)
{	uint8_t i = 0;
	char string[] = "Hello!\n";
	uart_init();
	
	while (1)
	{
		string_transmit(string);
	}
}

