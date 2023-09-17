#include "myiic.h"
#include "usart.h"

static void i2c_Delay(void)
{
	uint8_t i;						

	for (i = 0; i < 10; i++);
}
//IIC初始化
void IIC_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    
    __HAL_RCC_GPIOB_CLK_ENABLE();   //使能GPIOB时钟
//    __HAL_RCC_GPIOG_CLK_ENABLE();   //使能GPIOG时钟
//    __HAL_RCC_GPIOI_CLK_ENABLE();   //使能GPIOI时钟
    
    //PB12, 13初始化设置
    GPIO_Initure.Pin=GPIO_PIN_12|GPIO_PIN_13;
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //推挽输出
    GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
    GPIO_Initure.Speed = GPIO_SPEED_FREQ_HIGH;     //快速
    HAL_GPIO_Init(GPIOB,&GPIO_Initure);
    IIC1_SDA=1;
    IIC1_SCL=1;
	
//    //PG13,14初始化设置
//    GPIO_Initure.Pin=GPIO_PIN_13|GPIO_PIN_14;
//    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //推挽输出
//    GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
//    GPIO_Initure.Speed=GPIO_SPEED_FAST;     //快速
//    HAL_GPIO_Init(GPIOG,&GPIO_Initure);
//    IIC2_SDA=1;
//    IIC2_SCL=1;
//	
//    //PI5,6初始化设置
//    GPIO_Initure.Pin=GPIO_PIN_5|GPIO_PIN_6;
//    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //推挽输出
//    GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
//    GPIO_Initure.Speed=GPIO_SPEED_FAST;     //快速
//    HAL_GPIO_Init(GPIOI,&GPIO_Initure);    
//    IIC3_SDA=1;
//    IIC3_SCL=1;  
	
	printf("I2c init success!!\n");
}

//产生IIC起始信号
void IIC_Start(u8 IIC_num)
{
	switch(IIC_num){
		case I2C_1:
		{
			IIC1_SDA_OUT();     //sda线输出
			IIC1_SDA=1;
			i2c_Delay();
			IIC1_SCL=1;
			i2c_Delay();
			IIC1_SDA=0;//START:when CLK is high,DATA change form high to low 
			i2c_Delay();
			IIC1_SCL=0;//钳住I2C总线，准备发送或接收数据 
			//printf("I2C_1 start!!!\n");			
		}break;
//		case I2C_2:
//		{
//			IIC2_SDA_OUT();     //sda线输出
//			IIC2_SDA=1;	  	  
//			IIC2_SCL=1;
//			delay_us(4);
//			IIC2_SDA=0;//START:when CLK is high,DATA change form high to low 
//			delay_us(4);
//			IIC2_SCL=0;//钳住I2C总线，准备发送或接收数据
//		}break;	
//		case I2C_3:
//		{
//			IIC3_SDA_OUT();     //sda线输出
//			IIC3_SDA=1;	  	  
//			IIC3_SCL=1;
//			delay_us(4);
//			IIC3_SDA=0;//START:when CLK is high,DATA change form high to low 
//			delay_us(4);
//			IIC3_SCL=0;//钳住I2C总线，准备发送或接收数据
//		}break;
	
	}	
 
}	  
//产生IIC停止信号
void IIC_Stop(u8 IIC_num)
{
	switch(IIC_num){
		case I2C_1:
		{
			IIC1_SDA_OUT();//sda线输出
			IIC1_SCL=0;
			IIC1_SDA=0;//STOP:when CLK is high DATA change form low to high
			i2c_Delay();
			IIC1_SCL=1; 
			i2c_Delay();			
			IIC1_SDA=1;//发送I2C总线结束信号
			//printf("I2C_1 stop!!!\n");
		}break;
//		case I2C_2:
//		{
//			IIC2_SDA_OUT();//sda线输出
//			IIC2_SCL=0;
//			IIC2_SDA=0;//STOP:when CLK is high DATA change form low to high
//			delay_us(4);
//			IIC2_SCL=1; 
//			delay_us(4);			
//			IIC2_SDA=1;//发送I2C总线结束信号
//		}break;		
//		case I2C_3:
//		{
//			IIC3_SDA_OUT();//sda线输出
//			IIC3_SCL=0;
//			IIC3_SDA=0;//STOP:when CLK is high DATA change form low to high
//			delay_us(4);
//			IIC3_SCL=1; 
//			delay_us(4);			
//			IIC3_SDA=1;//发送I2C总线结束信号
//		}break;	
	}	
}

//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
u8 IIC_Wait_Ack(u8 IIC_num)
{
		switch(IIC_num){
		case I2C_1:
		{
			u8 ucErrTime=0;
			IIC1_SDA_IN();      //SDA设置为输入  
			IIC1_SDA=1;i2c_Delay();	   
			IIC1_SCL=1;i2c_Delay();	 
			while(IIC1_READ_SDA)
			{
				ucErrTime++;
				if(ucErrTime>250)
				{			
					IIC_Stop(I2C_1);
					//printf("I2C_1 ACK fault!!!\n");
					return 1;
				}
			}
			IIC1_SCL=0;//时钟输出0 			
		}break;
//		case I2C_2:
//		{
//			u8 ucErrTime=0;
//			IIC2_SDA_IN();      //SDA设置为输入  
//			IIC2_SDA=1;delay_us(1);	   
//			IIC2_SCL=1;delay_us(1);	 
//			while(IIC2_READ_SDA)
//			{
//				ucErrTime++;
//				if(ucErrTime>250)
//				{
//					IIC_Stop(I2C_2);
//					//printf("I2C_2 fault!!!\n");
//					return 1;
//				}
//			}
//			IIC2_SCL=0;//时钟输出0  			
//		}break;
//		case I2C_3:
//		{
//			u8 ucErrTime=0;
//			IIC3_SDA_IN();      //SDA设置为输入  
//			IIC3_SDA=1;delay_us(1);	   
//			IIC3_SCL=1;delay_us(1);	 
//			while(IIC3_READ_SDA)
//			{
//				ucErrTime++;
//				if(ucErrTime>250)
//				{
//					IIC_Stop(I2C_3);
//					//printf("I2C_3 fault!!!\n");
//					return 1;
//				}
//			}
//			IIC3_SCL=0;//时钟输出0 			
//		}break;				
	}
		
	return 0;  
} 
//产生ACK应答
void IIC_Ack(u8 IIC_num)
{
	switch(IIC_num){
		case I2C_1:
		{
			IIC1_SCL=0;
			IIC1_SDA_OUT();
			IIC1_SDA=0;
			i2c_Delay();
			IIC1_SCL=1;
			i2c_Delay();
			IIC1_SCL=0;	
		}break;
//		case I2C_2:
//		{
//			IIC2_SCL=0;
//			IIC2_SDA_OUT();
//			IIC2_SDA=0;
//			delay_us(2);
//			IIC2_SCL=1;
//			delay_us(2);
//			IIC2_SCL=0;	
//		}break;	
//		case I2C_3:
//		{
//			IIC3_SCL=0;
//			IIC3_SDA_OUT();
//			IIC3_SDA=0;
//			delay_us(2);
//			IIC3_SCL=1;
//			delay_us(2);
//			IIC3_SCL=0;
//		}break;	
	}	

}
//不产生ACK应答		    
void IIC_NAck(u8 IIC_num)
{
	switch(IIC_num){
		case I2C_1:
		{
			IIC1_SCL=0;
			IIC1_SDA_OUT();
			IIC1_SDA=1;
			i2c_Delay();
			IIC1_SCL=1;
			i2c_Delay();
			IIC1_SCL=0;			
		}break;
//		case I2C_2:
//		{
//			IIC2_SCL=0;
//			IIC2_SDA_OUT();
//			IIC2_SDA=1;
//			delay_us(2);
//			IIC2_SCL=1;
//			delay_us(2);
//			IIC2_SCL=0;		
//		}break;		
//		case I2C_3:
//		{
//			IIC3_SCL=0;
//			IIC3_SDA_OUT();
//			IIC3_SDA=1;
//			delay_us(2);
//			IIC3_SCL=1;
//			delay_us(2);
//			IIC3_SCL=0;	
//		}break;		
	}
}					 				     
//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
void IIC_Send_Byte( u8 IIC_num, u8 txd)
{ 
	switch(IIC_num){
		case I2C_1:
		{
			u8 t;   
			IIC1_SDA_OUT(); 	    
			IIC1_SCL=0;//拉低时钟开始数据传输
			for(t=0;t<8;t++)
			{              
				IIC1_SDA=(txd&0x80)>>7;
				txd<<=1; 	  
				i2c_Delay();   //对TEA5767这三个延时都是必须的
				IIC1_SCL=1;
				i2c_Delay(); 
				IIC1_SCL=0;	
				i2c_Delay();
			}
		}break;	
//		case I2C_2:
//		{
//			u8 t;   
//			IIC2_SDA_OUT(); 	    
//			IIC2_SCL=0;//拉低时钟开始数据传输
//			for(t=0;t<8;t++)
//			{              
//				IIC2_SDA=(txd&0x80)>>7;
//				txd<<=1; 	  
//				delay_us(2);   //对TEA5767这三个延时都是必须的
//				IIC2_SCL=1;
//				delay_us(2); 
//				IIC2_SCL=0;	
//				delay_us(2);
//			}
//		}break;	
//		case I2C_3:
//		{
//			u8 t;   
//			IIC3_SDA_OUT(); 	    
//			IIC3_SCL=0;//拉低时钟开始数据传输
//			for(t=0;t<8;t++)
//			{              
//				IIC3_SDA=(txd&0x80)>>7;
//				txd<<=1; 	  
//				delay_us(2);   //对TEA5767这三个延时都是必须的
//				IIC3_SCL=1;
//				delay_us(2); 
//				IIC3_SCL=0;	
//				delay_us(2);
//			}
//		}break;	
	}		
	 
}

//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
u8 IIC_Read_Byte(u8 IIC_num, unsigned char ack)
{
	unsigned char i,receive=0;
	switch(IIC_num){
		case I2C_1:
		{
			IIC1_SDA_IN();//SDA设置为输入
			for(i=0;i<8;i++ )
			{
				IIC1_SCL=0; 
				i2c_Delay();
				IIC1_SCL=1;
				receive<<=1;
				if(IIC1_READ_SDA)receive++;   
				i2c_Delay(); 
			}					 
			if (!ack)
				IIC_NAck(I2C_1);//发送nACK
			else
				IIC_Ack(I2C_1); //发送ACK			
		}break;
//		case I2C_2:
//		{
//			IIC2_SDA_IN();//SDA设置为输入
//			for(i=0;i<8;i++ )
//			{
//				IIC2_SCL=0; 
//				delay_us(2);
//				IIC2_SCL=1;
//				receive<<=1;
//				if(IIC2_READ_SDA)receive++;   
//				delay_us(1); 
//			}					 
//			if (!ack)
//				IIC_NAck(I2C_2);//发送nACK
//			else
//				IIC_Ack(I2C_2); //发送ACK			
//		}break;
//		case I2C_3:
//		{
//			IIC3_SDA_IN();//SDA设置为输入
//			for(i=0;i<8;i++ )
//			{
//				IIC3_SCL=0; 
//				delay_us(2);
//				IIC3_SCL=1;
//				receive<<=1;
//				if(IIC3_READ_SDA)receive++;   
//				delay_us(1); 
//			}					 
//			if (!ack)
//				IIC_NAck(I2C_3);//发送nACK
//			else
//				IIC_Ack(I2C_3); //发送ACK			
//		}break;						
	} 
    return receive;
}

//u8 IIC_Read_OneByte(u8 deviceaddr, u8 readaddr)
//{
//  u8 temp;
//  IIC_Start();
//  IIC_Send_Byte(deviceaddr & 0xfe);
//  IIC_Wait_Ack();
//  IIC_Send_Byte(readaddr);
//  IIC_Wait_Ack();

//  IIC_Start();
//  IIC_Send_Byte(deviceaddr | 0x01);
//  IIC_Wait_Ack();
//  temp = IIC_Read_Byte(0);
//  IIC_Stop();
//  return temp;
//}

//void IIC_Write_OneByte(u8 deviceaddr, u8 writeaddr, u8 writedata)
//{
//  IIC_Start();
//  IIC_Send_Byte(deviceaddr & 0xfe);
//  IIC_Wait_Ack();
//  IIC_Send_Byte(writeaddr);
//  IIC_Wait_Ack();
//  IIC_Send_Byte(writedata);
//  IIC_Wait_Ack();
//  IIC_Stop();
//  CPU_TS_Tmr_Delay_US(10);
//}
