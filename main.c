/**
  ******************************************************************************
  * @file    main.c
  * @author  Mouadh Dahech
  * @brief   How to develop structured code 
  * @version V1.0.0
  * @date    16-10-2022
  *****************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
//#include "stm32f4xx.h"
/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  InputOutputConfig (GPIOA, PIN12,OUTPUT);
  uint8_t GreenLedToggle = ButtonToggleLed(GPIOD,PIN0);
 
  while (1)
  {
   }
}


/**************************************END OF FILE**************************************/
