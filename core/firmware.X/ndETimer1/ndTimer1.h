/**
 * ndETimer1 is a library to help you to use the Timer1 module included in your
 * PIC.
 *
 * Not all operations that are possible through the registers are available with
 * this API. The main concern of this API is to help you to use the eventbus.
 */

#include "../ndCore.h"

#ifndef NDETIMER1_H
#define	NDETIMER1_H

/**
 * Describe the configuration of this timer
 */
typedef struct _timer1Config {
    unsigned triggerEvent : 1;
    unsigned shouldLoop : 1;
} timer1Config_t;

/**
 * Set the configuration that will be use for this timer
 * @param config
 */
void setUpTimer1(timer1Config_t config);

/**
 * Set the value of this timer. The value will be reuse as initial value if this
 * timer loops.
 */
void setTimer1(uint16_t initialValue, uint8_t prescaler);

/**
 * Start the timer
 */
#define startTimer1() T1CONbits.TMR1ON = 1

/**
 * Stop the timer
 */
#define stopTimer1() T1CONbits.TMR1ON = 0

/**
 * Reset the timer.
 * For internal use only. Should be removed from this .h
 */
#define resetTimer1() TMR1 = timer1InitialValue

/**
 * Has the timer1 trigger his interrupt
 */
#define timer1Interrupt() PIR1bits.TMR1IF

/**
 * Function that should be called when the timer1 end
 * and trigger his interruption.
 */
void onTimer1Interrupt();

#endif	/* NDETIMER1_H */

