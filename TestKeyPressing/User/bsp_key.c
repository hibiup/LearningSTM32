#include "stm32f10x.h"
#include "bsp_key.h"

void Key_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    /* 1)开启按键端口的时钟*/
    RCC_APB2PeriphClockCmd( KEY1_GPIO_CLK|
                            KEY2_GPIO_CLK, ENABLE);
    
    // 2)设置按键的引脚为浮空输入(上例点亮 LED 案例中设置的是推挽输出模式)
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    
    // 3-1)选择 key1 的引脚
    GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN;
    // 3-2)初始化 key1
    GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
    
    // 选择 key2 的引脚
    GPIO_InitStructure.GPIO_Pin = KEY2_GPIO_PIN;
    // 初始化key2
    GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);
}


uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
    /* 检测是否有按键按下 */
    if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON ) {         // GPIO_ReadInputDataBit 定义在 inc\stm32f10x_gpio.h 中，它读取 GPIOx.IDR 寄存器上的数据并检测指定引脚的值。
        /*等待按键释放 */
        while (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON);    // 死循环，直到 False，也就是直到返回 KEY_OFF
        return KEY_ON;
    } else
        return KEY_OFF;
}
