#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define InitSize 10

typedef struct{
	int length;//当前长度
	ElemType *data;
	int MaxSize;//最大长度
}SqList;

void InitList(SqList *L)
{
	L->data = (ElemType *)malloc(sizeof(ElemType)*InitSize);
	L->length = 0;
	L->MaxSize = InitSize;
	int n = 0;
	printf("请输入数据个数：\n");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("data[%d] = ",i);
		scanf(" %d", &L->data[i]);
	}
	L->length = n;
}

void PrintList(SqList *L)
{
	for(int i = 0; i < L->length; i++)
	{
		printf("data[%d] = %d\n", i,L->data[i]);	
	}
}

int main()
{
	SqList *L = (SqList *)malloc(sizeof(ElemType)*InitSize);
	InitList(L);
	PrintList(L);

	return 0;
}
