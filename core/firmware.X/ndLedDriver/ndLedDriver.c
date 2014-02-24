#include "ndLedDriver.h"
#include "ndLedDriverInternalFunctions.h"
#include "ndLedDriverConstants.h"
#include "ndLedDriverTypes.h"

#include "../ndInternalMemory/ndInternalMemory.h"
#include "../ndEeprom/ndEeprom.h"

ledDriverInternalState_t ledDriverInternalState;
uint8_t i;
register_t shift;

void configureRegister(register_t *portRegister, register_t *latchRegister, register_t mask) {
    for(i = 0; i < LEDDRIVER_NUMBER_OF_REGISTERS; i++) {
        ledsInternalState_t *leds = ledDriverInternalState.leds + i;
        if(leds->portRegister == (register_t*)0)
        {
            leds->portRegister = portRegister;
            leds->latchRegister = latchRegister;
            leds->mask = mask;
            leds->computedNextLedStates = 0;
        }
    }
}

void setDimmingHighLevelLenght(uint8_t led, uint8_t highLevelLength) {
    if(led >= LEDDRIVER_NUMBER_OF_LEDS)
        return;
    ledDriverInternalState.dimming.ledShutOffValue[led] = highLevelLength;
}

void loadConfigurationFromEeprom() {
    uint16_t timerBaseValue;
    uint16_t timerPrescaler;

    /* We open the eeprom if possible */
    if (openEeprom()) {
        /* We seek to the start and we load the value, one by one */
        seekEeprom(LEDDRIVER_CONFIGURATION_EEPROM_START_ADDRESS);
        /* Base value and prescaler for the dimming timer */
        readWordInternalMemory(readEeprom, timerBaseValue);
        readWordInternalMemory(readEeprom, timerPrescaler);
        setDimmingTimer(0, timerBaseValue, timerPrescaler);

        /* Base value and prescaler for the blinking timer */
        readWordInternalMemory(readEeprom, timerBaseValue);
        readWordInternalMemory(readEeprom, timerPrescaler);
        setBlinkingTimer(0, timerBaseValue, timerPrescaler);

        /* Do not forget to close the eeprom */
        closeEeprom();
    }
}

void setDimmingTimer(uint8_t writeInConfig, uint16_t baseValue, uint16_t prescaler) {
    /* If writeInConfig, we keep the configuration in eeprom */
    if (writeInConfig && openEeprom()) {
        seekEeprom(LEDDRIVER_CONFIGURATION_EEPROM_START_ADDRESS);
        /* TODO */
        closeEeprom();
    }
    /* We reconfigure our dimming timer wich is Timer3 */
    setTimer3(baseValue, prescaler);
}

void onDimmingTimerInterrupt() {
    onTimer3Interrupt();
    if (ledDriverInternalState.dimming.currentDimmingCycle == LEDDRIVER_COMPUTE_CYCLE) {
        /* We increment the counter */
        ledDriverInternalState.dimming.counter++;
        if ((ledDriverInternalState.dimming.counter & ledDriverInternalState.dimming.counterResetMask) == 0) {
            for (i = 0; i < LEDDRIVER_NUMBER_OF_REGISTERS; i++)
                ledDriverInternalState.dimming.nextLedStates[i] = 0xFF;
            ledDriverInternalState.dimming.counter = 0;
        }

        /* TODO : Add some comment here */
        for (i = 0; i < LEDDRIVER_NUMBER_OF_LEDS; i++) {
            /* */
            if ((i & 0x0F) == 0) shift = 0xFE;

            /* */
            if (ledDriverInternalState.dimming.counter == ledDriverInternalState.dimming.ledShutOffValue[i])
                ledDriverInternalState.dimming.nextLedStates[i & 0x0F] &= shift;

            /* */
            shift = shift << 1 | 1;
        }

        /* We compute the led states that will be applied to the register*/
        /* TODO : add blinking */
        for (i = 0; i < LEDDRIVER_NUMBER_OF_REGISTERS; i++)
            ledDriverInternalState.leds[i].computedNextLedStates = ledDriverInternalState.dimming.nextLedStates[i];
    } else {
        /* TODO : Add a comment here */
        for (i = 0; i < LEDDRIVER_NUMBER_OF_REGISTERS; i++) {
            ledsInternalState_t *currentLeds = ledDriverInternalState.leds + i;
            *currentLeds->portRegister = currentLeds->computedNextLedStates
                | (*currentLeds->latchRegister
                & currentLeds->mask);
        }
    }
    /* We change the type of the next cycle : COMPUTE -> ACT -> COMPUTE -> ... */
    ledDriverInternalState.dimming.currentDimmingCycle = ~ledDriverInternalState.dimming.currentDimmingCycle;
}

void setBlinkingTimer(uint8_t writeInConfig, uint16_t baseValue, uint16_t prescaler) {
    /* TODO */
}

void onBlinkingTimerInterrupt() {
    /* TODO */
}

