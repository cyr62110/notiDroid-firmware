/**
 * Those functions are part of the ndLedDriver module.
 *
 * They are all used by the module to manage his internal state,
 * so they must not be used outside the module code without caution.
 */

#ifndef NDLEDDRIVERINTERNALFUNCTIONS_H
#define	NDLEDDRIVERINTERNALFUNCTIONS_H

/**
 * Initialize the dimming timer module.
 * This function is called at the initialization of the module.
 */
void initDimmingTimer();

/**
 * Initialize the blinking timer module.
 * This function is called at the initialization of the module.
 */
void initBlinkingTimer();

/**
 * Load the configuration of this module from the eeprom.
 * The configuration contains base values and prescalers for timers.
 * This function is called at the initialization of the module.
 */
void loadConfigurationFromEeprom();

#endif	/* NDLEDDRIVERINTERNALFUNCTIONS_H */

