#include "main.h"
#include "usb_host.h"

/* Private includes ----------------------------------------------------------*/
#include "stm32f4xx.h"
#include "lcd.h"
#include "keypad.h"

/* Private variables ---------------------------------------------------------*/
I2S_HandleTypeDef hi2s3;
SPI_HandleTypeDef hspi1;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2S3_Init(void);
static void MX_SPI1_Init(void);
void MX_USB_HOST_Process(void);


uint16_t data_pins[8];
char code[4]={'x','x','x','x'};

int main(void)
{
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2S3_Init();
  MX_SPI1_Init();
  MX_USB_HOST_Init();
  /* USER CODE BEGIN 2 */

  data_pins[0] = D0_Pin;
  data_pins[1] = D1_Pin;
  data_pins[2] = D2_Pin;
  data_pins[3] = D3_Pin;
  data_pins[4] = D4_Pin;
  data_pins[5] = D5_Pin;
  data_pins[6] = D6_Pin;
  data_pins[7] = D7_Pin;

  /* Initialize LCD */

	LCD_init();
	HAL_Delay(1000);

	LCD_command(0x01);
	LCD_command(0x1C);
	LCD_command(0x1C);
	LCD_string((uint8_t *)"4 DIGIT CODE");
	LCD_command(0XC0); // Moving the cursor to second line
	LCD_command(0x0E);

	code_Detect();
	HAL_Delay(100);

  while (1)
  {
    MX_USB_HOST_Process();

for(int i =0 ; i<4 ; i++) {

	if(code[0] !='x' && code[1] !='x' && code[2] !='x' && code[3] !='x') {

   		if(code[0]=='1' && code[1]=='2' && code[2]=='3' && code[3]=='A' )
   			 {
   		    HAL_Delay(800);

   		    HAL_GPIO_WritePin(GPIOD, Red_led_Pin, GPIO_PIN_RESET);

   		    //Toggling section
   		    HAL_GPIO_WritePin(GPIOD, Green_led_Pin, GPIO_PIN_SET);
   		    HAL_Delay(300);
   		    HAL_GPIO_WritePin(GPIOD,Green_led_Pin, GPIO_PIN_RESET);
   		    HAL_Delay(300);
   		    HAL_GPIO_WritePin(GPIOD, Green_led_Pin, GPIO_PIN_SET);
   		    HAL_Delay(300);
   		    HAL_GPIO_WritePin(GPIOD, Green_led_Pin, GPIO_PIN_RESET);
   		    HAL_Delay(300);
   		    HAL_GPIO_WritePin(GPIOD, Green_led_Pin, GPIO_PIN_SET);

   		        LCD_command(0x01);
   			LCD_command(0x14);
   			LCD_command(0x14);
   			LCD_string((uint8_t *)"CORRECT CODE");
   			LCD_command(0x0C); //display on cursor off
   			HAL_Delay(1500);

   			LCD_command(0x01);
   			LCD_string((uint8_t *)"PRESS 1 TO TURN");
   			LCD_command(0XC0); // Moving the cursor to second line
   			LCD_string((uint8_t *)"ALL LEDS ON");
   			LCD_command(0x06);

   			led_lighting_Detect();
   			HAL_Delay(100);

   			if(code[0]=='1') {
   	   		    HAL_GPIO_WritePin(GPIOD, Red_led_Pin, GPIO_PIN_SET);
   	   		    HAL_GPIO_WritePin(GPIOD, Green_led_Pin, GPIO_PIN_SET);
   	   		    HAL_GPIO_WritePin(GPIOD, Orange_led_Pin, GPIO_PIN_SET);
   	   		    HAL_GPIO_WritePin(GPIOD, Blue_led_Pin, GPIO_PIN_SET);

   	   		    HAL_Delay(1000);
   	   		    LCD_command(0x01);
   	   		    LCD_command(0x1C);
   	   		    LCD_command(0x1C);
   	   		    LCD_string((uint8_t *)"ALL LEDS ON");
   	   		    HAL_Delay(2000);

   	   			LCD_command(0x01);
   	   			LCD_string((uint8_t *)"PRESS 2 TO TURN");
   	   			LCD_command(0XC0); // Moving the cursor to second line
   	   			LCD_string((uint8_t *)"ALL LEDS OFF");
   	   			LCD_command(0x06);

   	   			led_lighting_Detect();
   	   			HAL_Delay(100);

   	   			if(code[0]=='2') {
   	   	   		    HAL_GPIO_WritePin(GPIOD, Red_led_Pin, GPIO_PIN_RESET);
   	   	   		    HAL_GPIO_WritePin(GPIOD, Green_led_Pin, GPIO_PIN_RESET);
   	   	   		    HAL_GPIO_WritePin(GPIOD, Orange_led_Pin, GPIO_PIN_RESET);
   	   	   		    HAL_GPIO_WritePin(GPIOD, Blue_led_Pin, GPIO_PIN_RESET);

   	   	   		    HAL_Delay(1000);
   	   	   		    LCD_command(0x01);
   	   	   		    LCD_command(0x1C);
   	   	   		    LCD_command(0x1C);
   	   	   		    LCD_string((uint8_t *)"ALL LEDS OFF");
   	   	   		    HAL_Delay(2000);


   	   	   			LCD_command(0x01);
   	   	   			LCD_string((uint8_t *)"PRESS * TO ");
   	   	   			LCD_command(0XC0); // Moving the cursor to second line
   	   	   			LCD_string((uint8_t *)"TOGGLE ALL LEDS");
   	   	   			LCD_command(0x06);

   	   	   			led_lighting_Detect();
   	   	   			HAL_Delay(100);

   	   	   			if(code[0]=='*') {

   	   	   	   			LCD_command(0x01);
   	    	   		         `      LCD_command(0x1C);
   	   	   	   			LCD_string((uint8_t *)"LEDS TOGGLING");

   	   	   				for(int i=0 ; i<3000000 ; i++) {
   	   	   	   		    HAL_GPIO_WritePin(GPIOD, Blue_led_Pin, GPIO_PIN_SET);
   	   	   	   		    HAL_Delay(300);
   	   	   	   		    HAL_GPIO_WritePin(GPIOD, Blue_led_Pin, GPIO_PIN_RESET);

   	   	   	   		    HAL_GPIO_WritePin(GPIOD, Green_led_Pin, GPIO_PIN_SET);
   	   	   	   		    HAL_Delay(300);
   	   	   	   		    HAL_GPIO_WritePin(GPIOD, Green_led_Pin, GPIO_PIN_RESET);

   	   	   	   		    HAL_GPIO_WritePin(GPIOD, Orange_led_Pin, GPIO_PIN_SET);
   	   	   	   		    HAL_Delay(300);
   	   	   	   		    HAL_GPIO_WritePin(GPIOD, Orange_led_Pin, GPIO_PIN_RESET);

   	   	   	   		    HAL_GPIO_WritePin(GPIOD, Red_led_Pin, GPIO_PIN_SET);
   	   	   	   		    HAL_Delay(300);
   	   	   	   		    HAL_GPIO_WritePin(GPIOD, Red_led_Pin, GPIO_PIN_RESET);

   	   	   				}
   	   	   	   			break;
   	   	   			}
   	   			}
   			}
   		}

   		else {
   			HAL_Delay(1000);

   			LCD_command(0x01); //clear screen
   			LCD_command(0x14); //move to the right
   			LCD_command(0x14);
   			LCD_command(0x14);
   			LCD_string((uint8_t *)"TRY AGAIN ");
   			LCD_command(0x0C); //display on cursor off

   		    //Toggling section
   		    HAL_GPIO_WritePin(GPIOD, Red_led_Pin, GPIO_PIN_SET);
   		    HAL_Delay(300);
   		    HAL_GPIO_WritePin(GPIOD, Red_led_Pin, GPIO_PIN_RESET);
   		    HAL_Delay(300);
   		    HAL_GPIO_WritePin(GPIOD, Red_led_Pin, GPIO_PIN_SET);
   		    HAL_Delay(300);
   		    HAL_GPIO_WritePin(GPIOD, Red_led_Pin, GPIO_PIN_RESET);
   		    HAL_Delay(300);
   		    HAL_GPIO_WritePin(GPIOD, Red_led_Pin, GPIO_PIN_SET);
   		    HAL_Delay(1500);


    		        LCD_command(0x01); //clear screen
    			LCD_command(0x1C);
    			LCD_command(0x1C);
    			LCD_string((uint8_t *)"4 DIGIT CODE");
    			LCD_command(0XC0);                       // Moving the cursor to second line
    			LCD_command(0x0E);
        		code_Detect();
           		HAL_Delay(100);
   		}

	}

}
}
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2S3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2S3_Init(void)
{

  hi2s3.Instance = SPI3;
  hi2s3.Init.Mode = I2S_MODE_MASTER_TX;
  hi2s3.Init.Standard = I2S_STANDARD_PHILIPS;
  hi2s3.Init.DataFormat = I2S_DATAFORMAT_16B;
  hi2s3.Init.MCLKOutput = I2S_MCLKOUTPUT_DISABLE;
  hi2s3.Init.AudioFreq = I2S_AUDIOFREQ_8K;
  hi2s3.Init.CPOL = I2S_CPOL_LOW;
  hi2s3.Init.ClockSource = I2S_CLOCK_PLL;
  hi2s3.Init.FullDuplexMode = I2S_FULLDUPLEXMODE_DISABLE;
  if (HAL_I2S_Init(&hi2s3) != HAL_OK)
  {
    Error_Handler();
  }

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
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
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(CS_I2C_SPI_GPIO_Port, CS_I2C_SPI_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OTG_FS_PowerSwitchOn_GPIO_Port, OTG_FS_PowerSwitchOn_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, RS_Pin|E_Pin|RW_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, D0_Pin|D1_Pin|D2_Pin|D3_Pin
                          |D4_Pin|D5_Pin|D6_Pin|D7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, Green_led_Pin|Orange_led_Pin|Red_led_Pin|Blue_led_Pin
                          |Audio_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, R1_Pin|R2_Pin|R3_Pin|R4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : CS_I2C_SPI_Pin */
  GPIO_InitStruct.Pin = CS_I2C_SPI_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(CS_I2C_SPI_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : OTG_FS_PowerSwitchOn_Pin R1_Pin R2_Pin R3_Pin
                           R4_Pin */
  GPIO_InitStruct.Pin = OTG_FS_PowerSwitchOn_Pin|R1_Pin|R2_Pin|R3_Pin
                          |R4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PDM_OUT_Pin */
  GPIO_InitStruct.Pin = PDM_OUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(PDM_OUT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : RS_Pin E_Pin RW_Pin */
  GPIO_InitStruct.Pin = RS_Pin|E_Pin|RW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : D0_Pin D1_Pin D2_Pin D3_Pin
                           D4_Pin D5_Pin D6_Pin D7_Pin */
  GPIO_InitStruct.Pin = D0_Pin|D1_Pin|D2_Pin|D3_Pin
                          |D4_Pin|D5_Pin|D6_Pin|D7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : CLK_IN_Pin */
  GPIO_InitStruct.Pin = CLK_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(CLK_IN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : C1_Pin C2_Pin C3_Pin C4_Pin */
  GPIO_InitStruct.Pin = C1_Pin|C2_Pin|C3_Pin|C4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : C3D8_Pin C4D9_Pin OTG_FS_OverCurrent_Pin C1D6_Pin
                           C2D7_Pin */
  GPIO_InitStruct.Pin = C3D8_Pin|C4D9_Pin|OTG_FS_OverCurrent_Pin|C1D6_Pin
                          |C2D7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : Green_led_Pin Orange_led_Pin Red_led_Pin Blue_led_Pin
                           Audio_RST_Pin */
  GPIO_InitStruct.Pin = Green_led_Pin|Orange_led_Pin|Red_led_Pin|Blue_led_Pin
                          |Audio_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : Audio_SDA_Pin */
  GPIO_InitStruct.Pin = Audio_SDA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
  HAL_GPIO_Init(Audio_SDA_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : MEMS_INT2_Pin */
  GPIO_InitStruct.Pin = MEMS_INT2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MEMS_INT2_GPIO_Port, &GPIO_InitStruct);

}

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
