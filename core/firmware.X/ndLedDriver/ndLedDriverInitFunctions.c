#include "ndLedDriver.h"
#include "ndLedDriverInternalFunctions.h"
#include "ndLedDriverConstants.h"
#include "ndLedDriverTypes.h"
#include "ndLedDriverEepromFunctions.h"

extern ledDriverInternalState_t ledDriverInternalState;
extern uint8_t i;

void initLedDriver() {
    /* We start by initializing the internal state */
    initInternalState();
    /* We initialize both timers */
    initDimmingTimer();
    initBlinkingTimer();
    /* We load some configuration from the eeprom since those are not hardcoded. ex. Timer related values */
    loadConfigurationFromEeprom();
}

void initInternalState() {
    /* We clear led structures */
    for (i = 0; i < LEDDRIVER_NUMBER_OF_REGISTERS; i++) {
        ledsInternalState_t *leds = ledDriverInternalState.leds + i;
        leds->portRegister = (register_t*)0;
        leds->latchRegister = (register_t*)0;
        leds->computedNextLedStates = 0;
        leds->mask = 0;
    }

    /* Then we configure dimming and blinking internal states */
    initDimmingInternalState();
    initBlinkingInternalState();
}

void initDimmingInternalState() {
    ledDriverInternalState.dimming.currentDimmingCycle = LEDDRIVER_COMPUTE_CYCLE;
    ledDriverInternalState.dimming.counter = 0;
    ledDriverInternalState.dimming.counterResetMask = LEDDRIVER_COUNTER_RESET_MASK; /* TODO Read it for eeprom ? ? ? */
    for(i = 0; i < LEDDRIVER_NUMBER_OF_LEDS; i++)
        ledDriverInternalState.dimming.ledShutOffValue[i] = 0;
    for(i = 0; i < LEDDRIVER_NUMBER_OF_REGISTERS; i++)
        ledDriverInternalState.dimming.nextLedStates[i] = 0;
}

void initBlinkingInternalState() {
}

void initDimmingTimer() {
    timer3Config_t dimmingTimerConfig;
    dimmingTimerConfig.shouldLoop = 1;
    dimmingTimerConfig.triggerEvent = 0;
    dimmingTimerConfig.useInterrupt = 1;
    setUpTimer3(dimmingTimerConfig);
}

void initBlinkingTimer() {
    timer1Config_t blinkingTimerConfig;
    blinkingTimerConfig.shouldLoop = 1;
    blinkingTimerConfig.triggerEvent = 0;
    blinkingTimerConfig.useInterrupt = 1;
    setUpTimer1(dimmingTimerConfig);
}
