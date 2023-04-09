/*
 * Michael Amoah
 * ECE484 Chip Interface Project
 * Tilt Switch 
 * tilt.c
 */

#include <avr/io.h>
#include <util/delay.h>

/* C Prototypes of functions */
short is_tilted(int pin_number);

int main (void) 
{

	DDRD |= _BV(DDD5);	// Set LED pin 5 to output mode
	DDRD &= ~_BV(DDD7);	// Set tilt switch pin 7
	PORTD |= _BV(DDD7);
	DDRB |= _BV(DDB3);	// Set buzzer pin 11 to output mode

	while(1) 
	{
		if (is_tilted(PD7)) 
		{
			PORTD &= ~_BV(PORTD5);          // Keep LED OFF
			PORTB &= ~_BV(PORTB3);          // Keep Buzz OFF	
		}
		else {
			PORTD |= _BV(PORTD5);                // Turn LED ON
			PORTB |= _BV(PORTB3);                // Play Buzzer
		}
	}

}


/* 
 *  Here is a function you can use to simply use the tilt switch
 *  The is_tilted function checks when the tilt switch is tilted 
 *  If tilted ON else OFF 
 */
short is_tilted(int pin_number) 
{
	short tilted; 
	if (PIND & (1 << pin_number))
	{ 
		tilted = 1;
	}	
	else 
	{
		tilted = 0;
	}

	return tilted;
}
