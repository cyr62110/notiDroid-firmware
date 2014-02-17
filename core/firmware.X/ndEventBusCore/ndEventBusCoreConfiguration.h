/*
 * This file contains constants that are used to configure the behavior
 * of the eventbus.
 */

#include "ndEventBusCoreConstants.h"

#ifndef NDEVENTBUSCORECONFIGURATION_H
#define	NDEVENTBUSCORECONFIGURATION_H

/* The eventbus require some eeprom to maintain some value between shutdown/start
 * cycle.
 */
#define EVENTBUSCORE_RESERVED_EEPROM_START_ADDRESS 255 - EVENTBUS_RESERVED_EEPROM_LENGTH

#define EVENTBUSCODE_RESERVED_FLASH_START_ADDRESS 0x7000

#endif

