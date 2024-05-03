#include <stdio.h>

int count;//作用范围为整个程序，即每个函数中都可访问

void a();
void b();
void c();

void a()
{
	count++;
}
void b()
{
	count++;
}
void c()
{
	count++;
}

int main()
{
	a();
	b();
	c();
	c();
	
	printf("当前count的值为：%d",count);
	
	return 0;
}
