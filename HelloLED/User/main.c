#include "bsp_led.h"
#include "stm32f10x.h"

#define SOFT_DELAY Delay(0x0FFFFF);

void Delay(__IO u32 nCount);    // __IO 和 u32 定义在 stm32f10x.h 中


///////////////////////////////////////////////////

//简单的延时函数
void Delay(__IO uint32_t nCount)
{
    for (; nCount != 0; nCount--);
}

// 主函数
int main(void)
{
    /* LED 端口初始化 */
    LED_GPIO_Config();

    while (1)
    {
        // 用 bsp_led.h 中定义的宏来控制LED的亮灭
        LED1_ON; // 亮
        SOFT_DELAY;
        LED1_OFF; // 灭

        LED2_ON; // 亮
        SOFT_DELAY;
        LED2_OFF; // 灭

        LED3_ON; // 亮
        SOFT_DELAY;
        LED3_OFF; // 灭

        /*轮流显示 红绿蓝黄紫青白 颜色*/
        LED_RED;
        SOFT_DELAY;

        LED_GREEN;
        SOFT_DELAY;

        LED_BLUE;
        SOFT_DELAY;

        LED_YELLOW;
        SOFT_DELAY;

        LED_PURPLE;
        SOFT_DELAY;

        LED_CYAN;
        SOFT_DELAY;

        LED_WHITE;
        SOFT_DELAY;

        LED_RGBOFF;
        SOFT_DELAY;
    }
}

/*
这个函数在STM32标准库的“system_stm32f10x.c”文件中定义了，而我们的工程已经
包含该文件。标准库中的SystemInit 函数把STM32 芯片的系统时钟设置成了72MHz，即此
时AHB 时钟频率为72MHz，APB2 为72MHz，APB1 为36MHz。当STM32 芯片上电后，
执行启动文件中的指令后，会调用该函数，设置系统时钟为以上状态。

void SystemInit() {}
*/

///////////////////////////////////

// 见 p114-115 对 assert_param 宏的说明，如果开启了“USE_FULL_ASSERT”宏，那么我们需要提供一个错误信息的输出函数，因为缺省没有实现这个函数。
void assert_failed(uint8_t* file, uint32_t line)
{
    printf("\r\n 输入参数错误，错误文件名=%s,行号=%s", file, line);
}
