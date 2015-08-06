/***********************************************************************************
 BITOPERATION.H - Convenient MACROs for bit-wise operations of GPIO pins on AVR MCUs.
Version 1.0 (2008)
Copyright (c) 2008-2015 hyzhang7

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
                                                               hyzhang7
                                                               2008
                                                               All rights reserved.
************************************************************************************/


#ifndef __BIT_OPT_GENERAL__
#define __BIT_OPT_GENERAL__

#define SETB_P(port,pin)  (SETB_P ## port(pin))
#define CLR_P(port,pin)   (CLR_P ## port(pin))
#define OUT_P(port,pin)   (DDR ## port |=(1<<pin))
#define IN_P(port,pin)    (DDR ## port &=~(1<<pin))
#define PIN_P(port)       (PIN ## port)

#define _SETB_P(port,pin) SETB_P(port,pin)
#define _CLR_P(port,pin)  CLR_P(port,pin)
#define _OUT_P(port,pin)  OUT_P(port,pin)
#define _IN_P(port,pin)   IN_P(port,pin)
#define _PIN_P(port)      PIN_P(port) 
#endif

#ifndef __BIT_OPT_PD__
#define __BIT_OPT_PD__ 
#define  SETB_PD(x)  PORTD|=(1<<(x))
#define  CLR_PD(x)   PORTD&=~(1<<(x))
#endif

#ifndef __BIT_OPT_PB__
#define __BIT_OPT_PB__
#define  SETB_PB(x)  PORTB|=(1<<(x))
#define  CLR_PB(x)   PORTB&=~(1<<(x))
#endif

#ifndef __BIT_OPT_PC__
#define __BIT_OPT_PC__
#define  SETB_PC(x)  PORTC|=(1<<(x))
#define  CLR_PC(x)   PORTC&=~(1<<(x))
#endif

#ifndef __BIT_OPT_PA__
#define __BIT_OPT_PA__
#define  SETB_PA(x)  PORTA|=(1<<(x))
#define  CLR_PA(x)   PORTA&=~(1<<(x))
#endif

#ifndef __BIT_OPT_PE__
#define __BIT_OPT_PE__
#define  SETB_PE(x)  PORTE|=(1<<(x))
#define  CLR_PE(x)   PORTE&=~(1<<(x))
#endif

#ifndef __BIT_OPT_PF__
#define __BIT_OPT_PF__
#define  SETB_PF(x)  PORTF|=(1<<(x))
#define  CLR_PF(x)   PORTF&=~(1<<(x))
#endif

#ifndef __BIT_OPT_PG__
#define __BIT_OPT_PG__
#define  SETB_PG(x)  PORTG|=(1<<(x))
#define  CLR_PG(x)   PORTG&=~(1<<(x))
#endif
