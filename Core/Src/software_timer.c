/*
 * software_timer.c
 *
[ *  Created on: Oct 30, 2025
 *      Author: Admin
 */
#include "software_timer.h"

#define MAX_TIMERS 10

int tick = 10;
int timer_flag[MAX_TIMERS];
int timer_counter[MAX_TIMERS];

void set_timer(int index, int counter)
{
	if (index < 0 || index >= MAX_TIMERS) return;
	timer_flag[index] = 0;
	timer_counter[index] = counter/tick;
}

void led_timer()
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

void timer_run()
{
	for(int i = 0; i < MAX_TIMERS; i++)
	{
		if(timer_counter[i] >= 0)
		{
			timer_counter[i]--;
			if(timer_counter[i] <= 0)
			{
				timer_flag[i] = 1;
			}
		}
	}
}

int is_timer_expired(int index)
{
	if(index < 0 || index >= MAX_TIMERS)
	{
		return -1;
	}
	return timer_flag[index];
}
