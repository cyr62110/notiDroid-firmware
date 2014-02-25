#include "ndLedDriver.h"
#include "ndLedDriverInternalFunctions.h"
#include "ndLedDriverConstants.h"
#include "ndLedDriverTypes.h"
#include "ndLedDriverEepromFunctions.h"

ledDriverInternalState_t ledDriverInternalState;
uint8_t i, j;
register_t shift;

void configureRegisterLedDriver(register_t *portRegister, register_t *latchRegister, register_t mask) {
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

void setDimmingTimer(uint8_t writeInConfig, uint16_t baseValue, uint16_t prescaler) {
    /* If writeInConfig, we keep the configuration in eeprom */
    if (writeInConfig)
    	saveDimmingTimerToEeprom();
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
    /* If writeInConfig, we keep the configuration in eeprom */
    if (writeInConfig)
    	saveDimmingTimerToEeprom();
    /* We reconfigure our blinking timer wich is Timer1 */
    setTimer1(baseValue, prescaler);
}

void setBlinkingHighLevelDuration(uint8_t led, uint8_t duration) {
	if(led >= LEDDRIVER_NUMBER_OF_LEDS)
        return;
    ledDriverInternalState.blinking.leds[led].blinkingHightLevelDuration = duration;
}

void setBlinkingPeriod(uint8_t led, uint8_t period) {
	if(led >= LEDDRIVER_NUMBER_OF_LEDS)
        return;
    /* If the high level duration is higher than period, the led will always stay on. So nothing dangerous to not handle the case */
		
	ledDriverInternalState.blinking.leds[led].blinkingPeriod = duration;
	
	/* We set the counter to the max value so it will reset on the next loop. */
	/* It will affect the waveform for the current loop but will help to maintain consistency over the time */
	/* Otherwise, the counter can go beyond its max value and iznogoud :) */
	ledDriverInternalState.blinking.leds[led].counter = duration;
}

void onBlinkingTimerInterrupt() {
    ledBlinkingInternalState_t* led = (ledBlinkingInternalState_t*)0;
    for(j = 0; j < LEDDRIVER_NUMBER_OF_LEDS; j ++ ) {
    	/* TODO */
	}
}

