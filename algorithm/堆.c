#include <stdio.h>

void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//向大根堆中插入元素
void heapInsert(int *arr, int index)
{
	int faIndex = (index - 1) / 2;//父节点下标
	while(arr[index] > arr[faIndex])//与父节点大小进行比较，若大，则交换
	{
		swap(arr, index, faIndex);
		index = faIndex;//更新节点当前下标
	}
}

//brief：自顶向下将此节点的值与其子节点大小比较，移位，从而确定其位置
//param：index指从何位置开始进行此操作
//param：heapSize为判断该节点是否有子节点的根据（inedx*2+1 < heapSize时，存在子节点）
void heapify(int *arr, int index, int heapSize)
{
	int left = index * 2 + 1;//左孩子下标
	int right = left + 1;//右孩子下标
	
	while(left < heapSize)
	{
		int largest = right < heapSize && arr[right] > arr[left] ? right : left;
		if(arr[largest] > arr[index])
		{
			swap(arr, index, largest);
			index = largest;
			left = index * 2 + 1;
			right = left + 1;
		}
		else
		{
	    	break; // 如果不需要交换，则退出循环
	    }
	}
}

void heapSort(int *arr, int heapSize)
{
	if(arr == NULL || heapSize < 2)
	{
		return;
	}
	
	    // 初始化大根堆（自底向上堆化）
	/*
		(n/2-1)为最后一个非叶子节点的位置，大根堆性质只需要保证父节点大于等于其子节点，仅遍历所有父节点可提高效率
	*/
	for(int i = heapSize / 2 - 1; i>=0; i--)//由最后一个非叶子节点的位置向前遍历
	{
		heapify(arr, i, heapSize);//O(logN)
	}
	
	swap(arr, 0, --heapSize);//第一次交换
	while(heapSize > 0)
	{
		heapify(arr, 0, heapSize);
		swap(arr, 0, --heapSize);//迭代交换
	}
}

int main()
{
    int arr[] = {4, 10, 3, 5, 1, 33, 12, 656};
    int heapSize = sizeof(arr) / sizeof(arr[0]);
    
    heapSort(arr,heapSize);

    printf("Max Heap: ");
    for (int i = 0; i < heapSize; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
