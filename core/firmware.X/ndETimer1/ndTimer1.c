#include "ndTimer1.h"

/* Global variable that contains the configuration that have been set up
 * for the timer */
timer1Config_t timer1Config;

/* Value that should be loaded in the timer when it reset */
uint16_t timer1InitialValue;

void setUpTimer1(timer1Config_t config) {
    /* We copy the configuration */
    timer1Config = config;

    /* Then we configure the timer register in the most standard way */
    T1CON = 0;
    T1CONbits.RD16 = 1;

    /* And we configure the interruption */
    PIE1bits.TMR1IE = config.useInterrupt;
}

void setTimer1(uint16_t uInitialValue, uint8_t prescaler) {
    uint8_t computedPrescaler = 0;

    /* We keep the initial value if we need to loop */
    timer1InitialValue = uInitialValue;
    if(prescaler > 0) {
        /* This part convert the number given as prescaler in a value acceptable in the register */
        prescaler >>= 1; /* Since 2 is 1, we need one shift to make this algorithm works as expected. */
        while(prescaler) {
            prescaler >>= 1;
            computedPrescaler ++;
        }
        /* We set the prescaler with the value calculated through our algo */
        T1CONbits.T1CKPS = computedPrescaler;
    }
    /* We set the initial value in the timer register */
    resetTimer1();
}

