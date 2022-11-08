/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-11-07 00:23:47
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-11-07 23:22:00
 * @FilePath: /linux/driver/luoji/7_key/bsp/gpio/bsp_gpio.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef _BSP_KEY_H
#define _BSP_KEY_H

#include "imx6ul.h"
/* 定义按键值 */
enum keyvalue{
    KEY_NONE = 0,
    KEY0_VALUE,       //ALPHA开发板上面只有一个按键功能
};

/* 函数声明 */
void key_init(void);
int  key_getvalue(void);
#endif