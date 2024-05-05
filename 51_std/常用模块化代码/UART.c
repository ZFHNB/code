#include <STC89C5xRC.H>

/**
  * @brief 串口初始化9600bps@11.0592MHz
  * @param  无
  * @retval 无
  */
void UART_Init()
{
	SCON = 0x50;		//8位数据,可变波特率
	PCON |= 0x80;		//使能波特率倍速位SMOD
	TMOD &= 0x0F;			//设置定时器模式
	TMOD |= 0x20;			//设置定时器1模式为8位自动重装
	TL1 = 0xFA;			//设置定时初始值
	TH1 = 0xFA;			//设置定时重载值
	ET1 = 0;			//禁止定时器1中断
	TR1 = 1;			//定时器1开始计时
}

/**
  * @brief 串口发送一个字节数据
  * @param  Byte 要发送的一字节数据
  * @retval 无
  */
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI == 0);//TI为发送中断请求标志位，即未发送时此句产生阻塞，防止数据错误
	TI = 0;//串口模式1中需用软件进行复位
}
