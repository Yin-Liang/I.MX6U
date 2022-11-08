/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-11-07 23:18:20
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-11-08 04:11:48
 * @FilePath: /linux/driver/luoji/7_key/bsp/key/bsp_key.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "bsp_key.h"
#include "bsp_gpio.h"
#include "bsp_delay.h"
void key_init(void)
{
    gpio_pin_config_t key_config;

      /* 1.初始化IO使用，设置UART1_CTS 复用为GPIO1_IO18 */
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0);
    /* 2.配置GPIO1_IO18的IO属性  这个IO速度为100MHz，默认22K上拉
     *bit 16:0 HYS关闭
	 *bit [15:14]: 11默认22K上拉
     *bit [13]: 1 pull功能
     *bit [12]: 1 pull/keeper使能
     *bit [11]: 0 关闭开路输出
     *bit [7:6]: 10 速度100Mhz
     *bit [5:3]: 000 关闭输出
     *bit [0]: 0 低转换率  
     */ 
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0XF080);

    /* 3.初始化GPIO，GPIO1_IO03设置为输入 */
    key_config.direction = kGPIO_DigitalInput;
    gpio_init(GPIO1, 18, &key_config);
}


int  key_getvalue(void)
{
    int ret = 0;
    static unsigned char release = 1; /* 按键松开 */

    if((release == 1) && (gpio_pinread(GPIO1, 18) == 0)) /* KEY0按下 */
    {
        delay(10);     /* 延时消抖10ms */
        release = 0;   /* 标记按键按下 */
        if(gpio_pinread(GPIO1, 18) == 0)
            ret = KEY0_VALUE;
    }
    else if(gpio_pinread(GPIO1, 18) == 1)  /* KEY0未按下 */
    {
        ret = 0;  //返回值为0表示没有按键被按下来了
        release = 1; /* 标记按键释放 */
    }
    return ret;
}