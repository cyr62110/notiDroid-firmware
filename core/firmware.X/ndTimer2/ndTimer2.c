#include "ndTimer2.h"

/* Global variable that contains the configuration that have been set up
 * for the timer */
timer2Config_t timer2Config;

/* Value that should be loaded in the timer when it reset */
uint8_t timer2InitialValue;


void setUpTimer2(timer2Config_t config) {
    /* We copy the configuration */
    timer2Config = config;

    /* Then we configure timer registers */
    T2CON = 0;

    /* Finally we configure the interruption */
    PIE1bits.TMR2IE = config.useInterrupt;
}

void setTimer2(uint16_t uInitialValue, uint16_t prescaler) {
    /* We keep the initial value if we need to loop */
    timer2InitialValue = uInitialValue;
    if(prescaler > 0) {
        /* We start by managing the prescaler which can be 1, 4 or 16 */
        /* We check if the prescaler is a multiple of 16, if yes we set the prescaler to 16 */
        if((prescaler & 0xFFE0) && !(prescaler & 0x001F) ) {
            prescaler >>= 4;
            T2CONbits.T2CKPS = 2;
        }
        /* Otherwise, we test if the prescaler is a multiple of 4, same deal */
        else if((prescaler & 0xFFF8) && !(prescaler & 0x0007)) {
            prescaler >>= 2;
            T2CONbits.T2CKPS = 1;
        }
        else
            T2CONbits.T2CKPS = 0;

        /* The rest goes in the postscaler which has the same goal for the timer */
        T2CONbits.T2OUTPS = prescaler - 1; /* A postscaler of 1 is 0, so we need to remove 1 */
    }
    /* We set the initial value in the timer register */
    resetTimer2();
}

void onTimer2Interrupt() {
    /* We reset the interruption and the timer value */
    resetTimer2Interrupt();
    resetTimer2();

    PORTAbits.RA0 = ~LATAbits.LA0;
}


