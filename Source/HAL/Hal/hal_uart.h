/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : hal_uart.h
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/3/16      v1.0            dehongyi            first version
 ******************************************************************************/
#ifndef __HAL_UART_H
#define __HAL_UART_H
#ifdef __cplusplus
 extern "C" {
#endif
 
/***********************************include************************************/
#include "typedef.h" 
/***********************************define*************************************/
  
/***********************************Struct*************************************/
    
/**********************************Function************************************/

void hal_uart_init(void);
void hal_uart_send( uint8_t *buf, uint8_t len);
void hal_uart_read( uint8_t *buf);
 
 
#ifdef __cplusplus
}
#endif
#endif
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/