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
 
/***********************************define*************************************/
  
/***********************************Struct*************************************/
    
/**********************************Function************************************/
void hal_rtc_init();        //RTC初始化
void updata_time(void); //更新时间，万年历


 
#ifdef __cplusplus
}
#endif
#endif
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/