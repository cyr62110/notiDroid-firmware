#include "ndCore.h"
#include "ndETimer1/ndETimer1.h"
#include "ndFlash/ndFlash.h"

void interrupt isr() {
    if(timer1Interrupt()) {
        onTimer1Interrupt();
    }
    
}

void test(void* addr) {
    TRISB = 0;
    PORTB = 1;
}

void on() {
    PORTAbits.RA0 = 1;
}

int main(int argc, char** argv) {

    TRISA = 0;
    PORTAbits.RA0 = 0;

    /* We configure the interruption */
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;

    /* We will make some magic */
    eraseFlash((uint24_t)0x5FE);

    openFlash();
    seekFlash((uint24_t)0x5FE);
    writeFlash(0x80);
    writeFlash(0x80);
    flushFlash();

    asm("goto 5FEh");
    on();
    test((void*)on); /* This is the trick behind all the eventbus architecture */

    while(1);
}

