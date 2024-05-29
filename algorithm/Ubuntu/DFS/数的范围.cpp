#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define N 100010

int n,q;
int arr[N];

/**
 * @brief: 二分查找
 * @param: 目标数字
 * @retval: 返回第一个等于x的元素的索引，如果不存在则返回-1
*/
int binary_search1(int x)
{
    int L = -1;
    int R = n;
    int mid;
    while(L + 1 < R)
    {
        mid = L + ((R - L) >>1);
        if(arr[mid] < x)
            L = mid;
        else
            R = mid;
    }
    if(arr[R] == x) return R;
    else return -1;
}

/**
 * @brief:二分查找
 * @param:目标数字
 * @retval: 最后一个等于x的元素的索引，如果不存在则返回-1
 */ 
int binary_search2(int x)
{
    int L = -1;
    int R = n;
    int mid;
    while(L + 1 < R)
    {
        mid = L + ((R - L) >>1);
        if(arr[mid] <= x)// 如果中间元素小于等于x，更新左边界
            L = mid;
        else
            R = mid;// 否则，更新右边界
    }
    // 如果左边界等于x，返回左边界，否则返回-1
    if(L == x) return L;
    else return -1;
}

int main()
{
    scanf("%d %d", &n, &q);
    int res1, res2;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while(q --)
    {
        int x;
        scanf("%d", &x);
        res1 = binary_search1(x);
        //优化：
        // if(res1 == -1)
        // {
        //     printf("-1 -1\n");
        // }
        res2 = binary_search2(x);
        printf("%d %d", res1, res2);
    }

    return 0;
}
