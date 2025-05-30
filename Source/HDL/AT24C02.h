/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : AT24C02.h
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/5/29      v1.0            dehongyi            first version
 ******************************************************************************/
#ifndef __AT24C02_H
#define __AT24C02_H
#ifdef __cplusplus
 extern "C" {
#endif
 
/***********************************include************************************/
#include "hal_i2c.h"
#include "delay.h"
/***********************************define*************************************/

#define EE_ADDR                     0x00

#define EE_ADDR_VER                 EE_ADDR
#define EE_ADDR_VER_SIZE            0x02

#define EE_ADDR_SOFT_TIME           (EE_ADDR + EE_ADDR_VER_SIZE)
#define EE_ADDR_SOFT_TIME_SIZE      0x08




/***********************************Struct*************************************/
    
/**********************************Function************************************/
void AT24C02_Init(void);
uint8_t AT24C02_ReadByte( uint16_t addr );
void AT24C02_WriteByte( uint16_t addr, uint8_t data );
void AT24C02_Read( uint16_t addr, uint8_t *buf, uint16_t len );
void AT24C02_Write( uint16_t addr, uint8_t *buf, uint16_t len );
 
 
#ifdef __cplusplus
}
#endif
#endif
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/