#include <stdio.h>

int square(int);

int square(int num)
{
	return num * num;
}
int main(){

	//通过函数指针调用square函数
	int num;
	int (*fp)(int);//和square函数同样拥有整型参数与整型返回值

	printf("请输入一个整数：");
	scanf("%d",&num);

	fp = square;//函数名相当于函数的地址，则此句相当于将square函数的地址传过来

	printf("%d * %d = %d\n",num,num,(*fp)(num));

	return 0;
}
