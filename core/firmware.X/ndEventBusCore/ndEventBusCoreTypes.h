#include <stdint.h>

#ifndef NDEVENTBUSCORETYPES_H_
#define NDEVENTBUSCORETYPES_H_

/**
 * Structure defining what is an eventCode.
 * Each type of event that will be send on the event has its own uniq code.
 * The code is used to know which function will be called by the event dispatcher.
 * 
 * It exists two kind of event :
 * - Hardware are events related to module that use hardware capability like time, UART or ADC.
 * - Software are events related to module that do not use hardware component like the eventbus.
 *
 * An event is bind to a module and has an id specific to this module. Event with same id but not
 * with same module are not equals.
 *
 * A given event has always the same payload. So the payload size is
 * part of the identificator of the event.
 */
typedef union _eventCode_t {
    struct {
        unsigned moduleId : 6; /* Identificator of the module that have sent this event */
        unsigned isNotEmpty : 1; /* Is 0 if the eventcode represent an empty event */
        unsigned type : 1; /* Type of this event, SOFTWARE or HARDWARE */
        union {
            /* Struct are defined LSB first when working with unsigned. So the payloadSize are the two LSB or the eventId */
            struct {
                unsigned payloadSize : 2; /* Number of bytes used to store data about this event. */
                unsigned : 6; /* Those bits are part of the eventId but should not be accessed from the struct */
            };
            uint8_t eventId; /* Identificator of the event in the mode */
        };
    } internalStruct;
    uint16_t internalCode; /* Code of the event. Event with the same code are similar. */
} eventCode_t;

/**
 * Structure defining an event during the runtime.
 * An event has is code to determine its kind but also a payload that
 * contains some data related to this particular occurence of the event.
 */
typedef struct _event_t {
    eventCode_t eventCode; /* Identificator of the current event type */
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