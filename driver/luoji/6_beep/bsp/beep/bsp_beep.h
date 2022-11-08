/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-11-06 23:07:34
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-11-06 23:08:45
 * @FilePath: /linux/driver/luoji/6_beep/bsp/beep/beep.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __BSP_BEEP_H
#define __BSP_BEEP_H

#include "imx6ul.h"

void beep_init(void);
void beep_switch(int status);

#endif