#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	
	int *ptr1 = NULL;
	int *ptr2 = NULL;
	
	//第一次申请的内存空间
	ptr1 = (int *)malloc(10*sizeof(int));
	
	//进行若干操作后，若ptr1申请的内存空间不够用
	
	//第二次申请的内存空间
	ptr2 = (int *)malloc(20*sizeof(int));
	
	//将ptr1拷贝至ptr2中
	memcpy(ptr1, ptr2, 10);
	free(ptr1);
	
	//对ptr2进行若干操作...
	
	free(ptr2);
	
	return 0;
}
