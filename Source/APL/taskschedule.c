/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : taskschedule.c
 * Summary       : 任务调度
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/5/22      v1.0            dehongyi            first version
 ******************************************************************************/
 
/***********************************include************************************/
#include "taskschedule.h"
#include "typedef.h"
#include "drv_led.h"
#include "delay.h"
#include "hal_rtc.h"
#include "lcd.h"
#include "app.h"
#include "AT24C02.h"
#include "hal_crc.h"
/***********************************define*************************************/


volatile uint32_t task_flag = 0;
static uint32_t no_task_flag = 0;
volatile uint32_t temp = 0;


/**********************************Function************************************/
void task_sec()
{
    temp++;
    
    soft_time_updata();
    LCD_ShowString(30,130,200,12,12,(uint8_t*)get_soft_time_string()); 


    if((get_soft_time().min / 59) && (get_soft_time().sec / 58))
    {
        save_soft_time(get_soft_time());
    }
    
    if (GPIO_ReadOutputDataBit(LED_RED) == Bit_RESET)
    {
        LED_RED_ON;
    }
    else
    {
        LED_RED_OFF;
    }

}

void task_min()
{
    
}




/*******************************************************************************
* @function     : void task_flag_set()
* @param        : uint32_t flag
* @return       : none
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void task_flag_set( uint32_t flag )
{
    task_flag |= flag;
}

/*******************************************************************************
* @function     : void task_flag_clr(uint32_t flag)
* @param        : uint32_t flag
* @return       : none
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void task_flag_clr(uint32_t flag)
{
    task_flag &= ~flag;
}

/*******************************************************************************
* @function     : task_flag_get()
* @param        : uint32_t flag
* @return       : void
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
bool task_flag_get( uint32_t flag )
{
    return (task_flag & flag) != 0;
}

/*******************************************************************************
* @function     : task_process()
* @param        : 
* @return       : 
* @description  : 
* @Author       : dehongyi
*******************************************************************************/
void task_process()
{
    if(task_flag_get(no_task_flag))
    {
        
        return;
    }
    //秒任务处理
    if(task_flag_get(TASK_RTC_SECOND_FLAG))
    {
        task_flag_clr(TASK_RTC_SECOND_FLAG);
        task_sec();
    }
    
    if(task_flag_get(TASK_UART_FLAG))
    {
        task_flag_clr(TASK_UART_FLAG);      
    }
}








/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
 
