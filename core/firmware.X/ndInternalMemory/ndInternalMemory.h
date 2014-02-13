/**
 * ndInternalMemory contains some utility functions for ndFlash, ndEeprom, ndNonEmptyFlash modules.
 * It basicaly ensure that only one of this module is opened at the time.
 * 
 * This module should not be used in application developpement.
 */

#include <stdint.h>

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
 * Release the lock.
 * /!\ Do not forget or you will not be able to use any module.
 */
void closeInternalMemory();

#endif