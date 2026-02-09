/*
 * uart_string_transmit.c
 * Description: Transmitting string "Hello!" to serial moniter usingg UART.
 * Created: 04-01-2026 18:29:53
 * Author : ARJUN
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void uart_init()
{
	/*setting the baud rate value 9600 ~ 103 -> ((Fcpu / (16 * baud value)) - 1) = (16,000,000 /(16 * 9600)) - 1 = 103*/
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

int main(void)
{	uint8_t i = 0;
	char string[] = "Hello!";
	uart_init();
	
	while (1)
	{
		UDR0 = string[i];
		while(!(UCSR0A & (1 << UDRE0)));
		_delay_ms(1000);
		i++; //incrementing for printing next character
		if(i > 5)
		{
			UDR0 = '\n'; // to print in new line
			i = 0; //resetting i to start from beginning
		}
	}
}

