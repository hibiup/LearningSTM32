#ifndef __LED_H
#define __LED_H

// G-绿色
#define LED1_GPIO_PORT  GPIOB                 // 端口。定义在 CMSIS\stm32f10x.h
#define LED1_GPIO_CLK   RCC_APB2Periph_GPIOB   // 端口时钟。定义在 inc\stm32f10x_rcc.h 中
#define LED1_GPIO_PIN   GPIO_Pin_0             // 引脚。定义在 inc\stm32f10x_gpio.h 中

// B-蓝色
#define LED2_GPIO_PORT  GPIOB
#define LED2_GPIO_CLK   RCC_APB2Periph_GPIOB
#define LED2_GPIO_PIN   GPIO_Pin_1

// R-红色
#define LED3_GPIO_PORT  GPIOB
#define LED3_GPIO_CLK   RCC_APB2Periph_GPIOB
#define LED3_GPIO_PIN   GPIO_Pin_5


/* 我们把LED 灯常用的亮、灭及状态反转的控制也直接定义成宏。(直接操作寄存器的方法控制IO)*/
#define digitalHi(p,i)      { p->BSRR=i; }      //输出为高电平
#define digitalLo(p,i)      { p->BRR=i; }       //输出低电平
#define digitalToggle(p,i)  { p->ODR ^=i; }     //输出反转状态


/* 定义控制 IO 的宏 */
#define LED1_TOGGLE     digitalToggle(LED1_GPIO_PORT, LED1_GPIO_PIN)
#define LED1_OFF        digitalHi(LED1_GPIO_PORT, LED1_GPIO_PIN)
#define LED1_ON         digitalLo(LED1_GPIO_PORT, LED1_GPIO_PIN)

#define LED2_TOGGLE     digitalToggle(LED2_GPIO_PORT, LED2_GPIO_PIN)
#define LED2_OFF        digitalHi(LED2_GPIO_PORT, LED2_GPIO_PIN)
#define LED2_ON         digitalLo(LED2_GPIO_PORT, LED2_GPIO_PIN)

#define LED3_TOGGLE     digitalToggle(LED2_GPIO_PORT, LED3_GPIO_PIN)
#define LED3_OFF        digitalHi(LED2_GPIO_PORT, LED3_GPIO_PIN)
#define LED3_ON         digitalLo(LED2_GPIO_PORT, LED3_GPIO_PIN)


/* 基本混色，后面高级用法使用PWM 可混出全彩颜色,且效果更好 */
//红
#define LED_RED \
        LED1_ON;\
        LED2_OFF\
        LED3_OFF

//绿
#define LED_GREEN \
        LED1_OFF;\
        LED2_ON\
        LED3_OFF

//蓝
#define LED_BLUE \
        LED1_OFF;\
        LED2_OFF\
        LED3_ON

//黄(红+绿)
#define LED_YELLOW \
        LED1_ON;\
        LED2_ON\
        LED3_OFF

//紫(红+蓝)
#define LED_PURPLE \
        LED1_ON;\
        LED2_OFF\
        LED3_ON

//青(绿+蓝)
#define LED_CYAN \
        LED1_OFF;\
        LED2_ON\
        LED3_ON

//白(红+绿+蓝)
#define LED_WHITE \
        LED1_ON;\
        LED2_ON\
        LED3_ON

//黑(全部关闭)
#define LED_RGBOFF \
        LED1_OFF;\
        LED2_OFF\
        LED3_OFF



void LED_GPIO_Config(void);

#endif   // end of __LED_H: 防止头文件重复包含
