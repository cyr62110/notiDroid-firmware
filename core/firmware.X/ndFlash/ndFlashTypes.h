#ifndef NDFLASHTYPES_H
#define	NDFLASHTYPES_H

typedef struct _flashOperationInternalState_t {
    unsigned isOpened : 1;
    unsigned containsAtLeastOneWrite : 1;
    unsigned : 1;
    unsigned numberOfBytesWritten : 5;
    uint24_t startAddress;
} flashOperationInternalState_t;

#endif

