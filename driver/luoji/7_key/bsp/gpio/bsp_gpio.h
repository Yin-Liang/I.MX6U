#ifndef _BSP_GPIO_H
#define _BSP_GPIO_H

#include "imx6ul.h"
/* 枚举类型和结构体定义 */
typedef enum _gpio_pin_direction
{
    kGPIO_DigitalInput  = 0u, /* 输入 */
    kGPIO_DigitalOutput = 1u, /* 输出 */
}gpio_pin_direction_t;


/* GPIO配置结构体 */
typedef struct _gpio_pin_config
{
    gpio_pin_direction_t  direction;  /* GPIO方向：输入还是输出 */
    uint8_t  outputLogic;             /* 如果是输出的话，默认输出电平*/
}gpio_pin_config_t;

/* 函数声明 */
void gpio_init(GPIO_Type *base, int pin, gpio_pin_config_t *config);
int  gpio_pinread(GPIO_Type *base, int pin);
void gpio_pinwrite(GPIO_Type *base, int pin, int value);

#endif