线路图见 p119

两个键：key1 接在引脚 PA0 上，key2 接在引脚 PC13 上。接通（下压）后各自会产生 3.3v的高电平。

编程要点
1. 使能GPIO 端口时钟；
2. 初始化GPIO 目标引脚为输入模式(浮空输入)；
3. 编写简单测试程序，检测按键的状态，实现按键控制LED 灯。