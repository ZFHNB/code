#include <STC89C5xRC.H>
#include <INTRINS.H>

unsigned char NixieTable[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x00,};

void Delay(unsigned int xms)	//@11.0592MHz
{
	while(xms--)
	{
		unsigned char data i, j;

		_nop_();
		_nop_();
		i = 2;
		j = 15;
		do
		{
			while (--j);
		} while (--i);
	}
}




void Nixie(unsigned char Location, Number)
{
	switch(Location)
	{
		case 1:
			P24 = 1; P23 = 1; P22 = 1;break;
		case 2:
			P24 = 1; P23 = 1; P22 = 0;break;
		case 3:
			P24 = 1; P23 = 0; P22 = 1;break;
		case 4:
			P24 = 1; P23 = 0; P22 = 0;break;
		case 5:
			P24 = 0; P23 = 1; P22 = 1;break;
		case 6:
			P24 = 0; P23 = 1; P22 = 0;break;
		case 7:
			P24 = 0; P23 = 0; P22 = 1;break;
		case 8:
			P24 = 0; P23 = 0; P22 = 0;break;
	}
	P0 = NixieTable[Number];
	Delay(1);//稳定显示
	P0 = 0x00;//消影
}
	
void main()
{
	while(1)
	{
		Nixie(1,10);
		Nixie(2,11);
		Nixie(3,12);
		Nixie(4,13);
		Nixie(5,14);
		Nixie(6,15);
	}
}