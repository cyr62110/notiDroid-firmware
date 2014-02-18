#include <xc.inc>

GLOBAL module1_events

PSECT ndEventBusCoreEventDispatcher_HardwareModules, reloc=700h, class=CODE, delta=2
; I add here a little sample of the code we need to generate
; TODO : Remove this when the library will be able to generate his own code
MOVF (PRODH), 0, 0 ; We copy PRODH in WREG
SUBLW 1 ; We substract to see if the module is the module 1
BZ module1_events
; ...
RETURN

PSECT ndEventBusCoreEventDispatcher_SoftwareModules, reloc=708h, class=CODE, delta=2

PSECT ndEventBusCoreEventDispatcher_FirstHardwareModuleEvents, reloc=70Ah, class=CODE, delta=2
; And also a sample for a module events
module1_events:
MOVF (PRODL), 0, 0
SUBLW 1
BNZ $+6 ; We skip the next instruction
GOTO 0 ;functionAddress ; We call the function registered to handle this event
;...
RETURN
;
module2_events:
;...

PSECT ndEventBusCoreEventDispatcher_FirstSoftwareModuleEvents, reloc=720h, class=CODE, delta=2

