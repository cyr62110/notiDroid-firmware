#include "ndCore.h"
#include "ndETimer1/ndETimer1.h"
#include "ndFlash/ndFlash.h"
#include "ndEventBusCore/ndEventBusCoreEventDispatcher.h"
#include "ndEventBusCore/ndEventBusCoreConstants.h"

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
    //eraseFlash((uint24_t)0x5FE);

    //openFlash();
    //seekFlash((uint24_t)0x5FE);
    //writeFlash(0x80);
    //writeFlash(0x80);
    //seekFlash((uint24_t)0x602);
    //flushFlash();

    eventCode_t eventCode;
    eventCode.eventStruct.isNotEmpty = 1;
    eventCode.eventStruct.type = EVENT_TYPE_SW;
    eventCode.eventStruct.moduleId = 2;
    eventCode.eventStruct.eventId = 0x34;
    dispatchEvent(eventCode);

    //asm("goto 5FEh");
    //on();
    //test((void*)on); /* This is the trick behind all the eventbus architecture */

    while(1);
}

