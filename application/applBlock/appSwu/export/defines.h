/*
 * defines.h
 *
 *  Created on: 16 maj 2015
 *      Author: kirk
 */

#ifndef EXPORT_DEFINES_H_
#define EXPORT_DEFINES_H_

enum TIMERS {TIMER_HEARTBEAT = 0,
             TIMER_ALARM = 1,
             TIMER_TEMP_SAMPLING =2,
             TIMER_ENGINEN = 3};

enum TIMERS_TIMOUTS {TIMER_HEARTBEAT_TIMEOUT = 5,
                     TIMER_ALARM_TIMEOUT = 5,
                     TIMER_TEMP_SAMPLING_TIMEOUT =5,
                     TIMER_ENGINEN_TIMEOUT = 5};


enum NOTIFICATIONS {HEARTBEAT = 0,
                    ALARM = 1,
                    TEMP_SAMPLING = 2,
                    ENGINEN = 3};


#endif /* EXPORT_DEFINES_H_ */
