/* 
 * 配置MCO引脚：PA8 对外提供时钟，最高频率不能超过IO口的翻转频率50MHZ
 * MCO 时钟来源可以是：PLLCLK/2 ,HSI,HSE,SYSCLK
 */
#include "stm32f10x.h"
#include "bsp\bsp_led.h"
#include "bsp\bsp_clkconfig.h"

//  软件延时函数，使用不同的系统时钟，延时不一样
void Delay(__IO u32 nCount); 


/*******************************
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	
	/**
    * 程序来到main函数之前，启动文件：statup_stm32f10x_hd.s 已经调用 SystemInit() 函数把系统时钟初始化成 72MHZ
	* （SystemInit()在system_stm32f10x.c中定义）。如果用户想修改系统时钟，可自行编写程序修改重新设置系统时钟，
    * 这时候可以选择使用HSE还是HSI
	* 
	*  使用HSE时，SYSCLK = 8M * RCC_PLLMul_x, x:[2,3,...16],最高是128M
	*  使用HSI时，SYSCLK = 4M * RCC_PLLMul_x, x:[2,3,...16],最高是64MH
    */
	HSI_SetSysClock(RCC_PLLMul_5);
	//HSE_SetSysClock(RCC_PLLMul_9);
	
	// LED 端口初始化
	LED_GPIO_Config();
	while (1){
		LED1_ON;			  // 亮
		Delay(0x0FFFFF);
		LED1_OFF;    		  // 灭 
		Delay(0x0FFFFF);		
	}
}

/*******************************
*  软件延时函数，使用不同的系统时钟，延时不一样
*/
void Delay(__IO uint32_t nCount){
	for(; nCount != 0; nCount--);
}
