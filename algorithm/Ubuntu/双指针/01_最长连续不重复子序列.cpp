#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;

int n;
int q[N];
int cnt[N];//记录每个数字出现的次数
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &q[i]);
    }

    int res = 1;
    for(int i = 1, j = 1; i <= n; i++)//初始化两个指针 （此处为快慢指针）
    {
        cnt[q[i]] ++;
        while(cnt[q[i]] > 1)//当出现两个相同数字时，j指针开始向后移动,直到j挪动到第一次出现这个重复数字位置的后一个位置
        {
            cnt[q[j]] --;//将计数数组中，i之前的数据清零
            j ++;//挪动指针
        }
        res = max(res, i - j + 1);
    }

    printf("%d", res);

    return 0;
}