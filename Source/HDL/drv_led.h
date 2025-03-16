/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : drv_led.h
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/3/13      v1.0            dehongyi            first version
 ******************************************************************************/
#ifndef __DRV_LED_H
#define __DRV_LED_H
#ifdef __cplusplus
 extern "C" {
#endif
 
/***********************************include************************************/
#include <stdint.h>
#include <stdio.h>
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "typedef.h"
#include "bsp_config.h"
/***********************************define*************************************/
  
/***********************************Struct*************************************/
typedef enum
{
    READ  = 0x00,
    GRREN = 0x01
}LED_TypeDef;

/**********************************Function************************************/
void led_init(void);
bool led_ctrl(bool ledctrl, LED_TypeDef lednum);
 
#ifdef __cplusplus
}
#endif
#endif
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/