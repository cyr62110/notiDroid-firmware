/* 
 * File:   ndTimer3.h
 * Author: cyr62110
 *
 * Created on 18 février 2014, 22:47
 */

#include "../ndCore.h"

#ifndef NDTIMER3_H
#define	NDTIMER3_H

typedef struct _timer3Config_t {
    unsigned useInterrupt : 1;
    unsigned triggerEvent : 1;
    unsigned shouldLoop : 1;
} timer3Config_t ;

/**
 * Set the configuration that will be use for this timer
 * @param config
 */
void setUpTimer3(timer3Config_t config);

/**
 * Set the value of this timer. The value will be reuse as initial value if this
 * timer loops.
 * The prescaler can be one of this value : 1, 2, 4, 8
 * If -1 is used as prescaler, the prescaler value already set will not change.
 */
void setTimer3(uint16_t initialValue, uint16_t prescaler);

/**
 * Start the timer
 */
#define startTimer3() T3CONbits.TMR3ON = 1

/**
 * Stop the timer
 */
#define stopTimer3() T3CONbits.TMR3ON = 0

/**
 * Reset the timer.
 * For internal use only. Should be removed from this .h
 */
#define resetTimer3() TMR3 = timer3InitialValue

/**
 * Has the timer0 trigger his interrupt
 */
#define timer3Interrupt() PIR2bits.TMR3IF

/**
 * Reset the interrupt of the timer
 */
#define resetTimer3Interrupt() PIR2bits.TMR3IF = 0

/**
 * Function that should be called when the timer0 end
 * and trigger his interruption.
 */
void onTimer3Interrupt();

#endif	/* NDTIMER3_H */

