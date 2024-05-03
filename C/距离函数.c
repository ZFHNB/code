#include <stdio.h>
#include <math.h>

double dis2(int x[], int y[]) {
	return (sqrt(pow(x[1] - x[0], 2) + pow(y[1] - y[0], 2)) + sqrt(pow(x[2] - x[0], 2) + pow(y[2] - y[0], 2)) + sqrt(pow(x[1] - x[2], 2) + pow(y[1] - y[2], 2)));
}

int main() {
	int x[3];
	int y[3];

	for (int i = 0; i < 3; i++) {
		scanf("%d", &x[i]);
		scanf("%d", &y[i]);
	}
	printf("%.2lf", dis2(x, y));

	return 0;
}
