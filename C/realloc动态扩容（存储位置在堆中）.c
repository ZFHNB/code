#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	int num, i;
	int count = 0;
	int *ptr;
	
	while(num != -1){
		printf("������һ������������-1��������");
		scanf("%d",&num);
		count++;
		
		ptr = (int *)realloc(ptr,count*sizeof(int));
		if(ptr == NULL){
			exit(1);
		}
		
		ptr[count - 1] = num;
	}
	
	printf("����������ֱ��ǣ�\n");
	
	for(int i=0;i<count-1;i++){
		printf("%d\n",ptr[i]);
	}
	
	free(ptr);
	
	return 0;
}
