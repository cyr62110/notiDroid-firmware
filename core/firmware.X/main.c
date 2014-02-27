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

void interrupt low_priority lowPriorityIsr() {
    if(blinkingTimerInterrupt()) {
        onBlinkingTimerInterrupt();
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

    /* We will use high priority interrupt only for the dimming since it is the only real time operation  */
    /* All other interrupt will be low priority */
    RCONbits.IPEN = 1;
    IPR2bits.TMR3IP = 1; //Dimming is high priority
    IPR1bits.TMR1IP = 0;
    

    /* We configure the led driver */
    initLedDriver();

    /* We configure the PORTA to be handled by the module */
    configureRegisterLedDriver(&PORTA, &TRISA, 0x01);

    setDimmingHighLevelLenght(0, 16);
    setBlinkingPeriod(0, 100);
    setBlinkingHighLevelDuration(0, 50);

    startTimer3();
    startTimer1();

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

