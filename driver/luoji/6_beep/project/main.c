/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-11-06 23:06:13
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-11-06 23:58:51
 * @FilePath: /linux/driver/luoji/6_beep/project/main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
// chmod 777 imxdownload
// ./imxdownload beep.bin /dev/sdb

// 针对SDK包的代码设计
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"

/*
 * @desciption    ：main函数
 * @param   - n   ：无
 * @return        ：无
 */
int main(void)
{
    clk_enable(); /*使能所有的时钟*/
    led_init();   /*初始化led*/
    beep_init();  /*初始化beep*/

    while(1)
    {
        led_switch(LED0, ON);  /* 打开LED0 */
        beep_switch(ON); /*打开蜂鸣器*/
        delay(500);/* 延时大约500ms */

        led_switch(LED0, OFF);    /* 关闭LED0 */
        beep_switch(OFF); /*关闭蜂鸣器*/
        delay(500);/* 延时大约500ms */
    }
    return 0;
}