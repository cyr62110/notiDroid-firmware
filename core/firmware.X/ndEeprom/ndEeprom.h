/**
 * ndEeprom is a module made for reading and writing on the eeprom included in the microcontroller.
 * It should be used to keep information across device shutdown/power on cycle.
 */

#include "../ndCore.h"

#ifndef NDEEPROM_H_
#define NDEEPROM_H_

/**
 * Initialize the PIC register to allow writing on eeprom memory.
 * Must be done before doing any kind of operation on the eeprom.
 * You cannot open the flash and the eeprom at the same time.
 * 
 * Return 0 if the module cannot access the internal flash memory, otherwise return -1.
 */
uint8_t openEeprom();

/**
 * 
 */
void closeEeprom();

/**
 * 
 */
void writeEeprom(uint8_t data);

/**
 * 
 */
uint8_t readEeprom();

/**
 * 
 */
void seekEeprom(uint8_t eepromAddress);

/**
 * 
 */
void skipEeprom(uint8_t numberOfBytes);

#endif