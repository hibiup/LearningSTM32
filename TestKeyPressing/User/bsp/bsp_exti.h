#ifndef __EXTI_H
#define	__EXTI_H


#include "stm32f10x.h"


//引脚定义
#define KEY1_INT_GPIO_PORT         GPIOA
#define KEY1_INT_GPIO_CLK          (RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO)
#define KEY1_INT_GPIO_PIN          GPIO_Pin_0
#define KEY1_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOA
#define KEY1_INT_EXTI_PINSOURCE    GPIO_PinSource0
#define KEY1_INT_EXTI_LINE         EXTI_Line0
#define KEY1_INT_EXTI_IRQ          EXTI0_IRQn

// EXTI0_IRQHandler 是预设的中断入口，参考 startup_stm32f10x_hd.s 的中断向量表。
// 在此我们为 EXTI0_IRQHandler 设置一个别名 KEY1_IRQHandler; KEY1_IRQHandler 是个函数，定义在 stm32f10x_it.c 中。
// 当然，也可以不设置这个别名，直接在 stm32f10x_it.c 中实现 EXTI0_IRQHandler 函数。
#define KEY1_IRQHandler            EXTI0_IRQHandler


#define KEY2_INT_GPIO_PORT         GPIOC
#define KEY2_INT_GPIO_CLK          (RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO)
#define KEY2_INT_GPIO_PIN          GPIO_Pin_13
#define KEY2_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOC
#define KEY2_INT_EXTI_PINSOURCE    GPIO_PinSource13
#define KEY2_INT_EXTI_LINE         EXTI_Line13
#define KEY2_INT_EXTI_IRQ          EXTI15_10_IRQn

#define KEY2_IRQHandler            EXTI15_10_IRQHandler

void EXTI_Key_Config(void);


#endif /* __EXTI_H */
