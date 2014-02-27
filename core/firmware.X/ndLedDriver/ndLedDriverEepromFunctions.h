/**
 * All internal functions of the ndLedDriver module that are related to EEPROM.
 */

#include "../ndCore.h"

#include "ndLedDriverConstants.h"

#ifndef NDLEDDRIVEREEPROMFUNCTION_H
#define NDLEDDRIVEREEPROMFUNCTION_H

/**
 * Load the configuration of this module from the eeprom.
 * The configuration contains base values and prescalers for timers.
 * This function is called at the initialization of the module.
 */
void loadConfigurationFromEeprom();

void loadDimmingFromEeprom();

void loadBlinkingFromEeprom();

void saveTimerToEeprom(uint8_t eepromStartAddress, uint16_t baseValue, uint16_t prescaler);

#define saveDimmingTimerToEeprom(baseValue, prescaler) saveTimerToEeprom(LEDDRIVER_CONFIGURATION_DIMMING_START_ADDRESS, baseValue, prescaler)

#define saveBlinkingTimerToEeprom(uint16_t baseValue, uint16_t prescaler) saveTimerToEeprom(LEDDRIVER_CONFIGURATION_BLINKING_START_ADDRESS, baseValue, prescaler)

#endif