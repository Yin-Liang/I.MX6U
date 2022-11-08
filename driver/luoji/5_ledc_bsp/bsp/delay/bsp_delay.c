
#include "bsp_delay.h"

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
