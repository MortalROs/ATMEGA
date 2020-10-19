#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define USART_BAUDRATE 9600

void serial_init ( unsigned short ubrr ) {
	UBRR0 = ubrr ; // Set baud rate
	UCSR0B |= (1 << TXEN0 ); // Turn on transmitter
	UCSR0B |= (1 << RXEN0 ); // Turn on receiver
	UCSR0C = (3 << UCSZ00 ); // Set for async . operation , no parity ,
	// one stop bit , 8 data bits
}

void serial_out ( char ch )
{
	while (( UCSR0A & (1 << UDRE0 )) == 0);
	UDR0 = ch ;
}

char serial_in ()
{
	while ( !( UCSR0A & (1 << RXC0 )) );
	return UDR0 ;
}

char nrprint(char *dataprint) {
	
	int printvalue = 0x00;
	
	if(*dataprint == '0') {
		printvalue = 0x3F;
	}	
	if(*dataprint == '1') {
		printvalue = 0x06;
	}
	if(*dataprint == '2') {
		printvalue = 0x5B;
	}
	if(*dataprint == '3') {
		printvalue = 0x4F;
	}
	if(*dataprint == '4') {
		printvalue = 0x66;
	}
	if(*dataprint == '5') {
		printvalue = 0x6D;
	}
	if(*dataprint == '6') {
		printvalue = 0x7D;
	}
	if(*dataprint == '7') {
		printvalue = 0x07;
	}
	if(*dataprint == '8') {
		printvalue = 0x7F;
	}
	if(*dataprint == '9') {
		printvalue = 0x6F;
	}
	
	return printvalue;
	
}

int main(void)
{
	serial_init(USART_BAUDRATE);
    DDRB = 0b11111111;
	PORTB = 0x00;
	char *text;
	
    while (1) 
    {
		*text = serial_in();
		serial_out(*text);
		PORTB = nrprint(text);
    }
	
	return 0;
}

