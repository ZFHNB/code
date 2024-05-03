#include <STC89C5xRC.H>
#include <INTRINS.H>

void Delay(unsigned int xms)	//@11.0592MHz
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


void main()
{
	int i = 0x01;
	while(1)
	{
		if(P31 == 0)
		{
			Delay(20);
			while(p31 == 0);
			Delay(20);
			
			if(i == 0xff)
				i=0x01;
			P2 = i++;
		}
	}
}