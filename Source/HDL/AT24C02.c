/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : AT24C02.c
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/5/29      v1.0            dehongyi            first version
 ******************************************************************************/
 
/***********************************include************************************/
#include "AT24C02.h"
#include "hal_i2c.h"
/***********************************define*************************************/

/**********************************Function************************************/

/*******************************************************************************
* @function     : AT24C02_Init()
* @param        : 
* @return       : 
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void AT24C02_Init(void)
{
#if HAL_I2C1
    hal_i2c_init();
#else
    IIC_Init();
#endif
}

/*******************************************************************************
* @function     : AT24C02_ReadByte()
* @param        : uint16_t addr
* @return       : 
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
uint8_t AT24C02_ReadByte( uint16_t addr )
{
#if HAL_I2C1
    uint8_t temp=0;
    hal_i2c_start();  
    
    hal_i2c_write_byte(0xA0);
    hal_i2c_wait_ack();
    
    hal_i2c_write_byte(addr);
    hal_i2c_wait_ack();
    
    hal_i2c_start();
    hal_i2c_write_byte(0xA1);
    hal_i2c_wait_ack();
    
    temp = hal_i2c_read_byte(0);
    hal_i2c_stop();
    return temp;
#endif
}

/*******************************************************************************
* @function     : AT24C02_WriteByte()
* @param        : uint16_t addr, uint8_t data
* @return       : void
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void AT24C02_WriteByte( uint16_t addr, uint8_t data )
{
#if HAL_I2C1
    hal_i2c_start();
    
    hal_i2c_write_byte(0xA0); 
    hal_i2c_wait_ack();
    
    hal_i2c_write_byte(addr);
    hal_i2c_wait_ack();
    
    hal_i2c_write_byte(data);
    hal_i2c_wait_ack();
    
    hal_i2c_stop();
    delay_ms(5);
#endif
}

/*******************************************************************************
* @function     : AT24C02_Read()
* @param        : uint16_t addr, uint8_t *buf, uint16_t len
* @return       : void
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void AT24C02_Read( uint16_t addr, uint8_t *buf, uint16_t len )
{
    while(len)
    {
        *buf++=AT24C02_ReadByte(addr++);	
        len--;
    }
}

/*******************************************************************************
* @function     : AT24C02_Write()
* @param        : uint16_t addr, uint8_t *buf, uint16_t len
* @return       : void
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void AT24C02_Write( uint16_t addr, uint8_t *buf, uint16_t len )
{
    while(len--)
    {
        AT24C02_WriteByte(addr,*buf);
        addr++;
        buf++;
    } 
}










/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/