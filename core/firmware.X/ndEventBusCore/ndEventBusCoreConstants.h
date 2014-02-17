#ifndef NDEVENTBUSCORECONSTANTS_H_
#define NDEVENTBUSCORECONSTANTS_H_

/**
 * Definition of which kind of event we are sending.
 * SPECIAL : Value that are used for internal operation of the eventbus. DO NOT USE.
 * CORE : Events that are send by the eventbus to notify his state.
 * HW : Events that are send after a hardware interrupt occured. ex : a counter overflow.
 * SW : Events that are defined by modules. ex : We have receive a msg from the user.
 */
#define EVENT_TYPE_HW 0
#define EVENT_TYPE_SW 1

/**
 *
 */
#define EVENT_MODULE_EVENTBUS 0

/**
 * 
 */
#define EVENT_SPECIAL_NOEVENT 0 /** The is no event available */
#define EVENT_SPECIAL_SKIP_TO_START 1

/**
 */
#define EVENT_EMPTY_PAYLOAD 0
#define EVENT_1BYTE_PAYLOAD 1
#define EVENT_2BYTES_PAYLOAD 2
#define EVENT_4BYTES_PAYLOAD 3

/*
 * The eventbus require some eeprom to maintain some value between shutdown/start
 * cycle.
 */
#define EVENTBUS_RESERVED_EEPROM_LENGTH 1

/**
 * We define the maximum number of module that our event dispatcher can handle by type.
 */
#define EVENTDISPATCHER_MAX_NUMBER_OF_MODULE_PER_TYPE 4  

#define EVENTDISPATCHER_MODULES_BLOCK_LENGHT 

#define EVENTDISPATCHER_BLOCK_HARDWARE_MODULES_START_ADDRESS


#define EVENTBUS_

#endif