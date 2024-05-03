#include <stdio.h>

#define MAX_N 100000

int max(int, int);
int min(int, int);

int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}

int main() {

	int num;//������
	int L;//���ӳ���
	int n;//��������
	int x[MAX_N];

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &L);
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &x[j]);
		}

		int maxT = 0;
		int minT = 0;

		//���ʱ��
		for (int j = 0; j < n; j++) {
			minT = max(minT, min(x[j], L - x[j]));
		}
		//�ʱ��
		for (int j = 0; j < n; j++) {
			maxT = max(maxT, max(x[j], L - x[j]));
		}

		printf("%d %d\n", minT, maxT);
	}

	return 0;
}
