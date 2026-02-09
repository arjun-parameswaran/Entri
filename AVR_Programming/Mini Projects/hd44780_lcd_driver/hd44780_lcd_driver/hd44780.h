/*
 * hd44780.h
 *
 * Created: 27-01-2026 19:19:21
 *  Author: ARJUN
 */ 


#ifndef HD44780_H_
#define HD44780_H_

/*Macro definitions for ports and pins*/

//RS PIN
#define LCD_RS_DDR		DDRB
#define LCD_RS_PORT		PORTB
#define LCD_RS_PIN		PB7

//EN PIN
#define LCD_EN_DDR		DDRB
#define LCD_EN_PORT		PORTB
#define LCD_EN_PIN		PB6

//DATA & COMMAND PINS (D4 - D7)
#define LCD_DATA_DDR	DDRD
#define LCD_DATA_PORT	PORTD
#define LCD_D7_PIN		PD7
#define LCD_D6_PIN		PD6
#define LCD_D5_PIN		PD5
#define LCD_D4_PIN		PD4
//definitions for 
#define CLEAR_SCREEN	0x01
#define RETURN_HOME		0x02

//function definitions
void lcd_init(void);
static void lcd_send_nibble(uint8_t nibble);
void lcd_cmd(uint8_t cmd);
void lcd_data(uint8_t data);
void lcd_set_cursor(uint8_t row, uint8_t col);
void lcd_print(char *str);
voidlcd_print_uint16(uint16_t num);
void lcd_clear(void);
void lcd_home(void);

//void lcd_print_uint16(uint16_t value);
//void lcd_print_float(float value);

#endif /* HD44780_H_ */