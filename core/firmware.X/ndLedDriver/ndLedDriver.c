#include "ndLedDriver.h"
#include "ndLedDriverInternalFunctions.h"
#include "ndLedDriverConstants.h"

#include "../ndInternalMemory/ndInternalMemory.h"
#include "../ndEeprom/ndEeprom.h"

void initLedDriver() {
    /* We initialize both timers */
    initDimmingTimer();
    initBlinkingTimer();
    /* We load the configuration from the eeprom since they are not hardcoded */
    loadConfigurationFromEeprom();
}

void initDimmingTimer() {
    timer3Config_t dimmingTimerConfig;
    dimmingTimerConfig.shouldLoop = 0;
    dimmingTimerConfig.triggerEvent = 0;
    dimmingTimerConfig.useInterrupt = 1;
    setUpTimer3(dimmingTimerConfig);
}

void initBlinkingTimer() {
    /* TODO with timer 1 */
}

void loadConfigurationFromEeprom() {
    uint16_t timerBaseValue;
    uint16_t timerPrescaler;

    /* We open the eeprom if possible */
    if(openEeprom()) {
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
    if(writeInConfig && openEeprom()) {
        seekEeprom(LEDDRIVER_CONFIGURATION_EEPROM_START_ADDRESS);
        /* TODO */
        closeEeprom();
    }
    /* We reconfigure our dimming timer wich is Timer3 */
    setTimer3(baseValue, prescaler);
}

void onDimmingTimerInterrupt() {
    /* TODO */
}

void setBlinkingTimer(uint8_t writeInConfig, uint16_t baseValue, uint16_t prescaler) {
    /* TODO */
}

void onBlinkingTimerInterrupt() {
    /* TODO */
}

