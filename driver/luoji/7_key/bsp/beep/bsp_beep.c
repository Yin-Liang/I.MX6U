/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-11-06 17:52:33
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-11-06 23:18:11
 * @FilePath: /linux/driver/luoji/5_ledc_bsp/bsp/led/bsp_led.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "bsp_beep.h"

/*
 * @desciption ：初始化蜂鸣器所对应的GPIO
 * @param      ：无
 * @return     ：无
 */
void beep_init(void)
{
    /* 1.初始化IO使用，复用为GPIO5_IO01*/
    IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0);
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
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0X10B0);

    /* 3.初始化GPIO，GPIO5_IO01设置为输出 */
    GPIO5->GDIR |= (1<<1);

    /* 3.设置GPIO5_IO01输出为高电平，关闭蜂鸣器 */
    GPIO5->DR |= (1<<1);
}

/*
 * @desciption     ：蜂鸣器控制函数，控制蜂鸣器打开还是关闭
 * @param  -led    ：要控制的蜂鸣器灯编号
 * @param  -status : 0,关闭蜂鸣器；1，打开蜂鸣器
 * @return         ：无
 */
void beep_switch(int status)
{
    if(status == ON)
        GPIO5->DR &= ~(1<<1); /*打开蜂鸣器*/
    else if(status == OFF)
        GPIO5->DR |=  (1<<1); /*关闭蜂鸣器*/   
}

