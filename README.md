# SP0256 ISR driver
======================

Speech without busy wait (ISR), using SP0256

This library requires the commonDefines.h header which is located in the ATMEGA328P-LIBRARY-Common_Defines repository.

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
