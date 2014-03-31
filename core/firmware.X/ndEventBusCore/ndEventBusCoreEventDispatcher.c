#include "../ndCore.h"

#include "ndEventBusCoreEventDispatcher.h"
#include "ndEventBusCoreConstants.h"

/**
 * TODO
 */
void dispatchHardwareEventToModule();

/**
 * 
 */
void dispatchHardwareEventToHandler();

/**
 * 
 */
void dispatchSoftwareEventToModule();

/**
 * 
 */
void dispatchSoftwareEventToHandler();

void dispatchEvent(eventCode_t eventCode) {
	/* If it is an empty event, we have nothing to do */
    if(!eventCode.internalStruct.isNotEmpty)
        return;
    /* Otherwise, we must load some register to send the eventcode to the event dispatcher ASM code. */
   PRODH = eventCode.internalStruct.moduleId;
   PRODL = eventCode.internalStruct.eventId;
    /* We call the modules block start address of the type of module we want */
    if(eventCode.internalStruct.type == EVENT_TYPE_HW) {
        dispatchHardwareEventToModule();
    } else {
        dispatchSoftwareEventToModule();
    }
}

void dispatchHardwareEventToModule() {
}

void dispatchHardwareEventToHandler() {
#asm
    MOVF (PRODL), 0, 0
    SUBLW 1
    BNZ $+6 ; We skip the next instruction
    GOTO 55Eh ;functionAddress ; We call the function registered to handle this event
#endasm
}

void dispatchSoftwareEventToModule() {
    /* The first module is the eventbus, so everything is hardcoded and cannot be change */
    /* This code should be similar to the one that are generated when the user had his own modules */
    /* So I wrote it in ASM */
    asm("MOVF PRODH, 0, 0"); //We copy the module id in the working register
    asm("SUBLW 0"); //We susbtract the module id to make an equality test
    asm("BNZ $+6"); //If not equals, we skip to the next module
    asm("GOTO _dispatchSoftwareEventHander"); //Otherwise we goto the handler function.
    //I use the name of the function since I am certain that the first module to be handled by this function is the eventbus. It is hardcoded
}

void dispatchSoftwareEventToHandler() {
    //TODO
}


