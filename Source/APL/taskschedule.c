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
/***********************************define*************************************/


volatile uint32_t task_flag = 0;
static uint32_t no_task_flag = 0;
volatile uint32_t temp = 0;

/**********************************Function************************************/
void task_sec()
{

    if (GPIO_ReadOutputDataBit(LED_RED) == Bit_RESET)
    {
        
        LED_Control(0x00);
    }
    else
    {
        LED_Control(LED_RED_ON);
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
    
    if(task_flag_get(TASK_RTC_SECOND_FLAG))
    {
        task_flag_clr(TASK_RTC_SECOND_FLAG);
        task_sec();
    }
    if(task_flag_get(TASK_LED_FLAG))
    {
        task_flag_clr(TASK_LED_FLAG);
        led_task();
    }
}








/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
 
