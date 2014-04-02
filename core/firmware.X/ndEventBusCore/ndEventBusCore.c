#include "ndEventBusCore.h"

#include "../ndEventBusCircularBuffer/ndEventBusCircularBuffer.h"
#include "ndEventBusCoreEventDispatcher.h"

eventBus_t eventBus;

event_t currentEvent;

void emptyEvent(event_t *out);

void triggerRegisterHandlersEvent();

/**
 * Read the next event in the buffer and write it at the provided address.
 * Or write an empty event
 * @return
 */
void nextEvent(event_t* out);

void initEventBus() {
    /* We start by initializing the buffer that will contains events */
    initEventBusCircularBuffer();

    /* We initialize the dispatcher too */

    //TODO
    /* Then we reload the state of the previous execution from the EEPROM */
    /* If the dispatcher has never been configured, we ask the program to configure it. */
    triggerRegisterHandlersEvent();

}

void triggerEvent(event_t* event) {
    /* We just need to send the event to the circular buffer */
    putEventInBuffer(event);
}

void nextEvent(event_t* out) {
    /* If the buffer is empty, we send an empty event */
    if(isEventBusCircularBufferEmpty()) {
        emptyEvent(out);
    } else {
        /* Otherwise, we pull the event from the circular buffer */
        pullEventFromBuffer(out);
    }
}

void emptyEvent(event_t* out) {
    /* To make an event empty, we just need to set the isNotEmpty bit to 0 */
    out->eventCode.internalStruct.isNotEmpty = 0;
}

void eventLoop() {
    while(1) {
        /* We read the next event from the buffer */
        nextEvent(&currentEvent);
        /* And we dispatch it to the right function */
        dispatchEvent(currentEvent.eventCode);
    }
}

void triggerRegisterHandlersEvent() {
    event_t registerHandlersEvent;
    registerHandlersEvent.eventCode.internalStruct.isNotEmpty = 1;
    registerHandlersEvent.eventCode.internalStruct.type = EVENT_TYPE_SW;
    registerHandlersEvent.eventCode.internalStruct.moduleId = EVENT_MODULE_EVENTBUS;
    registerHandlersEvent.eventCode.internalStruct.eventId = EVENT_EVENTBUS_REGISTER_HANDLERS;
    triggerEvent(&registerHandlersEvent);
}