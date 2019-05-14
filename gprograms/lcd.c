/*
 * lcddisplay.c
 *
 * Created: 10-05-2019 14:33:25
 * Author : sandeep
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define RS 7
#define E  5

void send_a_command (unsigned char command);
void send_a_character(unsigned char character);

int main(void)
{
	DDRC = 0xFF;
	DDRD = 0xFF;
	_delay_ms(50);
	send_a_command(0x01);// sending all clear command
	send_a_command(0x38);// 16*2 line LCD
	send_a_command(0x0E);// screen and cursor ON
	
	send_a_character (0x53);
	send_a_character (0x41);
	send_a_character (0x4E);
	send_a_character (0x44);
	send_a_character (0x45);
	send_a_character (0x45);
	send_a_character (0x50);
	send_a_command(0xC0); // sending to 2nd line
	send_a_character (0x41);
	send_a_character (0x45);
	send_a_character (0x59);
	send_a_character (0x54);
	send_a_character (0x48);
	send_a_character (0x4F);
	send_a_character (0x50);
	send_a_character (0x55);
	
	
	
}

void send_a_command (unsigned char command)
{
	PORTC=command;
	PORTD&= ~(1<<RS);
	PORTD|= (1<<E);
	_delay_ms(50);
	PORTD&= ~(1<<E);
	PORTC =0;
}

void send_a_character (unsigned char character)
{
	PORTC=character;
	PORTD|= (1<<RS);
	PORTD|= (1<<E);
	_delay_ms(50);
	PORTD&= ~(1<<E);
	PORTC =0;
}
