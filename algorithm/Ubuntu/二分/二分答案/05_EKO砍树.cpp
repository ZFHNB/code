#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1000010;

int n, m;
int a[N];

bool is_enough(int x)
{
    int sum = 0; // 记录得到的总长度
    for (int i = 0; i < n; i++)
    {
        sum += max(0, a[i] - x);
        if (sum >= m)
        {
            return true;
        }
    }
    return false;
}

int binary(int l, int r)
{
    while (l + 1 < r)
    {
        int mid = l + ((r - l) >> 1);
        if (is_enough(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if (is_enough(r))
    {
        return r;
    }
    return l;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);
    int hest = a[n - 1]; // 记录最大树高

    int res = binary(-1, hest + 1);//取数组两端外（紧挨）的值
    printf("%d", res);

    return 0;
}