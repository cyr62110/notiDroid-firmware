/* 
 * File:   ndLedDriverTypes.h
 * Author: cyr62110
 *
 * Created on 19 février 2014, 22:23
 */

#include "../ndCore.h"
#include "ndLedDriverConstants.h"

#ifndef NDLEDDRIVERTYPES_H
#define	NDLEDDRIVERTYPES_H

typedef uint8_t register_t;

/* This struct store all the value that are stored */
typedef struct _ledDriverConfiguration_t {
    uint16_t dimmingTimerBaseValue;
    uint8_t dimmingTimerPrescaler;
    uint16_t blinkingTimerBaseValue;
    uint8_t blinkingTimerPrescaler;
} ledDriverConfiguration_t;

typedef struct _ledsInternalState_t [
	register_t *portRegister;
	register_t *latchRegister;
	register_t computedNextLedStates;
	register_t mask;
} ledsInternalState_t;

/* This struct store the internal state of this module */
typedef struct _ledDriverInternalState_t {
	uint8_t managedLedsMask[LEDDRIVER_NUMBER_OF_REGISTERS];
	
	ledsInternalState_t leds[LEDDRIVER_NUMBER_OF_REGISTERS];
	
    struct dimmingInternalState_t {
        unsigned currentDimmingCycle : 1;
        uint8_t counter; /* Counter */
        uint8_t counterResetMask /* Bitmask used to know if the counter has reached its max value. If counter AND this value == 0 THEN reset the counter */
        uint8_t ledShutOffValue[LEDDRIVER_NUMBER_OF_LEDS];
        uint8_t nextLedStates[LEDDRIVER_NUMBER_OF_REGISTERS]; /* Variable that will be written on the register that controls the leds */
    } dimming;
    
    struct blinkingInternalState_t {
        unsigned currentBlinkingCycle : 1;
    } blinking;
} ledDriverInternalState_t;

#endif	/* NDLEDDRIVERTYPES_H */

