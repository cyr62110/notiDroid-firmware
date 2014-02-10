/* 
 * This library provide an eventbus that can be used to make event-based programming on your PIC.
 * 
 */

#include "ndEventBusCorePredefinedEvents.h"

#ifndef NDEVENTBUSCORE_H
#define	NDEVENTBUSCORE_H

/**
 * Initialize the eventbus before starting using it. It will configure some of
 * its internal variables to make it work.
 */
void initEventBus();

/**
 * Push an event on the eventbus.
 * @param event The event
 */
void triggerEvent(event_t event);

/**
 * 
 * @param out
 */
void nextEvent(event_t* out);

#endif

