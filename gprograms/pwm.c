/*
 * PWM.c
 *
 * Created: 15-May-19 11:33:22 AM
 * Author : ROHITH
 */ 

#ifndef F_CPU
#define F_CPU 1600000
#endif
#include <avr/io.h>
#include <util/delay.h>
void PWM_init()
{
	/*set fast PWM mode with non-inverted output*/
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
	DDRB|=(1<<PB3);  /*set OC0 pin as output*/
}

int main(void)
{
    unsigned char duty;
    
    PWM_init();
    while (1)
    {
	    for(duty=0; duty<255; duty++)
	    {
		    OCR0=duty;  /*increase the LED light intensity*/
		    _delay_ms(20);
	    }
	    for(duty=255; duty>1; duty--)
	    {
		    OCR0=duty;  /*decrease the LED light intensity*/
		    _delay_ms(20);
	    }
    }
}

