/**
 * The event dispatcher is the heart of the eventbus. It calls the right function according 
 * to the eventcode.
 * 
 * Calling a function dynamically is not possible with the instruction set of a pic.
 * So we are using a little trick to make this possible :
 * 
 * The function in C : 
 *  - Test if it is a not empty event, if not return.
 *  - Load the eventcode in PRODH/L
 *  - If it is an hardware event, goto the block managing hardware modules
 *  - If it is an software event, goto the block managing software modules
 * 
 * A block managing some module/events :
 *  - Compare PRODH/L on the id,
 * 	- If there is a match, call the block managing events of this module
 *  - Else, return
 * 
 * So to add a module to the event dispatcher, you must follow this procedure :
 *  - Write the following code in the block managing S/H modules
 * 		if(PRODH == moduleId)
 * 			goto nextEventBlockFlashAddress
 *  - Then write this part of function for each events handled
 * 		if(PRODL == eventId)
 * 			goto functionAddress
 */

#include "ndEventBusCoreTypes.h"

#ifndef NDEVENTBUSCOREEVENTDISPATCHER_H_
#define NDEVENTBUSCOREEVENTDISPATCHER_H_

/**
 * Dispatch the event to registered functions that handle it.
 * /!\ This function is intented to be used only by the eventbus. 
 * Be careful if you use it into your own function, not intented things may append.
 */
void dispatchEvent(eventCode_t eventCode);

/**
 * This function indicate to the eventbus that you will register some function
 * to handle the provided event.
 * /!\ If you are registering two or more times an eventcode is not supported by the event dispatcher
 * but this is not handled for performance reason. 
 * Also no other function using the flash or eeprom memory should be executed during the registration.
 */
void startRegisteringEvent(eventCode_t eventCode);

/**
 * Register the provided function so it can be called when the registering event 
 * is triggered.
 */
void registerFunctionForCurrentEvent(uint24_t functionAddress);

/**
 * This function indicate that you have finished registering your function.
 * /!\ You MUST call this function when you are modifying the event dispatcher.
 */
void stopRegisteringEvent();

/**
 * Commodity function that register one function for the event.
 * Should be used only if the event will be handled by ONE function all the time.
 */
void registerFunctionForEvent(eventCode_t eventCode, uint24_t functionAddress);

/**
 * Remove all the registered functions for the provided event.
 */
void removeRegiteredFunctionsForEvent(eventCode_t eventCode);

#endif