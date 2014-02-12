#include "ndFlash.h"
#include "ndFlashTypes.h"

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

void openFlash() {
    currentOperation.isOpened = 1;
    currentOperation.numberOfBytesWritten = 0;
    currentOperation.startAddress = 0;
}

void closeFlash() {
    /* If we have done at least one write, we store the data on the flash */
    if(currentOperation.containsAtLeastOneWrite)
        flushFlash();
    currentOperation.isOpened = 0;
}

void seekFlash(uint24_t flashAddress) {
    if(!currentOperation.isOpened)
        return;
    /* TODO : handle the case when a write operation is already ongoing when
     the dev call this methods*/
    /* We are at the start, we must skip to the block and write FFh to have */

    /* We configure the pointer to be right ant the value in the internal state too */
    TBLPTR = flashAddress;
    currentOperation.startAddress = flashAddress;
}

//TODO
void skipFlash(uint8_t numberOfBytes) {
    if(!currentOperation.isOpened)
        return;
}

void writeFlash(uint8_t data) {
    if(!currentOperation.isOpened)
        return;
    /* We indicate that a write has been made on this batch */
    currentOperation.containsAtLeastOneWrite = 1;
    /* We execute the write and increment the position where we will write */
    INTERNAL_WRITE(data);
    /* If we have written enough data, we finish this batch.
     * Otherwise, we just increment our counter */
    if(currentOperation.numberOfBytesWritten == 31)
        doWrite(0);
    else
        currentOperation.numberOfBytesWritten ++;
}

void eraseFlash(uint24_t flashAddress) {
    if(!currentOperation.isOpened)
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
    if(!currentOperation.isOpened || !currentOperation.containsAtLeastOneWrite)
        return;
    while(currentOperation.numberOfBytesWritten++)
        INTERNAL_WRITE(0xFF);
    doWrite(0);
}

void doWrite(uint8_t erase) {
    /* We configure our register */
    EECON1bits.EEPGD = 1;
    EECON1bits.CFGS = 0;
    EECON1bits.FREE = erase;
    EECON1bits.WREN = 1;

    /* And we follow the procedure to write our data */
    INTCONbits.GIE = 0;
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    INTCONbits.GIE = 1;

    /* And we reinitialise our internal start for more writting */
    currentOperation.numberOfBytesWritten = 0;
    currentOperation.containsAtLeastOneWrite = 0;
}