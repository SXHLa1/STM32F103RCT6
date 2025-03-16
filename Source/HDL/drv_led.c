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

/***********************************define*************************************/
const LED_TypeDef LEDS[2] = {
    {"LED_READ" , .GPIOx = LED_READ_PORT ,  .pin = LED_READ_PIN  },
    {"LED_GREEN", .GPIOx = LED_GREEN_PORT , .pin = LED_GREEN_PIN },
};


/**********************************Function************************************/


/*******************************************************************************
* @function     : led_init()
* @param        : 
* @return       : 
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void led_init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD, ENABLE);
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_READ_PORT, &GPIO_InitStructure);
    GPIO_SetBits(LED_READ_PORT,LED_READ_PIN);

    GPIO_InitStructure.GPIO_Pin = LED_GREEN_PIN;
    GPIO_Init(LED_GREEN_PORT, &GPIO_InitStructure);
    GPIO_SetBits(LED_GREEN_PORT,LED_GREEN_PIN);
}


/*******************************************************************************
* @function     : LED_Control()
* @param        : 控制led开或者关
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void LED_Control(uint8_t mask)
{
    for (int i = 0; i < sizeof(LEDS)/sizeof(LEDS[0]); ++i)
    {
        if ((mask >> i) & 1)
        {
            // 打开LED灯，需要注意打开电平
            GPIO_ResetBits(LEDS[i].GPIOx, LEDS[i].pin);
        }
        else
        {
            // 关闭LED灯，需要注意关闭电平
            GPIO_SetBits(LEDS[i].GPIOx, LEDS[i].pin);
        }
    }
}



/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
 
