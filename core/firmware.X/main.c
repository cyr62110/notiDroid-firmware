#include "ndCore.h"
#include "ndLedDriver/ndLedDriver.h"
#include "ndEventBusCore/ndEventBusCoreEventDispatcher.h"
#include "ndEventBusCore/ndEventBusCoreConstants.h"
#include "ndEventBusCore/ndEventBusCoreEvents.h"

#include "ndTimer0/ndTimer0.h"
#include "ndETimer1/ndTimer1.h"
#include "ndTimer2/ndTimer2.h"
#include "ndTimer3/ndTimer3.h"
#include "ndEventBusCore/ndEventBusCore.h"

void configureInterrupt();

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

int main(int argc, char** argv) {

    TRISA = 0;
    PORTAbits.RA0 = 0;

    /* We configure interruption that are required to make the firmware works */
    configureInterrupt();

    /* Then we initialize all module of the firmware */
    initEventBus();

    /* Everything is now configured. We start handling events with the eventbus. */
    eventLoop();
}

void configureInterrupt() {
    /* We configure the interruption */
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;

    /* We will use high priority interrupt only for the dimming since it is the only real time operation  */
    /* All other interrupt will be low priority */
    RCONbits.IPEN = 1;
    IPR2bits.TMR3IP = 1; //Dimming is high priority
    IPR1bits.TMR1IP = 0;
}

void event_eventBus_registerHandlers() {
    PORTAbits.RA0 = 1;
}