#include <stdio.h>

void swap(int *array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void quick_sort(int *array, int L, int R) {
	int i = L,j=R;
	int pivot = (array[L] + array[R])/2;
	while(i<=j)
	{
		while(array[i] < pivot)
		{
			i++;
		}
		while(array[j] > pivot)
		{
			j--;
		}
		if(i<=j)
		{
			swap(array, i ,j);
			i++;
			j--;
		}
	}
	if(L<j)
	{
		quick_sort(array, L, j);
	}
	if(R>i)
	{
		quick_sort(array, i, R);
	}
}

int main() {
	int array[] = {123, 435, 656, 78, 9, 324, 57};
	int length = sizeof(array) / sizeof(array[0]);
	quick_sort(array, 0, length - 1);

	for (int i = 0; i < length; i++) {
		printf("%d\t", array[i]);
	}

	return 0;
}
