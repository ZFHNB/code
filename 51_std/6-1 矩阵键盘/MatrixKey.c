#include <STC89C5xRC.H>
#include "Delay.h"

/**
  * @brief 矩阵键盘读取按键键码
  * @param  无
  * @retval 返回值KeyNumber为按下按键的键码4值
	若按钮按下不放，程序会停留在此函数，松手一瞬间返回按钮键码，没有按钮按下时返回0
  */
unsigned char MatrixKey()
{
	unsigned char KeyNumber = 0;
	P1 = 0xff;
	P13 = 0;
	if(P17 == 0)
	{Delay(20);while(P17 == 0);/*检测松手*/KeyNumber = 1;}
	if(P16 == 0)
	{Delay(20);while(P16 == 0);/*检测松手*/KeyNumber = 5;}
	if(P15 == 0)
	{Delay(20);while(P15 == 0);/*检测松手*/KeyNumber = 9;}
	if(P14 == 0)
	{Delay(20);while(P14 == 0);/*检测松手*/KeyNumber = 13;}
	
	P1 = 0xff;
	P12 = 0;
	if(P17 == 0)
	{Delay(20);while(P17 == 0);/*检测松手*/KeyNumber = 2;}
	if(P16 == 0)
	{Delay(20);while(P16 == 0);/*检测松手*/KeyNumber = 6;}
	if(P15 == 0)
	{Delay(20);while(P15 == 0);/*检测松手*/KeyNumber = 10;}
	if(P14 == 0)
	{Delay(20);while(P14 == 0);/*检测松手*/KeyNumber = 14;}
	
	P1 = 0xff;
	P11 = 0;
	if(P17 == 0)
	{Delay(20);while(P17 == 0);/*检测松手*/KeyNumber = 3;}
	if(P16 == 0)
	{Delay(20);while(P16 == 0);/*检测松手*/KeyNumber = 7;}
	if(P15 == 0)
	{Delay(20);while(P15 == 0);/*检测松手*/KeyNumber = 11;}
	if(P14 == 0)
	{Delay(20);while(P14 == 0);/*检测松手*/KeyNumber = 15;}
	
	P1 = 0xff;
	P10 = 0;
	if(P17 == 0)
	{Delay(20);while(P17 == 0);/*检测松手*/KeyNumber = 4;}
	if(P16 == 0)
	{Delay(20);while(P16 == 0);/*检测松手*/KeyNumber = 8;}
	if(P15 == 0)
	{Delay(20);while(P15 == 0);/*检测松手*/KeyNumber = 12;}
	if(P14 == 0)
	{Delay(20);while(P14 == 0);/*检测松手*/KeyNumber = 16;}
	return KeyNumber;
}