/*
A simple implementation of DS18B20 temperature sensor. 
This driver uses one GPIO to communicate with sensor through 1-wire protocol,
NOTE: please adjust the pin-assignment in DS18B20_Reset()/DS18B20_ReadBit()/DS18B20_WriteBit() functions.
                                                                       hyzhang7
                                                                       2008
*/

#include<avr/io.h>
#include<util/delay.h>
#include<stdbool.h>
#include"bitoperation.h"

#define DS18B20_DQ          PC3

bool DS18B20_Reset()
{
	DDRC|=(1<<DS18B20_DQ);     //OUT
	CLR_PC(DS18B20_DQ);
	_delay_us(480);
	DDRC&=~(1<<DS18B20_DQ);    //IN
	SETB_PC(DS18B20_DQ);
	_delay_us(120);
	if(PINC&(1<<DS18B20_DQ))
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
bool DS18B20_ReadBit()
{
	bool b=0;
	DDRC|=(1<<DS18B20_DQ);     //OUT
	CLR_PC(DS18B20_DQ);
	_delay_us(2);
	DDRC&=~(1<<DS18B20_DQ);    //IN
	SETB_PC(DS18B20_DQ);
	_delay_us(8);
	if(PINC&(1<<DS18B20_DQ))
	{
		b=1;
	}
	_delay_us(50);
	DDRC&=~(1<<DS18B20_DQ);    //IN
	SETB_PC(DS18B20_DQ);
	_delay_us(2);
	return b;
}
void DS18B20_WriteBit(bool b)
{
	DDRC|=(1<<DS18B20_DQ);     //OUT
	CLR_PC(DS18B20_DQ);
	_delay_us(2);
	if(b)
	{
		DDRC&=~(1<<DS18B20_DQ);   
		SETB_PC(DS18B20_DQ);
	}
	_delay_us(58);
	DDRC&=~(1<<DS18B20_DQ);    //IN
	SETB_PC(DS18B20_DQ);
	_delay_us(2);
}
void DS18B20_WriteByte(unsigned char cmd)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if(cmd&0x01)
			DS18B20_WriteBit(1);
		else
			DS18B20_WriteBit(0);
		cmd>>=1;
	}
}
unsigned char DS18B20_ReadByte()
{
	unsigned char i,ch;
	ch=0;
	for(i=0;i<8;i++)
	{
		ch>>=1;
		if(DS18B20_ReadBit())
			ch|=0x80;
		
	}
	return (ch);
}
bool DS18B20_Init()
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

int DS18B20_GetTmperatureWithoutAddress()
{
	unsigned char th=0;
	unsigned char tl=0;
	unsigned int tmp2;
	int tmp=0;
	bool neg=0;
	DS18B20_Reset();
	DS18B20_WriteByte(0xCC);  //SKIP ROM
	DS18B20_WriteByte(0x44);
	_delay_ms(800);
	DS18B20_Reset();
	DS18B20_WriteByte(0xCC);
	DS18B20_WriteByte(0xBE);
	tl=DS18B20_ReadByte();
	th=DS18B20_ReadByte();
	tmp2=(tl)+(((unsigned int)th)<<8);
	if(tmp2&0x8000)
	{
		tmp2=~tmp2;
		tmp2++;
		neg=1;
	}
	else
	{
		neg=0;
	}
	tmp=((tmp2&0xfff0)>>4);
	if (neg)
		tmp=0-tmp;
	return tmp;
}

void DS18B20_GetDeviceID(unsigned char * dat)
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
unsigned int DS18B20_GetTemperatureAndConvert()
{
	unsigned char th=0;
	unsigned char tl=0;
	unsigned int tmp2;

	DS18B20_Reset();
	DS18B20_WriteByte(0xCC);
	DS18B20_WriteByte(0xBE);
	tl=DS18B20_ReadByte();
	th=DS18B20_ReadByte();
	
	tmp2=tl+(((unsigned int)th)<<8);

	//Start Next
	DS18B20_Reset();
	DS18B20_WriteByte(0xCC);  //SKIP ROM
	DS18B20_WriteByte(0x44);

	return tmp2;
}
