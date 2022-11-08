.global _start /* 全局标号 */

/* 全局标号设置C的运行环境 */
_start:
    /* 进入SVC模式 */
    mrs r0, cpsr
    bic r0, r0, #0x1f  /* 将r0的低五位清零，也就是cpsr的M0-M4 */
    orr r0, r0, #0x13  /* r0或上0x13，表示使用SVC模式*/
    msr cpsr, r0 /* 将r0的数据写入搭配cpsr_c中 */

    ldr sp, =0x80200000  /*设置栈指针*/
    b main               /*跳转到main函数中*/


    /*  （1）I.MX6U-ALPHA开发板上的DDR3地址范围是0X80000000~0XA0000000(512MB)由于 Cortex-A7的堆栈是向下增长的，所以将 SP指针设置为 0X80200000，
因此 SVC模式的栈大小 0X80200000-0X80000000=0X200000=2MB，2MB的栈空间已经很大了，
如果做裸机开发的话绰绰有余
        （2）为什么只需要切换到SVC模式下初始化SP指针，然后跳转到main函数就可以了呢？这是因为在
板卡LMX6U的Boot ROM会去读取DCD数据中的DDR配置参数来完成DDR初始化的。*/
