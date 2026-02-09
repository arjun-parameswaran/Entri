/*
 * servo_motor_sweep.c
 *
 * Created: 24-01-2026 11:57:39
 * Author : ARJUN
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void servo_init() {
	// Set PB1 (OC1A) as output
	DDRB |= (1 << PB1);

	// Timer 1 Configuration: Fast PWM, TOP = ICR1
	// Mode 14: WGM13=1, WGM12=1, WGM11=1, WGM10=0
	// Compare Output Mode: Non-inverting (COM1A1=1)
	TCCR1A |= (1 << COM1A1) | (1 << WGM11);
	TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Prescaler 8

	// Set TOP for 50Hz frequency
	// Formula: ICR1 = (F_CPU / (Prescaler * Target_Freq)) - 1
	// ICR1 = (16,000,000 / (8 * 50)) - 1 = 39,999
	ICR1 = 39999;
}

void set_servo_angle(uint16_t duty) {
	// OCR1A controls the pulse width
	// 0 degrees (~1ms) -> OCR1A = 2000
	// 180 degrees (~2ms) -> OCR1A = 4000
	OCR1A = duty;
}

int main(void) {
	servo_init();

	while (1) {
		// Sweep from 0 to 180 degrees
		for (uint16_t i = 2000; i <= 4000; i += 10) {
			set_servo_angle(i);
			_delay_ms(50);
		}
		// Sweep back from 180 to 0 degrees
		for (uint16_t i = 4000; i >= 2000; i -= 10) {
			set_servo_angle(i);
			_delay_ms(50);
		}
	}
}