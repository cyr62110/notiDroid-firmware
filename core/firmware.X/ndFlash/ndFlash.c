#include "ndFlash.h"
#include "ndFlashTypes.h"

#include "../ndInternalMemory/ndInternalMemory.h"

/**
 * Internal function that handle all the procedure to really write all the bytes
 * to the flash memory after all 16 words have been loaded.
 * 
 */
void doWrite(uint8_t erase);

/**
 * Internal macro that store a byte
 */
#define INTERNAL_WRITE(data) TABLAT = data; asm("TBLWT*+");

/**
 * Internal macro that give the address of the beginning of the block
 * containing the provided address.
 */
#define BLOCK_ALIGNED_ADDRESS(address) (address & ~0x00001F)

flashOperationInternalState_t currentOperation;

uint8_t openFlash() {
    if (currentOperation.isOpened == 1 || !openInternalMemory())
        return 0;

    /* We intialize part of the EECON1 register */
    EECON1bits.EEPGD = 1;
    EECON1bits.CFGS = 0;

    /* We initialize the internal state to support next operartion on flash */
    currentOperation.isOpened = 1;
    currentOperation.numberOfBytesWritten = 0;
    currentOperation.startAddress = 0;

    return -1;
}

void closeFlash() {
    if (currentOperation.isOpened == 0)
        return;

    /* If we have done at least one write, we store the data on the flash */
    if (currentOperation.containsAtLeastOneWrite)
        flushFlash();
    currentOperation.isOpened = 0;

    /* We ends by releasing the lock on the registers */
    closeInternalMemory();
}

void seekFlash(uint24_t flashAddress) {
    if (!currentOperation.isOpened)
        return;
    if (currentOperation.containsAtLeastOneWrite) {
        /* If we are skipping more than 32 - numberOfBytesWritten, we call the skip function.
           Otherwise, we flush the modification and do a simple jump */
        int24_t numberOfSkippedBytes = flashAddress - currentOperation.startAddress
                - currentOperation.numberOfBytesWritten;
        if (numberOfSkippedBytes > 0 && numberOfSkippedBytes) {
            skipFlash(numberOfSkippedBytes);
            return;
        } else
            flushFlash();
    }
    /* We configure the pointer to be right ant the value in the internal state too */
    TBLPTR = flashAddress;
    currentOperation.startAddress = flashAddress;
    currentOperation.numberOfBytesWritten = 0;
}

/* TODO */
void skipFlash(uint8_t numberOfBytes) {
    if (!currentOperation.isOpened)
        return;

    if (currentOperation.containsAtLeastOneWrite && numberOfBytes > 32 - currentOperation.numberOfBytesWritten) {
        /* TODO */
    } else {
        /* TODO */
    }
}

void writeFlash(uint8_t data) {
    if (!currentOperation.isOpened)
        return;
    /* We indicate that a write has been made on this batch */
    currentOperation.containsAtLeastOneWrite = 1;
    /* We execute the write and increment the position where we will write */
    INTERNAL_WRITE(data);
    /* If we have written enough data, we finish this batch.
     * Otherwise, we just increment our counter */
    if (currentOperation.numberOfBytesWritten == 31)
        doWrite(0);
    else
        currentOperation.numberOfBytesWritten++;
}

void eraseFlash(uint24_t flashAddress) {
    if (!currentOperation.isOpened)
        return;

    TBLPTR = BLOCK_ALIGNED_ADDRESS(flashAddress);
    doWrite(1);
}

//TODO

uint8_t readFlash() {
    return 0;
}

void flushFlash() {
    /* If the operation is not open or we have done no write on this batch, we do nothing so everything cool */
    if (!currentOperation.isOpened || !currentOperation.containsAtLeastOneWrite)
        return;
    while (currentOperation.numberOfBytesWritten++)
        INTERNAL_WRITE(0xFF);
    doWrite(0);
}

void doWrite(uint8_t erase) {
    /* We enable the writting */
    EECON1bits.FREE = erase;

    /* And we follow the procedure to write our data */
    doWriteInternalMemory();

    /* And we reinitialise our internal start for more writting */
    currentOperation.numberOfBytesWritten = 0;
    currentOperation.containsAtLeastOneWrite = 0;
    currentOperation.startAddress += 32;
}