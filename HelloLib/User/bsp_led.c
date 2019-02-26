#include "bsp_led.h"
#include "stm32f10x_gpio.h"

void LED_GPIO_Config(void) {
    /* 定义一个GPIO_InitTypeDef 类型的结构体*/
    GPIO_InitTypeDef GPIO_InitStructure;

    ///////////////////////////////////
    // 初始化引脚的步骤
    //
    /* 1) 开启 LED 相关的 GPIO 外设时钟*/
    RCC_APB2PeriphClockCmd( LED1_GPIO_CLK|
                            LED2_GPIO_CLK|
                            LED3_GPIO_CLK, ENABLE);
    
    /* 2-1) 设置引脚模式为通用推挽输出*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    /* 2-2) 设置引脚速率为50MHz */
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    
    /* 3-1) 选择 LED1 的GPIO 引脚*/
    GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;
    /* 3-2) 调用库函数，初始化 LED1 的 GPIO*/
    GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);

    // 重复以上 3-1),3-2) 动作初始化 LED2 和 LED3
    GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;
    GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED3_GPIO_PIN;
    GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure);

    ///////////////////////////////////
    // 执行功能函数
    //
    /* 关闭所有led 灯 */
    GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);

    /* 关闭所有led 灯 */
    GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);

    /* 关闭所有led 灯 */
    GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);
}
