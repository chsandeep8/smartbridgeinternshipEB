/*
 * GccApplication2.c
 *
 * Created: 14-05-2019 10:10:41
 * Author : sandeep
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>


int main(void) 
{
	DDRA= 0xFF;
	PORTA= 0xFF;
	
	char a[11]={0xFD,0x60,0xDA};
	while(1)
	{
	for(int i=0;i<=9;i++)
	{
		PORTA=a[i];
		_delay_ms(1000);
	}
	}
}
