/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : hal_uart.c
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/3/13      v1.0            dehongyi            first version
 ******************************************************************************/
 
/***********************************include************************************/
#include "hal_uart.h"
#include "hal_gpio.h"
#include "bsp_config.h"
#include "taskschedule.h"
#include <string.h>

/***********************************define*************************************/
 
#define RX_BUFFER_MAX           255
uint8_t rx_buffer[RX_BUFFER_MAX];
static uint8_t buf_size = 0;
/**********************************Function************************************/


void USART1_IRQHandler(void)
{
    if(USART_GetITStatus(USART1, USART_IT_RXNE))
    {
        __disable_irq();
        rx_buffer[buf_size++] = USART1->DR;

        if(buf_size >= RX_BUFFER_MAX)
        {
            buf_size = 0;
            memset(rx_buffer,0,RX_BUFFER_MAX);
        }
        __enable_irq();
    }
    if(USART_GetITStatus(USART1, USART_IT_IDLE))
    {
        USART1->SR = 0;
        
        task_flag_set(TASK_UART_FLAG);
    }
}







/*******************************************************************************
* @function     : hal_uart_init()
* @param        : 
* @return       : 
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void hal_uart_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    USART_InitTypeDef USART_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;

    //使能Uart1 GPIO口时钟和Uart1时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);


    GPIO_InitStruct.GPIO_Pin = UART1_TX_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(UART1_TX_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin = UART1_RX_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(UART1_RX_PORT, &GPIO_InitStruct);


    USART_InitStruct.USART_BaudRate = 9600;
    USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;
    USART_InitStruct.USART_Parity = USART_Parity_No;
    USART_InitStruct.USART_StopBits = USART_StopBits_1;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Init(USART1, &USART_InitStruct);


    NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 3;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);

    USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
    USART_Cmd(USART1, ENABLE);

}


/*******************************************************************************
* @function     : hal_uart_send()
* @param        : uint8_t *buf
* @return       : void
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void hal_uart_send( uint8_t *buf, uint8_t len)
{
    while(len--)
    {
        USART1->DR = *buf;
        buf++;
    }
}


/*******************************************************************************
* @function     : hal_uart_read()
* @param        : uint8_t *buf
* @return       : void
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void hal_uart_read( uint8_t *buf)
{
    
}







/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
