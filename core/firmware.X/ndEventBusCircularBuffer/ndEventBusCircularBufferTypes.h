#include "ndEventBusCircularBufferConstants.h"

#include "../ndEventBusCore/ndEventBusCoreTypes.h"

#ifndef NDEVENTBUSCIRCULARBUFFERTYPES_H
#define	NDEVENTBUSCIRCULARBUFFERTYPES_H

typedef struct _eventBusCircularBuffer_t {
    uint8_t buffer[EVENT_BUS_BUFFER_SIZE * sizeof(event_t)];
    uint8_t* start;
    uint8_t* end;
    unsigned lastOperation : 1; /* 1 : Read, 0 : Write */
} eventBusCircularBuffer_t;

#endif	/* NDEVENTBUSCIRCULARBUFFERTYPES_H */

