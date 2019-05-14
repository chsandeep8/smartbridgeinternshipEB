/*
 * GccApplication1.c
 *
 * Created: 10-05-2019 10:41:36
 * Author : sandeep
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB=0xFF;
	DDRC=0X00;
	while (1)
	{
			PORTB=PINC;
		
	}
	

	
}


