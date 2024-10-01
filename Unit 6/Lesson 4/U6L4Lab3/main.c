/*
 * main.c
 *
 *  Created on: Sep 27, 2024
 *      Author: DELL
 */

#include <util/delay.h> /* For the delay functions */
#include <avr/io.h>
#include<avr/interrupt.h>

	ISR(INT0_vect){
		PORTD |= (1<<PD5);
		_delay_ms(1000);

	}
	ISR(INT1_vect){
		PORTD |= (1<<PD6);
	   _delay_ms(1000);

		}
	ISR(INT2_vect){
		PORTD |= (1<<PD7);
		_delay_ms(1000);

		}
int main(){


DDRD &= ~(1<<PD2);
DDRD &= ~(1<<PD3);
DDRB &= ~(1<<PB2);
SREG |= (1<<7);
DDRD |= (1<<PD5);
DDRD |= (1<<PD6);
DDRD |= (1<<PD7);
//****
MCUCR |= (1<<ISC00) |(1<<ISC01) |(1<<ISC11);
MCUCSR &= ~(1<<ISC2);
GICR |=(1<<INT0) |(1<<INT1)|(1<<INT2);


while(1){
PORTD &= ~((1<<PD5) | (1<<PD6) |(1<<PD7));
_delay_ms(1000);
}
}
