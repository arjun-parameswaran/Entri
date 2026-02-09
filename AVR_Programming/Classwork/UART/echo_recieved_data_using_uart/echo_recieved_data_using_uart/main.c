/*
 * echo_recieved_data_using_uart.c
 * Description: Implementing line ECHO using UART, only transmit when ENTER key press is detected.
 * Created: 05-01-2026 11:56:53
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
void transmit_data(char *buffer)
{
	/*loop to iterating through the buffer until - NULL is encountered*/
	for(uint8_t i = 0; buffer[i]; i++)
	{
		
		while(!(UCSR0A & (1 << UDRE0))); // waiting for data transmission to complete
		UDR0 = buffer[i]; //giving data from the the buffer data register for transmitting (echoing).
	}
}

int main(void)
{
	/*to store the data to be echoed*/
	char buffer[50];
	uart_init();
	
	uint8_t count = 0;
    while (1) 
    {
		/**/
		if((UCSR0A & (1 << RXC0)))
		{
			/*updating the buffer with the recieved data*/
			buffer[count++] = UDR0;
			/*checking for the 'ENTER' key press to send the data back*/
			if(buffer[count - 1] == '\n') 
			{
				buffer[count] = '\0'; //terminating the data with a NULL
				/*function to transmit the data back to serial monitor ECHO - MODE*/
				transmit_data(buffer); 
				count = 0; //resetting the count value for overwriting the new collected data
			}
		}
	}
}

