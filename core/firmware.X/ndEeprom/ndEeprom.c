#include "ndEeprom.h"

#include "../ndInternalMemory/ndInternalMemory.h"

uint8_t isEepromOpened = 0;

uint8_t openEeprom() {
    if (isEepromOpened || !openInternalMemory())
        return 0;
    isEepromOpened = 1;

    /* We configure the EECON1 register to perform R/W operations on the EEPROM */
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.FREE = 0;
    return -1;
}

void closeEeprom() {
    if(isEepromOpened == 0)
        return;

    closeInternalMemory();
    isEepromOpened = 0;
}

void writeEeprom(uint8_t data) {
    EEDATA = data;
    
    doWriteInternalMemory();
    EEADR ++;
}

uint8_t readEeprom() {
    asm("TBLRD*+");
    return EEDATA;
}

void seekEeprom(uint8_t eepromAddress) {
    EEADR = eepromAddress;
}

void skipEeprom(uint8_t numberOfBytes) {
    EEADR += numberOfBytes;
}