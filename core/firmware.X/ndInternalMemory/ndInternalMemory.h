/**
 * ndInternalMemory contains some utility functions for ndFlash, ndEeprom, ndNonEmptyFlash modules.
 * It basicaly ensure that only one of this module is opened at the time.
 * 
 * This module should not be used in application developpement.
 */

#include "../ndCore.h"

#ifndef NDINTERNALMEMORY_H_
#define NDINTERNALMEMORY_H_

/**
 * Acquire a lock so only one module can use ECONX registers.
 * /!\ If the same try to open without having released the lock, it will fail to acquire the lock.
 * The function return -1 if the module has acquired the lock.
 * Or 0 is another module has the lock.
 */
uint8_t openInternalMemory();


/**
 * Configure the bits so the real write operation is executed.
 * This function is part of the internal work done by ndFlash, ndEeprom, ndNonEmptyFlash modules.
 *
 * /!\ Do not use in your program unless you know what you are doing.
 */
void doWriteInternalMemory();

/**
 * Macro providing an easy way to read a byte from one of the internal memmory
 */
#define readByteInternalMemory(readFunction, returnVariable) { returnVariable = readFunction(); }

/**
 * Macro providing an easy way to read a word from one of the internal memory
 */
#define readWordInternalMemory(readFunction, returnVariable) { returnVariable = readFunction(); returnVariable |= ((uint16_t)readFunction()) << 8; }

/**
 * Release the lock.
 * /!\ Do not forget or you will not be able to use any module.
 */
void closeInternalMemory();

#endif