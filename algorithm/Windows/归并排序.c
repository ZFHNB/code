#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// 函数声明
bool arraysEqual(int *array1, int *array2, int length);
void generateRandomArray(int *array, int length, int maxValue);
void copyArray(int *array1, int *array2, int length);
void swap(int *arr, int i, int j);
void quick_sort(int *array, int left, int right);
bool testSort(int maxSize, int maxValue);

void merge(int *array, int left, int mid, int right);
void process(int *array, int left, int right);

// 比较两个数组是否相等
bool arraysEqual(int *array1, int *array2, int length) {
    for (int i = 0; i < length; i++) {
        if (array1[i] != array2[i]) {
            return false;
        }
    }
    return true;
}

// 生成随机数组
void generateRandomArray(int *array, int length, int maxValue) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        array[i] = rand() % maxValue;
    }
}

// 复制数组
void copyArray(int *array1, int *array2, int length) {
    for (int i = 0; i < length; i++) {
        array2[i] = array1[i];
    }
}

// 交换数组元素
void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// 快速排序函数
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

// 对数器函数，用于测试排序算法
// 参数：maxSize - 数组大小，maxValue - 随机数最大值
// 返回值：true表示两个排序后的数组相等，false表示不相等
bool testSort(int maxSize, int maxValue) {
    int array1[maxSize];
    int array2[maxSize];
    
    generateRandomArray(array1, maxSize, maxValue);
    copyArray(array1, array2, maxSize);

    quick_sort(array1, 0, maxSize - 1); // 使用快速排序对第一个数组排序
    process(array2, 0, maxSize-1);        // 使用另一种排序方法对第二个数组排序

    return arraysEqual(array1, array2, maxSize); // 比较两个排序后的数组是否相等
}

void process(int *array, int left, int right)
{
	if(left == right)
		return;
	int mid = left + ((right-left) >> 1);
	process(array, left, mid);
	process(array, mid+1, right);
	merge(array,left,mid,right);
}

void merge(int *array, int left, int mid, int right)
{
    int p1 = left, p2 = mid + 1;
    int help[right - left + 1];
    int i = 0;

    while (p1 <= mid && p2 <= right)
    {
        help[i++] = array[p1] <= array[p2] ? array[p1++] : array[p2++];
    }
    while (p1 <= mid)
    {
        help[i++] = array[p1++];
    }
    while (p2 <= right)
    {
        help[i++] = array[p2++];
    }
    for (i = 0; i < (sizeof(help) / sizeof(help[0])); i++)
    {
        array[left + i] = help[i];
    }
}

int main() {
    int maxTime = 50000;
    int maxSize = 100;
    int maxValue = 10000;
    bool succeed = true;

    // 进行多次对数测试
    for (int i = 0; i < maxTime; i++) {
        if (!testSort(maxSize, maxValue)) {
            succeed = false;
            break;
        }
    }

    // 输出测试结果
    printf("%s\n", succeed ? "Congratulations! Arrays are equal." : "Arrays are not equal. Good luck.");

    return 0;
}
