/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : app.c
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/3/13      v1.0            dehongyi            first version
 ******************************************************************************/
 
/***********************************include************************************/
#include "app.h"
#include "drv_led.h"
#include "hal_iwdg.h"
#include "delay.h"
#include "taskschedule.h"
#include "hal_rcc.h"
#include "hal_rtc.h"
#include "hal_gpio.h"
/***********************************define*************************************/
 
/**********************************Function************************************/
void app_init(void)
{
    SystemClock_Config();
    hal_rtc_init();
    delay_init();
    LED_Init();
    hal_iwdg_init();
    LED_Flashing(200,200);
    hal_gpio_init(GPIOA, GPIO_Pin_15, GPIO_Mode_Out_PP, GPIO_Speed_50MHz,0x01);
}

void app_run(void)
{
    while(1)
    {
        hal_iwadg_clr();
        task_process();
    }

}
 
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
 
