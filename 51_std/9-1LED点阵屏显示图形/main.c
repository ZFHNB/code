#include <STC89C5xRC.H>
#include "Delay.h"

sbit RCK=P3^5;		//ECLK
sbit SCK=P3^6;		//SRCLK
sbit SER=P3^4;		//SER

#define MATRIX_LED_PORT		P0

/**
  * @brief 74HC595写入一个字节数据
  * @param  要写入的字节
  * @retval 无
  */
void _74HC595_WritrByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0; i<8; i++)
	{
		SER=Byte&(0x80>>i);
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;
}

/**
	* @brief LED点阵屏显示一列数据
  * @param  Column 要选择的列，范围：0~7
	* @param	Data 选择的列要显示的数据，范围0x00~0xff，高位在上，1为亮，0为灭
  * @retval 无
  */
void MatrixLED_ShowColumn(unsigned char Column,Data)
{
	_74HC595_WritrByte(Data);
	MATRIX_LED_PORT=~(0x80>>Column);//低电平有效
	Delay(1);
	MATRIX_LED_PORT=0xff;
}

void main()
{
	SCK=0;
	RCK=0;
	while(1)
	{
		MatrixLED_ShowColumn(0,0x3c);
		MatrixLED_ShowColumn(1,0x42);
		MatrixLED_ShowColumn(2,0xa9);
		MatrixLED_ShowColumn(3,0x85);
		MatrixLED_ShowColumn(4,0x85);
		MatrixLED_ShowColumn(5,0xa9);
		MatrixLED_ShowColumn(6,0x42);
		MatrixLED_ShowColumn(7,0x3c);
	}
}
