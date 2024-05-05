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
    printf("请输入一个数字:");
    scanf("%d",&input);
    
    printf("该数字的阶乘为：%ld",fac(input));

	return 0;
}
