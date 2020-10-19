#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int nrprint(char dataprint) {
	
	int printvalue = 0x00;
	
	if(dataprint == '0') {
		printvalue = 0x3F;
	}	
	if(dataprint == '1') {
		printvalue = 0x06;
	}
	if(dataprint == '2') {
		printvalue = 0x5B;
	}
	if(dataprint == '3') {
		printvalue = 0x4F;
	}
	if(dataprint == '4') {
		printvalue = 0x66;
	}
	if(dataprint == '5') {
		printvalue = 0x6D;
	}
	if(dataprint == '6') {
		printvalue = 0x7D;
	}
	if(dataprint == '7') {
		printvalue = 0x07;
	}
	if(dataprint == '8') {
		printvalue = 0x7F;
	}
	if(dataprint == '9') {
		printvalue = 0x6F;
	}
	
	return printvalue;
	
}

int main(void)
{
    DDRB = 0b11111111;
	
    while (1) 
    {
		PORTB = 0x00;
		_delay_ms(1000);
		for(int i = 0; i<10; i++){
			PORTB = nrprint('0'+ i);
			_delay_ms(1000);
		}
    }
	
	return 0;
}

