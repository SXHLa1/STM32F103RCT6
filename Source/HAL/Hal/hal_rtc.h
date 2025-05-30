/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : hal_rtc.h
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/3/16      v1.0            dehongyi            first version
 ******************************************************************************/
#ifndef __HAL_RTC_H
#define __HAL_RTC_H
#ifdef __cplusplus
 extern "C" {
#endif
 
/***********************************include************************************/
#include "typedef.h"
/***********************************define*************************************/
  
/***********************************Struct*************************************/
     
typedef struct{
    uint16_t cs;
    uint8_t sec;
    uint8_t min;
    uint8_t hour;
    uint8_t day;
    uint8_t month;
    uint8_t year;
}tsoft_time_t;
     
/**********************************Function************************************/
void hal_rtc_init();        //RTC初始化
void soft_time_updata(void); //更新时间，万年历
char* get_soft_time_string(void);
tsoft_time_t get_soft_time();
void save_soft_time(tsoft_time_t time);
void soft_time_check();

 
#ifdef __cplusplus
}
#endif
#endif
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/