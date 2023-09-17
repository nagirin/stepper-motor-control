#ifndef __MATRIXKEY_H
#define	__MATRIXKEY_H

#include "stm32f1xx.h"
#include "main.h"
//引脚定义
/*******************************************************/
#define KEY_PIN                  	GPIO_PIN_0                 
#define KEY_GPIO_PORT            	GPIOA                      
#define KEY_GPIO_CLK_ENABLE()    	__GPIOA_CLK_ENABLE()

#define KEY_row_GPIO_Port 			GPIOA
#define KEY_row0_Pin 				GPIO_PIN_0
#define KEY_row1_Pin 				GPIO_PIN_1
#define KEY_row2_Pin 				GPIO_PIN_2
#define KEY_row3_Pin 				GPIO_PIN_3
#define KEY_row_GPIO_CLK_ENABLE()   __GPIOA_CLK_ENABLE()

#define KEY_col_GPIO_Port 			GPIOB
#define KEY_col3_Pin 				GPIO_PIN_3
#define KEY_col2_Pin 				GPIO_PIN_4
#define KEY_col1_Pin 				GPIO_PIN_5
#define KEY_col0_Pin 				GPIO_PIN_6
#define KEY_col_GPIO_CLK_ENABLE()   __GPIOB_CLK_ENABLE()


/*******************************************************/

#define KEY_CLO0_OUT_LOW  			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_RESET) 
#define KEY_CLO1_OUT_LOW  			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_RESET)
#define KEY_CLO2_OUT_LOW  			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET)
#define KEY_CLO3_OUT_LOW  			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_RESET)

#define KEY_CLO0_OUT_HIGH  			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_SET) 
#define KEY_CLO1_OUT_HIGH  			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET)
#define KEY_CLO2_OUT_HIGH  			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET)
#define KEY_CLO3_OUT_HIGH  			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_SET)


#define KEY_ON						1
#define KEY_OFF						0

void Key_GPIO_Config(void);
char Key_Scan(void);
char KEY_ROW_SCAN(void);
void KEY_FUNCTION(void);

#endif /* __KEY_H */