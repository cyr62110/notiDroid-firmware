/* 
 * File:   ndLedDriver.h
 * Author: cyr62110
 *
 * Created on 19 février 2014, 20:15
 */

#include "../ndCore.h"

#include "ndLedDriverTypes.h"

#include "../ndTimer3/ndTimer3.h"

#ifndef NDLEDDRIVER_H
#define	NDLEDDRIVER_H

/**
 * Initialize the led driver module.
 */
void initLedDriver();

/**
 * Configure a register to be driven by the module.
 * All pin of the port will be considered as a manageable led.
 *
 * @param portRegister Register that control the port on wich are plugged some leds that will be managed by the module
 * @param latchRegister Matching latch register
 * @param mask Allow to disable some port by clearing the bit at 0. If all pin are connected to a led that should be driven by the module, mask = 0xFF
 */
void configureRegister(register_t *portRegister, register_t *latchRegister, register_t mask);

/**
 * Configure the base value and the prescaler of the dimming timer.
 * If writeInConfig is 0, the change will only be temporary. If -1, change will be
 * written in eeprom and should persist.
 */
void setDimmingTimer(uint8_t writeInConfig, uint16_t baseValue, uint16_t prescaler);

/**
 * Set the duration of the high level for a specific led.
 *
 * @param led
 * @param highLevelLength Number of dimming COMPUTE-ACT cycle with the led in "on" state.
 */
void setDimmingHighLevelLenght(uint8_t led, uint8_t highLevelLength);

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

/**
 * Set the 
 * duration unit is 10ms.
 */
void setBlinkingHighLevelDuration(uint8_t led, uint8_t duration);

/**
 * period unit is 10ms.
 */
void setBlinkingPeriod(uint8_t led, uint8_t period);

#define blinkingTimerInterrupt timer1Interrupt

void onBlinkingTimerInterrupt();

#endif	/* NDLEDDRIVER_H */

