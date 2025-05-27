/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : hal_rcc.c
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/5/8      v1.0            dehongyi            first version
 ******************************************************************************/
 
/***********************************include************************************/
#include "hal_rcc.h" 
#include "stm32f10x_rcc.h"
/***********************************define*************************************/
 
/**********************************Function************************************/

void SystemClock_Config()
{
    /*RCC_APB1PeriphClockCmd( RCC_APB1Periph_PWR, ENABLE);

    PWR_BackupAccessCmd(ENABLE);

    if(RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET)
    {
        RCC_HSEConfig(RCC_HSE_ON);
    }

    RCC_PLLConfig( RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);   //PLL *9, 72MHz

    RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE);  //启用 PLL时钟
    
    RCC_HCLKConfig(RCC_SYSCLK_Div1);
    RCC_PCLK1Config(RCC_HCLK_Div2);
    RCC_PCLK2Config(RCC_HCLK_Div1);*/

    
}




 
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
 
