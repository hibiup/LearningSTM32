/**
实现对（由GPIO端口状态的变化引起的）外部事件的响应需要执行以下步骤：

    1)开启相应GPIO时钟端口，以实现对该端口的控制相应。
        KEY1_INT_GPIO_CLK 定义在 bsp_exit.h 中

    2)开启AFIO时钟端口，以实现对AFIO的控制。
        同上。

    3)设置 AFIO，将指定的 GPIO 映射到指定的 EXTI。
        EXTI_Key_Config 中调用 GPIO_EXTILineConfig 函数
        
    4)设置 EXTI 以实现对信号的响应模式。
        EXTI_Key_Config 中调用 EXTI_Init。同时设置响应的线路 KEY1_INT_EXTI_LINE

    5)设置 NVIC，以定义中断响应的优先级。
        参考 bsp_exti.c 中的 NVIC_Configuration 函数

    6)实现中断响应函数 KEY1_IRQHandler（预设中断 EXTI0_IRQHandler 的别名）
        参考 stm32f10x_it.c
*/

#include "stm32f10x.h"
#include "bsp\bsp_led.h"
#include "bsp\bsp_exti.h" 


/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */ 
int main(void)
{
  /* LED 端口初始化 */
  LED_GPIO_Config();
      
  /* 初始化EXTI中断，按下按键会触发中断，
  *  触发中断会进入stm32f4xx_it.c文件中的函数
  *  KEY1_IRQHandler和KEY2_IRQHandler，处理中断，反转LED灯。
  */
  EXTI_Key_Config(); 
  
  /* 等待中断，由于使用中断方式，CPU不用轮询按键 */
  while(1)                            
  {
  }
}
/*********************************************END OF FILE**********************/
