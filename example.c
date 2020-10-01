/*
 * main.c
 *
 *  Created on: 01.10.2020
 *      Author: SimpleMethod
 *  
 *Copyright 2020 SimpleMethod
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy of
 *this software and associated documentation files (the "Software"), to deal in
 *the Software without restriction, including without limitation the rights to
 *use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 *of the Software, and to permit persons to whom the Software is furnished to do
 *so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all
 *copies or substantial portions of the Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *THE SOFTWARE.
 ******************************************************************************
 */
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "am2320.h"
/* USER CODE END Includes */

/* USER CODE BEGIN 2 */
Am2320_HandleTypeDef Am2320_;
Am2320_ = am2320_Init(&hi2c1, 0x5C << 1);
float temperature, humidity;
/* USER CODE END 2 */
/* Infinite loop */
/* USER CODE BEGIN WHILE */
while (1) {
  am2320_GetTemperatureAndHumidity(&Am2320_, &temperature, &humidity);
  my_printf("=====================================\r\n");
  my_printf("Temperature: %.1fºC\r\n", temperature);
  my_printf("Humidity: %.1f%%\r\n", humidity);
  HAL_Delay(3000);
  /* USER CODE END WHILE */
  /* USER CODE BEGIN 3 */
}
/* USER CODE END 3 */
