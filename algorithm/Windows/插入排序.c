#include <stdio.h>

void swap(int *arr, int i, int j);
void InsertSort(int *array, int length);

void InsertSort(int *array, int length) {
	for (int i = 1; i < length; i++) {//0~iÉÏÓÐÐò
		for (int j = i - 1; j >= 0 && array[j] > array[j + 1]; j--) {
			swap(array, j, j + 1);
		}

	}
}

void swap(int *arr, int i, int j) {
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main() {
	int array[] = {231, 435, 46, 87, 32, 5, 86, 87, 213};
	int length = sizeof(array) / sizeof(int);

	InsertSort(array, length);

	for (int i = 0; i < length; i++) {
		printf("%d\n", array[i]);
	}

	return 0;
}
