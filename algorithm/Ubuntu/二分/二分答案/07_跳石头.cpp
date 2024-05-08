#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 50010; 
int a[N];
int l;//起点到终点的距离
int n;//起点和终点之间的岩石数
int m;//组委会至多移走的岩石数

int main()
{
    scanf("%d %d %d", &l, &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    a[n + 1] = m;

    int l = 0, r = l + 1;

    return 0;
}