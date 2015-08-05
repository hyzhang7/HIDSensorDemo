#ifndef __DS18B20_HEADER__
#define __DS18B20_HEADER__ 1
#include <stdbool.h>
/* bool DS18B20_Reset()
Reset the 1-wire bus.
Parameters: none
Return value: 0- The device(s) correctly respond to the reset signal by pulling-down the bus.
              1- No device respond to the reset by pulling-down the bus. 
*/
bool DS18B20_Reset();
/* bool DS18B20_Init()
Initialize the DS18B20 device.
Parameters: none
Return value: 0- The device initialized successfully.
              1- Error during the initialization.
*/
bool DS18B20_Init();
/* unsigned int DS18B20_GetTmperatureWithoutAddress()
Get temperature without address. This function works when there is only 1 device on the bus. 
This is a Blocking function, it will take about 800ms to get the results.
Parameters: none
Return value: The temperature data, data format is defined in DS18B20 datasheet.
*/
unsigned int DS18B20_GetTmperatureWithoutAddress();
/* void DS18B20_WriteByte(unsigned char cmd)
Write one byte to the DS18B20 device.
Parameters: cmd - command/data to be writen to the device.
Return value: none
*/
void DS18B20_WriteByte(unsigned char cmd);
/* unsigned char DS18B20_ReadByte()
Read one byte from the DS18B20 device.
Parameters: none
Return value: One byte data read from DS18B20
*/
unsigned char DS18B20_ReadByte();

/* unsigned int DS18B20_GetTemperatureNonBlocking()
Get temperature from last convertion and start next convertion. 
This is a non-blocking function, it will return the temperature data from last convertion immediately 
and start next convertion.
Parameters: none
Return value: The temperature data, data format is defined in DS18B20 datasheet.
*/
unsigned int DS18B20_GetTemperatureNonBlocking();

/* void DS18B20_GetDeviceID(unsigned char * dat)
Get unique 8-byte-ID from DS18B20. 
Parameters: dat - pointer to the buffer for storing the 8-byte-ID
Return value: none
*/
void DS18B20_GetDeviceID(unsigned char * dat);

#endif
