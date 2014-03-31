#include "ndEventBusCircularBuffer.h"
#include "ndEventBusCircularBufferConstants.h"
#include "ndEventBusCircularBufferTypes.h"

#include "../ndEventBusCore/ndEventBusCoreConstants.h"
#include "../ndUtils/ndMemoryUtils.h"

eventBusCircularBuffer_t circularBuffer;

/**
 * Read one byte in the buffer.
 */
uint8_t readOneByte();

/**
 * Write one byte in the buffer.
 */
void writeOneByte(uint8_t byte);

void initEventBusCircularBuffer() {
    /* We initialize our buffer to be empty */
    circularBuffer.start = circularBuffer.buffer;
    circularBuffer.end = circularBuffer.buffer;
    circularBuffer.lastOperation = LAST_OPERATION_TYPE_READ;
}

uint8_t readOneByte() {
    uint8_t byte;
    if(!EVENT_BUS_IS_BUFFER_EMPTY(circularBuffer)) {
         byte = *(circularBuffer.start++);
         EVENT_BUS_HANDLE_POINTER_LOOPS(circularBuffer, start);
         return byte;
    }
    //TODO : else
}

void writeOneByte(uint8_t byte) {
    if(!EVENT_BUS_IS_BUFFER_FULL(circularBuffer)) {
        *(circularBuffer.end++) = byte;
        EVENT_BUS_HANDLE_POINTER_LOOPS(circularBuffer, end);
    }
    //TODO : else
}

uint8_t isEventBusCircularBufferEmpty() {
    return EVENT_BUS_IS_BUFFER_EMPTY(circularBuffer);
}

void putEventInBuffer(event_t* event) {
    /* Bytes in RAM memory have the same order than in the structure
     * So, we start by copying the two bytes thtat represents the eventCode
     */
    writeOneByte(((uint8_t*)event)[0]); /* Identifier of the module + Type of event */
    writeOneByte(((uint8_t*)event)[1]); /* Identifier of the event in the module  */
    /* Then we copy the payload if the event has one */
    if(event->eventCode.internalStruct.payloadSize > EVENT_EMPTY_PAYLOAD) {
        uint8_t payloadSize = 1 << (event->eventCode.internalStruct.payloadSize - 1);
        uint8_t* payload = event->payload;
        while(payloadSize-- > 0)
            writeOneByte(*(payload++));
    }
    
}

void pullEventFromBuffer(event_t* outEvent) {
    /* Bytes in RAM memory have the same order than in the structure
     * So, we start by copying the two bytes thtat represents the eventCode
     */
    ((uint8_t*)outEvent)[0] = readOneByte();
    ((uint8_t*)outEvent)[1] = readOneByte();
    /* Then we copy the payload if the event has one */
    if(outEvent->eventCode.internalStruct.payloadSize > EVENT_EMPTY_PAYLOAD) {
        uint8_t payloadSize = 1 << (outEvent->eventCode.internalStruct.payloadSize - 1);
        uint8_t* payload = outEvent->payload;
        while(payloadSize-- > 0)
            *(payload++) = readOneByte();
    }
}