#include "Stepper\stepper_init.h"
#include "usart.h"
TIM_HandleTypeDef TIM_StepperHandle;

__IO uint16_t OC_Pulse_num = 20;     //�Ƚ�����ļ���ֵ
uint8_t Motor_Flag = 1;

uint32_t Motor_Pulse_Set  =0;
uint32_t Motor_Pulse_Count=0;
uint16_t Motor_ARR;
uint16_t Motor_CCR1;

 /**
  * @brief  �ж����ȼ�����
  * @param  ��
  * @retval ��
  */
static void TIMx_NVIC_Configuration(void)
{
  /* �����ж����� */
  HAL_NVIC_SetPriority(MOTOR_PUL_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(MOTOR_PUL_IRQn);
}

/**
  * @brief  ����TIM�������PWMʱ�õ���I/O
  * @param  ��
  * @retval ��
  */
static void Stepper_GPIO_Config(void) 
{
	GPIO_InitTypeDef GPIO_InitStruct;
	/*����Motor��ص�GPIO����ʱ��*/
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();

	
	/*ѡ��Ҫ���Ƶ�GPIO����*/															   
	GPIO_InitStruct.Pin = MOTOR_X_DIR_PIN;	
	/*�������ŵ��������Ϊ�������*/
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
	GPIO_InitStruct.Pull =GPIO_PULLUP;
	/*������������Ϊ���� */   
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	/*MotorX �������� ��ʼ��*/
	HAL_GPIO_Init(MOTOR_X_DIR_GPIO_PORT, &GPIO_InitStruct);	

	/*Motor ʹ������ ��ʼ��*/
	GPIO_InitStruct.Pin = MOTOR_X_ENA_PIN;	
	HAL_GPIO_Init(MOTOR_X_ENA_GPIO_PORT, &GPIO_InitStruct);	
	
	/*MotorY DIR���� ��ʼ��*/															   
	GPIO_InitStruct.Pin = MOTOR_Y_DIR_PIN;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
	GPIO_InitStruct.Pull = GPIO_PULLUP;  
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(MOTOR_Y_DIR_GPIO_PORT, &GPIO_InitStruct);	

	/*MotorY ENA���� ��ʼ��*/
	GPIO_InitStruct.Pin = MOTOR_Y_ENA_PIN;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
	GPIO_InitStruct.Pull = GPIO_PULLUP;  
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;	
	HAL_GPIO_Init(MOTOR_Y_ENA_GPIO_PORT, &GPIO_InitStruct);
	
		/*MotorZ DIR���� ��ʼ��*/															   
	GPIO_InitStruct.Pin = MOTOR_Z_DIR_PIN;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
	GPIO_InitStruct.Pull = GPIO_PULLUP;  
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(MOTOR_Z_DIR_GPIO_PORT, &GPIO_InitStruct);	

	/*MotorZ ENA���� ��ʼ��*/
	GPIO_InitStruct.Pin = MOTOR_Z_ENA_PIN;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  
	GPIO_InitStruct.Pull = GPIO_PULLUP;  
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;	
	HAL_GPIO_Init(MOTOR_Y_ENA_GPIO_PORT, &GPIO_InitStruct);

	/* ��ʱ��ͨ��1��������IO��ʼ�� */
	/*�����������*/
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	/*������������ */ 
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	/*���ø���*/
	GPIO_InitStruct.Alternate = MOTOR_PUL_GPIO_AF;
	/*���ø���*/
	GPIO_InitStruct.Pull =GPIO_PULLUP;
	/*ѡ��Ҫ���Ƶ�GPIO����*/	
	GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7| GPIO_PIN_8;
	/*Motor �������� ��ʼ��*/
	HAL_GPIO_Init(MOTOR_PUL_PORT, &GPIO_InitStruct);			
}


/*
 * ע�⣺TIM_TimeBaseInitTypeDef�ṹ��������5����Ա��TIM6��TIM7�ļĴ�������ֻ��
 * TIM_Prescaler��TIM_Period������ʹ��TIM6��TIM7��ʱ��ֻ���ʼ����������Ա���ɣ�
 * ����������Ա��ͨ�ö�ʱ���͸߼���ʱ������.
 *-----------------------------------------------------------------------------
 * TIM_Prescaler         ����
 * TIM_CounterMode			 TIMx,x[6,7]û�У��������У�������ʱ����
 * TIM_Period            ����
 * TIM_ClockDivision     TIMx,x[6,7]û�У���������(������ʱ��)
 * TIM_RepetitionCounter TIMx,x[1,8]����(�߼���ʱ��)
 *-----------------------------------------------------------------------------
 */
void TIM_PWMOUTPUT_Config(void)
{
	TIM_OC_InitTypeDef  TIM_OCInitStructure;  	
	/*ʹ�ܶ�ʱ��*/
	MOTOR_PUL_CLK_ENABLE();

	TIM_StepperHandle.Instance = MOTOR_PUL_TIM;    
	/* �ۼ� TIM_Period�������һ�����»����ж�*/		
	//����ʱ����0������10000����Ϊ10000�Σ�Ϊһ����ʱ����
	TIM_StepperHandle.Init.Period = TIM_PERIOD; 
	// ͨ�ÿ��ƶ�ʱ��ʱ��ԴTIMxCLK = HCLK/2=90MHz 
	// �趨��ʱ��Ƶ��Ϊ=TIMxCLK/(TIM_Prescaler+1)=1MHz
	TIM_StepperHandle.Init.Prescaler = 84-1;                

	/*������ʽ*/
	TIM_StepperHandle.Init.CounterMode = TIM_COUNTERMODE_UP;            
	/*����ʱ�ӷ�Ƶ*/	
	TIM_StepperHandle.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;   
	TIM_StepperHandle.Init.RepetitionCounter = 0 ;  		
	/*��ʼ����ʱ��*/
	HAL_TIM_OC_Init(&TIM_StepperHandle);

	/*PWMģʽ����--��������Ϊ����Ƚ�ģʽ*/
	TIM_OCInitStructure.OCMode = TIM_OCMODE_TOGGLE; 
	/*�Ƚ�����ļ���ֵ*/
	TIM_OCInitStructure.Pulse = OC_Pulse_num;                    
	/*����ʱ������ֵС��CCR1_ValʱΪ�ߵ�ƽ*/
	TIM_OCInitStructure.OCPolarity = TIM_OCPOLARITY_HIGH;          
	/*���û���ͨ������ļ���*/
	TIM_OCInitStructure.OCNPolarity = TIM_OCNPOLARITY_LOW; 
	/*����ģʽ����*/
	TIM_OCInitStructure.OCFastMode = TIM_OCFAST_DISABLE;   
	/*���е�ƽ*/
	TIM_OCInitStructure.OCIdleState = TIM_OCIDLESTATE_RESET;  
	/*����ͨ������*/
	TIM_OCInitStructure.OCNIdleState = TIM_OCNIDLESTATE_RESET; 
	HAL_TIM_OC_ConfigChannel(&TIM_StepperHandle, &TIM_OCInitStructure, TIM_CHANNEL_1);
	HAL_TIM_OC_ConfigChannel(&TIM_StepperHandle, &TIM_OCInitStructure, TIM_CHANNEL_2);
	HAL_TIM_OC_ConfigChannel(&TIM_StepperHandle, &TIM_OCInitStructure, TIM_CHANNEL_3);
	/* ȷ����ʱ�� */
	HAL_TIM_Base_Start(&TIM_StepperHandle);
	/* �����Ƚ������ʹ���ж� */
	HAL_TIM_OC_Start_IT(&TIM_StepperHandle,TIM_CHANNEL_1);
	HAL_TIM_OC_Start_IT(&TIM_StepperHandle ,TIM_CHANNEL_2);
	HAL_TIM_OC_Start_IT(&TIM_StepperHandle ,TIM_CHANNEL_3);	
	/*ʹ�ܱȽ�ͨ��*/
	TIM_CCxChannelCmd(MOTOR_PUL_TIM,TIM_CHANNEL_1,TIM_CCx_ENABLE);
	TIM_CCxChannelCmd(TIM8,TIM_CHANNEL_2 ,TIM_CCx_ENABLE);
	TIM_CCxChannelCmd(TIM8,TIM_CHANNEL_3 ,TIM_CCx_ENABLE);
}

/**
  * @brief  ��ʱ���жϺ���
	*	@note 		��
  * @retval ��
  */
void MOTOR_PUL_IRQHandler(void)
{
  HAL_TIM_IRQHandler(&TIM_StepperHandle);
}

/**
  * @brief  ��ʱ���Ƚ��ж�
  * @param  htim����ʱ�����ָ��
	*	@note 		��
  * @retval ��
  */
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
  uint32_t count;

	/*��ȡ��ǰ����*/
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
  * @brief  ���ų�ʼ��
  * @retval ��
  */
void stepper_Init()
{
	/*���IO����*/
	Stepper_GPIO_Config();
	/*��ʱ��PWM�������*/
	TIM_PWMOUTPUT_Config();
	/*�ж�����*/
	TIMx_NVIC_Configuration();
	printf("stepper_Init success!!\n");
}

void Motor_PulseOutput(uint8_t axis, uint16_t cycle,uint16_t pulse_num)//����=cycle us (ռ�ձ�50%) 10������
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

