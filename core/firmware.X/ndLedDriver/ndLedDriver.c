#include "ndLedDriver.h"
#include "ndLedDriverInternalFunctions.h"
#include "ndLedDriverConstants.h"
#include "ndLedDriverTypes.h"
#include "ndLedDriverEepromFunctions.h"

#include "../ndETimer1/ndTimer1.h"

ledDriverInternalState_t ledDriverInternalState;

uint8_t dimmingIterator;
register_t dimmingUnsetShift;

uint8_t blinkingIterator;
register_t blinkingSetShift, blinkingUnsetShift;
ledBlinkingInternalState_t* led;

void configureRegisterLedDriver(register_t *portRegister, register_t *latchRegister, register_t mask) {
    for (dimmingIterator = 0; dimmingIterator < LEDDRIVER_NUMBER_OF_REGISTERS; dimmingIterator++) {
        ledsInternalState_t *leds = ledDriverInternalState.leds + dimmingIterator;
        if (leds->portRegister == (register_t*) 0) {
            leds->portRegister = portRegister;
            leds->latchRegister = latchRegister;
            leds->mask = mask;
            leds->computedNextLedStates = 0;
        }
    }
}

void setDimmingHighLevelLenght(uint8_t led, uint8_t highLevelLength) {
    if (led >= LEDDRIVER_NUMBER_OF_LEDS)
        return;
    ledDriverInternalState.dimming.ledShutOffValue[led] = highLevelLength;
}

void setDimmingTimer(uint8_t writeInConfig, uint16_t baseValue, uint16_t prescaler) {
    /* If writeInConfig, we keep the configuration in eeprom */
    if (writeInConfig)
        saveDimmingTimerToEeprom(baseValue, prescaler);
    /* We reconfigure our dimming timer wich is Timer3 */
    setTimer3(baseValue, prescaler);
}

void onDimmingTimerInterrupt() {
    onTimer3Interrupt();
    if (ledDriverInternalState.dimming.currentDimmingCycle == LEDDRIVER_COMPUTE_CYCLE) {
        /* We increment the counter */
        ledDriverInternalState.dimming.counter++;
        if ((ledDriverInternalState.dimming.counter & ledDriverInternalState.dimming.counterResetMask) == 0) {
            for (dimmingIterator = 0; dimmingIterator < LEDDRIVER_NUMBER_OF_REGISTERS; dimmingIterator++)
                ledDriverInternalState.dimming.nextLedStates[dimmingIterator] = 0xFF;
            ledDriverInternalState.dimming.counter = 0;
        }

        /* TODO : Add some comment here */
        for (dimmingIterator = 0; dimmingIterator < LEDDRIVER_NUMBER_OF_LEDS; dimmingIterator++) {
            /* */
            if ((dimmingIterator & 0x0F) == 0) dimmingUnsetShift = 0xFE;

            /* */
            if (ledDriverInternalState.dimming.counter == ledDriverInternalState.dimming.ledShutOffValue[dimmingIterator])
                ledDriverInternalState.dimming.nextLedStates[dimmingIterator >> 8] &= dimmingUnsetShift;

            /* */
            dimmingUnsetShift = dimmingUnsetShift << 1 | 1;
        }

        /* We compute the led states that will be applied to the register*/
        /* TODO : add blinking */
        for (dimmingIterator = 0; dimmingIterator < LEDDRIVER_NUMBER_OF_REGISTERS; dimmingIterator++)
            ledDriverInternalState.leds[dimmingIterator].computedNextLedStates = ledDriverInternalState.dimming.nextLedStates[dimmingIterator]
                    & ledDriverInternalState.blinking.nextLedStates[dimmingIterator];
    } else {
        /* TODO : Add a comment here */
        for (dimmingIterator = 0; dimmingIterator < LEDDRIVER_NUMBER_OF_REGISTERS; dimmingIterator++) {
            ledsInternalState_t *currentLeds = ledDriverInternalState.leds + dimmingIterator;
            *currentLeds->portRegister = currentLeds->computedNextLedStates
                    | (*currentLeds->latchRegister
                    & currentLeds->mask);
        }
    }
    /* We change the type of the next cycle : COMPUTE -> ACT -> COMPUTE -> ... */
    ledDriverInternalState.dimming.currentDimmingCycle = ~ledDriverInternalState.dimming.currentDimmingCycle;
}

void setBlinkingTimer(uint8_t writeInConfig, uint16_t baseValue, uint16_t prescaler) {
    /* If writeInConfig, we keep the configuration in eeprom */
    if (writeInConfig)
        saveDimmingTimerToEeprom(baseValue, prescaler);
    /* We reconfigure our blinking timer wich is Timer1 */
    setTimer1(baseValue, prescaler);
}

void setBlinkingHighLevelDuration(uint8_t led, uint8_t duration) {
    if (led >= LEDDRIVER_NUMBER_OF_LEDS)
        return;
    ledDriverInternalState.blinking.leds[led].blinkingHightLevelDuration = duration;
}

void setBlinkingPeriod(uint8_t led, uint8_t period) {
    if (led >= LEDDRIVER_NUMBER_OF_LEDS)
        return;
    /* If the high level duration is higher than period, the led will always stay on. So nothing dangerous to not handle the case */

    ledDriverInternalState.blinking.leds[led].blinkingPeriod = period;

    /* We set the counter to the max value so it will reset on the next loop. */
    /* It will affect the waveform for the current loop but will help to maintain consistency over the time */
    /* Otherwise, the counter can go beyond its max value and iznogoud :) */
    ledDriverInternalState.blinking.leds[led].counter = period;
}

void onBlinkingTimerInterrupt() {
    onTimer1Interrupt();
    
    for (blinkingIterator = 0; blinkingIterator < LEDDRIVER_NUMBER_OF_LEDS; blinkingIterator++) {
        led = ledDriverInternalState.blinking.leds + blinkingIterator;
        /* This will be usefull to unset desired bit in nextLedStates variable */
        if ((blinkingIterator & 0x0F) == 0) { blinkingUnsetShift = 0xFE; blinkingSetShift = 0x01; }
        /* We increment the counter */
        led->counter ++;
        /* If the counter is greater than  */
        if(led->counter > led->blinkingPeriod) {
            led->counter = 0;
            ledDriverInternalState.blinking.nextLedStates[blinkingIterator >> 8] |= blinkingSetShift;
        }

        if(led->counter == led->blinkingHightLevelDuration) {
            ledDriverInternalState.blinking.nextLedStates[blinkingIterator >> 8] &= blinkingUnsetShift;
        }

        /* */
        blinkingUnsetShift = blinkingUnsetShift << 1 | 1;
        blinkingSetShift <<= 1;
    }
}

