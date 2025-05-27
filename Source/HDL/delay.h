/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : delay.h
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/3/17      v1.0            dehongyi            first version
 ******************************************************************************/
#ifndef __DELAY_H
#define __DELAY_H
#ifdef __cplusplus
 extern "C" {
#endif
 
/***********************************include************************************/
#include "stm32f10x.h"
/***********************************define*************************************/
  
/***********************************Struct*************************************/
    
/**********************************Function************************************/
void delay_init(void);              //延时初始化函数 
void delay_us(uint32_t us);         //微秒延时函数
void delay_ms( uint32_t ms );       //毫秒延时函数
 
#ifdef __cplusplus
}
#endif
#endif
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/