; This file is part of the ndLedDriver module
;
; This file defines the organisation of the eeprom used for keeping
; the module configuration over on/off cycle.

#include <xc.inc>

PSECT ndLedDriverEeprom, class=EEDATA, delta=1
ORG 10h ;Start address for the configuration of the ndLedDriver module
DW 64641 ;Base value for the dimming timer
DW 1 ;Prescaler for the dimming timer
DW 5678h ;Base value for the blinking timer
DW 45h ;Prescaler for the blinking timer

