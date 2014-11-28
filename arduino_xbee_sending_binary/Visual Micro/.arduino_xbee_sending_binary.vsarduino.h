/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Pro or Pro Mini (5V, 16 MHz) w/ ATmega328, Platform=avr, Package=arduino
*/

#define __AVR_ATmega328p__
#define __AVR_ATmega328P__
#define ARDUINO 101
#define ARDUINO_MAIN
#define F_CPU 16000000L
#define __AVR__
#define __cplusplus
extern "C" void __cxa_pure_virtual() {;}

//
//
void value_to_add(int val);
void prepare_message( int value);
void newLine();

#include "C:\arduino-1.0.4-windows\arduino-1.0.4\hardware\arduino\variants\standard\pins_arduino.h" 
#include "C:\arduino-1.0.4-windows\arduino-1.0.4\hardware\arduino\cores\arduino\arduino.h"
#include "C:\Users\Tijmen\Dropbox\_M2.1\FMP\Code\nieuwe code verbeterd\arduino_xbee_sending_binary\arduino_xbee_sending_binary.ino"
