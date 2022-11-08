/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-11-06 17:52:33
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-11-06 21:04:15
 * @FilePath: /linux/driver/luoji/5_ledc_bsp/bsp/led/bsp_led.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "bsp_led.h"

/*
 * @desciption ：初始化LED所对应的GPIO
 * @param      ：无
 * @return     ：无
 */
void led_init(void)
{
    /* 1.初始化IO使用，复用为GPIO1_IO03,MODE为5对应GPIO功能 */
    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0);
    /* 2.配置GPIO1_IO03的IO属性
     *bit 16:0 HYS关闭
	 *bit [15:14]: 00 默认下拉
     *bit [13]: 0 kepper功能
     *bit [12]: 1 pull/keeper使能
     *bit [11]: 0 关闭开路输出
     *bit [7:6]: 10 速度100Mhz
     *bit [5:3]: 110 R0/6驱动能力
     *bit [0]: 0 低转换率  
     */ 
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0X10B0);

    /* 3.初始化GPIO，GPIO1_IO03设置为输出 */
    GPIO1->GDIR |= (1<<3);

    /* 3.设置GPIO1_IO03输出为低电平，打开LED0 */
    GPIO1->DR &= ~(1<<3);
}

/*
 * @desciption     ：LED控制函数，控制LED打开还是关闭
 * @param  -led    ：要控制的LED灯编号
 * @param  -status : 0,关闭LED0；1，打开LED0
 * @return         ：无
 */
void led_switch(int led, int status)
{
    switch(led)
    {
        case LED0:
            if(status == ON)
                GPIO1->DR &= ~(1<<3); /*打开LED0*/
            else if(status == OFF)
                GPIO1->DR |=  (1<<3); /*关闭LED0*/
        
    }
}

