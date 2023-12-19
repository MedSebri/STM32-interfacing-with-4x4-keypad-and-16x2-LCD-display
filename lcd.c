#include "lcd.h"
#include "stm32f4xx.h"
#include "stm32f4xx.h"

extern uint16_t data_pins[8];



 void LCD_init(void)
   {
   	  HAL_Delay(100);     // Give LCD time to intialize
   	  LCD_command(0x38);  // Setting 8-bit mode
      LCD_command(0x38);
      LCD_command(0x38);

      LCD_command(0x0C);  // Display ON and Cursor OFF
      LCD_command(0x06);  // Auto Increment Cursor
      LCD_command(0x01);  // Clear Display
      LCD_command(0x80);  // Cursor at home position
   }

   /*****************************************************************************************************************************/
   /* Command mode operations */

void LCD_command(uint8_t value)
   {
      HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_RESET);

   	// writing to data to D0, D1, D2, D3, D4, D5, D6, D7

   	  for (int i = 0; i < 8; i++)
   	{
       HAL_GPIO_WritePin(GPIOB, data_pins[i], ((value >> i) & 0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
     }

   	// Pulse the Enable pin

   	 HAL_GPIO_WritePin(GPIOA, E_Pin, GPIO_PIN_RESET);
     HAL_Delay(1);
     HAL_GPIO_WritePin(GPIOA, E_Pin, GPIO_PIN_SET);
     HAL_Delay(1);    // enable pulse must be >450ns
     HAL_GPIO_WritePin(GPIOA, E_Pin, GPIO_PIN_RESET);
     HAL_Delay(1);   // commands need > 37us to settle

   }
   /*****************************************************************************************************************************/
   /* Data mode operations */

void LCD_data(uint8_t value)
   {
   	  HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_RESET);

   	  for (int i = 0; i < 8; i++)
   	{
       HAL_GPIO_WritePin(GPIOB, data_pins[i], ((value >> i) & 0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
     }

   	// Pulse the Enable pin

     HAL_GPIO_WritePin(GPIOA, E_Pin, GPIO_PIN_RESET);
     HAL_Delay(1);
     HAL_GPIO_WritePin(GPIOA, E_Pin, GPIO_PIN_SET);
     HAL_Delay(1);    // enable pulse must be >450ns
     HAL_GPIO_WritePin(GPIOA, E_Pin, GPIO_PIN_RESET);
     HAL_Delay(1);   // commands need > 37us to settle
   }
   /*****************************************************************************************************************************/

   /* Printing the string */

void LCD_string(uint8_t *str)
   {
   	int i = 0;

   	while(str[i] != '\0')
   	{
   		 LCD_data(str[i]);
   		 i++;
   	}

  }



