#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200010;
int n, c;
int a[N];

int main()
{
    scanf("%d %d", &n, &c);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1);
    long long cnt = 0;

    for(int i = 1, j = 1, k = 1; i <= n; i++)//i为快指针，j、k为两个慢指针，j指向目标数字的后一个位置，k指向第一个目标数字
    {
        while(j <= i && a[i] - a[j] >= c)//j指向目标数字的后一个位置
        {
            j++;
        }
        while(k <= j && a[i] - a[k] > c)//k指向第一个目标数字
        {
            k++;
        }
        if(a[i] - a[j - 1] == c) cnt += j - k;//确保j指针当前指向的位置是目标数字的后一个位置，而不是在大于目标数字（目标数字不存在）的位置停下
    }

    printf("%lld\n", cnt);
    
    return 0;
}