/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "lcd16x2.h"
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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//Omid Davar : setting row and col using pointers
int SetRowCol(int *row , int *column) {
    //B5 , B6 , B7 , B8 , B9 for rows and are inputs
    //A8 , A9 , B3 , B4 for cols and are outputs
    //for first col
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3 | GPIO_PIN_4, GPIO_PIN_RESET);
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9) == 1)
    {
        *row = 0;
        *column = 0;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == 1)
    {
        *row = 1;
        *column = 0;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == 1)
    {
        *row = 2;
        *column = 0;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) == 1)
    {
        *row = 3;
        *column = 0;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) == 1)
    {
        *row = 4;
        *column = 0;
    }

    //for second col
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3 | GPIO_PIN_4, GPIO_PIN_RESET);
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9) == 1)
    {
        *row = 0;
        *column = 1;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == 1)
    {
        *row = 1;
        *column = 1;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == 1)
    {
        *row = 2;
        *column = 1;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) == 1)
    {
        *row = 3;
        *column = 1;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) == 1)
    {
        *row = 4;
        *column = 1;
    }

    //for third col
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 | GPIO_PIN_9, GPIO_PIN_RESET);
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9) == 1)
    {
        *row = 0;
        *column = 2;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == 1)
    {
        *row = 1;
        *column = 2;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == 1)
    {
        *row = 2;
        *column = 2;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) == 1)
    {
        *row = 3;
        *column = 2;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) == 1)
    {
        *row = 4;
        *column = 2;
    }

    //for fourth col
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8 | GPIO_PIN_9, GPIO_PIN_RESET);
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9) == 1)
    {
        *row = 0;
        *column = 3;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == 1)
    {
        *row = 1;
        *column = 3;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7) == 1)
    {
        *row = 2;
        *column = 3;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6) == 1)
    {
        *row = 3;
        *column = 3;
    }
    else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) == 1)
    {
        *row = 4;
        *column = 3;
    }
    return 0;
}
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
  /* USER CODE BEGIN 2 */
  char realpass[3] = { '0' , '0' , '0' };
  int tried = 0;
 LCD_HandleTypeDef lcd;
    lcd.RS.Port = GPIOA;
    lcd.RS.Pin = GPIO_PIN_1;
    lcd.EN.Port = GPIOA;
    lcd.EN.Pin = GPIO_PIN_3;
    //instead of RW pin 
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
    lcd.DB4.Port = GPIOA;
    lcd.DB4.Pin = GPIO_PIN_4;
    lcd.DB5.Port = GPIOA;
    lcd.DB5.Pin = GPIO_PIN_5;
    lcd.DB6.Port = GPIOA;
    lcd.DB6.Pin = GPIO_PIN_6;
    lcd.DB7.Port = GPIOA;
    lcd.DB7.Pin = GPIO_PIN_7;
    LCD_Init(&lcd);
    GETPASS:

    LCD_clrscr(&lcd);
    LCD_home(&lcd);
    LCD_puts(&lcd, "Enter your pass:");
    LCD_gotoxy(&lcd, 0, 1);
    char data [5][4] = {{'F','f','#','*'},
                      {'1','2','3','U'},
                      {'4','5','6','D'},
                      {'7','8','9','E'},
                      {'L','0','R','e'}};
  int row = 0;
  int column = -1;
  //declaring pointer for row and col
  int *rowptr = &row;
  int *colptr = &column;
  int lcdc=0;
  /* USER CODE END 2 */
  char pass[3];  
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  
  while (1)
  {
    /* USER CODE END WHILE */
    column=-1;
    SetRowCol(rowptr, colptr);
    if(column != -1)
	{
            LCD_gotoxy(&lcd,lcdc,1);
            LCD_sendChar(&lcd, data[row][column]);
            pass[lcdc] = data[row][column];
            lcdc++;
            if(lcdc == 3){
              break;
            }
            HAL_Delay(500);
	}
      
    /* USER CODE BEGIN 3 */
  }
  //cheking for pass
  if(pass[0] == realpass[0] && pass[1] == realpass[1] && pass[2] == realpass[2]){
      LCD_clrscr(&lcd);
      LCD_home(&lcd);
      LCD_puts(&lcd, "Pass Is Correct!");
      HAL_Delay(2000);
  }
  else {
      if (tried >= 2) {
          LCD_clrscr(&lcd);
          LCD_home(&lcd);
          LCD_puts(&lcd, "locked for 60s");
          HAL_Delay(15000);
          tried = 0;
      }
      else {
          tried++;
          LCD_clrscr(&lcd);
          LCD_home(&lcd);
          LCD_puts(&lcd, "pass wrong!");
          HAL_Delay(2000);
      }
      goto GETPASS;
  }
  //user entered the system
  LCD_clrscr(&lcd);
  LCD_home(&lcd);
  LCD_puts(&lcd, "Change Pass:");
  LCD_gotoxy(&lcd, 0, 1);
  lcdc = 0;
  while (1)
  {
      /* USER CODE END WHILE */
      column = -1;
      SetRowCol(rowptr, colptr);
      if (column != -1)
      {
          LCD_gotoxy(&lcd, lcdc, 1);
          LCD_sendChar(&lcd, data[row][column]);
          realpass[lcdc] = data[row][column];
          lcdc++;
          if (lcdc == 3) {
              break;
          }
          HAL_Delay(500);
      }

      /* USER CODE BEGIN 3 */
  }
  LCD_clrscr(&lcd);
  LCD_home(&lcd);
  LCD_puts(&lcd, "Password Changed!");
  goto GETPASS;
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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA1 PA2 PA3 PA4
                           PA5 PA6 PA7 PA8
                           PA9 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB3 PB4 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB5 PB6 PB7 PB8
                           PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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

#ifdef  USE_FULL_ASSERT
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
