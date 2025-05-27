/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : hal_rtc.c
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/3/13      v1.0            dehongyi            first version
 ******************************************************************************/
 
/***********************************include************************************/
#include "hal_rtc.h"
#include "stm32f10x.h"
#include "typedef.h"
#include "stm32f10x_rtc.h"
#include "taskschedule.h"

/***********************************define*************************************/


typedef struct{
    uint8_t sec;
    uint8_t min;
    uint8_t hour;
}time;

/**********************************Function************************************/
void hal_rtc_init()
{
    NVIC_InitTypeDef NVIC_InitStructure;
    
    // 1. 使能 PWR 和 BKP 外设时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);

    // 2. 允许访问备份寄存器 (Backup Domain)
    PWR_BackupAccessCmd(ENABLE); 

    RCC_LSEConfig(RCC_LSE_ON);
    
    RCC_RTCCLKCmd(ENABLE);
    RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
    
    RTC_WaitForSynchro();
    RTC_WaitForLastTask();

    
    NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    // 使能秒中断
    RTC_ITConfig(RTC_IT_SEC,  ENABLE);
    RTC_WaitForLastTask();

    RTC_SetPrescaler(0x7FFF);   //32.768KHz   1s触发一次中断
    RTC_WaitForLastTask();

    BKP_WriteBackupRegister(BKP_DR1, 0x32F2);    // 写入 backup register，以标记 RTC 配置完成
}

void RTC_IRQHandler(void)
{
    if(RTC_GetFlagStatus(RTC_FLAG_SEC))
    {
        RTC_ClearITPendingBit(RTC_IT_SEC);
        task_flag_set(TASK_RTC_SECOND_FLAG);
    }
    

}






/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
 
