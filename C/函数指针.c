#include <stdio.h>

int square(int);

int square(int num)
{
	return num * num;
}
int main(){

	//ͨ������ָ�����square����
	int num;
	int (*fp)(int);//��square����ͬ��ӵ�����Ͳ��������ͷ���ֵ

	printf("������һ��������");
	scanf("%d",&num);

	fp = square;//�������൱�ں����ĵ�ַ����˾��൱�ڽ�square�����ĵ�ַ������

	printf("%d * %d = %d\n",num,num,(*fp)(num));

	return 0;
}
