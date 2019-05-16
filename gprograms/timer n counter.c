/*
 * timer and counter.c
 *
 * Created: 15-May-19 9:48:08 AM
 * Author : ROHITH
 */ 

#ifndef F_CPU
#define F_CPU 1600000
#endif
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	uint8_t timerOverflowCount=0;
	TCNT0=0x00;
	DDRD=0xFF;
	TCCR0 = (1<<CS00) | (1<<CS02);
    /* Replace with your application code */
    while (1) 
    {
		while((TIFR & 0x01)==0)
			PORTB=0x00;
			TCNT0 = 0x00;
			TIFR=0x01; 
			timerOverflowCount++;
			if (timerOverflowCount>=120)
			{
				PORTD ^= (0x01<<PD0);
				timerOverflowCount=0;
			}
		
    }
}

