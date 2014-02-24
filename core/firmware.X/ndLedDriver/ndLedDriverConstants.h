/* 
 * File:   ndLedDriverConstants.h
 * Author: cyr62110
 *
 * Created on 19 février 2014, 22:30
 */

#ifndef NDLEDDRIVERCONSTANTS_H
#define	NDLEDDRIVERCONSTANTS_H

/**
 * Number of leds that are controlled by the module.
 */
#define LEDDRIVER_NUMBER_OF_LEDS 8

typedef uint8_t nextLedStates_t;

/**
 *
 */
#define LEDDRIVER_COMPUTE_CYCLE 0

/**
 * 
 */
#define LEDDRIVER_ACT_CYCLE 1

/**
 * Constants that give position of configuration value in the eeprom
 */
#define LEDDRIVER_CONFIGURATION_EEPROM_START_ADDRESS 0x10

#endif	/* NDLEDDRIVERCONSTANTS_H */

