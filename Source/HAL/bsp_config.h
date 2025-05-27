/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : bsp_config.h
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/3/16      v1.0            dehongyi            first version
 ******************************************************************************/
#ifndef __BSP_CONFIG_H
#define __BSP_CONFIG_H
#ifdef __cplusplus
 extern "C" {
#endif
 
/***********************************include************************************/
#include "stm32f10x.h"
/***********************************define*************************************/

/**********************************GPIO define*********************************/
/**********************************LED define**********************************/
#define LED_RED_PORT                            GPIOA
#define LED_RED_PIN                             GPIO_Pin_8
#define LED_RED                                 GPIOA,GPIO_Pin_8

#define LED_GREEN_PORT                          GPIOD
#define LED_GREEN_PIN                           GPIO_Pin_2
#define LED_GREEN                               GPIOD,GPIO_Pin_2

/**********************************UART define*********************************/






/***********************************Struct*************************************/
    
/**********************************Function************************************/
 
 
 
#ifdef __cplusplus
}
#endif
#endif
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/