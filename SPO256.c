/*
ISR.c

atmega328P SP0256 using ISR

Copyright (C) July 17, 2014 John Convertino

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

 *  Created on: Jul 17, 2014
 *      Author: John Convertino
 *      Contact: electrobs@gmail.com
 *
 *      Version 1.0
 *      July 17th, 2014: Started, and completed.
 */

//Standard AVR includes
#include <avr/io.h>
#include <avr/common.h>
#include <avr/interrupt.h>
//interface file


#include "SPO256.h"
#include "commonDefines.h"

//global variables
char phraseLoaded = 0;
uint8_t *phrase = 0;

typedef struct
{
	volatile uint8_t *PORT;
	uint8_t *phrase;
	uint8_t busyFLAG:1;

} alophoneStruct;

uint8_t defaultPhrase[] = {_END};
volatile alophoneStruct alophoneData;

void pulseDataPort();

//ISR vector, static may or may not work
ISR(PCINT2_vect)
{
	//create temp value for checking LRQ state
	uint8_t data;
	//check LRQ pin
	data = (PIND & (1 << DDD7)) >> DD7;
	//if LRQ pin is high (1, ON) then chip is not ready to load data, exit
	if(data) return;
	//check for end of phrase
	if(*(alophoneData.phrase) == _END)
	{
		//since phrase has ended, set phraseLoaded flag to off
		alophoneData.busyFLAG = FLAG_OFF;
		//load required pause at end of phrase
		*(alophoneData.PORT) = PA1;
		//pulse ALD pin to load data
		pulseDataPort();
		return;
	}
	alophoneData.phrase++;
	//assign phrase element to port
	*(alophoneData.PORT) = *(alophoneData.phrase);
	pulseDataPort();
	//pulse ALD
}
void initSP0256()
{
	uint8_t tmpSREG = 0;

	tmpSREG = SREG;
	cli();

	alophoneData.PORT = &PORTD;
	alophoneData.busyFLAG = FLAG_OFF;
	alophoneData.phrase = defaultPhrase;
	//setup data port used to communicate with chip
	DDRD |= (1 << DDD0) | (1 << DDD1) | (1 << DDD2) | (1 << DDD3) | (1 << DDD4) | (1 << DDD5) | (1 << DDD6);
	//input pin will be taken care of by pin change interrupt (no need to check PIND)
	DDRD &= ~(1 << DDD7);
	//setup for interrupt based on pin change state
	PCICR = (1 << PCIE2);
	PCMSK2 = (1 << PCINT23);
	//set port to 0, clear any misc values
	*(alophoneData.PORT) = PA1;

	SREG = tmpSREG;
	//enable interrupts
	sei();
}
//Full function for loading phrase to pointer and starting first allophone
int talk(uint8_t *phraseToLoad)
{
	uint8_t bufSREG = SREG;
	cli();
	//if phraseLoaded flag is true (1) then exit function as phrase is not finished
	if (alophoneData.busyFLAG == FLAG_ON)
	{
		SREG = bufSREG;
		return BUSY_TALKING;
	}
	//copy pointer phraseToLoad to global pointer phrase
	alophoneData.phrase = phraseToLoad;
	//set phraseLoaded flag to true (1)
	alophoneData.busyFLAG = FLAG_ON;
	//Dereference pointer and assign allophone to PORT
	*(alophoneData.PORT) = *(alophoneData.phrase);
	//Pulse ALD pin high then low to load data into register
	pulseDataPort();
	SREG = bufSREG;

	return 0;
}

//Pulse ALD pin high then low to load data into register
void pulseDataPort()
{
	*(alophoneData.PORT) |= (1 << DDD6);
	_delay_us(1);
	*(alophoneData.PORT) &= ~(1 << DDD6);
}
