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
#include <stdio.h>
#include "AT24C02.h"
#include "hal_crc.h"

/***********************************define*************************************/

#define SOFT_TIME_SEC              59u
#define SOFT_TIME_MIN              59u
#define SOFT_TIME_HOUR             23u
#define SOFT_TIME_DAY              30u
#define SOFT_TIME_MONTH            12u
#define SOFT_TIME_YEAR             99u


static tsoft_time_t soft_time;

static tsoft_time_t soft_time_def = {    //默认2019/1/1 8:00:00
    .sec   = 0x00,
    .min   = 0x28,
    .hour  = 0x15,
    .day   = 0x1b,
    .month = 0x05,
    .year  = 0x19,
};





/**********************************Function************************************/

void RTC_IRQHandler(void)
{
    if(RTC_GetFlagStatus(RTC_FLAG_SEC))
    {
        RTC_ClearITPendingBit(RTC_IT_SEC);
        task_flag_set(TASK_RTC_SECOND_FLAG);
    }
    

}


char* format_time_string(tsoft_time_t* time)
{
    static char buffer[20]; // 缓冲区用于存储格式化后的字符串
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d %02d:%02d:%02d",
             time->year, time->month, time->day,
             time->hour, time->min, time->sec);
    return buffer;
}


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

    soft_time_check();    //上电后初始化为默认值（后续eeprom驱动完善后，更新为上次保存在eeprom的值）
    
}


void soft_time_updata(void)
{
    soft_time.sec = RTC_GetCounter();
    if(soft_time.sec > SOFT_TIME_SEC )
    {
        RTC_SetCounter(0);
        soft_time.min++;

        if(soft_time.min > SOFT_TIME_MIN )
        {
            soft_time.min = 0;
            soft_time.hour++;
            
            if(soft_time.hour > SOFT_TIME_HOUR)
            {
                soft_time.hour = 0;
                soft_time.day++;

                if(soft_time.day > SOFT_TIME_DAY)
                {
                    soft_time.day = 1;
                    soft_time.month++;

                    if(soft_time.month > SOFT_TIME_MONTH)
                    {
                        soft_time.month = 1;
                        soft_time.year++;

                        if(soft_time.year > SOFT_TIME_YEAR)
                        {
                            soft_time.year = 0;
                        }
                    }
                }
            }
        }
    }
}


void soft_time_set(tsoft_time_t time)
{
    uint8_t sec = 0;

    if(time.sec < 60 && time.min < 60 && time.hour < 24 && time.day < 31 && time.month < 13 && time.year < 100)
    {
        sec = time.sec;

        RTC_SetCounter(sec);
        time.sec = RTC_GetCounter();
        
        soft_time = time;
        
        save_soft_time(time);
    }
    else
    {
        soft_time = soft_time_def;
    }
}

void soft_time_check()
{
    tsoft_time_t time;

    
    AT24C02_Read(EE_ADDR_SOFT_TIME, (uint8_t*)&time,EE_ADDR_SOFT_TIME_SIZE);

    //如果eeprom保存的CS和实际CS不一致，并且eeprom 中读取的值是正确的，则恢复到eeprom保存的时间
    if(time.cs != get_soft_time().cs)
    {
        soft_time_set(time);
    }
    else
    {
        // no action
    }
}


char* get_soft_time_string(void)
{
    tsoft_time_t current_time = {0};
    
    current_time = get_soft_time();
    
    return format_time_string(&current_time);
}


tsoft_time_t get_soft_time()
{
    return soft_time;
}



void save_soft_time(tsoft_time_t time)
{

    time.cs = hal_crc16((uint8_t*)&time.min, 5);

    AT24C02_Write(EE_ADDR_SOFT_TIME, (uint8_t*)&time, EE_ADDR_SOFT_TIME_SIZE);
}


/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
 
