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

/**
 * Number of physical pin on the microcontroller that can be controlled by on register.
 * This part is not configurable in the current version of this module
 */
#define LEDDRIVER_NUMBER_OF_PIN_PER_REGISTER 8

/**
 * Number of register that control led states.
 * For ex., with 8 leds, we only use one port which is represented by on register.
 */
#define LEDDRIVER_NUMBER_OF_REGISTERS LEDDRIVER_NUMBER_OF_LEDS / LEDDRIVER_NUMBER_OF_PIN_PER_REGISTER

/**
 * Mask used to know if the counter has reached its max value
 */
#define LEDDRIVER_COUNTER_RESET_MASK 0x1F

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

