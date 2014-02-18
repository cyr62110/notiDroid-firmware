#include "ndCore.h"
#include "ndETimer1/ndTimer1.h"
#include "ndTimer0/ndTimer0.h"
#include "ndTimer2/ndTimer2.h"
#include "ndTimer3/ndTimer3.h"
#include "ndFlash/ndFlash.h"
#include "ndEventBusCore/ndEventBusCoreEventDispatcher.h"
#include "ndEventBusCore/ndEventBusCoreConstants.h"

void interrupt isr() {
    if(timer0Interrupt()) {
        onTimer0Interrupt();
    }
    if(timer1Interrupt()) {
        onTimer1Interrupt();
    }
    if(timer2Interrupt()) {
        onTimer2Interrupt();
    }
    if(timer3Interrupt()) {
        onTimer3Interrupt();
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

    /* eventCode_t eventCode;
    eventCode.eventStruct.isNotEmpty = 1;
    eventCode.eventStruct.type = EVENT_TYPE_SW;
    eventCode.eventStruct.moduleId = 2;
    eventCode.eventStruct.eventId = 0x34;
    dispatchEvent(eventCode); */

    //asm("goto 5FEh");
    //on();
    //test((void*)on); /* This is the trick behind all the eventbus architecture */

    timer2Config_t timerConfig;
    timerConfig.useInterrupt = 1;
    timerConfig.shouldLoop = 1;
    timerConfig.triggerEvent = 0;

    setUpTimer2(timerConfig);
    setTimer2(123, 128);
    startTimer2();

    while(1);
}

