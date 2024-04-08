#include <stdio.h>
#include <stdlib.h>

int *func(void){
	int *ptr = NULL;
	
	ptr = (int *)malloc(sizeof(int));//通过访问内存地址来获取函数内的局部变量值
	if(ptr == NULL){
		exit(1);
	}
	
	*ptr = 520;
	
	return ptr;
}


int main(){
	
	int* ptr = NULL;
	
	ptr = func();
	
	printf("%d\n",*ptr);
	
	free(ptr);
	
	return 0;
}
