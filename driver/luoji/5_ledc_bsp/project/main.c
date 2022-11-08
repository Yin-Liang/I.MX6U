// chmod 777 imxdownload
// ./imxdownload bsp.bin /dev/sdb

// 针对SDK包的代码设计
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"

/*
 * @desciption    ：main函数
 * @param   - n   ：无
 * @return        ：无
 */
int main(void)
{
    clk_enable(); /*使能所有的时钟*/
    led_init();   /*初始化led*/

    while(1)
    {
        led_switch(LED0, ON);  /* 打开LED0 */
        delay(500);/* 延时大约500ms */

        led_switch(LED0, OFF);    /* 关闭LED0 */
        delay(500);/* 延时大约500ms */
    }

    return 0;
}