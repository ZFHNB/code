#include <stdio.h>

long fac(int);

long fac(int a)
{
	long res;
	if(a > 0)
	{
		res = a*fac(a - 1);
	}
	else
	{
		res = 1;
	}
	return res;
}

int main()
{
	int input;
    printf("������һ������:");
    scanf("%d",&input);
    
    printf("�����ֵĽ׳�Ϊ��%ld",fac(input));

	return 0;
}
