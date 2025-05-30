/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : taskschedule.h
 * Summary       : 任务调度
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/5/22      v1.0            dehongyi            first version
 ******************************************************************************/
#ifndef __TASKSCHEDULE_H
#define __TASKSCHEDULE_H
#ifdef __cplusplus
 extern "C" {
#endif
 
/***********************************include************************************/
#include "typedef.h"
/***********************************define*************************************/
#define TASK_RTC_SECOND_FLAG            0x00000001          //RTC 秒中断任务
#define TASK_RTC_MINUTE_FLAG            0x00000002          //RTC 分中断任务
#define TASK_RTC_HOUR_FLAG              0x00000004          //RTC 时中断任务
     
#define TASK_LED_FLAG                   0x00000010          //RTC *中断任务
     
/***********************************Struct*************************************/
    
/**********************************Function************************************/
void task_flag_set(uint32_t flag);          // 设置任务置位
void task_flag_clr(uint32_t flag);          // 清除任务置位
bool task_flag_get(uint32_t flag);          // 获取任务置位
void task_process();                        // 任务处理

 
#ifdef __cplusplus
}
#endif
#endif
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/