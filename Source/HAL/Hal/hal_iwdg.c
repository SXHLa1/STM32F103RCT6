/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : hal_iwdg.c
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/3/13      v1.0            dehongyi            first version
 ******************************************************************************/
 
/***********************************include************************************/
#include "hal_iwdg.h"
/***********************************define*************************************/

// 喂狗时间计算公式 T = ((4× 2^prer) × rlr) / 40
#define IWDG_Clear_Time_ms      8000ul          //喂狗时间：8000ms 

#define IWDG_Prer               (uint16_t)0x05  //分频128
#define IWDG_Prer_x             128ul           //预分频系数

//Reload = WDG_Clear_Time_ms * 40 / IWDG_Prer_x
#define IWDG_Reload             (uint16_t)(IWDG_Clear_Time_ms*40ul/IWDG_Prer_x)

/**********************************Function************************************/
/*******************************************************************************
* @function     : hal_iwdg_init()
* @param        : none
* @return       : none
* @description  : 看门狗初始化函数
* @Author       : dehongyi
*******************************************************************************/
void hal_iwdg_init(void)
{
    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
    //配置分频系数
    IWDG_SetPrescaler(IWDG_Prer);
    //加载计数值
    IWDG_SetReload(IWDG_Reload);

    IWDG_ReloadCounter();

    IWDG_Enable();
}

/*******************************************************************************
* @function     : hal_iwadg_clr()
* @param        : none
* @return       : none
* @description  : 喂狗
* @Author       : dehongyi
*******************************************************************************/
void hal_iwadg_clr(void)
{
    IWDG_ReloadCounter();
}


/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
 
