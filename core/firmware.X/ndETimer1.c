#include "ndETimer1/ndTimer1.h"

extern timer1Config_t timer1Config;
extern uint16_t timer1InitialValue;

void onTimer1Interrupt() {
     /* We reset the interruption and the timer value if required */
    resetTimer1Interrupt();
    if(timer1Config.shouldLoop == 1)
        resetTimer1();
    else
        stopTimer1();
}