#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	//vector��̬���飺
	
	//��ʼ����vector<elem> arr(����,[��ֵ]);
	vector<int> arr1(10,0);
	vector<int>::iterator it1 = arr1.begin();
	while(it1 != arr1.end())
	{
		printf("%d", *it1);
		++it1;
	}
	printf("\n");
	//��ʼ����ά���飺vector<vector<elem>> arr(����, vector<elem> ([����],[��ֵ]));
	vector<vector<int>> arr2(10, vector<int> (10,1));
	
	//β�壬βɾ��
	arr1.push_back(2);//β��
	
	vector<int>::iterator it2 = arr1.begin();
	while(it2 != arr1.end())
	{
		printf("%d", *it2);
		++it2;
	}
	
	int a = arr1.back();//�������һ��Ԫ��
	printf("arr1�����һ��Ԫ�أ�%d\n",a);
	
	arr1.pop_back();//βɾ
	
	vector<int>::iterator it3 = arr1.begin();
	while(it3 != arr1.end())
	{
		printf("%d",*it3);
		++it3;
	}
	printf("\n");
	
	//��ȡ���ȣ�.size()
	printf("arr1�ĳ���Ϊ��%d\n",arr1.size());
	for(int i = 0; i<arr1.size(); i++)
	{
		printf("%d",arr1[i]);
	}
	printf("\n");
	
	//��գ�.clear()
	//�пգ�.empty() �շ���true���ǿշ���false
	arr1.clear();
	if(arr1.empty())
	{
		printf("arr1Ϊ�գ�����\n");
	}
	
	//���ȶ���
	priority_queue<int, vector<int>> pque1
	
	//unique()
	vector<int> arr{1, 2, 1, 4, 5, 4, 4};
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	
	return 0;
}
