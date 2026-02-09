 /*
 * single_ssd_counter.c
 *
 * Created: 23-01-2026 20:50:32
 * Author : ARJUN
 */ 
#define F_CPU 16000000U
#include <avr/io.h>
#include <util/delay.h>
/*digit definitions for seven segment display*/
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

uint8_t digits[10] = {ZERO, ONE, TWO, THREE, FOUR,FIVE, SIX, SEVEN, EIGHT, NINE};
	
uint8_t count = 0;

gpio_init()
{
	DDRD &= ~(0xFF);
}
void display_count()
{
	for(uint8_t  i = 0; i < 10; i++)
	{
		PORTD = digits[i];	
		_delay_ms(1000);
	}
}

int main(void)
{
	gpio_init();
   
    while (1) 
    {
		display_count();
    }
}

