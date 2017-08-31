/*
General Instruments/Radio Shack SP0256 Library

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

Contact: electrobs@gmail.com
 *
 *  Created on: Apr 20, 2014
 *      Author: John Convertino
 */

#ifndef ALLOPHONES_H_
#define ALLOPHONES_H_

#include <inttypes.h>

/*allophones defined for the SP0256
* v0.1
* by John Convertino
* 01/03/2013
*/


// SPEECH PROCESSOR ADDRESS VALUES IN HEX
// 1. PAUSES
#define PA1 0x00
#define PA2 0x01
#define PA3 0x02
#define PA4 0x03
#define PA5 0x04

//2. ALLOPHONES
#define OY  0x05
#define AY  0x06
#define EH  0x07
#define KK3 0x08
#define PP  0x09
#define JH  0x0A
#define NN1 0x0B
#define IH  0x0C
#define TT2 0x0D
#define RR1 0x0E
#define AX  0x0F
#define MM  0x10
#define TT1 0x11
#define DH1 0x12
#define IY  0x13
#define EY  0x14
#define DD_1 0x15
#define UW1 0x16
#define AO  0x17
#define AA  0x18
#define YY2 0x19
#define AE  0x1A
#define HH1 0x1B
#define BB1 0x1C
#define TH  0x1D
#define UH  0x1E
#define UW2 0x1F
#define AW  0x20
#define DD_2 0x21
#define GG3 0x22
#define VV  0x23
#define GG1 0x24
#define SH  0x25
#define ZH1  0x26
#define RR2 0x27
#define FF  0x28
#define KK2 0x29
#define KK1 0x2A
#define ZZ  0x2B
#define NG  0x2C
#define LL  0x2D
#define WW  0x2E
#define XR  0x2F
#define WH  0x30
#define YY1 0x31
#define CH  0x32
#define ER1 0x33
#define ER2 0x34
#define OW  0x35
#define DH2 0x36
#define SS  0x37
#define NN2 0x38
#define HH2 0x39
#define OR  0x3A
#define AR  0x3B
#define YR  0x3C
#define GG2 0x3D
#define EL  0x3E
#define BB2 0x3F
//outside address range, used to tell where a phoneme ends
#define _END 0xFF

#endif /* ALLOPHONES_H_ */
