/*
 * 4_digit_up_counter.c
 * Description: A 4 Digit up counter using 7-segment display.
 * Created: 19-01-2026 14:47:15
 * Author : ARJUN
 */ 

#define F_CPU 16000000U
#include <avr/io.h>
#include <util/delay.h>

/*macro definitions for pins and peripherals*/

#define SWITCH_UP		PB3
#define SWITCH_DOWN		PB2
#define SWITCH_PAUSE	PB1
#define SWITCH_RESET	PB0
#define GREEN_LED		PC5
#define RED_LED			PC4
#define BUZZER			PB6

#define MAX_COUNT		9999
#define MIN_COUNT		0

#define UP_SWITCH_PRESS     (!(PINB & (1 << SWITCH_UP)))
#define DOWN_SWITCH_PRESS   (!(PINB & (1 << SWITCH_DOWN)))
#define PAUSE_SWITCH_PRESS	(!(PINB & (1 << SWITCH_PAUSE)))
#define RESET_SWITCH_PRESS	(!(PINB & (1 << SWITCH_RESET)))

#define HIGH				1
#define LOW					0

#define BUZZER_ON		(PORTB |= (1 << BUZZER))
#define BUZZER_OFF		(PORTB &= ~(1 << BUZZER))
#define BUZZER_TIME		10000
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

/*variable decelerations*/
uint16_t count = 0;
uint8_t enable_flag = LOW;
uint32_t buzzer_timer;
uint8_t up_prev_state = 0, down_prev_state = 0, pause_prev_state = 0, reset_prev_state = 0;

/*digit array*/
uint8_t digits[10] = {ZERO, ONE, TWO, THREE, FOUR,FIVE, SIX, SEVEN, EIGHT, NINE};

void gpio_init()
{
	/*switch configuration*/
	DDRB &= ~(0x0F);
	PORTB |= 0x0F;		//enabling internal pull up
	/*SSD data segment line configuration - a to g*/
	DDRD |= 0x7F;
	/*SSD Enable line configuration & Indication LED configuration*/
	DDRC |= 0x3F;
	/*Buzzer configuration*/
	DDRB |= 0x40;
	/*turning off  all digits*/
	PORTC |= 0x3F;
}
/*increment switch press detectionh*/
void up_switch_detection()
{
	
	uint8_t up_curr_state = (UP_SWITCH_PRESS)? HIGH: LOW;
	if (up_prev_state == 0 && up_curr_state == 1)
	{
		if (count < MAX_COUNT && enable_flag)
		{
			buzzer_timer = BUZZER_TIME;
			count++;	//count increment
		}
	}
	up_prev_state = up_curr_state;		
}
/*decrement switch press detection*/
void down_switch_detection()
{
	uint8_t down_curr_state = (DOWN_SWITCH_PRESS)? HIGH: LOW;

	if (down_prev_state == LOW && down_curr_state == HIGH)
	{
		if (count > MIN_COUNT && enable_flag)
		{
			buzzer_timer = BUZZER_TIME;
			count--;		//to increment the counter
		}
	}
	down_prev_state = down_curr_state;		//updating the previous state with current state
}
/*pause switch press detection*/
void pause_switch_detection()
{
	uint8_t pause_curr_state = (PAUSE_SWITCH_PRESS)? HIGH: LOW;
	
	if (pause_prev_state == LOW && pause_curr_state == HIGH)
	{
		enable_flag ^= 1;
	}
	pause_prev_state = pause_curr_state;		//updating the previous state with current state
}

/*Reset switch press detection*/
reset_switch_detection()
{
	uint8_t reset_curr_state = (RESET_SWITCH_PRESS)? HIGH : LOW ;
	
	if(reset_prev_state == LOW & reset_curr_state == HIGH)
	{
		count = 0;
		enable_flag = LOW;
	}
	reset_prev_state = reset_curr_state;		//updating the previous state with current state
	
}

void state_check()
{
	 /*current state indication (Pause/Working)*/
	 if(enable_flag)
	 {
		 enable_state();
	 }
	 else
	 {
		 pause_state();
	 }
}
/*buzzer control*/
void buzzer_check()
{
	if(buzzer_timer > 0)
	{
		BUZZER_ON;
		buzzer_timer--;
	}
	else
	{
		BUZZER_OFF;
	}
}
/*function to display the count on the SSD display*/
void display_digit(uint16_t count)
{
	/*Common Cathode SSD*/
	
	uint8_t digit_buffer[4];	//to store the digits separately for SSD's
	
	/*taking single digit from count and storing in digit buffer for each SSD's to display*/
	digit_buffer[0] = (count % 10);				//ones
	digit_buffer[1] = ((count / 10) % 10);		//tens
	digit_buffer[2] = ((count / 100) % 10);		//hundredths
	digit_buffer[3] = ((count / 1000) % 10);	//thousandths
	
	static uint8_t curr_pos = 0;

	PORTC |= 0x0F;								// 0x0F - 0000 1111 for Enabling the SSD Enable Pins					 
	PORTD = digits[digit_buffer[curr_pos]];		//loading digit to PORTD 
	PORTC &= ~(1 << curr_pos);					//Enabling the corresponding SSD

	curr_pos = (curr_pos + 1) % 4;		//to keep the range of curr_pos between 1 - 3.
}
/*Working state indication*/
void enable_state()
{
	 PORTC |= (1 << GREEN_LED);		//TURN ON GREEN LED
	 PORTC &= ~(1 << RED_LED);		//TURN OFF RED LED
}
/*Pause state indication */
void pause_state()
{
	PORTC &= ~(1 << GREEN_LED);		//TURN FF GREEN LED
	PORTC |= (1 << RED_LED);		//TURN ON RED LED
}

int main(void)
{
	gpio_init();

	while(1)
	{
		up_switch_detection();
		down_switch_detection();
		pause_switch_detection();
		reset_switch_detection();
		buzzer_check();
		state_check();
		/*function to display count on 7 Segment display*/
		display_digit(count); 
	 }
 }
