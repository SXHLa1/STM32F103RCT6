/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : delay.c
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/3/17      v1.0            dehongyi            first version
 ******************************************************************************/
 
/***********************************include************************************/
#include "delay.h"
#include "core_cm3.h"
/***********************************define*************************************/


/**********************************Function************************************/
/*******************************************************************************
* @function     : delay_init()
* @param        : 
* @return       : 
* @description  : 延时初始化函数
* @Author       : dehongyi
*******************************************************************************/
void delay_init(void)
{
        SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
}


/*******************************************************************************
* @function     : delay_us()
* @param        : uint32_t us
* @return       : void
* @description  : 微秒延时函数
* @Author       : dehongyi
*******************************************************************************/
void delay_us(uint32_t us)
{
    SysTick->LOAD = (uint32_t)(SystemCoreClock / 10000000L * us);   // Set reload register to count down in microseconds
    NVIC_EnableIRQ(SysTick_IRQn);      // Enable SysTick IRQ
    SysTick->VAL = 0;                  // Reload the counter with new value (clear it)
    SysTick->CTRL = SysTick_CTRL_ENABLE | SysTick_CTRL_CLKSOURCE;   // Enable SysTick IRQ and select its source clock
                                                                      // Note that using HAL library, the below line can be replaced by:
                                                                      //HAL_SYSTICK_Config(SystemCoreClock / 1000000L);
    while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG) == 0);   

}


/*******************************************************************************
* @function     : delay_ms()
* @param        : uint32_t ms
* @return       : void
* @description  : 毫秒延时函数
* @Author       : dehongyi
*******************************************************************************/
void delay_ms( uint32_t ms )
{
    uint32_t i;
    for(i = 0;i < ms;i++) delay_us(1000);
}









/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
 
