#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"

char nrprint(char *dataprint) {
	
	int printvalue;

	switch(*dataprint) {
		case '0': printvalue = 0x3F; break;
		case '1': printvalue = 0x06; break;
		case '2': printvalue = 0x5B; break;
		case '3': printvalue = 0x4F; break;
		case '4': printvalue = 0x66; break;
		case '5': printvalue = 0x6D; break;
		case '6': printvalue = 0x7D; break;
		case '7': printvalue = 0x07; break;
		case '8': printvalue = 0x7F; break;
		case '9': printvalue = 0x6F; break;
		default: printvalue = 0x00; break;
	}
	
	return printvalue;
	
}

int main(void)
{
	serial_init(USART_BAUDRATE);
    DDRB = 0xFF;
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

