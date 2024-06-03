#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10010;

int n;

int arr[10];//枚举和的数组
int hc[N] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};//火柴棍数量
int res;
// int cal(int x)//计算数字对应所需的火柴数
// {
//     if(hc[x] > 0) return hc[x];
//     else
//     {
//         int sumFire = 0;
//         while(x)
//         {
//             sumFire += hc[x % 10];
//             x /= 10;
//         }
//         return sumFire;
//     }
// }

void dfs(int x, int sum)
{
    if(sum > n) return;
    if(x > 3)
    {
        if(arr[1] + arr[2] == arr[3] && sum == n)
        {
            res++;
        }
        return;
    }
    for(int i = 0; i <= 1000; i++)
    {
        arr[x] = i;
        dfs(x + 1, sum + hc[i]);
    }
}

int main()
{
    scanf("%d", &n);
    n -= 4;
    //递推出10~1000需要的火柴数
    for(int i = 10; i <= 1000; i++)
    {
        hc[i] = hc[i % 10] + hc[i / 10];
    }
    dfs(1, 0);
    printf("%d", res);

    return 0;
}