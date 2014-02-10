#include "ndCore.h"
#include "ndETimer1/ndETimer1.h"

void interrupt isr() {
    if(timer1Interrupt()) {
        onTimer1Interrupt();
    }
    
}

void test(void* addr) {
    TRISB = 0;
    PORTB = 1;
}

int main(int argc, char** argv) {

    TRISA = 0;
    PORTAbits.RA0 = 0;

    /* We configure the interruption */
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;

    test((void*)main); /* This is the trick behind all the eventbus architecture */

    timer1Config_t config;
    setUpTimer1(config);
    setTimer1(1000, 3);
    startTimer1();

    while(1);
}

