#include <STC89C5xRC.H>
#include <INTRINS.H>

#define XMS 500

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


void main(void)
{
	while(1)
	{
		if(P31 == 0)
		{
			Delay(20);//��������ʱ�İ�������
			while(P31 == 0);//��ʱ��ť���ڴ���״̬
			Delay(20);//��������ʱ�İ�������
			
			P20 = ~P20;
		}
	}
}
