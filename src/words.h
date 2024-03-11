/*******************************************************************************
 * @file    words.c
 * @author  Jay Convertino(electrobs@gmail.com)
 * @date    2014.07.17
 * @brief   Words for SP0256, easier to keep them in one place for repeated usage.
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

#include "allophones.h"

#ifndef WORDS_H_
#define WORDS_H_

//prebuilt words
uint8_t hello[] = {HH1, EH, LL, AX, OW, _END};
uint8_t celsius[] = {SS, EH, LL, SS, PA1, IH, AX, SS, _END};
uint8_t degrees[] = {DD_2, DD_2, IH, IH, PA1, GG1, ER1, IY, ZZ, _END};
uint8_t negative[] = {NG, EH, GG3, PA1, IH, PA1, TT1, IH, VV, _END};
uint8_t it[] = {IH, IH, PA2, TT1, _END};
uint8_t is[] = {IH, IH, PA1, ZZ, _END};
uint8_t pause[] = {PA5, _END};
uint8_t shit[] = {SH, IH, IH, PA2, TT1, _END};
uint8_t buzzer[] = {EH,EH,EH,EH,PA2, _END};
//uint8_t phrase[] ={HH1, EH, LL, AX, OW, PA5, IH, IH, PA2, TT1, PA5, IH, IH, PA2, ZZ, _END};
uint8_t hour[] = {EY, PA3, TT2, _END};
uint8_t oclock[] = {OW, PA2, KK1, LL, AA, AA, PA3, KK2, _END};
uint8_t PM[] = {PP, IY, PA3, EH, EH, MM, _END};
uint8_t name[] = {AE, DD_1, XR, NN1, _END};

//Create Structure for dictonary of number phoneme
struct phoneme_struct
{
  int number;
  uint8_t phoneme[14];
};

struct clock_struct
{
  uint8_t phoneme[19];
};

//Array of structure phoneme_lookup, stores phonemes of numbers
struct phoneme_struct number_dictonary[] = { {0, {ZZ, YR, OW, _END}}, {1, {WW, AX, NN1, _END}}, {2, {TT2, UW2, _END}}, {3, {TH, ER1, IY, _END}}, {4, {FF, FF, OR, _END}}, {5, {FF, FF, FF, AY, VV, _END}}, {6, {SH, IH, IH, PA3, KK1, SH, _END}}, {7, {SS, PA1, EH, EH, VV, IH, NN1, _END}},
{8, {EY, PA3, TT2, _END}}, {9, {NN1, AY, NN1, _END}}, {10, {TT2, EH, EH, NN1, _END}}, {11, {IH, LL, EH, EH, PA1, VV, IH, NN1, _END}}, {12, {TT2, WH, EH, EH, LL, PA1, VV, _END}}, {13, {TH, ER1, PA2, PA3, TT2, IY, NN1, _END}}, {14, {FF, OR, PA2, PA3, TT2, IY, NN1, _END}}, {15, {FF, IH, FF, PA2, PA3, TT2, IY, NN1, _END}},
{16, {SH, IH, PA3, KK2, SS, PA2, PA3, TT2, IY, NN1, _END}}, {17, {SS, PA2, EH, VV, TH, NN1, PA2, PA3, TT2, IY, NN1, _END}}, {18, {EY, PA2, PA3, TT2, IY, NN1, _END}}, {19, {NN1, AY, NN1, PA2, PA3, TT2, IY, NN1, _END}}, {20, {TT2, PA1, WH, EH, EH, NN1, PA2, PA3, TT2, IY, _END}},
{30, {TH, ER1, PA2, PA3, TT2, IY, _END}}, {40, {FF, OR, PA3, TT2, IY, _END}}, {50, {FF, FF, IH, FF, FF, PA2, PA3, TT2, IY, _END}}, {60, {SH, IH, PA3, KK2, SS, PA2, PA3, TT2, IY, _END}}, {70, {SS, PA1, EH, VV, IH, NN1, PA2, PA3, TT2, IY, _END}}, {80, {EY, PA3, TT2, IY, _END}},
{90, {NN1, AY, NN1, PA3, TT2, IY, _END}}, {100, {HH2, AX, AX, NN1, PA2, DD_1, RR2, HH1, PA1, IH, IH, PA1, DD_1, _END}} };

struct clock_struct time_dictonary[] = {{PA2, _END}, {WW, AX, NN1, _END}, {TT2, UW2, _END}, {TH, ER1, IY, _END}, {FF, FF, OR, _END}, {FF, FF, FF, AY, VV, _END}, {SH, IH, IH, PA3, KK1, SH, _END}, {SS, PA1, EH, EH, VV, IH, NN1, _END},
{EY, PA3, TT2, _END}, {NN1, AY, NN1, _END}, {TT2, EH, EH, NN1, _END}, {IH, LL, EH, EH, PA1, VV, IH, NN1, _END}, {TT2, WH, EH, EH, LL, PA1, VV, _END}, {TH, ER1, PA2, PA3, TT2, IY, NN1, _END}, {FF, OR, PA2, PA3, TT2, IY, NN1, _END}, {FF, IH, FF, PA2, PA3, TT2, IY, NN1, _END},
{SH, IH, PA3, KK2, SS, PA2, PA3, TT2, IY, NN1, _END}, {SS, PA2, EH, VV, TH, NN1, PA2, PA3, TT2, IY, NN1, _END}, {EY, PA2, PA3, TT2, IY, NN1, _END}, {NN1, AY, NN1, PA2, PA3, TT2, IY, NN1, _END},
{TT2, PA2, WH, EH, EH, NN1, PA2, PA3, TT2, IY, _END}, {TT2, PA2, WH, EH, EH, NN1, PA2, PA3, TT2, IY, PA2, WW, AX, NN1, _END}, {TT2, PA2, WH, EH, EH, NN1, PA2, PA3, TT2, IY, PA2, TT2, UW2, _END}, {TT2, PA2, WH, EH, EH, NN1, PA2, PA3, TT2, IY, PA2, TH, ER1, IY, _END},  {TT2, PA2, WH, EH, EH, NN1, PA2, PA3, TT2, IY,  PA2, FF, FF, OR, _END},
{TT2, PA2, WH, EH, EH, NN1, PA2, PA3, TT2, IY,  PA2, FF, FF, FF, AY, VV, _END},  {TT2, PA2, WH, EH, EH, NN1, PA2, PA3, TT2, IY, PA2, SH, IH, IH, PA3, KK1, SH, _END},  {TT2, PA2, WH, EH, EH, NN1, PA2, PA3, TT2, IY, PA2, SS, PA2, EH, EH, VV, IH, NN1, _END},  {TT2, PA2, WH, EH, EH, NN1, PA2, PA3, TT2, IY, PA2, EY, PA3, TT2, _END},
{TT2, PA2, WH, EH, EH, NN1, PA2, PA3, TT2, IY, PA2, NN1, AY, NN1, _END},
{TH, ER1, PA2, PA3, TT2, IY, _END}, {TH, ER1, PA2, PA3, TT2, IY,PA2, WW, AX, NN1, _END}, {TH, ER1, PA2, PA3, TT2, IY, PA2, TT2, UW2, _END}, {TH, ER1, PA2, PA3, TT2, IY, PA2, TH, ER1, IY, _END},  {TH, ER1, PA2, PA3, TT2, IY, PA2, FF, FF, OR, _END},
{TH, ER1, PA2, PA3, TT2, IY, PA2, FF, FF, FF, AY, VV, _END},  {TH, ER1, PA2, PA3, TT2, IY, PA2, SH, IH, IH, PA3, KK1, SH, _END},  {TH, ER1, PA2, PA3, TT2, IY, PA2, SS, PA2, EH, EH, VV, IH, NN1, _END},  {TH, ER1, PA2, PA3, TT2, IY, PA2, EY, PA3, TT2, _END},
{TH, ER1, PA2, PA3, TT2, IY, PA2, NN1, AY, NN1, _END},
{FF, OR, PA3, TT2, IY, _END}, {FF, OR, PA3, TT2, IY, PA2, WW, AX, NN1, _END}, {FF, OR, PA3, TT2, IY, PA2, TT2, UW2, _END}, {FF, OR, PA3, TT2, IY, PA2, TH, ER1, IY, _END},  {FF, OR, PA3, TT2, IY, PA2, FF, FF, OR, _END},
{FF, OR, PA3, TT2, IY, PA2, FF, FF, FF, AY, VV, _END},  {FF, OR, PA3, TT2, IY, PA2, SH, IH, IH, PA3, KK1, SH, _END},  {FF, OR, PA3, TT2, IY, PA2, SS, PA2, EH, EH, VV, IH, NN1, _END},  {FF, OR, PA3, TT2, IY, PA2, EY, PA3, TT2, _END},
{FF, OR, PA3, TT2, IY, PA2, NN1, AY, NN1, _END},
{FF, FF, IH, FF, FF, PA2, PA3, TT2, IY, _END}, {FF, FF, IH, FF, FF, PA2, PA3, TT2, IY, PA2, WW, AX, NN1, _END}, {FF, FF, IH, FF, FF, PA2, PA3, TT2, IY, PA2, TT2, UW2, _END}, {FF, FF, IH, FF, FF, PA2, PA3, TT2, IY, PA2, TH, ER1, IY, _END},  {FF, FF, IH, FF, FF, PA2, PA3, TT2, IY, PA2, FF, FF, OR, _END},
{FF, FF, IH, FF, FF, PA2, PA3, TT2, IY, PA2, FF, FF, FF, AY, VV, _END},  {FF, FF, IH, FF, FF, PA2, PA3, TT2, IY, PA2, SH, IH, IH, PA3, KK1, SH, _END},  {FF, FF, IH, FF, FF, PA2, PA3, TT2, IY, PA2, SS, PA2, EH, EH, VV, IH, NN1, _END},  {FF, FF, IH, FF, FF, PA2, PA3, TT2, IY, PA2, EY, PA3, TT2, _END},
{FF, FF, IH, FF, FF, PA2, PA3, TT2, IY, PA2, NN1, AY, NN1, _END}};


#endif /* WORDS_H_ */
