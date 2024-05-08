#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200010;
int n,c;
int arr[N];

int binary_searchl(int x)
{
    int l = -1, r = n; 
    int mid;
    while(l + 1 < r)
    {
        mid = l + ((r - l) >> 1);
        if(arr[mid] < x)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if(arr[r] == x) return r;
    else return -1;
}
int binary_searchr(int x)
{
    int l = -1, r = n; 
    int mid;
    while(l + 1 < r)
    {
        mid = l + ((r - l) >> 1);
        if(arr[mid] <= x)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if(arr[l] == x) return l;
    else return -1;
}


int main()
{
    scanf("%d %d", &n, &c);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n);

    long long cnt = 0;

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = i; j < n; j++)
    //     {
    //         if(arr[j] - arr[i] == c)
    //         {
    //             cnt++;
    //         }
    //     }
    // }

    for(int i = 0; i < n; i++)
    {
       int l = binary_searchl(arr[i] - c);
       if(l == -1) continue;
       int r = binary_searchr(arr[i] - c);
       cnt += (r-l+1);
    }

    printf("%lld", cnt);

    return 0;
}