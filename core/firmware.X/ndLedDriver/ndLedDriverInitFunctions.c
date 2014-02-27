#include "ndLedDriver.h"
#include "ndLedDriverInternalFunctions.h"
#include "ndLedDriverConstants.h"
#include "ndLedDriverTypes.h"
#include "ndLedDriverEepromFunctions.h"

#include "../ndETimer1/ndTimer1.h"

extern ledDriverInternalState_t ledDriverInternalState;
extern uint8_t dimmingIterator;

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
    for (dimmingIterator = 0; dimmingIterator < LEDDRIVER_NUMBER_OF_REGISTERS; dimmingIterator++) {
        ledsInternalState_t *leds = ledDriverInternalState.leds + dimmingIterator;
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
    for(dimmingIterator = 0; dimmingIterator < LEDDRIVER_NUMBER_OF_LEDS; dimmingIterator++)
        ledDriverInternalState.dimming.ledShutOffValue[dimmingIterator] = 0;
    for(dimmingIterator = 0; dimmingIterator < LEDDRIVER_NUMBER_OF_REGISTERS; dimmingIterator++)
        ledDriverInternalState.dimming.nextLedStates[dimmingIterator] = 0xFF;
}

void initBlinkingInternalState() {
    for(dimmingIterator = 0; dimmingIterator < LEDDRIVER_NUMBER_OF_LEDS; dimmingIterator++) {
        ledDriverInternalState.blinking.leds[dimmingIterator].counter = 0;
        ledDriverInternalState.blinking.leds[dimmingIterator].blinkingPeriod = 0xFFFF;
        ledDriverInternalState.blinking.leds[dimmingIterator].blinkingHightLevelDuration = 0;
    }
    for(dimmingIterator = 0; dimmingIterator < LEDDRIVER_NUMBER_OF_REGISTERS; dimmingIterator++)
        ledDriverInternalState.blinking.nextLedStates[dimmingIterator] = 0xFF;
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
    setUpTimer1(blinkingTimerConfig);
}
