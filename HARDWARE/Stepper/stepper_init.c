#include "Stepper\stepper_init.h"
#include "usart.h"
TIM_HandleTypeDef TIM_StepperHandle;

__IO uint16_t OC_Pulse_num = 20;     //比较输出的计数值
uint8_t Motor_Flag = 1;

uint32_t Motor_Pulse_Set  =0;
uint32_t Motor_Pulse_Count=0;
uint16_t Motor_ARR;
uint16_t Motor_CCR1;

 /**
  * @brief  中断优先级配置
  * @param  无
  * @retval 无
  */
static void TIMx_NVIC_Configuration(void)
{
  /* 外设中断配置 */
  HAL_NVIC_SetPriority(MOTOR_PUL_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(MOTOR_PUL_IRQn);
}

/**
  * @brief  配置TIM复用输出PWM时用到的I/O
  * @param  无
  * @retval 无
  */
static void Stepper_GPIO_Config(void) 
{
	GPIO_InitTypeDef GPIO_InitStruct;
	/*开启Motor相关的GPIO外设时钟*/
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();

	
	/*选择要控制的GPIO引脚*/															   
	GPIO_InitStruct.Pin = MOTOR_X_DIR_PIN;	
	/*设置引脚的输出类型为推挽输出*/
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
	GPIO_InitStruct.Pull =GPIO_PULLUP;
	/*设置引脚速率为高速 */   
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	/*MotorX 方向引脚 初始化*/
	HAL_GPIO_Init(MOTOR_X_DIR_GPIO_PORT, &GPIO_InitStruct);	

	/*Motor 使能引脚 初始化*/
	GPIO_InitStruct.Pin = MOTOR_X_ENA_PIN;	
	HAL_GPIO_Init(MOTOR_X_ENA_GPIO_PORT, &GPIO_InitStruct);	
	
	/*MotorY DIR引脚 初始化*/															   
	GPIO_InitStruct.Pin = MOTOR_Y_DIR_PIN;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
	GPIO_InitStruct.Pull = GPIO_PULLUP;  
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(MOTOR_Y_DIR_GPIO_PORT, &GPIO_InitStruct);	

	/*MotorY ENA引脚 初始化*/
	GPIO_InitStruct.Pin = MOTOR_Y_ENA_PIN;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
	GPIO_InitStruct.Pull = GPIO_PULLUP;  
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;	
	HAL_GPIO_Init(MOTOR_Y_ENA_GPIO_PORT, &GPIO_InitStruct);
	
		/*MotorZ DIR引脚 初始化*/															   
	GPIO_InitStruct.Pin = MOTOR_Z_DIR_PIN;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
	GPIO_InitStruct.Pull = GPIO_PULLUP;  
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(MOTOR_Z_DIR_GPIO_PORT, &GPIO_InitStruct);	

	/*MotorZ ENA引脚 初始化*/
	GPIO_InitStruct.Pin = MOTOR_Z_ENA_PIN;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
	GPIO_InitStruct.Pull = GPIO_PULLUP;  
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;	
	HAL_GPIO_Init(MOTOR_Y_ENA_GPIO_PORT, &GPIO_InitStruct);

	/* 定时器通道1功能引脚IO初始化 */
	/*设置输出类型*/
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	/*设置引脚速率 */ 
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	/*设置复用*/
	GPIO_InitStruct.Alternate = MOTOR_PUL_GPIO_AF;
	/*设置复用*/
	GPIO_InitStruct.Pull =GPIO_PULLUP;
	/*选择要控制的GPIO引脚*/	
	GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7| GPIO_PIN_8;
	/*Motor 脉冲引脚 初始化*/
	HAL_GPIO_Init(MOTOR_PUL_PORT, &GPIO_InitStruct);			
}


/*
 * 注意：TIM_TimeBaseInitTypeDef结构体里面有5个成员，TIM6和TIM7的寄存器里面只有
 * TIM_Prescaler和TIM_Period，所以使用TIM6和TIM7的时候只需初始化这两个成员即可，
 * 另外三个成员是通用定时器和高级定时器才有.
 *-----------------------------------------------------------------------------
 * TIM_Prescaler         都有
 * TIM_CounterMode			 TIMx,x[6,7]没有，其他都有（基本定时器）
 * TIM_Period            都有
 * TIM_ClockDivision     TIMx,x[6,7]没有，其他都有(基本定时器)
 * TIM_RepetitionCounter TIMx,x[1,8]才有(高级定时器)
 *-----------------------------------------------------------------------------
 */
void TIM_PWMOUTPUT_Config(void)
{
	TIM_OC_InitTypeDef  TIM_OCInitStructure;  	
	/*使能定时器*/
	MOTOR_PUL_CLK_ENABLE();

	TIM_StepperHandle.Instance = MOTOR_PUL_TIM;    
	/* 累计 TIM_Period个后产生一个更新或者中断*/		
	//当定时器从0计数到10000，即为10000次，为一个定时周期
	TIM_StepperHandle.Init.Period = TIM_PERIOD; 
	// 通用控制定时器时钟源TIMxCLK = HCLK/2=90MHz 
	// 设定定时器频率为=TIMxCLK/(TIM_Prescaler+1)=1MHz
	TIM_StepperHandle.Init.Prescaler = 84-1;                

	/*计数方式*/
	TIM_StepperHandle.Init.CounterMode = TIM_COUNTERMODE_UP;            
	/*采样时钟分频*/	
	TIM_StepperHandle.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;   
	TIM_StepperHandle.Init.RepetitionCounter = 0 ;  		
	/*初始化定时器*/
	HAL_TIM_OC_Init(&TIM_StepperHandle);

	/*PWM模式配置--这里配置为输出比较模式*/
	TIM_OCInitStructure.OCMode = TIM_OCMODE_TOGGLE; 
	/*比较输出的计数值*/
	TIM_OCInitStructure.Pulse = OC_Pulse_num;                    
	/*当定时器计数值小于CCR1_Val时为高电平*/
	TIM_OCInitStructure.OCPolarity = TIM_OCPOLARITY_HIGH;          
	/*设置互补通道输出的极性*/
	TIM_OCInitStructure.OCNPolarity = TIM_OCNPOLARITY_LOW; 
	/*快速模式设置*/
	TIM_OCInitStructure.OCFastMode = TIM_OCFAST_DISABLE;   
	/*空闲电平*/
	TIM_OCInitStructure.OCIdleState = TIM_OCIDLESTATE_RESET;  
	/*互补通道设置*/
	TIM_OCInitStructure.OCNIdleState = TIM_OCNIDLESTATE_RESET; 
	HAL_TIM_OC_ConfigChannel(&TIM_StepperHandle, &TIM_OCInitStructure, TIM_CHANNEL_1);
	HAL_TIM_OC_ConfigChannel(&TIM_StepperHandle, &TIM_OCInitStructure, TIM_CHANNEL_2);
	HAL_TIM_OC_ConfigChannel(&TIM_StepperHandle, &TIM_OCInitStructure, TIM_CHANNEL_3);
	/* 确定定时器 */
	HAL_TIM_Base_Start(&TIM_StepperHandle);
	/* 启动比较输出并使能中断 */
	HAL_TIM_OC_Start_IT(&TIM_StepperHandle,TIM_CHANNEL_1);
	HAL_TIM_OC_Start_IT(&TIM_StepperHandle ,TIM_CHANNEL_2);
	HAL_TIM_OC_Start_IT(&TIM_StepperHandle ,TIM_CHANNEL_3);	
	/*使能比较通道*/
	TIM_CCxChannelCmd(MOTOR_PUL_TIM,TIM_CHANNEL_1,TIM_CCx_ENABLE);
	TIM_CCxChannelCmd(TIM8,TIM_CHANNEL_2 ,TIM_CCx_ENABLE);
	TIM_CCxChannelCmd(TIM8,TIM_CHANNEL_3 ,TIM_CCx_ENABLE);
}

/**
  * @brief  定时器中断函数
	*	@note 		无
  * @retval 无
  */
void MOTOR_PUL_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&TIM_StepperHandle);
}

/**
  * @brief  定时器比较中断
  * @param  htim：定时器句柄指针
	*	@note 		无
  * @retval 无
  */
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
  uint32_t count;

	/*获取当前计数*/
  count = __HAL_TIM_GET_COUNTER(htim);

	if(Motor_Flag == 1){
  __HAL_TIM_SET_COMPARE(&TIM_StepperHandle, TIM_CHANNEL_1, count + 550 - OC_Pulse_num);
  __HAL_TIM_SET_COMPARE(&TIM_StepperHandle, TIM_CHANNEL_2, count + 550 - OC_Pulse_num);
  __HAL_TIM_SET_COMPARE(&TIM_StepperHandle, TIM_CHANNEL_3, count + 550 - OC_Pulse_num);
}
	else{
		__HAL_TIM_SET_COMPARE(&TIM_StepperHandle, TIM_CHANNEL_1, count + Motor_ARR - OC_Pulse_num);
		__HAL_TIM_SET_COMPARE(&TIM_StepperHandle, TIM_CHANNEL_2, count + Motor_ARR - OC_Pulse_num);
		__HAL_TIM_SET_COMPARE(&TIM_StepperHandle, TIM_CHANNEL_3, count + Motor_ARR - OC_Pulse_num);
		Motor_Pulse_Count++;
		if(Motor_Pulse_Count > Motor_Pulse_Set)
			{
				TIM_CCxChannelCmd(MOTOR_PUL_TIM, TIM_CHANNEL_1, TIM_CCx_DISABLE);
				TIM_CCxChannelCmd(MOTOR_PUL_TIM, TIM_CHANNEL_2, TIM_CCx_DISABLE);
				TIM_CCxChannelCmd(MOTOR_PUL_TIM, TIM_CHANNEL_3, TIM_CCx_DISABLE);
				Motor_Pulse_Count = 0;
	}
}
}
/**
  * @brief  引脚初始化
  * @retval 无
  */
void stepper_Init()
{
	/*电机IO配置*/
	Stepper_GPIO_Config();
	/*定时器PWM输出配置*/
	TIM_PWMOUTPUT_Config();
	/*中断配置*/
	TIMx_NVIC_Configuration();
	printf("stepper_Init success!!\n");
}

void Motor_PulseOutput(uint8_t axis, uint16_t cycle,uint16_t pulse_num)//周期=cycle us (占空比50%) 10个脉冲
{
	Motor_Pulse_Set= pulse_num;
    Motor_Pulse_Count = 0;	
	Motor_ARR = cycle;
	switch(axis){
		case X_Axis:
			TIM_CCxChannelCmd(MOTOR_PUL_TIM,TIM_CHANNEL_1,TIM_CCx_ENABLE);break;
		case Y_Axis:
			TIM_CCxChannelCmd(MOTOR_PUL_TIM,TIM_CHANNEL_2,TIM_CCx_ENABLE);break;
		case Z_Axis:
			TIM_CCxChannelCmd(MOTOR_PUL_TIM,TIM_CHANNEL_3,TIM_CCx_ENABLE);break;		
	}
}

