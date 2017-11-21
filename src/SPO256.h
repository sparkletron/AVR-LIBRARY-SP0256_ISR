/*
ISR.h

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
 *      Version 1.0: See implementation file for details
 *
 *      This implementation allows the SP0256 speech chip to use a interrupt to get the next allophone.
 *      Allowing the microcontroller to be free to do other tasks. Works by using a pin interrupt so
 *      any IO can be used for monitoring LRQ. Does use ALD to pulse in data.
 *
 *      todo
 *      1) make pin assignment movable.
 */

#ifndef ISR_H_
#define ISR_H_

//librarys for avr micro controller
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <inttypes.h>
//included for _END
#include "allophones.h"

#define BUSY_TALKING 1

//initialize variables for talk routine
void initSPO256();
//calling this function and passing it an array of allophones will start the speech process
//returns 1 aka "BUSY_TALKING" if pharse is being processed. 0 if no phrase is being processed.
int talkSPO256(uint8_t *);



#endif /* ISR_H_ */
