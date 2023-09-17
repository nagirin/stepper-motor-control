#ifndef __KEY_H__
#define __KEY_H__

/* 包含头文件 ----------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* 类型定义 --------------------------------------------------------------*/
typedef enum
{
  KEY_UP   = 0,
  KEY_DOWN = 1,
}KEYState_TypeDef;

/* 宏定义 --------------------------------------------------------------------*/
#define KEY_RCC_CLK_ENABLE            __HAL_RCC_GPIOE_CLK_ENABLE
#define KEY_GPIO                      GPIOE
#define KEY0_GPIO_PIN                 GPIO_PIN_4
#define KEY0_DOWN_LEVEL               0  /* 根据原理图设计，KEY1按下时引脚为低电平，所以这里设置为0 */

#define KEY1_GPIO_PIN                 GPIO_PIN_3
#define KEY1_DOWN_LEVEL               0  /* 根据原理图设计，KEY2按下时引脚为低电平，所以这里设置为0 */



/* 扩展变量 ------------------------------------------------------------------*/
/* 函数声明 ------------------------------------------------------------------*/
void KEY_GPIO_Init(void);
KEYState_TypeDef KEY0_StateRead(void);
KEYState_TypeDef KEY1_StateRead(void);


#endif  //

