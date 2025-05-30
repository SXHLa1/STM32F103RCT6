/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : hal_gpio.c
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/3/13      v1.0            dehongyi            first version
 ******************************************************************************/
 
/***********************************include************************************/
#include "hal_gpio.h"
#include "bsp_config.h"
/***********************************define*************************************/
 
/**********************************Function************************************/


void hal_gpio_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed, uint8_t output)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    
    GPIO_InitStructure.GPIO_Mode = mode;
    GPIO_InitStructure.GPIO_Speed = speed;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
    
    GPIO_Init(GPIOx, &GPIO_InitStructure);

    if( output == 0x00 )
    {
        GPIOx->BRR = GPIO_Pin;
    }
    else
    {
        GPIOx->BSRR = GPIO_Pin;
    }
}


void hal_gpio_set(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t output)
{
    if( output == 0x00 )
    {
        GPIOx->BRR = GPIO_Pin;
    }
    else
    {
        GPIOx->BSRR = GPIO_Pin;
    }
}

uint8_t hal_gpio_get(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
    return ((GPIOx->IDR & GPIO_Pin) != 0x00) ? 0x01 : 0x00;
}



/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
 
