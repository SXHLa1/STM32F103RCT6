/************************* (C) COPYRIGHT dehongyi @2034 *************************
 * File          : bsp_config.h
 * Summary       : 
 * Platform      : 
 * Author        : dehongyi
 * Change Logs   :
 * Date            Version         Author          Notes
 * 2025/3/16      v1.0            dehongyi            first version
 ******************************************************************************/
#ifndef __BSP_CONFIG_H
#define __BSP_CONFIG_H
#ifdef __cplusplus
 extern "C" {
#endif
 
/***********************************include************************************/
#include "stm32f10x.h"
/***********************************define*************************************/
#define HAL_I2C1                    0x01




/**********************************GPIO define*********************************/

/**********************************LED define**********************************/
#define LED_RED                                 GPIOA,GPIO_Pin_8
#define LED_RED_PORT                            GPIOA
#define LED_RED_PIN                             GPIO_Pin_8

#define LED_GREEN                               GPIOD,GPIO_Pin_2
#define LED_GREEN_PORT                          GPIOD
#define LED_GREEN_PIN                           GPIO_Pin_2

/**********************************UART define*********************************/
#define UART1_RX                                GPIOA,GPIO_Pin_10
#define UART1_RX_PORT                           GPIOA
#define UART1_RX_PIN                            GPIO_Pin_10

#define UART1_TX                                GPIOA,GPIO_Pin_9
#define UART1_TX_PORT                           GPIOA
#define UART1_TX_PIN                            GPIO_Pin_9

/**********************************SPI1 define*********************************/
#define SPI1_CS                                 GPIOA,GPIO_Pin_2
#define SPI1_SCK                                GPIOA,GPIO_Pin_5
#define SPI1_SPI1_MISO                          GPIOA,GPIO_Pin_6
#define SPI1_SPI1_MOSI                          GPIOA,GPIO_Pin_7

/**********************************IIC define**********************************/
#define IIC1_SDA                                GPIOC,GPIO_Pin_11
#define IIC1_SDA_PORT                           GPIOC
#define IIC1_SDA_PIN                            GPIO_Pin_11

#define IIC1_SDC                                GPIOC,GPIO_Pin_12
#define IIC1_SDC_PORT                           GPIOC
#define IIC1_SDC_PIN                            GPIO_Pin_12


/**********************************LED define**********************************/
#define LCD_D0                                  GPIOB,GPIO_Pin_0
#define LCD_D1                                  GPIOB,GPIO_Pin_1
#define LCD_D2                                  GPIOB,GPIO_Pin_2
#define LCD_D3                                  GPIOB,GPIO_Pin_3
#define LCD_D4                                  GPIOB,GPIO_Pin_4
#define LCD_D5                                  GPIOB,GPIO_Pin_5
#define LCD_D6                                  GPIOB,GPIO_Pin_6
#define LCD_D7                                  GPIOB,GPIO_Pin_7
#define LCD_D8                                  GPIOB,GPIO_Pin_8
#define LCD_D9                                  GPIOB,GPIO_Pin_9
#define LCD_D10                                 GPIOB,GPIO_Pin_10
#define LCD_D11                                 GPIOB,GPIO_Pin_11
#define LCD_D12                                 GPIOB,GPIO_Pin_12
#define LCD_D13                                 GPIOB,GPIO_Pin_13
#define LCD_D14                                 GPIOB,GPIO_Pin_14
#define LCD_D15                                 GPIOB,GPIO_Pin_15
#define LCD_RD                                  GPIOC,GPIO_Pin_6
#define LCD_WR                                  GPIOC,GPIO_Pin_7
#define LCD_RS                                  GPIOC,GPIO_Pin_8
#define LCD_CS                                  GPIOC,GPIO_Pin_9
#define LCD_BL                                  GPIOC,GPIO_Pin_10

//触摸屏
#define T_SCK                                   GPIOC,GPIO_Pin_0
#define T_PEN                                   GPIOC,GPIO_Pin_1
#define T_MISO                                  GPIOC,GPIO_Pin_2
#define T_MOSI                                  GPIOC,GPIO_Pin_3
#define T_CS                                    GPIOC,GPIO_Pin_13

/*********************************Debug define*********************************/
#define DEBUG_SWDIO                             GPIOA,GPIO_Pin_13
#define DEBUG_SWDCLK                            GPIOA,GPIO_Pin_14
#define DEBUG_JTDI                              GPIOA,GPIO_Pin_15
#define DEBUG_JTDO                              GPIOB,GPIO_Pin_3
#define DEBUG_JTRST                             GPIOB,GPIO_Pin_4



/***********************************Struct*************************************/
    
/**********************************Function************************************/
 
 
 
#ifdef __cplusplus
}
#endif
#endif
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
