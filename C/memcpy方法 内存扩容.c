#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	
	int *ptr1 = NULL;
	int *ptr2 = NULL;
	
	//��һ��������ڴ�ռ�
	ptr1 = (int *)malloc(10*sizeof(int));
	
	//�������ɲ�������ptr1������ڴ�ռ䲻����
	
	//�ڶ���������ڴ�ռ�
	ptr2 = (int *)malloc(20*sizeof(int));
	
	//��ptr1������ptr2��
	memcpy(ptr1, ptr2, 10);
	free(ptr1);
	
	//��ptr2�������ɲ���...
	
	free(ptr2);
	
	return 0;
}
