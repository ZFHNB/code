#include <stdio.h>

int count;//���÷�ΧΪ�������򣬼�ÿ�������ж��ɷ���

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
	
	printf("��ǰcount��ֵΪ��%d",count);
	
	return 0;
}
