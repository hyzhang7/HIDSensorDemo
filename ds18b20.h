/***********************************************************************************
 DS18B20.H - A simple driver of DS18B20 temperature sensor for AVR MCUs
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
#ifndef __DS18B20_HEADER__
#define __DS18B20_HEADER__ 1
#include<stdint.h>

/*-----------Hardware Connection----------*/
#define _DS18B20_PORT_   C
#define _DS18B20_PIN_    PC3
/*________________________________________*/
/*Use float will increase the size of code*/
#define _NO_FLOAT_ 	     1
/*----------------------------------------*/

/* DS18B20_Reset--------------------------
Reset the 1-wire bus.
Parameters: none
Return value: 0- The device(s) correctly respond to the reset signal by pulling-down the bus.
              1- No device respond to the reset by pulling-down the bus. 
------------------------------------------*/
uint8_t DS18B20_Reset();

/* DS18B20_Init()--------------------------
Initialize the DS18B20 device.
Parameters: none
Return value: 0- The device initialized successfully.
              1- Error during the initialization.
-------------------------------------------*/
uint8_t DS18B20_Init();

/* DS18B20_GetTmperatureWithoutAddress()----
Get temperature without device address. This function works when there is only 1 device on the bus. 
This is a Blocking function, it will take about 800ms to get the results.
Parameters: none
Return value: The temperature data, data format is defined in DS18B20 datasheet.
--------------------------------------------*/
uint16_t DS18B20_GetTmperatureWithoutAddress();

/* DS18B20_WriteByte(uint8_t cmd)------------
Write one byte to the DS18B20 device.
Parameters: cmd - command/data to be writen to the device.
Return value: none
--------------------------------------------*/
void DS18B20_WriteByte(uint8_t cmd);

/* DS18B20_ReadByte()------------------------
Read one byte from the DS18B20 device.
Parameters: none
Return value: One byte data read from DS18B20
--------------------------------------------*/
uint8_t DS18B20_ReadByte();

/* DS18B20_GetTemperatureNonBlocking()-------
Get temperature from last convertion and start next convertion. 
This is a non-blocking function, it will return the temperature data from last convertion immediately 
and start next convertion.
Parameters: none
Return value: The temperature data, data format is defined in DS18B20 datasheet.
---------------------------------------------*/
uint16_t DS18B20_GetTemperatureNonBlocking();

/* DS18B20_GetDeviceID(uint8_t * dat)---------
Get unique 8-byte-ID from DS18B20. 
Parameters: dat - pointer to the buffer for storing the 8-byte-ID
Return value: none
---------------------------------------------*/
void DS18B20_GetDeviceID(uint8_t * dat);

/* DS18B20_ConvertTemperature(uint16_t dat)---
Convert DS18B20 data format into temperature in Celsius.
Parameters: Temperature data from sensor.
Return value: Temperature in Celsius.
---------------------------------------------*/
#ifndef _NO_FLOAT_
float DS18B20_ConvertTemperature(uint16_t dat);
#endif

#endif
