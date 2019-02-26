#include "bsp_key.h"

// 主函数
int main(void)
{
    /* LED 端口初始化 */
    Key_GPIO_Config();
    
    printf(Key_Scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN));
}
