/**
 * Those functions are part of the ndLedDriver module.
 *
 * They are all used by the module to manage his internal state,
 * so they must not be used outside the module code without caution.
 */

#ifndef NDLEDDRIVERINTERNALFUNCTIONS_H
#define	NDLEDDRIVERINTERNALFUNCTIONS_H

/**
 * Initialize the internal state of this module.
 */
void initInternalState();

/**
 * Initialize the dimming timer module.
 * This function is called at the initialization of the module.
 */
void initDimmingTimer();

/**
 * Initialize the internal state
 */
void initDimmingInternalState();

/**
 * Initialize the blinking timer module.
 * This function is called at the initialization of the module.
 */
void initBlinkingTimer();

/**
 * Initialize the internal state
 */
void initBlinkingInternalState();

#endif	/* NDLEDDRIVERINTERNALFUNCTIONS_H */

