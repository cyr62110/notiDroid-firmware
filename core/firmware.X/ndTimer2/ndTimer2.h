/* 
 * File:   ndTimer2.h
 * Author: cyr62110
 *
 * Created on 18 février 2014, 23:57
 */

#include "../ndCore.h"

#ifndef NDTIMER2_H
#define	NDTIMER2_H

typedef struct _timer2Config_t {
    unsigned useInterrupt : 1;
    unsigned triggerEvent : 1;
    unsigned shouldLoop : 1;
} timer2Config_t ;

/**
 * Set the configuration that will be use for this timer
 * @param config
 */
void setUpTimer2(timer2Config_t config);

/**
 * Set the value of this timer. The value will be reuse as initial value if this
 * timer loops.
 * The prescaler can be one of this value : 1..16, 4x(1..16) , 16x(1..16)
 * If 0 is used as prescaler, the prescaler value already set will not change.
 *
 * /!\ Physically, timer2 has a prescaler and a postscaler that have the same function.
 * So we expose this as a single prescaler in the API.
 */
void setTimer2(uint16_t initialValue, uint16_t prescaler);

/**
 * Start the timer
 */
#define startTimer2() T2CONbits.TMR2ON = 1

/**
 * Stop the timer
 */
#define stopTimer2() T2CONbits.TMR2ON = 0

/**
 * Reset the timer.
 * For internal use only. Should be removed from this .h
 */
#define resetTimer2() TMR2 = timer2InitialValue

/**
 * Has the timer0 trigger his interrupt
 */
#define timer2Interrupt() PIR1bits.TMR2IF

/**
 * Reset the interrupt of the timer
 */
#define resetTimer2Interrupt() PIR1bits.TMR2IF = 0

/**
 * Function that should be called when the timer0 end
 * and trigger his interruption.
 */
void onTimer2Interrupt();


#endif	/* NDTIMER2_H */

