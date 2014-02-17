#include "ndEventBusCoreEventDispatcher.h"
#include "ndEventBusCoreConstants.h"

#pragma psect text%%u=ndEventBusCoreEventDispatcherPsect
void dispatchEvent(eventCode_t eventCode) {
	/* If it is an empty event, we have nothing to do */
    if(eventCode.eventStruct.isNotEmpty)
        return;
    /* Otherwise, we must load some register to send the eventcode to the event dispatcher ASM code. */
   PRODH = eventCode.eventStruct.moduleId;
   PRODL = eventCode.eventStruct.eventId;
    /* We call the modules block start address of the type of module we want */
    if(eventCode.eventStruct.type == EVENT_TYPE_HW) {
        asm("goto 0x700");
    } else {
        asm("goto 0x700");
    }
}
