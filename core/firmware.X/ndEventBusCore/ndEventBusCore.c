#include "ndEventBusCore.h"

eventBus_t eventBus;

void emptyEvent(event_t *out);

void initEventBus() {
    /* We start by clearing the array that will contains our event */

}

void triggerEvent(event_t event) {
    
}

void nextEvent(event_t* out) {
    /* We start by handling special case */
    if(eventBus.currentEvent->type == EVENT_TYPE_SPECIAL) {
        switch(eventBus.currentEvent->eventCode) {
            /* There is no event available on the eventbus */
            case EVENT_SPECIAL_NOEVENT :
                
                return;
        }
    }
}

void emptyEvent(event_t* out) {
    out->eventCode = 0;
    out->payloadSize = EVENT_EMPTY_PAYLOAD;
}
