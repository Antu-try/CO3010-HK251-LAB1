/*
 * software_timer.c
 *
[ *  Created on: Oct 30, 2025
 *      Author: Admin
 */
#include "fsm_manual.h"

int red_time = 0;
int yellow_time = 0;
int green_time = 0;
int red;
int yellow;
int green;
int check = 0;

int num_to_display1 = 0;
int num_to_display2 = 0;

void fsm_manual()
{
	if(is_timer_expired(8))
	{
		getKeyInput();
		set_timer(8, 20);
	}

	if(is_timer_expired(9))
	{
		switch(status)
		{
		case MANUAL_INIT:
			toggle();
			led_buffer[0] = 0;
			led_buffer[1] = 0;
			led_buffer[2] = 0;
			led_buffer[3] = 0;
			if(isButton0Pressed())
			{
				clear();
				status = RED_SET;
			}
			else if(isButton2Pressed())
			{
				clear();
				status = AUTO_INIT;
			}
			else set_timer(3, 20);
			set_timer(9, 500);
			break;
		case RED_SET:
			togglered();
			if(isButton0Pressed())
			{
				clear();
				if (red_time <= 1) red_time = 2;
				else red = red_time;
				status = YELLOW_SET;
				led_buffer[0] = yellow_time/10;
				led_buffer[1] = yellow_time%10;
				led_buffer[2] = 0;
				led_buffer[3] = 0;
				set_timer(3, 20);
			}
			else if(isButton1Pressed())
			{
				clear();
				red_time++;
				led_buffer[0] = red_time/10;
				led_buffer[1] = red_time%10;
				led_buffer[2] = 0;
				led_buffer[3] = 0;
				set_timer(3, 20);
			}
			else if(isButton2Pressed())
			{
				clear();
				if(red_time <= 1)
				{
					red_time = 2;
					yellow_time = 1;
					green_time = red_time - yellow_time;

					red = red_time;
					yellow = yellow_time;
					green = green_time;

					status = MAN_RED_GREEN;
				}
				else
				{
					yellow_time = 1;
					green_time = red_time - yellow_time;
					red = red_time;
					yellow = yellow_time;
					green = green_time;
					led_buffer[0] = red_time/10;
					led_buffer[1] = red_time%10;
					led_buffer[2] = 0;
					led_buffer[3] = 0;
					status = MAN_RED_GREEN;
				}
				set_timer(3, 20);
			}
			else set_timer(3, 20);
			set_timer(9, 500);
			break;
		case YELLOW_SET:
			toggleyellow();
			if(isButton0Pressed())
			{
				clear();
				if (yellow_time <= 1) yellow_time = 1;
				status = GREEN_SET;
				led_buffer[0] = green_time/10;
				led_buffer[1] = green_time%10;
				led_buffer[2] = 0;
				led_buffer[3] = 0;
				set_timer(3, 20);
			}
			else if(isButton1Pressed())
			{
				yellow_time++;
				led_buffer[0] = yellow_time/10;
				led_buffer[1] = yellow_time%10;
				led_buffer[2] = 0;
				led_buffer[3] = 0;
				set_timer(3, 20);
			}
			else if(isButton2Pressed())
			{
				clear();
				if(yellow_time < 1)
				{
					yellow_time = 1;
					green_time = red_time - yellow_time;
					red = red_time;
					yellow = yellow_time;
					green = green_time;
					led_buffer[0] = yellow_time/10;
					led_buffer[1] = yellow_time%10;
					led_buffer[2] = 0;
					led_buffer[3] = 0;
					status = MAN_RED_GREEN;
				}
				else if (yellow_time >= red_time)
				{
					red_time = 0;
					yellow_time = 0;
					green_time = 0;
					led_buffer[0] = 0;
					led_buffer[1] = 0;
					led_buffer[2] = 0;
					led_buffer[3] = 0;
					status = RED_SET;
				}
				else{
					yellow = yellow_time;
					green = green_time = red_time - yellow_time;
					status = MAN_RED_GREEN;
				}
				set_timer(3, 20);
			}
			else set_timer(3, 20);
			set_timer(9, 500);
			break;
		case GREEN_SET:
			togglegreen();
			if(isButton0Pressed())
			{
				clear();
				status = RED_SET;
				set_timer(3, 20);
			}
			else if(isButton1Pressed())
			{
				green_time++;
				led_buffer[0] = green_time/10;
				led_buffer[1] = green_time%10;
				led_buffer[2] = 0;
				led_buffer[3] = 0;
				set_timer(3, 20);
			}
			else if(isButton2Pressed())
			{
				if(green_time == (red_time - yellow_time) && (yellow_time != 0))
				{
					clear();
					status = MAN_RED_GREEN;
				}
				else {
					status = RED_SET;
					red_time = 0;
					yellow_time = 0;
					green_time = 0;
					led_buffer[0] = 0;
					led_buffer[1] = 0;
					led_buffer[2] = 0;
					led_buffer[3] = 0;
				}
				set_timer(3, 20);
			}
			else set_timer(3, 20);
			set_timer(9, 500);
			break;
		case MAN_RED_GREEN:

			led_red_and_green();
			led_buffer[0] = red/10;
			led_buffer[1] = red%10;
			led_buffer[2] = green/10;
			led_buffer[3] = green%10;
			red--;
			green--;
			if(green == 0)
			{
				green = green_time;
				status = MAN_RED_YELLOW;
			}
			if(isButton2Pressed())
			{
				clear();
				red_time = 0; yellow_time = 0; green_time = 0;
				status = MANUAL_INIT;
				set_timer(3, 20);
			}
			set_timer(9, 1000);
			break;
		case MAN_RED_YELLOW:

			led_red_and_yellow();
			led_buffer[0] = red/10;
			led_buffer[1] = red%10;
			led_buffer[2] = yellow/10;
			led_buffer[3] = yellow%10;
			red--;
			yellow--;
			if(red == 0)red = red_time;
			if(yellow == 0)
			{
				yellow = yellow_time;
				status = MAN_GREEN_RED;
			}
			if(isButton2Pressed())
			{
				clear();
				red_time = 0; yellow_time = 0; green_time = 0;
				status = MANUAL_INIT;
				set_timer(3, 20);
			}
			set_timer(9, 1000);
			break;
		case MAN_GREEN_RED:

			led_green_and_red();
			led_buffer[0] = green/10;
			led_buffer[1] = green%10;
			led_buffer[2] = red/10;
			led_buffer[3] = red%10;
			red--;
			green--;
			if(green == 0)
			{
				green = green_time;
				status = MAN_YELLOW_RED;
			}
			if(isButton2Pressed())
			{
				clear();
				red_time = 0; yellow_time = 0; green_time = 0;
				status = MANUAL_INIT;
				set_timer(3, 20);
			}
			set_timer(9, 1000);
			break;
		case MAN_YELLOW_RED:

			led_yellow_and_red();
			led_buffer[0] = yellow/10;
			led_buffer[1] = yellow%10;
			led_buffer[2] = red/10;
			led_buffer[3] = red%10;
			yellow--;
			red--;
			if(yellow == 0)
			{
				red = red_time;
				yellow = yellow_time;
				status = MAN_RED_GREEN;
			}
			if(isButton2Pressed())
			{
				clear();
				red_time = 0; yellow_time = 0; green_time = 0;
				status = MANUAL_INIT;
				set_timer(3, 20);
			}
			set_timer(9, 1000);
			break;
//		case TER_INIT:
//			clear();
//			led_buffer[0] = 0;
//			led_buffer[1] = 0;
//			led_buffer[2] = 0;
//			led_buffer[3] = 0;
//			status = MANUAL_INIT;
//			set_timer(9, 1);
//			break;
		default:
			break;
			}
	}

}
