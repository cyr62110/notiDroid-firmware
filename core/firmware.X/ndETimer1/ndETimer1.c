#include "ndETimer1.h"

/* Global variable that contains the configuration that have been set up
 * for the timer */
timer1Config_t timerConfig;

/* Value that should be loaded in the timer when it reset */
uint16_t initialValue;

void setUpTimer1(timer1Config_t config) {
    /* We copy the configuration */
    timerConfig = config;

    /* Then we configure the timer register in the most standard way */
    T1CON = 0;
    T1CONbits.RD16 = 1;

    /* And we configure the interruption since we are using the eventbus */
    PIE1bits.TMR1IE = 1;
}

void setTimer1(uint16_t uInitialValue, uint8_t prescaler) {
    T1CONbits.T1CKPS = prescaler;
    initialValue = uInitialValue;
    
    resetTimer1();
}

void onTimer1Interrupt() {
    /* We reset the interruption and the timer value */
    PIR1bits.TMR1IF = 0;
    resetTimer1();

    PORTAbits.RA0 = ~LATAbits.LA0;
}