/*
 * software_timer.c
 *
[ *  Created on: Oct 30, 2025
 *      Author: Admin
 */
#include "button.h"
int KeyReg00 = NORMAL_STATE;
int KeyReg10 = NORMAL_STATE;
int KeyReg20 = NORMAL_STATE;
int KeyReg30 = NORMAL_STATE;
int KeyReg01 = NORMAL_STATE;
int KeyReg11 = NORMAL_STATE;
int KeyReg21 = NORMAL_STATE;
int KeyReg31 = NORMAL_STATE;
int KeyReg02 = NORMAL_STATE;
int KeyReg12 = NORMAL_STATE;
int KeyReg22 = NORMAL_STATE;
int KeyReg32 = NORMAL_STATE;

int TimeOutForKeyPress =  50;
int button0_pressed = 0;
int button1_long_pressed = 0;
int button0_flag = 0;
int button1_pressed = 0;
int button1_flag = 0;
int button2_pressed = 0;
int button2_flag = 0;

int isButton0Pressed(){
	if(button0_flag == 1){
		button0_flag = 0;
		return 1;
	}
	return 0;
}
int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}

int isButton1LongPressed(){
	if(button1_long_pressed == 1){
		button1_long_pressed = 0;
		return 1;
	}
	return 0;
}



void getKeyInput()
{
	KeyReg20 = KeyReg10;
	KeyReg10 = KeyReg00;
	// Add your key
	KeyReg00 = HAL_GPIO_ReadPin(btn1_GPIO_Port, btn1_Pin);

	if ((KeyReg10 == KeyReg00) && (KeyReg10 == KeyReg20))
	{
		if (KeyReg20 != KeyReg30)
		{
			KeyReg30 = KeyReg20;
			if (KeyReg30 == PRESSED_STATE)
			{
					TimeOutForKeyPress = 500;
					//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
					button0_flag = 1;
			}

		}
		else
		{
			TimeOutForKeyPress --;
			if (TimeOutForKeyPress == 0)
			{
				TimeOutForKeyPress = 500;
				if (KeyReg30 == PRESSED_STATE)
				{
					//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
					button0_flag = 1;
				}
			}
		}
	}
	KeyReg21 = KeyReg11;
    KeyReg11 = KeyReg01;
    // Add your key
    KeyReg01 = HAL_GPIO_ReadPin(btn2_GPIO_Port, btn2_Pin);

    if ((KeyReg11 == KeyReg01) && (KeyReg11 == KeyReg21))
    {
    	if (KeyReg21 != KeyReg31)
    	{
    		KeyReg31 = KeyReg21;
    		if (KeyReg31 == PRESSED_STATE)
    		{
    			TimeOutForKeyPress = 500;
    			//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
    			button1_flag = 1;
    		}
    	}
    	else
    	{
    		TimeOutForKeyPress --;
    		if (TimeOutForKeyPress == 0)
    		{
    			TimeOutForKeyPress = 500;
    			if (KeyReg31 == PRESSED_STATE)
    			{
    				//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
    				button1_flag = 1;
    			}
    		}
    	}
    }
    KeyReg22 = KeyReg12;
    KeyReg12 = KeyReg02;
      // Add your key
    KeyReg02 = HAL_GPIO_ReadPin(btn3_GPIO_Port, btn3_Pin);

    if ((KeyReg12 == KeyReg02) && (KeyReg12 == KeyReg22))
    {
    	if (KeyReg22 != KeyReg32)
    	{
    		KeyReg32 = KeyReg22;
    		if (KeyReg32 == PRESSED_STATE)
    		{
    			TimeOutForKeyPress = 500;
    			//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
    			button2_flag = 1;
    		}
        }
    	else
    	{
    		TimeOutForKeyPress --;
            if (TimeOutForKeyPress == 0)
            {
            	TimeOutForKeyPress = 500;
            	if (KeyReg32 == PRESSED_STATE)
            	{
            		//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
            		button2_flag = 1;
            	}
            }
    	}
    }
}



