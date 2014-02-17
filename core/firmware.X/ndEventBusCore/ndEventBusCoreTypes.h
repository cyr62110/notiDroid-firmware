#include <stdint.h>

#ifndef NDEVENTBUSCORETYPES_H_
#define NDEVENTBUSCORETYPES_H_

/**
 * Structure defining what is an eventCode.
 * Each type of event that will be send on the event has its own uniq code.
 * The code is used to know which function will be called by the event dispatcher.
 */
typedef union _eventCode_t {
    struct {
        unsigned isNotEmpty : 1; /* Is 0 if the eventcode represent an empty event */
        unsigned type : 1; /* Type of this event, one of EVENT_TYPE_* constant */
        unsigned moduleId : 6; /* Id of the module that have sent this event */
        unsigned eventId : 8; /**/
    } eventStruct;
    uint16_t eventCode;
} eventCode_t;

/**
 * Structure defining an event during the runtime.
 * An event has is code to determine its kind but also a payload that
 * contains some data related to this particular occurence of the event.
 */
typedef struct _event_t {
    eventCode_t eventCode; /* Identificator of the current event type */
    uint8_t payloadSize; /* Number of bytes that are data enclosed in this event */
    uint8_t payload[4]; /* Data */
} event_t;

/**
 * Structure that describe the eventbus
 */
typedef struct _eventBus_t {
    event_t *currentEvent;
    event_t events[1];
} eventBus_t;

#endif