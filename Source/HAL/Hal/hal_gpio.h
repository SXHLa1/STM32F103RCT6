/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : hal_gpio.h
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/3/16      v1.0            dehongyi            first version
 ******************************************************************************/
#ifndef __HAL_GPIO_H
#define __HAL_GPIO_H
#ifdef __cplusplus
 extern "C" {
#endif
 
/***********************************include************************************/
#include <stdint.h>
#include <stdio.h>
#include "stm32f10x.h"
/***********************************define*************************************/
  
/***********************************Struct*************************************/
    
/**********************************Function************************************/
void hal_gpio_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed, uint8_t output);




#ifdef __cplusplus
}
#endif
#endif
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/