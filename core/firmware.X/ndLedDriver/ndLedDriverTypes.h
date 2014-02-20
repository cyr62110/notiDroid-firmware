/* 
 * File:   ndLedDriverTypes.h
 * Author: cyr62110
 *
 * Created on 19 février 2014, 22:23
 */

#include "../ndCore.h"

#ifndef NDLEDDRIVERTYPES_H
#define	NDLEDDRIVERTYPES_H

/* This struct store all the value that are stored */
typedef struct _ledDriverConfiguration_t {
    uint16_t dimmingTimerBaseValue;
    uint8_t dimmingTimerPrescaler;
    uint16_t blinkingTimerBaseValue;
    uint8_t blinkingTimerPrescaler;
} ledDriverConfiguration_t;

#endif	/* NDLEDDRIVERTYPES_H */

