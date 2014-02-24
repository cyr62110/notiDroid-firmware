#include "ndCore.h"
#include "ndLedDriver/ndLedDriver.h"
#include "ndEventBusCore/ndEventBusCoreEventDispatcher.h"
#include "ndEventBusCore/ndEventBusCoreConstants.h"

#include "ndTimer0/ndTimer0.h"
#include "ndETimer1/ndTimer1.h"
#include "ndTimer2/ndTimer2.h"
#include "ndTimer3/ndTimer3.h"

void interrupt isr() {
    if(dimmingTimerInterrupt()) {
        onDimmingTimerInterrupt();
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

    /* We configure the led driver */
    initLedDriver();

    /* We configure the PORTA to be handled by the module */
    configureRegister(&PORTA, &TRISA, 0x01);

    setDimmingHighLevelLenght(0, 1);

    startTimer3();

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

    

    while(1);
}

