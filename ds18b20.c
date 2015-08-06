/***********************************************************************************
 DS18B20.C - A simple driver of DS18B20 temperature sensor for AVR MCUs
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
#include<avr/io.h>
#include<stdint.h>
#include<util/delay.h>
#include"bitoperation.h"
#include "ds18b20.h"


uint8_t DS18B20_Reset()
{
	_OUT_P(_DS18B20_PORT_,_DS18B20_PIN_);
	_CLR_P(_DS18B20_PORT_,_DS18B20_PIN_);
	_delay_us(480);
	_IN_P(_DS18B20_PORT_,_DS18B20_PIN_);
	_SETB_P(_DS18B20_PORT_,_DS18B20_PIN_);
	_delay_us(120);
	if(_PIN_P(_DS18B20_PORT_)&(1<<_DS18B20_PIN_))
	{	
		_delay_us(360);
		return 1;
	}
	else
	{
		_delay_us(360);
		return 0;
	}
}
uint8_t DS18B20_ReadBit()
{
	uint8_t b=0;
	_OUT_P(_DS18B20_PORT_,_DS18B20_PIN_);
	_CLR_P(_DS18B20_PORT_,_DS18B20_PIN_);
	_delay_us(2);
	_IN_P(_DS18B20_PORT_,_DS18B20_PIN_);
	_SETB_P(_DS18B20_PORT_,_DS18B20_PIN_);
	_delay_us(8);
	if(_PIN_P(_DS18B20_PORT_)&(1<<_DS18B20_PIN_))
	{
		b=1;
	}
	_delay_us(50);
	_IN_P(_DS18B20_PORT_,_DS18B20_PIN_);
	_SETB_P(_DS18B20_PORT_,_DS18B20_PIN_);
	_delay_us(2);
	return b;
}
void DS18B20_WriteBit(uint8_t b)
{
	_OUT_P(_DS18B20_PORT_,_DS18B20_PIN_);
	_CLR_P(_DS18B20_PORT_,_DS18B20_PIN_);
	_delay_us(2);
	if(b)
	{
		_OUT_P(_DS18B20_PORT_,_DS18B20_PIN_);
		_SETB_P(_DS18B20_PORT_,_DS18B20_PIN_);
	}
	_delay_us(58);
	_IN_P(_DS18B20_PORT_,_DS18B20_PIN_);
	_SETB_P(_DS18B20_PORT_,_DS18B20_PIN_);
	_delay_us(2);
}
void DS18B20_WriteByte(uint8_t cmd)
{
	uint8_t i;
	for(i=0;i<8;i++)
	{
		if(cmd&0x01)
			DS18B20_WriteBit(1);
		else
			DS18B20_WriteBit(0);
		cmd>>=1;
	}
}
uint8_t DS18B20_ReadByte()
{
	uint8_t i,ch;
	ch=0;
	for(i=0;i<8;i++)
	{
		ch>>=1;
		if(DS18B20_ReadBit())
			ch|=0x80;
		
	}
	return (ch);
}
uint8_t DS18B20_Init()
{
	if(DS18B20_Reset())
		return 1;
	DS18B20_WriteByte(0xCC);
	DS18B20_WriteByte(0x4E);
	DS18B20_WriteByte(0x64);
	DS18B20_WriteByte(0x8A);
	DS18B20_WriteByte(0x7F);
	return 0;
}

uint16_t DS18B20_GetTmperatureWithoutAddress()
{
	uint8_t th=0;
	uint8_t tl=0;
	uint16_t tmp2;
	DS18B20_Reset();
	DS18B20_WriteByte(0xCC);  //SKIP ROM
	DS18B20_WriteByte(0x44);
	_delay_ms(800);
	DS18B20_Reset();
	DS18B20_WriteByte(0xCC);
	DS18B20_WriteByte(0xBE);
	tl=DS18B20_ReadByte();
	th=DS18B20_ReadByte();
	tmp2=(tl)+(((uint16_t)th)<<8);
	
	return tmp2;
}
#ifndef NO_FLOAT
float DS18B20_ConvertTemperature(uint16_t dat)
{
	float temperature;
	uint8_t th,tl;
	th=dat>>8;
	tl=dat&0xFF;
	if (th&0x80)
	{
		uint16_t tmp;
		tmp=(th<<8)+tl;
		tmp&=0x07FF;
		tmp++;
		temperature=-(tmp/16.0);
	}
	else
	{
		temperature=((th<<8)+tl)/16.0;
	}
	return temperature;
}
#endif
void DS18B20_GetDeviceID(uint8_t * dat)
{
	DS18B20_Reset();
	DS18B20_WriteByte(0x33);
	dat[0]=DS18B20_ReadByte();
	dat[1]=DS18B20_ReadByte();
	dat[2]=DS18B20_ReadByte();
	dat[3]=DS18B20_ReadByte();
	dat[4]=DS18B20_ReadByte();
	dat[5]=DS18B20_ReadByte();
	dat[6]=DS18B20_ReadByte();
	dat[7]=DS18B20_ReadByte();


}
uint16_t DS18B20_GetTemperatureNonBlocking()
{
	uint8_t th=0;
	uint8_t tl=0;
	uint16_t tmp2;

	DS18B20_Reset();
	DS18B20_WriteByte(0xCC);
	DS18B20_WriteByte(0xBE);
	tl=DS18B20_ReadByte();
	th=DS18B20_ReadByte();
	
	tmp2=tl+(((uint16_t)th)<<8);

	//Start Next
	DS18B20_Reset();
	DS18B20_WriteByte(0xCC);  //SKIP ROM
	DS18B20_WriteByte(0x44);

	return tmp2;
}
