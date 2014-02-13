/**
 * ndFlash is a library that allow you to write some instruction
 * on the PIC flash at runtime.
 *
 * ndFlash is used by and is designed for the event dispatcher of the ndEventBusCore.
 * Therefore, only write on empty flash(meaning full of FFh) is supported by
 * this module. If you want to be able to write on any part of the flash, the
 * ndNonEmptyFlash module is made for you.
 *
 * TODO : write ndNonEmptyFlash code to expose it in the API.
 *
 */

#include "../ndCore.h"
#include <stdint.h>

#ifndef NDFLASH_H
#define	NDFLASH_H

/**
 * Initialize the PIC register to allow writing on flash memory.
 * Must be done before doing any kind of operation on the flash.
 * You cannot open the flash and the eeprom at the same time.
 * TODO : handle the case when a dev wants to open the flash and the eeprom
 * 
 * Return 0 if the module cannot access the internal flash memory, otherwise return -1.
 */
uint8_t openFlash();

/**
 * Close an operation on the flash.
 * It will flush the operation before actually ending it.
 */
void closeFlash();

/**
 * Configure where the next write operation will occur
 * @param flashAddress Address to go to in flash
 */
void seekFlash(uint24_t flashAddress);

/**
 * Erase the block of flash memory that contains the given address.
 * A block is 32 bytes long and start on an address aligned on his length.
 *
 * /!\ Use with caution
 * @param flashAddress Address contained in the block we want to erase.
 */
void eraseFlash(uint24_t flashAddress);

/**
 * Number of byte to skip
 * @param numberOfBytes
 */
void skipFlash(uint8_t numberOfBytes);

void writeFlash(uint8_t data);

uint8_t readFlash();

/**
 * Writting on the flash of a PIC is quite particular.
 * You must ensure you are writting 16 words or 32 bytes.
 * This function will garanty that this rule is always ... (Never find the word :p).
 */
void flushFlash();

#endif	/* NDFLASH_H */

