#include "ndEventBusCoreEventDispatcher.h"
#include "ndEventBusCoreConstants.h"

#pragma psect text%%u=ndEventBusCoreEventDispatcherPsect
void dispatchEvent(eventCode_t eventCode) {
    if(eventCode.eventStruct.isNotEmpty)
        return;
    if(eventCode.eventStruct.type == EVENT_TYPE_HW) {
        asm("goto 0x700");
    } else {
        asm("goto 0x700");
    }
}
