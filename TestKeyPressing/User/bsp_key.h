#ifndef __KEY
#define __KEY

// key1 引脚定义。根据 p119 图13-2 可知 key1 接入引脚 PA0，也就是 GPIOA 的第0引脚
#define KEY1_GPIO_PORT  GPIOA                   // 设置端口为 GPIOA
#define KEY1_GPIO_PIN   GPIO_Pin_0              // 设置第0引脚
#define KEY1_GPIO_CLK   RCC_APB2Periph_GPIOA    // 设置 GPIOA 的时钟

// key2 引脚定义。根据 p119 图13-2 可知 key2 接入引脚 PC13，也就是 GPIOC 的第13引脚
#define KEY2_GPIO_PORT  GPIOC
#define KEY2_GPIO_PIN   GPIO_Pin_13
#define KEY2_GPIO_CLK   RCC_APB2Periph_GPIOC


////////////////////////////////

void Key_GPIO_Config(void);

#endif