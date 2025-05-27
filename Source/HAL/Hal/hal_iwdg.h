/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : hal_iwdg.h
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/3/16      v1.0            dehongyi            first version
 ******************************************************************************/
#ifndef __HAL_IWDG_H
#define __HAL_IWDG_H
#ifdef __cplusplus
 extern "C" {
#endif
 
/***********************************include************************************/
#include "stm32f10x_iwdg.h"
/***********************************define*************************************/
  
/***********************************Struct*************************************/
    
/**********************************Function************************************/
void hal_iwdg_init(void);
void hal_iwadg_clr(void);
 
 
#ifdef __cplusplus
}
#endif
#endif
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/