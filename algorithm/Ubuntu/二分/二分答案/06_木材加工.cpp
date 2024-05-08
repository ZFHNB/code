#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 100010

int n, k;
int a[N];

bool process(int x)
{
    int sum = 0; // 记录获取的总段数
    for (int i = 0; i < n; i++)
    {
        sum += (a[i] / x);
        if (sum >= k)
            return true;
    }
    return false;
}

void binary(int l, int r)
{
    while (l + 1 < r)
    {
        int mid = l + ((r - l) >> 1);
        if (process(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if (process(r))
    {
        printf("%d", r);
    }
    printf("%d", l);
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int res = 0;

    sort(a, a + n);         // 对数组排序
    int longest = a[n - 1]; // 取出最长长度

    binary(0, longest); // 取数组两端外（紧挨）的值

    return 0;
}