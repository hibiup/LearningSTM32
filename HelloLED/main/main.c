/*
测试点亮主板上(接在 GPIOB 上)的 LED 灯。在本教程中STM32 芯片与LED 灯的连接 p60，这是一个RGB 灯，里面由红蓝绿
三个小灯构成。

注意：因为需要对外设地址(0x40000000开始)执行写入操作；在用模拟器调试的时候需要设置地址的读写权限，否则会遇到：
"error 65: access violation at 0x40023800 : no 'read' permission" 错误
	
设置方法：
	1)在项目根目录下新建 debug.ini 文件，内容：
	MAP 0x40000000, 0x47FFFFFF READ WRITE // allow R/W access to IO space
	
	2) 应用配置：
	Project->Options for Target->Debug，点击 "initialization file:" 边上的"..."按钮，选择debug.ini 文件，确定保存即可。	
*/


// 引入外设寄存器配置
#include "..\gpio\gpio.h"

// 系统初始化函数（必须定义，否则会报错）
void SystemInit(void){}


// 主函数
int main(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    /*
	  一、根据 p-66 的图8-11，开启 GPIOB 端口的时钟（也就意味着我们将使用 GPIOB 来控制外设。）：
	  */
    RCC->APB2ENR |= (1 << 3);
	
	
    /*
    二、根据P-60的图8-8所示，PB1端口控制蓝色LED灯。
    */
    int LED_GREEN	= GPIO_Pin_0;
    int LED_BLUE	= GPIO_Pin_1;
    int LED_RED		= GPIO_Pin_5;


	/*
	因此我们先清空PB1端口位。也就是将 CRL 的 4~7Bit 清零:
	
	~(0x0F << (4*1)) = ~0x000000F0 = 0xFFFFFF0F   // 0xF = 0b1111
	GPIOB_CRL = GPIOB_CRL & 0xFFFFFF0F = 0x......0.
	4*1 表示第二个4Bit(PB1)，如果要设置 PB0(绿色LED)，则改为 4*0
	*/
	//GPIOB->CRL &= ~(0x0F << (4*LED_BLUE));    // Debug模式下可以打开 Peripherals->System view->GPIO->GPIOB 窗口查看寄存器状态
    GPIO_InitStructure.GPIO_Pin = LED_BLUE;     // 选择要控制的 GPIO 引脚( 输入 0b1, GPIO_Init会计算出对CRL偏移4位)


	/*
	三、然后将PB1设置为通用推挽输出，速度为10M(参考P-59): 0x1=0b0001
	GPIOB_CRL = GPIOB_CRL | (1 << 4*1) = 0x......1.
	*/
	//GPIOB->CRL |= (1 << 4*LED_BLUE);
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     // 设置引脚模式为通用推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;    // 设置引脚速率为10MHz


	/*
	四、PB1 输出低电平(ODR的第2位对应PB1):
	~(1 << 1) = ~0x00000002 = 0xFFFFFFFD = 0b1111 1111 1111 1111 1111 1111 1111 1101
	*/
	//GPIOB->ODR &= ~(1 << LED_BLUE);
    GPIO_Init(GPIOB, &GPIO_InitStructure);     // 调用库函数，初始化GPIO 引脚
    GPIO_ResetBits(GPIOB, LED_BLUE);           // 使引脚输出低电平,点亮LED1


	/* 让子弹飞... */
	while(1);
}

