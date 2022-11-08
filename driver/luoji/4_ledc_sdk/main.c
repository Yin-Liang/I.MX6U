// chmod 777 imxdownload
// ./imxdownload ledc.bin /dev/sdb

// 针对SDK包的代码设计
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"

/*  IOMUXC_SetPinMux      设置IO复用功能           寄存器“IOMUXC_SW_MUX_CTL_PAD_XX” 
 *  IOMUXC_SetPinConfig   设置IO的上下拉、速度等    寄存器“IOMUXC_SW_P AD_CTL_PAD_XX”
 */

/*
 * @desciption ：使能I.MX6U所有外设时钟
 * @param      ：无
 * @return     ：无
 */
void clk_enable(void)
{
    CCM->CCGR0 = 0xffffffff;
    CCM->CCGR1 = 0xffffffff;
    CCM->CCGR2 = 0xffffffff;
    CCM->CCGR3 = 0xffffffff;
    CCM->CCGR4 = 0xffffffff;
    CCM->CCGR5 = 0xffffffff;
    CCM->CCGR6 = 0xffffffff;
}

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
 * @desciption ：打开LED
 * @param      ：无
 * @return     ：无
 */
void led_on(void)
{
    /*
     *将GPIO1_DR的bit3清零
     */
    GPIO1->DR &= ~(1<<3);
}

/*
 * @desciption ：关闭LED
 * @param      ：无
 * @return     ：无
 */
void led_off(void)
{
    /*
     *将GPIO1_DR的bit3置1
     */
    GPIO1->DR |= (1<<3);
}

/*
 * @desciption    ：短时间延时函数
 * @param   - n   ：要延时时循环次数(空操作循环次数，模式延时)
 * @return        ：无
 */
void delay_short(volatile unsigned int n)
{
    while(n--){}
}

/*
 * @desciption    ：延时函数，在Boot ROM设置的396MHz的主频下延时时间大约为1ms
 * @param   - n   ：要延时的ms数
 * @return        ：无
 */
void delay(volatile unsigned int n)
{
    while(n--){
        delay_short(0x7ff);  // 0x7ff是2047，这个时候能够实现大约1ms的延时
    }
}

/*
 * @desciption    ：main函数
 * @param   - n   ：无
 * @return        ：无
 */
int main()
{
    clk_enable(); /*使能所有的时钟*/
    led_init();   /*初始化led*/

    while(1)
    {
        led_off(); /* 关闭LED */
        delay(500);/* 延时大约500ms */

        led_on();  /* 打开LED */
        delay(500);/* 延时大约500ms */
    }

    return 0;
}