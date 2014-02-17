#include "ndInternalMemory.h"

uint8_t isInternalMemoryOpened = 0;

uint8_t openInternalMemory() {
    if (isInternalMemoryOpened)
        return 0;
    isInternalMemoryOpened = 1;
    return -1;
}

void doWriteInternalMemory() {
    /* We enable the writting on one of the internal memory */
    EECON1bits.WREN = 1;

    /* We follow the procedure describe in pic18 datasheets */
    INTCONbits.GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    INTCONbits.GIE = 1;

    /* We disable the writting to avoid mistake */
    EECON1bits.WREN = 0;
}

void closeInternalMemory() {
    isInternalMemoryOpened = 0;
}