/*
 * USART-BLUETOOTH.c
 *
 * Created: 16-May-19 2:21:49 PM
 * Author : ROHITH
 */ 

#define F_CPU 16000000UL			/* Define frequency here its 12MHz */
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
char buffer[10];

//#define USART_BAUDRATE 9600
//#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)


void UART_init(long func)
{
	UCSRB |= (1 << RXEN) | (1 << TXEN);/* Turn on transmission and reception */
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);/* Use 8-bit character sizes */
	UBRRL = func;		/* Load lower 8-bits of the baud rate value */
	UBRRH = (func >> 8);	/* Load upper 8-bits*/
}

unsigned char UART_RxChar()
{
	while ((UCSRA & (1 << RXC)) == 0);/* Wait till data is received */
	return(UDR);			/* Return the byte*/
}

void UART_TxChar(char ch)
{
	while (! (UCSRA & (1<<UDRE)));	/* Wait for empty transmit buffer*/
	UDR = ch ;
}

void UART_SendString(char *str)
{
	unsigned char j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		UART_TxChar(str[j]);
		j++;
	}
}

int main()
{
	char c;
	UART_init(77);
	DDRB=0XFF;
	
	
	UART_SendString("LED ON\n");
	while(1)
	{
		
		c=UART_RxChar();
		UART_TxChar(c);
		if(c =='1')
		{
			PORTB=0xFF;
		}
		else
		{
			PORTB=0x00;
		}
	}
	return 0;
}

