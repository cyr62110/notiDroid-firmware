#include "ndTimer3.h"

/* Global variable that contains the configuration that have been set up
 * for the timer */
timer3Config_t timer3Config;

/* Value that should be loaded in the timer when it reset */
uint16_t timer3InitialValue;


void setUpTimer3(timer3Config_t config) {
    /* We copy the configuration */
    timer3Config = config;

    /* Then we configure timer registers */
    T3CON = 0;
    T3CONbits.RD16 = 1;

    /* Finally we configure the interruption */
    PIE2bits.TMR3IE = config.useInterrupt;
}

void setTimer3(uint16_t uInitialValue, uint16_t prescaler) {
    uint8_t computedPrescaler = 0;

    /* We keep the initial value if we need to loop */
    timer3InitialValue = uInitialValue;
    if(prescaler > 0) {
        /* This part convert the number given as prescaler in a value acceptable in the register */
        prescaler >>= 1; /* Since 1 is 0, we need two shift to make this algorithm works as expected. */
        while(prescaler) {
            prescaler >>= 1;
            computedPrescaler ++;
        }
        /* We set the prescaler with the value calculated through our algo*/
        T3CONbits.T3CKPS = computedPrescaler;
    }
    /* We set the initial value in the timer register */
    resetTimer3();
}

void onTimer3Interrupt() {
    /* We reset the interruption and the timer value */
    resetTimer3Interrupt();
    resetTimer3();

    PORTAbits.RA0 = ~LATAbits.LA0;
}


