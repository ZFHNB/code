#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 50010; 
int a[N];
int L;//起点到终点的距离
int n;//起点和终点之间的岩石数
int m;//组委会至多移走的岩石数

bool check(int x)
{
    int cnt = 0;//计数器（计数挪走石头数量）
    int i = 0;//下一个石头
    int now = 0;//当前所在石头
    while(i < n + 1)
    {
        i++;
        while(a[i] - a[now] < x)//若当前所在石头与下一石头距离小于当前传输的数据x
        {
            cnt ++;//挪走一块石头
            if(i < n + 1)
            {
                i ++;//下下块变为下一块石头   
            }
            else//循环结束
            {
                if(cnt <= m) return true;//若挪走石头数符合题意
                else return false;
            }   
        }
        now = i;//此时当前所在石头与下一石头间距 >= x
    }
    if(cnt <= m) return true;//若挪走石头数符合题意
    else return false;
}

int main()
{
    scanf("%d %d %d", &L, &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    a[0] = 0;
    a[n + 1] = L;

    int l = 0, r = L + 1;
    while(l + 1 < r)
    {
        int mid = l + ((r - l) >> 1);
        if(check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if(check(r))
    {
        printf("%d",r);
    }
    else
    {
        printf("%d",l);
    }

    return 0;
}