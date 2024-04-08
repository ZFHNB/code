#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

bool arraysEqual(int *array1, int *array2, int length) {
	bool equle=1;
	for(int i = 0;i<length;i++)
	{
		equle = (array1[i] == array2[i]);
		if(!equle)
			return equle;
	}
	return equle;
}

void generateRandomArray(int *array, int length, int maxValue) {
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		array[i] = rand() % maxValue;
	}
}

//param：array1为原数组，arrray2为目标数组
void copyArray(int *array1, int *array2, int length) {
	for (int i = 0; i < length; i++) {
		array2[i] = array1[i];
	}
}

void swap(int *arr, int i, int j) {
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void quick_sort(int *array, int left, int right) {
	int i = left, j = right;
	int pivot;

	pivot = (array[left] + array[right]) / 2;
	while (i <= j) { //每一部分的排序方法
		//从左到右找到大于等于基准点的元素
		while (array[i] < pivot) {
			i++;
		}
		//从右到左找到小于等于基准点的元素
		while (array[j] > pivot) {
			j--;
		}
		//如果 i<=j ,则互换
		if (i <= j) {
			swap(array, i, j);
			i++;
			j--;
		}
	}

	//划分子序列,并给出结束条件
	if (left < j) {
		quick_sort(array, left, j);
	}
	if (right > i) {
		quick_sort(array, i, right);
	}
}

void InsertSort(int *array, int length) {
	for (int i = 1; i < length; i++) {//0~i上有序
		for (int j = i - 1; j >= 0 && array[j] > array[j + 1]; j--) {
			swap(array, j, j + 1);
		}

	}
}

int main() {

	int maxTime = 50000;
	int maxSize = 100;
	int maxValue = 10000;
	bool succeed = 1;

	for (int i = 0; i < maxTime; i++) {
		//新建两个相同随机数组
		int array1[maxSize];
		int array2[maxSize];
		generateRandomArray(array1, maxSize, maxValue);
		copyArray(array1, array2, maxSize);

		int length = sizeof(array1) / sizeof(array1[0]);

		quick_sort(array1, 0, length - 1);//待测试方法
		InsertSort(array2, length);//对照方法

		if (!arraysEqual(array1, array2,length)) {
			for (int j = 0; j < maxSize; j--) {
				printf("%d\t", array1[j]);
				printf("%d\n", array2[j]);
			}
			succeed = 0;
			break;
		}
	}
	printf("%s",succeed?"congratulation" : "good luck");

	return 0;
}
