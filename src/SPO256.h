/*******************************************************************************
 * @file    SPO256.h
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
