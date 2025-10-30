/*
 * software_timer.c
 *
[ *  Created on: Oct 30, 2025
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_
#include "global.h"
#include "main.h"

void led_timer();
void set_timer(int index, int counter);
void timer_run();
int is_timer_expired(int index);

#endif /* INC_SOFTWARE_TIMER_H_ */
