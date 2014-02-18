#include "ndTimer0.h"

/* Global variable that contains the configuration that have been set up
 * for the timer */
timer0Config_t timer0Config;

/* Value that should be loaded in the timer when it reset */
uint16_t timer0InitialValue;


void setUpTimer0(timer0Config_t config) {
    /* We copy the configuration */
    timer0Config = config;

    /* Then we configure timer registers */
    T0CON = 0;
    T0CONbits.T08BIT = ~config.use16bitsRegister;

    /* Finally we configure the interruption */
    INTCONbits.TMR0IE = config.useInterrupt;
}

void setTimer0(uint16_t uInitialValue, uint16_t prescaler) {
    uint8_t computedPrescaler = 0;

    /* We keep the initial value if we need to loop */
    timer0InitialValue = uInitialValue;
    if(prescaler > 0) {
        if(prescaler == 1)
            T0CONbits.PSA = 1;
        else {
            /* This part convert the number given as prescaler in a value acceptable in the register */
            prescaler >>= 2; /* Since 2 is 0, we need two shift to make this algorithm works as expected. */
            while(prescaler) {
                prescaler >>= 1;
                computedPrescaler ++;
            }
            /* We set the prescaler with the value calculated through our algo and enable it */
            T0CONbits.PSA = 0;
            T0CONbits.T0PS = computedPrescaler;
        }
    }
    /* We set the initial value in the timer register */
    resetTimer0();
}

void onTimer0Interrupt() {
    /* We reset the interruption and the timer value */
    resetTimer0Interrupt();
    resetTimer0();

    PORTAbits.RA0 = ~LATAbits.LA0;
}

