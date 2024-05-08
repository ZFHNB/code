/**
 * @brief: 二分查找
 * @param: 数组、数据长度、目标数字
 * @retval: 返回第一个等于x的元素的索引，如果不存在则返回-1
*/
int binary_search1(int arr[], int len, int x)
{
    int L = -1;
    int R = len;
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
 * @param:数组、数据长度、目标数字
 * @retval: 最后一个等于x的元素的索引，如果不存在则返回-1
 */ 
int binary_search2(int arr[], int len, int x)
{
    int L = -1;
    int R = len;
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
    if(arr[L] == x) return L;
    else return -1;
}