#include "ndLedDriverEepromFunctions.h"

#include "../ndInternalMemory/ndInternalMemory.h"
#include "../ndEeprom/ndEeprom.h"

extern ledDriverInternalState_t ledDriverInternalState;

void loadConfigurationFromEeprom() {
   loadDimmingFromEeprom();
   loadBlinkingFromEeprom();
}

void loadDimmingFromEeprom() {
	uint16_t timerBaseValue;
    uint16_t timerPrescaler;
    
	if(openEeprom()) {
		/* We seek to the start and we load the value, one by one */
        seekEeprom(LEDDRIVERN_CONFIGURATION_DIMMING_START_ADDRESS);
        /* Base value and prescaler for the dimming timer */
        readWordInternalMemory(readEeprom, timerBaseValue);
        readWordInternalMemory(readEeprom, timerPrescaler);
        setDimmingTimer(0, timerBaseValue, timerPrescaler);
        
        closeEeprom();
	}
}

void loadBlinkingFromEeprom() {
	uint16_t timerBaseValue;
    uint16_t timerPrescaler;
	
	if(openEeprom()) {
		/* We seek to the start and we load the value, one by one */
        seekEeprom(LEDDRIVERN_CONFIGURATION_BLINKING_START_ADDRESS);
        /* Base value and prescaler for the dimming timer */
        readWordInternalMemory(readEeprom, timerBaseValue);
        readWordInternalMemory(readEeprom, timerPrescaler);
        setDimmingTimer(0, timerBaseValue, timerPrescaler);
        
        closeEeprom();
	}
}

void saveTimerToEeprom(uint8_t startAddress, uint16_t baseValue, uint16_t prescaler) {
	if(openEeprom()) {
		/* We seek to the start and we load the value, one by one */
        seekEeprom(startAddress);
		/*TODO*/
		closeEeprom();
	}
}