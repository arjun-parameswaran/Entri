/*
 * uart.h
 *
 * Created: 06-01-2026 21:01:58
 *  Author: ARJUN
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


#ifndef UART_H_
#define UART_H_

void uart_init();
void uart_Txex(uint8_t value);
void uartTx_string(char *str);
void uartTx_number(uint8_t);



#endif /* UART_H_ */