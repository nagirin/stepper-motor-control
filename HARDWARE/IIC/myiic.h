#ifndef _MYIIC_H
#define _MYIIC_H
#include "main.h"


//IO��������
#define IIC1_SDA_IN()  	{GPIOB->MODER&=~(3<<(7*2));	GPIOB->MODER|=0<<7*2;}		//PB7����ģʽ
#define IIC1_SDA_OUT() 	{GPIOB->MODER&=~(3<<(7*2));	GPIOB->MODER|=1<<7*2;} 		//PB7���ģʽ
#define IIC2_SDA_IN()  	{GPIOG->MODER&=~(3<<(14*2));GPIOG->MODER|=0<<14*2;}		//PG14����ģʽ
#define IIC2_SDA_OUT() 	{GPIOG->MODER&=~(3<<(14*2));GPIOG->MODER|=1<<14*2;} 	//PG14���ģʽ
#define IIC3_SDA_IN()  	{GPIOI->MODER&=~(3<<(6*2));	GPIOI->MODER|=0<<6*2;}		//PI6����ģʽ
#define IIC3_SDA_OUT() 	{GPIOI->MODER&=~(3<<(6*2));	GPIOI->MODER|=1<<6*2;} 		//PI6���ģʽ
//IO����
#define IIC1_SCL   		PBout(6) //SCL
#define IIC1_SDA   		PBout(7) //SDA
#define IIC1_READ_SDA  	PBin(7)  //����SDA
#define IIC2_SCL   		PGout(13) //SCL
#define IIC2_SDA   		PGout(14) //SDA
#define IIC2_READ_SDA  	PGin(14)  //����SDA
#define IIC3_SCL   		PIout(5) //SCL
#define IIC3_SDA   		PIout(6) //SDA
#define IIC3_READ_SDA  	PIin(6)  //����SDA

enum
{
    I2C_1 = 0,
    I2C_2,
    I2C_3,
    I2C_4,
    I2C_5,
    I2C_MAX
};


//IIC���в�������
void IIC_Init(void);                //��ʼ��IIC��IO��				 
void IIC_Start(u8 IIC_num);				//����IIC��ʼ�ź�
void IIC_Stop(u8 IIC_num);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(u8 IIC_num, uint8_t txd);			//IIC����һ���ֽ�
u8 IIC_Read_Byte(u8 IIC_num, unsigned char ack);//IIC��ȡһ���ֽ�
u8 IIC_Wait_Ack(u8 IIC_num); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(u8 IIC_num);					//IIC����ACK�ź�
void IIC_NAck(u8 IIC_num);				//IIC������ACK�ź�

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
uint8_t IIC_Read_One_Byte(u8 daddr,u8 addr);	 
#endif

