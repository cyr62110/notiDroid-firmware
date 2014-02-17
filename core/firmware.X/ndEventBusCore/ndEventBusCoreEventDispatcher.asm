#include <xc.inc>

GLOBAL module1_events

PSECT ndEventBusCoreEventDispatcher_HardwareModules, class=CODE, delta=2
; I add here a little sample of the code we need to generate
; TODO : Remove this when the library will be able to generate his own code
MOVF PRODH, W, A ; We copy PRODH in WREG
SUBLW 1 ; We substract to see if the module is the module 1
BZ module1_events
; ...
RETURN

PSECT ndEventBusCoreEventDispatcher_SoftwareModules, class=CODE, delta=2

PSECT ndEventBusCoreEventDispatcher_FirstHardwareModuleEvents, class=CODE, delta=2
; And also a sample for a module events
module1_events:
MOVF PRODL, W, A
SUBLW 1
BNZ $+6 ; We skip the next instruction
GOTO functionAddress ; We call the function registered to handle this event
;...
RETURN
;
module2_events:
;...

PSECT ndEventBusCoreEventDispatcher_FirstSoftwareModuleEvents, class=CODE, delta=2

