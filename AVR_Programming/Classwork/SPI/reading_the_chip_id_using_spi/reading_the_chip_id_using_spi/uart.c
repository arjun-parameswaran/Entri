/*
 * uart.c
 *
 * Created: 06-01-2026 21:02:16
 *  Author: ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

/*UART configuration*/
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

/*uart fucntion to transmit data in hexadecimal format*/
void uart_Txhex(uint8_t value)
{
	const char hexChars[] = "0123456789ABCDEF";
	char hex[5];
	hex[0] = hexChars[(value >> 4) & 0x0F];
	hex[1] = hexChars[(value & 0x0F)];
	hex[2] = '\r';
	hex[3] = '\n';
	hex[4] = '\0';  
	uartTx_string("0X");
	uartTx_string(hex);
}

void uartTx_string(char *str)
{
	while (*str)
	{
		UDR0 = *str;
		while(!(UCSR0A & (1 << UDRE0))); //checking if sending is over
		str++;
	}
}
/* function to transmit data in number format*/
void uartTx_number(uint8_t value)
{
	char number[5];
	uint8_t i = 0;
	
	if(value >= 100)
		number[i++] = ((value / 100) % 10) + '0';
	if(value >= 10)
		number[i++] = ((value / 10) % 10) + '0';
	
	number[i++] = value % 10 + '0';
	number[i++] ='\n';
	number[i] = '\0';
	 
	uartTx_string(number);
}
