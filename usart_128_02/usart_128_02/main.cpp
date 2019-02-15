/*
 * usart_128_02.cpp
 *
 * Created: 1/30/2019 8:52:08 PM
 * Author : user
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#define BAUD 9600


//defining uart//
void uart_init(unsigned int BAUDRATE);
void uart_tx(unsigned char data);
unsigned char uart_rx();

void intarray(int num);

int main(void)
{  uart_init(51);
	
	//unsigned char rec;
    /* Replace with your application code */
    while (1) 
    {
		
		
		intarray(12.5);
		//rec=uart_rx();
		//uart_tx();
    }
}
void uart_init( unsigned int BAUDRATE)
{
	UBRR0H=(BAUDRATE>>8);
	UBRR0L=(BAUDRATE);
	UCSR0B|=((1<<TXEN0)|(1<<RXEN0));
	UCSR0C|=((1<<UCSZ0)|(1<<UCSZ1));
	
}
 void uart_tx(unsigned char data)
{
	while(!((UCSR0A)&(1<<UDRE0)));
	UDR0=data;
}
unsigned char uart_rx()
{
	while(!((UCSR0A)&(1<<RXC0)));
	return UDR0;
}

// transmmitting integers//
void intarray( int num)
{int i;
	unsigned char number[4];
	int dup = num;
	 int dup2 = num;
	int n = 0,k;
	for(i=0;dup>0;i++)
	{
		dup = dup/10;
		n++;
		
	}
	for(i=0;i<n;i++)
	{
			k = dup2 % 10;
			number[i]= '0' + k;
			dup2 = (dup2)/10;
	}
	for(i=n-1;i>=0;i--)
	{
		uart_tx(number[i]);
	}
}