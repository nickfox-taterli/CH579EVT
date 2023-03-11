/********************************** (C) COPYRIGHT *******************************
 * File Name          : LED.h
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2016/04/12
 * Description        : 
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/



/******************************************************************************/
#ifndef __LED_H
#define __LED_H

#ifdef __cplusplus
extern "C"
{
#endif

  
/*********************************************************************
 * CONSTANTS
 */

/* LEDS - The LED number is the same as the bit position */
#define HAL_LED_1     0x01
#define HAL_LED_2     0x02
#define HAL_LED_3     0x04
#define HAL_LED_4     0x08
#define HAL_LED_ALL   (HAL_LED_1 | HAL_LED_2 | HAL_LED_3 | HAL_LED_4)

/* Modes */
#define HAL_LED_MODE_OFF     0x00
#define HAL_LED_MODE_ON      0x01
#define HAL_LED_MODE_BLINK   0x02
#define HAL_LED_MODE_FLASH   0x04
#define HAL_LED_MODE_TOGGLE  0x08

/* Defaults */
#define HAL_LED_DEFAULT_MAX_LEDS      4
#define HAL_LED_DEFAULT_DUTY_CYCLE    5
#define HAL_LED_DEFAULT_FLASH_COUNT   50
#define HAL_LED_DEFAULT_FLASH_TIME    1000


/*********************************************************************
 * TYPEDEFS
 */

 /* ����һ��LED���ڼ����ʾ����Ľ���,�͵�ƽLED�� */

/* 1 - LED */
  #define LED1_BV           BV(0)
  #define LED2_BV           
  #define LED3_BV           

  #define LED1_OUT        	(R32_PB_OUT)
  #define LED2_OUT        	0
  #define LED3_OUT        	0
  #define LED4_OUT        	0

  #define LED1_DDR					(R32_PB_DIR|=LED1_BV)
  #define LED2_DDR          0
  #define LED3_DDR          0
							
  #define HAL_TURN_OFF_LED1()       (LED1_OUT |= LED1_BV) 
  #define HAL_TURN_OFF_LED2()       
  #define HAL_TURN_OFF_LED3()         
  #define HAL_TURN_OFF_LED4()       

  #define HAL_TURN_ON_LED1()        (LED1_OUT &= (~LED1_BV)) 
  #define HAL_TURN_ON_LED2()         
  #define HAL_TURN_ON_LED3()        
  #define HAL_TURN_ON_LED4()        

  #define HAL_STATE_LED1()        	0
  #define HAL_STATE_LED2()          0
  #define HAL_STATE_LED3()          0
  #define HAL_STATE_LED4()         	0

/*********************************************************************
 * GLOBAL VARIABLES
 */

/*
 * Initialize LED Service.
 */
void HAL_LedInit( void );


/*
 * update time LED Service.
 */
void HalLedUpdate (void);

/*
 * Set the LED ON/OFF/TOGGLE.
 */
extern uint8 HalLedSet( uint8 led, uint8 mode );

/*
 * Blink the LED.
 */
extern void HalLedBlink( uint8 leds, uint8 cnt, uint8 duty, uint16 time );

/*
 * Put LEDs in sleep state - store current values
 */
extern void HalLedEnterSleep( void );

/*
 * Retore LEDs from sleep state
 */
extern void HalLedExitSleep( void );

/*
 * Return LED state
 */
extern uint8 HalLedGetState ( void );

/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif