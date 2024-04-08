#include <stdio.h>

int main() {
	int total;
	int moneyNum=0;
	int money[7] = {100, 50, 20, 10, 5, 2, 1};
	scanf("%d", &total);
	printf("%d\n",total);

	for (int i = 0; i < 7; i++)
	{
		moneyNum = total / money[i];
		total %= money[i];
		printf("%d nota(s) de R$ %d,00\n", moneyNum, money[i]);
	}
	

	return 0;
}
