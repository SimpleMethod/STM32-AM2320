# AM2320

STM32 library for temperature and humidity sensor AM2320 using HAL and i2c.

Screenshot from logic analyzers
![](https://raw.githubusercontent.com/SimpleMethod/STM32-AM2320/master/Images/am2320_Logic.png)


![](https://raw.githubusercontent.com/SimpleMethod/STM32-AM2320/master/Images/am2320_RealTerm.png)



### **For using printf with float should be add flag -u _printf_float in C compiler**
![enter image description here](https://raw.githubusercontent.com/SimpleMethod/STM32-AM2320/master/Images/am2320_Atolic_TrueSTUDIO.png)

# Pin setting:

```markdown
| PERIPHERALS | MODES                 | FUNCTIONS      | PINS              |
|-------------|-----------------------|----------------|-------------------|
| I2C1        | I2C                   | I2C1_SCL       | PB8               |
| I2C1        | I2C                   | I2C1_SDA       | PB9               |
| SYS         | Trace Asynchronous Sw | SYS_JTMS-SWDIO | PA13              |
| SYS         | Trace Asynchronous Sw | SYS_JTCK-SWCLK | PA14              |
| SYS         | Trace Asynchronous Sw | SYS_JTDO-SWO   | PB3               |
| SYS         | SysTick               | SYS_VS_Systick | VP_SYS_VS_Systick |
| USART2      | Asynchronous          | USART2_RX      | PA3               |
| USART2      | Asynchronous          | USART2_TX      | PA2               |
```
# Example:

    /* Private includes ----------------------------------------------------------*/
    /* USER CODE BEGIN Includes */
    #include "am2320.h"
    /* USER CODE END Includes */
    
    /* USER CODE BEGIN 2 */
    Am2320_HandleTypeDef Am2320_;
    Am2320_ = am2320_Init(&hi2c1, AM2320_ADDRESS);
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
