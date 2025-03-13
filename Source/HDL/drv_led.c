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
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_SetBits(GPIOA,GPIO_Pin_8);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_SetBits(GPIOD,GPIO_Pin_2);
}


/*******************************************************************************
* @function     : led_ctrl()
* @param1       : bool ledctrl 控制led开或者关
* @param2       : uint8_t ledtype   选择需要控制的led
* @return       : ture/false
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
bool led_ctrl( bool ledctrl, uint8_t ledtype )
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
 
