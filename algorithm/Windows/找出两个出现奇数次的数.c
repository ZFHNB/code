#include <stdio.h>

int main() {
	int arr[10] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
	int eor = 0;
	for (int i = 0; i < 10; i++) {
		eor ^= arr[i];//eor = a^b
	}
	
	//�ҵ���ͬλ�ϵ�һ��Ϊ1��λ��
	int rightOne = eor & -eor;//-eor ��ȡ eor�Ĳ���, ��(~eor + 1)
	
	int a = 0;
	for (int i = 0; i < 10; i++) {
		if ((rightOne & arr[i]) != 0) {
			a ^= arr[i];
		}
	}
	int b = eor ^ a; //a^a^b

	printf("a = %d, b = %d", a, b);

	return 0;
}
