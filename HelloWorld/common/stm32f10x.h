/*
* P-70: 定义基本数据结构
*/
#define __IO volatile
typedef unsigned int		uint32_t;
typedef unsigned short	uint16_t;


/* p34: 存储器本身没有地址，给存储器分配地址的过程叫存储器映射。芯片厂商在每个块的范围内设计各具特色的外
* 设时并不一定都用得完，都是只用了其中的一部分而已。
*
* 表格 6-1 存储器功能分类:
*
*  序号     用途                 地址范围
*  Block 0  Code                 0x0000 0000 ~ 0x1FFF FFFF(512MB)
*  Block 1  SRAM                 0x2000 0000 ~ 0x3FFF FFFF(512MB)
*  Block 2  片上外设             0x4000 0000 ~ 0x5FFF FFFF(512MB)
*  Block 3  FSMC 的bank1 ~ bank2 0x6000 0000 ~ 0x7FFF FFFF(512MB)
*  Block 4  FSMC 的bank3 ~ bank4 0x8000 0000 ~ 0x9FFF FFFF(512MB)
*  Block 5  FSMC 寄存器          0xA000 0000 ~ 0xCFFF FFFF(512MB)
*  Block 6  没有使用             0xD000 0000 ~ 0xDFFF FFFF(512MB)
*  Block 7  Cortex-M3 内部外设   0xE000 0000 ~ 0xFFFF FFFF(512MB)
*/

/*片上外设基地址 (Block 2)  */
#define PERIPH_BASE           ((unsigned int)0x40000000)


/*
* P37: 在存储器Block2 这块区域，设计的是片上外设，它们以四个字节为一个单元，共32bit，每一个单元对应不同
* 的功能. 我们可以根据每个单元功能的不同，以功能为名给这个内存单元取一个别名，这个别名就是我们经常说的
* 寄存器，这个给已经分配好地址的有特定功能的内存单元取别名的过程就叫寄存器映射。
*
* 根据外设的总线速度不同. Block 被分成了 APB 和 AHB 两部分，其中 APB 又被分为APB1 和APB2，具体见表格 6-4。
*
* 表格 6-4 存储器Block2 内部区域功能划分
* 块       用途说明        地址范围
* Block2   APB1 总线外设   0x4000 0000 ~ 0x4000 77FF
*          APB2 总线外设   0x4001 0000 ~ 0x4001 3FFF
*          AHB 总线外设    0x4001 8000 ~ 0x5003 FFFF
*/

/* APB2 总线基地址 */
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
/* AHB 总线基地址 */
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x18000)

/* 外设时钟 RCC 基地址*/
#define RCC_BASE      (AHBPERIPH_BASE + 0x9000)  // 0x22000

typedef struct {
	__IO uint32_t     _UNKNOWN[6];   // 偏移 0x18 位
	__IO uint32_t     APB2ENR;
} RCC_T;

/* RCC 的 AHB1 时钟使能寄存器地址,强制转换成指针*/
#define RCC    ((RCC_T*)(RCC_BASE))

