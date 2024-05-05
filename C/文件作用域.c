#include <stdio.h>

void func(void);

int main()
{
	extern int count;//此处表示有全局变量count的声明，但不一定在此count所属函数之前
	
	func();
	count++;
	printf("In main, count = %d\n", count);
	
	return 0;
}

int count;//从此处声明count，若要在此语句前访问count，需要使用extern

void func (void)
{
	count ++;
	printf("In func, count = %d\n", count);
}
