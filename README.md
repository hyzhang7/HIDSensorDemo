# HIDSensorDemo
A temperature sensor device compatible with Microsoft HID Sensor Class Driver

Introduction:
Microsoft has introduced HID Sensor Class with its Windows 8. Windows 8 and later have a in-box driver for the sensors with HID protocol. With the support of in-box driver, on one hand, the hardware developers do not have to write a Windows device driver for their device which is time-consuming; on another hand, the users do not have to download or install drivers before using these sensors and the Windows will install the correct drivers automatically, similar to the mice/keyboards.

In this demo, I use the v-usb<https://www.obdev.at/products/vusb/index.html> to implement USB function on a ATMEL AVR mcu (atmega328p), a digital temperature sensor (ds18b20) to measure the environment temperature. Once connected to a PC with windows 8 and later, the board will be automatically enumerated as "HID Temperature Sensor" in the "Device Manager". to access the sensor, we can use API provided by Microsoft in the user-mode applications, or simply test the sensor with "Sensor Diagnostic Tool".   




Major Hardware Components:
1. Atmel ATMEGA328P
2. 18MHz Crystal Oscillator (According to v-usb, there are several options on the Freq.)
3. Maxim DS18B20
4. Mini USB Receptacle 
5. LEDs (Optional, only for display status)
5. Resistors/Capacitors



