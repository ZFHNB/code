#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// ��������
bool arraysEqual(int *array1, int *array2, int length);
void generateRandomArray(int *array, int length, int maxValue);
void copyArray(int *array1, int *array2, int length);
void swap(int *arr, int i, int j);
void quick_sort(int *array, int left, int right);
bool testSort(int maxSize, int maxValue);

void merge(int *array, int left, int mid, int right);
void process(int *array, int left, int right);

// �Ƚ����������Ƿ����
bool arraysEqual(int *array1, int *array2, int length) {
    for (int i = 0; i < length; i++) {
        if (array1[i] != array2[i]) {
            return false;
        }
    }
    return true;
}

// �����������
void generateRandomArray(int *array, int length, int maxValue) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        array[i] = rand() % maxValue;
    }
}

// ��������
void copyArray(int *array1, int *array2, int length) {
    for (int i = 0; i < length; i++) {
        array2[i] = array1[i];
    }
}

// ��������Ԫ��
void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// ����������
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

// ���������������ڲ��������㷨
// ������maxSize - �����С��maxValue - ��������ֵ
// ����ֵ��true��ʾ����������������ȣ�false��ʾ�����
bool testSort(int maxSize, int maxValue) {
    int array1[maxSize];
    int array2[maxSize];
    
    generateRandomArray(array1, maxSize, maxValue);
    copyArray(array1, array2, maxSize);

    quick_sort(array1, 0, maxSize - 1); // ʹ�ÿ�������Ե�һ����������
    process(array2, 0, maxSize-1);        // ʹ����һ�����򷽷��Եڶ�����������

    return arraysEqual(array1, array2, maxSize); // �Ƚ����������������Ƿ����
}

void process(int *array,int left, int right)
{
	if(left == right)
	{
		return;
	}
	int mid = left + ((right - left) >> 2);
	process(array, left, mid);
	process(array, mid+1, right);
	merge(array, left, mid, right);
}

void merge(int *array,int left,int mid,int right)
{
    int p1 = left,p2 = mid+1;
    int help[right - left + 1];
    int i = 0;
    while(p1 <= mid && p2 <= right)
    {
		help[i++] = array[p1] <= array[p2] ? array[p1++] : array[p2++];
	}
	while(p1<=mid)
	{
		help[i++] = array[p1++];
	}
	while(p2<=right)
	{
		help[i++] = array[p2++];
	}
	for(i = 0; i< right - left + 1; i++)
	{
		array[left+i] = help[i];
	}
}

int main() {
    int maxTime = 50000;
    int maxSize = 100;
    int maxValue = 10000;
    bool succeed = true;

    // ���ж�ζ�������
    for (int i = 0; i < maxTime; i++) {
        if (!testSort(maxSize, maxValue)) {
            succeed = false;
            break;
        }
    }

    // ������Խ��
    printf("%s\n", succeed ? "Congratulations! Arrays are equal." : "Arrays are not equal. Good luck.");

    return 0;
}
