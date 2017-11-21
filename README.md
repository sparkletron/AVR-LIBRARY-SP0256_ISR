# SP0256 ISR driver
======================

Speech without busy wait (ISR), using SP0256

This library requires the commonDefines.h header which is located in the ATMEGA328P-LIBRARY-Common_Defines repository.

This code is licensed under the following GNU GPL V2 (also same notice in all source code):

    atmel328P ISR based method for SP0256 speech chip
    Copyright (C) July 17th, 2014  John Convertino

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

This will be a C library usuable in AVR Studio, and the generic AVR compiler.

## Example
```c
#include <inttypes.h>
#include <avr/common.h>
#include <avr/io.h>

#include "words.h"
#include "SPO256.h"

int main(void)
{
	initSPO256();
	
	for(;;)
	{
		while(talkSPO256(hello));
		while(talkSPO256(pause));
	}
}
```
