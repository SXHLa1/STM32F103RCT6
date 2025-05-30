/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : hal_i2c.h
 * Summary       : 软件模拟IIC
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/5/29      v1.0            dehongyi            first version
 ******************************************************************************/
#ifndef __HAL_I2C_H
#define __HAL_I2C_H
#ifdef __cplusplus
 extern "C" {
#endif


/***********************************include************************************/
#include "hal_gpio.h"
#include "bsp_config.h"

#if HAL_I2C1
/***********************************define*************************************/
#define SDA_IN()  {GPIOC->CRH&=0XFFFF0FFF;GPIOC->CRH|=(uint32_t)8<<12;}
#define SDA_OUT() {GPIOC->CRH&=0XFFFF0FFF;GPIOC->CRH|=(uint32_t)3<<12;}

#define SDA_OUT_H               hal_gpio_set(IIC1_SDA,0x01)
#define SDA_OUT_L               hal_gpio_set(IIC1_SDA,0x00)
#define SCL_OUT_H               hal_gpio_set(IIC1_SDC,0x01)
#define SCL_OUT_L               hal_gpio_set(IIC1_SDC,0x00)

#define SDA_READ                (((IIC1_SDA_PORT->IDR & IIC1_SDA_PIN) != 0x00) ? 0x01 : 0x00)





/***********************************Struct*************************************/
    
/**********************************Function************************************/

void hal_i2c_init(void);            // IIC 初始化
void hal_i2c_start(void);           // IIC 开始信号
void hal_i2c_stop(void);            // IIC 停止信号
uint8_t hal_i2c_wait_ack(void);        // IIC 等待ack信号
void hal_i2c_ack(void);         // IIC 发送ack信号
void hal_i2c_nack(void);        // IIC 不发送ack信号
void hal_i2c_write_byte( uint8_t byte );    // IIC发送1Byte数据
uint8_t hal_i2c_read_byte( uint8_t ack );   // IIC 接收1Byte数据


#endif 
 
#ifdef __cplusplus
}
#endif
#endif
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/