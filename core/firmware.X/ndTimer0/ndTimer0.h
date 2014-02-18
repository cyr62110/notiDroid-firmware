/**
 * 
 */

#include "../ndCore.h"

#ifndef NDTIMER0_H
#define	NDTIMER0_H

typedef struct _timer0Config_t {
    unsigned use16bitsRegister : 1;
    unsigned useInterrupt : 1;
    unsigned triggerEvent : 1;
    unsigned shouldLoop : 1;
} timer0Config_t ;

/**
 * Set the configuration that will be use for this timer
 * @param config
 */
void setUpTimer0(timer0Config_t config);

/**
 * Set the value of this timer. The value will be reuse as initial value if this
 * timer loops.
 * The prescaler can be one of this value : 1, 2, 4, 8, 16, 32, 64, 128, 256
 * If 0 is used as prescaler, the prescaler value already set will not change.
 */
void setTimer0(uint16_t initialValue, uint16_t prescaler);

/**
 * Start the timer
 */
#define startTimer0() T0CONbits.TMR0ON = 1

/**
 * Stop the timer
 */
#define stopTimer0() T0CONbits.TMR0ON = 0

/**
 * Reset the timer.
 * For internal use only. Should be removed from this .h
 */
#define resetTimer0() TMR0 = timer0InitialValue

/**
 * Has the timer0 trigger his interrupt
 */
#define timer0Interrupt() INTCONbits.T0IF

/**
 * Reset the interrupt of the timer
 */
#define resetTimer0Interrupt() INTCONbits.T0IF = 0

/**
 * Function that should be called when the timer0 end
 * and trigger his interruption.
 */
void onTimer0Interrupt();

#endif

