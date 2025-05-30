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







//IO¿Ú²Ù×÷ºê¶¨Òå
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
//IO¿ÚµØÖ·Ó³Éä
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C 
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C 
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C 
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C 
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C 
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C    
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C    

#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808 
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08 
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008 
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408 
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808 
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08 
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08 
 
//IO¿Ú²Ù×÷,Ö»¶Ôµ¥Ò»µÄIO¿Ú!
//È·±£nµÄÖµÐ¡ÓÚ16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //Êä³ö 
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //ÊäÈë 

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //Êä³ö 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //ÊäÈë 

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //Êä³ö 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //ÊäÈë 

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //Êä³ö 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //ÊäÈë 

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //Êä³ö 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //ÊäÈë

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //Êä³ö 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //ÊäÈë

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //Êä³ö 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //ÊäÈë


/***********************************Struct*************************************/
    
/**********************************Function************************************/
 
 
 
#ifdef __cplusplus
}
#endif
#endif
/******************* (C) COPYRIGHT 2034 dehongyi ******END OF FILE*************/
