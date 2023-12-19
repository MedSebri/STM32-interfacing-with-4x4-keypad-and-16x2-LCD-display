#include "keypad.h"

void code_Detect(void)
   {int  x=0;

		 for (int j = 0; j < 4; j++)
		          {
		            code[j] = 'x';
		          }

	   while(x<4){

	 //reset all rows
	   HAL_GPIO_WritePin(GPIOC, R1_Pin, GPIO_PIN_RESET);
	   HAL_GPIO_WritePin(GPIOC, R2_Pin, GPIO_PIN_RESET);
	   HAL_GPIO_WritePin(GPIOC, R3_Pin, GPIO_PIN_RESET);
	   HAL_GPIO_WritePin(GPIOC, R4_Pin, GPIO_PIN_RESET);

	 //set row 1 
	   HAL_GPIO_WritePin(GPIOC, R1_Pin, GPIO_PIN_SET);

   	if(HAL_GPIO_ReadPin(GPIOB, C1_Pin) == GPIO_PIN_SET)
   	{
   		/* 1 */
   			HAL_Delay(200);
   			LCD_string((uint8_t *)"1");
   			x++;

   			if(code[0]=='x') code[0]='1';
   			else if(code[1]=='x') code[1]='1';
   			else if(code[2]=='x') code[2]='1';
   			else if(code[3]=='x') code[3]='1';

   	}




	if(HAL_GPIO_ReadPin(GPIOB, C2_Pin) == GPIO_PIN_SET)
   	{
   		/* 2 */
			HAL_Delay(200);
   			LCD_string((uint8_t *)"2");
   			x++;

   			if(code[0]=='x') code[0]='2';
   			else if(code[1]=='x') code[1]='2';
   			else if(code[2]=='x') code[2]='2';
   			else if(code[3]=='x') code[3]='2';

  	}

	if(HAL_GPIO_ReadPin(GPIOB, C3_Pin) == GPIO_PIN_SET)
   	{
   		/* 3 */
			HAL_Delay(200);
  			LCD_string((uint8_t *)"3");
  			x++;

   			if(code[0]=='x') code[0]='3';
   			else if(code[1]=='x') code[1]='3';
   			else if(code[2]=='x') code[2]='3';
   			else if(code[3]=='x') code[3]='3';

   	}

  	if(HAL_GPIO_ReadPin(GPIOB, C4_Pin) == GPIO_PIN_SET)
   	{
   		/* A */
			HAL_Delay(200);
  			LCD_string((uint8_t *)"A");
  			x++;

   			if(code[0]=='x') code[0]='A';
   			else if(code[1]=='x') code[1]='A';
   			else if(code[2]=='x') code[2]='A';
   			else if(code[3]=='x') code[3]='A';

   	}

   	// set row 2 and reset other rows
   	HAL_GPIO_WritePin(GPIOC, R1_Pin, GPIO_PIN_RESET);
   	HAL_GPIO_WritePin(GPIOC, R2_Pin, GPIO_PIN_SET);
   	HAL_GPIO_WritePin(GPIOC, R3_Pin, GPIO_PIN_RESET);
   	HAL_GPIO_WritePin(GPIOC, R4_Pin, GPIO_PIN_RESET);

   	if(HAL_GPIO_ReadPin(GPIOB, C1_Pin) == GPIO_PIN_SET)
   	{
   		/* 4 */
			HAL_Delay(200);
  			LCD_string((uint8_t *)"4");
			x++;

   			if(code[0]=='x') code[0]='4';
   			else if(code[1]=='x') code[1]='4';
   			else if(code[2]=='x') code[2]='4';
   			else if(code[3]=='x') code[3]='4';

   	}

	if(HAL_GPIO_ReadPin(GPIOB, C2_Pin) == GPIO_PIN_SET)
   	{
   		/* 5 */
			HAL_Delay(200);
   			LCD_string((uint8_t *)"5");
   			x++;

   			if(code[0]=='x') code[0]='5';
   			else if(code[1]=='x') code[1]='5';
   			else if(code[2]=='x') code[2]='5';
   			else if(code[3]=='x') code[3]='5';

   	}

   	if(HAL_GPIO_ReadPin(GPIOB, C3_Pin) == GPIO_PIN_SET)
   	{
   		/* 6 */
			HAL_Delay(200);
   			LCD_string((uint8_t *)"6");
   			x++;

   			if(code[0]=='x') code[0]='6';
   			else if(code[1]=='x') code[1]='6';
   			else if(code[2]=='x') code[2]='6';
   			else if(code[3]=='x') code[3]='6';

   	}

   	if(HAL_GPIO_ReadPin(GPIOB, C4_Pin) == GPIO_PIN_SET)
   	{
   		/* B */
			HAL_Delay(200);
   			LCD_string((uint8_t *)"B");
   			x++;

   			if(code[0]=='x') code[0]='B';
   			else if(code[1]=='x') code[1]='B';
   			else if(code[2]=='x') code[2]='B';
   			else if(code[3]=='x') code[3]='B';

   	}

   	// set row 3 and reset other rows
   	HAL_GPIO_WritePin(GPIOC, R1_Pin, GPIO_PIN_RESET);
   	HAL_GPIO_WritePin(GPIOC, R2_Pin, GPIO_PIN_RESET);
   	HAL_GPIO_WritePin(GPIOC, R3_Pin, GPIO_PIN_SET);
   	HAL_GPIO_WritePin(GPIOC, R4_Pin, GPIO_PIN_RESET);

   	if(HAL_GPIO_ReadPin(GPIOB, C1_Pin) == GPIO_PIN_SET)
   	{
   		/* 7 */
			HAL_Delay(200);
   			LCD_string((uint8_t *)"7");
   			x++;

   			if(code[0]=='x') code[0]='7';
   			else if(code[1]=='x') code[1]='7';
   			else if(code[2]=='x') code[2]='7';
   			else if(code[3]=='x') code[3]='7';

   	}

   	if(HAL_GPIO_ReadPin(GPIOB, C2_Pin) == GPIO_PIN_SET)
   	{
   		/* 8 */
			HAL_Delay(200);
   			LCD_string((uint8_t *)"8");
   			x++;

   			if(code[0]=='x') code[0]='8';
   			else if(code[1]=='x') code[1]='8';
   			else if(code[2]=='x') code[2]='8';
   			else if(code[3]=='x') code[3]='8';

   	}

   	if(HAL_GPIO_ReadPin(GPIOB, C3_Pin) == GPIO_PIN_SET)
   	{
  		/* 9 */
			HAL_Delay(200);
   			LCD_string((uint8_t *)"9");
   			x++;

   			if(code[0]=='x') code[0]='9';
   			else if(code[1]=='x') code[1]='9';
   			else if(code[2]=='x') code[2]='9';
   			else if(code[3]=='x') code[3]='9';

   	}

   	if(HAL_GPIO_ReadPin(GPIOB, C4_Pin) == GPIO_PIN_SET)
   	{
   		/* C */
			HAL_Delay(200);
   			LCD_string((uint8_t *)"C");
   			x++;

   			if(code[0]=='x') code[0]='C';
   			else if(code[1]=='x') code[1]='C';
   			else if(code[2]=='x') code[2]='C';
   			else if(code[3]=='x') code[3]='C';

   	}

	//set row 4 and reset other rows
   	HAL_GPIO_WritePin(GPIOC, R1_Pin, GPIO_PIN_RESET);
   	HAL_GPIO_WritePin(GPIOC, R2_Pin, GPIO_PIN_RESET);
   	HAL_GPIO_WritePin(GPIOC, R3_Pin, GPIO_PIN_RESET);
   	HAL_GPIO_WritePin(GPIOC, R4_Pin, GPIO_PIN_SET);

   	if(HAL_GPIO_ReadPin(GPIOB, C1_Pin) == GPIO_PIN_SET)
   	{
   		/* * */
			HAL_Delay(200);
   			LCD_string((uint8_t *)"*");
   			x++;

   			if(code[0]=='x') code[0]='*';
   			else if(code[1]=='x') code[1]='*';
   			else if(code[2]=='x') code[2]='*';
   			else if(code[3]=='x') code[3]='*';

   	}

   	if(HAL_GPIO_ReadPin(GPIOB, C2_Pin) == GPIO_PIN_SET)
   	{
   		/* 0 */
			HAL_Delay(200);
			LCD_string((uint8_t *)"0");
			x++;

   			if(code[0]=='x') code[0]='0';
   			else if(code[1]=='x') code[1]='0';
   			else if(code[2]=='x') code[2]='0';
   			else if(code[3]=='x') code[3]='0';

   	}

   	if(HAL_GPIO_ReadPin(GPIOB, C3_Pin) == GPIO_PIN_SET)
   	{
   		/* # */
			HAL_Delay(200);
   			LCD_string((uint8_t *)"#");
   			x++;

   			if(code[0]=='x') code[0]='#';
   			else if(code[1]=='x') code[1]='#';
   			else if(code[2]=='x') code[2]='#';
   			else if(code[3]=='x') code[3]='#';

   	}

   	if(HAL_GPIO_ReadPin(GPIOB, C4_Pin) == GPIO_PIN_SET)
   	{
   		/* D */
			HAL_Delay(200);
   			LCD_string((uint8_t *)"D");
   			x++;

   			if(code[0]=='x') code[0]='D';
   			else if(code[1]=='x') code[1]='D';
   			else if(code[2]=='x') code[2]='D';
   			else if(code[3]=='x') code[3]='D';

   	}

	}

   }




void led_lighting_Detect(void)
   {
	int  x=0;

	 for (int j = 0; j < 4; j++)
	          {
	            code[j] = 'x';
	          }

	   while(x<1){

	 //reset all rows
	   HAL_GPIO_WritePin(GPIOC, R1_Pin, GPIO_PIN_RESET);
	   HAL_GPIO_WritePin(GPIOC, R2_Pin, GPIO_PIN_RESET);
	   HAL_GPIO_WritePin(GPIOC, R3_Pin, GPIO_PIN_RESET);
	   HAL_GPIO_WritePin(GPIOC, R4_Pin, GPIO_PIN_RESET);

	 //set row 1
	   HAL_GPIO_WritePin(GPIOC, R1_Pin, GPIO_PIN_SET);

   	if(HAL_GPIO_ReadPin(GPIOB, C1_Pin) == GPIO_PIN_SET)
   	{
   		/* 1 */
   			HAL_Delay(200);
   			x++;
   			if(code[0]=='x') code[0]='1';

   	}




	if(HAL_GPIO_ReadPin(GPIOB, C2_Pin) == GPIO_PIN_SET)
   	{
   		/* 2 */
			HAL_Delay(200);
   			x++;
   			if(code[0]=='x') code[0]='2';

  	}




   	//set row 4 and reset other rows
   	HAL_GPIO_WritePin(GPIOC, R1_Pin, GPIO_PIN_RESET);
   	HAL_GPIO_WritePin(GPIOC, R2_Pin, GPIO_PIN_RESET);
   	HAL_GPIO_WritePin(GPIOC, R3_Pin, GPIO_PIN_RESET);
   	HAL_GPIO_WritePin(GPIOC, R4_Pin, GPIO_PIN_SET);

   	if(HAL_GPIO_ReadPin(GPIOB, C1_Pin) == GPIO_PIN_SET)
   	{
   		/* * */
			HAL_Delay(200);
   			x++;
   			if(code[0]=='x') code[0]='*';

   	}

	 }

   }
