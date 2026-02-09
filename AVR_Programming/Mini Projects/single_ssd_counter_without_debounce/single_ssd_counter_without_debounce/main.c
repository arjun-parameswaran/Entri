/*
 * single_ssd_counter_without_debounce.c
 *
 * Created: 26-01-2026 22:16:29
 * Author : ARJUN
 */ 

#define F_CPU 16000000U
#include <avr/io.h>
#include <avr/interrupt.h>

//macro definitions for number patterns
#define ZERO    0x3F	//0
#define ONE     0x06	//1
#define TWO     0x5B	//2
#define THREE   0x4F	//3
#define FOUR    0x66	//4
#define FIVE    0x6D	//5
#define SIX     0x7D	//6
#define SEVEN   0x07	//7
#define EIGHT   0x7F	//8
#define NINE    0x6F	//9

//digit array
uint8_t digits[10] = {ZERO, ONE, TWO, THREE, FOUR,FIVE, SIX, SEVEN, EIGHT, NINE};

#define		INT0_SWITCH		PD2
#define		INT1_SWITCH		PD3
#define		DEBOUNCE_TIME	50


volatile uint8_t count =  0;

ISR(INT0_vect)
{
	if(count < 9)
	{
		count++;
	}
}

ISR(INT1_vect)
{
	if(count > 0)
	{
		count--;
	}
}

void external_interrupt_init()
{
	/*configuring for falling EDGE for both INT0 and INT1*/
	EICRA &= ~((1 << ISC00) | (1 << ISC10));
	EICRA |= (1 << ISC01 | 1 << ISC11);
	
	EIMSK |= (1 << INT0 | (1 << INT1));  // Enabling both INT0 and INT1
	
}
/*GPIO Configuration Function*/
void gpio_init()
{
	/*PIN Configuration for INT1 & INT0*/
	DDRD &= ~(1 << DDD2 | 1 << DDD3);
	PORTD |= ((1 << INT0_SWITCH) | (1 << INT1_SWITCH));		//Enabling Internal Pull-Up.
	
	/*PIN Configuration for SSD*/
	DDRB |= 0x3F; //a-f
	DDRD |= 0x40; //g
}
/*SSD digit display function*/
void display_digit(uint8_t data)
{
	PORTB = ((PORTB & (0xC0) | (0x3F & data)));
	
	if(data & (1 << 6 ))
	{
		PORTD |= (1 << 6);
	}
	else
	{
		
		PORTD &= ~(1 << 6);
	}
}
int main(void)
{
	gpio_init();				//GPIO Initialization
	external_interrupt_init();	//External Interrupt INT0 & INT1 Enable
	sei();						//Global Interrupt Enable
	while (1)
	{
		/*calling the display function*/
		uint8_t data = digits[count];
		display_digit(data);
	}
}
