#ifndef __KEY_H__
#define __KEY_H__

/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* ���Ͷ��� --------------------------------------------------------------*/
typedef enum
{
  KEY_UP   = 0,
  KEY_DOWN = 1,
}KEYState_TypeDef;

/* �궨�� --------------------------------------------------------------------*/
#define KEY_RCC_CLK_ENABLE            __HAL_RCC_GPIOE_CLK_ENABLE
#define KEY_GPIO                      GPIOE
#define KEY0_GPIO_PIN                 GPIO_PIN_4
#define KEY0_DOWN_LEVEL               0  /* ����ԭ��ͼ��ƣ�KEY1����ʱ����Ϊ�͵�ƽ��������������Ϊ0 */

#define KEY1_GPIO_PIN                 GPIO_PIN_3
#define KEY1_DOWN_LEVEL               0  /* ����ԭ��ͼ��ƣ�KEY2����ʱ����Ϊ�͵�ƽ��������������Ϊ0 */



/* ��չ���� ------------------------------------------------------------------*/
/* �������� ------------------------------------------------------------------*/
void KEY_GPIO_Init(void);
KEYState_TypeDef KEY0_StateRead(void);
KEYState_TypeDef KEY1_StateRead(void);


#endif  //

