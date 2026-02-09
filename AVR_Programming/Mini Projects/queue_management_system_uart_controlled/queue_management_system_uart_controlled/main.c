/*
 * queue_management_system_uart_controlled.c
 * Description : 
 * Created: 28-01-2026 16:38:56
 * Author : ARJUN
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h> 

#define MIN_LIMIT 0
#define MAX_LIMIT 9999

#define RESET			'x'
#define INCREMENT		'+'
#define DECREMENT		'-'
#define TOGGLE_STATE	'1'

uint16_t count = 0;
char rx_value, enable_flag = 0;;
void update_counter()
{
	
	if(rx_value == RESET)
	{
		count =  0;
	}
	else if(rx_value == DECREMENT && count > MIN_LIMIT)
	{
		count--;
	}
	else if(rx_value == INCREMENT && count < MAX_LIMIT)
	{
		count++;
	}
	number_transmit(count);
}
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
	UCSR0B |= (1 << TXEN0 | 1 <<RXEN0);
}
/*function to transmit string*/
void string_transmit(char *str)
{
	while(*str)
	{
		while(!(UCSR0A & (1 << UDRE0))); 
		UDR0 = *str++;
	}
}
void number_transmit(uint16_t number)
{
	uint8_t buffer[8];
	utoa(count,  buffer, 10);
	strcat(buffer, "\n");
	string_transmit(buffer);
}
int main(void)
{
	uart_init();
	
	while (1)
	{
		if(UCSR0A & (1 << RXC0))
		{
			rx_value = UDR0;
			
			if (rx_value == TOGGLE_STATE)
			{
				enable_flag ^= 1;
			}
			
			if(enable_flag)
			{
				if(rx_value == INCREMENT || rx_value == DECREMENT || rx_value == RESET)
				{
					/*to update and display the counter value*/
					update_counter();
				}
			}
		}
		
	}
}

