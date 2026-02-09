/*
 * led_control_using_uart.c
 *
 * Created: 04-01-2026 20:19:47
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
	UCSR0B |= (1 << RXEN0 | 1 << TXEN0);
}


int main(void)
{	uint8_t led_flag = 0;
	char rx_value;
	
	DDRD |= (1 << DDD6);
	
	uart_init();
	
	while (1)
	{
		if(!(UCSR0A & (1 << RXC0)))
		{
			rx_value = UDR0;
			if(rx_value == '1')
			{
				led_flag = 1;
			}
			else
			{
				led_flag = 0;
			}
			
		}
		if(led_flag)
		{
			PORTD |= (1 << PD6);
		}
		else
		{
			PORTD &= ~(1 << PD6);
		}
		
	}
}

