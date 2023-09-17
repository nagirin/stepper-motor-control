/*
 * LaNgioklip
 */

//*使用的IO：  

//				(MotorX)
//				GPIOC6 		--> 	PUL(TIM8)
//				GPIOB13		--> 	DIR
//				GPIOB14 	--> 	ENABLE
//				
//				(MotorY)
//				GPIOC7 		--> 	PUL(TM8)
//				GPIOE13		--> 	DIR
//				GPIOE14 	--> 	ENABLE
//				
//				(MotorZ)
//				GPIOC8 		--> 	PUL(TIM8)
//				GPIOE11		--> 	DIR
//				GPIOE12 	--> 	ENABLE

#ifndef __STEPPER_INIT_H
#define	__STEPPER_INIT_H

#include "stm32f4xx_hal.h"
#include "main.h"
/*宏定义*/
/*******************************************************/

#define MOTOR_PUL_IRQn                  	TIM8_CC_IRQn
#define MOTOR_PUL_IRQHandler            	TIM8_CC_IRQHandler

#define MOTOR_PUL_TIM                   	TIM8
#define MOTOR_PUL_CLK_ENABLE()         	 	__TIM8_CLK_ENABLE()
#define MOTOR_PUL_PORT                  	GPIOC
#define MOTOR_PUL_GPIO_CLK_ENABLE()     	__HAL_RCC_GPIOC_CLK_ENABLE()
#define MOTOR_PUL_GPIO_AF               	GPIO_AF3_TIM8

//MotorX 
#define MOTOR_X_PUL_PIN                   	GPIO_PIN_6

#define MOTOR_X_DIR_PIN                  	GPIO_PIN_13
#define MOTOR_X_DIR_GPIO_PORT            	GPIOB  
#define MOTOR_X_DIR_GPIO_CLK_ENABLE()   	__HAL_RCC_GPIOB_CLK_ENABLE()

#define MOTOR_X_ENA_PIN                  	GPIO_PIN_14
#define MOTOR_X_ENA_GPIO_PORT            	GPIOB                      
#define MOTOR_X_ENA_GPIO_CLK_ENABLE()    	__HAL_RCC_GPIOB_CLK_ENABLE()

//MotorY 
#define MOTOR_Y_PUL_PIN                   	GPIO_PIN_7

#define MOTOR_Y_DIR_PIN                  	GPIO_PIN_13
#define MOTOR_Y_DIR_GPIO_PORT            	GPIOE  
#define MOTOR_Y_DIR_GPIO_CLK_ENABLE()   	__HAL_RCC_GPIOE_CLK_ENABLE()

#define MOTOR_Y_ENA_PIN                  	GPIO_PIN_14
#define MOTOR_Y_ENA_GPIO_PORT            	GPIOE                      
#define MOTOR_Y_ENA_GPIO_CLK_ENABLE()    	__HAL_RCC_GPIOE_CLK_ENABLE()

//MotorZ 
#define MOTOR_Z_PUL_PIN                   	GPIO_PIN_8

#define MOTOR_Z_DIR_PIN                  	GPIO_PIN_11
#define MOTOR_Z_DIR_GPIO_PORT            	GPIOE  
#define MOTOR_Z_DIR_GPIO_CLK_ENABLE()   	__HAL_RCC_GPIOE_CLK_ENABLE()

#define MOTOR_Z_ENA_PIN                  	GPIO_PIN_12
#define MOTOR_Z_ENA_GPIO_PORT            	GPIOE                      
#define MOTOR_Z_ENA_GPIO_CLK_ENABLE()    	__HAL_RCC_GPIOE    _CLK_ENABLE()



// 定义定时器周期，输出比较模式周期设置为0xFFFF
#define TIM_PERIOD                      0xFFFF

/************************************************************/
#define HIGH GPIO_PIN_SET       //高电平
#define LOW  GPIO_PIN_RESET     //低电平

#define ON  LOW                 //开
#define OFF HIGH                //关

#define CW  HIGH                //顺时针
#define CCW LOW                 //逆时针

enum Axis{
	X_Axis = 0,
	Y_Axis = 1,
	Z_Axis = 2
};


//控制使能引脚
#define MOTOR_X_EN(x)						HAL_GPIO_WritePin(MOTOR_X_ENA_GPIO_PORT, MOTOR_X_ENA_PIN, x)
#define MOTOR_X_PUL(x)						HAL_GPIO_WritePin(MOTOR_PUL_PORT, MOTOR_X_PUL_PIN, x)
#define MOTOR_X_DIR(x)						HAL_GPIO_WritePin(MOTOR_X_DIR_GPIO_PORT, MOTOR_X_DIR_PIN, x)
#define MOTOR_X_ENA_TOGGLE     				HAL_GPIO_TogglePin(MOTOR_X_ENA_GPIO_PORT, MOTOR_X_ENA_PIN)

#define MOTOR_Y_EN(x)						HAL_GPIO_WritePin(MOTOR_Y_ENA_GPIO_PORT, MOTOR_Y_ENA_PIN, x)
#define MOTOR_Y_PUL(x)						HAL_GPIO_WritePin(MOTOR_PUL_PORT, MOTOR_Y_PUL_PIN, x)
#define MOTOR_Y_DIR(x)						HAL_GPIO_WritePin(MOTOR_Y_DIR_GPIO_PORT, MOTOR_Y_DIR_PIN, x)
#define MOTOR_Y_ENA_TOGGLE     				HAL_GPIO_TogglePin(MOTOR_Y_ENA_GPIO_PORT, MOTOR_Y_ENA_PIN)

#define MOTOR_Z_EN(x)						HAL_GPIO_WritePin(MOTOR_Z_ENA_GPIO_PORT, MOTOR_Z_ENA_PIN, x)
#define MOTOR_Z_PUL(x)						HAL_GPIO_WritePin(MOTOR_PUL_PORT, MOTOR_Z_PUL_PIN, x)
#define MOTOR_Z_DIR(x)						HAL_GPIO_WritePin(MOTOR_Z_DIR_GPIO_PORT, MOTOR_Z_DIR_PIN, x)
#define MOTOR_Z_ENA_TOGGLE     				HAL_GPIO_TogglePin(MOTOR_Z_ENA_GPIO_PORT, MOTOR_Z_ENA_PIN)

extern void stepper_Init(void);
void Motor_PulseOutput(u8 Axis, u16 cycle,u16 pulse_num);

#endif 
