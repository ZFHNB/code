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

//param��array1Ϊԭ���飬arrray2ΪĿ������
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
	while (i <= j) { //ÿһ���ֵ����򷽷�
		//�������ҵ����ڵ��ڻ�׼���Ԫ��
		while (array[i] < pivot) {
			i++;
		}
		//���ҵ����ҵ�С�ڵ��ڻ�׼���Ԫ��
		while (array[j] > pivot) {
			j--;
		}
		//��� i<=j ,�򻥻�
		if (i <= j) {
			swap(array, i, j);
			i++;
			j--;
		}
	}

	//����������,��������������
	if (left < j) {
		quick_sort(array, left, j);
	}
	if (right > i) {
		quick_sort(array, i, right);
	}
}

void InsertSort(int *array, int length) {
	for (int i = 1; i < length; i++) {//0~i������
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
		//�½�������ͬ�������
		int array1[maxSize];
		int array2[maxSize];
		generateRandomArray(array1, maxSize, maxValue);
		copyArray(array1, array2, maxSize);

		int length = sizeof(array1) / sizeof(array1[0]);

		quick_sort(array1, 0, length - 1);//�����Է���
		InsertSort(array2, length);//���շ���

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
