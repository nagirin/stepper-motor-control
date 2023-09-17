#ifndef _MYIIC_H
#define _MYIIC_H
#include "main.h"


//IO方向设置
#define IIC1_SDA_IN()  	{GPIOB->MODER&=~(3<<(7*2));	GPIOB->MODER|=0<<7*2;}		//PB7输入模式
#define IIC1_SDA_OUT() 	{GPIOB->MODER&=~(3<<(7*2));	GPIOB->MODER|=1<<7*2;} 		//PB7输出模式
#define IIC2_SDA_IN()  	{GPIOG->MODER&=~(3<<(14*2));GPIOG->MODER|=0<<14*2;}		//PG14输入模式
#define IIC2_SDA_OUT() 	{GPIOG->MODER&=~(3<<(14*2));GPIOG->MODER|=1<<14*2;} 	//PG14输出模式
#define IIC3_SDA_IN()  	{GPIOI->MODER&=~(3<<(6*2));	GPIOI->MODER|=0<<6*2;}		//PI6输入模式
#define IIC3_SDA_OUT() 	{GPIOI->MODER&=~(3<<(6*2));	GPIOI->MODER|=1<<6*2;} 		//PI6输出模式
//IO操作
#define IIC1_SCL   		PBout(6) //SCL
#define IIC1_SDA   		PBout(7) //SDA
#define IIC1_READ_SDA  	PBin(7)  //输入SDA
#define IIC2_SCL   		PGout(13) //SCL
#define IIC2_SDA   		PGout(14) //SDA
#define IIC2_READ_SDA  	PGin(14)  //输入SDA
#define IIC3_SCL   		PIout(5) //SCL
#define IIC3_SDA   		PIout(6) //SDA
#define IIC3_READ_SDA  	PIin(6)  //输入SDA

enum
{
    I2C_1 = 0,
    I2C_2,
    I2C_3,
    I2C_4,
    I2C_5,
    I2C_MAX
};


//IIC所有操作函数
void IIC_Init(void);                //初始化IIC的IO口				 
void IIC_Start(u8 IIC_num);				//发送IIC开始信号
void IIC_Stop(u8 IIC_num);	  			//发送IIC停止信号
void IIC_Send_Byte(u8 IIC_num, uint8_t txd);			//IIC发送一个字节
u8 IIC_Read_Byte(u8 IIC_num, unsigned char ack);//IIC读取一个字节
u8 IIC_Wait_Ack(u8 IIC_num); 				//IIC等待ACK信号
void IIC_Ack(u8 IIC_num);					//IIC发送ACK信号
void IIC_NAck(u8 IIC_num);				//IIC不发送ACK信号

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
uint8_t IIC_Read_One_Byte(u8 daddr,u8 addr);	 
#endif

