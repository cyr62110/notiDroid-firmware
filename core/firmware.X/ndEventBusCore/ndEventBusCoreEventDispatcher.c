#include "../ndCore.h"

#include "ndEventBusCoreEventDispatcher.h"
#include "ndEventBusCoreConstants.h"

/**
 * TODO
 */
void handleHardwareModuleEvent();

/**
 * 
 */
void onFirstHardwareModuleEvent();

/**
 * 
 */
void handleSoftwareModuleEvent();

/**
 * 
 */
void onFirstSoftwareModuleEvent();

void dispatchEvent(eventCode_t eventCode) {
	/* If it is an empty event, we have nothing to do */
    if(!eventCode.eventStruct.isNotEmpty)
        return;
    /* Otherwise, we must load some register to send the eventcode to the event dispatcher ASM code. */
   PRODH = eventCode.eventStruct.moduleId;
   PRODL = eventCode.eventStruct.eventId;
    /* We call the modules block start address of the type of module we want */
    if(eventCode.eventStruct.type == EVENT_TYPE_HW) {
        handleHardwareModuleEvent();
    } else {
        handleSoftwareModuleEvent();
    }
}

void handleHardwareModuleEvent() {
#asm
    MOVF (PRODH), 0, 0 ; We copy PRODH in WREG
    SUBLW 1 ; We substract to see if the module is the module 1
    BNZ $+6
    GOTO _onFirstHardwareModuleEvent
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
    NOP
#endasm
}

void onFirstHardwareModuleEvent() {
#asm
    MOVF (PRODL), 0, 0
    SUBLW 1
    BNZ $+6 ; We skip the next instruction
    GOTO 55Eh ;functionAddress ; We call the function registered to handle this event
#endasm
}

void handleSoftwareModuleEvent() {
    
}

void onFirstSoftwareModuleEvent() {
    
}


