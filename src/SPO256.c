/*******************************************************************************
 * @file    SPO256.c
 * @author  Jay Convertino(electrobs@gmail.com)
 * @date    2014.07.17
 * @brief   atmega328P SP0256 using ISR
 * @detail  This implementation allows the SP0256 speech chip to use a interrupt to get the next allophone.
 *          Allowing the microcontroller to be free to do other tasks. Works by using a pin interrupt so
 *          any IO can be used for monitoring LRQ. Does use ALD to pulse in data.
 * @version 0.6.0
 *
 * @TODO
 *  - Cleanup interface
 *
 * @license mit
 *
 * Copyright 2024 Johnathan Convertino
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 ******************************************************************************/

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
	volatile uint8_t *phrase;
	volatile uint8_t busyFLAG:1;

} alophoneStruct;

uint8_t defaultPhrase[] = {_END};
volatile alophoneStruct alophoneData;

//helper functions
void pulseDataPort();

//public functions
void initSPO256()
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
int talkSPO256(uint8_t *phraseToLoad)
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

//helper function
//Pulse ALD pin high then low to load data into register
void pulseDataPort()
{
	*(alophoneData.PORT) |= (1 << DDD6);
	_delay_us(100);
	*(alophoneData.PORT) &= ~(1 << DDD6);
}

//ISR vector, static may or may not work
ISR(PCINT2_vect)
{
	//if LRQ pin is high (1, ON) then chip is not ready to load data, exit
	if((PIND & (1 << DDD7)) >> DD7) return;
	
	if(alophoneData.busyFLAG == FLAG_OFF) return;

	alophoneData.phrase++;
	
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
	//assign phrase element to port
	*(alophoneData.PORT) = *(alophoneData.phrase);
	
	pulseDataPort();
	//pulse ALD
}
