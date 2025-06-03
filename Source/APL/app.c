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
#include "lcd.h"
#include "hal_i2c.h"
#include "AT24C02.h"
#include "hal_uart.h"
/***********************************define*************************************/
const uint8_t TEXT_Buffer[]={"V1"};
#define SIZE sizeof(TEXT_Buffer)
uint8_t datatemp[SIZE]; 


/**********************************Function************************************/

void app_init(void)
{
    SystemClock_Config();
    
    AT24C02_Init();

    delay_init();
    LED_Init();
    hal_uart_init();

    LCD_Init();
    hal_rtc_init();
    hal_iwdg_init();
    LED_Flashing(200,200);
            
    POINT_COLOR=RED;	
    
    
    
    LCD_ShowString(30,170,200,16,16,"Start Read 24C02.... ");
    AT24C02_Read(0,datatemp,SIZE);
    LCD_ShowString(30,170,200,16,16,"The Data Readed Is:  ");
    LCD_ShowString(30,190,200,16,16,datatemp);
    
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
 
