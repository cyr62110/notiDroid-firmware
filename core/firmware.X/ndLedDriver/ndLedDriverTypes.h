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

/* This struct store all the value that are stored */
typedef struct _ledDriverConfiguration_t {
    uint16_t dimmingTimerBaseValue;
    uint8_t dimmingTimerPrescaler;
    uint16_t blinkingTimerBaseValue;
    uint8_t blinkingTimerPrescaler;
} ledDriverConfiguration_t;

/* This struct store the internal state of this module */
typedef struct _ledDriverInternalState_t {
    struct dimmingInternalState_t {
        unsigned currentDimmingCycle : 1;
        uint8_t currentDimmingCounter; /* Counter that */
        uint8_t ledShutOffValue[LEDDRIVER_NUMBER_OF_LEDS];
    } dimming;
    struct blinkingInternalState_t {
        unsigned currentBlinkingCycle : 1;
    } blinking;
} ledDriverInternalState_t;

#endif	/* NDLEDDRIVERTYPES_H */

