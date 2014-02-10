#include <stdint.h>

#ifndef NDEVENTBUSCORETYPES_H_
#define NDEVENTBUSCORETYPES_H_

/**
 * Structure of an event
 */
typedef struct _event_t {
    union {
        struct {
            unsigned type : 2; /* Type of this event, one of EVENT_TYPE_* constant */
            unsigned moduleId : 4; /* Id of the module that have sent this event */
            unsigned eventId : 2; /* Id of the event in the module */
        };
        uint8_t eventCode;
    };
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