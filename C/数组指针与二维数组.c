#include <stdio.h>

int main() {

    int array[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    int (*p)[4] = array;//�������߱�����:(p+i)�Ŀ��Ϊ: i * ��ά������Ԫ���� * sizeof(int))
//�˴���Ϊ int **p = array;��(p+i)�Ŀ��Ϊ: i * sizeof(int)
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf(" %2d", *(*(p + i) + j));
        }
        printf("\n");
    }
    
    printf("*****************\n");
    
    printf("&array:%p\n",&array);
	printf("array:%p\n",array);
	printf("p:%p\n",p);

    return 0;
}
