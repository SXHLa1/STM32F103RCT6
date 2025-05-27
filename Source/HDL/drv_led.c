/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : drv_led.c
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/3/13      v1.0            dehongyi            first version
 ******************************************************************************/
 
/***********************************include************************************/
#include "drv_led.h"
#include "hal_gpio.h"
#include "delay.h"

/***********************************define*************************************/


LED_TypeDef LEDS[2] = {
    {"LED_RED" ,  .GPIOx = LED_RED_PORT ,   .pin = LED_RED_PIN,   .state = 0x00},
    {"LED_GREEN", .GPIOx = LED_GREEN_PORT , .pin = LED_GREEN_PIN, .state = 0x00},
};

#define LED_NUMS    (sizeof(LEDS)/sizeof(LEDS[0]))
/**********************************Function************************************/



/*******************************************************************************
* @function     : led_init()
* @param        : 
* @return       : 
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void LED_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD, ENABLE);
    
    hal_gpio_init(LED_RED_PORT, LED_RED_PIN, GPIO_Mode_Out_PP, GPIO_Speed_50MHz, 0x01);
    hal_gpio_init(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_Mode_Out_PP, GPIO_Speed_50MHz, 0x01);

}


/*******************************************************************************
* @function     : LED_Control()
* @param        : 控制led开或者关
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void LED_Control(uint8_t mask)
{ 
    //操作LED
    for(int i = 0; i < LED_NUMS; ++i)
    {
        if ((mask >> i) & 1)
        {
            // 打开LED灯，需要注意打开电平
            GPIO_ResetBits(LEDS[i].GPIOx, LEDS[i].pin);
            LEDS[i].state = 0x01;
        }
        else
        {
            // 关闭LED灯，需要注意关闭电平
            GPIO_SetBits(LEDS[i].GPIOx, LEDS[i].pin);
            LEDS[i].state = 0x00;
        }
    }
}

/*******************************************************************************
* @function     : LED_Flashing()
* @param        : uint32_t delay     
* @param        : uint32_t delay1
* @return       : void
* @description  : led闪烁控制，通过输入延时时间来控制闪烁,时间单位：ms
* @Author       : dehongyi
*******************************************************************************/
void LED_Flashing(uint32_t delay,uint32_t delay1)
{
    LED_Control(LED_RED_OFF_GREEN_ON);
    delay_ms(delay);
    LED_Control(LED_RED_ON_GREEN_OFF);
    delay_ms(delay1);
}




/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
