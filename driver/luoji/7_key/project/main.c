/*
 * @Author: error: git config user.name && git config user.email & please set dead value or install git
 * @Date: 2022-11-06 23:06:13
 * @LastEditors: error: git config user.name && git config user.email & please set dead value or install git
 * @LastEditTime: 2022-11-08 04:22:09
 * @FilePath: /linux/driver/luoji/6_beep/project/main.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// chmod 777 imxdownload
// ./imxdownload key.bin /dev/sdb

// 针对SDK包的代码设计
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"

/*
 * @desciption    ：main函数
 * @param   - n   ：无
 * @return        ：无
 */
int main(void)
{
    int i = 0;
    int keyvalue = 0;
    unsigned char led_state = OFF;
    unsigned char beep_state = OFF;
    clk_enable(); /*使能所有的时钟*/
    led_init();   /*初始化led*/
    beep_init();  /*初始化beep*/
    key_init();

    while(1)
    {
        keyvalue = key_getvalue();
        if(keyvalue) 
        {
            switch(keyvalue)
            {
              case KEY0_VALUE:
                beep_state = !beep_state;
                beep_switch(beep_state);  
                break;
            }
        }
        i++;
        if(i == 50) 
        {
            i = 0;
            led_state = !led_state;
            led_switch(LED0, led_state);
        }
        delay(10);
    }
    return 0;

}