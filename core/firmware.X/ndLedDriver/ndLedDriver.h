/* 
 * File:   ndLedDriver.h
 * Author: cyr62110
 *
 * Created on 19 février 2014, 20:15
 */

#include "../ndCore.h"

#include "../ndTimer3/ndTimer3.h"

#ifndef NDLEDDRIVER_H
#define	NDLEDDRIVER_H

/**
 * Initialize the led driver module.
 * Il will make 
 */
void initLedDriver();

/**
 * Configure the base value and the prescaler of the dimming timer.
 * If writeInConfig is 0, the change will only be temporary. If -1, change will be
 * written in eeprom and should persist.
 */
void setDimmingTimer(uint8_t writeInConfig, uint16_t baseValue, uint16_t prescaler);

/**
 * Test if the dimming timer has interrupted
 */
#define dimmingTimerInterrupt timer3Interrupt

/**
 * This function must be called when the dimming timer interrupts.
 * Put this code in the interrupt service routine :
 * if(onDimmingTimerInterrupt()) { onDimmingTimerInterrupt(); }
 */
void onDimmingTimerInterrupt();

/**
 * Configure the base value and the prescaler of the blinking timer.
 * If writeInConfig is 0, the change will only be temporary. If -1, change will be
 * written in eeprom and should persist.
 */
void setBlinkingTimer(uint8_t writeInConfig, uint16_t baseValue, uint16_t prescaler);

#define blinkingTimerInterrupt onTimer1Interrupt

void onBlinkingTimerInterrupt();

#endif	/* NDLEDDRIVER_H */

