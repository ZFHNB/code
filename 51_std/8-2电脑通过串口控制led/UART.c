#include <STC89C5xRC.H>

/**
  * @brief 串口初始化9600bps@11.0592MHz
  * @param  无
  * @retval 无
  */
void UART_Init()
{
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xFA;			//设置定时初始值
	TH1 = 0xFA;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
	ES = 1;				//使能串口1中断
	EA = 1;				//启动总中断
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

/*串口中断函数模板
void UART_Routine() interrupt 4	//interrupt后的数字决定此函数的中断类型
{
	if(RI==1)//若为1，则为接收中断
	{

		RI = 0;//RI与TI一样，需要软件中置为0
	}
}
*/
