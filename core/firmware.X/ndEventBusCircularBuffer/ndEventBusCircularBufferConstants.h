#include "../ndEventBusCore/ndEventBusCoreTypes.h"

#ifndef NDEVENTBUSCIRCULARBUFFERCONSTANTS_H
#define	NDEVENTBUSCIRCULARBUFFERCONSTANTS_H

/**
 * Maximum number of event that can be written on the buffer
 * without read operation.
 */
#define EVENT_BUS_BUFFER_SIZE_IN_NUMBER_OF_EVENTS 4
#define EVENT_BUS_BUFFER_SIZE EVENT_BUS_BUFFER_SIZE_IN_NUMBER_OF_EVENTS * sizeof(event_t)

#define LAST_OPERATION_TYPE_WRITE 1
#define LAST_OPERATION_TYPE_READ 0

/**
 * Some macro that will be usefull for manipulating the buffer
 */

/**
 * Is the buffer empty
 */
#define EVENT_BUS_IS_BUFFER_EMPTY(buffer) (buffer.lastOperation == LAST_OPERATION_TYPE_READ && buffer.start == buffer.end)

/**
 * Is the buffer full
 */
#define EVENT_BUS_IS_BUFFER_FULL(buffer) (buffer.lastOperation == LAST_OPERATION_TYPE_WRITE && buffer.start == buffer.end)

/**
 * Return true if the provided pointer is at the end of internal buffer and should go back to the start.
 */
#define EVENT_BUS_SHOULD_POINTER_LOOP(circularBuffer, pointer) (circularBuffer.pointer == (circularBuffer.buffer + EVENT_BUS_BUFFER_SIZE + 1))

/**
 * This function make the pointer go back to the start of the internal buffer if it at reached the end. Otherwise, it does nothing.
 */
#define EVENT_BUS_HANDLE_POINTER_LOOPS(circularBuffer, pointer) { if(EVENT_BUS_SHOULD_POINTER_LOOP(circularBuffer, pointer)) { circularBuffer.pointer = circularBuffer.buffer; } }

#endif	/* NDEVENTBUSCIRCULARBUFFERCONSTANTS_H */

