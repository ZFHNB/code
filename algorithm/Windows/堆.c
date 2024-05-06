#include <stdio.h>

void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//�������в���Ԫ��
void heapInsert(int *arr, int index)
{
	int faIndex = (index - 1) / 2;//���ڵ��±�
	while(arr[index] > arr[faIndex])//�븸�ڵ��С���бȽϣ������򽻻�
	{
		swap(arr, index, faIndex);
		index = faIndex;//���½ڵ㵱ǰ�±�
	}
}

//brief���Զ����½��˽ڵ��ֵ�����ӽڵ��С�Ƚϣ���λ���Ӷ�ȷ����λ��
//param��indexָ�Ӻ�λ�ÿ�ʼ���д˲���
//param��heapSizeΪ�жϸýڵ��Ƿ����ӽڵ�ĸ��ݣ�inedx*2+1 < heapSizeʱ�������ӽڵ㣩
void heapify(int *arr, int index, int heapSize)
{
	int left = index * 2 + 1;//�����±�
	int right = left + 1;//�Һ����±�
	
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
	    	break; // �������Ҫ���������˳�ѭ��
	    }
	}
}

void heapSort(int *arr, int heapSize)
{
	if(arr == NULL || heapSize < 2)
	{
		return;
	}
	
	    // ��ʼ������ѣ��Ե����϶ѻ���
	/*
		(n/2-1)Ϊ���һ����Ҷ�ӽڵ��λ�ã����������ֻ��Ҫ��֤���ڵ���ڵ������ӽڵ㣬���������и��ڵ�����Ч��
	*/
	for(int i = heapSize / 2 - 1; i>=0; i--)//�����һ����Ҷ�ӽڵ��λ����ǰ����
	{
		heapify(arr, i, heapSize);//O(logN)
	}
	
	swap(arr, 0, --heapSize);//��һ�ν���
	while(heapSize > 0)
	{
		heapify(arr, 0, heapSize);
		swap(arr, 0, --heapSize);//��������
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
