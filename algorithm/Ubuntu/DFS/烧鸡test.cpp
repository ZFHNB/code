#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 20

int n;
int arr[N];//存储结果
int res;//存总方案数
int mem[59050][N];

//x 表示当前枚举到了第几位,sum 表示当前枚举的美味程度
void dfs(int x, int sum) {
	if (sum > n) {
		return ;
	}

	if (x > 10) {
		if (sum == n) {
			res ++;
			for (int j = 1; j <= 10; j++) {
				mem[res][j] = arr[j];
			}
		}
		return ;
	}

	for (int i = 1; i <= 3; i++) {
		arr[x] = i;
		dfs(x + 1, sum + i);
		arr[x] = 0;//恢复现场
	}
}

int main() {
	scanf("%d", &n);
	dfs(1, 0);
	printf("%d\n", res);
	for(int i = 1; i <= res; i++)
	{
		for(int j = 1; j <= 10; j++)
		{
			printf("%d ",mem[i][j]);
		}
		printf("\n");
	}

	return 0;
}
