/**
 * Since the eventbus need to read/write event in the same time and we do not have
 * dynamic memory available on a PIC, we will use a circualar buffer to store all
 * our events.
 *
 * The way this buffer is implemented is explained here : http://en.wikipedia.org/wiki/Circular_buffer#Record_last_operation .
 * In fact, we have 2 pointers :
 * - The start pointer pointing were we must start to read
 * - The end pointer pointing were we must start to write.
 * - A bit indicating the type of the last operation on the buffer : R/W.
 *
 * When the buffer is empty or full : both pointers point to the same address.
 * So we use the bit to know if the buffer is full or empty.
 * If the last operation was a read, the buffer must be empty.
 * If the last operation was a write, the buffer must be full.
 *
 * The way this implentation handle buffer overflow or underflow is TBD.
 */

#include "../ndCore.h"
#include "../ndEventBusCore/ndEventBusCoreTypes.h"

#ifndef NDEVENTBUSCIRCULARBUFFER_H
#define	NDEVENTBUSCIRCULARBUFFER_H

/**
 * Initialize the state of the circular buffer so we can
 * do read/write operation on it.
 */
void initEventBusCircularBuffer();

uint8_t isEventBusCircularBufferEmpty();

/**
 * Write the provided event in the buffer.
 * If the buffer is full, TBD.
 * @param event Event that will be written on the buffer
 */
void putEventInBuffer(event_t* event);

/**
 * Read an event from the buffer and store it in the space provided as
 * argument of this function.
 * If the buffer is empty, TBD.
 * @param outEvent Pointer where the event read from the buffer will be written.
 */
void pullEventFromBuffer(event_t* outEvent);

#endif	/* NDEVENTBUSCIRCULARBUFFER_H */

