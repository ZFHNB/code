#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 50010;
int n, k;
int a[N];
int cnt_lr[N], cnt_rl[N];

int main()
{
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    for(int i = 0, j = 0; i < n; i++)
    {   
        while(j <= i && a[i] - a[j] > k) j++;
        cnt_lr[i] = max(cnt_lr[i - 1], i - j + 1);//记录以每个位置i为终点，满足条件的最大连续钻石数
    }
    for(int i = n - 1, j = n - 1; i >= 0; i--)
    {   
        while(j >= i && a[j] - a[i] > k) j--;
        cnt_rl[i] = max(cnt_rl[i + 1], j - i + 1);//记录以每个位置i为起点，满足条件的最大连续钻石数
    }

    int res = 0;
    for(int i = 0; i < n; i++)
    {
        //cnt_lr[i]     ->  以 i     为结尾的满足条件的最大钻石数
        //cnt_rl[i + 1] ->  以 i + 1 为开头的满足条件的最大钻石数
        res = max(res, cnt_lr[i] + cnt_rl[i + 1]);
    }

    printf("%d\n", res);

    return 0;
}