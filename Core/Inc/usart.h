/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdio.h>

typedef __packed struct
{
  uint32_t head;    // 帧头
  uint8_t id;       // 轴
  uint32_t len;     // 帧长
  uint8_t cmd;      // 指令
  
}packet_head_t;

#define FRAME_HEADER     0x59485A53    // 帧头

 //ID???
#define XAxis                   0x01
#define YAxis                   0x02
#define ZAxis                   0x03
#define Sensor                  0x04


/* 指令(下位机 -> 上位机) */
#define SEND_ID_CMD             0x01     // ????ID????
#define SEND_START_CMD          0x02     // ?????????(?????????)
#define SEND_DATA_CMD           0x03     // ?????????(?????????)


/* 指令(上位机 -> 下位机) */
#define START_CMD               0x10     // ????
#define PAUSE_CMD               0x11     // ????
#define RESET_CMD               0x12     // ????
#define STOP_CMD                0x13     // ????
#define SET_SPEED_CMD           0x14     // ????
#define FORWARD_CMD             0x15     // ????
#define BACKWARD_CMD            0x16     // ????

/* ??? */
#define CMD_NONE             0xFF     // 空指令

/* ?????? */
#define HEAD_INDEX_VAL       0x3u     // ?????(4??)
#define CHX_INDEX_VAL        0x4u     // ?????(1??)
#define LEN_INDEX_VAL        0x5u     // ?????(4??)
#define CMD_INDEX_VAL        0x6u     // ?????(1??)

#define EXCHANGE_H_L_BIT(data)      ((((data) << 24) & 0xFF000000) |\
                                     (((data) <<  8) & 0x00FF0000) |\
                                     (((data) >>  8) & 0x0000FF00) |\
                                     (((data) >> 24) & 0x000000FF))     // ??????

#define COMPOUND_32BIT(data)        (((*(data-0) << 24) & 0xFF000000) |\
                                     ((*(data-1) << 16) & 0x00FF0000) |\
                                     ((*(data-2) <<  8) & 0x0000FF00) |\
                                     ((*(data-3) <<  0) & 0x000000FF))      // ??????


void set_computer_value(uint8_t cmd, uint8_t ch, void *data, uint8_t num);
uint8_t check_sum(uint8_t init, uint8_t *ptr,uint8_t len);

extern unsigned char UART_RxBuffer[256];


extern UART_HandleTypeDef huart2;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */
int fputc(int ch, FILE *f);
#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
