 #include "ndEeprom.h"
 
 uint8_t isEepromOpened = 0;
 
 uint8_t openEeprom() {
 	if(isEepromOpened || !openInternalMemory())
 		return 0;
 	isEepromOpened = 1;
 }