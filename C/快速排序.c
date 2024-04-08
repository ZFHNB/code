#include <stdio.h>

void quick_sort(int array[], int left, int right);

void quick_sort(int array[], int left, int right) {
	int i = left;
	int j = right;
	int temp;
	int pivot = array[(i + j) / 2]; //定义基准点

	while (i <= j) {
		//从左向右查找大于等于基准点的元素
		while (array[i] < pivot) {
			i++;
		}
		//从右向左查找小于等于基准点的元素
		while (array[j] > pivot) {
			j--;
		}
		//若i <= j,则交换i,j指向的数值
		if (i <= j) {
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	
	//递归调用
	if(j > left){
		quick_sort(array,left,j);
	}
	if(i < right){
		quick_sort(array,i,right);
	}
}

int main() {
	int array[] = {13, 54, 23, 64, 76, 87, 88, 43, 12};
	int i;
	int length = sizeof(array) / sizeof(array[0]);

	quick_sort(array, 0, length-1);

	printf("排序后的数组为：\n");

	for (i = 0; i < length; i++) {
		printf("%2d\n", array[i]);
	}
 
	return 0;
}
