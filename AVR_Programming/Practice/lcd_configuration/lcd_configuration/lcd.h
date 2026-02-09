/*
 * lcd.h
 *
 * Created: 19-12-2025 08:19:00
 *  Author: ARJUN
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/dealy.h>
#include <stdint.h>

/*RS = 12, EN = 11, D4 = 5, D5 = 4, D6 = 3, D7 = 2 - this is our correction*/

/*defining macros*/

/*for RS PIN*/
#define LCD_RS_PORT PORTB
#define LCD_RS_DDR DDRB
#define LCD_RS_PIN PB4

/*for EN PIN*/
#define LCD_EN_PORT PORTB
#define LCD_EN_DDR DDRB
#define LCD_EN_PIN PB3
/*for data and commands*/
#define LCD_D_PORT PORTD
#define LCD_D_DDR DDRD
#define LCD_D7_PIN PD2
#define LCD_D6_PIN PD3
#define LCD_D5_PIN PD4
#define LCD_D4_PIN PD5

/*function decelerations*/
 
 void lcd_intit(void);
 void lcd_cmd(uint8_t cmd);
 void lcd_data(uint8_t data);
 void lcd_set_cursor(uint8_t row, uint8_t col);
 void lcd_print(const char *s);
 void lcd_clear(void);
 void lcd_home(void);
 
 void lcd_print_uint16(uint16_t);
 void lcd_printf_float(float value);

 
#endif /* LCD_H_ */