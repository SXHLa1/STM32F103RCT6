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
#define LED_RED_OFF                     GPIO_ResetBits(LED_RED)        //关闭红色LED灯
#define LED_RED_ON                      GPIO_SetBits(LED_RED)          //打开红色LED灯

#define LED_GREEN_OFF                   GPIO_ResetBits(LED_GREEN)      //关闭绿色LED灯
#define LED_GREEN_ON                    GPIO_SetBits(LED_GREEN)        //打开绿色LED灯

#define LED_RED_ON_GREEN_OFF            0x01        //关闭绿色LED灯，打开红色LED灯
#define LED_RED_OFF_GREEN_ON            0x02        //关闭红色LED灯，打开绿色LED灯
     
#define LED_ALL_OFF                     0x00        //关闭所有LED灯
#define LED_ALL_ON                      0xFF        //打开所有LED灯

/***********************************Struct*************************************/
typedef struct {
    char* name;
    GPIO_TypeDef* GPIOx;
    uint16_t pin;
    uint8_t state;  //led 状态0x00：关，0x01：开
} LED_TypeDef;


/**********************************Function************************************/
void LED_Init(void);                    //led 初始化函数
void LED_Control(uint8_t mask);         //led 开/关控制函数
void LED_Flashing(uint32_t delay_ms,uint32_t delay_ms1);  //led 闪烁函数

 
#ifdef __cplusplus
}
#endif
#endif
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/