/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : hal_i2c.c
 * Summary       : 软件模拟IIC
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/5/29      v1.0            dehongyi            first version
 ******************************************************************************/

/***********************************include************************************/
#include "hal_i2c.h" 
#include "delay.h"

#if HAL_I2C1
/***********************************define*************************************/

/**********************************Function************************************/

/*******************************************************************************
* @function     : hal_i2c_init()
* @param        : 
* @return       : 
* @description  : IIC 初始化
* @Author       : dehongyi
*******************************************************************************/
void hal_i2c_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE );

    GPIO_InitStruct.GPIO_Pin = IIC1_SDA_PIN|IIC1_SDC_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(IIC1_SDA_PORT, &GPIO_InitStruct);

    SDA_OUT_H;
    SCL_OUT_H;
}

/*******************************************************************************
* @function     : hal_i2c_start()
* @param        : 
* @return       : 
* @description  : IIC 开始信号
* @Author       : dehongyi
*******************************************************************************/
void hal_i2c_start(void)
{
    // 时钟保持高电平，数据由高到底
    SDA_OUT();

    SDA_OUT_H;
    SCL_OUT_H;

    delay_us(4);
    
    SDA_OUT_L;
    delay_us(4);
    SCL_OUT_L;
}

/*******************************************************************************
* @function     : hal_i2c_stop()
* @param        : 
* @return       : 
* @description  : IIC 停止信号
* @Author       : dehongyi
*******************************************************************************/
void hal_i2c_stop(void)
{
    // 时钟保持高电平，数据由低到高
    SDA_OUT();
    
    SCL_OUT_L;
    SDA_OUT_L;
    delay_us(4);
    
    SCL_OUT_H;
    SDA_OUT_H;
    delay_us(4);
}

/*******************************************************************************
* @function     : hal_i2c_wait_ack()
* @param        : 
* @return       : bool
* @description  : IIC  等待ack
* @Author       : dehongyi
*******************************************************************************/
uint8_t hal_i2c_wait_ack(void)
{
    u8 ucErrTime=0;
    SDA_IN();
    
    SDA_OUT_H;
    delay_us(2);
    SCL_OUT_H;
    delay_us(2);
    
    while(SDA_READ)
    {
        ucErrTime++;
        if(ucErrTime>250)
        {
            hal_i2c_stop();
            return 1;
        }
    }
    SCL_OUT_L;
    return 0;
}

/*******************************************************************************
* @function     : hal_i2c_ack()
* @param        : 
* @return       : 
* @description  : IIC ACk信号
* @Author       : dehongyi
*******************************************************************************/
void hal_i2c_ack(void)
{
    SCL_OUT_L;
    SDA_OUT();
    
    SDA_OUT_L;
    delay_us(2);
    
    SCL_OUT_H;
    delay_us(2);
    SCL_OUT_L;
}



/*******************************************************************************
* @function     : hal_i2c_nack()
* @param        : 
* @return       : 
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void hal_i2c_nack(void)
{
    SCL_OUT_L;
    
    SDA_OUT();
    
    SDA_OUT_H;
    delay_us(2);
    SCL_OUT_H;
    delay_us(2);
    SCL_OUT_L;
}

/*******************************************************************************
* @function     : hal_i2c_write_byte()
* @param        : uint8_t byte
* @return       : void
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void hal_i2c_write_byte( uint8_t byte )
{
    SDA_OUT();
    
    SCL_OUT_L;
    for (uint8_t i = 0; i < 8; i++)
    {
        // 发送高位先
        if ( (byte & 0x80) << i)
            SDA_OUT_H;
        else
            SDA_OUT_L;
        byte <<= 1;
        delay_us(2);
        SCL_OUT_H; delay_us(2);   // 写入时钟脉冲，应答发生在SCL下降沿
        SCL_OUT_L; delay_us(2);
    }
}


/*******************************************************************************
* @function     : hal_i2c_read_byte()
* @param        : uint8_t ack
* @return       : uint8_t
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
uint8_t hal_i2c_read_byte( uint8_t ack )
{
    uint8_t receivedData = 0;
    SDA_OUT_L;
    SDA_IN();                // 设置为输入模式接收数据
    // 读入8位数据，最高有效位(MSB)先
    for (uint8_t i = 0; i < 8; i++)
    {
        SCL_OUT_L;
        delay_us(2);   // 唤醒SCL以让从设备输出数据

        SCL_OUT_H;
        delay_us(2);
        
        receivedData <<= 1;
        if(SDA_READ) receivedData++;
        delay_us(2);
    }
    if (!ack)
    {
        hal_i2c_nack();
    }
    else
    {
        hal_i2c_ack();
    }
    return receivedData;
}


#endif
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
