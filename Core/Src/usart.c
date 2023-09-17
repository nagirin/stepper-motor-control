/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
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

/* Includes ------------------------------------------------------------------*/
#include "usart.h"
#include <stdio.h>
#include "stepper\stepper_init.h"
#include "main.h"
/* USER CODE END 0 */

UART_HandleTypeDef huart1;

extern __IO uint16_t OC_Pulse_num ;
extern u8  Motor_Flag;
//串口接收数组
unsigned char UART_RxBuffer[256];
//串口接收数组指针
unsigned char UART_RxPtr;
/* 命令接收完成 */
uint8_t receive_cmd = 0;


void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	  /* 使能串口空闲断 */

  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}
/* USART2 init function */

/* USART3 init function */



void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


	__HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
  
	HAL_UART_Receive_IT(&huart1, UART_RxBuffer, sizeof(UART_RxBuffer));
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
 
//  else if(uartHandle->Instance==USART3)
//  {
//  /* USER CODE BEGIN USART3_MspInit 0 */

//  /* USER CODE END USART3_MspInit 0 */
//    /* USART3 clock enable */
//    __HAL_RCC_USART3_CLK_ENABLE();

//    __HAL_RCC_GPIOB_CLK_ENABLE();
//    /**USART3 GPIO Configuration
//    PB10     ------> USART3_TX
//    PB11     ------> USART3_RX
//    */
//    GPIO_InitStruct.Pin = GPIO_PIN_10;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

//    GPIO_InitStruct.Pin = GPIO_PIN_11;
//    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

//  /* USER CODE BEGIN USART3_MspInit 1 */

//  /* USER CODE END USART3_MspInit 1 */
//  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

    /* USART1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART1_IRQn);
  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
//  else if(uartHandle->Instance==USART3)
//  {
//  /* USER CODE BEGIN USART3_MspDeInit 0 */

//  /* USER CODE END USART3_MspDeInit 0 */
//    /* Peripheral clock disable */
//    __HAL_RCC_USART3_CLK_DISABLE();

//    /**USART3 GPIO Configuration
//    PB10     ------> USART3_TX
//    PB11     ------> USART3_RX
//    */
//    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_10|GPIO_PIN_11);

//  /* USER CODE BEGIN USART3_MspDeInit 1 */

//  /* USER CODE END USART3_MspDeInit 1 */
//  }
}

//清空接收缓冲
void uart_FlushRxBuffer(void)
{
  UART_RxPtr = 0;
  UART_RxBuffer[UART_RxPtr] = 0;
}

/*****************  发送字符 **********************/
void Usart_SendByte(uint8_t str)
{
  HAL_UART_Transmit(&huart1, &str, 1, 1000);
}

/*****************  发送字符串 **********************/
void Usart_SendString(uint8_t *str)
{
	unsigned int k=0;
  do 
  {
      HAL_UART_Transmit(&huart1,(uint8_t *)(str + k) ,1,1000);
      k++;
  } while(*(str + k)!='\0');
}

///重定向c库函数printf到串口DEBUG_USART，重定向后可使用printf函数
int fputc(int ch, FILE *f)
{
	/* 发送一个字节数据到串口DEBUG_USART */
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 1000);	
	
	return (ch);
}

///重定向c库函数scanf到串口DEBUG_USART，重写向后可使用scanf、getchar等函数
int fgetc(FILE *f)
{
		
	int ch;
	HAL_UART_Receive(&huart1, (uint8_t *)&ch, 1, 1000);	
	return (ch);
}

/**
  * @brief 计算校验和
  * @param ptr：需要计算的数据
  * @param len：需要计算的长度
  * @retval 校验和
  */
uint8_t check_sum(uint8_t init, uint8_t *ptr, uint8_t len )
{
  uint8_t sum = init;
  
  while(len--)
  {
    sum += *ptr;
    ptr++;
  }
  
  return sum;
}

static const u8 caCrc8Data[256] = {
    0x00, 0x5e, 0xbc, 0xe2, 0x61, 0x3f, 0xdd, 0x83,
    0xc2, 0x9c, 0x7e, 0x20, 0xa3, 0xfd, 0x1f, 0x41,
    0x9d, 0xc3, 0x21, 0x7f, 0xfc, 0xa2, 0x40, 0x1e,
    0x5f, 0x01, 0xe3, 0xbd, 0x3e, 0x60, 0x82, 0xdc,
    0x23, 0x7d, 0x9f, 0xc1, 0x42, 0x1c, 0xfe, 0xa0,
    0xe1, 0xbf, 0x5d, 0x03, 0x80, 0xde, 0x3c, 0x62,
    0xbe, 0xe0, 0x02, 0x5c, 0xdf, 0x81, 0x63, 0x3d,
    0x7c, 0x22, 0xc0, 0x9e, 0x1d, 0x43, 0xa1, 0xff,
    0x46, 0x18, 0xfa, 0xa4, 0x27, 0x79, 0x9b, 0xc5,
    0x84, 0xda, 0x38, 0x66, 0xe5, 0xbb, 0x59, 0x07,
    0xdb, 0x85, 0x67, 0x39, 0xba, 0xe4, 0x06, 0x58,
    0x19, 0x47, 0xa5, 0xfb, 0x78, 0x26, 0xc4, 0x9a,
    0x65, 0x3b, 0xd9, 0x87, 0x04, 0x5a, 0xb8, 0xe6,
    0xa7, 0xf9, 0x1b, 0x45, 0xc6, 0x98, 0x7a, 0x24,
    0xf8, 0xa6, 0x44, 0x1a, 0x99, 0xc7, 0x25, 0x7b,
    0x3a, 0x64, 0x86, 0xd8, 0x5b, 0x05, 0xe7, 0xb9,
    0x8c, 0xd2, 0x30, 0x6e, 0xed, 0xb3, 0x51, 0x0f,
    0x4e, 0x10, 0xf2, 0xac, 0x2f, 0x71, 0x93, 0xcd,
    0x11, 0x4f, 0xad, 0xf3, 0x70, 0x2e, 0xcc, 0x92,
    0xd3, 0x8d, 0x6f, 0x31, 0xb2, 0xec, 0x0e, 0x50,
    0xaf, 0xf1, 0x13, 0x4d, 0xce, 0x90, 0x72, 0x2c,
    0x6d, 0x33, 0xd1, 0x8f, 0x0c, 0x52, 0xb0, 0xee,
    0x32, 0x6c, 0x8e, 0xd0, 0x53, 0x0d, 0xef, 0xb1,
    0xf0, 0xae, 0x4c, 0x12, 0x91, 0xcf, 0x2d, 0x73,
    0xca, 0x94, 0x76, 0x28, 0xab, 0xf5, 0x17, 0x49,
    0x08, 0x56, 0xb4, 0xea, 0x69, 0x37, 0xd5, 0x8b,
    0x57, 0x09, 0xeb, 0xb5, 0x36, 0x68, 0x8a, 0xd4,
    0x95, 0xcb, 0x29, 0x77, 0xf4, 0xaa, 0x48, 0x16,
    0xe9, 0xb7, 0x55, 0x0b, 0x88, 0xd6, 0x34, 0x6a,
    0x2b, 0x75, 0x97, 0xc9, 0x4a, 0x14, 0xf6, 0xa8,
    0x74, 0x2a, 0xc8, 0x96, 0x15, 0x4b, 0xa9, 0xf7,
    0xb6, 0xe8, 0x0a, 0x54, 0xd7, 0x89, 0x6b, 0x35
};

u8 Crc8(u8 CRC8,const u8*pBuff, int len)
{

    int i;
    u8 temp;
    
    for (i = 0; i < len-1; i++) {
		
        temp = *(pBuff + i) ^ CRC8;
        CRC8 = caCrc8Data[temp];
		//printf("CRC8 is %uc \n",CRC8);
    }
    return (CRC8);
}



/**
  * @brief 设置上位机的值
  * @param cmd：命令
  * @param ch: 曲线通道
  * @param data：参数指针
  * @param num：参数个数
  * @retval 无
  */
void set_computer_value(uint8_t cmd, uint8_t id, void *data, uint8_t num)
{
  uint8_t sum = 0;    // 校验和
  num *= 4;           // 一个参数 4 个字节
	
  static packet_head_t set_packet;
  
  set_packet.head = FRAME_HEADER;     // 包头 0x59485A53
  set_packet.len  = 0x0B + num;      // 包长
  set_packet.id   = id;              // 设置通道
  set_packet.cmd  = cmd;             // 设置命令
 
  sum = Crc8(0,(uint8_t *)&set_packet,sizeof(set_packet)+1);	       // 计算校验和  
  sum = Crc8(sum,(uint8_t *)data, num+1);
  //printf("sum is %uc \n",sum);
  
  HAL_UART_Transmit(&huart1, (uint8_t *)&set_packet, sizeof(set_packet), 0xFFFFF);    // 发送数据头
  HAL_UART_Transmit(&huart1, (uint8_t *)data, num, 0xFFFFF);                          // 发送参数
  HAL_UART_Transmit(&huart1, (uint8_t *)&sum, sizeof(sum), 0xFFFFF);                  // 发送校验和
}

/**
  * @brief 解析串口接收到的数据
  * @param cmd：命令
  * @param ch: 曲线通道
  * @param data：数据
  * @retval 无
  */
void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *husart)
{
  packet_head_t packet;
    
  packet.cmd = UART_RxBuffer[CMD_INDEX_VAL];
  packet.len  = UART_RxBuffer[LEN_INDEX_VAL];     // 合成长度
  packet.head = EXCHANGE_H_L_BIT(COMPOUND_32BIT(&UART_RxBuffer[HEAD_INDEX_VAL]));    // 合成包头
//  printf("packet is %s \n",UART_RxBuffer);
//  printf("packet cmd is %x \n",packet.cmd);
	
	
  if (packet.head == FRAME_HEADER)    // 检查包头
  {
    /* 包头正确 */
	 //printf("check sum is %x ,CRC is %x,UART_RxBuffer[packet.len] is %x  \n",check_sum(0, UART_RxBuffer, packet.len), Crc8(UART_RxBuffer, packet.len ),UART_RxBuffer[packet.len - 1]);
    if (Crc8(0,UART_RxBuffer, packet.len ) == UART_RxBuffer[packet.len - 1])    // 检查校验和是否正确
    {
      switch(packet.cmd)
      {
		case START_CMD:
      {
		Motor_Flag = 1;
		printf("START_CMD \n");

        packet.id = UART_RxBuffer[CHX_INDEX_VAL];
        
        if (packet.id == XAxis)
        {
		  TIM_CCxChannelCmd(MOTOR_PUL_TIM,TIM_CHANNEL_1 ,TIM_CCx_ENABLE);
          MOTOR_X_EN(HIGH);
		  printf("MOTOR_X_ENABLE \n");
        }
        else if (packet.id == YAxis)
        {
		  TIM_CCxChannelCmd(MOTOR_PUL_TIM,TIM_CHANNEL_2 ,TIM_CCx_ENABLE);
          MOTOR_Y_EN(HIGH);;
		  printf("MOTOR_Y_ENABLE \n");
        }
		else if (packet.id == ZAxis)
        {
		  TIM_CCxChannelCmd(MOTOR_PUL_TIM,TIM_CHANNEL_3 ,TIM_CCx_ENABLE);
          MOTOR_Z_EN(HIGH);;
		  printf("MOTOR_Z_ENABLE \n");
        }
		
      }
      break;

      case PAUSE_CMD:
      {

        packet.id = UART_RxBuffer[CHX_INDEX_VAL];
        
        if (packet.id == XAxis)
        {
          MOTOR_X_ENA_TOGGLE;
		  printf("MOTOR_X_ENA_TOGGLE \n");
        }
        else if (packet.id == YAxis)
        {
          MOTOR_Y_ENA_TOGGLE;
		  printf("MOTOR_Y_ENA_TOGGLE \n");
        }
		else if (packet.id == ZAxis)
        {
          MOTOR_Z_ENA_TOGGLE;
		  printf("MOTOR_Z_ENA_TOGGLE \n");
        }
		
      }
      break;
        
      case STOP_CMD:
      {        		  
          MOTOR_X_EN(LOW);
		  TIM_CCxChannelCmd(MOTOR_PUL_TIM,TIM_CHANNEL_1 ,TIM_CCx_DISABLE);
		  TIM_CCxChannelCmd(MOTOR_PUL_TIM,TIM_CHANNEL_2 ,TIM_CCx_DISABLE);         
		  TIM_CCxChannelCmd(MOTOR_PUL_TIM,TIM_CHANNEL_3 ,TIM_CCx_DISABLE);
          
		  printf("MOTOR_DISABLE \n");
          // 停止电机
		  
      }
      break;
               
        case RESET_CMD:
        {
          HAL_NVIC_SystemReset();          // 复位系统
        }
        break;
        
      case SET_SPEED_CMD:
      {
        int actual_temp = UART_RxBuffer[7];    // 得到数据
        packet.id = UART_RxBuffer[CHX_INDEX_VAL];
        printf("Speed = %d \n",actual_temp);
           
        {
          
			OC_Pulse_num =  actual_temp * 5;    // 设置速度
        }
		
      }	
      break;
	 case FORWARD_CMD:
      {
		packet.id = UART_RxBuffer[CHX_INDEX_VAL];       
        if (packet.id == XAxis)
        {
		  MOTOR_X_DIR(HIGH);
		  Motor_Flag = 0;
		  MOTOR_X_EN(HIGH);              // 启动电机		
		  Motor_PulseOutput(X_Axis,500,6400);
		  printf("XAxis FORWARD \n");
		}
        else if (packet.id == YAxis)
        {
		  MOTOR_Y_DIR(HIGH);
		  Motor_Flag = 0;
		  MOTOR_X_EN(HIGH);              // 启动电机		
		  Motor_PulseOutput(Y_Axis,500,6400);
		  printf("YAxis FORWARD \n");                            
        }
        else if (packet.id == ZAxis)
        {
		  MOTOR_Z_DIR(HIGH);
		  Motor_Flag = 0;
		  MOTOR_Z_EN(HIGH);              // 启动电机		
		  Motor_PulseOutput(Z_Axis,500,6400);
		  printf("ZAxis FORWARD \n");                           
        }
		   
      }break;
	 case BACKWARD_CMD:
      {
		packet.id = UART_RxBuffer[CHX_INDEX_VAL];       
        if (packet.id == XAxis)
        {
		  MOTOR_X_DIR(LOW);
		  Motor_Flag = 0;
		  MOTOR_X_EN(HIGH);              // 启动电机		
		  Motor_PulseOutput(X_Axis,500,6400);
		  printf("XAxis BACKWARD \n");
		}
        else if (packet.id == YAxis)
        {
		  MOTOR_Y_DIR(LOW);
		  Motor_Flag = 0;
		  MOTOR_X_EN(HIGH);              // 启动电机		
		  Motor_PulseOutput(Y_Axis,500,6400);
		  printf("YAxis BACKWARD \n");                            
        }
        else if (packet.id == ZAxis)
        {
		  MOTOR_Z_DIR(LOW);
		  Motor_Flag = 0;
		  MOTOR_Z_EN(HIGH);              // 启动电机		
		  Motor_PulseOutput(Z_Axis,500,6400);
		  printf("ZAxis BACKWARD \n");                           
        }
			
      }
      break;
      }
    }
  }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
