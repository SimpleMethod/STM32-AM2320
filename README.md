# AM2320

STM32 library for temperature and humidity sensor AM2320 using HAL and i2c.

Minimum reading time with sensor response:
![enter image description here](https://raw.githubusercontent.com/SimpleMethod/STM32-AM2320/master/Images/am2320_Logic.png)

Example of program operation:
![enter image description here](https://raw.githubusercontent.com/SimpleMethod/STM32-AM2320/master/Images/am2320_RealTerm.png)

**IMPORTANT!**

### **If you want to use printf and return float number you must add the flag -u _printf_float in C compiler**
![enter image description here](https://raw.githubusercontent.com/SimpleMethod/STM32-AM2320/master/Images/am2320_Atolic_TrueSTUDIO.png)

**Pin setting**

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
**Example code:**
**Remember the address of the device must be left shift by one bit. It is also important to remember about pull-up resistors e.g. 4.7kΩ** 

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
