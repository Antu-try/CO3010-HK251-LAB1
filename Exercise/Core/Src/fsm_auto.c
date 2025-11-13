/*
 * software_timer.c
 *
[ *  Created on: Oct 30, 2025
 *      Author: Admin
 */
#include "fsm_auto.h"

int k = 0;

int led_buffer[4] = {0, 0, 0, 0};
int num_to_display_1 = 0;
int num_to_display_2 = 0;


void fsm_auto()
{
	if(is_timer_expired(3) && (status == AUTO_GREEN_RED ||
							   status == AUTO_RED_GREEN ||
							   status == AUTO_YELLOW_RED ||
							   status == AUTO_RED_YELLOW ||
							   status == AUTO_INIT))
	{
		getKeyInput();
		if (isButton0Pressed())
		{
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
			clear();
			led_buffer[0] = 0;
			led_buffer[1] = 0;
			led_buffer[2] = 0;
			led_buffer[3] = 0;
			status = MANUAL_INIT;
		}
		else set_timer(3, 20);
	}


	if(is_timer_expired(5)  && (status == AUTO_GREEN_RED ||
			   	   	   	   	   status == AUTO_RED_GREEN ||
							   status == AUTO_YELLOW_RED ||
							   status == AUTO_RED_YELLOW ||
							   status == AUTO_INIT))
	{
		num_to_display_1--;
		num_to_display_2--;
		led_buffer[0] = num_to_display_1/10;
		led_buffer[1] = num_to_display_1%10;
		led_buffer[2] = num_to_display_2/10;
		led_buffer[3] = num_to_display_2%10;
		set_timer(5, 1000);
	}
	if(is_timer_expired(4))
	{
		if(k == 4) k = 0;
		update7SEG(k);
		display7SEG(led_buffer[k]);
		k++;
		set_timer(4, 150);
	}


	if(is_timer_expired(2))
	{
		switch (status)
		{
			case AUTO_INIT:
				status = AUTO_RED_GREEN;
//				set_timer(2, 5);
//				set_timer(3, 4);
//				set_timer(4, 3);
//				set_timer(5, 2);
				break;
			case AUTO_RED_GREEN:
				led_red_and_green();
				num_to_display_1 = 5;
				num_to_display_2 = 3;
				status = AUTO_RED_YELLOW;
				set_timer(2, 3000);
				break;
			case AUTO_RED_YELLOW:
				led_red_and_yellow();
				num_to_display_1 = 2;
				num_to_display_2 = 2;
				status = AUTO_GREEN_RED;
				set_timer(2, 2000);
				break;
			case AUTO_GREEN_RED:
				led_green_and_red();
				num_to_display_1 = 3;
				num_to_display_2 = 5;
				status = AUTO_YELLOW_RED;
				set_timer(2, 3000);
				break;
			case AUTO_YELLOW_RED:
				led_yellow_and_red();
				num_to_display_1 = 2;
				num_to_display_2 = 2;
				status = AUTO_GREEN_RED;
				set_timer(2, 2000);
				break;
			default:
				break;
		}
	}
}
