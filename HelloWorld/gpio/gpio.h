# include "..\common\stm32f10x.h"

/*
* P40: GPIO 外设基地址
*/
#define GPIOA_BASE (APB2PERIPH_BASE + 0x0800)
#define GPIOB_BASE (APB2PERIPH_BASE + 0x0C00)
#define GPIOC_BASE (APB2PERIPH_BASE + 0x1000)
#define GPIOD_BASE (APB2PERIPH_BASE + 0x1400)
#define GPIOE_BASE (APB2PERIPH_BASE + 0x1800)
#define GPIOF_BASE (APB2PERIPH_BASE + 0x1C00)
#define GPIOG_BASE (APB2PERIPH_BASE + 0x2000)

typedef struct {
	__IO uint32_t CRL;
	__IO uint32_t CRH;
	__IO uint32_t IDR;
	__IO uint32_t ODR;
	__IO uint32_t BSRR;
	__IO uint32_t BRR;
	__IO uint32_t LCKR;
} GPIO_T;

#define GPIOA ((GPIO_T *) GPIOA_BASE)
#define GPIOB ((GPIO_T *) GPIOB_BASE)
#define GPIOC ((GPIO_T *) GPIOC_BASE)
#define GPIOD ((GPIO_T *) GPIOD_BASE)
#define GPIOE ((GPIO_T *) GPIOE_BASE)
#define GPIOF ((GPIO_T *) GPIOF_BASE)
#define GPIOG ((GPIO_T *) GPIOG_BASE)


/* GPIO 引脚 */
#define GPIO_Pin_0 		((uint16_t)(0b1 << 0))
#define GPIO_Pin_1		((uint16_t)(0b1 << 1))
#define GPIO_Pin_2		((uint16_t)(0b1 << 2))
#define GPIO_Pin_3		((uint16_t)(0b1 << 3))
#define GPIO_Pin_4		((uint16_t)(0b1 << 4))
#define GPIO_Pin_5		((uint16_t)(0b1 << 5))
#define GPIO_Pin_6		((uint16_t)(0b1 << 6))
#define GPIO_Pin_7		((uint16_t)(0b1 << 7))
#define GPIO_Pin_8		((uint16_t)(0b1 << 8))
#define GPIO_Pin_9		((uint16_t)(0b1 << 9))
#define GPIO_Pin_10		((uint16_t)(0b1 << 10))
#define GPIO_Pin_11		((uint16_t)(0b1 << 11))
#define GPIO_Pin_12		((uint16_t)(0b1 << 12))
#define GPIO_Pin_13		((uint16_t)(0b1 << 13))
#define GPIO_Pin_14		((uint16_t)(0b1 << 14))
#define GPIO_Pin_15		((uint16_t)(0b1 << 15))
#define GPIO_Pin_All 	((uint16_t)0xFFFF)


/**
2 * P-77: GPIO 输出速率枚举定义. CHL 的每4个Bit控制一个引脚，Speed由 0,1 Bit位控制。
3 */
typedef enum
{
		GPIO_Speed_10MHz = 1, 	// 10MHZ (0b01)
		GPIO_Speed_2MHz,			 	// 2MHZ  (0b10)
		GPIO_Speed_50MHz				// 50MHZ (0b11)
} GPIOSpeed_E;

/**
* P-78: GPIO 工作模式枚举定义
*/
typedef enum
{
		GPIO_Mode_AIN = 0x0,						// 模拟输入     (0b0000 0000)    Mode由 CHL 的2,3 Bit	位控制
		GPIO_Mode_IN_FLOATING = 0x04, 	// 浮空输入     (0b0000 0100)
		GPIO_Mode_IPD = 0x28,						// 下拉输入     (0b0010 1000)
		GPIO_Mode_IPU = 0x48, 					// 上拉输入     (0b0100 1000)
		GPIO_Mode_Out_OD = 0x14, 				// 开漏输出     (0b0001 0100)
		GPIO_Mode_Out_PP = 0x10, 				// 推挽输出     (0b0001 0000)
		GPIO_Mode_AF_OD = 0x1C, 				// 复用开漏输出 (0b0001 1100)
		GPIO_Mode_AF_PP = 0x18 					// 复用推挽输出 (0b0001 1000)
} GPIOMode_E;

typedef struct {
		uint16_t GPIO_Pin;
		uint16_t GPIO_Speed;
		uint16_t GPIO_Mode;
} GPIO_InitTypeDef;

void GPIO_Init(GPIO_T* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_SetBits(GPIO_T* GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_T* GPIOx, uint16_t GPIO_Pin);
