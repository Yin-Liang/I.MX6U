#include "bsp_gpio.h"

void gpio_init(GPIO_Type *base, int pin, gpio_pin_config_t *config)
{
    if(config->direction == kGPIO_DigitalInput) /*输入 */
    {
        base->GDIR &= ~(1<<pin);
    }
    else
    {
        base->GDIR |= 1<<pin;                 /*输出 */
        gpio_pinwrite(base, pin, config->outputLogic);
    }
}


int gpio_pinread(GPIO_Type *base, int pin)
{
    return ((base->DR)>>pin) & 0x1;
}


void gpio_pinwrite(GPIO_Type *base, int pin, int value)
{
    if(value == 0U)
    {
        base->DR &= ~(1U << pin); /*输出低电平*/
    }
    else 
    {
        base->DR |= (1U << pin); /*输出高电平*/
    }
}

/*
        base: 要初始化的 GPIO所属于的 GPIO组，比如 GPIO1_IO18就属于 GPIO1组。 
        pin：要初始化 GPIO在组内的标号，比如 GPIO1_IO18在组内的编号就是 18。 
        config: 要初始化的 GPIO配置结构体，用来指定 GPIO配置为输出还是输入。 
 */