#ifndef __KEY
#define __KEY

#include "stm32f10x.h"

// key1 引脚定义。根据 p119 图13-2 可知 key1 接入引脚 PA0，也就是 GPIOA 的第0引脚
#define KEY1_GPIO_PORT  GPIOA                   // 设置端口为 GPIOA
#define KEY1_GPIO_PIN   GPIO_Pin_0              // 设置第0引脚
#define KEY1_GPIO_CLK   RCC_APB2Periph_GPIOA    // 设置 GPIOA 的时钟

// key2 引脚定义。根据 p119 图13-2 可知 key2 接入引脚 PC13，也就是 GPIOC 的第13引脚
#define KEY2_GPIO_PORT  GPIOC
#define KEY2_GPIO_PIN   GPIO_Pin_13
#define KEY2_GPIO_CLK   RCC_APB2Periph_GPIOC


/**
* 按键按下为高电平，设置 KEY_ON=1， KEY_OFF=0
* 若按键按下为低电平，把宏设置成KEY_ON=0 ，KEY_OFF=1 即可
*/
#define KEY_ON 1
#define KEY_OFF 0

////////////////////////////////
/* 初始化函数 */
void Key_GPIO_Config(void);

/**
* @brief 检测是否有按键按下
* @param GPIOx:具体的端口, x 可以是（A...G）
* @param GPIO_PIN:具体的端口位， 可以是GPIO_PIN_x（x 可以是0...15）
* @retval 按键的状态
*   @arg KEY_ON:按键按下
*   @arg KEY_OFF:按键没按下
*/
uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);    // GPIO_TypeDef 定义在 "stm32f10x.h"

#endif
