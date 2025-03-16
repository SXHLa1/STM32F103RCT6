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

    GPIO_InitStructure.GPIO_Pin = LED_GRREN_PIN;
    GPIO_Init(LED_GRREN_PORT, &GPIO_InitStructure);
    GPIO_SetBits(LED_GRREN_PORT,LED_GRREN_PIN);
}


/*******************************************************************************
* @function     : led_ctrl()
* @param1       : bool ledctrl 控制led开或者关
* @param2       : uint8_t ledtype   选择需要控制的led
* @return       : ture/false
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
bool led_ctrl( bool ledctrl, LED_TypeDef ledtype )
{
    
    if( ledctrl != false )
    {
        
    }
    else
    {
        
    }
    
    return true;
}


/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
 
