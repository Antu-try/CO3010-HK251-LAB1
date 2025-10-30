/*
 * software_timer.c
 *
[ *  Created on: Oct 30, 2025
 *      Author: Admin
 */
#include "7seg.h"


const int MAX_LED = 4;
int index_led = 0;


void update7SEG ( int index )
{
	switch ( index )
	{
		case 0:
			// Display the first 7 SEG with led_buffer [0]
			HAL_GPIO_WritePin ( en0_GPIO_Port , en0_Pin ,GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( en1_GPIO_Port , en1_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( en2_GPIO_Port , en2_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( en3_GPIO_Port , en3_Pin ,GPIO_PIN_SET ) ;
			//display7SEG(led_buffer[index]);
			break ;
		case 1:
			// Display the second 7 SEG with led_buffer [1]
			HAL_GPIO_WritePin ( en0_GPIO_Port , en0_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( en1_GPIO_Port , en1_Pin ,GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( en2_GPIO_Port , en2_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( en3_GPIO_Port , en3_Pin ,GPIO_PIN_SET ) ;
			//display7SEG(led_buffer[index]);
			break ;
		case 2:
			// Display the third 7 SEG with led_buffer [2]
			HAL_GPIO_WritePin ( en0_GPIO_Port , en0_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( en1_GPIO_Port , en1_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( en2_GPIO_Port , en2_Pin ,GPIO_PIN_RESET ) ;
			HAL_GPIO_WritePin ( en3_GPIO_Port , en3_Pin ,GPIO_PIN_SET ) ;
			//display7SEG(led_buffer[index]);
			break ;
		case 3:
			// Display the forth 7 SEG with led_buffer [3]
			HAL_GPIO_WritePin ( en0_GPIO_Port , en0_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( en1_GPIO_Port , en1_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( en2_GPIO_Port , en2_Pin ,GPIO_PIN_SET ) ;
			HAL_GPIO_WritePin ( en3_GPIO_Port , en3_Pin ,GPIO_PIN_RESET ) ;
			//display7SEG(led_buffer[index]);
			index = 0;
			break ;
		default :
			break ;
	}
}

void display7SEG(int num)
{
	if (num == 0)
	{
		HAL_GPIO_WritePin ( a_GPIO_Port , a_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( b_GPIO_Port , b_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( c_GPIO_Port , c_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( d_GPIO_Port , d_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( e_GPIO_Port , e_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( f_GPIO_Port , f_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( g_GPIO_Port , g_Pin ,GPIO_PIN_SET ) ;
	}
	if (num == 1)
	{
		HAL_GPIO_WritePin ( a_GPIO_Port , a_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( b_GPIO_Port , b_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( c_GPIO_Port , c_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( d_GPIO_Port , d_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( e_GPIO_Port , e_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( f_GPIO_Port , f_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( g_GPIO_Port , g_Pin ,GPIO_PIN_SET ) ;
	}
	if (num == 2)
	{
		HAL_GPIO_WritePin ( a_GPIO_Port , a_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( b_GPIO_Port , b_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( c_GPIO_Port , c_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( d_GPIO_Port , d_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( e_GPIO_Port , e_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( f_GPIO_Port , f_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( g_GPIO_Port , g_Pin ,GPIO_PIN_RESET ) ;
	}
	if (num == 3)
	{
		HAL_GPIO_WritePin ( a_GPIO_Port , a_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( b_GPIO_Port , b_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( c_GPIO_Port , c_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( d_GPIO_Port , d_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( e_GPIO_Port , e_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( f_GPIO_Port , f_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( g_GPIO_Port , g_Pin ,GPIO_PIN_RESET ) ;
	}
	if (num == 4)
	{
		HAL_GPIO_WritePin ( a_GPIO_Port , a_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( b_GPIO_Port , b_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( c_GPIO_Port , c_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( d_GPIO_Port , d_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( e_GPIO_Port , e_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( f_GPIO_Port , f_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( g_GPIO_Port , g_Pin ,GPIO_PIN_RESET ) ;
	}
	if (num == 5)
	{
		HAL_GPIO_WritePin ( a_GPIO_Port , a_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( b_GPIO_Port , b_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( c_GPIO_Port , c_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( d_GPIO_Port , d_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( e_GPIO_Port , e_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( f_GPIO_Port , f_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( g_GPIO_Port , g_Pin ,GPIO_PIN_RESET ) ;
	}
	if (num == 6)
	{
		HAL_GPIO_WritePin ( a_GPIO_Port , a_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( b_GPIO_Port , b_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( c_GPIO_Port , c_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( d_GPIO_Port , d_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( e_GPIO_Port , e_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( f_GPIO_Port , f_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( g_GPIO_Port , g_Pin ,GPIO_PIN_RESET ) ;
	}
	if (num == 7)
	{
		HAL_GPIO_WritePin ( a_GPIO_Port , a_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( b_GPIO_Port , b_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( c_GPIO_Port , c_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( d_GPIO_Port , d_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( e_GPIO_Port , e_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( f_GPIO_Port , f_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( g_GPIO_Port , g_Pin ,GPIO_PIN_SET ) ;
	}
	if (num == 8)
	{
		HAL_GPIO_WritePin ( a_GPIO_Port , a_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( b_GPIO_Port , b_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( c_GPIO_Port , c_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( d_GPIO_Port , d_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( e_GPIO_Port , e_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( f_GPIO_Port , f_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( g_GPIO_Port , g_Pin ,GPIO_PIN_RESET ) ;
	}
	if (num == 9)
	{
		HAL_GPIO_WritePin ( a_GPIO_Port , a_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( b_GPIO_Port , b_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( c_GPIO_Port , c_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( d_GPIO_Port , d_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( e_GPIO_Port , e_Pin ,GPIO_PIN_SET ) ;
		HAL_GPIO_WritePin ( f_GPIO_Port , f_Pin ,GPIO_PIN_RESET ) ;
		HAL_GPIO_WritePin ( g_GPIO_Port , g_Pin ,GPIO_PIN_RESET ) ;
	}
}
