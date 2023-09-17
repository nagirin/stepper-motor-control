#ifndef __MD_AS5600_H
#define __MD_AS5600_H

//AS5600_X	
/* 
DIR		GND
SCL		PB6
SDA		PB7
PGO		����

*/ 



#include "stm32f4xx_hal.h"  //�����Ҫ���ݲ�ͬ��оƬ���ͽ��б任
#include "main.h"


typedef enum
{
/* set i2c address */ 
  _ams5600_Address = 0x36,
  _zmco = 0x00,
  _zpos_hi = 0x01,
  _zpos_lo = 0x02,
  _mpos_hi = 0x03,
  _mpos_lo = 0x04,
  _mang_hi = 0x05,
  _mang_lo = 0x06,
  _conf_hi = 0x07,    
  _conf_lo = 0x08,
  _raw_ang_hi = 0x0c,
  _raw_ang_lo = 0x0d,
  _ang_hi = 0x0e,
  _ang_lo = 0x0f,
  _stat = 0x0b,
  _agc = 0x1a,
  _mag_hi = 0x1b,
  _mag_lo = 0x1c,
  _burn = 0xff
}AMS5600Registers_t;


void PrintMenu(void);
uint8_t As5600Run(uint8_t IIC_num);
#endif 
		
