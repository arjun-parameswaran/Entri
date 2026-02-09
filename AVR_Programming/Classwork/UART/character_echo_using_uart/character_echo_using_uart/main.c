/*
 * character_echo_using_uart.c
 * Description: To echo the character instantly on the serial monitor.
 * Created: 05-01-2026 14:23:59
 * Author : ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


void uart_init()
{
	/*configuring the baud rate : 9600*/
	UBRR0H = 0;  UBRR0L = 103;
	/*configuring data size : 8 bit*/
	UCSR0B &= ~(1 << UCSZ02);
	UCSR0C |= ((1 << UCSZ01) | (1 << UCSZ00));
	/*configuring to one stop bit*/
	UCSR0C &= ~(1 << USBS0);
	/*configuring to no parity*/
	UCSR0C &= ~((1 << UPM01) | (1 << UPM00));
	/*UART Transmit and Receive Enable*/
	UCSR0B |= ((1 << RXEN0) | (1 << TXEN0));
}
/*transmitting the data received*/
void transmit_data(char character)
{
	/*waiting until UDR0 is empty*/
	while(!(UCSR0A & (1 << UDRE0)));
	/*updating the data register with the character received*/
	UDR0 =  character;
}

int main(void)
{
	/*to store the data received*/
	char received;
	uart_init();
	
	while (1)
	{
		/*checking for data received*/
		if((UCSR0A & (1 << RXC0)))
		{
			/*collecting the received data*/
			received = UDR0;
			/*function to transmit the character back to serial monitor ECHO - MODE*/
			transmit_data(received);
		}
	}
}


