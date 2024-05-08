#include <iostream>
using namespace std;

const int N = 100010;

int n,m;//数字个数与询问次数
int arr[N];

int binary_search(int x, int *arr, int len)
{
    int l = 0; 
    int r = len + 1;
    while(l + 1 < r)
    {
        int mid = l + ((r - l) >> 1);
        if(arr[mid] < x)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if(arr[r] == x)
    {
        return r;
    }
    else return -1;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while(m--)
    {
        int q;
        scanf("%d", &q);
        int res = binary_search(q, arr, n);
        printf("%d ", res);
    }

    return 0;
}