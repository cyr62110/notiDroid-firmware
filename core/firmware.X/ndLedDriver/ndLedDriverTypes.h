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

/**
 * This struct give all information required to drive a port of the PIC.
 */
typedef struct _ledsInternalState_t {
	register_t *portRegister; /* Pointer to the register associated with the PORT on which are connected our leds */
	register_t *latchRegister; /* Pointer to the register associated with the LATCH of the PORT */
	register_t computedNextLedStates; /* Bits that will be copied on the PORT register to control our leds */
	register_t mask; /* Configure which pin will be controlled by the module. Set the bit to allow the pin to be controlled. */
} ledsInternalState_t;

struct _ledBlinkingInternalState_t {
    uint16_t counter; /* Counter for the led */
    uint16_t blinkingPeriod; /* Period of the blinking signal for one led */
    uint16_t blinkingHightLevelDuration; /* The duration of the high level for one led */
} ledBlinkingInternalState_t;

/* This struct store the internal state of this module */
typedef struct _ledDriverInternalState_t {
	uint8_t managedLedsMask[LEDDRIVER_NUMBER_OF_REGISTERS];
	
	ledsInternalState_t leds[LEDDRIVER_NUMBER_OF_REGISTERS];
	
    struct dimmingInternalState_t {
        unsigned currentDimmingCycle : 1;
        uint8_t counter; /* Counter */
        uint8_t counterResetMask; /* Bitmask used to know if the counter has reached its max value. If counter AND this value == 0 THEN reset the counter */
        uint8_t ledShutOffValue[LEDDRIVER_NUMBER_OF_LEDS];
        uint8_t nextLedStates[LEDDRIVER_NUMBER_OF_REGISTERS]; /* State of port registers as if all pins were used and only the dimming was applied. It is used to create the computedNextLedStates. */
    } dimming;
    
    struct blinkingInternalState_t {
    	ledBlinkingInternalState_t leds[LEDDRIVER_NUMBER_OF_LEDS];
    	uint8_t nextLedStates[LEDDRIVER_NUMBER_OF_REGISTERS]; /* State of port registers as if all pins were used and only the blinking was applied. It is used to create the computedNextLedStates. */
	} blinking;
} ledDriverInternalState_t;

#endif	/* NDLEDDRIVERTYPES_H */

