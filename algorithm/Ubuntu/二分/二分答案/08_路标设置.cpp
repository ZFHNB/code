#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

// L: 公路总长度
// n: 原有路标数
// k: 最多可增路标数
int L, n, k;
int a[N], s[N]; // a: 路标位置数组，s: 相邻路标之间的距离数组

// 检查以x为长度插入路标后，是否有路段都大于等于 x 长度
bool check(int x)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt+= (s[i]-1)/x;
    }
    if(cnt <= k) return true;
    else return false;
}

int main()
{
    scanf("%d %d %d", &L, &n, &k); // 长度、原有路标数、最多可增路标数
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]); // 输入每个路标距起点的距离
        s[i] = a[i] - a[i - 1]; // 计算相邻路标的距离
    }

    a[n + 1] = L; // 公路终点
    s[n + 1] = L - a[n];

    int l = 0, r = L+1;
    while (l + 1 < r)
    {
        int mid = l + ((r - l) >> 1);
        if (check(mid)) r = mid; // 要让操作次数小于等于所给出的值
        else l = mid;
    }
    printf("%d\n", r);

    return 0;
}