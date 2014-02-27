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
#define LEDDRIVER_COUNTER_RESET_MASK 0x0F

/**
 *
 */
#define LEDDRIVER_COMPUTE_CYCLE 0

/**
 * 
 */
#define LEDDRIVER_ACT_CYCLE 1

/**
 * Since the configuration of this module can be modified by software, all the value are
 * not hardcoded in the source code. So the module require some eeprom space to store its
 * configuration.
 * 
 * Following constants are all related to the configuration and where it is stored in EEPROM
 */

/**
 * Address where the configuration of the module starts
 */
#define LEDDRIVER_CONFIGURATION_START_ADDRESS 0x10

/**
 * Position in EEPROM where is stored the base value and the prescaler for the dimming timer.
 * Organisation :
 * 	- Base Value : Double Word
 *  - Prescaler : Double Word
 */
#define LEDDRIVER_CONFIGURATION_DIMMING_START_ADDRESS 0x10

/**
 * Length in bytes of the configuration of the dimming timer
 */
#define LEDDRIVER_CONFIGURATION_DIMMING_LENGHT 4

/**
 * Position in EEPROM where is stored the base value and the prescaler for the blinking timer.
 * Organisation :
 *  - Base Value : Double Word
 *  - Prescaler : Double Word
 */
#define LEDDRIVER_CONFIGURATION_BLINKING_START_ADDRESS LEDDRIVER_CONFIGURATION_DIMMING_START_ADDRESS + LEDDRIVER_CONFIGURATION_DIMMING_LENGHT

/**
 * Length in bytes of the configuration of the blinking timer
 */
#define LEDDRIVER_CONFIGURATION_BLINKING_LENGHT 4

#endif	/* NDLEDDRIVERCONSTANTS_H */

