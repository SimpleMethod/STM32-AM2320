/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "am2320.h"
/* USER CODE END Includes */

/* USER CODE BEGIN 2 */
Am2320_HandleTypeDef Am2320_;
Am2320_ = am2320_init(&hi2c1, 0x5C << 1);
float temperature, humidity;
/* USER CODE END 2 */
/* Infinite loop */
/* USER CODE BEGIN WHILE */
while (1) {
  am2320_getValue(&Am2320_, &temperature, &humidity);
  my_printf("=====================================\r\n");
  my_printf("Temperature: %.1fºC\r\n", temperature);
  my_printf("Humidity: %.1f%%\r\n", humidity);
  HAL_Delay(3000);
  /* USER CODE END WHILE */
  /* USER CODE BEGIN 3 */
}
/* USER CODE END 3 */
