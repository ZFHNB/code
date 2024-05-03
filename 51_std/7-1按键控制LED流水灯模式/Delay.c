#include <INTRINS.H>
/**
  * @brief 设定参数对应的延时毫秒数
  * @param  xms 需要延时多少毫秒
  * @retval 无
  */
void Delay(unsigned int xms)	//@11.0592MHz
{
	while(xms--)
	{
		unsigned char data i, j;

		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

