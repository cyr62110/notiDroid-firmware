#ifndef NDEVENTBUSCORETYPES_H_
#define NDEVENTBUSCORETYPES_H_

/**
 * Structure of an event
 */
typedef struct _event_t {
	unsigned type : 2; /* Type of this event, one of EVENT_TYPE_* constant */
	unsigned module : 6; /* Id of the module that have sent this event */
	unsigned eventCode : 6; /* Code of the event */
	unsigned payloadSize : 2; /* Number of bytes that are data enclosed in this event */
	uint8_t payload[4]; /* Data */
} event_t;

/**
 * Structure that describe the eventbus
 */
typedef struct _eventBus_t {
	
} eventBus_t;

#endif