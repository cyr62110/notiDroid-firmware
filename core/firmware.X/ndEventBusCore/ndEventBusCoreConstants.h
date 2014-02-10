#ifndef NDEVENTBUSCORECONSTANTS_H_
#define NDEVENTBUSCORECONSTANTS_H_

/**
 * Definition of which kind of event we are sending.
 * SPECIAL : Value that are used for internal operation of the eventbus. DO NOT USE.
 * CORE : Events that are send by the eventbus to notify his state.
 * HW : Events that are send after a hardware interrupt occured. ex : a counter overflow.
 * SW : Events that are defined by modules. ex : We have receive a msg from the user.
 */
#define EVENT_TYPE_SPECIAL 0
#define EVENT_TYPE_CORE 1
#define EVENT_TYPE_HW 2
#define EVENT_TYPE_SW 3

#endif