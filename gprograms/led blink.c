/*
 * ledblink.c
 *
 * Created: 09-05-2019 14:16:16
 * Author : sandeep
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
  DDRA=0xFF;
  PINC=1<<PC7;
  PINC=1<<PC6;
    while (PC7==1) 
    {
		
		PORTA=0x80;
		_delay_ms(100);
		PORTB=0x40;
		_delay_ms(100);
		PORTC=0x20;
		_delay_ms(100);
		PORTD=0x10;
		_delay_ms(100);
		PORTA=0x08;
		_delay_ms(100);
		PORTB=0x04;
		_delay_ms(100);
		PORTC=0x02;
		_delay_ms(100);
		PORTD=0x01;
		_delay_ms(100);
		
    }
	
	 while (PC6==1)
	 {
		 
		 PORTA=0x80;
		 _delay_ms(100);
		 PORTB=0x40;
		 _delay_ms(100);
		 PORTC=0x20;
		 _delay_ms(100);
		 PORTD=0x10;
		 _delay_ms(100);
		 PORTA=0x08;
		 _delay_ms(100);
		 PORTB=0x04;
		 _delay_ms(100);
		 PORTC=0x02;
		 _delay_ms(100);
		 PORTD=0x01;
		 _delay_ms(100);
		 
	 }
	 
}

