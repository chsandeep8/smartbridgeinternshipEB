/*
 * DC MOTOR.c
 *
 * Created: 15-May-19 2:10:02 PM
 * Author : ROHITH
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRA=0xFF;
	while (1)
	{
		
		PORTA=0x00;
		_delay_ms(1000);
		PORTA=0x01;
		_delay_ms(1000);
		PORTA=0x02;
		_delay_ms(1000);
		PORTA=0x00;
		_delay_ms(1000);
	}
}
