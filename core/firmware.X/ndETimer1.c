#include "ndETimer1/ndTimer1.h"

extern timer1Config_t timerConfig;
extern uint16_t timer1InitialValue;

void onTimer1Interrupt() {
    /* We reset the interruption and the timer value */
    PIR1bits.TMR1IF = 0;
    resetTimer1();

    PORTAbits.RA0 = ~LATAbits.LA0;
}