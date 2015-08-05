/* LED.h
Convenient way to turn on/off of LEDs.
                                            hyzhang7
                                            2015
*/

#ifndef __LED_H__
#define __LED_H__     1
#include "bitoperation.h"
/*
LED1 -  PD5
LED2 -  PD6
LED3 -  PD7
*/
#define LED_Init()	DDRD|=0xE0;
#define LED_On(x)	CLR_PD(PD4+x);
#define LED_Off(x)	SETB_PD(PD4+x);


#endif
