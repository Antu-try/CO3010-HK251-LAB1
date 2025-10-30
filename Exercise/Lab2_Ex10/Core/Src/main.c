/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
#define TICK 10
/* USER CODE BEGIN PFP */
int timer_flag[10];
int timer_counter[10];

void set_timer(int index, int counter)
{
	timer_flag[index] = 0;
	timer_counter[index] = counter/TICK;
}

void timer_run()
{
	for (int i = 0; i < 10; i++)
	{
		if (timer_counter[i] >= 0)
		{
			timer_counter[i]--;
			if (timer_counter[i] <= 0)
			{
				timer_flag[i] = 1;
			}
		}
	}
}

void timer_isr()
{
	timer_run();
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

const int MAX_LED = 4;
int index_led = 0;
int led_bufer [4] = {1, 2, 3, 4};


void update7SEG(int index)
{
	switch(index)
	{
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_bufer[index]);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_bufer[index]);
		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_bufer[index]);
		break;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		display7SEG(led_bufer[index]);
		index = 0;
		break;
	default:
		break;
	}
}

const int MATRIX_8X8_RED = 8;
int index_lex_matrix = 0;
uint8_t matrix_buffer [8] = {0x01 , 0x02 , 0x03 , 0x04 , 0x05 , 0x06 , 0x07 , 0x08 };

// Define letter 'H'
const uint8_t char_H[8] = {
    0x81,  // 10000001
    0x81,  // 10000001
    0x81,  // 10000001
    0xFF,  // 11111111
    0x81,  // 10000001
    0x81,  // 10000001
    0x81,  // 10000001
    0x00   // 00000000
};

// Define letter 'E'
const uint8_t char_E[8] = {
    0xFF,  // 11111111
    0x80,  // 10000000
    0x80,  // 10000000
    0xFF,  // 11111111
    0x80,  // 10000000
    0x80,  // 10000000
    0xFF,  // 11111111
    0x00   // 00000000
};

int scroll_position = 0;
const int MESSAGE_LENGTH = 3; // Number of characters
uint8_t scroll_buffer[8];
int current_char_index = 0;  // Current character being displayed
int shift_count = 0;  // Number of bits shifted for current character
uint8_t display_buffer[8];  // Current display buffer (8 rows)

void movingchar()
{
    // Array of characters to display
    const uint8_t* message[3] = {char_H, char_E};

    // Calculate which character and bit position we're at
    int char_index = scroll_position / 8;
    int bit_shift = scroll_position % 8;

    // Fill the scroll buffer
    for (int row = 0; row < 8; row++)
    {
        scroll_buffer[row] = 0;

        // Get current character
        if (char_index < MESSAGE_LENGTH)
        {
            scroll_buffer[row] = message[char_index][row] << bit_shift;
        }

        // Add next character if needed
        if (bit_shift > 0 && (char_index + 1) < MESSAGE_LENGTH)
        {
            scroll_buffer[row] |= message[char_index + 1][row] >> (8 - bit_shift);
        }
    }

    // Update scroll position
    scroll_position++;

    // Reset when we've scrolled through all characters
    if (scroll_position >= (MESSAGE_LENGTH * 8 + 8))
    {
        scroll_position = 0;
    }
}

//void initScrollingText(void)
//{
//    current_char_index = 0;
//    shift_count = 0;
//
//    for(int i = 0; i < 8; i++)
//    {
//        display_buffer[i] = font_table[0][i];
//    }
//}

//void shiftDisplayLeft(void)
//{
//    int next_char = (current_char_index + 1) % NUM_CHARS;
//
//    for(int row = 0; row < 8; row++)
//    {
//        display_buffer[row] = display_buffer[row] << 1;
//
//        if(font_table[next_char][row] & 0x80)
//        {
//            display_buffer[row] |= 0x01;
//        }
//    }
//
//    shift_count++;
//
//    if(shift_count >= 8)
//    {
//        shift_count = 0;
//        current_char_index = next_char;
//    }
//}

void updateMatrixBuffer(void)
{
    for(int i = 0; i < 8; i++)
    {
        matrix_buffer[i] = display_buffer[i];
    }
}

void updateMatrix(int index)
{
    // First, set all pins HIGH (turn off all LEDs)
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, SET);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, SET);

    // Enable the current row
    switch (index)
    {
        case 0:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, RESET);
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, RESET);
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET);
            break;
        case 5:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, RESET);
            break;
        case 6:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, RESET);
            break;
        case 7:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, RESET);
            break;
        default:
            break;
    }

    // Set column pins based on scroll_buffer
    uint8_t row_data = scroll_buffer[index];

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8,  (row_data & 0x01) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9,  (row_data & 0x02) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, (row_data & 0x04) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, (row_data & 0x08) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (row_data & 0x10) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (row_data & 0x20) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, (row_data & 0x40) ? RESET : SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, (row_data & 0x80) ? RESET : SET);
}/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT (& htim2 ) ;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

//  initScrollingText();

  set_timer(0, 1);
  set_timer(1, 2);
  set_timer(2, 3);
  set_timer(3, 4);
  int index_matrix = 0;
  int index = 0;
  while(1)
      {
          if(timer_flag[0] == 1)
          {
              HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
              set_timer(0, 1000);
          }
          if(timer_flag[1] == 1)
          {
              updateMatrix(index_matrix++);
              if(index_matrix > 7) index_matrix = 0;
              set_timer(1, 100);
          }
//          if(timer_flag[2] == 1)
//          {
//              shiftDisplayLeft();
//              updateMatrixBuffer();
//              set_timer(2, 0);
//          }
          if (timer_flag[2] == 1)
          {
              updateMatrix(index++);
              if (index > 7)
              {
                  index = 0;
                  // Update scroll position after completing one full scan
                  if (index == 0) movingchar();
              }
              set_timer(3, 2);  // Faster refresh for smoother display
          }
      }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */
  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|d_Pin|e_Pin|f_Pin
                          |g_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin LED_RED_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a_Pin b_Pin c_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin d_Pin e_Pin f_Pin
                           g_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = a_Pin|b_Pin|c_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|d_Pin|e_Pin|f_Pin
                          |g_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */
  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
//int num = 1;
void HAL_TIM_PeriodElapsedCallback ( TIM_HandleTypeDef * htim )
{
	timer_run();
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
