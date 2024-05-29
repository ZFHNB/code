#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define N 100010

int n,q;
int arr[N];

/**
 * @brief: ���ֲ���
 * @param: Ŀ������
 * @retval: ���ص�һ������x��Ԫ�ص�����������������򷵻�-1
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
 * @brief:���ֲ���
 * @param:Ŀ������
 * @retval: ���һ������x��Ԫ�ص�����������������򷵻�-1
 */ 
int binary_search2(int x)
{
    int L = -1;
    int R = n;
    int mid;
    while(L + 1 < R)
    {
        mid = L + ((R - L) >>1);
        if(arr[mid] <= x)// ����м�Ԫ��С�ڵ���x��������߽�
            L = mid;
        else
            R = mid;// ���򣬸����ұ߽�
    }
    // �����߽����x��������߽磬���򷵻�-1
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
        //�Ż���
        // if(res1 == -1)
        // {
        //     printf("-1 -1\n");
        // }
        res2 = binary_search2(x);
        printf("%d %d", res1, res2);
    }

    return 0;
}
